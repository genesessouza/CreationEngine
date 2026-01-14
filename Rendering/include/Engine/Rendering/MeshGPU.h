#pragma once

#include "Engine/Platform/OpenGL/OpenGLArray.h"

#include <Engine/Framework/Mesh.h>

namespace Engine::Rendering
{
	class MeshGPU
	{
	public:
		MeshGPU(const Engine::Framework::Geometry::Mesh& mesh);

		void Bind() const;

		size_t GetIndexCount() { return m_MeshIBO.GetCount(); }
	private:
		Engine::Platform::OpenGL::OpenGLVertexArray m_MeshVAO;
		Engine::Platform::OpenGL::OpenGLVertexBuffer m_MeshVBO;
		Engine::Platform::OpenGL::OpenGLIndexBuffer m_MeshIBO;
	};
}