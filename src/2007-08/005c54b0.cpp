// from server: 100% by auto
// roc 2007-08 005c54b0  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c54b0
//
// 005c54b0  83ec08               sub esp, 8
// 005c54b3  56                   push esi
// 005c54b4  8bf1                 mov esi, ecx
// 005c54b6  8b5604               mov edx, dword ptr [esi + 4]
// 005c54b9  85d2                 test edx, edx
// 005c54bb  57                   push edi
// 005c54bc  7504                 jne 0x5c54c2
// 005c54be  33c9                 xor ecx, ecx
// 005c54c0  eb08                 jmp 0x5c54ca
// 005c54c2  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c54c5  2bca                 sub ecx, edx
// 005c54c7  c1f904               sar ecx, 4
// 005c54ca  85d2                 test edx, edx
// 005c54cc  743d                 je 0x5c550b
// 005c54ce  8b460c               mov eax, dword ptr [esi + 0xc]
// 005c54d1  2bc2                 sub eax, edx
// 005c54d3  c1f804               sar eax, 4
// 005c54d6  3bc8                 cmp ecx, eax
// 005c54d8  7331                 jae 0x5c550b
// 005c54da  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005c54de  8b542414             mov edx, dword ptr [esp + 0x14]
// 005c54e2  8b7e08               mov edi, dword ptr [esi + 8]
// 005c54e5  c644240800           mov byte ptr [esp + 8], 0
// 005c54ea  8b442408             mov eax, dword ptr [esp + 8]
// 005c54ee  50                   push eax
// 005c54ef  51                   push ecx
// 005c54f0  56                   push esi
// 005c54f1  52                   push edx
// 005c54f2  6a01                 push 1
// 005c54f4  57                   push edi
// 005c54f5  e8d6f9ffff           call 0x5c4ed0
// 005c54fa  83c418               add esp, 0x18
// 005c54fd  83c710               add edi, 0x10
// 005c5500  897e08               mov dword ptr [esi + 8], edi
// 005c5503  5f                   pop edi
// 005c5504  5e                   pop esi
// 005c5505  83c408               add esp, 8
// 005c5508  c20400               ret 4
// 005c550b  8b7e08               mov edi, dword ptr [esi + 8]
// 005c550e  3bd7                 cmp edx, edi
// 005c5510  7606                 jbe 0x5c5518
// 005c5512  ff15d8e67700         call dword ptr [0x77e6d8]
// 005c5518  8b442414             mov eax, dword ptr [esp + 0x14]
// 005c551c  50                   push eax
// 005c551d  57                   push edi
// 005c551e  56                   push esi
// 005c551f  8d4c2414             lea ecx, [esp + 0x14]
// 005c5523  51                   push ecx
// 005c5524  8bce                 mov ecx, esi
// 005c5526  e8f5feffff           call 0x5c5420
// 005c552b  5f                   pop edi
// 005c552c  5e                   pop esi
// 005c552d  83c408               add esp, 8
// 005c5530  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
