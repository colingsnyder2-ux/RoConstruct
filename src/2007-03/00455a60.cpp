// from server: 100% by auto
// roc 2007-03 00455a60  unit: seg_00450000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00455a60
//
// 00455a60  e82d8a1c00           call 0x61e492
// 00455a65  33c0                 xor eax, eax
// 00455a67  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?OnIdleUpdateCmdUI@CXTPDockingPaneManager@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
