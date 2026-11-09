// from server: 100% by auto
// roc 2010-06 00960c70  unit: RBX::SphereBuilder  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00960c70
//
// 00960c70  56                   push esi
// 00960c71  8bf1                 mov esi, ecx
// 00960c73  8b06                 mov eax, dword ptr [esi]
// 00960c75  57                   push edi
// 00960c76  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 00960c7c  85c0                 test eax, eax
// 00960c7e  7508                 jne 0x960c88
// 00960c80  ffd7                 call edi
// 00960c82  8b06                 mov eax, dword ptr [esi]
// 00960c84  85c0                 test eax, eax
// 00960c86  7404                 je 0x960c8c
// 00960c88  8b00                 mov eax, dword ptr [eax]
// 00960c8a  eb02                 jmp 0x960c8e
// 00960c8c  33c0                 xor eax, eax
// 00960c8e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00960c91  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00960c94  7502                 jne 0x960c98
// 00960c96  ffd7                 call edi
// 00960c98  8b5604               mov edx, dword ptr [esi + 4]
// 00960c9b  8b02                 mov eax, dword ptr [edx]
// 00960c9d  894604               mov dword ptr [esi + 4], eax
// 00960ca0  5f                   pop edi
// 00960ca1  8bc6                 mov eax, esi
// 00960ca3  5e                   pop esi
// 00960ca4  c3                   ret 
// standard library list<ptr> (function ??E?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV012@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
