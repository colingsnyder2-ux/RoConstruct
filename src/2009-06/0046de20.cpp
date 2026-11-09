// from server: 100% by auto
// roc 2009-06 0046de20  unit: VCContent::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046de20
//
// 0046de20  836c240404           sub dword ptr [esp + 4], 4
// 0046de25  e9d6ffffff           jmp 0x46de00
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
