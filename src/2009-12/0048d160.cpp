// from server: 100% by auto
// roc 2009-12 0048d160  unit: G3D::Shader  size: 409 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048d160
//
// 0048d160  55                   push ebp
// 0048d161  8bec                 mov ebp, esp
// 0048d163  6aff                 push -1
// 0048d165  68d0fc9200           push 0x92fcd0
// 0048d16a  64a100000000         mov eax, dword ptr fs:[0]
// 0048d170  50                   push eax
// 0048d171  64892500000000       mov dword ptr fs:[0], esp
// 0048d178  83ec20               sub esp, 0x20
// 0048d17b  53                   push ebx
// 0048d17c  56                   push esi
// 0048d17d  8bf1                 mov esi, ecx
// 0048d17f  8b460c               mov eax, dword ptr [esi + 0xc]
// 0048d182  57                   push edi
// 0048d183  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048d186  85c0                 test eax, eax
// 0048d188  7505                 jne 0x48d18f
// 0048d18a  8945ec               mov dword ptr [ebp - 0x14], eax
// 0048d18d  eb19                 jmp 0x48d1a8
// 0048d18f  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0048d192  2bc8                 sub ecx, eax
// 0048d194  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048d199  f7e9                 imul ecx
// 0048d19b  c1fa02               sar edx, 2
// 0048d19e  8bc2                 mov eax, edx
// 0048d1a0  c1e81f               shr eax, 0x1f
// 0048d1a3  03c2                 add eax, edx
// 0048d1a5  8945ec               mov dword ptr [ebp - 0x14], eax
// 0048d1a8  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 0048d1ab  85ff                 test edi, edi
// 0048d1ad  0f8448020000         je 0x48d3fb
// 0048d1b3  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0048d1b6  8bcb                 mov ecx, ebx
// 0048d1b8  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 0048d1bb  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048d1c0  f7e9                 imul ecx
// 0048d1c2  c1fa02               sar edx, 2
// 0048d1c5  8bc2                 mov eax, edx
// 0048d1c7  c1e81f               shr eax, 0x1f
// 0048d1ca  03c2                 add eax, edx
// 0048d1cc  b9aaaaaa0a           mov ecx, 0xaaaaaaa
// 0048d1d1  2bc8                 sub ecx, eax
// 0048d1d3  3bcf                 cmp ecx, edi
// 0048d1d5  7305                 jae 0x48d1dc
// 0048d1d7  e8844ffbff           call 0x442160
// 0048d1dc  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0048d1df  03c7                 add eax, edi
// 0048d1e1  3bc8                 cmp ecx, eax
// 0048d1e3  0f8325010000         jae 0x48d30e
// 0048d1e9  8bd1                 mov edx, ecx
// 0048d1eb  d1ea                 shr edx, 1
// 0048d1ed  bbaaaaaa0a           mov ebx, 0xaaaaaaa
// 0048d1f2  2bda                 sub ebx, edx
// 0048d1f4  3bd9                 cmp ebx, ecx
// 0048d1f6  730c                 jae 0x48d204
// 0048d1f8  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 0048d1ff  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0048d202  eb05                 jmp 0x48d209
// 0048d204  03ca                 add ecx, edx
// 0048d206  894dec               mov dword ptr [ebp - 0x14], ecx
// 0048d209  3bc8                 cmp ecx, eax
// 0048d20b  7305                 jae 0x48d212
// 0048d20d  8945ec               mov dword ptr [ebp - 0x14], eax
// 0048d210  8bc8                 mov ecx, eax
// 0048d212  6a00                 push 0
// 0048d214  51                   push ecx
// 0048d215  e866ac3000           call 0x797e80
// 0048d21a  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0048d21d  2b560c               sub edx, dword ptr [esi + 0xc]
// 0048d220  8bc8                 mov ecx, eax
// 0048d222  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048d227  f7ea                 imul edx
// 0048d229  c1fa02               sar edx, 2
// 0048d22c  8bda                 mov ebx, edx
// 0048d22e  83c408               add esp, 8
// 0048d231  c1eb1f               shr ebx, 0x1f
// 0048d234  03da                 add ebx, edx
// 0048d236  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0048d239  52                   push edx
// 0048d23a  894d10               mov dword ptr [ebp + 0x10], ecx
// 0048d23d  8d045b               lea eax, [ebx + ebx*2]
// 0048d240  8d0cc1               lea ecx, [ecx + eax*8]
// 0048d243  57                   push edi
// 0048d244  51                   push ecx
// 0048d245  8bce                 mov ecx, esi
// 0048d247  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048d24e  e8ddf8ffff           call 0x48cb30
// 0048d253  8b460c               mov eax, dword ptr [esi + 0xc]
// 0048d256  c6451400             mov byte ptr [ebp + 0x14], 0
// 0048d25a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0048d25d  52                   push edx
// 0048d25e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0048d261  52                   push edx
// 0048d262  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0048d265  8d4e08               lea ecx, [esi + 8]
// 0048d268  51                   push ecx
// 0048d269  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0048d26c  51                   push ecx
// 0048d26d  52                   push edx
// 0048d26e  50                   push eax
// 0048d26f  e80cf3ffff           call 0x48c580
// 0048d274  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0048d277  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048d27a  83c418               add esp, 0x18
// 0048d27d  03df                 add ebx, edi
// 0048d27f  8d0c5b               lea ecx, [ebx + ebx*2]
// 0048d282  8d0cca               lea ecx, [edx + ecx*8]
// 0048d285  c6451400             mov byte ptr [ebp + 0x14], 0
// 0048d289  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0048d28c  52                   push edx
// 0048d28d  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0048d290  52                   push edx
// 0048d291  8d5608               lea edx, [esi + 8]
// 0048d294  52                   push edx
// 0048d295  51                   push ecx
// 0048d296  50                   push eax
// 0048d297  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0048d29a  50                   push eax
// 0048d29b  e8e0f2ffff           call 0x48c580
// 0048d2a0  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048d2a3  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0048d2a6  2bcb                 sub ecx, ebx
// 0048d2a8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048d2ad  f7e9                 imul ecx
// 0048d2af  c1fa02               sar edx, 2
// 0048d2b2  8bca                 mov ecx, edx
// 0048d2b4  c1e91f               shr ecx, 0x1f
// 0048d2b7  03ca                 add ecx, edx
// 0048d2b9  83c418               add esp, 0x18
// 0048d2bc  03f9                 add edi, ecx
// 0048d2be  85db                 test ebx, ebx
// 0048d2c0  7409                 je 0x48d2cb
// 0048d2c2  53                   push ebx
// 0048d2c3  e892653600           call 0x7f385a
// 0048d2c8  83c404               add esp, 4
// 0048d2cb  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0048d2ce  8d1440               lea edx, [eax + eax*2]
// 0048d2d1  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0048d2d4  8d0cd0               lea ecx, [eax + edx*8]
// 0048d2d7  8d147f               lea edx, [edi + edi*2]
// 0048d2da  894e14               mov dword ptr [esi + 0x14], ecx
// 0048d2dd  8d0cd0               lea ecx, [eax + edx*8]
// 0048d2e0  894e10               mov dword ptr [esi + 0x10], ecx
// 0048d2e3  89460c               mov dword ptr [esi + 0xc], eax
// 0048d2e6  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048d2e9  64890d00000000       mov dword ptr fs:[0], ecx
// 0048d2f0  5f                   pop edi
// 0048d2f1  5e                   pop esi
// 0048d2f2  5b                   pop ebx
// 0048d2f3  8be5                 mov esp, ebp
// 0048d2f5  5d                   pop ebp
// 0048d2f6  c21000               ret 0x10
// library ogre-1.4.9/OgreSceneManager.cpp (function ?_Insert_n@?$vector@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@2@IABULightInfo@SceneManager@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
