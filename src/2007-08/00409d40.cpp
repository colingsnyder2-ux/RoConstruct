// from server: 100% by auto
// roc 2007-08 00409d40  unit: VCApp::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00409d40
//
// 00409d40  836c240404           sub dword ptr [esp + 4], 4
// 00409d45  e926ffffff           jmp 0x409c70
// library mfc-8.0/atlmfc\src\mfc\dlgprntx.cpp (function ?AddRef@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgprntx.cpp
