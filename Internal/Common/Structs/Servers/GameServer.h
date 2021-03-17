#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <unordered_map>
#include <random>

#include <Common/Utils.h>
#include <Common/Strings.h>
#include <Common/Structs/Character.h>
#include <Common/Structs/ServerParts/Logger.h>
#include <Common/Structs/ServerParts/Database.h>
#include <Common/Structs/ServerParts/Config.h>
#include <Common/Structs/ServerParts/CDClient.h>

#include <Net/PacketHeader.h>
#include <Net/GeneralPackets.h>
#include <Net/AuthPackets.h>
#include <Net/CharPackets.h>
#include <Net/WorldPackets.h>
#include <Net/ChatPackets.h>

#include <Files/LUZ/LUZFile.h>

#include <Game/ReplicaManager.h>

#include <RakNet/BitStream.h>
#include <RakNet/RakSleep.h>
#include <RakNet/RakPeerInterface.h>
#include <RakNet/MessageIdentifiers.h>
#include <RakNet/RakNetworkFactory.h>

class GameServer {
private:

public:
	// Basic stuff
	Config* m_Config;
	time_t m_StartTime;

	// Server configuration
	uint16_t m_ServerPort;
	uint32_t m_ZoneID;
	const char* m_ServerName;

	// Database types
	Database* m_Database;
	CDClient* m_CDClient;

	// RakNet Stuff
	uint32_t m_AllowedConnections = 32;
	RakPeerInterface* m_RakServer = RakNetworkFactory::GetRakPeerInterface();
	ReplicaManager* m_ReplicaManager = new ReplicaManager();

	std::unordered_map<std::string, Session>* m_LocalSessions = new std::unordered_map<std::string, Session>();

	// Game Server stuff
	LUZFile m_LUZ;

	// Mutex for threading
	std::mutex m_lock;

	GameServer(const char* _ServerName, bool ConnectToMaster) : m_ServerName(_ServerName), m_StartTime(time(0)), m_Config(new Config()), m_Database(new Database()) {
		Logger::ServerName = m_ServerName;
		Logger::ServerStart = m_StartTime;
		Logger::LoadLogger();
		m_Config->Load();
		Utils::SetTitle(m_ServerName);
		m_Database = new Database();
		m_Database->Connect(m_Config);
		m_CDClient = new CDClient();
		m_CDClient->Open();
		m_ReplicaManager->SetRakServer(m_RakServer);
	}

	~GameServer() {
		delete m_Config;
		delete m_Database;
		delete m_CDClient;
	}

	void Main(int Port, int WorldID);
};