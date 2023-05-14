#pragma once

#ifdef CBB_PLATFORM_WINDOWS

extern Cobble::Application* Cobble::CreateApplication();

int main(int argc, char** argv)
{
	Cobble::Log::Init();
	EngineDebug_Log("Finalized Engine Loading");
	Debug_Log("Finalized Application Loading");
	auto app = Cobble::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Cobble Supprots Windows only. Go buy an actual pc, or use a virtual machine.
#endif
