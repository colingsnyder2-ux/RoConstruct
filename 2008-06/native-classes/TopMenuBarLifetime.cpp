// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// RBX::TopMenuBar constructors (2008-06 native, inactive). Sibling methods live in TopMenuBar.cpp.
#include "gui/Gui.h"
#include "gui/GUI.h"
#include "util/object.h"

namespace RBX {
// 00573cb0 (??0TopMenuBar@RBX@@QAE@ABV?$basic_string...@W4Style@Layout@1@_N@Z): GuiItem base 005739d0, the
// init() stores inline (0x154 = 0, 0x144 = Color4::clear(), 0x158 = 1), setName 0055af90, then the style and,
// when the flag is set, a guarded static Color4 of 0.6f (0082f838) copied into the backdrop.
TopMenuBar::TopMenuBar(const std::string& name, Layout::Style style, bool translucent)
{
	layoutStyle = Layout::HORIZONTAL;
	backdropColor = G3D::Color4::clear();
	visible = true;
	setName(name);
	layoutStyle = style;
	if (translucent) {
		// INFERRED: guarded local static (guard 00974e50 bit 0, storage 00974e40); the same 0.6f grey as
		// GuiItem::translucentBackdrop() may be what the original inlined here.
		static G3D::Color4 c(0.6f, 0.6f, 0.6f, 0.6f);
		backdropColor = c;
	}
}
}
