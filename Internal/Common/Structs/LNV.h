#pragma once

#include <any>
#include <unordered_map>
#include <algorithm>

#include <RakNet/BitStream.h>

struct LWONameValue {
	uint8_t Type;
	std::any Data;

	void Serialize(RakNet::BitStream* bs, std::u16string Name);

	LWONameValue(uint8_t _type, std::any _data);
};

class LWONameValueGroup {
	std::unordered_map<std::u16string, LWONameValue> Values;
public:
	void FromBitStream(RakNet::BitStream* bs);
	void FromU16String(std::u16string Value);

	LWONameValueGroup();

	void Insert(std::u16string Name, LWONameValue Value);

	void Insert(std::u16string Name, std::any Value, uint8_t Type);

	template <class T>
	inline T Get(std::u16string Name) { return std::any_cast<T>(Values.at(Name).Data); }

	template <class T>
	inline T Get(std::u16string Name, T Default) {
		if (Values.find(Name) != Values.end()) {
			return Get<T>(Name);
		}
		
		return Default;
	}

	void Serialize(RakNet::BitStream* bs);
};
