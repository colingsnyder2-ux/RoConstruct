// from server: 100% by auto
// roc 2007-08 00412410  unit: VCContent::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00412410
//
// 00412410  836c240404           sub dword ptr [esp + 4], 4
// 00412415  e9b6ffffff           jmp 0x4123d0
// library mfc-8.0/atlmfc\src\mfc\dlgprntx.cpp (function ?AddRef@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgprntx.cpp
