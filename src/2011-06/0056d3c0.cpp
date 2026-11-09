// from server: 100% by auto
// roc 2011-06 0056d3c0  unit: seg_00560000  size: 2860 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056d3c0
//
// 0056d3c0  83ec30               sub esp, 0x30
// 0056d3c3  8b442438             mov eax, dword ptr [esp + 0x38]
// 0056d3c7  53                   push ebx
// 0056d3c8  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 0056d3cc  8a8b25010000         mov cl, byte ptr [ebx + 0x125]
// 0056d3d2  0fb693f9010000       movzx edx, byte ptr [ebx + 0x1f9]
// 0056d3d9  55                   push ebp
// 0056d3da  8b6804               mov ebp, dword ptr [eax + 4]
// 0056d3dd  56                   push esi
// 0056d3de  57                   push edi
// 0056d3df  0fb6780b             movzx edi, byte ptr [eax + 0xb]
// 0056d3e3  8b83e8000000         mov eax, dword ptr [ebx + 0xe8]
// 0056d3e9  83c707               add edi, 7
// 0056d3ec  c1ff03               sar edi, 3
// 0056d3ef  8944242c             mov dword ptr [esp + 0x2c], eax
// 0056d3f3  8b83ec000000         mov eax, dword ptr [ebx + 0xec]
// 0056d3f9  884c2413             mov byte ptr [esp + 0x13], cl
// 0056d3fd  896c2414             mov dword ptr [esp + 0x14], ebp
// 0056d401  89542448             mov dword ptr [esp + 0x48], edx
// 0056d405  897c2424             mov dword ptr [esp + 0x24], edi
// 0056d409  89442418             mov dword ptr [esp + 0x18], eax
// 0056d40d  89442428             mov dword ptr [esp + 0x28], eax
// 0056d411  c744241cffffff7f     mov dword ptr [esp + 0x1c], 0x7fffffff
// 0056d419  f6c108               test cl, 8
// 0056d41c  0f84bd000000         je 0x56d4df
// 0056d422  80f908               cmp cl, 8
// 0056d425  0f84b4000000         je 0x56d4df
// 0056d42b  33c0                 xor eax, eax
// 0056d42d  33d2                 xor edx, edx
// 0056d42f  85ed                 test ebp, ebp
// 0056d431  7630                 jbe 0x56d463
// 0056d433  eb0b                 jmp 0x56d440
// 0056d435  8da42400000000       lea esp, [esp]
// 0056d43c  8d642400             lea esp, [esp]
// 0056d440  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056d444  0fb6741101           movzx esi, byte ptr [ecx + edx + 1]
// 0056d449  81fe80000000         cmp esi, 0x80
// 0056d44f  7d04                 jge 0x56d455
// 0056d451  8bce                 mov ecx, esi
// 0056d453  eb07                 jmp 0x56d45c
// 0056d455  b900010000           mov ecx, 0x100
// 0056d45a  2bce                 sub ecx, esi
// 0056d45c  42                   inc edx
// 0056d45d  03c1                 add eax, ecx
// 0056d45f  3bd5                 cmp edx, ebp
// 0056d461  72dd                 jb 0x56d440
// 0056d463  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0056d46a  756f                 jne 0x56d4db
// 0056d46c  0fb7f0               movzx esi, ax
// 0056d46f  c1e80a               shr eax, 0xa
// 0056d472  25c0ff3f00           and eax, 0x3fffc0
// 0056d477  33c9                 xor ecx, ecx
// 0056d479  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0056d47d  8bd0                 mov edx, eax
// 0056d47f  7e2f                 jle 0x56d4b0
// 0056d481  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0056d487  803c0800             cmp byte ptr [eax + ecx], 0
// 0056d48b  751c                 jne 0x56d4a9
// 0056d48d  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0056d493  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0056d497  8be8                 mov ebp, eax
// 0056d499  0fafc2               imul eax, edx
// 0056d49c  0fafee               imul ebp, esi
// 0056d49f  c1ed08               shr ebp, 8
// 0056d4a2  c1e808               shr eax, 8
// 0056d4a5  8bf5                 mov esi, ebp
// 0056d4a7  8bd0                 mov edx, eax
// 0056d4a9  41                   inc ecx
// 0056d4aa  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0056d4ae  7cd1                 jl 0x56d481
// 0056d4b0  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0056d4b6  0fb701               movzx eax, word ptr [ecx]
// 0056d4b9  8bc8                 mov ecx, eax
// 0056d4bb  0fafca               imul ecx, edx
// 0056d4be  c1e903               shr ecx, 3
// 0056d4c1  81f9c0ff3f00         cmp ecx, 0x3fffc0
// 0056d4c7  7607                 jbe 0x56d4d0
// 0056d4c9  b8ffffff7f           mov eax, 0x7fffffff
// 0056d4ce  eb0b                 jmp 0x56d4db
// 0056d4d0  0fafc6               imul eax, esi
// 0056d4d3  c1e803               shr eax, 3
// 0056d4d6  c1e10a               shl ecx, 0xa
// 0056d4d9  03c1                 add eax, ecx
// 0056d4db  8944241c             mov dword ptr [esp + 0x1c], eax
// 0056d4df  8a442413             mov al, byte ptr [esp + 0x13]
// 0056d4e3  3c10                 cmp al, 0x10
// 0056d4e5  0f85dc000000         jne 0x56d5c7
// 0056d4eb  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056d4ef  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 0056d4f5  46                   inc esi
// 0056d4f6  33ed                 xor ebp, ebp
// 0056d4f8  40                   inc eax
// 0056d4f9  8bce                 mov ecx, esi
// 0056d4fb  85ff                 test edi, edi
// 0056d4fd  760d                 jbe 0x56d50c
// 0056d4ff  8bef                 mov ebp, edi
// 0056d501  8a11                 mov dl, byte ptr [ecx]
// 0056d503  8810                 mov byte ptr [eax], dl
// 0056d505  41                   inc ecx
// 0056d506  40                   inc eax
// 0056d507  83ef01               sub edi, 1
// 0056d50a  75f5                 jne 0x56d501
// 0056d50c  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 0056d510  7314                 jae 0x56d526
// 0056d512  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056d516  2bfd                 sub edi, ebp
// 0056d518  8a11                 mov dl, byte ptr [ecx]
// 0056d51a  2a16                 sub dl, byte ptr [esi]
// 0056d51c  41                   inc ecx
// 0056d51d  8810                 mov byte ptr [eax], dl
// 0056d51f  46                   inc esi
// 0056d520  40                   inc eax
// 0056d521  83ef01               sub edi, 1
// 0056d524  75f2                 jne 0x56d518
// 0056d526  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 0056d52c  89442418             mov dword ptr [esp + 0x18], eax
// 0056d530  f644241320           test byte ptr [esp + 0x13], 0x20
// 0056d535  0f841f040000         je 0x56d95a
// 0056d53b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056d53f  33ff                 xor edi, edi
// 0056d541  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0056d548  894c2430             mov dword ptr [esp + 0x30], ecx
// 0056d54c  0f8514030000         jne 0x56d866
// 0056d552  0fb7f1               movzx esi, cx
// 0056d555  c1e90a               shr ecx, 0xa
// 0056d558  33d2                 xor edx, edx
// 0056d55a  81e1c0ff3f00         and ecx, 0x3fffc0
// 0056d560  39542448             cmp dword ptr [esp + 0x48], edx
// 0056d564  89742434             mov dword ptr [esp + 0x34], esi
// 0056d568  7e33                 jle 0x56d59d
// 0056d56a  8babfc010000         mov ebp, dword ptr [ebx + 0x1fc]
// 0056d570  803c2a02             cmp byte ptr [edx + ebp], 2
// 0056d574  7520                 jne 0x56d596
// 0056d576  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0056d57c  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0056d580  8bf0                 mov esi, eax
// 0056d582  0fafc1               imul eax, ecx
// 0056d585  0faf742434           imul esi, dword ptr [esp + 0x34]
// 0056d58a  c1ee08               shr esi, 8
// 0056d58d  c1e808               shr eax, 8
// 0056d590  89742434             mov dword ptr [esp + 0x34], esi
// 0056d594  8bc8                 mov ecx, eax
// 0056d596  42                   inc edx
// 0056d597  3b542448             cmp edx, dword ptr [esp + 0x48]
// 0056d59b  7cd3                 jl 0x56d570
// 0056d59d  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0056d5a3  0fb75204             movzx edx, word ptr [edx + 4]
// 0056d5a7  8bc2                 mov eax, edx
// 0056d5a9  0fafc1               imul eax, ecx
// 0056d5ac  c1e803               shr eax, 3
// 0056d5af  3dc0ff3f00           cmp eax, 0x3fffc0
// 0056d5b4  0f869d020000         jbe 0x56d857
// 0056d5ba  c7442430ffffff7f     mov dword ptr [esp + 0x30], 0x7fffffff
// 0056d5c2  e99f020000           jmp 0x56d866
// 0056d5c7  a810                 test al, 0x10
// 0056d5c9  0f84ac010000         je 0x56d77b
// 0056d5cf  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056d5d3  33ff                 xor edi, edi
// 0056d5d5  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0056d5dc  894c2430             mov dword ptr [esp + 0x30], ecx
// 0056d5e0  757f                 jne 0x56d661
// 0056d5e2  0fb7f1               movzx esi, cx
// 0056d5e5  c1e90a               shr ecx, 0xa
// 0056d5e8  81e1c0ff3f00         and ecx, 0x3fffc0
// 0056d5ee  33d2                 xor edx, edx
// 0056d5f0  397c2448             cmp dword ptr [esp + 0x48], edi
// 0056d5f4  7e39                 jle 0x56d62f
// 0056d5f6  eb08                 jmp 0x56d600
// 0056d5f8  8da42400000000       lea esp, [esp]
// 0056d5ff  90                   nop 
// 0056d600  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0056d606  803c1001             cmp byte ptr [eax + edx], 1
// 0056d60a  751c                 jne 0x56d628
// 0056d60c  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0056d612  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0056d616  8be8                 mov ebp, eax
// 0056d618  0fafc1               imul eax, ecx
// 0056d61b  0fafee               imul ebp, esi
// 0056d61e  c1ed08               shr ebp, 8
// 0056d621  c1e808               shr eax, 8
// 0056d624  8bf5                 mov esi, ebp
// 0056d626  8bc8                 mov ecx, eax
// 0056d628  42                   inc edx
// 0056d629  3b542448             cmp edx, dword ptr [esp + 0x48]
// 0056d62d  7cd1                 jl 0x56d600
// 0056d62f  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0056d635  0fb75202             movzx edx, word ptr [edx + 2]
// 0056d639  8bc2                 mov eax, edx
// 0056d63b  0fafc1               imul eax, ecx
// 0056d63e  c1e803               shr eax, 3
// 0056d641  3dc0ff3f00           cmp eax, 0x3fffc0
// 0056d646  760a                 jbe 0x56d652
// 0056d648  c7442430ffffff7f     mov dword ptr [esp + 0x30], 0x7fffffff
// 0056d650  eb0f                 jmp 0x56d661
// 0056d652  0fafd6               imul edx, esi
// 0056d655  c1ea03               shr edx, 3
// 0056d658  c1e00a               shl eax, 0xa
// 0056d65b  03d0                 add edx, eax
// 0056d65d  89542430             mov dword ptr [esp + 0x30], edx
// 0056d661  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056d665  8b8bf0000000         mov ecx, dword ptr [ebx + 0xf0]
// 0056d66b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056d66f  45                   inc ebp
// 0056d670  41                   inc ecx
// 0056d671  897c2420             mov dword ptr [esp + 0x20], edi
// 0056d675  896c2438             mov dword ptr [esp + 0x38], ebp
// 0056d679  8bd5                 mov edx, ebp
// 0056d67b  85c0                 test eax, eax
// 0056d67d  762d                 jbe 0x56d6ac
// 0056d67f  8be8                 mov ebp, eax
// 0056d681  89442420             mov dword ptr [esp + 0x20], eax
// 0056d685  8a02                 mov al, byte ptr [edx]
// 0056d687  0fb6f0               movzx esi, al
// 0056d68a  81fe80000000         cmp esi, 0x80
// 0056d690  8801                 mov byte ptr [ecx], al
// 0056d692  7d04                 jge 0x56d698
// 0056d694  8bc6                 mov eax, esi
// 0056d696  eb07                 jmp 0x56d69f
// 0056d698  b800010000           mov eax, 0x100
// 0056d69d  2bc6                 sub eax, esi
// 0056d69f  03f8                 add edi, eax
// 0056d6a1  42                   inc edx
// 0056d6a2  41                   inc ecx
// 0056d6a3  83ed01               sub ebp, 1
// 0056d6a6  75dd                 jne 0x56d685
// 0056d6a8  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 0056d6ac  8b442414             mov eax, dword ptr [esp + 0x14]
// 0056d6b0  39442420             cmp dword ptr [esp + 0x20], eax
// 0056d6b4  7336                 jae 0x56d6ec
// 0056d6b6  8a02                 mov al, byte ptr [edx]
// 0056d6b8  2a4500               sub al, byte ptr [ebp]
// 0056d6bb  8801                 mov byte ptr [ecx], al
// 0056d6bd  0fb6c0               movzx eax, al
// 0056d6c0  3d80000000           cmp eax, 0x80
// 0056d6c5  7d04                 jge 0x56d6cb
// 0056d6c7  8bf0                 mov esi, eax
// 0056d6c9  eb07                 jmp 0x56d6d2
// 0056d6cb  be00010000           mov esi, 0x100
// 0056d6d0  2bf0                 sub esi, eax
// 0056d6d2  03fe                 add edi, esi
// 0056d6d4  3b7c2430             cmp edi, dword ptr [esp + 0x30]
// 0056d6d8  7712                 ja 0x56d6ec
// 0056d6da  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056d6de  40                   inc eax
// 0056d6df  42                   inc edx
// 0056d6e0  45                   inc ebp
// 0056d6e1  41                   inc ecx
// 0056d6e2  89442420             mov dword ptr [esp + 0x20], eax
// 0056d6e6  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0056d6ea  72ca                 jb 0x56d6b6
// 0056d6ec  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0056d6f3  7572                 jne 0x56d767
// 0056d6f5  0fb7f7               movzx esi, di
// 0056d6f8  c1ef0a               shr edi, 0xa
// 0056d6fb  81e7c0ff3f00         and edi, 0x3fffc0
// 0056d701  33c9                 xor ecx, ecx
// 0056d703  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0056d707  8bd7                 mov edx, edi
// 0056d709  7e2f                 jle 0x56d73a
// 0056d70b  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 0056d711  803c0f01             cmp byte ptr [edi + ecx], 1
// 0056d715  751c                 jne 0x56d733
// 0056d717  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0056d71d  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0056d721  8be8                 mov ebp, eax
// 0056d723  0fafc2               imul eax, edx
// 0056d726  0fafee               imul ebp, esi
// 0056d729  c1ed08               shr ebp, 8
// 0056d72c  c1e808               shr eax, 8
// 0056d72f  8bf5                 mov esi, ebp
// 0056d731  8bd0                 mov edx, eax
// 0056d733  41                   inc ecx
// 0056d734  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0056d738  7cd7                 jl 0x56d711
// 0056d73a  8b8b0c020000         mov ecx, dword ptr [ebx + 0x20c]
// 0056d740  0fb74902             movzx ecx, word ptr [ecx + 2]
// 0056d744  8bc1                 mov eax, ecx
// 0056d746  0fafc2               imul eax, edx
// 0056d749  c1e803               shr eax, 3
// 0056d74c  3dc0ff3f00           cmp eax, 0x3fffc0
// 0056d751  7607                 jbe 0x56d75a
// 0056d753  bfffffff7f           mov edi, 0x7fffffff
// 0056d758  eb0d                 jmp 0x56d767
// 0056d75a  0fafce               imul ecx, esi
// 0056d75d  c1e903               shr ecx, 3
// 0056d760  c1e00a               shl eax, 0xa
// 0056d763  03c8                 add ecx, eax
// 0056d765  8bf9                 mov edi, ecx
// 0056d767  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 0056d76b  730e                 jae 0x56d77b
// 0056d76d  8b93f0000000         mov edx, dword ptr [ebx + 0xf0]
// 0056d773  897c241c             mov dword ptr [esp + 0x1c], edi
// 0056d777  89542418             mov dword ptr [esp + 0x18], edx
// 0056d77b  807c241320           cmp byte ptr [esp + 0x13], 0x20
// 0056d780  0f85aafdffff         jne 0x56d530
// 0056d786  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 0056d78c  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056d790  33c9                 xor ecx, ecx
// 0056d792  40                   inc eax
// 0056d793  8d7a01               lea edi, [edx + 1]
// 0056d796  394c2414             cmp dword ptr [esp + 0x14], ecx
// 0056d79a  7618                 jbe 0x56d7b4
// 0056d79c  8bf7                 mov esi, edi
// 0056d79e  2bf2                 sub esi, edx
// 0056d7a0  0374242c             add esi, dword ptr [esp + 0x2c]
// 0056d7a4  8a1439               mov dl, byte ptr [ecx + edi]
// 0056d7a7  2a16                 sub dl, byte ptr [esi]
// 0056d7a9  41                   inc ecx
// 0056d7aa  8810                 mov byte ptr [eax], dl
// 0056d7ac  46                   inc esi
// 0056d7ad  40                   inc eax
// 0056d7ae  3b4c2414             cmp ecx, dword ptr [esp + 0x14]
// 0056d7b2  72f0                 jb 0x56d7a4
// 0056d7b4  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 0056d7ba  89442418             mov dword ptr [esp + 0x18], eax
// 0056d7be  f644241340           test byte ptr [esp + 0x13], 0x40
// 0056d7c3  0f840f040000         je 0x56dbd8
// 0056d7c9  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056d7cd  33d2                 xor edx, edx
// 0056d7cf  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0056d7d6  89542420             mov dword ptr [esp + 0x20], edx
// 0056d7da  894c2434             mov dword ptr [esp + 0x34], ecx
// 0056d7de  0f85a7020000         jne 0x56da8b
// 0056d7e4  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 0056d7e8  0fb7f1               movzx esi, cx
// 0056d7eb  c1e90a               shr ecx, 0xa
// 0056d7ee  81e1c0ff3f00         and ecx, 0x3fffc0
// 0056d7f4  3bfa                 cmp edi, edx
// 0056d7f6  7e35                 jle 0x56d82d
// 0056d7f8  eb06                 jmp 0x56d800
// 0056d7fa  8d9b00000000         lea ebx, [ebx]
// 0056d800  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0056d806  803c0203             cmp byte ptr [edx + eax], 3
// 0056d80a  751c                 jne 0x56d828
// 0056d80c  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0056d812  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0056d816  8be8                 mov ebp, eax
// 0056d818  0fafc1               imul eax, ecx
// 0056d81b  0fafee               imul ebp, esi
// 0056d81e  c1ed08               shr ebp, 8
// 0056d821  c1e808               shr eax, 8
// 0056d824  8bf5                 mov esi, ebp
// 0056d826  8bc8                 mov ecx, eax
// 0056d828  42                   inc edx
// 0056d829  3bd7                 cmp edx, edi
// 0056d82b  7cd3                 jl 0x56d800
// 0056d82d  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0056d833  0fb75206             movzx edx, word ptr [edx + 6]
// 0056d837  8bc2                 mov eax, edx
// 0056d839  0fafc1               imul eax, ecx
// 0056d83c  c1e803               shr eax, 3
// 0056d83f  3dc0ff3f00           cmp eax, 0x3fffc0
// 0056d844  0f8632020000         jbe 0x56da7c
// 0056d84a  c7442434ffffff7f     mov dword ptr [esp + 0x34], 0x7fffffff
// 0056d852  e934020000           jmp 0x56da8b
// 0056d857  0fafd6               imul edx, esi
// 0056d85a  c1ea03               shr edx, 3
// 0056d85d  c1e00a               shl eax, 0xa
// 0056d860  03d0                 add edx, eax
// 0056d862  89542430             mov dword ptr [esp + 0x30], edx
// 0056d866  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056d86a  8b8bf4000000         mov ecx, dword ptr [ebx + 0xf4]
// 0056d870  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0056d874  42                   inc edx
// 0056d875  41                   inc ecx
// 0056d876  40                   inc eax
// 0056d877  837c241400           cmp dword ptr [esp + 0x14], 0
// 0056d87c  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0056d884  7640                 jbe 0x56d8c6
// 0056d886  8be8                 mov ebp, eax
// 0056d888  2bea                 sub ebp, edx
// 0056d88a  8d9b00000000         lea ebx, [ebx]
// 0056d890  8a02                 mov al, byte ptr [edx]
// 0056d892  2a042a               sub al, byte ptr [edx + ebp]
// 0056d895  41                   inc ecx
// 0056d896  8841ff               mov byte ptr [ecx - 1], al
// 0056d899  0fb6c0               movzx eax, al
// 0056d89c  42                   inc edx
// 0056d89d  3d80000000           cmp eax, 0x80
// 0056d8a2  7d04                 jge 0x56d8a8
// 0056d8a4  8bf0                 mov esi, eax
// 0056d8a6  eb07                 jmp 0x56d8af
// 0056d8a8  be00010000           mov esi, 0x100
// 0056d8ad  2bf0                 sub esi, eax
// 0056d8af  03fe                 add edi, esi
// 0056d8b1  3b7c2430             cmp edi, dword ptr [esp + 0x30]
// 0056d8b5  770f                 ja 0x56d8c6
// 0056d8b7  8b442434             mov eax, dword ptr [esp + 0x34]
// 0056d8bb  40                   inc eax
// 0056d8bc  89442434             mov dword ptr [esp + 0x34], eax
// 0056d8c0  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0056d8c4  72ca                 jb 0x56d890
// 0056d8c6  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0056d8cd  7577                 jne 0x56d946
// 0056d8cf  0fb7f7               movzx esi, di
// 0056d8d2  c1ef0a               shr edi, 0xa
// 0056d8d5  81e7c0ff3f00         and edi, 0x3fffc0
// 0056d8db  33c9                 xor ecx, ecx
// 0056d8dd  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0056d8e1  8bd7                 mov edx, edi
// 0056d8e3  7e34                 jle 0x56d919
// 0056d8e5  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 0056d8eb  eb03                 jmp 0x56d8f0
// 0056d8ed  8d4900               lea ecx, [ecx]
// 0056d8f0  803c0f02             cmp byte ptr [edi + ecx], 2
// 0056d8f4  751c                 jne 0x56d912
// 0056d8f6  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0056d8fc  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0056d900  8be8                 mov ebp, eax
// 0056d902  0fafc2               imul eax, edx
// 0056d905  0fafee               imul ebp, esi
// 0056d908  c1ed08               shr ebp, 8
// 0056d90b  c1e808               shr eax, 8
// 0056d90e  8bf5                 mov esi, ebp
// 0056d910  8bd0                 mov edx, eax
// 0056d912  41                   inc ecx
// 0056d913  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0056d917  7cd7                 jl 0x56d8f0
// 0056d919  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0056d91f  0fb74904             movzx ecx, word ptr [ecx + 4]
// 0056d923  8bc1                 mov eax, ecx
// 0056d925  0fafc2               imul eax, edx
// 0056d928  c1e803               shr eax, 3
// 0056d92b  3dc0ff3f00           cmp eax, 0x3fffc0
// 0056d930  7607                 jbe 0x56d939
// 0056d932  bfffffff7f           mov edi, 0x7fffffff
// 0056d937  eb0d                 jmp 0x56d946
// 0056d939  0fafce               imul ecx, esi
// 0056d93c  c1e903               shr ecx, 3
// 0056d93f  c1e00a               shl eax, 0xa
// 0056d942  03c8                 add ecx, eax
// 0056d944  8bf9                 mov edi, ecx
// 0056d946  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 0056d94a  730e                 jae 0x56d95a
// 0056d94c  8b93f4000000         mov edx, dword ptr [ebx + 0xf4]
// 0056d952  897c241c             mov dword ptr [esp + 0x1c], edi
// 0056d956  89542418             mov dword ptr [esp + 0x18], edx
// 0056d95a  807c241340           cmp byte ptr [esp + 0x13], 0x40
// 0056d95f  0f8559feffff         jne 0x56d7be
// 0056d965  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0056d969  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 0056d96f  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0056d973  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056d977  45                   inc ebp
// 0056d978  33c0                 xor eax, eax
// 0056d97a  41                   inc ecx
// 0056d97b  46                   inc esi
// 0056d97c  8bfd                 mov edi, ebp
// 0056d97e  85d2                 test edx, edx
// 0056d980  7626                 jbe 0x56d9a8
// 0056d982  89542444             mov dword ptr [esp + 0x44], edx
// 0056d986  89542438             mov dword ptr [esp + 0x38], edx
// 0056d98a  8d9b00000000         lea ebx, [ebx]
// 0056d990  8a06                 mov al, byte ptr [esi]
// 0056d992  8a17                 mov dl, byte ptr [edi]
// 0056d994  d0e8                 shr al, 1
// 0056d996  2ad0                 sub dl, al
// 0056d998  8811                 mov byte ptr [ecx], dl
// 0056d99a  41                   inc ecx
// 0056d99b  46                   inc esi
// 0056d99c  47                   inc edi
// 0056d99d  836c244401           sub dword ptr [esp + 0x44], 1
// 0056d9a2  75ec                 jne 0x56d990
// 0056d9a4  8b442438             mov eax, dword ptr [esp + 0x38]
// 0056d9a8  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0056d9ac  7331                 jae 0x56d9df
// 0056d9ae  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056d9b2  2bd0                 sub edx, eax
// 0056d9b4  89542444             mov dword ptr [esp + 0x44], edx
// 0056d9b8  eb06                 jmp 0x56d9c0
// 0056d9ba  8d9b00000000         lea ebx, [ebx]
// 0056d9c0  0fb65500             movzx edx, byte ptr [ebp]
// 0056d9c4  0fb606               movzx eax, byte ptr [esi]
// 0056d9c7  03c2                 add eax, edx
// 0056d9c9  99                   cdq 
// 0056d9ca  2bc2                 sub eax, edx
// 0056d9cc  8a17                 mov dl, byte ptr [edi]
// 0056d9ce  d1f8                 sar eax, 1
// 0056d9d0  2ad0                 sub dl, al
// 0056d9d2  8811                 mov byte ptr [ecx], dl
// 0056d9d4  41                   inc ecx
// 0056d9d5  45                   inc ebp
// 0056d9d6  46                   inc esi
// 0056d9d7  47                   inc edi
// 0056d9d8  836c244401           sub dword ptr [esp + 0x44], 1
// 0056d9dd  75e1                 jne 0x56d9c0
// 0056d9df  8b83f8000000         mov eax, dword ptr [ebx + 0xf8]
// 0056d9e5  89442418             mov dword ptr [esp + 0x18], eax
// 0056d9e9  f644241380           test byte ptr [esp + 0x13], 0x80
// 0056d9ee  0f84a6040000         je 0x56de9a
// 0056d9f4  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056d9f8  33ed                 xor ebp, ebp
// 0056d9fa  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0056da01  896c2430             mov dword ptr [esp + 0x30], ebp
// 0056da05  894c2420             mov dword ptr [esp + 0x20], ecx
// 0056da09  0f85c7020000         jne 0x56dcd6
// 0056da0f  0fb7f1               movzx esi, cx
// 0056da12  c1e90a               shr ecx, 0xa
// 0056da15  33d2                 xor edx, edx
// 0056da17  81e1c0ff3f00         and ecx, 0x3fffc0
// 0056da1d  39542448             cmp dword ptr [esp + 0x48], edx
// 0056da21  7e2f                 jle 0x56da52
// 0056da23  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0056da29  803c0204             cmp byte ptr [edx + eax], 4
// 0056da2d  751c                 jne 0x56da4b
// 0056da2f  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0056da35  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0056da39  8bf8                 mov edi, eax
// 0056da3b  0fafc1               imul eax, ecx
// 0056da3e  0faffe               imul edi, esi
// 0056da41  c1ef08               shr edi, 8
// 0056da44  c1e808               shr eax, 8
// 0056da47  8bf7                 mov esi, edi
// 0056da49  8bc8                 mov ecx, eax
// 0056da4b  42                   inc edx
// 0056da4c  3b542448             cmp edx, dword ptr [esp + 0x48]
// 0056da50  7cd1                 jl 0x56da23
// 0056da52  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0056da58  0fb75208             movzx edx, word ptr [edx + 8]
// 0056da5c  8bc2                 mov eax, edx
// 0056da5e  0fafc1               imul eax, ecx
// 0056da61  c1e803               shr eax, 3
// 0056da64  3dc0ff3f00           cmp eax, 0x3fffc0
// 0056da69  0f8658020000         jbe 0x56dcc7
// 0056da6f  c7442420ffffff7f     mov dword ptr [esp + 0x20], 0x7fffffff
// 0056da77  e95a020000           jmp 0x56dcd6
// 0056da7c  0fafd6               imul edx, esi
// 0056da7f  c1ea03               shr edx, 3
// 0056da82  c1e00a               shl eax, 0xa
// 0056da85  03d0                 add edx, eax
// 0056da87  89542434             mov dword ptr [esp + 0x34], edx
// 0056da8b  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0056da8f  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 0056da95  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0056da99  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056da9d  45                   inc ebp
// 0056da9e  41                   inc ecx
// 0056da9f  46                   inc esi
// 0056daa0  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0056daa8  8bfd                 mov edi, ebp
// 0056daaa  85c0                 test eax, eax
// 0056daac  7635                 jbe 0x56dae3
// 0056daae  89442438             mov dword ptr [esp + 0x38], eax
// 0056dab2  89442430             mov dword ptr [esp + 0x30], eax
// 0056dab6  8a16                 mov dl, byte ptr [esi]
// 0056dab8  8a07                 mov al, byte ptr [edi]
// 0056daba  d0ea                 shr dl, 1
// 0056dabc  2ac2                 sub al, dl
// 0056dabe  8801                 mov byte ptr [ecx], al
// 0056dac0  0fb6c0               movzx eax, al
// 0056dac3  41                   inc ecx
// 0056dac4  46                   inc esi
// 0056dac5  47                   inc edi
// 0056dac6  3d80000000           cmp eax, 0x80
// 0056dacb  7d04                 jge 0x56dad1
// 0056dacd  8bd0                 mov edx, eax
// 0056dacf  eb07                 jmp 0x56dad8
// 0056dad1  ba00010000           mov edx, 0x100
// 0056dad6  2bd0                 sub edx, eax
// 0056dad8  01542420             add dword ptr [esp + 0x20], edx
// 0056dadc  836c243801           sub dword ptr [esp + 0x38], 1
// 0056dae1  75d3                 jne 0x56dab6
// 0056dae3  8b442414             mov eax, dword ptr [esp + 0x14]
// 0056dae7  39442430             cmp dword ptr [esp + 0x30], eax
// 0056daeb  7351                 jae 0x56db3e
// 0056daed  8d4900               lea ecx, [ecx]
// 0056daf0  0fb616               movzx edx, byte ptr [esi]
// 0056daf3  0fb64500             movzx eax, byte ptr [ebp]
// 0056daf7  03c2                 add eax, edx
// 0056daf9  99                   cdq 
// 0056dafa  2bc2                 sub eax, edx
// 0056dafc  8bd0                 mov edx, eax
// 0056dafe  8a07                 mov al, byte ptr [edi]
// 0056db00  d1fa                 sar edx, 1
// 0056db02  2ac2                 sub al, dl
// 0056db04  8801                 mov byte ptr [ecx], al
// 0056db06  0fb6c0               movzx eax, al
// 0056db09  41                   inc ecx
// 0056db0a  45                   inc ebp
// 0056db0b  46                   inc esi
// 0056db0c  47                   inc edi
// 0056db0d  3d80000000           cmp eax, 0x80
// 0056db12  7d04                 jge 0x56db18
// 0056db14  8bd0                 mov edx, eax
// 0056db16  eb07                 jmp 0x56db1f
// 0056db18  ba00010000           mov edx, 0x100
// 0056db1d  2bd0                 sub edx, eax
// 0056db1f  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056db23  03c2                 add eax, edx
// 0056db25  89442420             mov dword ptr [esp + 0x20], eax
// 0056db29  3b442434             cmp eax, dword ptr [esp + 0x34]
// 0056db2d  770f                 ja 0x56db3e
// 0056db2f  8b442430             mov eax, dword ptr [esp + 0x30]
// 0056db33  40                   inc eax
// 0056db34  89442430             mov dword ptr [esp + 0x30], eax
// 0056db38  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0056db3c  72b2                 jb 0x56daf0
// 0056db3e  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0056db45  7579                 jne 0x56dbc0
// 0056db47  8b542420             mov edx, dword ptr [esp + 0x20]
// 0056db4b  0fb7f2               movzx esi, dx
// 0056db4e  c1ea0a               shr edx, 0xa
// 0056db51  33c9                 xor ecx, ecx
// 0056db53  81e2c0ff3f00         and edx, 0x3fffc0
// 0056db59  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0056db5d  7e2f                 jle 0x56db8e
// 0056db5f  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 0056db65  803c3900             cmp byte ptr [ecx + edi], 0
// 0056db69  751c                 jne 0x56db87
// 0056db6b  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0056db71  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0056db75  8be8                 mov ebp, eax
// 0056db77  0fafc2               imul eax, edx
// 0056db7a  0fafee               imul ebp, esi
// 0056db7d  c1ed08               shr ebp, 8
// 0056db80  c1e808               shr eax, 8
// 0056db83  8bf5                 mov esi, ebp
// 0056db85  8bd0                 mov edx, eax
// 0056db87  41                   inc ecx
// 0056db88  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0056db8c  7cd7                 jl 0x56db65
// 0056db8e  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0056db94  0fb74906             movzx ecx, word ptr [ecx + 6]
// 0056db98  8bc1                 mov eax, ecx
// 0056db9a  0fafc2               imul eax, edx
// 0056db9d  c1e803               shr eax, 3
// 0056dba0  3dc0ff3f00           cmp eax, 0x3fffc0
// 0056dba5  760a                 jbe 0x56dbb1
// 0056dba7  c7442420ffffff7f     mov dword ptr [esp + 0x20], 0x7fffffff
// 0056dbaf  eb0f                 jmp 0x56dbc0
// 0056dbb1  0fafce               imul ecx, esi
// 0056dbb4  c1e903               shr ecx, 3
// 0056dbb7  c1e00a               shl eax, 0xa
// 0056dbba  03c8                 add ecx, eax
// 0056dbbc  894c2420             mov dword ptr [esp + 0x20], ecx
// 0056dbc0  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056dbc4  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 0056dbc8  730e                 jae 0x56dbd8
// 0056dbca  8b93f8000000         mov edx, dword ptr [ebx + 0xf8]
// 0056dbd0  8944241c             mov dword ptr [esp + 0x1c], eax
// 0056dbd4  89542418             mov dword ptr [esp + 0x18], edx
// 0056dbd8  807c241380           cmp byte ptr [esp + 0x13], 0x80
// 0056dbdd  0f8506feffff         jne 0x56d9e9
// 0056dbe3  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056dbe7  8bbbfc000000         mov edi, dword ptr [ebx + 0xfc]
// 0056dbed  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0056dbf1  40                   inc eax
// 0056dbf2  42                   inc edx
// 0056dbf3  47                   inc edi
// 0056dbf4  837c242400           cmp dword ptr [esp + 0x24], 0
// 0056dbf9  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0056dc01  8bc8                 mov ecx, eax
// 0056dc03  89442430             mov dword ptr [esp + 0x30], eax
// 0056dc07  8bf2                 mov esi, edx
// 0056dc09  761b                 jbe 0x56dc26
// 0056dc0b  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0056dc0f  896c2434             mov dword ptr [esp + 0x34], ebp
// 0056dc13  8a19                 mov bl, byte ptr [ecx]
// 0056dc15  2a1e                 sub bl, byte ptr [esi]
// 0056dc17  47                   inc edi
// 0056dc18  885fff               mov byte ptr [edi - 1], bl
// 0056dc1b  46                   inc esi
// 0056dc1c  41                   inc ecx
// 0056dc1d  83ed01               sub ebp, 1
// 0056dc20  75f1                 jne 0x56dc13
// 0056dc22  894c2430             mov dword ptr [esp + 0x30], ecx
// 0056dc26  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0056dc2a  8be8                 mov ebp, eax
// 0056dc2c  395c2434             cmp dword ptr [esp + 0x34], ebx
// 0056dc30  0f8388000000         jae 0x56dcbe
// 0056dc36  8bca                 mov ecx, edx
// 0056dc38  2bc8                 sub ecx, eax
// 0056dc3a  2b5c2434             sub ebx, dword ptr [esp + 0x34]
// 0056dc3e  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0056dc42  895c2434             mov dword ptr [esp + 0x34], ebx
// 0056dc46  eb0c                 jmp 0x56dc54
// 0056dc48  eb06                 jmp 0x56dc50
// 0056dc4a  8d9b00000000         lea ebx, [ebx]
// 0056dc50  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0056dc54  0fb61429             movzx edx, byte ptr [ecx + ebp]
// 0056dc58  0fb606               movzx eax, byte ptr [esi]
// 0056dc5b  0fb64d00             movzx ecx, byte ptr [ebp]
// 0056dc5f  89442424             mov dword ptr [esp + 0x24], eax
// 0056dc63  894c2428             mov dword ptr [esp + 0x28], ecx
// 0056dc67  2bc2                 sub eax, edx
// 0056dc69  46                   inc esi
// 0056dc6a  45                   inc ebp
// 0056dc6b  2bca                 sub ecx, edx
// 0056dc6d  85c0                 test eax, eax
// 0056dc6f  7d0a                 jge 0x56dc7b
// 0056dc71  8bd8                 mov ebx, eax
// 0056dc73  f7db                 neg ebx
// 0056dc75  895c2438             mov dword ptr [esp + 0x38], ebx
// 0056dc79  eb04                 jmp 0x56dc7f
// 0056dc7b  89442438             mov dword ptr [esp + 0x38], eax
// 0056dc7f  8bd9                 mov ebx, ecx
// 0056dc81  85c9                 test ecx, ecx
// 0056dc83  7d02                 jge 0x56dc87
// 0056dc85  f7db                 neg ebx
// 0056dc87  03c1                 add eax, ecx
// 0056dc89  7902                 jns 0x56dc8d
// 0056dc8b  f7d8                 neg eax
// 0056dc8d  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0056dc91  3bcb                 cmp ecx, ebx
// 0056dc93  7f0a                 jg 0x56dc9f
// 0056dc95  3bc8                 cmp ecx, eax
// 0056dc97  7f06                 jg 0x56dc9f
// 0056dc99  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056dc9d  eb08                 jmp 0x56dca7
// 0056dc9f  3bd8                 cmp ebx, eax
// 0056dca1  7f04                 jg 0x56dca7
// 0056dca3  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056dca7  8b442430             mov eax, dword ptr [esp + 0x30]
// 0056dcab  8a08                 mov cl, byte ptr [eax]
// 0056dcad  2aca                 sub cl, dl
// 0056dcaf  880f                 mov byte ptr [edi], cl
// 0056dcb1  40                   inc eax
// 0056dcb2  47                   inc edi
// 0056dcb3  836c243401           sub dword ptr [esp + 0x34], 1
// 0056dcb8  89442430             mov dword ptr [esp + 0x30], eax
// 0056dcbc  7592                 jne 0x56dc50
// 0056dcbe  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 0056dcc2  e9c9010000           jmp 0x56de90
// 0056dcc7  0fafd6               imul edx, esi
// 0056dcca  c1ea03               shr edx, 3
// 0056dccd  c1e00a               shl eax, 0xa
// 0056dcd0  03d0                 add edx, eax
// 0056dcd2  89542420             mov dword ptr [esp + 0x20], edx
// 0056dcd6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0056dcda  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0056dcde  8bb3fc000000         mov esi, dword ptr [ebx + 0xfc]
// 0056dce4  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056dce8  47                   inc edi
// 0056dce9  42                   inc edx
// 0056dcea  46                   inc esi
// 0056dceb  c744244400000000     mov dword ptr [esp + 0x44], 0
// 0056dcf3  897c2428             mov dword ptr [esp + 0x28], edi
// 0056dcf7  897c2434             mov dword ptr [esp + 0x34], edi
// 0056dcfb  8954242c             mov dword ptr [esp + 0x2c], edx
// 0056dcff  85c0                 test eax, eax
// 0056dd01  763d                 jbe 0x56dd40
// 0056dd03  89442438             mov dword ptr [esp + 0x38], eax
// 0056dd07  89442444             mov dword ptr [esp + 0x44], eax
// 0056dd0b  eb03                 jmp 0x56dd10
// 0056dd0d  8d4900               lea ecx, [ecx]
// 0056dd10  8a07                 mov al, byte ptr [edi]
// 0056dd12  2a02                 sub al, byte ptr [edx]
// 0056dd14  46                   inc esi
// 0056dd15  8846ff               mov byte ptr [esi - 1], al
// 0056dd18  0fb6c0               movzx eax, al
// 0056dd1b  42                   inc edx
// 0056dd1c  47                   inc edi
// 0056dd1d  3d80000000           cmp eax, 0x80
// 0056dd22  7d04                 jge 0x56dd28
// 0056dd24  8bc8                 mov ecx, eax
// 0056dd26  eb07                 jmp 0x56dd2f
// 0056dd28  b900010000           mov ecx, 0x100
// 0056dd2d  2bc8                 sub ecx, eax
// 0056dd2f  03e9                 add ebp, ecx
// 0056dd31  836c243801           sub dword ptr [esp + 0x38], 1
// 0056dd36  75d8                 jne 0x56dd10
// 0056dd38  896c2430             mov dword ptr [esp + 0x30], ebp
// 0056dd3c  897c2434             mov dword ptr [esp + 0x34], edi
// 0056dd40  8b442444             mov eax, dword ptr [esp + 0x44]
// 0056dd44  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0056dd48  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0056dd4c  0f83b8000000         jae 0x56de0a
// 0056dd52  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056dd56  2bf9                 sub edi, ecx
// 0056dd58  897c242c             mov dword ptr [esp + 0x2c], edi
// 0056dd5c  eb0e                 jmp 0x56dd6c
// 0056dd5e  8bff                 mov edi, edi
// 0056dd60  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056dd64  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0056dd68  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056dd6c  0fb602               movzx eax, byte ptr [edx]
// 0056dd6f  42                   inc edx
// 0056dd70  89542428             mov dword ptr [esp + 0x28], edx
// 0056dd74  0fb6140f             movzx edx, byte ptr [edi + ecx]
// 0056dd78  0fb639               movzx edi, byte ptr [ecx]
// 0056dd7b  41                   inc ecx
// 0056dd7c  894c2424             mov dword ptr [esp + 0x24], ecx
// 0056dd80  8944243c             mov dword ptr [esp + 0x3c], eax
// 0056dd84  8bcf                 mov ecx, edi
// 0056dd86  2bc2                 sub eax, edx
// 0056dd88  2bca                 sub ecx, edx
// 0056dd8a  85c0                 test eax, eax
// 0056dd8c  7d0a                 jge 0x56dd98
// 0056dd8e  8be8                 mov ebp, eax
// 0056dd90  f7dd                 neg ebp
// 0056dd92  896c2438             mov dword ptr [esp + 0x38], ebp
// 0056dd96  eb04                 jmp 0x56dd9c
// 0056dd98  89442438             mov dword ptr [esp + 0x38], eax
// 0056dd9c  8be9                 mov ebp, ecx
// 0056dd9e  85c9                 test ecx, ecx
// 0056dda0  7d02                 jge 0x56dda4
// 0056dda2  f7dd                 neg ebp
// 0056dda4  03c1                 add eax, ecx
// 0056dda6  7902                 jns 0x56ddaa
// 0056dda8  f7d8                 neg eax
// 0056ddaa  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0056ddae  3bcd                 cmp ecx, ebp
// 0056ddb0  7f08                 jg 0x56ddba
// 0056ddb2  3bc8                 cmp ecx, eax
// 0056ddb4  7f04                 jg 0x56ddba
// 0056ddb6  8bd7                 mov edx, edi
// 0056ddb8  eb08                 jmp 0x56ddc2
// 0056ddba  3be8                 cmp ebp, eax
// 0056ddbc  7f04                 jg 0x56ddc2
// 0056ddbe  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0056ddc2  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0056ddc6  8a01                 mov al, byte ptr [ecx]
// 0056ddc8  2ac2                 sub al, dl
// 0056ddca  8806                 mov byte ptr [esi], al
// 0056ddcc  0fb6c0               movzx eax, al
// 0056ddcf  41                   inc ecx
// 0056ddd0  46                   inc esi
// 0056ddd1  3d80000000           cmp eax, 0x80
// 0056ddd6  894c2434             mov dword ptr [esp + 0x34], ecx
// 0056ddda  7d04                 jge 0x56dde0
// 0056dddc  8bc8                 mov ecx, eax
// 0056ddde  eb07                 jmp 0x56dde7
// 0056dde0  b900010000           mov ecx, 0x100
// 0056dde5  2bc8                 sub ecx, eax
// 0056dde7  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 0056ddeb  03e9                 add ebp, ecx
// 0056dded  896c2430             mov dword ptr [esp + 0x30], ebp
// 0056ddf1  3b6c2420             cmp ebp, dword ptr [esp + 0x20]
// 0056ddf5  7713                 ja 0x56de0a
// 0056ddf7  8b442444             mov eax, dword ptr [esp + 0x44]
// 0056ddfb  40                   inc eax
// 0056ddfc  89442444             mov dword ptr [esp + 0x44], eax
// 0056de00  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0056de04  0f8256ffffff         jb 0x56dd60
// 0056de0a  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0056de11  7577                 jne 0x56de8a
// 0056de13  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 0056de17  0fb7f5               movzx esi, bp
// 0056de1a  c1ed0a               shr ebp, 0xa
// 0056de1d  81e5c0ff3f00         and ebp, 0x3fffc0
// 0056de23  33c9                 xor ecx, ecx
// 0056de25  8bd5                 mov edx, ebp
// 0056de27  85ff                 test edi, edi
// 0056de29  7e32                 jle 0x56de5d
// 0056de2b  eb03                 jmp 0x56de30
// 0056de2d  8d4900               lea ecx, [ecx]
// 0056de30  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0056de36  803c0104             cmp byte ptr [ecx + eax], 4
// 0056de3a  751c                 jne 0x56de58
// 0056de3c  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0056de42  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0056de46  8be8                 mov ebp, eax
// 0056de48  0fafc2               imul eax, edx
// 0056de4b  0fafee               imul ebp, esi
// 0056de4e  c1ed08               shr ebp, 8
// 0056de51  c1e808               shr eax, 8
// 0056de54  8bf5                 mov esi, ebp
// 0056de56  8bd0                 mov edx, eax
// 0056de58  41                   inc ecx
// 0056de59  3bcf                 cmp ecx, edi
// 0056de5b  7cd3                 jl 0x56de30
// 0056de5d  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0056de63  0fb74908             movzx ecx, word ptr [ecx + 8]
// 0056de67  8bc1                 mov eax, ecx
// 0056de69  0fafc2               imul eax, edx
// 0056de6c  c1e803               shr eax, 3
// 0056de6f  3dc0ff3f00           cmp eax, 0x3fffc0
// 0056de74  7607                 jbe 0x56de7d
// 0056de76  bdffffff7f           mov ebp, 0x7fffffff
// 0056de7b  eb0d                 jmp 0x56de8a
// 0056de7d  0fafce               imul ecx, esi
// 0056de80  c1e903               shr ecx, 3
// 0056de83  c1e00a               shl eax, 0xa
// 0056de86  03c8                 add ecx, eax
// 0056de88  8be9                 mov ebp, ecx
// 0056de8a  3b6c241c             cmp ebp, dword ptr [esp + 0x1c]
// 0056de8e  730a                 jae 0x56de9a
// 0056de90  8b93fc000000         mov edx, dword ptr [ebx + 0xfc]
// 0056de96  89542418             mov dword ptr [esp + 0x18], edx
// 0056de9a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0056de9e  50                   push eax
// 0056de9f  53                   push ebx
// 0056dea0  e84bf4ffff           call 0x56d2f0
// 0056dea5  83c408               add esp, 8
// 0056dea8  80bbf901000000       cmp byte ptr [ebx + 0x1f9], 0
// 0056deaf  7633                 jbe 0x56dee4
// 0056deb1  b801000000           mov eax, 1
// 0056deb6  39442448             cmp dword ptr [esp + 0x48], eax
// 0056deba  7e19                 jle 0x56ded5
// 0056debc  8d642400             lea esp, [esp]
// 0056dec0  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 0056dec6  8a5401ff             mov dl, byte ptr [ecx + eax - 1]
// 0056deca  03c8                 add ecx, eax
// 0056decc  40                   inc eax
// 0056decd  3b442448             cmp eax, dword ptr [esp + 0x48]
// 0056ded1  8811                 mov byte ptr [ecx], dl
// 0056ded3  7ceb                 jl 0x56dec0
// 0056ded5  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056ded9  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 0056dedf  8a12                 mov dl, byte ptr [edx]
// 0056dee1  881408               mov byte ptr [eax + ecx], dl
// 0056dee4  5f                   pop edi
// 0056dee5  5e                   pop esi
// 0056dee6  5d                   pop ebp
// 0056dee7  5b                   pop ebx
// 0056dee8  83c430               add esp, 0x30
// 0056deeb  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_find_filter)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
