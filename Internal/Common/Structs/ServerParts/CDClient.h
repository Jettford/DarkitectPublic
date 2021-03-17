#pragma once

#include <vector>

#include "Logger.h"
#include "CDClient/CDClientStructs.h"

#include <CppSQLite3/CppSQLite3.h>

#define CacheMissionNPCComponent
#define CacheMissions
#define CacheActivities
#define CacheInventoryComponent
#define CacheDestructibleComponent
#define CacheScriptComponent

#define GET_ROW_BY_ID(CDClient, TableName, idv) CDClientStructs::##TableName Row; { std::vector<CDClientStructs::##TableName> temp_table; temp_table = std::vector<CDClientStructs::##TableName>(); std::copy_if(##CDClient##->##TableName##Data.begin(), ##CDClient##->##TableName##Data.end(), std::back_inserter(temp_table), [&](CDClientStructs::##TableName itensla) { return itensla.id == ##idv ; }); Row = temp_table.at(0); } 
#define GET_ROWS_BY_ID(CDClient, TableName, idv) std::vector<CDClientStructs::##TableName> Rows; Rows = std::vector<CDClientStructs::##TableName>(); std::copy_if(##CDClient##->##TableName##Data.begin(), ##CDClient##->##TableName##Data.end(), std::back_inserter(Rows), [&](CDClientStructs::##TableName itensla) { return itensla.id == ##idv ; });

