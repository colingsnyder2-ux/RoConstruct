// from server: 100% by auto
// roc 2010-06 008260c0  unit: CXTPControlComboBoxGalleryPopupBar  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008260c0
//
// 008260c0  e8cbeaffff           call 0x824b90
// 008260c5  8bc8                 mov ecx, eax
// 008260c7  e924e5ffff           jmp 0x8245f0
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
