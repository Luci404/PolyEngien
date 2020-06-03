#pragma once

namespace PolyEngien
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define PE_MOUSE_BUTTON_0      ::PolyEngien::Mouse::Button0
#define PE_MOUSE_BUTTON_1      ::PolyEngien::Mouse::Button1
#define PE_MOUSE_BUTTON_2      ::PolyEngien::Mouse::Button2
#define PE_MOUSE_BUTTON_3      ::PolyEngien::Mouse::Button3
#define PE_MOUSE_BUTTON_4      ::PolyEngien::Mouse::Button4
#define PE_MOUSE_BUTTON_5      ::PolyEngien::Mouse::Button5
#define PE_MOUSE_BUTTON_6      ::PolyEngien::Mouse::Button6
#define PE_MOUSE_BUTTON_7      ::PolyEngien::Mouse::Button7
#define PE_MOUSE_BUTTON_LAST   ::PolyEngien::Mouse::ButtonLast
#define PE_MOUSE_BUTTON_LEFT   ::PolyEngien::Mouse::ButtonLeft
#define PE_MOUSE_BUTTON_RIGHT  ::PolyEngien::Mouse::ButtonRight
#define PE_MOUSE_BUTTON_MIDDLE ::PolyEngien::Mouse::ButtonMiddle