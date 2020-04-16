#include "pepch.h"
#include "PolyEngien/Application.h"

#include "PolyEngien/Events/ApplicationEvent.h"
#include "PolyEngien/Log.h"

namespace PolyEngien {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (true)
		{
			m_Window->OnUpdate();
		}
	}
}