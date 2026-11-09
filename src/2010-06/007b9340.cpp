// from server: 100% by auto
// roc 2010-06 007b9340  unit: CXTPCommandBar  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b9340
//
// 007b9340  e88bf2ffff           call 0x7b85d0
// 007b9345  85c0                 test eax, eax
// 007b9347  7407                 je 0x7b9350
// 007b9349  8bc8                 mov ecx, eax
// 007b934b  e950080100           jmp 0x7c9ba0
// 007b9350  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneSidePanel.cpp (function ?_RestoreFocus@CXTPDockingPaneSidePanel@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneSidePanel.cpp
