#pragma once

#include "Transform.h"

#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <memory>

namespace Engine::Framework
{
	class Camera
	{
	public:
		enum CameraType { Perspective };

		Camera() = default;

		const glm::mat4& GetViewMatrix() { return glm::inverse(m_Transform.GetMatrix()); }
		const glm::mat4& GetViewProjectionMatrix() { return m_ProjectionMatrix * GetViewMatrix(); }
	public:
		CameraType CameraType = CameraType::Perspective;
	protected:
		Transform m_Transform;
		glm::mat4 m_ProjectionMatrix = glm::mat4(1.0f);
		glm::mat4 m_ViewMatrix = glm::mat4(1.0f);
	};

	class PerspectiveCamera : public Camera
	{
	public:
		PerspectiveCamera(float fov, float aspectRatio, float nearClip, float farClip)
		{
			m_ProjectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip);
			m_ViewMatrix = glm::mat4(1.0f);

			CameraType = Perspective;
		}

		inline static std::shared_ptr<PerspectiveCamera> Create()
		{
			return std::make_shared<PerspectiveCamera>(45.0f, 800.0f / 600.0f, 0.1f, 50.0f);
		}

		inline void SetPerspectiveProjection(float fov, float aspectRatio, float nearClip, float farClip)
		{
			m_ProjectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip);
		}
	};
}