// from server: 100% by auto
// roc 2008-06 0049c6c0  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049c6c0
//
// 0049c6c0  6aff                 push -1
// 0049c6c2  68e8727d00           push 0x7d72e8
// 0049c6c7  64a100000000         mov eax, dword ptr fs:[0]
// 0049c6cd  50                   push eax
// 0049c6ce  64892500000000       mov dword ptr fs:[0], esp
// 0049c6d5  51                   push ecx
// 0049c6d6  56                   push esi
// 0049c6d7  8bf1                 mov esi, ecx
// 0049c6d9  89742404             mov dword ptr [esp + 4], esi
// 0049c6dd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0049c6e5  e8e6f5ffff           call 0x49bcd0
// 0049c6ea  8b06                 mov eax, dword ptr [esi]
// 0049c6ec  50                   push eax
// 0049c6ed  e8883f2000           call 0x6a067a
// 0049c6f2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0049c6f6  83c404               add esp, 4
// 0049c6f9  5e                   pop esi
// 0049c6fa  64890d00000000       mov dword ptr fs:[0], ecx
// 0049c701  83c410               add esp, 0x10
// 0049c704  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
