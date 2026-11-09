// from server: 100% by auto
// roc 2007-08 00409eb0  unit: VCApp::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00409eb0
//
// 00409eb0  836c240404           sub dword ptr [esp + 4], 4
// 00409eb5  e9a6ffffff           jmp 0x409e60
// library mfc-8.0/atlmfc\src\mfc\dlgprntx.cpp (function ?AddRef@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgprntx.cpp
