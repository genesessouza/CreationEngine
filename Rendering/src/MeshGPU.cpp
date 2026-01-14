#include "Engine/Rendering/MeshGPU.h"

#include <Engine/Framework/Mesh.h>

namespace Engine::Rendering
{
	MeshGPU::MeshGPU(const Engine::Framework::Geometry::Mesh& mesh)
	{
		m_MeshVAO.Bind();

		m_MeshVBO.Create(
			mesh.vertices.data(),
			mesh.vertices.size() * sizeof(Engine::Framework::Geometry::Vertex)
		);

		m_MeshIBO.Create(
			mesh.indices.data(), // indices
			mesh.indices.size() // count
		);

		m_MeshVAO.AddVertexBuffer(std::make_shared<Engine::Platform::OpenGL::OpenGLVertexBuffer>(m_MeshVBO), Engine::Framework::Geometry::Vertex::GetLayout());
		m_MeshVAO.SetIndexBuffer(std::make_shared<Engine::Platform::OpenGL::OpenGLIndexBuffer>(m_MeshIBO));

		m_MeshVAO.Unbind();
	}

	void MeshGPU::Bind() const
	{
		m_MeshVAO.Bind();
	}
}