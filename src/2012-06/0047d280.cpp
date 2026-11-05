// from server: 100% by auto
// roc 2012-06 0047d280  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0047d280
//
// 0047d280  836c240404           sub dword ptr [esp + 4], 4
// 0047d285  e916f7ffff           jmp 0x47c9a0
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
