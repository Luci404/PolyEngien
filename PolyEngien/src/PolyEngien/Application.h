#pragma once

#include "PolyEngien/Core.h"

#include "PolyEngien/Window.h"
#include "PolyEngien/LayerStack.h"
#include "PolyEngien/Events/ApplicationEvent.h"
#include "PolyEngien/Events/Event.h"

#include "PolyEngien/imgui/ImGuiLayer.h"

#include "PolyEngien/Renderer/Shader.h"
#include "PolyEngien/Renderer/Buffer.h"
#include "PolyEngien/Renderer/VertexArray.h"

#include "PolyEngien/Renderer/OrthographicCamera.h"

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

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;
	private:
		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();
}
