// from server: 100% by auto
// roc 2011-06 0045a580  unit: VCRoblox3D::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045a580
//
// 0045a580  836c240404           sub dword ptr [esp + 4], 4
// 0045a585  e986fbffff           jmp 0x45a110
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
