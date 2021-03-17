#pragma once

#include "../Component.h"

#include <Net/GameMessages/GMs.h>

#include <Common/Structs/ServerParts/CDClient/CDClientStructs.h>

class VendorComponent : public Component {
private:
	
public:
	void UpdateVendorStatus(Entity* Target) {

	}

	void OnRequestUse(Entity* Sender, ClientGameMessages::ClientGameMessage* msg) {
		CharacterComponent* Comp = Sender->GetComponent<CharacterComponent>();
		if (Comp != nullptr) {
			GameMessage::Send(Sender, Owner->m_ObjectID, ServerGameMessages::VendorOpenWindow());
		}
	}

	void OnRequestVendorStatusUpdate(Entity* Sender, ClientGameMessages::ClientGameMessage* msg) {
		OnRequestUse(Sender, nullptr);
	}

	void Start(uint32_t ComponentID) override {
		RegisterGMHandler(ClientGameMessages::RequestVendorStatusUpdate::GetID(), (Component::GMHandler)&VendorComponent::OnRequestVendorStatusUpdate);
		RegisterGMHandler(ClientGameMessages::RequestUse::GetID(), (Component::GMHandler)&VendorComponent::OnRequestUse);
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		bs->Write1();
		bs->Write1();
		bs->Write0();
	}

	constexpr static uint32_t GetID() {
		return (uint32_t)Enums::ECOMPONENT_TYPE::VENDOR_COMPONENT;
	}
};