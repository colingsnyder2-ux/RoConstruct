// from server: 100% by auto
// roc 2009-06 0044ee60  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044ee60
//
// 0044ee60  836c240410           sub dword ptr [esp + 4], 0x10
// 0044ee65  e9e6f9ffff           jmp 0x44e850
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
