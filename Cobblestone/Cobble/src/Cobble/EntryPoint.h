#pragma once

#ifdef CBB_PLATFORM_WINDOWS

extern Cobble::Application* Cobble::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Cobble::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Cobble Supprots Windows only. Go buy an actual pc, or uze a virtual machine.
#endif
