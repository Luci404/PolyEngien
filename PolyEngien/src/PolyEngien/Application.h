#pragma once

#include "PolyEngien/Core.h"

#include "PolyEngien/Window.h"
#include "PolyEngien/LayerStack.h"
#include "PolyEngien/Events/ApplicationEvent.h"
#include "PolyEngien/Events/Event.h"

namespace PolyEngien {

	class POLYENGIEN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in client
	Application* CreateApplication();
}
