// from server: 100% by auto
// roc 2009-12 004fcaa0  unit: RBX::Network::Player  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004fcaa0
//
// 004fcaa0  6aff                 push -1
// 004fcaa2  68d8c59300           push 0x93c5d8
// 004fcaa7  64a100000000         mov eax, dword ptr fs:[0]
// 004fcaad  50                   push eax
// 004fcaae  64892500000000       mov dword ptr fs:[0], esp
// 004fcab5  51                   push ecx
// 004fcab6  56                   push esi
// 004fcab7  8bf1                 mov esi, ecx
// 004fcab9  89742404             mov dword ptr [esp + 4], esi
// 004fcabd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004fcac5  e876d4ffff           call 0x4f9f40
// 004fcaca  8b4614               mov eax, dword ptr [esi + 0x14]
// 004fcacd  50                   push eax
// 004fcace  e8876d2f00           call 0x7f385a
// 004fcad3  8b0e                 mov ecx, dword ptr [esi]
// 004fcad5  51                   push ecx
// 004fcad6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004fcadd  e8786d2f00           call 0x7f385a
// 004fcae2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004fcae6  83c408               add esp, 8
// 004fcae9  5e                   pop esi
// 004fcaea  64890d00000000       mov dword ptr fs:[0], ecx
// 004fcaf1  83c410               add esp, 0x10
// 004fcaf4  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
