// from server: 100% by auto
// roc 2007-08 004124c0  unit: VCContent::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004124c0
//
// 004124c0  836c240404           sub dword ptr [esp + 4], 4
// 004124c5  e9162e0000           jmp 0x4152e0
// library mfc-8.0/atlmfc\src\mfc\dlgprntx.cpp (function ?AddRef@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgprntx.cpp
