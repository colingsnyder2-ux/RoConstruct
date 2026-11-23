// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native GuiRoot::canvasSize (inactive): G3D::Vector2 at 00974d78 (.bss, 0,0; read by GuiPanels / BackpackItem).
#include "gui/Gui.h"

namespace RBX
{
	G3D::Vector2 GuiRoot::canvasSize;
}
