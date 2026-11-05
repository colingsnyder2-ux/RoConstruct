// from server: 100% by auto
// roc 2009-12 007fb160  unit: CXTPControlComboBoxList  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fb160
//
// 007fb160  e8cb8cffff           call 0x7f3e30
// 007fb165  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?OnNcCreate@CWnd@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
