#include "CharPackets.h"

void CharPackets::WriteMinifigList(RakPeerInterface* RakServer, std::vector<Character> Characters, Account account, SystemAddress address) {
	BITSTREAM;

	Utils::WriteConstruct(bs, 0x05, 0x06);

	Logger::Log("Game", "Sending " + std::to_string(Characters.size()) + " characters");

	bs.Write<uint8_t>(Characters.size() & 0xff);
	bs.Write<uint8_t>(0);

	for (int i = 0; i < Characters.size(); ++i) {
		auto item = Characters.at(i);
		bs.Write<LWOOBJID>(0x1000000000000000 | (item.CharID & 0xffffffff)); // ObjectID
		bs.Write<uint32_t>(i);
		auto Name1 = std::u16string(item.Name.begin(), item.Name.end());
		auto Name2 = std::u16string(item.UnapprovedName.begin(), item.UnapprovedName.end());
		Utils::BufferedWStringToBitStream(&bs, Name1, 33);
		Utils::BufferedWStringToBitStream(&bs, Name2, 33);
		bs.Write<uint16_t>(0);
		bs.Write<int32_t>(0);
		bs.Write<uint16_t>(0);
		bs.Write<int32_t>(0);
		bs.Write<int32_t>(item.ShirtColor);
		bs.Write<int32_t>(item.ShirtStyle);
		bs.Write<int32_t>(item.PantsColor);
		bs.Write<int32_t>(item.HairStyle);
		bs.Write<int32_t>(item.HairColor);
		bs.Write<int32_t>(item.LeftHand);
		bs.Write<int32_t>(item.RightHand);
		bs.Write<int32_t>(item.EyebrowStyle);
		bs.Write<int32_t>(item.EyeStyle);
		bs.Write<int32_t>(item.MouthStyle);
		bs.Write<int32_t>(0);
		bs.Write<uint16_t>(item.LastZone == 1000 ? 0 : item.LastZone);
		bs.Write<uint16_t>(0);
		bs.Write<uint32_t>(0);
		bs.Write<uint64_t>(0ULL);

		std::vector<int32_t> EquippedItems = std::vector<int32_t>();

		bs.Write<uint16_t>(EquippedItems.size());

		for (auto item : EquippedItems) {
			bs.Write<uint32_t>(item);
		}
	}

	RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
}

void CharPackets::WriteCharCreateResponse(RakPeerInterface* RakServer, uint8_t response, SystemAddress address) {
	BITSTREAM;

	Utils::WriteConstruct(bs, 0x05, 0x07);
	bs.Write<uint8_t>(response);

	RakServer->Send(&bs, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, false);
}