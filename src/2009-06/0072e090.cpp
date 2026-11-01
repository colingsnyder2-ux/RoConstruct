// from server: 100% by auto
// roc 2009-06 0072e090  unit: CXTPCommandBar  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072e090
//
// 0072e090  e8fbf2ffff           call 0x72d390
// 0072e095  85c0                 test eax, eax
// 0072e097  7407                 je 0x72e0a0
// 0072e099  8bc8                 mov ecx, eax
// 0072e09b  e980cdffff           jmp 0x72ae20
// 0072e0a0  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSidePanel.cpp (function ?_RestoreFocus@CXTPDockingPaneSidePanel@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSidePanel.cpp
