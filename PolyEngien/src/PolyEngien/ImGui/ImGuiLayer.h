#pragma once

#include "PolyEngien/Layer.h"

#include "PolyEngien/Events/ApplicationEvent.h"
#include "PolyEngien/Events/KeyEvent.h"
#include "PolyEngien/Events/MouseEvent.h"

namespace PolyEngien {
	class POLYENGIEN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
		
	private:
		float m_Time = 0.0f;
	};
}

