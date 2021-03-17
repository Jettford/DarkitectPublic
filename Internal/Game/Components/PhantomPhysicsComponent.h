#pragma once

#include "../Component.h"

class PhantomPhysicsComponent : public Component {
private:
	bool DirtyPosition;
	bool DirtyPhysicsEffect;

	NiPoint3 Position;
	NiQuaternion Rotation;
public:
	void SetPosition(NiPoint3 Pos) {
		Position = Pos;
		DirtyPosition = true;
	}

	void SetRotation(NiQuaternion Rot) {
		Rotation = Rot;
		DirtyPosition = true;
	}

	void Start(uint32_t ComponentID) override {
		DirtyPosition = true;
		DirtyPhysicsEffect = true;
		Position = Owner->m_Position;
		Rotation = Owner->m_Rotation;
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		if (IsConstruction) DirtyPosition = true;
		bs->Write(DirtyPosition);
		if (DirtyPosition) {
			bs->Write(Position.X);
			bs->Write(Position.Y);
			bs->Write(Position.Z);

			bs->Write(Rotation.X);
			bs->Write(Rotation.Y);
			bs->Write(Rotation.Z);
			bs->Write(Rotation.W);
			DirtyPosition = false;
		}

		bs->Write(DirtyPhysicsEffect);
		if (DirtyPhysicsEffect) {
			bs->Write0();
			DirtyPhysicsEffect = false;
		}
	}

	constexpr static uint32_t GetID() {
		return (uint32_t)Enums::ECOMPONENT_TYPE::PHANTOM_PHYSICS_COMPONENT;
	}
};