// from server: 100% by auto
// roc 2011-06 00881c20  unit: CXTPControlComboBoxGalleryPopupBar  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00881c20
//
// 00881c20  6a00                 push 0
// 00881c22  e8f99bf9ff           call 0x81b820
// 00881c27  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?OnMoveDown@COutlookOptionsDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
