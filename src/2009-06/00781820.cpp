// from server: 100% by auto
// roc 2009-06 00781820  unit: CXTPDockingPane  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00781820
//
// 00781820  6a01                 push 1
// 00781822  51                   push ecx
// 00781823  83c120               add ecx, 0x20
// 00781826  e8d5440500           call 0x7d5d00
// 0078182b  8bc8                 mov ecx, eax
// 0078182d  e84ecafdff           call 0x75e280
// 00781832  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Select@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
