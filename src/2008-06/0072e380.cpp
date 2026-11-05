// from server: 100% by auto
// roc 2008-06 0072e380  unit: CXTPControlComboBoxGalleryPopupBar  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0072e380
//
// 0072e380  6a00                 push 0
// 0072e382  e82978f8ff           call 0x6b5bb0
// 0072e387  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?OnMoveDown@COutlookOptionsDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
