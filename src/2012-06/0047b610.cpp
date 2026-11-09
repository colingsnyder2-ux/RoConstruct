// from server: 100% by auto
// roc 2012-06 0047b610  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0047b610
//
// 0047b610  836c240410           sub dword ptr [esp + 4], 0x10
// 0047b615  e956f4ffff           jmp 0x47aa70
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
