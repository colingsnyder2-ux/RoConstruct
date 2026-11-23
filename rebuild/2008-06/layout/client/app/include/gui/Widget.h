// =============================================================================
// Widget.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/gui/Widget.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
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
		Verb* getVerb() { return verb; }                             // 00609a40
		virtual bool isEnabled();                                    // slot 30, 006423e0
		virtual void onClick(const GuiEvent&);                       // slot 25, 00642270
	public:
		VerbWidget(Verb*);                                           // 00642370
		virtual ~VerbWidget();                                       // 006424a0
		friend struct ::NativeWidgetLayout;
	};
}
