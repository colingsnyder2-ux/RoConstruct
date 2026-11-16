// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "gui/Gui.h"
namespace RBX {
// 005cf4e0 clears menuState at +0x144 without notifying listeners.
void UnifiedWidget::onLoseFocus() { menuState = NOTHING; }
void UnifiedWidget::render2d(Adorn* adorn) {
    if (isVisible()) { render2dMe(adorn); render2dChildren(adorn); }
}
}
