#pragma once

#include "Transform.h"
#include "Engine/Framework/Geometry/Geometry.h"

#include <Engine/Rendering/MeshGPU.h>

#include <memory>

namespace Engine::Framework
{
    class GameObject
    {
    public:
		GameObject(std::shared_ptr<Engine::Rendering::MeshGPU> mesh) 
            : m_Mesh(mesh) {}

		glm::mat4 GetModelMatrix() const { return m_ModelMatrix; }
		void UpdateModelMatrix() { m_ModelMatrix = m_Transform.GetMatrix(); }

        const Engine::Rendering::MeshGPU& GetMesh() const { return *m_Mesh; }
    public:
        Transform m_Transform;
    private:
		glm::mat4 m_ModelMatrix = glm::mat4(1.0f);
        std::shared_ptr<Engine::Rendering::MeshGPU> m_Mesh;
    };
}