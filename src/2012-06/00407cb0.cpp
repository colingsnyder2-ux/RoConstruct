// from server: 100% by auto
// roc 2012-06 00407cb0  unit: VCApp::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00407cb0
//
// 00407cb0  836c240404           sub dword ptr [esp + 4], 4
// 00407cb5  e986ffffff           jmp 0x407c40
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
