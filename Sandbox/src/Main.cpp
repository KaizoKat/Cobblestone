#include <Cobble.h>

class ExampleLayer : public Cobble::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		Debug_Log("ExampleLayer::Update");
	}

	void OnEvent(Cobble::Event& event) override
	{
		Debug_Trace("{0}", event);
	}
};



class Sandbox : public Cobble::Application
{
public:
	 Sandbox()
	 {
		 Debug_Trace("Sandbox Opened Succesfuly");
		 PushLayer(new ExampleLayer());
	 }
	~Sandbox(){}
};

Cobble::Application* Cobble::CreateApplication()
{
	return new Sandbox();
}