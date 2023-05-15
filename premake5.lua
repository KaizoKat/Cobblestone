workspace "Cobblestone"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Distrib"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Cobblestone/external/GLFW/include"
IncludeDir["glad"] = "Cobblestone/external/glad/include"

include "Cobblestone/external/GLFW"
include "Cobblestone/external/glad"

project "Cobblestone"
	location "Cobblestone"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cpch.h"
	pchsource "%{prj.name}/src/cpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/external/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}"
	}

	links 
	{ 
		"GLFW",
		"glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CBB_PLATFORM_WINDOWS",
			"CBB_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}


	filter "configurations:Debug"
		defines "CBB_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "CBB_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Distrib"
		defines "CBB_DISTRIB"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Cobblestone/external/spdlog/include",
		"Cobblestone/src"
	}

	links
	{
		"Cobblestone"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CBB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CBB_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "CBB_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Distrib"
		defines "CBB_DISTRIB"
		buildoptions "/MD"
		optimize "On"