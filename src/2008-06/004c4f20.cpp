// from server: 100% by auto
// roc 2008-06 004c4f20  unit: ProfiledRakPeer  size: 867 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c4f20
//
// 004c4f20  6aff                 push -1
// 004c4f22  68fb947c00           push 0x7c94fb
// 004c4f27  64a100000000         mov eax, dword ptr fs:[0]
// 004c4f2d  50                   push eax
// 004c4f2e  64892500000000       mov dword ptr fs:[0], esp
// 004c4f35  81ece8010000         sub esp, 0x1e8
// 004c4f3b  890c24               mov dword ptr [esp], ecx
// 004c4f3e  55                   push ebp
// 004c4f3f  8d8c24b8000000       lea ecx, [esp + 0xb8]
// 004c4f46  e81589ffff           call 0x4bd860
// 004c4f4b  8bac24fc010000       mov ebp, dword ptr [esp + 0x1fc]
// 004c4f52  83bd4808000004       cmp dword ptr [ebp + 0x848], 4
// 004c4f59  c78424f401000000000000 mov dword ptr [esp + 0x1f4], 0
// 004c4f64  0f8501030000         jne 0x4c526b
// 004c4f6a  53                   push ebx
// 004c4f6b  8b9c2404020000       mov ebx, dword ptr [esp + 0x204]
// 004c4f72  8b4315               mov eax, dword ptr [ebx + 0x15]
// 004c4f75  56                   push esi
// 004c4f76  57                   push edi
// 004c4f77  8d7319               lea esi, [ebx + 0x19]
// 004c4f7a  b908000000           mov ecx, 8
// 004c4f7f  8dbc24a4000000       lea edi, [esp + 0xa4]
// 004c4f86  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c4f88  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004c4f8c  80bf9d08000001       cmp byte ptr [edi + 0x89d], 1
// 004c4f93  89442414             mov dword ptr [esp + 0x14], eax
// 004c4f97  753f                 jne 0x4c4fd8
// 004c4f99  80bf9c08000000       cmp byte ptr [edi + 0x89c], 0
// 004c4fa0  7536                 jne 0x4c4fd8
// 004c4fa2  3b8778080000         cmp eax, dword ptr [edi + 0x878]
// 004c4fa8  0f8581010000         jne 0x4c512f
// 004c4fae  8d877c080000         lea eax, [edi + 0x87c]
// 004c4fb4  8d9424a4000000       lea edx, [esp + 0xa4]
// 004c4fbb  b920000000           mov ecx, 0x20
// 004c4fc0  2bd0                 sub edx, eax
// 004c4fc2  8b3402               mov esi, dword ptr [edx + eax]
// 004c4fc5  3b30                 cmp esi, dword ptr [eax]
// 004c4fc7  0f8562010000         jne 0x4c512f
// 004c4fcd  83e904               sub ecx, 4
// 004c4fd0  83c004               add eax, 4
// 004c4fd3  83f904               cmp ecx, 4
// 004c4fd6  73ea                 jae 0x4c4fc2
// 004c4fd8  33f6                 xor esi, esi
// 004c4fda  8d9b00000000         lea ebx, [ebx]
// 004c4fe0  e83bf10000           call 0x4d4120
// 004c4fe5  89443418             mov dword ptr [esp + esi + 0x18], eax
// 004c4fe9  83c604               add esi, 4
// 004c4fec  83fe14               cmp esi, 0x14
// 004c4fef  7cef                 jl 0x4c4fe0
// 004c4ff1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004c4ff5  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004c4ff9  33c0                 xor eax, eax
// 004c4ffb  8944242c             mov dword ptr [esp + 0x2c], eax
// 004c4fff  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004c5003  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004c5007  89442430             mov dword ptr [esp + 0x30], eax
// 004c500b  89442434             mov dword ptr [esp + 0x34], eax
// 004c500f  89442438             mov dword ptr [esp + 0x38], eax
// 004c5013  8944243c             mov dword ptr [esp + 0x3c], eax
// 004c5017  89442440             mov dword ptr [esp + 0x40], eax
// 004c501b  89442444             mov dword ptr [esp + 0x44], eax
// 004c501f  89442448             mov dword ptr [esp + 0x48], eax
// 004c5023  8b442420             mov eax, dword ptr [esp + 0x20]
// 004c5027  89542430             mov dword ptr [esp + 0x30], edx
// 004c502b  8b542428             mov edx, dword ptr [esp + 0x28]
// 004c502f  894c2438             mov dword ptr [esp + 0x38], ecx
// 004c5033  8d8c24c4000000       lea ecx, [esp + 0xc4]
// 004c503a  89442434             mov dword ptr [esp + 0x34], eax
// 004c503e  8954243c             mov dword ptr [esp + 0x3c], edx
// 004c5042  e81988ffff           call 0x4bd860
// 004c5047  8b442414             mov eax, dword ptr [esp + 0x14]
// 004c504b  898424c4000000       mov dword ptr [esp + 0xc4], eax
// 004c5052  33c0                 xor eax, eax
// 004c5054  898424c8000000       mov dword ptr [esp + 0xc8], eax
// 004c505b  898424cc000000       mov dword ptr [esp + 0xcc], eax
// 004c5062  898424d0000000       mov dword ptr [esp + 0xd0], eax
// 004c5069  898424d4000000       mov dword ptr [esp + 0xd4], eax
// 004c5070  898424d8000000       mov dword ptr [esp + 0xd8], eax
// 004c5077  898424dc000000       mov dword ptr [esp + 0xdc], eax
// 004c507e  898424e0000000       mov dword ptr [esp + 0xe0], eax
// 004c5085  b908000000           mov ecx, 8
// 004c508a  8db424a4000000       lea esi, [esp + 0xa4]
// 004c5091  8dbc24e4000000       lea edi, [esp + 0xe4]
// 004c5098  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c509a  8d8c2404010000       lea ecx, [esp + 0x104]
// 004c50a1  51                   push ecx
// 004c50a2  8d9424e8000000       lea edx, [esp + 0xe8]
// 004c50a9  52                   push edx
// 004c50aa  e841e3ffff           call 0x4c33f0
// 004c50af  8d84242c010000       lea eax, [esp + 0x12c]
// 004c50b6  50                   push eax
// 004c50b7  8d8c24f0000000       lea ecx, [esp + 0xf0]
// 004c50be  51                   push ecx
// 004c50bf  e8dcb6ffff           call 0x4c07a0
// 004c50c4  83c410               add esp, 0x10
// 004c50c7  80bc244401000000     cmp byte ptr [esp + 0x144], 0
// 004c50cf  0f84b8000000         je 0x4c518d
// 004c50d5  8d9424d8010000       lea edx, [esp + 0x1d8]
// 004c50dc  52                   push edx
// 004c50dd  8d8424cc010000       lea eax, [esp + 0x1cc]
// 004c50e4  50                   push eax
// 004c50e5  8d8c24b0010000       lea ecx, [esp + 0x1b0]
// 004c50ec  51                   push ecx
// 004c50ed  8d9424a4010000       lea edx, [esp + 0x1a4]
// 004c50f4  52                   push edx
// 004c50f5  8d8424f8010000       lea eax, [esp + 0x1f8]
// 004c50fc  50                   push eax
// 004c50fd  8d8c24cc010000       lea ecx, [esp + 0x1cc]
// 004c5104  51                   push ecx
// 004c5105  8d9424a0010000       lea edx, [esp + 0x1a0]
// 004c510c  52                   push edx
// 004c510d  8d8424e0000000       lea eax, [esp + 0xe0]
// 004c5114  50                   push eax
// 004c5115  8d4c244c             lea ecx, [esp + 0x4c]
// 004c5119  51                   push ecx
// 004c511a  8d9424a8000000       lea edx, [esp + 0xa8]
// 004c5121  52                   push edx
// 004c5122  e899e3ffff           call 0x4c34c0
// 004c5127  83c428               add esp, 0x28
// 004c512a  e983000000           jmp 0x4c51b2
// 004c512f  6a1d                 push 0x1d
// 004c5131  ff15b0288000         call dword ptr [0x8028b0]
// 004c5137  8bf0                 mov esi, eax
// 004c5139  c7460c01000000       mov dword ptr [esi + 0xc], 1
// 004c5140  c6461800             mov byte ptr [esi + 0x18], 0
// 004c5144  8d461c               lea eax, [esi + 0x1c]
// 004c5147  894614               mov dword ptr [esi + 0x14], eax
// 004c514a  c60014               mov byte ptr [eax], 0x14
// 004c514d  c7461008000000       mov dword ptr [esi + 0x10], 8
// 004c5154  8b4504               mov eax, dword ptr [ebp + 4]
// 004c5157  894604               mov dword ptr [esi + 4], eax
// 004c515a  668b4d08             mov cx, word ptr [ebp + 8]
// 004c515e  83c404               add esp, 4
// 004c5161  66894e08             mov word ptr [esi + 8], cx
// 004c5165  8b5608               mov edx, dword ptr [esi + 8]
// 004c5168  6a01                 push 1
// 004c516a  52                   push edx
// 004c516b  50                   push eax
// 004c516c  8bcf                 mov ecx, edi
// 004c516e  e8bdabffff           call 0x4bfd30
// 004c5173  56                   push esi
// 004c5174  8bcf                 mov ecx, edi
// 004c5176  668906               mov word ptr [esi], ax
// 004c5179  e85286ffff           call 0x4bd7d0
// 004c517e  c7854808000002000000 mov dword ptr [ebp + 0x848], 2
// 004c5188  e9db000000           jmp 0x4c5268
// 004c518d  8d842484000000       lea eax, [esp + 0x84]
// 004c5194  50                   push eax
// 004c5195  8d8c24e8000000       lea ecx, [esp + 0xe8]
// 004c519c  51                   push ecx
// 004c519d  8d9424cc000000       lea edx, [esp + 0xcc]
// 004c51a4  52                   push edx
// 004c51a5  8d442438             lea eax, [esp + 0x38]
// 004c51a9  50                   push eax
// 004c51aa  e8c1b6ffff           call 0x4c0870
// 004c51af  83c410               add esp, 0x10
// 004c51b2  33c0                 xor eax, eax
// 004c51b4  0fb64c0301           movzx ecx, byte ptr [ebx + eax + 1]
// 004c51b9  324c0418             xor cl, byte ptr [esp + eax + 0x18]
// 004c51bd  83c004               add eax, 4
// 004c51c0  888c281c080000       mov byte ptr [eax + ebp + 0x81c], cl
// 004c51c7  0fb65403fe           movzx edx, byte ptr [ebx + eax - 2]
// 004c51cc  32540415             xor dl, byte ptr [esp + eax + 0x15]
// 004c51d0  8894281d080000       mov byte ptr [eax + ebp + 0x81d], dl
// 004c51d7  0fb64c03ff           movzx ecx, byte ptr [ebx + eax - 1]
// 004c51dc  324c0416             xor cl, byte ptr [esp + eax + 0x16]
// 004c51e0  888c281e080000       mov byte ptr [eax + ebp + 0x81e], cl
// 004c51e7  0fb61403             movzx edx, byte ptr [ebx + eax]
// 004c51eb  32540417             xor dl, byte ptr [esp + eax + 0x17]
// 004c51ef  83f810               cmp eax, 0x10
// 004c51f2  8894281f080000       mov byte ptr [eax + ebp + 0x81f], dl
// 004c51f9  7cb9                 jl 0x4c51b4
// 004c51fb  c6853008000001       mov byte ptr [ebp + 0x830], 1
// 004c5202  8b4b05               mov ecx, dword ptr [ebx + 5]
// 004c5205  8b4301               mov eax, dword ptr [ebx + 1]
// 004c5208  8b5309               mov edx, dword ptr [ebx + 9]
// 004c520b  894c2451             mov dword ptr [esp + 0x51], ecx
// 004c520f  8b4b11               mov ecx, dword ptr [ebx + 0x11]
// 004c5212  8944244d             mov dword ptr [esp + 0x4d], eax
// 004c5216  8b430d               mov eax, dword ptr [ebx + 0xd]
// 004c5219  894c245d             mov dword ptr [esp + 0x5d], ecx
// 004c521d  c644244c06           mov byte ptr [esp + 0x4c], 6
// 004c5222  89542455             mov dword ptr [esp + 0x55], edx
// 004c5226  89442459             mov dword ptr [esp + 0x59], eax
// 004c522a  b908000000           mov ecx, 8
// 004c522f  8db42484000000       lea esi, [esp + 0x84]
// 004c5236  8d7c2461             lea edi, [esp + 0x61]
// 004c523a  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c523c  e84f450000           call 0x4c9790
// 004c5241  52                   push edx
// 004c5242  8b5508               mov edx, dword ptr [ebp + 8]
// 004c5245  50                   push eax
// 004c5246  8b4504               mov eax, dword ptr [ebp + 4]
// 004c5249  6a00                 push 0
// 004c524b  6a00                 push 0
// 004c524d  52                   push edx
// 004c524e  50                   push eax
// 004c524f  6a00                 push 0
// 004c5251  6a00                 push 0
// 004c5253  6a00                 push 0
// 004c5255  68a8010000           push 0x1a8
// 004c525a  8d4c2474             lea ecx, [esp + 0x74]
// 004c525e  51                   push ecx
// 004c525f  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004c5263  e8b8b1ffff           call 0x4c0420
// 004c5268  5f                   pop edi
// 004c5269  5e                   pop esi
// 004c526a  5b                   pop ebx
// 004c526b  8b8c24ec010000       mov ecx, dword ptr [esp + 0x1ec]
// 004c5272  5d                   pop ebp
// 004c5273  64890d00000000       mov dword ptr fs:[0], ecx
// 004c527a  81c4f4010000         add esp, 0x1f4
// 004c5280  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?SecuredConnectionConfirmation@RakPeer@@IAEXPAURemoteSystemStruct@1@PAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
