#pragma once

#include <Common/Global.h>

#include <RakNet/MessageIdentifiers.h>
#include <RakNet/PacketPriority.h>
#include <RakNet/RakPeerInterface.h>

#include <Net/Enums/ERemoteConnection.h>
#include <Net/Enums/EPackets.h>

#include <Common/Utils.h>
#include <Common/SHA512.h>

namespace AuthPackets {
	void WriteLoginResponse(RakPeerInterface* server, SystemAddress address, const char* ip, uint16_t port, uint8_t ReponseCode, std::u16string SessionKey);
}

