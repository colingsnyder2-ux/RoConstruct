<<<<<<< HEAD
#include "gui/Gui.h"
namespace RBX {
RelativePanel::RelativePanel(const Layout& layout)
=======
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/widget-rect-2008
// 2008-06 native RBX::RelativePanel(const Layout&) (inactive), the out-of-line copy emitted in the GuiBuilder range
// (neighbours GuiItem::addGuiItem 00600f10, PercentPanel ctor 00601050, shared_ptr<RelativePanel> ctor 00601280).
// Declaration and layout from native-headers/gui/Gui.h (RelativePanel offset +0x164; init 00573480 lives in GuiPanels.cpp).
#include "gui/Gui.h"

namespace RBX
{
	// 00600f90 ??0RelativePanel@RBX@@QAE@ABVLayout@1@@Z (registry identity, unique body): TopMenuBar() 005cf6d0, the
	// eleven RelativePanel vtables, offset (Vector2int16, +0x164/+0x166) zeroed, then init(layout) 00573480.
	RelativePanel::RelativePanel(const Layout& layout)
>>>>>>> mew/claude/optimistic-shannon-0xccuy
	{
		init(layout);
	}
}
