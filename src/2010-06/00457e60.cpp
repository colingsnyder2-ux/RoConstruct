// from server: 100% by auto
// roc 2010-06 00457e60  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00457e60
//
// 00457e60  836c240404           sub dword ptr [esp + 4], 4
// 00457e65  e976f8ffff           jmp 0x4576e0
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
