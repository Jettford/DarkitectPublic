#pragma once

#include "../Component.h"

#include <Common/Structs/LNV.h>

class SpawnerComponent : public Component {
private:
	std::vector<Entity*> SpawnedObjects = std::vector<Entity*>();
	int32_t SpawnLOT;
	Position Spawn;

	void SpawnSpawnableObject() {
		Entity* SpawnedObject = new Entity(Owner->m_Server, SpawnLOT, GenerateObjectIDFromFlags(false, true, true, false), Owner->m_Config->Get<std::u16string>(u"npcName", u""), Owner->m_Config, Owner->m_Position, Owner->m_Rotation);
		SpawnedObject->IsSerializable = true;
		SpawnedObject->m_ObjectScale = Owner->m_ObjectScale;
		SpawnedObject->m_Spawner = Owner->m_ObjectID;
		SpawnedObject->m_SpawnerNodeID = 0; // nodes/networks need to be implemented at somepoint
		SpawnedObject->m_Server->m_ReplicaManager->AddObject(SpawnedObject);
	}

public:
	Position SpawnPoint;

	void Start(uint32_t ComponentID) override {
		SpawnLOT = Owner->m_Config->Get<int32_t>(u"spawntemplate");
		Spawn.Pos = Owner->m_Position;
		Spawn.Rot = Owner->m_Rotation;
		if (Owner->m_Config->Get<bool>(u"spawner_active_on_load", true)) {
			SpawnSpawnableObject();
		}
	}

	void Serialize(RakNet::BitStream* bs, bool IsContruction) override {
		
	}

	constexpr static uint32_t GetID() {
		return (uint32_t)Enums::ECOMPONENT_TYPE::SPAWNER_COMPONENT;
	}
};