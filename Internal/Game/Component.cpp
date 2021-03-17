#include "Component.h"

#include "Components/CharacterComponent.h"
#include "Components/ControllablePhysicsComponent.h"
#include "Components/RenderComponent.h"
#include "Components/DestroyableComponent.h"
#include "Components/SkillComponent.h"
#include "Components/InventoryComponent.h"
#include "Components/StatsComponent.h"
#include "Components/Component107.h"
#include "Components/SpawnerComponent.h"
#include "Components/BouncerComponent.h"
#include "Components/ScriptComponent.h"
#include "Components/PhantomPhysicsComponent.h"
#include "Components/SimplePhysicsComponent.h"
#include "Components/VendorComponent.h"
#include "Components/MissionOfferComponent.h"
#include "Components/BaseCombatAIComponent.h"
#include "Components/ScriptedActivityComponent.h"
#include "Components/QuickbuildComponent.h"

Component* CreateComponentByType(Entity* Owner, uint32_t ComponentType) {
	Component* ReturnValue = nullptr;
	switch ((Enums::ECOMPONENT_TYPE)ComponentType) {
	case Enums::ECOMPONENT_TYPE::CONTROLABLE_PHYSICS_COMPONENT: ReturnValue = new ControllablePhysicsComponent(); break;
	case Enums::ECOMPONENT_TYPE::RENDER_COMPONENT: ReturnValue = new RenderComponent(); break;
	case Enums::ECOMPONENT_TYPE::CHARACTER_COMPONENT: ReturnValue = new CharacterComponent(); break;
	case Enums::ECOMPONENT_TYPE::DESTRUCTABLE_COMPONENT: ReturnValue = new DestroyableComponent(); break;
	case Enums::ECOMPONENT_TYPE::SKILL_COMPONENT: ReturnValue = new SkillComponent(); break;
	case Enums::ECOMPONENT_TYPE::INVENTORY_COMPONENT: ReturnValue = new InventoryComponent(); break;
	case Enums::ECOMPONENT_TYPE::UNKNOWN_107_COMPONENT: ReturnValue = new Component107(); break;
	case Enums::ECOMPONENT_TYPE::SPAWNER_COMPONENT: ReturnValue = new SpawnerComponent(); break;
	case Enums::ECOMPONENT_TYPE::BOUNCER_COMPONENT: ReturnValue = new BouncerComponent(); break;
	case Enums::ECOMPONENT_TYPE::SCRIPT_COMPONENT: ReturnValue = new ScriptComponent(); break;
	case Enums::ECOMPONENT_TYPE::PHANTOM_PHYSICS_COMPONENT: ReturnValue = new PhantomPhysicsComponent(); break;
	case Enums::ECOMPONENT_TYPE::SIMPLE_PHYSICS_COMPONENT: ReturnValue = new SimplePhysicsComponent(); break;
	case Enums::ECOMPONENT_TYPE::VENDOR_COMPONENT: ReturnValue = new VendorComponent(); break;
	case Enums::ECOMPONENT_TYPE::MISSION_NPC_COMPONENT: ReturnValue = new MissionOfferComponent(); break;
	case Enums::ECOMPONENT_TYPE::BASE_COMBAT_AI_COMPONENT: ReturnValue = new BaseCombatAIComponent(); break;
	case Enums::ECOMPONENT_TYPE::SCRIPTED_ACTIVITY_COMPONENT: ReturnValue = new ScriptedActivityComponent(); break;
	case Enums::ECOMPONENT_TYPE::REBUILD_COMPONENT: ReturnValue = new QuickbuildComponent(); break;

	// These are sub components that don't actually have a ID but are used by other components
	case (Enums::ECOMPONENT_TYPE)117: ReturnValue = new StatsComponent(); break;

	default: return nullptr;
	}

	ReturnValue->Owner = Owner;

	return ReturnValue;
}