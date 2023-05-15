
#include <Cobble.h>
#include "LayerStack.h"


class Sandbox : public Cobble::Application
{
public:
	 Sandbox()
	 {
		 Debug_Trace("Sandbox Opened Succesfuly");
		 #include "LayerChannel.h"
	 }
	~Sandbox(){}
};

Cobble::Application* Cobble::CreateApplication()
{
	return new Sandbox();
}