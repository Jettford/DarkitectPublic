#pragma once

#include "../Component.h"
#include "ScriptedActivityComponent.h"

class QuickbuildComponent : public Component {
private:
	float Information[10];

	std::vector<Entity*> Participants = std::vector<Entity*>();
	uint32_t ActivityID;
public:
	void Start(uint32_t ComponentID) override {
		ActivityID = Owner->m_Config->Get<int32_t>(u"activityID", 0);
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		bs->Write1();
		bs->Write<uint32_t>(Participants.size());
		for (const auto& item : Participants) {
			bs->Write<LWOOBJID>(item->m_ObjectID);
			for (uint8_t i = 0; i < 10; i++) bs->Write<float>(this->Information[i]);
		}
	}

	constexpr static uint32_t GetID() {
		return (uint32_t)Enums::ECOMPONENT_TYPE::REBUILD_COMPONENT;
	}
};