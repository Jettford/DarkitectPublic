#pragma once

#include <unordered_map>

#include <Common/Global.h>

#include <Net/Enums/EComponents.h>
#include <Net/GameMessages/ClientGMs.h>

constexpr int ComponentOrder[27] = {
		108,
		61,
		1,
		3,
		20,
		30,
		40,
		7,
		23,
		26,
		4,
		17,
		5,
		9,
		60,
		48,
		25,
		49,
		16,
		6,
		39,
		71,
		75,
		42,
		2,
		107,
		69
};

class Entity;

class Component {
public:
	using GMHandler = void(Component::*)(Entity*, ClientGameMessages::ClientGameMessage*);
	Entity* Owner;
	std::unordered_map<uint32_t, GMHandler> GMHandlers = std::unordered_map<uint32_t, GMHandler>();
	

	constexpr static uint32_t GetID() { return -1; }
	virtual void Start(uint32_t ComponentID) = 0;
	virtual void Serialize(RakNet::BitStream* bs, bool IsConstruction) = 0;

	// Component Events
	// Note: These are not GM event but rather Entity events 

	virtual void OnUpdate() {}

	inline void RegisterGMHandler(uint32_t ID, GMHandler Handler) { GMHandlers.insert({ ID, Handler }); }
};
Component* CreateComponentByType(Entity* Owner, uint32_t ComponentType);

#include "Entity.h"