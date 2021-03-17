#pragma once

#include <Common/Global.h>

#include <RakNet/MessageIdentifiers.h>
#include <RakNet/PacketPriority.h>
#include <RakNet/RakPeerInterface.h>

#include <Net/Enums/ERemoteConnection.h>
#include <Net/Enums/EPackets.h>

#include <Common/Utils.h>

namespace GeneralPackets {
	void WriteHandshake(RakPeerInterface* RakServer, SystemAddress address, bool IsAuth, uint32_t Version);
	void WriteDisconnect(RakPeerInterface* RakServer, SystemAddress address, uint32_t reason);
}