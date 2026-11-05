// from server: 100% by auto
// roc 2012-06 0048da60  unit: VCRobloxPlayer::?$CComObjectNoLock  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0048da60
//
// 0048da60  836c240404           sub dword ptr [esp + 4], 4
// 0048da65  e9d6ffffff           jmp 0x48da40
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
