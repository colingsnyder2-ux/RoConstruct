// from server: 100% by auto
// roc 2009-12 0097fdf0  unit: seg_00970000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097fdf0
//
// 0097fdf0  e8bbffbcff           call 0x54fdb0
// 0097fdf5  e936f8bcff           jmp 0x54f630
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?AfxAbort@@YGXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
