#pragma once
// 2008-06 native RBX::MenuItem (inactive). Shape after the donor tools/rbxgs gui/MenuItem.h (a differently named
// header so that it does not shadow the donor one). Read from the binary (tests/record_native_widget.py checks it):
//   MenuItem  vtable 0084b5f4 .?AVMenuItem@RBX@@ -> VerbWidget -> Widget. Constructor 0064ebf0 (Verb*, const
//             std::string&; ret 8): VerbWidget(verb) 00642370, the 11 vtables, accelerator +0x14c (std::string),
//             setName(title), guiSize = (200.0f 00819ba8, 24.0f 0082f85c). Destructor 0064ecd0 (~std::string,
//             ~VerbWidget 006424a0), deleting destructor 0064ed90. canLoseFocus (slot 17) = 00565950 (`return true`,
//             shared). render2d 0064edb0 (slot 24; not attempted). Size 0x168.
#include "gui/Widget.h"

struct NativeWidgetLayout;

namespace RBX
{
	class MenuItem : public VerbWidget
	{
	private:
		std::string accelerator;                                     // +0x14c

	protected:
		virtual bool canLoseFocus();                                 // slot 17, 00565950
	public:
		MenuItem(Verb*, const std::string&);                         // 0064ebf0
		virtual void render2d(Adorn*);                               // slot 24, 0064edb0 (not attempted)
		friend struct ::NativeWidgetLayout;
	};
}
