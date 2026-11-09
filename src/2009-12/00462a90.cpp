// from server: 100% by auto
// roc 2009-12 00462a90  unit: CRobloxWnd::PartDropTarget  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00462a90
//
// 00462a90  e88bfeffff           call 0x462920
// 00462a95  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?OnNcCreate@CWnd@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
