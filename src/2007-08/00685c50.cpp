// from server: 100% by auto
// roc 2007-08 00685c50  unit: CInstanceRecord::CNameItem  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00685c50
//
// 00685c50  8b442404             mov eax, dword ptr [esp + 4]
// 00685c54  56                   push esi
// 00685c55  8bf1                 mov esi, ecx
// 00685c57  50                   push eax
// 00685c58  66c7060000           mov word ptr [esi], 0
// 00685c5d  e85c2d0b00           call 0x7389be
// 00685c62  8bc6                 mov eax, esi
// 00685c64  5e                   pop esi
// 00685c65  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\daocore.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daocore.cpp
