// from server: 100% by auto
// roc 2010-06 007e56f0  unit: CXTPColorManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e56f0
//
// 007e56f0  e82be4ffff           call 0x7e3b20
// 007e56f5  8bc8                 mov ecx, eax
// 007e56f7  e964f6ffff           jmp 0x7e4d60
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
