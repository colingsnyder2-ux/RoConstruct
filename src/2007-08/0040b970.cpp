// from server: 100% by auto
// roc 2007-08 0040b970  unit: VCBrowserViewExternal::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040b970
//
// 0040b970  836c240404           sub dword ptr [esp + 4], 4
// 0040b975  e986ffffff           jmp 0x40b900
// library mfc-8.0/atlmfc\src\mfc\dlgprntx.cpp (function ?AddRef@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgprntx.cpp
