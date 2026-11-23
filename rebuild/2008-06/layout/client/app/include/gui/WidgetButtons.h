// =============================================================================
// WidgetButtons.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/gui/WidgetButtons.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "gui/Widget.h"
#include "gui/GuiDraw.h"

struct NativeWidgetLayout;

namespace RBX
{
	class KeyButton : public Widget
	{
	private:
		SDLKey keyCode;                                              // +0x148
	protected:
		bool keyIsDown;                                              // +0x14c (read by ImageKeyButton::render2d 0064f021)

	protected:
		virtual void onDown(const UIEvent&);                         // slot 27, 0064efd0
		virtual void onUp(const UIEvent&);                           // slot 28, 0064eff0
		virtual GuiResponse process(const GuiEvent&);                // 0064ef90
	public:
		KeyButton(const std::string&, SDLKey);                       // 0064f110
		friend struct ::NativeWidgetLayout;
	};

	class ImageWidget : public Widget
	{
	private:
		GuiDrawImage guiImageDraw;                                   // +0x148

	public:
		ImageWidget(Adorn*, const std::string&);                     // 0064f1c0
		virtual void render2d(Adorn*);                               // slot 24, 0064f070
		virtual G3D::Vector2 getSize() const;                        // slot 23, 0064f280
		friend struct ::NativeWidgetLayout;
	};

	class ImageButton : public VerbWidget
	{
	protected:
		GuiDrawImage guiImageDraw;                                   // +0x14c

	public:
		ImageButton(Adorn*, Verb*, const std::string&);              // 0064f340
		virtual void render2d(Adorn*);                               // slot 24, 0064f0c0
		virtual G3D::Vector2 getSize() const;                        // slot 23, 0064f410
		friend struct ::NativeWidgetLayout;
	};

	class ImageKeyButton : public KeyButton
	{
	private:
		GuiDrawImage imageDraw;                                      // +0x150

	public:
		ImageKeyButton(Adorn*, const std::string&, SDLKey);          // 0064f500
		virtual void render2d(Adorn*);                               // slot 24, 0064f010
		virtual G3D::Vector2 getSize() const;                        // slot 23, 0064f5c0
		friend struct ::NativeWidgetLayout;
	};
}
