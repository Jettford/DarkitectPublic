#include "CDClient.h"

CDClient::CDClient() {
#ifdef CacheAICombatRoles
	AICombatRolesData = std::vector<CDClientStructs::AICombatRoles>();
#endif
#ifdef CacheAccessoryDefaultLoc
	AccessoryDefaultLocData = std::vector<CDClientStructs::AccessoryDefaultLoc>();
#endif
#ifdef CacheActivities
	ActivitiesData = std::vector<CDClientStructs::Activities>();
#endif
#ifdef CacheActivityRewards
	ActivityRewardsData = std::vector<CDClientStructs::ActivityRewards>();
#endif
#ifdef CacheActivityText
	ActivityTextData = std::vector<CDClientStructs::ActivityText>();
#endif
#ifdef CacheAnimationIndex
	AnimationIndexData = std::vector<CDClientStructs::AnimationIndex>();
#endif
#ifdef CacheAnimations
	AnimationsData = std::vector<CDClientStructs::Animations>();
#endif
#ifdef CacheBaseCombatAIComponent
	BaseCombatAIComponentData = std::vector<CDClientStructs::BaseCombatAIComponent>();
#endif
#ifdef CacheBehaviorEffect
	BehaviorEffectData = std::vector<CDClientStructs::BehaviorEffect>();
#endif
#ifdef CacheBehaviorParameter
	BehaviorParameterData = std::vector<CDClientStructs::BehaviorParameter>();
#endif
#ifdef CacheBehaviorTemplate
	BehaviorTemplateData = std::vector<CDClientStructs::BehaviorTemplate>();
#endif
#ifdef CacheBehaviorTemplateName
	BehaviorTemplateNameData = std::vector<CDClientStructs::BehaviorTemplateName>();
#endif
#ifdef CacheBlueprints
	BlueprintsData = std::vector<CDClientStructs::Blueprints>();
#endif
#ifdef CacheBrickColors
	BrickColorsData = std::vector<CDClientStructs::BrickColors>();
#endif
#ifdef CacheBrickIDTable
	BrickIDTableData = std::vector<CDClientStructs::BrickIDTable>();
#endif
#ifdef CacheBuffDefinitions
	BuffDefinitionsData = std::vector<CDClientStructs::BuffDefinitions>();
#endif
#ifdef CacheBuffParameters
	BuffParametersData = std::vector<CDClientStructs::BuffParameters>();
#endif
#ifdef CacheCamera
	CameraData = std::vector<CDClientStructs::Camera>();
#endif
#ifdef CacheCelebrationParameters
	CelebrationParametersData = std::vector<CDClientStructs::CelebrationParameters>();
#endif
#ifdef CacheChoiceBuildComponent
	ChoiceBuildComponentData = std::vector<CDClientStructs::ChoiceBuildComponent>();
#endif
#ifdef CacheCollectibleComponent
	CollectibleComponentData = std::vector<CDClientStructs::CollectibleComponent>();
#endif
#ifdef CacheComponentsRegistry
	ComponentsRegistryData = std::vector<CDClientStructs::ComponentsRegistry>();
#endif
#ifdef CacheControlSchemes
	ControlSchemesData = std::vector<CDClientStructs::ControlSchemes>();
#endif
#ifdef CacheCurrencyDenominations
	CurrencyDenominationsData = std::vector<CDClientStructs::CurrencyDenominations>();
#endif
#ifdef CacheCurrencyTable
	CurrencyTableData = std::vector<CDClientStructs::CurrencyTable>();
#endif
#ifdef CacheDBExclude
	DBExcludeData = std::vector<CDClientStructs::DBExclude>();
#endif
#ifdef CacheDeletionRestrictions
	DeletionRestrictionsData = std::vector<CDClientStructs::DeletionRestrictions>();
#endif
#ifdef CacheDestructibleComponent
	DestructibleComponentData = std::vector<CDClientStructs::DestructibleComponent>();
#endif
#ifdef CacheEmotes
	EmotesData = std::vector<CDClientStructs::Emotes>();
#endif
#ifdef CacheEventGating
	EventGatingData = std::vector<CDClientStructs::EventGating>();
#endif
#ifdef CacheExhibitComponent
	ExhibitComponentData = std::vector<CDClientStructs::ExhibitComponent>();
#endif
#ifdef CacheFactions
	FactionsData = std::vector<CDClientStructs::Factions>();
#endif
#ifdef CacheFeatureGating
	FeatureGatingData = std::vector<CDClientStructs::FeatureGating>();
#endif
#ifdef CacheFlairTable
	FlairTableData = std::vector<CDClientStructs::FlairTable>();
#endif
#ifdef CacheIcons
	IconsData = std::vector<CDClientStructs::Icons>();
#endif
#ifdef CacheInventoryComponent
	InventoryComponentData = std::vector<CDClientStructs::InventoryComponent>();
#endif
#ifdef CacheItemComponent
	ItemComponentData = std::vector<CDClientStructs::ItemComponent>();
#endif
#ifdef CacheItemEggData
	ItemEggDataData = std::vector<CDClientStructs::ItemEggData>();
#endif
#ifdef CacheItemSetSkills
	ItemSetSkillsData = std::vector<CDClientStructs::ItemSetSkills>();
#endif
#ifdef CacheItemSets
	ItemSetsData = std::vector<CDClientStructs::ItemSets>();
#endif
#ifdef CacheJetPackPadComponent
	JetPackPadComponentData = std::vector<CDClientStructs::JetPackPadComponent>();
#endif
#ifdef CacheLUPExhibitComponent
	LUPExhibitComponentData = std::vector<CDClientStructs::LUPExhibitComponent>();
#endif
#ifdef CacheLUPExhibitModelData
	LUPExhibitModelDataData = std::vector<CDClientStructs::LUPExhibitModelData>();
#endif
#ifdef CacheLUPZoneIDs
	LUPZoneIDsData = std::vector<CDClientStructs::LUPZoneIDs>();
#endif
#ifdef CacheLanguageType
	LanguageTypeData = std::vector<CDClientStructs::LanguageType>();
#endif
#ifdef CacheLevelProgressionLookup
	LevelProgressionLookupData = std::vector<CDClientStructs::LevelProgressionLookup>();
#endif
#ifdef CacheLootMatrix
	LootMatrixData = std::vector<CDClientStructs::LootMatrix>();
#endif
#ifdef CacheLootMatrixIndex
	LootMatrixIndexData = std::vector<CDClientStructs::LootMatrixIndex>();
#endif
#ifdef CacheLootTable
	LootTableData = std::vector<CDClientStructs::LootTable>();
#endif
#ifdef CacheLootTableIndex
	LootTableIndexData = std::vector<CDClientStructs::LootTableIndex>();
#endif
#ifdef CacheMinifigComponent
	MinifigComponentData = std::vector<CDClientStructs::MinifigComponent>();
#endif
#ifdef CacheMinifigDecals_Eyebrows
	MinifigDecals_EyebrowsData = std::vector<CDClientStructs::MinifigDecals_Eyebrows>();
#endif
#ifdef CacheMinifigDecals_Eyes
	MinifigDecals_EyesData = std::vector<CDClientStructs::MinifigDecals_Eyes>();
#endif
#ifdef CacheMinifigDecals_Legs
	MinifigDecals_LegsData = std::vector<CDClientStructs::MinifigDecals_Legs>();
#endif
#ifdef CacheMinifigDecals_Mouths
	MinifigDecals_MouthsData = std::vector<CDClientStructs::MinifigDecals_Mouths>();
#endif
#ifdef CacheMinifigDecals_Torsos
	MinifigDecals_TorsosData = std::vector<CDClientStructs::MinifigDecals_Torsos>();
#endif
#ifdef CacheMissionEmail
	MissionEmailData = std::vector<CDClientStructs::MissionEmail>();
#endif
#ifdef CacheMissionNPCComponent
	MissionNPCComponentData = std::vector<CDClientStructs::MissionNPCComponent>();
#endif
#ifdef CacheMissionTasks
	MissionTasksData = std::vector<CDClientStructs::MissionTasks>();
#endif
#ifdef CacheMissionText
	MissionTextData = std::vector<CDClientStructs::MissionText>();
#endif
#ifdef CacheMissions
	MissionsData = std::vector<CDClientStructs::Missions>();
#endif
#ifdef CacheModelBehavior
	ModelBehaviorData = std::vector<CDClientStructs::ModelBehavior>();
#endif
#ifdef CacheModularBuildComponent
	ModularBuildComponentData = std::vector<CDClientStructs::ModularBuildComponent>();
#endif
#ifdef CacheModuleComponent
	ModuleComponentData = std::vector<CDClientStructs::ModuleComponent>();
#endif
#ifdef CacheMotionFX
	MotionFXData = std::vector<CDClientStructs::MotionFX>();
#endif
#ifdef CacheMovementAIComponent
	MovementAIComponentData = std::vector<CDClientStructs::MovementAIComponent>();
#endif
#ifdef CacheMovingPlatforms
	MovingPlatformsData = std::vector<CDClientStructs::MovingPlatforms>();
#endif
#ifdef CacheNpcIcons
	NpcIconsData = std::vector<CDClientStructs::NpcIcons>();
#endif
#ifdef CacheObjectBehaviors
	ObjectBehaviorsData = std::vector<CDClientStructs::ObjectBehaviors>();
#endif
#ifdef CacheObjectSkills
	ObjectSkillsData = std::vector<CDClientStructs::ObjectSkills>();
#endif
#ifdef CacheObjects
	ObjectsData = std::vector<CDClientStructs::Objects>();
#endif
#ifdef CachePackageComponent
	PackageComponentData = std::vector<CDClientStructs::PackageComponent>();
#endif
#ifdef CachePetAbilities
	PetAbilitiesData = std::vector<CDClientStructs::PetAbilities>();
#endif
#ifdef CachePetComponent
	PetComponentData = std::vector<CDClientStructs::PetComponent>();
#endif
#ifdef CachePetNestComponent
	PetNestComponentData = std::vector<CDClientStructs::PetNestComponent>();
#endif
#ifdef CachePhysicsComponent
	PhysicsComponentData = std::vector<CDClientStructs::PhysicsComponent>();
#endif
#ifdef CachePlayerFlags
	PlayerFlagsData = std::vector<CDClientStructs::PlayerFlags>();
#endif
#ifdef CachePlayerStatistics
	PlayerStatisticsData = std::vector<CDClientStructs::PlayerStatistics>();
#endif
#ifdef CachePossessableComponent
	PossessableComponentData = std::vector<CDClientStructs::PossessableComponent>();
#endif
#ifdef CachePreconditions
	PreconditionsData = std::vector<CDClientStructs::Preconditions>();
#endif
#ifdef CachePropertyEntranceComponent
	PropertyEntranceComponentData = std::vector<CDClientStructs::PropertyEntranceComponent>();
#endif
#ifdef CachePropertyTemplate
	PropertyTemplateData = std::vector<CDClientStructs::PropertyTemplate>();
#endif
#ifdef CacheProximityMonitorComponent
	ProximityMonitorComponentData = std::vector<CDClientStructs::ProximityMonitorComponent>();
#endif
#ifdef CacheProximityTypes
	ProximityTypesData = std::vector<CDClientStructs::ProximityTypes>();
#endif
#ifdef CacheRacingModuleComponent
	RacingModuleComponentData = std::vector<CDClientStructs::RacingModuleComponent>();
#endif
#ifdef CacheRailActivatorComponent
	RailActivatorComponentData = std::vector<CDClientStructs::RailActivatorComponent>();
#endif
#ifdef CacheRarityTable
	RarityTableData = std::vector<CDClientStructs::RarityTable>();
#endif
#ifdef CacheRarityTableIndex
	RarityTableIndexData = std::vector<CDClientStructs::RarityTableIndex>();
#endif
#ifdef CacheRebuildComponent
	RebuildComponentData = std::vector<CDClientStructs::RebuildComponent>();
#endif
#ifdef CacheRebuildSections
	RebuildSectionsData = std::vector<CDClientStructs::RebuildSections>();
#endif
#ifdef CacheRelease_Version
	Release_VersionData = std::vector<CDClientStructs::Release_Version>();
#endif
#ifdef CacheRenderComponent
	RenderComponentData = std::vector<CDClientStructs::RenderComponent>();
#endif
#ifdef CacheRenderComponentFlash
	RenderComponentFlashData = std::vector<CDClientStructs::RenderComponentFlash>();
#endif
#ifdef CacheRenderComponentWrapper
	RenderComponentWrapperData = std::vector<CDClientStructs::RenderComponentWrapper>();
#endif
#ifdef CacheRenderIconAssets
	RenderIconAssetsData = std::vector<CDClientStructs::RenderIconAssets>();
#endif
#ifdef CacheRewardCodes
	RewardCodesData = std::vector<CDClientStructs::RewardCodes>();
#endif
#ifdef CacheRewards
	RewardsData = std::vector<CDClientStructs::Rewards>();
#endif
#ifdef CacheRocketLaunchpadControlComponent
	RocketLaunchpadControlComponentData = std::vector<CDClientStructs::RocketLaunchpadControlComponent>();
#endif
#ifdef CacheSceneTable
	SceneTableData = std::vector<CDClientStructs::SceneTable>();
#endif
#ifdef CacheScriptComponent
	ScriptComponentData = std::vector<CDClientStructs::ScriptComponent>();
#endif
#ifdef CacheSkillBehavior
	SkillBehaviorData = std::vector<CDClientStructs::SkillBehavior>();
#endif
#ifdef CacheSmashableChain
	SmashableChainData = std::vector<CDClientStructs::SmashableChain>();
#endif
#ifdef CacheSmashableChainIndex
	SmashableChainIndexData = std::vector<CDClientStructs::SmashableChainIndex>();
#endif
#ifdef CacheSmashableComponent
	SmashableComponentData = std::vector<CDClientStructs::SmashableComponent>();
#endif
#ifdef CacheSmashableElements
	SmashableElementsData = std::vector<CDClientStructs::SmashableElements>();
#endif
#ifdef CacheSpeedchatMenu
	SpeedchatMenuData = std::vector<CDClientStructs::SpeedchatMenu>();
#endif
#ifdef CacheSubscriptionPricing
	SubscriptionPricingData = std::vector<CDClientStructs::SubscriptionPricing>();
#endif
#ifdef CacheSurfaceType
	SurfaceTypeData = std::vector<CDClientStructs::SurfaceType>();
#endif
#ifdef CacheTamingBuildPuzzles
	TamingBuildPuzzlesData = std::vector<CDClientStructs::TamingBuildPuzzles>();
#endif
#ifdef CacheTrailEffects
	TrailEffectsData = std::vector<CDClientStructs::TrailEffects>();
#endif
#ifdef CacheUGBehaviorSounds
	UGBehaviorSoundsData = std::vector<CDClientStructs::UGBehaviorSounds>();
#endif
#ifdef CacheVehiclePhysics
	VehiclePhysicsData = std::vector<CDClientStructs::VehiclePhysics>();
#endif
#ifdef CacheVehicleStatMap
	VehicleStatMapData = std::vector<CDClientStructs::VehicleStatMap>();
#endif
#ifdef CacheVendorComponent
	VendorComponentData = std::vector<CDClientStructs::VendorComponent>();
#endif
#ifdef CacheWhatsCoolItemSpotlight
	WhatsCoolItemSpotlightData = std::vector<CDClientStructs::WhatsCoolItemSpotlight>();
#endif
#ifdef CacheWhatsCoolNewsAndTips
	WhatsCoolNewsAndTipsData = std::vector<CDClientStructs::WhatsCoolNewsAndTips>();
#endif
#ifdef CacheWorldConfig
	WorldConfigData = std::vector<CDClientStructs::WorldConfig>();
#endif
#ifdef CacheZoneLoadingTips
	ZoneLoadingTipsData = std::vector<CDClientStructs::ZoneLoadingTips>();
#endif
#ifdef CacheZoneSummary
	ZoneSummaryData = std::vector<CDClientStructs::ZoneSummary>();
#endif
#ifdef CacheZoneTable
	ZoneTableData = std::vector<CDClientStructs::ZoneTable>();
#endif
#ifdef CachebrickAttributes
	brickAttributesData = std::vector<CDClientStructs::brickAttributes>();
#endif
#ifdef CachemapAnimationPriorities
	mapAnimationPrioritiesData = std::vector<CDClientStructs::mapAnimationPriorities>();
#endif
#ifdef CachemapAssetType
	mapAssetTypeData = std::vector<CDClientStructs::mapAssetType>();
#endif
#ifdef CachemapIcon
	mapIconData = std::vector<CDClientStructs::mapIcon>();
#endif
#ifdef CachemapItemTypes
	mapItemTypesData = std::vector<CDClientStructs::mapItemTypes>();
#endif
#ifdef CachemapRenderEffects
	mapRenderEffectsData = std::vector<CDClientStructs::mapRenderEffects>();
#endif
#ifdef CachemapShaders
	mapShadersData = std::vector<CDClientStructs::mapShaders>();
#endif
#ifdef CachemapTextureResource
	mapTextureResourceData = std::vector<CDClientStructs::mapTextureResource>();
#endif
#ifdef Cachemap_BlueprintCategory
	map_BlueprintCategoryData = std::vector<CDClientStructs::map_BlueprintCategory>();
#endif
#ifdef Cachesysdiagrams
	sysdiagramsData = std::vector<CDClientStructs::sysdiagrams>();
#endif
}

void CDClient::Open() {
	this->open("./res/CDClient.sqlite");
	LoadCDClientData();
	Logger::Log("CDClient", "Loaded CDClient");
}

