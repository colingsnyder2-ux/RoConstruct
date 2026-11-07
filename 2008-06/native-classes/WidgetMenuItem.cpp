// 2008-06 native gui MenuItem unit (inactive): 0064ebf0..0064ef90.
// Layout and addresses in native-headers/gui/WidgetMenuItem.h; verified by tests/record_native_widget.py.
// >>> native-status (generated) -- do not edit >>>
// WidgetMenuItem | 2008-06 | linked
// 1/1 exact by name (100%) | 1/1 exact bodies | no strings | verified 2026-11-07| by king_originala (deepseek:deepseek-flash)
// <<< native-status | src 1994490b | roc native-status --write
#include "gui/WidgetMenuItem.h"

namespace RBX
{
	MenuItem::MenuItem(Verb* verb, const std::string& title)
		: VerbWidget(verb)
	{
		setName(title);
		setGuiSize(G3D::Vector2(200.0f, 24.0f));
	}

	bool MenuItem::canLoseFocus()
	{
		return true;
	}
}
