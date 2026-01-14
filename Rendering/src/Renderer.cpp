#include "Engine/Rendering/Renderer.h"
#include "Engine/Rendering/Array/Array.h"
#include "Engine/Rendering/RenderCommand.h"

#include "Engine/Framework/Camera.h"

#include <Engine/Core/Paths.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine::Rendering
{
	Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;
	Shader* Renderer::DebugShader = new Shader(ShaderFilepath "Debug.cshader");

	void Renderer::SetClearColor(const glm::vec4& color)
	{
		glEnable(GL_DEPTH_TEST);
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::BeginScene(const std::shared_ptr<Engine::Framework::Camera>& camera)
	{
		m_SceneData->ViewMatrix = camera->GetViewMatrix();
		m_SceneData->ViewProjectionMatrix = camera->GetViewProjectionMatrix();
	}

	void Renderer::Submit(const std::shared_ptr<Shader>& shader, 
		const std::shared_ptr<Engine::Rendering::Array::VertexArray>& vertexArray, 
		const glm::mat4& transform = glm::mat4(1.0f))
	{
		shader->Bind();

		shader->DefineUniformMat4(shader->GetDefaultUniformNames(UniformType::View), m_SceneData->ViewMatrix);
		shader->DefineUniformMat4(shader->GetDefaultUniformNames(UniformType::ViewProjection), m_SceneData->ViewProjectionMatrix);
		shader->DefineUniformMat4(shader->GetDefaultUniformNames(UniformType::Transform), transform);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);

		DebugShader->Bind();
		vertexArray->Bind();

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		glDrawElements(GL_TRIANGLES, (GLsizei)vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderer::DrawIndexed(const std::shared_ptr<Engine::Rendering::Array::VertexArray>& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, (GLsizei)vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderer::EndScene()
	{

	}
}