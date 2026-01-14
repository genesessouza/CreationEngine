#include "Engine/Platform/Windows/WindowsWindowFactory.h"
#include "Engine/Platform/Windows/WindowsWindow.h"

namespace Engine::Platform::Windows
{
    std::unique_ptr<Engine::Core::Window> WindowsWindowFactory(const Engine::Core::Window::WindowProps& props)
    {
        return std::make_unique<WindowsWindow>(props);
    }
}