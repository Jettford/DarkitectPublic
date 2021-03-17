#pragma once

#include <vector>
#include <unordered_map>
#include <sstream>

#include <Common/Global.h>
#include <Common/Utils.h>
#include <Common/Structs/LNV.h>
#include <Common/Structs/NiPoint3.h>
#include <Common/Structs/NiQuaternion.h>

#include <CppSQLite3/CppSQLite3.h>

#include "Component.h"

class GameServer;

class Entity {
private:

public:
	GameServer* m_Server;

	// Data for base data;
	LWOOBJID m_ObjectID;
	uint32_t m_LOT;
	std::u16string m_Name;

	uint16_t m_NetworkID;

	NiPoint3 m_Position;
	NiQuaternion m_Rotation;

	LWONameValueGroup* m_Config = nullptr;
	
	uint32_t m_TimeSinceCreatedOnServer = 0;

	// TODO: Additional LNV
	LWONameValueGroup* ExtraInfo = nullptr;

	LWOOBJID m_Spawner = 0;

	uint32_t m_SpawnerNodeID = 0;
	float m_ObjectScale = 1.0f;
	uint8_t m_ObjectWorldState = 0;
	uint8_t m_GMLevel = 0;

	Entity* m_Parent = nullptr;
	std::vector<Entity*> m_Children = std::vector<Entity*>();
	std::unordered_map<uint32_t, Component*> m_Components = std::unordered_map<uint32_t, Component*>();
	
	bool IsDirty = true;
	bool IsSerializable = false;

	void Serialize(RakNet::BitStream* bs, bool IsConstruction);

	template <class T = Component>
	Component* AddComponent();

	void AddComponent(Component* comp);

	Component* AddComponentByType(uint32_t Type);

	template <class T = Component>
	inline T* GetComponent() { return (T*)this->m_Components.at(T::GetID()); }

	template <class T = Component>
	inline bool HasComponent() { return this->m_Components.find(T::GetID()) != this->m_Components.end(); }

	void HandleGM(Entity* Sender, uint16_t ID, ClientGameMessages::ClientGameMessage* GM);

	void Update();

	Entity(GameServer* Server, uint32_t LOT, LWOOBJID ObjectID, std::u16string Name, LWONameValueGroup* Config, NiPoint3 Position, NiQuaternion Rotation);

	~Entity();
};

#include <Common/Structs/Servers/GameServer.h>