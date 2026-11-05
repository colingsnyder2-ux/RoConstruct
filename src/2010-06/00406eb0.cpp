// from server: 100% by auto
// roc 2010-06 00406eb0  unit: VCApp::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00406eb0
//
// 00406eb0  836c240404           sub dword ptr [esp + 4], 4
// 00406eb5  e996ffffff           jmp 0x406e50
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
