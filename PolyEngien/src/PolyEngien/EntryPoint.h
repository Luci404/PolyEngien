#pragma once

#ifdef PE_PLATFORM_WINDOWS

extern PolyEngien::Application* PolyEngien::CreateApplication();

int main(int argc, char** argv)
{
	PolyEngien::Log::Init();
	PE_CORE_CRITICAL("Initialized Log!");
	PE_INFO("Initialized Log!");


		auto app = PolyEngien::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Poly engien only supports Windows!
#endif