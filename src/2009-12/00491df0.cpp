// from server: 100% by auto
// roc 2009-12 00491df0  unit: Ogre::RbxEntity  size: 401 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00491df0
//
// 00491df0  55                   push ebp
// 00491df1  8bec                 mov ebp, esp
// 00491df3  6aff                 push -1
// 00491df5  6840009300           push 0x930040
// 00491dfa  64a100000000         mov eax, dword ptr fs:[0]
// 00491e00  50                   push eax
// 00491e01  64892500000000       mov dword ptr fs:[0], esp
// 00491e08  83ec14               sub esp, 0x14
// 00491e0b  53                   push ebx
// 00491e0c  56                   push esi
// 00491e0d  8bf1                 mov esi, ecx
// 00491e0f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00491e12  57                   push edi
// 00491e13  8965f0               mov dword ptr [ebp - 0x10], esp
// 00491e16  85c0                 test eax, eax
// 00491e18  7504                 jne 0x491e1e
// 00491e1a  33c9                 xor ecx, ecx
// 00491e1c  eb17                 jmp 0x491e35
// 00491e1e  8b5614               mov edx, dword ptr [esi + 0x14]
// 00491e21  2bd0                 sub edx, eax
// 00491e23  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00491e28  f7ea                 imul edx
// 00491e2a  d1fa                 sar edx, 1
// 00491e2c  8bc2                 mov eax, edx
// 00491e2e  c1e81f               shr eax, 0x1f
// 00491e31  03c2                 add eax, edx
// 00491e33  8bc8                 mov ecx, eax
// 00491e35  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00491e38  85ff                 test edi, edi
// 00491e3a  0f8449020000         je 0x492089
// 00491e40  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00491e43  8bd3                 mov edx, ebx
// 00491e45  2b560c               sub edx, dword ptr [esi + 0xc]
// 00491e48  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00491e4d  f7ea                 imul edx
// 00491e4f  d1fa                 sar edx, 1
// 00491e51  8bc2                 mov eax, edx
// 00491e53  c1e81f               shr eax, 0x1f
// 00491e56  03c2                 add eax, edx
// 00491e58  ba55555515           mov edx, 0x15555555
// 00491e5d  2bd0                 sub edx, eax
// 00491e5f  3bd7                 cmp edx, edi
// 00491e61  7305                 jae 0x491e68
// 00491e63  e8f802fbff           call 0x442160
// 00491e68  8d1438               lea edx, [eax + edi]
// 00491e6b  3bca                 cmp ecx, edx
// 00491e6d  0f8323010000         jae 0x491f96
// 00491e73  8bc1                 mov eax, ecx
// 00491e75  d1e8                 shr eax, 1
// 00491e77  bb55555515           mov ebx, 0x15555555
// 00491e7c  2bd8                 sub ebx, eax
// 00491e7e  3bd9                 cmp ebx, ecx
// 00491e80  730c                 jae 0x491e8e
// 00491e82  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00491e89  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00491e8c  eb05                 jmp 0x491e93
// 00491e8e  03c8                 add ecx, eax
// 00491e90  894dec               mov dword ptr [ebp - 0x14], ecx
// 00491e93  3bca                 cmp ecx, edx
// 00491e95  7305                 jae 0x491e9c
// 00491e97  8955ec               mov dword ptr [ebp - 0x14], edx
// 00491e9a  8bca                 mov ecx, edx
// 00491e9c  6a00                 push 0
// 00491e9e  51                   push ecx
// 00491e9f  e8ac1bfcff           call 0x453a50
// 00491ea4  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00491ea7  2b560c               sub edx, dword ptr [esi + 0xc]
// 00491eaa  8bc8                 mov ecx, eax
// 00491eac  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00491eb1  f7ea                 imul edx
// 00491eb3  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00491eb6  d1fa                 sar edx, 1
// 00491eb8  8bda                 mov ebx, edx
// 00491eba  83c408               add esp, 8
// 00491ebd  c1eb1f               shr ebx, 0x1f
// 00491ec0  03da                 add ebx, edx
// 00491ec2  50                   push eax
// 00491ec3  8d145b               lea edx, [ebx + ebx*2]
// 00491ec6  8d0491               lea eax, [ecx + edx*4]
// 00491ec9  57                   push edi
// 00491eca  894d10               mov dword ptr [ebp + 0x10], ecx
// 00491ecd  50                   push eax
// 00491ece  8bce                 mov ecx, esi
// 00491ed0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00491ed7  e8d4feffff           call 0x491db0
// 00491edc  8b460c               mov eax, dword ptr [esi + 0xc]
// 00491edf  c6451400             mov byte ptr [ebp + 0x14], 0
// 00491ee3  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00491ee6  52                   push edx
// 00491ee7  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00491eea  52                   push edx
// 00491eeb  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00491eee  8d4e08               lea ecx, [esi + 8]
// 00491ef1  51                   push ecx
// 00491ef2  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00491ef5  51                   push ecx
// 00491ef6  52                   push edx
// 00491ef7  50                   push eax
// 00491ef8  e893f51100           call 0x5b1490
// 00491efd  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00491f00  8b4610               mov eax, dword ptr [esi + 0x10]
// 00491f03  83c418               add esp, 0x18
// 00491f06  03df                 add ebx, edi
// 00491f08  8d0c5b               lea ecx, [ebx + ebx*2]
// 00491f0b  8d0c8a               lea ecx, [edx + ecx*4]
// 00491f0e  c6451400             mov byte ptr [ebp + 0x14], 0
// 00491f12  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00491f15  52                   push edx
// 00491f16  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00491f19  52                   push edx
// 00491f1a  8d5608               lea edx, [esi + 8]
// 00491f1d  52                   push edx
// 00491f1e  51                   push ecx
// 00491f1f  50                   push eax
// 00491f20  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00491f23  50                   push eax
// 00491f24  e867f51100           call 0x5b1490
// 00491f29  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00491f2c  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00491f2f  2bcb                 sub ecx, ebx
// 00491f31  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00491f36  f7e9                 imul ecx
// 00491f38  d1fa                 sar edx, 1
// 00491f3a  8bca                 mov ecx, edx
// 00491f3c  c1e91f               shr ecx, 0x1f
// 00491f3f  03ca                 add ecx, edx
// 00491f41  83c418               add esp, 0x18
// 00491f44  03f9                 add edi, ecx
// 00491f46  85db                 test ebx, ebx
// 00491f48  7409                 je 0x491f53
// 00491f4a  53                   push ebx
// 00491f4b  e80a193600           call 0x7f385a
// 00491f50  83c404               add esp, 4
// 00491f53  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00491f56  8d1440               lea edx, [eax + eax*2]
// 00491f59  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00491f5c  8d0c90               lea ecx, [eax + edx*4]
// 00491f5f  8d147f               lea edx, [edi + edi*2]
// 00491f62  894e14               mov dword ptr [esi + 0x14], ecx
// 00491f65  8d0c90               lea ecx, [eax + edx*4]
// 00491f68  894e10               mov dword ptr [esi + 0x10], ecx
// 00491f6b  89460c               mov dword ptr [esi + 0xc], eax
// 00491f6e  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00491f71  64890d00000000       mov dword ptr fs:[0], ecx
// 00491f78  5f                   pop edi
// 00491f79  5e                   pop esi
// 00491f7a  5b                   pop ebx
// 00491f7b  8be5                 mov esp, ebp
// 00491f7d  5d                   pop ebp
// 00491f7e  c21000               ret 0x10
// standard library vector<pod12> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
