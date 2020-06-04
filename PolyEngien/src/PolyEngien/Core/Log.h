#pragma once

#include "PolyEngien/Core/Base.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace PolyEngien {
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;

	};

}

// Core log macros
#define PE_CORE_TRACE(...)      ::PolyEngien::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PE_CORE_INFO(...)       ::PolyEngien::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PE_CORE_WARN(...)       ::PolyEngien::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PE_CORE_ERROR(...)      ::PolyEngien::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PE_CORE_CRITICAL(...)   ::PolyEngien::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define PE_TRACE(...)           ::PolyEngien::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PE_INFO(...)            ::PolyEngien::Log::GetClientLogger()->info(__VA_ARGS__)
#define PE_WARN(...)            ::PolyEngien::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PE_ERROR(...)           ::PolyEngien::Log::GetClientLogger()->error(__VA_ARGS__)
#define PE_CRITICAL(...)        ::PolyEngien::Log::GetClientLogger()->critical(__VA_ARGS__)

// TODO: Strip log macros in dist builds
// #define PE_CORE_TRACE, this will define PE_CORE_TRACE to do nothing