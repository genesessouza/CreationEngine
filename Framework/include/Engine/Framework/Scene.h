#pragma once

#include "Engine/Framework/Camera.h"

#include "Simpleton/Geometry/GameObject.h"

#include "Engine/Core/Layer/Layer.h"

#include "Engine/Rendering/RenderCommand.h"
#include "Engine/Rendering/Array/Array.h"

#include <Engine/Core/Time/Time.h>

namespace Engine::Framework
{
	class Scene : public Engine::Core::Layer::Layer
	{
	public:
		Scene();
		void InitObjects();

		void OnUpdate(Engine::Core::Time::Time deltaTime) override;
		void OnEvent(Engine::Core::Event::Event& event) override;
	protected:
		std::shared_ptr<Quad> m_GroundPlane;
		std::shared_ptr<Camera> m_SceneCamera;
		std::shared_ptr<GameObject> m_DefaultGameObject;
	};

	class Scene3D : public Scene
	{
	public:
		Scene3D()
		{
			m_ScenePerspCamera = PerspectiveCamera::Create();
			m_SceneCamera = m_ScenePerspCamera;

			m_DefaultCube.reset(new Cube());
			m_DefaultGameObject = m_DefaultCube;

			m_GroundPlane.reset(new Quad());

			InitObjects();
		}

		inline static Scene3D* Create() { return new Scene3D(); }
	private:
		std::shared_ptr<PerspectiveCamera> m_ScenePerspCamera;
		std::shared_ptr<Cube> m_DefaultCube;
	};
}