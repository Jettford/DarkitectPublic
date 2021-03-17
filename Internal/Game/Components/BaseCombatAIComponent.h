#pragma once

#include "../Component.h"

class BaseCombatAIComponent : public Component {
private:
	bool IsStateDirty = true;

	LWOOBJID Target = 0;

	/// Combat states
	/// 0 - Idle
	/// 1 - Aggro
	/// 2 - Tether
	/// 3 - Spawn
	/// 4 - Dead
	
public:
	uint32_t State = 3;

	void Start(uint32_t ComponentID) override {
		
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		bs->Write(IsStateDirty);
		if (IsStateDirty) {
			bs->Write(State);
			bs->Write(Target);
			IsStateDirty = false;
		}

		if (State == 3) {
			State = 0;
			IsStateDirty = true;
			Owner->IsDirty = true;
		}
	}

	constexpr static uint32_t GetID() {
		return (int)Enums::ECOMPONENT_TYPE::BASE_COMBAT_AI_COMPONENT;
	}
};