class CDClient : public CppSQLite3DB { // I hate this
public:
#ifdef CacheAICombatRoles
	std::vector<CDClientStructs::AICombatRoles> AICombatRolesData;
#endif
#ifdef CacheAccessoryDefaultLoc
	std::vector<CDClientStructs::AccessoryDefaultLoc> AccessoryDefaultLocData;
#endif
#ifdef CacheActivities
	std::vector<CDClientStructs::Activities> ActivitiesData;
#endif
#ifdef CacheActivityRewards
	std::vector<CDClientStructs::ActivityRewards> ActivityRewardsData;
#endif
#ifdef CacheActivityText
	std::vector<CDClientStructs::ActivityText> ActivityTextData;
#endif
#ifdef CacheAnimationIndex
	std::vector<CDClientStructs::AnimationIndex> AnimationIndexData;
#endif
#ifdef CacheAnimations
	std::vector<CDClientStructs::Animations> AnimationsData;
#endif
#ifdef CacheBaseCombatAIComponent
	std::vector<CDClientStructs::BaseCombatAIComponent> BaseCombatAIComponentData;
#endif
#ifdef CacheBehaviorEffect
	std::vector<CDClientStructs::BehaviorEffect> BehaviorEffectData;
#endif
#ifdef CacheBehaviorParameter
	std::vector<CDClientStructs::BehaviorParameter> BehaviorParameterData;
#endif
#ifdef CacheBehaviorTemplate
	std::vector<CDClientStructs::BehaviorTemplate> BehaviorTemplateData;
#endif
#ifdef CacheBehaviorTemplateName
	std::vector<CDClientStructs::BehaviorTemplateName> BehaviorTemplateNameData;
#endif
#ifdef CacheBlueprints
	std::vector<CDClientStructs::Blueprints> BlueprintsData;
#endif
#ifdef CacheBrickColors
	std::vector<CDClientStructs::BrickColors> BrickColorsData;
#endif
#ifdef CacheBrickIDTable
	std::vector<CDClientStructs::BrickIDTable> BrickIDTableData;
#endif
#ifdef CacheBuffDefinitions
	std::vector<CDClientStructs::BuffDefinitions> BuffDefinitionsData;
#endif
#ifdef CacheBuffParameters
	std::vector<CDClientStructs::BuffParameters> BuffParametersData;
#endif
#ifdef CacheCamera
	std::vector<CDClientStructs::Camera> CameraData;
#endif
#ifdef CacheCelebrationParameters
	std::vector<CDClientStructs::CelebrationParameters> CelebrationParametersData;
#endif
#ifdef CacheChoiceBuildComponent
	std::vector<CDClientStructs::ChoiceBuildComponent> ChoiceBuildComponentData;
#endif
#ifdef CacheCollectibleComponent
	std::vector<CDClientStructs::CollectibleComponent> CollectibleComponentData;
#endif
#ifdef CacheComponentsRegistry
	std::vector<CDClientStructs::ComponentsRegistry> ComponentsRegistryData;
#endif
#ifdef CacheControlSchemes
	std::vector<CDClientStructs::ControlSchemes> ControlSchemesData;
#endif
#ifdef CacheCurrencyDenominations
	std::vector<CDClientStructs::CurrencyDenominations> CurrencyDenominationsData;
#endif
#ifdef CacheCurrencyTable
	std::vector<CDClientStructs::CurrencyTable> CurrencyTableData;
#endif
#ifdef CacheDBExclude
	std::vector<CDClientStructs::DBExclude> DBExcludeData;
#endif
#ifdef CacheDeletionRestrictions
	std::vector<CDClientStructs::DeletionRestrictions> DeletionRestrictionsData;
#endif
#ifdef CacheDestructibleComponent
	std::vector<CDClientStructs::DestructibleComponent> DestructibleComponentData;
#endif
#ifdef CacheEmotes
	std::vector<CDClientStructs::Emotes> EmotesData;
#endif
#ifdef CacheEventGating
	std::vector<CDClientStructs::EventGating> EventGatingData;
#endif
#ifdef CacheExhibitComponent
	std::vector<CDClientStructs::ExhibitComponent> ExhibitComponentData;
#endif
#ifdef CacheFactions
	std::vector<CDClientStructs::Factions> FactionsData;
#endif
#ifdef CacheFeatureGating
	std::vector<CDClientStructs::FeatureGating> FeatureGatingData;
#endif
#ifdef CacheFlairTable
	std::vector<CDClientStructs::FlairTable> FlairTableData;
#endif
#ifdef CacheIcons
	std::vector<CDClientStructs::Icons> IconsData;
#endif
#ifdef CacheInventoryComponent
	std::vector<CDClientStructs::InventoryComponent> InventoryComponentData;
#endif
#ifdef CacheItemComponent
	std::vector<CDClientStructs::ItemComponent> ItemComponentData;
#endif
#ifdef CacheItemEggData
	std::vector<CDClientStructs::ItemEggData> ItemEggDataData;
#endif
#ifdef CacheItemSetSkills
	std::vector<CDClientStructs::ItemSetSkills> ItemSetSkillsData;
#endif
#ifdef CacheItemSets
	std::vector<CDClientStructs::ItemSets> ItemSetsData;
#endif
#ifdef CacheJetPackPadComponent
	std::vector<CDClientStructs::JetPackPadComponent> JetPackPadComponentData;
#endif
#ifdef CacheLUPExhibitComponent
	std::vector<CDClientStructs::LUPExhibitComponent> LUPExhibitComponentData;
#endif
#ifdef CacheLUPExhibitModelData
	std::vector<CDClientStructs::LUPExhibitModelData> LUPExhibitModelDataData;
#endif
#ifdef CacheLUPZoneIDs
	std::vector<CDClientStructs::LUPZoneIDs> LUPZoneIDsData;
#endif
#ifdef CacheLanguageType
	std::vector<CDClientStructs::LanguageType> LanguageTypeData;
#endif
#ifdef CacheLevelProgressionLookup
	std::vector<CDClientStructs::LevelProgressionLookup> LevelProgressionLookupData;
#endif
#ifdef CacheLootMatrix
	std::vector<CDClientStructs::LootMatrix> LootMatrixData;
#endif
#ifdef CacheLootMatrixIndex
	std::vector<CDClientStructs::LootMatrixIndex> LootMatrixIndexData;
#endif
#ifdef CacheLootTable
	std::vector<CDClientStructs::LootTable> LootTableData;
#endif
#ifdef CacheLootTableIndex
	std::vector<CDClientStructs::LootTableIndex> LootTableIndexData;
#endif
#ifdef CacheMinifigComponent
	std::vector<CDClientStructs::MinifigComponent> MinifigComponentData;
#endif
#ifdef CacheMinifigDecals_Eyebrows
	std::vector<CDClientStructs::MinifigDecals_Eyebrows> MinifigDecals_EyebrowsData;
#endif
#ifdef CacheMinifigDecals_Eyes
	std::vector<CDClientStructs::MinifigDecals_Eyes> MinifigDecals_EyesData;
#endif
#ifdef CacheMinifigDecals_Legs
	std::vector<CDClientStructs::MinifigDecals_Legs> MinifigDecals_LegsData;
#endif
#ifdef CacheMinifigDecals_Mouths
	std::vector<CDClientStructs::MinifigDecals_Mouths> MinifigDecals_MouthsData;
#endif
#ifdef CacheMinifigDecals_Torsos
	std::vector<CDClientStructs::MinifigDecals_Torsos> MinifigDecals_TorsosData;
#endif
#ifdef CacheMissionEmail
	std::vector<CDClientStructs::MissionEmail> MissionEmailData;
#endif
#ifdef CacheMissionNPCComponent
	std::vector<CDClientStructs::MissionNPCComponent> MissionNPCComponentData;
#endif
#ifdef CacheMissionTasks
	std::vector<CDClientStructs::MissionTasks> MissionTasksData;
#endif
#ifdef CacheMissionText
	std::vector<CDClientStructs::MissionText> MissionTextData;
#endif
#ifdef CacheMissions
	std::vector<CDClientStructs::Missions> MissionsData;
#endif
#ifdef CacheModelBehavior
	std::vector<CDClientStructs::ModelBehavior> ModelBehaviorData;
#endif
#ifdef CacheModularBuildComponent
	std::vector<CDClientStructs::ModularBuildComponent> ModularBuildComponentData;
#endif
#ifdef CacheModuleComponent
	std::vector<CDClientStructs::ModuleComponent> ModuleComponentData;
#endif
#ifdef CacheMotionFX
	std::vector<CDClientStructs::MotionFX> MotionFXData;
#endif
#ifdef CacheMovementAIComponent
	std::vector<CDClientStructs::MovementAIComponent> MovementAIComponentData;
#endif
#ifdef CacheMovingPlatforms
	std::vector<CDClientStructs::MovingPlatforms> MovingPlatformsData;
#endif
#ifdef CacheNpcIcons
	std::vector<CDClientStructs::NpcIcons> NpcIconsData;
#endif
#ifdef CacheObjectBehaviors
	std::vector<CDClientStructs::ObjectBehaviors> ObjectBehaviorsData;
#endif
#ifdef CacheObjectSkills
	std::vector<CDClientStructs::ObjectSkills> ObjectSkillsData;
#endif
#ifdef CacheObjects
	std::vector<CDClientStructs::Objects> ObjectsData;
#endif
#ifdef CachePackageComponent
	std::vector<CDClientStructs::PackageComponent> PackageComponentData;
#endif
#ifdef CachePetAbilities
	std::vector<CDClientStructs::PetAbilities> PetAbilitiesData;
#endif
#ifdef CachePetComponent
	std::vector<CDClientStructs::PetComponent> PetComponentData;
#endif
#ifdef CachePetNestComponent
	std::vector<CDClientStructs::PetNestComponent> PetNestComponentData;
#endif
#ifdef CachePhysicsComponent
	std::vector<CDClientStructs::PhysicsComponent> PhysicsComponentData;
#endif
#ifdef CachePlayerFlags
	std::vector<CDClientStructs::PlayerFlags> PlayerFlagsData;
#endif
#ifdef CachePlayerStatistics
	std::vector<CDClientStructs::PlayerStatistics> PlayerStatisticsData;
#endif
#ifdef CachePossessableComponent
	std::vector<CDClientStructs::PossessableComponent> PossessableComponentData;
#endif
#ifdef CachePreconditions
	std::vector<CDClientStructs::Preconditions> PreconditionsData;
#endif
#ifdef CachePropertyEntranceComponent
	std::vector<CDClientStructs::PropertyEntranceComponent> PropertyEntranceComponentData;
#endif
#ifdef CachePropertyTemplate
	std::vector<CDClientStructs::PropertyTemplate> PropertyTemplateData;
#endif
#ifdef CacheProximityMonitorComponent
	std::vector<CDClientStructs::ProximityMonitorComponent> ProximityMonitorComponentData;
#endif
#ifdef CacheProximityTypes
	std::vector<CDClientStructs::ProximityTypes> ProximityTypesData;
#endif
#ifdef CacheRacingModuleComponent
	std::vector<CDClientStructs::RacingModuleComponent> RacingModuleComponentData;
#endif
#ifdef CacheRailActivatorComponent
	std::vector<CDClientStructs::RailActivatorComponent> RailActivatorComponentData;
#endif
#ifdef CacheRarityTable
	std::vector<CDClientStructs::RarityTable> RarityTableData;
#endif
#ifdef CacheRarityTableIndex
	std::vector<CDClientStructs::RarityTableIndex> RarityTableIndexData;
#endif
#ifdef CacheRebuildComponent
	std::vector<CDClientStructs::RebuildComponent> RebuildComponentData;
#endif
#ifdef CacheRebuildSections
	std::vector<CDClientStructs::RebuildSections> RebuildSectionsData;
#endif
#ifdef CacheRelease_Version
	std::vector<CDClientStructs::Release_Version> Release_VersionData;
#endif
#ifdef CacheRenderComponent
	std::vector<CDClientStructs::RenderComponent> RenderComponentData;
#endif
#ifdef CacheRenderComponentFlash
	std::vector<CDClientStructs::RenderComponentFlash> RenderComponentFlashData;
#endif
#ifdef CacheRenderComponentWrapper
	std::vector<CDClientStructs::RenderComponentWrapper> RenderComponentWrapperData;
#endif
#ifdef CacheRenderIconAssets
	std::vector<CDClientStructs::RenderIconAssets> RenderIconAssetsData;
#endif
#ifdef CacheRewardCodes
	std::vector<CDClientStructs::RewardCodes> RewardCodesData;
#endif
#ifdef CacheRewards
	std::vector<CDClientStructs::Rewards> RewardsData;
#endif
#ifdef CacheRocketLaunchpadControlComponent
	std::vector<CDClientStructs::RocketLaunchpadControlComponent> RocketLaunchpadControlComponentData;
#endif
#ifdef CacheSceneTable
	std::vector<CDClientStructs::SceneTable> SceneTableData;
#endif
#ifdef CacheScriptComponent
	std::vector<CDClientStructs::ScriptComponent> ScriptComponentData;
#endif
#ifdef CacheSkillBehavior
	std::vector<CDClientStructs::SkillBehavior> SkillBehaviorData;
#endif
#ifdef CacheSmashableChain
	std::vector<CDClientStructs::SmashableChain> SmashableChainData;
#endif
#ifdef CacheSmashableChainIndex
	std::vector<CDClientStructs::SmashableChainIndex> SmashableChainIndexData;
#endif
#ifdef CacheSmashableComponent
	std::vector<CDClientStructs::SmashableComponent> SmashableComponentData;
#endif
#ifdef CacheSmashableElements
	std::vector<CDClientStructs::SmashableElements> SmashableElementsData;
#endif
#ifdef CacheSpeedchatMenu
	std::vector<CDClientStructs::SpeedchatMenu> SpeedchatMenuData;
#endif
#ifdef CacheSubscriptionPricing
	std::vector<CDClientStructs::SubscriptionPricing> SubscriptionPricingData;
#endif
#ifdef CacheSurfaceType
	std::vector<CDClientStructs::SurfaceType> SurfaceTypeData;
#endif
#ifdef CacheTamingBuildPuzzles
	std::vector<CDClientStructs::TamingBuildPuzzles> TamingBuildPuzzlesData;
#endif
#ifdef CacheTrailEffects
	std::vector<CDClientStructs::TrailEffects> TrailEffectsData;
#endif
#ifdef CacheUGBehaviorSounds
	std::vector<CDClientStructs::UGBehaviorSounds> UGBehaviorSoundsData;
#endif
#ifdef CacheVehiclePhysics
	std::vector<CDClientStructs::VehiclePhysics> VehiclePhysicsData;
#endif
#ifdef CacheVehicleStatMap
	std::vector<CDClientStructs::VehicleStatMap> VehicleStatMapData;
#endif
#ifdef CacheVendorComponent
	std::vector<CDClientStructs::VendorComponent> VendorComponentData;
#endif
#ifdef CacheWhatsCoolItemSpotlight
	std::vector<CDClientStructs::WhatsCoolItemSpotlight> WhatsCoolItemSpotlightData;
#endif
#ifdef CacheWhatsCoolNewsAndTips
	std::vector<CDClientStructs::WhatsCoolNewsAndTips> WhatsCoolNewsAndTipsData;
#endif
#ifdef CacheWorldConfig
	std::vector<CDClientStructs::WorldConfig> WorldConfigData;
#endif
#ifdef CacheZoneLoadingTips
	std::vector<CDClientStructs::ZoneLoadingTips> ZoneLoadingTipsData;
#endif
#ifdef CacheZoneSummary
	std::vector<CDClientStructs::ZoneSummary> ZoneSummaryData;
#endif
#ifdef CacheZoneTable
	std::vector<CDClientStructs::ZoneTable> ZoneTableData;
#endif
#ifdef CachebrickAttributes
	std::vector<CDClientStructs::brickAttributes> brickAttributesData;
#endif
#ifdef CachemapAnimationPriorities
	std::vector<CDClientStructs::mapAnimationPriorities> mapAnimationPrioritiesData;
#endif
#ifdef CachemapAssetType
	std::vector<CDClientStructs::mapAssetType> mapAssetTypeData;
#endif
#ifdef CachemapIcon
	std::vector<CDClientStructs::mapIcon> mapIconData;
#endif
#ifdef CachemapItemTypes
	std::vector<CDClientStructs::mapItemTypes> mapItemTypesData;
#endif
#ifdef CachemapRenderEffects
	std::vector<CDClientStructs::mapRenderEffects> mapRenderEffectsData;
#endif
#ifdef CachemapShaders
	std::vector<CDClientStructs::mapShaders> mapShadersData;
#endif
#ifdef CachemapTextureResource
	std::vector<CDClientStructs::mapTextureResource> mapTextureResourceData;
#endif
#ifdef Cachemap_BlueprintCategory
	std::vector<CDClientStructs::map_BlueprintCategory> map_BlueprintCategoryData;
#endif
#ifdef Cachesysdiagrams
	std::vector<CDClientStructs::sysdiagrams> sysdiagramsData;
#endif

	CDClient();
	void Open();
	void LoadCDClientData();
};
