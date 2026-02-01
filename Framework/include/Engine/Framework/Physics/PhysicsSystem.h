#pragma once

#include "Engine/Framework/Scene.h"

#include "Engine/Framework/Physics/Collider.h"
#include "Engine/Framework/Physics/Gravity.h"
#include "Engine/Framework/Physics/PhysicsComponent.h"

#include <glm/glm.hpp>
#include <iostream>

namespace Engine::Framework::Physics
{
	class PhysicsSystem
	{
	public:
		PhysicsSystem() = default;
		virtual ~PhysicsSystem() = default;

		static bool AABBOverlap(const Collider::AABB& a, const Collider::AABB& b);

		static void UpdateCaches(const Scene& scene);
		static void Step(float dt);

		static void ResolveCollision(PhysicsComponent* a, PhysicsComponent* b, Collider::ContactManifold& m);
	private:
		inline static std::vector<Collider*> m_SceneColliders;
		inline static std::vector<PhysicsComponent*> m_ScenePhysicsComps;
	};
}