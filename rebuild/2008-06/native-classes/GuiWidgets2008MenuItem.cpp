// 2008-06 native RBX::MenuItem::render2d 0064edb0 (slot 24 of 0084b5f4), the last row of the MenuItem unit
// 0064ebf0..0064ef90 that native-classes/WidgetMenuItem.cpp (tests/record_native_widget.py) does not compile. Class and
// layout in native-headers/gui/WidgetMenuItem.h (read-only here); verified by tests/record_native_gui_widgets2008.py.
//
// Read from the original: widgetState +0x144 HOVER / DOWN_OVER (0064edda) -> adorn->rect2d (slot 11, 0064ee1a) of the
// inline GuiItem::getMyRect2D (getMyRect 00573310, Rect2D::xyxy 004f35d0) in the colour 00573250; isEnabled (slot 30) is
// called twice, the first result unused (0064ee1c..0064ee23); the title colour is 005731d0 when enabled, else 00573210;
// verb (+0x148, read directly) && verb->isChecked() (Verb slot 3, 0064ee51) prefixes "x " (0084b670) to getTitle()
// (slot 22); label2d 00573360 with Color4::clear 007baf10 and XAlign 1 (XALIGN_LEFT); then, when accelerator (+0x14c)
// is not empty (_Mysize +0x160 at 0064ef32), the accelerator with XAlign 0 (XALIGN_RIGHT).
// The three GuiItem colour getters have no evidence names: 00573250 (0.7, 0.7, 0.7, 1), 005731d0 (0.3, 0.3, 0.3, 1),
// 00573210 (0.6, 0.6, 0.6, 1) are written as menuSelect / menuEnabledFill / menuDisabledFill of gui/Gui.h (codegen
// analogs; the recorder binds them by their call sites).
//
// NATIVE_GUIWIDGETS_PENDING: the body needs `Verb* getVerb() { return verb; }` (the donor's protected accessor) in
// VerbWidget (gui/Widget.h, owner: widget family); the generated overlay under out/native-layouts/gui-widgets2008-pending
// supplies it.
#include "gui/WidgetMenuItem.h"

namespace RBX
{
#ifdef NATIVE_GUIWIDGETS_PENDING
	void MenuItem::render2d(Adorn* adorn)
	{
		if (widgetState == HOVER || widgetState == DOWN_OVER)
			adorn->rect2d(getMyRect2D(), GuiItem::menuSelect());

		bool enabled = isEnabled();
		const G3D::Color4& fontColor = isEnabled() ? GuiItem::menuEnabledFill() : GuiItem::menuDisabledFill();
		label2d(adorn, (getVerb() && getVerb()->isChecked()) ? "x " + getTitle() : getTitle(), fontColor,
				G3D::Color4::clear(), Adorn::XALIGN_LEFT);

		if (accelerator.size() > 0)
			label2d(adorn, accelerator, isEnabled() ? GuiItem::menuEnabledFill() : GuiItem::menuDisabledFill(),
					G3D::Color4::clear(), Adorn::XALIGN_RIGHT);
	}
#endif
}
