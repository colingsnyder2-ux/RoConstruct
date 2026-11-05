// from server: 100% by auto
// roc 2007-08 004935d0  unit: RBX::Network::VPlayers::?$Notifier  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004935d0
//
// 004935d0  56                   push esi
// 004935d1  8bf1                 mov esi, ecx
// 004935d3  e8e8fcffff           call 0x4932c0
// 004935d8  8b4604               mov eax, dword ptr [esi + 4]
// 004935db  50                   push eax
// 004935dc  e881c61900           call 0x62fc62
// 004935e1  83c404               add esp, 4
// 004935e4  c7460400000000       mov dword ptr [esi + 4], 0
// 004935eb  5e                   pop esi
// 004935ec  c3                   ret 
// standard library list<string> (function ?_Tidy@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
