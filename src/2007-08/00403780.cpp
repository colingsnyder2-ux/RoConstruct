// from server: 100% by auto
// roc 2007-08 00403780  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00403780
//
// 00403780  836c240404           sub dword ptr [esp + 4], 4
// 00403785  e9f6f4ffff           jmp 0x402c80
// library mfc-8.0/atlmfc\src\mfc\dlgprntx.cpp (function ?AddRef@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgprntx.cpp
