
#include "cpch.h"
#include "WindowsInput.h"
#include "Cobble\Main\Application.h"

#include <GLFW\glfw3.h>

namespace Cobble
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::i_IsKeyPressed(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);

		return state == GLFW_PRESS || GLFW_REPEAT;
	}

	bool WindowsInput::i_IsMouseButtonPresed(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::i_GetMousePosition()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double posY;
		double posX;
		glfwGetCursorPos(window, &posX, &posY);

		return std::pair<float, float>(posX,posY);
	}

	float WindowsInput::i_GetMouseX()
	{
		auto [x, y] = i_GetMousePosition();

		return x;
	}

	float WindowsInput::i_GetMouseY()
	{
		auto [x, y] = i_GetMousePosition();

		return y;
	}
}