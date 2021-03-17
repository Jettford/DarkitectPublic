#pragma once

#include <tinyxml2/tinyxml2.h>

#include <Game/Components/CharacterComponent.h>

#include <vector>

namespace Characters {
	class CharacterXML {
	private:
		std::string Value;
	
	public:

		void GenerateCharacterXML(CharacterComponent* CharComp) {
			tinyxml2::XMLDocument XMLDoc = tinyxml2::XMLDocument();
			auto OBJRoot = XMLDoc.NewElement("obj");
			OBJRoot->SetAttribute("v", "1");
			XMLDoc.LinkEndChild(OBJRoot);

			// Buff Node

			auto buff = OBJRoot->InsertNewChildElement("buff");

			// Skill node

			auto skil = OBJRoot->InsertNewChildElement("skil");

			// destroyable/stats node

			auto dest = OBJRoot->InsertNewChildElement("dest");

			dest->SetAttribute("am", ""); // max armour
			dest->SetAttribute("ac", ""); // current armour
			dest->SetAttribute("hc", ""); // current health
			dest->SetAttribute("hm", ""); // max health
			dest->SetAttribute("ic", ""); // current imagination
			dest->SetAttribute("im", ""); // max imagination

			// inventory node

			auto inv = OBJRoot->InsertNewChildElement("inv");

			inv->SetAttribute("csl", ""); // consumable slot template

			{
				// bag array
				auto bag = inv->InsertNewChildElement("bag");
				
				{
					std::vector<std::pair<uint32_t, uint32_t>> SlotsType = std::vector<std::pair<uint32_t, uint32_t>>();

					for (const auto& item : SlotsType) {
						auto b = bag->InsertNewChildElement("b");
						b->SetAttribute("t", item.second);
						b->SetAttribute("m", item.first);
					}
				}

				auto grps = inv->InsertNewChildElement("grps");

				
			}

			XMLDoc.Print();
		}
	};
}