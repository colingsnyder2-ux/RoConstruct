// from server: 100% by auto
// roc 2009-06 0047b9e0  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 401 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047b9e0
//
// 0047b9e0  55                   push ebp
// 0047b9e1  8bec                 mov ebp, esp
// 0047b9e3  6aff                 push -1
// 0047b9e5  68604a8500           push 0x854a60
// 0047b9ea  64a100000000         mov eax, dword ptr fs:[0]
// 0047b9f0  50                   push eax
// 0047b9f1  64892500000000       mov dword ptr fs:[0], esp
// 0047b9f8  83ec14               sub esp, 0x14
// 0047b9fb  53                   push ebx
// 0047b9fc  56                   push esi
// 0047b9fd  8bf1                 mov esi, ecx
// 0047b9ff  8b460c               mov eax, dword ptr [esi + 0xc]
// 0047ba02  57                   push edi
// 0047ba03  8965f0               mov dword ptr [ebp - 0x10], esp
// 0047ba06  85c0                 test eax, eax
// 0047ba08  7504                 jne 0x47ba0e
// 0047ba0a  33c9                 xor ecx, ecx
// 0047ba0c  eb17                 jmp 0x47ba25
// 0047ba0e  8b5614               mov edx, dword ptr [esi + 0x14]
// 0047ba11  2bd0                 sub edx, eax
// 0047ba13  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0047ba18  f7ea                 imul edx
// 0047ba1a  d1fa                 sar edx, 1
// 0047ba1c  8bc2                 mov eax, edx
// 0047ba1e  c1e81f               shr eax, 0x1f
// 0047ba21  03c2                 add eax, edx
// 0047ba23  8bc8                 mov ecx, eax
// 0047ba25  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 0047ba28  85ff                 test edi, edi
// 0047ba2a  0f8434020000         je 0x47bc64
// 0047ba30  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0047ba33  8bd3                 mov edx, ebx
// 0047ba35  2b560c               sub edx, dword ptr [esi + 0xc]
// 0047ba38  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0047ba3d  f7ea                 imul edx
// 0047ba3f  d1fa                 sar edx, 1
// 0047ba41  8bc2                 mov eax, edx
// 0047ba43  c1e81f               shr eax, 0x1f
// 0047ba46  03c2                 add eax, edx
// 0047ba48  ba55555515           mov edx, 0x15555555
// 0047ba4d  2bd0                 sub edx, eax
// 0047ba4f  3bd7                 cmp edx, edi
// 0047ba51  7305                 jae 0x47ba58
// 0047ba53  e808490100           call 0x490360
// 0047ba58  8d1438               lea edx, [eax + edi]
// 0047ba5b  3bca                 cmp ecx, edx
// 0047ba5d  0f8323010000         jae 0x47bb86
// 0047ba63  8bc1                 mov eax, ecx
// 0047ba65  d1e8                 shr eax, 1
// 0047ba67  bb55555515           mov ebx, 0x15555555
// 0047ba6c  2bd8                 sub ebx, eax
// 0047ba6e  3bd9                 cmp ebx, ecx
// 0047ba70  730c                 jae 0x47ba7e
// 0047ba72  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 0047ba79  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0047ba7c  eb05                 jmp 0x47ba83
// 0047ba7e  03c8                 add ecx, eax
// 0047ba80  894dec               mov dword ptr [ebp - 0x14], ecx
// 0047ba83  3bca                 cmp ecx, edx
// 0047ba85  7305                 jae 0x47ba8c
// 0047ba87  8955ec               mov dword ptr [ebp - 0x14], edx
// 0047ba8a  8bca                 mov ecx, edx
// 0047ba8c  6a00                 push 0
// 0047ba8e  51                   push ecx
// 0047ba8f  e8bcf4ffff           call 0x47af50
// 0047ba94  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0047ba97  2b560c               sub edx, dword ptr [esi + 0xc]
// 0047ba9a  8bc8                 mov ecx, eax
// 0047ba9c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0047baa1  f7ea                 imul edx
// 0047baa3  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0047baa6  d1fa                 sar edx, 1
// 0047baa8  8bda                 mov ebx, edx
// 0047baaa  83c408               add esp, 8
// 0047baad  c1eb1f               shr ebx, 0x1f
// 0047bab0  03da                 add ebx, edx
// 0047bab2  50                   push eax
// 0047bab3  8d145b               lea edx, [ebx + ebx*2]
// 0047bab6  8d0491               lea eax, [ecx + edx*4]
// 0047bab9  57                   push edi
// 0047baba  894d10               mov dword ptr [ebp + 0x10], ecx
// 0047babd  50                   push eax
// 0047babe  8bce                 mov ecx, esi
// 0047bac0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0047bac7  e814fcffff           call 0x47b6e0
// 0047bacc  8b460c               mov eax, dword ptr [esi + 0xc]
// 0047bacf  c6451400             mov byte ptr [ebp + 0x14], 0
// 0047bad3  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0047bad6  52                   push edx
// 0047bad7  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0047bada  52                   push edx
// 0047badb  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0047bade  8d4e08               lea ecx, [esi + 8]
// 0047bae1  51                   push ecx
// 0047bae2  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0047bae5  51                   push ecx
// 0047bae6  52                   push edx
// 0047bae7  50                   push eax
// 0047bae8  e823f5ffff           call 0x47b010
// 0047baed  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0047baf0  8b4610               mov eax, dword ptr [esi + 0x10]
// 0047baf3  83c418               add esp, 0x18
// 0047baf6  03df                 add ebx, edi
// 0047baf8  8d0c5b               lea ecx, [ebx + ebx*2]
// 0047bafb  8d0c8a               lea ecx, [edx + ecx*4]
// 0047bafe  c6451400             mov byte ptr [ebp + 0x14], 0
// 0047bb02  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0047bb05  52                   push edx
// 0047bb06  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0047bb09  52                   push edx
// 0047bb0a  8d5608               lea edx, [esi + 8]
// 0047bb0d  52                   push edx
// 0047bb0e  51                   push ecx
// 0047bb0f  50                   push eax
// 0047bb10  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0047bb13  50                   push eax
// 0047bb14  e8f7f4ffff           call 0x47b010
// 0047bb19  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0047bb1c  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0047bb1f  2bcb                 sub ecx, ebx
// 0047bb21  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0047bb26  f7e9                 imul ecx
// 0047bb28  d1fa                 sar edx, 1
// 0047bb2a  8bca                 mov ecx, edx
// 0047bb2c  c1e91f               shr ecx, 0x1f
// 0047bb2f  03ca                 add ecx, edx
// 0047bb31  83c418               add esp, 0x18
// 0047bb34  03f9                 add edi, ecx
// 0047bb36  85db                 test ebx, ebx
// 0047bb38  7409                 je 0x47bb43
// 0047bb3a  53                   push ebx
// 0047bb3b  e8f2ce2900           call 0x718a32
// 0047bb40  83c404               add esp, 4
// 0047bb43  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0047bb46  8d1440               lea edx, [eax + eax*2]
// 0047bb49  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0047bb4c  8d0c90               lea ecx, [eax + edx*4]
// 0047bb4f  8d147f               lea edx, [edi + edi*2]
// 0047bb52  894e14               mov dword ptr [esi + 0x14], ecx
// 0047bb55  8d0c90               lea ecx, [eax + edx*4]
// 0047bb58  894e10               mov dword ptr [esi + 0x10], ecx
// 0047bb5b  89460c               mov dword ptr [esi + 0xc], eax
// 0047bb5e  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0047bb61  64890d00000000       mov dword ptr fs:[0], ecx
// 0047bb68  5f                   pop edi
// 0047bb69  5e                   pop esi
// 0047bb6a  5b                   pop ebx
// 0047bb6b  8be5                 mov esp, ebp
// 0047bb6d  5d                   pop ebp
// 0047bb6e  c21000               ret 0x10
// library ogre-1.4.9/OgreMeshSerializerImpl.cpp (function ?_Insert_n@?$vector@VVector3@Ogre@@V?$allocator@VVector3@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@VVector3@Ogre@@V?$allocator@VVector3@Ogre@@@std@@@2@IABVVector3@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreMeshSerializerImpl.cpp
