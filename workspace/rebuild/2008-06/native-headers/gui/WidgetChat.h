#pragma once
// >>> native-status (generated) -- do not edit >>>
// WidgetChat | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src ee28700a | roc native-status --write
// 2008-06 native RBX::ChatWidget, RBX::UnifiedImageWidget and RBX::ChatButton (inactive). Shape after the donor
// tools/rbxgs gui/ChatWidget.h (a differently named header so that it does not shadow the donor one). Every base,
// field and size below is read from the binary (tests/record_native_widget.py checks them):
//   ChatWidget          vtable 0084b4e4 .?AVChatWidget@RBX@@ -> UnifiedWidget -> GuiItem. Constructor 0064e8c0
//                       (const std::string& title, std::string code; ret 0x20): UnifiedWidget() 00600540, the 11
//                       vtables, code +0x148 (std::string), setName(title), code = argument. onMenuStateChanged
//                       0064e8a0 (slot 25; reads menuState +0x144 directly: NATIVE_WIDGET_PENDING), process 0064ead0
//                       (GuiTarget slot, vtable 0084b45c; not attempted: Players / chat). Destructor 0064ea20 (its
//                       extent also covers the deleting destructor 0064ea70: bounds). Size 0x164.
//   UnifiedImageWidget  vtable 0084222c -> UnifiedWidget. guiImageDraw +0x148 (GuiDrawImage, 0x38 bytes). Constructor
//                       00601c50 (Adorn*, const std::string&): UnifiedWidget() 00600540, GuiDrawImage(adorn, name)
//                       006010e0 (no setName). render2dMe 0064e840 (slot 28; menuState +0x144 read directly:
//                       NATIVE_WIDGET_PENDING), getSize 0064f280 (slot 23, shared with ImageWidget::getSize).
//                       Destructor 0064f2f0 (shared with ImageWidget). Size 0x180.
//   ChatButton          vtable 0084232c -> UnifiedImageWidget. Constructor 00601d00 (Adorn*, const std::string&).
//                       isVisible 0064ea90 (slot 21; local Player lookup, not attempted).
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
