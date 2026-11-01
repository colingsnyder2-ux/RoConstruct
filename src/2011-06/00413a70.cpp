// from server: 100% by auto
// roc 2011-06 00413a70  unit: boost::bad_weak_ptr  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00413a70
//
// 00413a70  e88b693f00           call 0x80a400
// 00413a75  33c0                 xor eax, eax
// 00413a77  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?OnIdleUpdateCmdUI@CXTPDockingPaneManager@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
