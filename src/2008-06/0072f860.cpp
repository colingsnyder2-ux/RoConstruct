// from server: 100% by auto
// roc 2008-06 0072f860  unit: CXTPControlComboBoxGalleryPopupBar  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0072f860
//
// 0072f860  e81bebffff           call 0x72e380
// 0072f865  8bc8                 mov ecx, eax
// 0072f867  e974e5ffff           jmp 0x72dde0
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
