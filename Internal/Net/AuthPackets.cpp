#include "AuthPackets.h"

void AuthPackets::WriteLoginResponse(RakPeerInterface* RakServer, SystemAddress address, const char* ip, uint16_t port, uint8_t ReponseCode, std::u16string SessionKey) {
	BITSTREAM;

	Utils::WriteConstruct(bs, 0x05, 0x00);

	bs.Write<uint8_t>(ReponseCode);

	Utils::FillZero(&bs, 264);
	bs.Write<uint16_t>(1);
	bs.Write<uint16_t>(10);
	bs.Write<uint16_t>(64);

	Utils::BufferedWStringToBitStream(&bs, SessionKey);
	Utils::BufferedStringToBitStream(&bs, ip);
	Utils::BufferedStringToBitStream(&bs, "");
	bs.Write<uint16_t>(port);
	bs.Write<uint16_t>(0);
	Utils::BufferedStringToBitStream(&bs, "", 33);
	Utils::BufferedStringToBitStream(&bs, "00000000-0000-0000-0000-000000000000", 37);
	bs.Write<uint32_t>(0);
	Utils::BufferedStringToBitStream(&bs, "US", 3);
	bs.Write<uint8_t>(false);
	bs.Write<uint8_t>(false);
	bs.Write<uint64_t>(0);

	bs.Write<std::uint16_t>(0);

	bs.Write<uint32_t>(0x0144);
	bs.Write<uint64_t>(0x0000000000000000);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x0000001c00000007);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x0000000300000008);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x0000000000000009);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x000000000000000a);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x000000010000000b);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x000000010000000e);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x000000000000000f);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x0000000100000011);	bs.Write<uint64_t>(0x000000004ee27a4d);
	bs.Write<uint64_t>(0x0000000000000005);	bs.Write<uint64_t>(0x000000004ee27a4d);
	bs.Write<uint64_t>(0x0000000100000006);	bs.Write<uint64_t>(0x000000004ee27a4d);
	bs.Write<uint64_t>(0x0000000100000014);	bs.Write<uint64_t>(0x000000004ee27a4d);
	bs.Write<uint64_t>(0x000029ca00000013);	bs.Write<uint64_t>(0x000000004ee27a4d);
	bs.Write<uint64_t>(0x0000000000000015);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x0000000000000016);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x000029c400000017);	bs.Write<uint64_t>(0x000000004ee27a4d);
	bs.Write<uint64_t>(0x000029c40000001b);	bs.Write<uint64_t>(0x000000004ee27a4d);
	bs.Write<uint64_t>(0x000000010000001c);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x000000000000001d);	bs.Write<uint64_t>(0x000000004ee27a4c);
	bs.Write<uint64_t>(0x000029ca0000001e);	bs.Write<uint64_t>(0x000000004ee27a4d);

	RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
}