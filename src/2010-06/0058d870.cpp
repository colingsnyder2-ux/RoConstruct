// from server: 100% by auto
// roc 2010-06 0058d870  unit: seg_00580000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0058d870
//
// 0058d870  e83bdd2000           call 0x79b5b0
// 0058d875  8bc8                 mov ecx, eax
// 0058d877  e904bf2000           jmp 0x799780
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
