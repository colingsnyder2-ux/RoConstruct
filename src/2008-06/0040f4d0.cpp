// from server: 100% by auto
// roc 2008-06 0040f4d0  unit: VCBrowserViewExternal::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040f4d0
//
// 0040f4d0  836c240404           sub dword ptr [esp + 4], 4
// 0040f4d5  e936ffffff           jmp 0x40f410
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
