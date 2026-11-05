// from server: 100% by auto
// roc 2010-06 00960b20  unit: RBX::SphereBuilder  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00960b20
//
// 00960b20  56                   push esi
// 00960b21  8bf1                 mov esi, ecx
// 00960b23  833e00               cmp dword ptr [esi], 0
// 00960b26  57                   push edi
// 00960b27  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 00960b2d  7502                 jne 0x960b31
// 00960b2f  ffd7                 call edi
// 00960b31  8b4604               mov eax, dword ptr [esi + 4]
// 00960b34  8b4804               mov ecx, dword ptr [eax + 4]
// 00960b37  8b06                 mov eax, dword ptr [esi]
// 00960b39  894e04               mov dword ptr [esi + 4], ecx
// 00960b3c  85c0                 test eax, eax
// 00960b3e  7404                 je 0x960b44
// 00960b40  8b00                 mov eax, dword ptr [eax]
// 00960b42  eb02                 jmp 0x960b46
// 00960b44  33c0                 xor eax, eax
// 00960b46  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00960b49  7502                 jne 0x960b4d
// 00960b4b  ffd7                 call edi
// 00960b4d  5f                   pop edi
// 00960b4e  8bc6                 mov eax, esi
// 00960b50  5e                   pop esi
// 00960b51  c3                   ret 
// standard library list<ptr> (function ??F?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV012@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
