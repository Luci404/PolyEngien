#pragma once

namespace PolyEngien
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define PE_KEY_SPACE           ::PolyEngien::Key::Space
#define PE_KEY_APOSTROPHE      ::PolyEngien::Key::Apostrophe    /* ' */
#define PE_KEY_COMMA           ::PolyEngien::Key::Comma         /* , */
#define PE_KEY_MINUS           ::PolyEngien::Key::Minus         /* - */
#define PE_KEY_PERIOD          ::PolyEngien::Key::Period        /* . */
#define PE_KEY_SLASH           ::PolyEngien::Key::Slash         /* / */
#define PE_KEY_0               ::PolyEngien::Key::D0
#define PE_KEY_1               ::PolyEngien::Key::D1
#define PE_KEY_2               ::PolyEngien::Key::D2
#define PE_KEY_3               ::PolyEngien::Key::D3
#define PE_KEY_4               ::PolyEngien::Key::D4
#define PE_KEY_5               ::PolyEngien::Key::D5
#define PE_KEY_6               ::PolyEngien::Key::D6
#define PE_KEY_7               ::PolyEngien::Key::D7
#define PE_KEY_8               ::PolyEngien::Key::D8
#define PE_KEY_9               ::PolyEngien::Key::D9
#define PE_KEY_SEMICOLON       ::PolyEngien::Key::Semicolon     /* ; */
#define PE_KEY_EQUAL           ::PolyEngien::Key::Equal         /* = */
#define PE_KEY_A               ::PolyEngien::Key::A
#define PE_KEY_B               ::PolyEngien::Key::B
#define PE_KEY_C               ::PolyEngien::Key::C
#define PE_KEY_D               ::PolyEngien::Key::D
#define PE_KEY_E               ::PolyEngien::Key::E
#define PE_KEY_F               ::PolyEngien::Key::F
#define PE_KEY_G               ::PolyEngien::Key::G
#define PE_KEY_H               ::PolyEngien::Key::H
#define PE_KEY_I               ::PolyEngien::Key::I
#define PE_KEY_J               ::PolyEngien::Key::J
#define PE_KEY_K               ::PolyEngien::Key::K
#define PE_KEY_L               ::PolyEngien::Key::L
#define PE_KEY_M               ::PolyEngien::Key::M
#define PE_KEY_N               ::PolyEngien::Key::N
#define PE_KEY_O               ::PolyEngien::Key::O
#define PE_KEY_P               ::PolyEngien::Key::P
#define PE_KEY_Q               ::PolyEngien::Key::Q
#define PE_KEY_R               ::PolyEngien::Key::R
#define PE_KEY_S               ::PolyEngien::Key::S
#define PE_KEY_T               ::PolyEngien::Key::T
#define PE_KEY_U               ::PolyEngien::Key::U
#define PE_KEY_V               ::PolyEngien::Key::V
#define PE_KEY_W               ::PolyEngien::Key::W
#define PE_KEY_X               ::PolyEngien::Key::X
#define PE_KEY_Y               ::PolyEngien::Key::Y
#define PE_KEY_Z               ::PolyEngien::Key::Z
#define PE_KEY_LEFT_BRACKET    ::PolyEngien::Key::LeftBracket   /* [ */
#define PE_KEY_BACKSLASH       ::PolyEngien::Key::Backslash     /* \ */
#define PE_KEY_RIGHT_BRACKET   ::PolyEngien::Key::RightBracket  /* ] */
#define PE_KEY_GRAVE_ACCENT    ::PolyEngien::Key::GraveAccent   /* ` */
#define PE_KEY_WORLD_1         ::PolyEngien::Key::World1        /* non-US #1 */
#define PE_KEY_WORLD_2         ::PolyEngien::Key::World2        /* non-US #2 */

