#pragma once
#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Cobble\Events\ApplicationEvent.h"
#include "Cobble\Events\KeyEvent.h"
#include "Cobble\Events\MouseEvent.h"
#include "Cobble\Events\Event.h"

namespace Cobble
{
	struct Vector4
	{
		float x = 0;
		float y = 0;
		float z = 0;
		float w = 0;
	};

	class COBBLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
		Vector4 m_BGColor;
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_Stack;

	private:
		static Application* s_Instance;
	};

	// to be defined inside on clientside
	Application* CreateApplication();
}
