// from server: 100% by auto
// roc 2009-12 00838a00  unit: CXTPDockingPaneManager  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00838a00
//
// 00838a00  e8abffffff           call 0x8389b0
// 00838a05  33c0                 xor eax, eax
// 00838a07  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?OnIdleUpdateCmdUI@CXTPDockingPaneManager@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
