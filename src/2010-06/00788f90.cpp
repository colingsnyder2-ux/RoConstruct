// from server: 100% by auto
// roc 2010-06 00788f90  unit: RBX::HUMAN::GettingUp  size: 451 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00788f90
//
// 00788f90  55                   push ebp
// 00788f91  8bec                 mov ebp, esp
// 00788f93  6aff                 push -1
// 00788f95  6800d09a00           push 0x9ad000
// 00788f9a  64a100000000         mov eax, dword ptr fs:[0]
// 00788fa0  50                   push eax
// 00788fa1  64892500000000       mov dword ptr fs:[0], esp
// 00788fa8  83ec68               sub esp, 0x68
// 00788fab  53                   push ebx
// 00788fac  56                   push esi
// 00788fad  8bf1                 mov esi, ecx
// 00788faf  8b460c               mov eax, dword ptr [esi + 0xc]
// 00788fb2  57                   push edi
// 00788fb3  8965f0               mov dword ptr [ebp - 0x10], esp
// 00788fb6  8975e0               mov dword ptr [ebp - 0x20], esi
// 00788fb9  85c0                 test eax, eax
// 00788fbb  7505                 jne 0x788fc2
// 00788fbd  8945ec               mov dword ptr [ebp - 0x14], eax
// 00788fc0  eb19                 jmp 0x788fdb
// 00788fc2  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00788fc5  2bc8                 sub ecx, eax
// 00788fc7  b867666666           mov eax, 0x66666667
// 00788fcc  f7e9                 imul ecx
// 00788fce  c1fa04               sar edx, 4
// 00788fd1  8bc2                 mov eax, edx
// 00788fd3  c1e81f               shr eax, 0x1f
// 00788fd6  03c2                 add eax, edx
// 00788fd8  8945ec               mov dword ptr [ebp - 0x14], eax
// 00788fdb  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00788fde  85ff                 test edi, edi
// 00788fe0  0f84e1020000         je 0x7892c7
// 00788fe6  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00788fe9  8bcb                 mov ecx, ebx
// 00788feb  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00788fee  b867666666           mov eax, 0x66666667
// 00788ff3  f7e9                 imul ecx
// 00788ff5  c1fa04               sar edx, 4
// 00788ff8  8bc2                 mov eax, edx
// 00788ffa  c1e81f               shr eax, 0x1f
// 00788ffd  03c2                 add eax, edx
// 00788fff  b966666606           mov ecx, 0x6666666
// 00789004  2bc8                 sub ecx, eax
// 00789006  3bcf                 cmp ecx, edi
// 00789008  7305                 jae 0x78900f
// 0078900a  e8e1adc9ff           call 0x423df0
// 0078900f  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00789012  03c7                 add eax, edi
// 00789014  3bc8                 cmp ecx, eax
// 00789016  0f8387010000         jae 0x7891a3
// 0078901c  8bd1                 mov edx, ecx
// 0078901e  d1ea                 shr edx, 1
// 00789020  bb66666606           mov ebx, 0x6666666
// 00789025  2bda                 sub ebx, edx
// 00789027  3bd9                 cmp ebx, ecx
// 00789029  730c                 jae 0x789037
// 0078902b  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00789032  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00789035  eb05                 jmp 0x78903c
// 00789037  03ca                 add ecx, edx
// 00789039  894dec               mov dword ptr [ebp - 0x14], ecx
// 0078903c  3bc8                 cmp ecx, eax
// 0078903e  7305                 jae 0x789045
// 00789040  8945ec               mov dword ptr [ebp - 0x14], eax
// 00789043  8bc8                 mov ecx, eax
// 00789045  6a00                 push 0
// 00789047  51                   push ecx
// 00789048  e87312f2ff           call 0x6aa2c0
// 0078904d  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00789050  2b560c               sub edx, dword ptr [esi + 0xc]
// 00789053  8bc8                 mov ecx, eax
// 00789055  b867666666           mov eax, 0x66666667
// 0078905a  f7ea                 imul edx
// 0078905c  c1fa04               sar edx, 4
// 0078905f  8bda                 mov ebx, edx
// 00789061  33c0                 xor eax, eax
// 00789063  83c408               add esp, 8
// 00789066  c1eb1f               shr ebx, 0x1f
// 00789069  03da                 add ebx, edx
// 0078906b  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0078906e  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00789071  8945fc               mov dword ptr [ebp - 4], eax
// 00789074  52                   push edx
// 00789075  894de8               mov dword ptr [ebp - 0x18], ecx
// 00789078  8d049b               lea eax, [ebx + ebx*4]
// 0078907b  8d0cc1               lea ecx, [ecx + eax*8]
// 0078907e  57                   push edi
// 0078907f  51                   push ecx
// 00789080  8bce                 mov ecx, esi
// 00789082  895ddc               mov dword ptr [ebp - 0x24], ebx
// 00789085  e826faffff           call 0x788ab0
// 0078908a  8b460c               mov eax, dword ptr [esi + 0xc]
// 0078908d  c6451400             mov byte ptr [ebp + 0x14], 0
// 00789091  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00789094  52                   push edx
// 00789095  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00789098  52                   push edx
// 00789099  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0078909c  8d4e08               lea ecx, [esi + 8]
// 0078909f  51                   push ecx
// 007890a0  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 007890a3  51                   push ecx
// 007890a4  52                   push edx
// 007890a5  50                   push eax
// 007890a6  c745e401000000       mov dword ptr [ebp - 0x1c], 1
// 007890ad  e80ef0ffff           call 0x7880c0
// 007890b2  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 007890b5  8b4610               mov eax, dword ptr [esi + 0x10]
// 007890b8  83c418               add esp, 0x18
// 007890bb  03df                 add ebx, edi
// 007890bd  8d0c9b               lea ecx, [ebx + ebx*4]
// 007890c0  8d0cca               lea ecx, [edx + ecx*8]
// 007890c3  c6451400             mov byte ptr [ebp + 0x14], 0
// 007890c7  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007890ca  52                   push edx
// 007890cb  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007890ce  52                   push edx
// 007890cf  8d5608               lea edx, [esi + 8]
// 007890d2  52                   push edx
// 007890d3  51                   push ecx
// 007890d4  50                   push eax
// 007890d5  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007890d8  50                   push eax
// 007890d9  c745e402000000       mov dword ptr [ebp - 0x1c], 2
// 007890e0  e8dbefffff           call 0x7880c0
// 007890e5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 007890e8  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007890eb  2bcb                 sub ecx, ebx
// 007890ed  b867666666           mov eax, 0x66666667
// 007890f2  f7e9                 imul ecx
// 007890f4  c1fa04               sar edx, 4
// 007890f7  8bca                 mov ecx, edx
// 007890f9  c1e91f               shr ecx, 0x1f
// 007890fc  03ca                 add ecx, edx
// 007890fe  83c418               add esp, 0x18
// 00789101  03f9                 add edi, ecx
// 00789103  85db                 test ebx, ebx
// 00789105  741e                 je 0x789125
// 00789107  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0078910a  52                   push edx
// 0078910b  8d4608               lea eax, [esi + 8]
// 0078910e  50                   push eax
// 0078910f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00789112  50                   push eax
// 00789113  53                   push ebx
// 00789114  e8d7cefcff           call 0x755ff0
// 00789119  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0078911c  51                   push ecx
// 0078911d  e878e80100           call 0x7a799a
// 00789122  83c414               add esp, 0x14
// 00789125  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00789128  8d1480               lea edx, [eax + eax*4]
// 0078912b  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 0078912e  8d0cd0               lea ecx, [eax + edx*8]
// 00789131  8d14bf               lea edx, [edi + edi*4]
// 00789134  894e14               mov dword ptr [esi + 0x14], ecx
// 00789137  8d0cd0               lea ecx, [eax + edx*8]
// 0078913a  894e10               mov dword ptr [esi + 0x10], ecx
// 0078913d  89460c               mov dword ptr [esi + 0xc], eax
// 00789140  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00789143  64890d00000000       mov dword ptr fs:[0], ecx
// 0078914a  5f                   pop edi
// 0078914b  5e                   pop esi
// 0078914c  5b                   pop ebx
// 0078914d  8be5                 mov esp, ebp
// 0078914f  5d                   pop ebp
// 00789150  c21000               ret 0x10
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ?_Insert_n@?$vector@UEdgeGroup@EdgeData@Ogre@@V?$allocator@UEdgeGroup@EdgeData@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@UEdgeGroup@EdgeData@Ogre@@V?$allocator@UEdgeGroup@EdgeData@Ogre@@@std@@@2@IABUEdgeGroup@EdgeData@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
