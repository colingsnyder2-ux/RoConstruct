// from server: 100% by auto
// roc 2009-12 006c1c10  unit: RBX::VInstance::?$NonFactoryProduct  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c1c10
//
// 006c1c10  83ec08               sub esp, 8
// 006c1c13  53                   push ebx
// 006c1c14  55                   push ebp
// 006c1c15  56                   push esi
// 006c1c16  8bf1                 mov esi, ecx
// 006c1c18  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 006c1c1b  57                   push edi
// 006c1c1c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 006c1c1f  7606                 jbe 0x6c1c27
// 006c1c21  ff1560b79800         call dword ptr [0x98b760]
// 006c1c27  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006c1c2a  8b2e                 mov ebp, dword ptr [esi]
// 006c1c2c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 006c1c2f  7606                 jbe 0x6c1c37
// 006c1c31  ff1560b79800         call dword ptr [0x98b760]
// 006c1c37  8b06                 mov eax, dword ptr [esi]
// 006c1c39  53                   push ebx
// 006c1c3a  55                   push ebp
// 006c1c3b  57                   push edi
// 006c1c3c  50                   push eax
// 006c1c3d  8d442420             lea eax, [esp + 0x20]
// 006c1c41  50                   push eax
// 006c1c42  8bce                 mov ecx, esi
// 006c1c44  e8d7faffff           call 0x6c1720
// 006c1c49  5f                   pop edi
// 006c1c4a  5e                   pop esi
// 006c1c4b  5d                   pop ebp
// 006c1c4c  5b                   pop ebx
// 006c1c4d  83c408               add esp, 8
// 006c1c50  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
