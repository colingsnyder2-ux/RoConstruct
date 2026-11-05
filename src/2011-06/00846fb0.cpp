// from server: 100% by auto
// roc 2011-06 00846fb0  unit: CXTPColorManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00846fb0
//
// 00846fb0  e82be4ffff           call 0x8453e0
// 00846fb5  8bc8                 mov ecx, eax
// 00846fb7  e964f6ffff           jmp 0x846620
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
