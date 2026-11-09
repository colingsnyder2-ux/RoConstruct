// from server: 100% by auto
// roc 2011-06 0046feb0  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0046feb0
//
// 0046feb0  836c240410           sub dword ptr [esp + 4], 0x10
// 0046feb5  e9f6f8ffff           jmp 0x46f7b0
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
