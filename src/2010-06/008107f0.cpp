// from server: 100% by auto
// roc 2010-06 008107f0  unit: CXTPDockingPane  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008107f0
//
// 008107f0  51                   push ecx
// 008107f1  83c120               add ecx, 0x20
// 008107f4  e817410500           call 0x864910
// 008107f9  8bc8                 mov ecx, eax
// 008107fb  e820cafdff           call 0x7ed220
// 00810800  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Close@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPane.cpp
