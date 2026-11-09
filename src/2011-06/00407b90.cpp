// from server: 100% by auto
// roc 2011-06 00407b90  unit: VCApp::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00407b90
//
// 00407b90  836c240404           sub dword ptr [esp + 4], 4
// 00407b95  e966ffffff           jmp 0x407b00
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
