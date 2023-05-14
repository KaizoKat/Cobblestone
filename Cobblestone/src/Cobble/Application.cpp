#include "cpch.h"
#include "Application.h"
#include "../Events/ApplicationEvent.h"
#include "../Logging/Log.h"

namespace Cobble
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		Debug_Log(e);

		while (true)
		{

		}
	}
}