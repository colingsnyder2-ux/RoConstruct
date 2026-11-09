// from server: 100% by auto
// roc 2007-08 00493a20  unit: RBX::Network::VPlayers::?$Notifier  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00493a20
//
// 00493a20  56                   push esi
// 00493a21  8bf1                 mov esi, ecx
// 00493a23  e828fdffff           call 0x493750
// 00493a28  8b4604               mov eax, dword ptr [esi + 4]
// 00493a2b  50                   push eax
// 00493a2c  e831c21900           call 0x62fc62
// 00493a31  83c404               add esp, 4
// 00493a34  c7460400000000       mov dword ptr [esi + 4], 0
// 00493a3b  5e                   pop esi
// 00493a3c  c3                   ret 
// standard library list<string> (function ?_Tidy@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
