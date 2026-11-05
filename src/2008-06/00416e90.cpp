// from server: 100% by auto
// roc 2008-06 00416e90  unit: DHTMLWindowService  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00416e90
//
// 00416e90  6a00                 push 0
// 00416e92  e8593a1400           call 0x55a8f0
// 00416e97  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?OnMoveDown@COutlookOptionsDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
