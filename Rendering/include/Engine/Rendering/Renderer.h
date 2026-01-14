#pragma once

#include "Shader.h"

#include "Array/Array.h"

#include "Engine/Framework/Camera.h"

#include <glm/ext/vector_float4.hpp>

namespace Engine::Rendering
{
	class Renderer
	{
	public:
		void SetClearColor(const glm::vec4& color);
		void Clear();

		static void BeginScene(const std::shared_ptr<Engine::Framework::Camera>& camera);
		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<Engine::Rendering::Array::VertexArray>& vertexArray, const glm::mat4& transform);
		static void EndScene();

		void DrawIndexed(const std::shared_ptr<Engine::Rendering::Array::VertexArray>& vertexArray);
		static Shader* DebugShader;
	private:
		struct SceneData
		{
			glm::mat4 ViewMatrix;
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};
}