// from server: 100% by auto
// roc 2009-06 0075d860  unit: CXTPControls  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075d860
//
// 0075d860  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0075d864  85c9                 test ecx, ecx
// 0075d866  740c                 je 0x75d874
// 0075d868  e843410200           call 0x7819b0
// 0075d86d  85c0                 test eax, eax
// 0075d86f  7503                 jne 0x75d874
// 0075d871  c20400               ret 4
// 0075d874  b801000000           mov eax, 1
// 0075d879  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?IsPaneClosed@CXTPDockingPaneManager@@QBEHPAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
