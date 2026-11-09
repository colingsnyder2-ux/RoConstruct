// from server: 100% by auto
// roc 2009-06 004581b0  unit: CRobloxView  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004581b0
//
// 004581b0  6a00                 push 0
// 004581b2  e8b9feffff           call 0x458070
// 004581b7  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?OnMoveDown@COutlookOptionsDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
