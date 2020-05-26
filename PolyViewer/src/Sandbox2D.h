#pragma once

#include "PolyEngien.h"

class Sandbox2D : public PolyEngien::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(PolyEngien::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(PolyEngien::Event& e) override;
private:
	PolyEngien::OrthographicCameraController m_CameraController;

	// Temp
	PolyEngien::Ref<PolyEngien::VertexArray> m_SquareVA;
	PolyEngien::Ref<PolyEngien::Shader> m_FlatColorShader;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};