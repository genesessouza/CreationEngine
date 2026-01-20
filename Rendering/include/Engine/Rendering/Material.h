#pragma once

#include "Engine/Rendering/Shader.h"
#include "Engine/Rendering/Renderer.h"

#include <glm/ext/vector_float3.hpp>

namespace Engine::Rendering
{
	class Material
	{
	public:
		Material()
			: m_Shader(nullptr)
		{
		}

		virtual ~Material() = default;

		void Init()
		{
			m_Shader = Engine::Rendering::Shader::CreateDefaultShader();
			Engine::Rendering::Renderer::InitSceneUniforms(m_Shader);

			CRTN_CHECK_PTR(m_Shader);
		}

		inline void Bind() const 
		{
			CRTN_CHECK_PTR(m_Shader);
			m_Shader->Bind(); 
		}

		void SetColor(const glm::vec4& color) 
		{
			CRTN_CHECK_PTR(m_Shader);
			m_Shader->DefineUniformVec4(m_Shader->GetUniformLocation(m_Shader->GetDefaultUniformNames(UniformType::Color)), glm::vec4(color.r, color.g, color.b, color.a));
		}

		const std::shared_ptr<Shader>& GetShader()
		{
			CRTN_CHECK_PTR(m_Shader);
			return m_Shader;
		}

		static std::shared_ptr<Material> Create()
		{
			auto mat = std::make_shared<Material>();
			CRTN_CHECK_PTR(mat);

			return mat;
		}
	private:
		std::shared_ptr<Shader> m_Shader;
	};
}