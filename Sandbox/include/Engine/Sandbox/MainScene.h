#pragma once

#include <Engine/Framework/Scene.h>
#include <Engine/Framework/MeshLibrary.h>
#include <Engine/Rendering/MeshRenderer.h>
#include <Engine/Framework/Light.h>

#include <Engine/Framework/Physics/Collider.h>
#include <Engine/Framework/Physics/PhysicsComponent.h>

#include <glm/gtc/quaternion.hpp>

#include <memory>

namespace Engine::Sandbox
{
	class MainScene : public Engine::Framework::Scene
	{
	public:
		virtual ~MainScene() = default;

		void Init()
		{
			Scene::Init();

			// POINT LIGHTS 
			/*{
				auto redLightGo = Engine::Framework::Entity::CreateEmpty("[Entity] Red Light");
				redLightGo->GetTransform().SetPosition({ 0.0f, 1.0f, -3.0f });

				auto redLight = redLightGo->AddComponent<Engine::Framework::Lights::PointLight>();
				redLight->SetIntensity(10.0f);
				redLight->SetColor({ 1.0f, 0.0f, 0.0f, 1.0f });

				AddPointLight(redLight);
				AddEntity(std::move(redLightGo));

				auto greenLightGo = Engine::Framework::Entity::CreateEmpty("[Entity] Green Light");
				greenLightGo->GetTransform().SetPosition({ -3.0f, 1.0f, 0.0f });

				auto greenLight = greenLightGo->AddComponent<Engine::Framework::Lights::PointLight>();
				greenLight->SetIntensity(10.0f);
				greenLight->SetColor({ 0.0f, 1.0f, 0.0f, 1.0f });

				AddPointLight(greenLight);
				AddEntity(std::move(greenLightGo));

				auto blueLightGo = Engine::Framework::Entity::CreateEmpty("[Entity] Blue Light");
				blueLightGo->GetTransform().SetPosition({ 3.0f, 1.0f, 0.0f });

				auto blueLight = blueLightGo->AddComponent<Engine::Framework::Lights::PointLight>();
				blueLight->SetIntensity(10.0f);
				blueLight->SetColor({ 0.0f, 0.0f, 1.0f, 1.0f });

				AddPointLight(blueLight);
				AddEntity(std::move(blueLightGo));
			}*/

			// SCENE OBJECTS
			{
				// GROUND
				m_GroundCube = Engine::Framework::Entity::CreateWithCollider("[Entity] Ground Cube", Engine::Framework::MeshLibrary::InstantiateCube());
				m_GroundCube->GetTransform().SetScale({ 10.0f, 0.3f, 10.0f });
				m_GroundCube->GetComponent<Engine::Rendering::MeshRenderer>()->GetMaterial()->SetColor(glm::vec4(0.0f, 0.05f, 1.0f, 1.0f)); // Sets ground color to blue

				AddEntity(std::move(m_GroundCube));

				// DEFAULT CUBE
				m_DefaultCube = Engine::Framework::Entity::CreateWithPhysics("[Entity] Default Cube", Engine::Framework::MeshLibrary::InstantiateCube());
				m_DefaultCube->GetTransform().SetPosition({ 3.0f, 3.0f, 0.0f });
				m_DefaultCube->GetTransform().SetRotation({ 15.0f, 0.0f, 60.0f });
				m_DefaultCube->GetComponent<Engine::Rendering::MeshRenderer>()->GetMaterial()->SetColor(glm::vec4(0.9f, 0.05f, 0.05f, 1.0f)); // Sets color to red

				AddEntity(std::move(m_DefaultCube));

				// SPHERE
				m_DefaultSphere = Engine::Framework::Entity::CreateWithPhysics("[Entity] Default Sphere", Engine::Framework::MeshLibrary::InstantiateSphere());
				m_DefaultSphere->GetTransform().SetPosition({ -3.0f, 3.0f, 0.0f });
				m_DefaultSphere->GetComponent<Engine::Rendering::MeshRenderer>()->GetMaterial()->SetColor(glm::vec4(0.05f, 0.9f, 0.05f, 1.0f)); // Sets color to green

				AddEntity(std::move(m_DefaultSphere));
			}
		}

		Engine::Framework::Physics::PhysicsComponent* GetCubePhysics() {
			if (m_DefaultCube) {
				return m_DefaultCube->GetComponent<Engine::Framework::Physics::PhysicsComponent>();
			}
			return nullptr;
		}
	private:
		std::unique_ptr<Engine::Framework::Entity> m_GroundCube;
		std::unique_ptr<Engine::Framework::Entity> m_DefaultCube;
		std::unique_ptr<Engine::Framework::Entity> m_DefaultSphere;
	};
}