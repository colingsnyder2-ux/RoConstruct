// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::TopMenuBar unit (inactive): init 00573530..0057356e, the (name, Layout::Style, bool)
// constructor 00573cb0..00573df8, the isVisible inline body 00573e00 and the generated destructor family
// (dtor 00573e20, scalar deleting destructor 00574150, subobject adjustor thunks 00573e10/00574130/00574140).
// Layout and addresses in native-headers/gui/Gui.h (class TopMenuBar, declared after TextDisplay).
// getChildPosition 00573f30, getSize 00573e30 and render2d 00574050 are NOT recovered here: see
// work/2008-06/shared-layouts/top-menu-bar-20261106.json for their evidence and next proof.
#include "gui/Gui.h"

namespace RBX
{
	void TopMenuBar::init()
	{
		layoutStyle = Layout::HORIZONTAL;
		backdropColor = G3D::Color4::clear();
		visible = true;
	}

	TopMenuBar::TopMenuBar(const std::string& name, Layout::Style style, bool visible)
		: GuiItem()
	{
		layoutStyle = Layout::HORIZONTAL;
		backdropColor = G3D::Color4::clear();
		this->visible = true;
		setName(name);
		this->layoutStyle = style;
		if (visible)
			backdropColor = G3D::Color4(0.6f, 0.6f, 0.6f, 0.6f);
	}
}
