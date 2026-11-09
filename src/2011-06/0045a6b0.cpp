// from server: 100% by auto
// roc 2011-06 0045a6b0  unit: VCRoblox3D::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045a6b0
//
// 0045a6b0  836c240410           sub dword ptr [esp + 4], 0x10
// 0045a6b5  e936faffff           jmp 0x45a0f0
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
