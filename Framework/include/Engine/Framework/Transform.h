#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Engine::Framework
{
	class Transform
	{
    public:
        Transform() 
            : m_Position(0.0f), m_Scale(1.0f), m_Orientation(1.0f, 0.0f, 0.0f, 0.0f), m_WorldMatrix(glm::mat4(1.0f))
        {
        }
        virtual ~Transform() = default;
        
        const glm::mat4& GetWorldMatrix() const;

        void SetPosition(const glm::vec3& pos, bool local = true);
        void SetRotation(const glm::vec3& newRotation, bool local = true);
        void SetScale(const glm::vec3& scale) { m_Scale = scale; MarkDirty(); }
        void Translate(const glm::vec3& delta, bool local = true);
        void Rotate(const glm::vec3& deltaAxis, bool local = true);

        const glm::vec3& GetPosition() const { return m_Position; }
        const glm::vec3& GetRotation() const { return m_Rotation; }
        const glm::quat& GetOrientation() const { return m_Orientation; }
        const glm::vec3& GetScale() const { return m_Scale; }

        bool WasModifiedThisFrame() const { return m_ModifiedThisFrame; }
        void ClearFrameFlag() { m_ModifiedThisFrame = false; }
    private:
        void MarkDirty();
        void Recalculate() const;
    private:
        glm::vec3 m_Position;
        glm::vec3 m_Rotation;
        glm::vec3 m_Scale;
        glm::quat m_Orientation;

        mutable glm::mat4 m_WorldMatrix;

        bool m_Dirty = true;
        bool m_ModifiedThisFrame = false;
    };
}