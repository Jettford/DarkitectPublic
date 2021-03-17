#include "WorldPackets.h"

void WorldPackets::WriteLoadZone(RakPeerInterface* RakServer, SystemAddress address, uint16_t ZoneID, uint16_t MapInstance, uint32_t MapClone, uint32_t MapChecksum, NiPoint3 Spawn, bool IsActivityWorld) {
	BITSTREAM;

	Utils::WriteConstruct(bs, 0x05, 0x02);

	bs.Write(ZoneID);
	bs.Write(MapInstance);
	bs.Write(MapClone);
	bs.Write(MapChecksum);
	bs.Write<uint16_t>(0);
	bs.Write(Spawn.X);
	bs.Write(Spawn.Y);
	bs.Write(Spawn.Z);
	bs.Write<uint32_t>(IsActivityWorld ? 4 : 0);

	RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
}

void WorldPackets::WriteTransferServer(RakPeerInterface* RakServer, SystemAddress address, const char* IP, uint16_t Port, bool IsDimensionalShift) {
	BITSTREAM;

	Utils::WriteConstruct(bs, 0x05, 0x0e);

	Utils::BufferedStringToBitStream(&bs, IP);

	bs.Write<uint16_t>(Port);
	bs.Write<uint8_t>(IsDimensionalShift);

	RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
}

void WorldPackets::WriteCreateCharacter(RakPeerInterface* RakServer, SystemAddress address, LWONameValueGroup* lnv) {
	BITSTREAM;
	
	Utils::WriteConstruct(bs, 0x05, 0x04);

	lnv->Serialize(&bs);

	RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
}