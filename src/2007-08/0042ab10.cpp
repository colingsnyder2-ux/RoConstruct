// from server: 100% by auto
// roc 2007-08 0042ab10  unit: VCLuaFunction::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042ab10
//
// 0042ab10  836c240404           sub dword ptr [esp + 4], 4
// 0042ab15  e9d6ffffff           jmp 0x42aaf0
// library mfc-8.0/atlmfc\src\mfc\dlgprntx.cpp (function ?AddRef@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgprntx.cpp
