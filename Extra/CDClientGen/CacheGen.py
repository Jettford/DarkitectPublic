import sqlite3
from dataclasses import dataclass
from enum import Enum

@dataclass
class table_info:
    cid: int
    name: str
    type: str
    notnull: int
    dflt_value: str # FDB doesn't support defaults so this can pretty much be ignored
    pk: int

class Type(Enum):
    i64 = 1
    i32 = 2
    string = 3
    flt = 4

conn = sqlite3.connect("CDClient.sqlite")

cursor = conn.cursor()

CppFile = open("CDClient.cpp", "w")
HeaderFile = open("CDClient.h", "w")

HeaderFile.write("""#pragma once

#include <vector>

#include "Logger.h"
#include "CDClient/CDClientStructs.h"

#include <CppSQLite3/CppSQLite3.h>

#define GET_COMPONENT_FROM_CDCLIENT(CDClient, TableName, idv) std::vector<CDClientStructs::##TableName> temp_table; temp_table = std::vector<CDClientStructs::##TableName>(); std::copy_if(##CDClient##->##TableName##Data->begin(), ##CDClient##->##TableName##Data->end(), temp_table.begin(), [&](CDClientStructs::##TableName item) { return item.id == ##idv ; }); auto row = temp_table.at(0);

class CDClient : public CppSQLite3DB { // I hate this
public:
""")

CppFile.write("""#include "CDClient.h"

""")

for item in cursor.execute("SELECT * FROM sqlite_sequence").fetchall():
    HeaderFile.write("#ifdef Cache" + item[0] + "\n")
    HeaderFile.write("\tstd::vector<CDClientStructs::" + item[0] + "> " + item[0] + "Data;\n")
    HeaderFile.write("#endif\n")

HeaderFile.write("\n\tCDClient();\n")
HeaderFile.write("\tvoid Open();\n")
HeaderFile.write("\tvoid LoadCDClientData();\n")

CppFile.write("CDClient::CDClient() {\n")
for item in cursor.execute("SELECT * FROM sqlite_sequence").fetchall():
    CppFile.write("#ifdef Cache" + item[0] + "\n")
    CppFile.write("\t" + item[0] + "Data = std::vector<CDClientStructs::" + item[0] + ">();\n")
    CppFile.write("#endif\n")
CppFile.write("}\n")

CppFile.write("""
void CDClient::Open() {
	this->open("./res/CDClient.sqlite");
	LoadCDClientData();
	Logger::Log("CDClient", "Loaded CDClient");
}

void CDClient::LoadCDClientData() {
""")

for item in cursor.execute("SELECT * FROM sqlite_sequence").fetchall():
    if item[0] == "SurfaceType": continue
    CppFile.write("#ifdef Cache" + item[0] + "\n")
    CppFile.write("\tauto " + item[0] + 'Query = this->compileStatement("SELECT * FROM ' + item[0] + '");\n')
    CppFile.write("\tauto " + item[0] + "Result = " + item[0] + "Query.execQuery();\n")
    CppFile.write("\twhile (!" + item[0] + "Result.eof()) {\n")
    CppFile.write("\t\tCDClientStructs::" + item[0] + " Table;\n")
    for row in cursor.execute("PRAGMA table_info('" + item[0] + "')").fetchall():
        Table = table_info(row[0], row[1], row[2], row[3], row[4], row[5])
        if Table.name == "static": Table.name = "Static"
        PostType: Type
        if Table.type == "INTEGER":
            LargestIntegerArray = cursor.execute("SELECT " + Table.name + " FROM " + item[0] + " WHERE " + Table.name + " = (SELECT MAX(" + Table.name + ") FROM " + item[0] + ")").fetchone()
            if LargestIntegerArray == None: 
                CppFile.write('\t\tTable.' + Table.name + " = " + item[0] + "Result.getInt64Field(" + '"' + Table.name + '"' + ");\n")
            else:
                if LargestIntegerArray[0] > 2147483647:
                    CppFile.write('\t\tTable.' + Table.name + " = " + item[0] + "Result.getInt64Field(" + '"' + Table.name + '"' + ");\n")
                else:
                    CppFile.write('\t\tTable.' + Table.name + " = " + item[0] + "Result.getIntField(" + '"' + Table.name + '"' + ");\n")
            
        elif Table.type == "TEXT":
            PostType = CppFile.write('\t\tTable.' + Table.name + " = " + item[0] + "Result.getStringField(" + '"' + Table.name + '"' + ");\n")
        elif Table.type == "REAL":
            if Table.name == "Static":
                CppFile.write('\t\tTable.' + Table.name + " = " + item[0] + 'Result.getFloatField("static");\n')
            else:
                CppFile.write('\t\tTable.' + Table.name + " = " + item[0] + "Result.getFloatField(" + '"' + Table.name + '"' + ");\n")
    CppFile.write("\t\t" + item[0] + "Data.push_back(Table);\n")
    CppFile.write("\t\t" + item[0] + "Result.nextRow();\n")
    CppFile.write("\t}\n")
    CppFile.write('\tLogger::Log("CDClient", "Loaded ' + item[0] + '");\n')
    CppFile.write("#endif\n\n")
    
CppFile.write("}")

HeaderFile.write("};\n")
