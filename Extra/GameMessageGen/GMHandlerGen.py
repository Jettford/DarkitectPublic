import zlib
import pickle

f = open('gm', 'rb')
decompressed_data = zlib.decompress(f.read())
gamemsgs = pickle.loads(decompressed_data)

headerfile = open('GMHandler.h', 'w')

for x in gamemsgs["messages"]:
    message = gamemsgs["messages"][x]
    if "client" in message["network"]: continue
    if "custom" in message or message["name"] == "ControlBehaviors": continue
    print(message)
    headerfile.write("case " + str(x) + ":\n\t\t\t{\n\t\t\t\t" + message["name"] + " msg = " + message["name"] + "();\n\t\t\t\tmsg.Deserialize(bs);\n\t\t\t\tTarget->HandleGM(Sender, MsgID, &msg);\n\t\t\t\t break;\n\t\t\t}\n")