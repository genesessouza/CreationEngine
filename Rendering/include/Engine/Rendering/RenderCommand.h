#pragma once

#include "Array/Array.h"

#include "Engine/Rendering/Renderer.h"

namespace Engine::Rendering
{
	class RenderCommand
	{
	public:
		inline static void SetClearColor(const glm::vec4& color)
		{
			s_Renderer->SetClearColor(color);
		}

		inline static void Clear()
		{
			s_Renderer->Clear();
		}

		inline static void DrawIndexed(const std::shared_ptr<Engine::Rendering::Array::VertexArray>& vertexArray)
		{
			s_Renderer->DrawIndexed(vertexArray);
		}
	private:
		static Renderer* s_Renderer;
	};
}