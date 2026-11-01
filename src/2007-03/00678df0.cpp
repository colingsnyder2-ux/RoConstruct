// from server: 100% by auto
// roc 2007-03 00678df0  unit: seg_00670000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00678df0
//
// 00678df0  6a01                 push 1
// 00678df2  51                   push ecx
// 00678df3  83c120               add ecx, 0x20
// 00678df6  e825070500           call 0x6c9520
// 00678dfb  8bc8                 mov ecx, eax
// 00678dfd  e89e1cfeff           call 0x65aaa0
// 00678e02  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Select@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
