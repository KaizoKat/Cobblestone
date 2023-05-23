#include "DefaultScene.h"

DefaultScene::DefaultScene() : Layer("Default Scene")
{
}

void DefaultScene::OnAttach()
{
}

void DefaultScene::OnDetach()
{
}

void DefaultScene::OnUpdate()
{
}

void DefaultScene::OnImGuiRender()
{
}

void DefaultScene::OnEvent(Cobble::Event& e)
{
	Cobble::EventDispatcher dsp(e);
	dsp.Dispatch<Cobble::MouseScrollEvent>(std::bind(&DefaultScene::feScroll, this, std::placeholders::_1));
}

bool DefaultScene::feScroll(Cobble::MouseScrollEvent& e)
{
	return false;
}
