// from server: 100% by auto
// roc 2009-12 00869090  unit: CXTPPropertyGridView  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00869090
//
// 00869090  e89badf8ff           call 0x7f3e30
// 00869095  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\barcore.cpp (function ?OnLButtonDblClk@CWnd@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcore.cpp
