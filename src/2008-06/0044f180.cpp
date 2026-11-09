// from server: 100% by auto
// roc 2008-06 0044f180  unit: CRobloxDHtmlDialog  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044f180
//
// 0044f180  6a02                 push 2
// 0044f182  e8195c1000           call 0x554da0
// 0044f187  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgcore.cpp
