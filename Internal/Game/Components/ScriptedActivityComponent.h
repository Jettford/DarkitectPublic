#pragma once

#include "../Component.h"

class ScriptedActivityComponent : public Component {
private:

public:

	float Information[10];

	std::vector<Entity*> Participants = std::vector<Entity*>();

	CDClientStructs::Activities Activity;
	
	void Start(uint32_t ComponentID) override {
		int32_t ActivityID = Owner->m_Config->Get<int32_t>(u"activityID", 0);
		if (ActivityID == 0) Logger::Log("ActivityComp", "Failed to load activity for LOT " + std::to_string(Owner->m_LOT)); return;
		if (ActivityID != ComponentID) throw std::exception();
		Logger::Log("ActivityComp", "Loaded activity " + std::to_string(ActivityID));
		std::vector<CDClientStructs::Activities> TempTable = std::vector<CDClientStructs::Activities>();
		std::copy_if(Owner->m_Server->m_CDClient->ActivitiesData.begin(), Owner->m_Server->m_CDClient->ActivitiesData.end(), std::back_inserter(TempTable), [&](CDClientStructs::Activities item) { return item.ActivityID == ActivityID; });
		if (TempTable.size() > 0) Activity = TempTable.at(0); 
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
		return (uint32_t)Enums::ECOMPONENT_TYPE::SCRIPTED_ACTIVITY_COMPONENT;
	}
};