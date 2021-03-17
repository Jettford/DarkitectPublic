#pragma once

#include "../Component.h"

class InventoryComponent : public Component {
public:

	void Start(uint32_t ComponentID) override {

	}

	void Serialize(RakNet::BitStream* bs, bool IsContruction) override {
		bs->Write1();
		bs->Write<uint32_t>(0);
		bs->Write0();
	}

	constexpr static uint32_t GetID() {
		return (uint32_t)Enums::ECOMPONENT_TYPE::INVENTORY_COMPONENT;
	}
};