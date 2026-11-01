// from server: 100% by auto
// roc 2009-12 008051d0  unit: CXTPCommandBar  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008051d0
//
// 008051d0  e8fbf2ffff           call 0x8044d0
// 008051d5  85c0                 test eax, eax
// 008051d7  7407                 je 0x8051e0
// 008051d9  8bc8                 mov ecx, eax
// 008051db  e9f0080100           jmp 0x815ad0
// 008051e0  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSidePanel.cpp (function ?_RestoreFocus@CXTPDockingPaneSidePanel@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSidePanel.cpp
