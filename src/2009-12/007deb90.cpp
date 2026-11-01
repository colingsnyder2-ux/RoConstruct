// from server: 100% by auto
// roc 2009-12 007deb90  unit: RBX::ContactStage  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007deb90
//
// 007deb90  8b442404             mov eax, dword ptr [esp + 4]
// 007deb94  8b09                 mov ecx, dword ptr [ecx]
// 007deb96  50                   push eax
// 007deb97  51                   push ecx
// 007deb98  e82322e3ff           call 0x610dc0
// 007deb9d  83c408               add esp, 8
// 007deba0  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?CompareNoCase@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QBEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
