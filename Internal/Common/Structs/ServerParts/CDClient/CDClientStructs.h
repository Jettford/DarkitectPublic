#pragma once

#include <string>
#include <cstdint>

#include "../CDClient.h"
#pragma pack(push, 1)
namespace CDClientStructs {
	struct AICombatRoles { 
		int32_t efId;
		int32_t id;
		int32_t preferredRole;
		float specifiedMinRangeNOUSE;
		float specifiedMaxRangeNOUSE;
		float specificMinRange;
		float specificMaxRange;
	};

	struct AccessoryDefaultLoc { 
		int32_t efId;
		int32_t GroupID;
		std::string Description;
		float Pos_X;
		float Pos_Y;
		float Pos_Z;
		float Rot_X;
		float Rot_Y;
		float Rot_Z;
	};

	struct Activities { 
		int32_t efId;
		int32_t ActivityID;
		int32_t locStatus;
		int32_t instanceMapID;
		int32_t minTeams;
		int32_t maxTeams;
		int32_t minTeamSize;
		int32_t maxTeamSize;
		int32_t waitTime;
		int32_t startDelay;
		int32_t requiresUniqueData;
		int32_t leaderboardType;
		int32_t localize;
		int32_t optionalCostLOT;
		int32_t optionalCostCount;
		int32_t showUIRewards;
		int64_t CommunityActivityFlagID;
		std::string gate_version;
		int32_t noTeamLootOnDeath;
		float optionalPercentage;
	};

	struct ActivityRewards { 
		int32_t efId;
		int32_t objectTemplate;
		int32_t ActivityRewardIndex;
		int32_t activityRating;
		int32_t LootMatrixIndex;
		int32_t CurrencyIndex;
		int32_t ChallengeRating;
		std::string description;
	};

	struct ActivityText { 
		int32_t efId;
		int32_t activityID;
		std::string type;
		int32_t localize;
		int32_t locStatus;
		std::string gate_version;
	};

	struct AnimationIndex { 
		int32_t efId;
		int32_t animationGroupID;
		std::string description;
		std::string groupType;
	};

	struct Animations { 
		int32_t efId;
		int32_t animationGroupID;
		std::string animation_type;
		std::string animation_name;
		float chance_to_play;
		int32_t min_loops;
		int32_t max_loops;
		float animation_length;
		int32_t hideEquip;
		int32_t ignoreUpperBody;
		int32_t restartable;
		std::string face_animation_name;
		float priority;
		float blendTime;
	};

	struct BaseCombatAIComponent { 
		int32_t efId;
		int32_t id;
		int32_t behaviorType;
		float combatRoundLength;
		int32_t combatRole;
		float minRoundLength;
		float maxRoundLength;
		float tetherSpeed;
		float pursuitSpeed;
		float combatStartDelay;
		float softTetherRadius;
		float hardTetherRadius;
		float spawnTimer;
		int32_t tetherEffectID;
		int32_t ignoreMediator;
		float aggroRadius;
		int32_t ignoreStatReset;
		int32_t ignoreParent;
	};

	struct BehaviorEffect { 
		int32_t efId;
		int32_t effectID;
		std::string effectType;
		std::string effectName;
		int32_t trailID;
		float pcreateDuration;
		std::string animationName;
		int32_t attachToObject;
		std::string boneName;
		int32_t useSecondary;
		int32_t cameraEffectType;
		float cameraDuration;
		float cameraFrequency;
		float cameraXAmp;
		float cameraYAmp;
		float cameraZAmp;
		float cameraRotFrequency;
		float cameraRoll;
		float cameraPitch;
		float cameraYaw;
		std::string AudioEventGUID;
		int32_t renderEffectType;
		float renderEffectTime;
		float renderStartVal;
		float renderEndVal;
		float renderDelayVal;
		float renderValue1;
		float renderValue2;
		float renderValue3;
		std::string renderRGBA;
		int32_t renderShaderVal;
		int32_t motionID;
		int32_t meshID;
		float meshDuration;
		std::string meshLockedNode;
	};

	struct BehaviorParameter { 
		int32_t efId;
		int32_t behaviorID;
		std::string parameterID;
		float value;
	};

	struct BehaviorTemplate { 
		int32_t efId;
		int32_t behaviorID;
		int32_t templateID;
		int32_t effectID;
		std::string effectHandle;
	};

	struct BehaviorTemplateName { 
		int32_t efId;
		int32_t templateID;
		std::string name;
	};

	struct Blueprints { 
		int32_t efId;
		int32_t id;
		std::string name;
		std::string description;
		int32_t accountid;
		int32_t characterid;
		int32_t price;
		int32_t rating;
		int32_t categoryid;
		std::string lxfpath;
		int32_t deleted;
		int32_t created;
		int32_t modified;
	};

	struct BrickColors { 
		int32_t efId;
		int32_t id;
		float red;
		float green;
		float blue;
		float alpha;
		int32_t legopaletteid;
		std::string description;
		int32_t validTypes;
		int32_t validCharacters;
		int32_t factoryValid;
	};

	struct BrickIDTable { 
		int32_t efId;
		int32_t NDObjectID;
		int32_t LEGOBrickID;
	};

	struct BuffDefinitions { 
		int32_t efId;
		int32_t ID;
		float Priority;
		std::string UIIcon;
	};

	struct BuffParameters { 
		int32_t efId;
		int32_t BuffID;
		std::string ParameterName;
		float NumberValue;
		std::string StringValue;
		int32_t EffectID;
	};

