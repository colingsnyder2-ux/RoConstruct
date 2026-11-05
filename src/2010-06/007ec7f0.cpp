// from server: 100% by auto
// roc 2010-06 007ec7f0  unit: CXTPControls  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ec7f0
//
// 007ec7f0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007ec7f4  85c9                 test ecx, ecx
// 007ec7f6  740c                 je 0x7ec804
// 007ec7f8  e8d3410200           call 0x8109d0
// 007ec7fd  85c0                 test eax, eax
// 007ec7ff  7503                 jne 0x7ec804
// 007ec801  c20400               ret 4
// 007ec804  b801000000           mov eax, 1
// 007ec809  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?IsPaneClosed@CXTPDockingPaneManager@@QBEHPAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
