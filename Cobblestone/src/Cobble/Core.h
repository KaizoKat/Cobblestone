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

#ifdef HZ_ENABLE_ASSERTS
	#define CBB_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CBB_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CBB_ASSERT(x, ...)
	#define CBB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x)