	struct Camera { 
		int32_t efId;
		std::string camera_name;
		float pitch_angle_tolerance;
		float starting_zoom;
		float zoom_return_modifier;
		float pitch_return_modifier;
		float tether_out_return_modifier;
		float tether_in_return_multiplier;
		float verticle_movement_dampening_modifier;
		float return_from_incline_modifier;
		float horizontal_return_modifier;
		float yaw_behavior_speed_multiplier;
		float camera_collision_padding;
		float glide_speed;
		float fade_player_min_range;
		float min_movement_delta_tolerance;
		float min_glide_distance_tolerance;
		float look_forward_offset;
		float look_up_offset;
		float minimum_vertical_dampening_distance;
		float maximum_vertical_dampening_distance;
		float minimum_ignore_jump_distance;
		float maximum_ignore_jump_distance;
		float maximum_auto_glide_angle;
		float minimum_tether_glide_distance;
		float yaw_sign_correction;
		float set_1_look_forward_offset;
		float set_1_look_up_offset;
		float set_2_look_forward_offset;
		float set_2_look_up_offset;
		float set_0_speed_influence_on_dir;
		float set_1_speed_influence_on_dir;
		float set_2_speed_influence_on_dir;
		float set_0_angular_relaxation;
		float set_1_angular_relaxation;
		float set_2_angular_relaxation;
		float set_0_position_up_offset;
		float set_1_position_up_offset;
		float set_2_position_up_offset;
		float set_0_position_forward_offset;
		float set_1_position_forward_offset;
		float set_2_position_forward_offset;
		float set_0_FOV;
		float set_1_FOV;
		float set_2_FOV;
		float set_0_max_yaw_angle;
		float set_1_max_yaw_angle;
		float set_2_max_yaw_angle;
		int32_t set_1_fade_in_camera_set_change;
		int32_t set_1_fade_out_camera_set_change;
		int32_t set_2_fade_in_camera_set_change;
		int32_t set_2_fade_out_camera_set_change;
		float input_movement_scalar;
		float input_rotation_scalar;
		float input_zoom_scalar;
		float minimum_pitch_desired;
		float maximum_pitch_desired;
		float minimum_zoom;
		float maximum_zoom;
		float horizontal_rotate_tolerance;
		float horizontal_rotate_modifier;
	};

	struct CelebrationParameters { 
		int32_t efId;
		int32_t id;
		std::string animation;
		int32_t backgroundObject;
		float duration;
		std::string subText;
		std::string mainText;
		int32_t iconID;
		float celeLeadIn;
		float celeLeadOut;
		int32_t cameraPathLOT;
		std::string pathNodeName;
		float ambientR;
		float ambientG;
		float ambientB;
		float directionalR;
		float directionalG;
		float directionalB;
		float specularR;
		float specularG;
		float specularB;
		float lightPositionX;
		float lightPositionY;
		float lightPositionZ;
		float blendTime;
		float fogColorR;
		float fogColorG;
		float fogColorB;
		std::string musicCue;
		std::string soundGUID;
		std::string mixerProgram;
	};

	struct ChoiceBuildComponent { 
		int32_t efId;
		int32_t id;
		std::string selections;
		int32_t imaginationOverride;
	};

	struct CollectibleComponent { 
		int32_t efId;
		int32_t id;
		int32_t requirement_mission;
	};

	struct ComponentsRegistry { 
		int32_t efId;
		int32_t id;
		int32_t component_type;
		int32_t component_id;
	};

	struct ControlSchemes { 
		int32_t efId;
		int32_t control_scheme;
		std::string scheme_name;
		float rotation_speed;
		float walk_forward_speed;
		float walk_backward_speed;
		float walk_strafe_speed;
		float walk_strafe_forward_speed;
		float walk_strafe_backward_speed;
		float run_backward_speed;
		float run_strafe_speed;
		float run_strafe_forward_speed;
		float run_strafe_backward_speed;
		float keyboard_zoom_sensitivity;
		float keyboard_pitch_sensitivity;
		float keyboard_yaw_sensitivity;
		float mouse_zoom_wheel_sensitivity;
		float x_mouse_move_sensitivity_modifier;
		float y_mouse_move_sensitivity_modifier;
		float freecam_speed_modifier;
		float freecam_slow_speed_multiplier;
		float freecam_fast_speed_multiplier;
		float freecam_mouse_modifier;
		float gamepad_pitch_rot_sensitivity;
		float gamepad_yaw_rot_sensitivity;
		float gamepad_trigger_sensitivity;
	};

	struct CurrencyDenominations { 
		int32_t efId;
		int32_t value;
		int32_t objectid;
	};

	struct CurrencyTable { 
		int32_t efId;
		int32_t currencyIndex;
		int32_t npcminlevel;
		int32_t minvalue;
		int32_t maxvalue;
		int32_t id;
	};

	struct DBExclude { 
		int32_t efId;
		std::string table;
		std::string column;
	};

	struct DeletionRestrictions { 
		int32_t efId;
		int32_t id;
		int32_t restricted;
		std::string ids;
		int32_t checkType;
		int32_t localize;
		int32_t locStatus;
		std::string gate_version;
	};

	struct DestructibleComponent { 
		int32_t efId;
		int32_t id;
		int32_t faction;
		std::string factionList;
		int32_t life;
		int32_t imagination;
		int32_t LootMatrixIndex;
		int32_t CurrencyIndex;
		int32_t level;
		float armor;
		int32_t death_behavior;
		int32_t isnpc;
		int32_t attack_priority;
		int32_t isSmashable;
		int64_t difficultyLevel;
	};

	struct Emotes { 
		int32_t efId;
		int32_t id;
		std::string animationName;
		std::string iconFilename;
		std::string channel;
		std::string command;
		int32_t locked;
		int32_t localize;
		int32_t locStatus;
		std::string gate_version;
	};

	struct EventGating { 
		int32_t efId;
		std::string eventName;
		int32_t date_start;
		int32_t date_end;
	};

