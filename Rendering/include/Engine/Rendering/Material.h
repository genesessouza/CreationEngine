#pragma once

#include "Shader.h"

#include <string>

#include <memory>

namespace Engine::Rendering
{
	class Material
	{
	public:
		Material(const std::string& name) : m_Name(name)
		{
			m_Shader = Shader::Create();

			m_BaseColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f); // White

			m_Color_uName = m_Shader->GetDefaultUniformNames(UniformType::Color);
			m_ColorOverrideBool_uName = m_Shader->GetDefaultUniformNames(UniformType::ColorOverride);

			SetColor(m_BaseColor);
		}

		static std::shared_ptr<Material> Create();

		std::shared_ptr<Shader>& GetShader() { return m_Shader; }

		void SetColor(const glm::vec4 color);
		const glm::vec4 GetColor(const std::string& name) const;

		void RenderLight(const glm::vec3 lightSourcePos, const glm::vec3 objectPos, const glm::vec3 viewPos);
	private:
		const std::string& m_Name;

		glm::vec4 m_BaseColor;
		std::string m_Color_uName;
		std::string m_ColorOverrideBool_uName;

		std::shared_ptr<Shader> m_Shader;
	};
}