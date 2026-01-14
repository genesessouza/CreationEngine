#include "Engine/Framework/Transform.h"

#include <glm/gtc/quaternion.hpp>

namespace Engine::Framework
{
	glm::mat4 Transform::BuildTransformRotationScale() const
	{
		glm::mat4 mat(1.0f);

		mat = glm::translate(mat, m_Position);
		mat *= glm::mat4_cast(glm::quat(m_Rotation));
		mat = glm::scale(mat, m_Scale);

		return mat;
	}

	const glm::mat4& Transform::GetMatrix()
	{
		if (m_MatrixUpdated)
		{
			m_CachedMatrix = BuildTransformRotationScale();
			m_MatrixUpdated = false;
		}
		return m_CachedMatrix;
	}
}