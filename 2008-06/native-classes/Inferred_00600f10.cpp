// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// 00600f10: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "gui/Gui.h"
#include "util/Name.h"

namespace RBX { 
// Genuine public API, native600f10: attach child to this, release passed owner.
// Keep observed out-of-line boundary used by all native panel builders.
__declspec(noinline) void GuiItem::addGuiItem(boost::shared_ptr<GuiItem> item) {
    item->setParent(this);
}
}
