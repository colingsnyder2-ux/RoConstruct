// from server: 100% by auto
// roc 2008-06 0055e590  unit: RBX::MD5HasherImpl  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055e590
//
// 0055e590  6aff                 push -1
// 0055e592  68e8727d00           push 0x7d72e8
// 0055e597  64a100000000         mov eax, dword ptr fs:[0]
// 0055e59d  50                   push eax
// 0055e59e  64892500000000       mov dword ptr fs:[0], esp
// 0055e5a5  51                   push ecx
// 0055e5a6  56                   push esi
// 0055e5a7  8bf1                 mov esi, ecx
// 0055e5a9  6a04                 push 4
// 0055e5ab  89742408             mov dword ptr [esp + 8], esi
// 0055e5af  e86c231400           call 0x6a0920
// 0055e5b4  83c404               add esp, 4
// 0055e5b7  85c0                 test eax, eax
// 0055e5b9  7404                 je 0x55e5bf
// 0055e5bb  8930                 mov dword ptr [eax], esi
// 0055e5bd  eb02                 jmp 0x55e5c1
// 0055e5bf  33c0                 xor eax, eax
// 0055e5c1  8906                 mov dword ptr [esi], eax
// 0055e5c3  8bce                 mov ecx, esi
// 0055e5c5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0055e5cd  e8ce840700           call 0x5d6aa0
// 0055e5d2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0055e5d6  894614               mov dword ptr [esi + 0x14], eax
// 0055e5d9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0055e5e0  8bc6                 mov eax, esi
// 0055e5e2  5e                   pop esi
// 0055e5e3  64890d00000000       mov dword ptr fs:[0], ecx
// 0055e5ea  83c410               add esp, 0x10
// 0055e5ed  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
