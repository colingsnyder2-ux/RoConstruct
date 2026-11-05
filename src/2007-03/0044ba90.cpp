// from server: 100% by auto
// roc 2007-03 0044ba90  unit: seg_00440000  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0044ba90
//
// 0044ba90  6a02                 push 2
// 0044ba92  e8a9470e00           call 0x530240
// 0044ba97  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgcore.cpp
