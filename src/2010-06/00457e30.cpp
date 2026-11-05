// from server: 100% by auto
// roc 2010-06 00457e30  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00457e30
//
// 00457e30  836c240410           sub dword ptr [esp + 4], 0x10
// 00457e35  e9e6f8ffff           jmp 0x457720
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
