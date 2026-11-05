// from server: 100% by auto
// roc 2008-06 00498850  unit: RBX::Network::VPlayers::?$SignalDesc  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00498850
//
// 00498850  56                   push esi
// 00498851  8bf1                 mov esi, ecx
// 00498853  e818faffff           call 0x498270
// 00498858  8b4614               mov eax, dword ptr [esi + 0x14]
// 0049885b  50                   push eax
// 0049885c  e8197e2000           call 0x6a067a
// 00498861  83c404               add esp, 4
// 00498864  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0049886b  5e                   pop esi
// 0049886c  c3                   ret 
// standard library list<string> (function ?_Tidy@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
