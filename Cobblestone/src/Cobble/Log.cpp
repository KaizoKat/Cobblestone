#include "cpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Cobble
{
	std::shared_ptr<spdlog::logger> Log::s_EngineLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%n|%M:%S:%e]: [>> %v]%$");

		s_EngineLogger = spdlog::stdout_color_mt("~~E~~");
		s_ClientLogger = spdlog::stdout_color_mt("--A--");

		s_EngineLogger->set_level(spdlog::level::trace);
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}
