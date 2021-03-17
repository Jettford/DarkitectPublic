#include "Entity.h"

void Entity::Serialize(RakNet::BitStream* bs, bool IsConstruction) {
	if (IsConstruction) {
		bs->Write<int64_t>(m_ObjectID);
		bs->Write<int32_t>(m_LOT);
		Utils::WStringToBitStream<uint8_t>(bs, m_Name);
		bs->Write<uint32_t>(m_TimeSinceCreatedOnServer);

		bs->Write0(); // Write Extra LNV data this isn't actually needed until properties

		bs->Write0(); // trigger_id?

		bs->Write(m_Spawner != 0);
		if (m_Spawner != 0) {
			bs->Write<LWOOBJID>(m_Spawner);
		}

		bs->Write(m_SpawnerNodeID != 0);
		if (m_SpawnerNodeID != 0) {
			bs->Write<uint32_t>(m_SpawnerNodeID);
		}

		bs->Write(m_ObjectScale != 1.0f);
		if (m_ObjectScale != 1.0f) {
			bs->Write<float>(m_ObjectScale);
		}

		bs->Write(m_ObjectWorldState != 0);
		if (m_ObjectWorldState != 0) {
			bs->Write<uint8_t>(m_ObjectWorldState);
		}

		bs->Write(m_GMLevel != 0);
		if (m_GMLevel != 0) {
			bs->Write<uint8_t>(m_GMLevel);
		}
	}

	bs->Write1();

	bs->Write(m_Parent != nullptr);
	if (m_Parent != nullptr) {
		bs->Write<LWOOBJID>(m_Parent->m_ObjectID);
		bs->Write0();
	}


	bs->Write(m_Children.size() != 0);
	if (m_Children.size() != 0) {
		bs->Write<uint16_t>(m_Children.size());
		for (auto item : m_Children) {
			bs->Write<LWOOBJID>(item->m_ObjectID);
		}
	}

	for (int i = 0; i < 27; i++) {
		for (auto item : m_Components) {
			if (item.first == ComponentOrder[i]) {
				if (item.second != nullptr) {
					item.second->Serialize(bs, IsConstruction);
				}
			}
		}
	}
	IsDirty = false;
}

template <class T>
Component* Entity::AddComponent() {
	auto component = CreateComponentByType(this, T::GetID());
	this->m_Components.insert({ T::GetID(), component });
	return component;
}

Component* Entity::AddComponentByType(uint32_t Type) {
	auto component = CreateComponentByType(this, Type);
	this->m_Components.insert({ Type, component });
	return component;
}

void Entity::HandleGM(Entity* Sender, uint16_t ID, ClientGameMessages::ClientGameMessage* GM) {
	for (const auto& item : m_Components) {
		for (const auto& handler : item.second->GMHandlers) {
			if (handler.first == ID) {
				Component::GMHandler gmhandler = handler.second;
				(item.second->*gmhandler)(Sender, GM);
			}
		}
	}
}

void Entity::Update() {
	for (const auto& item : m_Components) item.second->OnUpdate();

	// TODO: Work out if should be destructed 
}

Entity::Entity(GameServer* Server, uint32_t LOT, LWOOBJID ObjectID, std::u16string Name, LWONameValueGroup* Config, NiPoint3 Position = NiPoint3(), NiQuaternion Rotation = NiQuaternion()) : m_Server(Server), m_LOT(LOT), m_ObjectID(ObjectID), m_Name(Name), m_Config(Config), m_Position(Position), m_Rotation(Rotation) {
	CppSQLite3Statement stmt = Server->m_CDClient->compileStatement("SELECT * FROM ComponentsRegistry WHERE id = ?");
	stmt.bind(1, (int32_t)LOT);
	CppSQLite3Query rs = stmt.execQuery();
	while (!rs.eof()) {
		std::istringstream stream(rs.fieldValue("component_type"));
		uint32_t CompType;
		stream >> CompType;
		Component* comp = CreateComponentByType(this, CompType);
		if (comp == nullptr) { rs.nextRow(); continue; }
		uint32_t CompID = std::stoi(rs.fieldValue("component_id"));
		comp->Start(CompID);
		m_Components.insert({ std::stoi(rs.fieldValue("component_type")), comp });

		rs.nextRow();
	}
}

Entity::~Entity() {
	delete m_Config;
	delete ExtraInfo;
	for (const auto& item : m_Components) delete item.second;
}