#pragma once
#include "Core.h"

namespace Cobble
{
	class COBBLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be defined inside on clientside
	Application* CreateApplication();
}
