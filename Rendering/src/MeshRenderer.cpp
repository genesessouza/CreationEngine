#include "Engine/Rendering/MeshRenderer.h"
#include "Engine/Rendering/Renderer.h"

#include <Engine/Core/Log/Logger.h>

namespace Engine::Rendering
{
	void MeshRenderer::InitUniforms()
	{
		auto& shader = m_MeshMat->GetShader();
		shader->Bind();

		m_MeshUniforms.Model = shader->GetUniformLocation(shader->GetDefaultUniformNames(UniformType::Model));
		m_MeshUniforms.Normal = shader->GetUniformLocation(shader->GetDefaultUniformNames(UniformType::Normal));
	}

	void MeshRenderer::Draw(const Engine::Framework::Transform& transform) const
	{
		const auto& sceneData = Engine::Rendering::Renderer::GetSceneData();

		m_MeshMat->Bind();

		auto& shader = m_MeshMat->GetShader();

		Engine::Rendering::Renderer::UploadSceneUniforms(shader);

		if (transform.IsDirty())
		{
			shader->DefineUniformMat4(m_MeshUniforms.Model, transform.GetMatrix());
			//shader->DefineUniformMat3(m_MeshUniforms.Normal, glm::transpose(glm::inverse(glm::mat3(transform.GetMatrix()))));

			transform.ClearDirty();
		}

		m_Mesh->Bind();

		glDrawElements(GL_TRIANGLES, m_Mesh->GetIndexCount(), GL_UNSIGNED_INT, nullptr);
	}
}