	struct ExhibitComponent { 
		int32_t efId;
		int32_t id;
		float length;
		float width;
		float height;
		float offsetX;
		float offsetY;
		float offsetZ;
		float fReputationSizeMultiplier;
		float fImaginationCost;
	};

	struct Factions { 
		int32_t efId;
		int32_t faction;
		std::string factionList;
		int32_t factionListFriendly;
		std::string friendList;
		std::string enemyList;
	};

	struct FeatureGating { 
		int32_t efId;
		std::string featureName;
		int32_t major;
		int32_t current;
		int32_t minor;
		std::string description;
	};

	struct FlairTable { 
		int32_t efId;
		int32_t id;
		std::string asset;
	};

	struct Icons { 
		int32_t efId;
		int32_t IconID;
		std::string IconPath;
		std::string IconName;
	};

	struct InventoryComponent { 
		int32_t efId;
		int32_t id;
		int32_t itemid;
		int32_t count;
		int32_t equip;
	};

	struct ItemComponent { 
		int32_t efId;
		int32_t id;
		std::string equipLocation;
		int32_t baseValue;
		int32_t isKitPiece;
		int32_t rarity;
		int32_t itemType;
		int64_t itemInfo;
		int32_t inLootTable;
		int32_t inVendor;
		int32_t isUnique;
		int32_t isBOP;
		int32_t isBOE;
		int32_t reqFlagID;
		int32_t reqSpecialtyID;
		int32_t reqSpecRank;
		int32_t reqAchievementID;
		int32_t stackSize;
		int32_t color1;
		int32_t decal;
		int32_t offsetGroupID;
		int32_t buildTypes;
		std::string reqPrecondition;
		int32_t animationFlag;
		int32_t equipEffects;
		int32_t readyForQA;
		int32_t itemRating;
		int32_t isTwoHanded;
		int32_t minNumRequired;
		int32_t delResIndex;
		int32_t currencyLOT;
		int32_t altCurrencyCost;
		std::string subItems;
		std::string audioEventUse;
		int32_t noEquipAnimation;
		int32_t commendationLOT;
		int32_t commendationCost;
		std::string audioEquipMetaEventSet;
		std::string currencyCosts;
		std::string ingredientInfo;
		int32_t locStatus;
		int32_t forgeType;
		float SellMultiplier;
	};

	struct ItemEggData { 
		int32_t efId;
		int32_t id;
		int32_t chassie_type_id;
	};

	struct ItemSetSkills { 
		int32_t efId;
		int32_t SkillSetID;
		int32_t SkillID;
		int32_t SkillCastType;
	};

	struct ItemSets { 
		int32_t efId;
		int32_t setID;
		int32_t locStatus;
		std::string itemIDs;
		int32_t kitType;
		int32_t kitRank;
		int32_t kitImage;
		int32_t skillSetWith2;
		int32_t skillSetWith3;
		int32_t skillSetWith4;
		int32_t skillSetWith5;
		int32_t skillSetWith6;
		int32_t localize;
		std::string gate_version;
		int64_t kitID;
		float priority;
	};

	struct JetPackPadComponent { 
		int32_t efId;
		int32_t id;
		float xDistance;
		float yDistance;
		float warnDistance;
		int32_t lotBlocker;
		int32_t lotWarningVolume;
	};

	struct LUPExhibitComponent { 
		int32_t efId;
		int32_t id;
		float minXZ;
		float maxXZ;
		float maxY;
		float offsetX;
		float offsetY;
		float offsetZ;
	};

	struct LUPExhibitModelData { 
		int32_t efId;
		int32_t LOT;
		float minXZ;
		float maxXZ;
		float maxY;
		std::string description;
		std::string owner;
	};

	struct LUPZoneIDs { 
		int32_t efId;
		int32_t zoneID;
	};

	struct LanguageType { 
		int32_t efId;
		int32_t LanguageID;
		std::string LanguageDescription;
	};

	struct LevelProgressionLookup { 
		int32_t efId;
		int32_t id;
		int32_t requiredUScore;
		std::string BehaviorEffect;
	};

	struct LootMatrix { 
		int32_t efId;
		int32_t LootMatrixIndex;
		int32_t LootTableIndex;
		int32_t RarityTableIndex;
		float percent;
		int32_t minToDrop;
		int32_t maxToDrop;
		int32_t id;
		int32_t flagID;
		std::string gate_version;
	};

	struct LootMatrixIndex { 
		int32_t efId;
		int32_t LootMatrixIndex;
		int32_t inNpcEditor;
	};

	struct LootTable { 
		int32_t efId;
		int32_t itemid;
		int32_t LootTableIndex;
		int32_t id;
		int32_t MissionDrop;
		int32_t sortPriority;
	};

	struct LootTableIndex { 
		int32_t efId;
		int32_t LootTableIndex;
	};

	struct MinifigComponent { 
		int32_t efId;
		int32_t id;
		int32_t head;
		int32_t chest;
		int32_t legs;
		int32_t hairstyle;
		int32_t haircolor;
		int32_t chestdecal;
		int32_t headcolor;
		int32_t lefthand;
		int32_t righthand;
		int32_t eyebrowstyle;
		int32_t eyesstyle;
		int32_t mouthstyle;
	};

	struct MinifigDecals_Eyebrows { 
		int32_t efId;
		int32_t ID;
		std::string High_path;
		std::string Low_path;
		int32_t CharacterCreateValid;
		int32_t male;
		int32_t female;
	};

	struct MinifigDecals_Eyes { 
		int32_t efId;
		int32_t ID;
		std::string High_path;
		std::string Low_path;
		int32_t CharacterCreateValid;
		int32_t male;
		int32_t female;
	};

