#include "Engine/Core/Application.h"
#include "Engine/Core/Window.h"

#include <Engine/Core/Event/WindowEvent.h>

#include <format>

namespace Engine::Core
{
	static Application* s_Instance = nullptr;

	Application::Application()
	{
		CRTN_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		m_ShowFps = true;

		m_Window = Window::Create(Window::WindowProps{});
		m_Window->SetEventCallback([this](Event::Event& e) { OnEvent(e); });
		m_Window->SetVSync(false);

		m_Running = true;
	}

	Application::~Application()
	{
		s_Instance = nullptr;
	}

	void Application::PushLayer(Layer::Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer::Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::Run()
	{
		while (m_Running)
		{
			float deltaTime = Time::Time::GetDeltaTime();

			static float currentTime = 0;
			currentTime += deltaTime;

			OnUpdate();
			m_Window->OnUpdate();

			if (currentTime >= 0.008)
			{
				for (Layer::Layer* layer : m_LayerStack)
					layer->OnUpdate(deltaTime);

				currentTime = 0;
			}
		}
	}

	Application& Application::Get()
	{
		return *s_Instance;
	}

	void Application::OnUpdate()
	{
		// Nothing for now
	}

	void Application::OnEvent(Event::Event& e)
	{
		Event::EventDispatcher dispatcher(e);
		dispatcher.Dispatch<Event::WindowCloseEvent>(
			BIND_EVENT_FN(Application::OnWindowClose)
		);

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.Handled)
				break;
		}

		CRTN_LOG_TRACE("Application registered event: <%s>", e.ToString().c_str());
	}

	bool Application::OnWindowClose(Event::WindowCloseEvent& e)
	{
		m_Running = false;
		return false;
	}
}