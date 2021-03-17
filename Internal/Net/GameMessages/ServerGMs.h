#pragma once

#include <RakNet/BitStream.h>
#include <string>
#include <cstdint>
#include <vector>
#include <Common/Structs/NiPoint3.h>
#include <Common/Structs/NiQuaternion.h>
#include <unordered_map>

namespace ServerGameMessages {
	struct ServerGameMessage {
		constexpr static uint32_t GetID() { return 0; }

		virtual void Serialize(RakNet::BitStream* bs) {}
	};

	struct Teleport : ServerGameMessage {
		bool bIgnoreY = true;
		bool bSetRotation = false;
		bool bSkipAllChecks = false;
		NiPoint3 pos;
		bool useNavmesh = false;
		float_t w = 1.0f;
		float_t x;
		float_t y;
		float_t z;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 19; }
	};

	struct DropClientLoot : ServerGameMessage {
		bool bUsePosition = false;
		NiPoint3 finalPosition = NiPoint3();
		int32_t iCurrency;
		int32_t itemTemplate;
		int64_t lootID;
		int64_t owner;
		int64_t sourceObj;
		NiPoint3 spawnPosition = NiPoint3();
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 30; }
	};

	struct Die : ServerGameMessage {
		bool bClientDeath = false;
		bool bSpawnLoot = true;
		std::u16string deathType;
		float_t directionRelative_AngleXZ;
		float_t directionRelative_AngleY;
		float_t directionRelative_Force;
		uint32_t killType = 0;
		int64_t killerID;
		int64_t lootOwnerID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 37; }
	};

	struct PreloadAnimation : ServerGameMessage {
		std::u16string animationID;
		bool handled = false;
		int64_t respondObjID;
		std::u16string userData;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 42; }
	};

	struct PlayAnimation : ServerGameMessage {
		std::u16string animationID;
		bool bExpectAnimToExist = true;
		bool bPlayImmediate;
		bool bTriggerOnCompleteMsg = false;
		float_t fPriority = 0.400000005960465f;
		float_t fScale = 1.0f;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 43; }
	};

	struct SetName : ServerGameMessage {
		std::u16string name;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 72; }
	};

	struct EchoStartSkill : ServerGameMessage {
		bool bUsedMouse = false;
		float_t fCasterLatency = 0.0f;
		int32_t iCastType = 0;
		NiPoint3 lastClickedPosit = NiPoint3();
		int64_t optionalOriginatorID;
		int64_t optionalTargetID = 0;
		NiQuaternion originatorRot = NiQuaternion();
		std::string sBitStream;
		uint32_t skillID;
		uint32_t uiSkillHandle = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 118; }
	};

	struct AddSkill : ServerGameMessage {
		int32_t AICombatWeight = 0;
		bool bFromSkillSet = false;
		int32_t castType = 0;
		float_t fTimeSecs = -1.0f;
		int32_t iTimesCanCast = -1;
		uint32_t skillID;
		int32_t slotID = -1;
		bool temporary = true;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 127; }
	};

	struct RemoveSkill : ServerGameMessage {
		bool bFromSkillSet = false;
		uint32_t skillID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 128; }
	};

	struct SetCurrency : ServerGameMessage {
		int64_t currency;
		int32_t lootType = -1;
		NiPoint3 position;
		int32_t sourceLOT = -1;
		int64_t sourceObject = 0;
		int64_t sourceTradeID = 0;
		int32_t sourceType = -1;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 133; }
	};

	struct TeamPickupItem : ServerGameMessage {
		int64_t lootID;
		int64_t lootOwnerID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 140; }
	};

	struct PlayFXEffect : ServerGameMessage {
		int32_t effectID = -1;
		std::u16string effectType;
		float_t fScale = 1.0f;
		std::string name;
		float_t priority = 1.0;
		int64_t secondary = 0;
		bool serialize = true;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 154; }
	};

	struct StopFXEffect : ServerGameMessage {
		bool bKillImmediate;
		std::string name;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 155; }
	};

	struct Resurrect : ServerGameMessage {
		bool bRezImmediately = false;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 160; }
	};

	struct SetStunned : ServerGameMessage {
		int64_t Originator = 0;
		uint32_t StateChangeType;
		bool bCantAttack;
		bool bCantAttackOutChangeWasApplied = false;
		bool bCantEquip;
		bool bCantEquipOutChangeWasApplied = false;
		bool bCantInteract;
		bool bCantInteractOutChangeWasApplied = false;
		bool bCantJump;
		bool bCantJumpOutChangeWasApplied = false;
		bool bCantMove;
		bool bCantMoveOutChangeWasApplied = false;
		bool bCantTurn;
		bool bCantTurnOutChangeWasApplied = false;
		bool bCantUseItem = false;
		bool bCantUseItemOutChangeWasApplied = false;
		bool bDontTerminateInteract = false;
		bool bIgnoreImmunity = true;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 198; }
	};

	struct SetStunImmunity : ServerGameMessage {
		int64_t Caster = 0;
		uint32_t StateChangeType;
		bool bImmuneToStunAttack;
		bool bImmuneToStunEquip;
		bool bImmuneToStunInteract;
		bool bImmuneToStunJump;
		bool bImmuneToStunMove;
		bool bImmuneToStunTurn;
		bool bImmuneToStunUseItem;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 200; }
	};

	struct Knockback : ServerGameMessage {
		int64_t Caster = 0;
		int64_t Originator = 0;
		int32_t iKnockBackTimeMS = 0;
		NiPoint3 vector;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 202; }
	};

	struct EnableRebuild : ServerGameMessage {
		bool bEnable;
		bool bFail;
		bool bSuccess;
		uint32_t eFailReason = 0;
		float_t fDuration;
		int64_t user;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 213; }
	};

	struct MoveItemInInventory : ServerGameMessage {
		int32_t destInvType = 100;
		int64_t iObjID;
		int32_t inventoryType;
		int32_t responseCode;
		int32_t slot;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 224; }
	};

	struct AddItemToInventoryClientSync : ServerGameMessage {
		bool bBound;
		bool bIsBOE;
		bool bIsBOP;
		int32_t eLootTypeSource = -1;
		std::u16string extraInfo;
		int32_t iObjTemplate;
		int64_t iSubkey = 0;
		int32_t invType = -1;
		uint32_t itemCount = 1;
		uint32_t itemsTotal = 0;
		int64_t newObjID;
		NiPoint3 ni3FlyingLootPosit;
		bool showFlyingLoot = true;
		int32_t slotID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 227; }
	};

	struct RemoveItemFromInventory : ServerGameMessage {
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
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 230; }
	};

	struct EquipInventory : ServerGameMessage {
		bool bIgnoreCooldown = false;
		bool bOutSuccess;
		int64_t itemtoequip;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 231; }
	};

	struct UnEquipInventory : ServerGameMessage {
		bool bEvenIfDead = false;
		bool bIgnoreCooldown = false;
		bool bOutSuccess;
		int64_t itemtounequip;
		int64_t replacementObjectID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 233; }
	};

	struct OfferMission : ServerGameMessage {
		int32_t missionID;
		int64_t offerer;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 248; }
	};

	struct NotifyMission : ServerGameMessage {
		int32_t missionID;
		int32_t missionState;
		bool sendingRewards = false;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 254; }
	};

	struct RebuildNotifyState : ServerGameMessage {
		int32_t iPrevState;
		int32_t iState;
		int64_t player;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 336; }
	};

	struct ToggleInteractionUpdates : ServerGameMessage {
		bool bEnable = false;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 356; }
	};

	struct TerminateInteraction : ServerGameMessage {
		int64_t ObjIDTerminator;
		uint32_t type;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 357; }
	};

	struct VendorOpenWindow : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 369; }
	};

	struct EmotePlayed : ServerGameMessage {
		int32_t emoteID;
		int64_t targetID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 371; }
	};

	struct TeamSetOffWorldFlag : ServerGameMessage {
		int64_t i64PlayerID;
		int64_t zoneID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 383; }
	};

	struct SetInventorySize : ServerGameMessage {
		int32_t inventoryType;
		int32_t size;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 389; }
	};

	struct ActivityEnter : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 405; }
	};

	struct ActivityExit : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 406; }
	};

	struct ActivityStart : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 407; }
	};

	struct ActivityStop : ServerGameMessage {
		bool bExit;
		bool bUserCancel;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 408; }
	};

	struct CancelMission : ServerGameMessage {
		int32_t missionID;
		bool resetCompleted;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 418; }
	};

	struct ResetMissions : ServerGameMessage {
		int32_t missionID = -1;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 419; }
	};

	struct NotifyClientShootingGalleryScore : ServerGameMessage {
		float_t addTime;
		int32_t score;
		int64_t target;
		NiPoint3 targetPos;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 425; }
	};

	struct SetUserCtrlCompPause : ServerGameMessage {
		bool bPaused;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 466; }
	};

	struct NotifyClientFlagChange : ServerGameMessage {
		bool bFlag;
		int32_t iFlagID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 472; }
	};

	struct Help : ServerGameMessage {
		int32_t iHelpID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 475; }
	};

	struct VendorTransactionResult : ServerGameMessage {
		int32_t iResult;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 476; }
	};

	struct HasBeenCollectedByClient : ServerGameMessage {
		int64_t playerID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 487; }
	};

	struct PlayerReady : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 509; }
	};

	struct TransferToZone : ServerGameMessage {
		bool bCheckTransferAllowed = false;
		uint32_t cloneID = 0;
		float_t pos_x = FLT_MAX;
		float_t pos_y = FLT_MAX;
		float_t pos_z = FLT_MAX;
		float_t rot_w = 1;
		float_t rot_x = 0;
		float_t rot_y = 0;
		float_t rot_z = 0;
		std::u16string spawnPoint;
		uint8_t ucInstanceType;
		uint16_t zoneID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 516; }
	};

	struct TransferToZoneCheckedIM : ServerGameMessage {
		bool bIsThereaQueue = false;
		uint32_t cloneID = 0;
		float_t pos_x = FLT_MAX;
		float_t pos_y = FLT_MAX;
		float_t pos_z = FLT_MAX;
		float_t rot_w = 1;
		float_t rot_x = 0;
		float_t rot_y = 0;
		float_t rot_z = 0;
		std::u16string spawnPoint;
		uint8_t ucInstanceType;
		uint16_t zoneID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 517; }
	};

	struct InvalidZoneTransferList : ServerGameMessage {
		std::u16string CustomerFeedbackURL;
		std::u16string InvalidMapTransferList;
		bool bCustomerFeedbackOnExit;
		bool bCustomerFeedbackOnInvalidMapTransfer;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 519; }
	};

	struct TransferToLastNonInstance : ServerGameMessage {
		bool bUseLastPosition = true;
		int64_t playerID;
		float_t pos_x = FLT_MAX;
		float_t pos_y = FLT_MAX;
		float_t pos_z = FLT_MAX;
		float_t rot_w = 1;
		float_t rot_x = 0;
		float_t rot_y = 0;
		float_t rot_z = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 527; }
	};

	struct DisplayMessageBox : ServerGameMessage {
		bool bShow;
		int64_t callbackClient;
		std::u16string identifier;
		int32_t imageID;
		std::u16string text;
		std::u16string userData;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 529; }
	};

	struct Smash : ServerGameMessage {
		bool bIgnoreObjectVisibility = false;
		float_t force;
		float_t ghostOpacity;
		int64_t killerID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 537; }
	};

	struct UnSmash : ServerGameMessage {
		int64_t builderID = 0;
		float_t duration = 3.0f;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 538; }
	};

	struct SetGravityScale : ServerGameMessage {
		float_t scale;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 541; }
	};

	struct PlaceModelResponse : ServerGameMessage {
		NiPoint3 position = NiPoint3();
		int64_t propertyPlaqueID = 0;
		int32_t response = 0;
		NiQuaternion rotation = NiQuaternion();
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 547; }
	};

	struct SetJetPackMode : ServerGameMessage {
		bool bBypassChecks = false;
		bool bDoHover = false;
		bool bUse;
		int32_t effectID = -1;
		float_t fAirspeed = 10;
		float_t fMaxAirspeed = 15;
		float_t fVertVel = 1;
		int32_t iWarningEffectID = -1;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 561; }
	};

	struct RegisterPetID : ServerGameMessage {
		int64_t objID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 565; }
	};

	struct RegisterPetDBID : ServerGameMessage {
		int64_t petDBID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 566; }
	};

	struct ShowActivityCountdown : ServerGameMessage {
		bool bPlayAdditionalSound;
		bool bPlayCountdownSound;
		std::u16string sndName;
		int32_t stateToPlaySoundOn;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 568; }
	};

	struct DisplayTooltip : ServerGameMessage {
		bool DoOrDie = false;
		bool NoRepeat = false;
		bool NoRevive = false;
		bool bIsPropertyTooltip = false;
		bool bShow;
		bool bTranslate = false;
		int32_t iTime;
		std::u16string id;
		std::u16string localizeParams;
		std::u16string strImageName;
		std::u16string strText;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 569; }
	};

	struct StartActivityTime : ServerGameMessage {
		float_t startTime;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 576; }
	};

	struct ActivityPause : ServerGameMessage {
		bool bPause;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 602; }
	};

	struct UseItemResult : ServerGameMessage {
		int32_t m_ItemTemplateID;
		bool m_UseItemResult = false;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 607; }
	};

	struct PetResponse : ServerGameMessage {
		int64_t ObjIDPet;
		int32_t iPetCommandType;
		int32_t iResponse;
		int32_t iTypeID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 641; }
	};

	struct SendActivitySummaryLeaderboardData : ServerGameMessage {
		int32_t gameID;
		int32_t infoType;
		std::u16string leaderboardData;
		bool throttled;
		bool weekly;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 649; }
	};

	struct ClientNotifyPet : ServerGameMessage {
		int64_t ObjIDSource;
		int32_t iPetNotificationType;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 659; }
	};

	struct NotifyPetTamingMinigame : ServerGameMessage {
		int64_t PetID;
		int64_t PlayerTamingID;
		bool bForceTeleport;
		uint32_t notifyType;
		NiPoint3 petsDestPos;
		NiPoint3 telePos;
		NiQuaternion teleRot = NiQuaternion();
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 661; }
	};

	struct PetTamingTryBuildResult : ServerGameMessage {
		bool bSuccess = true;
		int32_t iNumCorrect = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 668; }
	};

	struct NotifyTamingModelLoadedOnServer : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 674; }
	};

	struct AddPetToPlayer : ServerGameMessage {
		int32_t iElementalType;
		std::u16string name;
		int64_t petDBID;
		int32_t petLOT;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 681; }
	};

	struct SetPetName : ServerGameMessage {
		std::u16string name;
		int64_t petDBID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 684; }
	};

	struct PetNameChanged : ServerGameMessage {
		int32_t moderationStatus;
		std::u16string name;
		std::u16string ownerName;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 686; }
	};

	struct ShowPetActionButton : ServerGameMessage {
		int32_t ButtonLabel;
		bool bShow;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 692; }
	};

	struct SetEmoteLockState : ServerGameMessage {
		bool bLock;
		int32_t emoteID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 693; }
	};

	struct UseItemRequirementsResponse : ServerGameMessage {
		uint32_t eUseResponse;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 703; }
	};

	struct PlayEmbeddedEffectOnAllClientsNearObject : ServerGameMessage {
		std::u16string effectName;
		int64_t fromObjectID;
		float_t radius;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 713; }
	};

	struct NotifyClientZoneObject : ServerGameMessage {
		std::u16string name;
		int32_t param1;
		int32_t param2;
		int64_t paramObj;
		std::string paramStr;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 737; }
	};

	struct UpdateReputation : ServerGameMessage {
		int64_t iReputation;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 746; }
	};

	struct PropertyRentalResponse : ServerGameMessage {
		uint32_t cloneid;
		int32_t code;
		int64_t propertyID;
		int64_t rentdue;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 750; }
	};

	struct PlatformResync : ServerGameMessage {
		bool bReverse;
		bool bStopAtDesiredWaypoint;
		int32_t eCommand;
		int32_t eState;
		int32_t eUnexpectedCommand;
		float_t fIdleTimeElapsed;
		float_t fMoveTimeElapsed;
		float_t fPercentBetweenPoints;
		int32_t iDesiredWaypointIndex;
		int32_t iIndex;
		int32_t iNextIndex;
		NiPoint3 ptUnexpectedLocation;
		NiQuaternion qUnexpectedRotation = NiQuaternion();
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 761; }
	};

	struct PlayCinematic : ServerGameMessage {
		bool allowGhostUpdates = true;
		bool bCloseMultiInteract;
		bool bSendServerNotify;
		bool bUseControlledObjectForAudioListener = false;
		uint32_t endBehavior = 0;
		bool hidePlayerDuringCine = false;
		float_t leadIn = -1.0f;
		bool leavePlayerLockedWhenFinished = false;
		bool lockPlayer = true;
		std::u16string pathName;
		bool result = false;
		bool skipIfSamePath = false;
		float_t startTimeAdvance;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 762; }
	};

	struct EndCinematic : ServerGameMessage {
		float_t leadOut = -1.0f;
		bool leavePlayerLocked = false;
		std::u16string pathName;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 763; }
	};

	struct ScriptNetworkVarUpdate : ServerGameMessage {
		std::u16string tableOfVars;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 781; }
	};

	struct PlayNDAudioEmitter : ServerGameMessage {
		int64_t m_NDAudioCallbackMessageData = 0;
		int64_t m_NDAudioEmitterID = 0;
		std::string m_NDAudioEventGUID;
		std::string m_NDAudioMetaEventName;
		bool m_Result = false;
		int64_t m_TargetObjectIDForNDAudioCallbackMessages = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 821; }
	};

	struct StopNDAudioEmitter : ServerGameMessage {
		bool m_AllowNativeFadeOut = true;
		int64_t m_NDAudioEmitterID = 0;
		std::string m_NDAudioEventGUID;
		std::string m_NDAudioMetaEventName;
		bool m_Result = false;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 822; }
	};

	struct SetMissionTypeState : ServerGameMessage {
		uint32_t state = 1;
		std::string subtype;
		std::string type;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 851; }
	};

	struct BroadcastTextToChatbox : ServerGameMessage {
		std::u16string attrs;
		std::u16string wsText;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 858; }
	};

	struct OpenPropertyVendor : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 861; }
	};

	struct ServerTradeInvite : ServerGameMessage {
		bool bNeedInvitePopUp = false;
		int64_t i64Requestor;
		std::u16string wsName;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 870; }
	};

	struct ServerTradeInitialReply : ServerGameMessage {
		int64_t i64Invitee;
		uint32_t resultType;
		std::u16string wsName;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 873; }
	};

	struct ServerTradeFinalReply : ServerGameMessage {
		bool bResult;
		int64_t i64Invitee;
		std::u16string wsName;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 874; }
	};

	struct ServerTradeAccept : ServerGameMessage {
		bool bFirst = false;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 884; }
	};

	struct GetLastCustomBuild : ServerGameMessage {
		std::u16string tokenizedLOTList;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 891; }
	};

	struct SetIgnoreProjectileCollision : ServerGameMessage {
		bool bShouldIgnore = false;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 903; }
	};

	struct OrientToObject : ServerGameMessage {
		int64_t objID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 905; }
	};

	struct OrientToPosition : ServerGameMessage {
		NiPoint3 ni3Posit;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 906; }
	};

	struct OrientToAngle : ServerGameMessage {
		bool bRelativeToCurrent;
		float_t fAngle;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 907; }
	};

	struct PropertyModerationStatusUpdate : ServerGameMessage {
		int32_t newModerationStatus = -1;
		std::u16string rejectionReason;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 917; }
	};

	struct RequestClientBounce : ServerGameMessage {
		int64_t BounceTargetID;
		NiPoint3 BounceTargetPosOnServer;
		NiPoint3 BouncedObjLinVel;
		int64_t RequestSourceID;
		bool bAllBounced;
		bool bAllowClientOverride;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 934; }
	};

	struct BouncerActiveStatus : ServerGameMessage {
		bool bActive;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 942; }
	};

	struct MoveInventoryBatch : ServerGameMessage {
		bool bAllowPartial = false;
		bool bOutSuccess = false;
		uint32_t count = 1;
		int32_t dstBag = 0;
		int32_t moveLOT = -1;
		int64_t moveSubkey = 0;
		bool showFlyingLoot = false;
		int32_t srcBag = 0;
		int64_t startObjectID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 957; }
	};

	struct ObjectActivatedClient : ServerGameMessage {
		int64_t activatorID;
		int64_t objectActivatedID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 980; }
	};

	struct NotifyClientObject : ServerGameMessage {
		std::u16string name;
		int32_t param1;
		int32_t param2;
		int64_t paramObj;
		std::string paramStr;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1042; }
	};

	struct DisplayZoneSummary : ServerGameMessage {
		bool isPropertyMap = false;
		bool isZoneStart = false;
		int64_t sender = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1043; }
	};

	struct ModifyPlayerZoneStatistic : ServerGameMessage {
		bool bSet = false;
		std::u16string statName;
		int32_t statValue = 0;
		uint16_t zoneID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1046; }
	};

	struct StartArrangingWithItem : ServerGameMessage {
		bool bFirstTime = true;
		int64_t buildAreaID = 0;
		NiPoint3 buildStartPOS;
		int32_t sourceBAG;
		int64_t sourceID;
		int32_t sourceLOT;
		int32_t sourceTYPE;
		int64_t targetID;
		int32_t targetLOT;
		NiPoint3 targetPOS;
		int32_t targetTYPE;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1061; }
	};

	struct FinishArrangingWithItem : ServerGameMessage {
		int64_t buildAreaID = 0;
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
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1062; }
	};

	struct SetBuildMode : ServerGameMessage {
		bool bStart;
		int32_t distanceType = -1;
		bool modePaused = false;
		int32_t modeValue = 1;
		int64_t playerID;
		NiPoint3 startPos = NiPoint3();
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1068; }
	};

	struct BuildModeSet : ServerGameMessage {
		bool bStart;
		int32_t distanceType = -1;
		bool modePaused = false;
		int32_t modeValue = 1;
		int64_t playerID;
		NiPoint3 startPos = NiPoint3();
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1069; }
	};

	struct SetBuildModeConfirmed : ServerGameMessage {
		bool bStart;
		bool bWarnVisitors = true;
		bool modePaused = false;
		int32_t modeValue = 1;
		int64_t playerID;
		NiPoint3 startPos = NiPoint3();
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1073; }
	};

	struct BuildModeNotificationReport : ServerGameMessage {
		bool bStart;
		int32_t numSent;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1075; }
	};

	struct SetModelToBuild : ServerGameMessage {
		int32_t templateID = -1;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1077; }
	};

	struct SpawnModelBricks : ServerGameMessage {
		float_t amount = 0.0f;
		NiPoint3 pos = NiPoint3();
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1078; }
	};

	struct NotifyClientFailedPrecondition : ServerGameMessage {
		std::u16string FailedReason;
		int32_t PreconditionID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1081; }
	};

	struct ModuleAssemblyDBDataForClient : ServerGameMessage {
		int64_t assemblyID;
		std::u16string blob;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1131; }
	};

	struct EchoSyncSkill : ServerGameMessage {
		bool bDone = false;
		std::string sBitStream;
		uint32_t uiBehaviorHandle;
		uint32_t uiSkillHandle;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1144; }
	};

	struct DoClientProjectileImpact : ServerGameMessage {
		int64_t i64OrgID = 0;
		int64_t i64OwnerID = 0;
		int64_t i64TargetID = 0;
		std::string sBitStream;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1151; }
	};

	struct SetPlayerAllowedRespawn : ServerGameMessage {
		bool dontPromptForRespawn;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1165; }
	};

	struct UncastSkill : ServerGameMessage {
		int32_t skillID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1206; }
	};

	struct FireEventClientSide : ServerGameMessage {
		std::u16string args;
		int64_t object;
		int64_t param1 = 0;
		int32_t param2 = -1;
		int64_t senderID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1213; }
	};

	struct ChangeObjectWorldState : ServerGameMessage {
		uint32_t newState = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1223; }
	};

	struct VehicleLockInput : ServerGameMessage {
		bool bLockWheels = true;
		bool bLockedPowerslide = false;
		float_t fLockedX = 0.0f;
		float_t fLockedY = 0.0f;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1230; }
	};

	struct VehicleUnlockInput : ServerGameMessage {
		bool bLockWheels = true;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1231; }
	};

	struct RacingResetPlayerToLastReset : ServerGameMessage {
		int64_t playerID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1252; }
	};

	struct RacingSetPlayerResetInfo : ServerGameMessage {
		int32_t currentLap;
		uint32_t furthestResetPlane;
		int64_t playerID;
		NiPoint3 respawnPos;
		uint32_t upcomingPlane;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1254; }
	};

	struct LockNodeRotation : ServerGameMessage {
		std::string nodeName;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1260; }
	};

	struct NotifyVehicleOfRacingObject : ServerGameMessage {
		int64_t racingObjectID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1276; }
	};

	struct PlayerReachedRespawnCheckpoint : ServerGameMessage {
		NiPoint3 pos;
		NiQuaternion rot = NiQuaternion();
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1296; }
	};

	struct HandleUGCEquipPostDeleteBasedOnEditMode : ServerGameMessage {
		int64_t invItem;
		int32_t itemsTotal = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1300; }
	};

	struct HandleUGCEquipPreCreateBasedOnEditMode : ServerGameMessage {
		int32_t modelCount;
		int64_t modelID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1301; }
	};

	struct MatchResponse : ServerGameMessage {
		int32_t response;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1309; }
	};

	struct MatchUpdate : ServerGameMessage {
		std::u16string data;
		int32_t type;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1310; }
	};

	struct ChangeIdleFlags : ServerGameMessage {
		int32_t off = 0;
		int32_t on = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1338; }
	};

	struct VehicleAddPassiveBoostAction : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1340; }
	};

	struct VehicleRemovePassiveBoostAction : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1341; }
	};

	struct NotifyRacingClient : ServerGameMessage {
		uint32_t EventType = 0;
		int32_t param1;
		int64_t paramObj;
		std::u16string paramStr;
		int64_t singleClient;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1390; }
	};

	struct RacingPlayerLoaded : ServerGameMessage {
		int64_t playerID;
		int64_t vehicleID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1392; }
	};

	struct SetStatusImmunity : ServerGameMessage {
		uint32_t StateChangeType;
		bool bImmuneToBasicAttack;
		bool bImmuneToDOT;
		bool bImmuneToImaginationGain;
		bool bImmuneToImaginationLoss;
		bool bImmuneToInterrupt;
		bool bImmuneToKnockback;
		bool bImmuneToPullToPoint;
		bool bImmuneToQuickbuildInterrupt;
		bool bImmuneToSpeed;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1435; }
	};

	struct ActivateBrickMode : ServerGameMessage {
		int64_t buildObjectID = 0;
		uint32_t buildType = 2;
		bool enterBuildFromWorld = true;
		bool enterFlag = true;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1438; }
	};

	struct SetPetNameModerated : ServerGameMessage {
		int64_t PetDBID = 0;
		int32_t nModerationStatus;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1448; }
	};

	struct CancelSkillCast : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1451; }
	};

	struct ModifyLegoScore : ServerGameMessage {
		int64_t score;
		int32_t sourceType = -1;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1459; }
	};

	struct RestoreToPostLoadStats : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1468; }
	};

	struct SetRailMovement : ServerGameMessage {
		bool pathGoForward;
		std::u16string pathName;
		uint32_t pathStart;
		int32_t railActivatorComponentID = -1;
		int64_t railActivatorObjID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1471; }
	};

	struct StartRailMovement : ServerGameMessage {
		bool bDamageImmune = true;
		bool bNoAggro = true;
		bool bNotifyActivator = false;
		bool bShowNameBillboard = true;
		bool cameraLocked = true;
		bool collisionEnabled = true;
		std::u16string loopSound;
		bool pathGoForward = true;
		std::u16string pathName;
		uint32_t pathStart = 0;
		int32_t railActivatorComponentID = -1;
		int64_t railActivatorObjID = 0;
		std::u16string startSound;
		std::u16string stopSound;
		bool useDB = true;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1472; }
	};

	struct NotifyRailActivatorStateChange : ServerGameMessage {
		bool bActive = true;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1478; }
	};

	struct NotifyRewardMailed : ServerGameMessage {
		int64_t objectID;
		NiPoint3 startPoint;
		int64_t subkey;
		int32_t templateID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1480; }
	};

	struct UpdatePlayerStatistic : ServerGameMessage {
		int32_t updateID;
		int64_t updateValue = 1;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1481; }
	};

	struct RequeryPropertyModels : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1491; }
	};

	struct NotifyNotEnoughInvSpace : ServerGameMessage {
		uint32_t freeSlotsNeeded;
		uint32_t inventoryType = -1;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1516; }
	};

	struct NotifyPropertyOfEditMode : ServerGameMessage {
		bool bEditingActive;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1546; }
	};

	struct PropertyEntranceBegin : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1553; }
	};

	struct TeamSetLeader : ServerGameMessage {
		int64_t i64PlayerID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1557; }
	};

	struct TeamInviteConfirm : ServerGameMessage {
		bool bLeaderIsFreeTrial = false;
		int64_t i64LeaderID;
		int64_t i64LeaderZoneID;
		uint32_t SizeOfsTeamBuffer;
		const char* sTeamBuffer;
		uint8_t ucLootFlag;
		uint8_t ucNumOfOtherPlayers;
		uint8_t ucResponseCode;
		std::u16string wsLeaderName;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1558; }
	};

	struct TeamGetStatusResponse : ServerGameMessage {
		int64_t i64LeaderID;
		int64_t i64LeaderZoneID;
		uint32_t SizeOfsTeamBuffer;
		const char* sTeamBuffer;
		uint8_t ucLootFlag;
		uint8_t ucNumOfOtherPlayers;
		std::u16string wsLeaderName;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1559; }
	};

	struct TeamAddPlayer : ServerGameMessage {
		bool bIsFreeTrial = false;
		bool bLocal = false;
		bool bNoLootOnDeath = false;
		int64_t i64PlayerID;
		std::u16string wsPlayerName;
		int64_t zoneID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1562; }
	};

	struct TeamRemovePlayer : ServerGameMessage {
		bool bDisband;
		bool bIsKicked;
		bool bIsLeaving;
		bool bLocal = false;
		int64_t i64LeaderID;
		int64_t i64PlayerID;
		std::u16string wsName;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1563; }
	};

	struct SetResurrectRestoreValues : ServerGameMessage {
		int32_t iArmorRestore = -1;
		int32_t iHealthRestore = -1;
		int32_t iImaginationRestore = -1;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1591; }
	};

	struct SetPropertyModerationStatus : ServerGameMessage {
		int32_t moderationStatus = -1;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1594; }
	};

	struct UpdatePropertyModelCount : ServerGameMessage {
		uint32_t modelCount = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1595; }
	};

	struct VehicleStopBoost : ServerGameMessage {
		bool bAffectPassive = true;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1617; }
	};

	struct StartCelebrationEffect : ServerGameMessage {
		std::u16string animation;
		int32_t backgroundObject = 11164;
		int32_t cameraPathLOT = 12458;
		float_t celeLeadIn = 1.0f;
		float_t celeLeadOut = 0.8f;
		int32_t celebrationID = -1;
		float_t duration;
		uint32_t iconID;
		std::u16string mainText;
		std::string mixerProgram;
		std::string musicCue;
		std::string pathNodeName;
		std::string soundGUID;
		std::u16string subText;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1618; }
	};

	struct SetLocalTeam : ServerGameMessage {
		bool bIsLocal = false;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1636; }
	};

	struct ServerDoneLoadingAllObjects : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1642; }
	};

	struct AddBuff : ServerGameMessage {
		bool bAddedByTeammate;
		bool bApplyOnTeammates;
		bool bCancelOnDamageAbsorbRanOut;
		bool bCancelOnDamaged;
		bool bCancelOnDeath = true;
		bool bCancelOnLogOut;
		bool bCancelOnMove;
		bool bCancelOnRemoveBuff = true;
		bool bCancelOnUI;
		bool bCancelOnUnEquip;
		bool bCancelOnZone;
		bool bIgnoreImmunities;
		bool bIsImmunity;
		bool bUseRefCount;
		int64_t casterID;
		int64_t i64AddedBy;
		uint32_t uiBuffID;
		uint32_t uiDurationMS;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1647; }
	};

	struct RemoveBuff : ServerGameMessage {
		bool bFromRemoveBehavior;
		bool bFromUnEquip;
		bool bRemoveImmunity;
		uint32_t uiBuffID;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1648; }
	};

	struct PlayerSetCameraCyclingMode : ServerGameMessage {
		bool bAllowCyclingWhileDeadOnly = true;
		uint32_t cyclingMode = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1676; }
	};

	struct SetMountInventoryID : ServerGameMessage {
		int64_t inventoryMountID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1726; }
	};

	struct NotifyLevelRewards : ServerGameMessage {
		int32_t level;
		bool sendingRewards = false;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1735; }
	};

	struct ClientCancelMoveSkill : ServerGameMessage {
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1747; }
	};

	struct MarkInventoryItemAsActive : ServerGameMessage {
		bool bActive = false;
		int32_t iType = 0;
		int64_t itemID = 0;
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 1767; }
	};

	struct VendorStatusUpdate : ServerGameMessage {
		bool bUpdateOnly = false;
		std::unordered_map<int32_t, uint32_t> ItemList = {};
		void Serialize(RakNet::BitStream* bs) override;
		constexpr static uint32_t GetID() { return 417; }
	};

}

// add serialization for NotifyMissionTask
// add serialization for VendorStatusUpdate
// add serialization for FetchModelMetadataResponse
// add serialization for NotifyPetTamingPuzzleSelected
// add serialization for DownloadPropertyData
// add serialization for PropertySelectQuery
// add serialization for ServerTradeUpdate
// add serialization for PropertyBuildModeUpdate
// add serialization for UIMessageServerToSingleClient
// add serialization for GetModelsOnProperty
// add serialization for NewsSendHotPropertiesinfoToClient
// add serialization for TeamCreateLocal
