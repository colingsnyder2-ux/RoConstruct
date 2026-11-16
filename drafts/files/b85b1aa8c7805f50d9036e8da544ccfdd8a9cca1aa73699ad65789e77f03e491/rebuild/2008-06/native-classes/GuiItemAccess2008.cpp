// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include "gui/Gui.h"
namespace RBX {
GuiItem* GuiItem::getGuiParent() { return dynamic_cast<GuiItem*>(getParent()); }
const GuiItem* GuiItem::getGuiParent() const { return dynamic_cast<const GuiItem*>(getParent()); }
Rect GuiItem::getMyRect() const {
    G3D::Vector2 pos = getPosition();
    return Rect(pos, pos + getSize());
}
void GuiItem::label2d(
	Adorn* adorn,
	const std::string& label,
	const G3D::Color4& fill,
	const G3D::Color4& border,
	Adorn::XAlign align
) const
{
	if (label.size() == 0) {
		return;
	}

	Rect myRect = getMyRect();

	G3D::Vector2 size = myRect.size();
	G3D::Vector2 pos = myRect.center();

	switch (align) {
	case Adorn::XALIGN_RIGHT:
		pos.x = myRect.high.x - size.x * 0.1f;
		break;

	case Adorn::XALIGN_CENTER:
		break;

	default:
		pos.x = myRect.low.x + size.x * 0.1f;
		break;
	}

	adorn
		->drawFont2D(label, pos, getFontSize(), fill, border, align, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
}


GuiItem* GuiItem::getGuiItem(int index) { return dynamic_cast<GuiItem*>(getChild(index)); }
void GuiItem::addGuiItem(boost::shared_ptr<GuiItem> item) { item->setParent(this); }
}
