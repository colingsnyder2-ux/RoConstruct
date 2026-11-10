// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::MenuSpacer unit (inactive): 006005e0..0060065a.
// Layout and addresses in native-headers/gui/Gui.h (class MenuSpacer, declared after PercentPanel).
// addItem(GuiItem*) is declared in Gui.h but has no code in the binary (never referenced), so it is not defined here.
#include "gui/Gui.h"

namespace RBX
{
	MenuSpacer::MenuSpacer(float x, float y)
		: GuiItem()
	{
		setGuiSize(G3D::Vector2(x, y));
	}
}
