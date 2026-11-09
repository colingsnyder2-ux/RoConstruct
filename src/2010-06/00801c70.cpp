// from server: 100% by auto
// roc 2010-06 00801c70  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00801c70
//
// 00801c70  e86bfeffff           call 0x801ae0
// 00801c75  8bc8                 mov ecx, eax
// 00801c77  e9d4b00100           jmp 0x81cd50
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
