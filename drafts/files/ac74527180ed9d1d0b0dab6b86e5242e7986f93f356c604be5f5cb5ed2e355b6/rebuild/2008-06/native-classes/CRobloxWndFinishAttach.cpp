// CRobloxWnd::finishAttach (0045ead0) - native 2008-06.
// Layout: dataModel at 0x6c, gWindow at 0x70, adorn at 0xa4.
// Bodies recovered from disassembly of 0045ead0.
// >>> native-status (generated) -- do not edit >>>
// CRobloxWndFinishAttach | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (deepseek:deepseek-flash)
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
    // Identities (work/2008-06/identity-registry.json): 0096eff4 = G3D::GWindow::m_current, so +0xa4 is
    //   a G3D::GWindow* and the first block is the inline gWindow->makeCurrent() (vtable +0x98);
    //   0041eea0 = ServiceProvider::create<ContentProvider>() on +0x70, 00974d74 = RBX::guiContentProvider,
    //   005756e0 = DataModel::buildGui(Adorn*) on +0x70 with +0xb4. Proposed authentic body:
    //     window->makeCurrent(); guiContentProvider = ServiceProvider::create<ContentProvider>(dataModel);
    //     dataModel->buildGui(adorn); guiContentProvider = NULL;
    //   Blocked: DataModel.h does not declare buildGui (core header) and CRobloxView.h types 0x70/0xa4/0xb4 wrongly.
    // STUB (not authentic): none of the calls above are made yet. Reference members to keep layout meaningful; renderer wiring comes later.
    (void)this->dataModel;
    (void)this->gWindow;
    (void)this->adorn;
}
