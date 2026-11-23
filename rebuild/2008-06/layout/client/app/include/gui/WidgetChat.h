// =============================================================================
// WidgetChat.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/gui/WidgetChat.h
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
	class ChatWidget : public UnifiedWidget
	{
	private:
		std::string code;                                            // +0x148

	private:
		virtual void onMenuStateChanged();                           // slot 25, 0064e8a0 (pending)
		virtual GuiResponse process(const GuiEvent&);                // 0064ead0 (not attempted)
	public:
		ChatWidget(const std::string&, std::string);                 // 0064e8c0
		friend struct ::NativeWidgetLayout;
	};

	class UnifiedImageWidget : public UnifiedWidget
	{
	protected:
		GuiDrawImage guiImageDraw;                                   // +0x148

	public:
		UnifiedImageWidget(Adorn*, const std::string&);              // 00601c50
		virtual void render2dMe(Adorn*);                             // slot 28, 0064e840
		virtual G3D::Vector2 getSize() const;                        // slot 23, 0064f280
		friend struct ::NativeWidgetLayout;
	};

	class ChatButton : public UnifiedImageWidget
	{
	private:
		virtual bool isVisible() const;                              // slot 21, 0064ea90 (not attempted)
	public:
		ChatButton(Adorn*, const std::string&);                      // 00601d00
	};
}
