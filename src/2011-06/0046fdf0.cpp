// from server: 100% by auto
// roc 2011-06 0046fdf0  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0046fdf0
//
// 0046fdf0  836c240404           sub dword ptr [esp + 4], 4
// 0046fdf5  e9c6f9ffff           jmp 0x46f7c0
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
