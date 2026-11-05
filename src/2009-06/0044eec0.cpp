// from server: 100% by auto
// roc 2009-06 0044eec0  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044eec0
//
// 0044eec0  836c240410           sub dword ptr [esp + 4], 0x10
// 0044eec5  e926f2fbff           jmp 0x40e0f0
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
