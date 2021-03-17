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

#include <Files/LUZ/LUZFile.h>

#include "Common/Structs/LNV.h"

namespace WorldPackets {
	void WriteLoadZone(RakPeerInterface* RakServer, SystemAddress address, uint16_t ZoneID, uint16_t MapInstance, uint32_t MapClone, uint32_t MapChecksum, NiPoint3 Spawn, bool IsActivityWorld);
	void WriteTransferServer(RakPeerInterface* RakServer, SystemAddress address, const char* IP, uint16_t Port, bool IsDimensionalShift);
	void WriteCreateCharacter(RakPeerInterface* RakServer, SystemAddress address, LWONameValueGroup* lnv);
}
