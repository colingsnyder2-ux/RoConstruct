// from server: 100% by auto
// roc 2007-03 00453710  unit: seg_00450000  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00453710
//
// 00453710  6a02                 push 2
// 00453712  e8a9feffff           call 0x4535c0
// 00453717  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgcore.cpp
