#pragma once

#include "PolyEngien/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace PolyEngien {
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}
