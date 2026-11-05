// from server: 100% by auto
// roc 2010-06 008d3490  unit: Ogre::VisualEngine  size: 409 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d3490
//
// 008d3490  55                   push ebp
// 008d3491  8bec                 mov ebp, esp
// 008d3493  6aff                 push -1
// 008d3495  68f0e29b00           push 0x9be2f0
// 008d349a  64a100000000         mov eax, dword ptr fs:[0]
// 008d34a0  50                   push eax
// 008d34a1  64892500000000       mov dword ptr fs:[0], esp
// 008d34a8  83ec20               sub esp, 0x20
// 008d34ab  53                   push ebx
// 008d34ac  56                   push esi
// 008d34ad  8bf1                 mov esi, ecx
// 008d34af  8b460c               mov eax, dword ptr [esi + 0xc]
// 008d34b2  57                   push edi
// 008d34b3  8965f0               mov dword ptr [ebp - 0x10], esp
// 008d34b6  85c0                 test eax, eax
// 008d34b8  7505                 jne 0x8d34bf
// 008d34ba  8945ec               mov dword ptr [ebp - 0x14], eax
// 008d34bd  eb19                 jmp 0x8d34d8
// 008d34bf  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 008d34c2  2bc8                 sub ecx, eax
// 008d34c4  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d34c9  f7e9                 imul ecx
// 008d34cb  c1fa02               sar edx, 2
// 008d34ce  8bc2                 mov eax, edx
// 008d34d0  c1e81f               shr eax, 0x1f
// 008d34d3  03c2                 add eax, edx
// 008d34d5  8945ec               mov dword ptr [ebp - 0x14], eax
// 008d34d8  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 008d34db  85ff                 test edi, edi
// 008d34dd  0f8448020000         je 0x8d372b
// 008d34e3  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008d34e6  8bcb                 mov ecx, ebx
// 008d34e8  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 008d34eb  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d34f0  f7e9                 imul ecx
// 008d34f2  c1fa02               sar edx, 2
// 008d34f5  8bc2                 mov eax, edx
// 008d34f7  c1e81f               shr eax, 0x1f
// 008d34fa  03c2                 add eax, edx
// 008d34fc  b9aaaaaa0a           mov ecx, 0xaaaaaaa
// 008d3501  2bc8                 sub ecx, eax
// 008d3503  3bcf                 cmp ecx, edi
// 008d3505  7305                 jae 0x8d350c
// 008d3507  e8e408b5ff           call 0x423df0
// 008d350c  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 008d350f  03c7                 add eax, edi
// 008d3511  3bc8                 cmp ecx, eax
// 008d3513  0f8325010000         jae 0x8d363e
// 008d3519  8bd1                 mov edx, ecx
// 008d351b  d1ea                 shr edx, 1
// 008d351d  bbaaaaaa0a           mov ebx, 0xaaaaaaa
// 008d3522  2bda                 sub ebx, edx
// 008d3524  3bd9                 cmp ebx, ecx
// 008d3526  730c                 jae 0x8d3534
// 008d3528  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 008d352f  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 008d3532  eb05                 jmp 0x8d3539
// 008d3534  03ca                 add ecx, edx
// 008d3536  894dec               mov dword ptr [ebp - 0x14], ecx
// 008d3539  3bc8                 cmp ecx, eax
// 008d353b  7305                 jae 0x8d3542
// 008d353d  8945ec               mov dword ptr [ebp - 0x14], eax
// 008d3540  8bc8                 mov ecx, eax
// 008d3542  6a00                 push 0
// 008d3544  51                   push ecx
// 008d3545  e896d1e5ff           call 0x7306e0
// 008d354a  8b550c               mov edx, dword ptr [ebp + 0xc]
// 008d354d  2b560c               sub edx, dword ptr [esi + 0xc]
// 008d3550  8bc8                 mov ecx, eax
// 008d3552  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d3557  f7ea                 imul edx
// 008d3559  c1fa02               sar edx, 2
// 008d355c  8bda                 mov ebx, edx
// 008d355e  83c408               add esp, 8
// 008d3561  c1eb1f               shr ebx, 0x1f
// 008d3564  03da                 add ebx, edx
// 008d3566  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008d3569  52                   push edx
// 008d356a  894d10               mov dword ptr [ebp + 0x10], ecx
// 008d356d  8d045b               lea eax, [ebx + ebx*2]
// 008d3570  8d0cc1               lea ecx, [ecx + eax*8]
// 008d3573  57                   push edi
// 008d3574  51                   push ecx
// 008d3575  8bce                 mov ecx, esi
// 008d3577  c745fc00000000       mov dword ptr [ebp - 4], 0
// 008d357e  e8ddf8ffff           call 0x8d2e60
// 008d3583  8b460c               mov eax, dword ptr [esi + 0xc]
// 008d3586  c6451400             mov byte ptr [ebp + 0x14], 0
// 008d358a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008d358d  52                   push edx
// 008d358e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008d3591  52                   push edx
// 008d3592  8b550c               mov edx, dword ptr [ebp + 0xc]
// 008d3595  8d4e08               lea ecx, [esi + 8]
// 008d3598  51                   push ecx
// 008d3599  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 008d359c  51                   push ecx
// 008d359d  52                   push edx
// 008d359e  50                   push eax
// 008d359f  e8ccf2ffff           call 0x8d2870
// 008d35a4  8b5510               mov edx, dword ptr [ebp + 0x10]
// 008d35a7  8b4610               mov eax, dword ptr [esi + 0x10]
// 008d35aa  83c418               add esp, 0x18
// 008d35ad  03df                 add ebx, edi
// 008d35af  8d0c5b               lea ecx, [ebx + ebx*2]
// 008d35b2  8d0cca               lea ecx, [edx + ecx*8]
// 008d35b5  c6451400             mov byte ptr [ebp + 0x14], 0
// 008d35b9  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008d35bc  52                   push edx
// 008d35bd  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008d35c0  52                   push edx
// 008d35c1  8d5608               lea edx, [esi + 8]
// 008d35c4  52                   push edx
// 008d35c5  51                   push ecx
// 008d35c6  50                   push eax
// 008d35c7  8b450c               mov eax, dword ptr [ebp + 0xc]
// 008d35ca  50                   push eax
// 008d35cb  e8a0f2ffff           call 0x8d2870
// 008d35d0  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008d35d3  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008d35d6  2bcb                 sub ecx, ebx
// 008d35d8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d35dd  f7e9                 imul ecx
// 008d35df  c1fa02               sar edx, 2
// 008d35e2  8bca                 mov ecx, edx
// 008d35e4  c1e91f               shr ecx, 0x1f
// 008d35e7  03ca                 add ecx, edx
// 008d35e9  83c418               add esp, 0x18
// 008d35ec  03f9                 add edi, ecx
// 008d35ee  85db                 test ebx, ebx
// 008d35f0  7409                 je 0x8d35fb
// 008d35f2  53                   push ebx
// 008d35f3  e8a243edff           call 0x7a799a
// 008d35f8  83c404               add esp, 4
// 008d35fb  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 008d35fe  8d1440               lea edx, [eax + eax*2]
// 008d3601  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008d3604  8d0cd0               lea ecx, [eax + edx*8]
// 008d3607  8d147f               lea edx, [edi + edi*2]
// 008d360a  894e14               mov dword ptr [esi + 0x14], ecx
// 008d360d  8d0cd0               lea ecx, [eax + edx*8]
// 008d3610  894e10               mov dword ptr [esi + 0x10], ecx
// 008d3613  89460c               mov dword ptr [esi + 0xc], eax
// 008d3616  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008d3619  64890d00000000       mov dword ptr fs:[0], ecx
// 008d3620  5f                   pop edi
// 008d3621  5e                   pop esi
// 008d3622  5b                   pop ebx
// 008d3623  8be5                 mov esp, ebp
// 008d3625  5d                   pop ebp
// 008d3626  c21000               ret 0x10
// library ogre-1.4.9/OgreSceneManager.cpp (function ?_Insert_n@?$vector@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@2@IABULightInfo@SceneManager@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
