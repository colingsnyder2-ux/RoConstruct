// from server: 100% by auto
// roc 2009-12 005efb10  unit: G3D::Log  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005efb10
//
// 005efb10  8b442404             mov eax, dword ptr [esp + 4]
// 005efb14  56                   push esi
// 005efb15  50                   push eax
// 005efb16  8bf1                 mov esi, ecx
// 005efb18  e843ffffff           call 0x5efa60
// 005efb1d  8bc6                 mov eax, esi
// 005efb1f  5e                   pop esi
// 005efb20  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\appterm.cpp (function ??4?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appterm.cpp
