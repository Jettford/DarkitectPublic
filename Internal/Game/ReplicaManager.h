#pragma once

#include <RakNet/MessageIdentifiers.h>

#include "Entity.h"

class ReplicaManager {
	std::unordered_map<uint16_t, Entity*>* Objects = new std::unordered_map<uint16_t, Entity*>();
	std::vector<SystemAddress>* Targets = new std::vector<SystemAddress>();
	RakPeerInterface* m_RakServer;
	uint16_t ReservedNetworkIDs = 1;
public:
	void SetRakServer(RakPeerInterface* Server) {
		m_RakServer = Server;
	}

	uint32_t GetObjectCount() {
		return Objects->size();
	}

	Entity* GetObjectByObjectID(LWOOBJID ID) {
		for (const auto& item : *Objects) {
			if (item.second->m_ObjectID == ID) {
				return item.second;
			}
		}
		return nullptr;
	}

	void AddObject(Entity* Object) {
		Objects->insert({ ReservedNetworkIDs, Object });
		Object->m_NetworkID = ReservedNetworkIDs;

		if (Object->IsSerializable) {
			RakNet::BitStream bs = RakNet::BitStream(); // Construction packet;

			bs.Write<uint8_t>(0x24);
			bs.Write1();
			bs.Write<uint16_t>(ReservedNetworkIDs);
			Object->Serialize(&bs, true);

			for (const auto& address : *Targets)
				m_RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
		}
		ReservedNetworkIDs += 1;
	}

	void RemoveObject(Entity* Object) {
		Objects->erase(Object->m_NetworkID);

		if (Object->IsSerializable) {
			RakNet::BitStream bs = RakNet::BitStream();

			bs.Write<uint8_t>(0x25);
			bs.Write<uint16_t>(Object->m_NetworkID);

			for (const auto& address : *Targets)
				m_RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
		}

		delete Object;
	}

	void RemoveObject(LWOOBJID ObjectID) {
		for (const auto& item : *Objects) {
			if (item.second->m_ObjectID == ObjectID) {
				RemoveObject(item.second);
			}
		}
	}
	
	void RegisterTarget(SystemAddress Address) {
		Targets->push_back(Address);
		for (const auto& item : *Objects) {
			if (!item.second->IsSerializable) continue;
			Logger::Log("Game", "Serializing Object : " + std::to_string(item.second->m_LOT) + " / " + std::to_string(item.second->m_ObjectID));
			RakNet::BitStream bs = RakNet::BitStream(); // Construction packet;

			bs.Write<uint8_t>(0x24);
			bs.Write1();
			bs.Write<uint16_t>(item.second->m_NetworkID);
			item.second->Serialize(&bs, true);

			m_RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, Address, false);
		}
	}

	void Update() { // this is a very hot code path, keep as efficient as possible
		for (const auto& item : *Objects) {
			item.second->Update();

			if (item.second->IsDirty && item.second->IsSerializable) { 
				RakNet::BitStream bs = RakNet::BitStream();

				bs.Write<uint8_t>(0x27);
				bs.Write<uint16_t>(item.second->m_NetworkID);
				item.second->Serialize(&bs, false);

				for (const auto& address : *Targets)
					m_RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
			}
		}
	}
};