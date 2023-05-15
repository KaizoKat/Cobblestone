#pragma once

#include "Cobble/Core.h"

namespace Cobble
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		ApkTick, ApkUpdate, ApkRender,
		KeyPress, KeyRelease,
		MousePress, MouseRelease, MouseMove, MouseScroll
	};

	enum class EventCategory
	{
		None = 0,
		EC_Application  = BIT(0),
		EC_Input        = BIT(1),
		EC_Keyboard     = BIT(2),
		EC_Mouse        = BIT(3),
		EC_MouseButton  = BIT(4)
	};

	class COBBLE_API Event
	{
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & (int)category;
		}
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return false;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator << (std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}