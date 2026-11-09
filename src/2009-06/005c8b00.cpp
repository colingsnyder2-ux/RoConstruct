// from server: 100% by auto
// roc 2009-06 005c8b00  unit: seg_005c0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c8b00
//
// 005c8b00  e85b3b1400           call 0x70c660
// 005c8b05  8bc8                 mov ecx, eax
// 005c8b07  e9c41f1400           jmp 0x70aad0
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
