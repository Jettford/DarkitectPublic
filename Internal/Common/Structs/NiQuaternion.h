#pragma once


struct NiQuaternion {
#pragma pack(push, 1)
	float X = 0.0f;
	float Y = 0.0f;
	float Z = 0.0f;
	float W = 1.0f;
#pragma pack(pop)
	inline bool operator==(const NiQuaternion& other) const {
		return (X == other.X && Y == other.Y && Z == other.Z && W == other.W);
	}
	inline bool operator != (const NiQuaternion& other) const { return !(*this == other); }
};
