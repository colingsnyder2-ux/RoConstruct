// from server: 81% by EspClaude
// from server: 100% by coldek
// roc 2008-06 00654d20  unit: RBX::ScoreHud  size: 1214 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00654d20
//
// 00654d20  64a100000000         mov eax, dword ptr fs:[0]
// 00654d26  6aff                 push -1
// 00654d28  683aba7d00           push 0x7dba3a
// 00654d2d  50                   push eax
// 00654d2e  64892500000000       mov dword ptr fs:[0], esp
// 00654d35  8b8950010000         mov ecx, dword ptr [ecx + 0x150]
// 00654d3b  83ec50               sub esp, 0x50
// 00654d3e  53                   push ebx
// 00654d3f  55                   push ebp
// 00654d40  56                   push esi
// 00654d41  57                   push edi
// 00654d42  33ff                 xor edi, edi
// 00654d44  3bcf                 cmp ecx, edi
// 00654d46  0f84eb030000         je 0x655137
// 00654d4c  8d442420             lea eax, [esp + 0x20]
// 00654d50  50                   push eax
// 00654d51  e86a27e4ff           call 0x4974c0
// 00654d56  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00654d5a  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00654d5d  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 00654d60  8b742470             mov esi, dword ptr [esp + 0x70]
// 00654d64  c1f903               sar ecx, 3
// 00654d67  897c2468             mov dword ptr [esp + 0x68], edi
// 00654d6b  897c2410             mov dword ptr [esp + 0x10], edi
// 00654d6f  85c9                 test ecx, ecx
// 00654d71  0f86ab020000         jbe 0x655022
// 00654d77  897c2470             mov dword ptr [esp + 0x70], edi
// 00654d7b  eb07                 jmp 0x654d84
// 00654d7d  8d4900               lea ecx, [ecx]
// 00654d80  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00654d84  57                   push edi
// 00654d85  8bcd                 mov ecx, ebp
// 00654d87  e8c4c4ffff           call 0x651250
// 00654d8c  8b18                 mov ebx, dword ptr [eax]
// 00654d8e  6818bd8400           push 0x84bd18
// 00654d93  8d4c242c             lea ecx, [esp + 0x2c]
// 00654d97  895c2418             mov dword ptr [esp + 0x18], ebx
// 00654d9b  ff1558248000         call dword ptr [0x802458]
// 00654da1  8d542428             lea edx, [esp + 0x28]
// 00654da5  52                   push edx
// 00654da6  8bcb                 mov ecx, ebx
// 00654da8  c644246c01           mov byte ptr [esp + 0x6c], 1
// 00654dad  e89e2bf0ff           call 0x557950
// 00654db2  8d4c2428             lea ecx, [esp + 0x28]
// 00654db6  8bd8                 mov ebx, eax
// 00654db8  c644246800           mov byte ptr [esp + 0x68], 0
// 00654dbd  ff1568248000         call dword ptr [0x802468]
// 00654dc3  85db                 test ebx, ebx
// 00654dc5  0f8481030000         je 0x65514c
// 00654dcb  8b8b08010000         mov ecx, dword ptr [ebx + 0x108]
// 00654dd1  85c9                 test ecx, ecx
// 00654dd3  740b                 je 0x654de0
// 00654dd5  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00654dd8  2b410c               sub eax, dword ptr [ecx + 0xc]
// 00654ddb  c1f803               sar eax, 3
// 00654dde  eb02                 jmp 0x654de2
// 00654de0  33c0                 xor eax, eax
// 00654de2  40                   inc eax
// 00654de3  50                   push eax
// 00654de4  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00654de7  2b450c               sub eax, dword ptr [ebp + 0xc]
// 00654dea  8bce                 mov ecx, esi
// 00654dec  c1f803               sar eax, 3
// 00654def  50                   push eax
// 00654df0  e83bf8ffff           call 0x654630
// 00654df5  6a00                 push 0
// 00654df7  83ec1c               sub esp, 0x1c
// 00654dfa  8bcc                 mov ecx, esp
// 00654dfc  89642438             mov dword ptr [esp + 0x38], esp
// 00654e00  68ac398400           push 0x8439ac
// 00654e05  ff1558248000         call dword ptr [0x802458]
// 00654e0b  8bce                 mov ecx, esi
// 00654e0d  e8dec0ffff           call 0x650ef0
// 00654e12  8bcb                 mov ecx, ebx
// 00654e14  33ff                 xor edi, edi
// 00654e16  e80560e3ff           call 0x48ae20
// 00654e1b  85c0                 test eax, eax
// 00654e1d  7654                 jbe 0x654e73
// 00654e1f  90                   nop 
// 00654e20  8bab08010000         mov ebp, dword ptr [ebx + 0x108]
// 00654e26  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00654e29  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 00654e2c  8d4701               lea eax, [edi + 1]
// 00654e2f  c1f903               sar ecx, 3
// 00654e32  89442418             mov dword ptr [esp + 0x18], eax
// 00654e36  50                   push eax
// 00654e37  3bf9                 cmp edi, ecx
// 00654e39  7206                 jb 0x654e41
// 00654e3b  ff1590288000         call dword ptr [0x802890]
// 00654e41  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00654e44  8b3cfa               mov edi, dword ptr [edx + edi*8]
// 00654e47  83ec1c               sub esp, 0x1c
// 00654e4a  81c710010000         add edi, 0x110
// 00654e50  8bcc                 mov ecx, esp
// 00654e52  8964243c             mov dword ptr [esp + 0x3c], esp
// 00654e56  57                   push edi
// 00654e57  ff155c248000         call dword ptr [0x80245c]
// 00654e5d  8bce                 mov ecx, esi
// 00654e5f  e88cc0ffff           call 0x650ef0
// 00654e64  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00654e68  8bcb                 mov ecx, ebx
// 00654e6a  e8b15fe3ff           call 0x48ae20
// 00654e6f  3bf8                 cmp edi, eax
// 00654e71  72ad                 jb 0x654e20
// 00654e73  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00654e76  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00654e79  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00654e7e  f7e9                 imul ecx
// 00654e80  c1fa02               sar edx, 2
// 00654e83  8bc2                 mov eax, edx
// 00654e85  c1e81f               shr eax, 0x1f
// 00654e88  03c2                 add eax, edx
// 00654e8a  39442410             cmp dword ptr [esp + 0x10], eax
// 00654e8e  7206                 jb 0x654e96
// 00654e90  ff1590288000         call dword ptr [0x802890]
// 00654e96  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00654e99  037c2470             add edi, dword ptr [esp + 0x70]
// 00654e9d  b893244992           mov eax, 0x92492493
// 00654ea2  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00654ea5  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 00654ea8  f7e9                 imul ecx
// 00654eaa  03d1                 add edx, ecx
// 00654eac  c1fa04               sar edx, 4
// 00654eaf  8bca                 mov ecx, edx
// 00654eb1  c1e91f               shr ecx, 0x1f
// 00654eb4  03ca                 add ecx, edx
// 00654eb6  7506                 jne 0x654ebe
// 00654eb8  ff1590288000         call dword ptr [0x802890]
// 00654ebe  8b542414             mov edx, dword ptr [esp + 0x14]
// 00654ec2  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00654ec5  81c210010000         add edx, 0x110
// 00654ecb  52                   push edx
// 00654ecc  ff150c248000         call dword ptr [0x80240c]
// 00654ed2  8bcb                 mov ecx, ebx
// 00654ed4  33ed                 xor ebp, ebp
// 00654ed6  e8455fe3ff           call 0x48ae20
// 00654edb  85c0                 test eax, eax
// 00654edd  0f861c010000         jbe 0x654fff
// 00654ee3  c74424141c000000     mov dword ptr [esp + 0x14], 0x1c
// 00654eeb  8bbb08010000         mov edi, dword ptr [ebx + 0x108]
// 00654ef1  8b4710               mov eax, dword ptr [edi + 0x10]
// 00654ef4  2b470c               sub eax, dword ptr [edi + 0xc]
// 00654ef7  c1f803               sar eax, 3
// 00654efa  3be8                 cmp ebp, eax
// 00654efc  7206                 jb 0x654f04
// 00654efe  ff1590288000         call dword ptr [0x802890]
// 00654f04  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00654f07  8b04e9               mov eax, dword ptr [ecx + ebp*8]
// 00654f0a  6a00                 push 0
// 00654f0c  68780f9600           push 0x960f78
// 00654f11  687c909200           push 0x92907c
// 00654f16  6a00                 push 0
// 00654f18  50                   push eax
// 00654f19  e8a8c80400           call 0x6a17c6
// 00654f1e  8bbb08010000         mov edi, dword ptr [ebx + 0x108]
// 00654f24  8b5710               mov edx, dword ptr [edi + 0x10]
// 00654f27  2b570c               sub edx, dword ptr [edi + 0xc]
// 00654f2a  83c414               add esp, 0x14
// 00654f2d  c1fa03               sar edx, 3
// 00654f30  3bea                 cmp ebp, edx
// 00654f32  7206                 jb 0x654f3a
// 00654f34  ff1590288000         call dword ptr [0x802890]
// 00654f3a  8b470c               mov eax, dword ptr [edi + 0xc]
// 00654f3d  8b04e8               mov eax, dword ptr [eax + ebp*8]
// 00654f40  85c0                 test eax, eax
// 00654f42  7405                 je 0x654f49
// 00654f44  83c014               add eax, 0x14
// 00654f47  eb02                 jmp 0x654f4b
// 00654f49  33c0                 xor eax, eax
// 00654f4b  8b0d9cd39700         mov ecx, dword ptr [0x97d39c]
// 00654f51  8b11                 mov edx, dword ptr [ecx]
// 00654f53  50                   push eax
// 00654f54  8b4208               mov eax, dword ptr [edx + 8]
// 00654f57  ffd0                 call eax
// 00654f59  8d4c2418             lea ecx, [esp + 0x18]
// 00654f5d  51                   push ecx
// 00654f5e  8d542448             lea edx, [esp + 0x48]
// 00654f62  52                   push edx
// 00654f63  89442420             mov dword ptr [esp + 0x20], eax
// 00654f67  e864c9eaff           call 0x5018d0
// 00654f6c  83c408               add esp, 8
// 00654f6f  89442418             mov dword ptr [esp + 0x18], eax
// 00654f73  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00654f76  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00654f79  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00654f7e  f7e9                 imul ecx
// 00654f80  c1fa02               sar edx, 2
// 00654f83  8bc2                 mov eax, edx
// 00654f85  c1e81f               shr eax, 0x1f
// 00654f88  03c2                 add eax, edx
// 00654f8a  c644246802           mov byte ptr [esp + 0x68], 2
// 00654f8f  39442410             cmp dword ptr [esp + 0x10], eax
// 00654f93  7206                 jb 0x654f9b
// 00654f95  ff1590288000         call dword ptr [0x802890]
// 00654f9b  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00654f9e  037c2470             add edi, dword ptr [esp + 0x70]
// 00654fa2  b893244992           mov eax, 0x92492493
// 00654fa7  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00654faa  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 00654fad  45                   inc ebp
// 00654fae  f7e9                 imul ecx
// 00654fb0  03d1                 add edx, ecx
// 00654fb2  c1fa04               sar edx, 4
// 00654fb5  8bca                 mov ecx, edx
// 00654fb7  c1e91f               shr ecx, 0x1f
// 00654fba  03ca                 add ecx, edx
// 00654fbc  3be9                 cmp ebp, ecx
// 00654fbe  7206                 jb 0x654fc6
// 00654fc0  ff1590288000         call dword ptr [0x802890]
// 00654fc6  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00654fc9  8b542418             mov edx, dword ptr [esp + 0x18]
// 00654fcd  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00654fd1  52                   push edx
// 00654fd2  03cf                 add ecx, edi
// 00654fd4  ff150c248000         call dword ptr [0x80240c]
// 00654fda  8d4c2444             lea ecx, [esp + 0x44]
// 00654fde  c644246800           mov byte ptr [esp + 0x68], 0
// 00654fe3  ff1568248000         call dword ptr [0x802468]
// 00654fe9  83c71c               add edi, 0x1c
// 00654fec  8bcb                 mov ecx, ebx
// 00654fee  897c2414             mov dword ptr [esp + 0x14], edi
// 00654ff2  e8295ee3ff           call 0x48ae20
// 00654ff7  3be8                 cmp ebp, eax
// 00654ff9  0f82ecfeffff         jb 0x654eeb
// 00654fff  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00655003  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00655006  2b550c               sub edx, dword ptr [ebp + 0xc]
// 00655009  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065500d  8344247018           add dword ptr [esp + 0x70], 0x18
// 00655012  40                   inc eax
// 00655013  c1fa03               sar edx, 3
// 00655016  89442410             mov dword ptr [esp + 0x10], eax
// 0065501a  3bc2                 cmp eax, edx
// 0065501c  0f825efdffff         jb 0x654d80
// 00655022  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00655025  2b450c               sub eax, dword ptr [ebp + 0xc]
// 00655028  33db                 xor ebx, ebx
// 0065502a  c1f803               sar eax, 3
// 0065502d  85c0                 test eax, eax
// 0065502f  0f86c8000000         jbe 0x6550fd
// 00655035  895c2470             mov dword ptr [esp + 0x70], ebx
// 00655039  8da42400000000       lea esp, [esp]
// 00655040  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00655043  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00655046  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0065504b  f7e9                 imul ecx
// 0065504d  c1fa02               sar edx, 2
// 00655050  8bca                 mov ecx, edx
// 00655052  c1e91f               shr ecx, 0x1f
// 00655055  03ca                 add ecx, edx
// 00655057  3bd9                 cmp ebx, ecx
// 00655059  7206                 jb 0x655061
// 0065505b  ff1590288000         call dword ptr [0x802890]
// 00655061  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00655064  037c2470             add edi, dword ptr [esp + 0x70]
// 00655068  b893244992           mov eax, 0x92492493
// 0065506d  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00655070  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 00655073  f7e9                 imul ecx
// 00655075  03d1                 add edx, ecx
// 00655077  c1fa04               sar edx, 4
// 0065507a  8bc2                 mov eax, edx
// 0065507c  c1e81f               shr eax, 0x1f
// 0065507f  03c2                 add eax, edx
// 00655081  7506                 jne 0x655089
// 00655083  ff1590288000         call dword ptr [0x802890]
// 00655089  8b7f0c               mov edi, dword ptr [edi + 0xc]
// 0065508c  837f1410             cmp dword ptr [edi + 0x14], 0x10
// 00655090  7654                 jbe 0x6550e6
// 00655092  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00655095  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00655098  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0065509d  f7e9                 imul ecx
// 0065509f  c1fa02               sar edx, 2
// 006550a2  8bca                 mov ecx, edx
// 006550a4  c1e91f               shr ecx, 0x1f
// 006550a7  03ca                 add ecx, edx
// 006550a9  3bd9                 cmp ebx, ecx
// 006550ab  7206                 jb 0x6550b3
// 006550ad  ff1590288000         call dword ptr [0x802890]
// 006550b3  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006550b6  037c2470             add edi, dword ptr [esp + 0x70]
// 006550ba  b893244992           mov eax, 0x92492493
// 006550bf  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 006550c2  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 006550c5  f7e9                 imul ecx
// 006550c7  03d1                 add edx, ecx
// 006550c9  c1fa04               sar edx, 4
// 006550cc  8bc2                 mov eax, edx
// 006550ce  c1e81f               shr eax, 0x1f
// 006550d1  03c2                 add eax, edx
// 006550d3  7506                 jne 0x6550db
// 006550d5  ff1590288000         call dword ptr [0x802890]
// 006550db  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 006550de  6a10                 push 0x10
// 006550e0  ff15cc258000         call dword ptr [0x8025cc]
// 006550e6  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 006550e9  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 006550ec  8344247018           add dword ptr [esp + 0x70], 0x18
// 006550f1  43                   inc ebx
// 006550f2  c1f903               sar ecx, 3
// 006550f5  3bd9                 cmp ebx, ecx
// 006550f7  0f8243ffffff         jb 0x655040
// 006550fd  8b742424             mov esi, dword ptr [esp + 0x24]
// 00655101  c7442468ffffffff     mov dword ptr [esp + 0x68], 0xffffffff
// 00655109  85f6                 test esi, esi
// 0065510b  742a                 je 0x655137
// 0065510d  8d5604               lea edx, [esi + 4]
// 00655110  83c8ff               or eax, 0xffffffff
// 00655113  f00fc102             lock xadd dword ptr [edx], eax
// 00655117  751e                 jne 0x655137
// 00655119  8b16                 mov edx, dword ptr [esi]
// 0065511b  8b4204               mov eax, dword ptr [edx + 4]
// 0065511e  8bce                 mov ecx, esi
// 00655120  ffd0                 call eax
// 00655122  8d4e08               lea ecx, [esi + 8]
// 00655125  83caff               or edx, 0xffffffff
// 00655128  f00fc111             lock xadd dword ptr [ecx], edx
// 0065512c  7509                 jne 0x655137
// 0065512e  8b06                 mov eax, dword ptr [esi]
// 00655130  8b5008               mov edx, dword ptr [eax + 8]
// 00655133  8bce                 mov ecx, esi
// 00655135  ffd2                 call edx
// 00655137  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0065513b  5f                   pop edi
// 0065513c  5e                   pop esi
// 0065513d  5d                   pop ebp
// 0065513e  64890d00000000       mov dword ptr fs:[0], ecx
// 00655145  5b                   pop ebx
// 00655146  83c45c               add esp, 0x5c
// 00655149  c20400               ret 4
// 0065514c  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0065514f  2b450c               sub eax, dword ptr [ebp + 0xc]
// 00655152  6a01                 push 1
// 00655154  c1f803               sar eax, 3
// 00655157  50                   push eax
// 00655158  8bce                 mov ecx, esi
// 0065515a  e8d1f4ffff           call 0x654630
// 0065515f  6a00                 push 0
// 00655161  83ec1c               sub esp, 0x1c
// 00655164  8bcc                 mov ecx, esp
// 00655166  8964243c             mov dword ptr [esp + 0x3c], esp
// 0065516a  6824bd8400           push 0x84bd24
// 0065516f  ff1558248000         call dword ptr [0x802458]
// 00655175  8bce                 mov ecx, esi
// 00655177  e874bdffff           call 0x650ef0
// 0065517c  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0065517f  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00655182  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00655187  f7e9                 imul ecx
// 00655189  c1fa02               sar edx, 2
// 0065518c  8bca                 mov ecx, edx
// 0065518e  c1e91f               shr ecx, 0x1f
// 00655191  03ca                 add ecx, edx
// 00655193  3bf9                 cmp edi, ecx
// 00655195  7206                 jb 0x65519d
// 00655197  ff1590288000         call dword ptr [0x802890]
// 0065519d  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006551a0  037c2470             add edi, dword ptr [esp + 0x70]
// 006551a4  b893244992           mov eax, 0x92492493
// 006551a9  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 006551ac  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 006551af  f7e9                 imul ecx
// 006551b1  03d1                 add edx, ecx
// 006551b3  c1fa04               sar edx, 4
// 006551b6  8bc2                 mov eax, edx
// 006551b8  c1e81f               shr eax, 0x1f
// 006551bb  03c2                 add eax, edx
// 006551bd  7506                 jne 0x6551c5
// 006551bf  ff1590288000         call dword ptr [0x802890]
// 006551c5  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006551c9  81c110010000         add ecx, 0x110
// 006551cf  51                   push ecx
// 006551d0  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 006551d3  ff150c248000         call dword ptr [0x80240c]
// 006551d9  e925feffff           jmp 0x655003

