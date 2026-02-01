#include "Engine/Framework/Physics/PhysicsComponent.h"

#include "Engine/Framework/GameObject.h"
#include "Engine/Framework/Physics/Collider.h"

namespace Engine::Framework::Physics
{
	void PhysicsComponent::CalculateInertiaTensor()
	{
		auto coll = m_Owner->GetComponent<Collider>();
		glm::vec3 halfSize = coll->GetHalfSize();

		float x2 = (halfSize.x * 2.0f) * (halfSize.x * 2.0f);
		float y2 = (halfSize.y * 2.0f) * (halfSize.y * 2.0f);
		float z2 = (halfSize.z * 2.0f) * (halfSize.z * 2.0f);

		float fraction = 1.0f / 12.0f;

		glm::mat3 inertiaTensor(0.0f);
		inertiaTensor[0][0] = fraction * m_Mass * (y2 + z2);
		inertiaTensor[1][1] = fraction * m_Mass * (x2 + z2);
		inertiaTensor[2][2] = fraction * m_Mass * (x2 + y2);

		if (inertiaTensor[0][0] > 0.0001f)
			m_InvInertiaTensorLocal = glm::inverse(inertiaTensor);
		else
			m_InvInertiaTensorLocal = glm::mat3(0.0f);

		m_InvInertiaTensorLocal = glm::inverse(inertiaTensor);
	}

	void PhysicsComponent::UpdateInertiaTensorWorld()
	{
		if (IsStatic())
		{
			m_InvInertiaTensorWorld = glm::mat3(0.0f);
			return;
		}

		glm::quat q = GetOwner()->GetTransform().GetOrientation();

		glm::mat3 R = glm::toMat3(q);
		m_InvInertiaTensorWorld = R * m_InvInertiaTensorLocal * glm::transpose(R);
	}
}