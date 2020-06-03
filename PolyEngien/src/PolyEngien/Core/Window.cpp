#include "pepch.h"
#include "PolyEngien/Core/Window.h"

#ifdef PE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace PolyEngien
{

	Scope<Window> Window::Create(const WindowProperties& props)
	{
		#ifdef PE_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
		#else
		PE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
		#endif
	}

}