	struct MinifigDecals_Legs { 
		int32_t efId;
		int32_t ID;
		std::string High_path;
	};

	struct MinifigDecals_Mouths { 
		int32_t efId;
		int32_t ID;
		std::string High_path;
		std::string Low_path;
		int32_t CharacterCreateValid;
		int32_t male;
		int32_t female;
	};

	struct MinifigDecals_Torsos { 
		int32_t efId;
		int32_t ID;
		std::string High_path;
		int32_t CharacterCreateValid;
		int32_t male;
		int32_t female;
	};

	struct MissionEmail { 
		int32_t efId;
		int32_t ID;
		int32_t messageType;
		int32_t notificationGroup;
		int32_t missionID;
		int32_t attachmentLOT;
		int32_t localize;
		int32_t locStatus;
		std::string gate_version;
	};

	struct MissionNPCComponent { 
		int32_t efId;
		int32_t id;
		int32_t missionID;
		int32_t offersMission;
		int32_t acceptsMission;
		std::string gate_version;
	};

	struct MissionTasks { 
		int32_t efId;
		int32_t id;
		int32_t locStatus;
		int32_t taskType;
		int32_t target;
		std::string targetGroup;
		int32_t targetValue;
		std::string taskParam1;
		std::string largeTaskIcon;
		int32_t IconID;
		int32_t uid;
		int32_t largeTaskIconID;
		int32_t localize;
		std::string gate_version;
	};

	struct MissionText { 
		int32_t efId;
		int32_t id;
		std::string story_icon;
		std::string missionIcon;
		std::string offerNPCIcon;
		int32_t IconID;
		std::string state_1_anim;
		std::string state_2_anim;
		std::string state_3_anim;
		std::string state_4_anim;
		std::string state_3_turnin_anim;
		std::string state_4_turnin_anim;
		std::string onclick_anim;
		std::string CinematicAccepted;
		float CinematicAcceptedLeadin;
		std::string CinematicCompleted;
		float CinematicCompletedLeadin;
		std::string CinematicRepeatable;
		float CinematicRepeatableLeadin;
		std::string CinematicRepeatableCompleted;
		float CinematicRepeatableCompletedLeadin;
		std::string AudioEventGUID_Interact;
		std::string AudioEventGUID_OfferAccept;
		std::string AudioEventGUID_OfferDeny;
		std::string AudioEventGUID_Completed;
		std::string AudioEventGUID_TurnIn;
		std::string AudioEventGUID_Failed;
		std::string AudioEventGUID_Progress;
		std::string AudioMusicCue_OfferAccept;
		std::string AudioMusicCue_TurnIn;
		int32_t turnInIconID;
		int32_t localize;
		int32_t locStatus;
		std::string gate_version;
	};

	struct Missions { 
		int32_t efId;
		int32_t id;
		std::string defined_type;
		std::string defined_subtype;
		int32_t UISortOrder;
		int32_t offer_objectID;
		int32_t target_objectID;
		int32_t reward_currency;
		int32_t LegoScore;
		int32_t reward_reputation;
		int32_t isChoiceReward;
		int32_t reward_item1;
		int32_t reward_item1_count;
		int32_t reward_item2;
		int32_t reward_item2_count;
		int32_t reward_item3;
		int32_t reward_item3_count;
		int32_t reward_item4;
		int32_t reward_item4_count;
		int32_t reward_emote;
		int32_t reward_emote2;
		int32_t reward_emote3;
		int32_t reward_emote4;
		int32_t reward_maximagination;
		int32_t reward_maxhealth;
		int32_t reward_maxinventory;
		int32_t reward_maxmodel;
		int32_t reward_maxwidget;
		int32_t reward_maxwallet;
		int32_t repeatable;
		int32_t reward_currency_repeatable;
		int32_t reward_item1_repeatable;
		int32_t reward_item1_repeat_count;
		int32_t reward_item2_repeatable;
		int32_t reward_item2_repeat_count;
		int32_t reward_item3_repeatable;
		int32_t reward_item3_repeat_count;
		int32_t reward_item4_repeatable;
		int32_t reward_item4_repeat_count;
		int32_t time_limit;
		int32_t isMission;
		int32_t missionIconID;
		std::string prereqMissionID;
		int32_t localize;
		int32_t inMOTD;
		int32_t cooldownTime;
		int32_t isRandom;
		std::string randomPool;
		int32_t UIPrereqID;
		std::string gate_version;
		std::string HUDStates;
		int32_t locStatus;
		int32_t reward_bankinventory;
	};

	struct ModelBehavior { 
		int32_t efId;
		int32_t id;
		std::string definitionXMLfilename;
	};

	struct ModularBuildComponent { 
		int32_t efId;
		int32_t id;
		int32_t buildType;
		std::string xml;
		int32_t createdLOT;
		int32_t createdPhysicsID;
		std::string AudioEventGUID_Snap;
		std::string AudioEventGUID_Complete;
		std::string AudioEventGUID_Present;
	};

	struct ModuleComponent { 
		int32_t efId;
		int32_t id;
		int32_t partCode;
		int32_t buildType;
		std::string xml;
		std::string primarySoundGUID;
		int32_t assembledEffectID;
	};

	struct MotionFX { 
		int32_t efId;
		int32_t id;
		int32_t typeID;
		float slamVelocity;
		float addVelocity;
		float duration;
		std::string destGroupName;
		float startScale;
		float endScale;
		float velocity;
		float distance;
	};

	struct MovementAIComponent { 
		int32_t efId;
		int32_t id;
		std::string MovementType;
		float WanderChance;
		float WanderDelayMin;
		float WanderDelayMax;
		float WanderSpeed;
		float WanderRadius;
		std::string attachedPath;
	};

