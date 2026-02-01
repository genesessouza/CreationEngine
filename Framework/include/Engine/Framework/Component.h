#pragma once

namespace Engine::Framework
{
    class GameObject;
    class Scene;

    class Component
    {
    public:
        Component() = default;
        virtual ~Component() = default;

        virtual void Init() {}

        bool IsEnabled() const { return m_IsEnabled; }
        void SetEnabled(bool value) { m_IsEnabled = value; }

        virtual void SetOwner(GameObject* owner) { m_Owner = owner; }
        virtual GameObject* GetOwner() const { return m_Owner; }

        virtual void OnUpdate() {}

        virtual void OnAddedToScene(Scene* scene) {};
        virtual void OnRemovedFromScene(Scene* scene) {};
    protected:
        GameObject* m_Owner = nullptr;

        bool m_IsEnabled = true;
    };
}