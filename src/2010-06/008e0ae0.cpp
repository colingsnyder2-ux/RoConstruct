// from server: 100% by auto
// roc 2010-06 008e0ae0  unit: Ogre::RbxMaterialAdapter  size: 401 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e0ae0
//
// 008e0ae0  55                   push ebp
// 008e0ae1  8bec                 mov ebp, esp
// 008e0ae3  6aff                 push -1
// 008e0ae5  6850f19b00           push 0x9bf150
// 008e0aea  64a100000000         mov eax, dword ptr fs:[0]
// 008e0af0  50                   push eax
// 008e0af1  64892500000000       mov dword ptr fs:[0], esp
// 008e0af8  83ec14               sub esp, 0x14
// 008e0afb  53                   push ebx
// 008e0afc  56                   push esi
// 008e0afd  8bf1                 mov esi, ecx
// 008e0aff  8b460c               mov eax, dword ptr [esi + 0xc]
// 008e0b02  57                   push edi
// 008e0b03  8965f0               mov dword ptr [ebp - 0x10], esp
// 008e0b06  85c0                 test eax, eax
// 008e0b08  7504                 jne 0x8e0b0e
// 008e0b0a  33c9                 xor ecx, ecx
// 008e0b0c  eb17                 jmp 0x8e0b25
// 008e0b0e  8b5614               mov edx, dword ptr [esi + 0x14]
// 008e0b11  2bd0                 sub edx, eax
// 008e0b13  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e0b18  f7ea                 imul edx
// 008e0b1a  d1fa                 sar edx, 1
// 008e0b1c  8bc2                 mov eax, edx
// 008e0b1e  c1e81f               shr eax, 0x1f
// 008e0b21  03c2                 add eax, edx
// 008e0b23  8bc8                 mov ecx, eax
// 008e0b25  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 008e0b28  85ff                 test edi, edi
// 008e0b2a  0f8449020000         je 0x8e0d79
// 008e0b30  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008e0b33  8bd3                 mov edx, ebx
// 008e0b35  2b560c               sub edx, dword ptr [esi + 0xc]
// 008e0b38  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e0b3d  f7ea                 imul edx
// 008e0b3f  d1fa                 sar edx, 1
// 008e0b41  8bc2                 mov eax, edx
// 008e0b43  c1e81f               shr eax, 0x1f
// 008e0b46  03c2                 add eax, edx
// 008e0b48  ba55555515           mov edx, 0x15555555
// 008e0b4d  2bd0                 sub edx, eax
// 008e0b4f  3bd7                 cmp edx, edi
// 008e0b51  7305                 jae 0x8e0b58
// 008e0b53  e89832b4ff           call 0x423df0
// 008e0b58  8d1438               lea edx, [eax + edi]
// 008e0b5b  3bca                 cmp ecx, edx
// 008e0b5d  0f8323010000         jae 0x8e0c86
// 008e0b63  8bc1                 mov eax, ecx
// 008e0b65  d1e8                 shr eax, 1
// 008e0b67  bb55555515           mov ebx, 0x15555555
// 008e0b6c  2bd8                 sub ebx, eax
// 008e0b6e  3bd9                 cmp ebx, ecx
// 008e0b70  730c                 jae 0x8e0b7e
// 008e0b72  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 008e0b79  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 008e0b7c  eb05                 jmp 0x8e0b83
// 008e0b7e  03c8                 add ecx, eax
// 008e0b80  894dec               mov dword ptr [ebp - 0x14], ecx
// 008e0b83  3bca                 cmp ecx, edx
// 008e0b85  7305                 jae 0x8e0b8c
// 008e0b87  8955ec               mov dword ptr [ebp - 0x14], edx
// 008e0b8a  8bca                 mov ecx, edx
// 008e0b8c  6a00                 push 0
// 008e0b8e  51                   push ecx
// 008e0b8f  e8fcde0000           call 0x8eea90
// 008e0b94  8b550c               mov edx, dword ptr [ebp + 0xc]
// 008e0b97  2b560c               sub edx, dword ptr [esi + 0xc]
// 008e0b9a  8bc8                 mov ecx, eax
// 008e0b9c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e0ba1  f7ea                 imul edx
// 008e0ba3  8b4514               mov eax, dword ptr [ebp + 0x14]
// 008e0ba6  d1fa                 sar edx, 1
// 008e0ba8  8bda                 mov ebx, edx
// 008e0baa  83c408               add esp, 8
// 008e0bad  c1eb1f               shr ebx, 0x1f
// 008e0bb0  03da                 add ebx, edx
// 008e0bb2  50                   push eax
// 008e0bb3  8d145b               lea edx, [ebx + ebx*2]
// 008e0bb6  8d0491               lea eax, [ecx + edx*4]
// 008e0bb9  57                   push edi
// 008e0bba  894d10               mov dword ptr [ebp + 0x10], ecx
// 008e0bbd  50                   push eax
// 008e0bbe  8bce                 mov ecx, esi
// 008e0bc0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 008e0bc7  e8d4ea0800           call 0x96f6a0
// 008e0bcc  8b460c               mov eax, dword ptr [esi + 0xc]
// 008e0bcf  c6451400             mov byte ptr [ebp + 0x14], 0
// 008e0bd3  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008e0bd6  52                   push edx
// 008e0bd7  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008e0bda  52                   push edx
// 008e0bdb  8b550c               mov edx, dword ptr [ebp + 0xc]
// 008e0bde  8d4e08               lea ecx, [esi + 8]
// 008e0be1  51                   push ecx
// 008e0be2  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 008e0be5  51                   push ecx
// 008e0be6  52                   push edx
// 008e0be7  50                   push eax
// 008e0be8  e863eaffff           call 0x8df650
// 008e0bed  8b5510               mov edx, dword ptr [ebp + 0x10]
// 008e0bf0  8b4610               mov eax, dword ptr [esi + 0x10]
// 008e0bf3  83c418               add esp, 0x18
// 008e0bf6  03df                 add ebx, edi
// 008e0bf8  8d0c5b               lea ecx, [ebx + ebx*2]
// 008e0bfb  8d0c8a               lea ecx, [edx + ecx*4]
// 008e0bfe  c6451400             mov byte ptr [ebp + 0x14], 0
// 008e0c02  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008e0c05  52                   push edx
// 008e0c06  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008e0c09  52                   push edx
// 008e0c0a  8d5608               lea edx, [esi + 8]
// 008e0c0d  52                   push edx
// 008e0c0e  51                   push ecx
// 008e0c0f  50                   push eax
// 008e0c10  8b450c               mov eax, dword ptr [ebp + 0xc]
// 008e0c13  50                   push eax
// 008e0c14  e837eaffff           call 0x8df650
// 008e0c19  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008e0c1c  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008e0c1f  2bcb                 sub ecx, ebx
// 008e0c21  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e0c26  f7e9                 imul ecx
// 008e0c28  d1fa                 sar edx, 1
// 008e0c2a  8bca                 mov ecx, edx
// 008e0c2c  c1e91f               shr ecx, 0x1f
// 008e0c2f  03ca                 add ecx, edx
// 008e0c31  83c418               add esp, 0x18
// 008e0c34  03f9                 add edi, ecx
// 008e0c36  85db                 test ebx, ebx
// 008e0c38  7409                 je 0x8e0c43
// 008e0c3a  53                   push ebx
// 008e0c3b  e85a6decff           call 0x7a799a
// 008e0c40  83c404               add esp, 4
// 008e0c43  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 008e0c46  8d1440               lea edx, [eax + eax*2]
// 008e0c49  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008e0c4c  8d0c90               lea ecx, [eax + edx*4]
// 008e0c4f  8d147f               lea edx, [edi + edi*2]
// 008e0c52  894e14               mov dword ptr [esi + 0x14], ecx
// 008e0c55  8d0c90               lea ecx, [eax + edx*4]
// 008e0c58  894e10               mov dword ptr [esi + 0x10], ecx
// 008e0c5b  89460c               mov dword ptr [esi + 0xc], eax
// 008e0c5e  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008e0c61  64890d00000000       mov dword ptr fs:[0], ecx
// 008e0c68  5f                   pop edi
// 008e0c69  5e                   pop esi
// 008e0c6a  5b                   pop ebx
// 008e0c6b  8be5                 mov esp, ebp
// 008e0c6d  5d                   pop ebp
// 008e0c6e  c21000               ret 0x10
// standard library vector<pod12> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
