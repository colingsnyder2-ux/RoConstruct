// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "LuaBridge2008/LuaSignalBridge2008.h"

// INFERRED: the header excerpt declares no ~WaitScriptSlot(), so the vendor
// destructor is the implicit one. It cannot be defined out of line (C2600).
// The implicit destructor destroys waitThread (ThreadRef at +8), then the
// Slot base releases its shared count at +4 via the inlined atomic decrements.
// INFERRED: to make the compiler emit that implicit destructor as the real
// symbol ??1WaitScriptSlot@@QAE@XZ, I odr-use it from a helper while
// auto-inlining is disabled. This forces an out-of-line copy.
// The helper uses a C++ name (not fn_0061f350), so it does not clash with the
// target's thiscall signature.
#pragma auto_inline(off)
void keep_WaitScriptSlot_dtor(WaitScriptSlot* p)
{
    p->WaitScriptSlot::~WaitScriptSlot();
}
#pragma auto_inline(on)
