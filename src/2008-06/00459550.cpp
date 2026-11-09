// from server: 100% by auto
// roc 2008-06 00459550  unit: CRobloxView  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00459550
//
// 00459550  6a02                 push 2
// 00459552  e8c9feffff           call 0x459420
// 00459557  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgcore.cpp