	struct MovingPlatforms { 
		int32_t efId;
		int32_t id;
		int32_t platformIsSimpleMover;
		float platformMoveX;
		float platformMoveY;
		float platformMoveZ;
		float platformMoveTime;
		int32_t platformStartAtEnd;
		std::string description;
	};

	struct NpcIcons { 
		int32_t efId;
		int32_t id;
		int32_t color;
		float offset;
		int32_t LOT;
		std::string Texture;
		int32_t isClickable;
		float scale;
		int32_t rotateToFace;
		float compositeHorizOffset;
		float compositeVertOffset;
		float compositeScale;
		std::string compositeConnectionNode;
		int32_t compositeLOTMultiMission;
		int32_t compositeLOTMultiMissionVentor;
		std::string compositeIconTexture;
	};

	struct ObjectBehaviors { 
		int32_t efId;
		int32_t BehaviorID;
		std::string xmldata;
	};

	struct ObjectSkills { 
		int32_t efId;
		int32_t objectTemplate;
		int32_t skillID;
		int32_t castOnType;
		int32_t AICombatWeight;
	};

	struct Objects { 
		int32_t efId;
		int32_t id;
		std::string name;
		int32_t placeable;
		std::string type;
		std::string description;
		int32_t localize;
		int32_t npcTemplateID;
		std::string displayName;
		float interactionDistance;
		int32_t nametag;
		std::string _internalNotes;
		int32_t locStatus;
		std::string gate_version;
		int32_t HQ_valid;
	};

	struct PackageComponent { 
		int32_t efId;
		int32_t id;
		int32_t LootMatrixIndex;
		int32_t packageType;
	};

	struct PetAbilities { 
		int32_t efId;
		int32_t id;
		std::string AbilityName;
		int32_t ImaginationCost;
		int32_t locStatus;
	};

	struct PetComponent { 
		int32_t efId;
		int32_t id;
		float minTameUpdateTime;
		float maxTameUpdateTime;
		float percentTameChance;
		float tamability;
		int32_t elementType;
		float walkSpeed;
		float runSpeed;
		float sprintSpeed;
		float idleTimeMin;
		float idleTimeMax;
		int32_t petForm;
		float imaginationDrainRate;
		std::string AudioMetaEventSet;
		std::string buffIDs;
	};

	struct PetNestComponent { 
		int32_t efId;
		int32_t id;
		int32_t ElementalType;
	};

	struct PhysicsComponent { 
		int32_t efId;
		int32_t id;
		float Static;
		std::string physics_asset;
		float jump;
		float doublejump;
		float speed;
		float rotSpeed;
		float playerHeight;
		float playerRadius;
		int32_t pcShapeType;
		int32_t collisionGroup;
		float airSpeed;
		std::string boundaryAsset;
		float jumpAirSpeed;
		float friction;
		std::string gravityVolumeAsset;
	};

	struct PlayerFlags { 
		int32_t efId;
		int32_t id;
		int32_t SessionOnly;
		int32_t OnlySetByServer;
		int32_t SessionZoneOnly;
	};

	struct PlayerStatistics { 
		int32_t efId;
		int32_t statID;
		int64_t sortOrder;
		int32_t locStatus;
		std::string gate_version;
	};

	struct PossessableComponent { 
		int32_t efId;
		int32_t id;
		int32_t controlSchemeID;
		std::string minifigAttachPoint;
		std::string minifigAttachAnimation;
		std::string minifigDetachAnimation;
		std::string mountAttachAnimation;
		std::string mountDetachAnimation;
		float attachOffsetFwd;
		float attachOffsetRight;
		int32_t possessionType;
		int32_t wantBillboard;
		float billboardOffsetUp;
		int32_t depossessOnHit;
		float hitStunTime;
		int64_t skillSet;
	};

	struct Preconditions { 
		int32_t efId;
		int32_t id;
		int32_t type;
		std::string targetLOT;
		std::string targetGroup;
		int32_t targetCount;
		int32_t iconID;
		int32_t localize;
		int32_t validContexts;
		int32_t locStatus;
		std::string gate_version;
	};

	struct PropertyEntranceComponent { 
		int32_t efId;
		int32_t id;
		int32_t mapID;
		std::string propertyName;
		int32_t isOnProperty;
		std::string groupType;
	};

	struct PropertyTemplate { 
		int32_t efId;
		int32_t id;
		int32_t mapID;
		int32_t vendorMapID;
		std::string spawnName;
		int32_t type;
		int32_t sizecode;
		int32_t minimumPrice;
		int32_t rentDuration;
		std::string path;
		int32_t cloneLimit;
		int32_t durationType;
		int32_t achievementRequired;
		float zoneX;
		float zoneY;
		float zoneZ;
		float maxBuildHeight;
		int32_t localize;
		int32_t reputationPerMinute;
		int32_t locStatus;
		std::string gate_version;
	};

	struct ProximityMonitorComponent { 
		int32_t efId;
		int32_t id;
		std::string Proximities;
		int32_t LoadOnClient;
		int32_t LoadOnServer;
	};

	struct ProximityTypes { 
		int32_t efId;
		int32_t id;
		std::string Name;
		int32_t Radius;
		int32_t CollisionGroup;
		int32_t PassiveChecks;
		int32_t IconID;
		int32_t LoadOnClient;
		int32_t LoadOnServer;
	};

	struct RacingModuleComponent { 
		int32_t efId;
		int32_t id;
		float topSpeed;
		float acceleration;
		float handling;
		float stability;
		float imagination;
	};

