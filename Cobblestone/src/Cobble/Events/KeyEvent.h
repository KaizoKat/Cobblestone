#pragma once

#include "Event.h"

struct GLFWwindow;

namespace Cobble
{
	class COBBLE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		inline int GetScanCode() const { return m_ScanCode; }
		inline int GetAction() const { return m_Action; }
		inline int GetMods() const { return m_Mods; }
		inline GLFWwindow* GetWindow() const { return m_Window; }

		virtual int GetCategoryFlags() const override { return (int)EventCategory::EC_Keyboard + (int)EventCategory::EC_Input;}
	protected:
		KeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
			: m_Window(window), m_KeyCode(key), m_ScanCode(scancode), m_Action(action), m_Mods(mods) {}

		int m_KeyCode;
		int m_ScanCode;
		int m_Action;
		int m_Mods;
		GLFWwindow* m_Window;
	};

	class COBBLE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(GLFWwindow* window, int key, int scancode, int action, int mods, int repeatCount)
			: KeyEvent(window, key, scancode, action, mods), m_RepeatCount(repeatCount) {}

		inline int GetRepeqatCount() const { return m_RepeatCount; }

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "KeyPressEvent:  " << m_Window << ", " << m_KeyCode << ", " << m_ScanCode << ", " << m_Action << "," << m_Mods << ", (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::KeyPress; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()    const override { return "Key Press"; }
	private:
		int m_RepeatCount;
	};

	class COBBLE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
			: KeyEvent(window, key, scancode, action, mods){}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasEvent: "<< m_Window << ", " << m_KeyCode << ", " << m_ScanCode << ", " << m_Action << "," << m_Mods;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::KeyRelease; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()    const override { return "Key Release"; }
	};
}