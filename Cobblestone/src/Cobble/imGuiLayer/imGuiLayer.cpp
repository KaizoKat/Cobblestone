
#include "cpch.h"
#include "imGuiLayer.h"
#include "GLFW\glfw3.h"

#include "Cobble\Main\Application.h"
#include "Cobble\Main\Input.h"

#include "Platform\ImGui\OpenGL_glfw\imgui_impl_glfw.h"
#include "Platform\ImGui\OpenGL_glfw\imgui_impl_opengl3.h"
#include "Platform\Windows\WindowsWindow.h"

#include "imGuiThemes.h"

struct GLFWwindow;

namespace Cobble
{
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer"), b_Info(false) {}

	ImGuiLayer::~ImGuiLayer()  {}

	int itt = 7;

	void ImGuiLayer::OnAttach()
	{
        IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		SwitchStyle();

        ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplGlfw_InitForOpenGL(glfwGetCurrentContext(), false);
        ImGui_ImplOpenGL3_Init("#version 130");
	}

	void ImGuiLayer::OnDetach()
	{
		ImGui_ImplGlfw_Shutdown();
	}

	void ImGuiLayer::OnUpdate() 
    {

        Application& app = Application::Get();
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

		ShowDebugWindow();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

	void ImGuiLayer::OnImGuiRender()
	{

	}

	void ImGuiLayer::OnEvent(Cobble::Event& e)
	{
	}

	void ImGuiLayer::ShowDebugWindow()
	{
		static bool b_MFTB = true;
		static bool b_Debug = false;

		static float bgColor[4] = { 102.0f / 255.0f,124.0f / 255.0f,154.0f / 255.0f,1 };
		static int wait = 0;
		static int prevFPSV;
		static double oldTime = 0.0;
		__int64 counter;
		__int64 frequency;

		Application& app = Application::Get();
		ImGuiIO& io = ImGui::GetIO();

		app.m_BGColor.x = bgColor[0];
		app.m_BGColor.y = bgColor[1];
		app.m_BGColor.z = bgColor[2];
		app.m_BGColor.w = bgColor[3];

		QueryPerformanceCounter((LARGE_INTEGER*)&counter);
		QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);

		double newTime = (double)counter / (double)frequency;
		double frameRate = 1 / (newTime - oldTime);
		oldTime = newTime;

		if (wait > 60) wait = 0;
		else wait++;

		ImGui::SetNextWindowSize(ImVec2(220.0f,360.0f),ImGuiCond_Appearing);
		ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Appearing, ImVec2(0.0f, 0.0f));

		ImGui::Begin("Main Menu");// Main Menu ------------------------------------------------------

		ImGui::Checkbox("Lock Position", &b_MFTB);
		io.ConfigWindowsMoveFromTitleBarOnly = b_MFTB;

		if (ImGui::Button("Open Debug Menu"))
		{
			b_Debug = !b_Debug;
		}

		if (ImGui::Button("Open Info Menu"))
		{
			b_Info = !b_Info;
		}

		ImGui::End();//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		if (b_Debug)
		{
			ImGui::SetNextWindowSize(ImVec2(480.0f, 360.0f), ImGuiCond_Appearing);
			ImGui::SetNextWindowPos(ImVec2(220.0f, 0.0f), ImGuiCond_Appearing, ImVec2(0.0f, 0.0f));

			ImGui::Begin("Debug Pannel", &b_Debug);// Debug Pannel -----------------------------------

			ImGui::ColorEdit4("BackgroundColor", bgColor, 0);

			if (ImGui::Button("Shuffle Color Theme"))
			{
				if (itt == 7) itt = 0;
				else itt++;
			}

			SwitchStyle();

			ImGui::End();//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		}

		if (b_Info)
		{
			ImGui::SetNextWindowSize(ImVec2(220.0f, 200.0f), ImGuiCond_Appearing);
			ImGui::SetNextWindowPos(ImVec2(0.0f, 360.0f), ImGuiCond_Appearing, ImVec2(0.0f, 0.0f));

			ImGui::Begin("Info Pannel", &b_Info);// Info Pannel -----------------------------------

			std::stringstream framerate;
			if (wait == 0) prevFPSV = (int)frameRate;
			framerate << "Frame Rate: " << prevFPSV;
			ImGui::Text(framerate.str().c_str());

			std::stringstream mousePos;
			mousePos << "Mouse Pos: " << Input::GetMouseX() << ", " << Input::GetMouseY();
			ImGui::Text(mousePos.str().c_str());

			ImGui::End();//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		}
	}

	void ImGuiLayer::SwitchStyle()
	{
		switch (itt)
		{
		case 0:
			Cobble::Themes::DefaultDarkTheme();
			break;
		case 1:
			Cobble::Themes::DefaultLightTheme();
			break;
		case 2:
			Cobble::Themes::ClassicTheme();
			break;
		case 3:
			Cobble::Themes::CinderTheme();
			break;
		case 4:
			Cobble::Themes::EnemyMouseTheme();
			break;
		case 5:
			Cobble::Themes::LeadSynthTheme();
			break;
		case 6:
			Cobble::Themes::DougblinksThemeDark();
			break;
		case 7:
			Cobble::Themes::DougblinksThemeLight();
			break;
		}
	}
}
