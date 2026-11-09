// from server: 100% by auto
// roc 2011-06 00407bb0  unit: VCApp::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00407bb0
//
// 00407bb0  836c240404           sub dword ptr [esp + 4], 4
// 00407bb5  e986ffffff           jmp 0x407b40
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
