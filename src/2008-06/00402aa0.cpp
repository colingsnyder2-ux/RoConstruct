// from server: 100% by auto
// roc 2008-06 00402aa0  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402aa0
//
// 00402aa0  836c240410           sub dword ptr [esp + 4], 0x10
// 00402aa5  e956fcffff           jmp 0x402700
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
