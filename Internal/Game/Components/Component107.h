#pragma once

#include "../Component.h"

class Component107 : public Component {
public:
	void Start(uint32_t ComponentID) override {
		
	}

	void Serialize(RakNet::BitStream* bs, bool IsContruction) override {
		bs->Write1();
		bs->Write<LWOOBJID>(0);
	}

	constexpr static uint32_t GetID() {
		return (uint32_t)Enums::ECOMPONENT_TYPE::UNKNOWN_107_COMPONENT;
	}
};