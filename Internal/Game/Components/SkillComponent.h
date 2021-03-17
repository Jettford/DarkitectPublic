#pragma once

#include "../Component.h"

#include <Net/GameMessages/GMs.h>

class SkillComponent : public Component {
public:

	void OnStartSkill(Entity* Sender, ClientGameMessages::ClientGameMessage* msg) {

	}

	void Start(uint32_t ComponentID) override {
		RegisterGMHandler(ClientGameMessages::StartSkill::GetID(), (Component::GMHandler)&SkillComponent::OnStartSkill);
	}

	void Serialize(RakNet::BitStream* bs, bool IsContruction) override {
		if (IsContruction) {
			bs->Write1();
			bs->Write<uint32_t>(0);
		}
	}

	constexpr static uint32_t GetID() {
		return (int)Enums::ECOMPONENT_TYPE::SKILL_COMPONENT;
	}
};