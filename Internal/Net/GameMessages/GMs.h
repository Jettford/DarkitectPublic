#pragma once

#include "ServerGMs.h"

#include <RakNet/MessageIdentifiers.h>

#include <Common/Structs/Servers/GameServer.h>

namespace GameMessage {
	template<typename T = ServerGameMessages::ServerGameMessage>
	static void Send(GameServer* Server, SystemAddress Address, LWOOBJID Target, T msg) {
		RakNet::BitStream bs = RakNet::BitStream();
		Utils::WriteConstruct(bs, 0x05, 0x0c);
		bs.Write(Target);
		bs.Write<uint16_t>(msg.GetID());
		msg.Serialize(&bs);
		Server->m_RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, Address, Address == UNASSIGNED_SYSTEM_ADDRESS ? true : false);
	}

	template<typename T = ServerGameMessages::ServerGameMessage>
	static void Send(Entity* TargetPlayer, LWOOBJID Target, T msg) {
		RakNet::BitStream bs = RakNet::BitStream();
		Utils::WriteConstruct(bs, 0x05, 0x0c);
		bs.Write(Target);
		bs.Write<uint16_t>(msg.GetID());
		msg.Serialize(&bs);
		TargetPlayer->m_Server->m_RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, TargetPlayer->GetComponent<CharacterComponent>()->GetPlayerSystemAddress(), false);
	}

	template<typename T = ServerGameMessages::ServerGameMessage>
	static void Send(Entity* TargetPlayer, Entity* Target, T msg) {
		Send(TargetPlayer, Target->m_ObjectID, msg);
	}
}