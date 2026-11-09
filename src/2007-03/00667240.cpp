// from server: 100% by auto
// roc 2007-03 00667240  unit: seg_00660000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00667240
//
// 00667240  8b442404             mov eax, dword ptr [esp + 4]
// 00667244  56                   push esi
// 00667245  8bf1                 mov esi, ecx
// 00667247  50                   push eax
// 00667248  66c7060000           mov word ptr [esi], 0
// 0066724d  e8fe3d0d00           call 0x73b050
// 00667252  8bc6                 mov eax, esi
// 00667254  5e                   pop esi
// 00667255  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\daocore.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daocore.cpp
