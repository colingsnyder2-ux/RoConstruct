// from server: 100% by auto
// roc 2009-12 0058b1d0  unit: RBX::BeveledBlockBuilder  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b1d0
//
// 0058b1d0  53                   push ebx
// 0058b1d1  55                   push ebp
// 0058b1d2  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0058b1d8  56                   push esi
// 0058b1d9  57                   push edi
// 0058b1da  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0058b1de  8bf1                 mov esi, ecx
// 0058b1e0  c70700000000         mov dword ptr [edi], 0
// 0058b1e6  85f6                 test esi, esi
// 0058b1e8  740e                 je 0x58b1f8
// 0058b1ea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058b1ee  39460c               cmp dword ptr [esi + 0xc], eax
// 0058b1f1  7705                 ja 0x58b1f8
// 0058b1f3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 0058b1f6  7606                 jbe 0x58b1fe
// 0058b1f8  ffd5                 call ebp
// 0058b1fa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058b1fe  8b0e                 mov ecx, dword ptr [esi]
// 0058b200  894704               mov dword ptr [edi + 4], eax
// 0058b203  8b442424             mov eax, dword ptr [esp + 0x24]
// 0058b207  890f                 mov dword ptr [edi], ecx
// 0058b209  39460c               cmp dword ptr [esi + 0xc], eax
// 0058b20c  7705                 ja 0x58b213
// 0058b20e  3b4610               cmp eax, dword ptr [esi + 0x10]
// 0058b211  7606                 jbe 0x58b219
// 0058b213  ffd5                 call ebp
// 0058b215  8b442424             mov eax, dword ptr [esp + 0x24]
// 0058b219  8b0e                 mov ecx, dword ptr [esi]
// 0058b21b  8bd8                 mov ebx, eax
// 0058b21d  8b07                 mov eax, dword ptr [edi]
// 0058b21f  85c0                 test eax, eax
// 0058b221  7404                 je 0x58b227
// 0058b223  3bc1                 cmp eax, ecx
// 0058b225  7402                 je 0x58b229
// 0058b227  ffd5                 call ebp
// 0058b229  8b4704               mov eax, dword ptr [edi + 4]
// 0058b22c  3bc3                 cmp eax, ebx
// 0058b22e  7411                 je 0x58b241
// 0058b230  8b5610               mov edx, dword ptr [esi + 0x10]
// 0058b233  50                   push eax
// 0058b234  52                   push edx
// 0058b235  53                   push ebx
// 0058b236  e825feffff           call 0x58b060
// 0058b23b  83c40c               add esp, 0xc
// 0058b23e  894610               mov dword ptr [esi + 0x10], eax
// 0058b241  8bc7                 mov eax, edi
// 0058b243  5f                   pop edi
// 0058b244  5e                   pop esi
// 0058b245  5d                   pop ebp
// 0058b246  5b                   pop ebx
// 0058b247  c21400               ret 0x14
// standard library vector<pod20> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
