// from server: 100% by auto
// roc 2009-12 008385d0  unit: CXTPControls  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008385d0
//
// 008385d0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008385d4  85c9                 test ecx, ecx
// 008385d6  740c                 je 0x8385e4
// 008385d8  e823440200           call 0x85ca00
// 008385dd  85c0                 test eax, eax
// 008385df  7503                 jne 0x8385e4
// 008385e1  c20400               ret 4
// 008385e4  b801000000           mov eax, 1
// 008385e9  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?IsPaneClosed@CXTPDockingPaneManager@@QBEHPAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
