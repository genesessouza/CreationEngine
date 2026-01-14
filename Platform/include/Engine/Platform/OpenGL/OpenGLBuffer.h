#pragma once

#include <Engine/Rendering/Buffer/Buffer.h>

namespace Engine::Platform::OpenGL
{
	class OpenGLVertexBuffer : public Engine::Rendering::Buffer::VertexBuffer
	{
	public:
		OpenGLVertexBuffer();
		OpenGLVertexBuffer(const void* data, size_t sizeInBytes);

		~OpenGLVertexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;
	private:
		uint32_t m_RendererId;

		const void* m_Data;
		size_t m_SizeInBytes;
	};

	class OpenGLIndexBuffer : public Engine::Rendering::Buffer::IndexBuffer
	{
	public:
		OpenGLIndexBuffer();
		OpenGLIndexBuffer(const void* data, size_t size);

		~OpenGLIndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

		size_t GetCount() { return m_Count; }
	private:
		uint32_t m_RendererId;
		size_t m_Count;
	};
}