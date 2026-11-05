// from server: 100% by auto
// roc 2008-06 004169c0  unit: VCContent::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004169c0
//
// 004169c0  836c240404           sub dword ptr [esp + 4], 4
// 004169c5  e9e6150000           jmp 0x417fb0
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
