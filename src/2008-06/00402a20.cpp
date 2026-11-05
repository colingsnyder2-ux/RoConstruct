// from server: 100% by auto
// roc 2008-06 00402a20  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402a20
//
// 00402a20  836c240410           sub dword ptr [esp + 4], 0x10
// 00402a25  e906fdffff           jmp 0x402730
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
