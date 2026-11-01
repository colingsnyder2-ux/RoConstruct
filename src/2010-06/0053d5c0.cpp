// from server: 100% by auto
// roc 2010-06 0053d5c0  unit: RBX::ImmediateMeshGenAdapter  size: 409 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053d5c0
//
// 0053d5c0  55                   push ebp
// 0053d5c1  8bec                 mov ebp, esp
// 0053d5c3  6aff                 push -1
// 0053d5c5  6800f89800           push 0x98f800
// 0053d5ca  64a100000000         mov eax, dword ptr fs:[0]
// 0053d5d0  50                   push eax
// 0053d5d1  64892500000000       mov dword ptr fs:[0], esp
// 0053d5d8  83ec20               sub esp, 0x20
// 0053d5db  53                   push ebx
// 0053d5dc  56                   push esi
// 0053d5dd  8bf1                 mov esi, ecx
// 0053d5df  8b460c               mov eax, dword ptr [esi + 0xc]
// 0053d5e2  57                   push edi
// 0053d5e3  8965f0               mov dword ptr [ebp - 0x10], esp
// 0053d5e6  85c0                 test eax, eax
// 0053d5e8  7505                 jne 0x53d5ef
// 0053d5ea  8945ec               mov dword ptr [ebp - 0x14], eax
// 0053d5ed  eb19                 jmp 0x53d608
// 0053d5ef  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0053d5f2  2bc8                 sub ecx, eax
// 0053d5f4  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053d5f9  f7e9                 imul ecx
// 0053d5fb  c1fa02               sar edx, 2
// 0053d5fe  8bc2                 mov eax, edx
// 0053d600  c1e81f               shr eax, 0x1f
// 0053d603  03c2                 add eax, edx
// 0053d605  8945ec               mov dword ptr [ebp - 0x14], eax
// 0053d608  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 0053d60b  85ff                 test edi, edi
// 0053d60d  0f8448020000         je 0x53d85b
// 0053d613  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0053d616  8bcb                 mov ecx, ebx
// 0053d618  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 0053d61b  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053d620  f7e9                 imul ecx
// 0053d622  c1fa02               sar edx, 2
// 0053d625  8bc2                 mov eax, edx
// 0053d627  c1e81f               shr eax, 0x1f
// 0053d62a  03c2                 add eax, edx
// 0053d62c  b9aaaaaa0a           mov ecx, 0xaaaaaaa
// 0053d631  2bc8                 sub ecx, eax
// 0053d633  3bcf                 cmp ecx, edi
// 0053d635  7305                 jae 0x53d63c
// 0053d637  e8b467eeff           call 0x423df0
// 0053d63c  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0053d63f  03c7                 add eax, edi
// 0053d641  3bc8                 cmp ecx, eax
// 0053d643  0f8325010000         jae 0x53d76e
// 0053d649  8bd1                 mov edx, ecx
// 0053d64b  d1ea                 shr edx, 1
// 0053d64d  bbaaaaaa0a           mov ebx, 0xaaaaaaa
// 0053d652  2bda                 sub ebx, edx
// 0053d654  3bd9                 cmp ebx, ecx
// 0053d656  730c                 jae 0x53d664
// 0053d658  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 0053d65f  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0053d662  eb05                 jmp 0x53d669
// 0053d664  03ca                 add ecx, edx
// 0053d666  894dec               mov dword ptr [ebp - 0x14], ecx
// 0053d669  3bc8                 cmp ecx, eax
// 0053d66b  7305                 jae 0x53d672
// 0053d66d  8945ec               mov dword ptr [ebp - 0x14], eax
// 0053d670  8bc8                 mov ecx, eax
// 0053d672  6a00                 push 0
// 0053d674  51                   push ecx
// 0053d675  e866301f00           call 0x7306e0
// 0053d67a  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0053d67d  2b560c               sub edx, dword ptr [esi + 0xc]
// 0053d680  8bc8                 mov ecx, eax
// 0053d682  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053d687  f7ea                 imul edx
// 0053d689  c1fa02               sar edx, 2
// 0053d68c  8bda                 mov ebx, edx
// 0053d68e  83c408               add esp, 8
// 0053d691  c1eb1f               shr ebx, 0x1f
// 0053d694  03da                 add ebx, edx
// 0053d696  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0053d699  52                   push edx
// 0053d69a  894d10               mov dword ptr [ebp + 0x10], ecx
// 0053d69d  8d045b               lea eax, [ebx + ebx*2]
// 0053d6a0  8d0cc1               lea ecx, [ecx + eax*8]
// 0053d6a3  57                   push edi
// 0053d6a4  51                   push ecx
// 0053d6a5  8bce                 mov ecx, esi
// 0053d6a7  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0053d6ae  e87dfdffff           call 0x53d430
// 0053d6b3  8b460c               mov eax, dword ptr [esi + 0xc]
// 0053d6b6  c6451400             mov byte ptr [ebp + 0x14], 0
// 0053d6ba  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0053d6bd  52                   push edx
// 0053d6be  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0053d6c1  52                   push edx
// 0053d6c2  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0053d6c5  8d4e08               lea ecx, [esi + 8]
// 0053d6c8  51                   push ecx
// 0053d6c9  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0053d6cc  51                   push ecx
// 0053d6cd  52                   push edx
// 0053d6ce  50                   push eax
// 0053d6cf  e88cfcffff           call 0x53d360
// 0053d6d4  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0053d6d7  8b4610               mov eax, dword ptr [esi + 0x10]
// 0053d6da  83c418               add esp, 0x18
// 0053d6dd  03df                 add ebx, edi
// 0053d6df  8d0c5b               lea ecx, [ebx + ebx*2]
// 0053d6e2  8d0cca               lea ecx, [edx + ecx*8]
// 0053d6e5  c6451400             mov byte ptr [ebp + 0x14], 0
// 0053d6e9  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0053d6ec  52                   push edx
// 0053d6ed  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0053d6f0  52                   push edx
// 0053d6f1  8d5608               lea edx, [esi + 8]
// 0053d6f4  52                   push edx
// 0053d6f5  51                   push ecx
// 0053d6f6  50                   push eax
// 0053d6f7  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0053d6fa  50                   push eax
// 0053d6fb  e860fcffff           call 0x53d360
// 0053d700  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0053d703  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0053d706  2bcb                 sub ecx, ebx
// 0053d708  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053d70d  f7e9                 imul ecx
// 0053d70f  c1fa02               sar edx, 2
// 0053d712  8bca                 mov ecx, edx
// 0053d714  c1e91f               shr ecx, 0x1f
// 0053d717  03ca                 add ecx, edx
// 0053d719  83c418               add esp, 0x18
// 0053d71c  03f9                 add edi, ecx
// 0053d71e  85db                 test ebx, ebx
// 0053d720  7409                 je 0x53d72b
// 0053d722  53                   push ebx
// 0053d723  e872a22600           call 0x7a799a
// 0053d728  83c404               add esp, 4
// 0053d72b  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0053d72e  8d1440               lea edx, [eax + eax*2]
// 0053d731  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0053d734  8d0cd0               lea ecx, [eax + edx*8]
// 0053d737  8d147f               lea edx, [edi + edi*2]
// 0053d73a  894e14               mov dword ptr [esi + 0x14], ecx
// 0053d73d  8d0cd0               lea ecx, [eax + edx*8]
// 0053d740  894e10               mov dword ptr [esi + 0x10], ecx
// 0053d743  89460c               mov dword ptr [esi + 0xc], eax
// 0053d746  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0053d749  64890d00000000       mov dword ptr fs:[0], ecx
// 0053d750  5f                   pop edi
// 0053d751  5e                   pop esi
// 0053d752  5b                   pop ebx
// 0053d753  8be5                 mov esp, ebp
// 0053d755  5d                   pop ebp
// 0053d756  c21000               ret 0x10
// library ogre-1.4.9/OgreSceneManager.cpp (function ?_Insert_n@?$vector@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@2@IABULightInfo@SceneManager@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
