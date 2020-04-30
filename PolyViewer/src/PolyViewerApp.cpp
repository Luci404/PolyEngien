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
		//PE_INFO("ExampleLayer::Update");
	}

	void OnEvent(PolyEngien::Event& event) override
	{
		PE_TRACE("{0}", event);
	}
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
