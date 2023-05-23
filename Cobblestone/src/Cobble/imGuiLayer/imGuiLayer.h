#pragma once

#include "Cobble\Main\Layer.h"
#include "Cobble\Events\KeyEvent.h"

namespace Cobble
{
	class COBBLE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;

		void OnUpdate() override;
		void ImGuiLayer::OnImGuiRender() override;
		void OnEvent(Cobble::Event& e) override;
		void ShowDebugWindow();
	private:
		float m_Time = 0.0f;
	};
}
