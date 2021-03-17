#include <Common/Structs/Servers/GameServer.h>

#include <Game/Entity.h>
#include <Game/Components/ControllablePhysicsComponent.h>
#include <Game/Components/CharacterComponent.h>
#include <Game/Components/ScriptComponent.h>
#include <Game/Systems/Characters/CharacterXML.h>

#include <Net/GameMessages/GMs.h>
#include <Net/GameMessages/GMHandler.h>

#include <thread>
#include <string>

void GameServer::Main(int Port, int WorldID) {
	Logger::Log("Game", "Starting up... on " + m_Config->m_Reader->Get("Master", "IP", "127.0.0.1") + ":" + std::to_string(Port));

	m_ServerPort = Port;
	m_ZoneID = WorldID;

	SocketDescriptor socketDescriptor(m_ServerPort, "0.0.0.0");
	m_RakServer->SetIncomingPassword("3.25 ND1", 8);
	m_RakServer->SetMaximumIncomingConnections(m_AllowedConnections);

	if (!m_RakServer->Startup(32, 30, &socketDescriptor, 1)) {
		Logger::Log("Game", "RakPeerInterface failed to be created, closing...");
		exit(-1);
	}

	if (m_ZoneID != 0) {
		auto query = m_CDClient->compileStatement("SELECT * FROM ZoneTable WHERE zoneID = ?");
		query.bind(1, std::to_string(WorldID).c_str());
		auto rs = query.execQuery();
		m_LUZ = LUZFile(std::string("res/maps/").append(rs.fieldValue("zoneName")).c_str());
		Logger::Log("Game", std::string("Loaded LUZ file: res/maps/") + rs.fieldValue("zoneName"));
		
		auto zoneTemplate = rs.getIntField("zoneControlTemplate", 0);
		if (zoneTemplate != 0) {
			auto config = new LWONameValueGroup();
			Entity* ZoneObject = new Entity(this, zoneTemplate, 0x3FFFFFFFFFFE, u"", config, NiPoint3(), NiQuaternion());
			ZoneObject->AddComponentByType((uint32_t)Enums::ECOMPONENT_TYPE::SCRIPT_COMPONENT)->Start(rs.getIntField("scriptID", -1));
			m_ReplicaManager->AddObject(ZoneObject);
		}

		for (const auto& Scene : m_LUZ.Scenes) {
			for (const auto& Object : Scene.SceneFile.Objects.Objects) {
				auto config = new LWONameValueGroup();
				config->FromU16String(Object.Config);
				Entity* SpawnedObject = new Entity(this, Object.LOT, 70368744177664ULL | Object.ObjectID, u"", config, Object.SpawnPosition.Pos, Object.SpawnPosition.Rot);
				SpawnedObject->m_ObjectScale = Object.Scale;
				m_ReplicaManager->AddObject(SpawnedObject);
			}
		}
		Logger::Log("Game", "Loaded " + std::to_string(m_ReplicaManager->GetObjectCount()) + " Objects");
	}

	Packet* packet;

	while (true) {
		RakSleep(1);
		while (packet = m_RakServer->Receive()) {
			RakNet::BitStream bs = RakNet::BitStream(packet->data, packet->length, false);
			switch (packet->data[0]) {
			case ID_USER_PACKET_ENUM: {
				PacketHeader header; bs.Read(header);
				//printf("[00-00-00] [Game] Recieved packet %02x-%02x-00-%02x \n", header.RakPacketID, header.RemoteConnection, header.PacketID);
				switch (static_cast<Enums::ERemoteConnection>(header.RemoteConnection)) {
				case Enums::ERemoteConnection::GENERAL: {
					GeneralPackets::WriteHandshake(m_RakServer, packet->systemAddress, m_ServerPort == 1001, bs.Read<uint32_t>().second);
					Logger::Log("Game", "Sent handshake");
				} break;

				case Enums::ERemoteConnection::AUTH: {
					if ((Enums::EAuthPacketID)header.PacketID == Enums::EAuthPacketID::LOGIN_RESPONSE) {
						std::u16string Username = Utils::WStringFromBitStream(&bs, 33);
						std::u16string Password = Utils::WStringFromBitStream(&bs, 41);

						Logger::Log("Game", "Recieved login request from " + std::string(Username.begin(), Username.end()));

						auto SessionKey = Strings::StringToU16String(Strings::RandomString(32));
						SessionKey.append(u"\0");
						uint8_t ResponseCode = 0x06;

						if (m_Database->CheckLogin(Strings::u16StringToString(Username).c_str(), Strings::u16StringToString(Password).c_str())) ResponseCode = 0x01;

						AuthPackets::WriteLoginResponse(m_RakServer, packet->systemAddress, m_Config->m_Reader->Get("Master", "IP", "127.0.0.1").c_str(), 2000, ResponseCode, SessionKey);

						if (ResponseCode == 0x01) {
							m_Database->CreateSession(Strings::u16StringToString(Username).c_str(), Strings::u16StringToString(SessionKey).c_str());
						}
					}
				} break;
				case Enums::ERemoteConnection::SERVER: {
					switch (static_cast<Enums::EWorldPacketID>(header.PacketID)) {
					case Enums::EWorldPacketID::CLIENT_STRING_CHECK: {
						bs.IgnoreBytes(1);
						ChatPackets::StringCheck(m_RakServer, packet->systemAddress, true, bs.Read<uint8_t>().second);
					} break;
					case Enums::EWorldPacketID::CLIENT_GENERAL_CHAT_MESSAGE: {
						bs.IgnoreBytes(3);
						std::u16string Message = Utils::WStringFromBitStream<uint32_t>(&bs);
						auto player = m_ReplicaManager->GetObjectByObjectID(0x1000000000000000 | (m_LocalSessions->find(std::string(packet->systemAddress.ToString()))->second.m_Char.CharID & 0xffffffff));
						ChatPackets::BroadcastMessage(m_RakServer, 0x04, Message, player);
					} break;
					case Enums::EWorldPacketID::CLIENT_VALIDATION: {
						Logger::Log("Game", "Recieved client validation");
						std::u16string Username = Utils::WStringFromBitStream(&bs, 33);
						std::u16string SessionKey = Utils::WStringFromBitStream(&bs, 33);
						std::string FDBChecksum = Utils::StringFromBitStream(&bs, 33);

						bool IsGood = m_Database->CheckSession(Strings::u16StringToString(Username).c_str(), Strings::u16StringToString(SessionKey).c_str());

						if (!IsGood) {
							GeneralPackets::WriteDisconnect(m_RakServer, packet->systemAddress, 0x07);
							break;
						}

						auto CurrentCharacter = m_Database->GetCharacterByCharID(m_Database->GetCharIDFromUsername(Strings::u16StringToString(Username).c_str()));

						m_LocalSessions->insert({ std::string(packet->systemAddress.ToString()), Session{ Strings::u16StringToString(Username), SessionType::Client, CurrentCharacter }});

						if (m_ZoneID != 0) {
							WorldPackets::WriteLoadZone(m_RakServer, packet->systemAddress, CurrentCharacter.LastZone, 0, 0, m_LUZ.checksum.result(), m_LUZ.SpawnPos, false);
						}

						// TODO: Check the FDB Checksum for integrity 

					} break;
					case Enums::EWorldPacketID::CLIENT_CHARACTER_LIST_REQUEST: {
						Logger::Log("Game", "Recieved character list request");
						int accountID = m_Database->GetAccountIDByUsername(m_LocalSessions->find(std::string(packet->systemAddress.ToString()))->second.m_Name.c_str());
						CharPackets::WriteMinifigList(m_RakServer, m_Database->GetCharactersByAccountID(accountID), m_Database->GetAccountByID(accountID), packet->systemAddress);
					} break;
					case Enums::EWorldPacketID::CLIENT_CHARACTER_DELETE_REQUEST: {
						m_Database->DeleteCharacter(bs.Read<int64_t>().second & 0x00FFFFFFFFFFFFFFULL);
					} break;
					case Enums::EWorldPacketID::CLIENT_CHARACTER_CREATE_REQUEST: {
						Character CurrentCharacter;

						CurrentCharacter.AccountID = m_Database->GetAccountIDByUsername(m_LocalSessions->find(std::string(packet->systemAddress.ToString()))->second.m_Name.c_str());

						CurrentCharacter.UnapprovedName = Strings::u16StringToString(Utils::WStringFromBitStream(&bs, 33));

						uint32_t FirstName = bs.Read<uint32_t>().second;
						uint32_t SecondName = bs.Read<uint32_t>().second;
						uint32_t ThirdName = bs.Read<uint32_t>().second;

						bs.IgnoreBytes(9);

						CurrentCharacter.ShirtColor = bs.Read<uint32_t>().second;
						CurrentCharacter.ShirtStyle = bs.Read<uint32_t>().second;
						CurrentCharacter.PantsColor = bs.Read<uint32_t>().second;
						CurrentCharacter.HairStyle = bs.Read<uint32_t>().second;
						CurrentCharacter.HairColor = bs.Read<uint32_t>().second;
						CurrentCharacter.LeftHand = bs.Read<uint32_t>().second;
						CurrentCharacter.RightHand = bs.Read<uint32_t>().second;
						CurrentCharacter.EyebrowStyle = bs.Read<uint32_t>().second;
						CurrentCharacter.EyeStyle = bs.Read<uint32_t>().second;
						CurrentCharacter.MouthStyle = bs.Read<uint32_t>().second;

						std::string NameOne = Utils::ReadLineOfTextFile("res/names/minifigname_first.txt", FirstName + 1);
						std::string NameTwo = Utils::ReadLineOfTextFile("res/names/minifigname_middle.txt", SecondName + 1);
						std::string NameThree = Utils::ReadLineOfTextFile("res/names/minifigname_last.txt", ThirdName + 1);

						CurrentCharacter.Name = NameOne + NameTwo + NameThree;
						CurrentCharacter.LastZone = 1000;

						m_Database->AddCharacterToDatabase(CurrentCharacter);
						CharPackets::WriteCharCreateResponse(m_RakServer, 0x00, packet->systemAddress);
						CharPackets::WriteMinifigList(m_RakServer, m_Database->GetCharactersByAccountID(CurrentCharacter.AccountID), m_Database->GetAccountByID(CurrentCharacter.AccountID), packet->systemAddress);

						Logger::Log("Game", "Created character " + CurrentCharacter.Name);

					} break;
					case Enums::EWorldPacketID::CLIENT_LOGIN_REQUEST: {
						Logger::Log("Game", "Recieved login request");
						Character chara = m_Database->GetCharacterByCharID(bs.Read<int64_t>().second & 0x00FFFFFFFFFFFFFFULL);
						m_Database->SetSessionCharacter(m_LocalSessions->find(std::string(packet->systemAddress.ToString()))->second.m_Name.c_str(), chara.CharID);
						WorldPackets::WriteTransferServer(m_RakServer, packet->systemAddress, m_Config->m_Reader->Get("Master", "IP", "127.0.0.1").c_str(), Utils::GetGameInstance(m_Database, m_Config, chara.LastZone), false);
					} break;
					case Enums::EWorldPacketID::CLIENT_LEVEL_LOAD_COMPLETE: {
						uint16_t ZoneID = bs.Read<uint16_t>().second;
						uint16_t MapInstance = bs.Read<uint16_t>().second;
						uint32_t MapClone = bs.Read<uint32_t>().second;

						// Send CreateCharacter

						auto session = m_LocalSessions->find(std::string(packet->systemAddress.ToString()))->second;

						LWONameValueGroup lnv = LWONameValueGroup();
						Entity* Player = new Entity(this, 1, 0x1000000000000000 | (session.m_Char.CharID & 0xffffffff), Strings::StringToU16String(session.m_Char.Name), &lnv, m_LUZ.SpawnPos, m_LUZ.SpawnRot);
						Player->IsSerializable = true;
						Player->GetComponent<CharacterComponent>()->SetPlayerSystemAddress(packet->systemAddress);

						lnv.Insert(u"template", LWONameValue{ 1, (int32_t)1 });
						lnv.Insert(u"objid", LWONameValue{ 9, Player->m_ObjectID });
						lnv.Insert(u"name", LWONameValue{ 0, Player->m_Name });

						WorldPackets::WriteCreateCharacter(m_RakServer, packet->systemAddress, &lnv);

						m_ReplicaManager->RegisterTarget(packet->systemAddress);
						m_ReplicaManager->AddObject(Player);

						GameMessage::Send(this, packet->systemAddress, Player->m_ObjectID, ServerGameMessages::PlayerReady{});
						
						GameMessage::Send(this, packet->systemAddress, Player->m_ObjectID, ServerGameMessages::ServerDoneLoadingAllObjects{});
					} break;
					case Enums::EWorldPacketID::CLIENT_POSITION_UPDATE: {
						auto player = m_ReplicaManager->GetObjectByObjectID(0x1000000000000000 | (m_LocalSessions->find(std::string(packet->systemAddress.ToString()))->second.m_Char.CharID & 0xffffffff));
						player->GetComponent<ControllablePhysicsComponent>()->ReadPositionUpdate(&bs);
					} break;
					case Enums::EWorldPacketID::CLIENT_GAME_MSG: {
						auto player = m_ReplicaManager->GetObjectByObjectID(0x1000000000000000 | (m_LocalSessions->find(std::string(packet->systemAddress.ToString()))->second.m_Char.CharID & 0xffffffff));
						ClientGameMessages::HandleGameMessage(player, &bs);
					} break;
					}
				} break;

				}

			} break;

			case ID_NEW_INCOMING_CONNECTION: {
				Logger::Log("Game", "Recieving new Connection");
			} break;

			case ID_DISCONNECTION_NOTIFICATION: {
				Logger::Log("Game", "Recieving disconnection");
				try {
					m_LocalSessions->erase(std::string(packet->systemAddress.ToString()));
				}
				catch (...) {}
			} break;
			}
			m_RakServer->DeallocatePacket(packet);
		}
	}

	m_RakServer->Shutdown(0);
	RakNetworkFactory::DestroyRakPeerInterface(m_RakServer);
}

int main(int argc, char* argv[]) {
	GameServer server = GameServer((std::string("GameServer_") + argv[1]).c_str(), false);
	std::thread HandleThread([&]() { server.Main(std::stoi(argv[1]), std::stoi(argv[2])); });

	server.m_Database->CreateServer(std::stoi(argv[1]), std::stoi(argv[2]));

	while (true) { // game loop
		RakSleep(30);
		server.m_ReplicaManager->Update();
	}

	return 0;
}