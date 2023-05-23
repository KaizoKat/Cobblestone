#pragma once

#include "Cobble.h"

class DefaultScene : public Cobble::Layer
{
public:
	DefaultScene();
	virtual ~DefaultScene() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate() override;
	virtual void OnImGuiRender() override;
	void OnEvent(Cobble::Event& e) override;
	bool feScroll(Cobble::MouseScrollEvent& e);
};
