// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// TopMenuBar | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by auto
// <<< native-status | src eb31b416 | roc native-status --write
#include "gui/Gui.h"
#include "gui/GUI.h"
#include "util/object.h"

namespace RBX {
// 00573f30: center the target on the cross-axis; the older behavioural glue omits this adjustment.
G3D::Vector2 TopMenuBar::getChildPosition(const GuiItem* child) const
{
    G3D::Vector2 position = getPosition();
    G3D::Vector2 size = getSize();
    for (size_t i = 0; i < numChildren(); ++i) {
        const GuiItem* item = dynamic_cast<const GuiItem*>(getChild(i));
        if (item) {
            G3D::Vector2 childSize = item->getSize();
            if (item == child) {
                int crossAxis = (layoutStyle + 1) % 2;
                position[crossAxis] += (size[crossAxis] - childSize[crossAxis]) * 0.5f;
                return position;
            }
            switch (layoutStyle) {
            case Layout::HORIZONTAL:
            case Layout::VERTICAL:
                position[layoutStyle] += item->getSize()[layoutStyle];
                break;
            }
        }
    }
    return position;
}

// 00573e30: sum along the layout direction and retain the maximum cross-axis size.
G3D::Vector2 TopMenuBar::getSize() const
{
    G3D::Vector2 result(0.0f, 0.0f);
    for (size_t i = 0; i < numChildren(); ++i) {
        const GuiItem* item = dynamic_cast<const GuiItem*>(getChild(i));
        if (item) {
            G3D::Vector2 size = item->getSize();
            switch (layoutStyle) {
            case Layout::HORIZONTAL:
                result.x += size.x;
                result.y = G3D::max(result.y, size.y);
                break;
            case Layout::VERTICAL:
                result.x = G3D::max(result.x, size.x);
                result.y += size.y;
                break;
            }
        }
    }
    return result;
}

// 00574050: visibility gates the backdrop and child draw traversal.
void TopMenuBar::render2d(Adorn* adorn)
{
    if (isVisible()) {
        if (backdropColor != G3D::Color4::zero())
            adorn->rect2d(getMyRect2D(), backdropColor);
        for (size_t i = 0; i < numChildren(); ++i) {
            GuiItem* item = dynamic_cast<GuiItem*>(getChild(i));
            if (item)
                item->render2d(adorn);
        }
    }
}

// 00574bf0: children get first use; an opaque backdrop consumes mouse input inside its rectangle.
GuiResponse TopMenuBar::process(const GuiEvent& event)
{
    if (isVisible()) {
        {
            GuiResponse response = GuiItem::process(event);
            if (response.wasUsed())
                return response;
        }
        if (backdropColor.a > 0.0f && event.eventType >= UIEvent::MOUSE_RIGHT_BUTTON_DOWN
            && event.eventType <= UIEvent::MOUSE_IDLE && getMyRect().pointInRect(event.mousePosition))
            return GuiResponse::used();
    }
    return GuiResponse::notUsed();
}

void TopMenuBar::init()
{
	layoutStyle = Layout::HORIZONTAL;
	backdropColor = G3D::Color4::clear();
	visible = true;
}
}
