// from server: 100% by auto
// roc 2008-06 004987f0  unit: RBX::Network::VPlayers::?$SignalDesc  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004987f0
//
// 004987f0  6aff                 push -1
// 004987f2  68e8727d00           push 0x7d72e8
// 004987f7  64a100000000         mov eax, dword ptr fs:[0]
// 004987fd  50                   push eax
// 004987fe  64892500000000       mov dword ptr fs:[0], esp
// 00498805  51                   push ecx
// 00498806  56                   push esi
// 00498807  8bf1                 mov esi, ecx
// 00498809  6a04                 push 4
// 0049880b  89742408             mov dword ptr [esp + 8], esi
// 0049880f  e80c812000           call 0x6a0920
// 00498814  83c404               add esp, 4
// 00498817  85c0                 test eax, eax
// 00498819  7404                 je 0x49881f
// 0049881b  8930                 mov dword ptr [eax], esi
// 0049881d  eb02                 jmp 0x498821
// 0049881f  33c0                 xor eax, eax
// 00498821  8906                 mov dword ptr [esi], eax
// 00498823  8bce                 mov ecx, esi
// 00498825  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0049882d  e89ee6ffff           call 0x496ed0
// 00498832  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00498836  894614               mov dword ptr [esi + 0x14], eax
// 00498839  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00498840  8bc6                 mov eax, esi
// 00498842  5e                   pop esi
// 00498843  64890d00000000       mov dword ptr fs:[0], ecx
// 0049884a  83c410               add esp, 0x10
// 0049884d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
