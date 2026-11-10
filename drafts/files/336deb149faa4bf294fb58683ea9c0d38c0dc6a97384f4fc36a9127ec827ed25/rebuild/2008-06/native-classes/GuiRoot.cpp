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
	G3D::Vector2 result(0.0f, 0.0f);

	if (canvasSize.y == canvasSize.x * 0.75f)
	{
		result.x = canvasSize.x * 0.75f * (size.y * 0.01f);
		result.y = canvasSize.x * (size.x * 0.01f);
	}
	else
	{
		result.x = canvasSize.y * 1.33f * (size.y * 0.01f);
		result.y = canvasSize.y * (size.x * 0.01f);
	}

	return result;
}

void GuiRoot::render2d(Adorn* adorn)
	{
		unsigned short height = (unsigned short)adorn->getHeight();
		short width = (short)adorn->getWidth();
		canvasSize = G3D::Vector2((float)(short)height, (float)width);

		for (size_t i = 0; i < numChildren(); ++i)
		{
			GuiItem* item = dynamic_cast<GuiItem*>(getChild(i));
			if (item)
				item->render2d(adorn);
		}
	}
}
