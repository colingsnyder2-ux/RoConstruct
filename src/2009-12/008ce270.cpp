// from server: 100% by auto
// roc 2009-12 008ce270  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ce270
//
// 008ce270  8b442404             mov eax, dword ptr [esp + 4]
// 008ce274  83780402             cmp dword ptr [eax + 4], 2
// 008ce278  7512                 jne 0x8ce28c
// 008ce27a  8b4104               mov eax, dword ptr [ecx + 4]
// 008ce27d  85c0                 test eax, eax
// 008ce27f  7406                 je 0x8ce287
// 008ce281  8b4068               mov eax, dword ptr [eax + 0x68]
// 008ce284  c20400               ret 4
// 008ce287  33c0                 xor eax, eax
// 008ce289  c20400               ret 4
// 008ce28c  b801000000           mov eax, 1
// 008ce291  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?IsNavigateButtonAutomaticVisible@CXTPTabManager@@MAEHPAVCXTPTabManagerNavigateButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
