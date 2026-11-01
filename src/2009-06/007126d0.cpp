// from server: 100% by auto
// roc 2009-06 007126d0  unit: W4_D3DFORMAT::?$EnumDesc  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007126d0
//
// 007126d0  55                   push ebp
// 007126d1  8bec                 mov ebp, esp
// 007126d3  6aff                 push -1
// 007126d5  68c0428700           push 0x8742c0
// 007126da  64a100000000         mov eax, dword ptr fs:[0]
// 007126e0  50                   push eax
// 007126e1  83ec08               sub esp, 8
// 007126e4  53                   push ebx
// 007126e5  56                   push esi
// 007126e6  57                   push edi
// 007126e7  a1304fa200           mov eax, dword ptr [0xa24f30]
// 007126ec  33c5                 xor eax, ebp
// 007126ee  50                   push eax
// 007126ef  8d45f4               lea eax, [ebp - 0xc]
// 007126f2  64a300000000         mov dword ptr fs:[0], eax
// 007126f8  8965f0               mov dword ptr [ebp - 0x10], esp
// 007126fb  8bf1                 mov esi, ecx
// 007126fd  8b560c               mov edx, dword ptr [esi + 0xc]
// 00712700  85d2                 test edx, edx
// 00712702  7504                 jne 0x712708
// 00712704  33c9                 xor ecx, ecx
// 00712706  eb0a                 jmp 0x712712
// 00712708  8b4614               mov eax, dword ptr [esi + 0x14]
// 0071270b  2bc2                 sub eax, edx
// 0071270d  c1f802               sar eax, 2
// 00712710  8bc8                 mov ecx, eax
// 00712712  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00712715  85ff                 test edi, edi
// 00712717  0f84e0010000         je 0x7128fd
// 0071271d  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00712720  8bc3                 mov eax, ebx
// 00712722  2bc2                 sub eax, edx
// 00712724  c1f802               sar eax, 2
// 00712727  baffffff3f           mov edx, 0x3fffffff
// 0071272c  2bd0                 sub edx, eax
// 0071272e  3bd7                 cmp edx, edi
// 00712730  7305                 jae 0x712737
// 00712732  e8d9f8ffff           call 0x712010
// 00712737  8d1438               lea edx, [eax + edi]
// 0071273a  3bca                 cmp ecx, edx
// 0071273c  0f83fa000000         jae 0x71283c
// 00712742  8bc1                 mov eax, ecx
// 00712744  d1e8                 shr eax, 1
// 00712746  bbffffff3f           mov ebx, 0x3fffffff
// 0071274b  2bd8                 sub ebx, eax
// 0071274d  3bd9                 cmp ebx, ecx
// 0071274f  730c                 jae 0x71275d
// 00712751  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00712758  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0071275b  eb05                 jmp 0x712762
// 0071275d  03c8                 add ecx, eax
// 0071275f  894dec               mov dword ptr [ebp - 0x14], ecx
// 00712762  3bca                 cmp ecx, edx
// 00712764  7305                 jae 0x71276b
// 00712766  8955ec               mov dword ptr [ebp - 0x14], edx
// 00712769  8bca                 mov ecx, edx
// 0071276b  6a00                 push 0
// 0071276d  51                   push ecx
// 0071276e  e88d62eeff           call 0x5f8a00
// 00712773  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00712776  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 00712779  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0071277c  83c408               add esp, 8
// 0071277f  51                   push ecx
// 00712780  c1fb02               sar ebx, 2
// 00712783  57                   push edi
// 00712784  8d1498               lea edx, [eax + ebx*4]
// 00712787  52                   push edx
// 00712788  8bce                 mov ecx, esi
// 0071278a  894510               mov dword ptr [ebp + 0x10], eax
// 0071278d  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00712794  e8e7e0d2ff           call 0x440880
// 00712799  8b460c               mov eax, dword ptr [esi + 0xc]
// 0071279c  c6451400             mov byte ptr [ebp + 0x14], 0
// 007127a0  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007127a3  52                   push edx
// 007127a4  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007127a7  52                   push edx
// 007127a8  8b550c               mov edx, dword ptr [ebp + 0xc]
// 007127ab  8d4e08               lea ecx, [esi + 8]
// 007127ae  51                   push ecx
// 007127af  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 007127b2  51                   push ecx
// 007127b3  52                   push edx
// 007127b4  50                   push eax
// 007127b5  e8c633f9ff           call 0x6a5b80
// 007127ba  8b4610               mov eax, dword ptr [esi + 0x10]
// 007127bd  83c418               add esp, 0x18
// 007127c0  c6451400             mov byte ptr [ebp + 0x14], 0
// 007127c4  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007127c7  52                   push edx
// 007127c8  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007127cb  52                   push edx
// 007127cc  8d0c3b               lea ecx, [ebx + edi]
// 007127cf  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 007127d2  8d5608               lea edx, [esi + 8]
// 007127d5  52                   push edx
// 007127d6  8d0c8b               lea ecx, [ebx + ecx*4]
// 007127d9  51                   push ecx
// 007127da  50                   push eax
// 007127db  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007127de  50                   push eax
// 007127df  e89c33f9ff           call 0x6a5b80
// 007127e4  8b460c               mov eax, dword ptr [esi + 0xc]
// 007127e7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007127ea  2bc8                 sub ecx, eax
// 007127ec  c1f902               sar ecx, 2
// 007127ef  83c418               add esp, 0x18
// 007127f2  03f9                 add edi, ecx
// 007127f4  85c0                 test eax, eax
// 007127f6  7409                 je 0x712801
// 007127f8  50                   push eax
// 007127f9  e834620000           call 0x718a32
// 007127fe  83c404               add esp, 4
// 00712801  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00712804  8d0493               lea eax, [ebx + edx*4]
// 00712807  8d0cbb               lea ecx, [ebx + edi*4]
// 0071280a  894614               mov dword ptr [esi + 0x14], eax
// 0071280d  894e10               mov dword ptr [esi + 0x10], ecx
// 00712810  895e0c               mov dword ptr [esi + 0xc], ebx
// 00712813  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00712816  64890d00000000       mov dword ptr fs:[0], ecx
// 0071281d  59                   pop ecx
// 0071281e  5f                   pop edi
// 0071281f  5e                   pop esi
// 00712820  5b                   pop ebx
// 00712821  8be5                 mov esp, ebp
// 00712823  5d                   pop ebp
// 00712824  c21000               ret 0x10
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ?_Insert_n@?$vector@W4PixelFormat@Ogre@@V?$allocator@W4PixelFormat@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@W4PixelFormat@Ogre@@V?$allocator@W4PixelFormat@Ogre@@@std@@@2@IABW4PixelFormat@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
