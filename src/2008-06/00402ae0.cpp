// from server: 100% by auto
// roc 2008-06 00402ae0  unit: VCWorkspace::?$CComContainedObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402ae0
//
// 00402ae0  836c240410           sub dword ptr [esp + 4], 0x10
// 00402ae5  e976feffff           jmp 0x402960
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
