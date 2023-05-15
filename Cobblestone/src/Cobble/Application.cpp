#include "cpch.h"
#include "Application.h"
#include "Events/Event.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace Cobble
{
	#define BEF(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BEF(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		//EngineDebug_Trace("{0}", e);
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BEF(OnWindowClose));

		for (auto it = m_Stack.end(); it != m_Stack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_Stack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_Stack.PushOverlay(layer);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(108.0f / 255.0f, 135.0f / 255.0f, 155.0f / 255.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_Stack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

}