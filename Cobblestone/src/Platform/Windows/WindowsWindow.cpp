#include "cpch.h"
#include "WindowsWindow.h"

#include "Cobble/Events/ApplicationEvent.h"
#include "Cobble/Events/KeyEvent.h"
#include "Cobble/Events/MouseEvent.h"
#include "Platform\OpenGL\i_ImGuiGlfw.h"

namespace Cobble {

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int code, const char* error)
	{
		EngineDebug_Error("GLFW Error: [{0}] >>> {1}", code, error);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		EngineDebug_Info("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			CBB_CORE_ASSERT(success, "Could not intialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		CBB_CORE_ASSERT(status, "Failed to initialize glad.");

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(false);
		//set GLFW callback
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));
				WindowCloseEvent event;

				data.EventCallback(event);
			});

		glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focus) 
			{
				ImGui_ImplGlfw_WindowFocusCallback(window, focus);
			});

		glfwSetCursorEnterCallback(m_Window, [](GLFWwindow* window, int enter)
			{
				ImGui_ImplGlfw_CursorEnterCallback(window, enter);
			});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int c)
			{
				ImGui_ImplGlfw_CharCallback(window, c);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(window,key,scancode,action,mods, 0);
						data.EventCallback(event);
						break;
					}

					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(window, key, scancode, action, mods);
						data.EventCallback(event);
						break;
					}

					case GLFW_REPEAT:
					{
						KeyPressedEvent event(window, key, scancode, action, mods, 1);
						data.EventCallback(event);
						break;
					}
				}

				ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) 
			{
				WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));

				switch (action)
				{
					case GLFW_PRESS:
					{
						MousePressButtonEvent event(button);
						data.EventCallback(event);
						break;
					}

					case GLFW_RELEASE:
					{
						MouseReleaseButtonEvent event(button);
						data.EventCallback(event);
						break;
					}
				}

				ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrollEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);

				ImGui_ImplGlfw_ScrollCallback(window, xOffset, yOffset);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);

				ImGui_ImplGlfw_CursorPosCallback(window, xPos, yPos);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}