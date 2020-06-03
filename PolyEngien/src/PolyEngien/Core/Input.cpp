#include "pepch.h"
#include "PolyEngien/Core/Input.h"

#ifdef PE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace PolyEngien {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
		#ifdef PE_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
		#else
		PE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
		#endif
	}
}