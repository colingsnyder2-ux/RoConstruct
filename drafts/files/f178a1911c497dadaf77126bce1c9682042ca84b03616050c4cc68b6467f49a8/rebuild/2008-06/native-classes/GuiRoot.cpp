// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::GuiRoot unit (inactive): 00573b10..00573c46 (ctor, getSize inline body, render2d).
// Layout and addresses in native-headers/gui/Gui.h (class GuiRoot, declared after PercentPanel).
#include "gui/Gui.h"

namespace RBX
{
	GuiRoot::GuiRoot()
		: GuiItem()
	{
		setName("GuiRoot");
	}

	// toPixelSize reads the canvasSize statics directly and compares canvasSize.y against canvasSize.x * 0.75f.
// The original's x87 trace fixes the grouping: x = (canvas.x*A) * (0.01f*size.y) and y = canvas.x * (0.01f*size.x),
// with the else branch using canvas.y and the reciprocal constant (0x82f86c). Precise FP is what produces the
// original's fused fxch/fmulp sequence; /fp:fast reassociates it away - but /fp:fast is what render2d needs.
G3D::Vector2 GuiRoot::toPixelSize(const G3D::Vector2& size)
{
	G3D::Vector2 pixelSize(0, 0);

	if (canvasSize.y > 0.75f * canvasSize.x)
		pixelSize = (0.01f * size) * G3D::Vector2(canvasSize.x, 0.75f * canvasSize.x);
	else
		pixelSize = (0.01f * size) * G3D::Vector2(1.33f * canvasSize.y, canvasSize.y);

	return pixelSize;
}

void GuiRoot::render2d(Adorn* adorn)
	{
		unsigned short height = (unsigned short)adorn->getHeight();
		short width = (short)adorn->getWidth();
		canvasSize = G3D::Vector2((float)width, (float)(short)height);

		for (size_t i = 0; i < numChildren(); ++i)
		{
			GuiItem* item = dynamic_cast<GuiItem*>(getChild(i));
			if (item)
				item->render2d(adorn);
		}
	}
}
