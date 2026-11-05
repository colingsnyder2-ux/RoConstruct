// from server: 100% by auto
// roc 2010-06 00882500  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882500
//
// 00882500  8b4104               mov eax, dword ptr [ecx + 4]
// 00882503  85c0                 test eax, eax
// 00882505  7404                 je 0x88250b
// 00882507  8b402c               mov eax, dword ptr [eax + 0x2c]
// 0088250a  c3                   ret 
// 0088250b  83c8ff               or eax, 0xffffffff
// 0088250e  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetCurSel@CXTPTabManager@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
