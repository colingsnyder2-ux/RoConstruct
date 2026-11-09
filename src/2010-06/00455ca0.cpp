// from server: 100% by auto
// roc 2010-06 00455ca0  unit: CRobloxDHtmlDialog  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00455ca0
//
// 00455ca0  6a02                 push 2
// 00455ca2  e879861400           call 0x59e320
// 00455ca7  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgcore.cpp
