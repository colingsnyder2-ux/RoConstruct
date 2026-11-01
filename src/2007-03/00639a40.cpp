// from server: 100% by auto
// roc 2007-03 00639a40  unit: seg_00630000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00639a40
//
// 00639a40  e8cbf2ffff           call 0x638d10
// 00639a45  85c0                 test eax, eax
// 00639a47  7407                 je 0x639a50
// 00639a49  8bc8                 mov ecx, eax
// 00639a4b  e9c035ffff           jmp 0x62d010
// 00639a50  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSidePanel.cpp (function ?_RestoreFocus@CXTPDockingPaneSidePanel@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSidePanel.cpp
