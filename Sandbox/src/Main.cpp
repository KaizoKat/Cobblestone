#include <Cobble.h>

class Sandbox : public Cobble::Application
{
public:
	Sandbox(){}
	~Sandbox(){}
};

Cobble::Application* Cobble::CreateApplication()
{
	return new Sandbox();
}