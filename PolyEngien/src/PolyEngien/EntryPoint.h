#pragma once

#ifdef PE_PLATFORM_WINDOWS

extern PolyEngien::Application* PolyEngien::CreateApplication();

int main(int argc, char** argv)
{
	auto app = PolyEngien::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Poly engien only supports Windows!
#endif