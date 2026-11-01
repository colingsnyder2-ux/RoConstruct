// from server: 100% by auto
// roc 2011-06 008d3360  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d3360
//
// 008d3360  8b442404             mov eax, dword ptr [esp + 4]
// 008d3364  83780402             cmp dword ptr [eax + 4], 2
// 008d3368  7512                 jne 0x8d337c
// 008d336a  8b4104               mov eax, dword ptr [ecx + 4]
// 008d336d  85c0                 test eax, eax
// 008d336f  7406                 je 0x8d3377
// 008d3371  8b4068               mov eax, dword ptr [eax + 0x68]
// 008d3374  c20400               ret 4
// 008d3377  33c0                 xor eax, eax
// 008d3379  c20400               ret 4
// 008d337c  b801000000           mov eax, 1
// 008d3381  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?IsNavigateButtonAutomaticVisible@CXTPTabManager@@MAEHPAVCXTPTabManagerNavigateButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
