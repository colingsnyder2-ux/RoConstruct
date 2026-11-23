// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxView.h"

extern "C" int __fastcall fn_0045d650(void* self, int unusedEdx, int a1, int a2, int a3);

// Exposes protected CWnd::Default through a public using-declaration.
struct CWndDefaultAccess : CWnd {
    using CWnd::Default;
};

// INFERRED: OnSize(nType, cx, cy); args are pushed as (nType, cx, cy) for both callees.
extern "C" void __fastcall fn_0045d7c0(CRobloxWnd* self, int unusedEdx, UINT nType, int cx, int cy)
{
    if (cx > 0 && cy > 0 && cx <= 0x2000 && cy <= 0x2000) {
        (static_cast<CWnd*>(self)->*(&CWndDefaultAccess::Default))();
        if (*(int*)((char*)self + 0x5c) == 2)
            fn_0045d650(self, 0, (int)nType, cx, cy);
        else
            self->OnSize(nType, cx, cy);
    }
}
