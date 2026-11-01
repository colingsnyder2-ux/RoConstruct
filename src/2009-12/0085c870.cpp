// from server: 100% by auto
// roc 2009-12 0085c870  unit: CXTPDockingPane  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085c870
//
// 0085c870  6a01                 push 1
// 0085c872  51                   push ecx
// 0085c873  83c120               add ecx, 0x20
// 0085c876  e8c53f0500           call 0x8b0840
// 0085c87b  8bc8                 mov ecx, eax
// 0085c87d  e8bec7fdff           call 0x839040
// 0085c882  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Select@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
