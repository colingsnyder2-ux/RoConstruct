// from server: 100% by auto
// roc 2009-06 0075dc40  unit: CXTPDockingPaneManager  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075dc40
//
// 0075dc40  e8abffffff           call 0x75dbf0
// 0075dc45  33c0                 xor eax, eax
// 0075dc47  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?OnIdleUpdateCmdUI@CXTPDockingPaneManager@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
