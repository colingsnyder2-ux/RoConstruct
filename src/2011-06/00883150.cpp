// from server: 100% by auto
// roc 2011-06 00883150  unit: CXTPControlComboBoxGalleryPopupBar  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00883150
//
// 00883150  e8cbeaffff           call 0x881c20
// 00883155  8bc8                 mov ecx, eax
// 00883157  e934e5ffff           jmp 0x881690
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
