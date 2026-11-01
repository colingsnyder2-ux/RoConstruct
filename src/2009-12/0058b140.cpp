// from server: 100% by auto
// roc 2009-12 0058b140  unit: RBX::BeveledBlockBuilder  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b140
//
// 0058b140  6aff                 push -1
// 0058b142  68d8c59300           push 0x93c5d8
// 0058b147  64a100000000         mov eax, dword ptr fs:[0]
// 0058b14d  50                   push eax
// 0058b14e  64892500000000       mov dword ptr fs:[0], esp
// 0058b155  51                   push ecx
// 0058b156  56                   push esi
// 0058b157  6a04                 push 4
// 0058b159  8bf1                 mov esi, ecx
// 0058b15b  e800872600           call 0x7f3860
// 0058b160  33c9                 xor ecx, ecx
// 0058b162  83c404               add esp, 4
// 0058b165  3bc1                 cmp eax, ecx
// 0058b167  7404                 je 0x58b16d
// 0058b169  8930                 mov dword ptr [eax], esi
// 0058b16b  eb02                 jmp 0x58b16f
// 0058b16d  33c0                 xor eax, eax
// 0058b16f  8906                 mov dword ptr [esi], eax
// 0058b171  894e0c               mov dword ptr [esi + 0xc], ecx
// 0058b174  894e10               mov dword ptr [esi + 0x10], ecx
// 0058b177  894e14               mov dword ptr [esi + 0x14], ecx
// 0058b17a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0058b17e  8bc6                 mov eax, esi
// 0058b180  5e                   pop esi
// 0058b181  64890d00000000       mov dword ptr fs:[0], ecx
// 0058b188  83c410               add esp, 0x10
// 0058b18b  c3                   ret 
// standard library vector<ptr> (function ??0?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
