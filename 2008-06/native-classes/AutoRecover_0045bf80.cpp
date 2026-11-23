// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxView.h"

// INFERRED: 0x006a0c68 is a thiscall helper (probably a base-class/MFC function) that is
// tail-called with the same this pointer; its return type is unknown, so void is assumed.
// It is declared with only the object pointer so no edx setup is emitted before the jump.
extern "C" void __fastcall fn_006a0c68(CRobloxWnd* self);

extern "C" void __fastcall fn_0045bf80(CRobloxWnd* self, int unusedEdx)
{
    self->sub_0045beb0();
    fn_006a0c68(self);
}
