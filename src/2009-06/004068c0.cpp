// from server: 100% by auto
// roc 2009-06 004068c0  unit: VCApp::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004068c0
//
// 004068c0  836c240404           sub dword ptr [esp + 4], 4
// 004068c5  e9b6ffffff           jmp 0x406880
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
