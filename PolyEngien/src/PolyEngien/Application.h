#pragma once

#include "PolyEngien/Core.h"

#include "PolyEngien/Window.h"
#include "PolyEngien/LayerStack.h"
#include "PolyEngien/Events/Event.h"
#include "PolyEngien/Events/ApplicationEvent.h"

#include "PolyEngien/Core/Timestep.h"

#include "PolyEngien/imgui/ImGuiLayer.h"

namespace PolyEngien {

	class POLYENGIEN_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event & e);

		void PushLayer(Layer * layer);
		void PushOverlay(Layer * layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent & e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();
}
