// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::UnifiedWidget layout and drawing rows of the original gui/GUI.cpp unit (inactive):
// childOffset 005735a0, TopMenuBar::render2d 00574050, render2dMe 00574170, render2d 00574300, firstChildPosition 00574330,
// getChildPosition 00574400 and onLoseFocus 005cf4e0 (COMDAT-folded with Widget::onLoseFocus: one store of NOTHING at
// +0x144) and render2dChildren 00574280. Class in native-headers/gui/Gui.h (read-only here).
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

	// 00573310: Rect(getPosition (slot 18), getPosition + getSize (slot 23)). Defined in this unit as in GUI.cpp: with
	// it visible, the inline GuiItem::getMyRect2D grows past the inliner and render2dMe calls it out of line (00573960).
	Rect GuiItem::getMyRect() const
	{
		G3D::Vector2 position = getPosition();
		return Rect(position, position + getSize());
	}

	// 00573360 (203 B, ret 0x14): ?label2d@GuiItem@RBX@@IBEXPAVAdorn@2@ABV?$basic_string@...@ABVColor4@G3D@@2W4XAlign@32@@Z
	// (registry). Body of the donor openrbx gui/GUI.cpp GuiItem::label2d: empty label returns; getMyRect 00573310;
	// size/center (0.5f 00819bac); XALIGN_RIGHT high.x - 0.1f (0081e704) * size.x, XALIGN_LEFT low.x + ...;
	// getFontSize (slot 0x50), then Adorn::drawFont2D (slot 0x34) with YALIGN_CENTER (2), PROPORTIONAL_SPACING (0).
	// PARKED after 3 hypotheses (203 B, same size): only the x87 commutative mirror of center().x remains (target
	// fld st(2); fadd st(1) = high.x + low.x, candidate fld st(0); fadd st(3)). Rejected: (high + low) * 0.5f inline
	// (also mirrors y and swaps esi/edi, 201 B); center() before size() (fstp/fxch reshuffle in the switch).
	void GuiItem::label2d(Adorn* adorn, const std::string& label, const G3D::Color4& fill, const G3D::Color4& border,
		Adorn::XAlign align) const
	{
		if (label.size() == 0)
			return;

		Rect myRect = getMyRect();

		G3D::Vector2 size = myRect.size();
		G3D::Vector2 pos = myRect.center();

		switch (align)
		{
		case Adorn::XALIGN_RIGHT:
			pos.x = myRect.high.x - size.x * 0.1f;
			break;

		case Adorn::XALIGN_CENTER:
			break;

		default:
			pos.x = myRect.low.x + size.x * 0.1f;
			break;
		}

		adorn->drawFont2D(label, pos, getFontSize(), fill, border, align, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
	}

	// 005736f0 ?toPixelSize@GuiRoot@RBX@@SA?AVVector2@G3D@@ABV34@@Z (registry; callers PercentPanel::getPosition 005738e0
	// and the LocalBackpack/Hopper font sizing call it out of line, so it is kept here, away from GuiPanels.cpp where
	// /Ob2 inlined it into PercentPanel::getPosition). Read from the original: answer zeroed first; canvasSize
	// (00974d78/00974d7c) fitted to 4:3: width * 0.75f (0082f840) when canvas.y is larger, else canvas.y * 1.33f
	// (0082f86c); then percent * 0.01f (0082748c) per axis, the tail duplicated per branch. No donor body (openrbx
	// GUI.cpp only calls it).
	// PARKED after 3 hypotheses (114 of 114 B, closest): only the x87 commutative mirror of x = (percent.x * 0.01f) *
	// width remains in the first branch (target fxch st(3); fmulp st(1), candidate fxch st(1); fmulp st(3)) plus the
	// pop order entering the else branch (target fstp st(1) twice, candidate fstp st(2); fstp st(0)). Rejected: one
	// size Vector2 with `canvasSize.y <= size.y` reassignment (93 B, jp merge, no tail duplication); size * (percent *
	// 0.01f) operand order (112 B, worse).
	G3D::Vector2 GuiRoot::toPixelSize(const G3D::Vector2& percent)
	{
		G3D::Vector2 answer;
		float width = canvasSize.x;
		float height = width * 0.75f;
		if (canvasSize.y > height)
			answer = percent * 0.01f * G3D::Vector2(width, height);
		else
			answer = percent * 0.01f * G3D::Vector2(canvasSize.y * 1.33f, canvasSize.y);
		return answer;
	}

	// 005735a0: (0, 28.0f 0082f864).
	G3D::Vector2 UnifiedWidget::childOffset() const
	{
		return G3D::Vector2(0.0f, 28.0f);
	}

	// 00574050: backdrop rect2d (Adorn slot 0x2c) when backdropColor != Color4::clear() 007baf10, then children.
	// Moved from GuiPanels.cpp: byte-exact only in this unit, which also defines GuiItem::getMyRect 00573310 (the
	// original GUI.cpp), so the inline getMyRect2D is called out of line (00573960) as in the original.
	void TopMenuBar::render2d(Adorn* adorn)
	{
		if (isVisible())
		{
			if (backdropColor != G3D::Color4::clear())
				adorn->rect2d(getMyRect2D(), backdropColor);

			for (size_t i = 0; i < numChildren(); i++)
			{
				GuiItem* current = dynamic_cast<GuiItem*>(getChild(i));
				if (current)
					current->render2d(adorn);
			}
		}
	}

	// 00574170: adorn->rect2d (slot 11) / outlineRect2d (slot 10) of the out-of-line getMyRect2D 00573960, then
	// label2d 00573360 with Color3::black, Color4::clear (007baf10) and XAlign 2.
	void UnifiedWidget::render2dMe(Adorn* adorn)
	{
		adorn->rect2d(getMyRect2D(), menuState != NOTHING ? menuSelect() : G3D::Color4(G3D::Color3::white()));
		adorn->outlineRect2d(getMyRect2D(), 1.0f, G3D::Color3::black());
		label2d(adorn, getName(), G3D::Color3::black(), G3D::Color4::clear(), Adorn::XALIGN_CENTER);
	}

	// 00574280 (func_00574280, 119 B, ret 4): identity from the donor openrbx GUI.cpp UnifiedWidget::render2dChildren
	// (showChildren, then render2d of every GuiItem child) and its only caller render2d 00574300 below; numChildren
	// 0048ae20, dynamic_cast Instance 0092907c -> GuiItem 0092b8d8, GuiItem::render2d vtable slot 0x60.
	void UnifiedWidget::render2dChildren(Adorn* adorn)
	{
		if (showChildren())
		{
			for (size_t i = 0; i < numChildren(); ++i)
			{
				GuiItem* item = dynamic_cast<GuiItem*>(getChild(i));
				if (item)
					item->render2d(adorn);
			}
		}
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
