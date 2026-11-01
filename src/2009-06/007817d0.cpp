// from server: 100% by auto
// roc 2009-06 007817d0  unit: CXTPDockingPane  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007817d0
//
// 007817d0  51                   push ecx
// 007817d1  83c120               add ecx, 0x20
// 007817d4  e827450500           call 0x7d5d00
// 007817d9  8bc8                 mov ecx, eax
// 007817db  e820cbfdff           call 0x75e300
// 007817e0  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Close@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
