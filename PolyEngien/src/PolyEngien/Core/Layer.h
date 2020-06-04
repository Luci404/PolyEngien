#pragma once

#include "PolyEngien/Core/Base.h"
#include "PolyEngien/Core/Timestep.h"
#include "PolyEngien/Events/Event.h"

namespace PolyEngien {
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_DebugName; }
	private:
		std::string m_DebugName;
	};
}

