// from server: 100% by auto
// roc 2009-12 005dd740  unit: RBX::ImmediateMeshGenAdapter  size: 409 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005dd740
//
// 005dd740  55                   push ebp
// 005dd741  8bec                 mov ebp, esp
// 005dd743  6aff                 push -1
// 005dd745  6840dd9300           push 0x93dd40
// 005dd74a  64a100000000         mov eax, dword ptr fs:[0]
// 005dd750  50                   push eax
// 005dd751  64892500000000       mov dword ptr fs:[0], esp
// 005dd758  83ec20               sub esp, 0x20
// 005dd75b  53                   push ebx
// 005dd75c  56                   push esi
// 005dd75d  8bf1                 mov esi, ecx
// 005dd75f  8b460c               mov eax, dword ptr [esi + 0xc]
// 005dd762  57                   push edi
// 005dd763  8965f0               mov dword ptr [ebp - 0x10], esp
// 005dd766  85c0                 test eax, eax
// 005dd768  7505                 jne 0x5dd76f
// 005dd76a  8945ec               mov dword ptr [ebp - 0x14], eax
// 005dd76d  eb19                 jmp 0x5dd788
// 005dd76f  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005dd772  2bc8                 sub ecx, eax
// 005dd774  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005dd779  f7e9                 imul ecx
// 005dd77b  c1fa02               sar edx, 2
// 005dd77e  8bc2                 mov eax, edx
// 005dd780  c1e81f               shr eax, 0x1f
// 005dd783  03c2                 add eax, edx
// 005dd785  8945ec               mov dword ptr [ebp - 0x14], eax
// 005dd788  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 005dd78b  85ff                 test edi, edi
// 005dd78d  0f8448020000         je 0x5dd9db
// 005dd793  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005dd796  8bcb                 mov ecx, ebx
// 005dd798  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 005dd79b  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005dd7a0  f7e9                 imul ecx
// 005dd7a2  c1fa02               sar edx, 2
// 005dd7a5  8bc2                 mov eax, edx
// 005dd7a7  c1e81f               shr eax, 0x1f
// 005dd7aa  03c2                 add eax, edx
// 005dd7ac  b9aaaaaa0a           mov ecx, 0xaaaaaaa
// 005dd7b1  2bc8                 sub ecx, eax
// 005dd7b3  3bcf                 cmp ecx, edi
// 005dd7b5  7305                 jae 0x5dd7bc
// 005dd7b7  e8a449e6ff           call 0x442160
// 005dd7bc  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 005dd7bf  03c7                 add eax, edi
// 005dd7c1  3bc8                 cmp ecx, eax
// 005dd7c3  0f8325010000         jae 0x5dd8ee
// 005dd7c9  8bd1                 mov edx, ecx
// 005dd7cb  d1ea                 shr edx, 1
// 005dd7cd  bbaaaaaa0a           mov ebx, 0xaaaaaaa
// 005dd7d2  2bda                 sub ebx, edx
// 005dd7d4  3bd9                 cmp ebx, ecx
// 005dd7d6  730c                 jae 0x5dd7e4
// 005dd7d8  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 005dd7df  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 005dd7e2  eb05                 jmp 0x5dd7e9
// 005dd7e4  03ca                 add ecx, edx
// 005dd7e6  894dec               mov dword ptr [ebp - 0x14], ecx
// 005dd7e9  3bc8                 cmp ecx, eax
// 005dd7eb  7305                 jae 0x5dd7f2
// 005dd7ed  8945ec               mov dword ptr [ebp - 0x14], eax
// 005dd7f0  8bc8                 mov ecx, eax
// 005dd7f2  6a00                 push 0
// 005dd7f4  51                   push ecx
// 005dd7f5  e886a61b00           call 0x797e80
// 005dd7fa  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005dd7fd  2b560c               sub edx, dword ptr [esi + 0xc]
// 005dd800  8bc8                 mov ecx, eax
// 005dd802  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005dd807  f7ea                 imul edx
// 005dd809  c1fa02               sar edx, 2
// 005dd80c  8bda                 mov ebx, edx
// 005dd80e  83c408               add esp, 8
// 005dd811  c1eb1f               shr ebx, 0x1f
// 005dd814  03da                 add ebx, edx
// 005dd816  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005dd819  52                   push edx
// 005dd81a  894d10               mov dword ptr [ebp + 0x10], ecx
// 005dd81d  8d045b               lea eax, [ebx + ebx*2]
// 005dd820  8d0cc1               lea ecx, [ecx + eax*8]
// 005dd823  57                   push edi
// 005dd824  51                   push ecx
// 005dd825  8bce                 mov ecx, esi
// 005dd827  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005dd82e  e83dfdffff           call 0x5dd570
// 005dd833  8b460c               mov eax, dword ptr [esi + 0xc]
// 005dd836  c6451400             mov byte ptr [ebp + 0x14], 0
// 005dd83a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005dd83d  52                   push edx
// 005dd83e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005dd841  52                   push edx
// 005dd842  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005dd845  8d4e08               lea ecx, [esi + 8]
// 005dd848  51                   push ecx
// 005dd849  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 005dd84c  51                   push ecx
// 005dd84d  52                   push edx
// 005dd84e  50                   push eax
// 005dd84f  e84cfcffff           call 0x5dd4a0
// 005dd854  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005dd857  8b4610               mov eax, dword ptr [esi + 0x10]
// 005dd85a  83c418               add esp, 0x18
// 005dd85d  03df                 add ebx, edi
// 005dd85f  8d0c5b               lea ecx, [ebx + ebx*2]
// 005dd862  8d0cca               lea ecx, [edx + ecx*8]
// 005dd865  c6451400             mov byte ptr [ebp + 0x14], 0
// 005dd869  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005dd86c  52                   push edx
// 005dd86d  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005dd870  52                   push edx
// 005dd871  8d5608               lea edx, [esi + 8]
// 005dd874  52                   push edx
// 005dd875  51                   push ecx
// 005dd876  50                   push eax
// 005dd877  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005dd87a  50                   push eax
// 005dd87b  e820fcffff           call 0x5dd4a0
// 005dd880  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005dd883  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005dd886  2bcb                 sub ecx, ebx
// 005dd888  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005dd88d  f7e9                 imul ecx
// 005dd88f  c1fa02               sar edx, 2
// 005dd892  8bca                 mov ecx, edx
// 005dd894  c1e91f               shr ecx, 0x1f
// 005dd897  03ca                 add ecx, edx
// 005dd899  83c418               add esp, 0x18
// 005dd89c  03f9                 add edi, ecx
// 005dd89e  85db                 test ebx, ebx
// 005dd8a0  7409                 je 0x5dd8ab
// 005dd8a2  53                   push ebx
// 005dd8a3  e8b25f2100           call 0x7f385a
// 005dd8a8  83c404               add esp, 4
// 005dd8ab  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005dd8ae  8d1440               lea edx, [eax + eax*2]
// 005dd8b1  8b4510               mov eax, dword ptr [ebp + 0x10]
// 005dd8b4  8d0cd0               lea ecx, [eax + edx*8]
// 005dd8b7  8d147f               lea edx, [edi + edi*2]
// 005dd8ba  894e14               mov dword ptr [esi + 0x14], ecx
// 005dd8bd  8d0cd0               lea ecx, [eax + edx*8]
// 005dd8c0  894e10               mov dword ptr [esi + 0x10], ecx
// 005dd8c3  89460c               mov dword ptr [esi + 0xc], eax
// 005dd8c6  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005dd8c9  64890d00000000       mov dword ptr fs:[0], ecx
// 005dd8d0  5f                   pop edi
// 005dd8d1  5e                   pop esi
// 005dd8d2  5b                   pop ebx
// 005dd8d3  8be5                 mov esp, ebp
// 005dd8d5  5d                   pop ebp
// 005dd8d6  c21000               ret 0x10
// library ogre-1.4.9/OgreSceneManager.cpp (function ?_Insert_n@?$vector@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@2@IABULightInfo@SceneManager@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
