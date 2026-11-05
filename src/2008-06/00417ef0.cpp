// from server: 100% by auto
// roc 2008-06 00417ef0  unit: VCLuaFunction::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00417ef0
//
// 00417ef0  836c240404           sub dword ptr [esp + 4], 4
// 00417ef5  e986ffffff           jmp 0x417e80
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
