// from server: 100% by auto
// roc 2008-06 004293d0  unit: ThreadLogManager  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004293d0
//
// 004293d0  6aff                 push -1
// 004293d2  68e8727d00           push 0x7d72e8
// 004293d7  64a100000000         mov eax, dword ptr fs:[0]
// 004293dd  50                   push eax
// 004293de  64892500000000       mov dword ptr fs:[0], esp
// 004293e5  51                   push ecx
// 004293e6  56                   push esi
// 004293e7  6a04                 push 4
// 004293e9  8bf1                 mov esi, ecx
// 004293eb  e830752700           call 0x6a0920
// 004293f0  33c9                 xor ecx, ecx
// 004293f2  83c404               add esp, 4
// 004293f5  3bc1                 cmp eax, ecx
// 004293f7  7404                 je 0x4293fd
// 004293f9  8930                 mov dword ptr [eax], esi
// 004293fb  eb02                 jmp 0x4293ff
// 004293fd  33c0                 xor eax, eax
// 004293ff  8906                 mov dword ptr [esi], eax
// 00429401  894e0c               mov dword ptr [esi + 0xc], ecx
// 00429404  894e10               mov dword ptr [esi + 0x10], ecx
// 00429407  894e14               mov dword ptr [esi + 0x14], ecx
// 0042940a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042940e  8bc6                 mov eax, esi
// 00429410  5e                   pop esi
// 00429411  64890d00000000       mov dword ptr fs:[0], ecx
// 00429418  83c410               add esp, 0x10
// 0042941b  c3                   ret 
// standard library vector<ptr> (function ??0?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
