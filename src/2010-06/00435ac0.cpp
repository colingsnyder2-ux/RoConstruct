// from server: 100% by auto
// roc 2010-06 00435ac0  unit: CPropGrid::UpdateItemsJob  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00435ac0
//
// 00435ac0  56                   push esi
// 00435ac1  8bf1                 mov esi, ecx
// 00435ac3  8b4610               mov eax, dword ptr [esi + 0x10]
// 00435ac6  85c0                 test eax, eax
// 00435ac8  7409                 je 0x435ad3
// 00435aca  50                   push eax
// 00435acb  e8ca1e3700           call 0x7a799a
// 00435ad0  83c404               add esp, 4
// 00435ad3  8b4604               mov eax, dword ptr [esi + 4]
// 00435ad6  50                   push eax
// 00435ad7  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00435ade  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00435ae5  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00435aec  e8a91e3700           call 0x7a799a
// 00435af1  83c404               add esp, 4
// 00435af4  5e                   pop esi
// 00435af5  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??1?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
