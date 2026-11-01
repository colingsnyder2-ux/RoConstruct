// from server: 100% by auto
// roc 2010-06 008d9fd0  unit: Ogre::TextureCompositor  size: 443 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d9fd0
//
// 008d9fd0  55                   push ebp
// 008d9fd1  8d6c24a4             lea ebp, [esp - 0x5c]
// 008d9fd5  83ec5c               sub esp, 0x5c
// 008d9fd8  6aff                 push -1
// 008d9fda  68d0e99b00           push 0x9be9d0
// 008d9fdf  64a100000000         mov eax, dword ptr fs:[0]
// 008d9fe5  50                   push eax
// 008d9fe6  64892500000000       mov dword ptr fs:[0], esp
// 008d9fed  83ec4c               sub esp, 0x4c
// 008d9ff0  53                   push ebx
// 008d9ff1  56                   push esi
// 008d9ff2  8bf1                 mov esi, ecx
// 008d9ff4  8b460c               mov eax, dword ptr [esi + 0xc]
// 008d9ff7  57                   push edi
// 008d9ff8  8965f0               mov dword ptr [ebp - 0x10], esp
// 008d9ffb  897550               mov dword ptr [ebp + 0x50], esi
// 008d9ffe  85c0                 test eax, eax
// 008da000  7505                 jne 0x8da007
// 008da002  894558               mov dword ptr [ebp + 0x58], eax
// 008da005  eb19                 jmp 0x8da020
// 008da007  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 008da00a  2bc8                 sub ecx, eax
// 008da00c  b8398ee338           mov eax, 0x38e38e39
// 008da011  f7e9                 imul ecx
// 008da013  c1fa04               sar edx, 4
// 008da016  8bc2                 mov eax, edx
// 008da018  c1e81f               shr eax, 0x1f
// 008da01b  03c2                 add eax, edx
// 008da01d  894558               mov dword ptr [ebp + 0x58], eax
// 008da020  8b7d6c               mov edi, dword ptr [ebp + 0x6c]
// 008da023  85ff                 test edi, edi
// 008da025  0f84db020000         je 0x8da306
// 008da02b  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008da02e  8bcb                 mov ecx, ebx
// 008da030  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 008da033  b8398ee338           mov eax, 0x38e38e39
// 008da038  f7e9                 imul ecx
// 008da03a  c1fa04               sar edx, 4
// 008da03d  8bc2                 mov eax, edx
// 008da03f  c1e81f               shr eax, 0x1f
// 008da042  03c2                 add eax, edx
// 008da044  b9e3388e03           mov ecx, 0x38e38e3
// 008da049  2bc8                 sub ecx, eax
// 008da04b  3bcf                 cmp ecx, edi
// 008da04d  7305                 jae 0x8da054
// 008da04f  e89c9db4ff           call 0x423df0
// 008da054  8b4d58               mov ecx, dword ptr [ebp + 0x58]
// 008da057  03c7                 add eax, edi
// 008da059  3bc8                 cmp ecx, eax
// 008da05b  0f837a010000         jae 0x8da1db
// 008da061  8bd1                 mov edx, ecx
// 008da063  d1ea                 shr edx, 1
// 008da065  bbe3388e03           mov ebx, 0x38e38e3
// 008da06a  2bda                 sub ebx, edx
// 008da06c  3bd9                 cmp ebx, ecx
// 008da06e  730c                 jae 0x8da07c
// 008da070  c7455800000000       mov dword ptr [ebp + 0x58], 0
// 008da077  8b4d58               mov ecx, dword ptr [ebp + 0x58]
// 008da07a  eb05                 jmp 0x8da081
// 008da07c  03ca                 add ecx, edx
// 008da07e  894d58               mov dword ptr [ebp + 0x58], ecx
// 008da081  3bc8                 cmp ecx, eax
// 008da083  7305                 jae 0x8da08a
// 008da085  894558               mov dword ptr [ebp + 0x58], eax
// 008da088  8bc8                 mov ecx, eax
// 008da08a  6a00                 push 0
// 008da08c  51                   push ecx
// 008da08d  e8de480100           call 0x8ee970
// 008da092  8b5568               mov edx, dword ptr [ebp + 0x68]
// 008da095  2b560c               sub edx, dword ptr [esi + 0xc]
// 008da098  8bc8                 mov ecx, eax
// 008da09a  b8398ee338           mov eax, 0x38e38e39
// 008da09f  f7ea                 imul edx
// 008da0a1  c1fa04               sar edx, 4
// 008da0a4  8bda                 mov ebx, edx
// 008da0a6  33c0                 xor eax, eax
// 008da0a8  83c408               add esp, 8
// 008da0ab  c1eb1f               shr ebx, 0x1f
// 008da0ae  03da                 add ebx, edx
// 008da0b0  8b5570               mov edx, dword ptr [ebp + 0x70]
// 008da0b3  89454c               mov dword ptr [ebp + 0x4c], eax
// 008da0b6  8945fc               mov dword ptr [ebp - 4], eax
// 008da0b9  52                   push edx
// 008da0ba  894d54               mov dword ptr [ebp + 0x54], ecx
// 008da0bd  8d04db               lea eax, [ebx + ebx*8]
// 008da0c0  8d0cc1               lea ecx, [ecx + eax*8]
// 008da0c3  57                   push edi
// 008da0c4  51                   push ecx
// 008da0c5  8bce                 mov ecx, esi
// 008da0c7  895d48               mov dword ptr [ebp + 0x48], ebx
// 008da0ca  e8a1efffff           call 0x8d9070
// 008da0cf  8b460c               mov eax, dword ptr [esi + 0xc]
// 008da0d2  c6457000             mov byte ptr [ebp + 0x70], 0
// 008da0d6  8b5570               mov edx, dword ptr [ebp + 0x70]
// 008da0d9  52                   push edx
// 008da0da  8b556c               mov edx, dword ptr [ebp + 0x6c]
// 008da0dd  52                   push edx
// 008da0de  8b5568               mov edx, dword ptr [ebp + 0x68]
// 008da0e1  8d4e08               lea ecx, [esi + 8]
// 008da0e4  51                   push ecx
// 008da0e5  8b4d54               mov ecx, dword ptr [ebp + 0x54]
// 008da0e8  51                   push ecx
// 008da0e9  52                   push edx
// 008da0ea  50                   push eax
// 008da0eb  c7454c01000000       mov dword ptr [ebp + 0x4c], 1
// 008da0f2  e869e6ffff           call 0x8d8760
// 008da0f7  8b5554               mov edx, dword ptr [ebp + 0x54]
// 008da0fa  8b4610               mov eax, dword ptr [esi + 0x10]
// 008da0fd  83c418               add esp, 0x18
// 008da100  03df                 add ebx, edi
// 008da102  8d0cdb               lea ecx, [ebx + ebx*8]
// 008da105  8d0cca               lea ecx, [edx + ecx*8]
// 008da108  c6457000             mov byte ptr [ebp + 0x70], 0
// 008da10c  8b5570               mov edx, dword ptr [ebp + 0x70]
// 008da10f  52                   push edx
// 008da110  8b556c               mov edx, dword ptr [ebp + 0x6c]
// 008da113  52                   push edx
// 008da114  8d5608               lea edx, [esi + 8]
// 008da117  52                   push edx
// 008da118  51                   push ecx
// 008da119  50                   push eax
// 008da11a  8b4568               mov eax, dword ptr [ebp + 0x68]
// 008da11d  50                   push eax
// 008da11e  c7454c02000000       mov dword ptr [ebp + 0x4c], 2
// 008da125  e836e6ffff           call 0x8d8760
// 008da12a  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008da12d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008da130  2bcb                 sub ecx, ebx
// 008da132  b8398ee338           mov eax, 0x38e38e39
// 008da137  f7e9                 imul ecx
// 008da139  c1fa04               sar edx, 4
// 008da13c  8bca                 mov ecx, edx
// 008da13e  c1e91f               shr ecx, 0x1f
// 008da141  03ca                 add ecx, edx
// 008da143  83c418               add esp, 0x18
// 008da146  03f9                 add edi, ecx
// 008da148  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 008da14f  85db                 test ebx, ebx
// 008da151  7418                 je 0x8da16b
// 008da153  8b5610               mov edx, dword ptr [esi + 0x10]
// 008da156  52                   push edx
// 008da157  53                   push ebx
// 008da158  8bce                 mov ecx, esi
// 008da15a  e851efffff           call 0x8d90b0
// 008da15f  8b460c               mov eax, dword ptr [esi + 0xc]
// 008da162  50                   push eax
// 008da163  e832d8ecff           call 0x7a799a
// 008da168  83c404               add esp, 4
// 008da16b  8b4558               mov eax, dword ptr [ebp + 0x58]
// 008da16e  8d0cc0               lea ecx, [eax + eax*8]
// 008da171  8b4554               mov eax, dword ptr [ebp + 0x54]
// 008da174  8d14c8               lea edx, [eax + ecx*8]
// 008da177  8d0cff               lea ecx, [edi + edi*8]
// 008da17a  895614               mov dword ptr [esi + 0x14], edx
// 008da17d  8d14c8               lea edx, [eax + ecx*8]
// 008da180  895610               mov dword ptr [esi + 0x10], edx
// 008da183  89460c               mov dword ptr [esi + 0xc], eax
// 008da186  e97b010000           jmp 0x8da306
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ?_Insert_n@?$vector@UPMWorkingData@ProgressiveMesh@Ogre@@V?$allocator@UPMWorkingData@ProgressiveMesh@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@UPMWorkingData@ProgressiveMesh@Ogre@@V?$allocator@UPMWorkingData@ProgressiveMesh@Ogre@@@std@@@2@IABUPMWorkingData@ProgressiveMesh@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
