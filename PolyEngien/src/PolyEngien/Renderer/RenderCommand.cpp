#include "pepch.h"
#include "PolyEngien/Renderer/RenderCommand.h"

namespace PolyEngien {
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}