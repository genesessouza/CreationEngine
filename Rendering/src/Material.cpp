#include "Engine/Rendering/Material.h"

namespace Engine::Rendering
{
	std::shared_ptr<Material> Material::Create()
	{
		return std::make_shared<Material>("DefaultMaterial");
	}

	void Material::SetColor(const glm::vec4 color)
	{
		m_BaseColor = color;
		m_Shader->DefineUniformVec4(m_Color_uName, color);
		m_Shader->DefineUniformBool(m_ColorOverrideBool_uName, true);
	}

	const glm::vec4 Material::GetColor(const std::string& colorUniformName) const
	{
		return m_Shader->GetUniformVec4(colorUniformName);
	}

	void Material::RenderLight(const glm::vec3 lightSourcePos, const glm::vec3 objectPos, const glm::vec3 cameraPos)
	{
		m_Shader->DefineUniformVec3("u_LightDir", lightSourcePos - objectPos);
		m_Shader->DefineUniformVec3("u_LightColor", glm::vec3(1.0f));
		//m_Shader->DefineUniformVec3("u_ViewPos", cameraPos); // for specular
	}
}