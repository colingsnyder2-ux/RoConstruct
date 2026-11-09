// from server: 100% by auto
// roc 2008-06 00402a60  unit: VCWorkspace::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402a60
//
// 00402a60  836c240404           sub dword ptr [esp + 4], 4
// 00402a65  e9f6feffff           jmp 0x402960
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
