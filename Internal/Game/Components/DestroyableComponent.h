#pragma once

#include "../Component.h"
#include "../Entity.h"
#include "StatsComponent.h"

#include <CppSQLite3/CppSQLite3.h>

class DestroyableComponent : public Component {
public:
	StatsComponent* m_StatsComp = nullptr;

	void Start(uint32_t ComponentID) override {
		m_StatsComp = (StatsComponent *)this->Owner->AddComponentByType(117);
		m_StatsComp->Start(ComponentID);

		GET_ROW_BY_ID(Owner->m_Server->m_CDClient, DestructibleComponent, ComponentID);

		m_StatsComp->Factions = std::vector<int32_t>();
		m_StatsComp->Factions.push_back(Row.faction);
		m_StatsComp->Health = Row.life;
		m_StatsComp->MaxHealth = Row.life;
		m_StatsComp->Armor = Row.armor;
		m_StatsComp->MaxArmor = Row.armor;
		m_StatsComp->Imagination = Row.imagination;
		m_StatsComp->MaxImagination = Row.imagination;
		m_StatsComp->Smashable = Row.isSmashable == 1;
		m_StatsComp->AbsorbstionPoints = 0;
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		if (IsConstruction) {
			bs->Write0();
			bs->Write0();
		}

		m_StatsComp->Serialize(bs, IsConstruction);
	}

	constexpr static uint32_t GetID() {
		return (uint32_t)Enums::ECOMPONENT_TYPE::DESTRUCTABLE_COMPONENT;
	}

};

