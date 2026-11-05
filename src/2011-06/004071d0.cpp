// from server: 100% by auto
// roc 2011-06 004071d0  unit: VCApp::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004071d0
//
// 004071d0  836c240404           sub dword ptr [esp + 4], 4
// 004071d5  e966ffffff           jmp 0x407140
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
