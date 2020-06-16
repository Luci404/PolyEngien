#include <PolyEngien.h>
#include <PolyEngien/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace PolyEngien {

	class KronosEditor : public Application
	{
	public:
		KronosEditor()
			: Application("Kronos Editor")
		{
			PushLayer(new EditorLayer());
		}

		~KronosEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new KronosEditor();
	}

}