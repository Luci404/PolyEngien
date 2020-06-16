#pragma once
#include "PolyEngien/Core/Base.h"

#ifdef PE_PLATFORM_WINDOWS

extern PolyEngien::Application* PolyEngien::CreateApplication();

int main(int argc, char** argv)
{
	PolyEngien::Log::Init();

	PE_PROFILE_BEGIN_SESSION("Startup", "PolyEngienProfile-Startup.json");
	auto app = PolyEngien::CreateApplication();
	PE_PROFILE_END_SESSION();

	PE_PROFILE_BEGIN_SESSION("Runtime", "PolyEngienProfile-Runtime.json");
	app->Run();
	PE_PROFILE_END_SESSION();

	PE_PROFILE_BEGIN_SESSION("Shutdown", "PolyEngienProfile-Shutdown.json");
	delete app;
	PE_PROFILE_END_SESSION();
}

#endif