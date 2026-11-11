#include "gui/Gui.h"
#include "gui/GUI.h"
#include "util/object.h"

namespace RBX {
void TopMenuBar::init()
{
	layoutStyle = Layout::HORIZONTAL;
	backdropColor = G3D::Color4::clear();
	visible = true;
}
}
