// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 2008-06 native RBX::UnifiedWidget default constructor (inactive). Class in native-headers/gui/Gui.h.
#include "../native-headers/gui/Gui.h"

namespace RBX {
// 00600540 ??0UnifiedWidget@RBX@@QAE@XZ (identity registry). Evidence: calls GuiItem::GuiItem 005739d0, stores the
// UnifiedWidget vftables (0x82fbe4 primary, ...), then calls UnifiedWidget::init 00573570 under an EH frame
// (__ehhandler 007d8168 destroys the GuiItem base). Emitted next to MenuSpacer::MenuSpacer 006005e0 and the widget
// constructors that call it (WidgetChat 00601c50).
UnifiedWidget::UnifiedWidget()
{
	init();
}
}
