// from server: 100% by auto
// roc 2009-06 00764600  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00764600
//
// 00764600  e8034afbff           call 0x719008
// 00764605  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?OnSize@CWnd@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
