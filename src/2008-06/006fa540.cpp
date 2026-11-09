// from server: 100% by auto
// roc 2008-06 006fa540  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fa540
//
// 006fa540  e86bfeffff           call 0x6fa3b0
// 006fa545  8bc8                 mov ecx, eax
// 006fa547  e944b00100           jmp 0x715590
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
