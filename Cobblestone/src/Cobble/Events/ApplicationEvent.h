#pragma once

#include "Event.h"

namespace Cobble
{
	class COBBLE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int w, unsigned int h)
			:m_Width(w), m_Height(h) {}

		inline unsigned int  GetWidth() const { return m_Width; }
		inline unsigned int  GetHeight() const { return m_Height; }

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowResize; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()    const override { return "Window Resize"; }


		virtual int GetCategoryFlags() const override { return (int)EventCategory::EC_Application; }

	private:
		unsigned int m_Width, m_Height;
	};

	
	class COBBLE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}


		static EventType GetStaticType() { return EventType::WindowClose; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()    const override { return "Window Close"; }


		virtual int GetCategoryFlags() const override { return (int)EventCategory::EC_Application; }
	};

	class COBBLE_API ApkTickEvent : public Event
	{
	public:
		ApkTickEvent() {}

		static EventType GetStaticType() { return EventType::ApkTick; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()    const override { return "Application Tick"; }


		virtual int GetCategoryFlags() const override { return (int)EventCategory::EC_Application; }
	};

	class COBBLE_API ApkUpdateEvent : public Event
	{
	public:
		ApkUpdateEvent() {}

		static EventType GetStaticType() { return EventType::ApkUpdate; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()    const override { return "Application Update"; }


		virtual int GetCategoryFlags() const override { return (int)EventCategory::EC_Application; }
	};

	class COBBLE_API ApkRenderEvent : public Event
	{
	public:
		ApkRenderEvent() {}

		static EventType GetStaticType() { return EventType::ApkRender; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()    const override { return "Application Render"; }


		virtual int GetCategoryFlags() const override { return (int)EventCategory::EC_Application; }
	};
}