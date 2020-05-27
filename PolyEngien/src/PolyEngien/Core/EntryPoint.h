#pragma once
#include "PolyEngien/Core/Core.h"

#ifdef PE_PLATFORM_WINDOWS

extern PolyEngien::Application* PolyEngien::CreateApplication();

int main(int argc, char** argv)
{
	PolyEngien::Log::Init();
	PE_CORE_INFO("Initialized Log!");

	auto app = PolyEngien::CreateApplication();
	app->Run();
	delete app;
}

#endif