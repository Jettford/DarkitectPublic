#pragma once

#define ODBC_STATIC

#include "../../Global.h"

#include <odbc/Connection.h>
#include <odbc/Environment.h>
#include <odbc/Exception.h>
#include <odbc/PreparedStatement.h>
#include <odbc/ResultSet.h>

#include <string>

#include "../../SHA512.h"
#include "../Character.h"
#include "../Account.h"
#include "../Mission.h"
#include "Logger.h"
#include "Config.h"

class Database {
private:
	odbc::EnvironmentRef env;
	odbc::ConnectionRef conn;
public:
	void Connect(Config* config) {
		env = odbc::Environment::create();

		conn = env->createConnection();

		std::string DSN = config->m_Reader->Get("Master", "DSN", "Darkitect");
		std::string Username = config->m_Reader->Get("Master", "Username", "root");
		std::string Password = config->m_Reader->Get("Master", "Password", "");

		Logger::Log("Database", "Connecting to " + DSN + " with username " + Username);

		try {
			conn->connect(DSN.c_str(), Username.c_str(), Password.c_str());

			conn->setAutoCommit(true);
		}
		catch (odbc::Exception ex) {
			Logger::Log("Database", ex.what());
		}
	}

	void ClearSessionCache() {
		Logger::Log("Database", "Clearing session cache");
		
		odbc::PreparedStatementRef DropQuery = conn->prepareStatement("DROP TABLE SESSIONS");
		DropQuery->executeQuery();

		odbc::PreparedStatementRef CreateQuery = conn->prepareStatement("CREATE TABLE IF NOT EXISTS Sessions ( Username text, SessionKey text, CharID int)");
		CreateQuery->executeQuery();
	}

	void ClearServerList() {
		Logger::Log("Database", "Clearing Server list");

		odbc::PreparedStatementRef DropQuery = conn->prepareStatement("DROP TABLE Servers");
		DropQuery->executeQuery();

		odbc::PreparedStatementRef CreateQuery = conn->prepareStatement("CREATE TABLE IF NOT EXISTS Servers (WorldID int, Port int)");
		CreateQuery->executeQuery();
	}

	void CreateSession(const char* Username, const char* SessionKey) {
		odbc::PreparedStatementRef SessionQuery = conn->prepareStatement("INSERT INTO Sessions VALUES (?, ?, ?)");

		SessionQuery->setCString(1, Username);
		SessionQuery->setCString(2, SessionKey);
		SessionQuery->setUInt(3, 0);
		SessionQuery->executeQuery();
	}

	void SetSessionCharacter(const char* Username, uint32_t CharID) {
		odbc::PreparedStatementRef SessionQuery = conn->prepareStatement("UPDATE Sessions SET CharID = ? WHERE Username = ?");

		SessionQuery->setUInt(1, CharID);
		SessionQuery->setCString(2, Username);
		SessionQuery->executeQuery();
	}

	uint32_t GetCharIDFromUsername(const char* Username) {
		odbc::PreparedStatementRef SessionQuery = conn->prepareStatement("SELECT CharID FROM Sessions WHERE Username = ?");

		SessionQuery->setCString(1, Username);
		odbc::ResultSetRef rs = SessionQuery->executeQuery();
		if (rs->next()) {
			return *rs->getUShort(1);
		}
		return 0;
	}
	

	void CreateServer(uint16_t Port, uint16_t WorldID) {
		odbc::PreparedStatementRef ServerQuery = conn->prepareStatement("INSERT INTO Servers (WorldID, Port) VALUES (?, ?)");
		
		ServerQuery->setInt(1, WorldID);
		ServerQuery->setInt(2, Port);
		ServerQuery->executeQuery();
	}

