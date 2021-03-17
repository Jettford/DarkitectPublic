#pragma once

#include <cstdint>
#include <cmath>
#include <string>
#include <vector>

#include <Common/Structs/Position.h>

struct SceneObjectTemplate {
	uint64_t ObjectID;
	int32_t LOT;
	uint32_t AssetType;
	Position SpawnPosition;
	float_t Scale;
	std::u16string Config;
};

struct ObjectChunk {
	std::vector<SceneObjectTemplate> Objects;

	void ReadChunk(uint32_t Version, char* data) {
		Objects = std::vector<SceneObjectTemplate>();
		uint32_t ObjectCount = *reinterpret_cast<uint32_t*>(data);
		uint32_t off = 4;
		for (uint32_t i = 0; i < ObjectCount; ++i) {
			SceneObjectTemplate obj;
			obj.ObjectID = *reinterpret_cast<uint64_t*>(data + off);
			obj.LOT = *reinterpret_cast<std::int32_t*>(data + off + 8);
			off += 12;
			if (Version >= 0x26) {
				obj.AssetType = *reinterpret_cast<std::uint32_t*>(data + off + 0);
				off += 4;
			}
			if (Version >= 0x20) off += 4;
			obj.SpawnPosition.Pos = NiPoint3();
			obj.SpawnPosition.Pos.X = *reinterpret_cast<float_t*>(data + off);
			obj.SpawnPosition.Pos.Y = *reinterpret_cast<float_t*>(data + off + 4);
			obj.SpawnPosition.Pos.Z = *reinterpret_cast<float_t*>(data + off + 8);
			obj.SpawnPosition.Rot = NiQuaternion();
			obj.SpawnPosition.Rot.X = *reinterpret_cast<float_t*>(data + off + 16);
			obj.SpawnPosition.Rot.Y = *reinterpret_cast<float_t*>(data + off + 20);
			obj.SpawnPosition.Rot.Z = *reinterpret_cast<float_t*>(data + off + 24);
			obj.SpawnPosition.Rot.W = *reinterpret_cast<float_t*>(data + off + 12);
			obj.Scale = *reinterpret_cast<float_t*>(data + off + 28);
			off += 32;
			uint32_t Len = *reinterpret_cast<std::uint32_t*>(data + off);
			off += 4;
			obj.Config = std::u16string();
			for (uint32_t i = 0; i < Len; i++)
			{
				obj.Config += *reinterpret_cast<char16_t*>(data + off);
				off += 2;
			}

			if (Version >= 7) {
				if (*reinterpret_cast<std::uint32_t*>(data + off) != 0x00000000) { throw std::exception(); }
				off += 4;
			}
			if (obj.LOT != 0) {
				Objects.push_back(obj);
			}
		}
	}
};