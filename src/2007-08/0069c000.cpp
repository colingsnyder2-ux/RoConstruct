// from server: 100% by auto
// roc 2007-08 0069c000  unit: CXTPPropertyGridView  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069c000
//
// 0069c000  e83942f9ff           call 0x63023e
// 0069c005  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\barcore.cpp (function ?OnLButtonDblClk@CWnd@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcore.cpp
