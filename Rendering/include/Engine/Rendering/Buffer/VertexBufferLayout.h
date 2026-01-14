#pragma once

#include <glad/glad.h>

#include <cstdint>
#include <string>
#include <vector>

namespace Engine::Rendering::Buffer
{
	struct VertexBufferElement {
		uint32_t index;
		uint32_t count;
		GLenum type;
		bool normalized;
		uint32_t offset;
	};

	class VertexBufferLayout {
	public:
		const std::vector<VertexBufferElement>& GetElements() const {
			return m_Elements;
		}

		uint32_t GetStride() const {
			return m_Stride;
		}

		void Add(uint32_t index, uint32_t count, GLenum type, bool normalized) {
			m_Elements.push_back({
				index,
				count,
				type,
				normalized,
				m_Stride
				});

			m_Stride += count * SizeOfGLType(type);
		}

		static uint32_t SizeOfGLType(GLenum type) {
			switch (type) {
			case GL_FLOAT: return 4;
			case GL_UNSIGNED_INT: return 4;
			case GL_UNSIGNED_BYTE: return 1;
			}
			return 0;
		}
	private:
		std::vector<VertexBufferElement> m_Elements;
		uint32_t m_Stride = 0;
	};
}