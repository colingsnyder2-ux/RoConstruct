#pragma once
// >>> native-status (generated) -- do not edit >>>
// ArrowPanel | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src c8d05de1 | roc native-status --write
// 2008-06 native RBX::ArrowPanel and RBX::ArrowButton (inactive). Shape after the donor tools/rbxgs gui/ArrowPanel.h
// (the donor includes gui/Button.h; the 2008 button classes are in gui/WidgetButtons.h). Read from the binary
// (tests/record_native_widget.py checks it):
//   ArrowPanel   vtable 0084c164 .?AVArrowPanel@RBX@@ -> TopMenuBar -> GuiItem. dataModel +0x15c, controller +0x160
//                (isVisible 00656db0 reads both). getSize 00656bf0 (slot 23: TopMenuBar::getSize 00573e30 while
//                visible, else Vector2::zero). Constructor 00657780 / init 00657240 and isVisible not attempted.
//   ArrowButton  vtable 0084bffc .?AVArrowButton@RBX@@ -> ImageKeyButton. Constructor 006570a0 (Adorn*, const
//                std::string&, SDLKey, Controller::ControllerType, DataModel*; ret 0x14): ImageKeyButton(adorn, name,
//                key) 0064f500, the 11 vtables, dataModel +0x188, controller +0x18c. isEnabled 00657be0 (slot 30;
//                not attempted). Size 0x190.
#include "gui/WidgetButtons.h"
#include "v8world/Controller.h"

struct NativeWidgetLayout;

namespace RBX
{
	class DataModel;

	class ArrowPanel : public TopMenuBar
	{
	protected:
		DataModel* dataModel;                                        // +0x15c
		Controller::ControllerType controller;                       // +0x160

	public:
		ArrowPanel(Adorn*, DataModel*, Controller::ControllerType);  // 00657780 (not attempted)
		virtual bool isVisible() const;                              // slot 21, 00656db0 (not attempted)
		virtual G3D::Vector2 getSize() const;                        // slot 23, 00656bf0
		friend struct ::NativeWidgetLayout;
	};

	class ArrowButton : public ImageKeyButton
	{
	private:
		DataModel* dataModel;                                        // +0x188
		Controller::ControllerType controller;                       // +0x18c

	public:
		ArrowButton(Adorn*, const std::string&, SDLKey, Controller::ControllerType, DataModel*);  // 006570a0
		virtual bool isEnabled();                                    // slot 30, 00657be0 (not attempted)
		friend struct ::NativeWidgetLayout;
	};
}
