#pragma once

#include "Engine/Framework/Transform.h"

#include <Engine/Rendering/MeshGPU.h>
#include <Engine/Rendering/MeshRenderer.h>

#include <memory>

namespace Engine::Framework
{
	enum class ObjectType
	{
		Mesh,
		PointLight,
		Null
	};

	class GameObject
	{
	public:
		GameObject() : m_MeshRenderer(nullptr), m_Type(ObjectType::Mesh)
		{
		}

		virtual ~GameObject() = default;

		ObjectType GetType() const { return m_Type; }

		void Init()
		{
			m_MeshRenderer = Engine::Rendering::MeshRenderer::Create();

			if (m_MeshRenderer)
				m_MeshRenderer->Init();
		}

		inline void Draw() const
		{
			if (m_MeshRenderer)
				m_MeshRenderer->Draw(m_Transform);
		}

		static std::shared_ptr<GameObject> Create() { return std::make_shared<GameObject>(); }
	public:
		Transform m_Transform;
		std::shared_ptr<Engine::Rendering::MeshRenderer> m_MeshRenderer;
	protected:
		GameObject(ObjectType type) : m_Type(type) {}
	private:
		ObjectType m_Type;
	};
}