// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::UnifiedWidget layout and drawing rows of the original gui/GUI.cpp unit (inactive):
// childOffset 005735a0, render2dMe 00574170, render2d 00574300, firstChildPosition 00574330,
// getChildPosition 00574400 and onLoseFocus 005cf4e0 (COMDAT-folded with Widget::onLoseFocus: one store of NOTHING at
// +0x144). Class in native-headers/gui/Gui.h (read-only here). render2dChildren 00574280 is called, not compiled here.
// render2dMe inlines GuiItem::menuSelect (00573250, the same local static 00974e2c guarded by 00974e3c), so that getter
// is defined in this unit ahead of render2dMe, as in the original GUI.cpp.
#include "gui/Gui.h"

namespace RBX
{
	// 00573250: (0.7, 0.7, 0.7, 1) from 008288b8 and fld1.
	const G3D::Color4& GuiItem::menuSelect()
	{
		static G3D::Color4 c(0.7f, 0.7f, 0.7f, 1.0f);
		return c;
	}

	// 005735a0: (0, 28.0f 0082f864).
	G3D::Vector2 UnifiedWidget::childOffset() const
	{
		return G3D::Vector2(0.0f, 28.0f);
	}

	// 00574170: adorn->rect2d (slot 11) / outlineRect2d (slot 10) of the out-of-line getMyRect2D 00573960, then
	// label2d 00573360 with Color3::black, Color4::clear (007baf10) and XAlign 2.
	void UnifiedWidget::render2dMe(Adorn* adorn)
	{
		adorn->rect2d(getMyRect2D(), menuState != NOTHING ? menuSelect() : G3D::Color4(G3D::Color3::white()));
		adorn->outlineRect2d(getMyRect2D(), 1.0f, G3D::Color3::black());
		label2d(adorn, getName(), G3D::Color3::black(), G3D::Color4::clear(), Adorn::XALIGN_CENTER);
	}

	// 00574300: isVisible (slot 21), render2dMe (slot 28), render2dChildren 00574280.
	void UnifiedWidget::render2d(Adorn* adorn)
	{
		if (isVisible())
		{
			render2dMe(adorn);
			render2dChildren(adorn);
		}
	}

	// 00574330: canvas height GuiRoot::canvasSize.y (00974d7c), rows of size.y + 4 between 20 and canvas - 120.
	G3D::Vector2 UnifiedWidget::firstChildPosition() const
	{
		G3D::Vector2 position = getPosition();
		G3D::Vector2 size = getSize();
		position.x = (size.x + 4.0f) + position.x;
		int rowHeight = int(size.y) + 4;
		int maxRows = (int(GuiRoot::getCanvasSize().y) - 120) / rowHeight;
		int row = (int(position.y) - 20) / rowHeight;
		int half = int(numChildren()) / 2;
		maxRows -= half;
		row = std::max(half, row);
		row = std::min(maxRows, row);
		position.y = float((row - half) * rowHeight + 20);
		return position;
	}

	// 00574400: firstChildPosition (slot 26), then childOffset (slot 27) per GuiItem child before `child`.
	G3D::Vector2 UnifiedWidget::getChildPosition(const GuiItem* child) const
	{
		G3D::Vector2 position = firstChildPosition();
		for (size_t i = 0; i < numChildren(); ++i)
		{
			const GuiItem* item = dynamic_cast<const GuiItem*>(getChild(i));
			if (item)
			{
				if (item == child)
					return position;
				position += childOffset();
			}
		}
		return position;
	}

	// 005cf4e0 (folded with Widget::onLoseFocus).
	void UnifiedWidget::onLoseFocus()
	{
		menuState = NOTHING;
	}
}