/* Function keys */
#define PE_KEY_ESCAPE          ::PolyEngien::Key::Escape
#define PE_KEY_ENTER           ::PolyEngien::Key::Enter
#define PE_KEY_TAB             ::PolyEngien::Key::Tab
#define PE_KEY_BACKSPACE       ::PolyEngien::Key::Backspace
#define PE_KEY_INSERT          ::PolyEngien::Key::Insert
#define PE_KEY_DELETE          ::PolyEngien::Key::Delete
#define PE_KEY_RIGHT           ::PolyEngien::Key::Right
#define PE_KEY_LEFT            ::PolyEngien::Key::Left
#define PE_KEY_DOWN            ::PolyEngien::Key::Down
#define PE_KEY_UP              ::PolyEngien::Key::Up
#define PE_KEY_PAGE_UP         ::PolyEngien::Key::PageUp
#define PE_KEY_PAGE_DOWN       ::PolyEngien::Key::PageDown
#define PE_KEY_HOME            ::PolyEngien::Key::Home
#define PE_KEY_END             ::PolyEngien::Key::End
#define PE_KEY_CAPS_LOCK       ::PolyEngien::Key::CapsLock
#define PE_KEY_SCROLL_LOCK     ::PolyEngien::Key::ScrollLock
#define PE_KEY_NUM_LOCK        ::PolyEngien::Key::NumLock
#define PE_KEY_PRINT_SCREEN    ::PolyEngien::Key::PrintScreen
#define PE_KEY_PAUSE           ::PolyEngien::Key::Pause
#define PE_KEY_F1              ::PolyEngien::Key::F1
#define PE_KEY_F2              ::PolyEngien::Key::F2
#define PE_KEY_F3              ::PolyEngien::Key::F3
#define PE_KEY_F4              ::PolyEngien::Key::F4
#define PE_KEY_F5              ::PolyEngien::Key::F5
#define PE_KEY_F6              ::PolyEngien::Key::F6
#define PE_KEY_F7              ::PolyEngien::Key::F7
#define PE_KEY_F8              ::PolyEngien::Key::F8
#define PE_KEY_F9              ::PolyEngien::Key::F9
#define PE_KEY_F10             ::PolyEngien::Key::F10
#define PE_KEY_F11             ::PolyEngien::Key::F11
#define PE_KEY_F12             ::PolyEngien::Key::F12
#define PE_KEY_F13             ::PolyEngien::Key::F13
#define PE_KEY_F14             ::PolyEngien::Key::F14
#define PE_KEY_F15             ::PolyEngien::Key::F15
#define PE_KEY_F16             ::PolyEngien::Key::F16
#define PE_KEY_F17             ::PolyEngien::Key::F17
#define PE_KEY_F18             ::PolyEngien::Key::F18
#define PE_KEY_F19             ::PolyEngien::Key::F19
#define PE_KEY_F20             ::PolyEngien::Key::F20
#define PE_KEY_F21             ::PolyEngien::Key::F21
#define PE_KEY_F22             ::PolyEngien::Key::F22
#define PE_KEY_F23             ::PolyEngien::Key::F23
#define PE_KEY_F24             ::PolyEngien::Key::F24
#define PE_KEY_F25             ::PolyEngien::Key::F25

/* Keypad */
#define PE_KEY_KP_0            ::PolyEngien::Key::KP0
#define PE_KEY_KP_1            ::PolyEngien::Key::KP1
#define PE_KEY_KP_2            ::PolyEngien::Key::KP2
#define PE_KEY_KP_3            ::PolyEngien::Key::KP3
#define PE_KEY_KP_4            ::PolyEngien::Key::KP4
#define PE_KEY_KP_5            ::PolyEngien::Key::KP5
#define PE_KEY_KP_6            ::PolyEngien::Key::KP6
#define PE_KEY_KP_7            ::PolyEngien::Key::KP7
#define PE_KEY_KP_8            ::PolyEngien::Key::KP8
#define PE_KEY_KP_9            ::PolyEngien::Key::KP9
#define PE_KEY_KP_DECIMAL      ::PolyEngien::Key::KPDecimal
#define PE_KEY_KP_DIVIDE       ::PolyEngien::Key::KPDivide
#define PE_KEY_KP_MULTIPLY     ::PolyEngien::Key::KPMultiply
#define PE_KEY_KP_SUBTRACT     ::PolyEngien::Key::KPSubtract
#define PE_KEY_KP_ADD          ::PolyEngien::Key::KPAdd
#define PE_KEY_KP_ENTER        ::PolyEngien::Key::KPEnter
#define PE_KEY_KP_EQUAL        ::PolyEngien::Key::KPEqual

#define PE_KEY_LEFT_SHIFT      ::PolyEngien::Key::LeftShift
#define PE_KEY_LEFT_CONTROL    ::PolyEngien::Key::LeftControl
#define PE_KEY_LEFT_ALT        ::PolyEngien::Key::LeftAlt
#define PE_KEY_LEFT_SUPER      ::PolyEngien::Key::LeftSuper
#define PE_KEY_RIGHT_SHIFT     ::PolyEngien::Key::RightShift
#define PE_KEY_RIGHT_CONTROL   ::PolyEngien::Key::RightControl
#define PE_KEY_RIGHT_ALT       ::PolyEngien::Key::RightAlt
#define PE_KEY_RIGHT_SUPER     ::PolyEngien::Key::RightSuper
#define PE_KEY_MENU            ::PolyEngien::Key::Menu