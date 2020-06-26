#pragma once

#include "PolyEngien/Core/Base.h"
#include "PolyEngien/Core/KeyCodes.h"
#include "PolyEngien/Core/MouseCodes.h"

namespace PolyEngien {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}