#include <PolyEngien.h>

class PolyViewer : public PolyEngien::Application
{
public:
	PolyViewer() {}
	~PolyViewer() {}
};

PolyEngien::Application* PolyEngien::CreateApplication()
{
	return new PolyViewer();
}
