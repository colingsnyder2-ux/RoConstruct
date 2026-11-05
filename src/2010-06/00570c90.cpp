// from server: 100% by auto
// roc 2010-06 00570c90  unit: G3D::LineSegment  size: 2860 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00570c90
//
// 00570c90  83ec30               sub esp, 0x30
// 00570c93  8b442438             mov eax, dword ptr [esp + 0x38]
// 00570c97  53                   push ebx
// 00570c98  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 00570c9c  8a8b25010000         mov cl, byte ptr [ebx + 0x125]
// 00570ca2  0fb693f9010000       movzx edx, byte ptr [ebx + 0x1f9]
// 00570ca9  55                   push ebp
// 00570caa  8b6804               mov ebp, dword ptr [eax + 4]
// 00570cad  56                   push esi
// 00570cae  57                   push edi
// 00570caf  0fb6780b             movzx edi, byte ptr [eax + 0xb]
// 00570cb3  8b83e8000000         mov eax, dword ptr [ebx + 0xe8]
// 00570cb9  83c707               add edi, 7
// 00570cbc  c1ff03               sar edi, 3
// 00570cbf  8944242c             mov dword ptr [esp + 0x2c], eax
// 00570cc3  8b83ec000000         mov eax, dword ptr [ebx + 0xec]
// 00570cc9  884c2413             mov byte ptr [esp + 0x13], cl
// 00570ccd  896c2414             mov dword ptr [esp + 0x14], ebp
// 00570cd1  89542448             mov dword ptr [esp + 0x48], edx
// 00570cd5  897c2424             mov dword ptr [esp + 0x24], edi
// 00570cd9  89442418             mov dword ptr [esp + 0x18], eax
// 00570cdd  89442428             mov dword ptr [esp + 0x28], eax
// 00570ce1  c744241cffffff7f     mov dword ptr [esp + 0x1c], 0x7fffffff
// 00570ce9  f6c108               test cl, 8
// 00570cec  0f84bd000000         je 0x570daf
// 00570cf2  80f908               cmp cl, 8
// 00570cf5  0f84b4000000         je 0x570daf
// 00570cfb  33c0                 xor eax, eax
// 00570cfd  33d2                 xor edx, edx
// 00570cff  85ed                 test ebp, ebp
// 00570d01  7630                 jbe 0x570d33
// 00570d03  eb0b                 jmp 0x570d10
// 00570d05  8da42400000000       lea esp, [esp]
// 00570d0c  8d642400             lea esp, [esp]
// 00570d10  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00570d14  0fb6741101           movzx esi, byte ptr [ecx + edx + 1]
// 00570d19  81fe80000000         cmp esi, 0x80
// 00570d1f  7d04                 jge 0x570d25
// 00570d21  8bce                 mov ecx, esi
// 00570d23  eb07                 jmp 0x570d2c
// 00570d25  b900010000           mov ecx, 0x100
// 00570d2a  2bce                 sub ecx, esi
// 00570d2c  42                   inc edx
// 00570d2d  03c1                 add eax, ecx
// 00570d2f  3bd5                 cmp edx, ebp
// 00570d31  72dd                 jb 0x570d10
// 00570d33  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00570d3a  756f                 jne 0x570dab
// 00570d3c  0fb7f0               movzx esi, ax
// 00570d3f  c1e80a               shr eax, 0xa
// 00570d42  25c0ff3f00           and eax, 0x3fffc0
// 00570d47  33c9                 xor ecx, ecx
// 00570d49  394c2448             cmp dword ptr [esp + 0x48], ecx
// 00570d4d  8bd0                 mov edx, eax
// 00570d4f  7e2f                 jle 0x570d80
// 00570d51  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00570d57  803c0800             cmp byte ptr [eax + ecx], 0
// 00570d5b  751c                 jne 0x570d79
// 00570d5d  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 00570d63  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00570d67  8be8                 mov ebp, eax
// 00570d69  0fafc2               imul eax, edx
// 00570d6c  0fafee               imul ebp, esi
// 00570d6f  c1ed08               shr ebp, 8
// 00570d72  c1e808               shr eax, 8
// 00570d75  8bf5                 mov esi, ebp
// 00570d77  8bd0                 mov edx, eax
// 00570d79  41                   inc ecx
// 00570d7a  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 00570d7e  7cd1                 jl 0x570d51
// 00570d80  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 00570d86  0fb701               movzx eax, word ptr [ecx]
// 00570d89  8bc8                 mov ecx, eax
// 00570d8b  0fafca               imul ecx, edx
// 00570d8e  c1e903               shr ecx, 3
// 00570d91  81f9c0ff3f00         cmp ecx, 0x3fffc0
// 00570d97  7607                 jbe 0x570da0
// 00570d99  b8ffffff7f           mov eax, 0x7fffffff
// 00570d9e  eb0b                 jmp 0x570dab
// 00570da0  0fafc6               imul eax, esi
// 00570da3  c1e803               shr eax, 3
// 00570da6  c1e10a               shl ecx, 0xa
// 00570da9  03c1                 add eax, ecx
// 00570dab  8944241c             mov dword ptr [esp + 0x1c], eax
// 00570daf  8a442413             mov al, byte ptr [esp + 0x13]
// 00570db3  3c10                 cmp al, 0x10
// 00570db5  0f85dc000000         jne 0x570e97
// 00570dbb  8b742418             mov esi, dword ptr [esp + 0x18]
// 00570dbf  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 00570dc5  46                   inc esi
// 00570dc6  33ed                 xor ebp, ebp
// 00570dc8  40                   inc eax
// 00570dc9  8bce                 mov ecx, esi
// 00570dcb  85ff                 test edi, edi
// 00570dcd  760d                 jbe 0x570ddc
// 00570dcf  8bef                 mov ebp, edi
// 00570dd1  8a11                 mov dl, byte ptr [ecx]
// 00570dd3  8810                 mov byte ptr [eax], dl
// 00570dd5  41                   inc ecx
// 00570dd6  40                   inc eax
// 00570dd7  83ef01               sub edi, 1
// 00570dda  75f5                 jne 0x570dd1
// 00570ddc  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 00570de0  7314                 jae 0x570df6
// 00570de2  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00570de6  2bfd                 sub edi, ebp
// 00570de8  8a11                 mov dl, byte ptr [ecx]
// 00570dea  2a16                 sub dl, byte ptr [esi]
// 00570dec  41                   inc ecx
// 00570ded  8810                 mov byte ptr [eax], dl
// 00570def  46                   inc esi
// 00570df0  40                   inc eax
// 00570df1  83ef01               sub edi, 1
// 00570df4  75f2                 jne 0x570de8
// 00570df6  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 00570dfc  89442418             mov dword ptr [esp + 0x18], eax
// 00570e00  f644241320           test byte ptr [esp + 0x13], 0x20
// 00570e05  0f841f040000         je 0x57122a
// 00570e0b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00570e0f  33ff                 xor edi, edi
// 00570e11  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00570e18  894c2430             mov dword ptr [esp + 0x30], ecx
// 00570e1c  0f8514030000         jne 0x571136
// 00570e22  0fb7f1               movzx esi, cx
// 00570e25  c1e90a               shr ecx, 0xa
// 00570e28  33d2                 xor edx, edx
// 00570e2a  81e1c0ff3f00         and ecx, 0x3fffc0
// 00570e30  39542448             cmp dword ptr [esp + 0x48], edx
// 00570e34  89742434             mov dword ptr [esp + 0x34], esi
// 00570e38  7e33                 jle 0x570e6d
// 00570e3a  8babfc010000         mov ebp, dword ptr [ebx + 0x1fc]
// 00570e40  803c2a02             cmp byte ptr [edx + ebp], 2
// 00570e44  7520                 jne 0x570e66
// 00570e46  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 00570e4c  0fb70450             movzx eax, word ptr [eax + edx*2]
// 00570e50  8bf0                 mov esi, eax
// 00570e52  0fafc1               imul eax, ecx
// 00570e55  0faf742434           imul esi, dword ptr [esp + 0x34]
// 00570e5a  c1ee08               shr esi, 8
// 00570e5d  c1e808               shr eax, 8
// 00570e60  89742434             mov dword ptr [esp + 0x34], esi
// 00570e64  8bc8                 mov ecx, eax
// 00570e66  42                   inc edx
// 00570e67  3b542448             cmp edx, dword ptr [esp + 0x48]
// 00570e6b  7cd3                 jl 0x570e40
// 00570e6d  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 00570e73  0fb75204             movzx edx, word ptr [edx + 4]
// 00570e77  8bc2                 mov eax, edx
// 00570e79  0fafc1               imul eax, ecx
// 00570e7c  c1e803               shr eax, 3
// 00570e7f  3dc0ff3f00           cmp eax, 0x3fffc0
// 00570e84  0f869d020000         jbe 0x571127
// 00570e8a  c7442430ffffff7f     mov dword ptr [esp + 0x30], 0x7fffffff
// 00570e92  e99f020000           jmp 0x571136
// 00570e97  a810                 test al, 0x10
// 00570e99  0f84ac010000         je 0x57104b
// 00570e9f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00570ea3  33ff                 xor edi, edi
// 00570ea5  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00570eac  894c2430             mov dword ptr [esp + 0x30], ecx
// 00570eb0  757f                 jne 0x570f31
// 00570eb2  0fb7f1               movzx esi, cx
// 00570eb5  c1e90a               shr ecx, 0xa
// 00570eb8  81e1c0ff3f00         and ecx, 0x3fffc0
// 00570ebe  33d2                 xor edx, edx
// 00570ec0  397c2448             cmp dword ptr [esp + 0x48], edi
// 00570ec4  7e39                 jle 0x570eff
// 00570ec6  eb08                 jmp 0x570ed0
// 00570ec8  8da42400000000       lea esp, [esp]
// 00570ecf  90                   nop 
// 00570ed0  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00570ed6  803c1001             cmp byte ptr [eax + edx], 1
// 00570eda  751c                 jne 0x570ef8
// 00570edc  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 00570ee2  0fb70450             movzx eax, word ptr [eax + edx*2]
// 00570ee6  8be8                 mov ebp, eax
// 00570ee8  0fafc1               imul eax, ecx
// 00570eeb  0fafee               imul ebp, esi
// 00570eee  c1ed08               shr ebp, 8
// 00570ef1  c1e808               shr eax, 8
// 00570ef4  8bf5                 mov esi, ebp
// 00570ef6  8bc8                 mov ecx, eax
// 00570ef8  42                   inc edx
// 00570ef9  3b542448             cmp edx, dword ptr [esp + 0x48]
// 00570efd  7cd1                 jl 0x570ed0
// 00570eff  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 00570f05  0fb75202             movzx edx, word ptr [edx + 2]
// 00570f09  8bc2                 mov eax, edx
// 00570f0b  0fafc1               imul eax, ecx
// 00570f0e  c1e803               shr eax, 3
// 00570f11  3dc0ff3f00           cmp eax, 0x3fffc0
// 00570f16  760a                 jbe 0x570f22
// 00570f18  c7442430ffffff7f     mov dword ptr [esp + 0x30], 0x7fffffff
// 00570f20  eb0f                 jmp 0x570f31
// 00570f22  0fafd6               imul edx, esi
// 00570f25  c1ea03               shr edx, 3
// 00570f28  c1e00a               shl eax, 0xa
// 00570f2b  03d0                 add edx, eax
// 00570f2d  89542430             mov dword ptr [esp + 0x30], edx
// 00570f31  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00570f35  8b8bf0000000         mov ecx, dword ptr [ebx + 0xf0]
// 00570f3b  8b442424             mov eax, dword ptr [esp + 0x24]
// 00570f3f  45                   inc ebp
// 00570f40  41                   inc ecx
// 00570f41  897c2420             mov dword ptr [esp + 0x20], edi
// 00570f45  896c2438             mov dword ptr [esp + 0x38], ebp
// 00570f49  8bd5                 mov edx, ebp
// 00570f4b  85c0                 test eax, eax
// 00570f4d  762d                 jbe 0x570f7c
// 00570f4f  8be8                 mov ebp, eax
// 00570f51  89442420             mov dword ptr [esp + 0x20], eax
// 00570f55  8a02                 mov al, byte ptr [edx]
// 00570f57  0fb6f0               movzx esi, al
// 00570f5a  81fe80000000         cmp esi, 0x80
// 00570f60  8801                 mov byte ptr [ecx], al
// 00570f62  7d04                 jge 0x570f68
// 00570f64  8bc6                 mov eax, esi
// 00570f66  eb07                 jmp 0x570f6f
// 00570f68  b800010000           mov eax, 0x100
// 00570f6d  2bc6                 sub eax, esi
// 00570f6f  03f8                 add edi, eax
// 00570f71  42                   inc edx
// 00570f72  41                   inc ecx
// 00570f73  83ed01               sub ebp, 1
// 00570f76  75dd                 jne 0x570f55
// 00570f78  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 00570f7c  8b442414             mov eax, dword ptr [esp + 0x14]
// 00570f80  39442420             cmp dword ptr [esp + 0x20], eax
// 00570f84  7336                 jae 0x570fbc
// 00570f86  8a02                 mov al, byte ptr [edx]
// 00570f88  2a4500               sub al, byte ptr [ebp]
// 00570f8b  8801                 mov byte ptr [ecx], al
// 00570f8d  0fb6c0               movzx eax, al
// 00570f90  3d80000000           cmp eax, 0x80
// 00570f95  7d04                 jge 0x570f9b
// 00570f97  8bf0                 mov esi, eax
// 00570f99  eb07                 jmp 0x570fa2
// 00570f9b  be00010000           mov esi, 0x100
// 00570fa0  2bf0                 sub esi, eax
// 00570fa2  03fe                 add edi, esi
// 00570fa4  3b7c2430             cmp edi, dword ptr [esp + 0x30]
// 00570fa8  7712                 ja 0x570fbc
// 00570faa  8b442420             mov eax, dword ptr [esp + 0x20]
// 00570fae  40                   inc eax
// 00570faf  42                   inc edx
// 00570fb0  45                   inc ebp
// 00570fb1  41                   inc ecx
// 00570fb2  89442420             mov dword ptr [esp + 0x20], eax
// 00570fb6  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00570fba  72ca                 jb 0x570f86
// 00570fbc  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00570fc3  7572                 jne 0x571037
// 00570fc5  0fb7f7               movzx esi, di
// 00570fc8  c1ef0a               shr edi, 0xa
// 00570fcb  81e7c0ff3f00         and edi, 0x3fffc0
// 00570fd1  33c9                 xor ecx, ecx
// 00570fd3  394c2448             cmp dword ptr [esp + 0x48], ecx
// 00570fd7  8bd7                 mov edx, edi
// 00570fd9  7e2f                 jle 0x57100a
// 00570fdb  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 00570fe1  803c0f01             cmp byte ptr [edi + ecx], 1
// 00570fe5  751c                 jne 0x571003
// 00570fe7  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 00570fed  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00570ff1  8be8                 mov ebp, eax
// 00570ff3  0fafc2               imul eax, edx
// 00570ff6  0fafee               imul ebp, esi
// 00570ff9  c1ed08               shr ebp, 8
// 00570ffc  c1e808               shr eax, 8
// 00570fff  8bf5                 mov esi, ebp
// 00571001  8bd0                 mov edx, eax
// 00571003  41                   inc ecx
// 00571004  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 00571008  7cd7                 jl 0x570fe1
// 0057100a  8b8b0c020000         mov ecx, dword ptr [ebx + 0x20c]
// 00571010  0fb74902             movzx ecx, word ptr [ecx + 2]
// 00571014  8bc1                 mov eax, ecx
// 00571016  0fafc2               imul eax, edx
// 00571019  c1e803               shr eax, 3
// 0057101c  3dc0ff3f00           cmp eax, 0x3fffc0
// 00571021  7607                 jbe 0x57102a
// 00571023  bfffffff7f           mov edi, 0x7fffffff
// 00571028  eb0d                 jmp 0x571037
// 0057102a  0fafce               imul ecx, esi
// 0057102d  c1e903               shr ecx, 3
// 00571030  c1e00a               shl eax, 0xa
// 00571033  03c8                 add ecx, eax
// 00571035  8bf9                 mov edi, ecx
// 00571037  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 0057103b  730e                 jae 0x57104b
// 0057103d  8b93f0000000         mov edx, dword ptr [ebx + 0xf0]
// 00571043  897c241c             mov dword ptr [esp + 0x1c], edi
// 00571047  89542418             mov dword ptr [esp + 0x18], edx
// 0057104b  807c241320           cmp byte ptr [esp + 0x13], 0x20
// 00571050  0f85aafdffff         jne 0x570e00
// 00571056  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 0057105c  8b542428             mov edx, dword ptr [esp + 0x28]
// 00571060  33c9                 xor ecx, ecx
// 00571062  40                   inc eax
// 00571063  8d7a01               lea edi, [edx + 1]
// 00571066  394c2414             cmp dword ptr [esp + 0x14], ecx
// 0057106a  7618                 jbe 0x571084
// 0057106c  8bf7                 mov esi, edi
// 0057106e  2bf2                 sub esi, edx
// 00571070  0374242c             add esi, dword ptr [esp + 0x2c]
// 00571074  8a1439               mov dl, byte ptr [ecx + edi]
// 00571077  2a16                 sub dl, byte ptr [esi]
// 00571079  41                   inc ecx
// 0057107a  8810                 mov byte ptr [eax], dl
// 0057107c  46                   inc esi
// 0057107d  40                   inc eax
// 0057107e  3b4c2414             cmp ecx, dword ptr [esp + 0x14]
// 00571082  72f0                 jb 0x571074
// 00571084  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 0057108a  89442418             mov dword ptr [esp + 0x18], eax
// 0057108e  f644241340           test byte ptr [esp + 0x13], 0x40
// 00571093  0f840f040000         je 0x5714a8
// 00571099  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0057109d  33d2                 xor edx, edx
// 0057109f  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 005710a6  89542420             mov dword ptr [esp + 0x20], edx
// 005710aa  894c2434             mov dword ptr [esp + 0x34], ecx
// 005710ae  0f85a7020000         jne 0x57135b
// 005710b4  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 005710b8  0fb7f1               movzx esi, cx
// 005710bb  c1e90a               shr ecx, 0xa
// 005710be  81e1c0ff3f00         and ecx, 0x3fffc0
// 005710c4  3bfa                 cmp edi, edx
// 005710c6  7e35                 jle 0x5710fd
// 005710c8  eb06                 jmp 0x5710d0
// 005710ca  8d9b00000000         lea ebx, [ebx]
// 005710d0  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 005710d6  803c0203             cmp byte ptr [edx + eax], 3
// 005710da  751c                 jne 0x5710f8
// 005710dc  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 005710e2  0fb70450             movzx eax, word ptr [eax + edx*2]
// 005710e6  8be8                 mov ebp, eax
// 005710e8  0fafc1               imul eax, ecx
// 005710eb  0fafee               imul ebp, esi
// 005710ee  c1ed08               shr ebp, 8
// 005710f1  c1e808               shr eax, 8
// 005710f4  8bf5                 mov esi, ebp
// 005710f6  8bc8                 mov ecx, eax
// 005710f8  42                   inc edx
// 005710f9  3bd7                 cmp edx, edi
// 005710fb  7cd3                 jl 0x5710d0
// 005710fd  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 00571103  0fb75206             movzx edx, word ptr [edx + 6]
// 00571107  8bc2                 mov eax, edx
// 00571109  0fafc1               imul eax, ecx
// 0057110c  c1e803               shr eax, 3
// 0057110f  3dc0ff3f00           cmp eax, 0x3fffc0
// 00571114  0f8632020000         jbe 0x57134c
// 0057111a  c7442434ffffff7f     mov dword ptr [esp + 0x34], 0x7fffffff
// 00571122  e934020000           jmp 0x57135b
// 00571127  0fafd6               imul edx, esi
// 0057112a  c1ea03               shr edx, 3
// 0057112d  c1e00a               shl eax, 0xa
// 00571130  03d0                 add edx, eax
// 00571132  89542430             mov dword ptr [esp + 0x30], edx
// 00571136  8b542428             mov edx, dword ptr [esp + 0x28]
// 0057113a  8b8bf4000000         mov ecx, dword ptr [ebx + 0xf4]
// 00571140  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00571144  42                   inc edx
// 00571145  41                   inc ecx
// 00571146  40                   inc eax
// 00571147  837c241400           cmp dword ptr [esp + 0x14], 0
// 0057114c  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00571154  7640                 jbe 0x571196
// 00571156  8be8                 mov ebp, eax
// 00571158  2bea                 sub ebp, edx
// 0057115a  8d9b00000000         lea ebx, [ebx]
// 00571160  8a02                 mov al, byte ptr [edx]
// 00571162  2a042a               sub al, byte ptr [edx + ebp]
// 00571165  41                   inc ecx
// 00571166  8841ff               mov byte ptr [ecx - 1], al
// 00571169  0fb6c0               movzx eax, al
// 0057116c  42                   inc edx
// 0057116d  3d80000000           cmp eax, 0x80
// 00571172  7d04                 jge 0x571178
// 00571174  8bf0                 mov esi, eax
// 00571176  eb07                 jmp 0x57117f
// 00571178  be00010000           mov esi, 0x100
// 0057117d  2bf0                 sub esi, eax
// 0057117f  03fe                 add edi, esi
// 00571181  3b7c2430             cmp edi, dword ptr [esp + 0x30]
// 00571185  770f                 ja 0x571196
// 00571187  8b442434             mov eax, dword ptr [esp + 0x34]
// 0057118b  40                   inc eax
// 0057118c  89442434             mov dword ptr [esp + 0x34], eax
// 00571190  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00571194  72ca                 jb 0x571160
// 00571196  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0057119d  7577                 jne 0x571216
// 0057119f  0fb7f7               movzx esi, di
// 005711a2  c1ef0a               shr edi, 0xa
// 005711a5  81e7c0ff3f00         and edi, 0x3fffc0
// 005711ab  33c9                 xor ecx, ecx
// 005711ad  394c2448             cmp dword ptr [esp + 0x48], ecx
// 005711b1  8bd7                 mov edx, edi
// 005711b3  7e34                 jle 0x5711e9
// 005711b5  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 005711bb  eb03                 jmp 0x5711c0
// 005711bd  8d4900               lea ecx, [ecx]
// 005711c0  803c0f02             cmp byte ptr [edi + ecx], 2
// 005711c4  751c                 jne 0x5711e2
// 005711c6  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 005711cc  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 005711d0  8be8                 mov ebp, eax
// 005711d2  0fafc2               imul eax, edx
// 005711d5  0fafee               imul ebp, esi
// 005711d8  c1ed08               shr ebp, 8
// 005711db  c1e808               shr eax, 8
// 005711de  8bf5                 mov esi, ebp
// 005711e0  8bd0                 mov edx, eax
// 005711e2  41                   inc ecx
// 005711e3  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 005711e7  7cd7                 jl 0x5711c0
// 005711e9  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 005711ef  0fb74904             movzx ecx, word ptr [ecx + 4]
// 005711f3  8bc1                 mov eax, ecx
// 005711f5  0fafc2               imul eax, edx
// 005711f8  c1e803               shr eax, 3
// 005711fb  3dc0ff3f00           cmp eax, 0x3fffc0
// 00571200  7607                 jbe 0x571209
// 00571202  bfffffff7f           mov edi, 0x7fffffff
// 00571207  eb0d                 jmp 0x571216
// 00571209  0fafce               imul ecx, esi
// 0057120c  c1e903               shr ecx, 3
// 0057120f  c1e00a               shl eax, 0xa
// 00571212  03c8                 add ecx, eax
// 00571214  8bf9                 mov edi, ecx
// 00571216  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 0057121a  730e                 jae 0x57122a
// 0057121c  8b93f4000000         mov edx, dword ptr [ebx + 0xf4]
// 00571222  897c241c             mov dword ptr [esp + 0x1c], edi
// 00571226  89542418             mov dword ptr [esp + 0x18], edx
// 0057122a  807c241340           cmp byte ptr [esp + 0x13], 0x40
// 0057122f  0f8559feffff         jne 0x57108e
// 00571235  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 00571239  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 0057123f  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00571243  8b542424             mov edx, dword ptr [esp + 0x24]
// 00571247  45                   inc ebp
// 00571248  33c0                 xor eax, eax
// 0057124a  41                   inc ecx
// 0057124b  46                   inc esi
// 0057124c  8bfd                 mov edi, ebp
// 0057124e  85d2                 test edx, edx
// 00571250  7626                 jbe 0x571278
// 00571252  89542444             mov dword ptr [esp + 0x44], edx
// 00571256  89542438             mov dword ptr [esp + 0x38], edx
// 0057125a  8d9b00000000         lea ebx, [ebx]
// 00571260  8a06                 mov al, byte ptr [esi]
// 00571262  8a17                 mov dl, byte ptr [edi]
// 00571264  d0e8                 shr al, 1
// 00571266  2ad0                 sub dl, al
// 00571268  8811                 mov byte ptr [ecx], dl
// 0057126a  41                   inc ecx
// 0057126b  46                   inc esi
// 0057126c  47                   inc edi
// 0057126d  836c244401           sub dword ptr [esp + 0x44], 1
// 00571272  75ec                 jne 0x571260
// 00571274  8b442438             mov eax, dword ptr [esp + 0x38]
// 00571278  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0057127c  7331                 jae 0x5712af
// 0057127e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00571282  2bd0                 sub edx, eax
// 00571284  89542444             mov dword ptr [esp + 0x44], edx
// 00571288  eb06                 jmp 0x571290
// 0057128a  8d9b00000000         lea ebx, [ebx]
// 00571290  0fb65500             movzx edx, byte ptr [ebp]
// 00571294  0fb606               movzx eax, byte ptr [esi]
// 00571297  03c2                 add eax, edx
// 00571299  99                   cdq 
// 0057129a  2bc2                 sub eax, edx
// 0057129c  8a17                 mov dl, byte ptr [edi]
// 0057129e  d1f8                 sar eax, 1
// 005712a0  2ad0                 sub dl, al
// 005712a2  8811                 mov byte ptr [ecx], dl
// 005712a4  41                   inc ecx
// 005712a5  45                   inc ebp
// 005712a6  46                   inc esi
// 005712a7  47                   inc edi
// 005712a8  836c244401           sub dword ptr [esp + 0x44], 1
// 005712ad  75e1                 jne 0x571290
// 005712af  8b83f8000000         mov eax, dword ptr [ebx + 0xf8]
// 005712b5  89442418             mov dword ptr [esp + 0x18], eax
// 005712b9  f644241380           test byte ptr [esp + 0x13], 0x80
// 005712be  0f84a6040000         je 0x57176a
// 005712c4  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005712c8  33ed                 xor ebp, ebp
// 005712ca  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 005712d1  896c2430             mov dword ptr [esp + 0x30], ebp
// 005712d5  894c2420             mov dword ptr [esp + 0x20], ecx
// 005712d9  0f85c7020000         jne 0x5715a6
// 005712df  0fb7f1               movzx esi, cx
// 005712e2  c1e90a               shr ecx, 0xa
// 005712e5  33d2                 xor edx, edx
// 005712e7  81e1c0ff3f00         and ecx, 0x3fffc0
// 005712ed  39542448             cmp dword ptr [esp + 0x48], edx
// 005712f1  7e2f                 jle 0x571322
// 005712f3  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 005712f9  803c0204             cmp byte ptr [edx + eax], 4
// 005712fd  751c                 jne 0x57131b
// 005712ff  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 00571305  0fb70450             movzx eax, word ptr [eax + edx*2]
// 00571309  8bf8                 mov edi, eax
// 0057130b  0fafc1               imul eax, ecx
// 0057130e  0faffe               imul edi, esi
// 00571311  c1ef08               shr edi, 8
// 00571314  c1e808               shr eax, 8
// 00571317  8bf7                 mov esi, edi
// 00571319  8bc8                 mov ecx, eax
// 0057131b  42                   inc edx
// 0057131c  3b542448             cmp edx, dword ptr [esp + 0x48]
// 00571320  7cd1                 jl 0x5712f3
// 00571322  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 00571328  0fb75208             movzx edx, word ptr [edx + 8]
// 0057132c  8bc2                 mov eax, edx
// 0057132e  0fafc1               imul eax, ecx
// 00571331  c1e803               shr eax, 3
// 00571334  3dc0ff3f00           cmp eax, 0x3fffc0
// 00571339  0f8658020000         jbe 0x571597
// 0057133f  c7442420ffffff7f     mov dword ptr [esp + 0x20], 0x7fffffff
// 00571347  e95a020000           jmp 0x5715a6
// 0057134c  0fafd6               imul edx, esi
// 0057134f  c1ea03               shr edx, 3
// 00571352  c1e00a               shl eax, 0xa
// 00571355  03d0                 add edx, eax
// 00571357  89542434             mov dword ptr [esp + 0x34], edx
// 0057135b  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0057135f  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 00571365  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00571369  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057136d  45                   inc ebp
// 0057136e  41                   inc ecx
// 0057136f  46                   inc esi
// 00571370  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00571378  8bfd                 mov edi, ebp
// 0057137a  85c0                 test eax, eax
// 0057137c  7635                 jbe 0x5713b3
// 0057137e  89442438             mov dword ptr [esp + 0x38], eax
// 00571382  89442430             mov dword ptr [esp + 0x30], eax
// 00571386  8a16                 mov dl, byte ptr [esi]
// 00571388  8a07                 mov al, byte ptr [edi]
// 0057138a  d0ea                 shr dl, 1
// 0057138c  2ac2                 sub al, dl
// 0057138e  8801                 mov byte ptr [ecx], al
// 00571390  0fb6c0               movzx eax, al
// 00571393  41                   inc ecx
// 00571394  46                   inc esi
// 00571395  47                   inc edi
// 00571396  3d80000000           cmp eax, 0x80
// 0057139b  7d04                 jge 0x5713a1
// 0057139d  8bd0                 mov edx, eax
// 0057139f  eb07                 jmp 0x5713a8
// 005713a1  ba00010000           mov edx, 0x100
// 005713a6  2bd0                 sub edx, eax
// 005713a8  01542420             add dword ptr [esp + 0x20], edx
// 005713ac  836c243801           sub dword ptr [esp + 0x38], 1
// 005713b1  75d3                 jne 0x571386
// 005713b3  8b442414             mov eax, dword ptr [esp + 0x14]
// 005713b7  39442430             cmp dword ptr [esp + 0x30], eax
// 005713bb  7351                 jae 0x57140e
// 005713bd  8d4900               lea ecx, [ecx]
// 005713c0  0fb616               movzx edx, byte ptr [esi]
// 005713c3  0fb64500             movzx eax, byte ptr [ebp]
// 005713c7  03c2                 add eax, edx
// 005713c9  99                   cdq 
// 005713ca  2bc2                 sub eax, edx
// 005713cc  8bd0                 mov edx, eax
// 005713ce  8a07                 mov al, byte ptr [edi]
// 005713d0  d1fa                 sar edx, 1
// 005713d2  2ac2                 sub al, dl
// 005713d4  8801                 mov byte ptr [ecx], al
// 005713d6  0fb6c0               movzx eax, al
// 005713d9  41                   inc ecx
// 005713da  45                   inc ebp
// 005713db  46                   inc esi
// 005713dc  47                   inc edi
// 005713dd  3d80000000           cmp eax, 0x80
// 005713e2  7d04                 jge 0x5713e8
// 005713e4  8bd0                 mov edx, eax
// 005713e6  eb07                 jmp 0x5713ef
// 005713e8  ba00010000           mov edx, 0x100
// 005713ed  2bd0                 sub edx, eax
// 005713ef  8b442420             mov eax, dword ptr [esp + 0x20]
// 005713f3  03c2                 add eax, edx
// 005713f5  89442420             mov dword ptr [esp + 0x20], eax
// 005713f9  3b442434             cmp eax, dword ptr [esp + 0x34]
// 005713fd  770f                 ja 0x57140e
// 005713ff  8b442430             mov eax, dword ptr [esp + 0x30]
// 00571403  40                   inc eax
// 00571404  89442430             mov dword ptr [esp + 0x30], eax
// 00571408  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0057140c  72b2                 jb 0x5713c0
// 0057140e  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00571415  7579                 jne 0x571490
// 00571417  8b542420             mov edx, dword ptr [esp + 0x20]
// 0057141b  0fb7f2               movzx esi, dx
// 0057141e  c1ea0a               shr edx, 0xa
// 00571421  33c9                 xor ecx, ecx
// 00571423  81e2c0ff3f00         and edx, 0x3fffc0
// 00571429  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0057142d  7e2f                 jle 0x57145e
// 0057142f  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 00571435  803c3900             cmp byte ptr [ecx + edi], 0
// 00571439  751c                 jne 0x571457
// 0057143b  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 00571441  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00571445  8be8                 mov ebp, eax
// 00571447  0fafc2               imul eax, edx
// 0057144a  0fafee               imul ebp, esi
// 0057144d  c1ed08               shr ebp, 8
// 00571450  c1e808               shr eax, 8
// 00571453  8bf5                 mov esi, ebp
// 00571455  8bd0                 mov edx, eax
// 00571457  41                   inc ecx
// 00571458  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0057145c  7cd7                 jl 0x571435
// 0057145e  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 00571464  0fb74906             movzx ecx, word ptr [ecx + 6]
// 00571468  8bc1                 mov eax, ecx
// 0057146a  0fafc2               imul eax, edx
// 0057146d  c1e803               shr eax, 3
// 00571470  3dc0ff3f00           cmp eax, 0x3fffc0
// 00571475  760a                 jbe 0x571481
// 00571477  c7442420ffffff7f     mov dword ptr [esp + 0x20], 0x7fffffff
// 0057147f  eb0f                 jmp 0x571490
// 00571481  0fafce               imul ecx, esi
// 00571484  c1e903               shr ecx, 3
// 00571487  c1e00a               shl eax, 0xa
// 0057148a  03c8                 add ecx, eax
// 0057148c  894c2420             mov dword ptr [esp + 0x20], ecx
// 00571490  8b442420             mov eax, dword ptr [esp + 0x20]
// 00571494  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 00571498  730e                 jae 0x5714a8
// 0057149a  8b93f8000000         mov edx, dword ptr [ebx + 0xf8]
// 005714a0  8944241c             mov dword ptr [esp + 0x1c], eax
// 005714a4  89542418             mov dword ptr [esp + 0x18], edx
// 005714a8  807c241380           cmp byte ptr [esp + 0x13], 0x80
// 005714ad  0f8506feffff         jne 0x5712b9
// 005714b3  8b442428             mov eax, dword ptr [esp + 0x28]
// 005714b7  8bbbfc000000         mov edi, dword ptr [ebx + 0xfc]
// 005714bd  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 005714c1  40                   inc eax
// 005714c2  42                   inc edx
// 005714c3  47                   inc edi
// 005714c4  837c242400           cmp dword ptr [esp + 0x24], 0
// 005714c9  c744243400000000     mov dword ptr [esp + 0x34], 0
// 005714d1  8bc8                 mov ecx, eax
// 005714d3  89442430             mov dword ptr [esp + 0x30], eax
// 005714d7  8bf2                 mov esi, edx
// 005714d9  761b                 jbe 0x5714f6
// 005714db  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 005714df  896c2434             mov dword ptr [esp + 0x34], ebp
// 005714e3  8a19                 mov bl, byte ptr [ecx]
// 005714e5  2a1e                 sub bl, byte ptr [esi]
// 005714e7  47                   inc edi
// 005714e8  885fff               mov byte ptr [edi - 1], bl
// 005714eb  46                   inc esi
// 005714ec  41                   inc ecx
// 005714ed  83ed01               sub ebp, 1
// 005714f0  75f1                 jne 0x5714e3
// 005714f2  894c2430             mov dword ptr [esp + 0x30], ecx
// 005714f6  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005714fa  8be8                 mov ebp, eax
// 005714fc  395c2434             cmp dword ptr [esp + 0x34], ebx
// 00571500  0f8388000000         jae 0x57158e
// 00571506  8bca                 mov ecx, edx
// 00571508  2bc8                 sub ecx, eax
// 0057150a  2b5c2434             sub ebx, dword ptr [esp + 0x34]
// 0057150e  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00571512  895c2434             mov dword ptr [esp + 0x34], ebx
// 00571516  eb0c                 jmp 0x571524
// 00571518  eb06                 jmp 0x571520
// 0057151a  8d9b00000000         lea ebx, [ebx]
// 00571520  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00571524  0fb61429             movzx edx, byte ptr [ecx + ebp]
// 00571528  0fb606               movzx eax, byte ptr [esi]
// 0057152b  0fb64d00             movzx ecx, byte ptr [ebp]
// 0057152f  89442424             mov dword ptr [esp + 0x24], eax
// 00571533  894c2428             mov dword ptr [esp + 0x28], ecx
// 00571537  2bc2                 sub eax, edx
// 00571539  46                   inc esi
// 0057153a  45                   inc ebp
// 0057153b  2bca                 sub ecx, edx
// 0057153d  85c0                 test eax, eax
// 0057153f  7d0a                 jge 0x57154b
// 00571541  8bd8                 mov ebx, eax
// 00571543  f7db                 neg ebx
// 00571545  895c2438             mov dword ptr [esp + 0x38], ebx
// 00571549  eb04                 jmp 0x57154f
// 0057154b  89442438             mov dword ptr [esp + 0x38], eax
// 0057154f  8bd9                 mov ebx, ecx
// 00571551  85c9                 test ecx, ecx
// 00571553  7d02                 jge 0x571557
// 00571555  f7db                 neg ebx
// 00571557  03c1                 add eax, ecx
// 00571559  7902                 jns 0x57155d
// 0057155b  f7d8                 neg eax
// 0057155d  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00571561  3bcb                 cmp ecx, ebx
// 00571563  7f0a                 jg 0x57156f
// 00571565  3bc8                 cmp ecx, eax
// 00571567  7f06                 jg 0x57156f
// 00571569  8b542428             mov edx, dword ptr [esp + 0x28]
// 0057156d  eb08                 jmp 0x571577
// 0057156f  3bd8                 cmp ebx, eax
// 00571571  7f04                 jg 0x571577
// 00571573  8b542424             mov edx, dword ptr [esp + 0x24]
// 00571577  8b442430             mov eax, dword ptr [esp + 0x30]
// 0057157b  8a08                 mov cl, byte ptr [eax]
// 0057157d  2aca                 sub cl, dl
// 0057157f  880f                 mov byte ptr [edi], cl
// 00571581  40                   inc eax
// 00571582  47                   inc edi
// 00571583  836c243401           sub dword ptr [esp + 0x34], 1
// 00571588  89442430             mov dword ptr [esp + 0x30], eax
// 0057158c  7592                 jne 0x571520
// 0057158e  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 00571592  e9c9010000           jmp 0x571760
// 00571597  0fafd6               imul edx, esi
// 0057159a  c1ea03               shr edx, 3
// 0057159d  c1e00a               shl eax, 0xa
// 005715a0  03d0                 add edx, eax
// 005715a2  89542420             mov dword ptr [esp + 0x20], edx
// 005715a6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005715aa  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 005715ae  8bb3fc000000         mov esi, dword ptr [ebx + 0xfc]
// 005715b4  8b442424             mov eax, dword ptr [esp + 0x24]
// 005715b8  47                   inc edi
// 005715b9  42                   inc edx
// 005715ba  46                   inc esi
// 005715bb  c744244400000000     mov dword ptr [esp + 0x44], 0
// 005715c3  897c2428             mov dword ptr [esp + 0x28], edi
// 005715c7  897c2434             mov dword ptr [esp + 0x34], edi
// 005715cb  8954242c             mov dword ptr [esp + 0x2c], edx
// 005715cf  85c0                 test eax, eax
// 005715d1  763d                 jbe 0x571610
// 005715d3  89442438             mov dword ptr [esp + 0x38], eax
// 005715d7  89442444             mov dword ptr [esp + 0x44], eax
// 005715db  eb03                 jmp 0x5715e0
// 005715dd  8d4900               lea ecx, [ecx]
// 005715e0  8a07                 mov al, byte ptr [edi]
// 005715e2  2a02                 sub al, byte ptr [edx]
// 005715e4  46                   inc esi
// 005715e5  8846ff               mov byte ptr [esi - 1], al
// 005715e8  0fb6c0               movzx eax, al
// 005715eb  42                   inc edx
// 005715ec  47                   inc edi
// 005715ed  3d80000000           cmp eax, 0x80
// 005715f2  7d04                 jge 0x5715f8
// 005715f4  8bc8                 mov ecx, eax
// 005715f6  eb07                 jmp 0x5715ff
// 005715f8  b900010000           mov ecx, 0x100
// 005715fd  2bc8                 sub ecx, eax
// 005715ff  03e9                 add ebp, ecx
// 00571601  836c243801           sub dword ptr [esp + 0x38], 1
// 00571606  75d8                 jne 0x5715e0
// 00571608  896c2430             mov dword ptr [esp + 0x30], ebp
// 0057160c  897c2434             mov dword ptr [esp + 0x34], edi
// 00571610  8b442444             mov eax, dword ptr [esp + 0x44]
// 00571614  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00571618  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0057161c  0f83b8000000         jae 0x5716da
// 00571622  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00571626  2bf9                 sub edi, ecx
// 00571628  897c242c             mov dword ptr [esp + 0x2c], edi
// 0057162c  eb0e                 jmp 0x57163c
// 0057162e  8bff                 mov edi, edi
// 00571630  8b542428             mov edx, dword ptr [esp + 0x28]
// 00571634  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00571638  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0057163c  0fb602               movzx eax, byte ptr [edx]
// 0057163f  42                   inc edx
// 00571640  89542428             mov dword ptr [esp + 0x28], edx
// 00571644  0fb6140f             movzx edx, byte ptr [edi + ecx]
// 00571648  0fb639               movzx edi, byte ptr [ecx]
// 0057164b  41                   inc ecx
// 0057164c  894c2424             mov dword ptr [esp + 0x24], ecx
// 00571650  8944243c             mov dword ptr [esp + 0x3c], eax
// 00571654  8bcf                 mov ecx, edi
// 00571656  2bc2                 sub eax, edx
// 00571658  2bca                 sub ecx, edx
// 0057165a  85c0                 test eax, eax
// 0057165c  7d0a                 jge 0x571668
// 0057165e  8be8                 mov ebp, eax
// 00571660  f7dd                 neg ebp
// 00571662  896c2438             mov dword ptr [esp + 0x38], ebp
// 00571666  eb04                 jmp 0x57166c
// 00571668  89442438             mov dword ptr [esp + 0x38], eax
// 0057166c  8be9                 mov ebp, ecx
// 0057166e  85c9                 test ecx, ecx
// 00571670  7d02                 jge 0x571674
// 00571672  f7dd                 neg ebp
// 00571674  03c1                 add eax, ecx
// 00571676  7902                 jns 0x57167a
// 00571678  f7d8                 neg eax
// 0057167a  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0057167e  3bcd                 cmp ecx, ebp
// 00571680  7f08                 jg 0x57168a
// 00571682  3bc8                 cmp ecx, eax
// 00571684  7f04                 jg 0x57168a
// 00571686  8bd7                 mov edx, edi
// 00571688  eb08                 jmp 0x571692
// 0057168a  3be8                 cmp ebp, eax
// 0057168c  7f04                 jg 0x571692
// 0057168e  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00571692  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00571696  8a01                 mov al, byte ptr [ecx]
// 00571698  2ac2                 sub al, dl
// 0057169a  8806                 mov byte ptr [esi], al
// 0057169c  0fb6c0               movzx eax, al
// 0057169f  41                   inc ecx
// 005716a0  46                   inc esi
// 005716a1  3d80000000           cmp eax, 0x80
// 005716a6  894c2434             mov dword ptr [esp + 0x34], ecx
// 005716aa  7d04                 jge 0x5716b0
// 005716ac  8bc8                 mov ecx, eax
// 005716ae  eb07                 jmp 0x5716b7
// 005716b0  b900010000           mov ecx, 0x100
// 005716b5  2bc8                 sub ecx, eax
// 005716b7  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 005716bb  03e9                 add ebp, ecx
// 005716bd  896c2430             mov dword ptr [esp + 0x30], ebp
// 005716c1  3b6c2420             cmp ebp, dword ptr [esp + 0x20]
// 005716c5  7713                 ja 0x5716da
// 005716c7  8b442444             mov eax, dword ptr [esp + 0x44]
// 005716cb  40                   inc eax
// 005716cc  89442444             mov dword ptr [esp + 0x44], eax
// 005716d0  3b442414             cmp eax, dword ptr [esp + 0x14]
// 005716d4  0f8256ffffff         jb 0x571630
// 005716da  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 005716e1  7577                 jne 0x57175a
// 005716e3  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 005716e7  0fb7f5               movzx esi, bp
// 005716ea  c1ed0a               shr ebp, 0xa
// 005716ed  81e5c0ff3f00         and ebp, 0x3fffc0
// 005716f3  33c9                 xor ecx, ecx
// 005716f5  8bd5                 mov edx, ebp
// 005716f7  85ff                 test edi, edi
// 005716f9  7e32                 jle 0x57172d
// 005716fb  eb03                 jmp 0x571700
// 005716fd  8d4900               lea ecx, [ecx]
// 00571700  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00571706  803c0104             cmp byte ptr [ecx + eax], 4
// 0057170a  751c                 jne 0x571728
// 0057170c  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 00571712  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00571716  8be8                 mov ebp, eax
// 00571718  0fafc2               imul eax, edx
// 0057171b  0fafee               imul ebp, esi
// 0057171e  c1ed08               shr ebp, 8
// 00571721  c1e808               shr eax, 8
// 00571724  8bf5                 mov esi, ebp
// 00571726  8bd0                 mov edx, eax
// 00571728  41                   inc ecx
// 00571729  3bcf                 cmp ecx, edi
// 0057172b  7cd3                 jl 0x571700
// 0057172d  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 00571733  0fb74908             movzx ecx, word ptr [ecx + 8]
// 00571737  8bc1                 mov eax, ecx
// 00571739  0fafc2               imul eax, edx
// 0057173c  c1e803               shr eax, 3
// 0057173f  3dc0ff3f00           cmp eax, 0x3fffc0
// 00571744  7607                 jbe 0x57174d
// 00571746  bdffffff7f           mov ebp, 0x7fffffff
// 0057174b  eb0d                 jmp 0x57175a
// 0057174d  0fafce               imul ecx, esi
// 00571750  c1e903               shr ecx, 3
// 00571753  c1e00a               shl eax, 0xa
// 00571756  03c8                 add ecx, eax
// 00571758  8be9                 mov ebp, ecx
// 0057175a  3b6c241c             cmp ebp, dword ptr [esp + 0x1c]
// 0057175e  730a                 jae 0x57176a
// 00571760  8b93fc000000         mov edx, dword ptr [ebx + 0xfc]
// 00571766  89542418             mov dword ptr [esp + 0x18], edx
// 0057176a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0057176e  50                   push eax
// 0057176f  53                   push ebx
// 00571770  e83bf4ffff           call 0x570bb0
// 00571775  83c408               add esp, 8
// 00571778  80bbf901000000       cmp byte ptr [ebx + 0x1f9], 0
// 0057177f  7633                 jbe 0x5717b4
// 00571781  b801000000           mov eax, 1
// 00571786  39442448             cmp dword ptr [esp + 0x48], eax
// 0057178a  7e19                 jle 0x5717a5
// 0057178c  8d642400             lea esp, [esp]
// 00571790  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 00571796  8a5401ff             mov dl, byte ptr [ecx + eax - 1]
// 0057179a  03c8                 add ecx, eax
// 0057179c  40                   inc eax
// 0057179d  3b442448             cmp eax, dword ptr [esp + 0x48]
// 005717a1  8811                 mov byte ptr [ecx], dl
// 005717a3  7ceb                 jl 0x571790
// 005717a5  8b542418             mov edx, dword ptr [esp + 0x18]
// 005717a9  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 005717af  8a12                 mov dl, byte ptr [edx]
// 005717b1  881408               mov byte ptr [eax + ecx], dl
// 005717b4  5f                   pop edi
// 005717b5  5e                   pop esi
// 005717b6  5d                   pop ebp
// 005717b7  5b                   pop ebx
// 005717b8  83c430               add esp, 0x30
// 005717bb  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_find_filter)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
