// from server: 100% by auto
// roc 2010-06 007b4850  unit: CXTPControlComboBoxPopupBar  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4850
//
// 007b4850  e81b37ffff           call 0x7a7f70
// 007b4855  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?OnSize@CWnd@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
