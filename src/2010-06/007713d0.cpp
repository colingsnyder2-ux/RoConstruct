// from server: 100% by auto
// roc 2010-06 007713d0  unit: RBX::ScoreHud  size: 458 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007713d0
//
// 007713d0  55                   push ebp
// 007713d1  8bec                 mov ebp, esp
// 007713d3  6aff                 push -1
// 007713d5  6880c49a00           push 0x9ac480
// 007713da  64a100000000         mov eax, dword ptr fs:[0]
// 007713e0  50                   push eax
// 007713e1  64892500000000       mov dword ptr fs:[0], esp
// 007713e8  83ec48               sub esp, 0x48
// 007713eb  53                   push ebx
// 007713ec  56                   push esi
// 007713ed  8bf1                 mov esi, ecx
// 007713ef  8b460c               mov eax, dword ptr [esi + 0xc]
// 007713f2  57                   push edi
// 007713f3  8965f0               mov dword ptr [ebp - 0x10], esp
// 007713f6  8975e0               mov dword ptr [ebp - 0x20], esi
// 007713f9  85c0                 test eax, eax
// 007713fb  7505                 jne 0x771402
// 007713fd  8945ec               mov dword ptr [ebp - 0x14], eax
// 00771400  eb19                 jmp 0x77141b
// 00771402  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00771405  2bc8                 sub ecx, eax
// 00771407  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0077140c  f7e9                 imul ecx
// 0077140e  c1fa02               sar edx, 2
// 00771411  8bc2                 mov eax, edx
// 00771413  c1e81f               shr eax, 0x1f
// 00771416  03c2                 add eax, edx
// 00771418  8945ec               mov dword ptr [ebp - 0x14], eax
// 0077141b  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 0077141e  85ff                 test edi, edi
// 00771420  0f84ef020000         je 0x771715
// 00771426  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00771429  8bcb                 mov ecx, ebx
// 0077142b  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 0077142e  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00771433  f7e9                 imul ecx
// 00771435  c1fa02               sar edx, 2
// 00771438  8bc2                 mov eax, edx
// 0077143a  c1e81f               shr eax, 0x1f
// 0077143d  03c2                 add eax, edx
// 0077143f  b9aaaaaa0a           mov ecx, 0xaaaaaaa
// 00771444  2bc8                 sub ecx, eax
// 00771446  3bcf                 cmp ecx, edi
// 00771448  7305                 jae 0x77144f
// 0077144a  e8a129cbff           call 0x423df0
// 0077144f  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00771452  03c7                 add eax, edi
// 00771454  3bc8                 cmp ecx, eax
// 00771456  0f838e010000         jae 0x7715ea
// 0077145c  8bd1                 mov edx, ecx
// 0077145e  d1ea                 shr edx, 1
// 00771460  bbaaaaaa0a           mov ebx, 0xaaaaaaa
// 00771465  2bda                 sub ebx, edx
// 00771467  3bd9                 cmp ebx, ecx
// 00771469  730c                 jae 0x771477
// 0077146b  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00771472  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00771475  eb05                 jmp 0x77147c
// 00771477  03ca                 add ecx, edx
// 00771479  894dec               mov dword ptr [ebp - 0x14], ecx
// 0077147c  3bc8                 cmp ecx, eax
// 0077147e  7305                 jae 0x771485
// 00771480  8945ec               mov dword ptr [ebp - 0x14], eax
// 00771483  8bc8                 mov ecx, eax
// 00771485  6a00                 push 0
// 00771487  51                   push ecx
// 00771488  e853f2fbff           call 0x7306e0
// 0077148d  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00771490  2b560c               sub edx, dword ptr [esi + 0xc]
// 00771493  8bc8                 mov ecx, eax
// 00771495  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0077149a  f7ea                 imul edx
// 0077149c  c1fa02               sar edx, 2
// 0077149f  8bda                 mov ebx, edx
// 007714a1  33c0                 xor eax, eax
// 007714a3  83c408               add esp, 8
// 007714a6  c1eb1f               shr ebx, 0x1f
// 007714a9  03da                 add ebx, edx
// 007714ab  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007714ae  8945e4               mov dword ptr [ebp - 0x1c], eax
// 007714b1  8945fc               mov dword ptr [ebp - 4], eax
// 007714b4  52                   push edx
// 007714b5  894de8               mov dword ptr [ebp - 0x18], ecx
// 007714b8  8d045b               lea eax, [ebx + ebx*2]
// 007714bb  8d0cc1               lea ecx, [ecx + eax*8]
// 007714be  57                   push edi
// 007714bf  51                   push ecx
// 007714c0  8bce                 mov ecx, esi
// 007714c2  895ddc               mov dword ptr [ebp - 0x24], ebx
// 007714c5  e836fbffff           call 0x771000
// 007714ca  8b460c               mov eax, dword ptr [esi + 0xc]
// 007714cd  c6451400             mov byte ptr [ebp + 0x14], 0
// 007714d1  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007714d4  52                   push edx
// 007714d5  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007714d8  52                   push edx
// 007714d9  8b550c               mov edx, dword ptr [ebp + 0xc]
// 007714dc  8d4e08               lea ecx, [esi + 8]
// 007714df  51                   push ecx
// 007714e0  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 007714e3  51                   push ecx
// 007714e4  52                   push edx
// 007714e5  50                   push eax
// 007714e6  c745e401000000       mov dword ptr [ebp - 0x1c], 1
// 007714ed  e8beecffff           call 0x7701b0
// 007714f2  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 007714f5  8b4610               mov eax, dword ptr [esi + 0x10]
// 007714f8  83c418               add esp, 0x18
// 007714fb  03df                 add ebx, edi
// 007714fd  8d0c5b               lea ecx, [ebx + ebx*2]
// 00771500  8d0cca               lea ecx, [edx + ecx*8]
// 00771503  c6451400             mov byte ptr [ebp + 0x14], 0
// 00771507  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0077150a  52                   push edx
// 0077150b  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0077150e  52                   push edx
// 0077150f  8d5608               lea edx, [esi + 8]
// 00771512  52                   push edx
// 00771513  51                   push ecx
// 00771514  50                   push eax
// 00771515  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00771518  50                   push eax
// 00771519  c745e402000000       mov dword ptr [ebp - 0x1c], 2
// 00771520  e88becffff           call 0x7701b0
// 00771525  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00771528  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0077152b  2bcb                 sub ecx, ebx
// 0077152d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00771532  f7e9                 imul ecx
// 00771534  c1fa02               sar edx, 2
// 00771537  8bca                 mov ecx, edx
// 00771539  c1e91f               shr ecx, 0x1f
// 0077153c  03ca                 add ecx, edx
// 0077153e  83c418               add esp, 0x18
// 00771541  03f9                 add edi, ecx
// 00771543  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0077154a  85db                 test ebx, ebx
// 0077154c  741e                 je 0x77156c
// 0077154e  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00771551  52                   push edx
// 00771552  8d4608               lea eax, [esi + 8]
// 00771555  50                   push eax
// 00771556  8b4610               mov eax, dword ptr [esi + 0x10]
// 00771559  50                   push eax
// 0077155a  53                   push ebx
// 0077155b  e830ebffff           call 0x770090
// 00771560  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00771563  51                   push ecx
// 00771564  e831640300           call 0x7a799a
// 00771569  83c414               add esp, 0x14
// 0077156c  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0077156f  8d1440               lea edx, [eax + eax*2]
// 00771572  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00771575  8d0cd0               lea ecx, [eax + edx*8]
// 00771578  8d147f               lea edx, [edi + edi*2]
// 0077157b  894e14               mov dword ptr [esi + 0x14], ecx
// 0077157e  8d0cd0               lea ecx, [eax + edx*8]
// 00771581  894e10               mov dword ptr [esi + 0x10], ecx
// 00771584  89460c               mov dword ptr [esi + 0xc], eax
// 00771587  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0077158a  64890d00000000       mov dword ptr fs:[0], ecx
// 00771591  5f                   pop edi
// 00771592  5e                   pop esi
// 00771593  5b                   pop ebx
// 00771594  8be5                 mov esp, ebp
// 00771596  5d                   pop ebp
// 00771597  c21000               ret 0x10
// library ogre-1.6.4/OgreScriptCompiler.cpp (function ?_Insert_n@?$vector@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@V?$allocator@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@@2@@std@@IAEXV?$_Vector_const_iterator@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@V?$allocator@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@@2@@2@IABU?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreScriptCompiler.cpp
