// from server: 100% by auto
// roc 2009-12 0048cb70  unit: G3D::Shader  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048cb70
//
// 0048cb70  53                   push ebx
// 0048cb71  55                   push ebp
// 0048cb72  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0048cb78  56                   push esi
// 0048cb79  57                   push edi
// 0048cb7a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0048cb7e  8bf1                 mov esi, ecx
// 0048cb80  c70700000000         mov dword ptr [edi], 0
// 0048cb86  85f6                 test esi, esi
// 0048cb88  740e                 je 0x48cb98
// 0048cb8a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048cb8e  39460c               cmp dword ptr [esi + 0xc], eax
// 0048cb91  7705                 ja 0x48cb98
// 0048cb93  3b4610               cmp eax, dword ptr [esi + 0x10]
// 0048cb96  7606                 jbe 0x48cb9e
// 0048cb98  ffd5                 call ebp
// 0048cb9a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048cb9e  8b0e                 mov ecx, dword ptr [esi]
// 0048cba0  894704               mov dword ptr [edi + 4], eax
// 0048cba3  8b442424             mov eax, dword ptr [esp + 0x24]
// 0048cba7  890f                 mov dword ptr [edi], ecx
// 0048cba9  39460c               cmp dword ptr [esi + 0xc], eax
// 0048cbac  7705                 ja 0x48cbb3
// 0048cbae  3b4610               cmp eax, dword ptr [esi + 0x10]
// 0048cbb1  7606                 jbe 0x48cbb9
// 0048cbb3  ffd5                 call ebp
// 0048cbb5  8b442424             mov eax, dword ptr [esp + 0x24]
// 0048cbb9  8b0e                 mov ecx, dword ptr [esi]
// 0048cbbb  8bd8                 mov ebx, eax
// 0048cbbd  8b07                 mov eax, dword ptr [edi]
// 0048cbbf  85c0                 test eax, eax
// 0048cbc1  7404                 je 0x48cbc7
// 0048cbc3  3bc1                 cmp eax, ecx
// 0048cbc5  7402                 je 0x48cbc9
// 0048cbc7  ffd5                 call ebp
// 0048cbc9  8b4704               mov eax, dword ptr [edi + 4]
// 0048cbcc  3bc3                 cmp eax, ebx
// 0048cbce  7411                 je 0x48cbe1
// 0048cbd0  8b5610               mov edx, dword ptr [esi + 0x10]
// 0048cbd3  50                   push eax
// 0048cbd4  52                   push edx
// 0048cbd5  53                   push ebx
// 0048cbd6  e8e5fdffff           call 0x48c9c0
// 0048cbdb  83c40c               add esp, 0xc
// 0048cbde  894610               mov dword ptr [esi + 0x10], eax
// 0048cbe1  8bc7                 mov eax, edi
// 0048cbe3  5f                   pop edi
// 0048cbe4  5e                   pop esi
// 0048cbe5  5d                   pop ebp
// 0048cbe6  5b                   pop ebx
// 0048cbe7  c21400               ret 0x14
// standard library vector<pod20> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
