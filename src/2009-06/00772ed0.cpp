// from server: 100% by auto
// roc 2009-06 00772ed0  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00772ed0
//
// 00772ed0  e87bfeffff           call 0x772d50
// 00772ed5  8bc8                 mov ecx, eax
// 00772ed7  e954ae0100           jmp 0x78dd30
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
