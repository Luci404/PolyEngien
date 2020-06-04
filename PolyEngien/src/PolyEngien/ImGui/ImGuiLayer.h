#pragma once

#include "PolyEngien/Core/Layer.h"

#include "PolyEngien/Events/ApplicationEvent.h"
#include "PolyEngien/Events/KeyEvent.h"
#include "PolyEngien/Events/MouseEvent.h"

namespace PolyEngien {
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();
		
	private:
		float m_Time = 0.0f;
	};
}


