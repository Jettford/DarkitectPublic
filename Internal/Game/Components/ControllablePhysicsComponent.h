#pragma once

#include <PxPhysicsAPI.h>

#include <Common/Structs/NiPoint3.h>
#include <Common/Structs/NiQuaternion.h>

#include "../Component.h"

class ControllablePhysicsComponent : public Component {
private:

public:
	bool m_IsInJetpackMode = false;
	uint32_t m_JetpackEffectID;
	bool m_JetpackFlying;
	bool m_JetpackBypassChecks;

	bool m_DirtyPosition = true;

	NiPoint3 m_Position;
	NiQuaternion m_Rotation;

	bool m_IsOnGround = true;
	bool m_IsOnRail = false;

	bool m_DirtyVelocity = true;
	NiPoint3 m_Velocity;

	bool m_DirtyAngularVelocity = true;
	NiPoint3 m_AngularVelocity;

	void Start(uint32_t ComponentID) override {
		m_Position = Owner->m_Server->m_LUZ.SpawnPos;
		m_Rotation = Owner->m_Server->m_LUZ.SpawnRot;

		physx::PxDefaultErrorCallback DefaultErrorCallback;
		physx::PxDefaultAllocator DefaultAllocatorCallback;

		physx::PxFoundation* mFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, DefaultAllocatorCallback, DefaultErrorCallback);
	}

	void ReadPositionUpdate(RakNet::BitStream* bs) {
		bs->Read<NiPoint3>(m_Position);
		bs->Read<NiQuaternion>(m_Rotation);
		bs->Read(m_IsOnGround);
		bs->Read(m_IsOnRail);
		if (bs->ReadBit()) {
			m_Velocity = bs->Read<NiPoint3>().second;
		}
		else { m_Velocity = NiPoint3(); }
		if (bs->ReadBit()) {
			m_AngularVelocity = bs->Read<NiPoint3>().second;
		}
		else { m_AngularVelocity = NiPoint3(); }

		m_DirtyPosition = true;

		this->Owner->IsDirty = true;
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		if (IsConstruction) {
			bs->Write(m_IsInJetpackMode);
			if (m_IsInJetpackMode) {
				bs->Write(m_JetpackEffectID);
				bs->Write(m_JetpackFlying);
				bs->Write(m_JetpackBypassChecks);
			}

			bs->Write0();
		}

		bs->Write0();
		bs->Write0();
		bs->Write0();

		bs->Write(m_DirtyPosition);
		if (m_DirtyPosition) {
			bs->Write(m_Position.X);
			bs->Write(m_Position.Y);
			bs->Write(m_Position.Z);

			bs->Write(m_Rotation.X);
			bs->Write(m_Rotation.Y);
			bs->Write(m_Rotation.Z);
			bs->Write(m_Rotation.W);

			bs->Write<bool>(m_IsOnGround);
			bs->Write<bool>(m_IsOnRail);

			bs->Write(m_DirtyVelocity);
			if (m_DirtyVelocity) {
				bs->Write(m_Velocity.X);
				bs->Write(m_Velocity.Y);
				bs->Write(m_Velocity.Z);
				m_DirtyVelocity = false;
			}

			bs->Write(m_DirtyAngularVelocity);
			if (m_DirtyAngularVelocity) {
				bs->Write(m_AngularVelocity.X);
				bs->Write(m_AngularVelocity.Y);
				bs->Write(m_AngularVelocity.Z);
				m_DirtyAngularVelocity = false;
			}

			bs->Write0();
			m_DirtyPosition = false;
		}

		if (!IsConstruction) bs->Write0();
	}

	constexpr static uint32_t GetID() {
		return (int)Enums::ECOMPONENT_TYPE::CONTROLABLE_PHYSICS_COMPONENT;
	}
};
