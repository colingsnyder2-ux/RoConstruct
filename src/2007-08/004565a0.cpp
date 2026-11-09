// from server: 100% by auto
// roc 2007-08 004565a0  unit: CRobloxView  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004565a0
//
// 004565a0  6a02                 push 2
// 004565a2  e8a9feffff           call 0x456450
// 004565a7  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgcore.cpp
