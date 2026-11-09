// from server: 100% by auto
// roc 2011-06 0045a620  unit: VCRoblox3D::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045a620
//
// 0045a620  836c240410           sub dword ptr [esp + 4], 0x10
// 0045a625  e9e6faffff           jmp 0x45a110
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?Release@?$CMFCComObject@VCAccessibleProxy@ATL@@@@WBA@AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
