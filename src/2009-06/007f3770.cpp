// from server: 100% by auto
// roc 2009-06 007f3770  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f3770
//
// 007f3770  8b4104               mov eax, dword ptr [ecx + 4]
// 007f3773  85c0                 test eax, eax
// 007f3775  7404                 je 0x7f377b
// 007f3777  8b402c               mov eax, dword ptr [eax + 0x2c]
// 007f377a  c3                   ret 
// 007f377b  83c8ff               or eax, 0xffffffff
// 007f377e  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetCurSel@CXTPTabManager@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
