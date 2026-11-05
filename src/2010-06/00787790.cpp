// from server: 100% by auto
// roc 2010-06 00787790  unit: RBX::HUMAN::GettingUp  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00787790
//
// 00787790  53                   push ebx
// 00787791  55                   push ebp
// 00787792  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00787798  56                   push esi
// 00787799  57                   push edi
// 0078779a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0078779e  8bf1                 mov esi, ecx
// 007877a0  c70700000000         mov dword ptr [edi], 0
// 007877a6  85f6                 test esi, esi
// 007877a8  740e                 je 0x7877b8
// 007877aa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007877ae  39460c               cmp dword ptr [esi + 0xc], eax
// 007877b1  7705                 ja 0x7877b8
// 007877b3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 007877b6  7606                 jbe 0x7877be
// 007877b8  ffd5                 call ebp
// 007877ba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007877be  8b0e                 mov ecx, dword ptr [esi]
// 007877c0  894704               mov dword ptr [edi + 4], eax
// 007877c3  8b442424             mov eax, dword ptr [esp + 0x24]
// 007877c7  890f                 mov dword ptr [edi], ecx
// 007877c9  39460c               cmp dword ptr [esi + 0xc], eax
// 007877cc  7705                 ja 0x7877d3
// 007877ce  3b4610               cmp eax, dword ptr [esi + 0x10]
// 007877d1  7606                 jbe 0x7877d9
// 007877d3  ffd5                 call ebp
// 007877d5  8b442424             mov eax, dword ptr [esp + 0x24]
// 007877d9  8b0e                 mov ecx, dword ptr [esi]
// 007877db  8bd8                 mov ebx, eax
// 007877dd  8b07                 mov eax, dword ptr [edi]
// 007877df  85c0                 test eax, eax
// 007877e1  7404                 je 0x7877e7
// 007877e3  3bc1                 cmp eax, ecx
// 007877e5  7402                 je 0x7877e9
// 007877e7  ffd5                 call ebp
// 007877e9  8b4704               mov eax, dword ptr [edi + 4]
// 007877ec  3bc3                 cmp eax, ebx
// 007877ee  7411                 je 0x787801
// 007877f0  8b5610               mov edx, dword ptr [esi + 0x10]
// 007877f3  50                   push eax
// 007877f4  52                   push edx
// 007877f5  53                   push ebx
// 007877f6  e8f52c1e00           call 0x96a4f0
// 007877fb  83c40c               add esp, 0xc
// 007877fe  894610               mov dword ptr [esi + 0x10], eax
// 00787801  8bc7                 mov eax, edi
// 00787803  5f                   pop edi
// 00787804  5e                   pop esi
// 00787805  5d                   pop ebp
// 00787806  5b                   pop ebx
// 00787807  c21400               ret 0x14
// standard library vector<pod20> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
