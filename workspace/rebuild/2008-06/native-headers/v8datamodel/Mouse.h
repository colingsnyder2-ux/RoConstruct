#pragma once
// >>> native-status (generated) -- do not edit >>>
// Mouse | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 780e1ec8 | roc native-status --write
// 2008-06 native RBX::Mouse (inactive). Shape after the donor tools/rbxgs v8datamodel/Mouse.h. The changes are the
// class-name template argument, a const char array (RTTI $1?sMouse@2@3QBDB; "Mouse" at 0084b260 in .rdata), and the
// descriptor set of the 2008 binary. Every base, field and size below is read from the 2008-06 binary
// (tests/record_native_mouse.py checks them):
//   RTTI       vtable 00841cdc .?AVMouse@RBX@@ (21 bases) -> DescribedNonCreatable<Mouse, Instance, sMouse> ->
//              Described<Mouse, sMouse, NonFactoryProduct<Instance, sMouse>> -> NonFactoryProduct<Instance, sMouse>
//              -> Instance. The 16 slots of the Mouse vtable equal the Instance vtable 0082d884: no virtual overrides.
//   size       0x168: Creatable<Instance>::create<Mouse> 005ff600 allocates 0x168 and calls the constructor 005ff3b0.
//   fields     constructor 005ff3b0 (the inline donor constructor, emitted in the Tool unit): lastEvent +0x130
//              (UIEvent(): eventType +0x130 = NO_EVENT, userInput +0x134 = NULL, three Vector2int16 +0x138/+0x13c/
//              +0x140 = 0), icon +0x144 (TextureId: std::string +0x144, mimeTypePtr +0x160 = &Name::getNullName()),
//              command +0x164 = NULL. The destructor 005ff520 (implicit: no vtable stores) destroys the icon string
//              and runs ~Instance.
//   accessors  getX 0064dfa0 / getY 0064dfc0 read mousePosition +0x138 / +0x13a, getViewSizeX 0064dfe0 / getViewSizeY
//              0064e000 read windowSize +0x140 / +0x142, each after checkActive 00642f10 (command +0x164 == NULL ->
//              runtime_error "This Mouse is no longer active"). cacheUIEvent 0064df60 copies the 0x14-byte event and
//              clears eventType; it is out of line (called by update 0064e660).
//   descriptors (dynamic initializers 007f8c40..007f8f30 in this order, category "Data" 00822490, Functionality 5):
//              SignalDesc<Mouse, void()> Move, Idle, Button1Down, Button2Down, Button1Up, Button2Up, WheelForward,
//              WheelBackward; SignalDesc<Mouse, void(std::string)> KeyDown ("Key"); PropDescriptor<Mouse,
//              CoordinateFrame> Hit / Origin (read only), RefPropDescriptor<Mouse, PartInstance> Target (read only),
//              PropDescriptor<Mouse, int> X, Y, ViewSizeX, ViewSizeY (read only), PropDescriptor<Mouse, TextureId>
//              Icon (getIcon 00642f80, setIcon 0064e180).
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
