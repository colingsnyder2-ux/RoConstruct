// from server: 100% by auto
// roc 2007-03 00412d20  unit: seg_00410000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00412d20
//
// 00412d20  8b442404             mov eax, dword ptr [esp + 4]
// 00412d24  56                   push esi
// 00412d25  8bf1                 mov esi, ecx
// 00412d27  50                   push eax
// 00412d28  66c7060000           mov word ptr [esi], 0
// 00412d2d  e88efaffff           call 0x4127c0
// 00412d32  8bc6                 mov eax, esi
// 00412d34  5e                   pop esi
// 00412d35  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\daocore.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daocore.cpp
