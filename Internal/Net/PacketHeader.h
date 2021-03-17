#pragma once

#include <cstdint>

#pragma pack(push, 1)
struct PacketHeader {
	uint8_t RakPacketID;
	uint16_t RemoteConnection;
	uint32_t PacketID;
private:
	uint8_t Padding;
};
#pragma pack(pop)