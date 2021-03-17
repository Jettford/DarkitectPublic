#pragma once

#include <Common/Utils.h>
#include <Common/Structs/NiPoint3.h>
#include <Common/Structs/NiQuaternion.h>

#include <vector>

#include "Scene/LUZScene.h"

struct Checksum {
	uint32_t v = 0xFFFFU;
	uint32_t t = 0xFFFFU;

	Checksum& operator +=(std::uint32_t r);
	uint32_t result();
};

struct Scene {
	const char* FileName;
	uint32_t SceneID;
	uint32_t LayerID;
	const char* SceneName;
	LUZScene SceneFile;
};

struct TransitionPoint {
	uint64_t SceneID;
	NiPoint3 Position;
};

struct SceneTransition {
	std::string Name;
	uint32_t TransitionPointCount; 
	std::vector<TransitionPoint> TransitionPoints;
};

class LUZFile {
public:
	Checksum checksum;

	uint32_t Version;
	uint32_t RevisionNumber;
	uint32_t WorldID;

	NiPoint3 SpawnPos;
	NiQuaternion SpawnRot;

	uint32_t SceneCount;

	std::vector<Scene> Scenes = std::vector<Scene>();

	std::string TerrainDescription;
	std::string TerrainFileName;
	std::string TerrainFile;

	std::vector<SceneTransition> SceneTransitions;

	LUZFile(const char* FileName);
	LUZFile() = default;
};