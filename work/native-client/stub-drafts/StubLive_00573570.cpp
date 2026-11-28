// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 00573570 RBX::UnifiedWidget::init against the NATIVE gui/Gui.h. The linked drafts (test_00573570.cpp,
// UnifiedWidgetRecovery_00573570.cpp) were compiled with the donor rbxgs include paths first: their GuiItem is 8 bytes
// smaller, so init stored 140.0f/24.0f into +0x134/+0x138 = GuiItem's shared_ptr -> ~GuiItem released a float
// (File->New crash). The original stores +0x13c, +0x140 and zeroes +0x144.
#include "util/Object.h"
#include "gui/Gui.h"

namespace RBX {
	void UnifiedWidget::init()
	{
		setGuiSize(G3D::Vector2(140.0f, 24.0f));
		menuState = NOTHING;
	}
}
