#include "Engine/Rendering/Buffer/Buffer.h"

#include <Engine/Platform/OpenGL/OpenGLBuffer.h>
#include <Engine/Core/Log/Logger.h>

namespace Engine::Rendering::Buffer
{
	VertexBuffer* VertexBuffer::Create(const void* data, size_t sizeInBytes)
	{
		Engine::Platform::OpenGL::OpenGLVertexBuffer* openGLVertexBuffer = new Engine::Platform::OpenGL::OpenGLVertexBuffer(data, sizeInBytes);
		CRTN_ASSERT(openGLVertexBuffer, "OpenGL Vertex Buffer is null!");
		return openGLVertexBuffer;
	}

	IndexBuffer* IndexBuffer::Create(const void* data, size_t size)
	{
		Engine::Platform::OpenGL::OpenGLIndexBuffer* openGLIndexBuffer = new Engine::Platform::OpenGL::OpenGLIndexBuffer(data, size);
		CRTN_ASSERT(openGLIndexBuffer, "OpenGL Index Buffer is null!");
		return openGLIndexBuffer;
	}
}