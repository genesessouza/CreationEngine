#include "Engine/Framework/Scene.h"

namespace Engine::Framework
{
	void Scene::AddObject(const std::shared_ptr<GameObject>& obj)
	{
		m_SceneObjects.push_back(obj);

		if (obj->GetType() == ObjectType::PointLight)
		{
			m_PointLights.push_back(static_cast<Engine::Framework::Lights::PointLight*>(obj.get()));
			Engine::Rendering::Renderer::MarkLightsDirty();
		}
	}

	void Scene::RemoveObject(const std::shared_ptr<GameObject>& obj)
	{
		std::erase(m_SceneObjects, obj);

		if (obj->GetType() == ObjectType::PointLight)
		{
			std::erase(m_PointLights, static_cast<Engine::Framework::Lights::PointLight*>(obj.get()));
			Engine::Rendering::Renderer::MarkLightsDirty();
		}
	}

	void Scene::Render()
	{
		Engine::Rendering::Renderer::BeginScene(m_SceneCamera, *this);

		for (auto& obj : m_SceneObjects)
			obj->Draw();

		Engine::Rendering::Renderer::EndScene();
	}
}