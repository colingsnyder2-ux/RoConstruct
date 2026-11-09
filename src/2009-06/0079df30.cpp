// from server: 100% by auto
// roc 2009-06 0079df30  unit: CXTPControlComboBoxGalleryPopupBar  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079df30
//
// 0079df30  e8cbeaffff           call 0x79ca00
// 0079df35  8bc8                 mov ecx, eax
// 0079df37  e934e5ffff           jmp 0x79c470
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
