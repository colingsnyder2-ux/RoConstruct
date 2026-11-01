// from server: 100% by auto
// roc 2007-08 00644690  unit: CXTPCommandBar  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00644690
//
// 00644690  e8ebf2ffff           call 0x643980
// 00644695  85c0                 test eax, eax
// 00644697  7407                 je 0x6446a0
// 00644699  8bc8                 mov ecx, eax
// 0064469b  e9c0f1feff           jmp 0x633860
// 006446a0  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSidePanel.cpp (function ?_RestoreFocus@CXTPDockingPaneSidePanel@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSidePanel.cpp
