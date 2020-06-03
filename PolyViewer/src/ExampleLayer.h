#pragma once

#include "PolyEngien.h"

class ExampleLayer : public PolyEngien::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(PolyEngien::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(PolyEngien::Event& e) override;
private:
	PolyEngien::ShaderLibrary m_ShaderLibrary;
	PolyEngien::Ref<PolyEngien::Shader> m_Shader;
	PolyEngien::Ref<PolyEngien::VertexArray> m_VertexArray;

	PolyEngien::Ref<PolyEngien::Shader> m_FlatColorShader;
	PolyEngien::Ref<PolyEngien::VertexArray> m_SquareVA;

	PolyEngien::Ref<PolyEngien::Texture2D> m_Texture, m_ChernoLogoTexture;

	PolyEngien::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};