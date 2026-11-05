// from server: 100% by auto
// roc 2008-06 006e1910  unit: CXTPColorManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006e1910
//
// 006e1910  e82be4ffff           call 0x6dfd40
// 006e1915  8bc8                 mov ecx, eax
// 006e1917  e964f6ffff           jmp 0x6e0f80
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
