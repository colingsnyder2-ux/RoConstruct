// from server: 100% by auto
// roc 2010-06 00457e90  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00457e90
//
// 00457e90  836c240404           sub dword ptr [esp + 4], 4
// 00457e95  e986f8ffff           jmp 0x457720
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
