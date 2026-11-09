// from server: 100% by auto
// roc 2008-06 00702d70  unit: CXTPTabClientWnd  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00702d70
//
// 00702d70  e8f3def9ff           call 0x6a0c68
// 00702d75  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?OnSize@CWnd@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