// from server: 77% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Native ScoreHud board builder. Opaque receiver prefixes create no GUI/Instance objects or RTTI.
#include <string>
#include <vector>
#include <typeinfo>
#include <cstddef>
#include <intrin.h>
namespace boost {
class noncopyable {protected:noncopyable(){}~noncopyable(){}private:noncopyable(const noncopyable&);const noncopyable&operator=(const noncopyable&);};
namespace detail {
// Actual Boost1.34.1 Windows counted base; only unused methods are omitted.
class sp_counted_base {
 sp_counted_base(const sp_counted_base&);sp_counted_base&operator=(const sp_counted_base&);
 long use_count_,weak_count_;
public:
 sp_counted_base():use_count_(1),weak_count_(1){}
 virtual ~sp_counted_base(){}
 virtual void dispose()=0;
 virtual void destroy(){delete this;}
 virtual void*get_deleter(const std::type_info&)=0;
 void add_ref_copy(){_InterlockedIncrement(&use_count_);}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
};
class shared_count {sp_counted_base*pi_;
public:shared_count():pi_(0){}
 shared_count(const shared_count&r):pi_(r.pi_){if(pi_)pi_->add_ref_copy();}
 ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T>class shared_ptr {T*px;detail::shared_count pn;
public:shared_ptr():px(0),pn(){}
 T*get()const{return px;}T&operator*()const{return *px;}T*operator->()const{return px;}
 typedef T*shared_ptr::*unspecified_bool_type;
 operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
};
// The existing client instantiation at005018d0 is the genuine conversion boundary.
template<class Target,class Source>__declspec(noalias) Target lexical_cast(const Source&);
}
namespace RBX {
template<class T>class CopyOnWrite:public boost::noncopyable {boost::shared_ptr<T>object;
public:operator typename boost::shared_ptr<T>::unspecified_bool_type()const{return object;}
 const T&operator*()const{return *object.get();}const T*operator->()const{return object.get();}
};
class Instance;
typedef std::vector<boost::shared_ptr<Instance> >Instances;
class Instance {public:char unobserved00[0x108];CopyOnWrite<Instances>children;std::string name;
 size_t numChildren()const{return children?children->size():0;}
 Instance*getChild(size_t i){return (*children)[i].get();}
 const std::string&getName()const{return name;}
 Instance*findFirstChildByName(const std::string&)const;
};
namespace Reflection {
class DescribedBase;
template<class T>class TypedPropertyDescriptor {public:
 // Native RTTI-linked GetSet implementations prove these four actual methods.
 // Two predicate slots precede the value getter; there is no virtual destructor.
 class GetSet {public:
  virtual bool isReadOnly()const=0;
  virtual bool isWriteOnly()const=0;
  virtual T getValue(const DescribedBase*)const=0;
  virtual void setValue(DescribedBase*,const T&)const=0;
 };
};
}
// Actual pointer storage read at97d39c in IntValue's native descriptor.
extern Reflection::TypedPropertyDescriptor<int>::GetSet*nativeIntValueGetSet;
// Native Instance's actual DescribedBase subobject is at+14; preserve the null conversion.
const Reflection::DescribedBase*observedDescribedBase(const Instance*p){return p?reinterpret_cast<const Reflection::DescribedBase*>(reinterpret_cast<const char*>(p)+0x14):0;}
extern const type_info nativeInstanceType,nativeIntValueType;
extern "C" void*__cdecl __RTDynamicCast(void*,long,void*,void*,int);
namespace Network {class Players {public:__declspec(noalias) boost::shared_ptr<const Instances>getPlayers();};}
class BoardData {public:std::vector<std::vector<std::string> >data;std::vector<std::string>fields;
 void SetSize(int,int);
 void AddField(std::string,int);
};
class ScoreHud {public:char unobserved00[0x150];Network::Players*players;void BuildBoardData(BoardData&);};
typedef char native_owner_size[sizeof(boost::shared_ptr<const Instances>)==8?1:-1];
typedef char native_counted_base_size[sizeof(boost::detail::sp_counted_base)==12?1:-1];
typedef char native_cow_size[sizeof(CopyOnWrite<Instances>)==8?1:-1];
typedef char native_board_size[sizeof(BoardData)==48?1:-1];
typedef char native_instance_children[offsetof(Instance,children)==0x108?1:-1];
typedef char native_instance_name[offsetof(Instance,name)==0x110?1:-1];
typedef char native_hud_players[offsetof(ScoreHud,players)==0x150?1:-1];
void ScoreHud::BuildBoardData(BoardData&data){
 if(!players)return;
 boost::shared_ptr<const Instances>playerList=players->getPlayers();
 for(size_t i=0;i<playerList->size();++i){
  Instance*player=playerList->at(i).get();
  Instance*stats=player->findFirstChildByName("leaderstats");
  if(stats){
   data.SetSize((int)playerList->size(),(int)stats->numChildren()+1);
   data.AddField("Player",0);
   for(size_t j=0;j<stats->numChildren();++j){
    data.AddField(stats->getChild(j)->getName(),(int)j+1);
   }
   data.data[i][0]=player->getName();
   for(size_t j=0;j<stats->numChildren();++j){
    __RTDynamicCast(stats->getChild(j),0,(void*)&nativeInstanceType,(void*)&nativeIntValueType,0);
    int statValue=nativeIntValueGetSet->getValue(observedDescribedBase(stats->getChild(j)));
    data.data[i][j+1]=boost::lexical_cast<std::string>(statValue);
   }
  }else{
   data.SetSize((int)playerList->size(),1);
   data.AddField("Player List",0);
   data.data[i][0]=player->getName();
  }
 }
 for(size_t i=0;i<playerList->size();++i){
  if(data.data[i][0].size()>16)data.data[i][0].resize(16);
 }
}
}

namespace RBX {typedef char native_getset_size[sizeof(Reflection::TypedPropertyDescriptor<int>::GetSet)==4?1:-1];}
