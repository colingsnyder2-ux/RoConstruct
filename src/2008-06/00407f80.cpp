// from server: 100% by auto
// roc 2008-06 00407f80  unit: VCApp::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00407f80
//
// 00407f80  836c240404           sub dword ptr [esp + 4], 4
// 00407f85  e956770000           jmp 0x40f6e0
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
