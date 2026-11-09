// from server: 100% by auto
// roc 2008-06 00560bd0  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00560bd0
//
// 00560bd0  83ec08               sub esp, 8
// 00560bd3  53                   push ebx
// 00560bd4  55                   push ebp
// 00560bd5  56                   push esi
// 00560bd6  8bf1                 mov esi, ecx
// 00560bd8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00560bdb  57                   push edi
// 00560bdc  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00560bdf  7606                 jbe 0x560be7
// 00560be1  ff1590288000         call dword ptr [0x802890]
// 00560be7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00560bea  8b2e                 mov ebp, dword ptr [esi]
// 00560bec  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00560bef  7606                 jbe 0x560bf7
// 00560bf1  ff1590288000         call dword ptr [0x802890]
// 00560bf7  8b06                 mov eax, dword ptr [esi]
// 00560bf9  53                   push ebx
// 00560bfa  55                   push ebp
// 00560bfb  57                   push edi
// 00560bfc  50                   push eax
// 00560bfd  8d442420             lea eax, [esp + 0x20]
// 00560c01  50                   push eax
// 00560c02  8bce                 mov ecx, esi
// 00560c04  e8c7fcffff           call 0x5608d0
// 00560c09  5f                   pop edi
// 00560c0a  5e                   pop esi
// 00560c0b  5d                   pop ebp
// 00560c0c  5b                   pop ebx
// 00560c0d  83c408               add esp, 8
// 00560c10  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
