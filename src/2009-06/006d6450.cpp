// from server: 100% by auto
// roc 2009-06 006d6450  unit: RBX::Mechanism  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d6450
//
// 006d6450  53                   push ebx
// 006d6451  55                   push ebp
// 006d6452  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 006d6458  56                   push esi
// 006d6459  57                   push edi
// 006d645a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006d645e  8bf1                 mov esi, ecx
// 006d6460  c70700000000         mov dword ptr [edi], 0
// 006d6466  85f6                 test esi, esi
// 006d6468  740e                 je 0x6d6478
// 006d646a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006d646e  39460c               cmp dword ptr [esi + 0xc], eax
// 006d6471  7705                 ja 0x6d6478
// 006d6473  3b4610               cmp eax, dword ptr [esi + 0x10]
// 006d6476  7606                 jbe 0x6d647e
// 006d6478  ffd5                 call ebp
// 006d647a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006d647e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006d6482  8b0e                 mov ecx, dword ptr [esi]
// 006d6484  890f                 mov dword ptr [edi], ecx
// 006d6486  894704               mov dword ptr [edi + 4], eax
// 006d6489  395e0c               cmp dword ptr [esi + 0xc], ebx
// 006d648c  7705                 ja 0x6d6493
// 006d648e  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 006d6491  7606                 jbe 0x6d6499
// 006d6493  ffd5                 call ebp
// 006d6495  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006d6499  8b07                 mov eax, dword ptr [edi]
// 006d649b  8b0e                 mov ecx, dword ptr [esi]
// 006d649d  85c0                 test eax, eax
// 006d649f  7404                 je 0x6d64a5
// 006d64a1  3bc1                 cmp eax, ecx
// 006d64a3  7402                 je 0x6d64a7
// 006d64a5  ffd5                 call ebp
// 006d64a7  8b4f04               mov ecx, dword ptr [edi + 4]
// 006d64aa  3bcb                 cmp ecx, ebx
// 006d64ac  7425                 je 0x6d64d3
// 006d64ae  8b4610               mov eax, dword ptr [esi + 0x10]
// 006d64b1  c644241400           mov byte ptr [esp + 0x14], 0
// 006d64b6  8b542414             mov edx, dword ptr [esp + 0x14]
// 006d64ba  52                   push edx
// 006d64bb  8b542418             mov edx, dword ptr [esp + 0x18]
// 006d64bf  52                   push edx
// 006d64c0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006d64c4  52                   push edx
// 006d64c5  51                   push ecx
// 006d64c6  50                   push eax
// 006d64c7  53                   push ebx
// 006d64c8  e873faffff           call 0x6d5f40
// 006d64cd  83c418               add esp, 0x18
// 006d64d0  894610               mov dword ptr [esi + 0x10], eax
// 006d64d3  8bc7                 mov eax, edi
// 006d64d5  5f                   pop edi
// 006d64d6  5e                   pop esi
// 006d64d7  5d                   pop ebp
// 006d64d8  5b                   pop ebx
// 006d64d9  c21400               ret 0x14
// standard library vector<pod12> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
