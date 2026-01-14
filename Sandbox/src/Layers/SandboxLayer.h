#include <glad/glad.h>

class SandboxLayer : public Engine::Core::Layer::Layer
{
public:
	SandboxLayer()
		: Layer("Sandbox")
	{
		glEnable(GL_DEPTH_TEST);
	}

	void OnAttach() override
	{
		CRTN_LOG_INFO("SandboxLayer attached");
	}

	void OnUpdate(float deltaTime) override
	{
		//CRTN_LOG_INFO("SandboxLayer update");
		CRTN_LOG_INFO("FPS: %.2f", 1 / deltaTime);

		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OnEvent(Engine::Core::Event::Event& e) override
	{
		CRTN_LOG_INFO("SandboxLayer registered event: <%s>", e.ToString().c_str());
	}
};