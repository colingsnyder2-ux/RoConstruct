// from server: 100% by auto
// roc 2012-06 004b19e0  unit: VCContent::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b19e0
//
// 004b19e0  836c240404           sub dword ptr [esp + 4], 4
// 004b19e5  e986ffffff           jmp 0x4b1970
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
