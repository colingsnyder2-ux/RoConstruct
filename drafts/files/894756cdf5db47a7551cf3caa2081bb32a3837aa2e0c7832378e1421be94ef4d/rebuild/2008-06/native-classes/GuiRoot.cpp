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

	G3D::Vector2 GuiRoot::toPixelSize(const G3D::Vector2& size)
	{
		G3D::Vector2 result(0.0f, 0.0f);

		if (canvasSize.y == canvasSize.x * 0.75f)
		{
			result.x = size.x * 0.01f * canvasSize.x;
			result.y = size.y * 0.01f * 0.75f * canvasSize.x;
		}
		else
		{
			result.x = size.x * 0.01f * 1.33f * canvasSize.x;
			result.y = size.y * 0.01f * canvasSize.x;
		}

		return result;
	}

	void GuiRoot::render2d(Adorn* adorn)
	{
		int height = adorn->getHeight();
		int width = adorn->getWidth();
		canvasSize = G3D::Vector2((float)width, (float)height);

		for (size_t i = 0; i < numChildren(); ++i)
		{
			GuiItem* item = dynamic_cast<GuiItem*>(getChild(i));
			if (item)
				item->render2d(adorn);
		}
	}
}
