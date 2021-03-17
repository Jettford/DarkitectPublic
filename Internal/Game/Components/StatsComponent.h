#pragma once

#include "../Component.h"

// This is a fake replica component 
// it is used by other components

class StatsComponent : public Component {
public:
	bool DirtyBuffs = true;
	bool DirtyStats = true;

	// Stats
	int32_t Health;
	float_t MaxHealth;
	int32_t Armor;
	float_t MaxArmor;
	int32_t Imagination;
	float_t MaxImagination;
	int32_t AbsorbstionPoints;
	bool Immune = false;
	bool GMImmune = false;
	bool Shield = false;
	std::vector<std::int32_t> Factions;
	bool Smashable = true;


	void Start(uint32_t ComponentID) override {
		
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		if (IsConstruction) {
			bs->Write(DirtyBuffs);
			if (DirtyBuffs) {
				for (uint32_t i = 0; i < 9; i++) bs->Write<uint32_t>(0);
			}
		}

		bs->Write(DirtyStats);
		if (DirtyStats) {
			bs->Write<uint32_t>(Health);
			bs->Write<float_t>(MaxHealth);

			bs->Write<uint32_t>(Armor);
			bs->Write<float_t>(MaxArmor);
			
			bs->Write<uint32_t>(Imagination);
			bs->Write<float_t>(MaxImagination);

			bs->Write<uint32_t>(AbsorbstionPoints);

			bs->Write<bool>(Immune);
			bs->Write<bool>(GMImmune);
			bs->Write<bool>(Shield);

			bs->Write<float_t>(MaxHealth);
			bs->Write<float_t>(MaxArmor);
			bs->Write<float_t>(MaxImagination);

			bs->Write<uint32_t>(Factions.size());
			for (auto item : Factions) {
				bs->Write<int32_t>(item);
			}

			bs->Write<bool>(Smashable);

			if (IsConstruction) {
				bs->Write0();
				bs->Write0();
				if (Smashable) {
					bs->Write0();
					bs->Write0();
				}
			}
			DirtyStats = false;
		}

		bs->Write0();
	}

	constexpr static uint32_t GetID() {
		return 117;
	}
};