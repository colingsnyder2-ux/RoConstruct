// 2008-06 native gui MenuItem unit (inactive): 0064ebf0..0064ef90.
// Layout and addresses in native-headers/gui/WidgetMenuItem.h; verified by tests/record_native_widget.py.
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
