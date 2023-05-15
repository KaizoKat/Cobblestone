#include <Cobble.h>

class Layer_ImGui : public Cobble::Layer
{
private:
	int counter;
public:
	//start of the layer's loop (called once)
	Layer_ImGui() : Layer("Example"), counter(0)
	{
		Debug_Trace("ImGui Layer");
	}

	//called every frame (multiple times.)
	void OnUpdate() override
	{}

	//called when event is called
	void OnEvent(Cobble::Event& event) override
	{}
};

class Layer0 : public Cobble::Layer
{
private:
	int counter;
public:
	//start of the layer's loop (called once)
	Layer0() : Layer("Example"), counter(0)
	{
		Debug_Trace("Layer0");
	}

	//called every frame (multiple times.)
	void OnUpdate() override
	{}

	//called when event is called
	void OnEvent(Cobble::Event& event) override
	{}
};