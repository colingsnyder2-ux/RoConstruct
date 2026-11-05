// from server: 100% by auto
// roc 2012-06 0047d270  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0047d270
//
// 0047d270  836c240410           sub dword ptr [esp + 4], 0x10
// 0047d275  e926f7ffff           jmp 0x47c9a0
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
