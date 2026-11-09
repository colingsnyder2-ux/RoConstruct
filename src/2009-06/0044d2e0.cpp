// from server: 100% by auto
// roc 2009-06 0044d2e0  unit: CRobloxDHtmlDialog  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044d2e0
//
// 0044d2e0  6a02                 push 2
// 0044d2e2  e899a21800           call 0x5d7580
// 0044d2e7  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgcore.cpp
