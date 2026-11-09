// from server: 100% by auto
// roc 2012-06 004073d0  unit: VCApp::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004073d0
//
// 004073d0  836c240404           sub dword ptr [esp + 4], 4
// 004073d5  e9b6ffffff           jmp 0x407390
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
