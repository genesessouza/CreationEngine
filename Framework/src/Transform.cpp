#include "Engine/Framework/Transform.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Engine::Framework
{
	void Transform::Recalculate() const
	{
		glm::mat4 translation = glm::translate(glm::mat4(1.0f), m_Position);
		glm::mat4 rotation = glm::mat4_cast(m_Orientation);
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), m_Scale);

		m_WorldMatrix = translation * rotation * scale;
	}

	const glm::mat4& Transform::GetWorldMatrix() const
	{
		if (m_Dirty)
			Recalculate();

		return m_WorldMatrix;
	}

	void Transform::SetPosition(const glm::vec3& pos, bool local)
	{
		if (local)
			m_Position = m_Orientation * pos;
		else
			m_Position = pos;

		MarkDirty();
	}

	void Transform::SetRotation(const glm::vec3& rot, bool local)
	{
		m_Rotation = rot;
		m_Orientation = m_Orientation = glm::quat(glm::radians(m_Rotation));
	
		MarkDirty();
	}

	void Transform::Translate(const glm::vec3& delta, bool local)
	{
		if (local)
			m_Position += m_Orientation * delta;
		else
			m_Position += delta;

		MarkDirty();
	}

	void Transform::Rotate(const glm::vec3& deltaDegrees, bool local)
	{
		glm::quat deltaQuat = glm::quat(glm::radians(deltaDegrees));

		if (local)
			m_Orientation = m_Orientation * deltaQuat;
		else
			m_Orientation = deltaQuat * m_Orientation;

		m_Rotation = glm::degrees(glm::eulerAngles(m_Orientation));

		MarkDirty();
	}

	void Transform::MarkDirty()
	{
		m_Dirty = true;
		m_ModifiedThisFrame = true;
	}
}