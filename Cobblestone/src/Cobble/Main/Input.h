#pragma once

#include "Core.h"

namespace Cobble
{
	class COBBLE_API Input
	{
	public:
		inline static bool IsKeyPresed(int keycode) { return s_Instance->i_IsKeyPressed(keycode); }

		inline static bool IsMouseButtonPresed(int button) { return s_Instance->i_IsMouseButtonPresed(button); }
		inline static std::pair<float,float> GetMousePosition() { return s_Instance->i_GetMousePosition(); }
		inline static float GetMouseX() { return s_Instance->i_GetMouseX(); }
		inline static float GetMouseY() { return s_Instance->i_GetMouseY(); }

		// include the rest of the things for input polling. PLEASE!!!!!!
	protected:
		virtual bool i_IsKeyPressed(int keycode) = 0;

		virtual bool i_IsMouseButtonPresed(int button) = 0;
		virtual std::pair<float, float> i_GetMousePosition() = 0;
		virtual float i_GetMouseX() = 0;
		virtual float i_GetMouseY() = 0;

	private:
		static Input* s_Instance;
	};
}