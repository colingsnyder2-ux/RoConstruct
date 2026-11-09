// from server: 100% by auto
// roc 2010-06 00882450  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882450
//
// 00882450  8b442404             mov eax, dword ptr [esp + 4]
// 00882454  83780402             cmp dword ptr [eax + 4], 2
// 00882458  7512                 jne 0x88246c
// 0088245a  8b4104               mov eax, dword ptr [ecx + 4]
// 0088245d  85c0                 test eax, eax
// 0088245f  7406                 je 0x882467
// 00882461  8b4068               mov eax, dword ptr [eax + 0x68]
// 00882464  c20400               ret 4
// 00882467  33c0                 xor eax, eax
// 00882469  c20400               ret 4
// 0088246c  b801000000           mov eax, 1
// 00882471  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?IsNavigateButtonAutomaticVisible@CXTPTabManager@@MAEHPAVCXTPTabManagerNavigateButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
