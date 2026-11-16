// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include "gui/Gui.h"
namespace RBX {
GuiItem* GuiItem::getGuiParent() { return dynamic_cast<GuiItem*>(getParent()); }
const GuiItem* GuiItem::getGuiParent() const { return dynamic_cast<const GuiItem*>(getParent()); }
Rect GuiItem::getMyRect() const {
    G3D::Vector2 pos = getPosition();
    return Rect(pos, pos + getSize());
}
}
