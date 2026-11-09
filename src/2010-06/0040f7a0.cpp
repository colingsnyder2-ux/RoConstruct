// from server: 100% by auto
// roc 2010-06 0040f7a0  unit: boost::bad_weak_ptr  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040f7a0
//
// 0040f7a0  e89d853900           call 0x7a7d42
// 0040f7a5  33c0                 xor eax, eax
// 0040f7a7  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?OnIdleUpdateCmdUI@CXTPDockingPaneManager@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
