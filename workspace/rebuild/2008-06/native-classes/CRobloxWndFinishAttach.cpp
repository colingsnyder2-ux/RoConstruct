// CRobloxWnd::finishAttach (0045ead0) - native 2008-06.
// Layout: dataModel at 0x6c, gWindow at 0x70, adorn at 0xa4.
// Bodies recovered from disassembly of 0045ead0.
// >>> native-status (generated) -- do not edit >>>
// CRobloxWndFinishAttach | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src a992974f | roc native-status --write
#include "../native-headers/CRobloxView.h"

// 0045ead0
void CRobloxWnd::finishAttach() {
    // Original:
    //   edi = this->adorn; if (global != edi) { (*edi->vtable[0x26])(edi); global = edi; }
    //   ecx = this->gWindow; if (ecx) eax = fn_0041eea0(ecx); else eax = 0;
    //   global_0x974d74 = eax;
    //   eax = this->slots_ac_b8[2]; ecx = this->gWindow;
    //   fn_005756e0(ecx, eax); global_0x974d74 = 0;
    // STUB (not authentic): none of the calls above are made yet. Reference members to keep layout meaningful; renderer wiring comes later.
    (void)this->dataModel;
    (void)this->gWindow;
    (void)this->adorn;
}
