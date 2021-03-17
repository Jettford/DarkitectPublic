#pragma once

#include <cstdint>

#include <Common/Utils.h>

#include "Objects.h"

struct ChunkHeader {
	uint32_t Type;
	uint32_t Unknown;
	uint32_t Length;
	uint32_t Offset;
};

struct InfoChunk {
	uint32_t Version;
	uint32_t Revision;
	uint32_t SkyAdress;
	uint32_t ObjectsAdress;
	uint32_t EnvAdress;
};

class LUZScene {
public:
	InfoChunk Info;
	ObjectChunk Objects;
	void Read(std::string Path);
};

