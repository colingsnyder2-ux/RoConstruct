// from server: 100% by auto
// roc 2011-06 00413b00  unit: CChatPrompt  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00413b00
//
// 00413b00  e8296b3f00           call 0x80a62e
// 00413b05  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?OnSize@CWnd@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
