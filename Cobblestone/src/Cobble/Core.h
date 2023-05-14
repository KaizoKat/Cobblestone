#pragma once

#ifdef CBB_PLATFORM_WINDOWS
	#ifdef CBB_BUILD_DLL
		#define COBBLE_API __declspec(dllexport)
	#else
		#define COBBLE_API __declspec(dllimport)
	#endif // HZ_BUILD_DLL
#else
#error Cobble Supprots Windows only. Go buy an actual pc, or use a virtual machine.
#endif