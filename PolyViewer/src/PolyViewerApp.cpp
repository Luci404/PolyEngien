#include <PolyEngien.h>
#include <PolyEngien/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class PolyViewer : public PolyEngien::Application
{
public:
	PolyViewer() 
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~PolyViewer() 
	{
	}
};

PolyEngien::Application* PolyEngien::CreateApplication()
{
	return new PolyViewer();
}