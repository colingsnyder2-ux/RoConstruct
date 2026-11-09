// from server: 100% by auto
// roc 2008-06 005e9f20  unit: RBX::PhysicsService  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e9f20
//
// 005e9f20  56                   push esi
// 005e9f21  8bf1                 mov esi, ecx
// 005e9f23  8b4610               mov eax, dword ptr [esi + 0x10]
// 005e9f26  85c0                 test eax, eax
// 005e9f28  7409                 je 0x5e9f33
// 005e9f2a  50                   push eax
// 005e9f2b  e84a670b00           call 0x6a067a
// 005e9f30  83c404               add esp, 4
// 005e9f33  8b4604               mov eax, dword ptr [esi + 4]
// 005e9f36  50                   push eax
// 005e9f37  c7461000000000       mov dword ptr [esi + 0x10], 0
// 005e9f3e  c7461400000000       mov dword ptr [esi + 0x14], 0
// 005e9f45  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005e9f4c  e829670b00           call 0x6a067a
// 005e9f51  83c404               add esp, 4
// 005e9f54  5e                   pop esi
// 005e9f55  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??1?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
