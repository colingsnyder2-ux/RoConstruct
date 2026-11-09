// from server: 100% by auto
// roc 2008-06 00498770  unit: RBX::Network::VPlayers::?$SignalDesc  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00498770
//
// 00498770  6aff                 push -1
// 00498772  68e8727d00           push 0x7d72e8
// 00498777  64a100000000         mov eax, dword ptr fs:[0]
// 0049877d  50                   push eax
// 0049877e  64892500000000       mov dword ptr fs:[0], esp
// 00498785  51                   push ecx
// 00498786  56                   push esi
// 00498787  8bf1                 mov esi, ecx
// 00498789  6a04                 push 4
// 0049878b  89742408             mov dword ptr [esp + 8], esi
// 0049878f  e88c812000           call 0x6a0920
// 00498794  83c404               add esp, 4
// 00498797  85c0                 test eax, eax
// 00498799  7404                 je 0x49879f
// 0049879b  8930                 mov dword ptr [eax], esi
// 0049879d  eb02                 jmp 0x4987a1
// 0049879f  33c0                 xor eax, eax
// 004987a1  8906                 mov dword ptr [esi], eax
// 004987a3  8bce                 mov ecx, esi
// 004987a5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004987ad  e8fee6ffff           call 0x496eb0
// 004987b2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004987b6  894614               mov dword ptr [esi + 0x14], eax
// 004987b9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004987c0  8bc6                 mov eax, esi
// 004987c2  5e                   pop esi
// 004987c3  64890d00000000       mov dword ptr fs:[0], ecx
// 004987ca  83c410               add esp, 0x10
// 004987cd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
