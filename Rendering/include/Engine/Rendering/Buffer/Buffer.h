#pragma once

#include <cstdint>

namespace Engine::Rendering::Buffer
{
	class VertexBuffer
	{
	public:
		static VertexBuffer* Create(const void* data, size_t sizeInBytes);

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
	};

	class IndexBuffer
	{
	public:
		static IndexBuffer* Create(const void* data, size_t size);

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual size_t GetCount() = 0;
	};
}