#pragma once

#include "../Component.h"
#include "../Systems/Scripts/CppScript.h"

class ScriptComponent : public Component {
private:

public:

	LWONameValueGroup NetworkedConfig = LWONameValueGroup();

	CppScript* Script = nullptr;

	void Start(uint32_t ComponentID) override {
		if (ComponentID == -1) return;
		GET_ROW_BY_ID(Owner->m_Server->m_CDClient, ScriptComponent, ComponentID);
		if (Row.script_name == "") return;
		Logger::Log("Game", "Loaded script " + Row.script_name);
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		bs->Write(Script != nullptr);
		if (Script != nullptr) {
			NetworkedConfig.Serialize(bs);
		}
	}

	constexpr static uint32_t GetID() {
		return (uint32_t)Enums::ECOMPONENT_TYPE::SCRIPT_COMPONENT;
	}
};