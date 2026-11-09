// from server: 100% by auto
// roc 2007-08 00637990  unit: CXTPControlComboBoxList  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00637990
//
// 00637990  e8a988ffff           call 0x63023e
// 00637995  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?OnNcCreate@CWnd@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
