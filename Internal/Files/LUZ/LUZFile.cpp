#include "LUZFile.h"

Checksum& Checksum::operator +=(std::uint32_t r) {
	v += (r >> 16);
	t += v;
	v += (r & 0xFFFFU);
	t += v;
	return *this;
}

uint32_t Checksum::result() {
	return ((((t & 0xFFFFU) + (t >> 16)) << 16) | ((v & 0xFFFFU) + (v >> 16)));
}


LUZFile::LUZFile(const char* FileName) {
	uint32_t FileSize;

	auto data = Utils::ReadFileCompletely(FileName, &FileSize);

	RakNet::BitStream* bs = new RakNet::BitStream((unsigned char*)data.get(), FileSize, false);

	checksum += 0xFFFFU;
	checksum += 0;

	this->Version = bs->Read<uint32_t>().second;

	if (Version >= 0x24UL) {
		RevisionNumber = bs->Read<uint32_t>().second;
	}
	else RevisionNumber = 0;

	checksum += RevisionNumber;

	WorldID = bs->Read<uint32_t>().second;
	
	if (Version >= 0x26UL) {
		SpawnPos = bs->Read<NiPoint3>().second;
		SpawnRot = bs->Read<NiQuaternion>().second;
	}

	if (Version < 0x25) SceneCount = bs->Read<uint8_t>().second;
	else SceneCount = bs->Read<uint32_t>().second;

	for (uint32_t i = 0; i < SceneCount; ++i) {
		bool FileChunked;

		Scene current;
		
		uint8_t SceneFileNameLen = bs->Read<uint8_t>().second; // Get length of file name string 
		std::string SceneFileName;
		for (int i = 0; i < SceneFileNameLen; ++i) SceneFileName += bs->Read<char>().second;

		Logger::Log("Game", "Loading LVL File: " + SceneFileName);
		std::string Path = std::string(FileName).substr(0, std::string(FileName).find_last_of("\\/")) + "/" + SceneFileName;
		std::transform(Path.begin(), Path.end(), Path.begin(), [](unsigned char c) -> unsigned char {
			return std::tolower(c);
		});
		current.SceneFile.Read(Path);
		
		current.FileName = SceneFileName.c_str();
		current.SceneID = bs->Read<uint32_t>().second;
		current.LayerID = bs->Read<uint32_t>().second;

		uint8_t SceneNameLen = bs->Read<uint8_t>().second;
		std::string SceneName;
		for (int i = 0; i < SceneNameLen; ++i) SceneName += bs->Read<char>().second;

		current.SceneName = SceneName.c_str();

		bs->IgnoreBytes(3);

		checksum += current.SceneID;
		checksum += current.LayerID;
		checksum += current.SceneFile.Info.Revision;

		Scenes.push_back(current);
	}

	// Finish rest of LUZ

	bs->Read<uint8_t>();

	uint8_t TerrainFileNameLen = bs->Read<uint8_t>().second;
	for (int i = 0; i < TerrainFileNameLen; ++i) TerrainFileName += bs->Read<char>().second;

	uint8_t TerrainFileLen = bs->Read<uint8_t>().second;
	for (int i = 0; i < TerrainFileLen; ++i) TerrainFile += bs->Read<char>().second;
	
	uint8_t TerrainDescriptionLen = bs->Read<uint8_t>().second;
	for (int i = 0; i < TerrainDescriptionLen; ++i) TerrainDescription += bs->Read<char>().second;

	if (Version >= 0x20) {
		uint32_t SceneTransitionCount = bs->Read<uint32_t>().second;

		SceneTransitions = std::vector<SceneTransition>();

		for (uint32_t i = 0; i < SceneTransitionCount; ++i) {
			SceneTransition current;
			if (Version < 0x25) {
				uint32_t SceneTransitionNameLen = bs->Read<uint8_t>().second;
				for (int i = 0; i < SceneTransitionNameLen; ++i) current.Name += bs->Read<char>().second;

				current.TransitionPointCount = (Version <= 0x21 || Version >= 0x27) ? 2 : 5;

				current.TransitionPoints = std::vector<TransitionPoint>();

				for (int i = 0; i < current.TransitionPointCount; ++i) {
					TransitionPoint point;
					point.SceneID = bs->Read<uint64_t>().second;
					point.Position = bs->Read<NiPoint3>().second;
					current.TransitionPoints.push_back(point);
				}
			}
		}
	}
	
	if (Version >= 0x23) {
		uint32_t RemainingData = bs->Read<uint32_t>().second;

		// TOOD: Read Path data
	}
}