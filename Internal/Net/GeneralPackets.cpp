#include "GeneralPackets.h"

void GeneralPackets::WriteHandshake(RakPeerInterface* RakServer, SystemAddress address, bool IsAuth, uint32_t Version) {
	BITSTREAM;

	Utils::WriteConstruct(bs, 0x00, 0x00);
	  
	bs.Write<uint32_t>(Version);
	bs.Write<uint32_t>(0x93);
	bs.Write<uint32_t>(IsAuth ? 1 : 4);
	bs.Write<uint32_t>(0);
	bs.Write<uint16_t>(0xff);
	bs.Write("127.0.0.1", 33);

	RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
}

void GeneralPackets::WriteDisconnect(RakPeerInterface* RakServer, SystemAddress address, uint32_t reason) {
	BITSTREAM;

	Utils::WriteConstruct(bs, 0x00, 0x01);

	bs.Write<uint32_t>(reason);

	RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
}
