#include "PolyEngien/Application.h"

#include "PolyEngien/Events/Event.h"
#include "PolyEngien/Events/ApplicationEvent.h"
#include "PolyEngien/Log.h"

namespace PolyEngien {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		PE_TRACE(e);

		while (true);
	}
}