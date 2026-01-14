#pragma once

#include <Engine/Core/Window.h>

#include <memory>

namespace Engine::Platform::Windows
{
	std::unique_ptr<Engine::Core::Window> WindowsWindowFactory(const Engine::Core::Window::WindowProps& props);
}