// from server: 100% by auto
// roc 2009-06 006185b0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006185b0
//
// 006185b0  56                   push esi
// 006185b1  8bf1                 mov esi, ecx
// 006185b3  833e00               cmp dword ptr [esi], 0
// 006185b6  57                   push edi
// 006185b7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006185bd  7502                 jne 0x6185c1
// 006185bf  ffd7                 call edi
// 006185c1  8b4604               mov eax, dword ptr [esi + 4]
// 006185c4  8b4804               mov ecx, dword ptr [eax + 4]
// 006185c7  8b06                 mov eax, dword ptr [esi]
// 006185c9  894e04               mov dword ptr [esi + 4], ecx
// 006185cc  85c0                 test eax, eax
// 006185ce  7404                 je 0x6185d4
// 006185d0  8b00                 mov eax, dword ptr [eax]
// 006185d2  eb02                 jmp 0x6185d6
// 006185d4  33c0                 xor eax, eax
// 006185d6  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 006185d9  7502                 jne 0x6185dd
// 006185db  ffd7                 call edi
// 006185dd  5f                   pop edi
// 006185de  8bc6                 mov eax, esi
// 006185e0  5e                   pop esi
// 006185e1  c3                   ret 
// standard library list<ptr> (function ??F?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV012@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
