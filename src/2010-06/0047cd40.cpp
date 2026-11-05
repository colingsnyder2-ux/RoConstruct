// from server: 100% by auto
// roc 2010-06 0047cd40  unit: VCContent::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047cd40
//
// 0047cd40  836c240404           sub dword ptr [esp + 4], 4
// 0047cd45  e976ffffff           jmp 0x47ccc0
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
