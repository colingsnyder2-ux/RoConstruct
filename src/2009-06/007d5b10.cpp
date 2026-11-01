// from server: 100% by auto
// roc 2009-06 007d5b10  unit: CXTPDockingPaneMiniWnd  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d5b10
//
// 007d5b10  8b442404             mov eax, dword ptr [esp + 4]
// 007d5b14  8b4014               mov eax, dword ptr [eax + 0x14]
// 007d5b17  3df1240000           cmp eax, 0x24f1
// 007d5b1c  7508                 jne 0x7d5b26
// 007d5b1e  e81df0ffff           call 0x7d4b40
// 007d5b23  c20400               ret 4
// 007d5b26  3df0240000           cmp eax, 0x24f0
// 007d5b2b  7505                 jne 0x7d5b32
// 007d5b2d  e8defcffff           call 0x7d5810
// 007d5b32  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnCaptionButtonClick@CXTPDockingPaneMiniWnd@@MAEXPAVCXTPDockingPaneCaptionButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
