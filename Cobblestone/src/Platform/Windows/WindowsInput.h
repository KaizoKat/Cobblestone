#pragma once

#include "Cobble\Main\Input.h"

namespace Cobble
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool i_IsKeyPressed(int keycode) override;

		virtual bool i_IsMouseButtonPresed(int button) override;
		virtual std::pair<float, float> i_GetMousePosition()override;
		virtual float i_GetMouseX() override;
		virtual float i_GetMouseY() override;
	};
}