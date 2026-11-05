// from server: 100% by auto
// roc 2010-06 00406e80  unit: VCApp::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00406e80
//
// 00406e80  836c240404           sub dword ptr [esp + 4], 4
// 00406e85  e9a6ffffff           jmp 0x406e30
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
