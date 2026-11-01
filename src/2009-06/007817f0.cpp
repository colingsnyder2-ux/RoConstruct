// from server: 100% by auto
// roc 2009-06 007817f0  unit: CXTPDockingPane  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007817f0
//
// 007817f0  85c9                 test ecx, ecx
// 007817f2  7414                 je 0x781808
// 007817f4  8d4120               lea eax, [ecx + 0x20]
// 007817f7  50                   push eax
// 007817f8  83c120               add ecx, 0x20
// 007817fb  e800450500           call 0x7d5d00
// 00781800  8bc8                 mov ecx, eax
// 00781802  e829d6fdff           call 0x75ee30
// 00781807  c3                   ret 
// 00781808  33c0                 xor eax, eax
// 0078180a  50                   push eax
// 0078180b  83c120               add ecx, 0x20
// 0078180e  e8ed440500           call 0x7d5d00
// 00781813  8bc8                 mov ecx, eax
// 00781815  e816d6fdff           call 0x75ee30
// 0078181a  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Hide@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
