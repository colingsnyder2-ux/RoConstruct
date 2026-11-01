// from server: 100% by auto
// roc 2009-12 007debb0  unit: RBX::ContactStage  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007debb0
//
// 007debb0  8b442404             mov eax, dword ptr [esp + 4]
// 007debb4  8b09                 mov ecx, dword ptr [ecx]
// 007debb6  50                   push eax
// 007debb7  51                   push ecx
// 007debb8  e83340e3ff           call 0x612bf0
// 007debbd  83c408               add esp, 8
// 007debc0  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?CompareNoCase@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QBEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
