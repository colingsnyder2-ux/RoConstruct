// from server: 100% by auto
// roc 2010-06 0096a640  unit: Ogre::RbxSceneUpdater  size: 405 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096a640
//
// 0096a640  55                   push ebp
// 0096a641  8bec                 mov ebp, esp
// 0096a643  6aff                 push -1
// 0096a645  6870279c00           push 0x9c2770
// 0096a64a  64a100000000         mov eax, dword ptr fs:[0]
// 0096a650  50                   push eax
// 0096a651  64892500000000       mov dword ptr fs:[0], esp
// 0096a658  83ec20               sub esp, 0x20
// 0096a65b  53                   push ebx
// 0096a65c  56                   push esi
// 0096a65d  8bf1                 mov esi, ecx
// 0096a65f  8b460c               mov eax, dword ptr [esi + 0xc]
// 0096a662  57                   push edi
// 0096a663  8965f0               mov dword ptr [ebp - 0x10], esp
// 0096a666  85c0                 test eax, eax
// 0096a668  7504                 jne 0x96a66e
// 0096a66a  33c9                 xor ecx, ecx
// 0096a66c  eb18                 jmp 0x96a686
// 0096a66e  8b5614               mov edx, dword ptr [esi + 0x14]
// 0096a671  2bd0                 sub edx, eax
// 0096a673  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096a678  f7ea                 imul edx
// 0096a67a  c1fa02               sar edx, 2
// 0096a67d  8bc2                 mov eax, edx
// 0096a67f  c1e81f               shr eax, 0x1f
// 0096a682  03c2                 add eax, edx
// 0096a684  8bc8                 mov ecx, eax
// 0096a686  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 0096a689  85ff                 test edi, edi
// 0096a68b  0f8476020000         je 0x96a907
// 0096a691  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0096a694  8bd3                 mov edx, ebx
// 0096a696  2b560c               sub edx, dword ptr [esi + 0xc]
// 0096a699  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096a69e  f7ea                 imul edx
// 0096a6a0  c1fa02               sar edx, 2
// 0096a6a3  8bc2                 mov eax, edx
// 0096a6a5  c1e81f               shr eax, 0x1f
// 0096a6a8  03c2                 add eax, edx
// 0096a6aa  baaaaaaa0a           mov edx, 0xaaaaaaa
// 0096a6af  2bd0                 sub edx, eax
// 0096a6b1  3bd7                 cmp edx, edi
// 0096a6b3  7305                 jae 0x96a6ba
// 0096a6b5  e83697abff           call 0x423df0
// 0096a6ba  8d1438               lea edx, [eax + edi]
// 0096a6bd  3bca                 cmp ecx, edx
// 0096a6bf  0f8325010000         jae 0x96a7ea
// 0096a6c5  8bc1                 mov eax, ecx
// 0096a6c7  d1e8                 shr eax, 1
// 0096a6c9  bbaaaaaa0a           mov ebx, 0xaaaaaaa
// 0096a6ce  2bd8                 sub ebx, eax
// 0096a6d0  3bd9                 cmp ebx, ecx
// 0096a6d2  730c                 jae 0x96a6e0
// 0096a6d4  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 0096a6db  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0096a6de  eb05                 jmp 0x96a6e5
// 0096a6e0  03c8                 add ecx, eax
// 0096a6e2  894dec               mov dword ptr [ebp - 0x14], ecx
// 0096a6e5  3bca                 cmp ecx, edx
// 0096a6e7  7305                 jae 0x96a6ee
// 0096a6e9  8955ec               mov dword ptr [ebp - 0x14], edx
// 0096a6ec  8bca                 mov ecx, edx
// 0096a6ee  6a00                 push 0
// 0096a6f0  51                   push ecx
// 0096a6f1  e8ea5fdcff           call 0x7306e0
// 0096a6f6  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0096a6f9  2b560c               sub edx, dword ptr [esi + 0xc]
// 0096a6fc  8bc8                 mov ecx, eax
// 0096a6fe  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096a703  f7ea                 imul edx
// 0096a705  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0096a708  c1fa02               sar edx, 2
// 0096a70b  8bda                 mov ebx, edx
// 0096a70d  83c408               add esp, 8
// 0096a710  c1eb1f               shr ebx, 0x1f
// 0096a713  03da                 add ebx, edx
// 0096a715  50                   push eax
// 0096a716  8d145b               lea edx, [ebx + ebx*2]
// 0096a719  8d04d1               lea eax, [ecx + edx*8]
// 0096a71c  57                   push edi
// 0096a71d  894d10               mov dword ptr [ebp + 0x10], ecx
// 0096a720  50                   push eax
// 0096a721  8bce                 mov ecx, esi
// 0096a723  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0096a72a  e8a1feffff           call 0x96a5d0
// 0096a72f  8b460c               mov eax, dword ptr [esi + 0xc]
// 0096a732  c6451400             mov byte ptr [ebp + 0x14], 0
// 0096a736  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0096a739  52                   push edx
// 0096a73a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0096a73d  52                   push edx
// 0096a73e  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0096a741  8d4e08               lea ecx, [esi + 8]
// 0096a744  51                   push ecx
// 0096a745  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0096a748  51                   push ecx
// 0096a749  52                   push edx
// 0096a74a  50                   push eax
// 0096a74b  e850fdffff           call 0x96a4a0
// 0096a750  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0096a753  8b4610               mov eax, dword ptr [esi + 0x10]
// 0096a756  83c418               add esp, 0x18
// 0096a759  03df                 add ebx, edi
// 0096a75b  8d0c5b               lea ecx, [ebx + ebx*2]
// 0096a75e  8d0cca               lea ecx, [edx + ecx*8]
// 0096a761  c6451400             mov byte ptr [ebp + 0x14], 0
// 0096a765  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0096a768  52                   push edx
// 0096a769  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0096a76c  52                   push edx
// 0096a76d  8d5608               lea edx, [esi + 8]
// 0096a770  52                   push edx
// 0096a771  51                   push ecx
// 0096a772  50                   push eax
// 0096a773  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0096a776  50                   push eax
// 0096a777  e824fdffff           call 0x96a4a0
// 0096a77c  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0096a77f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0096a782  2bcb                 sub ecx, ebx
// 0096a784  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096a789  f7e9                 imul ecx
// 0096a78b  c1fa02               sar edx, 2
// 0096a78e  8bca                 mov ecx, edx
// 0096a790  c1e91f               shr ecx, 0x1f
// 0096a793  03ca                 add ecx, edx
// 0096a795  83c418               add esp, 0x18
// 0096a798  03f9                 add edi, ecx
// 0096a79a  85db                 test ebx, ebx
// 0096a79c  7409                 je 0x96a7a7
// 0096a79e  53                   push ebx
// 0096a79f  e8f6d1e3ff           call 0x7a799a
// 0096a7a4  83c404               add esp, 4
// 0096a7a7  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0096a7aa  8d1440               lea edx, [eax + eax*2]
// 0096a7ad  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0096a7b0  8d0cd0               lea ecx, [eax + edx*8]
// 0096a7b3  8d147f               lea edx, [edi + edi*2]
// 0096a7b6  894e14               mov dword ptr [esi + 0x14], ecx
// 0096a7b9  8d0cd0               lea ecx, [eax + edx*8]
// 0096a7bc  894e10               mov dword ptr [esi + 0x10], ecx
// 0096a7bf  89460c               mov dword ptr [esi + 0xc], eax
// 0096a7c2  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0096a7c5  64890d00000000       mov dword ptr fs:[0], ecx
// 0096a7cc  5f                   pop edi
// 0096a7cd  5e                   pop esi
// 0096a7ce  5b                   pop ebx
// 0096a7cf  8be5                 mov esp, ebp
// 0096a7d1  5d                   pop ebp
// 0096a7d2  c21000               ret 0x10
// standard library vector<pod24> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
