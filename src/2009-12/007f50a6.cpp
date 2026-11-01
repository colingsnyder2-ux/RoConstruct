// from server: 100% by auto
// roc 2009-12 007f50a6  unit: ActiveDocView  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f50a6
//
// 007f50a6  e88d060000           call 0x7f5738
// 007f50ab  e936fdffff           jmp 0x7f4de6
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?AfxAbort@@YGXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
