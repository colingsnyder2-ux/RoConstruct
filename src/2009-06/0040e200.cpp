// from server: 100% by auto
// roc 2009-06 0040e200  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040e200
//
// 0040e200  836c240404           sub dword ptr [esp + 4], 4
// 0040e205  e9e6feffff           jmp 0x40e0f0
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
