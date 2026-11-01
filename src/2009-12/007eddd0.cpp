// from server: 100% by auto
// roc 2009-12 007eddd0  unit: W4_D3DFORMAT::?$EnumDesc  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007eddd0
//
// 007eddd0  55                   push ebp
// 007eddd1  8bec                 mov ebp, esp
// 007eddd3  6aff                 push -1
// 007eddd5  6890849500           push 0x958490
// 007eddda  64a100000000         mov eax, dword ptr fs:[0]
// 007edde0  50                   push eax
// 007edde1  83ec08               sub esp, 8
// 007edde4  53                   push ebx
// 007edde5  56                   push esi
// 007edde6  57                   push edi
// 007edde7  a10052b600           mov eax, dword ptr [0xb65200]
// 007eddec  33c5                 xor eax, ebp
// 007eddee  50                   push eax
// 007eddef  8d45f4               lea eax, [ebp - 0xc]
// 007eddf2  64a300000000         mov dword ptr fs:[0], eax
// 007eddf8  8965f0               mov dword ptr [ebp - 0x10], esp
// 007eddfb  8bf1                 mov esi, ecx
// 007eddfd  8b560c               mov edx, dword ptr [esi + 0xc]
// 007ede00  85d2                 test edx, edx
// 007ede02  7504                 jne 0x7ede08
// 007ede04  33c9                 xor ecx, ecx
// 007ede06  eb0a                 jmp 0x7ede12
// 007ede08  8b4614               mov eax, dword ptr [esi + 0x14]
// 007ede0b  2bc2                 sub eax, edx
// 007ede0d  c1f802               sar eax, 2
// 007ede10  8bc8                 mov ecx, eax
// 007ede12  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 007ede15  85ff                 test edi, edi
// 007ede17  0f84e0010000         je 0x7edffd
// 007ede1d  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 007ede20  8bc3                 mov eax, ebx
// 007ede22  2bc2                 sub eax, edx
// 007ede24  c1f802               sar eax, 2
// 007ede27  baffffff3f           mov edx, 0x3fffffff
// 007ede2c  2bd0                 sub edx, eax
// 007ede2e  3bd7                 cmp edx, edi
// 007ede30  7305                 jae 0x7ede37
// 007ede32  e8d9f8ffff           call 0x7ed710
// 007ede37  8d1438               lea edx, [eax + edi]
// 007ede3a  3bca                 cmp ecx, edx
// 007ede3c  0f83fa000000         jae 0x7edf3c
// 007ede42  8bc1                 mov eax, ecx
// 007ede44  d1e8                 shr eax, 1
// 007ede46  bbffffff3f           mov ebx, 0x3fffffff
// 007ede4b  2bd8                 sub ebx, eax
// 007ede4d  3bd9                 cmp ebx, ecx
// 007ede4f  730c                 jae 0x7ede5d
// 007ede51  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 007ede58  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 007ede5b  eb05                 jmp 0x7ede62
// 007ede5d  03c8                 add ecx, eax
// 007ede5f  894dec               mov dword ptr [ebp - 0x14], ecx
// 007ede62  3bca                 cmp ecx, edx
// 007ede64  7305                 jae 0x7ede6b
// 007ede66  8955ec               mov dword ptr [ebp - 0x14], edx
// 007ede69  8bca                 mov ecx, edx
// 007ede6b  6a00                 push 0
// 007ede6d  51                   push ecx
// 007ede6e  e8cd2ac4ff           call 0x430940
// 007ede73  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 007ede76  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 007ede79  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 007ede7c  83c408               add esp, 8
// 007ede7f  51                   push ecx
// 007ede80  c1fb02               sar ebx, 2
// 007ede83  57                   push edi
// 007ede84  8d1498               lea edx, [eax + ebx*4]
// 007ede87  52                   push edx
// 007ede88  8bce                 mov ecx, esi
// 007ede8a  894510               mov dword ptr [ebp + 0x10], eax
// 007ede8d  c745fc00000000       mov dword ptr [ebp - 4], 0
// 007ede94  e8b749f8ff           call 0x772850
// 007ede99  8b460c               mov eax, dword ptr [esi + 0xc]
// 007ede9c  c6451400             mov byte ptr [ebp + 0x14], 0
// 007edea0  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007edea3  52                   push edx
// 007edea4  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007edea7  52                   push edx
// 007edea8  8b550c               mov edx, dword ptr [ebp + 0xc]
// 007edeab  8d4e08               lea ecx, [esi + 8]
// 007edeae  51                   push ecx
// 007edeaf  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 007edeb2  51                   push ecx
// 007edeb3  52                   push edx
// 007edeb4  50                   push eax
// 007edeb5  e8d665c5ff           call 0x444490
// 007edeba  8b4610               mov eax, dword ptr [esi + 0x10]
// 007edebd  83c418               add esp, 0x18
// 007edec0  c6451400             mov byte ptr [ebp + 0x14], 0
// 007edec4  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007edec7  52                   push edx
// 007edec8  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007edecb  52                   push edx
// 007edecc  8d0c3b               lea ecx, [ebx + edi]
// 007edecf  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 007eded2  8d5608               lea edx, [esi + 8]
// 007eded5  52                   push edx
// 007eded6  8d0c8b               lea ecx, [ebx + ecx*4]
// 007eded9  51                   push ecx
// 007ededa  50                   push eax
// 007ededb  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007edede  50                   push eax
// 007ededf  e8ac65c5ff           call 0x444490
// 007edee4  8b460c               mov eax, dword ptr [esi + 0xc]
// 007edee7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007edeea  2bc8                 sub ecx, eax
// 007edeec  c1f902               sar ecx, 2
// 007edeef  83c418               add esp, 0x18
// 007edef2  03f9                 add edi, ecx
// 007edef4  85c0                 test eax, eax
// 007edef6  7409                 je 0x7edf01
// 007edef8  50                   push eax
// 007edef9  e85c590000           call 0x7f385a
// 007edefe  83c404               add esp, 4
// 007edf01  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 007edf04  8d0493               lea eax, [ebx + edx*4]
// 007edf07  8d0cbb               lea ecx, [ebx + edi*4]
// 007edf0a  894614               mov dword ptr [esi + 0x14], eax
// 007edf0d  894e10               mov dword ptr [esi + 0x10], ecx
// 007edf10  895e0c               mov dword ptr [esi + 0xc], ebx
// 007edf13  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 007edf16  64890d00000000       mov dword ptr fs:[0], ecx
// 007edf1d  59                   pop ecx
// 007edf1e  5f                   pop edi
// 007edf1f  5e                   pop esi
// 007edf20  5b                   pop ebx
// 007edf21  8be5                 mov esp, ebp
// 007edf23  5d                   pop ebp
// 007edf24  c21000               ret 0x10
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ?_Insert_n@?$vector@W4PixelFormat@Ogre@@V?$allocator@W4PixelFormat@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@W4PixelFormat@Ogre@@V?$allocator@W4PixelFormat@Ogre@@@std@@@2@IABW4PixelFormat@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
