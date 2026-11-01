// from server: 100% by auto
// roc 2011-06 0084e3b0  unit: CXTPDockingPaneManager  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0084e3b0
//
// 0084e3b0  e8abffffff           call 0x84e360
// 0084e3b5  33c0                 xor eax, eax
// 0084e3b7  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?OnIdleUpdateCmdUI@CXTPDockingPaneManager@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
