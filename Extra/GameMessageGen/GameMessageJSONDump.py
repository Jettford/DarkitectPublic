import pickle
import zlib
import json

f = open('gm', 'rb')
decompressed_data = zlib.decompress(f.read())
gamemsgs = pickle.loads(decompressed_data)
print(json.dumps(gamemsgs))