// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/gui/Gui.h"

namespace RBX {
void UnifiedWidget::render2dMe(Adorn* adorn)
{
	{
		G3D::Color4 temporary;
		const G3D::Color4* color;
		if (menuState) {
			static G3D::Color4 selectedColor(0.7f, 0.7f, 0.7f, 1.0f);
			color = &selectedColor;
		} else {
			const G3D::Color3& v = G3D::Color3::white();
			temporary.r = v.r;
			temporary.g = v.g;
			temporary.b = v.b;
			temporary.a = 1.0f;
			color = &temporary;
		}
		adorn->rect2d((this->*(&UnifiedWidget::getMyRect2D))(), *color);
	}
	adorn->outlineRect2d((this->*(&UnifiedWidget::getMyRect2D))(), 1.0f, G3D::Color4(G3D::Color3::black(), 1.0f));
	label2d(adorn, getName(), G3D::Color4(G3D::Color3::black(), 1.0f), G3D::Color4::zero(), Adorn::XALIGN_CENTER);
}
}
