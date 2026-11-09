// from server: 100% by auto
// roc 2009-12 00461aa0  unit: G3D::TextureManager::TextureArgs  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00461aa0
//
// 00461aa0  e85d213900           call 0x7f3c02
// 00461aa5  33c0                 xor eax, eax
// 00461aa7  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?OnIdleUpdateCmdUI@CXTPDockingPaneManager@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
