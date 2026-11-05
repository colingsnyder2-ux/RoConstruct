// from server: 100% by auto
// roc 2010-06 0040e3a0  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040e3a0
//
// 0040e3a0  836c240404           sub dword ptr [esp + 4], 4
// 0040e3a5  e916ffffff           jmp 0x40e2c0
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
