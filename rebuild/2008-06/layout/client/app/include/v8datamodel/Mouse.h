#pragma once
#include "v8tree/Instance.h"
#include "util/UIEvent.h"
#include "util/TextureId.h"
#include <G3D/CoordinateFrame.h>

struct NativeMouseLayout;

namespace RBX
{
	class MouseCommand;
	class PartInstance;

	extern const char sMouse[];

	class Mouse : public DescribedNonCreatable<Mouse, Instance, sMouse>
	{
		friend struct ::NativeMouseLayout; // tests/NativeMouseLayout.cpp offset asserts

	private:
		UIEvent lastEvent;        // +0x130
		TextureId icon;           // +0x144
		MouseCommand* command;    // +0x164

	private:
		void cacheUIEvent(const UIEvent& uiEvent)  // 0064df60 (emitted out of line)
		{
			lastEvent = uiEvent;
			lastEvent.eventType = UIEvent::NO_EVENT;
		}

		void checkActive() const                   // 00642f10 (emitted out of line)
		{
			if (!command)
				throw std::runtime_error("This Mouse is no longer active");
		}
	public:
		Mouse()                                    // 005ff3b0
			: command(NULL)
		{
		}

		void update(const UIEvent& uiEvent);       // 0064e660
		G3D::CoordinateFrame getHit() const;       // 0064e1a0
		G3D::CoordinateFrame getOrigin() const;    // 0064e050
		PartInstance* getTarget() const;           // 0064e020

		void setCommand(MouseCommand* value)
		{
			command = value;
		}

		TextureId getIcon() const                  // 00642f80
		{
			checkActive();
			return icon;
		}

		void setIcon(const TextureId& value)       // 0064e180
		{
			icon = value;
		}

		int getX() const                           // 0064dfa0
		{
			checkActive();
			return lastEvent.mousePosition.x;
		}

		int getY() const                           // 0064dfc0
		{
			checkActive();
			return lastEvent.mousePosition.y;
		}

		int getViewSizeX() const                   // 0064dfe0
		{
			checkActive();
			return lastEvent.windowSize.x;
		}

		int getViewSizeY() const                   // 0064e000
		{
			checkActive();
			return lastEvent.windowSize.y;
		}
	};
}
