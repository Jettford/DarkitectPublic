#pragma once

#include "../Component.h"

class SimplePhysicsComponent : public Component {
private:
	bool DirtyPosition;
	bool DirtyLinearAndAngularVelocity;

	NiPoint3 Position;
	NiQuaternion Rotation;

	NiPoint3 LinearVelocity;
	NiPoint3 AngularVelocity;
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
		Position = Owner->m_Position;
		Rotation = Owner->m_Rotation;
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		if (IsConstruction) {
			bs->Write0();
			bs->Write<int32_t>(0);
		}

		bs->Write(DirtyLinearAndAngularVelocity);
		if (DirtyLinearAndAngularVelocity) {
			bs->Write(LinearVelocity);
			bs->Write(AngularVelocity);
		}

		bs->Write1(); // Write air speed
		bs->Write<uint32_t>(5);

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
	}

	constexpr static uint32_t GetID() {
		return (uint32_t)Enums::ECOMPONENT_TYPE::SIMPLE_PHYSICS_COMPONENT;
	}
};