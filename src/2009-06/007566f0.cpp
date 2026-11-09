// from server: 100% by auto
// roc 2009-06 007566f0  unit: CXTPColorManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007566f0
//
// 007566f0  e82be4ffff           call 0x754b20
// 007566f5  8bc8                 mov ecx, eax
// 007566f7  e964f6ffff           jmp 0x755d60
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
