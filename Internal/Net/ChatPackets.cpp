#include "ChatPackets.h"

void ChatPackets::StringCheck(RakPeerInterface* RakServer, SystemAddress address, bool Approved, uint8_t Channel) {
	BITSTREAM;
	Utils::WriteConstruct(bs, 0x05, 0x3b);

	if (Approved) {
		bs.Write<uint8_t>(1);
		bs.Write<uint16_t>(0);
		bs.Write(Channel);
	}
	else {
		bs.Write<uint8_t>(0);
		bs.Write<uint16_t>(0);
		bs.Write(Channel);
	}

	RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
}

void ChatPackets::BroadcastMessage(RakPeerInterface* RakServer, uint8_t Channel, std::u16string Message, Entity* Sender) {
	BITSTREAM;

	Utils::WriteConstruct(bs, 0x02, 0x01);

	bs.Write<uint64_t>(0);
	bs.Write<uint8_t>(Channel);
	bs.Write<uint8_t>(Message.size() * 2);

	bs.Write<uint8_t>(0);
	bs.Write<uint8_t>(0);
	bs.Write<uint8_t>(0);
		
	if (Channel != 0x00) {
		Utils::BufferedWStringToBitStream(&bs, Sender->m_Name);
		bs.Write<LWOOBJID>(Sender->m_ObjectID);
	}
	else {
		Utils::BufferedWStringToBitStream(&bs, u"");
		bs.Write<LWOOBJID>(0);
	}

	bs.Write<uint16_t>(0);
	bs.Write<uint8_t>(0);

	Utils::BufferedWStringToBitStream(&bs, Message, Message.size() + 1);

	RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, UNASSIGNED_SYSTEM_ADDRESS, true);
}