// from server: 100% by auto
// roc 2012-06 00658ad0  unit: seg_00650000  size: 2860 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00658ad0
//
// 00658ad0  83ec30               sub esp, 0x30
// 00658ad3  8b442438             mov eax, dword ptr [esp + 0x38]
// 00658ad7  53                   push ebx
// 00658ad8  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 00658adc  8a8b25010000         mov cl, byte ptr [ebx + 0x125]
// 00658ae2  0fb693f9010000       movzx edx, byte ptr [ebx + 0x1f9]
// 00658ae9  55                   push ebp
// 00658aea  8b6804               mov ebp, dword ptr [eax + 4]
// 00658aed  56                   push esi
// 00658aee  57                   push edi
// 00658aef  0fb6780b             movzx edi, byte ptr [eax + 0xb]
// 00658af3  8b83e8000000         mov eax, dword ptr [ebx + 0xe8]
// 00658af9  83c707               add edi, 7
// 00658afc  c1ff03               sar edi, 3
// 00658aff  8944242c             mov dword ptr [esp + 0x2c], eax
// 00658b03  8b83ec000000         mov eax, dword ptr [ebx + 0xec]
// 00658b09  884c2413             mov byte ptr [esp + 0x13], cl
// 00658b0d  896c2414             mov dword ptr [esp + 0x14], ebp
// 00658b11  89542448             mov dword ptr [esp + 0x48], edx
// 00658b15  897c2424             mov dword ptr [esp + 0x24], edi
// 00658b19  89442418             mov dword ptr [esp + 0x18], eax
// 00658b1d  89442428             mov dword ptr [esp + 0x28], eax
// 00658b21  c744241cffffff7f     mov dword ptr [esp + 0x1c], 0x7fffffff
// 00658b29  f6c108               test cl, 8
// 00658b2c  0f84bd000000         je 0x658bef
// 00658b32  80f908               cmp cl, 8
// 00658b35  0f84b4000000         je 0x658bef
// 00658b3b  33c0                 xor eax, eax
// 00658b3d  33d2                 xor edx, edx
// 00658b3f  85ed                 test ebp, ebp
// 00658b41  7630                 jbe 0x658b73
// 00658b43  eb0b                 jmp 0x658b50
// 00658b45  8da42400000000       lea esp, [esp]
// 00658b4c  8d642400             lea esp, [esp]
// 00658b50  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00658b54  0fb6741101           movzx esi, byte ptr [ecx + edx + 1]
// 00658b59  81fe80000000         cmp esi, 0x80
// 00658b5f  7d04                 jge 0x658b65
// 00658b61  8bce                 mov ecx, esi
// 00658b63  eb07                 jmp 0x658b6c
// 00658b65  b900010000           mov ecx, 0x100
// 00658b6a  2bce                 sub ecx, esi
// 00658b6c  42                   inc edx
// 00658b6d  03c1                 add eax, ecx
// 00658b6f  3bd5                 cmp edx, ebp
// 00658b71  72dd                 jb 0x658b50
// 00658b73  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00658b7a  756f                 jne 0x658beb
// 00658b7c  0fb7f0               movzx esi, ax
// 00658b7f  c1e80a               shr eax, 0xa
// 00658b82  25c0ff3f00           and eax, 0x3fffc0
// 00658b87  33c9                 xor ecx, ecx
// 00658b89  394c2448             cmp dword ptr [esp + 0x48], ecx
// 00658b8d  8bd0                 mov edx, eax
// 00658b8f  7e2f                 jle 0x658bc0
// 00658b91  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00658b97  803c0800             cmp byte ptr [eax + ecx], 0
// 00658b9b  751c                 jne 0x658bb9
// 00658b9d  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 00658ba3  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00658ba7  8be8                 mov ebp, eax
// 00658ba9  0fafc2               imul eax, edx
// 00658bac  0fafee               imul ebp, esi
// 00658baf  c1ed08               shr ebp, 8
// 00658bb2  c1e808               shr eax, 8
// 00658bb5  8bf5                 mov esi, ebp
// 00658bb7  8bd0                 mov edx, eax
// 00658bb9  41                   inc ecx
// 00658bba  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 00658bbe  7cd1                 jl 0x658b91
// 00658bc0  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 00658bc6  0fb701               movzx eax, word ptr [ecx]
// 00658bc9  8bc8                 mov ecx, eax
// 00658bcb  0fafca               imul ecx, edx
// 00658bce  c1e903               shr ecx, 3
// 00658bd1  81f9c0ff3f00         cmp ecx, 0x3fffc0
// 00658bd7  7607                 jbe 0x658be0
// 00658bd9  b8ffffff7f           mov eax, 0x7fffffff
// 00658bde  eb0b                 jmp 0x658beb
// 00658be0  0fafc6               imul eax, esi
// 00658be3  c1e803               shr eax, 3
// 00658be6  c1e10a               shl ecx, 0xa
// 00658be9  03c1                 add eax, ecx
// 00658beb  8944241c             mov dword ptr [esp + 0x1c], eax
// 00658bef  8a442413             mov al, byte ptr [esp + 0x13]
// 00658bf3  3c10                 cmp al, 0x10
// 00658bf5  0f85dc000000         jne 0x658cd7
// 00658bfb  8b742418             mov esi, dword ptr [esp + 0x18]
// 00658bff  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 00658c05  46                   inc esi
// 00658c06  33ed                 xor ebp, ebp
// 00658c08  40                   inc eax
// 00658c09  8bce                 mov ecx, esi
// 00658c0b  85ff                 test edi, edi
// 00658c0d  760d                 jbe 0x658c1c
// 00658c0f  8bef                 mov ebp, edi
// 00658c11  8a11                 mov dl, byte ptr [ecx]
// 00658c13  8810                 mov byte ptr [eax], dl
// 00658c15  41                   inc ecx
// 00658c16  40                   inc eax
// 00658c17  83ef01               sub edi, 1
// 00658c1a  75f5                 jne 0x658c11
// 00658c1c  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 00658c20  7314                 jae 0x658c36
// 00658c22  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00658c26  2bfd                 sub edi, ebp
// 00658c28  8a11                 mov dl, byte ptr [ecx]
// 00658c2a  2a16                 sub dl, byte ptr [esi]
// 00658c2c  41                   inc ecx
// 00658c2d  8810                 mov byte ptr [eax], dl
// 00658c2f  46                   inc esi
// 00658c30  40                   inc eax
// 00658c31  83ef01               sub edi, 1
// 00658c34  75f2                 jne 0x658c28
// 00658c36  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 00658c3c  89442418             mov dword ptr [esp + 0x18], eax
// 00658c40  f644241320           test byte ptr [esp + 0x13], 0x20
// 00658c45  0f841f040000         je 0x65906a
// 00658c4b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00658c4f  33ff                 xor edi, edi
// 00658c51  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00658c58  894c2430             mov dword ptr [esp + 0x30], ecx
// 00658c5c  0f8514030000         jne 0x658f76
// 00658c62  0fb7f1               movzx esi, cx
// 00658c65  c1e90a               shr ecx, 0xa
// 00658c68  33d2                 xor edx, edx
// 00658c6a  81e1c0ff3f00         and ecx, 0x3fffc0
// 00658c70  39542448             cmp dword ptr [esp + 0x48], edx
// 00658c74  89742434             mov dword ptr [esp + 0x34], esi
// 00658c78  7e33                 jle 0x658cad
// 00658c7a  8babfc010000         mov ebp, dword ptr [ebx + 0x1fc]
// 00658c80  803c2a02             cmp byte ptr [edx + ebp], 2
// 00658c84  7520                 jne 0x658ca6
// 00658c86  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 00658c8c  0fb70450             movzx eax, word ptr [eax + edx*2]
// 00658c90  8bf0                 mov esi, eax
// 00658c92  0fafc1               imul eax, ecx
// 00658c95  0faf742434           imul esi, dword ptr [esp + 0x34]
// 00658c9a  c1ee08               shr esi, 8
// 00658c9d  c1e808               shr eax, 8
// 00658ca0  89742434             mov dword ptr [esp + 0x34], esi
// 00658ca4  8bc8                 mov ecx, eax
// 00658ca6  42                   inc edx
// 00658ca7  3b542448             cmp edx, dword ptr [esp + 0x48]
// 00658cab  7cd3                 jl 0x658c80
// 00658cad  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 00658cb3  0fb75204             movzx edx, word ptr [edx + 4]
// 00658cb7  8bc2                 mov eax, edx
// 00658cb9  0fafc1               imul eax, ecx
// 00658cbc  c1e803               shr eax, 3
// 00658cbf  3dc0ff3f00           cmp eax, 0x3fffc0
// 00658cc4  0f869d020000         jbe 0x658f67
// 00658cca  c7442430ffffff7f     mov dword ptr [esp + 0x30], 0x7fffffff
// 00658cd2  e99f020000           jmp 0x658f76
// 00658cd7  a810                 test al, 0x10
// 00658cd9  0f84ac010000         je 0x658e8b
// 00658cdf  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00658ce3  33ff                 xor edi, edi
// 00658ce5  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00658cec  894c2430             mov dword ptr [esp + 0x30], ecx
// 00658cf0  757f                 jne 0x658d71
// 00658cf2  0fb7f1               movzx esi, cx
// 00658cf5  c1e90a               shr ecx, 0xa
// 00658cf8  81e1c0ff3f00         and ecx, 0x3fffc0
// 00658cfe  33d2                 xor edx, edx
// 00658d00  397c2448             cmp dword ptr [esp + 0x48], edi
// 00658d04  7e39                 jle 0x658d3f
// 00658d06  eb08                 jmp 0x658d10
// 00658d08  8da42400000000       lea esp, [esp]
// 00658d0f  90                   nop 
// 00658d10  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00658d16  803c1001             cmp byte ptr [eax + edx], 1
// 00658d1a  751c                 jne 0x658d38
// 00658d1c  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 00658d22  0fb70450             movzx eax, word ptr [eax + edx*2]
// 00658d26  8be8                 mov ebp, eax
// 00658d28  0fafc1               imul eax, ecx
// 00658d2b  0fafee               imul ebp, esi
// 00658d2e  c1ed08               shr ebp, 8
// 00658d31  c1e808               shr eax, 8
// 00658d34  8bf5                 mov esi, ebp
// 00658d36  8bc8                 mov ecx, eax
// 00658d38  42                   inc edx
// 00658d39  3b542448             cmp edx, dword ptr [esp + 0x48]
// 00658d3d  7cd1                 jl 0x658d10
// 00658d3f  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 00658d45  0fb75202             movzx edx, word ptr [edx + 2]
// 00658d49  8bc2                 mov eax, edx
// 00658d4b  0fafc1               imul eax, ecx
// 00658d4e  c1e803               shr eax, 3
// 00658d51  3dc0ff3f00           cmp eax, 0x3fffc0
// 00658d56  760a                 jbe 0x658d62
// 00658d58  c7442430ffffff7f     mov dword ptr [esp + 0x30], 0x7fffffff
// 00658d60  eb0f                 jmp 0x658d71
// 00658d62  0fafd6               imul edx, esi
// 00658d65  c1ea03               shr edx, 3
// 00658d68  c1e00a               shl eax, 0xa
// 00658d6b  03d0                 add edx, eax
// 00658d6d  89542430             mov dword ptr [esp + 0x30], edx
// 00658d71  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00658d75  8b8bf0000000         mov ecx, dword ptr [ebx + 0xf0]
// 00658d7b  8b442424             mov eax, dword ptr [esp + 0x24]
// 00658d7f  45                   inc ebp
// 00658d80  41                   inc ecx
// 00658d81  897c2420             mov dword ptr [esp + 0x20], edi
// 00658d85  896c2438             mov dword ptr [esp + 0x38], ebp
// 00658d89  8bd5                 mov edx, ebp
// 00658d8b  85c0                 test eax, eax
// 00658d8d  762d                 jbe 0x658dbc
// 00658d8f  8be8                 mov ebp, eax
// 00658d91  89442420             mov dword ptr [esp + 0x20], eax
// 00658d95  8a02                 mov al, byte ptr [edx]
// 00658d97  0fb6f0               movzx esi, al
// 00658d9a  81fe80000000         cmp esi, 0x80
// 00658da0  8801                 mov byte ptr [ecx], al
// 00658da2  7d04                 jge 0x658da8
// 00658da4  8bc6                 mov eax, esi
// 00658da6  eb07                 jmp 0x658daf
// 00658da8  b800010000           mov eax, 0x100
// 00658dad  2bc6                 sub eax, esi
// 00658daf  03f8                 add edi, eax
// 00658db1  42                   inc edx
// 00658db2  41                   inc ecx
// 00658db3  83ed01               sub ebp, 1
// 00658db6  75dd                 jne 0x658d95
// 00658db8  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 00658dbc  8b442414             mov eax, dword ptr [esp + 0x14]
// 00658dc0  39442420             cmp dword ptr [esp + 0x20], eax
// 00658dc4  7336                 jae 0x658dfc
// 00658dc6  8a02                 mov al, byte ptr [edx]
// 00658dc8  2a4500               sub al, byte ptr [ebp]
// 00658dcb  8801                 mov byte ptr [ecx], al
// 00658dcd  0fb6c0               movzx eax, al
// 00658dd0  3d80000000           cmp eax, 0x80
// 00658dd5  7d04                 jge 0x658ddb
// 00658dd7  8bf0                 mov esi, eax
// 00658dd9  eb07                 jmp 0x658de2
// 00658ddb  be00010000           mov esi, 0x100
// 00658de0  2bf0                 sub esi, eax
// 00658de2  03fe                 add edi, esi
// 00658de4  3b7c2430             cmp edi, dword ptr [esp + 0x30]
// 00658de8  7712                 ja 0x658dfc
// 00658dea  8b442420             mov eax, dword ptr [esp + 0x20]
// 00658dee  40                   inc eax
// 00658def  42                   inc edx
// 00658df0  45                   inc ebp
// 00658df1  41                   inc ecx
// 00658df2  89442420             mov dword ptr [esp + 0x20], eax
// 00658df6  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00658dfa  72ca                 jb 0x658dc6
// 00658dfc  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00658e03  7572                 jne 0x658e77
// 00658e05  0fb7f7               movzx esi, di
// 00658e08  c1ef0a               shr edi, 0xa
// 00658e0b  81e7c0ff3f00         and edi, 0x3fffc0
// 00658e11  33c9                 xor ecx, ecx
// 00658e13  394c2448             cmp dword ptr [esp + 0x48], ecx
// 00658e17  8bd7                 mov edx, edi
// 00658e19  7e2f                 jle 0x658e4a
// 00658e1b  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 00658e21  803c0f01             cmp byte ptr [edi + ecx], 1
// 00658e25  751c                 jne 0x658e43
// 00658e27  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 00658e2d  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00658e31  8be8                 mov ebp, eax
// 00658e33  0fafc2               imul eax, edx
// 00658e36  0fafee               imul ebp, esi
// 00658e39  c1ed08               shr ebp, 8
// 00658e3c  c1e808               shr eax, 8
// 00658e3f  8bf5                 mov esi, ebp
// 00658e41  8bd0                 mov edx, eax
// 00658e43  41                   inc ecx
// 00658e44  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 00658e48  7cd7                 jl 0x658e21
// 00658e4a  8b8b0c020000         mov ecx, dword ptr [ebx + 0x20c]
// 00658e50  0fb74902             movzx ecx, word ptr [ecx + 2]
// 00658e54  8bc1                 mov eax, ecx
// 00658e56  0fafc2               imul eax, edx
// 00658e59  c1e803               shr eax, 3
// 00658e5c  3dc0ff3f00           cmp eax, 0x3fffc0
// 00658e61  7607                 jbe 0x658e6a
// 00658e63  bfffffff7f           mov edi, 0x7fffffff
// 00658e68  eb0d                 jmp 0x658e77
// 00658e6a  0fafce               imul ecx, esi
// 00658e6d  c1e903               shr ecx, 3
// 00658e70  c1e00a               shl eax, 0xa
// 00658e73  03c8                 add ecx, eax
// 00658e75  8bf9                 mov edi, ecx
// 00658e77  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 00658e7b  730e                 jae 0x658e8b
// 00658e7d  8b93f0000000         mov edx, dword ptr [ebx + 0xf0]
// 00658e83  897c241c             mov dword ptr [esp + 0x1c], edi
// 00658e87  89542418             mov dword ptr [esp + 0x18], edx
// 00658e8b  807c241320           cmp byte ptr [esp + 0x13], 0x20
// 00658e90  0f85aafdffff         jne 0x658c40
// 00658e96  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 00658e9c  8b542428             mov edx, dword ptr [esp + 0x28]
// 00658ea0  33c9                 xor ecx, ecx
// 00658ea2  40                   inc eax
// 00658ea3  8d7a01               lea edi, [edx + 1]
// 00658ea6  394c2414             cmp dword ptr [esp + 0x14], ecx
// 00658eaa  7618                 jbe 0x658ec4
// 00658eac  8bf7                 mov esi, edi
// 00658eae  2bf2                 sub esi, edx
// 00658eb0  0374242c             add esi, dword ptr [esp + 0x2c]
// 00658eb4  8a1439               mov dl, byte ptr [ecx + edi]
// 00658eb7  2a16                 sub dl, byte ptr [esi]
// 00658eb9  41                   inc ecx
// 00658eba  8810                 mov byte ptr [eax], dl
// 00658ebc  46                   inc esi
// 00658ebd  40                   inc eax
// 00658ebe  3b4c2414             cmp ecx, dword ptr [esp + 0x14]
// 00658ec2  72f0                 jb 0x658eb4
// 00658ec4  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 00658eca  89442418             mov dword ptr [esp + 0x18], eax
// 00658ece  f644241340           test byte ptr [esp + 0x13], 0x40
// 00658ed3  0f840f040000         je 0x6592e8
// 00658ed9  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00658edd  33d2                 xor edx, edx
// 00658edf  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00658ee6  89542420             mov dword ptr [esp + 0x20], edx
// 00658eea  894c2434             mov dword ptr [esp + 0x34], ecx
// 00658eee  0f85a7020000         jne 0x65919b
// 00658ef4  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 00658ef8  0fb7f1               movzx esi, cx
// 00658efb  c1e90a               shr ecx, 0xa
// 00658efe  81e1c0ff3f00         and ecx, 0x3fffc0
// 00658f04  3bfa                 cmp edi, edx
// 00658f06  7e35                 jle 0x658f3d
// 00658f08  eb06                 jmp 0x658f10
// 00658f0a  8d9b00000000         lea ebx, [ebx]
// 00658f10  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00658f16  803c0203             cmp byte ptr [edx + eax], 3
// 00658f1a  751c                 jne 0x658f38
// 00658f1c  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 00658f22  0fb70450             movzx eax, word ptr [eax + edx*2]
// 00658f26  8be8                 mov ebp, eax
// 00658f28  0fafc1               imul eax, ecx
// 00658f2b  0fafee               imul ebp, esi
// 00658f2e  c1ed08               shr ebp, 8
// 00658f31  c1e808               shr eax, 8
// 00658f34  8bf5                 mov esi, ebp
// 00658f36  8bc8                 mov ecx, eax
// 00658f38  42                   inc edx
// 00658f39  3bd7                 cmp edx, edi
// 00658f3b  7cd3                 jl 0x658f10
// 00658f3d  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 00658f43  0fb75206             movzx edx, word ptr [edx + 6]
// 00658f47  8bc2                 mov eax, edx
// 00658f49  0fafc1               imul eax, ecx
// 00658f4c  c1e803               shr eax, 3
// 00658f4f  3dc0ff3f00           cmp eax, 0x3fffc0
// 00658f54  0f8632020000         jbe 0x65918c
// 00658f5a  c7442434ffffff7f     mov dword ptr [esp + 0x34], 0x7fffffff
// 00658f62  e934020000           jmp 0x65919b
// 00658f67  0fafd6               imul edx, esi
// 00658f6a  c1ea03               shr edx, 3
// 00658f6d  c1e00a               shl eax, 0xa
// 00658f70  03d0                 add edx, eax
// 00658f72  89542430             mov dword ptr [esp + 0x30], edx
// 00658f76  8b542428             mov edx, dword ptr [esp + 0x28]
// 00658f7a  8b8bf4000000         mov ecx, dword ptr [ebx + 0xf4]
// 00658f80  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00658f84  42                   inc edx
// 00658f85  41                   inc ecx
// 00658f86  40                   inc eax
// 00658f87  837c241400           cmp dword ptr [esp + 0x14], 0
// 00658f8c  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00658f94  7640                 jbe 0x658fd6
// 00658f96  8be8                 mov ebp, eax
// 00658f98  2bea                 sub ebp, edx
// 00658f9a  8d9b00000000         lea ebx, [ebx]
// 00658fa0  8a02                 mov al, byte ptr [edx]
// 00658fa2  2a042a               sub al, byte ptr [edx + ebp]
// 00658fa5  41                   inc ecx
// 00658fa6  8841ff               mov byte ptr [ecx - 1], al
// 00658fa9  0fb6c0               movzx eax, al
// 00658fac  42                   inc edx
// 00658fad  3d80000000           cmp eax, 0x80
// 00658fb2  7d04                 jge 0x658fb8
// 00658fb4  8bf0                 mov esi, eax
// 00658fb6  eb07                 jmp 0x658fbf
// 00658fb8  be00010000           mov esi, 0x100
// 00658fbd  2bf0                 sub esi, eax
// 00658fbf  03fe                 add edi, esi
// 00658fc1  3b7c2430             cmp edi, dword ptr [esp + 0x30]
// 00658fc5  770f                 ja 0x658fd6
// 00658fc7  8b442434             mov eax, dword ptr [esp + 0x34]
// 00658fcb  40                   inc eax
// 00658fcc  89442434             mov dword ptr [esp + 0x34], eax
// 00658fd0  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00658fd4  72ca                 jb 0x658fa0
// 00658fd6  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00658fdd  7577                 jne 0x659056
// 00658fdf  0fb7f7               movzx esi, di
// 00658fe2  c1ef0a               shr edi, 0xa
// 00658fe5  81e7c0ff3f00         and edi, 0x3fffc0
// 00658feb  33c9                 xor ecx, ecx
// 00658fed  394c2448             cmp dword ptr [esp + 0x48], ecx
// 00658ff1  8bd7                 mov edx, edi
// 00658ff3  7e34                 jle 0x659029
// 00658ff5  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 00658ffb  eb03                 jmp 0x659000
// 00658ffd  8d4900               lea ecx, [ecx]
// 00659000  803c0f02             cmp byte ptr [edi + ecx], 2
// 00659004  751c                 jne 0x659022
// 00659006  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0065900c  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00659010  8be8                 mov ebp, eax
// 00659012  0fafc2               imul eax, edx
// 00659015  0fafee               imul ebp, esi
// 00659018  c1ed08               shr ebp, 8
// 0065901b  c1e808               shr eax, 8
// 0065901e  8bf5                 mov esi, ebp
// 00659020  8bd0                 mov edx, eax
// 00659022  41                   inc ecx
// 00659023  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 00659027  7cd7                 jl 0x659000
// 00659029  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0065902f  0fb74904             movzx ecx, word ptr [ecx + 4]
// 00659033  8bc1                 mov eax, ecx
// 00659035  0fafc2               imul eax, edx
// 00659038  c1e803               shr eax, 3
// 0065903b  3dc0ff3f00           cmp eax, 0x3fffc0
// 00659040  7607                 jbe 0x659049
// 00659042  bfffffff7f           mov edi, 0x7fffffff
// 00659047  eb0d                 jmp 0x659056
// 00659049  0fafce               imul ecx, esi
// 0065904c  c1e903               shr ecx, 3
// 0065904f  c1e00a               shl eax, 0xa
// 00659052  03c8                 add ecx, eax
// 00659054  8bf9                 mov edi, ecx
// 00659056  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 0065905a  730e                 jae 0x65906a
// 0065905c  8b93f4000000         mov edx, dword ptr [ebx + 0xf4]
// 00659062  897c241c             mov dword ptr [esp + 0x1c], edi
// 00659066  89542418             mov dword ptr [esp + 0x18], edx
// 0065906a  807c241340           cmp byte ptr [esp + 0x13], 0x40
// 0065906f  0f8559feffff         jne 0x658ece
// 00659075  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 00659079  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 0065907f  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00659083  8b542424             mov edx, dword ptr [esp + 0x24]
// 00659087  45                   inc ebp
// 00659088  33c0                 xor eax, eax
// 0065908a  41                   inc ecx
// 0065908b  46                   inc esi
// 0065908c  8bfd                 mov edi, ebp
// 0065908e  85d2                 test edx, edx
// 00659090  7626                 jbe 0x6590b8
// 00659092  89542444             mov dword ptr [esp + 0x44], edx
// 00659096  89542438             mov dword ptr [esp + 0x38], edx
// 0065909a  8d9b00000000         lea ebx, [ebx]
// 006590a0  8a06                 mov al, byte ptr [esi]
// 006590a2  8a17                 mov dl, byte ptr [edi]
// 006590a4  d0e8                 shr al, 1
// 006590a6  2ad0                 sub dl, al
// 006590a8  8811                 mov byte ptr [ecx], dl
// 006590aa  41                   inc ecx
// 006590ab  46                   inc esi
// 006590ac  47                   inc edi
// 006590ad  836c244401           sub dword ptr [esp + 0x44], 1
// 006590b2  75ec                 jne 0x6590a0
// 006590b4  8b442438             mov eax, dword ptr [esp + 0x38]
// 006590b8  3b442414             cmp eax, dword ptr [esp + 0x14]
// 006590bc  7331                 jae 0x6590ef
// 006590be  8b542414             mov edx, dword ptr [esp + 0x14]
// 006590c2  2bd0                 sub edx, eax
// 006590c4  89542444             mov dword ptr [esp + 0x44], edx
// 006590c8  eb06                 jmp 0x6590d0
// 006590ca  8d9b00000000         lea ebx, [ebx]
// 006590d0  0fb65500             movzx edx, byte ptr [ebp]
// 006590d4  0fb606               movzx eax, byte ptr [esi]
// 006590d7  03c2                 add eax, edx
// 006590d9  99                   cdq 
// 006590da  2bc2                 sub eax, edx
// 006590dc  8a17                 mov dl, byte ptr [edi]
// 006590de  d1f8                 sar eax, 1
// 006590e0  2ad0                 sub dl, al
// 006590e2  8811                 mov byte ptr [ecx], dl
// 006590e4  41                   inc ecx
// 006590e5  45                   inc ebp
// 006590e6  46                   inc esi
// 006590e7  47                   inc edi
// 006590e8  836c244401           sub dword ptr [esp + 0x44], 1
// 006590ed  75e1                 jne 0x6590d0
// 006590ef  8b83f8000000         mov eax, dword ptr [ebx + 0xf8]
// 006590f5  89442418             mov dword ptr [esp + 0x18], eax
// 006590f9  f644241380           test byte ptr [esp + 0x13], 0x80
// 006590fe  0f84a6040000         je 0x6595aa
// 00659104  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00659108  33ed                 xor ebp, ebp
// 0065910a  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00659111  896c2430             mov dword ptr [esp + 0x30], ebp
// 00659115  894c2420             mov dword ptr [esp + 0x20], ecx
// 00659119  0f85c7020000         jne 0x6593e6
// 0065911f  0fb7f1               movzx esi, cx
// 00659122  c1e90a               shr ecx, 0xa
// 00659125  33d2                 xor edx, edx
// 00659127  81e1c0ff3f00         and ecx, 0x3fffc0
// 0065912d  39542448             cmp dword ptr [esp + 0x48], edx
// 00659131  7e2f                 jle 0x659162
// 00659133  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00659139  803c0204             cmp byte ptr [edx + eax], 4
// 0065913d  751c                 jne 0x65915b
// 0065913f  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 00659145  0fb70450             movzx eax, word ptr [eax + edx*2]
// 00659149  8bf8                 mov edi, eax
// 0065914b  0fafc1               imul eax, ecx
// 0065914e  0faffe               imul edi, esi
// 00659151  c1ef08               shr edi, 8
// 00659154  c1e808               shr eax, 8
// 00659157  8bf7                 mov esi, edi
// 00659159  8bc8                 mov ecx, eax
// 0065915b  42                   inc edx
// 0065915c  3b542448             cmp edx, dword ptr [esp + 0x48]
// 00659160  7cd1                 jl 0x659133
// 00659162  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 00659168  0fb75208             movzx edx, word ptr [edx + 8]
// 0065916c  8bc2                 mov eax, edx
// 0065916e  0fafc1               imul eax, ecx
// 00659171  c1e803               shr eax, 3
// 00659174  3dc0ff3f00           cmp eax, 0x3fffc0
// 00659179  0f8658020000         jbe 0x6593d7
// 0065917f  c7442420ffffff7f     mov dword ptr [esp + 0x20], 0x7fffffff
// 00659187  e95a020000           jmp 0x6593e6
// 0065918c  0fafd6               imul edx, esi
// 0065918f  c1ea03               shr edx, 3
// 00659192  c1e00a               shl eax, 0xa
// 00659195  03d0                 add edx, eax
// 00659197  89542434             mov dword ptr [esp + 0x34], edx
// 0065919b  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0065919f  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 006591a5  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 006591a9  8b442424             mov eax, dword ptr [esp + 0x24]
// 006591ad  45                   inc ebp
// 006591ae  41                   inc ecx
// 006591af  46                   inc esi
// 006591b0  c744243000000000     mov dword ptr [esp + 0x30], 0
// 006591b8  8bfd                 mov edi, ebp
// 006591ba  85c0                 test eax, eax
// 006591bc  7635                 jbe 0x6591f3
// 006591be  89442438             mov dword ptr [esp + 0x38], eax
// 006591c2  89442430             mov dword ptr [esp + 0x30], eax
// 006591c6  8a16                 mov dl, byte ptr [esi]
// 006591c8  8a07                 mov al, byte ptr [edi]
// 006591ca  d0ea                 shr dl, 1
// 006591cc  2ac2                 sub al, dl
// 006591ce  8801                 mov byte ptr [ecx], al
// 006591d0  0fb6c0               movzx eax, al
// 006591d3  41                   inc ecx
// 006591d4  46                   inc esi
// 006591d5  47                   inc edi
// 006591d6  3d80000000           cmp eax, 0x80
// 006591db  7d04                 jge 0x6591e1
// 006591dd  8bd0                 mov edx, eax
// 006591df  eb07                 jmp 0x6591e8
// 006591e1  ba00010000           mov edx, 0x100
// 006591e6  2bd0                 sub edx, eax
// 006591e8  01542420             add dword ptr [esp + 0x20], edx
// 006591ec  836c243801           sub dword ptr [esp + 0x38], 1
// 006591f1  75d3                 jne 0x6591c6
// 006591f3  8b442414             mov eax, dword ptr [esp + 0x14]
// 006591f7  39442430             cmp dword ptr [esp + 0x30], eax
// 006591fb  7351                 jae 0x65924e
// 006591fd  8d4900               lea ecx, [ecx]
// 00659200  0fb616               movzx edx, byte ptr [esi]
// 00659203  0fb64500             movzx eax, byte ptr [ebp]
// 00659207  03c2                 add eax, edx
// 00659209  99                   cdq 
// 0065920a  2bc2                 sub eax, edx
// 0065920c  8bd0                 mov edx, eax
// 0065920e  8a07                 mov al, byte ptr [edi]
// 00659210  d1fa                 sar edx, 1
// 00659212  2ac2                 sub al, dl
// 00659214  8801                 mov byte ptr [ecx], al
// 00659216  0fb6c0               movzx eax, al
// 00659219  41                   inc ecx
// 0065921a  45                   inc ebp
// 0065921b  46                   inc esi
// 0065921c  47                   inc edi
// 0065921d  3d80000000           cmp eax, 0x80
// 00659222  7d04                 jge 0x659228
// 00659224  8bd0                 mov edx, eax
// 00659226  eb07                 jmp 0x65922f
// 00659228  ba00010000           mov edx, 0x100
// 0065922d  2bd0                 sub edx, eax
// 0065922f  8b442420             mov eax, dword ptr [esp + 0x20]
// 00659233  03c2                 add eax, edx
// 00659235  89442420             mov dword ptr [esp + 0x20], eax
// 00659239  3b442434             cmp eax, dword ptr [esp + 0x34]
// 0065923d  770f                 ja 0x65924e
// 0065923f  8b442430             mov eax, dword ptr [esp + 0x30]
// 00659243  40                   inc eax
// 00659244  89442430             mov dword ptr [esp + 0x30], eax
// 00659248  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0065924c  72b2                 jb 0x659200
// 0065924e  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00659255  7579                 jne 0x6592d0
// 00659257  8b542420             mov edx, dword ptr [esp + 0x20]
// 0065925b  0fb7f2               movzx esi, dx
// 0065925e  c1ea0a               shr edx, 0xa
// 00659261  33c9                 xor ecx, ecx
// 00659263  81e2c0ff3f00         and edx, 0x3fffc0
// 00659269  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0065926d  7e2f                 jle 0x65929e
// 0065926f  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 00659275  803c3900             cmp byte ptr [ecx + edi], 0
// 00659279  751c                 jne 0x659297
// 0065927b  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 00659281  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00659285  8be8                 mov ebp, eax
// 00659287  0fafc2               imul eax, edx
// 0065928a  0fafee               imul ebp, esi
// 0065928d  c1ed08               shr ebp, 8
// 00659290  c1e808               shr eax, 8
// 00659293  8bf5                 mov esi, ebp
// 00659295  8bd0                 mov edx, eax
// 00659297  41                   inc ecx
// 00659298  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0065929c  7cd7                 jl 0x659275
// 0065929e  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 006592a4  0fb74906             movzx ecx, word ptr [ecx + 6]
// 006592a8  8bc1                 mov eax, ecx
// 006592aa  0fafc2               imul eax, edx
// 006592ad  c1e803               shr eax, 3
// 006592b0  3dc0ff3f00           cmp eax, 0x3fffc0
// 006592b5  760a                 jbe 0x6592c1
// 006592b7  c7442420ffffff7f     mov dword ptr [esp + 0x20], 0x7fffffff
// 006592bf  eb0f                 jmp 0x6592d0
// 006592c1  0fafce               imul ecx, esi
// 006592c4  c1e903               shr ecx, 3
// 006592c7  c1e00a               shl eax, 0xa
// 006592ca  03c8                 add ecx, eax
// 006592cc  894c2420             mov dword ptr [esp + 0x20], ecx
// 006592d0  8b442420             mov eax, dword ptr [esp + 0x20]
// 006592d4  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 006592d8  730e                 jae 0x6592e8
// 006592da  8b93f8000000         mov edx, dword ptr [ebx + 0xf8]
// 006592e0  8944241c             mov dword ptr [esp + 0x1c], eax
// 006592e4  89542418             mov dword ptr [esp + 0x18], edx
// 006592e8  807c241380           cmp byte ptr [esp + 0x13], 0x80
// 006592ed  0f8506feffff         jne 0x6590f9
// 006592f3  8b442428             mov eax, dword ptr [esp + 0x28]
// 006592f7  8bbbfc000000         mov edi, dword ptr [ebx + 0xfc]
// 006592fd  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00659301  40                   inc eax
// 00659302  42                   inc edx
// 00659303  47                   inc edi
// 00659304  837c242400           cmp dword ptr [esp + 0x24], 0
// 00659309  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00659311  8bc8                 mov ecx, eax
// 00659313  89442430             mov dword ptr [esp + 0x30], eax
// 00659317  8bf2                 mov esi, edx
// 00659319  761b                 jbe 0x659336
// 0065931b  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0065931f  896c2434             mov dword ptr [esp + 0x34], ebp
// 00659323  8a19                 mov bl, byte ptr [ecx]
// 00659325  2a1e                 sub bl, byte ptr [esi]
// 00659327  47                   inc edi
// 00659328  885fff               mov byte ptr [edi - 1], bl
// 0065932b  46                   inc esi
// 0065932c  41                   inc ecx
// 0065932d  83ed01               sub ebp, 1
// 00659330  75f1                 jne 0x659323
// 00659332  894c2430             mov dword ptr [esp + 0x30], ecx
// 00659336  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0065933a  8be8                 mov ebp, eax
// 0065933c  395c2434             cmp dword ptr [esp + 0x34], ebx
// 00659340  0f8388000000         jae 0x6593ce
// 00659346  8bca                 mov ecx, edx
// 00659348  2bc8                 sub ecx, eax
// 0065934a  2b5c2434             sub ebx, dword ptr [esp + 0x34]
// 0065934e  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00659352  895c2434             mov dword ptr [esp + 0x34], ebx
// 00659356  eb0c                 jmp 0x659364
// 00659358  eb06                 jmp 0x659360
// 0065935a  8d9b00000000         lea ebx, [ebx]
// 00659360  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00659364  0fb61429             movzx edx, byte ptr [ecx + ebp]
// 00659368  0fb606               movzx eax, byte ptr [esi]
// 0065936b  0fb64d00             movzx ecx, byte ptr [ebp]
// 0065936f  89442424             mov dword ptr [esp + 0x24], eax
// 00659373  894c2428             mov dword ptr [esp + 0x28], ecx
// 00659377  2bc2                 sub eax, edx
// 00659379  46                   inc esi
// 0065937a  45                   inc ebp
// 0065937b  2bca                 sub ecx, edx
// 0065937d  85c0                 test eax, eax
// 0065937f  7d0a                 jge 0x65938b
// 00659381  8bd8                 mov ebx, eax
// 00659383  f7db                 neg ebx
// 00659385  895c2438             mov dword ptr [esp + 0x38], ebx
// 00659389  eb04                 jmp 0x65938f
// 0065938b  89442438             mov dword ptr [esp + 0x38], eax
// 0065938f  8bd9                 mov ebx, ecx
// 00659391  85c9                 test ecx, ecx
// 00659393  7d02                 jge 0x659397
// 00659395  f7db                 neg ebx
// 00659397  03c1                 add eax, ecx
// 00659399  7902                 jns 0x65939d
// 0065939b  f7d8                 neg eax
// 0065939d  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 006593a1  3bcb                 cmp ecx, ebx
// 006593a3  7f0a                 jg 0x6593af
// 006593a5  3bc8                 cmp ecx, eax
// 006593a7  7f06                 jg 0x6593af
// 006593a9  8b542428             mov edx, dword ptr [esp + 0x28]
// 006593ad  eb08                 jmp 0x6593b7
// 006593af  3bd8                 cmp ebx, eax
// 006593b1  7f04                 jg 0x6593b7
// 006593b3  8b542424             mov edx, dword ptr [esp + 0x24]
// 006593b7  8b442430             mov eax, dword ptr [esp + 0x30]
// 006593bb  8a08                 mov cl, byte ptr [eax]
// 006593bd  2aca                 sub cl, dl
// 006593bf  880f                 mov byte ptr [edi], cl
// 006593c1  40                   inc eax
// 006593c2  47                   inc edi
// 006593c3  836c243401           sub dword ptr [esp + 0x34], 1
// 006593c8  89442430             mov dword ptr [esp + 0x30], eax
// 006593cc  7592                 jne 0x659360
// 006593ce  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 006593d2  e9c9010000           jmp 0x6595a0
// 006593d7  0fafd6               imul edx, esi
// 006593da  c1ea03               shr edx, 3
// 006593dd  c1e00a               shl eax, 0xa
// 006593e0  03d0                 add edx, eax
// 006593e2  89542420             mov dword ptr [esp + 0x20], edx
// 006593e6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006593ea  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 006593ee  8bb3fc000000         mov esi, dword ptr [ebx + 0xfc]
// 006593f4  8b442424             mov eax, dword ptr [esp + 0x24]
// 006593f8  47                   inc edi
// 006593f9  42                   inc edx
// 006593fa  46                   inc esi
// 006593fb  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00659403  897c2428             mov dword ptr [esp + 0x28], edi
// 00659407  897c2434             mov dword ptr [esp + 0x34], edi
// 0065940b  8954242c             mov dword ptr [esp + 0x2c], edx
// 0065940f  85c0                 test eax, eax
// 00659411  763d                 jbe 0x659450
// 00659413  89442438             mov dword ptr [esp + 0x38], eax
// 00659417  89442444             mov dword ptr [esp + 0x44], eax
// 0065941b  eb03                 jmp 0x659420
// 0065941d  8d4900               lea ecx, [ecx]
// 00659420  8a07                 mov al, byte ptr [edi]
// 00659422  2a02                 sub al, byte ptr [edx]
// 00659424  46                   inc esi
// 00659425  8846ff               mov byte ptr [esi - 1], al
// 00659428  0fb6c0               movzx eax, al
// 0065942b  42                   inc edx
// 0065942c  47                   inc edi
// 0065942d  3d80000000           cmp eax, 0x80
// 00659432  7d04                 jge 0x659438
// 00659434  8bc8                 mov ecx, eax
// 00659436  eb07                 jmp 0x65943f
// 00659438  b900010000           mov ecx, 0x100
// 0065943d  2bc8                 sub ecx, eax
// 0065943f  03e9                 add ebp, ecx
// 00659441  836c243801           sub dword ptr [esp + 0x38], 1
// 00659446  75d8                 jne 0x659420
// 00659448  896c2430             mov dword ptr [esp + 0x30], ebp
// 0065944c  897c2434             mov dword ptr [esp + 0x34], edi
// 00659450  8b442444             mov eax, dword ptr [esp + 0x44]
// 00659454  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00659458  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0065945c  0f83b8000000         jae 0x65951a
// 00659462  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00659466  2bf9                 sub edi, ecx
// 00659468  897c242c             mov dword ptr [esp + 0x2c], edi
// 0065946c  eb0e                 jmp 0x65947c
// 0065946e  8bff                 mov edi, edi
// 00659470  8b542428             mov edx, dword ptr [esp + 0x28]
// 00659474  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00659478  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0065947c  0fb602               movzx eax, byte ptr [edx]
// 0065947f  42                   inc edx
// 00659480  89542428             mov dword ptr [esp + 0x28], edx
// 00659484  0fb6140f             movzx edx, byte ptr [edi + ecx]
// 00659488  0fb639               movzx edi, byte ptr [ecx]
// 0065948b  41                   inc ecx
// 0065948c  894c2424             mov dword ptr [esp + 0x24], ecx
// 00659490  8944243c             mov dword ptr [esp + 0x3c], eax
// 00659494  8bcf                 mov ecx, edi
// 00659496  2bc2                 sub eax, edx
// 00659498  2bca                 sub ecx, edx
// 0065949a  85c0                 test eax, eax
// 0065949c  7d0a                 jge 0x6594a8
// 0065949e  8be8                 mov ebp, eax
// 006594a0  f7dd                 neg ebp
// 006594a2  896c2438             mov dword ptr [esp + 0x38], ebp
// 006594a6  eb04                 jmp 0x6594ac
// 006594a8  89442438             mov dword ptr [esp + 0x38], eax
// 006594ac  8be9                 mov ebp, ecx
// 006594ae  85c9                 test ecx, ecx
// 006594b0  7d02                 jge 0x6594b4
// 006594b2  f7dd                 neg ebp
// 006594b4  03c1                 add eax, ecx
// 006594b6  7902                 jns 0x6594ba
// 006594b8  f7d8                 neg eax
// 006594ba  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 006594be  3bcd                 cmp ecx, ebp
// 006594c0  7f08                 jg 0x6594ca
// 006594c2  3bc8                 cmp ecx, eax
// 006594c4  7f04                 jg 0x6594ca
// 006594c6  8bd7                 mov edx, edi
// 006594c8  eb08                 jmp 0x6594d2
// 006594ca  3be8                 cmp ebp, eax
// 006594cc  7f04                 jg 0x6594d2
// 006594ce  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 006594d2  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 006594d6  8a01                 mov al, byte ptr [ecx]
// 006594d8  2ac2                 sub al, dl
// 006594da  8806                 mov byte ptr [esi], al
// 006594dc  0fb6c0               movzx eax, al
// 006594df  41                   inc ecx
// 006594e0  46                   inc esi
// 006594e1  3d80000000           cmp eax, 0x80
// 006594e6  894c2434             mov dword ptr [esp + 0x34], ecx
// 006594ea  7d04                 jge 0x6594f0
// 006594ec  8bc8                 mov ecx, eax
// 006594ee  eb07                 jmp 0x6594f7
// 006594f0  b900010000           mov ecx, 0x100
// 006594f5  2bc8                 sub ecx, eax
// 006594f7  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 006594fb  03e9                 add ebp, ecx
// 006594fd  896c2430             mov dword ptr [esp + 0x30], ebp
// 00659501  3b6c2420             cmp ebp, dword ptr [esp + 0x20]
// 00659505  7713                 ja 0x65951a
// 00659507  8b442444             mov eax, dword ptr [esp + 0x44]
// 0065950b  40                   inc eax
// 0065950c  89442444             mov dword ptr [esp + 0x44], eax
// 00659510  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00659514  0f8256ffffff         jb 0x659470
// 0065951a  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00659521  7577                 jne 0x65959a
// 00659523  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 00659527  0fb7f5               movzx esi, bp
// 0065952a  c1ed0a               shr ebp, 0xa
// 0065952d  81e5c0ff3f00         and ebp, 0x3fffc0
// 00659533  33c9                 xor ecx, ecx
// 00659535  8bd5                 mov edx, ebp
// 00659537  85ff                 test edi, edi
// 00659539  7e32                 jle 0x65956d
// 0065953b  eb03                 jmp 0x659540
// 0065953d  8d4900               lea ecx, [ecx]
// 00659540  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00659546  803c0104             cmp byte ptr [ecx + eax], 4
// 0065954a  751c                 jne 0x659568
// 0065954c  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 00659552  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00659556  8be8                 mov ebp, eax
// 00659558  0fafc2               imul eax, edx
// 0065955b  0fafee               imul ebp, esi
// 0065955e  c1ed08               shr ebp, 8
// 00659561  c1e808               shr eax, 8
// 00659564  8bf5                 mov esi, ebp
// 00659566  8bd0                 mov edx, eax
// 00659568  41                   inc ecx
// 00659569  3bcf                 cmp ecx, edi
// 0065956b  7cd3                 jl 0x659540
// 0065956d  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 00659573  0fb74908             movzx ecx, word ptr [ecx + 8]
// 00659577  8bc1                 mov eax, ecx
// 00659579  0fafc2               imul eax, edx
// 0065957c  c1e803               shr eax, 3
// 0065957f  3dc0ff3f00           cmp eax, 0x3fffc0
// 00659584  7607                 jbe 0x65958d
// 00659586  bdffffff7f           mov ebp, 0x7fffffff
// 0065958b  eb0d                 jmp 0x65959a
// 0065958d  0fafce               imul ecx, esi
// 00659590  c1e903               shr ecx, 3
// 00659593  c1e00a               shl eax, 0xa
// 00659596  03c8                 add ecx, eax
// 00659598  8be9                 mov ebp, ecx
// 0065959a  3b6c241c             cmp ebp, dword ptr [esp + 0x1c]
// 0065959e  730a                 jae 0x6595aa
// 006595a0  8b93fc000000         mov edx, dword ptr [ebx + 0xfc]
// 006595a6  89542418             mov dword ptr [esp + 0x18], edx
// 006595aa  8b442418             mov eax, dword ptr [esp + 0x18]
// 006595ae  50                   push eax
// 006595af  53                   push ebx
// 006595b0  e84bf4ffff           call 0x658a00
// 006595b5  83c408               add esp, 8
// 006595b8  80bbf901000000       cmp byte ptr [ebx + 0x1f9], 0
// 006595bf  7633                 jbe 0x6595f4
// 006595c1  b801000000           mov eax, 1
// 006595c6  39442448             cmp dword ptr [esp + 0x48], eax
// 006595ca  7e19                 jle 0x6595e5
// 006595cc  8d642400             lea esp, [esp]
// 006595d0  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 006595d6  8a5401ff             mov dl, byte ptr [ecx + eax - 1]
// 006595da  03c8                 add ecx, eax
// 006595dc  40                   inc eax
// 006595dd  3b442448             cmp eax, dword ptr [esp + 0x48]
// 006595e1  8811                 mov byte ptr [ecx], dl
// 006595e3  7ceb                 jl 0x6595d0
// 006595e5  8b542418             mov edx, dword ptr [esp + 0x18]
// 006595e9  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 006595ef  8a12                 mov dl, byte ptr [edx]
// 006595f1  881408               mov byte ptr [eax + ecx], dl
// 006595f4  5f                   pop edi
// 006595f5  5e                   pop esi
// 006595f6  5d                   pop ebp
// 006595f7  5b                   pop ebx
// 006595f8  83c430               add esp, 0x30
// 006595fb  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_find_filter)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