	uint16_t GetServer(uint16_t WorldID) {
		odbc::PreparedStatementRef ServerQuery = conn->prepareStatement("SELECT * FROM Servers WHERE WorldID = ?");

		ServerQuery->setInt(1, WorldID);
		odbc::ResultSetRef rs = ServerQuery->executeQuery();
		if (rs->next()) {
			return *rs->getInt(2);
		}
		return 0;
	}

	uint16_t GetServerCount() {
		odbc::PreparedStatementRef ServerCountQuery = conn->prepareStatement("SELECT COUNT(*) FROM Servers");

		odbc::ResultSetRef rs = ServerCountQuery->executeQuery();
		if (rs->next()) {
			return *rs->getInt(1);
		}
	}

	bool CheckLogin(const char* Username, const char* Password) {
		odbc::PreparedStatementRef LoginQuery = conn->prepareStatement("SELECT * FROM Accounts WHERE Username = ?");
		LoginQuery->setCString(1, Username);
		odbc::ResultSetRef rs = LoginQuery->executeQuery();
		while (rs->next()) {
			if (sha512(Password) == *rs->getString(4)) {
				if (CheckSession(Username, Password)) return false;
				return true;
			}
		}
		return false;
	}

	bool CheckSession(const char* Username, const char* SessionKey) {
		odbc::PreparedStatementRef SessionQuery = conn->prepareStatement("SELECT * FROM Sessions WHERE Username = ?");

		SessionQuery->setCString(1, Username);
		odbc::ResultSetRef rs = SessionQuery->executeQuery();
		while (rs->next()) {
			if (SessionKey == *rs->getString(2)) {
				return true;
			}
		}
		return false;
	}

	int GetAccountIDByUsername(const char* Username) {
		odbc::PreparedStatementRef LoginQuery = conn->prepareStatement("SELECT * FROM Accounts WHERE Username = ?");
		LoginQuery->setCString(1, Username);
		odbc::ResultSetRef rs = LoginQuery->executeQuery();
		while (rs->next()) {
			return (int)*rs->getInt(1);
		}
		return 0;
	}