	struct RailActivatorComponent { 
		int32_t efId;
		int32_t id;
		std::string startAnim;
		std::string loopAnim;
		std::string stopAnim;
		std::string startSound;
		std::string loopSound;
		std::string stopSound;
		std::string effectIDs;
		std::string preconditions;
		int32_t playerCollision;
		int32_t cameraLocked;
		std::string StartEffectID;
		std::string StopEffectID;
		int32_t DamageImmune;
		int32_t NoAggro;
		int32_t ShowNameBillboard;
	};

	struct RarityTable { 
		int32_t efId;
		int32_t id;
		float randmax;
		int32_t rarity;
		int32_t RarityTableIndex;
	};

	struct RarityTableIndex { 
		int32_t efId;
		int32_t RarityTableIndex;
	};

	struct RebuildComponent { 
		int32_t efId;
		int32_t id;
		float reset_time;
		float complete_time;
		int32_t take_imagination;
		int32_t interruptible;
		int32_t self_activator;
		std::string custom_modules;
		int32_t activityID;
		int32_t post_imagination_cost;
		float time_before_smash;
	};

	struct RebuildSections { 
		int32_t efId;
		int32_t id;
		int32_t rebuildID;
		int32_t objectID;
		float offset_x;
		float offset_y;
		float offset_z;
		float fall_angle_x;
		float fall_angle_y;
		float fall_angle_z;
		float fall_height;
		std::string requires_list;
		int32_t size;
		int32_t bPlaced;
	};

	struct Release_Version { 
		int32_t efId;
		std::string ReleaseVersion;
		int32_t ReleaseDate;
	};

	struct RenderComponent { 
		int32_t efId;
		int32_t id;
		std::string render_asset;
		std::string icon_asset;
		int32_t IconID;
		int32_t shader_id;
		int32_t effect1;
		int32_t effect2;
		int32_t effect3;
		int32_t effect4;
		int32_t effect5;
		int32_t effect6;
		std::string animationGroupIDs;
		int32_t fade;
		int32_t usedropshadow;
		int32_t preloadAnimations;
		float fadeInTime;
		float maxShadowDistance;
		int32_t ignoreCameraCollision;
		int32_t renderComponentLOD1;
		int32_t renderComponentLOD2;
		int32_t gradualSnap;
		int32_t animationFlag;
		std::string AudioMetaEventSet;
		float billboardHeight;
		float chatBubbleOffset;
		int32_t staticBillboard;
		std::string LXFMLFolder;
		int32_t attachIndicatorsToNode;
	};

	struct RenderComponentFlash { 
		int32_t efId;
		int32_t id;
		int32_t interactive;
		int32_t animated;
		std::string nodeName;
		std::string flashPath;
		std::string elementName;
		int32_t _uid;
	};

	struct RenderComponentWrapper { 
		int32_t efId;
		int32_t id;
		std::string defaultWrapperAsset;
	};

	struct RenderIconAssets { 
		int32_t efId;
		int32_t id;
		std::string icon_asset;
		std::string blank_column;
	};

	struct RewardCodes { 
		int32_t efId;
		int32_t id;
		std::string code;
		int32_t attachmentLOT;
		int32_t locStatus;
		std::string gate_version;
	};

	struct Rewards { 
		int32_t efId;
		int32_t id;
		int32_t LevelID;
		int64_t MissionID;
		int32_t RewardType;
		int32_t value;
		int32_t count;
	};

	struct RocketLaunchpadControlComponent { 
		int32_t efId;
		int32_t id;
		int32_t targetZone;
		int32_t defaultZoneID;
		std::string targetScene;
		int32_t gmLevel;
		std::string playerAnimation;
		std::string rocketAnimation;
		std::string launchMusic;
		int32_t useLaunchPrecondition;
		int32_t useAltLandingPrecondition;
		std::string launchPrecondition;
		std::string altLandingPrecondition;
		std::string altLandingSpawnPointName;
	};

	struct SceneTable { 
		int32_t efId;
		int32_t sceneID;
		std::string sceneName;
	};

	struct ScriptComponent { 
		int32_t efId;
		int32_t id;
		std::string script_name;
		std::string client_script_name;
	};

	struct SkillBehavior { 
		int32_t efId;
		int32_t skillID;
		int32_t locStatus;
		int32_t behaviorID;
		int32_t imaginationcost;
		int32_t cooldowngroup;
		float cooldown;
		int32_t inNpcEditor;
		int32_t skillIcon;
		std::string oomSkillID;
		int32_t oomBehaviorEffectID;
		int32_t castTypeDesc;
		int32_t imBonusUI;
		int32_t lifeBonusUI;
		int32_t armorBonusUI;
		int32_t damageUI;
		int32_t hideIcon;
		int32_t localize;
		std::string gate_version;
		int32_t cancelType;
	};

	struct SmashableChain { 
		int32_t efId;
		int32_t chainIndex;
		int32_t chainLevel;
		int32_t lootMatrixID;
		int32_t rarityTableIndex;
		int32_t currencyIndex;
		int32_t currencyLevel;
		int32_t smashCount;
		int32_t timeLimit;
		int32_t chainStepID;
	};

	struct SmashableChainIndex { 
		int32_t efId;
		int32_t id;
		std::string targetGroup;
		std::string description;
		int32_t continuous;
	};

	struct SmashableComponent { 
		int32_t efId;
		int32_t id;
		int32_t LootMatrixIndex;
	};

	struct SmashableElements { 
		int32_t efId;
		int32_t elementID;
		int32_t dropWeight;
	};

	struct SpeedchatMenu { 
		int32_t efId;
		int32_t id;
		int32_t parentId;
		int32_t emoteId;
		std::string imageName;
		int32_t localize;
		int32_t locStatus;
		std::string gate_version;
	};

	struct SubscriptionPricing { 
		int32_t efId;
		int32_t id;
		std::string countryCode;
		std::string monthlyFeeGold;
		std::string monthlyFeeSilver;
		std::string monthlyFeeBronze;
		int32_t monetarySymbol;
		int32_t symbolIsAppended;
	};

