#include <Common/Structs/Servers/MasterServer.h>

void MasterServer::Main()
{
	Logger::Log("Master", "Starting up...");

	m_ServerIP = "0.0.0.0";
	m_ServerPort = (uint16_t)m_Config->m_Reader->GetInteger("Master", "Port", 0);

	std::string PortRange = m_Config->m_Reader->Get("Master", "PortRange", "0-0");
	
	auto NextPort = std::stoul(PortRange.substr(0, PortRange.find("-")));
	auto WorldServerPortRangeEnd = std::stoul(PortRange.substr(PortRange.find("-") + 1, PortRange.length()));

	Logger::Log("Master", "Using port range: " + PortRange);

	m_Database->ClearSessionCache();
	m_Database->ClearServerList();

	SocketDescriptor socketDescriptor(1002, "0.0.0.0");
	m_RakServer->SetMaximumIncomingConnections(m_AllowedConnections);
	m_RakServer->SetIncomingPassword("Darkitect", 9);

	if (!m_RakServer->Startup(32, 30, &socketDescriptor, 1)) {
		Logger::Log("Master", "RakPeerInterface failed to be created, closing...");
		exit(-1);
	}
	else {
		try {

			// 0 - AuthServer/CharServer
			// * - WorldServer

			std::system(std::string("start GameServer.exe " + std::to_string(1001) + " 0").c_str());
			std::system(std::string("start GameServer.exe " + std::to_string(2000) + " 0").c_str());
		}
		catch (std::exception& ex) {
			Logger::Log("Master", ex);
		}
	}
	

	Packet* packet;
	while (true) {
		RakSleep(1);
		while (packet = m_RakServer->Receive()) {
			RakNet::BitStream bs = RakNet::BitStream(packet->data, packet->length, false);
			switch (*packet->data) {
			case ID_USER_PACKET_ENUM: {
				Logger::Log("Master", "Recieved handshake");
			} break;

			case ID_NEW_INCOMING_CONNECTION: {
				Logger::Log("Master", "Recieving new Connection");
			} break;

			case ID_DISCONNECTION_NOTIFICATION: {
				Logger::Log("Master", "User Disconnected from auth");
			} break;
			}
			m_RakServer->DeallocatePacket(packet);
		}
	}

	m_RakServer->Shutdown(0);
	RakNetworkFactory::DestroyRakPeerInterface(m_RakServer);
}

int main(int argc, char* argv[]) {
	MasterServer server = MasterServer("MasterServer", false);
	server.Main();

	while (true) { // game loop
		RakSleep(30);
	}
	return 0;
}