// from server: 100% by auto
// roc 2009-12 0085c820  unit: CXTPDockingPane  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085c820
//
// 0085c820  51                   push ecx
// 0085c821  83c120               add ecx, 0x20
// 0085c824  e817400500           call 0x8b0840
// 0085c829  8bc8                 mov ecx, eax
// 0085c82b  e890c8fdff           call 0x8390c0
// 0085c830  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Close@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
