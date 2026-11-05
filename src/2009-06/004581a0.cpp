// from server: 100% by auto
// roc 2009-06 004581a0  unit: CRobloxView  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004581a0
//
// 004581a0  6a02                 push 2
// 004581a2  e8c9feffff           call 0x458070
// 004581a7  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgcore.cpp
