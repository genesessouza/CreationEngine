#pragma once

#include "Engine/Core/Window.h"

#include <Engine/Rendering/GraphicsContext.h>

struct GLFWwindow;

namespace Engine::Platform::Windows
{
    class WindowsWindow : public Engine::Core::Window 
    {
    public:
        WindowsWindow(const Engine::Core::Window::WindowProps& props);
        ~WindowsWindow() override;

        void SetEventCallback(const EventCallbackFn& callback) override;

		void Init(const Window::WindowProps props) override;

        void OnUpdate() override;

        uint32_t GetWidth() const override;
        uint32_t GetHeight() const override;

        void SetTitle(const std::string& title) override;
        void Resize(uint32_t width, uint32_t height) override;

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

        bool ShouldClose() const override;
    private:
        GLFWwindow* m_Window = nullptr;
        Engine::Rendering::GraphicsContext* m_Context;

        EventCallbackFn m_EventCallback;
    };
}