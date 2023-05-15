#pragma once

#include "Event.h"

namespace Cobble
{
	class COBBLE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvet: " << GetX() << ", " << GetY();
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseMove; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()    const override { return "Mouse Move"; }


		virtual int GetCategoryFlags() const override { return (int)EventCategory::EC_Mouse; + (int)EventCategory::EC_Input;}

	private:
		float m_MouseX;
		float m_MouseY;
	};

	class COBBLE_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float xOffset, float yOffset)
			: m_OffsetX(xOffset), m_OffsetY(xOffset) {}

		inline float GetOffsetX() const { return m_OffsetX; }
		inline float GetOffsetY() const { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvet: " << GetOffsetX() << ", " << GetOffsetY();
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseScroll; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()    const override { return "Mouse Scroll"; }


		virtual int GetCategoryFlags() const override { return (int)EventCategory::EC_Mouse; +(int)EventCategory::EC_Input; }

	private:
		float m_OffsetX;
		float m_OffsetY;
	};

	class COBBLE_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		virtual int GetCategoryFlags() const override { return (int)EventCategory::EC_Mouse; +(int)EventCategory::EC_Input; }
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class COBBLE_API MousePressButtonEvent : public MouseButtonEvent
	{
	public:
		MousePressButtonEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MousePressButtonEvent: " << m_Button;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MousePress; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()    const override { return "Mouse Press"; }
	};

	class COBBLE_API MouseReleaseButtonEvent : public MouseButtonEvent
	{
	public:
		MouseReleaseButtonEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseReleaseButtonEvent: " << m_Button;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseRelease; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()    const override { return "Mouse Release"; }
	};
}