// from server: 100% by auto
// roc 2008-06 00459560  unit: CRobloxView  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00459560
//
// 00459560  6a00                 push 0
// 00459562  e8b9feffff           call 0x459420
// 00459567  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?OnMoveDown@COutlookOptionsDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
