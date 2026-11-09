// from server: 100% by auto
// roc 2010-06 00824b90  unit: CXTPControlComboBoxGalleryPopupBar  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00824b90
//
// 00824b90  6a00                 push 0
// 00824b92  e83948f9ff           call 0x7b93d0
// 00824b97  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?OnMoveDown@COutlookOptionsDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
