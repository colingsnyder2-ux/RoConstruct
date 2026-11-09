// from server: 100% by auto
// roc 2009-06 0044eeb0  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044eeb0
//
// 0044eeb0  836c240404           sub dword ptr [esp + 4], 4
// 0044eeb5  e996f9ffff           jmp 0x44e850
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
