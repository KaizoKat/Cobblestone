

#include "Cobble.h"
#include "Cobble\Main\EntryPoint.h"
#include "DefaultScene.h"

class Sandbox : public Cobble::Application
{
public:
	 Sandbox()
	 {
		 Debug_Info("Sandbox Opened Succesfuly");
		 PushOverlay(new Cobble::ImGuiLayer());
		 PushLayer(new DefaultScene());
	 }
	~Sandbox(){}
};

Cobble::Application* Cobble::CreateApplication()
{
	return new Sandbox();
}