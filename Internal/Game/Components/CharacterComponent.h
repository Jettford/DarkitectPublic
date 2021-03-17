#pragma once

#include <Common/Structs/NiPoint3.h>
#include <Common/Structs/NiQuaternion.h>
#include <Common/Structs/Character.h>
#include <Common/Utils.h>
#include <Common/Strings.h>

#include <Net/GameMessages/ServerGMs.h>
#include <Net/GameMessages/GMs.h>

#include "../Component.h"
#include "../Entity.h"

class CharacterComponent : public Component {
	bool m_Driving = false;
	LWOOBJID m_VehicleOBJID = 0ULL;

	bool m_HasLevel = true;
	uint32_t m_Level = 0;

	uint32_t m_CharID;
	Character m_CharData;
	
	bool m_LandingInRocket = false;

	std::u16string m_RocketData;

	bool m_IsPVPEnabled;

	uint32_t m_Activity = 0;

	SystemAddress Address;

	bool Flying = false;
public:
	void SetPlayerSystemAddress(SystemAddress _address) { Address = _address; }
	SystemAddress GetPlayerSystemAddress() { return Address; }

	void OnParseChatMessage(Entity* Sender, ClientGameMessages::ClientGameMessage* msg) {
		auto nmsg = (ClientGameMessages::ParseChatMessage*)msg;
		std::string MessageU8 = Strings::u16StringToString(nmsg->wsString);
		std::vector<std::string> Arguments = Utils::SplitU8String(MessageU8, ' ');
		if (Arguments.at(0) == "/fly" && m_CharData.GMLevel > 0) {
			Flying = !Flying;
			Logger::Log("Game", m_CharData.Name + " set their flying state to " + (Flying ? "True" : "False"));
			if (Flying) {
				ServerGameMessages::SetJetPackMode msg;
				msg.bBypassChecks = true;
				msg.bUse = true;
				msg.effectID = 167;
				msg.fAirspeed = 40;
				msg.fMaxAirspeed = 40;
				msg.fVertVel = 40;
				GameMessage::Send(Owner, Owner, msg);
			}
			else {
				ServerGameMessages::SetJetPackMode msg;
				msg.bUse = false;
				GameMessage::Send(Owner, Owner, msg);
			}
		}
	}

	void OnRequestUse(Entity* Sender, ClientGameMessages::ClientGameMessage* msg) {
		auto nmsg = (ClientGameMessages::RequestUse*)msg;
		if (nmsg->object == Owner->m_ObjectID) return;
		Sender->m_Server->m_ReplicaManager->GetObjectByObjectID(nmsg->object)->HandleGM(Sender, ClientGameMessages::RequestUse::GetID(), msg);
	}

	void Start(uint32_t ComponentID) override {
		RegisterGMHandler(ClientGameMessages::RequestUse::GetID(), (Component::GMHandler)&CharacterComponent::OnRequestUse);
		RegisterGMHandler(ClientGameMessages::ParseChatMessage::GetID(), (Component::GMHandler)&CharacterComponent::OnParseChatMessage);

		m_CharID = this->Owner->m_ObjectID & 0x00FFFFFFFFFFFFFFULL;
		m_CharData = this->Owner->m_Server->m_Database->GetCharacterByCharID(m_CharID);
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		bs->Write(true);

		bs->Write(m_Driving);
		if (m_Driving) {
			bs->Write(m_VehicleOBJID);
		}
		bs->Write<int8_t>(0);

		bs->Write(m_HasLevel);
		if (m_HasLevel) {
			bs->Write(m_Level);
		}

		bs->Write1();
		bs->Write0();
		bs->Write1();

		if (IsConstruction) {
			bs->Write0();
			bs->Write0();
			bs->Write0();
			bs->Write0();

			bs->Write<uint32_t>(m_CharData.HairColor);
			bs->Write<uint32_t>(m_CharData.HairStyle);
			bs->Write<uint32_t>(0);
			bs->Write<uint32_t>(m_CharData.ShirtColor);
			bs->Write<uint32_t>(m_CharData.PantsColor);
			bs->Write<uint32_t>(m_CharData.ShirtStyle);
			bs->Write<uint32_t>(0);
			bs->Write<uint32_t>(m_CharData.EyebrowStyle);
			bs->Write<uint32_t>(m_CharData.EyeStyle);
			bs->Write<uint32_t>(m_CharData.MouthStyle);
			bs->Write<uint64_t>(m_CharData.AccountID);
			bs->Write<uint64_t>(0);
			bs->Write<uint64_t>(0);
			bs->Write<uint64_t>(m_CharData.UScore);
			bs->Write0();

			for (int i = 0; i < 27; i++)
			{
				bs->Write((uint64_t)0);
			}

			bs->Write(false);
			bs->Write(m_LandingInRocket);
			if (m_LandingInRocket) {
				Utils::WStringToBitStream<uint16_t>(bs, m_RocketData);
			}
		}

		bs->Write1();

		bs->Write(m_IsPVPEnabled);
		bs->Write(m_CharData.GMLevel > 0);
		bs->Write<uint8_t>(m_CharData.GMLevel);
		bs->Write0();
		bs->Write<uint8_t>(0);

		bs->Write1();
		bs->Write(m_Activity);

		bs->Write0();
	}

	constexpr static uint32_t GetID() {
		return (int)Enums::ECOMPONENT_TYPE::CHARACTER_COMPONENT;
	}
};