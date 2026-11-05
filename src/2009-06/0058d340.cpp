// from server: 100% by auto
// roc 2009-06 0058d340  unit: seg_00580000  size: 2860 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058d340
//
// 0058d340  83ec30               sub esp, 0x30
// 0058d343  8b442438             mov eax, dword ptr [esp + 0x38]
// 0058d347  53                   push ebx
// 0058d348  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 0058d34c  8a8b25010000         mov cl, byte ptr [ebx + 0x125]
// 0058d352  0fb693f9010000       movzx edx, byte ptr [ebx + 0x1f9]
// 0058d359  55                   push ebp
// 0058d35a  8b6804               mov ebp, dword ptr [eax + 4]
// 0058d35d  56                   push esi
// 0058d35e  57                   push edi
// 0058d35f  0fb6780b             movzx edi, byte ptr [eax + 0xb]
// 0058d363  8b83e8000000         mov eax, dword ptr [ebx + 0xe8]
// 0058d369  83c707               add edi, 7
// 0058d36c  c1ff03               sar edi, 3
// 0058d36f  8944242c             mov dword ptr [esp + 0x2c], eax
// 0058d373  8b83ec000000         mov eax, dword ptr [ebx + 0xec]
// 0058d379  884c2413             mov byte ptr [esp + 0x13], cl
// 0058d37d  896c2414             mov dword ptr [esp + 0x14], ebp
// 0058d381  89542448             mov dword ptr [esp + 0x48], edx
// 0058d385  897c2424             mov dword ptr [esp + 0x24], edi
// 0058d389  89442418             mov dword ptr [esp + 0x18], eax
// 0058d38d  89442428             mov dword ptr [esp + 0x28], eax
// 0058d391  c744241cffffff7f     mov dword ptr [esp + 0x1c], 0x7fffffff
// 0058d399  f6c108               test cl, 8
// 0058d39c  0f84bd000000         je 0x58d45f
// 0058d3a2  80f908               cmp cl, 8
// 0058d3a5  0f84b4000000         je 0x58d45f
// 0058d3ab  33c0                 xor eax, eax
// 0058d3ad  33d2                 xor edx, edx
// 0058d3af  85ed                 test ebp, ebp
// 0058d3b1  7630                 jbe 0x58d3e3
// 0058d3b3  eb0b                 jmp 0x58d3c0
// 0058d3b5  8da42400000000       lea esp, [esp]
// 0058d3bc  8d642400             lea esp, [esp]
// 0058d3c0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0058d3c4  0fb6741101           movzx esi, byte ptr [ecx + edx + 1]
// 0058d3c9  81fe80000000         cmp esi, 0x80
// 0058d3cf  7d04                 jge 0x58d3d5
// 0058d3d1  8bce                 mov ecx, esi
// 0058d3d3  eb07                 jmp 0x58d3dc
// 0058d3d5  b900010000           mov ecx, 0x100
// 0058d3da  2bce                 sub ecx, esi
// 0058d3dc  42                   inc edx
// 0058d3dd  03c1                 add eax, ecx
// 0058d3df  3bd5                 cmp edx, ebp
// 0058d3e1  72dd                 jb 0x58d3c0
// 0058d3e3  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0058d3ea  756f                 jne 0x58d45b
// 0058d3ec  0fb7f0               movzx esi, ax
// 0058d3ef  c1e80a               shr eax, 0xa
// 0058d3f2  25c0ff3f00           and eax, 0x3fffc0
// 0058d3f7  33c9                 xor ecx, ecx
// 0058d3f9  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0058d3fd  8bd0                 mov edx, eax
// 0058d3ff  7e2f                 jle 0x58d430
// 0058d401  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0058d407  803c0800             cmp byte ptr [eax + ecx], 0
// 0058d40b  751c                 jne 0x58d429
// 0058d40d  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0058d413  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0058d417  8be8                 mov ebp, eax
// 0058d419  0fafc2               imul eax, edx
// 0058d41c  0fafee               imul ebp, esi
// 0058d41f  c1ed08               shr ebp, 8
// 0058d422  c1e808               shr eax, 8
// 0058d425  8bf5                 mov esi, ebp
// 0058d427  8bd0                 mov edx, eax
// 0058d429  41                   inc ecx
// 0058d42a  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0058d42e  7cd1                 jl 0x58d401
// 0058d430  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0058d436  0fb701               movzx eax, word ptr [ecx]
// 0058d439  8bc8                 mov ecx, eax
// 0058d43b  0fafca               imul ecx, edx
// 0058d43e  c1e903               shr ecx, 3
// 0058d441  81f9c0ff3f00         cmp ecx, 0x3fffc0
// 0058d447  7607                 jbe 0x58d450
// 0058d449  b8ffffff7f           mov eax, 0x7fffffff
// 0058d44e  eb0b                 jmp 0x58d45b
// 0058d450  0fafc6               imul eax, esi
// 0058d453  c1e803               shr eax, 3
// 0058d456  c1e10a               shl ecx, 0xa
// 0058d459  03c1                 add eax, ecx
// 0058d45b  8944241c             mov dword ptr [esp + 0x1c], eax
// 0058d45f  8a442413             mov al, byte ptr [esp + 0x13]
// 0058d463  3c10                 cmp al, 0x10
// 0058d465  0f85dc000000         jne 0x58d547
// 0058d46b  8b742418             mov esi, dword ptr [esp + 0x18]
// 0058d46f  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 0058d475  46                   inc esi
// 0058d476  33ed                 xor ebp, ebp
// 0058d478  40                   inc eax
// 0058d479  8bce                 mov ecx, esi
// 0058d47b  85ff                 test edi, edi
// 0058d47d  760d                 jbe 0x58d48c
// 0058d47f  8bef                 mov ebp, edi
// 0058d481  8a11                 mov dl, byte ptr [ecx]
// 0058d483  8810                 mov byte ptr [eax], dl
// 0058d485  41                   inc ecx
// 0058d486  40                   inc eax
// 0058d487  83ef01               sub edi, 1
// 0058d48a  75f5                 jne 0x58d481
// 0058d48c  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 0058d490  7314                 jae 0x58d4a6
// 0058d492  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0058d496  2bfd                 sub edi, ebp
// 0058d498  8a11                 mov dl, byte ptr [ecx]
// 0058d49a  2a16                 sub dl, byte ptr [esi]
// 0058d49c  41                   inc ecx
// 0058d49d  8810                 mov byte ptr [eax], dl
// 0058d49f  46                   inc esi
// 0058d4a0  40                   inc eax
// 0058d4a1  83ef01               sub edi, 1
// 0058d4a4  75f2                 jne 0x58d498
// 0058d4a6  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 0058d4ac  89442418             mov dword ptr [esp + 0x18], eax
// 0058d4b0  f644241320           test byte ptr [esp + 0x13], 0x20
// 0058d4b5  0f841f040000         je 0x58d8da
// 0058d4bb  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0058d4bf  33ff                 xor edi, edi
// 0058d4c1  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0058d4c8  894c2430             mov dword ptr [esp + 0x30], ecx
// 0058d4cc  0f8514030000         jne 0x58d7e6
// 0058d4d2  0fb7f1               movzx esi, cx
// 0058d4d5  c1e90a               shr ecx, 0xa
// 0058d4d8  33d2                 xor edx, edx
// 0058d4da  81e1c0ff3f00         and ecx, 0x3fffc0
// 0058d4e0  39542448             cmp dword ptr [esp + 0x48], edx
// 0058d4e4  89742434             mov dword ptr [esp + 0x34], esi
// 0058d4e8  7e33                 jle 0x58d51d
// 0058d4ea  8babfc010000         mov ebp, dword ptr [ebx + 0x1fc]
// 0058d4f0  803c2a02             cmp byte ptr [edx + ebp], 2
// 0058d4f4  7520                 jne 0x58d516
// 0058d4f6  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0058d4fc  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0058d500  8bf0                 mov esi, eax
// 0058d502  0fafc1               imul eax, ecx
// 0058d505  0faf742434           imul esi, dword ptr [esp + 0x34]
// 0058d50a  c1ee08               shr esi, 8
// 0058d50d  c1e808               shr eax, 8
// 0058d510  89742434             mov dword ptr [esp + 0x34], esi
// 0058d514  8bc8                 mov ecx, eax
// 0058d516  42                   inc edx
// 0058d517  3b542448             cmp edx, dword ptr [esp + 0x48]
// 0058d51b  7cd3                 jl 0x58d4f0
// 0058d51d  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0058d523  0fb75204             movzx edx, word ptr [edx + 4]
// 0058d527  8bc2                 mov eax, edx
// 0058d529  0fafc1               imul eax, ecx
// 0058d52c  c1e803               shr eax, 3
// 0058d52f  3dc0ff3f00           cmp eax, 0x3fffc0
// 0058d534  0f869d020000         jbe 0x58d7d7
// 0058d53a  c7442430ffffff7f     mov dword ptr [esp + 0x30], 0x7fffffff
// 0058d542  e99f020000           jmp 0x58d7e6
// 0058d547  a810                 test al, 0x10
// 0058d549  0f84ac010000         je 0x58d6fb
// 0058d54f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0058d553  33ff                 xor edi, edi
// 0058d555  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0058d55c  894c2430             mov dword ptr [esp + 0x30], ecx
// 0058d560  757f                 jne 0x58d5e1
// 0058d562  0fb7f1               movzx esi, cx
// 0058d565  c1e90a               shr ecx, 0xa
// 0058d568  81e1c0ff3f00         and ecx, 0x3fffc0
// 0058d56e  33d2                 xor edx, edx
// 0058d570  397c2448             cmp dword ptr [esp + 0x48], edi
// 0058d574  7e39                 jle 0x58d5af
// 0058d576  eb08                 jmp 0x58d580
// 0058d578  8da42400000000       lea esp, [esp]
// 0058d57f  90                   nop 
// 0058d580  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0058d586  803c1001             cmp byte ptr [eax + edx], 1
// 0058d58a  751c                 jne 0x58d5a8
// 0058d58c  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0058d592  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0058d596  8be8                 mov ebp, eax
// 0058d598  0fafc1               imul eax, ecx
// 0058d59b  0fafee               imul ebp, esi
// 0058d59e  c1ed08               shr ebp, 8
// 0058d5a1  c1e808               shr eax, 8
// 0058d5a4  8bf5                 mov esi, ebp
// 0058d5a6  8bc8                 mov ecx, eax
// 0058d5a8  42                   inc edx
// 0058d5a9  3b542448             cmp edx, dword ptr [esp + 0x48]
// 0058d5ad  7cd1                 jl 0x58d580
// 0058d5af  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0058d5b5  0fb75202             movzx edx, word ptr [edx + 2]
// 0058d5b9  8bc2                 mov eax, edx
// 0058d5bb  0fafc1               imul eax, ecx
// 0058d5be  c1e803               shr eax, 3
// 0058d5c1  3dc0ff3f00           cmp eax, 0x3fffc0
// 0058d5c6  760a                 jbe 0x58d5d2
// 0058d5c8  c7442430ffffff7f     mov dword ptr [esp + 0x30], 0x7fffffff
// 0058d5d0  eb0f                 jmp 0x58d5e1
// 0058d5d2  0fafd6               imul edx, esi
// 0058d5d5  c1ea03               shr edx, 3
// 0058d5d8  c1e00a               shl eax, 0xa
// 0058d5db  03d0                 add edx, eax
// 0058d5dd  89542430             mov dword ptr [esp + 0x30], edx
// 0058d5e1  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0058d5e5  8b8bf0000000         mov ecx, dword ptr [ebx + 0xf0]
// 0058d5eb  8b442424             mov eax, dword ptr [esp + 0x24]
// 0058d5ef  45                   inc ebp
// 0058d5f0  41                   inc ecx
// 0058d5f1  897c2420             mov dword ptr [esp + 0x20], edi
// 0058d5f5  896c2438             mov dword ptr [esp + 0x38], ebp
// 0058d5f9  8bd5                 mov edx, ebp
// 0058d5fb  85c0                 test eax, eax
// 0058d5fd  762d                 jbe 0x58d62c
// 0058d5ff  8be8                 mov ebp, eax
// 0058d601  89442420             mov dword ptr [esp + 0x20], eax
// 0058d605  8a02                 mov al, byte ptr [edx]
// 0058d607  0fb6f0               movzx esi, al
// 0058d60a  81fe80000000         cmp esi, 0x80
// 0058d610  8801                 mov byte ptr [ecx], al
// 0058d612  7d04                 jge 0x58d618
// 0058d614  8bc6                 mov eax, esi
// 0058d616  eb07                 jmp 0x58d61f
// 0058d618  b800010000           mov eax, 0x100
// 0058d61d  2bc6                 sub eax, esi
// 0058d61f  03f8                 add edi, eax
// 0058d621  42                   inc edx
// 0058d622  41                   inc ecx
// 0058d623  83ed01               sub ebp, 1
// 0058d626  75dd                 jne 0x58d605
// 0058d628  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 0058d62c  8b442414             mov eax, dword ptr [esp + 0x14]
// 0058d630  39442420             cmp dword ptr [esp + 0x20], eax
// 0058d634  7336                 jae 0x58d66c
// 0058d636  8a02                 mov al, byte ptr [edx]
// 0058d638  2a4500               sub al, byte ptr [ebp]
// 0058d63b  8801                 mov byte ptr [ecx], al
// 0058d63d  0fb6c0               movzx eax, al
// 0058d640  3d80000000           cmp eax, 0x80
// 0058d645  7d04                 jge 0x58d64b
// 0058d647  8bf0                 mov esi, eax
// 0058d649  eb07                 jmp 0x58d652
// 0058d64b  be00010000           mov esi, 0x100
// 0058d650  2bf0                 sub esi, eax
// 0058d652  03fe                 add edi, esi
// 0058d654  3b7c2430             cmp edi, dword ptr [esp + 0x30]
// 0058d658  7712                 ja 0x58d66c
// 0058d65a  8b442420             mov eax, dword ptr [esp + 0x20]
// 0058d65e  40                   inc eax
// 0058d65f  42                   inc edx
// 0058d660  45                   inc ebp
// 0058d661  41                   inc ecx
// 0058d662  89442420             mov dword ptr [esp + 0x20], eax
// 0058d666  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0058d66a  72ca                 jb 0x58d636
// 0058d66c  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0058d673  7572                 jne 0x58d6e7
// 0058d675  0fb7f7               movzx esi, di
// 0058d678  c1ef0a               shr edi, 0xa
// 0058d67b  81e7c0ff3f00         and edi, 0x3fffc0
// 0058d681  33c9                 xor ecx, ecx
// 0058d683  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0058d687  8bd7                 mov edx, edi
// 0058d689  7e2f                 jle 0x58d6ba
// 0058d68b  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 0058d691  803c0f01             cmp byte ptr [edi + ecx], 1
// 0058d695  751c                 jne 0x58d6b3
// 0058d697  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0058d69d  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0058d6a1  8be8                 mov ebp, eax
// 0058d6a3  0fafc2               imul eax, edx
// 0058d6a6  0fafee               imul ebp, esi
// 0058d6a9  c1ed08               shr ebp, 8
// 0058d6ac  c1e808               shr eax, 8
// 0058d6af  8bf5                 mov esi, ebp
// 0058d6b1  8bd0                 mov edx, eax
// 0058d6b3  41                   inc ecx
// 0058d6b4  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0058d6b8  7cd7                 jl 0x58d691
// 0058d6ba  8b8b0c020000         mov ecx, dword ptr [ebx + 0x20c]
// 0058d6c0  0fb74902             movzx ecx, word ptr [ecx + 2]
// 0058d6c4  8bc1                 mov eax, ecx
// 0058d6c6  0fafc2               imul eax, edx
// 0058d6c9  c1e803               shr eax, 3
// 0058d6cc  3dc0ff3f00           cmp eax, 0x3fffc0
// 0058d6d1  7607                 jbe 0x58d6da
// 0058d6d3  bfffffff7f           mov edi, 0x7fffffff
// 0058d6d8  eb0d                 jmp 0x58d6e7
// 0058d6da  0fafce               imul ecx, esi
// 0058d6dd  c1e903               shr ecx, 3
// 0058d6e0  c1e00a               shl eax, 0xa
// 0058d6e3  03c8                 add ecx, eax
// 0058d6e5  8bf9                 mov edi, ecx
// 0058d6e7  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 0058d6eb  730e                 jae 0x58d6fb
// 0058d6ed  8b93f0000000         mov edx, dword ptr [ebx + 0xf0]
// 0058d6f3  897c241c             mov dword ptr [esp + 0x1c], edi
// 0058d6f7  89542418             mov dword ptr [esp + 0x18], edx
// 0058d6fb  807c241320           cmp byte ptr [esp + 0x13], 0x20
// 0058d700  0f85aafdffff         jne 0x58d4b0
// 0058d706  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 0058d70c  8b542428             mov edx, dword ptr [esp + 0x28]
// 0058d710  33c9                 xor ecx, ecx
// 0058d712  40                   inc eax
// 0058d713  8d7a01               lea edi, [edx + 1]
// 0058d716  394c2414             cmp dword ptr [esp + 0x14], ecx
// 0058d71a  7618                 jbe 0x58d734
// 0058d71c  8bf7                 mov esi, edi
// 0058d71e  2bf2                 sub esi, edx
// 0058d720  0374242c             add esi, dword ptr [esp + 0x2c]
// 0058d724  8a1439               mov dl, byte ptr [ecx + edi]
// 0058d727  2a16                 sub dl, byte ptr [esi]
// 0058d729  41                   inc ecx
// 0058d72a  8810                 mov byte ptr [eax], dl
// 0058d72c  46                   inc esi
// 0058d72d  40                   inc eax
// 0058d72e  3b4c2414             cmp ecx, dword ptr [esp + 0x14]
// 0058d732  72f0                 jb 0x58d724
// 0058d734  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 0058d73a  89442418             mov dword ptr [esp + 0x18], eax
// 0058d73e  f644241340           test byte ptr [esp + 0x13], 0x40
// 0058d743  0f840f040000         je 0x58db58
// 0058d749  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0058d74d  33d2                 xor edx, edx
// 0058d74f  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0058d756  89542420             mov dword ptr [esp + 0x20], edx
// 0058d75a  894c2434             mov dword ptr [esp + 0x34], ecx
// 0058d75e  0f85a7020000         jne 0x58da0b
// 0058d764  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 0058d768  0fb7f1               movzx esi, cx
// 0058d76b  c1e90a               shr ecx, 0xa
// 0058d76e  81e1c0ff3f00         and ecx, 0x3fffc0
// 0058d774  3bfa                 cmp edi, edx
// 0058d776  7e35                 jle 0x58d7ad
// 0058d778  eb06                 jmp 0x58d780
// 0058d77a  8d9b00000000         lea ebx, [ebx]
// 0058d780  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0058d786  803c0203             cmp byte ptr [edx + eax], 3
// 0058d78a  751c                 jne 0x58d7a8
// 0058d78c  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0058d792  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0058d796  8be8                 mov ebp, eax
// 0058d798  0fafc1               imul eax, ecx
// 0058d79b  0fafee               imul ebp, esi
// 0058d79e  c1ed08               shr ebp, 8
// 0058d7a1  c1e808               shr eax, 8
// 0058d7a4  8bf5                 mov esi, ebp
// 0058d7a6  8bc8                 mov ecx, eax
// 0058d7a8  42                   inc edx
// 0058d7a9  3bd7                 cmp edx, edi
// 0058d7ab  7cd3                 jl 0x58d780
// 0058d7ad  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0058d7b3  0fb75206             movzx edx, word ptr [edx + 6]
// 0058d7b7  8bc2                 mov eax, edx
// 0058d7b9  0fafc1               imul eax, ecx
// 0058d7bc  c1e803               shr eax, 3
// 0058d7bf  3dc0ff3f00           cmp eax, 0x3fffc0
// 0058d7c4  0f8632020000         jbe 0x58d9fc
// 0058d7ca  c7442434ffffff7f     mov dword ptr [esp + 0x34], 0x7fffffff
// 0058d7d2  e934020000           jmp 0x58da0b
// 0058d7d7  0fafd6               imul edx, esi
// 0058d7da  c1ea03               shr edx, 3
// 0058d7dd  c1e00a               shl eax, 0xa
// 0058d7e0  03d0                 add edx, eax
// 0058d7e2  89542430             mov dword ptr [esp + 0x30], edx
// 0058d7e6  8b542428             mov edx, dword ptr [esp + 0x28]
// 0058d7ea  8b8bf4000000         mov ecx, dword ptr [ebx + 0xf4]
// 0058d7f0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0058d7f4  42                   inc edx
// 0058d7f5  41                   inc ecx
// 0058d7f6  40                   inc eax
// 0058d7f7  837c241400           cmp dword ptr [esp + 0x14], 0
// 0058d7fc  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0058d804  7640                 jbe 0x58d846
// 0058d806  8be8                 mov ebp, eax
// 0058d808  2bea                 sub ebp, edx
// 0058d80a  8d9b00000000         lea ebx, [ebx]
// 0058d810  8a02                 mov al, byte ptr [edx]
// 0058d812  2a042a               sub al, byte ptr [edx + ebp]
// 0058d815  41                   inc ecx
// 0058d816  8841ff               mov byte ptr [ecx - 1], al
// 0058d819  0fb6c0               movzx eax, al
// 0058d81c  42                   inc edx
// 0058d81d  3d80000000           cmp eax, 0x80
// 0058d822  7d04                 jge 0x58d828
// 0058d824  8bf0                 mov esi, eax
// 0058d826  eb07                 jmp 0x58d82f
// 0058d828  be00010000           mov esi, 0x100
// 0058d82d  2bf0                 sub esi, eax
// 0058d82f  03fe                 add edi, esi
// 0058d831  3b7c2430             cmp edi, dword ptr [esp + 0x30]
// 0058d835  770f                 ja 0x58d846
// 0058d837  8b442434             mov eax, dword ptr [esp + 0x34]
// 0058d83b  40                   inc eax
// 0058d83c  89442434             mov dword ptr [esp + 0x34], eax
// 0058d840  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0058d844  72ca                 jb 0x58d810
// 0058d846  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0058d84d  7577                 jne 0x58d8c6
// 0058d84f  0fb7f7               movzx esi, di
// 0058d852  c1ef0a               shr edi, 0xa
// 0058d855  81e7c0ff3f00         and edi, 0x3fffc0
// 0058d85b  33c9                 xor ecx, ecx
// 0058d85d  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0058d861  8bd7                 mov edx, edi
// 0058d863  7e34                 jle 0x58d899
// 0058d865  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 0058d86b  eb03                 jmp 0x58d870
// 0058d86d  8d4900               lea ecx, [ecx]
// 0058d870  803c0f02             cmp byte ptr [edi + ecx], 2
// 0058d874  751c                 jne 0x58d892
// 0058d876  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0058d87c  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0058d880  8be8                 mov ebp, eax
// 0058d882  0fafc2               imul eax, edx
// 0058d885  0fafee               imul ebp, esi
// 0058d888  c1ed08               shr ebp, 8
// 0058d88b  c1e808               shr eax, 8
// 0058d88e  8bf5                 mov esi, ebp
// 0058d890  8bd0                 mov edx, eax
// 0058d892  41                   inc ecx
// 0058d893  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0058d897  7cd7                 jl 0x58d870
// 0058d899  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0058d89f  0fb74904             movzx ecx, word ptr [ecx + 4]
// 0058d8a3  8bc1                 mov eax, ecx
// 0058d8a5  0fafc2               imul eax, edx
// 0058d8a8  c1e803               shr eax, 3
// 0058d8ab  3dc0ff3f00           cmp eax, 0x3fffc0
// 0058d8b0  7607                 jbe 0x58d8b9
// 0058d8b2  bfffffff7f           mov edi, 0x7fffffff
// 0058d8b7  eb0d                 jmp 0x58d8c6
// 0058d8b9  0fafce               imul ecx, esi
// 0058d8bc  c1e903               shr ecx, 3
// 0058d8bf  c1e00a               shl eax, 0xa
// 0058d8c2  03c8                 add ecx, eax
// 0058d8c4  8bf9                 mov edi, ecx
// 0058d8c6  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 0058d8ca  730e                 jae 0x58d8da
// 0058d8cc  8b93f4000000         mov edx, dword ptr [ebx + 0xf4]
// 0058d8d2  897c241c             mov dword ptr [esp + 0x1c], edi
// 0058d8d6  89542418             mov dword ptr [esp + 0x18], edx
// 0058d8da  807c241340           cmp byte ptr [esp + 0x13], 0x40
// 0058d8df  0f8559feffff         jne 0x58d73e
// 0058d8e5  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0058d8e9  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 0058d8ef  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0058d8f3  8b542424             mov edx, dword ptr [esp + 0x24]
// 0058d8f7  45                   inc ebp
// 0058d8f8  33c0                 xor eax, eax
// 0058d8fa  41                   inc ecx
// 0058d8fb  46                   inc esi
// 0058d8fc  8bfd                 mov edi, ebp
// 0058d8fe  85d2                 test edx, edx
// 0058d900  7626                 jbe 0x58d928
// 0058d902  89542444             mov dword ptr [esp + 0x44], edx
// 0058d906  89542438             mov dword ptr [esp + 0x38], edx
// 0058d90a  8d9b00000000         lea ebx, [ebx]
// 0058d910  8a06                 mov al, byte ptr [esi]
// 0058d912  8a17                 mov dl, byte ptr [edi]
// 0058d914  d0e8                 shr al, 1
// 0058d916  2ad0                 sub dl, al
// 0058d918  8811                 mov byte ptr [ecx], dl
// 0058d91a  41                   inc ecx
// 0058d91b  46                   inc esi
// 0058d91c  47                   inc edi
// 0058d91d  836c244401           sub dword ptr [esp + 0x44], 1
// 0058d922  75ec                 jne 0x58d910
// 0058d924  8b442438             mov eax, dword ptr [esp + 0x38]
// 0058d928  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0058d92c  7331                 jae 0x58d95f
// 0058d92e  8b542414             mov edx, dword ptr [esp + 0x14]
// 0058d932  2bd0                 sub edx, eax
// 0058d934  89542444             mov dword ptr [esp + 0x44], edx
// 0058d938  eb06                 jmp 0x58d940
// 0058d93a  8d9b00000000         lea ebx, [ebx]
// 0058d940  0fb65500             movzx edx, byte ptr [ebp]
// 0058d944  0fb606               movzx eax, byte ptr [esi]
// 0058d947  03c2                 add eax, edx
// 0058d949  99                   cdq 
// 0058d94a  2bc2                 sub eax, edx
// 0058d94c  8a17                 mov dl, byte ptr [edi]
// 0058d94e  d1f8                 sar eax, 1
// 0058d950  2ad0                 sub dl, al
// 0058d952  8811                 mov byte ptr [ecx], dl
// 0058d954  41                   inc ecx
// 0058d955  45                   inc ebp
// 0058d956  46                   inc esi
// 0058d957  47                   inc edi
// 0058d958  836c244401           sub dword ptr [esp + 0x44], 1
// 0058d95d  75e1                 jne 0x58d940
// 0058d95f  8b83f8000000         mov eax, dword ptr [ebx + 0xf8]
// 0058d965  89442418             mov dword ptr [esp + 0x18], eax
// 0058d969  f644241380           test byte ptr [esp + 0x13], 0x80
// 0058d96e  0f84a6040000         je 0x58de1a
// 0058d974  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0058d978  33ed                 xor ebp, ebp
// 0058d97a  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0058d981  896c2430             mov dword ptr [esp + 0x30], ebp
// 0058d985  894c2420             mov dword ptr [esp + 0x20], ecx
// 0058d989  0f85c7020000         jne 0x58dc56
// 0058d98f  0fb7f1               movzx esi, cx
// 0058d992  c1e90a               shr ecx, 0xa
// 0058d995  33d2                 xor edx, edx
// 0058d997  81e1c0ff3f00         and ecx, 0x3fffc0
// 0058d99d  39542448             cmp dword ptr [esp + 0x48], edx
// 0058d9a1  7e2f                 jle 0x58d9d2
// 0058d9a3  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0058d9a9  803c0204             cmp byte ptr [edx + eax], 4
// 0058d9ad  751c                 jne 0x58d9cb
// 0058d9af  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0058d9b5  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0058d9b9  8bf8                 mov edi, eax
// 0058d9bb  0fafc1               imul eax, ecx
// 0058d9be  0faffe               imul edi, esi
// 0058d9c1  c1ef08               shr edi, 8
// 0058d9c4  c1e808               shr eax, 8
// 0058d9c7  8bf7                 mov esi, edi
// 0058d9c9  8bc8                 mov ecx, eax
// 0058d9cb  42                   inc edx
// 0058d9cc  3b542448             cmp edx, dword ptr [esp + 0x48]
// 0058d9d0  7cd1                 jl 0x58d9a3
// 0058d9d2  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0058d9d8  0fb75208             movzx edx, word ptr [edx + 8]
// 0058d9dc  8bc2                 mov eax, edx
// 0058d9de  0fafc1               imul eax, ecx
// 0058d9e1  c1e803               shr eax, 3
// 0058d9e4  3dc0ff3f00           cmp eax, 0x3fffc0
// 0058d9e9  0f8658020000         jbe 0x58dc47
// 0058d9ef  c7442420ffffff7f     mov dword ptr [esp + 0x20], 0x7fffffff
// 0058d9f7  e95a020000           jmp 0x58dc56
// 0058d9fc  0fafd6               imul edx, esi
// 0058d9ff  c1ea03               shr edx, 3
// 0058da02  c1e00a               shl eax, 0xa
// 0058da05  03d0                 add edx, eax
// 0058da07  89542434             mov dword ptr [esp + 0x34], edx
// 0058da0b  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0058da0f  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 0058da15  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0058da19  8b442424             mov eax, dword ptr [esp + 0x24]
// 0058da1d  45                   inc ebp
// 0058da1e  41                   inc ecx
// 0058da1f  46                   inc esi
// 0058da20  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0058da28  8bfd                 mov edi, ebp
// 0058da2a  85c0                 test eax, eax
// 0058da2c  7635                 jbe 0x58da63
// 0058da2e  89442438             mov dword ptr [esp + 0x38], eax
// 0058da32  89442430             mov dword ptr [esp + 0x30], eax
// 0058da36  8a16                 mov dl, byte ptr [esi]
// 0058da38  8a07                 mov al, byte ptr [edi]
// 0058da3a  d0ea                 shr dl, 1
// 0058da3c  2ac2                 sub al, dl
// 0058da3e  8801                 mov byte ptr [ecx], al
// 0058da40  0fb6c0               movzx eax, al
// 0058da43  41                   inc ecx
// 0058da44  46                   inc esi
// 0058da45  47                   inc edi
// 0058da46  3d80000000           cmp eax, 0x80
// 0058da4b  7d04                 jge 0x58da51
// 0058da4d  8bd0                 mov edx, eax
// 0058da4f  eb07                 jmp 0x58da58
// 0058da51  ba00010000           mov edx, 0x100
// 0058da56  2bd0                 sub edx, eax
// 0058da58  01542420             add dword ptr [esp + 0x20], edx
// 0058da5c  836c243801           sub dword ptr [esp + 0x38], 1
// 0058da61  75d3                 jne 0x58da36
// 0058da63  8b442414             mov eax, dword ptr [esp + 0x14]
// 0058da67  39442430             cmp dword ptr [esp + 0x30], eax
// 0058da6b  7351                 jae 0x58dabe
// 0058da6d  8d4900               lea ecx, [ecx]
// 0058da70  0fb616               movzx edx, byte ptr [esi]
// 0058da73  0fb64500             movzx eax, byte ptr [ebp]
// 0058da77  03c2                 add eax, edx
// 0058da79  99                   cdq 
// 0058da7a  2bc2                 sub eax, edx
// 0058da7c  8bd0                 mov edx, eax
// 0058da7e  8a07                 mov al, byte ptr [edi]
// 0058da80  d1fa                 sar edx, 1
// 0058da82  2ac2                 sub al, dl
// 0058da84  8801                 mov byte ptr [ecx], al
// 0058da86  0fb6c0               movzx eax, al
// 0058da89  41                   inc ecx
// 0058da8a  45                   inc ebp
// 0058da8b  46                   inc esi
// 0058da8c  47                   inc edi
// 0058da8d  3d80000000           cmp eax, 0x80
// 0058da92  7d04                 jge 0x58da98
// 0058da94  8bd0                 mov edx, eax
// 0058da96  eb07                 jmp 0x58da9f
// 0058da98  ba00010000           mov edx, 0x100
// 0058da9d  2bd0                 sub edx, eax
// 0058da9f  8b442420             mov eax, dword ptr [esp + 0x20]
// 0058daa3  03c2                 add eax, edx
// 0058daa5  89442420             mov dword ptr [esp + 0x20], eax
// 0058daa9  3b442434             cmp eax, dword ptr [esp + 0x34]
// 0058daad  770f                 ja 0x58dabe
// 0058daaf  8b442430             mov eax, dword ptr [esp + 0x30]
// 0058dab3  40                   inc eax
// 0058dab4  89442430             mov dword ptr [esp + 0x30], eax
// 0058dab8  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0058dabc  72b2                 jb 0x58da70
// 0058dabe  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0058dac5  7579                 jne 0x58db40
// 0058dac7  8b542420             mov edx, dword ptr [esp + 0x20]
// 0058dacb  0fb7f2               movzx esi, dx
// 0058dace  c1ea0a               shr edx, 0xa
// 0058dad1  33c9                 xor ecx, ecx
// 0058dad3  81e2c0ff3f00         and edx, 0x3fffc0
// 0058dad9  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0058dadd  7e2f                 jle 0x58db0e
// 0058dadf  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 0058dae5  803c3900             cmp byte ptr [ecx + edi], 0
// 0058dae9  751c                 jne 0x58db07
// 0058daeb  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0058daf1  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0058daf5  8be8                 mov ebp, eax
// 0058daf7  0fafc2               imul eax, edx
// 0058dafa  0fafee               imul ebp, esi
// 0058dafd  c1ed08               shr ebp, 8
// 0058db00  c1e808               shr eax, 8
// 0058db03  8bf5                 mov esi, ebp
// 0058db05  8bd0                 mov edx, eax
// 0058db07  41                   inc ecx
// 0058db08  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0058db0c  7cd7                 jl 0x58dae5
// 0058db0e  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0058db14  0fb74906             movzx ecx, word ptr [ecx + 6]
// 0058db18  8bc1                 mov eax, ecx
// 0058db1a  0fafc2               imul eax, edx
// 0058db1d  c1e803               shr eax, 3
// 0058db20  3dc0ff3f00           cmp eax, 0x3fffc0
// 0058db25  760a                 jbe 0x58db31
// 0058db27  c7442420ffffff7f     mov dword ptr [esp + 0x20], 0x7fffffff
// 0058db2f  eb0f                 jmp 0x58db40
// 0058db31  0fafce               imul ecx, esi
// 0058db34  c1e903               shr ecx, 3
// 0058db37  c1e00a               shl eax, 0xa
// 0058db3a  03c8                 add ecx, eax
// 0058db3c  894c2420             mov dword ptr [esp + 0x20], ecx
// 0058db40  8b442420             mov eax, dword ptr [esp + 0x20]
// 0058db44  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 0058db48  730e                 jae 0x58db58
// 0058db4a  8b93f8000000         mov edx, dword ptr [ebx + 0xf8]
// 0058db50  8944241c             mov dword ptr [esp + 0x1c], eax
// 0058db54  89542418             mov dword ptr [esp + 0x18], edx
// 0058db58  807c241380           cmp byte ptr [esp + 0x13], 0x80
// 0058db5d  0f8506feffff         jne 0x58d969
// 0058db63  8b442428             mov eax, dword ptr [esp + 0x28]
// 0058db67  8bbbfc000000         mov edi, dword ptr [ebx + 0xfc]
// 0058db6d  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0058db71  40                   inc eax
// 0058db72  42                   inc edx
// 0058db73  47                   inc edi
// 0058db74  837c242400           cmp dword ptr [esp + 0x24], 0
// 0058db79  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0058db81  8bc8                 mov ecx, eax
// 0058db83  89442430             mov dword ptr [esp + 0x30], eax
// 0058db87  8bf2                 mov esi, edx
// 0058db89  761b                 jbe 0x58dba6
// 0058db8b  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0058db8f  896c2434             mov dword ptr [esp + 0x34], ebp
// 0058db93  8a19                 mov bl, byte ptr [ecx]
// 0058db95  2a1e                 sub bl, byte ptr [esi]
// 0058db97  47                   inc edi
// 0058db98  885fff               mov byte ptr [edi - 1], bl
// 0058db9b  46                   inc esi
// 0058db9c  41                   inc ecx
// 0058db9d  83ed01               sub ebp, 1
// 0058dba0  75f1                 jne 0x58db93
// 0058dba2  894c2430             mov dword ptr [esp + 0x30], ecx
// 0058dba6  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0058dbaa  8be8                 mov ebp, eax
// 0058dbac  395c2434             cmp dword ptr [esp + 0x34], ebx
// 0058dbb0  0f8388000000         jae 0x58dc3e
// 0058dbb6  8bca                 mov ecx, edx
// 0058dbb8  2bc8                 sub ecx, eax
// 0058dbba  2b5c2434             sub ebx, dword ptr [esp + 0x34]
// 0058dbbe  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0058dbc2  895c2434             mov dword ptr [esp + 0x34], ebx
// 0058dbc6  eb0c                 jmp 0x58dbd4
// 0058dbc8  eb06                 jmp 0x58dbd0
// 0058dbca  8d9b00000000         lea ebx, [ebx]
// 0058dbd0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0058dbd4  0fb61429             movzx edx, byte ptr [ecx + ebp]
// 0058dbd8  0fb606               movzx eax, byte ptr [esi]
// 0058dbdb  0fb64d00             movzx ecx, byte ptr [ebp]
// 0058dbdf  89442424             mov dword ptr [esp + 0x24], eax
// 0058dbe3  894c2428             mov dword ptr [esp + 0x28], ecx
// 0058dbe7  2bc2                 sub eax, edx
// 0058dbe9  46                   inc esi
// 0058dbea  45                   inc ebp
// 0058dbeb  2bca                 sub ecx, edx
// 0058dbed  85c0                 test eax, eax
// 0058dbef  7d0a                 jge 0x58dbfb
// 0058dbf1  8bd8                 mov ebx, eax
// 0058dbf3  f7db                 neg ebx
// 0058dbf5  895c2438             mov dword ptr [esp + 0x38], ebx
// 0058dbf9  eb04                 jmp 0x58dbff
// 0058dbfb  89442438             mov dword ptr [esp + 0x38], eax
// 0058dbff  8bd9                 mov ebx, ecx
// 0058dc01  85c9                 test ecx, ecx
// 0058dc03  7d02                 jge 0x58dc07
// 0058dc05  f7db                 neg ebx
// 0058dc07  03c1                 add eax, ecx
// 0058dc09  7902                 jns 0x58dc0d
// 0058dc0b  f7d8                 neg eax
// 0058dc0d  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0058dc11  3bcb                 cmp ecx, ebx
// 0058dc13  7f0a                 jg 0x58dc1f
// 0058dc15  3bc8                 cmp ecx, eax
// 0058dc17  7f06                 jg 0x58dc1f
// 0058dc19  8b542428             mov edx, dword ptr [esp + 0x28]
// 0058dc1d  eb08                 jmp 0x58dc27
// 0058dc1f  3bd8                 cmp ebx, eax
// 0058dc21  7f04                 jg 0x58dc27
// 0058dc23  8b542424             mov edx, dword ptr [esp + 0x24]
// 0058dc27  8b442430             mov eax, dword ptr [esp + 0x30]
// 0058dc2b  8a08                 mov cl, byte ptr [eax]
// 0058dc2d  2aca                 sub cl, dl
// 0058dc2f  880f                 mov byte ptr [edi], cl
// 0058dc31  40                   inc eax
// 0058dc32  47                   inc edi
// 0058dc33  836c243401           sub dword ptr [esp + 0x34], 1
// 0058dc38  89442430             mov dword ptr [esp + 0x30], eax
// 0058dc3c  7592                 jne 0x58dbd0
// 0058dc3e  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 0058dc42  e9c9010000           jmp 0x58de10
// 0058dc47  0fafd6               imul edx, esi
// 0058dc4a  c1ea03               shr edx, 3
// 0058dc4d  c1e00a               shl eax, 0xa
// 0058dc50  03d0                 add edx, eax
// 0058dc52  89542420             mov dword ptr [esp + 0x20], edx
// 0058dc56  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0058dc5a  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0058dc5e  8bb3fc000000         mov esi, dword ptr [ebx + 0xfc]
// 0058dc64  8b442424             mov eax, dword ptr [esp + 0x24]
// 0058dc68  47                   inc edi
// 0058dc69  42                   inc edx
// 0058dc6a  46                   inc esi
// 0058dc6b  c744244400000000     mov dword ptr [esp + 0x44], 0
// 0058dc73  897c2428             mov dword ptr [esp + 0x28], edi
// 0058dc77  897c2434             mov dword ptr [esp + 0x34], edi
// 0058dc7b  8954242c             mov dword ptr [esp + 0x2c], edx
// 0058dc7f  85c0                 test eax, eax
// 0058dc81  763d                 jbe 0x58dcc0
// 0058dc83  89442438             mov dword ptr [esp + 0x38], eax
// 0058dc87  89442444             mov dword ptr [esp + 0x44], eax
// 0058dc8b  eb03                 jmp 0x58dc90
// 0058dc8d  8d4900               lea ecx, [ecx]
// 0058dc90  8a07                 mov al, byte ptr [edi]
// 0058dc92  2a02                 sub al, byte ptr [edx]
// 0058dc94  46                   inc esi
// 0058dc95  8846ff               mov byte ptr [esi - 1], al
// 0058dc98  0fb6c0               movzx eax, al
// 0058dc9b  42                   inc edx
// 0058dc9c  47                   inc edi
// 0058dc9d  3d80000000           cmp eax, 0x80
// 0058dca2  7d04                 jge 0x58dca8
// 0058dca4  8bc8                 mov ecx, eax
// 0058dca6  eb07                 jmp 0x58dcaf
// 0058dca8  b900010000           mov ecx, 0x100
// 0058dcad  2bc8                 sub ecx, eax
// 0058dcaf  03e9                 add ebp, ecx
// 0058dcb1  836c243801           sub dword ptr [esp + 0x38], 1
// 0058dcb6  75d8                 jne 0x58dc90
// 0058dcb8  896c2430             mov dword ptr [esp + 0x30], ebp
// 0058dcbc  897c2434             mov dword ptr [esp + 0x34], edi
// 0058dcc0  8b442444             mov eax, dword ptr [esp + 0x44]
// 0058dcc4  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0058dcc8  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0058dccc  0f83b8000000         jae 0x58dd8a
// 0058dcd2  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0058dcd6  2bf9                 sub edi, ecx
// 0058dcd8  897c242c             mov dword ptr [esp + 0x2c], edi
// 0058dcdc  eb0e                 jmp 0x58dcec
// 0058dcde  8bff                 mov edi, edi
// 0058dce0  8b542428             mov edx, dword ptr [esp + 0x28]
// 0058dce4  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0058dce8  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0058dcec  0fb602               movzx eax, byte ptr [edx]
// 0058dcef  42                   inc edx
// 0058dcf0  89542428             mov dword ptr [esp + 0x28], edx
// 0058dcf4  0fb6140f             movzx edx, byte ptr [edi + ecx]
// 0058dcf8  0fb639               movzx edi, byte ptr [ecx]
// 0058dcfb  41                   inc ecx
// 0058dcfc  894c2424             mov dword ptr [esp + 0x24], ecx
// 0058dd00  8944243c             mov dword ptr [esp + 0x3c], eax
// 0058dd04  8bcf                 mov ecx, edi
// 0058dd06  2bc2                 sub eax, edx
// 0058dd08  2bca                 sub ecx, edx
// 0058dd0a  85c0                 test eax, eax
// 0058dd0c  7d0a                 jge 0x58dd18
// 0058dd0e  8be8                 mov ebp, eax
// 0058dd10  f7dd                 neg ebp
// 0058dd12  896c2438             mov dword ptr [esp + 0x38], ebp
// 0058dd16  eb04                 jmp 0x58dd1c
// 0058dd18  89442438             mov dword ptr [esp + 0x38], eax
// 0058dd1c  8be9                 mov ebp, ecx
// 0058dd1e  85c9                 test ecx, ecx
// 0058dd20  7d02                 jge 0x58dd24
// 0058dd22  f7dd                 neg ebp
// 0058dd24  03c1                 add eax, ecx
// 0058dd26  7902                 jns 0x58dd2a
// 0058dd28  f7d8                 neg eax
// 0058dd2a  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0058dd2e  3bcd                 cmp ecx, ebp
// 0058dd30  7f08                 jg 0x58dd3a
// 0058dd32  3bc8                 cmp ecx, eax
// 0058dd34  7f04                 jg 0x58dd3a
// 0058dd36  8bd7                 mov edx, edi
// 0058dd38  eb08                 jmp 0x58dd42
// 0058dd3a  3be8                 cmp ebp, eax
// 0058dd3c  7f04                 jg 0x58dd42
// 0058dd3e  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0058dd42  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0058dd46  8a01                 mov al, byte ptr [ecx]
// 0058dd48  2ac2                 sub al, dl
// 0058dd4a  8806                 mov byte ptr [esi], al
// 0058dd4c  0fb6c0               movzx eax, al
// 0058dd4f  41                   inc ecx
// 0058dd50  46                   inc esi
// 0058dd51  3d80000000           cmp eax, 0x80
// 0058dd56  894c2434             mov dword ptr [esp + 0x34], ecx
// 0058dd5a  7d04                 jge 0x58dd60
// 0058dd5c  8bc8                 mov ecx, eax
// 0058dd5e  eb07                 jmp 0x58dd67
// 0058dd60  b900010000           mov ecx, 0x100
// 0058dd65  2bc8                 sub ecx, eax
// 0058dd67  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 0058dd6b  03e9                 add ebp, ecx
// 0058dd6d  896c2430             mov dword ptr [esp + 0x30], ebp
// 0058dd71  3b6c2420             cmp ebp, dword ptr [esp + 0x20]
// 0058dd75  7713                 ja 0x58dd8a
// 0058dd77  8b442444             mov eax, dword ptr [esp + 0x44]
// 0058dd7b  40                   inc eax
// 0058dd7c  89442444             mov dword ptr [esp + 0x44], eax
// 0058dd80  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0058dd84  0f8256ffffff         jb 0x58dce0
// 0058dd8a  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0058dd91  7577                 jne 0x58de0a
// 0058dd93  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 0058dd97  0fb7f5               movzx esi, bp
// 0058dd9a  c1ed0a               shr ebp, 0xa
// 0058dd9d  81e5c0ff3f00         and ebp, 0x3fffc0
// 0058dda3  33c9                 xor ecx, ecx
// 0058dda5  8bd5                 mov edx, ebp
// 0058dda7  85ff                 test edi, edi
// 0058dda9  7e32                 jle 0x58dddd
// 0058ddab  eb03                 jmp 0x58ddb0
// 0058ddad  8d4900               lea ecx, [ecx]
// 0058ddb0  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0058ddb6  803c0104             cmp byte ptr [ecx + eax], 4
// 0058ddba  751c                 jne 0x58ddd8
// 0058ddbc  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0058ddc2  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0058ddc6  8be8                 mov ebp, eax
// 0058ddc8  0fafc2               imul eax, edx
// 0058ddcb  0fafee               imul ebp, esi
// 0058ddce  c1ed08               shr ebp, 8
// 0058ddd1  c1e808               shr eax, 8
// 0058ddd4  8bf5                 mov esi, ebp
// 0058ddd6  8bd0                 mov edx, eax
// 0058ddd8  41                   inc ecx
// 0058ddd9  3bcf                 cmp ecx, edi
// 0058dddb  7cd3                 jl 0x58ddb0
// 0058dddd  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0058dde3  0fb74908             movzx ecx, word ptr [ecx + 8]
// 0058dde7  8bc1                 mov eax, ecx
// 0058dde9  0fafc2               imul eax, edx
// 0058ddec  c1e803               shr eax, 3
// 0058ddef  3dc0ff3f00           cmp eax, 0x3fffc0
// 0058ddf4  7607                 jbe 0x58ddfd
// 0058ddf6  bdffffff7f           mov ebp, 0x7fffffff
// 0058ddfb  eb0d                 jmp 0x58de0a
// 0058ddfd  0fafce               imul ecx, esi
// 0058de00  c1e903               shr ecx, 3
// 0058de03  c1e00a               shl eax, 0xa
// 0058de06  03c8                 add ecx, eax
// 0058de08  8be9                 mov ebp, ecx
// 0058de0a  3b6c241c             cmp ebp, dword ptr [esp + 0x1c]
// 0058de0e  730a                 jae 0x58de1a
// 0058de10  8b93fc000000         mov edx, dword ptr [ebx + 0xfc]
// 0058de16  89542418             mov dword ptr [esp + 0x18], edx
// 0058de1a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0058de1e  50                   push eax
// 0058de1f  53                   push ebx
// 0058de20  e83bf4ffff           call 0x58d260
// 0058de25  83c408               add esp, 8
// 0058de28  80bbf901000000       cmp byte ptr [ebx + 0x1f9], 0
// 0058de2f  7633                 jbe 0x58de64
// 0058de31  b801000000           mov eax, 1
// 0058de36  39442448             cmp dword ptr [esp + 0x48], eax
// 0058de3a  7e19                 jle 0x58de55
// 0058de3c  8d642400             lea esp, [esp]
// 0058de40  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 0058de46  8a5401ff             mov dl, byte ptr [ecx + eax - 1]
// 0058de4a  03c8                 add ecx, eax
// 0058de4c  40                   inc eax
// 0058de4d  3b442448             cmp eax, dword ptr [esp + 0x48]
// 0058de51  8811                 mov byte ptr [ecx], dl
// 0058de53  7ceb                 jl 0x58de40
// 0058de55  8b542418             mov edx, dword ptr [esp + 0x18]
// 0058de59  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 0058de5f  8a12                 mov dl, byte ptr [edx]
// 0058de61  881408               mov byte ptr [eax + ecx], dl
// 0058de64  5f                   pop edi
// 0058de65  5e                   pop esi
// 0058de66  5d                   pop ebp
// 0058de67  5b                   pop ebx
// 0058de68  83c430               add esp, 0x30
// 0058de6b  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_find_filter)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
