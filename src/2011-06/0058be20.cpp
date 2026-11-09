// from server: 100% by auto
// roc 2011-06 0058be20  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0058be20
//
// 0058be20  e8db192700           call 0x7fd800
// 0058be25  8bc8                 mov ecx, eax
// 0058be27  e9c4fa2600           jmp 0x7fb8f0
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?Trim@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV12@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
