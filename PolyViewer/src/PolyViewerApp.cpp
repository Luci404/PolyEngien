#include <PolyEngien.h>
#include <PolyEngien/Core/EntryPoint.h>

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class ExampleLayer : public PolyEngien::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.0f / 720.0f, false)
	{
		m_VertexArray = PolyEngien::VertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		PolyEngien::Ref<PolyEngien::VertexBuffer> vertexBuffer = PolyEngien::VertexBuffer::Create(vertices, sizeof(vertices));
		PolyEngien::BufferLayout layout = {
			{ PolyEngien::ShaderDataType::Float3, "a_Position" },
			{ PolyEngien::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		PolyEngien::Ref<PolyEngien::IndexBuffer> indexBuffer = PolyEngien::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA = PolyEngien::VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		PolyEngien::Ref<PolyEngien::VertexBuffer> squareVB = PolyEngien::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
		squareVB->SetLayout({
			{ PolyEngien::ShaderDataType::Float3, "a_Position" },
			{ PolyEngien::ShaderDataType::Float2, "a_TexCoord" }
		});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		PolyEngien::Ref<PolyEngien::IndexBuffer> squareIB = PolyEngien::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
	 		uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
 				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader = PolyEngien::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
 			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			uniform vec3 u_Color;

			in vec3 v_Position;

			void main()
			{
				color = vec4(u_Color, 1);
			}
		)";

		m_FlatColorShader = PolyEngien::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/S_Texture.glsl");

		m_Texture = PolyEngien::Texture2D::Create("assets/textures/T_Checkerboard.png");
		m_ChernoLogoTexture = PolyEngien::Texture2D::Create("assets/textures/ChernoLogo.png");

		textureShader->Bind();
		textureShader->SetInt("u_Texture", 0);

	}

	void OnUpdate(PolyEngien::Timestep ts) override
	{
		// Update
		m_CameraController.OnUpdate(ts);

		// Render
		PolyEngien::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		PolyEngien::RenderCommand::Clear();

		PolyEngien::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		m_FlatColorShader->Bind();
		m_FlatColorShader->SetFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				PolyEngien::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.Get("S_Texture");

		m_Texture->Bind();
		PolyEngien::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_ChernoLogoTexture->Bind();
		PolyEngien::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		// Triangle
		// PolyEngien::Renderer::Submit(m_Shader, m_VertexArray);

		PolyEngien::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(PolyEngien::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}

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

class PolyViewer : public PolyEngien::Application
{
public:
	PolyViewer() 
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~PolyViewer() {}
};

PolyEngien::Application* PolyEngien::CreateApplication()
{
	return new PolyViewer();
}