// from server: 100% by auto
// roc 2009-06 00426b20  unit: boost::any::H::?$holder  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00426b20
//
// 00426b20  83ec08               sub esp, 8
// 00426b23  56                   push esi
// 00426b24  8bf1                 mov esi, ecx
// 00426b26  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00426b29  57                   push edi
// 00426b2a  85c9                 test ecx, ecx
// 00426b2c  7504                 jne 0x426b32
// 00426b2e  33c0                 xor eax, eax
// 00426b30  eb08                 jmp 0x426b3a
// 00426b32  8b4614               mov eax, dword ptr [esi + 0x14]
// 00426b35  2bc1                 sub eax, ecx
// 00426b37  c1f803               sar eax, 3
// 00426b3a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00426b3d  8bd7                 mov edx, edi
// 00426b3f  2bd1                 sub edx, ecx
// 00426b41  c1fa03               sar edx, 3
// 00426b44  3bd0                 cmp edx, eax
// 00426b46  7331                 jae 0x426b79
// 00426b48  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00426b4c  c644240800           mov byte ptr [esp + 8], 0
// 00426b51  8b442408             mov eax, dword ptr [esp + 8]
// 00426b55  50                   push eax
// 00426b56  8b442418             mov eax, dword ptr [esp + 0x18]
// 00426b5a  51                   push ecx
// 00426b5b  8d5608               lea edx, [esi + 8]
// 00426b5e  52                   push edx
// 00426b5f  50                   push eax
// 00426b60  6a01                 push 1
// 00426b62  57                   push edi
// 00426b63  e868f8ffff           call 0x4263d0
// 00426b68  83c418               add esp, 0x18
// 00426b6b  83c708               add edi, 8
// 00426b6e  897e10               mov dword ptr [esi + 0x10], edi
// 00426b71  5f                   pop edi
// 00426b72  5e                   pop esi
// 00426b73  83c408               add esp, 8
// 00426b76  c20400               ret 4
// 00426b79  3bcf                 cmp ecx, edi
// 00426b7b  7606                 jbe 0x426b83
// 00426b7d  ff15ace98900         call dword ptr [0x89e9ac]
// 00426b83  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00426b87  8b06                 mov eax, dword ptr [esi]
// 00426b89  51                   push ecx
// 00426b8a  57                   push edi
// 00426b8b  50                   push eax
// 00426b8c  8d542414             lea edx, [esp + 0x14]
// 00426b90  52                   push edx
// 00426b91  8bce                 mov ecx, esi
// 00426b93  e8c8feffff           call 0x426a60
// 00426b98  5f                   pop edi
// 00426b99  5e                   pop esi
// 00426b9a  83c408               add esp, 8
// 00426b9d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
