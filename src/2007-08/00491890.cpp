// from server: 100% by auto
// roc 2007-08 00491890  unit: RBX::Network::Players  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00491890
//
// 00491890  56                   push esi
// 00491891  8bf1                 mov esi, ecx
// 00491893  833e00               cmp dword ptr [esi], 0
// 00491896  57                   push edi
// 00491897  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0049189d  7502                 jne 0x4918a1
// 0049189f  ffd7                 call edi
// 004918a1  8b06                 mov eax, dword ptr [esi]
// 004918a3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004918a6  3b4804               cmp ecx, dword ptr [eax + 4]
// 004918a9  7502                 jne 0x4918ad
// 004918ab  ffd7                 call edi
// 004918ad  8b5604               mov edx, dword ptr [esi + 4]
// 004918b0  8b02                 mov eax, dword ptr [edx]
// 004918b2  894604               mov dword ptr [esi + 4], eax
// 004918b5  5f                   pop edi
// 004918b6  8bc6                 mov eax, esi
// 004918b8  5e                   pop esi
// 004918b9  c3                   ret 
// standard library list<ptr> (function ??E?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV012@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
