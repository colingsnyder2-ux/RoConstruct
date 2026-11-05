// from server: 100% by auto
// roc 2007-08 0044cf90  unit: CRobloxDHtmlDialog  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044cf90
//
// 0044cf90  6a02                 push 2
// 0044cf92  e8e9070e00           call 0x52d780
// 0044cf97  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgcore.cpp
