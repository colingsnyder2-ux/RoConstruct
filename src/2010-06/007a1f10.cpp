// from server: 100% by auto
// roc 2010-06 007a1f10  unit: W4_D3DFORMAT::?$EnumDesc  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007a1f10
//
// 007a1f10  55                   push ebp
// 007a1f11  8bec                 mov ebp, esp
// 007a1f13  6aff                 push -1
// 007a1f15  68c0e39a00           push 0x9ae3c0
// 007a1f1a  64a100000000         mov eax, dword ptr fs:[0]
// 007a1f20  50                   push eax
// 007a1f21  83ec08               sub esp, 8
// 007a1f24  53                   push ebx
// 007a1f25  56                   push esi
// 007a1f26  57                   push edi
// 007a1f27  a1b05fbe00           mov eax, dword ptr [0xbe5fb0]
// 007a1f2c  33c5                 xor eax, ebp
// 007a1f2e  50                   push eax
// 007a1f2f  8d45f4               lea eax, [ebp - 0xc]
// 007a1f32  64a300000000         mov dword ptr fs:[0], eax
// 007a1f38  8965f0               mov dword ptr [ebp - 0x10], esp
// 007a1f3b  8bf1                 mov esi, ecx
// 007a1f3d  8b560c               mov edx, dword ptr [esi + 0xc]
// 007a1f40  85d2                 test edx, edx
// 007a1f42  7504                 jne 0x7a1f48
// 007a1f44  33c9                 xor ecx, ecx
// 007a1f46  eb0a                 jmp 0x7a1f52
// 007a1f48  8b4614               mov eax, dword ptr [esi + 0x14]
// 007a1f4b  2bc2                 sub eax, edx
// 007a1f4d  c1f802               sar eax, 2
// 007a1f50  8bc8                 mov ecx, eax
// 007a1f52  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 007a1f55  85ff                 test edi, edi
// 007a1f57  0f84e0010000         je 0x7a213d
// 007a1f5d  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 007a1f60  8bc3                 mov eax, ebx
// 007a1f62  2bc2                 sub eax, edx
// 007a1f64  c1f802               sar eax, 2
// 007a1f67  baffffff3f           mov edx, 0x3fffffff
// 007a1f6c  2bd0                 sub edx, eax
// 007a1f6e  3bd7                 cmp edx, edi
// 007a1f70  7305                 jae 0x7a1f77
// 007a1f72  e8d9f8ffff           call 0x7a1850
// 007a1f77  8d1438               lea edx, [eax + edi]
// 007a1f7a  3bca                 cmp ecx, edx
// 007a1f7c  0f83fa000000         jae 0x7a207c
// 007a1f82  8bc1                 mov eax, ecx
// 007a1f84  d1e8                 shr eax, 1
// 007a1f86  bbffffff3f           mov ebx, 0x3fffffff
// 007a1f8b  2bd8                 sub ebx, eax
// 007a1f8d  3bd9                 cmp ebx, ecx
// 007a1f8f  730c                 jae 0x7a1f9d
// 007a1f91  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 007a1f98  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 007a1f9b  eb05                 jmp 0x7a1fa2
// 007a1f9d  03c8                 add ecx, eax
// 007a1f9f  894dec               mov dword ptr [ebp - 0x14], ecx
// 007a1fa2  3bca                 cmp ecx, edx
// 007a1fa4  7305                 jae 0x7a1fab
// 007a1fa6  8955ec               mov dword ptr [ebp - 0x14], edx
// 007a1fa9  8bca                 mov ecx, edx
// 007a1fab  6a00                 push 0
// 007a1fad  51                   push ecx
// 007a1fae  e85d331300           call 0x8d5310
// 007a1fb3  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 007a1fb6  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 007a1fb9  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 007a1fbc  83c408               add esp, 8
// 007a1fbf  51                   push ecx
// 007a1fc0  c1fb02               sar ebx, 2
// 007a1fc3  57                   push edi
// 007a1fc4  8d1498               lea edx, [eax + ebx*4]
// 007a1fc7  52                   push edx
// 007a1fc8  8bce                 mov ecx, esi
// 007a1fca  894510               mov dword ptr [ebp + 0x10], eax
// 007a1fcd  c745fc00000000       mov dword ptr [ebp - 4], 0
// 007a1fd4  e8b74ff6ff           call 0x706f90
// 007a1fd9  8b460c               mov eax, dword ptr [esi + 0xc]
// 007a1fdc  c6451400             mov byte ptr [ebp + 0x14], 0
// 007a1fe0  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007a1fe3  52                   push edx
// 007a1fe4  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007a1fe7  52                   push edx
// 007a1fe8  8b550c               mov edx, dword ptr [ebp + 0xc]
// 007a1feb  8d4e08               lea ecx, [esi + 8]
// 007a1fee  51                   push ecx
// 007a1fef  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 007a1ff2  51                   push ecx
// 007a1ff3  52                   push edx
// 007a1ff4  50                   push eax
// 007a1ff5  e85638caff           call 0x445850
// 007a1ffa  8b4610               mov eax, dword ptr [esi + 0x10]
// 007a1ffd  83c418               add esp, 0x18
// 007a2000  c6451400             mov byte ptr [ebp + 0x14], 0
// 007a2004  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007a2007  52                   push edx
// 007a2008  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007a200b  52                   push edx
// 007a200c  8d0c3b               lea ecx, [ebx + edi]
// 007a200f  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 007a2012  8d5608               lea edx, [esi + 8]
// 007a2015  52                   push edx
// 007a2016  8d0c8b               lea ecx, [ebx + ecx*4]
// 007a2019  51                   push ecx
// 007a201a  50                   push eax
// 007a201b  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007a201e  50                   push eax
// 007a201f  e82c38caff           call 0x445850
// 007a2024  8b460c               mov eax, dword ptr [esi + 0xc]
// 007a2027  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007a202a  2bc8                 sub ecx, eax
// 007a202c  c1f902               sar ecx, 2
// 007a202f  83c418               add esp, 0x18
// 007a2032  03f9                 add edi, ecx
// 007a2034  85c0                 test eax, eax
// 007a2036  7409                 je 0x7a2041
// 007a2038  50                   push eax
// 007a2039  e85c590000           call 0x7a799a
// 007a203e  83c404               add esp, 4
// 007a2041  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 007a2044  8d0493               lea eax, [ebx + edx*4]
// 007a2047  8d0cbb               lea ecx, [ebx + edi*4]
// 007a204a  894614               mov dword ptr [esi + 0x14], eax
// 007a204d  894e10               mov dword ptr [esi + 0x10], ecx
// 007a2050  895e0c               mov dword ptr [esi + 0xc], ebx
// 007a2053  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 007a2056  64890d00000000       mov dword ptr fs:[0], ecx
// 007a205d  59                   pop ecx
// 007a205e  5f                   pop edi
// 007a205f  5e                   pop esi
// 007a2060  5b                   pop ebx
// 007a2061  8be5                 mov esp, ebp
// 007a2063  5d                   pop ebp
// 007a2064  c21000               ret 0x10
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ?_Insert_n@?$vector@W4PixelFormat@Ogre@@V?$allocator@W4PixelFormat@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@W4PixelFormat@Ogre@@V?$allocator@W4PixelFormat@Ogre@@@std@@@2@IABW4PixelFormat@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
