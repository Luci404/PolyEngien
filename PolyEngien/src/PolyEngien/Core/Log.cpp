#include "pepch.h"

#include "Log.h"

//#include "spdlog/sinks/stdout_color_sinks.h"

namespace PolyEngien {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");	// -startcolorr(%^) [Timestamp([%T)] nameoflogger(core/client)(%n): message(%v) -endcolor(%$)
		
		s_CoreLogger = spdlog::stdout_color_mt("POLY ENGIEN");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APPLICATION");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}