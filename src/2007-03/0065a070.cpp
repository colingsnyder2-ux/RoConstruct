// from server: 100% by auto
// roc 2007-03 0065a070  unit: seg_00650000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065a070
//
// 0065a070  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0065a074  85c9                 test ecx, ecx
// 0065a076  740c                 je 0x65a084
// 0065a078  e803ef0100           call 0x678f80
// 0065a07d  85c0                 test eax, eax
// 0065a07f  7503                 jne 0x65a084
// 0065a081  c20400               ret 4
// 0065a084  b801000000           mov eax, 1
// 0065a089  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?IsPaneClosed@CXTPDockingPaneManager@@QBEHPAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
