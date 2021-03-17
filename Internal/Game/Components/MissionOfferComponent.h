#pragma once

#include "../Component.h"
#include "../Systems/Missions/Requirements.h"

#include <Net/GameMessages/GMs.h>

class MissionOfferComponent : public Component {
	std::vector<CDClientStructs::MissionNPCComponent> MissionCache;
public:

	void OnRequestUse(Entity* Sender, ClientGameMessages::ClientGameMessage* msg) {
		// We need to manage multi interacts for the NS vendors at somepoint but for now can ignore that

		Logger::Log("Game", "Sending Mission Offer");

		auto nmsg = (ClientGameMessages::RequestUse*)msg;

		auto MissionOfferMessage = ServerGameMessages::OfferMission{};
		MissionOfferMessage.missionID = INT32_MAX;

		for (const auto& item : MissionCache) {
			bool HasMission = Sender->m_Server->m_Database->HasMission(Sender->m_ObjectID, item.missionID);

			if (nmsg->bIsMultiInteractUse && nmsg->multiInteractID != item.missionID) continue;

			if (item.acceptsMission) {
				if (HasMission) {
					auto SavedMission = Sender->m_Server->m_Database->GetMission(Sender->m_ObjectID, item.missionID);

					if (SavedMission.State == 4 || SavedMission.State == 12 || SavedMission.State == 2 || SavedMission.State == 10) {
						MissionOfferMessage.offerer = nmsg->object;
						MissionOfferMessage.missionID = item.missionID;

						GameMessage::Send(Sender, Owner, MissionOfferMessage);
						GameMessage::Send(Sender, Sender, MissionOfferMessage);
						return;
					}
				}
			}

			if (item.offersMission) {
				bool IsActiveMission = false;
				bool PlayerPassedRequirements = false;

				GET_ROW_BY_ID(Owner->m_Server->m_CDClient, Missions, item.missionID);

				if (HasMission) {
					auto SavedMission = Sender->m_Server->m_Database->GetMission(Sender->m_ObjectID, item.missionID);
					if (!(SavedMission.State == 1 || (Row.repeatable == 1 && SavedMission.State == 9))) continue;
					if (SavedMission.State == 2 || SavedMission.State == 10) IsActiveMission = true;
				}
				
				if (!IsActiveMission) {
					if (Row.prereqMissionID != "") {
						auto MissionSweep = Missions::MissionRequirementParser::sweepMissionListNumerical(Row.prereqMissionID);

						auto MissionSweepDB = Sender->m_Server->m_Database->GetAllMissions(Sender->m_ObjectID, MissionSweep);

						PlayerPassedRequirements = Missions::MissionRequirementParser(Row.prereqMissionID, MissionSweepDB).result;
					}
					else {
						PlayerPassedRequirements = true;
					}
				}
				else {
					PlayerPassedRequirements = true;
				}

				if (PlayerPassedRequirements) {
					MissionOfferMessage.offerer = nmsg->object;
					MissionOfferMessage.missionID = item.missionID;

					GameMessage::Send(Sender, Owner, MissionOfferMessage);
					GameMessage::Send(Sender, Sender, MissionOfferMessage);
					return;
				}
			}
		}

		if (MissionOfferMessage.missionID != INT32_MAX) {
			MissionOfferMessage.offerer = nmsg->object;

			GameMessage::Send(Sender, Owner, MissionOfferMessage);
			GameMessage::Send(Sender, Sender, MissionOfferMessage);
		}
	}

	void OnMissionDialogueOk(Entity* Sender, ClientGameMessages::ClientGameMessage* msg) {
		auto nmsg = (ClientGameMessages::MissionDialogueOK*)msg;
		
		if (!Sender->m_Server->m_Database->HasMission(Sender->m_ObjectID, nmsg->missionID)) {
			Mission MissionData{};
			MissionData.State = 2;
			MissionData.MissionID = nmsg->missionID;
			MissionData.MissionOwner = Sender->m_ObjectID;
			Sender->m_Server->m_Database->AddMission(MissionData);

			ServerGameMessages::NotifyMission NotifyMessage{};
			NotifyMessage.missionID = nmsg->missionID;
			NotifyMessage.missionState = 2;
			GameMessage::Send(Sender, Sender, NotifyMessage);
		}
		else {
			auto SavedMission = Sender->m_Server->m_Database->GetMission(Sender->m_ObjectID, nmsg->missionID);

			if (nmsg->bIsComplete && (SavedMission.State == 4 || SavedMission.State == 12)) {
				ServerGameMessages::NotifyMission NotifyMessage{};
				NotifyMessage.missionID = nmsg->missionID;
				NotifyMessage.missionState = 0;
				NotifyMessage.sendingRewards = true;
				GameMessage::Send(Sender, Sender, NotifyMessage);
				
				// TODO: mission rewards

				SavedMission.State = 8;
				SavedMission.CompletionCount++;
				SavedMission.LastCompletion = time(0);
				Sender->m_Server->m_Database->UpdateMission(SavedMission);

				NotifyMessage.missionState = SavedMission.State;
				NotifyMessage.sendingRewards = false;
				GameMessage::Send(Sender, Sender, NotifyMessage);

				auto Responder = Sender->m_Server->m_ReplicaManager->GetObjectByObjectID(nmsg->responder);
				if (Responder != nullptr) {
					ClientGameMessages::RequestUse RequestUseGM{};
					RequestUseGM.bIsMultiInteractUse = false;
					RequestUseGM.object = nmsg->responder;
					RequestUseGM.multiInteractID = 0;
					OnRequestUse(Sender, (ClientGameMessages::ClientGameMessage*)&RequestUseGM);
				}
			}

			if (SavedMission.State == 8 || SavedMission.State == 9) {
				ClientGameMessages::RequestUse RequestUseGM{};
				RequestUseGM.bIsMultiInteractUse = false;
				RequestUseGM.object = Owner->m_ObjectID;
				RequestUseGM.multiInteractID = 0;

				OnRequestUse(Sender, (ClientGameMessages::ClientGameMessage*)&RequestUseGM);
			}
		}
	}

	void Start(uint32_t ComponentID) override {
		RegisterGMHandler(ClientGameMessages::RequestUse::GetID(), (Component::GMHandler)&MissionOfferComponent::OnRequestUse);
		RegisterGMHandler(ClientGameMessages::MissionDialogueOK::GetID(), (Component::GMHandler)&MissionOfferComponent::OnMissionDialogueOk);

		GET_ROWS_BY_ID(Owner->m_Server->m_CDClient, MissionNPCComponent, ComponentID);
		MissionCache = Rows;
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {

	}

	constexpr static uint32_t GetID() {
		return (int)Enums::ECOMPONENT_TYPE::MISSION_NPC_COMPONENT;
	}
};