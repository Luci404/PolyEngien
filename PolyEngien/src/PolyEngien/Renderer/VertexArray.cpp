#include "pepch.h"
#include "PolyEngien/Renderer/VertexArray.h"

#include "PolyEngien/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace PolyEngien {

	Ref<VertexArray> VertexArray::Create() 
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    PE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLVertexArray>();
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}