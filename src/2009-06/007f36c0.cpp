// from server: 100% by auto
// roc 2009-06 007f36c0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f36c0
//
// 007f36c0  8b442404             mov eax, dword ptr [esp + 4]
// 007f36c4  83780402             cmp dword ptr [eax + 4], 2
// 007f36c8  7512                 jne 0x7f36dc
// 007f36ca  8b4104               mov eax, dword ptr [ecx + 4]
// 007f36cd  85c0                 test eax, eax
// 007f36cf  7406                 je 0x7f36d7
// 007f36d1  8b4068               mov eax, dword ptr [eax + 0x68]
// 007f36d4  c20400               ret 4
// 007f36d7  33c0                 xor eax, eax
// 007f36d9  c20400               ret 4
// 007f36dc  b801000000           mov eax, 1
// 007f36e1  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?IsNavigateButtonAutomaticVisible@CXTPTabManager@@MAEHPAVCXTPTabManagerNavigateButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
