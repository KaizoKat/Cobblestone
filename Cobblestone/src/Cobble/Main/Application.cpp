#include "cpch.h"
#include "Application.h"
#include "Log.h"
#include "Input.h"

#include <glad/glad.h>
#include <imgui.h>

namespace Cobble
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		CBB_CORE_ASSERT(!s_Instance, "Application allready exists.");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BindFunction(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		//EngineDebug_Trace("{0}", e);
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BindFunction(OnWindowClose));

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
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_Stack.PushOverlay(layer);
		layer->OnAttach();
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
			glClearColor(m_BGColor.x,m_BGColor.y,m_BGColor.z,m_BGColor.w);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_Stack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

}