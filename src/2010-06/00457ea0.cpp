// from server: 100% by auto
// roc 2010-06 00457ea0  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00457ea0
//
// 00457ea0  836c240410           sub dword ptr [esp + 4], 0x10
// 00457ea5  e936f8ffff           jmp 0x4576e0
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
