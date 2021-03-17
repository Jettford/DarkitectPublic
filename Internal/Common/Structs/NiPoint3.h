#pragma once

struct NiPoint3 {
#pragma pack(push, 1)
	float X = 0.0f;
	float Y = 0.0f;
	float Z = 0.0f;
#pragma pack(pop)
	inline bool operator==(const NiPoint3& other) const {
		return (((this->X > other.X - 0.00001) && (this->X < other.X + 0.00001))
			&& ((this->X > other.Y - 0.00001) && (this->Y < other.Y + 0.00001))
			&& ((this->Z > other.Z - 0.00001) && (this->Z < other.Z + 0.00001)));
	}
	inline bool operator != (const NiPoint3& other) const { return !(*this == other); }
};