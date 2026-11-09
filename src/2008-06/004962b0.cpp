// from server: 100% by auto
// roc 2008-06 004962b0  unit: RBX::Network::Players  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004962b0
//
// 004962b0  56                   push esi
// 004962b1  8bf1                 mov esi, ecx
// 004962b3  833e00               cmp dword ptr [esi], 0
// 004962b6  57                   push edi
// 004962b7  8b3d90288000         mov edi, dword ptr [0x802890]
// 004962bd  7502                 jne 0x4962c1
// 004962bf  ffd7                 call edi
// 004962c1  8b4604               mov eax, dword ptr [esi + 4]
// 004962c4  8b4804               mov ecx, dword ptr [eax + 4]
// 004962c7  8b06                 mov eax, dword ptr [esi]
// 004962c9  894e04               mov dword ptr [esi + 4], ecx
// 004962cc  85c0                 test eax, eax
// 004962ce  7404                 je 0x4962d4
// 004962d0  8b00                 mov eax, dword ptr [eax]
// 004962d2  eb02                 jmp 0x4962d6
// 004962d4  33c0                 xor eax, eax
// 004962d6  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 004962d9  7502                 jne 0x4962dd
// 004962db  ffd7                 call edi
// 004962dd  5f                   pop edi
// 004962de  8bc6                 mov eax, esi
// 004962e0  5e                   pop esi
// 004962e1  c3                   ret 
// standard library list<ptr> (function ??F?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV012@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
