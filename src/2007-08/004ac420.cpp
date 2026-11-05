// from server: 100% by auto
// roc 2007-08 004ac420  unit: RBX::Network::Replicator::DeleteInstanceItem  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ac420
//
// 004ac420  56                   push esi
// 004ac421  8bf1                 mov esi, ecx
// 004ac423  e8a8f6f7ff           call 0x42bad0
// 004ac428  8b4604               mov eax, dword ptr [esi + 4]
// 004ac42b  50                   push eax
// 004ac42c  e831381800           call 0x62fc62
// 004ac431  83c404               add esp, 4
// 004ac434  c7460400000000       mov dword ptr [esi + 4], 0
// 004ac43b  5e                   pop esi
// 004ac43c  c3                   ret 
// standard library list<string> (function ?_Tidy@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
