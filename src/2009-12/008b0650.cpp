// from server: 100% by auto
// roc 2009-12 008b0650  unit: CXTPDockingPaneMiniWnd  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b0650
//
// 008b0650  8b442404             mov eax, dword ptr [esp + 4]
// 008b0654  8b4014               mov eax, dword ptr [eax + 0x14]
// 008b0657  3df1240000           cmp eax, 0x24f1
// 008b065c  7508                 jne 0x8b0666
// 008b065e  e81df0ffff           call 0x8af680
// 008b0663  c20400               ret 4
// 008b0666  3df0240000           cmp eax, 0x24f0
// 008b066b  7505                 jne 0x8b0672
// 008b066d  e8defcffff           call 0x8b0350
// 008b0672  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnCaptionButtonClick@CXTPDockingPaneMiniWnd@@MAEXPAVCXTPDockingPaneCaptionButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
