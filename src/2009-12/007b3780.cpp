// from server: 100% by auto
// roc 2009-12 007b3780  unit: RBX::Assembly  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b3780
//
// 007b3780  53                   push ebx
// 007b3781  55                   push ebp
// 007b3782  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007b3788  56                   push esi
// 007b3789  57                   push edi
// 007b378a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007b378e  8bf1                 mov esi, ecx
// 007b3790  c70700000000         mov dword ptr [edi], 0
// 007b3796  85f6                 test esi, esi
// 007b3798  740e                 je 0x7b37a8
// 007b379a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007b379e  39460c               cmp dword ptr [esi + 0xc], eax
// 007b37a1  7705                 ja 0x7b37a8
// 007b37a3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 007b37a6  7606                 jbe 0x7b37ae
// 007b37a8  ffd5                 call ebp
// 007b37aa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007b37ae  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007b37b2  8b0e                 mov ecx, dword ptr [esi]
// 007b37b4  890f                 mov dword ptr [edi], ecx
// 007b37b6  894704               mov dword ptr [edi + 4], eax
// 007b37b9  395e0c               cmp dword ptr [esi + 0xc], ebx
// 007b37bc  7705                 ja 0x7b37c3
// 007b37be  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 007b37c1  7606                 jbe 0x7b37c9
// 007b37c3  ffd5                 call ebp
// 007b37c5  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007b37c9  8b07                 mov eax, dword ptr [edi]
// 007b37cb  8b0e                 mov ecx, dword ptr [esi]
// 007b37cd  85c0                 test eax, eax
// 007b37cf  7404                 je 0x7b37d5
// 007b37d1  3bc1                 cmp eax, ecx
// 007b37d3  7402                 je 0x7b37d7
// 007b37d5  ffd5                 call ebp
// 007b37d7  8b4f04               mov ecx, dword ptr [edi + 4]
// 007b37da  3bcb                 cmp ecx, ebx
// 007b37dc  7425                 je 0x7b3803
// 007b37de  8b4610               mov eax, dword ptr [esi + 0x10]
// 007b37e1  c644241400           mov byte ptr [esp + 0x14], 0
// 007b37e6  8b542414             mov edx, dword ptr [esp + 0x14]
// 007b37ea  52                   push edx
// 007b37eb  8b542418             mov edx, dword ptr [esp + 0x18]
// 007b37ef  52                   push edx
// 007b37f0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007b37f4  52                   push edx
// 007b37f5  51                   push ecx
// 007b37f6  50                   push eax
// 007b37f7  53                   push ebx
// 007b37f8  e883f9ffff           call 0x7b3180
// 007b37fd  83c418               add esp, 0x18
// 007b3800  894610               mov dword ptr [esi + 0x10], eax
// 007b3803  8bc7                 mov eax, edi
// 007b3805  5f                   pop edi
// 007b3806  5e                   pop esi
// 007b3807  5d                   pop ebp
// 007b3808  5b                   pop ebx
// 007b3809  c21400               ret 0x14
// standard library vector<pod12> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
