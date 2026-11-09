// from server: 100% by auto
// roc 2008-06 00407ea0  unit: VCApp::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00407ea0
//
// 00407ea0  836c240404           sub dword ptr [esp + 4], 4
// 00407ea5  e9b6ffffff           jmp 0x407e60
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
