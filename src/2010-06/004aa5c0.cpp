// from server: 100% by auto
// roc 2010-06 004aa5c0  unit: RBX::Network::Player  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004aa5c0
//
// 004aa5c0  6aff                 push -1
// 004aa5c2  6858a29900           push 0x99a258
// 004aa5c7  64a100000000         mov eax, dword ptr fs:[0]
// 004aa5cd  50                   push eax
// 004aa5ce  64892500000000       mov dword ptr fs:[0], esp
// 004aa5d5  51                   push ecx
// 004aa5d6  56                   push esi
// 004aa5d7  8bf1                 mov esi, ecx
// 004aa5d9  89742404             mov dword ptr [esp + 4], esi
// 004aa5dd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004aa5e5  e896d6ffff           call 0x4a7c80
// 004aa5ea  8b4614               mov eax, dword ptr [esi + 0x14]
// 004aa5ed  50                   push eax
// 004aa5ee  e8a7d32f00           call 0x7a799a
// 004aa5f3  8b0e                 mov ecx, dword ptr [esi]
// 004aa5f5  51                   push ecx
// 004aa5f6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004aa5fd  e898d32f00           call 0x7a799a
// 004aa602  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004aa606  83c408               add esp, 8
// 004aa609  5e                   pop esi
// 004aa60a  64890d00000000       mov dword ptr fs:[0], ecx
// 004aa611  83c410               add esp, 0x10
// 004aa614  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
