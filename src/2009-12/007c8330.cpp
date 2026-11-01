// from server: 100% by auto
// roc 2009-12 007c8330  unit: RBX::ScoreHud  size: 458 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c8330
//
// 007c8330  55                   push ebp
// 007c8331  8bec                 mov ebp, esp
// 007c8333  6aff                 push -1
// 007c8335  68706a9500           push 0x956a70
// 007c833a  64a100000000         mov eax, dword ptr fs:[0]
// 007c8340  50                   push eax
// 007c8341  64892500000000       mov dword ptr fs:[0], esp
// 007c8348  83ec48               sub esp, 0x48
// 007c834b  53                   push ebx
// 007c834c  56                   push esi
// 007c834d  8bf1                 mov esi, ecx
// 007c834f  8b460c               mov eax, dword ptr [esi + 0xc]
// 007c8352  57                   push edi
// 007c8353  8965f0               mov dword ptr [ebp - 0x10], esp
// 007c8356  8975e0               mov dword ptr [ebp - 0x20], esi
// 007c8359  85c0                 test eax, eax
// 007c835b  7505                 jne 0x7c8362
// 007c835d  8945ec               mov dword ptr [ebp - 0x14], eax
// 007c8360  eb19                 jmp 0x7c837b
// 007c8362  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007c8365  2bc8                 sub ecx, eax
// 007c8367  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007c836c  f7e9                 imul ecx
// 007c836e  c1fa02               sar edx, 2
// 007c8371  8bc2                 mov eax, edx
// 007c8373  c1e81f               shr eax, 0x1f
// 007c8376  03c2                 add eax, edx
// 007c8378  8945ec               mov dword ptr [ebp - 0x14], eax
// 007c837b  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 007c837e  85ff                 test edi, edi
// 007c8380  0f84ef020000         je 0x7c8675
// 007c8386  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 007c8389  8bcb                 mov ecx, ebx
// 007c838b  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 007c838e  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007c8393  f7e9                 imul ecx
// 007c8395  c1fa02               sar edx, 2
// 007c8398  8bc2                 mov eax, edx
// 007c839a  c1e81f               shr eax, 0x1f
// 007c839d  03c2                 add eax, edx
// 007c839f  b9aaaaaa0a           mov ecx, 0xaaaaaaa
// 007c83a4  2bc8                 sub ecx, eax
// 007c83a6  3bcf                 cmp ecx, edi
// 007c83a8  7305                 jae 0x7c83af
// 007c83aa  e8b19dc7ff           call 0x442160
// 007c83af  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 007c83b2  03c7                 add eax, edi
// 007c83b4  3bc8                 cmp ecx, eax
// 007c83b6  0f838e010000         jae 0x7c854a
// 007c83bc  8bd1                 mov edx, ecx
// 007c83be  d1ea                 shr edx, 1
// 007c83c0  bbaaaaaa0a           mov ebx, 0xaaaaaaa
// 007c83c5  2bda                 sub ebx, edx
// 007c83c7  3bd9                 cmp ebx, ecx
// 007c83c9  730c                 jae 0x7c83d7
// 007c83cb  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 007c83d2  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 007c83d5  eb05                 jmp 0x7c83dc
// 007c83d7  03ca                 add ecx, edx
// 007c83d9  894dec               mov dword ptr [ebp - 0x14], ecx
// 007c83dc  3bc8                 cmp ecx, eax
// 007c83de  7305                 jae 0x7c83e5
// 007c83e0  8945ec               mov dword ptr [ebp - 0x14], eax
// 007c83e3  8bc8                 mov ecx, eax
// 007c83e5  6a00                 push 0
// 007c83e7  51                   push ecx
// 007c83e8  e893fafcff           call 0x797e80
// 007c83ed  8b550c               mov edx, dword ptr [ebp + 0xc]
// 007c83f0  2b560c               sub edx, dword ptr [esi + 0xc]
// 007c83f3  8bc8                 mov ecx, eax
// 007c83f5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007c83fa  f7ea                 imul edx
// 007c83fc  c1fa02               sar edx, 2
// 007c83ff  8bda                 mov ebx, edx
// 007c8401  33c0                 xor eax, eax
// 007c8403  83c408               add esp, 8
// 007c8406  c1eb1f               shr ebx, 0x1f
// 007c8409  03da                 add ebx, edx
// 007c840b  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007c840e  8945e4               mov dword ptr [ebp - 0x1c], eax
// 007c8411  8945fc               mov dword ptr [ebp - 4], eax
// 007c8414  52                   push edx
// 007c8415  894de8               mov dword ptr [ebp - 0x18], ecx
// 007c8418  8d045b               lea eax, [ebx + ebx*2]
// 007c841b  8d0cc1               lea ecx, [ecx + eax*8]
// 007c841e  57                   push edi
// 007c841f  51                   push ecx
// 007c8420  8bce                 mov ecx, esi
// 007c8422  895ddc               mov dword ptr [ebp - 0x24], ebx
// 007c8425  e836fbffff           call 0x7c7f60
// 007c842a  8b460c               mov eax, dword ptr [esi + 0xc]
// 007c842d  c6451400             mov byte ptr [ebp + 0x14], 0
// 007c8431  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007c8434  52                   push edx
// 007c8435  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007c8438  52                   push edx
// 007c8439  8b550c               mov edx, dword ptr [ebp + 0xc]
// 007c843c  8d4e08               lea ecx, [esi + 8]
// 007c843f  51                   push ecx
// 007c8440  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 007c8443  51                   push ecx
// 007c8444  52                   push edx
// 007c8445  50                   push eax
// 007c8446  c745e401000000       mov dword ptr [ebp - 0x1c], 1
// 007c844d  e8beecffff           call 0x7c7110
// 007c8452  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 007c8455  8b4610               mov eax, dword ptr [esi + 0x10]
// 007c8458  83c418               add esp, 0x18
// 007c845b  03df                 add ebx, edi
// 007c845d  8d0c5b               lea ecx, [ebx + ebx*2]
// 007c8460  8d0cca               lea ecx, [edx + ecx*8]
// 007c8463  c6451400             mov byte ptr [ebp + 0x14], 0
// 007c8467  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007c846a  52                   push edx
// 007c846b  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007c846e  52                   push edx
// 007c846f  8d5608               lea edx, [esi + 8]
// 007c8472  52                   push edx
// 007c8473  51                   push ecx
// 007c8474  50                   push eax
// 007c8475  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007c8478  50                   push eax
// 007c8479  c745e402000000       mov dword ptr [ebp - 0x1c], 2
// 007c8480  e88becffff           call 0x7c7110
// 007c8485  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 007c8488  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007c848b  2bcb                 sub ecx, ebx
// 007c848d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007c8492  f7e9                 imul ecx
// 007c8494  c1fa02               sar edx, 2
// 007c8497  8bca                 mov ecx, edx
// 007c8499  c1e91f               shr ecx, 0x1f
// 007c849c  03ca                 add ecx, edx
// 007c849e  83c418               add esp, 0x18
// 007c84a1  03f9                 add edi, ecx
// 007c84a3  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 007c84aa  85db                 test ebx, ebx
// 007c84ac  741e                 je 0x7c84cc
// 007c84ae  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007c84b1  52                   push edx
// 007c84b2  8d4608               lea eax, [esi + 8]
// 007c84b5  50                   push eax
// 007c84b6  8b4610               mov eax, dword ptr [esi + 0x10]
// 007c84b9  50                   push eax
// 007c84ba  53                   push ebx
// 007c84bb  e830ebffff           call 0x7c6ff0
// 007c84c0  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007c84c3  51                   push ecx
// 007c84c4  e891b30200           call 0x7f385a
// 007c84c9  83c414               add esp, 0x14
// 007c84cc  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 007c84cf  8d1440               lea edx, [eax + eax*2]
// 007c84d2  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 007c84d5  8d0cd0               lea ecx, [eax + edx*8]
// 007c84d8  8d147f               lea edx, [edi + edi*2]
// 007c84db  894e14               mov dword ptr [esi + 0x14], ecx
// 007c84de  8d0cd0               lea ecx, [eax + edx*8]
// 007c84e1  894e10               mov dword ptr [esi + 0x10], ecx
// 007c84e4  89460c               mov dword ptr [esi + 0xc], eax
// 007c84e7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 007c84ea  64890d00000000       mov dword ptr fs:[0], ecx
// 007c84f1  5f                   pop edi
// 007c84f2  5e                   pop esi
// 007c84f3  5b                   pop ebx
// 007c84f4  8be5                 mov esp, ebp
// 007c84f6  5d                   pop ebp
// 007c84f7  c21000               ret 0x10
// library ogre-1.6.4/OgreScriptCompiler.cpp (function ?_Insert_n@?$vector@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@V?$allocator@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@@2@@std@@IAEXV?$_Vector_const_iterator@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@V?$allocator@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@@2@@2@IABU?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreScriptCompiler.cpp
