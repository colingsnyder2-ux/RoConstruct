// from server: 100% by auto
// roc 2010-06 00810840  unit: CXTPDockingPane  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00810840
//
// 00810840  6a01                 push 1
// 00810842  51                   push ecx
// 00810843  83c120               add ecx, 0x20
// 00810846  e8c5400500           call 0x864910
// 0081084b  8bc8                 mov ecx, eax
// 0081084d  e84ec9fdff           call 0x7ed1a0
// 00810852  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Select@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPane.cpp
