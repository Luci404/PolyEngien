#include <PolyEngien.h>

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
			PE_INFO("Tab key is pressed!");
	}

	void OnEvent(PolyEngien::Event& event) override
	{}
};

class PolyViewer : public PolyEngien::Application
{
public:
	PolyViewer() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new PolyEngien::ImGuiLayer());
	}

	~PolyViewer() {}
};

PolyEngien::Application* PolyEngien::CreateApplication()
{
	return new PolyViewer();
}