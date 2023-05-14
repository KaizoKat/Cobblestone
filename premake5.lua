workspace "Cobblestone"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Cobblestone"
	location "Cobblestone"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "cpch.h"
	pchsource "Cobblestone/src/cpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/Vendor/spdlog/include"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CBB_PLATFORM_WINDOWS",
			"CBB_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CBB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CBB_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "CBB_DISTRIBUTION"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Cobblestone/Vendor/spdlog/include",
		"Cobblestone/src"
	}

	links
	{
		"Cobblestone"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CBB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Distribution"
		defines "HZ_DISTRIBUTION"
		runtime "Release"
		optimize "on"