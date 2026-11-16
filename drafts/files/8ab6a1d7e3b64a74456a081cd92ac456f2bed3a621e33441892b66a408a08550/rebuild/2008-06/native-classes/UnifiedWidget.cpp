// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "gui/Gui.h"
namespace RBX {
// 005cf4e0 clears menuState at +0x144 without notifying listeners.
void UnifiedWidget::onLoseFocus() { menuState = NOTHING; }
void UnifiedWidget::render2d(Adorn* adorn) {
    if (isVisible()) { render2dMe(adorn); render2dChildren(adorn); }
}
}

namespace RBX { G3D::Vector2 UnifiedWidget::childOffset() const { return G3D::Vector2(0.0f, 28.0f); } }

namespace RBX {
G3D::Vector2 UnifiedWidget::getChildPosition(const GuiItem* child) const {
    G3D::Vector2 result = firstChildPosition();
    unsigned i = 0;
    while (i < numChildren()) {
        const GuiItem* item = dynamic_cast<const GuiItem*>(getChild(i));
        if (item) {
            if (item == child) return result;
            result += childOffset();
        }
        ++i;
    }
    return result;
}
}

namespace RBX {
GuiResponse UnifiedWidget::process(const GuiEvent& event) {
    if (isVisible() && event.eventType >= UIEvent::MOUSE_RIGHT_BUTTON_DOWN
        && event.eventType <= UIEvent::MOUSE_IDLE) {
        switch (menuState) {
        case NOTHING: return processNothing(event);
        case HOVER: return processHover(event);
        case SHOWN_APPEARING:
        case SHOWN: return processShown(event);
        }
    }
    return GuiResponse::notUsed();
}
}

namespace RBX {
G3D::Vector2 UnifiedWidget::firstChildPosition() const {
    G3D::Vector2 position = getPosition();
    G3D::Vector2 offset = getSize();
    position.x += offset.x + 4.0f;
    int height = int(offset.y) + 4;
    int bottom = (int(GuiRoot::getCanvasSize().y) - 120) / height;
    int top = (int(position.y) - 20) / height;
    int half = int(numChildren()) / 2;
    position.y = float(20 + (std::min(std::max(half, top), bottom) - half) * height);
    return position;
}
}