	void AddCharacterToDatabase(Character CurrentCharacter) {
		odbc::PreparedStatementRef CharCreateQuery = conn->prepareStatement("INSERT INTO Characters (AccountID, Name, UnapprovedName, ShirtColor, ShirtStyle, PantsColor, HairStyle, HairColor, LeftHand, RightHand, Eyebrows, Eyes, Mouth) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
		CharCreateQuery->setInt(1, CurrentCharacter.AccountID);
		CharCreateQuery->setCString(2, CurrentCharacter.Name.c_str());
		CharCreateQuery->setCString(3, CurrentCharacter.UnapprovedName.c_str());
		CharCreateQuery->setInt(4, CurrentCharacter.ShirtColor);
		CharCreateQuery->setInt(5, CurrentCharacter.ShirtStyle);
		CharCreateQuery->setInt(6, CurrentCharacter.PantsColor);
		CharCreateQuery->setInt(7, CurrentCharacter.HairStyle);
		CharCreateQuery->setInt(8, CurrentCharacter.HairColor);
		CharCreateQuery->setInt(9, CurrentCharacter.LeftHand);
		CharCreateQuery->setInt(10, CurrentCharacter.RightHand);
		CharCreateQuery->setInt(11, CurrentCharacter.EyebrowStyle);
		CharCreateQuery->setInt(12, CurrentCharacter.EyeStyle);
		CharCreateQuery->setInt(13, CurrentCharacter.MouthStyle);
		CharCreateQuery->executeQuery();
	}

	Account GetAccountByID(int ID) {
		odbc::PreparedStatementRef LoginQuery = conn->prepareStatement("SELECT * FROM Accounts WHERE ID = ?");
		LoginQuery->setInt(1, ID);
		odbc::ResultSetRef rs = LoginQuery->executeQuery();
		while (rs->next()) {
			Account currentAccount;
			currentAccount.Username = *rs->getString(2);
			currentAccount.Email = *rs->getString(3);
			currentAccount.Password = *rs->getString(4);
			currentAccount.FirstChar = *rs->getInt(5);
			return currentAccount;
		}
		return Account();
	}

	std::vector<Character> GetCharactersByAccountID(int ID) {
		odbc::PreparedStatementRef CharListQuery = conn->prepareStatement("SELECT * FROM Characters WHERE AccountID = ?");
		CharListQuery->setInt(1, ID);
		odbc::ResultSetRef rs = CharListQuery->executeQuery();
		std::vector<Character> chars = std::vector<Character>();
		while (rs->next()) {
			Character current;
			current.CharID = *rs->getInt(1);
			current.AccountID = *rs->getInt(2);
			current.Name = *rs->getString(3);
			current.UnapprovedName = *rs->getString(4);
			current.ShirtColor = *rs->getInt(5);
			current.ShirtStyle = *rs->getInt(6);
			current.PantsColor = *rs->getInt(7);
			current.HairStyle = *rs->getInt(8);
			current.HairColor = *rs->getInt(9);
			current.LeftHand = *rs->getInt(10);
			current.RightHand = *rs->getInt(11);
			current.EyebrowStyle = *rs->getInt(12);
			current.EyeStyle = *rs->getInt(13);
			current.MouthStyle = *rs->getInt(14);
			current.LastZone = *rs->getInt(15);
			current.Health = *rs->getInt(16);
			current.MaxHealth = *rs->getInt(17);
			current.Armor = *rs->getInt(18);
			current.MaxArmor = *rs->getInt(19);
			current.Imagination = *rs->getInt(20);
			current.MaxImagination = *rs->getInt(21);
			current.InventorySpace = *rs->getInt(22);
			current.UScore = *rs->getInt(23);
			current.GMLevel = *rs->getInt(24);
			current.Reputation = *rs->getInt(25);
			current.Level = *rs->getInt(26);
			current.X = *rs->getFloat(27);
			current.Y = *rs->getFloat(28);
			current.Z = *rs->getFloat(29);
			chars.push_back(current);
		}

		return chars;
	}

	Character GetCharacterByCharID(int ID) {
		odbc::PreparedStatementRef CharListQuery = conn->prepareStatement("SELECT * FROM Characters WHERE CharID = ?");
		CharListQuery->setInt(1, ID);
		odbc::ResultSetRef rs = CharListQuery->executeQuery();
		Character current;
		if (rs->next()) {
			current.CharID = *rs->getInt(1);
			current.AccountID = *rs->getInt(2);
			current.Name = *rs->getString(3);
			current.UnapprovedName = *rs->getString(4);
			current.ShirtColor = *rs->getInt(5);
			current.ShirtStyle = *rs->getInt(6);
			current.PantsColor = *rs->getInt(7);
			current.HairStyle = *rs->getInt(8);
			current.HairColor = *rs->getInt(9);
			current.LeftHand = *rs->getInt(10);
			current.RightHand = *rs->getInt(11);
			current.EyebrowStyle = *rs->getInt(12);
			current.EyeStyle = *rs->getInt(13);
			current.MouthStyle = *rs->getInt(14);
			current.LastZone = *rs->getInt(15);
			current.Health = *rs->getInt(16);
			current.MaxHealth = *rs->getInt(17);
			current.Armor = *rs->getInt(18);
			current.MaxArmor = *rs->getInt(19);
			current.Imagination = *rs->getInt(20);
			current.MaxImagination = *rs->getInt(21);
			current.InventorySpace = *rs->getInt(22);
			current.UScore = *rs->getInt(23);
			current.GMLevel = *rs->getInt(24);
			current.Reputation = *rs->getInt(25);
			current.Level = *rs->getInt(26);
			current.X = *rs->getFloat(27);
			current.Y = *rs->getFloat(28);
			current.Z = *rs->getFloat(29);
		}

		return current;
	}

	void DeleteCharacter(uint32_t ID) {
		odbc::PreparedStatementRef stmt = conn->prepareStatement("DELETE FROM Characters WHERE CharID = ?");
		stmt->setInt(1, ID);
		stmt->executeQuery();
	}

	bool HasMission(LWOOBJID CharID, uint32_t MissionID) {
		odbc::PreparedStatementRef stmt = conn->prepareStatement("SELECT MissionID FROM Missions WHERE MissionOwner = ?");
		stmt->setULong(1, CharID);
		odbc::ResultSetRef rs = stmt->executeQuery();
		while (rs->next()) {
			if (*rs->getInt(1) == MissionID) return true;
		}
		return false;
	}

	Mission GetMission(LWOOBJID CharID, uint32_t MissionID) {
		odbc::PreparedStatementRef stmt = conn->prepareStatement("SELECT * FROM Missions WHERE MissionOwner = ? AND MissionID = ?");
		stmt->setULong(1, CharID);
		stmt->setUInt(2, MissionID);
		odbc::ResultSetRef rs = stmt->executeQuery();
		while (rs->next()) {
			Mission mission;
			mission.ID = *rs->getUInt(1);
			mission.MissionID = *rs->getUInt(2);
			mission.State = *rs->getUInt(3);
			mission.CompletionCount = *rs->getUInt(4);
			mission.LastCompletion = *rs->getULong(5);
			mission.MissionOwner = *rs->getULong(6);
			return mission;
		}
	}

	void UpdateMission(Mission MissionData) {
		odbc::PreparedStatementRef stmt = conn->prepareStatement("UPDATE Missions SET State = ?, CompletionCount = ?, LastCompletion = ? WHERE MissionID = ? AND MissionOwner = ?");
		stmt->setUInt(1, MissionData.State);
		stmt->setUInt(2, MissionData.CompletionCount);
		stmt->setULong(3, MissionData.LastCompletion);
		stmt->setUInt(4, MissionData.MissionID);
		stmt->setULong(5, MissionData.MissionOwner);
		stmt->executeQuery();
	}

	void AddMission(Mission MissionData) {
		odbc::PreparedStatementRef stmt = conn->prepareStatement("INSERT INTO Missions (MissionID, State, CompletionCount, LastCompletion, MissionOwner) VALUES (?, ?, ?, ?, ?)");
		stmt->setUInt(1, MissionData.MissionID);
		stmt->setUInt(2, MissionData.State);
		stmt->setUInt(3, 0);
		stmt->setULong(4, 0);
		stmt->setULong(5, MissionData.MissionOwner);
		stmt->executeQuery();
	}

	std::vector<Mission> GetAllMissions(LWOOBJID CharID, std::vector<int32_t> MissionList) {
		std::vector<Mission> ReturnMissionList = std::vector<Mission>();

		std::string StringBuilder = "SELECT * FROM Missions WHERE MissionOwner = ? AND MissionID IN (";

		if (MissionList.size() != 0) StringBuilder += "?";
		for (int32_t i = 1; i < MissionList.size(); ++i) StringBuilder += ",?";
		StringBuilder += ")";

		odbc::PreparedStatementRef stmt = conn->prepareStatement(StringBuilder.c_str());

		stmt->setULong(1, CharID);
		uint32_t Index = 0;
		for (const auto& item : MissionList) {
			stmt->setInt((Index++) + 2, item);
		}

		odbc::ResultSetRef rs = stmt->executeQuery();

		while (rs->next()) {
			Mission mission;
			mission.ID = *rs->getUInt(1);
			mission.MissionID = *rs->getUInt(2);
			mission.State = *rs->getUInt(3);
			mission.CompletionCount = *rs->getUInt(4);
			mission.LastCompletion = *rs->getULong(5);
			mission.MissionOwner = *rs->getULong(6);
			ReturnMissionList.push_back(mission);
		}

		return ReturnMissionList;
	}
};