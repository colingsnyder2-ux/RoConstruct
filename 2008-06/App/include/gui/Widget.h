#pragma once
// >>> native-status (generated) -- do not edit >>>
// Widget | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 0c62fa5d | roc native-status --write
// 2008-06 native RBX::Widget and RBX::VerbWidget (inactive). Shape after the donor tools/rbxgs gui/Widget.h; the
// virtual order of the donor matches the 2008 vtables slot for slot, so every unit that already used the donor header
// (Hopper/BackpackItem, Tool, Flag, Backpack) compiles the same declarations. MultiVerbWidget is left out: the 2008-06
// binary has no RTTI for it. Every base, field and size below is read from the binary
// (tests/record_native_widget.py checks them):
//   Widget      vtable 0084a6a4 .?AVWidget@RBX@@ -> GuiItem -> Instance (+ GuiTarget +0x130, vtable 0084a61c whose one
//               slot is Widget::process 00642210, compiled against the GuiTarget subobject). Constructor 006422b0:
//               GuiItem() 005739d0, the 11 Widget vtables, widgetState (+0x144) = NOTHING, then the inline
//               GuiItem::setGuiSize: guiSize (+0x13c/+0x140) = (100.0f 008163a4, 24.0f 0082f85c; the donor has 25). No own destructor:
//               the deleting destructor thunks 00642340/00642350/00642360 jump to the shared GuiItem one 00574150.
//               Size 0x148 (VerbWidget::verb follows at +0x148).
//               Slots 16..30 of 0084a6a4: onLoseFocus 005cf4e0, canLoseFocus 0060a2f0, getPosition 004117f0,
//               getChildPosition 00411810, getFontSize 005cf4f0, isVisible 00565950, getTitle 00411840, getSize
//               00411870, render2d 00642520, onClick/onDown/onUp 0070bdf0 (empty), onDrag 0068e880, getFontColor
//               005cf500, isEnabled 005cf530. processMouse 00641ff0 is non-virtual (direct call from 00642210).
//   VerbWidget  vtable 0084a7ac .?AVVerbWidget@RBX@@ -> Widget. Constructor 00642370 (Widget() 006422b0, verb +0x148);
//               destructor 006424a0 (user-declared virtual, body empty: vtables then ~GuiItem 00411540), scalar deleting
//               destructor 00642500. onClick 00642270 (slot 25), isEnabled 006423e0 (slot 30). Size 0x14c (MenuItem
//               and ImageButton fields start there).
#include "gui/Gui.h"
#include "v8tree/Verb.h"

struct NativeWidgetLayout;

namespace RBX
{
	class Widget : public GuiItem
	{
	public:
		enum WidgetState
		{
			NOTHING,
			HOVER,
			DOWN_OVER,
			DOWN_AWAY
		};

	protected:
		WidgetState widgetState;                                     // +0x144 (00642316)

	private:
		GuiResponse processMouse(const GuiEvent&);                   // 00641ff0
	protected:
		virtual GuiResponse process(const GuiEvent& event);          // 00642210 (GuiTarget slot 0)

		virtual void onLoseFocus()                                   // slot 16, 005cf4e0
		{
			widgetState = Widget::NOTHING;
		}

		virtual void render2d(Adorn* adorn);                         // slot 24, 00642520

		virtual void onClick(const GuiEvent&)                        // slot 25, 0070bdf0
		{
			return;
		}

		virtual bool onDrag(const GuiEvent& event)                   // slot 26, 0068e880
		{
			return false;
		}

		virtual void onDown(const UIEvent& event)                    // slot 27, 0070bdf0
		{
			return;
		}

		virtual void onUp(const UIEvent&)                            // slot 28, 0070bdf0
		{
			return;
		}

		virtual int getFontSize() const                              // slot 20, 005cf4f0
		{
			return 12;
		}

		virtual G3D::Color4 getFontColor()                           // slot 29, 005cf500
		{
			return G3D::Color3::white();
		}

		virtual bool isEnabled()                                     // slot 30, 005cf530
		{
			return isVisible();
		}

	public:
		Widget();                                                    // 006422b0
		friend struct ::NativeWidgetLayout;
	};

	class VerbWidget : public Widget
	{
	private:
		Verb* verb;                                                  // +0x148 (00642370)

	protected:
		virtual bool isEnabled();                                    // slot 30, 006423e0
		virtual void onClick(const GuiEvent&);                       // slot 25, 00642270
	public:
		VerbWidget(Verb*);                                           // 00642370
		virtual ~VerbWidget();                                       // 006424a0
		friend struct ::NativeWidgetLayout;
	};
}
