// from server: 100% by auto
// roc 2009-06 005327a0  unit: RBX::BeveledBlockBuilder  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005327a0
//
// 005327a0  53                   push ebx
// 005327a1  55                   push ebp
// 005327a2  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 005327a8  56                   push esi
// 005327a9  57                   push edi
// 005327aa  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005327ae  8bf1                 mov esi, ecx
// 005327b0  c70700000000         mov dword ptr [edi], 0
// 005327b6  85f6                 test esi, esi
// 005327b8  740e                 je 0x5327c8
// 005327ba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005327be  39460c               cmp dword ptr [esi + 0xc], eax
// 005327c1  7705                 ja 0x5327c8
// 005327c3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 005327c6  7606                 jbe 0x5327ce
// 005327c8  ffd5                 call ebp
// 005327ca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005327ce  8b0e                 mov ecx, dword ptr [esi]
// 005327d0  894704               mov dword ptr [edi + 4], eax
// 005327d3  8b442424             mov eax, dword ptr [esp + 0x24]
// 005327d7  890f                 mov dword ptr [edi], ecx
// 005327d9  39460c               cmp dword ptr [esi + 0xc], eax
// 005327dc  7705                 ja 0x5327e3
// 005327de  3b4610               cmp eax, dword ptr [esi + 0x10]
// 005327e1  7606                 jbe 0x5327e9
// 005327e3  ffd5                 call ebp
// 005327e5  8b442424             mov eax, dword ptr [esp + 0x24]
// 005327e9  8b0e                 mov ecx, dword ptr [esi]
// 005327eb  8bd8                 mov ebx, eax
// 005327ed  8b07                 mov eax, dword ptr [edi]
// 005327ef  85c0                 test eax, eax
// 005327f1  7404                 je 0x5327f7
// 005327f3  3bc1                 cmp eax, ecx
// 005327f5  7402                 je 0x5327f9
// 005327f7  ffd5                 call ebp
// 005327f9  8b4704               mov eax, dword ptr [edi + 4]
// 005327fc  3bc3                 cmp eax, ebx
// 005327fe  7411                 je 0x532811
// 00532800  8b5610               mov edx, dword ptr [esi + 0x10]
// 00532803  50                   push eax
// 00532804  52                   push edx
// 00532805  53                   push ebx
// 00532806  e875feffff           call 0x532680
// 0053280b  83c40c               add esp, 0xc
// 0053280e  894610               mov dword ptr [esi + 0x10], eax
// 00532811  8bc7                 mov eax, edi
// 00532813  5f                   pop edi
// 00532814  5e                   pop esi
// 00532815  5d                   pop ebp
// 00532816  5b                   pop ebx
// 00532817  c21400               ret 0x14
// standard library vector<pod20> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
