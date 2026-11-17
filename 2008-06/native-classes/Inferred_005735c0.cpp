// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 005735c0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "gui/Gui.h"
#include "util/Name.h"

namespace RBX {

void __thiscall UnifiedWidget::setMenuState(UnifiedWidget::MenuState state)
{
	if (menuState != state)
	{
		menuState = state;
		onMenuStateChanged();
	}
}

}
