#include <Cobble.h>

class Layer0 : public Cobble::Layer
{
private:
	int counter;
public:
	//start of the layer's loop (called once)
	Layer0()
		: Layer("Example"), counter(0)
	{

	}

	//called every frame (multiple times.)
	void OnUpdate() override
	{

	}

	void OnEvent(Cobble::Event& event) override
	{

	}
};



class Sandbox : public Cobble::Application
{
public:
	 Sandbox()
	 {
		 Debug_Trace("Sandbox Opened Succesfuly");
		 PushLayer(new Layer0());
	 }
	~Sandbox(){}
};

Cobble::Application* Cobble::CreateApplication()
{
	return new Sandbox();
}