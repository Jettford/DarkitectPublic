#pragma once 

#include <cstdint>
#include <string>
#include <vector>

struct Character {
	uint32_t CharID;
	uint32_t AccountID;
	std::string Name;
	std::string UnapprovedName = "";
	uint32_t ShirtColor;
	uint32_t ShirtStyle;
	uint32_t PantsColor;
	uint32_t HairStyle;
	uint32_t HairColor;
	uint32_t LeftHand;
	uint32_t RightHand;
	uint32_t EyebrowStyle;
	uint32_t EyeStyle;
	uint32_t MouthStyle;
	uint32_t LastZone = 0;
	uint32_t Health = 4;
	float MaxHealth = 4;
	uint32_t Armor = 0;
	float MaxArmor = 0;
	uint32_t Imagination = 0;
	float MaxImagination = 0;
	uint32_t InventorySpace = 20;
	uint32_t UScore = 0;
	uint32_t GMLevel = 0;
	uint32_t Reputation = 0;
	uint32_t Level = 1;
	float X = 0;
	float Y = 0;
	float Z = 0;
	std::vector<uint32_t> EquippedItems;
};