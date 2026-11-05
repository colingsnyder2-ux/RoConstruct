// from server: 100% by auto
// roc 2009-12 005dd5e0  unit: RBX::ImmediateMeshGenAdapter  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005dd5e0
//
// 005dd5e0  56                   push esi
// 005dd5e1  8bf1                 mov esi, ecx
// 005dd5e3  8b4610               mov eax, dword ptr [esi + 0x10]
// 005dd5e6  85c0                 test eax, eax
// 005dd5e8  7409                 je 0x5dd5f3
// 005dd5ea  50                   push eax
// 005dd5eb  e86a622100           call 0x7f385a
// 005dd5f0  83c404               add esp, 4
// 005dd5f3  8b4604               mov eax, dword ptr [esi + 4]
// 005dd5f6  50                   push eax
// 005dd5f7  c7461000000000       mov dword ptr [esi + 0x10], 0
// 005dd5fe  c7461400000000       mov dword ptr [esi + 0x14], 0
// 005dd605  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005dd60c  e849622100           call 0x7f385a
// 005dd611  83c404               add esp, 4
// 005dd614  5e                   pop esi
// 005dd615  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??1?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
