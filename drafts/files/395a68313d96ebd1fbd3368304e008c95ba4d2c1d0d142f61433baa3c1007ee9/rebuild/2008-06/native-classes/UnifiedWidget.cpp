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
