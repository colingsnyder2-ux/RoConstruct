// from server: 100% by auto
// roc 2010-06 00864720  unit: CXTPDockingPaneMiniWnd  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00864720
//
// 00864720  8b442404             mov eax, dword ptr [esp + 4]
// 00864724  8b4014               mov eax, dword ptr [eax + 0x14]
// 00864727  3df1240000           cmp eax, 0x24f1
// 0086472c  7508                 jne 0x864736
// 0086472e  e83df0ffff           call 0x863770
// 00864733  c20400               ret 4
// 00864736  3df0240000           cmp eax, 0x24f0
// 0086473b  7505                 jne 0x864742
// 0086473d  e8defcffff           call 0x864420
// 00864742  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnCaptionButtonClick@CXTPDockingPaneMiniWnd@@MAEXPAVCXTPDockingPaneCaptionButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
