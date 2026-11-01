// from server: 100% by auto
// roc 2009-12 0085c840  unit: CXTPDockingPane  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085c840
//
// 0085c840  85c9                 test ecx, ecx
// 0085c842  7414                 je 0x85c858
// 0085c844  8d4120               lea eax, [ecx + 0x20]
// 0085c847  50                   push eax
// 0085c848  83c120               add ecx, 0x20
// 0085c84b  e8f03f0500           call 0x8b0840
// 0085c850  8bc8                 mov ecx, eax
// 0085c852  e899d3fdff           call 0x839bf0
// 0085c857  c3                   ret 
// 0085c858  33c0                 xor eax, eax
// 0085c85a  50                   push eax
// 0085c85b  83c120               add ecx, 0x20
// 0085c85e  e8dd3f0500           call 0x8b0840
// 0085c863  8bc8                 mov ecx, eax
// 0085c865  e886d3fdff           call 0x839bf0
// 0085c86a  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Hide@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
