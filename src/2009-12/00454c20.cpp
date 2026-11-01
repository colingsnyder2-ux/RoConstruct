// from server: 100% by auto
// roc 2009-12 00454c20  unit: CRobloxDHtmlDialog  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00454c20
//
// 00454c20  6a02                 push 2
// 00454c22  e8e9761e00           call 0x63c310
// 00454c27  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgcore.cpp
