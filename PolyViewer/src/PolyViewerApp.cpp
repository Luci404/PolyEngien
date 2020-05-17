#include <PolyEngien.h>

#include "imgui/imgui.h"

class ExampleLayer : public PolyEngien::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (PolyEngien::Input::IsKeyPressed(PE_KEY_TAB))
			PE_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(PolyEngien::Event& event) override
	{
		if (event.GetEventType() == PolyEngien::EventType::KeyPressed)
		{
			PolyEngien::KeyPressedEvent& e = (PolyEngien::KeyPressedEvent&)event;
			if (e.GetKeyCode() == PE_KEY_TAB)
				PE_TRACE("Tab key is pressed (event)!");
			PE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class PolyViewer : public PolyEngien::Application
{
public:
	PolyViewer() 
	{
		PushLayer(new ExampleLayer());
	}

	~PolyViewer() {}
};

PolyEngien::Application* PolyEngien::CreateApplication()
{
	return new PolyViewer();
}