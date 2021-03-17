#pragma once

#include <Common/Global.h>

#include <RakNet/MessageIdentifiers.h>
#include <RakNet/PacketPriority.h>
#include <RakNet/RakPeerInterface.h>

#include <Net/Enums/ERemoteConnection.h>
#include <Net/Enums/EPackets.h>

#include <Common/Utils.h>

#include <Game/Entity.h>

namespace ChatPackets {
	void StringCheck(RakPeerInterface* RakServer, SystemAddress address, bool Approved, uint8_t Channel);
	void BroadcastMessage(RakPeerInterface* RakServer, uint8_t Channel, std::u16string Message, Entity* Sender);
}