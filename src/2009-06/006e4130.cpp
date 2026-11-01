// from server: 100% by auto
// roc 2009-06 006e4130  unit: RBX::ScoreHud  size: 458 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e4130
//
// 006e4130  55                   push ebp
// 006e4131  8bec                 mov ebp, esp
// 006e4133  6aff                 push -1
// 006e4135  68001e8700           push 0x871e00
// 006e413a  64a100000000         mov eax, dword ptr fs:[0]
// 006e4140  50                   push eax
// 006e4141  64892500000000       mov dword ptr fs:[0], esp
// 006e4148  83ec48               sub esp, 0x48
// 006e414b  53                   push ebx
// 006e414c  56                   push esi
// 006e414d  8bf1                 mov esi, ecx
// 006e414f  8b460c               mov eax, dword ptr [esi + 0xc]
// 006e4152  57                   push edi
// 006e4153  8965f0               mov dword ptr [ebp - 0x10], esp
// 006e4156  8975e0               mov dword ptr [ebp - 0x20], esi
// 006e4159  85c0                 test eax, eax
// 006e415b  7505                 jne 0x6e4162
// 006e415d  8945ec               mov dword ptr [ebp - 0x14], eax
// 006e4160  eb19                 jmp 0x6e417b
// 006e4162  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006e4165  2bc8                 sub ecx, eax
// 006e4167  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006e416c  f7e9                 imul ecx
// 006e416e  c1fa02               sar edx, 2
// 006e4171  8bc2                 mov eax, edx
// 006e4173  c1e81f               shr eax, 0x1f
// 006e4176  03c2                 add eax, edx
// 006e4178  8945ec               mov dword ptr [ebp - 0x14], eax
// 006e417b  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 006e417e  85ff                 test edi, edi
// 006e4180  0f84ef020000         je 0x6e4475
// 006e4186  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 006e4189  8bcb                 mov ecx, ebx
// 006e418b  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 006e418e  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006e4193  f7e9                 imul ecx
// 006e4195  c1fa02               sar edx, 2
// 006e4198  8bc2                 mov eax, edx
// 006e419a  c1e81f               shr eax, 0x1f
// 006e419d  03c2                 add eax, edx
// 006e419f  b9aaaaaa0a           mov ecx, 0xaaaaaaa
// 006e41a4  2bc8                 sub ecx, eax
// 006e41a6  3bcf                 cmp ecx, edi
// 006e41a8  7305                 jae 0x6e41af
// 006e41aa  e8b1c1daff           call 0x490360
// 006e41af  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 006e41b2  03c7                 add eax, edi
// 006e41b4  3bc8                 cmp ecx, eax
// 006e41b6  0f838e010000         jae 0x6e434a
// 006e41bc  8bd1                 mov edx, ecx
// 006e41be  d1ea                 shr edx, 1
// 006e41c0  bbaaaaaa0a           mov ebx, 0xaaaaaaa
// 006e41c5  2bda                 sub ebx, edx
// 006e41c7  3bd9                 cmp ebx, ecx
// 006e41c9  730c                 jae 0x6e41d7
// 006e41cb  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 006e41d2  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 006e41d5  eb05                 jmp 0x6e41dc
// 006e41d7  03ca                 add ecx, edx
// 006e41d9  894dec               mov dword ptr [ebp - 0x14], ecx
// 006e41dc  3bc8                 cmp ecx, eax
// 006e41de  7305                 jae 0x6e41e5
// 006e41e0  8945ec               mov dword ptr [ebp - 0x14], eax
// 006e41e3  8bc8                 mov ecx, eax
// 006e41e5  6a00                 push 0
// 006e41e7  51                   push ecx
// 006e41e8  e813d9fdff           call 0x6c1b00
// 006e41ed  8b550c               mov edx, dword ptr [ebp + 0xc]
// 006e41f0  2b560c               sub edx, dword ptr [esi + 0xc]
// 006e41f3  8bc8                 mov ecx, eax
// 006e41f5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006e41fa  f7ea                 imul edx
// 006e41fc  c1fa02               sar edx, 2
// 006e41ff  8bda                 mov ebx, edx
// 006e4201  33c0                 xor eax, eax
// 006e4203  83c408               add esp, 8
// 006e4206  c1eb1f               shr ebx, 0x1f
// 006e4209  03da                 add ebx, edx
// 006e420b  8b5514               mov edx, dword ptr [ebp + 0x14]
// 006e420e  8945e4               mov dword ptr [ebp - 0x1c], eax
// 006e4211  8945fc               mov dword ptr [ebp - 4], eax
// 006e4214  52                   push edx
// 006e4215  894de8               mov dword ptr [ebp - 0x18], ecx
// 006e4218  8d045b               lea eax, [ebx + ebx*2]
// 006e421b  8d0cc1               lea ecx, [ecx + eax*8]
// 006e421e  57                   push edi
// 006e421f  51                   push ecx
// 006e4220  8bce                 mov ecx, esi
// 006e4222  895ddc               mov dword ptr [ebp - 0x24], ebx
// 006e4225  e826fcffff           call 0x6e3e50
// 006e422a  8b460c               mov eax, dword ptr [esi + 0xc]
// 006e422d  c6451400             mov byte ptr [ebp + 0x14], 0
// 006e4231  8b5514               mov edx, dword ptr [ebp + 0x14]
// 006e4234  52                   push edx
// 006e4235  8b5510               mov edx, dword ptr [ebp + 0x10]
// 006e4238  52                   push edx
// 006e4239  8b550c               mov edx, dword ptr [ebp + 0xc]
// 006e423c  8d4e08               lea ecx, [esi + 8]
// 006e423f  51                   push ecx
// 006e4240  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 006e4243  51                   push ecx
// 006e4244  52                   push edx
// 006e4245  50                   push eax
// 006e4246  c745e401000000       mov dword ptr [ebp - 0x1c], 1
// 006e424d  e8beecffff           call 0x6e2f10
// 006e4252  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 006e4255  8b4610               mov eax, dword ptr [esi + 0x10]
// 006e4258  83c418               add esp, 0x18
// 006e425b  03df                 add ebx, edi
// 006e425d  8d0c5b               lea ecx, [ebx + ebx*2]
// 006e4260  8d0cca               lea ecx, [edx + ecx*8]
// 006e4263  c6451400             mov byte ptr [ebp + 0x14], 0
// 006e4267  8b5514               mov edx, dword ptr [ebp + 0x14]
// 006e426a  52                   push edx
// 006e426b  8b5510               mov edx, dword ptr [ebp + 0x10]
// 006e426e  52                   push edx
// 006e426f  8d5608               lea edx, [esi + 8]
// 006e4272  52                   push edx
// 006e4273  51                   push ecx
// 006e4274  50                   push eax
// 006e4275  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006e4278  50                   push eax
// 006e4279  c745e402000000       mov dword ptr [ebp - 0x1c], 2
// 006e4280  e88becffff           call 0x6e2f10
// 006e4285  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006e4288  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006e428b  2bcb                 sub ecx, ebx
// 006e428d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006e4292  f7e9                 imul ecx
// 006e4294  c1fa02               sar edx, 2
// 006e4297  8bca                 mov ecx, edx
// 006e4299  c1e91f               shr ecx, 0x1f
// 006e429c  03ca                 add ecx, edx
// 006e429e  83c418               add esp, 0x18
// 006e42a1  03f9                 add edi, ecx
// 006e42a3  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 006e42aa  85db                 test ebx, ebx
// 006e42ac  741e                 je 0x6e42cc
// 006e42ae  8b5510               mov edx, dword ptr [ebp + 0x10]
// 006e42b1  52                   push edx
// 006e42b2  8d4608               lea eax, [esi + 8]
// 006e42b5  50                   push eax
// 006e42b6  8b4610               mov eax, dword ptr [esi + 0x10]
// 006e42b9  50                   push eax
// 006e42ba  53                   push ebx
// 006e42bb  e830ebffff           call 0x6e2df0
// 006e42c0  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006e42c3  51                   push ecx
// 006e42c4  e869470300           call 0x718a32
// 006e42c9  83c414               add esp, 0x14
// 006e42cc  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 006e42cf  8d1440               lea edx, [eax + eax*2]
// 006e42d2  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 006e42d5  8d0cd0               lea ecx, [eax + edx*8]
// 006e42d8  8d147f               lea edx, [edi + edi*2]
// 006e42db  894e14               mov dword ptr [esi + 0x14], ecx
// 006e42de  8d0cd0               lea ecx, [eax + edx*8]
// 006e42e1  894e10               mov dword ptr [esi + 0x10], ecx
// 006e42e4  89460c               mov dword ptr [esi + 0xc], eax
// 006e42e7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006e42ea  64890d00000000       mov dword ptr fs:[0], ecx
// 006e42f1  5f                   pop edi
// 006e42f2  5e                   pop esi
// 006e42f3  5b                   pop ebx
// 006e42f4  8be5                 mov esp, ebp
// 006e42f6  5d                   pop ebp
// 006e42f7  c21000               ret 0x10
// library ogre-1.6.4/OgreScriptCompiler.cpp (function ?_Insert_n@?$vector@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@V?$allocator@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@@2@@std@@IAEXV?$_Vector_const_iterator@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@V?$allocator@U?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@std@@@2@@2@IABU?$pair@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$_Iterator@$00@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreScriptCompiler.cpp
