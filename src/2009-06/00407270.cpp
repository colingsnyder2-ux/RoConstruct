// from server: 100% by auto
// roc 2009-06 00407270  unit: VCApp::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00407270
//
// 00407270  836c240404           sub dword ptr [esp + 4], 4
// 00407275  e9a6ffffff           jmp 0x407220
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
