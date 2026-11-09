// from server: 100% by auto
// roc 2010-06 005c8df0  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005c8df0
//
// 005c8df0  6aff                 push -1
// 005c8df2  6858a29900           push 0x99a258
// 005c8df7  64a100000000         mov eax, dword ptr fs:[0]
// 005c8dfd  50                   push eax
// 005c8dfe  64892500000000       mov dword ptr fs:[0], esp
// 005c8e05  51                   push ecx
// 005c8e06  56                   push esi
// 005c8e07  6a04                 push 4
// 005c8e09  8bf1                 mov esi, ecx
// 005c8e0b  e890eb1d00           call 0x7a79a0
// 005c8e10  33c9                 xor ecx, ecx
// 005c8e12  83c404               add esp, 4
// 005c8e15  3bc1                 cmp eax, ecx
// 005c8e17  7404                 je 0x5c8e1d
// 005c8e19  8930                 mov dword ptr [eax], esi
// 005c8e1b  eb02                 jmp 0x5c8e1f
// 005c8e1d  33c0                 xor eax, eax
// 005c8e1f  8906                 mov dword ptr [esi], eax
// 005c8e21  894e0c               mov dword ptr [esi + 0xc], ecx
// 005c8e24  894e10               mov dword ptr [esi + 0x10], ecx
// 005c8e27  894e14               mov dword ptr [esi + 0x14], ecx
// 005c8e2a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c8e2e  8bc6                 mov eax, esi
// 005c8e30  5e                   pop esi
// 005c8e31  64890d00000000       mov dword ptr fs:[0], ecx
// 005c8e38  83c410               add esp, 0x10
// 005c8e3b  c3                   ret 
// standard library vector<ptr> (function ??0?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
