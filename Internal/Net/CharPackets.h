#pragma once

#include <vector>

#include <RakNet/MessageIdentifiers.h>
#include <RakNet/PacketPriority.h>
#include <RakNet/RakPeerInterface.h>

#include <Net/Enums/ERemoteConnection.h>
#include <Net/Enums/EPackets.h>

#include <Common/Utils.h>
#include <Common/Structs/ServerParts/Logger.h>
#include <Common/Structs/Character.h>
#include <Common/Structs/Account.h>
#include <Common/Global.h>
#include <Common/Structs/Servers/GameServer.h>

namespace CharPackets {
	void WriteMinifigList(RakPeerInterface* RakServer, std::vector<Character> Characters, Account account, SystemAddress address);
	void WriteCharCreateResponse(RakPeerInterface* RakServer, uint8_t response, SystemAddress address);
};

