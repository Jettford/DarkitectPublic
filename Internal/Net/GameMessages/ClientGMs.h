#pragma once

#include <RakNet/BitStream.h>
#include <string>
#include <cstdint>
#include <vector>
#include <Common/Structs/NiPoint3.h>
#include <Common/Utils.h>
#include <Common/Structs/NiQuaternion.h>

namespace ClientGameMessages {
	struct ClientGameMessage {
		constexpr static uint32_t GetID() { return 0; }

		virtual void Deserialize(RakNet::BitStream* bs) = 0;
	};

	struct RequestDie : ClientGameMessage {
		bool bUnknownBoolean;
		std::u16string deathType;
		float_t directionRelative_AngleXZ;
		float_t directionRelative_AngleY;
		float_t directionRelative_Force;
		uint32_t killType = 0;
		int64_t killerID;
		int64_t lootOwnerID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 38; }
	};

	struct PlayEmote : ClientGameMessage {
		int32_t emoteID;
		int64_t targetID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 41; }
	};

	struct StartSkill : ClientGameMessage {
		bool bUsedMouse = false;
		int64_t consumableItemID = 0;
		float_t fCasterLatency = 0.0f;
		int32_t iCastType = 0;
		NiPoint3 lastClickedPosit = NiPoint3();
		int64_t optionalOriginatorID;
		int64_t optionalTargetID = 0;
		NiQuaternion originatorRot = NiQuaternion();
		std::string sBitStream;
		uint32_t skillID;
		uint32_t uiSkillHandle = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 119; }
	};

	struct CasterDead : ClientGameMessage {
		int64_t i64Caster = 0;
		uint32_t uiSkillHandle = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 120; }
	};

	struct VerifyAck : ClientGameMessage {
		bool bDifferent = false;
		std::string sBitStream;
		uint32_t uiHandle = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 121; }
	};

	struct SelectSkill : ClientGameMessage {
		bool bFromSkillSet = false;
		int32_t skillID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 124; }
	};

	struct RemoveSkill : ClientGameMessage {
		bool bFromSkillSet = false;
		uint32_t skillID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 128; }
	};

	struct PickupCurrency : ClientGameMessage {
		uint32_t currency;
		NiPoint3 position;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 137; }
	};

	struct PickupItem : ClientGameMessage {
		int64_t lootObjectID;
		int64_t playerID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 139; }
	};

	struct RequestResurrect : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 159; }
	};

	struct PopEquippedItemsState : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 192; }
	};

	struct RebuildCancel : ClientGameMessage {
		bool bEarlyRelease;
		int64_t userID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 209; }
	};

	struct MoveItemInInventory : ClientGameMessage {
		int32_t destInvType = 100;
		int64_t iObjID;
		int32_t inventoryType;
		int32_t responseCode;
		int32_t slot;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 224; }
	};

	struct RemoveItemFromInventory : ClientGameMessage {
		bool bConfirmed = false;
		bool bDeleteItem = true;
		bool bOutSuccess = false;
		int32_t eInvType = 100;
		int32_t eLootTypeSource = -1;
		std::u16string extraInfo;
		bool forceDeletion = true;
		int64_t iLootTypeSourceID = 0;
		int64_t iObjID = 0;
		int32_t iObjTemplate = -1;
		int64_t iRequestingObjID = 0;
		uint32_t iStackCount = 1;
		uint32_t iStackRemaining = 0;
		int64_t iSubkey = 0;
		int64_t iTradeID = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 230; }
	};

	struct EquipInventory : ClientGameMessage {
		bool bIgnoreCooldown = false;
		bool bOutSuccess;
		int64_t itemtoequip;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 231; }
	};

	struct UnEquipInventory : ClientGameMessage {
		bool bEvenIfDead = false;
		bool bIgnoreCooldown = false;
		bool bOutSuccess;
		int64_t itemtounequip;
		int64_t replacementObjectID = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 233; }
	};

	struct RespondToMission : ClientGameMessage {
		int32_t missionID;
		int64_t playerID;
		int64_t receiver;
		int32_t rewardItem = -1;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 249; }
	};

	struct ServerTerminateInteraction : ClientGameMessage {
		int64_t ObjIDTerminator;
		uint32_t type;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 358; }
	};

	struct RequestUse : ClientGameMessage {
		bool bIsMultiInteractUse;
		uint32_t multiInteractID;
		int32_t multiInteractType;
		int64_t object;
		bool secondary = false;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 364; }
	};

	struct BuyFromVendor : ClientGameMessage {
		bool confirmed = false;
		int32_t count = 1;
		int32_t item;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 373; }
	};

	struct SellToVendor : ClientGameMessage {
		int32_t count = 1;
		int64_t itemObjID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 374; }
	};

	struct CancelDonationOnPlayer : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 379; }
	};

	struct AcknowledgePossession : ClientGameMessage {
		int64_t possessedObjID = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 391; }
	};

	struct RequestActivityExit : ClientGameMessage {
		bool bUserCancel;
		int64_t userID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 404; }
	};

	struct ShootingGalleryFire : ClientGameMessage {
		NiPoint3 targetPos;
		float_t w;
		float_t x;
		float_t y;
		float_t z;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 411; }
	};

	struct RequestVendorStatusUpdate : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 416; }
	};

	struct CancelMission : ClientGameMessage {
		int32_t missionID;
		bool resetCompleted;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 418; }
	};

	struct ClientItemConsumed : ClientGameMessage {
		int64_t item;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 428; }
	};

	struct UpdateShootingGalleryRotation : ClientGameMessage {
		float_t angle;
		NiPoint3 facing;
		NiPoint3 muzzlePos;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 448; }
	};

	struct SetTooltipFlag : ClientGameMessage {
		bool bFlag;
		int32_t iToolTip;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 469; }
	};

	struct SetFlag : ClientGameMessage {
		bool bFlag;
		int32_t iFlagID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 471; }
	};

	struct HasBeenCollected : ClientGameMessage {
		int64_t playerID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 486; }
	};

	struct DespawnPet : ClientGameMessage {
		bool bDeletePet;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 499; }
	};

	struct PlayerLoaded : ClientGameMessage {
		int64_t playerID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 505; }
	};

	struct MissionDialogueOK : ClientGameMessage {
		bool bIsComplete;
		int32_t iMissionState;
		int32_t missionID;
		int64_t responder;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 520; }
	};

	struct MessageBoxRespond : ClientGameMessage {
		int32_t iButton;
		std::u16string identifier;
		std::u16string userData;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 530; }
	};

	struct ChoiceBoxRespond : ClientGameMessage {
		std::u16string buttonIdentifier;
		int32_t iButton;
		std::u16string identifier;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 531; }
	};

	struct UseNonEquipmentItem : ClientGameMessage {
		int64_t itemToUse;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 603; }
	};

	struct FetchModelMetadataRequest : ClientGameMessage {
		int32_t context;
		int64_t objectID;
		int64_t requestorID;
		int64_t ugID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 638; }
	};

	struct CommandPet : ClientGameMessage {
		NiPoint3 GenericPosInfo;
		int64_t ObjIDSource;
		int32_t iPetCommandType;
		int32_t iTypeID;
		bool overrideObey = false;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 640; }
	};

	struct RequestActivitySummaryLeaderboardData : ClientGameMessage {
		int32_t gameID = 0;
		int32_t queryType = 1;
		int32_t resultsEnd = 10;
		int32_t resultsStart = 0;
		int64_t target;
		bool weekly;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 648; }
	};

	struct NotifyPet : ClientGameMessage {
		int64_t ObjIDSource;
		int64_t ObjToNotifyPetAbout;
		int32_t iPetNotificationType;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 660; }
	};

	struct StartServerPetMinigameTimer : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 662; }
	};

	struct ClientExitTamingMinigame : ClientGameMessage {
		bool bVoluntaryExit = true;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 663; }
	};

	struct PetTamingMinigameResult : ClientGameMessage {
		bool bSuccess;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 667; }
	};

	struct NotifyTamingBuildSuccess : ClientGameMessage {
		NiPoint3 BuildPosition;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 673; }
	};

	struct RequestSetPetName : ClientGameMessage {
		std::u16string name;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 683; }
	};

	struct QueryPropertyData : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 717; }
	};

	struct PropertyEditorBegin : ClientGameMessage {
		int32_t distanceType = 0;
		int64_t propertyObjectID = 0;
		int32_t startMode = 1;
		bool startPaused = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 724; }
	};

	struct PropertyEditorEnd : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 725; }
	};

	struct RequestPlatformResync : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 760; }
	};

	struct CinematicUpdate : ClientGameMessage {
		uint32_t event = 0;
		float_t overallTime = -1.0f;
		std::u16string pathName;
		float_t pathTime = -1.0f;
		int32_t waypoint = -1;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 764; }
	};

	struct ToggleGhostReferenceOverride : ClientGameMessage {
		bool override = false;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 767; }
	};

	struct SetGhostReferencePosition : ClientGameMessage {
		NiPoint3 pos;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 768; }
	};

	struct FireEventServerSide : ClientGameMessage {
		std::u16string args;
		int32_t param1 = -1;
		int32_t param2 = -1;
		int32_t param3 = -1;
		int64_t senderID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 770; }
	};

	struct UpdateModelFromClient : ClientGameMessage {
		int64_t modelID;
		NiPoint3 position;
		NiQuaternion rotation = NiQuaternion();
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 793; }
	};

	struct DeleteModelFromClient : ClientGameMessage {
		int64_t modelID = 0;
		uint32_t reason = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 794; }
	};

	struct EnterProperty1 : ClientGameMessage {
		int32_t index;
		bool returnToZone = true;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 840; }
	};

	struct PropertyEntranceSync : ClientGameMessage {
		bool bIncludeNullAddress;
		bool bIncludeNullDescription;
		bool bPlayersOwn;
		bool bUpdateUI;
		int32_t lNumResults;
		int32_t lReputationTime;
		int32_t lSortMethod;
		int32_t lStartIndex;
		std::string sfilterText;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 842; }
	};

	struct ParseChatMessage : ClientGameMessage {
		int32_t iClientState;
		std::u16string wsString;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 850; }
	};

	struct SetMissionTypeState : ClientGameMessage {
		uint32_t state = 1;
		std::string subtype;
		std::string type;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 851; }
	};

	struct ClientTradeRequest : ClientGameMessage {
		bool bNeedInvitePopUp = false;
		int64_t i64Invitee;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 868; }
	};

	struct ClientTradeCancel : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 878; }
	};

	struct ClientTradeAccept : ClientGameMessage {
		bool bFirst = false;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 880; }
	};

	struct ReadyForUpdates : ClientGameMessage {
		int64_t objectID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 888; }
	};

	struct SetLastCustomBuild : ClientGameMessage {
		std::u16string tokenizedLOTList;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 890; }
	};

	struct SetIgnoreProjectileCollision : ClientGameMessage {
		bool bShouldIgnore = false;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 903; }
	};

	struct PropertyModerationAction : ClientGameMessage {
		int64_t characterID = 0;
		std::u16string info;
		int32_t newModerationStatus = -1;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 915; }
	};

	struct PropertyModerationStatusUpdate : ClientGameMessage {
		int32_t newModerationStatus = -1;
		std::u16string rejectionReason;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 917; }
	};

	struct BounceNotification : ClientGameMessage {
		int64_t ObjIDBounced;
		int64_t ObjIDBouncer;
		bool bSuccess;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 932; }
	};

	struct MoveInventoryBatch : ClientGameMessage {
		bool bAllowPartial = false;
		bool bOutSuccess = false;
		uint32_t count = 1;
		int32_t dstBag = 0;
		int32_t moveLOT = -1;
		int64_t moveSubkey = 0;
		bool showFlyingLoot = false;
		int32_t srcBag = 0;
		int64_t startObjectID = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 957; }
	};

	struct SetBBBAutosave : ClientGameMessage {
		uint32_t SizeOflxfmlDataCompressed;
		const char* lxfmlDataCompressed;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 996; }
	};

	struct BBBLoadItemRequest : ClientGameMessage {
		int64_t itemID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1000; }
	};

	struct BBBSaveRequest : ClientGameMessage {
		int64_t localID;
		uint32_t SizeOflxfmlDataCompressed;
		const char* lxfmlDataCompressed;
		uint32_t timeTakenInMS;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1001; }
	};

	struct BBBResetMetadataSourceItem : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1004; }
	};

	struct ZoneSummaryDismissed : ClientGameMessage {
		int64_t playerID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1044; }
	};

	struct ModifyPlayerZoneStatistic : ClientGameMessage {
		bool bSet = false;
		std::u16string statName;
		int32_t statValue = 0;
		uint16_t zoneID = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1046; }
	};

	struct ActivityStateChangeRequest : ClientGameMessage {
		int64_t i64ObjID;
		int32_t iNumValue1;
		int32_t iNumValue2;
		std::u16string wsStringValue;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1053; }
	};

	struct StartBuildingWithItem : ClientGameMessage {
		bool bFirstTime = true;
		bool bSuccess;
		int32_t sourceBAG;
		int64_t sourceID;
		int32_t sourceLOT;
		int32_t sourceTYPE;
		int64_t targetID;
		int32_t targetLOT;
		NiPoint3 targetPOS;
		int32_t targetTYPE;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1057; }
	};

	struct DoneArrangingWithItem : ClientGameMessage {
		int32_t newSourceBAG;
		int64_t newSourceID;
		int32_t newSourceLOT;
		int32_t newSourceTYPE;
		int64_t newTargetID;
		int32_t newTargetLOT;
		int32_t newTargetTYPE;
		NiPoint3 newtargetPOS;
		int32_t oldItemBAG;
		int64_t oldItemID;
		int32_t oldItemLOT;
		int32_t oldItemTYPE;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1063; }
	};

	struct SetBuildMode : ClientGameMessage {
		bool bStart;
		int32_t distanceType = -1;
		bool modePaused = false;
		int32_t modeValue = 1;
		int64_t playerID;
		NiPoint3 startPos = NiPoint3();
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1068; }
	};

	struct BuildModeSet : ClientGameMessage {
		bool bStart;
		int32_t distanceType = -1;
		bool modePaused = false;
		int32_t modeValue = 1;
		int64_t playerID;
		NiPoint3 startPos = NiPoint3();
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1069; }
	};

	struct BuildExitConfirmation : ClientGameMessage {
		int64_t playerID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1072; }
	};

	struct MoveItemBetweenInventoryTypes : ClientGameMessage {
		int32_t inventoryTypeA;
		int32_t inventoryTypeB;
		int64_t objectID;
		bool showFlyingLoot = true;
		uint32_t stackCount = 1;
		int32_t templateID = -1;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1093; }
	};

	struct MissionDialogueCancelled : ClientGameMessage {
		bool bIsComplete;
		int32_t iMissionState;
		int32_t missionID;
		int64_t responder;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1129; }
	};

	struct ModuleAssemblyQueryData : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1132; }
	};

	struct SyncSkill : ClientGameMessage {
		bool bDone = false;
		std::string sBitStream;
		uint32_t uiBehaviorHandle;
		uint32_t uiSkillHandle;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1145; }
	};

	struct RequestServerProjectileImpact : ClientGameMessage {
		int64_t i64LocalID = 0;
		int64_t i64TargetID = 0;
		std::string sBitStream;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1148; }
	};

	struct ToggleSendingPositionUpdates : ClientGameMessage {
		bool bSendUpdates = false;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1166; }
	};

	struct PlacePropertyModel : ClientGameMessage {
		int64_t modelID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1170; }
	};

	struct ResyncEquipment : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1238; }
	};

	struct RacingPlayerInfoResetFinished : ClientGameMessage {
		int64_t playerID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1255; }
	};

	struct VehicleSetWheelLockState : ClientGameMessage {
		bool bExtraFriction = true;
		bool bLocked = false;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1273; }
	};

	struct PropertyContentsFromClient : ClientGameMessage {
		bool queryDB = false;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1305; }
	};

	struct VehicleNotifyServerAddPassiveBoostAction : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1342; }
	};

	struct VehicleNotifyServerRemovePassiveBoostAction : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1343; }
	};

	struct ZonePropertyModelRotated : ClientGameMessage {
		int64_t playerID = 0;
		int64_t propertyID = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1370; }
	};

	struct ZonePropertyModelRemovedWhileEquipped : ClientGameMessage {
		int64_t playerID = 0;
		int64_t propertyID = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1371; }
	};

	struct ZonePropertyModelEquipped : ClientGameMessage {
		int64_t playerID = 0;
		int64_t propertyID = 0;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1372; }
	};

	struct RacingClientReady : ClientGameMessage {
		int64_t playerID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1393; }
	};

	struct ResetPropertyBehaviors : ClientGameMessage {
		bool bForce = true;
		bool bPause = false;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1406; }
	};

	struct SetConsumableItem : ClientGameMessage {
		int32_t itemTemplateID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1409; }
	};

	struct UsedInformationPlaque : ClientGameMessage {
		int64_t i64Plaque;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1419; }
	};

	struct ActivateBrickMode : ClientGameMessage {
		int64_t buildObjectID = 0;
		uint32_t buildType = 2;
		bool enterBuildFromWorld = true;
		bool enterFlag = true;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1438; }
	};

	struct CancelRailMovement : ClientGameMessage {
		bool bImmediate = false;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1474; }
	};

	struct ClientRailMovementReady : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1476; }
	};

	struct PlayerRailArrivedNotification : ClientGameMessage {
		std::u16string pathName;
		int32_t waypointNumber;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1477; }
	};

	struct RequestRailActivatorState : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1479; }
	};

	struct ModifyGhostingDistance : ClientGameMessage {
		float_t fDistanceScalar = 1.0f;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1485; }
	};

	struct ModularAssemblyNIFCompleted : ClientGameMessage {
		int64_t objectID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1498; }
	};

	struct GetHotPropertyData : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1511; }
	};

	struct NotifyPropertyOfEditMode : ClientGameMessage {
		bool bEditingActive;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1546; }
	};

	struct UpdatePropertyPerformanceCost : ClientGameMessage {
		float_t performanceCost = 0.0f;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1547; }
	};

	struct SetEmotesEnabled : ClientGameMessage {
		bool bEnableEmotes = true;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1577; }
	};

	struct VehicleNotifyHitImaginationServer : ClientGameMessage {
		int64_t pickupObjID = 0;
		int64_t pickupSpawnerID = 0;
		int32_t pickupSpawnerIndex = -1;
		NiPoint3 vehiclePosition = NiPoint3();
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1606; }
	};

	struct CelebrationCompleted : ClientGameMessage {
		std::u16string animation;
		int32_t celebrationID = -1;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1632; }
	};

	struct NotifyServerLevelProcessingComplete : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1734; }
	};

	struct ServerCancelMoveSkill : ClientGameMessage {
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1746; }
	};

	struct DismountComplete : ClientGameMessage {
		int64_t mountID;
		void Deserialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1756; }
	};

}

// add serialization for ControlBehaviors
// add serialization for RequestLinkedMission
// add serialization for ClientTradeUpdate
// add serialization for ModularBuildFinish
// add serialization for PetTamingTryBuild
// add serialization for MatchRequest
