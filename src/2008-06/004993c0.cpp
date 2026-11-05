// from server: 100% by auto
// roc 2008-06 004993c0  unit: RBX::Network::VPlayers::?$SignalDesc  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004993c0
//
// 004993c0  6aff                 push -1
// 004993c2  68e8727d00           push 0x7d72e8
// 004993c7  64a100000000         mov eax, dword ptr fs:[0]
// 004993cd  50                   push eax
// 004993ce  64892500000000       mov dword ptr fs:[0], esp
// 004993d5  51                   push ecx
// 004993d6  56                   push esi
// 004993d7  8bf1                 mov esi, ecx
// 004993d9  89742404             mov dword ptr [esp + 4], esi
// 004993dd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004993e5  e876f6ffff           call 0x498a60
// 004993ea  8b4614               mov eax, dword ptr [esi + 0x14]
// 004993ed  50                   push eax
// 004993ee  e887722000           call 0x6a067a
// 004993f3  8b0e                 mov ecx, dword ptr [esi]
// 004993f5  51                   push ecx
// 004993f6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004993fd  e878722000           call 0x6a067a
// 00499402  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00499406  83c408               add esp, 8
// 00499409  5e                   pop esi
// 0049940a  64890d00000000       mov dword ptr fs:[0], ecx
// 00499411  83c410               add esp, 0x10
// 00499414  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
