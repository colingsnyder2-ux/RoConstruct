// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// CRobloxWnd::finishAttach (0045ead0) - native 2008-06.
// Layout: dataModel at 0x6c, gWindow at 0x70, adorn at 0xa4.
// Bodies recovered from disassembly of 0045ead0.
// >>> native-status (generated) -- do not edit >>>
// CRobloxWndFinishAttach | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin
// <<< native-status | src a992974f | roc native-status --write
#include "../native-headers/CRobloxView.h"

// Global state at fixed addresses recovered from the target.
static void** global_96eff4 = (void**)0x96eff4;
static int* global_0x974d74 = (int*)0x974d74;

// External helpers recovered from the target.
extern "C" int fn_0041eea0(void*);
extern "C" void fn_005756e0(void*, void*);

// 0045ead0
void CRobloxWnd::finishAttach()
{
    void* adorn = this->slots_a0_a4[1];
    if (*global_96eff4 != adorn)
    {
        void** adornVtbl = *(void***)adorn;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))adornVtbl[0x26];
        fn(adorn);
        *global_96eff4 = adorn;
    }

    void* gWindow = this->slots_64_7c[3];
    int result = gWindow ? fn_0041eea0(gWindow) : 0;
    *global_0x974d74 = result;

    void* slot = this->slots_ac_b8[2];
    fn_005756e0(gWindow, slot);
    *global_0x974d74 = 0;
}
