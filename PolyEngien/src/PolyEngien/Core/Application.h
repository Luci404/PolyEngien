#pragma once

#include "PolyEngien/Core/Core.h"

#include "PolyEngien/Core/Window.h"
#include "PolyEngien/Core/LayerStack.h"
#include "PolyEngien/Events/Event.h"
#include "PolyEngien/Events/ApplicationEvent.h"

#include "PolyEngien/Core/Timestep.h"

#include "PolyEngien/imgui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace PolyEngien {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event & e);

		void PushLayer(Layer * layer);
		void PushOverlay(Layer * layer);

		Window& GetWindow() { return *m_Window; }

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
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
		friend int ::main(int argc, char** argv);
	};

	// To be defined in client
	Application* CreateApplication();
}
