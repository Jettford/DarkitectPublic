import zlib
import pickle

def CheckDefault(message, param) -> str:
    default = param["default"]
    if "enums" in message and param["type"] in message["enums"]:
        default = message["enums"][param["type"]].index(default)
    
    if default == "SECONDARY_PRIORITY": default = "0.400000005960465f"
    elif default == "OBJECTID_EMPTY": default = "0"
    elif default == "LOT_NULL": default = "-1"
    elif default == "LOOTTYPE_NONE": default = "-1"
    elif default == "INVENTORY_DEFAULT": default = "-1"
    elif default == "ZONEID_INVALID": default = "0"
    elif default == "Vector3::ZERO": default = "NiPoint3()"
    elif default == "Quaternion::IDENTITY": default = "NiQuaternion()"
    elif default == "NDAudio::g_NDAudioIDNone": default = "0"
    elif default == "WORLDSTATE_INWORLD": default = "0"
    elif default == "BUILD_ON_PROPERTY": default = "2"
    elif default == "INVENTORY_MAX": default = "100"
    elif default == "INVENTORY_INVALID": default = "100"
    elif default == "CLONEID_INVALID": default = "0"
    elif default == "MAPID_INVALID": default = "0"
    
    return str(default)
    
def Deserialize(cppfile, type, name):
    if type == "std::string":
        cppfile.write(name + " = Utils::StringFromBitStream<uint32_t>(bs); // utf-8 string\n")
        return None
    elif type == "std::u16string":
        cppfile.write(name + " = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string\n")
        return None

    cppfile.write("bs->Read<" + type + ">(" + name + ");\n")

f = open('gm', 'rb')
decompressed_data = zlib.decompress(f.read())
gamemsgs = pickle.loads(decompressed_data)
custom = []
headerfile = open('../../Internal/Net/GameMessages/ClientGMs.h', 'w')
cppfile = open('../../Internal/Net/GameMessages/ClientGMs.cpp', 'w')

headerfile.write("#pragma once\n\n")
headerfile.write("#include <RakNet/BitStream.h>\n")
headerfile.write("#include <string>\n")
headerfile.write("#include <cstdint>\n")
headerfile.write("#include <vector>\n")
headerfile.write("#include <Common/Structs/NiPoint3.h>\n")
headerfile.write("#include <Common/Utils.h>\n")
headerfile.write("#include <Common/Structs/NiQuaternion.h>\n\n")
headerfile.write("namespace ClientGameMessages {\n")

cppfile.write('#include "ClientGMs.h"\n\n')

headerfile.write("\tstruct ClientGameMessage {\n\t\tconstexpr static uint32_t GetID() { return 0; }\n\n\t\tvirtual void Deserialize(RakNet::BitStream* bs) {}\n\t};\n\n")


for x in gamemsgs["messages"]:
    message = gamemsgs["messages"][x]
    if "client" in message["network"]: continue
    if "custom" in message or message["name"] == "ControlBehaviors":
        custom.append(message["name"])
        continue

    message = gamemsgs["messages"][x]
    print("Generating struct and deserialization for " + message["name"])
    params = message["params"]

    # write headers for structs

    headerfile.write("\tstruct " + message["name"] + " : ClientGameMessage {\n")
    for param in params:
        type = param["type"]

        # Here we replace objects if we need to

        if type == "unsigned char": type = "uint8_t"
        elif type == "mapid": type = "uint16_t"
        elif type in ("int", "LOT"): type = "int32_t" 
        elif type in ("unsigned int", "clondid", "TSkillID"): type = "uint32_t"
        elif type == "__int64": type = "int64_t"
        elif type == "objectid": type = "int64_t"
        elif type == "LDF": type = "std::u16string"
        elif type == "wstr": type = "std::u16string"
        elif type == "str": type = "std::string"
        elif type == "float": type = "float_t"
        elif type == "Vector3": type = "NiPoint3"
        elif type == "Quaternion": type = "NiQuaternion"
        elif type == "BinaryBuffer": 
            type = "const char*"
            headerfile.write("\t\tuint32_t SizeOf" + param["name"] + ";\n")
            headerfile.write("\t\tconst char* " + param["name"] + ";\n")
            continue
        elif type == "zoneid": type = "int64_t"
        elif type == "cloneid": type = "uint32_t"
        elif type == "NDAudio::TNDAudioID": type = "int64_t"
        elif "enums" in message and type in message["enums"] or type == "eObjectWorldState" or type == "EBuildType": type = "uint32_t"

        if "default" not in param:
            headerfile.write("\t\t" + type + " " + param["name"] + ";\n")
        else:
            default = CheckDefault(message, param)
            headerfile.write("\t\t" + type + " " + param["name"] + " = " + default + ";\n")

    headerfile.write("\t\tvoid Deserialize(RakNet::BitStream* bs) override;\n")
    headerfile.write("\t\tconstexpr static uint32_t GetID() { return " + str(x) + "; }\n")
    headerfile.write("\t};\n\n")

    cppfile.write("void ClientGameMessages::" + message["name"] + "::Deserialize(RakNet::BitStream* bs) {\n")

    # write the serialization

    for param in params:
        type = param["type"]

        if type == "unsigned char": type = "uint8_t"
        elif type == "mapid": type = "uint16_t"
        elif type in ("int", "LOT"): type = "int32_t" 
        elif type in ("unsigned int", "clondid", "TSkillID"): type = "uint32_t"
        elif type == "__int64": type = "int64_t"
        elif type == "objectid": type = "int64_t"
        elif type == "LDF": type = "std::u16string"
        elif type == "wstr": type = "std::u16string"
        elif type == "str": type = "std::string"
        elif type == "float": type = "float_t"
        elif type == "Vector3": type = "NiPoint3"
        elif type == "Quaternion": type = "NiQuaternion"
        elif type == "zoneid": type = "int64_t"
        elif type == "cloneid": type = "uint32_t"
        elif type == "NDAudio::TNDAudioID": type = "int64_t"
        elif type == "BinaryBuffer": 
            type = "const char*"
            cppfile.write("\tbs->Read<uint32_t>(SizeOf" + param["name"] + ");\n")
            cppfile.write("\t" + param["name"] + " = (char*)malloc((size_t)SizeOf" + param["name"] + ");\n")
            cppfile.write("\tbs->Read((char*)" + param["name"] + ", SizeOf" + param["name"] +");\n")
            continue
        elif "enums" in message and type in message["enums"] or type == "eObjectWorldState" or type == "EBuildType": type = "uint32_t"

        if not type == "bool":
            if "default" not in param:
                cppfile.write("\t")
                Deserialize(cppfile, type, param["name"])
            else:
                default = CheckDefault(message, param)
                cppfile.write("\tif (bs->ReadBit()) ")
                Deserialize(cppfile, type, param["name"])
        else:
            cppfile.write("\t" + param["name"] + " = bs->ReadBit();\n")
            
    cppfile.write("}\n\n")

headerfile.write("}\n\n")

for x in custom:
    headerfile.write("// add serialization for " + x + "\n")