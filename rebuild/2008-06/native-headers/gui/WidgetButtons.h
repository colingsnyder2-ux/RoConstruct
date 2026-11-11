#pragma once
// >>> native-status (generated) -- do not edit >>>
// WidgetButtons | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8be27ac8 | roc native-status --write
// 2008-06 native RBX::KeyButton, ImageWidget, ImageButton and ImageKeyButton (inactive): the original gui Button unit
// 0064ef90..0064f6a0. Shape after the donor tools/rbxgs gui/Button.h (TextButton, ImageToggleButton and
// MultiImageButton are left out: the 2008-06 binary has no RTTI for them). A differently named header so that it does
// not shadow the donor gui/Button.h. Every base, field and size below is read from the binary
// (tests/record_native_widget.py checks them):
//   KeyButton       vtable 0084b70c .?AVKeyButton@RBX@@ -> Widget. Constructor 0064f110 (const std::string& name,
//                   SDLKey): Widget() 006422b0, keyCode +0x148, keyIsDown +0x14c = false, the 11 vtables, setName.
//                   process 0064ef90 (GuiTarget slot, vtable 0084b684), onDown 0064efd0 / onUp 0064eff0 (slots 27/28:
//                   UserInputBase::setKeyState, slot 6). isEnabled is Widget's (slot 30 = 005cf530), so no override.
//                   Size 0x150 (ImageKeyButton::imageDraw follows at +0x150).
//   ImageWidget     vtable 0084b814 -> Widget. guiImageDraw +0x148 (GuiDrawImage, 0x38 bytes). Constructor 0064f1c0
//                   (Adorn*, const std::string&): GuiDrawImage(Adorn*, const std::string&) 006010e0, then setName with
//                   the same string. render2d 0064f070 (slot 24), getSize 0064f280 (slot 23, GuiDrawImage::
//                   getImageSize 00642690). Implicit destructor 0064f2f0 (~GuiDrawImage 005cf360, ~GuiItem 00411540),
//                   deleting destructor 0064f670. Size 0x180.
//   ImageButton     vtable 0084b91c -> VerbWidget. guiImageDraw +0x14c. Constructor 0064f340 (Adorn*, Verb*,
//                   const std::string&): VerbWidget(verb) 00642370, GuiDrawImage(adorn, verb's name string)
//                   (Verb::getName inline, NATIVE_WIDGET_PENDING), setName(title). render2d 0064f0c0, getSize
//                   0064f410, destructor 0064f4b0 (~GuiDrawImage, ~VerbWidget 006424a0), deleting 0064f690. Size 0x184.
//   ImageKeyButton  vtable 0084ba24 -> KeyButton. imageDraw +0x150. Constructor 0064f500 (Adorn*, const std::string&,
//                   SDLKey): KeyButton(name, key) 0064f110, GuiDrawImage(adorn, name). render2d 0064f010 (DOWN_OVER
//                   image while the key is down), getSize 0064f5c0, destructor 0064f600, deleting 0064f650. Size
//                   0x188 (ArrowButton derives from it).
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
