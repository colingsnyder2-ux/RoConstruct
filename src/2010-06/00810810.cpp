// from server: 100% by auto
// roc 2010-06 00810810  unit: CXTPDockingPane  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00810810
//
// 00810810  85c9                 test ecx, ecx
// 00810812  7414                 je 0x810828
// 00810814  8d4120               lea eax, [ecx + 0x20]
// 00810817  50                   push eax
// 00810818  83c120               add ecx, 0x20
// 0081081b  e8f0400500           call 0x864910
// 00810820  8bc8                 mov ecx, eax
// 00810822  e829d5fdff           call 0x7edd50
// 00810827  c3                   ret 
// 00810828  33c0                 xor eax, eax
// 0081082a  50                   push eax
// 0081082b  83c120               add ecx, 0x20
// 0081082e  e8dd400500           call 0x864910
// 00810833  8bc8                 mov ecx, eax
// 00810835  e816d5fdff           call 0x7edd50
// 0081083a  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Hide@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPane.cpp
