#include "pepch.h"
#include "PolyEngien/Renderer/GraphicsContext.h"

#include "PolyEngien/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace PolyEngien {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    PE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}