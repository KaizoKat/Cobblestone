#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Cobble
{
	class COBBLE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// both macros can be called from anywhere and currently, there is no diffrence in the two of 
// them.
//engine macros

#define EngineDebug_Log(...)	 ::Cobble::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define EngineDebug_Info(...)	 ::Cobble::Log::GetEngineLogger()->info(__VA_ARGS__)
#define EngineDebug_Warn(...)	 ::Cobble::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define EngineDebug_Error(...)   ::Cobble::Log::GetEngineLogger()->error(__VA_ARGS__)

//client macros
#define Debug_Log(...)	    ::Cobble::Log::GetClientLogger()->trace(__VA_ARGS__)
#define Debug_Info(...)	    ::Cobble::Log::GetClientLogger()->info(__VA_ARGS__)
#define Debug_Warn(...)	    ::Cobble::Log::GetClientLogger()->warn(__VA_ARGS__)
#define Debug_Error(...)    ::Cobble::Log::GetClientLogger()->error(__VA_ARGS__)