	struct SurfaceType { 
		int32_t efId;
		int32_t SurfaceType;
		std::string FootstepNDAudioMetaEventSetName;
	};

	struct TamingBuildPuzzles { 
		int32_t efId;
		int32_t id;
		int32_t PuzzleModelLot;
		int32_t NPCLot;
		std::string ValidPiecesLXF;
		std::string InvalidPiecesLXF;
		int32_t Difficulty;
		int32_t Timelimit;
		int32_t NumValidPieces;
		int32_t TotalNumPieces;
		std::string ModelName;
		std::string FullModelLXF;
		float Duration;
		int32_t imagCostPerBuild;
	};

	struct TrailEffects { 
		int32_t efId;
		int32_t trailID;
		std::string textureName;
		int32_t blendmode;
		float cardlifetime;
		float colorlifetime;
		float minTailFade;
		float tailFade;
		int32_t max_particles;
		float birthDelay;
		float deathDelay;
		std::string bone1;
		std::string bone2;
		float texLength;
		float texWidth;
		float startColorR;
		float startColorG;
		float startColorB;
		float startColorA;
		float middleColorR;
		float middleColorG;
		float middleColorB;
		float middleColorA;
		float endColorR;
		float endColorG;
		float endColorB;
		float endColorA;
	};

	struct UGBehaviorSounds { 
		int32_t efId;
		int32_t id;
		std::string guid;
		int32_t localize;
		int32_t locStatus;
		std::string gate_version;
	};

	struct VehiclePhysics { 
		int32_t efId;
		int32_t id;
		std::string hkxFilename;
		float fGravityScale;
		float fMass;
		float fChassisFriction;
		float fMaxSpeed;
		float fEngineTorque;
		float fBrakeFrontTorque;
		float fBrakeRearTorque;
		float fBrakeMinInputToBlock;
		float fBrakeMinTimeToBlock;
		float fSteeringMaxAngle;
		float fSteeringSpeedLimitForMaxAngle;
		float fSteeringMinAngle;
		float fFwdBias;
		float fFrontTireFriction;
		float fRearTireFriction;
		float fFrontTireFrictionSlide;
		float fRearTireFrictionSlide;
		float fFrontTireSlipAngle;
		float fRearTireSlipAngle;
		float fWheelWidth;
		float fWheelRadius;
		float fWheelMass;
		float fReorientPitchStrength;
		float fReorientRollStrength;
		float fSuspensionLength;
		float fSuspensionStrength;
		float fSuspensionDampingCompression;
		float fSuspensionDampingRelaxation;
		int32_t iChassisCollisionGroup;
		float fNormalSpinDamping;
		float fCollisionSpinDamping;
		float fCollisionThreshold;
		float fTorqueRollFactor;
		float fTorquePitchFactor;
		float fTorqueYawFactor;
		float fInertiaRoll;
		float fInertiaPitch;
		float fInertiaYaw;
		float fExtraTorqueFactor;
		float fCenterOfMassFwd;
		float fCenterOfMassUp;
		float fCenterOfMassRight;
		float fWheelHardpointFrontFwd;
		float fWheelHardpointFrontUp;
		float fWheelHardpointFrontRight;
		float fWheelHardpointRearFwd;
		float fWheelHardpointRearUp;
		float fWheelHardpointRearRight;
		float fInputTurnSpeed;
		float fInputDeadTurnBackSpeed;
		float fInputAccelSpeed;
		float fInputDeadAccelDownSpeed;
		float fInputDecelSpeed;
		float fInputDeadDecelDownSpeed;
		float fInputSlopeChangePointX;
		float fInputInitialSlope;
		float fInputDeadZone;
		float fAeroAirDensity;
		float fAeroFrontalArea;
		float fAeroDragCoefficient;
		float fAeroLiftCoefficient;
		float fAeroExtraGravity;
		float fBoostTopSpeed;
		float fBoostCostPerSecond;
		float fBoostAccelerateChange;
		float fBoostDampingChange;
		float fPowerslideNeutralAngle;
		float fPowerslideTorqueStrength;
		int32_t iPowerslideNumTorqueApplications;
		float fImaginationTankSize;
		float fSkillCost;
		float fWreckSpeedBase;
		float fWreckSpeedPercent;
		float fWreckMinAngle;
		std::string AudioEventEngine;
		std::string AudioEventSkid;
		std::string AudioEventLightHit;
		float AudioSpeedThresholdLightHit;
		float AudioTimeoutLightHit;
		std::string AudioEventHeavyHit;
		float AudioSpeedThresholdHeavyHit;
		float AudioTimeoutHeavyHit;
		std::string AudioEventStart;
		std::string AudioEventTreadConcrete;
		std::string AudioEventTreadSand;
		std::string AudioEventTreadWood;
		std::string AudioEventTreadDirt;
		std::string AudioEventTreadPlastic;
		std::string AudioEventTreadGrass;
		std::string AudioEventTreadGravel;
		std::string AudioEventTreadMud;
		std::string AudioEventTreadWater;
		std::string AudioEventTreadSnow;
		std::string AudioEventTreadIce;
		std::string AudioEventTreadMetal;
		std::string AudioEventTreadLeaves;
		std::string AudioEventLightLand;
		float AudioAirtimeForLightLand;
		std::string AudioEventHeavyLand;
		float AudioAirtimeForHeavyLand;
		int32_t bWheelsVisible;
	};

	struct VehicleStatMap { 
		int32_t efId;
		int32_t id;
		std::string ModuleStat;
		std::string HavokStat;
		float HavokChangePerModuleStat;
	};

