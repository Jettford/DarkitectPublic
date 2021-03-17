#pragma once

#include "../Component.h"

class BouncerComponent : public Component {
private:
	bool IsPetBouncer;

public:
	void Start(uint32_t ComponentID) override {
		IsPetBouncer = Owner->m_LOT == 7625;
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		bs->Write(true);
		bs->Write(!IsPetBouncer); // Pet required 
		// Note: fuck it was inverted
	}

	constexpr static uint32_t GetID() {
		return (uint32_t)Enums::ECOMPONENT_TYPE::BOUNCER_COMPONENT;
	}
};