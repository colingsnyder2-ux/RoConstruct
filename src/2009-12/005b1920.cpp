// from server: 100% by auto
// roc 2009-12 005b1920  unit: RBX::BrickBuilder  size: 401 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b1920
//
// 005b1920  55                   push ebp
// 005b1921  8bec                 mov ebp, esp
// 005b1923  6aff                 push -1
// 005b1925  6850ca9300           push 0x93ca50
// 005b192a  64a100000000         mov eax, dword ptr fs:[0]
// 005b1930  50                   push eax
// 005b1931  64892500000000       mov dword ptr fs:[0], esp
// 005b1938  83ec14               sub esp, 0x14
// 005b193b  53                   push ebx
// 005b193c  56                   push esi
// 005b193d  8bf1                 mov esi, ecx
// 005b193f  8b460c               mov eax, dword ptr [esi + 0xc]
// 005b1942  57                   push edi
// 005b1943  8965f0               mov dword ptr [ebp - 0x10], esp
// 005b1946  85c0                 test eax, eax
// 005b1948  7504                 jne 0x5b194e
// 005b194a  33c9                 xor ecx, ecx
// 005b194c  eb17                 jmp 0x5b1965
// 005b194e  8b5614               mov edx, dword ptr [esi + 0x14]
// 005b1951  2bd0                 sub edx, eax
// 005b1953  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b1958  f7ea                 imul edx
// 005b195a  d1fa                 sar edx, 1
// 005b195c  8bc2                 mov eax, edx
// 005b195e  c1e81f               shr eax, 0x1f
// 005b1961  03c2                 add eax, edx
// 005b1963  8bc8                 mov ecx, eax
// 005b1965  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 005b1968  85ff                 test edi, edi
// 005b196a  0f8449020000         je 0x5b1bb9
// 005b1970  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005b1973  8bd3                 mov edx, ebx
// 005b1975  2b560c               sub edx, dword ptr [esi + 0xc]
// 005b1978  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b197d  f7ea                 imul edx
// 005b197f  d1fa                 sar edx, 1
// 005b1981  8bc2                 mov eax, edx
// 005b1983  c1e81f               shr eax, 0x1f
// 005b1986  03c2                 add eax, edx
// 005b1988  ba55555515           mov edx, 0x15555555
// 005b198d  2bd0                 sub edx, eax
// 005b198f  3bd7                 cmp edx, edi
// 005b1991  7305                 jae 0x5b1998
// 005b1993  e8c807e9ff           call 0x442160
// 005b1998  8d1438               lea edx, [eax + edi]
// 005b199b  3bca                 cmp ecx, edx
// 005b199d  0f8323010000         jae 0x5b1ac6
// 005b19a3  8bc1                 mov eax, ecx
// 005b19a5  d1e8                 shr eax, 1
// 005b19a7  bb55555515           mov ebx, 0x15555555
// 005b19ac  2bd8                 sub ebx, eax
// 005b19ae  3bd9                 cmp ebx, ecx
// 005b19b0  730c                 jae 0x5b19be
// 005b19b2  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 005b19b9  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 005b19bc  eb05                 jmp 0x5b19c3
// 005b19be  03c8                 add ecx, eax
// 005b19c0  894dec               mov dword ptr [ebp - 0x14], ecx
// 005b19c3  3bca                 cmp ecx, edx
// 005b19c5  7305                 jae 0x5b19cc
// 005b19c7  8955ec               mov dword ptr [ebp - 0x14], edx
// 005b19ca  8bca                 mov ecx, edx
// 005b19cc  6a00                 push 0
// 005b19ce  51                   push ecx
// 005b19cf  e87c20eaff           call 0x453a50
// 005b19d4  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005b19d7  2b560c               sub edx, dword ptr [esi + 0xc]
// 005b19da  8bc8                 mov ecx, eax
// 005b19dc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b19e1  f7ea                 imul edx
// 005b19e3  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005b19e6  d1fa                 sar edx, 1
// 005b19e8  8bda                 mov ebx, edx
// 005b19ea  83c408               add esp, 8
// 005b19ed  c1eb1f               shr ebx, 0x1f
// 005b19f0  03da                 add ebx, edx
// 005b19f2  50                   push eax
// 005b19f3  8d145b               lea edx, [ebx + ebx*2]
// 005b19f6  8d0491               lea eax, [ecx + edx*4]
// 005b19f9  57                   push edi
// 005b19fa  894d10               mov dword ptr [ebp + 0x10], ecx
// 005b19fd  50                   push eax
// 005b19fe  8bce                 mov ecx, esi
// 005b1a00  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005b1a07  e8a403eeff           call 0x491db0
// 005b1a0c  8b460c               mov eax, dword ptr [esi + 0xc]
// 005b1a0f  c6451400             mov byte ptr [ebp + 0x14], 0
// 005b1a13  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005b1a16  52                   push edx
// 005b1a17  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005b1a1a  52                   push edx
// 005b1a1b  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005b1a1e  8d4e08               lea ecx, [esi + 8]
// 005b1a21  51                   push ecx
// 005b1a22  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 005b1a25  51                   push ecx
// 005b1a26  52                   push edx
// 005b1a27  50                   push eax
// 005b1a28  e863faffff           call 0x5b1490
// 005b1a2d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005b1a30  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b1a33  83c418               add esp, 0x18
// 005b1a36  03df                 add ebx, edi
// 005b1a38  8d0c5b               lea ecx, [ebx + ebx*2]
// 005b1a3b  8d0c8a               lea ecx, [edx + ecx*4]
// 005b1a3e  c6451400             mov byte ptr [ebp + 0x14], 0
// 005b1a42  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005b1a45  52                   push edx
// 005b1a46  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005b1a49  52                   push edx
// 005b1a4a  8d5608               lea edx, [esi + 8]
// 005b1a4d  52                   push edx
// 005b1a4e  51                   push ecx
// 005b1a4f  50                   push eax
// 005b1a50  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005b1a53  50                   push eax
// 005b1a54  e837faffff           call 0x5b1490
// 005b1a59  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005b1a5c  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005b1a5f  2bcb                 sub ecx, ebx
// 005b1a61  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b1a66  f7e9                 imul ecx
// 005b1a68  d1fa                 sar edx, 1
// 005b1a6a  8bca                 mov ecx, edx
// 005b1a6c  c1e91f               shr ecx, 0x1f
// 005b1a6f  03ca                 add ecx, edx
// 005b1a71  83c418               add esp, 0x18
// 005b1a74  03f9                 add edi, ecx
// 005b1a76  85db                 test ebx, ebx
// 005b1a78  7409                 je 0x5b1a83
// 005b1a7a  53                   push ebx
// 005b1a7b  e8da1d2400           call 0x7f385a
// 005b1a80  83c404               add esp, 4
// 005b1a83  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005b1a86  8d1440               lea edx, [eax + eax*2]
// 005b1a89  8b4510               mov eax, dword ptr [ebp + 0x10]
// 005b1a8c  8d0c90               lea ecx, [eax + edx*4]
// 005b1a8f  8d147f               lea edx, [edi + edi*2]
// 005b1a92  894e14               mov dword ptr [esi + 0x14], ecx
// 005b1a95  8d0c90               lea ecx, [eax + edx*4]
// 005b1a98  894e10               mov dword ptr [esi + 0x10], ecx
// 005b1a9b  89460c               mov dword ptr [esi + 0xc], eax
// 005b1a9e  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005b1aa1  64890d00000000       mov dword ptr fs:[0], ecx
// 005b1aa8  5f                   pop edi
// 005b1aa9  5e                   pop esi
// 005b1aaa  5b                   pop ebx
// 005b1aab  8be5                 mov esp, ebp
// 005b1aad  5d                   pop ebp
// 005b1aae  c21000               ret 0x10
// standard library vector<pod12> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
