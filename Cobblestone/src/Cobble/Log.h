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

namespace Debug
{
	namespace Engine
	{

	}
}
//engine macros
#define EngineDebug_Trace(...)	 ::Cobble::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define EngineDebug_Log(...)	     ::Cobble::Log::GetEngineLogger()->info(__VA_ARGS__)
#define EngineDebug_Warn(...)	 ::Cobble::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define EngineDebug_Error(...)   ::Cobble::Log::GetEngineLogger()->error(__VA_ARGS__)
#define EngineDebug_Fatal(...)   ::Cobble::Log::GetEngineLogger()->fatal(__VA_ARGS__)

#define Debug_Trace(...)	::Cobble::Log::GetClientLogger()->trace(__VA_ARGS__)
#define Debug_Log(...)	        ::Cobble::Log::GetClientLogger()->info(__VA_ARGS__)
#define Debug_Warn(...)	    ::Cobble::Log::GetClientLogger()->warn(__VA_ARGS__)
#define Debug_Error(...)    ::Cobble::Log::GetClientLogger()->error(__VA_ARGS__)
#define Debug_Fatal(...)    ::Cobble::Log::GetClientLogger()->fatal(__VA_ARGS__)


