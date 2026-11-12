// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// CRobloxWnd::finishAttach (0045ead0) - native 2008-06.
// Layout: dataModel at 0x6c, gWindow at 0x70, adorn at 0xa4.
// Bodies recovered from disassembly of 0045ead0.
// >>> native-status (generated) -- do not edit >>>
// CRobloxWndFinishAttach | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin
// <<< native-status | src a992974f | roc native-status --write
#include "../native-headers/CRobloxView.h"

// External helpers recovered from the target.
extern "C" int __fastcall fn_0041eea0(void* thisPtr);
extern "C" void __fastcall fn_005756e0(void* thisPtr, void* slot);

// 0045ead0
void CRobloxWnd::finishAttach()
{
    void* adorn = *(void**)((unsigned char*)this + 0xa4);
    if (*(void**)0x96eff4 != adorn)
    {
        void** adornVtbl = *(void***)adorn;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))adornVtbl[0x26];
        fn(adorn);
        *(void**)0x96eff4 = adorn;
    }

    void* gWindow = *(void**)((unsigned char*)this + 0x70);
    int result = gWindow ? fn_0041eea0(gWindow) : 0;
    *(int*)0x974d74 = result;

    void* slot = *(void**)((unsigned char*)this + 0xb4);
    fn_005756e0(gWindow, slot);
    *(int*)0x974d74 = 0;
}