	struct VendorComponent { 
		int32_t efId;
		int32_t id;
		float buyScalar;
		float sellScalar;
		float refreshTimeSeconds;
		int32_t LootMatrixIndex;
	};

	struct WhatsCoolItemSpotlight { 
		int32_t efId;
		int32_t id;
		int32_t itemID;
		int32_t localize;
		std::string gate_version;
		int32_t locStatus;
	};

	struct WhatsCoolNewsAndTips { 
		int32_t efId;
		int32_t id;
		int32_t iconID;
		int32_t type;
		int32_t localize;
		std::string gate_version;
		int32_t locStatus;
	};

	struct WorldConfig { 
		int32_t efId;
		int32_t WorldConfigID;
		float pegravityvalue;
		float pebroadphaseworldsize;
		float pegameobjscalefactor;
		float character_rotation_speed;
		float character_walk_forward_speed;
		float character_walk_backward_speed;
		float character_walk_strafe_speed;
		float character_walk_strafe_forward_speed;
		float character_walk_strafe_backward_speed;
		float character_run_backward_speed;
		float character_run_strafe_speed;
		float character_run_strafe_forward_speed;
		float character_run_strafe_backward_speed;
		float global_cooldown;
		float characterGroundedTime;
		float characterGroundedSpeed;
		float globalImmunityTime;
		float character_max_slope;
		float defaultrespawntime;
		float mission_tooltip_timeout;
		float vendor_buy_multiplier;
		float pet_follow_radius;
		float character_eye_height;
		float flight_vertical_velocity;
		float flight_airspeed;
		float flight_fuel_ratio;
		float flight_max_airspeed;
		float fReputationPerVote;
		int32_t nPropertyCloneLimit;
		int32_t defaultHomespaceTemplate;
		float coins_lost_on_death_percent;
		int32_t coins_lost_on_death_min;
		int32_t coins_lost_on_death_max;
		int32_t character_votes_per_day;
		int32_t property_moderation_request_approval_cost;
		int32_t property_moderation_request_review_cost;
		int32_t propertyModRequestsAllowedSpike;
		int32_t propertyModRequestsAllowedInterval;
		int32_t propertyModRequestsAllowedTotal;
		int32_t propertyModRequestsSpikeDuration;
		int32_t propertyModRequestsIntervalDuration;
		int32_t modelModerateOnCreate;
		float defaultPropertyMaxHeight;
		float reputationPerVoteCast;
		float reputationPerVoteReceived;
		int32_t showcaseTopModelConsiderationBattles;
		float reputationPerBattlePromotion;
		float coins_lost_on_death_min_timeout;
		float coins_lost_on_death_max_timeout;
		int32_t mail_base_fee;
		float mail_percent_attachment_fee;
		int32_t propertyReputationDelay;
		int32_t LevelCap;
		std::string LevelUpBehaviorEffect;
		int32_t CharacterVersion;
		int32_t LevelCapCurrencyConversion;
	};

	struct ZoneLoadingTips { 
		int32_t efId;
		int32_t id;
		int32_t zoneid;
		std::string imagelocation;
		int32_t localize;
		std::string gate_version;
		int32_t locStatus;
		int32_t weight;
		std::string targetVersion;
	};

	struct ZoneSummary { 
		int32_t efId;
		int32_t zoneID;
		int32_t type;
		int32_t value;
		int32_t _uniqueID;
	};

	struct ZoneTable { 
		int32_t efId;
		int32_t zoneID;
		int32_t locStatus;
		std::string zoneName;
		int32_t scriptID;
		float ghostdistance_min;
		float ghostdistance;
		int32_t population_soft_cap;
		int32_t population_hard_cap;
		std::string DisplayDescription;
		std::string mapFolder;
		float smashableMinDistance;
		float smashableMaxDistance;
		std::string mixerProgram;
		std::string clientPhysicsFramerate;
		std::string serverPhysicsFramerate;
		int32_t zoneControlTemplate;
		int32_t widthInChunks;
		int32_t heightInChunks;
		int32_t petsAllowed;
		int32_t localize;
		float fZoneWeight;
		std::string thumbnail;
		int32_t PlayerLoseCoinsOnDeath;
		int32_t disableSaveLoc;
		float teamRadius;
		std::string gate_version;
		int32_t mountsAllowed;
	};

	struct brickAttributes { 
		int32_t efId;
		int32_t ID;
		std::string icon_asset;
		int32_t display_order;
		int32_t locStatus;
	};

	struct mapAnimationPriorities { 
		int32_t efId;
		int32_t id;
		std::string name;
		float priority;
	};

	struct mapAssetType { 
		int32_t efId;
		int32_t id;
		std::string label;
		std::string pathdir;
		std::string typelabel;
	};

	struct mapIcon { 
		int32_t efId;
		int32_t LOT;
		int32_t iconID;
		int32_t iconState;
	};

	struct mapItemTypes { 
		int32_t efId;
		int32_t id;
		std::string description;
		std::string equipLocation;
	};

	struct mapRenderEffects { 
		int32_t efId;
		int32_t id;
		int32_t gameID;
		std::string description;
	};

	struct mapShaders { 
		int32_t efId;
		int32_t id;
		std::string label;
		int32_t gameValue;
		int32_t priority;
	};

	struct mapTextureResource { 
		int32_t efId;
		int32_t id;
		std::string texturepath;
		int32_t SurfaceType;
	};

	struct map_BlueprintCategory { 
		int32_t efId;
		int32_t id;
		std::string description;
		int32_t enabled;
	};

	struct sysdiagrams { 
		int32_t efId;
		std::string name;
		int32_t principal_id;
		int32_t diagram_id;
		int32_t version;
		std::string definition;
	};
}
#pragma pack(pop)