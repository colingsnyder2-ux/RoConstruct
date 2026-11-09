// from server: 100% by auto
// roc 2008-06 00407fc0  unit: VCApp::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00407fc0
//
// 00407fc0  836c240404           sub dword ptr [esp + 4], 4
// 00407fc5  e986ffffff           jmp 0x407f50
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
