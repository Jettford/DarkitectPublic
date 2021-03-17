import sqlite3
from dataclasses import dataclass


@dataclass
class table_info:
    cid: int
    name: str
    type: str
    notnull: int
    dflt_value: str # FDB doesn't support defaults so this can pretty much be ignored
    pk: int

conn = sqlite3.connect("CDClient.sqlite")

cursor = conn.cursor()

HeaderFile = open("CDClientStructs.h", "w")

HeaderFile.write("#pragma once\n\n")

HeaderFile.write("#include <string>\n")
HeaderFile.write("#include <cstdint>\n\n")

for item in cursor.execute("SELECT * FROM sqlite_sequence").fetchall():
    

    HeaderFile.write("struct " + item[0] + " { \n")

    for row in cursor.execute("PRAGMA table_info('" + item[0] + "')").fetchall():
        Table = table_info(row[0], row[1], row[2], row[3], row[4], row[5])
        PostType: str
        if Table.type == "INTEGER":
            LargestIntegerArray = cursor.execute("SELECT " + Table.name + " FROM " + item[0] + " WHERE " + Table.name + " = (SELECT MAX(" + Table.name + ") FROM " + item[0] + ")").fetchone()
            if LargestIntegerArray == None: 
                PostType = "int64_t"
            else:
                if LargestIntegerArray[0] > 2147483647: # int64_t
                    PostType = "int64_t"
                else:
                    PostType = "int32_t"
        elif Table.type == "TEXT":
            PostType = "std::string"
        elif Table.type == "REAL":
            PostType = "float"

        HeaderFile.write("\t" + PostType + " " + Table.name + ";\n")

    HeaderFile.write("};\n\n")