void CDClient::LoadCDClientData() {
#ifdef CacheAICombatRoles
	auto AICombatRolesQuery = this->compileStatement("SELECT * FROM AICombatRoles");
	auto AICombatRolesResult = AICombatRolesQuery.execQuery();
	while (!AICombatRolesResult.eof()) {
		CDClientStructs::AICombatRoles Table;
		Table.efId = AICombatRolesResult.getIntField("efId");
		Table.id = AICombatRolesResult.getIntField("id");
		Table.preferredRole = AICombatRolesResult.getIntField("preferredRole");
		Table.specifiedMinRangeNOUSE = AICombatRolesResult.getFloatField("specifiedMinRangeNOUSE");
		Table.specifiedMaxRangeNOUSE = AICombatRolesResult.getFloatField("specifiedMaxRangeNOUSE");
		Table.specificMinRange = AICombatRolesResult.getFloatField("specificMinRange");
		Table.specificMaxRange = AICombatRolesResult.getFloatField("specificMaxRange");
		AICombatRolesData.push_back(Table);
		AICombatRolesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded AICombatRoles");
#endif

#ifdef CacheAccessoryDefaultLoc
	auto AccessoryDefaultLocQuery = this->compileStatement("SELECT * FROM AccessoryDefaultLoc");
	auto AccessoryDefaultLocResult = AccessoryDefaultLocQuery.execQuery();
	while (!AccessoryDefaultLocResult.eof()) {
		CDClientStructs::AccessoryDefaultLoc Table;
		Table.efId = AccessoryDefaultLocResult.getIntField("efId");
		Table.GroupID = AccessoryDefaultLocResult.getIntField("GroupID");
		Table.Description = AccessoryDefaultLocResult.getStringField("Description");
		Table.Pos_X = AccessoryDefaultLocResult.getFloatField("Pos_X");
		Table.Pos_Y = AccessoryDefaultLocResult.getFloatField("Pos_Y");
		Table.Pos_Z = AccessoryDefaultLocResult.getFloatField("Pos_Z");
		Table.Rot_X = AccessoryDefaultLocResult.getFloatField("Rot_X");
		Table.Rot_Y = AccessoryDefaultLocResult.getFloatField("Rot_Y");
		Table.Rot_Z = AccessoryDefaultLocResult.getFloatField("Rot_Z");
		AccessoryDefaultLocData.push_back(Table);
		AccessoryDefaultLocResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded AccessoryDefaultLoc");
#endif

#ifdef CacheActivities
	auto ActivitiesQuery = this->compileStatement("SELECT * FROM Activities");
	auto ActivitiesResult = ActivitiesQuery.execQuery();
	while (!ActivitiesResult.eof()) {
		CDClientStructs::Activities Table;
		Table.efId = ActivitiesResult.getIntField("efId");
		Table.ActivityID = ActivitiesResult.getIntField("ActivityID");
		Table.locStatus = ActivitiesResult.getIntField("locStatus");
		Table.instanceMapID = ActivitiesResult.getIntField("instanceMapID");
		Table.minTeams = ActivitiesResult.getIntField("minTeams");
		Table.maxTeams = ActivitiesResult.getIntField("maxTeams");
		Table.minTeamSize = ActivitiesResult.getIntField("minTeamSize");
		Table.maxTeamSize = ActivitiesResult.getIntField("maxTeamSize");
		Table.waitTime = ActivitiesResult.getIntField("waitTime");
		Table.startDelay = ActivitiesResult.getIntField("startDelay");
		Table.requiresUniqueData = ActivitiesResult.getIntField("requiresUniqueData");
		Table.leaderboardType = ActivitiesResult.getIntField("leaderboardType");
		Table.localize = ActivitiesResult.getIntField("localize");
		Table.optionalCostLOT = ActivitiesResult.getIntField("optionalCostLOT");
		Table.optionalCostCount = ActivitiesResult.getIntField("optionalCostCount");
		Table.showUIRewards = ActivitiesResult.getIntField("showUIRewards");
		Table.CommunityActivityFlagID = ActivitiesResult.getInt64Field("CommunityActivityFlagID");
		Table.gate_version = ActivitiesResult.getStringField("gate_version");
		Table.noTeamLootOnDeath = ActivitiesResult.getIntField("noTeamLootOnDeath");
		Table.optionalPercentage = ActivitiesResult.getFloatField("optionalPercentage");
		ActivitiesData.push_back(Table);
		ActivitiesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Activities");
#endif

#ifdef CacheActivityRewards
	auto ActivityRewardsQuery = this->compileStatement("SELECT * FROM ActivityRewards");
	auto ActivityRewardsResult = ActivityRewardsQuery.execQuery();
	while (!ActivityRewardsResult.eof()) {
		CDClientStructs::ActivityRewards Table;
		Table.efId = ActivityRewardsResult.getIntField("efId");
		Table.objectTemplate = ActivityRewardsResult.getIntField("objectTemplate");
		Table.ActivityRewardIndex = ActivityRewardsResult.getIntField("ActivityRewardIndex");
		Table.activityRating = ActivityRewardsResult.getIntField("activityRating");
		Table.LootMatrixIndex = ActivityRewardsResult.getIntField("LootMatrixIndex");
		Table.CurrencyIndex = ActivityRewardsResult.getIntField("CurrencyIndex");
		Table.ChallengeRating = ActivityRewardsResult.getIntField("ChallengeRating");
		Table.description = ActivityRewardsResult.getStringField("description");
		ActivityRewardsData.push_back(Table);
		ActivityRewardsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ActivityRewards");
#endif

#ifdef CacheActivityText
	auto ActivityTextQuery = this->compileStatement("SELECT * FROM ActivityText");
	auto ActivityTextResult = ActivityTextQuery.execQuery();
	while (!ActivityTextResult.eof()) {
		CDClientStructs::ActivityText Table;
		Table.efId = ActivityTextResult.getIntField("efId");
		Table.activityID = ActivityTextResult.getIntField("activityID");
		Table.type = ActivityTextResult.getStringField("type");
		Table.localize = ActivityTextResult.getIntField("localize");
		Table.locStatus = ActivityTextResult.getIntField("locStatus");
		Table.gate_version = ActivityTextResult.getStringField("gate_version");
		ActivityTextData.push_back(Table);
		ActivityTextResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ActivityText");
#endif

#ifdef CacheAnimationIndex
	auto AnimationIndexQuery = this->compileStatement("SELECT * FROM AnimationIndex");
	auto AnimationIndexResult = AnimationIndexQuery.execQuery();
	while (!AnimationIndexResult.eof()) {
		CDClientStructs::AnimationIndex Table;
		Table.efId = AnimationIndexResult.getIntField("efId");
		Table.animationGroupID = AnimationIndexResult.getIntField("animationGroupID");
		Table.description = AnimationIndexResult.getStringField("description");
		Table.groupType = AnimationIndexResult.getStringField("groupType");
		AnimationIndexData.push_back(Table);
		AnimationIndexResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded AnimationIndex");
#endif

#ifdef CacheAnimations
	auto AnimationsQuery = this->compileStatement("SELECT * FROM Animations");
	auto AnimationsResult = AnimationsQuery.execQuery();
	while (!AnimationsResult.eof()) {
		CDClientStructs::Animations Table;
		Table.efId = AnimationsResult.getIntField("efId");
		Table.animationGroupID = AnimationsResult.getIntField("animationGroupID");
		Table.animation_type = AnimationsResult.getStringField("animation_type");
		Table.animation_name = AnimationsResult.getStringField("animation_name");
		Table.chance_to_play = AnimationsResult.getFloatField("chance_to_play");
		Table.min_loops = AnimationsResult.getIntField("min_loops");
		Table.max_loops = AnimationsResult.getIntField("max_loops");
		Table.animation_length = AnimationsResult.getFloatField("animation_length");
		Table.hideEquip = AnimationsResult.getIntField("hideEquip");
		Table.ignoreUpperBody = AnimationsResult.getIntField("ignoreUpperBody");
		Table.restartable = AnimationsResult.getIntField("restartable");
		Table.face_animation_name = AnimationsResult.getStringField("face_animation_name");
		Table.priority = AnimationsResult.getFloatField("priority");
		Table.blendTime = AnimationsResult.getFloatField("blendTime");
		AnimationsData.push_back(Table);
		AnimationsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Animations");
#endif

#ifdef CacheBaseCombatAIComponent
	auto BaseCombatAIComponentQuery = this->compileStatement("SELECT * FROM BaseCombatAIComponent");
	auto BaseCombatAIComponentResult = BaseCombatAIComponentQuery.execQuery();
	while (!BaseCombatAIComponentResult.eof()) {
		CDClientStructs::BaseCombatAIComponent Table;
		Table.efId = BaseCombatAIComponentResult.getIntField("efId");
		Table.id = BaseCombatAIComponentResult.getIntField("id");
		Table.behaviorType = BaseCombatAIComponentResult.getIntField("behaviorType");
		Table.combatRoundLength = BaseCombatAIComponentResult.getFloatField("combatRoundLength");
		Table.combatRole = BaseCombatAIComponentResult.getIntField("combatRole");
		Table.minRoundLength = BaseCombatAIComponentResult.getFloatField("minRoundLength");
		Table.maxRoundLength = BaseCombatAIComponentResult.getFloatField("maxRoundLength");
		Table.tetherSpeed = BaseCombatAIComponentResult.getFloatField("tetherSpeed");
		Table.pursuitSpeed = BaseCombatAIComponentResult.getFloatField("pursuitSpeed");
		Table.combatStartDelay = BaseCombatAIComponentResult.getFloatField("combatStartDelay");
		Table.softTetherRadius = BaseCombatAIComponentResult.getFloatField("softTetherRadius");
		Table.hardTetherRadius = BaseCombatAIComponentResult.getFloatField("hardTetherRadius");
		Table.spawnTimer = BaseCombatAIComponentResult.getFloatField("spawnTimer");
		Table.tetherEffectID = BaseCombatAIComponentResult.getIntField("tetherEffectID");
		Table.ignoreMediator = BaseCombatAIComponentResult.getIntField("ignoreMediator");
		Table.aggroRadius = BaseCombatAIComponentResult.getFloatField("aggroRadius");
		Table.ignoreStatReset = BaseCombatAIComponentResult.getIntField("ignoreStatReset");
		Table.ignoreParent = BaseCombatAIComponentResult.getIntField("ignoreParent");
		BaseCombatAIComponentData.push_back(Table);
		BaseCombatAIComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded BaseCombatAIComponent");
#endif

#ifdef CacheBehaviorEffect
	auto BehaviorEffectQuery = this->compileStatement("SELECT * FROM BehaviorEffect");
	auto BehaviorEffectResult = BehaviorEffectQuery.execQuery();
	while (!BehaviorEffectResult.eof()) {
		CDClientStructs::BehaviorEffect Table;
		Table.efId = BehaviorEffectResult.getIntField("efId");
		Table.effectID = BehaviorEffectResult.getIntField("effectID");
		Table.effectType = BehaviorEffectResult.getStringField("effectType");
		Table.effectName = BehaviorEffectResult.getStringField("effectName");
		Table.trailID = BehaviorEffectResult.getIntField("trailID");
		Table.pcreateDuration = BehaviorEffectResult.getFloatField("pcreateDuration");
		Table.animationName = BehaviorEffectResult.getStringField("animationName");
		Table.attachToObject = BehaviorEffectResult.getIntField("attachToObject");
		Table.boneName = BehaviorEffectResult.getStringField("boneName");
		Table.useSecondary = BehaviorEffectResult.getIntField("useSecondary");
		Table.cameraEffectType = BehaviorEffectResult.getIntField("cameraEffectType");
		Table.cameraDuration = BehaviorEffectResult.getFloatField("cameraDuration");
		Table.cameraFrequency = BehaviorEffectResult.getFloatField("cameraFrequency");
		Table.cameraXAmp = BehaviorEffectResult.getFloatField("cameraXAmp");
		Table.cameraYAmp = BehaviorEffectResult.getFloatField("cameraYAmp");
		Table.cameraZAmp = BehaviorEffectResult.getFloatField("cameraZAmp");
		Table.cameraRotFrequency = BehaviorEffectResult.getFloatField("cameraRotFrequency");
		Table.cameraRoll = BehaviorEffectResult.getFloatField("cameraRoll");
		Table.cameraPitch = BehaviorEffectResult.getFloatField("cameraPitch");
		Table.cameraYaw = BehaviorEffectResult.getFloatField("cameraYaw");
		Table.AudioEventGUID = BehaviorEffectResult.getStringField("AudioEventGUID");
		Table.renderEffectType = BehaviorEffectResult.getIntField("renderEffectType");
		Table.renderEffectTime = BehaviorEffectResult.getFloatField("renderEffectTime");
		Table.renderStartVal = BehaviorEffectResult.getFloatField("renderStartVal");
		Table.renderEndVal = BehaviorEffectResult.getFloatField("renderEndVal");
		Table.renderDelayVal = BehaviorEffectResult.getFloatField("renderDelayVal");
		Table.renderValue1 = BehaviorEffectResult.getFloatField("renderValue1");
		Table.renderValue2 = BehaviorEffectResult.getFloatField("renderValue2");
		Table.renderValue3 = BehaviorEffectResult.getFloatField("renderValue3");
		Table.renderRGBA = BehaviorEffectResult.getStringField("renderRGBA");
		Table.renderShaderVal = BehaviorEffectResult.getIntField("renderShaderVal");
		Table.motionID = BehaviorEffectResult.getIntField("motionID");
		Table.meshID = BehaviorEffectResult.getIntField("meshID");
		Table.meshDuration = BehaviorEffectResult.getFloatField("meshDuration");
		Table.meshLockedNode = BehaviorEffectResult.getStringField("meshLockedNode");
		BehaviorEffectData.push_back(Table);
		BehaviorEffectResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded BehaviorEffect");
#endif

#ifdef CacheBehaviorParameter
	auto BehaviorParameterQuery = this->compileStatement("SELECT * FROM BehaviorParameter");
	auto BehaviorParameterResult = BehaviorParameterQuery.execQuery();
	while (!BehaviorParameterResult.eof()) {
		CDClientStructs::BehaviorParameter Table;
		Table.efId = BehaviorParameterResult.getIntField("efId");
		Table.behaviorID = BehaviorParameterResult.getIntField("behaviorID");
		Table.parameterID = BehaviorParameterResult.getStringField("parameterID");
		Table.value = BehaviorParameterResult.getFloatField("value");
		BehaviorParameterData.push_back(Table);
		BehaviorParameterResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded BehaviorParameter");
#endif

#ifdef CacheBehaviorTemplate
	auto BehaviorTemplateQuery = this->compileStatement("SELECT * FROM BehaviorTemplate");
	auto BehaviorTemplateResult = BehaviorTemplateQuery.execQuery();
	while (!BehaviorTemplateResult.eof()) {
		CDClientStructs::BehaviorTemplate Table;
		Table.efId = BehaviorTemplateResult.getIntField("efId");
		Table.behaviorID = BehaviorTemplateResult.getIntField("behaviorID");
		Table.templateID = BehaviorTemplateResult.getIntField("templateID");
		Table.effectID = BehaviorTemplateResult.getIntField("effectID");
		Table.effectHandle = BehaviorTemplateResult.getStringField("effectHandle");
		BehaviorTemplateData.push_back(Table);
		BehaviorTemplateResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded BehaviorTemplate");
#endif

#ifdef CacheBehaviorTemplateName
	auto BehaviorTemplateNameQuery = this->compileStatement("SELECT * FROM BehaviorTemplateName");
	auto BehaviorTemplateNameResult = BehaviorTemplateNameQuery.execQuery();
	while (!BehaviorTemplateNameResult.eof()) {
		CDClientStructs::BehaviorTemplateName Table;
		Table.efId = BehaviorTemplateNameResult.getIntField("efId");
		Table.templateID = BehaviorTemplateNameResult.getIntField("templateID");
		Table.name = BehaviorTemplateNameResult.getStringField("name");
		BehaviorTemplateNameData.push_back(Table);
		BehaviorTemplateNameResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded BehaviorTemplateName");
#endif

#ifdef CacheBlueprints
	auto BlueprintsQuery = this->compileStatement("SELECT * FROM Blueprints");
	auto BlueprintsResult = BlueprintsQuery.execQuery();
	while (!BlueprintsResult.eof()) {
		CDClientStructs::Blueprints Table;
		Table.efId = BlueprintsResult.getIntField("efId");
		Table.id = BlueprintsResult.getIntField("id");
		Table.name = BlueprintsResult.getStringField("name");
		Table.description = BlueprintsResult.getStringField("description");
		Table.accountid = BlueprintsResult.getIntField("accountid");
		Table.characterid = BlueprintsResult.getIntField("characterid");
		Table.price = BlueprintsResult.getIntField("price");
		Table.rating = BlueprintsResult.getIntField("rating");
		Table.categoryid = BlueprintsResult.getIntField("categoryid");
		Table.lxfpath = BlueprintsResult.getStringField("lxfpath");
		Table.deleted = BlueprintsResult.getIntField("deleted");
		Table.created = BlueprintsResult.getIntField("created");
		Table.modified = BlueprintsResult.getIntField("modified");
		BlueprintsData.push_back(Table);
		BlueprintsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Blueprints");
#endif

#ifdef CacheBrickColors
	auto BrickColorsQuery = this->compileStatement("SELECT * FROM BrickColors");
	auto BrickColorsResult = BrickColorsQuery.execQuery();
	while (!BrickColorsResult.eof()) {
		CDClientStructs::BrickColors Table;
		Table.efId = BrickColorsResult.getIntField("efId");
		Table.id = BrickColorsResult.getIntField("id");
		Table.red = BrickColorsResult.getFloatField("red");
		Table.green = BrickColorsResult.getFloatField("green");
		Table.blue = BrickColorsResult.getFloatField("blue");
		Table.alpha = BrickColorsResult.getFloatField("alpha");
		Table.legopaletteid = BrickColorsResult.getIntField("legopaletteid");
		Table.description = BrickColorsResult.getStringField("description");
		Table.validTypes = BrickColorsResult.getIntField("validTypes");
		Table.validCharacters = BrickColorsResult.getIntField("validCharacters");
		Table.factoryValid = BrickColorsResult.getIntField("factoryValid");
		BrickColorsData.push_back(Table);
		BrickColorsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded BrickColors");
#endif

#ifdef CacheBrickIDTable
	auto BrickIDTableQuery = this->compileStatement("SELECT * FROM BrickIDTable");
	auto BrickIDTableResult = BrickIDTableQuery.execQuery();
	while (!BrickIDTableResult.eof()) {
		CDClientStructs::BrickIDTable Table;
		Table.efId = BrickIDTableResult.getIntField("efId");
		Table.NDObjectID = BrickIDTableResult.getIntField("NDObjectID");
		Table.LEGOBrickID = BrickIDTableResult.getIntField("LEGOBrickID");
		BrickIDTableData.push_back(Table);
		BrickIDTableResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded BrickIDTable");
#endif

#ifdef CacheBuffDefinitions
	auto BuffDefinitionsQuery = this->compileStatement("SELECT * FROM BuffDefinitions");
	auto BuffDefinitionsResult = BuffDefinitionsQuery.execQuery();
	while (!BuffDefinitionsResult.eof()) {
		CDClientStructs::BuffDefinitions Table;
		Table.efId = BuffDefinitionsResult.getIntField("efId");
		Table.ID = BuffDefinitionsResult.getIntField("ID");
		Table.Priority = BuffDefinitionsResult.getFloatField("Priority");
		Table.UIIcon = BuffDefinitionsResult.getStringField("UIIcon");
		BuffDefinitionsData.push_back(Table);
		BuffDefinitionsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded BuffDefinitions");
#endif

#ifdef CacheBuffParameters
	auto BuffParametersQuery = this->compileStatement("SELECT * FROM BuffParameters");
	auto BuffParametersResult = BuffParametersQuery.execQuery();
	while (!BuffParametersResult.eof()) {
		CDClientStructs::BuffParameters Table;
		Table.efId = BuffParametersResult.getIntField("efId");
		Table.BuffID = BuffParametersResult.getIntField("BuffID");
		Table.ParameterName = BuffParametersResult.getStringField("ParameterName");
		Table.NumberValue = BuffParametersResult.getFloatField("NumberValue");
		Table.StringValue = BuffParametersResult.getStringField("StringValue");
		Table.EffectID = BuffParametersResult.getIntField("EffectID");
		BuffParametersData.push_back(Table);
		BuffParametersResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded BuffParameters");
#endif

#ifdef CacheCamera
	auto CameraQuery = this->compileStatement("SELECT * FROM Camera");
	auto CameraResult = CameraQuery.execQuery();
	while (!CameraResult.eof()) {
		CDClientStructs::Camera Table;
		Table.efId = CameraResult.getIntField("efId");
		Table.camera_name = CameraResult.getStringField("camera_name");
		Table.pitch_angle_tolerance = CameraResult.getFloatField("pitch_angle_tolerance");
		Table.starting_zoom = CameraResult.getFloatField("starting_zoom");
		Table.zoom_return_modifier = CameraResult.getFloatField("zoom_return_modifier");
		Table.pitch_return_modifier = CameraResult.getFloatField("pitch_return_modifier");
		Table.tether_out_return_modifier = CameraResult.getFloatField("tether_out_return_modifier");
		Table.tether_in_return_multiplier = CameraResult.getFloatField("tether_in_return_multiplier");
		Table.verticle_movement_dampening_modifier = CameraResult.getFloatField("verticle_movement_dampening_modifier");
		Table.return_from_incline_modifier = CameraResult.getFloatField("return_from_incline_modifier");
		Table.horizontal_return_modifier = CameraResult.getFloatField("horizontal_return_modifier");
		Table.yaw_behavior_speed_multiplier = CameraResult.getFloatField("yaw_behavior_speed_multiplier");
		Table.camera_collision_padding = CameraResult.getFloatField("camera_collision_padding");
		Table.glide_speed = CameraResult.getFloatField("glide_speed");
		Table.fade_player_min_range = CameraResult.getFloatField("fade_player_min_range");
		Table.min_movement_delta_tolerance = CameraResult.getFloatField("min_movement_delta_tolerance");
		Table.min_glide_distance_tolerance = CameraResult.getFloatField("min_glide_distance_tolerance");
		Table.look_forward_offset = CameraResult.getFloatField("look_forward_offset");
		Table.look_up_offset = CameraResult.getFloatField("look_up_offset");
		Table.minimum_vertical_dampening_distance = CameraResult.getFloatField("minimum_vertical_dampening_distance");
		Table.maximum_vertical_dampening_distance = CameraResult.getFloatField("maximum_vertical_dampening_distance");
		Table.minimum_ignore_jump_distance = CameraResult.getFloatField("minimum_ignore_jump_distance");
		Table.maximum_ignore_jump_distance = CameraResult.getFloatField("maximum_ignore_jump_distance");
		Table.maximum_auto_glide_angle = CameraResult.getFloatField("maximum_auto_glide_angle");
		Table.minimum_tether_glide_distance = CameraResult.getFloatField("minimum_tether_glide_distance");
		Table.yaw_sign_correction = CameraResult.getFloatField("yaw_sign_correction");
		Table.set_1_look_forward_offset = CameraResult.getFloatField("set_1_look_forward_offset");
		Table.set_1_look_up_offset = CameraResult.getFloatField("set_1_look_up_offset");
		Table.set_2_look_forward_offset = CameraResult.getFloatField("set_2_look_forward_offset");
		Table.set_2_look_up_offset = CameraResult.getFloatField("set_2_look_up_offset");
		Table.set_0_speed_influence_on_dir = CameraResult.getFloatField("set_0_speed_influence_on_dir");
		Table.set_1_speed_influence_on_dir = CameraResult.getFloatField("set_1_speed_influence_on_dir");
		Table.set_2_speed_influence_on_dir = CameraResult.getFloatField("set_2_speed_influence_on_dir");
		Table.set_0_angular_relaxation = CameraResult.getFloatField("set_0_angular_relaxation");
		Table.set_1_angular_relaxation = CameraResult.getFloatField("set_1_angular_relaxation");
		Table.set_2_angular_relaxation = CameraResult.getFloatField("set_2_angular_relaxation");
		Table.set_0_position_up_offset = CameraResult.getFloatField("set_0_position_up_offset");
		Table.set_1_position_up_offset = CameraResult.getFloatField("set_1_position_up_offset");
		Table.set_2_position_up_offset = CameraResult.getFloatField("set_2_position_up_offset");
		Table.set_0_position_forward_offset = CameraResult.getFloatField("set_0_position_forward_offset");
		Table.set_1_position_forward_offset = CameraResult.getFloatField("set_1_position_forward_offset");
		Table.set_2_position_forward_offset = CameraResult.getFloatField("set_2_position_forward_offset");
		Table.set_0_FOV = CameraResult.getFloatField("set_0_FOV");
		Table.set_1_FOV = CameraResult.getFloatField("set_1_FOV");
		Table.set_2_FOV = CameraResult.getFloatField("set_2_FOV");
		Table.set_0_max_yaw_angle = CameraResult.getFloatField("set_0_max_yaw_angle");
		Table.set_1_max_yaw_angle = CameraResult.getFloatField("set_1_max_yaw_angle");
		Table.set_2_max_yaw_angle = CameraResult.getFloatField("set_2_max_yaw_angle");
		Table.set_1_fade_in_camera_set_change = CameraResult.getIntField("set_1_fade_in_camera_set_change");
		Table.set_1_fade_out_camera_set_change = CameraResult.getIntField("set_1_fade_out_camera_set_change");
		Table.set_2_fade_in_camera_set_change = CameraResult.getIntField("set_2_fade_in_camera_set_change");
		Table.set_2_fade_out_camera_set_change = CameraResult.getIntField("set_2_fade_out_camera_set_change");
		Table.input_movement_scalar = CameraResult.getFloatField("input_movement_scalar");
		Table.input_rotation_scalar = CameraResult.getFloatField("input_rotation_scalar");
		Table.input_zoom_scalar = CameraResult.getFloatField("input_zoom_scalar");
		Table.minimum_pitch_desired = CameraResult.getFloatField("minimum_pitch_desired");
		Table.maximum_pitch_desired = CameraResult.getFloatField("maximum_pitch_desired");
		Table.minimum_zoom = CameraResult.getFloatField("minimum_zoom");
		Table.maximum_zoom = CameraResult.getFloatField("maximum_zoom");
		Table.horizontal_rotate_tolerance = CameraResult.getFloatField("horizontal_rotate_tolerance");
		Table.horizontal_rotate_modifier = CameraResult.getFloatField("horizontal_rotate_modifier");
		CameraData.push_back(Table);
		CameraResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Camera");
#endif

#ifdef CacheCelebrationParameters
	auto CelebrationParametersQuery = this->compileStatement("SELECT * FROM CelebrationParameters");
	auto CelebrationParametersResult = CelebrationParametersQuery.execQuery();
	while (!CelebrationParametersResult.eof()) {
		CDClientStructs::CelebrationParameters Table;
		Table.efId = CelebrationParametersResult.getIntField("efId");
		Table.id = CelebrationParametersResult.getIntField("id");
		Table.animation = CelebrationParametersResult.getStringField("animation");
		Table.backgroundObject = CelebrationParametersResult.getIntField("backgroundObject");
		Table.duration = CelebrationParametersResult.getFloatField("duration");
		Table.subText = CelebrationParametersResult.getStringField("subText");
		Table.mainText = CelebrationParametersResult.getStringField("mainText");
		Table.iconID = CelebrationParametersResult.getIntField("iconID");
		Table.celeLeadIn = CelebrationParametersResult.getFloatField("celeLeadIn");
		Table.celeLeadOut = CelebrationParametersResult.getFloatField("celeLeadOut");
		Table.cameraPathLOT = CelebrationParametersResult.getIntField("cameraPathLOT");
		Table.pathNodeName = CelebrationParametersResult.getStringField("pathNodeName");
		Table.ambientR = CelebrationParametersResult.getFloatField("ambientR");
		Table.ambientG = CelebrationParametersResult.getFloatField("ambientG");
		Table.ambientB = CelebrationParametersResult.getFloatField("ambientB");
		Table.directionalR = CelebrationParametersResult.getFloatField("directionalR");
		Table.directionalG = CelebrationParametersResult.getFloatField("directionalG");
		Table.directionalB = CelebrationParametersResult.getFloatField("directionalB");
		Table.specularR = CelebrationParametersResult.getFloatField("specularR");
		Table.specularG = CelebrationParametersResult.getFloatField("specularG");
		Table.specularB = CelebrationParametersResult.getFloatField("specularB");
		Table.lightPositionX = CelebrationParametersResult.getFloatField("lightPositionX");
		Table.lightPositionY = CelebrationParametersResult.getFloatField("lightPositionY");
		Table.lightPositionZ = CelebrationParametersResult.getFloatField("lightPositionZ");
		Table.blendTime = CelebrationParametersResult.getFloatField("blendTime");
		Table.fogColorR = CelebrationParametersResult.getFloatField("fogColorR");
		Table.fogColorG = CelebrationParametersResult.getFloatField("fogColorG");
		Table.fogColorB = CelebrationParametersResult.getFloatField("fogColorB");
		Table.musicCue = CelebrationParametersResult.getStringField("musicCue");
		Table.soundGUID = CelebrationParametersResult.getStringField("soundGUID");
		Table.mixerProgram = CelebrationParametersResult.getStringField("mixerProgram");
		CelebrationParametersData.push_back(Table);
		CelebrationParametersResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded CelebrationParameters");
#endif

#ifdef CacheChoiceBuildComponent
	auto ChoiceBuildComponentQuery = this->compileStatement("SELECT * FROM ChoiceBuildComponent");
	auto ChoiceBuildComponentResult = ChoiceBuildComponentQuery.execQuery();
	while (!ChoiceBuildComponentResult.eof()) {
		CDClientStructs::ChoiceBuildComponent Table;
		Table.efId = ChoiceBuildComponentResult.getIntField("efId");
		Table.id = ChoiceBuildComponentResult.getIntField("id");
		Table.selections = ChoiceBuildComponentResult.getStringField("selections");
		Table.imaginationOverride = ChoiceBuildComponentResult.getIntField("imaginationOverride");
		ChoiceBuildComponentData.push_back(Table);
		ChoiceBuildComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ChoiceBuildComponent");
#endif

#ifdef CacheCollectibleComponent
	auto CollectibleComponentQuery = this->compileStatement("SELECT * FROM CollectibleComponent");
	auto CollectibleComponentResult = CollectibleComponentQuery.execQuery();
	while (!CollectibleComponentResult.eof()) {
		CDClientStructs::CollectibleComponent Table;
		Table.efId = CollectibleComponentResult.getIntField("efId");
		Table.id = CollectibleComponentResult.getIntField("id");
		Table.requirement_mission = CollectibleComponentResult.getIntField("requirement_mission");
		CollectibleComponentData.push_back(Table);
		CollectibleComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded CollectibleComponent");
#endif

#ifdef CacheComponentsRegistry
	auto ComponentsRegistryQuery = this->compileStatement("SELECT * FROM ComponentsRegistry");
	auto ComponentsRegistryResult = ComponentsRegistryQuery.execQuery();
	while (!ComponentsRegistryResult.eof()) {
		CDClientStructs::ComponentsRegistry Table;
		Table.efId = ComponentsRegistryResult.getIntField("efId");
		Table.id = ComponentsRegistryResult.getIntField("id");
		Table.component_type = ComponentsRegistryResult.getIntField("component_type");
		Table.component_id = ComponentsRegistryResult.getIntField("component_id");
		ComponentsRegistryData.push_back(Table);
		ComponentsRegistryResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ComponentsRegistry");
#endif

#ifdef CacheControlSchemes
	auto ControlSchemesQuery = this->compileStatement("SELECT * FROM ControlSchemes");
	auto ControlSchemesResult = ControlSchemesQuery.execQuery();
	while (!ControlSchemesResult.eof()) {
		CDClientStructs::ControlSchemes Table;
		Table.efId = ControlSchemesResult.getIntField("efId");
		Table.control_scheme = ControlSchemesResult.getIntField("control_scheme");
		Table.scheme_name = ControlSchemesResult.getStringField("scheme_name");
		Table.rotation_speed = ControlSchemesResult.getFloatField("rotation_speed");
		Table.walk_forward_speed = ControlSchemesResult.getFloatField("walk_forward_speed");
		Table.walk_backward_speed = ControlSchemesResult.getFloatField("walk_backward_speed");
		Table.walk_strafe_speed = ControlSchemesResult.getFloatField("walk_strafe_speed");
		Table.walk_strafe_forward_speed = ControlSchemesResult.getFloatField("walk_strafe_forward_speed");
		Table.walk_strafe_backward_speed = ControlSchemesResult.getFloatField("walk_strafe_backward_speed");
		Table.run_backward_speed = ControlSchemesResult.getFloatField("run_backward_speed");
		Table.run_strafe_speed = ControlSchemesResult.getFloatField("run_strafe_speed");
		Table.run_strafe_forward_speed = ControlSchemesResult.getFloatField("run_strafe_forward_speed");
		Table.run_strafe_backward_speed = ControlSchemesResult.getFloatField("run_strafe_backward_speed");
		Table.keyboard_zoom_sensitivity = ControlSchemesResult.getFloatField("keyboard_zoom_sensitivity");
		Table.keyboard_pitch_sensitivity = ControlSchemesResult.getFloatField("keyboard_pitch_sensitivity");
		Table.keyboard_yaw_sensitivity = ControlSchemesResult.getFloatField("keyboard_yaw_sensitivity");
		Table.mouse_zoom_wheel_sensitivity = ControlSchemesResult.getFloatField("mouse_zoom_wheel_sensitivity");
		Table.x_mouse_move_sensitivity_modifier = ControlSchemesResult.getFloatField("x_mouse_move_sensitivity_modifier");
		Table.y_mouse_move_sensitivity_modifier = ControlSchemesResult.getFloatField("y_mouse_move_sensitivity_modifier");
		Table.freecam_speed_modifier = ControlSchemesResult.getFloatField("freecam_speed_modifier");
		Table.freecam_slow_speed_multiplier = ControlSchemesResult.getFloatField("freecam_slow_speed_multiplier");
		Table.freecam_fast_speed_multiplier = ControlSchemesResult.getFloatField("freecam_fast_speed_multiplier");
		Table.freecam_mouse_modifier = ControlSchemesResult.getFloatField("freecam_mouse_modifier");
		Table.gamepad_pitch_rot_sensitivity = ControlSchemesResult.getFloatField("gamepad_pitch_rot_sensitivity");
		Table.gamepad_yaw_rot_sensitivity = ControlSchemesResult.getFloatField("gamepad_yaw_rot_sensitivity");
		Table.gamepad_trigger_sensitivity = ControlSchemesResult.getFloatField("gamepad_trigger_sensitivity");
		ControlSchemesData.push_back(Table);
		ControlSchemesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ControlSchemes");
#endif

#ifdef CacheCurrencyDenominations
	auto CurrencyDenominationsQuery = this->compileStatement("SELECT * FROM CurrencyDenominations");
	auto CurrencyDenominationsResult = CurrencyDenominationsQuery.execQuery();
	while (!CurrencyDenominationsResult.eof()) {
		CDClientStructs::CurrencyDenominations Table;
		Table.efId = CurrencyDenominationsResult.getIntField("efId");
		Table.value = CurrencyDenominationsResult.getIntField("value");
		Table.objectid = CurrencyDenominationsResult.getIntField("objectid");
		CurrencyDenominationsData.push_back(Table);
		CurrencyDenominationsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded CurrencyDenominations");
#endif

#ifdef CacheCurrencyTable
	auto CurrencyTableQuery = this->compileStatement("SELECT * FROM CurrencyTable");
	auto CurrencyTableResult = CurrencyTableQuery.execQuery();
	while (!CurrencyTableResult.eof()) {
		CDClientStructs::CurrencyTable Table;
		Table.efId = CurrencyTableResult.getIntField("efId");
		Table.currencyIndex = CurrencyTableResult.getIntField("currencyIndex");
		Table.npcminlevel = CurrencyTableResult.getIntField("npcminlevel");
		Table.minvalue = CurrencyTableResult.getIntField("minvalue");
		Table.maxvalue = CurrencyTableResult.getIntField("maxvalue");
		Table.id = CurrencyTableResult.getIntField("id");
		CurrencyTableData.push_back(Table);
		CurrencyTableResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded CurrencyTable");
#endif

#ifdef CacheDBExclude
	auto DBExcludeQuery = this->compileStatement("SELECT * FROM DBExclude");
	auto DBExcludeResult = DBExcludeQuery.execQuery();
	while (!DBExcludeResult.eof()) {
		CDClientStructs::DBExclude Table;
		Table.efId = DBExcludeResult.getIntField("efId");
		Table.table = DBExcludeResult.getStringField("table");
		Table.column = DBExcludeResult.getStringField("column");
		DBExcludeData.push_back(Table);
		DBExcludeResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded DBExclude");
#endif

#ifdef CacheDeletionRestrictions
	auto DeletionRestrictionsQuery = this->compileStatement("SELECT * FROM DeletionRestrictions");
	auto DeletionRestrictionsResult = DeletionRestrictionsQuery.execQuery();
	while (!DeletionRestrictionsResult.eof()) {
		CDClientStructs::DeletionRestrictions Table;
		Table.efId = DeletionRestrictionsResult.getIntField("efId");
		Table.id = DeletionRestrictionsResult.getIntField("id");
		Table.restricted = DeletionRestrictionsResult.getIntField("restricted");
		Table.ids = DeletionRestrictionsResult.getStringField("ids");
		Table.checkType = DeletionRestrictionsResult.getIntField("checkType");
		Table.localize = DeletionRestrictionsResult.getIntField("localize");
		Table.locStatus = DeletionRestrictionsResult.getIntField("locStatus");
		Table.gate_version = DeletionRestrictionsResult.getStringField("gate_version");
		DeletionRestrictionsData.push_back(Table);
		DeletionRestrictionsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded DeletionRestrictions");
#endif

#ifdef CacheDestructibleComponent
	auto DestructibleComponentQuery = this->compileStatement("SELECT * FROM DestructibleComponent");
	auto DestructibleComponentResult = DestructibleComponentQuery.execQuery();
	while (!DestructibleComponentResult.eof()) {
		CDClientStructs::DestructibleComponent Table;
		Table.efId = DestructibleComponentResult.getIntField("efId");
		Table.id = DestructibleComponentResult.getIntField("id");
		Table.faction = DestructibleComponentResult.getIntField("faction");
		Table.factionList = DestructibleComponentResult.getStringField("factionList");
		Table.life = DestructibleComponentResult.getIntField("life");
		Table.imagination = DestructibleComponentResult.getIntField("imagination");
		Table.LootMatrixIndex = DestructibleComponentResult.getIntField("LootMatrixIndex");
		Table.CurrencyIndex = DestructibleComponentResult.getIntField("CurrencyIndex");
		Table.level = DestructibleComponentResult.getIntField("level");
		Table.armor = DestructibleComponentResult.getFloatField("armor");
		Table.death_behavior = DestructibleComponentResult.getIntField("death_behavior");
		Table.isnpc = DestructibleComponentResult.getIntField("isnpc");
		Table.attack_priority = DestructibleComponentResult.getIntField("attack_priority");
		Table.isSmashable = DestructibleComponentResult.getIntField("isSmashable");
		Table.difficultyLevel = DestructibleComponentResult.getInt64Field("difficultyLevel");
		DestructibleComponentData.push_back(Table);
		DestructibleComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded DestructibleComponent");
#endif

#ifdef CacheEmotes
	auto EmotesQuery = this->compileStatement("SELECT * FROM Emotes");
	auto EmotesResult = EmotesQuery.execQuery();
	while (!EmotesResult.eof()) {
		CDClientStructs::Emotes Table;
		Table.efId = EmotesResult.getIntField("efId");
		Table.id = EmotesResult.getIntField("id");
		Table.animationName = EmotesResult.getStringField("animationName");
		Table.iconFilename = EmotesResult.getStringField("iconFilename");
		Table.channel = EmotesResult.getStringField("channel");
		Table.command = EmotesResult.getStringField("command");
		Table.locked = EmotesResult.getIntField("locked");
		Table.localize = EmotesResult.getIntField("localize");
		Table.locStatus = EmotesResult.getIntField("locStatus");
		Table.gate_version = EmotesResult.getStringField("gate_version");
		EmotesData.push_back(Table);
		EmotesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Emotes");
#endif

#ifdef CacheEventGating
	auto EventGatingQuery = this->compileStatement("SELECT * FROM EventGating");
	auto EventGatingResult = EventGatingQuery.execQuery();
	while (!EventGatingResult.eof()) {
		CDClientStructs::EventGating Table;
		Table.efId = EventGatingResult.getIntField("efId");
		Table.eventName = EventGatingResult.getStringField("eventName");
		Table.date_start = EventGatingResult.getIntField("date_start");
		Table.date_end = EventGatingResult.getIntField("date_end");
		EventGatingData.push_back(Table);
		EventGatingResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded EventGating");
#endif

#ifdef CacheExhibitComponent
	auto ExhibitComponentQuery = this->compileStatement("SELECT * FROM ExhibitComponent");
	auto ExhibitComponentResult = ExhibitComponentQuery.execQuery();
	while (!ExhibitComponentResult.eof()) {
		CDClientStructs::ExhibitComponent Table;
		Table.efId = ExhibitComponentResult.getIntField("efId");
		Table.id = ExhibitComponentResult.getIntField("id");
		Table.length = ExhibitComponentResult.getFloatField("length");
		Table.width = ExhibitComponentResult.getFloatField("width");
		Table.height = ExhibitComponentResult.getFloatField("height");
		Table.offsetX = ExhibitComponentResult.getFloatField("offsetX");
		Table.offsetY = ExhibitComponentResult.getFloatField("offsetY");
		Table.offsetZ = ExhibitComponentResult.getFloatField("offsetZ");
		Table.fReputationSizeMultiplier = ExhibitComponentResult.getFloatField("fReputationSizeMultiplier");
		Table.fImaginationCost = ExhibitComponentResult.getFloatField("fImaginationCost");
		ExhibitComponentData.push_back(Table);
		ExhibitComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ExhibitComponent");
#endif

#ifdef CacheFactions
	auto FactionsQuery = this->compileStatement("SELECT * FROM Factions");
	auto FactionsResult = FactionsQuery.execQuery();
	while (!FactionsResult.eof()) {
		CDClientStructs::Factions Table;
		Table.efId = FactionsResult.getIntField("efId");
		Table.faction = FactionsResult.getIntField("faction");
		Table.factionList = FactionsResult.getStringField("factionList");
		Table.factionListFriendly = FactionsResult.getIntField("factionListFriendly");
		Table.friendList = FactionsResult.getStringField("friendList");
		Table.enemyList = FactionsResult.getStringField("enemyList");
		FactionsData.push_back(Table);
		FactionsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Factions");
#endif

#ifdef CacheFeatureGating
	auto FeatureGatingQuery = this->compileStatement("SELECT * FROM FeatureGating");
	auto FeatureGatingResult = FeatureGatingQuery.execQuery();
	while (!FeatureGatingResult.eof()) {
		CDClientStructs::FeatureGating Table;
		Table.efId = FeatureGatingResult.getIntField("efId");
		Table.featureName = FeatureGatingResult.getStringField("featureName");
		Table.major = FeatureGatingResult.getIntField("major");
		Table.current = FeatureGatingResult.getIntField("current");
		Table.minor = FeatureGatingResult.getIntField("minor");
		Table.description = FeatureGatingResult.getStringField("description");
		FeatureGatingData.push_back(Table);
		FeatureGatingResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded FeatureGating");
#endif

#ifdef CacheFlairTable
	auto FlairTableQuery = this->compileStatement("SELECT * FROM FlairTable");
	auto FlairTableResult = FlairTableQuery.execQuery();
	while (!FlairTableResult.eof()) {
		CDClientStructs::FlairTable Table;
		Table.efId = FlairTableResult.getIntField("efId");
		Table.id = FlairTableResult.getIntField("id");
		Table.asset = FlairTableResult.getStringField("asset");
		FlairTableData.push_back(Table);
		FlairTableResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded FlairTable");
#endif

#ifdef CacheIcons
	auto IconsQuery = this->compileStatement("SELECT * FROM Icons");
	auto IconsResult = IconsQuery.execQuery();
	while (!IconsResult.eof()) {
		CDClientStructs::Icons Table;
		Table.efId = IconsResult.getIntField("efId");
		Table.IconID = IconsResult.getIntField("IconID");
		Table.IconPath = IconsResult.getStringField("IconPath");
		Table.IconName = IconsResult.getStringField("IconName");
		IconsData.push_back(Table);
		IconsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Icons");
#endif

#ifdef CacheInventoryComponent
	auto InventoryComponentQuery = this->compileStatement("SELECT * FROM InventoryComponent");
	auto InventoryComponentResult = InventoryComponentQuery.execQuery();
	while (!InventoryComponentResult.eof()) {
		CDClientStructs::InventoryComponent Table;
		Table.efId = InventoryComponentResult.getIntField("efId");
		Table.id = InventoryComponentResult.getIntField("id");
		Table.itemid = InventoryComponentResult.getIntField("itemid");
		Table.count = InventoryComponentResult.getIntField("count");
		Table.equip = InventoryComponentResult.getIntField("equip");
		InventoryComponentData.push_back(Table);
		InventoryComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded InventoryComponent");
#endif

#ifdef CacheItemComponent
	auto ItemComponentQuery = this->compileStatement("SELECT * FROM ItemComponent");
	auto ItemComponentResult = ItemComponentQuery.execQuery();
	while (!ItemComponentResult.eof()) {
		CDClientStructs::ItemComponent Table;
		Table.efId = ItemComponentResult.getIntField("efId");
		Table.id = ItemComponentResult.getIntField("id");
		Table.equipLocation = ItemComponentResult.getStringField("equipLocation");
		Table.baseValue = ItemComponentResult.getIntField("baseValue");
		Table.isKitPiece = ItemComponentResult.getIntField("isKitPiece");
		Table.rarity = ItemComponentResult.getIntField("rarity");
		Table.itemType = ItemComponentResult.getIntField("itemType");
		Table.itemInfo = ItemComponentResult.getInt64Field("itemInfo");
		Table.inLootTable = ItemComponentResult.getIntField("inLootTable");
		Table.inVendor = ItemComponentResult.getIntField("inVendor");
		Table.isUnique = ItemComponentResult.getIntField("isUnique");
		Table.isBOP = ItemComponentResult.getIntField("isBOP");
		Table.isBOE = ItemComponentResult.getIntField("isBOE");
		Table.reqFlagID = ItemComponentResult.getIntField("reqFlagID");
		Table.reqSpecialtyID = ItemComponentResult.getIntField("reqSpecialtyID");
		Table.reqSpecRank = ItemComponentResult.getIntField("reqSpecRank");
		Table.reqAchievementID = ItemComponentResult.getIntField("reqAchievementID");
		Table.stackSize = ItemComponentResult.getIntField("stackSize");
		Table.color1 = ItemComponentResult.getIntField("color1");
		Table.decal = ItemComponentResult.getIntField("decal");
		Table.offsetGroupID = ItemComponentResult.getIntField("offsetGroupID");
		Table.buildTypes = ItemComponentResult.getIntField("buildTypes");
		Table.reqPrecondition = ItemComponentResult.getStringField("reqPrecondition");
		Table.animationFlag = ItemComponentResult.getIntField("animationFlag");
		Table.equipEffects = ItemComponentResult.getIntField("equipEffects");
		Table.readyForQA = ItemComponentResult.getIntField("readyForQA");
		Table.itemRating = ItemComponentResult.getIntField("itemRating");
		Table.isTwoHanded = ItemComponentResult.getIntField("isTwoHanded");
		Table.minNumRequired = ItemComponentResult.getIntField("minNumRequired");
		Table.delResIndex = ItemComponentResult.getIntField("delResIndex");
		Table.currencyLOT = ItemComponentResult.getIntField("currencyLOT");
		Table.altCurrencyCost = ItemComponentResult.getIntField("altCurrencyCost");
		Table.subItems = ItemComponentResult.getStringField("subItems");
		Table.audioEventUse = ItemComponentResult.getStringField("audioEventUse");
		Table.noEquipAnimation = ItemComponentResult.getIntField("noEquipAnimation");
		Table.commendationLOT = ItemComponentResult.getIntField("commendationLOT");
		Table.commendationCost = ItemComponentResult.getIntField("commendationCost");
		Table.audioEquipMetaEventSet = ItemComponentResult.getStringField("audioEquipMetaEventSet");
		Table.currencyCosts = ItemComponentResult.getStringField("currencyCosts");
		Table.ingredientInfo = ItemComponentResult.getStringField("ingredientInfo");
		Table.locStatus = ItemComponentResult.getIntField("locStatus");
		Table.forgeType = ItemComponentResult.getIntField("forgeType");
		Table.SellMultiplier = ItemComponentResult.getFloatField("SellMultiplier");
		ItemComponentData.push_back(Table);
		ItemComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ItemComponent");
#endif

#ifdef CacheItemEggData
	auto ItemEggDataQuery = this->compileStatement("SELECT * FROM ItemEggData");
	auto ItemEggDataResult = ItemEggDataQuery.execQuery();
	while (!ItemEggDataResult.eof()) {
		CDClientStructs::ItemEggData Table;
		Table.efId = ItemEggDataResult.getIntField("efId");
		Table.id = ItemEggDataResult.getIntField("id");
		Table.chassie_type_id = ItemEggDataResult.getIntField("chassie_type_id");
		ItemEggDataData.push_back(Table);
		ItemEggDataResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ItemEggData");
#endif

#ifdef CacheItemSetSkills
	auto ItemSetSkillsQuery = this->compileStatement("SELECT * FROM ItemSetSkills");
	auto ItemSetSkillsResult = ItemSetSkillsQuery.execQuery();
	while (!ItemSetSkillsResult.eof()) {
		CDClientStructs::ItemSetSkills Table;
		Table.efId = ItemSetSkillsResult.getIntField("efId");
		Table.SkillSetID = ItemSetSkillsResult.getIntField("SkillSetID");
		Table.SkillID = ItemSetSkillsResult.getIntField("SkillID");
		Table.SkillCastType = ItemSetSkillsResult.getIntField("SkillCastType");
		ItemSetSkillsData.push_back(Table);
		ItemSetSkillsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ItemSetSkills");
#endif

#ifdef CacheItemSets
	auto ItemSetsQuery = this->compileStatement("SELECT * FROM ItemSets");
	auto ItemSetsResult = ItemSetsQuery.execQuery();
	while (!ItemSetsResult.eof()) {
		CDClientStructs::ItemSets Table;
		Table.efId = ItemSetsResult.getIntField("efId");
		Table.setID = ItemSetsResult.getIntField("setID");
		Table.locStatus = ItemSetsResult.getIntField("locStatus");
		Table.itemIDs = ItemSetsResult.getStringField("itemIDs");
		Table.kitType = ItemSetsResult.getIntField("kitType");
		Table.kitRank = ItemSetsResult.getIntField("kitRank");
		Table.kitImage = ItemSetsResult.getIntField("kitImage");
		Table.skillSetWith2 = ItemSetsResult.getIntField("skillSetWith2");
		Table.skillSetWith3 = ItemSetsResult.getIntField("skillSetWith3");
		Table.skillSetWith4 = ItemSetsResult.getIntField("skillSetWith4");
		Table.skillSetWith5 = ItemSetsResult.getIntField("skillSetWith5");
		Table.skillSetWith6 = ItemSetsResult.getIntField("skillSetWith6");
		Table.localize = ItemSetsResult.getIntField("localize");
		Table.gate_version = ItemSetsResult.getStringField("gate_version");
		Table.kitID = ItemSetsResult.getInt64Field("kitID");
		Table.priority = ItemSetsResult.getFloatField("priority");
		ItemSetsData.push_back(Table);
		ItemSetsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ItemSets");
#endif

#ifdef CacheJetPackPadComponent
	auto JetPackPadComponentQuery = this->compileStatement("SELECT * FROM JetPackPadComponent");
	auto JetPackPadComponentResult = JetPackPadComponentQuery.execQuery();
	while (!JetPackPadComponentResult.eof()) {
		CDClientStructs::JetPackPadComponent Table;
		Table.efId = JetPackPadComponentResult.getIntField("efId");
		Table.id = JetPackPadComponentResult.getIntField("id");
		Table.xDistance = JetPackPadComponentResult.getFloatField("xDistance");
		Table.yDistance = JetPackPadComponentResult.getFloatField("yDistance");
		Table.warnDistance = JetPackPadComponentResult.getFloatField("warnDistance");
		Table.lotBlocker = JetPackPadComponentResult.getIntField("lotBlocker");
		Table.lotWarningVolume = JetPackPadComponentResult.getIntField("lotWarningVolume");
		JetPackPadComponentData.push_back(Table);
		JetPackPadComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded JetPackPadComponent");
#endif

#ifdef CacheLUPExhibitComponent
	auto LUPExhibitComponentQuery = this->compileStatement("SELECT * FROM LUPExhibitComponent");
	auto LUPExhibitComponentResult = LUPExhibitComponentQuery.execQuery();
	while (!LUPExhibitComponentResult.eof()) {
		CDClientStructs::LUPExhibitComponent Table;
		Table.efId = LUPExhibitComponentResult.getIntField("efId");
		Table.id = LUPExhibitComponentResult.getIntField("id");
		Table.minXZ = LUPExhibitComponentResult.getFloatField("minXZ");
		Table.maxXZ = LUPExhibitComponentResult.getFloatField("maxXZ");
		Table.maxY = LUPExhibitComponentResult.getFloatField("maxY");
		Table.offsetX = LUPExhibitComponentResult.getFloatField("offsetX");
		Table.offsetY = LUPExhibitComponentResult.getFloatField("offsetY");
		Table.offsetZ = LUPExhibitComponentResult.getFloatField("offsetZ");
		LUPExhibitComponentData.push_back(Table);
		LUPExhibitComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded LUPExhibitComponent");
#endif

#ifdef CacheLUPExhibitModelData
	auto LUPExhibitModelDataQuery = this->compileStatement("SELECT * FROM LUPExhibitModelData");
	auto LUPExhibitModelDataResult = LUPExhibitModelDataQuery.execQuery();
	while (!LUPExhibitModelDataResult.eof()) {
		CDClientStructs::LUPExhibitModelData Table;
		Table.efId = LUPExhibitModelDataResult.getIntField("efId");
		Table.LOT = LUPExhibitModelDataResult.getIntField("LOT");
		Table.minXZ = LUPExhibitModelDataResult.getFloatField("minXZ");
		Table.maxXZ = LUPExhibitModelDataResult.getFloatField("maxXZ");
		Table.maxY = LUPExhibitModelDataResult.getFloatField("maxY");
		Table.description = LUPExhibitModelDataResult.getStringField("description");
		Table.owner = LUPExhibitModelDataResult.getStringField("owner");
		LUPExhibitModelDataData.push_back(Table);
		LUPExhibitModelDataResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded LUPExhibitModelData");
#endif

#ifdef CacheLUPZoneIDs
	auto LUPZoneIDsQuery = this->compileStatement("SELECT * FROM LUPZoneIDs");
	auto LUPZoneIDsResult = LUPZoneIDsQuery.execQuery();
	while (!LUPZoneIDsResult.eof()) {
		CDClientStructs::LUPZoneIDs Table;
		Table.efId = LUPZoneIDsResult.getIntField("efId");
		Table.zoneID = LUPZoneIDsResult.getIntField("zoneID");
		LUPZoneIDsData.push_back(Table);
		LUPZoneIDsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded LUPZoneIDs");
#endif

#ifdef CacheLanguageType
	auto LanguageTypeQuery = this->compileStatement("SELECT * FROM LanguageType");
	auto LanguageTypeResult = LanguageTypeQuery.execQuery();
	while (!LanguageTypeResult.eof()) {
		CDClientStructs::LanguageType Table;
		Table.efId = LanguageTypeResult.getIntField("efId");
		Table.LanguageID = LanguageTypeResult.getIntField("LanguageID");
		Table.LanguageDescription = LanguageTypeResult.getStringField("LanguageDescription");
		LanguageTypeData.push_back(Table);
		LanguageTypeResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded LanguageType");
#endif

#ifdef CacheLevelProgressionLookup
	auto LevelProgressionLookupQuery = this->compileStatement("SELECT * FROM LevelProgressionLookup");
	auto LevelProgressionLookupResult = LevelProgressionLookupQuery.execQuery();
	while (!LevelProgressionLookupResult.eof()) {
		CDClientStructs::LevelProgressionLookup Table;
		Table.efId = LevelProgressionLookupResult.getIntField("efId");
		Table.id = LevelProgressionLookupResult.getIntField("id");
		Table.requiredUScore = LevelProgressionLookupResult.getIntField("requiredUScore");
		Table.BehaviorEffect = LevelProgressionLookupResult.getStringField("BehaviorEffect");
		LevelProgressionLookupData.push_back(Table);
		LevelProgressionLookupResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded LevelProgressionLookup");
#endif

#ifdef CacheLootMatrix
	auto LootMatrixQuery = this->compileStatement("SELECT * FROM LootMatrix");
	auto LootMatrixResult = LootMatrixQuery.execQuery();
	while (!LootMatrixResult.eof()) {
		CDClientStructs::LootMatrix Table;
		Table.efId = LootMatrixResult.getIntField("efId");
		Table.LootMatrixIndex = LootMatrixResult.getIntField("LootMatrixIndex");
		Table.LootTableIndex = LootMatrixResult.getIntField("LootTableIndex");
		Table.RarityTableIndex = LootMatrixResult.getIntField("RarityTableIndex");
		Table.percent = LootMatrixResult.getFloatField("percent");
		Table.minToDrop = LootMatrixResult.getIntField("minToDrop");
		Table.maxToDrop = LootMatrixResult.getIntField("maxToDrop");
		Table.id = LootMatrixResult.getIntField("id");
		Table.flagID = LootMatrixResult.getIntField("flagID");
		Table.gate_version = LootMatrixResult.getStringField("gate_version");
		LootMatrixData.push_back(Table);
		LootMatrixResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded LootMatrix");
#endif

#ifdef CacheLootMatrixIndex
	auto LootMatrixIndexQuery = this->compileStatement("SELECT * FROM LootMatrixIndex");
	auto LootMatrixIndexResult = LootMatrixIndexQuery.execQuery();
	while (!LootMatrixIndexResult.eof()) {
		CDClientStructs::LootMatrixIndex Table;
		Table.efId = LootMatrixIndexResult.getIntField("efId");
		Table.LootMatrixIndex = LootMatrixIndexResult.getIntField("LootMatrixIndex");
		Table.inNpcEditor = LootMatrixIndexResult.getIntField("inNpcEditor");
		LootMatrixIndexData.push_back(Table);
		LootMatrixIndexResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded LootMatrixIndex");
#endif

#ifdef CacheLootTable
	auto LootTableQuery = this->compileStatement("SELECT * FROM LootTable");
	auto LootTableResult = LootTableQuery.execQuery();
	while (!LootTableResult.eof()) {
		CDClientStructs::LootTable Table;
		Table.efId = LootTableResult.getIntField("efId");
		Table.itemid = LootTableResult.getIntField("itemid");
		Table.LootTableIndex = LootTableResult.getIntField("LootTableIndex");
		Table.id = LootTableResult.getIntField("id");
		Table.MissionDrop = LootTableResult.getIntField("MissionDrop");
		Table.sortPriority = LootTableResult.getIntField("sortPriority");
		LootTableData.push_back(Table);
		LootTableResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded LootTable");
#endif

#ifdef CacheLootTableIndex
	auto LootTableIndexQuery = this->compileStatement("SELECT * FROM LootTableIndex");
	auto LootTableIndexResult = LootTableIndexQuery.execQuery();
	while (!LootTableIndexResult.eof()) {
		CDClientStructs::LootTableIndex Table;
		Table.efId = LootTableIndexResult.getIntField("efId");
		Table.LootTableIndex = LootTableIndexResult.getIntField("LootTableIndex");
		LootTableIndexData.push_back(Table);
		LootTableIndexResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded LootTableIndex");
#endif

#ifdef CacheMinifigComponent
	auto MinifigComponentQuery = this->compileStatement("SELECT * FROM MinifigComponent");
	auto MinifigComponentResult = MinifigComponentQuery.execQuery();
	while (!MinifigComponentResult.eof()) {
		CDClientStructs::MinifigComponent Table;
		Table.efId = MinifigComponentResult.getIntField("efId");
		Table.id = MinifigComponentResult.getIntField("id");
		Table.head = MinifigComponentResult.getIntField("head");
		Table.chest = MinifigComponentResult.getIntField("chest");
		Table.legs = MinifigComponentResult.getIntField("legs");
		Table.hairstyle = MinifigComponentResult.getIntField("hairstyle");
		Table.haircolor = MinifigComponentResult.getIntField("haircolor");
		Table.chestdecal = MinifigComponentResult.getIntField("chestdecal");
		Table.headcolor = MinifigComponentResult.getIntField("headcolor");
		Table.lefthand = MinifigComponentResult.getIntField("lefthand");
		Table.righthand = MinifigComponentResult.getIntField("righthand");
		Table.eyebrowstyle = MinifigComponentResult.getIntField("eyebrowstyle");
		Table.eyesstyle = MinifigComponentResult.getIntField("eyesstyle");
		Table.mouthstyle = MinifigComponentResult.getIntField("mouthstyle");
		MinifigComponentData.push_back(Table);
		MinifigComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MinifigComponent");
#endif

#ifdef CacheMinifigDecals_Eyebrows
	auto MinifigDecals_EyebrowsQuery = this->compileStatement("SELECT * FROM MinifigDecals_Eyebrows");
	auto MinifigDecals_EyebrowsResult = MinifigDecals_EyebrowsQuery.execQuery();
	while (!MinifigDecals_EyebrowsResult.eof()) {
		CDClientStructs::MinifigDecals_Eyebrows Table;
		Table.efId = MinifigDecals_EyebrowsResult.getIntField("efId");
		Table.ID = MinifigDecals_EyebrowsResult.getIntField("ID");
		Table.High_path = MinifigDecals_EyebrowsResult.getStringField("High_path");
		Table.Low_path = MinifigDecals_EyebrowsResult.getStringField("Low_path");
		Table.CharacterCreateValid = MinifigDecals_EyebrowsResult.getIntField("CharacterCreateValid");
		Table.male = MinifigDecals_EyebrowsResult.getIntField("male");
		Table.female = MinifigDecals_EyebrowsResult.getIntField("female");
		MinifigDecals_EyebrowsData.push_back(Table);
		MinifigDecals_EyebrowsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MinifigDecals_Eyebrows");
#endif

#ifdef CacheMinifigDecals_Eyes
	auto MinifigDecals_EyesQuery = this->compileStatement("SELECT * FROM MinifigDecals_Eyes");
	auto MinifigDecals_EyesResult = MinifigDecals_EyesQuery.execQuery();
	while (!MinifigDecals_EyesResult.eof()) {
		CDClientStructs::MinifigDecals_Eyes Table;
		Table.efId = MinifigDecals_EyesResult.getIntField("efId");
		Table.ID = MinifigDecals_EyesResult.getIntField("ID");
		Table.High_path = MinifigDecals_EyesResult.getStringField("High_path");
		Table.Low_path = MinifigDecals_EyesResult.getStringField("Low_path");
		Table.CharacterCreateValid = MinifigDecals_EyesResult.getIntField("CharacterCreateValid");
		Table.male = MinifigDecals_EyesResult.getIntField("male");
		Table.female = MinifigDecals_EyesResult.getIntField("female");
		MinifigDecals_EyesData.push_back(Table);
		MinifigDecals_EyesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MinifigDecals_Eyes");
#endif

#ifdef CacheMinifigDecals_Legs
	auto MinifigDecals_LegsQuery = this->compileStatement("SELECT * FROM MinifigDecals_Legs");
	auto MinifigDecals_LegsResult = MinifigDecals_LegsQuery.execQuery();
	while (!MinifigDecals_LegsResult.eof()) {
		CDClientStructs::MinifigDecals_Legs Table;
		Table.efId = MinifigDecals_LegsResult.getIntField("efId");
		Table.ID = MinifigDecals_LegsResult.getIntField("ID");
		Table.High_path = MinifigDecals_LegsResult.getStringField("High_path");
		MinifigDecals_LegsData.push_back(Table);
		MinifigDecals_LegsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MinifigDecals_Legs");
#endif

#ifdef CacheMinifigDecals_Mouths
	auto MinifigDecals_MouthsQuery = this->compileStatement("SELECT * FROM MinifigDecals_Mouths");
	auto MinifigDecals_MouthsResult = MinifigDecals_MouthsQuery.execQuery();
	while (!MinifigDecals_MouthsResult.eof()) {
		CDClientStructs::MinifigDecals_Mouths Table;
		Table.efId = MinifigDecals_MouthsResult.getIntField("efId");
		Table.ID = MinifigDecals_MouthsResult.getIntField("ID");
		Table.High_path = MinifigDecals_MouthsResult.getStringField("High_path");
		Table.Low_path = MinifigDecals_MouthsResult.getStringField("Low_path");
		Table.CharacterCreateValid = MinifigDecals_MouthsResult.getIntField("CharacterCreateValid");
		Table.male = MinifigDecals_MouthsResult.getIntField("male");
		Table.female = MinifigDecals_MouthsResult.getIntField("female");
		MinifigDecals_MouthsData.push_back(Table);
		MinifigDecals_MouthsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MinifigDecals_Mouths");
#endif

#ifdef CacheMinifigDecals_Torsos
	auto MinifigDecals_TorsosQuery = this->compileStatement("SELECT * FROM MinifigDecals_Torsos");
	auto MinifigDecals_TorsosResult = MinifigDecals_TorsosQuery.execQuery();
	while (!MinifigDecals_TorsosResult.eof()) {
		CDClientStructs::MinifigDecals_Torsos Table;
		Table.efId = MinifigDecals_TorsosResult.getIntField("efId");
		Table.ID = MinifigDecals_TorsosResult.getIntField("ID");
		Table.High_path = MinifigDecals_TorsosResult.getStringField("High_path");
		Table.CharacterCreateValid = MinifigDecals_TorsosResult.getIntField("CharacterCreateValid");
		Table.male = MinifigDecals_TorsosResult.getIntField("male");
		Table.female = MinifigDecals_TorsosResult.getIntField("female");
		MinifigDecals_TorsosData.push_back(Table);
		MinifigDecals_TorsosResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MinifigDecals_Torsos");
#endif

#ifdef CacheMissionEmail
	auto MissionEmailQuery = this->compileStatement("SELECT * FROM MissionEmail");
	auto MissionEmailResult = MissionEmailQuery.execQuery();
	while (!MissionEmailResult.eof()) {
		CDClientStructs::MissionEmail Table;
		Table.efId = MissionEmailResult.getIntField("efId");
		Table.ID = MissionEmailResult.getIntField("ID");
		Table.messageType = MissionEmailResult.getIntField("messageType");
		Table.notificationGroup = MissionEmailResult.getIntField("notificationGroup");
		Table.missionID = MissionEmailResult.getIntField("missionID");
		Table.attachmentLOT = MissionEmailResult.getIntField("attachmentLOT");
		Table.localize = MissionEmailResult.getIntField("localize");
		Table.locStatus = MissionEmailResult.getIntField("locStatus");
		Table.gate_version = MissionEmailResult.getStringField("gate_version");
		MissionEmailData.push_back(Table);
		MissionEmailResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MissionEmail");
#endif

#ifdef CacheMissionNPCComponent
	auto MissionNPCComponentQuery = this->compileStatement("SELECT * FROM MissionNPCComponent");
	auto MissionNPCComponentResult = MissionNPCComponentQuery.execQuery();
	while (!MissionNPCComponentResult.eof()) {
		CDClientStructs::MissionNPCComponent Table;
		Table.efId = MissionNPCComponentResult.getIntField("efId");
		Table.id = MissionNPCComponentResult.getIntField("id");
		Table.missionID = MissionNPCComponentResult.getIntField("missionID");
		Table.offersMission = MissionNPCComponentResult.getIntField("offersMission");
		Table.acceptsMission = MissionNPCComponentResult.getIntField("acceptsMission");
		Table.gate_version = MissionNPCComponentResult.getStringField("gate_version");
		MissionNPCComponentData.push_back(Table);
		MissionNPCComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MissionNPCComponent");
#endif

#ifdef CacheMissionTasks
	auto MissionTasksQuery = this->compileStatement("SELECT * FROM MissionTasks");
	auto MissionTasksResult = MissionTasksQuery.execQuery();
	while (!MissionTasksResult.eof()) {
		CDClientStructs::MissionTasks Table;
		Table.efId = MissionTasksResult.getIntField("efId");
		Table.id = MissionTasksResult.getIntField("id");
		Table.locStatus = MissionTasksResult.getIntField("locStatus");
		Table.taskType = MissionTasksResult.getIntField("taskType");
		Table.target = MissionTasksResult.getIntField("target");
		Table.targetGroup = MissionTasksResult.getStringField("targetGroup");
		Table.targetValue = MissionTasksResult.getIntField("targetValue");
		Table.taskParam1 = MissionTasksResult.getStringField("taskParam1");
		Table.largeTaskIcon = MissionTasksResult.getStringField("largeTaskIcon");
		Table.IconID = MissionTasksResult.getIntField("IconID");
		Table.uid = MissionTasksResult.getIntField("uid");
		Table.largeTaskIconID = MissionTasksResult.getIntField("largeTaskIconID");
		Table.localize = MissionTasksResult.getIntField("localize");
		Table.gate_version = MissionTasksResult.getStringField("gate_version");
		MissionTasksData.push_back(Table);
		MissionTasksResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MissionTasks");
#endif

#ifdef CacheMissionText
	auto MissionTextQuery = this->compileStatement("SELECT * FROM MissionText");
	auto MissionTextResult = MissionTextQuery.execQuery();
	while (!MissionTextResult.eof()) {
		CDClientStructs::MissionText Table;
		Table.efId = MissionTextResult.getIntField("efId");
		Table.id = MissionTextResult.getIntField("id");
		Table.story_icon = MissionTextResult.getStringField("story_icon");
		Table.missionIcon = MissionTextResult.getStringField("missionIcon");
		Table.offerNPCIcon = MissionTextResult.getStringField("offerNPCIcon");
		Table.IconID = MissionTextResult.getIntField("IconID");
		Table.state_1_anim = MissionTextResult.getStringField("state_1_anim");
		Table.state_2_anim = MissionTextResult.getStringField("state_2_anim");
		Table.state_3_anim = MissionTextResult.getStringField("state_3_anim");
		Table.state_4_anim = MissionTextResult.getStringField("state_4_anim");
		Table.state_3_turnin_anim = MissionTextResult.getStringField("state_3_turnin_anim");
		Table.state_4_turnin_anim = MissionTextResult.getStringField("state_4_turnin_anim");
		Table.onclick_anim = MissionTextResult.getStringField("onclick_anim");
		Table.CinematicAccepted = MissionTextResult.getStringField("CinematicAccepted");
		Table.CinematicAcceptedLeadin = MissionTextResult.getFloatField("CinematicAcceptedLeadin");
		Table.CinematicCompleted = MissionTextResult.getStringField("CinematicCompleted");
		Table.CinematicCompletedLeadin = MissionTextResult.getFloatField("CinematicCompletedLeadin");
		Table.CinematicRepeatable = MissionTextResult.getStringField("CinematicRepeatable");
		Table.CinematicRepeatableLeadin = MissionTextResult.getFloatField("CinematicRepeatableLeadin");
		Table.CinematicRepeatableCompleted = MissionTextResult.getStringField("CinematicRepeatableCompleted");
		Table.CinematicRepeatableCompletedLeadin = MissionTextResult.getFloatField("CinematicRepeatableCompletedLeadin");
		Table.AudioEventGUID_Interact = MissionTextResult.getStringField("AudioEventGUID_Interact");
		Table.AudioEventGUID_OfferAccept = MissionTextResult.getStringField("AudioEventGUID_OfferAccept");
		Table.AudioEventGUID_OfferDeny = MissionTextResult.getStringField("AudioEventGUID_OfferDeny");
		Table.AudioEventGUID_Completed = MissionTextResult.getStringField("AudioEventGUID_Completed");
		Table.AudioEventGUID_TurnIn = MissionTextResult.getStringField("AudioEventGUID_TurnIn");
		Table.AudioEventGUID_Failed = MissionTextResult.getStringField("AudioEventGUID_Failed");
		Table.AudioEventGUID_Progress = MissionTextResult.getStringField("AudioEventGUID_Progress");
		Table.AudioMusicCue_OfferAccept = MissionTextResult.getStringField("AudioMusicCue_OfferAccept");
		Table.AudioMusicCue_TurnIn = MissionTextResult.getStringField("AudioMusicCue_TurnIn");
		Table.turnInIconID = MissionTextResult.getIntField("turnInIconID");
		Table.localize = MissionTextResult.getIntField("localize");
		Table.locStatus = MissionTextResult.getIntField("locStatus");
		Table.gate_version = MissionTextResult.getStringField("gate_version");
		MissionTextData.push_back(Table);
		MissionTextResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MissionText");
#endif

#ifdef CacheMissions
	auto MissionsQuery = this->compileStatement("SELECT * FROM Missions");
	auto MissionsResult = MissionsQuery.execQuery();
	while (!MissionsResult.eof()) {
		CDClientStructs::Missions Table;
		Table.efId = MissionsResult.getIntField("efId");
		Table.id = MissionsResult.getIntField("id");
		Table.defined_type = MissionsResult.getStringField("defined_type");
		Table.defined_subtype = MissionsResult.getStringField("defined_subtype");
		Table.UISortOrder = MissionsResult.getIntField("UISortOrder");
		Table.offer_objectID = MissionsResult.getIntField("offer_objectID");
		Table.target_objectID = MissionsResult.getIntField("target_objectID");
		Table.reward_currency = MissionsResult.getIntField("reward_currency");
		Table.LegoScore = MissionsResult.getIntField("LegoScore");
		Table.reward_reputation = MissionsResult.getIntField("reward_reputation");
		Table.isChoiceReward = MissionsResult.getIntField("isChoiceReward");
		Table.reward_item1 = MissionsResult.getIntField("reward_item1");
		Table.reward_item1_count = MissionsResult.getIntField("reward_item1_count");
		Table.reward_item2 = MissionsResult.getIntField("reward_item2");
		Table.reward_item2_count = MissionsResult.getIntField("reward_item2_count");
		Table.reward_item3 = MissionsResult.getIntField("reward_item3");
		Table.reward_item3_count = MissionsResult.getIntField("reward_item3_count");
		Table.reward_item4 = MissionsResult.getIntField("reward_item4");
		Table.reward_item4_count = MissionsResult.getIntField("reward_item4_count");
		Table.reward_emote = MissionsResult.getIntField("reward_emote");
		Table.reward_emote2 = MissionsResult.getIntField("reward_emote2");
		Table.reward_emote3 = MissionsResult.getIntField("reward_emote3");
		Table.reward_emote4 = MissionsResult.getIntField("reward_emote4");
		Table.reward_maximagination = MissionsResult.getIntField("reward_maximagination");
		Table.reward_maxhealth = MissionsResult.getIntField("reward_maxhealth");
		Table.reward_maxinventory = MissionsResult.getIntField("reward_maxinventory");
		Table.reward_maxmodel = MissionsResult.getIntField("reward_maxmodel");
		Table.reward_maxwidget = MissionsResult.getIntField("reward_maxwidget");
		Table.reward_maxwallet = MissionsResult.getIntField("reward_maxwallet");
		Table.repeatable = MissionsResult.getIntField("repeatable");
		Table.reward_currency_repeatable = MissionsResult.getIntField("reward_currency_repeatable");
		Table.reward_item1_repeatable = MissionsResult.getIntField("reward_item1_repeatable");
		Table.reward_item1_repeat_count = MissionsResult.getIntField("reward_item1_repeat_count");
		Table.reward_item2_repeatable = MissionsResult.getIntField("reward_item2_repeatable");
		Table.reward_item2_repeat_count = MissionsResult.getIntField("reward_item2_repeat_count");
		Table.reward_item3_repeatable = MissionsResult.getIntField("reward_item3_repeatable");
		Table.reward_item3_repeat_count = MissionsResult.getIntField("reward_item3_repeat_count");
		Table.reward_item4_repeatable = MissionsResult.getIntField("reward_item4_repeatable");
		Table.reward_item4_repeat_count = MissionsResult.getIntField("reward_item4_repeat_count");
		Table.time_limit = MissionsResult.getIntField("time_limit");
		Table.isMission = MissionsResult.getIntField("isMission");
		Table.missionIconID = MissionsResult.getIntField("missionIconID");
		Table.prereqMissionID = MissionsResult.getStringField("prereqMissionID");
		Table.localize = MissionsResult.getIntField("localize");
		Table.inMOTD = MissionsResult.getIntField("inMOTD");
		Table.cooldownTime = MissionsResult.getIntField("cooldownTime");
		Table.isRandom = MissionsResult.getIntField("isRandom");
		Table.randomPool = MissionsResult.getStringField("randomPool");
		Table.UIPrereqID = MissionsResult.getIntField("UIPrereqID");
		Table.gate_version = MissionsResult.getStringField("gate_version");
		Table.HUDStates = MissionsResult.getStringField("HUDStates");
		Table.locStatus = MissionsResult.getIntField("locStatus");
		Table.reward_bankinventory = MissionsResult.getIntField("reward_bankinventory");
		MissionsData.push_back(Table);
		MissionsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Missions");
#endif

#ifdef CacheModelBehavior
	auto ModelBehaviorQuery = this->compileStatement("SELECT * FROM ModelBehavior");
	auto ModelBehaviorResult = ModelBehaviorQuery.execQuery();
	while (!ModelBehaviorResult.eof()) {
		CDClientStructs::ModelBehavior Table;
		Table.efId = ModelBehaviorResult.getIntField("efId");
		Table.id = ModelBehaviorResult.getIntField("id");
		Table.definitionXMLfilename = ModelBehaviorResult.getStringField("definitionXMLfilename");
		ModelBehaviorData.push_back(Table);
		ModelBehaviorResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ModelBehavior");
#endif

#ifdef CacheModularBuildComponent
	auto ModularBuildComponentQuery = this->compileStatement("SELECT * FROM ModularBuildComponent");
	auto ModularBuildComponentResult = ModularBuildComponentQuery.execQuery();
	while (!ModularBuildComponentResult.eof()) {
		CDClientStructs::ModularBuildComponent Table;
		Table.efId = ModularBuildComponentResult.getIntField("efId");
		Table.id = ModularBuildComponentResult.getIntField("id");
		Table.buildType = ModularBuildComponentResult.getIntField("buildType");
		Table.xml = ModularBuildComponentResult.getStringField("xml");
		Table.createdLOT = ModularBuildComponentResult.getIntField("createdLOT");
		Table.createdPhysicsID = ModularBuildComponentResult.getIntField("createdPhysicsID");
		Table.AudioEventGUID_Snap = ModularBuildComponentResult.getStringField("AudioEventGUID_Snap");
		Table.AudioEventGUID_Complete = ModularBuildComponentResult.getStringField("AudioEventGUID_Complete");
		Table.AudioEventGUID_Present = ModularBuildComponentResult.getStringField("AudioEventGUID_Present");
		ModularBuildComponentData.push_back(Table);
		ModularBuildComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ModularBuildComponent");
#endif

#ifdef CacheModuleComponent
	auto ModuleComponentQuery = this->compileStatement("SELECT * FROM ModuleComponent");
	auto ModuleComponentResult = ModuleComponentQuery.execQuery();
	while (!ModuleComponentResult.eof()) {
		CDClientStructs::ModuleComponent Table;
		Table.efId = ModuleComponentResult.getIntField("efId");
		Table.id = ModuleComponentResult.getIntField("id");
		Table.partCode = ModuleComponentResult.getIntField("partCode");
		Table.buildType = ModuleComponentResult.getIntField("buildType");
		Table.xml = ModuleComponentResult.getStringField("xml");
		Table.primarySoundGUID = ModuleComponentResult.getStringField("primarySoundGUID");
		Table.assembledEffectID = ModuleComponentResult.getIntField("assembledEffectID");
		ModuleComponentData.push_back(Table);
		ModuleComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ModuleComponent");
#endif

#ifdef CacheMotionFX
	auto MotionFXQuery = this->compileStatement("SELECT * FROM MotionFX");
	auto MotionFXResult = MotionFXQuery.execQuery();
	while (!MotionFXResult.eof()) {
		CDClientStructs::MotionFX Table;
		Table.efId = MotionFXResult.getIntField("efId");
		Table.id = MotionFXResult.getIntField("id");
		Table.typeID = MotionFXResult.getIntField("typeID");
		Table.slamVelocity = MotionFXResult.getFloatField("slamVelocity");
		Table.addVelocity = MotionFXResult.getFloatField("addVelocity");
		Table.duration = MotionFXResult.getFloatField("duration");
		Table.destGroupName = MotionFXResult.getStringField("destGroupName");
		Table.startScale = MotionFXResult.getFloatField("startScale");
		Table.endScale = MotionFXResult.getFloatField("endScale");
		Table.velocity = MotionFXResult.getFloatField("velocity");
		Table.distance = MotionFXResult.getFloatField("distance");
		MotionFXData.push_back(Table);
		MotionFXResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MotionFX");
#endif

#ifdef CacheMovementAIComponent
	auto MovementAIComponentQuery = this->compileStatement("SELECT * FROM MovementAIComponent");
	auto MovementAIComponentResult = MovementAIComponentQuery.execQuery();
	while (!MovementAIComponentResult.eof()) {
		CDClientStructs::MovementAIComponent Table;
		Table.efId = MovementAIComponentResult.getIntField("efId");
		Table.id = MovementAIComponentResult.getIntField("id");
		Table.MovementType = MovementAIComponentResult.getStringField("MovementType");
		Table.WanderChance = MovementAIComponentResult.getFloatField("WanderChance");
		Table.WanderDelayMin = MovementAIComponentResult.getFloatField("WanderDelayMin");
		Table.WanderDelayMax = MovementAIComponentResult.getFloatField("WanderDelayMax");
		Table.WanderSpeed = MovementAIComponentResult.getFloatField("WanderSpeed");
		Table.WanderRadius = MovementAIComponentResult.getFloatField("WanderRadius");
		Table.attachedPath = MovementAIComponentResult.getStringField("attachedPath");
		MovementAIComponentData.push_back(Table);
		MovementAIComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MovementAIComponent");
#endif

#ifdef CacheMovingPlatforms
	auto MovingPlatformsQuery = this->compileStatement("SELECT * FROM MovingPlatforms");
	auto MovingPlatformsResult = MovingPlatformsQuery.execQuery();
	while (!MovingPlatformsResult.eof()) {
		CDClientStructs::MovingPlatforms Table;
		Table.efId = MovingPlatformsResult.getIntField("efId");
		Table.id = MovingPlatformsResult.getIntField("id");
		Table.platformIsSimpleMover = MovingPlatformsResult.getIntField("platformIsSimpleMover");
		Table.platformMoveX = MovingPlatformsResult.getFloatField("platformMoveX");
		Table.platformMoveY = MovingPlatformsResult.getFloatField("platformMoveY");
		Table.platformMoveZ = MovingPlatformsResult.getFloatField("platformMoveZ");
		Table.platformMoveTime = MovingPlatformsResult.getFloatField("platformMoveTime");
		Table.platformStartAtEnd = MovingPlatformsResult.getIntField("platformStartAtEnd");
		Table.description = MovingPlatformsResult.getStringField("description");
		MovingPlatformsData.push_back(Table);
		MovingPlatformsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded MovingPlatforms");
#endif

#ifdef CacheNpcIcons
	auto NpcIconsQuery = this->compileStatement("SELECT * FROM NpcIcons");
	auto NpcIconsResult = NpcIconsQuery.execQuery();
	while (!NpcIconsResult.eof()) {
		CDClientStructs::NpcIcons Table;
		Table.efId = NpcIconsResult.getIntField("efId");
		Table.id = NpcIconsResult.getIntField("id");
		Table.color = NpcIconsResult.getIntField("color");
		Table.offset = NpcIconsResult.getFloatField("offset");
		Table.LOT = NpcIconsResult.getIntField("LOT");
		Table.Texture = NpcIconsResult.getStringField("Texture");
		Table.isClickable = NpcIconsResult.getIntField("isClickable");
		Table.scale = NpcIconsResult.getFloatField("scale");
		Table.rotateToFace = NpcIconsResult.getIntField("rotateToFace");
		Table.compositeHorizOffset = NpcIconsResult.getFloatField("compositeHorizOffset");
		Table.compositeVertOffset = NpcIconsResult.getFloatField("compositeVertOffset");
		Table.compositeScale = NpcIconsResult.getFloatField("compositeScale");
		Table.compositeConnectionNode = NpcIconsResult.getStringField("compositeConnectionNode");
		Table.compositeLOTMultiMission = NpcIconsResult.getIntField("compositeLOTMultiMission");
		Table.compositeLOTMultiMissionVentor = NpcIconsResult.getIntField("compositeLOTMultiMissionVentor");
		Table.compositeIconTexture = NpcIconsResult.getStringField("compositeIconTexture");
		NpcIconsData.push_back(Table);
		NpcIconsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded NpcIcons");
#endif

#ifdef CacheObjectBehaviors
	auto ObjectBehaviorsQuery = this->compileStatement("SELECT * FROM ObjectBehaviors");
	auto ObjectBehaviorsResult = ObjectBehaviorsQuery.execQuery();
	while (!ObjectBehaviorsResult.eof()) {
		CDClientStructs::ObjectBehaviors Table;
		Table.efId = ObjectBehaviorsResult.getIntField("efId");
		Table.BehaviorID = ObjectBehaviorsResult.getIntField("BehaviorID");
		Table.xmldata = ObjectBehaviorsResult.getStringField("xmldata");
		ObjectBehaviorsData.push_back(Table);
		ObjectBehaviorsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ObjectBehaviors");
#endif

#ifdef CacheObjectSkills
	auto ObjectSkillsQuery = this->compileStatement("SELECT * FROM ObjectSkills");
	auto ObjectSkillsResult = ObjectSkillsQuery.execQuery();
	while (!ObjectSkillsResult.eof()) {
		CDClientStructs::ObjectSkills Table;
		Table.efId = ObjectSkillsResult.getIntField("efId");
		Table.objectTemplate = ObjectSkillsResult.getIntField("objectTemplate");
		Table.skillID = ObjectSkillsResult.getIntField("skillID");
		Table.castOnType = ObjectSkillsResult.getIntField("castOnType");
		Table.AICombatWeight = ObjectSkillsResult.getIntField("AICombatWeight");
		ObjectSkillsData.push_back(Table);
		ObjectSkillsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ObjectSkills");
#endif

#ifdef CacheObjects
	auto ObjectsQuery = this->compileStatement("SELECT * FROM Objects");
	auto ObjectsResult = ObjectsQuery.execQuery();
	while (!ObjectsResult.eof()) {
		CDClientStructs::Objects Table;
		Table.efId = ObjectsResult.getIntField("efId");
		Table.id = ObjectsResult.getIntField("id");
		Table.name = ObjectsResult.getStringField("name");
		Table.placeable = ObjectsResult.getIntField("placeable");
		Table.type = ObjectsResult.getStringField("type");
		Table.description = ObjectsResult.getStringField("description");
		Table.localize = ObjectsResult.getIntField("localize");
		Table.npcTemplateID = ObjectsResult.getIntField("npcTemplateID");
		Table.displayName = ObjectsResult.getStringField("displayName");
		Table.interactionDistance = ObjectsResult.getFloatField("interactionDistance");
		Table.nametag = ObjectsResult.getIntField("nametag");
		Table._internalNotes = ObjectsResult.getStringField("_internalNotes");
		Table.locStatus = ObjectsResult.getIntField("locStatus");
		Table.gate_version = ObjectsResult.getStringField("gate_version");
		Table.HQ_valid = ObjectsResult.getIntField("HQ_valid");
		ObjectsData.push_back(Table);
		ObjectsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Objects");
#endif

#ifdef CachePackageComponent
	auto PackageComponentQuery = this->compileStatement("SELECT * FROM PackageComponent");
	auto PackageComponentResult = PackageComponentQuery.execQuery();
	while (!PackageComponentResult.eof()) {
		CDClientStructs::PackageComponent Table;
		Table.efId = PackageComponentResult.getIntField("efId");
		Table.id = PackageComponentResult.getIntField("id");
		Table.LootMatrixIndex = PackageComponentResult.getIntField("LootMatrixIndex");
		Table.packageType = PackageComponentResult.getIntField("packageType");
		PackageComponentData.push_back(Table);
		PackageComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded PackageComponent");
#endif

#ifdef CachePetAbilities
	auto PetAbilitiesQuery = this->compileStatement("SELECT * FROM PetAbilities");
	auto PetAbilitiesResult = PetAbilitiesQuery.execQuery();
	while (!PetAbilitiesResult.eof()) {
		CDClientStructs::PetAbilities Table;
		Table.efId = PetAbilitiesResult.getIntField("efId");
		Table.id = PetAbilitiesResult.getIntField("id");
		Table.AbilityName = PetAbilitiesResult.getStringField("AbilityName");
		Table.ImaginationCost = PetAbilitiesResult.getIntField("ImaginationCost");
		Table.locStatus = PetAbilitiesResult.getIntField("locStatus");
		PetAbilitiesData.push_back(Table);
		PetAbilitiesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded PetAbilities");
#endif

#ifdef CachePetComponent
	auto PetComponentQuery = this->compileStatement("SELECT * FROM PetComponent");
	auto PetComponentResult = PetComponentQuery.execQuery();
	while (!PetComponentResult.eof()) {
		CDClientStructs::PetComponent Table;
		Table.efId = PetComponentResult.getIntField("efId");
		Table.id = PetComponentResult.getIntField("id");
		Table.minTameUpdateTime = PetComponentResult.getFloatField("minTameUpdateTime");
		Table.maxTameUpdateTime = PetComponentResult.getFloatField("maxTameUpdateTime");
		Table.percentTameChance = PetComponentResult.getFloatField("percentTameChance");
		Table.tamability = PetComponentResult.getFloatField("tamability");
		Table.elementType = PetComponentResult.getIntField("elementType");
		Table.walkSpeed = PetComponentResult.getFloatField("walkSpeed");
		Table.runSpeed = PetComponentResult.getFloatField("runSpeed");
		Table.sprintSpeed = PetComponentResult.getFloatField("sprintSpeed");
		Table.idleTimeMin = PetComponentResult.getFloatField("idleTimeMin");
		Table.idleTimeMax = PetComponentResult.getFloatField("idleTimeMax");
		Table.petForm = PetComponentResult.getIntField("petForm");
		Table.imaginationDrainRate = PetComponentResult.getFloatField("imaginationDrainRate");
		Table.AudioMetaEventSet = PetComponentResult.getStringField("AudioMetaEventSet");
		Table.buffIDs = PetComponentResult.getStringField("buffIDs");
		PetComponentData.push_back(Table);
		PetComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded PetComponent");
#endif

#ifdef CachePetNestComponent
	auto PetNestComponentQuery = this->compileStatement("SELECT * FROM PetNestComponent");
	auto PetNestComponentResult = PetNestComponentQuery.execQuery();
	while (!PetNestComponentResult.eof()) {
		CDClientStructs::PetNestComponent Table;
		Table.efId = PetNestComponentResult.getIntField("efId");
		Table.id = PetNestComponentResult.getIntField("id");
		Table.ElementalType = PetNestComponentResult.getIntField("ElementalType");
		PetNestComponentData.push_back(Table);
		PetNestComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded PetNestComponent");
#endif

#ifdef CachePhysicsComponent
	auto PhysicsComponentQuery = this->compileStatement("SELECT * FROM PhysicsComponent");
	auto PhysicsComponentResult = PhysicsComponentQuery.execQuery();
	while (!PhysicsComponentResult.eof()) {
		CDClientStructs::PhysicsComponent Table;
		Table.efId = PhysicsComponentResult.getIntField("efId");
		Table.id = PhysicsComponentResult.getIntField("id");
		Table.Static = PhysicsComponentResult.getFloatField("static");
		Table.physics_asset = PhysicsComponentResult.getStringField("physics_asset");
		Table.jump = PhysicsComponentResult.getFloatField("jump");
		Table.doublejump = PhysicsComponentResult.getFloatField("doublejump");
		Table.speed = PhysicsComponentResult.getFloatField("speed");
		Table.rotSpeed = PhysicsComponentResult.getFloatField("rotSpeed");
		Table.playerHeight = PhysicsComponentResult.getFloatField("playerHeight");
		Table.playerRadius = PhysicsComponentResult.getFloatField("playerRadius");
		Table.pcShapeType = PhysicsComponentResult.getIntField("pcShapeType");
		Table.collisionGroup = PhysicsComponentResult.getIntField("collisionGroup");
		Table.airSpeed = PhysicsComponentResult.getFloatField("airSpeed");
		Table.boundaryAsset = PhysicsComponentResult.getStringField("boundaryAsset");
		Table.jumpAirSpeed = PhysicsComponentResult.getFloatField("jumpAirSpeed");
		Table.friction = PhysicsComponentResult.getFloatField("friction");
		Table.gravityVolumeAsset = PhysicsComponentResult.getStringField("gravityVolumeAsset");
		PhysicsComponentData.push_back(Table);
		PhysicsComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded PhysicsComponent");
#endif

#ifdef CachePlayerFlags
	auto PlayerFlagsQuery = this->compileStatement("SELECT * FROM PlayerFlags");
	auto PlayerFlagsResult = PlayerFlagsQuery.execQuery();
	while (!PlayerFlagsResult.eof()) {
		CDClientStructs::PlayerFlags Table;
		Table.efId = PlayerFlagsResult.getIntField("efId");
		Table.id = PlayerFlagsResult.getIntField("id");
		Table.SessionOnly = PlayerFlagsResult.getIntField("SessionOnly");
		Table.OnlySetByServer = PlayerFlagsResult.getIntField("OnlySetByServer");
		Table.SessionZoneOnly = PlayerFlagsResult.getIntField("SessionZoneOnly");
		PlayerFlagsData.push_back(Table);
		PlayerFlagsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded PlayerFlags");
#endif

#ifdef CachePlayerStatistics
	auto PlayerStatisticsQuery = this->compileStatement("SELECT * FROM PlayerStatistics");
	auto PlayerStatisticsResult = PlayerStatisticsQuery.execQuery();
	while (!PlayerStatisticsResult.eof()) {
		CDClientStructs::PlayerStatistics Table;
		Table.efId = PlayerStatisticsResult.getIntField("efId");
		Table.statID = PlayerStatisticsResult.getIntField("statID");
		Table.sortOrder = PlayerStatisticsResult.getInt64Field("sortOrder");
		Table.locStatus = PlayerStatisticsResult.getIntField("locStatus");
		Table.gate_version = PlayerStatisticsResult.getStringField("gate_version");
		PlayerStatisticsData.push_back(Table);
		PlayerStatisticsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded PlayerStatistics");
#endif

#ifdef CachePossessableComponent
	auto PossessableComponentQuery = this->compileStatement("SELECT * FROM PossessableComponent");
	auto PossessableComponentResult = PossessableComponentQuery.execQuery();
	while (!PossessableComponentResult.eof()) {
		CDClientStructs::PossessableComponent Table;
		Table.efId = PossessableComponentResult.getIntField("efId");
		Table.id = PossessableComponentResult.getIntField("id");
		Table.controlSchemeID = PossessableComponentResult.getIntField("controlSchemeID");
		Table.minifigAttachPoint = PossessableComponentResult.getStringField("minifigAttachPoint");
		Table.minifigAttachAnimation = PossessableComponentResult.getStringField("minifigAttachAnimation");
		Table.minifigDetachAnimation = PossessableComponentResult.getStringField("minifigDetachAnimation");
		Table.mountAttachAnimation = PossessableComponentResult.getStringField("mountAttachAnimation");
		Table.mountDetachAnimation = PossessableComponentResult.getStringField("mountDetachAnimation");
		Table.attachOffsetFwd = PossessableComponentResult.getFloatField("attachOffsetFwd");
		Table.attachOffsetRight = PossessableComponentResult.getFloatField("attachOffsetRight");
		Table.possessionType = PossessableComponentResult.getIntField("possessionType");
		Table.wantBillboard = PossessableComponentResult.getIntField("wantBillboard");
		Table.billboardOffsetUp = PossessableComponentResult.getFloatField("billboardOffsetUp");
		Table.depossessOnHit = PossessableComponentResult.getIntField("depossessOnHit");
		Table.hitStunTime = PossessableComponentResult.getFloatField("hitStunTime");
		Table.skillSet = PossessableComponentResult.getInt64Field("skillSet");
		PossessableComponentData.push_back(Table);
		PossessableComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded PossessableComponent");
#endif

#ifdef CachePreconditions
	auto PreconditionsQuery = this->compileStatement("SELECT * FROM Preconditions");
	auto PreconditionsResult = PreconditionsQuery.execQuery();
	while (!PreconditionsResult.eof()) {
		CDClientStructs::Preconditions Table;
		Table.efId = PreconditionsResult.getIntField("efId");
		Table.id = PreconditionsResult.getIntField("id");
		Table.type = PreconditionsResult.getIntField("type");
		Table.targetLOT = PreconditionsResult.getStringField("targetLOT");
		Table.targetGroup = PreconditionsResult.getStringField("targetGroup");
		Table.targetCount = PreconditionsResult.getIntField("targetCount");
		Table.iconID = PreconditionsResult.getIntField("iconID");
		Table.localize = PreconditionsResult.getIntField("localize");
		Table.validContexts = PreconditionsResult.getIntField("validContexts");
		Table.locStatus = PreconditionsResult.getIntField("locStatus");
		Table.gate_version = PreconditionsResult.getStringField("gate_version");
		PreconditionsData.push_back(Table);
		PreconditionsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Preconditions");
#endif

#ifdef CachePropertyEntranceComponent
	auto PropertyEntranceComponentQuery = this->compileStatement("SELECT * FROM PropertyEntranceComponent");
	auto PropertyEntranceComponentResult = PropertyEntranceComponentQuery.execQuery();
	while (!PropertyEntranceComponentResult.eof()) {
		CDClientStructs::PropertyEntranceComponent Table;
		Table.efId = PropertyEntranceComponentResult.getIntField("efId");
		Table.id = PropertyEntranceComponentResult.getIntField("id");
		Table.mapID = PropertyEntranceComponentResult.getIntField("mapID");
		Table.propertyName = PropertyEntranceComponentResult.getStringField("propertyName");
		Table.isOnProperty = PropertyEntranceComponentResult.getIntField("isOnProperty");
		Table.groupType = PropertyEntranceComponentResult.getStringField("groupType");
		PropertyEntranceComponentData.push_back(Table);
		PropertyEntranceComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded PropertyEntranceComponent");
#endif

#ifdef CachePropertyTemplate
	auto PropertyTemplateQuery = this->compileStatement("SELECT * FROM PropertyTemplate");
	auto PropertyTemplateResult = PropertyTemplateQuery.execQuery();
	while (!PropertyTemplateResult.eof()) {
		CDClientStructs::PropertyTemplate Table;
		Table.efId = PropertyTemplateResult.getIntField("efId");
		Table.id = PropertyTemplateResult.getIntField("id");
		Table.mapID = PropertyTemplateResult.getIntField("mapID");
		Table.vendorMapID = PropertyTemplateResult.getIntField("vendorMapID");
		Table.spawnName = PropertyTemplateResult.getStringField("spawnName");
		Table.type = PropertyTemplateResult.getIntField("type");
		Table.sizecode = PropertyTemplateResult.getIntField("sizecode");
		Table.minimumPrice = PropertyTemplateResult.getIntField("minimumPrice");
		Table.rentDuration = PropertyTemplateResult.getIntField("rentDuration");
		Table.path = PropertyTemplateResult.getStringField("path");
		Table.cloneLimit = PropertyTemplateResult.getIntField("cloneLimit");
		Table.durationType = PropertyTemplateResult.getIntField("durationType");
		Table.achievementRequired = PropertyTemplateResult.getIntField("achievementRequired");
		Table.zoneX = PropertyTemplateResult.getFloatField("zoneX");
		Table.zoneY = PropertyTemplateResult.getFloatField("zoneY");
		Table.zoneZ = PropertyTemplateResult.getFloatField("zoneZ");
		Table.maxBuildHeight = PropertyTemplateResult.getFloatField("maxBuildHeight");
		Table.localize = PropertyTemplateResult.getIntField("localize");
		Table.reputationPerMinute = PropertyTemplateResult.getIntField("reputationPerMinute");
		Table.locStatus = PropertyTemplateResult.getIntField("locStatus");
		Table.gate_version = PropertyTemplateResult.getStringField("gate_version");
		PropertyTemplateData.push_back(Table);
		PropertyTemplateResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded PropertyTemplate");
#endif

#ifdef CacheProximityMonitorComponent
	auto ProximityMonitorComponentQuery = this->compileStatement("SELECT * FROM ProximityMonitorComponent");
	auto ProximityMonitorComponentResult = ProximityMonitorComponentQuery.execQuery();
	while (!ProximityMonitorComponentResult.eof()) {
		CDClientStructs::ProximityMonitorComponent Table;
		Table.efId = ProximityMonitorComponentResult.getIntField("efId");
		Table.id = ProximityMonitorComponentResult.getIntField("id");
		Table.Proximities = ProximityMonitorComponentResult.getStringField("Proximities");
		Table.LoadOnClient = ProximityMonitorComponentResult.getIntField("LoadOnClient");
		Table.LoadOnServer = ProximityMonitorComponentResult.getIntField("LoadOnServer");
		ProximityMonitorComponentData.push_back(Table);
		ProximityMonitorComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ProximityMonitorComponent");
#endif

#ifdef CacheProximityTypes
	auto ProximityTypesQuery = this->compileStatement("SELECT * FROM ProximityTypes");
	auto ProximityTypesResult = ProximityTypesQuery.execQuery();
	while (!ProximityTypesResult.eof()) {
		CDClientStructs::ProximityTypes Table;
		Table.efId = ProximityTypesResult.getIntField("efId");
		Table.id = ProximityTypesResult.getIntField("id");
		Table.Name = ProximityTypesResult.getStringField("Name");
		Table.Radius = ProximityTypesResult.getIntField("Radius");
		Table.CollisionGroup = ProximityTypesResult.getIntField("CollisionGroup");
		Table.PassiveChecks = ProximityTypesResult.getIntField("PassiveChecks");
		Table.IconID = ProximityTypesResult.getIntField("IconID");
		Table.LoadOnClient = ProximityTypesResult.getIntField("LoadOnClient");
		Table.LoadOnServer = ProximityTypesResult.getIntField("LoadOnServer");
		ProximityTypesData.push_back(Table);
		ProximityTypesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ProximityTypes");
#endif

#ifdef CacheRacingModuleComponent
	auto RacingModuleComponentQuery = this->compileStatement("SELECT * FROM RacingModuleComponent");
	auto RacingModuleComponentResult = RacingModuleComponentQuery.execQuery();
	while (!RacingModuleComponentResult.eof()) {
		CDClientStructs::RacingModuleComponent Table;
		Table.efId = RacingModuleComponentResult.getIntField("efId");
		Table.id = RacingModuleComponentResult.getIntField("id");
		Table.topSpeed = RacingModuleComponentResult.getFloatField("topSpeed");
		Table.acceleration = RacingModuleComponentResult.getFloatField("acceleration");
		Table.handling = RacingModuleComponentResult.getFloatField("handling");
		Table.stability = RacingModuleComponentResult.getFloatField("stability");
		Table.imagination = RacingModuleComponentResult.getFloatField("imagination");
		RacingModuleComponentData.push_back(Table);
		RacingModuleComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RacingModuleComponent");
#endif

#ifdef CacheRailActivatorComponent
	auto RailActivatorComponentQuery = this->compileStatement("SELECT * FROM RailActivatorComponent");
	auto RailActivatorComponentResult = RailActivatorComponentQuery.execQuery();
	while (!RailActivatorComponentResult.eof()) {
		CDClientStructs::RailActivatorComponent Table;
		Table.efId = RailActivatorComponentResult.getIntField("efId");
		Table.id = RailActivatorComponentResult.getIntField("id");
		Table.startAnim = RailActivatorComponentResult.getStringField("startAnim");
		Table.loopAnim = RailActivatorComponentResult.getStringField("loopAnim");
		Table.stopAnim = RailActivatorComponentResult.getStringField("stopAnim");
		Table.startSound = RailActivatorComponentResult.getStringField("startSound");
		Table.loopSound = RailActivatorComponentResult.getStringField("loopSound");
		Table.stopSound = RailActivatorComponentResult.getStringField("stopSound");
		Table.effectIDs = RailActivatorComponentResult.getStringField("effectIDs");
		Table.preconditions = RailActivatorComponentResult.getStringField("preconditions");
		Table.playerCollision = RailActivatorComponentResult.getIntField("playerCollision");
		Table.cameraLocked = RailActivatorComponentResult.getIntField("cameraLocked");
		Table.StartEffectID = RailActivatorComponentResult.getStringField("StartEffectID");
		Table.StopEffectID = RailActivatorComponentResult.getStringField("StopEffectID");
		Table.DamageImmune = RailActivatorComponentResult.getIntField("DamageImmune");
		Table.NoAggro = RailActivatorComponentResult.getIntField("NoAggro");
		Table.ShowNameBillboard = RailActivatorComponentResult.getIntField("ShowNameBillboard");
		RailActivatorComponentData.push_back(Table);
		RailActivatorComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RailActivatorComponent");
#endif

#ifdef CacheRarityTable
	auto RarityTableQuery = this->compileStatement("SELECT * FROM RarityTable");
	auto RarityTableResult = RarityTableQuery.execQuery();
	while (!RarityTableResult.eof()) {
		CDClientStructs::RarityTable Table;
		Table.efId = RarityTableResult.getIntField("efId");
		Table.id = RarityTableResult.getIntField("id");
		Table.randmax = RarityTableResult.getFloatField("randmax");
		Table.rarity = RarityTableResult.getIntField("rarity");
		Table.RarityTableIndex = RarityTableResult.getIntField("RarityTableIndex");
		RarityTableData.push_back(Table);
		RarityTableResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RarityTable");
#endif

#ifdef CacheRarityTableIndex
	auto RarityTableIndexQuery = this->compileStatement("SELECT * FROM RarityTableIndex");
	auto RarityTableIndexResult = RarityTableIndexQuery.execQuery();
	while (!RarityTableIndexResult.eof()) {
		CDClientStructs::RarityTableIndex Table;
		Table.efId = RarityTableIndexResult.getIntField("efId");
		Table.RarityTableIndex = RarityTableIndexResult.getIntField("RarityTableIndex");
		RarityTableIndexData.push_back(Table);
		RarityTableIndexResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RarityTableIndex");
#endif

#ifdef CacheRebuildComponent
	auto RebuildComponentQuery = this->compileStatement("SELECT * FROM RebuildComponent");
	auto RebuildComponentResult = RebuildComponentQuery.execQuery();
	while (!RebuildComponentResult.eof()) {
		CDClientStructs::RebuildComponent Table;
		Table.efId = RebuildComponentResult.getIntField("efId");
		Table.id = RebuildComponentResult.getIntField("id");
		Table.reset_time = RebuildComponentResult.getFloatField("reset_time");
		Table.complete_time = RebuildComponentResult.getFloatField("complete_time");
		Table.take_imagination = RebuildComponentResult.getIntField("take_imagination");
		Table.interruptible = RebuildComponentResult.getIntField("interruptible");
		Table.self_activator = RebuildComponentResult.getIntField("self_activator");
		Table.custom_modules = RebuildComponentResult.getStringField("custom_modules");
		Table.activityID = RebuildComponentResult.getIntField("activityID");
		Table.post_imagination_cost = RebuildComponentResult.getIntField("post_imagination_cost");
		Table.time_before_smash = RebuildComponentResult.getFloatField("time_before_smash");
		RebuildComponentData.push_back(Table);
		RebuildComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RebuildComponent");
#endif

#ifdef CacheRebuildSections
	auto RebuildSectionsQuery = this->compileStatement("SELECT * FROM RebuildSections");
	auto RebuildSectionsResult = RebuildSectionsQuery.execQuery();
	while (!RebuildSectionsResult.eof()) {
		CDClientStructs::RebuildSections Table;
		Table.efId = RebuildSectionsResult.getIntField("efId");
		Table.id = RebuildSectionsResult.getIntField("id");
		Table.rebuildID = RebuildSectionsResult.getIntField("rebuildID");
		Table.objectID = RebuildSectionsResult.getIntField("objectID");
		Table.offset_x = RebuildSectionsResult.getFloatField("offset_x");
		Table.offset_y = RebuildSectionsResult.getFloatField("offset_y");
		Table.offset_z = RebuildSectionsResult.getFloatField("offset_z");
		Table.fall_angle_x = RebuildSectionsResult.getFloatField("fall_angle_x");
		Table.fall_angle_y = RebuildSectionsResult.getFloatField("fall_angle_y");
		Table.fall_angle_z = RebuildSectionsResult.getFloatField("fall_angle_z");
		Table.fall_height = RebuildSectionsResult.getFloatField("fall_height");
		Table.requires_list = RebuildSectionsResult.getStringField("requires_list");
		Table.size = RebuildSectionsResult.getIntField("size");
		Table.bPlaced = RebuildSectionsResult.getIntField("bPlaced");
		RebuildSectionsData.push_back(Table);
		RebuildSectionsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RebuildSections");
#endif

#ifdef CacheRelease_Version
	auto Release_VersionQuery = this->compileStatement("SELECT * FROM Release_Version");
	auto Release_VersionResult = Release_VersionQuery.execQuery();
	while (!Release_VersionResult.eof()) {
		CDClientStructs::Release_Version Table;
		Table.efId = Release_VersionResult.getIntField("efId");
		Table.ReleaseVersion = Release_VersionResult.getStringField("ReleaseVersion");
		Table.ReleaseDate = Release_VersionResult.getIntField("ReleaseDate");
		Release_VersionData.push_back(Table);
		Release_VersionResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Release_Version");
#endif

#ifdef CacheRenderComponent
	auto RenderComponentQuery = this->compileStatement("SELECT * FROM RenderComponent");
	auto RenderComponentResult = RenderComponentQuery.execQuery();
	while (!RenderComponentResult.eof()) {
		CDClientStructs::RenderComponent Table;
		Table.efId = RenderComponentResult.getIntField("efId");
		Table.id = RenderComponentResult.getIntField("id");
		Table.render_asset = RenderComponentResult.getStringField("render_asset");
		Table.icon_asset = RenderComponentResult.getStringField("icon_asset");
		Table.IconID = RenderComponentResult.getIntField("IconID");
		Table.shader_id = RenderComponentResult.getIntField("shader_id");
		Table.effect1 = RenderComponentResult.getIntField("effect1");
		Table.effect2 = RenderComponentResult.getIntField("effect2");
		Table.effect3 = RenderComponentResult.getIntField("effect3");
		Table.effect4 = RenderComponentResult.getIntField("effect4");
		Table.effect5 = RenderComponentResult.getIntField("effect5");
		Table.effect6 = RenderComponentResult.getIntField("effect6");
		Table.animationGroupIDs = RenderComponentResult.getStringField("animationGroupIDs");
		Table.fade = RenderComponentResult.getIntField("fade");
		Table.usedropshadow = RenderComponentResult.getIntField("usedropshadow");
		Table.preloadAnimations = RenderComponentResult.getIntField("preloadAnimations");
		Table.fadeInTime = RenderComponentResult.getFloatField("fadeInTime");
		Table.maxShadowDistance = RenderComponentResult.getFloatField("maxShadowDistance");
		Table.ignoreCameraCollision = RenderComponentResult.getIntField("ignoreCameraCollision");
		Table.renderComponentLOD1 = RenderComponentResult.getIntField("renderComponentLOD1");
		Table.renderComponentLOD2 = RenderComponentResult.getIntField("renderComponentLOD2");
		Table.gradualSnap = RenderComponentResult.getIntField("gradualSnap");
		Table.animationFlag = RenderComponentResult.getIntField("animationFlag");
		Table.AudioMetaEventSet = RenderComponentResult.getStringField("AudioMetaEventSet");
		Table.billboardHeight = RenderComponentResult.getFloatField("billboardHeight");
		Table.chatBubbleOffset = RenderComponentResult.getFloatField("chatBubbleOffset");
		Table.staticBillboard = RenderComponentResult.getIntField("staticBillboard");
		Table.LXFMLFolder = RenderComponentResult.getStringField("LXFMLFolder");
		Table.attachIndicatorsToNode = RenderComponentResult.getIntField("attachIndicatorsToNode");
		RenderComponentData.push_back(Table);
		RenderComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RenderComponent");
#endif

#ifdef CacheRenderComponentFlash
	auto RenderComponentFlashQuery = this->compileStatement("SELECT * FROM RenderComponentFlash");
	auto RenderComponentFlashResult = RenderComponentFlashQuery.execQuery();
	while (!RenderComponentFlashResult.eof()) {
		CDClientStructs::RenderComponentFlash Table;
		Table.efId = RenderComponentFlashResult.getIntField("efId");
		Table.id = RenderComponentFlashResult.getIntField("id");
		Table.interactive = RenderComponentFlashResult.getIntField("interactive");
		Table.animated = RenderComponentFlashResult.getIntField("animated");
		Table.nodeName = RenderComponentFlashResult.getStringField("nodeName");
		Table.flashPath = RenderComponentFlashResult.getStringField("flashPath");
		Table.elementName = RenderComponentFlashResult.getStringField("elementName");
		Table._uid = RenderComponentFlashResult.getIntField("_uid");
		RenderComponentFlashData.push_back(Table);
		RenderComponentFlashResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RenderComponentFlash");
#endif

#ifdef CacheRenderComponentWrapper
	auto RenderComponentWrapperQuery = this->compileStatement("SELECT * FROM RenderComponentWrapper");
	auto RenderComponentWrapperResult = RenderComponentWrapperQuery.execQuery();
	while (!RenderComponentWrapperResult.eof()) {
		CDClientStructs::RenderComponentWrapper Table;
		Table.efId = RenderComponentWrapperResult.getIntField("efId");
		Table.id = RenderComponentWrapperResult.getIntField("id");
		Table.defaultWrapperAsset = RenderComponentWrapperResult.getStringField("defaultWrapperAsset");
		RenderComponentWrapperData.push_back(Table);
		RenderComponentWrapperResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RenderComponentWrapper");
#endif

#ifdef CacheRenderIconAssets
	auto RenderIconAssetsQuery = this->compileStatement("SELECT * FROM RenderIconAssets");
	auto RenderIconAssetsResult = RenderIconAssetsQuery.execQuery();
	while (!RenderIconAssetsResult.eof()) {
		CDClientStructs::RenderIconAssets Table;
		Table.efId = RenderIconAssetsResult.getIntField("efId");
		Table.id = RenderIconAssetsResult.getIntField("id");
		Table.icon_asset = RenderIconAssetsResult.getStringField("icon_asset");
		Table.blank_column = RenderIconAssetsResult.getStringField("blank_column");
		RenderIconAssetsData.push_back(Table);
		RenderIconAssetsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RenderIconAssets");
#endif

#ifdef CacheRewardCodes
	auto RewardCodesQuery = this->compileStatement("SELECT * FROM RewardCodes");
	auto RewardCodesResult = RewardCodesQuery.execQuery();
	while (!RewardCodesResult.eof()) {
		CDClientStructs::RewardCodes Table;
		Table.efId = RewardCodesResult.getIntField("efId");
		Table.id = RewardCodesResult.getIntField("id");
		Table.code = RewardCodesResult.getStringField("code");
		Table.attachmentLOT = RewardCodesResult.getIntField("attachmentLOT");
		Table.locStatus = RewardCodesResult.getIntField("locStatus");
		Table.gate_version = RewardCodesResult.getStringField("gate_version");
		RewardCodesData.push_back(Table);
		RewardCodesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RewardCodes");
#endif

#ifdef CacheRewards
	auto RewardsQuery = this->compileStatement("SELECT * FROM Rewards");
	auto RewardsResult = RewardsQuery.execQuery();
	while (!RewardsResult.eof()) {
		CDClientStructs::Rewards Table;
		Table.efId = RewardsResult.getIntField("efId");
		Table.id = RewardsResult.getIntField("id");
		Table.LevelID = RewardsResult.getIntField("LevelID");
		Table.MissionID = RewardsResult.getInt64Field("MissionID");
		Table.RewardType = RewardsResult.getIntField("RewardType");
		Table.value = RewardsResult.getIntField("value");
		Table.count = RewardsResult.getIntField("count");
		RewardsData.push_back(Table);
		RewardsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded Rewards");
#endif

#ifdef CacheRocketLaunchpadControlComponent
	auto RocketLaunchpadControlComponentQuery = this->compileStatement("SELECT * FROM RocketLaunchpadControlComponent");
	auto RocketLaunchpadControlComponentResult = RocketLaunchpadControlComponentQuery.execQuery();
	while (!RocketLaunchpadControlComponentResult.eof()) {
		CDClientStructs::RocketLaunchpadControlComponent Table;
		Table.efId = RocketLaunchpadControlComponentResult.getIntField("efId");
		Table.id = RocketLaunchpadControlComponentResult.getIntField("id");
		Table.targetZone = RocketLaunchpadControlComponentResult.getIntField("targetZone");
		Table.defaultZoneID = RocketLaunchpadControlComponentResult.getIntField("defaultZoneID");
		Table.targetScene = RocketLaunchpadControlComponentResult.getStringField("targetScene");
		Table.gmLevel = RocketLaunchpadControlComponentResult.getIntField("gmLevel");
		Table.playerAnimation = RocketLaunchpadControlComponentResult.getStringField("playerAnimation");
		Table.rocketAnimation = RocketLaunchpadControlComponentResult.getStringField("rocketAnimation");
		Table.launchMusic = RocketLaunchpadControlComponentResult.getStringField("launchMusic");
		Table.useLaunchPrecondition = RocketLaunchpadControlComponentResult.getIntField("useLaunchPrecondition");
		Table.useAltLandingPrecondition = RocketLaunchpadControlComponentResult.getIntField("useAltLandingPrecondition");
		Table.launchPrecondition = RocketLaunchpadControlComponentResult.getStringField("launchPrecondition");
		Table.altLandingPrecondition = RocketLaunchpadControlComponentResult.getStringField("altLandingPrecondition");
		Table.altLandingSpawnPointName = RocketLaunchpadControlComponentResult.getStringField("altLandingSpawnPointName");
		RocketLaunchpadControlComponentData.push_back(Table);
		RocketLaunchpadControlComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded RocketLaunchpadControlComponent");
#endif

#ifdef CacheSceneTable
	auto SceneTableQuery = this->compileStatement("SELECT * FROM SceneTable");
	auto SceneTableResult = SceneTableQuery.execQuery();
	while (!SceneTableResult.eof()) {
		CDClientStructs::SceneTable Table;
		Table.efId = SceneTableResult.getIntField("efId");
		Table.sceneID = SceneTableResult.getIntField("sceneID");
		Table.sceneName = SceneTableResult.getStringField("sceneName");
		SceneTableData.push_back(Table);
		SceneTableResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded SceneTable");
#endif

#ifdef CacheScriptComponent
	auto ScriptComponentQuery = this->compileStatement("SELECT * FROM ScriptComponent");
	auto ScriptComponentResult = ScriptComponentQuery.execQuery();
	while (!ScriptComponentResult.eof()) {
		CDClientStructs::ScriptComponent Table;
		Table.efId = ScriptComponentResult.getIntField("efId");
		Table.id = ScriptComponentResult.getIntField("id");
		Table.script_name = ScriptComponentResult.getStringField("script_name");
		Table.client_script_name = ScriptComponentResult.getStringField("client_script_name");
		ScriptComponentData.push_back(Table);
		ScriptComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ScriptComponent");
#endif

#ifdef CacheSkillBehavior
	auto SkillBehaviorQuery = this->compileStatement("SELECT * FROM SkillBehavior");
	auto SkillBehaviorResult = SkillBehaviorQuery.execQuery();
	while (!SkillBehaviorResult.eof()) {
		CDClientStructs::SkillBehavior Table;
		Table.efId = SkillBehaviorResult.getIntField("efId");
		Table.skillID = SkillBehaviorResult.getIntField("skillID");
		Table.locStatus = SkillBehaviorResult.getIntField("locStatus");
		Table.behaviorID = SkillBehaviorResult.getIntField("behaviorID");
		Table.imaginationcost = SkillBehaviorResult.getIntField("imaginationcost");
		Table.cooldowngroup = SkillBehaviorResult.getIntField("cooldowngroup");
		Table.cooldown = SkillBehaviorResult.getFloatField("cooldown");
		Table.inNpcEditor = SkillBehaviorResult.getIntField("inNpcEditor");
		Table.skillIcon = SkillBehaviorResult.getIntField("skillIcon");
		Table.oomSkillID = SkillBehaviorResult.getStringField("oomSkillID");
		Table.oomBehaviorEffectID = SkillBehaviorResult.getIntField("oomBehaviorEffectID");
		Table.castTypeDesc = SkillBehaviorResult.getIntField("castTypeDesc");
		Table.imBonusUI = SkillBehaviorResult.getIntField("imBonusUI");
		Table.lifeBonusUI = SkillBehaviorResult.getIntField("lifeBonusUI");
		Table.armorBonusUI = SkillBehaviorResult.getIntField("armorBonusUI");
		Table.damageUI = SkillBehaviorResult.getIntField("damageUI");
		Table.hideIcon = SkillBehaviorResult.getIntField("hideIcon");
		Table.localize = SkillBehaviorResult.getIntField("localize");
		Table.gate_version = SkillBehaviorResult.getStringField("gate_version");
		Table.cancelType = SkillBehaviorResult.getIntField("cancelType");
		SkillBehaviorData.push_back(Table);
		SkillBehaviorResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded SkillBehavior");
#endif

#ifdef CacheSmashableChain
	auto SmashableChainQuery = this->compileStatement("SELECT * FROM SmashableChain");
	auto SmashableChainResult = SmashableChainQuery.execQuery();
	while (!SmashableChainResult.eof()) {
		CDClientStructs::SmashableChain Table;
		Table.efId = SmashableChainResult.getIntField("efId");
		Table.chainIndex = SmashableChainResult.getIntField("chainIndex");
		Table.chainLevel = SmashableChainResult.getIntField("chainLevel");
		Table.lootMatrixID = SmashableChainResult.getIntField("lootMatrixID");
		Table.rarityTableIndex = SmashableChainResult.getIntField("rarityTableIndex");
		Table.currencyIndex = SmashableChainResult.getIntField("currencyIndex");
		Table.currencyLevel = SmashableChainResult.getIntField("currencyLevel");
		Table.smashCount = SmashableChainResult.getIntField("smashCount");
		Table.timeLimit = SmashableChainResult.getIntField("timeLimit");
		Table.chainStepID = SmashableChainResult.getIntField("chainStepID");
		SmashableChainData.push_back(Table);
		SmashableChainResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded SmashableChain");
#endif

#ifdef CacheSmashableChainIndex
	auto SmashableChainIndexQuery = this->compileStatement("SELECT * FROM SmashableChainIndex");
	auto SmashableChainIndexResult = SmashableChainIndexQuery.execQuery();
	while (!SmashableChainIndexResult.eof()) {
		CDClientStructs::SmashableChainIndex Table;
		Table.efId = SmashableChainIndexResult.getIntField("efId");
		Table.id = SmashableChainIndexResult.getIntField("id");
		Table.targetGroup = SmashableChainIndexResult.getStringField("targetGroup");
		Table.description = SmashableChainIndexResult.getStringField("description");
		Table.continuous = SmashableChainIndexResult.getIntField("continuous");
		SmashableChainIndexData.push_back(Table);
		SmashableChainIndexResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded SmashableChainIndex");
#endif

#ifdef CacheSmashableComponent
	auto SmashableComponentQuery = this->compileStatement("SELECT * FROM SmashableComponent");
	auto SmashableComponentResult = SmashableComponentQuery.execQuery();
	while (!SmashableComponentResult.eof()) {
		CDClientStructs::SmashableComponent Table;
		Table.efId = SmashableComponentResult.getIntField("efId");
		Table.id = SmashableComponentResult.getIntField("id");
		Table.LootMatrixIndex = SmashableComponentResult.getIntField("LootMatrixIndex");
		SmashableComponentData.push_back(Table);
		SmashableComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded SmashableComponent");
#endif

#ifdef CacheSmashableElements
	auto SmashableElementsQuery = this->compileStatement("SELECT * FROM SmashableElements");
	auto SmashableElementsResult = SmashableElementsQuery.execQuery();
	while (!SmashableElementsResult.eof()) {
		CDClientStructs::SmashableElements Table;
		Table.efId = SmashableElementsResult.getIntField("efId");
		Table.elementID = SmashableElementsResult.getIntField("elementID");
		Table.dropWeight = SmashableElementsResult.getIntField("dropWeight");
		SmashableElementsData.push_back(Table);
		SmashableElementsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded SmashableElements");
#endif

#ifdef CacheSpeedchatMenu
	auto SpeedchatMenuQuery = this->compileStatement("SELECT * FROM SpeedchatMenu");
	auto SpeedchatMenuResult = SpeedchatMenuQuery.execQuery();
	while (!SpeedchatMenuResult.eof()) {
		CDClientStructs::SpeedchatMenu Table;
		Table.efId = SpeedchatMenuResult.getIntField("efId");
		Table.id = SpeedchatMenuResult.getIntField("id");
		Table.parentId = SpeedchatMenuResult.getIntField("parentId");
		Table.emoteId = SpeedchatMenuResult.getIntField("emoteId");
		Table.imageName = SpeedchatMenuResult.getStringField("imageName");
		Table.localize = SpeedchatMenuResult.getIntField("localize");
		Table.locStatus = SpeedchatMenuResult.getIntField("locStatus");
		Table.gate_version = SpeedchatMenuResult.getStringField("gate_version");
		SpeedchatMenuData.push_back(Table);
		SpeedchatMenuResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded SpeedchatMenu");
#endif

#ifdef CacheSubscriptionPricing
	auto SubscriptionPricingQuery = this->compileStatement("SELECT * FROM SubscriptionPricing");
	auto SubscriptionPricingResult = SubscriptionPricingQuery.execQuery();
	while (!SubscriptionPricingResult.eof()) {
		CDClientStructs::SubscriptionPricing Table;
		Table.efId = SubscriptionPricingResult.getIntField("efId");
		Table.id = SubscriptionPricingResult.getIntField("id");
		Table.countryCode = SubscriptionPricingResult.getStringField("countryCode");
		Table.monthlyFeeGold = SubscriptionPricingResult.getStringField("monthlyFeeGold");
		Table.monthlyFeeSilver = SubscriptionPricingResult.getStringField("monthlyFeeSilver");
		Table.monthlyFeeBronze = SubscriptionPricingResult.getStringField("monthlyFeeBronze");
		Table.monetarySymbol = SubscriptionPricingResult.getIntField("monetarySymbol");
		Table.symbolIsAppended = SubscriptionPricingResult.getIntField("symbolIsAppended");
		SubscriptionPricingData.push_back(Table);
		SubscriptionPricingResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded SubscriptionPricing");
#endif

#ifdef CacheTamingBuildPuzzles
	auto TamingBuildPuzzlesQuery = this->compileStatement("SELECT * FROM TamingBuildPuzzles");
	auto TamingBuildPuzzlesResult = TamingBuildPuzzlesQuery.execQuery();
	while (!TamingBuildPuzzlesResult.eof()) {
		CDClientStructs::TamingBuildPuzzles Table;
		Table.efId = TamingBuildPuzzlesResult.getIntField("efId");
		Table.id = TamingBuildPuzzlesResult.getIntField("id");
		Table.PuzzleModelLot = TamingBuildPuzzlesResult.getIntField("PuzzleModelLot");
		Table.NPCLot = TamingBuildPuzzlesResult.getIntField("NPCLot");
		Table.ValidPiecesLXF = TamingBuildPuzzlesResult.getStringField("ValidPiecesLXF");
		Table.InvalidPiecesLXF = TamingBuildPuzzlesResult.getStringField("InvalidPiecesLXF");
		Table.Difficulty = TamingBuildPuzzlesResult.getIntField("Difficulty");
		Table.Timelimit = TamingBuildPuzzlesResult.getIntField("Timelimit");
		Table.NumValidPieces = TamingBuildPuzzlesResult.getIntField("NumValidPieces");
		Table.TotalNumPieces = TamingBuildPuzzlesResult.getIntField("TotalNumPieces");
		Table.ModelName = TamingBuildPuzzlesResult.getStringField("ModelName");
		Table.FullModelLXF = TamingBuildPuzzlesResult.getStringField("FullModelLXF");
		Table.Duration = TamingBuildPuzzlesResult.getFloatField("Duration");
		Table.imagCostPerBuild = TamingBuildPuzzlesResult.getIntField("imagCostPerBuild");
		TamingBuildPuzzlesData.push_back(Table);
		TamingBuildPuzzlesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded TamingBuildPuzzles");
#endif

#ifdef CacheTrailEffects
	auto TrailEffectsQuery = this->compileStatement("SELECT * FROM TrailEffects");
	auto TrailEffectsResult = TrailEffectsQuery.execQuery();
	while (!TrailEffectsResult.eof()) {
		CDClientStructs::TrailEffects Table;
		Table.efId = TrailEffectsResult.getIntField("efId");
		Table.trailID = TrailEffectsResult.getIntField("trailID");
		Table.textureName = TrailEffectsResult.getStringField("textureName");
		Table.blendmode = TrailEffectsResult.getIntField("blendmode");
		Table.cardlifetime = TrailEffectsResult.getFloatField("cardlifetime");
		Table.colorlifetime = TrailEffectsResult.getFloatField("colorlifetime");
		Table.minTailFade = TrailEffectsResult.getFloatField("minTailFade");
		Table.tailFade = TrailEffectsResult.getFloatField("tailFade");
		Table.max_particles = TrailEffectsResult.getIntField("max_particles");
		Table.birthDelay = TrailEffectsResult.getFloatField("birthDelay");
		Table.deathDelay = TrailEffectsResult.getFloatField("deathDelay");
		Table.bone1 = TrailEffectsResult.getStringField("bone1");
		Table.bone2 = TrailEffectsResult.getStringField("bone2");
		Table.texLength = TrailEffectsResult.getFloatField("texLength");
		Table.texWidth = TrailEffectsResult.getFloatField("texWidth");
		Table.startColorR = TrailEffectsResult.getFloatField("startColorR");
		Table.startColorG = TrailEffectsResult.getFloatField("startColorG");
		Table.startColorB = TrailEffectsResult.getFloatField("startColorB");
		Table.startColorA = TrailEffectsResult.getFloatField("startColorA");
		Table.middleColorR = TrailEffectsResult.getFloatField("middleColorR");
		Table.middleColorG = TrailEffectsResult.getFloatField("middleColorG");
		Table.middleColorB = TrailEffectsResult.getFloatField("middleColorB");
		Table.middleColorA = TrailEffectsResult.getFloatField("middleColorA");
		Table.endColorR = TrailEffectsResult.getFloatField("endColorR");
		Table.endColorG = TrailEffectsResult.getFloatField("endColorG");
		Table.endColorB = TrailEffectsResult.getFloatField("endColorB");
		Table.endColorA = TrailEffectsResult.getFloatField("endColorA");
		TrailEffectsData.push_back(Table);
		TrailEffectsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded TrailEffects");
#endif

#ifdef CacheUGBehaviorSounds
	auto UGBehaviorSoundsQuery = this->compileStatement("SELECT * FROM UGBehaviorSounds");
	auto UGBehaviorSoundsResult = UGBehaviorSoundsQuery.execQuery();
	while (!UGBehaviorSoundsResult.eof()) {
		CDClientStructs::UGBehaviorSounds Table;
		Table.efId = UGBehaviorSoundsResult.getIntField("efId");
		Table.id = UGBehaviorSoundsResult.getIntField("id");
		Table.guid = UGBehaviorSoundsResult.getStringField("guid");
		Table.localize = UGBehaviorSoundsResult.getIntField("localize");
		Table.locStatus = UGBehaviorSoundsResult.getIntField("locStatus");
		Table.gate_version = UGBehaviorSoundsResult.getStringField("gate_version");
		UGBehaviorSoundsData.push_back(Table);
		UGBehaviorSoundsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded UGBehaviorSounds");
#endif

#ifdef CacheVehiclePhysics
	auto VehiclePhysicsQuery = this->compileStatement("SELECT * FROM VehiclePhysics");
	auto VehiclePhysicsResult = VehiclePhysicsQuery.execQuery();
	while (!VehiclePhysicsResult.eof()) {
		CDClientStructs::VehiclePhysics Table;
		Table.efId = VehiclePhysicsResult.getIntField("efId");
		Table.id = VehiclePhysicsResult.getIntField("id");
		Table.hkxFilename = VehiclePhysicsResult.getStringField("hkxFilename");
		Table.fGravityScale = VehiclePhysicsResult.getFloatField("fGravityScale");
		Table.fMass = VehiclePhysicsResult.getFloatField("fMass");
		Table.fChassisFriction = VehiclePhysicsResult.getFloatField("fChassisFriction");
		Table.fMaxSpeed = VehiclePhysicsResult.getFloatField("fMaxSpeed");
		Table.fEngineTorque = VehiclePhysicsResult.getFloatField("fEngineTorque");
		Table.fBrakeFrontTorque = VehiclePhysicsResult.getFloatField("fBrakeFrontTorque");
		Table.fBrakeRearTorque = VehiclePhysicsResult.getFloatField("fBrakeRearTorque");
		Table.fBrakeMinInputToBlock = VehiclePhysicsResult.getFloatField("fBrakeMinInputToBlock");
		Table.fBrakeMinTimeToBlock = VehiclePhysicsResult.getFloatField("fBrakeMinTimeToBlock");
		Table.fSteeringMaxAngle = VehiclePhysicsResult.getFloatField("fSteeringMaxAngle");
		Table.fSteeringSpeedLimitForMaxAngle = VehiclePhysicsResult.getFloatField("fSteeringSpeedLimitForMaxAngle");
		Table.fSteeringMinAngle = VehiclePhysicsResult.getFloatField("fSteeringMinAngle");
		Table.fFwdBias = VehiclePhysicsResult.getFloatField("fFwdBias");
		Table.fFrontTireFriction = VehiclePhysicsResult.getFloatField("fFrontTireFriction");
		Table.fRearTireFriction = VehiclePhysicsResult.getFloatField("fRearTireFriction");
		Table.fFrontTireFrictionSlide = VehiclePhysicsResult.getFloatField("fFrontTireFrictionSlide");
		Table.fRearTireFrictionSlide = VehiclePhysicsResult.getFloatField("fRearTireFrictionSlide");
		Table.fFrontTireSlipAngle = VehiclePhysicsResult.getFloatField("fFrontTireSlipAngle");
		Table.fRearTireSlipAngle = VehiclePhysicsResult.getFloatField("fRearTireSlipAngle");
		Table.fWheelWidth = VehiclePhysicsResult.getFloatField("fWheelWidth");
		Table.fWheelRadius = VehiclePhysicsResult.getFloatField("fWheelRadius");
		Table.fWheelMass = VehiclePhysicsResult.getFloatField("fWheelMass");
		Table.fReorientPitchStrength = VehiclePhysicsResult.getFloatField("fReorientPitchStrength");
		Table.fReorientRollStrength = VehiclePhysicsResult.getFloatField("fReorientRollStrength");
		Table.fSuspensionLength = VehiclePhysicsResult.getFloatField("fSuspensionLength");
		Table.fSuspensionStrength = VehiclePhysicsResult.getFloatField("fSuspensionStrength");
		Table.fSuspensionDampingCompression = VehiclePhysicsResult.getFloatField("fSuspensionDampingCompression");
		Table.fSuspensionDampingRelaxation = VehiclePhysicsResult.getFloatField("fSuspensionDampingRelaxation");
		Table.iChassisCollisionGroup = VehiclePhysicsResult.getIntField("iChassisCollisionGroup");
		Table.fNormalSpinDamping = VehiclePhysicsResult.getFloatField("fNormalSpinDamping");
		Table.fCollisionSpinDamping = VehiclePhysicsResult.getFloatField("fCollisionSpinDamping");
		Table.fCollisionThreshold = VehiclePhysicsResult.getFloatField("fCollisionThreshold");
		Table.fTorqueRollFactor = VehiclePhysicsResult.getFloatField("fTorqueRollFactor");
		Table.fTorquePitchFactor = VehiclePhysicsResult.getFloatField("fTorquePitchFactor");
		Table.fTorqueYawFactor = VehiclePhysicsResult.getFloatField("fTorqueYawFactor");
		Table.fInertiaRoll = VehiclePhysicsResult.getFloatField("fInertiaRoll");
		Table.fInertiaPitch = VehiclePhysicsResult.getFloatField("fInertiaPitch");
		Table.fInertiaYaw = VehiclePhysicsResult.getFloatField("fInertiaYaw");
		Table.fExtraTorqueFactor = VehiclePhysicsResult.getFloatField("fExtraTorqueFactor");
		Table.fCenterOfMassFwd = VehiclePhysicsResult.getFloatField("fCenterOfMassFwd");
		Table.fCenterOfMassUp = VehiclePhysicsResult.getFloatField("fCenterOfMassUp");
		Table.fCenterOfMassRight = VehiclePhysicsResult.getFloatField("fCenterOfMassRight");
		Table.fWheelHardpointFrontFwd = VehiclePhysicsResult.getFloatField("fWheelHardpointFrontFwd");
		Table.fWheelHardpointFrontUp = VehiclePhysicsResult.getFloatField("fWheelHardpointFrontUp");
		Table.fWheelHardpointFrontRight = VehiclePhysicsResult.getFloatField("fWheelHardpointFrontRight");
		Table.fWheelHardpointRearFwd = VehiclePhysicsResult.getFloatField("fWheelHardpointRearFwd");
		Table.fWheelHardpointRearUp = VehiclePhysicsResult.getFloatField("fWheelHardpointRearUp");
		Table.fWheelHardpointRearRight = VehiclePhysicsResult.getFloatField("fWheelHardpointRearRight");
		Table.fInputTurnSpeed = VehiclePhysicsResult.getFloatField("fInputTurnSpeed");
		Table.fInputDeadTurnBackSpeed = VehiclePhysicsResult.getFloatField("fInputDeadTurnBackSpeed");
		Table.fInputAccelSpeed = VehiclePhysicsResult.getFloatField("fInputAccelSpeed");
		Table.fInputDeadAccelDownSpeed = VehiclePhysicsResult.getFloatField("fInputDeadAccelDownSpeed");
		Table.fInputDecelSpeed = VehiclePhysicsResult.getFloatField("fInputDecelSpeed");
		Table.fInputDeadDecelDownSpeed = VehiclePhysicsResult.getFloatField("fInputDeadDecelDownSpeed");
		Table.fInputSlopeChangePointX = VehiclePhysicsResult.getFloatField("fInputSlopeChangePointX");
		Table.fInputInitialSlope = VehiclePhysicsResult.getFloatField("fInputInitialSlope");
		Table.fInputDeadZone = VehiclePhysicsResult.getFloatField("fInputDeadZone");
		Table.fAeroAirDensity = VehiclePhysicsResult.getFloatField("fAeroAirDensity");
		Table.fAeroFrontalArea = VehiclePhysicsResult.getFloatField("fAeroFrontalArea");
		Table.fAeroDragCoefficient = VehiclePhysicsResult.getFloatField("fAeroDragCoefficient");
		Table.fAeroLiftCoefficient = VehiclePhysicsResult.getFloatField("fAeroLiftCoefficient");
		Table.fAeroExtraGravity = VehiclePhysicsResult.getFloatField("fAeroExtraGravity");
		Table.fBoostTopSpeed = VehiclePhysicsResult.getFloatField("fBoostTopSpeed");
		Table.fBoostCostPerSecond = VehiclePhysicsResult.getFloatField("fBoostCostPerSecond");
		Table.fBoostAccelerateChange = VehiclePhysicsResult.getFloatField("fBoostAccelerateChange");
		Table.fBoostDampingChange = VehiclePhysicsResult.getFloatField("fBoostDampingChange");
		Table.fPowerslideNeutralAngle = VehiclePhysicsResult.getFloatField("fPowerslideNeutralAngle");
		Table.fPowerslideTorqueStrength = VehiclePhysicsResult.getFloatField("fPowerslideTorqueStrength");
		Table.iPowerslideNumTorqueApplications = VehiclePhysicsResult.getIntField("iPowerslideNumTorqueApplications");
		Table.fImaginationTankSize = VehiclePhysicsResult.getFloatField("fImaginationTankSize");
		Table.fSkillCost = VehiclePhysicsResult.getFloatField("fSkillCost");
		Table.fWreckSpeedBase = VehiclePhysicsResult.getFloatField("fWreckSpeedBase");
		Table.fWreckSpeedPercent = VehiclePhysicsResult.getFloatField("fWreckSpeedPercent");
		Table.fWreckMinAngle = VehiclePhysicsResult.getFloatField("fWreckMinAngle");
		Table.AudioEventEngine = VehiclePhysicsResult.getStringField("AudioEventEngine");
		Table.AudioEventSkid = VehiclePhysicsResult.getStringField("AudioEventSkid");
		Table.AudioEventLightHit = VehiclePhysicsResult.getStringField("AudioEventLightHit");
		Table.AudioSpeedThresholdLightHit = VehiclePhysicsResult.getFloatField("AudioSpeedThresholdLightHit");
		Table.AudioTimeoutLightHit = VehiclePhysicsResult.getFloatField("AudioTimeoutLightHit");
		Table.AudioEventHeavyHit = VehiclePhysicsResult.getStringField("AudioEventHeavyHit");
		Table.AudioSpeedThresholdHeavyHit = VehiclePhysicsResult.getFloatField("AudioSpeedThresholdHeavyHit");
		Table.AudioTimeoutHeavyHit = VehiclePhysicsResult.getFloatField("AudioTimeoutHeavyHit");
		Table.AudioEventStart = VehiclePhysicsResult.getStringField("AudioEventStart");
		Table.AudioEventTreadConcrete = VehiclePhysicsResult.getStringField("AudioEventTreadConcrete");
		Table.AudioEventTreadSand = VehiclePhysicsResult.getStringField("AudioEventTreadSand");
		Table.AudioEventTreadWood = VehiclePhysicsResult.getStringField("AudioEventTreadWood");
		Table.AudioEventTreadDirt = VehiclePhysicsResult.getStringField("AudioEventTreadDirt");
		Table.AudioEventTreadPlastic = VehiclePhysicsResult.getStringField("AudioEventTreadPlastic");
		Table.AudioEventTreadGrass = VehiclePhysicsResult.getStringField("AudioEventTreadGrass");
		Table.AudioEventTreadGravel = VehiclePhysicsResult.getStringField("AudioEventTreadGravel");
		Table.AudioEventTreadMud = VehiclePhysicsResult.getStringField("AudioEventTreadMud");
		Table.AudioEventTreadWater = VehiclePhysicsResult.getStringField("AudioEventTreadWater");
		Table.AudioEventTreadSnow = VehiclePhysicsResult.getStringField("AudioEventTreadSnow");
		Table.AudioEventTreadIce = VehiclePhysicsResult.getStringField("AudioEventTreadIce");
		Table.AudioEventTreadMetal = VehiclePhysicsResult.getStringField("AudioEventTreadMetal");
		Table.AudioEventTreadLeaves = VehiclePhysicsResult.getStringField("AudioEventTreadLeaves");
		Table.AudioEventLightLand = VehiclePhysicsResult.getStringField("AudioEventLightLand");
		Table.AudioAirtimeForLightLand = VehiclePhysicsResult.getFloatField("AudioAirtimeForLightLand");
		Table.AudioEventHeavyLand = VehiclePhysicsResult.getStringField("AudioEventHeavyLand");
		Table.AudioAirtimeForHeavyLand = VehiclePhysicsResult.getFloatField("AudioAirtimeForHeavyLand");
		Table.bWheelsVisible = VehiclePhysicsResult.getIntField("bWheelsVisible");
		VehiclePhysicsData.push_back(Table);
		VehiclePhysicsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded VehiclePhysics");
#endif

#ifdef CacheVehicleStatMap
	auto VehicleStatMapQuery = this->compileStatement("SELECT * FROM VehicleStatMap");
	auto VehicleStatMapResult = VehicleStatMapQuery.execQuery();
	while (!VehicleStatMapResult.eof()) {
		CDClientStructs::VehicleStatMap Table;
		Table.efId = VehicleStatMapResult.getIntField("efId");
		Table.id = VehicleStatMapResult.getIntField("id");
		Table.ModuleStat = VehicleStatMapResult.getStringField("ModuleStat");
		Table.HavokStat = VehicleStatMapResult.getStringField("HavokStat");
		Table.HavokChangePerModuleStat = VehicleStatMapResult.getFloatField("HavokChangePerModuleStat");
		VehicleStatMapData.push_back(Table);
		VehicleStatMapResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded VehicleStatMap");
#endif

#ifdef CacheVendorComponent
	auto VendorComponentQuery = this->compileStatement("SELECT * FROM VendorComponent");
	auto VendorComponentResult = VendorComponentQuery.execQuery();
	while (!VendorComponentResult.eof()) {
		CDClientStructs::VendorComponent Table;
		Table.efId = VendorComponentResult.getIntField("efId");
		Table.id = VendorComponentResult.getIntField("id");
		Table.buyScalar = VendorComponentResult.getFloatField("buyScalar");
		Table.sellScalar = VendorComponentResult.getFloatField("sellScalar");
		Table.refreshTimeSeconds = VendorComponentResult.getFloatField("refreshTimeSeconds");
		Table.LootMatrixIndex = VendorComponentResult.getIntField("LootMatrixIndex");
		VendorComponentData.push_back(Table);
		VendorComponentResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded VendorComponent");
#endif

#ifdef CacheWhatsCoolItemSpotlight
	auto WhatsCoolItemSpotlightQuery = this->compileStatement("SELECT * FROM WhatsCoolItemSpotlight");
	auto WhatsCoolItemSpotlightResult = WhatsCoolItemSpotlightQuery.execQuery();
	while (!WhatsCoolItemSpotlightResult.eof()) {
		CDClientStructs::WhatsCoolItemSpotlight Table;
		Table.efId = WhatsCoolItemSpotlightResult.getIntField("efId");
		Table.id = WhatsCoolItemSpotlightResult.getIntField("id");
		Table.itemID = WhatsCoolItemSpotlightResult.getIntField("itemID");
		Table.localize = WhatsCoolItemSpotlightResult.getIntField("localize");
		Table.gate_version = WhatsCoolItemSpotlightResult.getStringField("gate_version");
		Table.locStatus = WhatsCoolItemSpotlightResult.getIntField("locStatus");
		WhatsCoolItemSpotlightData.push_back(Table);
		WhatsCoolItemSpotlightResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded WhatsCoolItemSpotlight");
#endif

#ifdef CacheWhatsCoolNewsAndTips
	auto WhatsCoolNewsAndTipsQuery = this->compileStatement("SELECT * FROM WhatsCoolNewsAndTips");
	auto WhatsCoolNewsAndTipsResult = WhatsCoolNewsAndTipsQuery.execQuery();
	while (!WhatsCoolNewsAndTipsResult.eof()) {
		CDClientStructs::WhatsCoolNewsAndTips Table;
		Table.efId = WhatsCoolNewsAndTipsResult.getIntField("efId");
		Table.id = WhatsCoolNewsAndTipsResult.getIntField("id");
		Table.iconID = WhatsCoolNewsAndTipsResult.getIntField("iconID");
		Table.type = WhatsCoolNewsAndTipsResult.getIntField("type");
		Table.localize = WhatsCoolNewsAndTipsResult.getIntField("localize");
		Table.gate_version = WhatsCoolNewsAndTipsResult.getStringField("gate_version");
		Table.locStatus = WhatsCoolNewsAndTipsResult.getIntField("locStatus");
		WhatsCoolNewsAndTipsData.push_back(Table);
		WhatsCoolNewsAndTipsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded WhatsCoolNewsAndTips");
#endif

#ifdef CacheWorldConfig
	auto WorldConfigQuery = this->compileStatement("SELECT * FROM WorldConfig");
	auto WorldConfigResult = WorldConfigQuery.execQuery();
	while (!WorldConfigResult.eof()) {
		CDClientStructs::WorldConfig Table;
		Table.efId = WorldConfigResult.getIntField("efId");
		Table.WorldConfigID = WorldConfigResult.getIntField("WorldConfigID");
		Table.pegravityvalue = WorldConfigResult.getFloatField("pegravityvalue");
		Table.pebroadphaseworldsize = WorldConfigResult.getFloatField("pebroadphaseworldsize");
		Table.pegameobjscalefactor = WorldConfigResult.getFloatField("pegameobjscalefactor");
		Table.character_rotation_speed = WorldConfigResult.getFloatField("character_rotation_speed");
		Table.character_walk_forward_speed = WorldConfigResult.getFloatField("character_walk_forward_speed");
		Table.character_walk_backward_speed = WorldConfigResult.getFloatField("character_walk_backward_speed");
		Table.character_walk_strafe_speed = WorldConfigResult.getFloatField("character_walk_strafe_speed");
		Table.character_walk_strafe_forward_speed = WorldConfigResult.getFloatField("character_walk_strafe_forward_speed");
		Table.character_walk_strafe_backward_speed = WorldConfigResult.getFloatField("character_walk_strafe_backward_speed");
		Table.character_run_backward_speed = WorldConfigResult.getFloatField("character_run_backward_speed");
		Table.character_run_strafe_speed = WorldConfigResult.getFloatField("character_run_strafe_speed");
		Table.character_run_strafe_forward_speed = WorldConfigResult.getFloatField("character_run_strafe_forward_speed");
		Table.character_run_strafe_backward_speed = WorldConfigResult.getFloatField("character_run_strafe_backward_speed");
		Table.global_cooldown = WorldConfigResult.getFloatField("global_cooldown");
		Table.characterGroundedTime = WorldConfigResult.getFloatField("characterGroundedTime");
		Table.characterGroundedSpeed = WorldConfigResult.getFloatField("characterGroundedSpeed");
		Table.globalImmunityTime = WorldConfigResult.getFloatField("globalImmunityTime");
		Table.character_max_slope = WorldConfigResult.getFloatField("character_max_slope");
		Table.defaultrespawntime = WorldConfigResult.getFloatField("defaultrespawntime");
		Table.mission_tooltip_timeout = WorldConfigResult.getFloatField("mission_tooltip_timeout");
		Table.vendor_buy_multiplier = WorldConfigResult.getFloatField("vendor_buy_multiplier");
		Table.pet_follow_radius = WorldConfigResult.getFloatField("pet_follow_radius");
		Table.character_eye_height = WorldConfigResult.getFloatField("character_eye_height");
		Table.flight_vertical_velocity = WorldConfigResult.getFloatField("flight_vertical_velocity");
		Table.flight_airspeed = WorldConfigResult.getFloatField("flight_airspeed");
		Table.flight_fuel_ratio = WorldConfigResult.getFloatField("flight_fuel_ratio");
		Table.flight_max_airspeed = WorldConfigResult.getFloatField("flight_max_airspeed");
		Table.fReputationPerVote = WorldConfigResult.getFloatField("fReputationPerVote");
		Table.nPropertyCloneLimit = WorldConfigResult.getIntField("nPropertyCloneLimit");
		Table.defaultHomespaceTemplate = WorldConfigResult.getIntField("defaultHomespaceTemplate");
		Table.coins_lost_on_death_percent = WorldConfigResult.getFloatField("coins_lost_on_death_percent");
		Table.coins_lost_on_death_min = WorldConfigResult.getIntField("coins_lost_on_death_min");
		Table.coins_lost_on_death_max = WorldConfigResult.getIntField("coins_lost_on_death_max");
		Table.character_votes_per_day = WorldConfigResult.getIntField("character_votes_per_day");
		Table.property_moderation_request_approval_cost = WorldConfigResult.getIntField("property_moderation_request_approval_cost");
		Table.property_moderation_request_review_cost = WorldConfigResult.getIntField("property_moderation_request_review_cost");
		Table.propertyModRequestsAllowedSpike = WorldConfigResult.getIntField("propertyModRequestsAllowedSpike");
		Table.propertyModRequestsAllowedInterval = WorldConfigResult.getIntField("propertyModRequestsAllowedInterval");
		Table.propertyModRequestsAllowedTotal = WorldConfigResult.getIntField("propertyModRequestsAllowedTotal");
		Table.propertyModRequestsSpikeDuration = WorldConfigResult.getIntField("propertyModRequestsSpikeDuration");
		Table.propertyModRequestsIntervalDuration = WorldConfigResult.getIntField("propertyModRequestsIntervalDuration");
		Table.modelModerateOnCreate = WorldConfigResult.getIntField("modelModerateOnCreate");
		Table.defaultPropertyMaxHeight = WorldConfigResult.getFloatField("defaultPropertyMaxHeight");
		Table.reputationPerVoteCast = WorldConfigResult.getFloatField("reputationPerVoteCast");
		Table.reputationPerVoteReceived = WorldConfigResult.getFloatField("reputationPerVoteReceived");
		Table.showcaseTopModelConsiderationBattles = WorldConfigResult.getIntField("showcaseTopModelConsiderationBattles");
		Table.reputationPerBattlePromotion = WorldConfigResult.getFloatField("reputationPerBattlePromotion");
		Table.coins_lost_on_death_min_timeout = WorldConfigResult.getFloatField("coins_lost_on_death_min_timeout");
		Table.coins_lost_on_death_max_timeout = WorldConfigResult.getFloatField("coins_lost_on_death_max_timeout");
		Table.mail_base_fee = WorldConfigResult.getIntField("mail_base_fee");
		Table.mail_percent_attachment_fee = WorldConfigResult.getFloatField("mail_percent_attachment_fee");
		Table.propertyReputationDelay = WorldConfigResult.getIntField("propertyReputationDelay");
		Table.LevelCap = WorldConfigResult.getIntField("LevelCap");
		Table.LevelUpBehaviorEffect = WorldConfigResult.getStringField("LevelUpBehaviorEffect");
		Table.CharacterVersion = WorldConfigResult.getIntField("CharacterVersion");
		Table.LevelCapCurrencyConversion = WorldConfigResult.getIntField("LevelCapCurrencyConversion");
		WorldConfigData.push_back(Table);
		WorldConfigResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded WorldConfig");
#endif

#ifdef CacheZoneLoadingTips
	auto ZoneLoadingTipsQuery = this->compileStatement("SELECT * FROM ZoneLoadingTips");
	auto ZoneLoadingTipsResult = ZoneLoadingTipsQuery.execQuery();
	while (!ZoneLoadingTipsResult.eof()) {
		CDClientStructs::ZoneLoadingTips Table;
		Table.efId = ZoneLoadingTipsResult.getIntField("efId");
		Table.id = ZoneLoadingTipsResult.getIntField("id");
		Table.zoneid = ZoneLoadingTipsResult.getIntField("zoneid");
		Table.imagelocation = ZoneLoadingTipsResult.getStringField("imagelocation");
		Table.localize = ZoneLoadingTipsResult.getIntField("localize");
		Table.gate_version = ZoneLoadingTipsResult.getStringField("gate_version");
		Table.locStatus = ZoneLoadingTipsResult.getIntField("locStatus");
		Table.weight = ZoneLoadingTipsResult.getIntField("weight");
		Table.targetVersion = ZoneLoadingTipsResult.getStringField("targetVersion");
		ZoneLoadingTipsData.push_back(Table);
		ZoneLoadingTipsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ZoneLoadingTips");
#endif

#ifdef CacheZoneSummary
	auto ZoneSummaryQuery = this->compileStatement("SELECT * FROM ZoneSummary");
	auto ZoneSummaryResult = ZoneSummaryQuery.execQuery();
	while (!ZoneSummaryResult.eof()) {
		CDClientStructs::ZoneSummary Table;
		Table.efId = ZoneSummaryResult.getIntField("efId");
		Table.zoneID = ZoneSummaryResult.getIntField("zoneID");
		Table.type = ZoneSummaryResult.getIntField("type");
		Table.value = ZoneSummaryResult.getIntField("value");
		Table._uniqueID = ZoneSummaryResult.getIntField("_uniqueID");
		ZoneSummaryData.push_back(Table);
		ZoneSummaryResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ZoneSummary");
#endif

#ifdef CacheZoneTable
	auto ZoneTableQuery = this->compileStatement("SELECT * FROM ZoneTable");
	auto ZoneTableResult = ZoneTableQuery.execQuery();
	while (!ZoneTableResult.eof()) {
		CDClientStructs::ZoneTable Table;
		Table.efId = ZoneTableResult.getIntField("efId");
		Table.zoneID = ZoneTableResult.getIntField("zoneID");
		Table.locStatus = ZoneTableResult.getIntField("locStatus");
		Table.zoneName = ZoneTableResult.getStringField("zoneName");
		Table.scriptID = ZoneTableResult.getIntField("scriptID");
		Table.ghostdistance_min = ZoneTableResult.getFloatField("ghostdistance_min");
		Table.ghostdistance = ZoneTableResult.getFloatField("ghostdistance");
		Table.population_soft_cap = ZoneTableResult.getIntField("population_soft_cap");
		Table.population_hard_cap = ZoneTableResult.getIntField("population_hard_cap");
		Table.DisplayDescription = ZoneTableResult.getStringField("DisplayDescription");
		Table.mapFolder = ZoneTableResult.getStringField("mapFolder");
		Table.smashableMinDistance = ZoneTableResult.getFloatField("smashableMinDistance");
		Table.smashableMaxDistance = ZoneTableResult.getFloatField("smashableMaxDistance");
		Table.mixerProgram = ZoneTableResult.getStringField("mixerProgram");
		Table.clientPhysicsFramerate = ZoneTableResult.getStringField("clientPhysicsFramerate");
		Table.serverPhysicsFramerate = ZoneTableResult.getStringField("serverPhysicsFramerate");
		Table.zoneControlTemplate = ZoneTableResult.getIntField("zoneControlTemplate");
		Table.widthInChunks = ZoneTableResult.getIntField("widthInChunks");
		Table.heightInChunks = ZoneTableResult.getIntField("heightInChunks");
		Table.petsAllowed = ZoneTableResult.getIntField("petsAllowed");
		Table.localize = ZoneTableResult.getIntField("localize");
		Table.fZoneWeight = ZoneTableResult.getFloatField("fZoneWeight");
		Table.thumbnail = ZoneTableResult.getStringField("thumbnail");
		Table.PlayerLoseCoinsOnDeath = ZoneTableResult.getIntField("PlayerLoseCoinsOnDeath");
		Table.disableSaveLoc = ZoneTableResult.getIntField("disableSaveLoc");
		Table.teamRadius = ZoneTableResult.getFloatField("teamRadius");
		Table.gate_version = ZoneTableResult.getStringField("gate_version");
		Table.mountsAllowed = ZoneTableResult.getIntField("mountsAllowed");
		ZoneTableData.push_back(Table);
		ZoneTableResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded ZoneTable");
#endif

#ifdef CachebrickAttributes
	auto brickAttributesQuery = this->compileStatement("SELECT * FROM brickAttributes");
	auto brickAttributesResult = brickAttributesQuery.execQuery();
	while (!brickAttributesResult.eof()) {
		CDClientStructs::brickAttributes Table;
		Table.efId = brickAttributesResult.getIntField("efId");
		Table.ID = brickAttributesResult.getIntField("ID");
		Table.icon_asset = brickAttributesResult.getStringField("icon_asset");
		Table.display_order = brickAttributesResult.getIntField("display_order");
		Table.locStatus = brickAttributesResult.getIntField("locStatus");
		brickAttributesData.push_back(Table);
		brickAttributesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded brickAttributes");
#endif

#ifdef CachemapAnimationPriorities
	auto mapAnimationPrioritiesQuery = this->compileStatement("SELECT * FROM mapAnimationPriorities");
	auto mapAnimationPrioritiesResult = mapAnimationPrioritiesQuery.execQuery();
	while (!mapAnimationPrioritiesResult.eof()) {
		CDClientStructs::mapAnimationPriorities Table;
		Table.efId = mapAnimationPrioritiesResult.getIntField("efId");
		Table.id = mapAnimationPrioritiesResult.getIntField("id");
		Table.name = mapAnimationPrioritiesResult.getStringField("name");
		Table.priority = mapAnimationPrioritiesResult.getFloatField("priority");
		mapAnimationPrioritiesData.push_back(Table);
		mapAnimationPrioritiesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded mapAnimationPriorities");
#endif

#ifdef CachemapAssetType
	auto mapAssetTypeQuery = this->compileStatement("SELECT * FROM mapAssetType");
	auto mapAssetTypeResult = mapAssetTypeQuery.execQuery();
	while (!mapAssetTypeResult.eof()) {
		CDClientStructs::mapAssetType Table;
		Table.efId = mapAssetTypeResult.getIntField("efId");
		Table.id = mapAssetTypeResult.getIntField("id");
		Table.label = mapAssetTypeResult.getStringField("label");
		Table.pathdir = mapAssetTypeResult.getStringField("pathdir");
		Table.typelabel = mapAssetTypeResult.getStringField("typelabel");
		mapAssetTypeData.push_back(Table);
		mapAssetTypeResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded mapAssetType");
#endif

#ifdef CachemapIcon
	auto mapIconQuery = this->compileStatement("SELECT * FROM mapIcon");
	auto mapIconResult = mapIconQuery.execQuery();
	while (!mapIconResult.eof()) {
		CDClientStructs::mapIcon Table;
		Table.efId = mapIconResult.getIntField("efId");
		Table.LOT = mapIconResult.getIntField("LOT");
		Table.iconID = mapIconResult.getIntField("iconID");
		Table.iconState = mapIconResult.getIntField("iconState");
		mapIconData.push_back(Table);
		mapIconResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded mapIcon");
#endif

#ifdef CachemapItemTypes
	auto mapItemTypesQuery = this->compileStatement("SELECT * FROM mapItemTypes");
	auto mapItemTypesResult = mapItemTypesQuery.execQuery();
	while (!mapItemTypesResult.eof()) {
		CDClientStructs::mapItemTypes Table;
		Table.efId = mapItemTypesResult.getIntField("efId");
		Table.id = mapItemTypesResult.getIntField("id");
		Table.description = mapItemTypesResult.getStringField("description");
		Table.equipLocation = mapItemTypesResult.getStringField("equipLocation");
		mapItemTypesData.push_back(Table);
		mapItemTypesResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded mapItemTypes");
#endif

#ifdef CachemapRenderEffects
	auto mapRenderEffectsQuery = this->compileStatement("SELECT * FROM mapRenderEffects");
	auto mapRenderEffectsResult = mapRenderEffectsQuery.execQuery();
	while (!mapRenderEffectsResult.eof()) {
		CDClientStructs::mapRenderEffects Table;
		Table.efId = mapRenderEffectsResult.getIntField("efId");
		Table.id = mapRenderEffectsResult.getIntField("id");
		Table.gameID = mapRenderEffectsResult.getIntField("gameID");
		Table.description = mapRenderEffectsResult.getStringField("description");
		mapRenderEffectsData.push_back(Table);
		mapRenderEffectsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded mapRenderEffects");
#endif

#ifdef CachemapShaders
	auto mapShadersQuery = this->compileStatement("SELECT * FROM mapShaders");
	auto mapShadersResult = mapShadersQuery.execQuery();
	while (!mapShadersResult.eof()) {
		CDClientStructs::mapShaders Table;
		Table.efId = mapShadersResult.getIntField("efId");
		Table.id = mapShadersResult.getIntField("id");
		Table.label = mapShadersResult.getStringField("label");
		Table.gameValue = mapShadersResult.getIntField("gameValue");
		Table.priority = mapShadersResult.getIntField("priority");
		mapShadersData.push_back(Table);
		mapShadersResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded mapShaders");
#endif

#ifdef CachemapTextureResource
	auto mapTextureResourceQuery = this->compileStatement("SELECT * FROM mapTextureResource");
	auto mapTextureResourceResult = mapTextureResourceQuery.execQuery();
	while (!mapTextureResourceResult.eof()) {
		CDClientStructs::mapTextureResource Table;
		Table.efId = mapTextureResourceResult.getIntField("efId");
		Table.id = mapTextureResourceResult.getIntField("id");
		Table.texturepath = mapTextureResourceResult.getStringField("texturepath");
		Table.SurfaceType = mapTextureResourceResult.getIntField("SurfaceType");
		mapTextureResourceData.push_back(Table);
		mapTextureResourceResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded mapTextureResource");
#endif

#ifdef Cachemap_BlueprintCategory
	auto map_BlueprintCategoryQuery = this->compileStatement("SELECT * FROM map_BlueprintCategory");
	auto map_BlueprintCategoryResult = map_BlueprintCategoryQuery.execQuery();
	while (!map_BlueprintCategoryResult.eof()) {
		CDClientStructs::map_BlueprintCategory Table;
		Table.efId = map_BlueprintCategoryResult.getIntField("efId");
		Table.id = map_BlueprintCategoryResult.getIntField("id");
		Table.description = map_BlueprintCategoryResult.getStringField("description");
		Table.enabled = map_BlueprintCategoryResult.getIntField("enabled");
		map_BlueprintCategoryData.push_back(Table);
		map_BlueprintCategoryResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded map_BlueprintCategory");
#endif

#ifdef Cachesysdiagrams
	auto sysdiagramsQuery = this->compileStatement("SELECT * FROM sysdiagrams");
	auto sysdiagramsResult = sysdiagramsQuery.execQuery();
	while (!sysdiagramsResult.eof()) {
		CDClientStructs::sysdiagrams Table;
		Table.efId = sysdiagramsResult.getIntField("efId");
		Table.name = sysdiagramsResult.getStringField("name");
		Table.principal_id = sysdiagramsResult.getIntField("principal_id");
		Table.diagram_id = sysdiagramsResult.getIntField("diagram_id");
		Table.version = sysdiagramsResult.getIntField("version");
		Table.definition = sysdiagramsResult.getStringField("definition");
		sysdiagramsData.push_back(Table);
		sysdiagramsResult.nextRow();
	}
	Logger::Log("CDClient", "Loaded sysdiagrams");
#endif

}