// from server: 100% by auto
// roc 2009-06 0065a610  unit: RBX::VCamera::?$FactoryProduct  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065a610
//
// 0065a610  6aff                 push -1
// 0065a612  6878ef8600           push 0x86ef78
// 0065a617  64a100000000         mov eax, dword ptr fs:[0]
// 0065a61d  50                   push eax
// 0065a61e  64892500000000       mov dword ptr fs:[0], esp
// 0065a625  51                   push ecx
// 0065a626  56                   push esi
// 0065a627  6a04                 push 4
// 0065a629  8bf1                 mov esi, ecx
// 0065a62b  e808e40b00           call 0x718a38
// 0065a630  33c9                 xor ecx, ecx
// 0065a632  83c404               add esp, 4
// 0065a635  3bc1                 cmp eax, ecx
// 0065a637  7404                 je 0x65a63d
// 0065a639  8930                 mov dword ptr [eax], esi
// 0065a63b  eb02                 jmp 0x65a63f
// 0065a63d  33c0                 xor eax, eax
// 0065a63f  8906                 mov dword ptr [esi], eax
// 0065a641  894e0c               mov dword ptr [esi + 0xc], ecx
// 0065a644  894e10               mov dword ptr [esi + 0x10], ecx
// 0065a647  894e14               mov dword ptr [esi + 0x14], ecx
// 0065a64a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0065a64e  8bc6                 mov eax, esi
// 0065a650  5e                   pop esi
// 0065a651  64890d00000000       mov dword ptr fs:[0], ecx
// 0065a658  83c410               add esp, 0x10
// 0065a65b  c3                   ret 
// standard library vector<ptr> (function ??0?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
