// from server: 100% by auto
// roc 2007-03 006c9330  unit: seg_006c0000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c9330
//
// 006c9330  8b442404             mov eax, dword ptr [esp + 4]
// 006c9334  8b4014               mov eax, dword ptr [eax + 0x14]
// 006c9337  3df1240000           cmp eax, 0x24f1
// 006c933c  7508                 jne 0x6c9346
// 006c933e  e8fdf0ffff           call 0x6c8440
// 006c9343  c20400               ret 4
// 006c9346  3df0240000           cmp eax, 0x24f0
// 006c934b  7505                 jne 0x6c9352
// 006c934d  e8eefcffff           call 0x6c9040
// 006c9352  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnCaptionButtonClick@CXTPDockingPaneMiniWnd@@MAEXPAVCXTPDockingPaneCaptionButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
