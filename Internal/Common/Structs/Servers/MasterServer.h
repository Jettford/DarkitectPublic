#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <unordered_map>

#include <RakNet/BitStream.h>
#include <RakNet/RakSleep.h>
#include <RakNet/RakPeerInterface.h>
#include <RakNet/MessageIdentifiers.h>
#include <RakNet/RakNetworkFactory.h>

#include <Net/Enums/EPackets.h>

#include <Common/Structs/ServerParts/Logger.h>
#include <Common/Structs/ServerParts/Database.h>
#include <Common/Structs/ServerParts/Config.h>
#include <Common/Utils.h>

class MasterServer {
private:

public:
	// Basic stuff
	Config* m_Config;
	time_t m_StartTime;

	// Server configuration
	uint16_t m_ServerPort;
	const char* m_ServerIP;
	const char* m_ServerName;

	// Database types
	Database* m_Database;

	// RakNet Stuff
	uint32_t m_AllowedConnections = 32;
	RakPeerInterface* m_RakServer = RakNetworkFactory::GetRakPeerInterface();

	std::unordered_map<std::string, Session>* m_LocalSessions = new std::unordered_map<std::string, Session>();

	// Mutex for threading
	std::mutex m_lock;

	MasterServer(const char* _ServerName, bool ConnectToMaster) : m_ServerName(_ServerName), m_StartTime(time(0)), m_Config(new Config()), m_Database(new Database()) {
		Logger::ServerName = m_ServerName;
		Logger::ServerStart = m_StartTime;
		Logger::LoadLogger();
		m_Config->Load();
		Utils::SetTitle(m_ServerName);
		m_Database = new Database();
		m_Database->Connect(m_Config);
	}

	~MasterServer() {
		delete m_Config;
		delete m_Database;
	}

	void Main();
};