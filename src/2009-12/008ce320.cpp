// from server: 100% by auto
// roc 2009-12 008ce320  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ce320
//
// 008ce320  8b4104               mov eax, dword ptr [ecx + 4]
// 008ce323  85c0                 test eax, eax
// 008ce325  7404                 je 0x8ce32b
// 008ce327  8b402c               mov eax, dword ptr [eax + 0x2c]
// 008ce32a  c3                   ret 
// 008ce32b  83c8ff               or eax, 0xffffffff
// 008ce32e  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetCurSel@CXTPTabManager@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
