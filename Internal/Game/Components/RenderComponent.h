#pragma once

#include "../Component.h"

#include "../Entity.h"

struct Effect {
	std::string Name = "";
	uint32_t EffectID = 0;
	std::u16string Type = u"";
	float_t Scale = 1.0f;
	int64_t Secondary = 0;
};

class RenderComponent : public Component {
private:
	std::vector<Effect> CurrentEffects = std::vector<Effect>();
public:
	void Start(uint32_t ComponentID) override {
		
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		if (IsConstruction) {
			bs->Write<uint32_t>(CurrentEffects.size());
			for (const auto& item : CurrentEffects) {
				Utils::StringToBitStream<uint8_t>(bs, item.Name);
				bs->Write(item.EffectID);
				Utils::WStringToBitStream<uint8_t>(bs, item.Type);
				bs->Write(item.Scale);
				bs->Write(item.Secondary);
			}
		}
	}

	constexpr static uint32_t GetID() {
		return (int)Enums::ECOMPONENT_TYPE::RENDER_COMPONENT;
	}
};