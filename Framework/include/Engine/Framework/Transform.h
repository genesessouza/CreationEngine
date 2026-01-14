#pragma once

#include <glm/glm.hpp>

namespace Engine::Framework
{
	class Transform
	{
	public:
		const glm::vec3 GlobalForward() const { return glm::normalize(glm::vec3(glm::mat4(1.0f) * glm::vec4(0, 0, -1, 0))); }
		const glm::vec3 GlobalRight() const { return glm::normalize(glm::vec3(glm::mat4(1.0f) * glm::vec4(1, 0, 0, 0))); }
		const glm::vec3 GlobalUp() const { return glm::normalize(glm::vec3(glm::mat4(1.0f) * glm::vec4(0, 1, 0, 0))); }

		const glm::vec3 LocalForward() const { return glm::normalize(glm::vec3(m_RotationMatrix * glm::vec4(0, 0, -1, 0))); }
		const glm::vec3 LocalRight() const { return glm::normalize(glm::vec3(m_RotationMatrix * glm::vec4(1, 0, 0, 0))); }
		const glm::vec3 LocalUp() const { return glm::normalize(glm::vec3(m_RotationMatrix * glm::vec4(0, 1, 0, 0))); }

		const void SetPosition(const glm::vec3& position) { m_Position = position; m_MatrixUpdated = true; }
		const glm::vec3& GetPosition() const { return m_Position; }

		const void SetRotation(const glm::vec3& rotation) { m_Rotation = rotation; m_MatrixUpdated = true; }
		const glm::vec3& GetRotation() const { return m_Rotation; }

		const virtual void SetScale(const glm::vec3& scale) { m_Scale = scale; m_MatrixUpdated = true; }
		const glm::vec3& GetScale() const { return m_Scale; }

		const float& GetMovementSpeed() const { return m_MovementSpeed; }
		const void SetMovementSpeed(const float& movementSpeed) { m_MovementSpeed = movementSpeed; }

		const float& GetRotationDegreesPerSec() const { return m_RotDegreesPerSec; }
		const void SetRotationDegreesPerSec(const float& rotationDegreesPerSec) { m_RotDegreesPerSec = rotationDegreesPerSec; }

		const void SetPositionAxises(const glm::vec3& right, const glm::vec3& up, const glm::vec3& forward) { m_Right = right; m_Up = up; m_Forward = forward; }
		const void SetRotationAxises(const glm::vec3& right, const glm::vec3& up, const glm::vec3& forward) { m_Right = right; m_Up = up; m_Forward = forward; }

		glm::mat4 BuildTransformRotationScale() const;

		const glm::mat4& GetMatrix();
	protected:
		glm::mat4 m_RotationMatrix = glm::mat4(1.0f);

		glm::vec3 m_Pitch = {};
		glm::vec3 m_Yaw = {};
		glm::vec3 m_Roll = {};

		glm::vec3 m_Right = {};
		glm::vec3 m_Up = {};
		glm::vec3 m_Forward = {};

		glm::vec3 m_Position = { 0, 0, 0 };
		glm::vec3 m_Rotation = { 0, 0, 0 };
		glm::vec3 m_Scale = { 1, 1, 1 };

		float m_MovementSpeed = 0.0f;
		float m_RotDegreesPerSec = 0.0f;
	private:
		bool m_MatrixUpdated = false;
		glm::mat4 m_CachedMatrix = glm::mat4(1.0f);
	};
}