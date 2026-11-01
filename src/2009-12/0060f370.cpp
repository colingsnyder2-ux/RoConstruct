// from server: 100% by auto
// roc 2009-12 0060f370  unit: seg_00600000  size: 2860 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060f370
//
// 0060f370  83ec30               sub esp, 0x30
// 0060f373  8b442438             mov eax, dword ptr [esp + 0x38]
// 0060f377  53                   push ebx
// 0060f378  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 0060f37c  8a8b25010000         mov cl, byte ptr [ebx + 0x125]
// 0060f382  0fb693f9010000       movzx edx, byte ptr [ebx + 0x1f9]
// 0060f389  55                   push ebp
// 0060f38a  8b6804               mov ebp, dword ptr [eax + 4]
// 0060f38d  56                   push esi
// 0060f38e  57                   push edi
// 0060f38f  0fb6780b             movzx edi, byte ptr [eax + 0xb]
// 0060f393  8b83e8000000         mov eax, dword ptr [ebx + 0xe8]
// 0060f399  83c707               add edi, 7
// 0060f39c  c1ff03               sar edi, 3
// 0060f39f  8944242c             mov dword ptr [esp + 0x2c], eax
// 0060f3a3  8b83ec000000         mov eax, dword ptr [ebx + 0xec]
// 0060f3a9  884c2413             mov byte ptr [esp + 0x13], cl
// 0060f3ad  896c2414             mov dword ptr [esp + 0x14], ebp
// 0060f3b1  89542448             mov dword ptr [esp + 0x48], edx
// 0060f3b5  897c2424             mov dword ptr [esp + 0x24], edi
// 0060f3b9  89442418             mov dword ptr [esp + 0x18], eax
// 0060f3bd  89442428             mov dword ptr [esp + 0x28], eax
// 0060f3c1  c744241cffffff7f     mov dword ptr [esp + 0x1c], 0x7fffffff
// 0060f3c9  f6c108               test cl, 8
// 0060f3cc  0f84bd000000         je 0x60f48f
// 0060f3d2  80f908               cmp cl, 8
// 0060f3d5  0f84b4000000         je 0x60f48f
// 0060f3db  33c0                 xor eax, eax
// 0060f3dd  33d2                 xor edx, edx
// 0060f3df  85ed                 test ebp, ebp
// 0060f3e1  7630                 jbe 0x60f413
// 0060f3e3  eb0b                 jmp 0x60f3f0
// 0060f3e5  8da42400000000       lea esp, [esp]
// 0060f3ec  8d642400             lea esp, [esp]
// 0060f3f0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0060f3f4  0fb6741101           movzx esi, byte ptr [ecx + edx + 1]
// 0060f3f9  81fe80000000         cmp esi, 0x80
// 0060f3ff  7d04                 jge 0x60f405
// 0060f401  8bce                 mov ecx, esi
// 0060f403  eb07                 jmp 0x60f40c
// 0060f405  b900010000           mov ecx, 0x100
// 0060f40a  2bce                 sub ecx, esi
// 0060f40c  42                   inc edx
// 0060f40d  03c1                 add eax, ecx
// 0060f40f  3bd5                 cmp edx, ebp
// 0060f411  72dd                 jb 0x60f3f0
// 0060f413  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0060f41a  756f                 jne 0x60f48b
// 0060f41c  0fb7f0               movzx esi, ax
// 0060f41f  c1e80a               shr eax, 0xa
// 0060f422  25c0ff3f00           and eax, 0x3fffc0
// 0060f427  33c9                 xor ecx, ecx
// 0060f429  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0060f42d  8bd0                 mov edx, eax
// 0060f42f  7e2f                 jle 0x60f460
// 0060f431  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0060f437  803c0800             cmp byte ptr [eax + ecx], 0
// 0060f43b  751c                 jne 0x60f459
// 0060f43d  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0060f443  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0060f447  8be8                 mov ebp, eax
// 0060f449  0fafc2               imul eax, edx
// 0060f44c  0fafee               imul ebp, esi
// 0060f44f  c1ed08               shr ebp, 8
// 0060f452  c1e808               shr eax, 8
// 0060f455  8bf5                 mov esi, ebp
// 0060f457  8bd0                 mov edx, eax
// 0060f459  41                   inc ecx
// 0060f45a  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0060f45e  7cd1                 jl 0x60f431
// 0060f460  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0060f466  0fb701               movzx eax, word ptr [ecx]
// 0060f469  8bc8                 mov ecx, eax
// 0060f46b  0fafca               imul ecx, edx
// 0060f46e  c1e903               shr ecx, 3
// 0060f471  81f9c0ff3f00         cmp ecx, 0x3fffc0
// 0060f477  7607                 jbe 0x60f480
// 0060f479  b8ffffff7f           mov eax, 0x7fffffff
// 0060f47e  eb0b                 jmp 0x60f48b
// 0060f480  0fafc6               imul eax, esi
// 0060f483  c1e803               shr eax, 3
// 0060f486  c1e10a               shl ecx, 0xa
// 0060f489  03c1                 add eax, ecx
// 0060f48b  8944241c             mov dword ptr [esp + 0x1c], eax
// 0060f48f  8a442413             mov al, byte ptr [esp + 0x13]
// 0060f493  3c10                 cmp al, 0x10
// 0060f495  0f85dc000000         jne 0x60f577
// 0060f49b  8b742418             mov esi, dword ptr [esp + 0x18]
// 0060f49f  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 0060f4a5  46                   inc esi
// 0060f4a6  33ed                 xor ebp, ebp
// 0060f4a8  40                   inc eax
// 0060f4a9  8bce                 mov ecx, esi
// 0060f4ab  85ff                 test edi, edi
// 0060f4ad  760d                 jbe 0x60f4bc
// 0060f4af  8bef                 mov ebp, edi
// 0060f4b1  8a11                 mov dl, byte ptr [ecx]
// 0060f4b3  8810                 mov byte ptr [eax], dl
// 0060f4b5  41                   inc ecx
// 0060f4b6  40                   inc eax
// 0060f4b7  83ef01               sub edi, 1
// 0060f4ba  75f5                 jne 0x60f4b1
// 0060f4bc  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 0060f4c0  7314                 jae 0x60f4d6
// 0060f4c2  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0060f4c6  2bfd                 sub edi, ebp
// 0060f4c8  8a11                 mov dl, byte ptr [ecx]
// 0060f4ca  2a16                 sub dl, byte ptr [esi]
// 0060f4cc  41                   inc ecx
// 0060f4cd  8810                 mov byte ptr [eax], dl
// 0060f4cf  46                   inc esi
// 0060f4d0  40                   inc eax
// 0060f4d1  83ef01               sub edi, 1
// 0060f4d4  75f2                 jne 0x60f4c8
// 0060f4d6  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 0060f4dc  89442418             mov dword ptr [esp + 0x18], eax
// 0060f4e0  f644241320           test byte ptr [esp + 0x13], 0x20
// 0060f4e5  0f841f040000         je 0x60f90a
// 0060f4eb  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060f4ef  33ff                 xor edi, edi
// 0060f4f1  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0060f4f8  894c2430             mov dword ptr [esp + 0x30], ecx
// 0060f4fc  0f8514030000         jne 0x60f816
// 0060f502  0fb7f1               movzx esi, cx
// 0060f505  c1e90a               shr ecx, 0xa
// 0060f508  33d2                 xor edx, edx
// 0060f50a  81e1c0ff3f00         and ecx, 0x3fffc0
// 0060f510  39542448             cmp dword ptr [esp + 0x48], edx
// 0060f514  89742434             mov dword ptr [esp + 0x34], esi
// 0060f518  7e33                 jle 0x60f54d
// 0060f51a  8babfc010000         mov ebp, dword ptr [ebx + 0x1fc]
// 0060f520  803c2a02             cmp byte ptr [edx + ebp], 2
// 0060f524  7520                 jne 0x60f546
// 0060f526  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0060f52c  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0060f530  8bf0                 mov esi, eax
// 0060f532  0fafc1               imul eax, ecx
// 0060f535  0faf742434           imul esi, dword ptr [esp + 0x34]
// 0060f53a  c1ee08               shr esi, 8
// 0060f53d  c1e808               shr eax, 8
// 0060f540  89742434             mov dword ptr [esp + 0x34], esi
// 0060f544  8bc8                 mov ecx, eax
// 0060f546  42                   inc edx
// 0060f547  3b542448             cmp edx, dword ptr [esp + 0x48]
// 0060f54b  7cd3                 jl 0x60f520
// 0060f54d  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0060f553  0fb75204             movzx edx, word ptr [edx + 4]
// 0060f557  8bc2                 mov eax, edx
// 0060f559  0fafc1               imul eax, ecx
// 0060f55c  c1e803               shr eax, 3
// 0060f55f  3dc0ff3f00           cmp eax, 0x3fffc0
// 0060f564  0f869d020000         jbe 0x60f807
// 0060f56a  c7442430ffffff7f     mov dword ptr [esp + 0x30], 0x7fffffff
// 0060f572  e99f020000           jmp 0x60f816
// 0060f577  a810                 test al, 0x10
// 0060f579  0f84ac010000         je 0x60f72b
// 0060f57f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060f583  33ff                 xor edi, edi
// 0060f585  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0060f58c  894c2430             mov dword ptr [esp + 0x30], ecx
// 0060f590  757f                 jne 0x60f611
// 0060f592  0fb7f1               movzx esi, cx
// 0060f595  c1e90a               shr ecx, 0xa
// 0060f598  81e1c0ff3f00         and ecx, 0x3fffc0
// 0060f59e  33d2                 xor edx, edx
// 0060f5a0  397c2448             cmp dword ptr [esp + 0x48], edi
// 0060f5a4  7e39                 jle 0x60f5df
// 0060f5a6  eb08                 jmp 0x60f5b0
// 0060f5a8  8da42400000000       lea esp, [esp]
// 0060f5af  90                   nop 
// 0060f5b0  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0060f5b6  803c1001             cmp byte ptr [eax + edx], 1
// 0060f5ba  751c                 jne 0x60f5d8
// 0060f5bc  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0060f5c2  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0060f5c6  8be8                 mov ebp, eax
// 0060f5c8  0fafc1               imul eax, ecx
// 0060f5cb  0fafee               imul ebp, esi
// 0060f5ce  c1ed08               shr ebp, 8
// 0060f5d1  c1e808               shr eax, 8
// 0060f5d4  8bf5                 mov esi, ebp
// 0060f5d6  8bc8                 mov ecx, eax
// 0060f5d8  42                   inc edx
// 0060f5d9  3b542448             cmp edx, dword ptr [esp + 0x48]
// 0060f5dd  7cd1                 jl 0x60f5b0
// 0060f5df  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0060f5e5  0fb75202             movzx edx, word ptr [edx + 2]
// 0060f5e9  8bc2                 mov eax, edx
// 0060f5eb  0fafc1               imul eax, ecx
// 0060f5ee  c1e803               shr eax, 3
// 0060f5f1  3dc0ff3f00           cmp eax, 0x3fffc0
// 0060f5f6  760a                 jbe 0x60f602
// 0060f5f8  c7442430ffffff7f     mov dword ptr [esp + 0x30], 0x7fffffff
// 0060f600  eb0f                 jmp 0x60f611
// 0060f602  0fafd6               imul edx, esi
// 0060f605  c1ea03               shr edx, 3
// 0060f608  c1e00a               shl eax, 0xa
// 0060f60b  03d0                 add edx, eax
// 0060f60d  89542430             mov dword ptr [esp + 0x30], edx
// 0060f611  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0060f615  8b8bf0000000         mov ecx, dword ptr [ebx + 0xf0]
// 0060f61b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060f61f  45                   inc ebp
// 0060f620  41                   inc ecx
// 0060f621  897c2420             mov dword ptr [esp + 0x20], edi
// 0060f625  896c2438             mov dword ptr [esp + 0x38], ebp
// 0060f629  8bd5                 mov edx, ebp
// 0060f62b  85c0                 test eax, eax
// 0060f62d  762d                 jbe 0x60f65c
// 0060f62f  8be8                 mov ebp, eax
// 0060f631  89442420             mov dword ptr [esp + 0x20], eax
// 0060f635  8a02                 mov al, byte ptr [edx]
// 0060f637  0fb6f0               movzx esi, al
// 0060f63a  81fe80000000         cmp esi, 0x80
// 0060f640  8801                 mov byte ptr [ecx], al
// 0060f642  7d04                 jge 0x60f648
// 0060f644  8bc6                 mov eax, esi
// 0060f646  eb07                 jmp 0x60f64f
// 0060f648  b800010000           mov eax, 0x100
// 0060f64d  2bc6                 sub eax, esi
// 0060f64f  03f8                 add edi, eax
// 0060f651  42                   inc edx
// 0060f652  41                   inc ecx
// 0060f653  83ed01               sub ebp, 1
// 0060f656  75dd                 jne 0x60f635
// 0060f658  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 0060f65c  8b442414             mov eax, dword ptr [esp + 0x14]
// 0060f660  39442420             cmp dword ptr [esp + 0x20], eax
// 0060f664  7336                 jae 0x60f69c
// 0060f666  8a02                 mov al, byte ptr [edx]
// 0060f668  2a4500               sub al, byte ptr [ebp]
// 0060f66b  8801                 mov byte ptr [ecx], al
// 0060f66d  0fb6c0               movzx eax, al
// 0060f670  3d80000000           cmp eax, 0x80
// 0060f675  7d04                 jge 0x60f67b
// 0060f677  8bf0                 mov esi, eax
// 0060f679  eb07                 jmp 0x60f682
// 0060f67b  be00010000           mov esi, 0x100
// 0060f680  2bf0                 sub esi, eax
// 0060f682  03fe                 add edi, esi
// 0060f684  3b7c2430             cmp edi, dword ptr [esp + 0x30]
// 0060f688  7712                 ja 0x60f69c
// 0060f68a  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060f68e  40                   inc eax
// 0060f68f  42                   inc edx
// 0060f690  45                   inc ebp
// 0060f691  41                   inc ecx
// 0060f692  89442420             mov dword ptr [esp + 0x20], eax
// 0060f696  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0060f69a  72ca                 jb 0x60f666
// 0060f69c  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0060f6a3  7572                 jne 0x60f717
// 0060f6a5  0fb7f7               movzx esi, di
// 0060f6a8  c1ef0a               shr edi, 0xa
// 0060f6ab  81e7c0ff3f00         and edi, 0x3fffc0
// 0060f6b1  33c9                 xor ecx, ecx
// 0060f6b3  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0060f6b7  8bd7                 mov edx, edi
// 0060f6b9  7e2f                 jle 0x60f6ea
// 0060f6bb  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 0060f6c1  803c0f01             cmp byte ptr [edi + ecx], 1
// 0060f6c5  751c                 jne 0x60f6e3
// 0060f6c7  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0060f6cd  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0060f6d1  8be8                 mov ebp, eax
// 0060f6d3  0fafc2               imul eax, edx
// 0060f6d6  0fafee               imul ebp, esi
// 0060f6d9  c1ed08               shr ebp, 8
// 0060f6dc  c1e808               shr eax, 8
// 0060f6df  8bf5                 mov esi, ebp
// 0060f6e1  8bd0                 mov edx, eax
// 0060f6e3  41                   inc ecx
// 0060f6e4  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0060f6e8  7cd7                 jl 0x60f6c1
// 0060f6ea  8b8b0c020000         mov ecx, dword ptr [ebx + 0x20c]
// 0060f6f0  0fb74902             movzx ecx, word ptr [ecx + 2]
// 0060f6f4  8bc1                 mov eax, ecx
// 0060f6f6  0fafc2               imul eax, edx
// 0060f6f9  c1e803               shr eax, 3
// 0060f6fc  3dc0ff3f00           cmp eax, 0x3fffc0
// 0060f701  7607                 jbe 0x60f70a
// 0060f703  bfffffff7f           mov edi, 0x7fffffff
// 0060f708  eb0d                 jmp 0x60f717
// 0060f70a  0fafce               imul ecx, esi
// 0060f70d  c1e903               shr ecx, 3
// 0060f710  c1e00a               shl eax, 0xa
// 0060f713  03c8                 add ecx, eax
// 0060f715  8bf9                 mov edi, ecx
// 0060f717  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 0060f71b  730e                 jae 0x60f72b
// 0060f71d  8b93f0000000         mov edx, dword ptr [ebx + 0xf0]
// 0060f723  897c241c             mov dword ptr [esp + 0x1c], edi
// 0060f727  89542418             mov dword ptr [esp + 0x18], edx
// 0060f72b  807c241320           cmp byte ptr [esp + 0x13], 0x20
// 0060f730  0f85aafdffff         jne 0x60f4e0
// 0060f736  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 0060f73c  8b542428             mov edx, dword ptr [esp + 0x28]
// 0060f740  33c9                 xor ecx, ecx
// 0060f742  40                   inc eax
// 0060f743  8d7a01               lea edi, [edx + 1]
// 0060f746  394c2414             cmp dword ptr [esp + 0x14], ecx
// 0060f74a  7618                 jbe 0x60f764
// 0060f74c  8bf7                 mov esi, edi
// 0060f74e  2bf2                 sub esi, edx
// 0060f750  0374242c             add esi, dword ptr [esp + 0x2c]
// 0060f754  8a1439               mov dl, byte ptr [ecx + edi]
// 0060f757  2a16                 sub dl, byte ptr [esi]
// 0060f759  41                   inc ecx
// 0060f75a  8810                 mov byte ptr [eax], dl
// 0060f75c  46                   inc esi
// 0060f75d  40                   inc eax
// 0060f75e  3b4c2414             cmp ecx, dword ptr [esp + 0x14]
// 0060f762  72f0                 jb 0x60f754
// 0060f764  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 0060f76a  89442418             mov dword ptr [esp + 0x18], eax
// 0060f76e  f644241340           test byte ptr [esp + 0x13], 0x40
// 0060f773  0f840f040000         je 0x60fb88
// 0060f779  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060f77d  33d2                 xor edx, edx
// 0060f77f  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0060f786  89542420             mov dword ptr [esp + 0x20], edx
// 0060f78a  894c2434             mov dword ptr [esp + 0x34], ecx
// 0060f78e  0f85a7020000         jne 0x60fa3b
// 0060f794  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 0060f798  0fb7f1               movzx esi, cx
// 0060f79b  c1e90a               shr ecx, 0xa
// 0060f79e  81e1c0ff3f00         and ecx, 0x3fffc0
// 0060f7a4  3bfa                 cmp edi, edx
// 0060f7a6  7e35                 jle 0x60f7dd
// 0060f7a8  eb06                 jmp 0x60f7b0
// 0060f7aa  8d9b00000000         lea ebx, [ebx]
// 0060f7b0  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0060f7b6  803c0203             cmp byte ptr [edx + eax], 3
// 0060f7ba  751c                 jne 0x60f7d8
// 0060f7bc  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0060f7c2  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0060f7c6  8be8                 mov ebp, eax
// 0060f7c8  0fafc1               imul eax, ecx
// 0060f7cb  0fafee               imul ebp, esi
// 0060f7ce  c1ed08               shr ebp, 8
// 0060f7d1  c1e808               shr eax, 8
// 0060f7d4  8bf5                 mov esi, ebp
// 0060f7d6  8bc8                 mov ecx, eax
// 0060f7d8  42                   inc edx
// 0060f7d9  3bd7                 cmp edx, edi
// 0060f7db  7cd3                 jl 0x60f7b0
// 0060f7dd  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0060f7e3  0fb75206             movzx edx, word ptr [edx + 6]
// 0060f7e7  8bc2                 mov eax, edx
// 0060f7e9  0fafc1               imul eax, ecx
// 0060f7ec  c1e803               shr eax, 3
// 0060f7ef  3dc0ff3f00           cmp eax, 0x3fffc0
// 0060f7f4  0f8632020000         jbe 0x60fa2c
// 0060f7fa  c7442434ffffff7f     mov dword ptr [esp + 0x34], 0x7fffffff
// 0060f802  e934020000           jmp 0x60fa3b
// 0060f807  0fafd6               imul edx, esi
// 0060f80a  c1ea03               shr edx, 3
// 0060f80d  c1e00a               shl eax, 0xa
// 0060f810  03d0                 add edx, eax
// 0060f812  89542430             mov dword ptr [esp + 0x30], edx
// 0060f816  8b542428             mov edx, dword ptr [esp + 0x28]
// 0060f81a  8b8bf4000000         mov ecx, dword ptr [ebx + 0xf4]
// 0060f820  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0060f824  42                   inc edx
// 0060f825  41                   inc ecx
// 0060f826  40                   inc eax
// 0060f827  837c241400           cmp dword ptr [esp + 0x14], 0
// 0060f82c  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0060f834  7640                 jbe 0x60f876
// 0060f836  8be8                 mov ebp, eax
// 0060f838  2bea                 sub ebp, edx
// 0060f83a  8d9b00000000         lea ebx, [ebx]
// 0060f840  8a02                 mov al, byte ptr [edx]
// 0060f842  2a042a               sub al, byte ptr [edx + ebp]
// 0060f845  41                   inc ecx
// 0060f846  8841ff               mov byte ptr [ecx - 1], al
// 0060f849  0fb6c0               movzx eax, al
// 0060f84c  42                   inc edx
// 0060f84d  3d80000000           cmp eax, 0x80
// 0060f852  7d04                 jge 0x60f858
// 0060f854  8bf0                 mov esi, eax
// 0060f856  eb07                 jmp 0x60f85f
// 0060f858  be00010000           mov esi, 0x100
// 0060f85d  2bf0                 sub esi, eax
// 0060f85f  03fe                 add edi, esi
// 0060f861  3b7c2430             cmp edi, dword ptr [esp + 0x30]
// 0060f865  770f                 ja 0x60f876
// 0060f867  8b442434             mov eax, dword ptr [esp + 0x34]
// 0060f86b  40                   inc eax
// 0060f86c  89442434             mov dword ptr [esp + 0x34], eax
// 0060f870  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0060f874  72ca                 jb 0x60f840
// 0060f876  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0060f87d  7577                 jne 0x60f8f6
// 0060f87f  0fb7f7               movzx esi, di
// 0060f882  c1ef0a               shr edi, 0xa
// 0060f885  81e7c0ff3f00         and edi, 0x3fffc0
// 0060f88b  33c9                 xor ecx, ecx
// 0060f88d  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0060f891  8bd7                 mov edx, edi
// 0060f893  7e34                 jle 0x60f8c9
// 0060f895  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 0060f89b  eb03                 jmp 0x60f8a0
// 0060f89d  8d4900               lea ecx, [ecx]
// 0060f8a0  803c0f02             cmp byte ptr [edi + ecx], 2
// 0060f8a4  751c                 jne 0x60f8c2
// 0060f8a6  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0060f8ac  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0060f8b0  8be8                 mov ebp, eax
// 0060f8b2  0fafc2               imul eax, edx
// 0060f8b5  0fafee               imul ebp, esi
// 0060f8b8  c1ed08               shr ebp, 8
// 0060f8bb  c1e808               shr eax, 8
// 0060f8be  8bf5                 mov esi, ebp
// 0060f8c0  8bd0                 mov edx, eax
// 0060f8c2  41                   inc ecx
// 0060f8c3  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0060f8c7  7cd7                 jl 0x60f8a0
// 0060f8c9  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0060f8cf  0fb74904             movzx ecx, word ptr [ecx + 4]
// 0060f8d3  8bc1                 mov eax, ecx
// 0060f8d5  0fafc2               imul eax, edx
// 0060f8d8  c1e803               shr eax, 3
// 0060f8db  3dc0ff3f00           cmp eax, 0x3fffc0
// 0060f8e0  7607                 jbe 0x60f8e9
// 0060f8e2  bfffffff7f           mov edi, 0x7fffffff
// 0060f8e7  eb0d                 jmp 0x60f8f6
// 0060f8e9  0fafce               imul ecx, esi
// 0060f8ec  c1e903               shr ecx, 3
// 0060f8ef  c1e00a               shl eax, 0xa
// 0060f8f2  03c8                 add ecx, eax
// 0060f8f4  8bf9                 mov edi, ecx
// 0060f8f6  3b7c241c             cmp edi, dword ptr [esp + 0x1c]
// 0060f8fa  730e                 jae 0x60f90a
// 0060f8fc  8b93f4000000         mov edx, dword ptr [ebx + 0xf4]
// 0060f902  897c241c             mov dword ptr [esp + 0x1c], edi
// 0060f906  89542418             mov dword ptr [esp + 0x18], edx
// 0060f90a  807c241340           cmp byte ptr [esp + 0x13], 0x40
// 0060f90f  0f8559feffff         jne 0x60f76e
// 0060f915  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0060f919  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 0060f91f  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0060f923  8b542424             mov edx, dword ptr [esp + 0x24]
// 0060f927  45                   inc ebp
// 0060f928  33c0                 xor eax, eax
// 0060f92a  41                   inc ecx
// 0060f92b  46                   inc esi
// 0060f92c  8bfd                 mov edi, ebp
// 0060f92e  85d2                 test edx, edx
// 0060f930  7626                 jbe 0x60f958
// 0060f932  89542444             mov dword ptr [esp + 0x44], edx
// 0060f936  89542438             mov dword ptr [esp + 0x38], edx
// 0060f93a  8d9b00000000         lea ebx, [ebx]
// 0060f940  8a06                 mov al, byte ptr [esi]
// 0060f942  8a17                 mov dl, byte ptr [edi]
// 0060f944  d0e8                 shr al, 1
// 0060f946  2ad0                 sub dl, al
// 0060f948  8811                 mov byte ptr [ecx], dl
// 0060f94a  41                   inc ecx
// 0060f94b  46                   inc esi
// 0060f94c  47                   inc edi
// 0060f94d  836c244401           sub dword ptr [esp + 0x44], 1
// 0060f952  75ec                 jne 0x60f940
// 0060f954  8b442438             mov eax, dword ptr [esp + 0x38]
// 0060f958  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0060f95c  7331                 jae 0x60f98f
// 0060f95e  8b542414             mov edx, dword ptr [esp + 0x14]
// 0060f962  2bd0                 sub edx, eax
// 0060f964  89542444             mov dword ptr [esp + 0x44], edx
// 0060f968  eb06                 jmp 0x60f970
// 0060f96a  8d9b00000000         lea ebx, [ebx]
// 0060f970  0fb65500             movzx edx, byte ptr [ebp]
// 0060f974  0fb606               movzx eax, byte ptr [esi]
// 0060f977  03c2                 add eax, edx
// 0060f979  99                   cdq 
// 0060f97a  2bc2                 sub eax, edx
// 0060f97c  8a17                 mov dl, byte ptr [edi]
// 0060f97e  d1f8                 sar eax, 1
// 0060f980  2ad0                 sub dl, al
// 0060f982  8811                 mov byte ptr [ecx], dl
// 0060f984  41                   inc ecx
// 0060f985  45                   inc ebp
// 0060f986  46                   inc esi
// 0060f987  47                   inc edi
// 0060f988  836c244401           sub dword ptr [esp + 0x44], 1
// 0060f98d  75e1                 jne 0x60f970
// 0060f98f  8b83f8000000         mov eax, dword ptr [ebx + 0xf8]
// 0060f995  89442418             mov dword ptr [esp + 0x18], eax
// 0060f999  f644241380           test byte ptr [esp + 0x13], 0x80
// 0060f99e  0f84a6040000         je 0x60fe4a
// 0060f9a4  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060f9a8  33ed                 xor ebp, ebp
// 0060f9aa  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0060f9b1  896c2430             mov dword ptr [esp + 0x30], ebp
// 0060f9b5  894c2420             mov dword ptr [esp + 0x20], ecx
// 0060f9b9  0f85c7020000         jne 0x60fc86
// 0060f9bf  0fb7f1               movzx esi, cx
// 0060f9c2  c1e90a               shr ecx, 0xa
// 0060f9c5  33d2                 xor edx, edx
// 0060f9c7  81e1c0ff3f00         and ecx, 0x3fffc0
// 0060f9cd  39542448             cmp dword ptr [esp + 0x48], edx
// 0060f9d1  7e2f                 jle 0x60fa02
// 0060f9d3  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0060f9d9  803c0204             cmp byte ptr [edx + eax], 4
// 0060f9dd  751c                 jne 0x60f9fb
// 0060f9df  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 0060f9e5  0fb70450             movzx eax, word ptr [eax + edx*2]
// 0060f9e9  8bf8                 mov edi, eax
// 0060f9eb  0fafc1               imul eax, ecx
// 0060f9ee  0faffe               imul edi, esi
// 0060f9f1  c1ef08               shr edi, 8
// 0060f9f4  c1e808               shr eax, 8
// 0060f9f7  8bf7                 mov esi, edi
// 0060f9f9  8bc8                 mov ecx, eax
// 0060f9fb  42                   inc edx
// 0060f9fc  3b542448             cmp edx, dword ptr [esp + 0x48]
// 0060fa00  7cd1                 jl 0x60f9d3
// 0060fa02  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 0060fa08  0fb75208             movzx edx, word ptr [edx + 8]
// 0060fa0c  8bc2                 mov eax, edx
// 0060fa0e  0fafc1               imul eax, ecx
// 0060fa11  c1e803               shr eax, 3
// 0060fa14  3dc0ff3f00           cmp eax, 0x3fffc0
// 0060fa19  0f8658020000         jbe 0x60fc77
// 0060fa1f  c7442420ffffff7f     mov dword ptr [esp + 0x20], 0x7fffffff
// 0060fa27  e95a020000           jmp 0x60fc86
// 0060fa2c  0fafd6               imul edx, esi
// 0060fa2f  c1ea03               shr edx, 3
// 0060fa32  c1e00a               shl eax, 0xa
// 0060fa35  03d0                 add edx, eax
// 0060fa37  89542434             mov dword ptr [esp + 0x34], edx
// 0060fa3b  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0060fa3f  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 0060fa45  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0060fa49  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060fa4d  45                   inc ebp
// 0060fa4e  41                   inc ecx
// 0060fa4f  46                   inc esi
// 0060fa50  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0060fa58  8bfd                 mov edi, ebp
// 0060fa5a  85c0                 test eax, eax
// 0060fa5c  7635                 jbe 0x60fa93
// 0060fa5e  89442438             mov dword ptr [esp + 0x38], eax
// 0060fa62  89442430             mov dword ptr [esp + 0x30], eax
// 0060fa66  8a16                 mov dl, byte ptr [esi]
// 0060fa68  8a07                 mov al, byte ptr [edi]
// 0060fa6a  d0ea                 shr dl, 1
// 0060fa6c  2ac2                 sub al, dl
// 0060fa6e  8801                 mov byte ptr [ecx], al
// 0060fa70  0fb6c0               movzx eax, al
// 0060fa73  41                   inc ecx
// 0060fa74  46                   inc esi
// 0060fa75  47                   inc edi
// 0060fa76  3d80000000           cmp eax, 0x80
// 0060fa7b  7d04                 jge 0x60fa81
// 0060fa7d  8bd0                 mov edx, eax
// 0060fa7f  eb07                 jmp 0x60fa88
// 0060fa81  ba00010000           mov edx, 0x100
// 0060fa86  2bd0                 sub edx, eax
// 0060fa88  01542420             add dword ptr [esp + 0x20], edx
// 0060fa8c  836c243801           sub dword ptr [esp + 0x38], 1
// 0060fa91  75d3                 jne 0x60fa66
// 0060fa93  8b442414             mov eax, dword ptr [esp + 0x14]
// 0060fa97  39442430             cmp dword ptr [esp + 0x30], eax
// 0060fa9b  7351                 jae 0x60faee
// 0060fa9d  8d4900               lea ecx, [ecx]
// 0060faa0  0fb616               movzx edx, byte ptr [esi]
// 0060faa3  0fb64500             movzx eax, byte ptr [ebp]
// 0060faa7  03c2                 add eax, edx
// 0060faa9  99                   cdq 
// 0060faaa  2bc2                 sub eax, edx
// 0060faac  8bd0                 mov edx, eax
// 0060faae  8a07                 mov al, byte ptr [edi]
// 0060fab0  d1fa                 sar edx, 1
// 0060fab2  2ac2                 sub al, dl
// 0060fab4  8801                 mov byte ptr [ecx], al
// 0060fab6  0fb6c0               movzx eax, al
// 0060fab9  41                   inc ecx
// 0060faba  45                   inc ebp
// 0060fabb  46                   inc esi
// 0060fabc  47                   inc edi
// 0060fabd  3d80000000           cmp eax, 0x80
// 0060fac2  7d04                 jge 0x60fac8
// 0060fac4  8bd0                 mov edx, eax
// 0060fac6  eb07                 jmp 0x60facf
// 0060fac8  ba00010000           mov edx, 0x100
// 0060facd  2bd0                 sub edx, eax
// 0060facf  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060fad3  03c2                 add eax, edx
// 0060fad5  89442420             mov dword ptr [esp + 0x20], eax
// 0060fad9  3b442434             cmp eax, dword ptr [esp + 0x34]
// 0060fadd  770f                 ja 0x60faee
// 0060fadf  8b442430             mov eax, dword ptr [esp + 0x30]
// 0060fae3  40                   inc eax
// 0060fae4  89442430             mov dword ptr [esp + 0x30], eax
// 0060fae8  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0060faec  72b2                 jb 0x60faa0
// 0060faee  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0060faf5  7579                 jne 0x60fb70
// 0060faf7  8b542420             mov edx, dword ptr [esp + 0x20]
// 0060fafb  0fb7f2               movzx esi, dx
// 0060fafe  c1ea0a               shr edx, 0xa
// 0060fb01  33c9                 xor ecx, ecx
// 0060fb03  81e2c0ff3f00         and edx, 0x3fffc0
// 0060fb09  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0060fb0d  7e2f                 jle 0x60fb3e
// 0060fb0f  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 0060fb15  803c3900             cmp byte ptr [ecx + edi], 0
// 0060fb19  751c                 jne 0x60fb37
// 0060fb1b  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0060fb21  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0060fb25  8be8                 mov ebp, eax
// 0060fb27  0fafc2               imul eax, edx
// 0060fb2a  0fafee               imul ebp, esi
// 0060fb2d  c1ed08               shr ebp, 8
// 0060fb30  c1e808               shr eax, 8
// 0060fb33  8bf5                 mov esi, ebp
// 0060fb35  8bd0                 mov edx, eax
// 0060fb37  41                   inc ecx
// 0060fb38  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 0060fb3c  7cd7                 jl 0x60fb15
// 0060fb3e  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0060fb44  0fb74906             movzx ecx, word ptr [ecx + 6]
// 0060fb48  8bc1                 mov eax, ecx
// 0060fb4a  0fafc2               imul eax, edx
// 0060fb4d  c1e803               shr eax, 3
// 0060fb50  3dc0ff3f00           cmp eax, 0x3fffc0
// 0060fb55  760a                 jbe 0x60fb61
// 0060fb57  c7442420ffffff7f     mov dword ptr [esp + 0x20], 0x7fffffff
// 0060fb5f  eb0f                 jmp 0x60fb70
// 0060fb61  0fafce               imul ecx, esi
// 0060fb64  c1e903               shr ecx, 3
// 0060fb67  c1e00a               shl eax, 0xa
// 0060fb6a  03c8                 add ecx, eax
// 0060fb6c  894c2420             mov dword ptr [esp + 0x20], ecx
// 0060fb70  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060fb74  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 0060fb78  730e                 jae 0x60fb88
// 0060fb7a  8b93f8000000         mov edx, dword ptr [ebx + 0xf8]
// 0060fb80  8944241c             mov dword ptr [esp + 0x1c], eax
// 0060fb84  89542418             mov dword ptr [esp + 0x18], edx
// 0060fb88  807c241380           cmp byte ptr [esp + 0x13], 0x80
// 0060fb8d  0f8506feffff         jne 0x60f999
// 0060fb93  8b442428             mov eax, dword ptr [esp + 0x28]
// 0060fb97  8bbbfc000000         mov edi, dword ptr [ebx + 0xfc]
// 0060fb9d  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0060fba1  40                   inc eax
// 0060fba2  42                   inc edx
// 0060fba3  47                   inc edi
// 0060fba4  837c242400           cmp dword ptr [esp + 0x24], 0
// 0060fba9  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0060fbb1  8bc8                 mov ecx, eax
// 0060fbb3  89442430             mov dword ptr [esp + 0x30], eax
// 0060fbb7  8bf2                 mov esi, edx
// 0060fbb9  761b                 jbe 0x60fbd6
// 0060fbbb  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0060fbbf  896c2434             mov dword ptr [esp + 0x34], ebp
// 0060fbc3  8a19                 mov bl, byte ptr [ecx]
// 0060fbc5  2a1e                 sub bl, byte ptr [esi]
// 0060fbc7  47                   inc edi
// 0060fbc8  885fff               mov byte ptr [edi - 1], bl
// 0060fbcb  46                   inc esi
// 0060fbcc  41                   inc ecx
// 0060fbcd  83ed01               sub ebp, 1
// 0060fbd0  75f1                 jne 0x60fbc3
// 0060fbd2  894c2430             mov dword ptr [esp + 0x30], ecx
// 0060fbd6  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0060fbda  8be8                 mov ebp, eax
// 0060fbdc  395c2434             cmp dword ptr [esp + 0x34], ebx
// 0060fbe0  0f8388000000         jae 0x60fc6e
// 0060fbe6  8bca                 mov ecx, edx
// 0060fbe8  2bc8                 sub ecx, eax
// 0060fbea  2b5c2434             sub ebx, dword ptr [esp + 0x34]
// 0060fbee  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0060fbf2  895c2434             mov dword ptr [esp + 0x34], ebx
// 0060fbf6  eb0c                 jmp 0x60fc04
// 0060fbf8  eb06                 jmp 0x60fc00
// 0060fbfa  8d9b00000000         lea ebx, [ebx]
// 0060fc00  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0060fc04  0fb61429             movzx edx, byte ptr [ecx + ebp]
// 0060fc08  0fb606               movzx eax, byte ptr [esi]
// 0060fc0b  0fb64d00             movzx ecx, byte ptr [ebp]
// 0060fc0f  89442424             mov dword ptr [esp + 0x24], eax
// 0060fc13  894c2428             mov dword ptr [esp + 0x28], ecx
// 0060fc17  2bc2                 sub eax, edx
// 0060fc19  46                   inc esi
// 0060fc1a  45                   inc ebp
// 0060fc1b  2bca                 sub ecx, edx
// 0060fc1d  85c0                 test eax, eax
// 0060fc1f  7d0a                 jge 0x60fc2b
// 0060fc21  8bd8                 mov ebx, eax
// 0060fc23  f7db                 neg ebx
// 0060fc25  895c2438             mov dword ptr [esp + 0x38], ebx
// 0060fc29  eb04                 jmp 0x60fc2f
// 0060fc2b  89442438             mov dword ptr [esp + 0x38], eax
// 0060fc2f  8bd9                 mov ebx, ecx
// 0060fc31  85c9                 test ecx, ecx
// 0060fc33  7d02                 jge 0x60fc37
// 0060fc35  f7db                 neg ebx
// 0060fc37  03c1                 add eax, ecx
// 0060fc39  7902                 jns 0x60fc3d
// 0060fc3b  f7d8                 neg eax
// 0060fc3d  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0060fc41  3bcb                 cmp ecx, ebx
// 0060fc43  7f0a                 jg 0x60fc4f
// 0060fc45  3bc8                 cmp ecx, eax
// 0060fc47  7f06                 jg 0x60fc4f
// 0060fc49  8b542428             mov edx, dword ptr [esp + 0x28]
// 0060fc4d  eb08                 jmp 0x60fc57
// 0060fc4f  3bd8                 cmp ebx, eax
// 0060fc51  7f04                 jg 0x60fc57
// 0060fc53  8b542424             mov edx, dword ptr [esp + 0x24]
// 0060fc57  8b442430             mov eax, dword ptr [esp + 0x30]
// 0060fc5b  8a08                 mov cl, byte ptr [eax]
// 0060fc5d  2aca                 sub cl, dl
// 0060fc5f  880f                 mov byte ptr [edi], cl
// 0060fc61  40                   inc eax
// 0060fc62  47                   inc edi
// 0060fc63  836c243401           sub dword ptr [esp + 0x34], 1
// 0060fc68  89442430             mov dword ptr [esp + 0x30], eax
// 0060fc6c  7592                 jne 0x60fc00
// 0060fc6e  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 0060fc72  e9c9010000           jmp 0x60fe40
// 0060fc77  0fafd6               imul edx, esi
// 0060fc7a  c1ea03               shr edx, 3
// 0060fc7d  c1e00a               shl eax, 0xa
// 0060fc80  03d0                 add edx, eax
// 0060fc82  89542420             mov dword ptr [esp + 0x20], edx
// 0060fc86  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0060fc8a  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0060fc8e  8bb3fc000000         mov esi, dword ptr [ebx + 0xfc]
// 0060fc94  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060fc98  47                   inc edi
// 0060fc99  42                   inc edx
// 0060fc9a  46                   inc esi
// 0060fc9b  c744244400000000     mov dword ptr [esp + 0x44], 0
// 0060fca3  897c2428             mov dword ptr [esp + 0x28], edi
// 0060fca7  897c2434             mov dword ptr [esp + 0x34], edi
// 0060fcab  8954242c             mov dword ptr [esp + 0x2c], edx
// 0060fcaf  85c0                 test eax, eax
// 0060fcb1  763d                 jbe 0x60fcf0
// 0060fcb3  89442438             mov dword ptr [esp + 0x38], eax
// 0060fcb7  89442444             mov dword ptr [esp + 0x44], eax
// 0060fcbb  eb03                 jmp 0x60fcc0
// 0060fcbd  8d4900               lea ecx, [ecx]
// 0060fcc0  8a07                 mov al, byte ptr [edi]
// 0060fcc2  2a02                 sub al, byte ptr [edx]
// 0060fcc4  46                   inc esi
// 0060fcc5  8846ff               mov byte ptr [esi - 1], al
// 0060fcc8  0fb6c0               movzx eax, al
// 0060fccb  42                   inc edx
// 0060fccc  47                   inc edi
// 0060fccd  3d80000000           cmp eax, 0x80
// 0060fcd2  7d04                 jge 0x60fcd8
// 0060fcd4  8bc8                 mov ecx, eax
// 0060fcd6  eb07                 jmp 0x60fcdf
// 0060fcd8  b900010000           mov ecx, 0x100
// 0060fcdd  2bc8                 sub ecx, eax
// 0060fcdf  03e9                 add ebp, ecx
// 0060fce1  836c243801           sub dword ptr [esp + 0x38], 1
// 0060fce6  75d8                 jne 0x60fcc0
// 0060fce8  896c2430             mov dword ptr [esp + 0x30], ebp
// 0060fcec  897c2434             mov dword ptr [esp + 0x34], edi
// 0060fcf0  8b442444             mov eax, dword ptr [esp + 0x44]
// 0060fcf4  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0060fcf8  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0060fcfc  0f83b8000000         jae 0x60fdba
// 0060fd02  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0060fd06  2bf9                 sub edi, ecx
// 0060fd08  897c242c             mov dword ptr [esp + 0x2c], edi
// 0060fd0c  eb0e                 jmp 0x60fd1c
// 0060fd0e  8bff                 mov edi, edi
// 0060fd10  8b542428             mov edx, dword ptr [esp + 0x28]
// 0060fd14  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0060fd18  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0060fd1c  0fb602               movzx eax, byte ptr [edx]
// 0060fd1f  42                   inc edx
// 0060fd20  89542428             mov dword ptr [esp + 0x28], edx
// 0060fd24  0fb6140f             movzx edx, byte ptr [edi + ecx]
// 0060fd28  0fb639               movzx edi, byte ptr [ecx]
// 0060fd2b  41                   inc ecx
// 0060fd2c  894c2424             mov dword ptr [esp + 0x24], ecx
// 0060fd30  8944243c             mov dword ptr [esp + 0x3c], eax
// 0060fd34  8bcf                 mov ecx, edi
// 0060fd36  2bc2                 sub eax, edx
// 0060fd38  2bca                 sub ecx, edx
// 0060fd3a  85c0                 test eax, eax
// 0060fd3c  7d0a                 jge 0x60fd48
// 0060fd3e  8be8                 mov ebp, eax
// 0060fd40  f7dd                 neg ebp
// 0060fd42  896c2438             mov dword ptr [esp + 0x38], ebp
// 0060fd46  eb04                 jmp 0x60fd4c
// 0060fd48  89442438             mov dword ptr [esp + 0x38], eax
// 0060fd4c  8be9                 mov ebp, ecx
// 0060fd4e  85c9                 test ecx, ecx
// 0060fd50  7d02                 jge 0x60fd54
// 0060fd52  f7dd                 neg ebp
// 0060fd54  03c1                 add eax, ecx
// 0060fd56  7902                 jns 0x60fd5a
// 0060fd58  f7d8                 neg eax
// 0060fd5a  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0060fd5e  3bcd                 cmp ecx, ebp
// 0060fd60  7f08                 jg 0x60fd6a
// 0060fd62  3bc8                 cmp ecx, eax
// 0060fd64  7f04                 jg 0x60fd6a
// 0060fd66  8bd7                 mov edx, edi
// 0060fd68  eb08                 jmp 0x60fd72
// 0060fd6a  3be8                 cmp ebp, eax
// 0060fd6c  7f04                 jg 0x60fd72
// 0060fd6e  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0060fd72  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0060fd76  8a01                 mov al, byte ptr [ecx]
// 0060fd78  2ac2                 sub al, dl
// 0060fd7a  8806                 mov byte ptr [esi], al
// 0060fd7c  0fb6c0               movzx eax, al
// 0060fd7f  41                   inc ecx
// 0060fd80  46                   inc esi
// 0060fd81  3d80000000           cmp eax, 0x80
// 0060fd86  894c2434             mov dword ptr [esp + 0x34], ecx
// 0060fd8a  7d04                 jge 0x60fd90
// 0060fd8c  8bc8                 mov ecx, eax
// 0060fd8e  eb07                 jmp 0x60fd97
// 0060fd90  b900010000           mov ecx, 0x100
// 0060fd95  2bc8                 sub ecx, eax
// 0060fd97  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 0060fd9b  03e9                 add ebp, ecx
// 0060fd9d  896c2430             mov dword ptr [esp + 0x30], ebp
// 0060fda1  3b6c2420             cmp ebp, dword ptr [esp + 0x20]
// 0060fda5  7713                 ja 0x60fdba
// 0060fda7  8b442444             mov eax, dword ptr [esp + 0x44]
// 0060fdab  40                   inc eax
// 0060fdac  89442444             mov dword ptr [esp + 0x44], eax
// 0060fdb0  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0060fdb4  0f8256ffffff         jb 0x60fd10
// 0060fdba  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0060fdc1  7577                 jne 0x60fe3a
// 0060fdc3  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 0060fdc7  0fb7f5               movzx esi, bp
// 0060fdca  c1ed0a               shr ebp, 0xa
// 0060fdcd  81e5c0ff3f00         and ebp, 0x3fffc0
// 0060fdd3  33c9                 xor ecx, ecx
// 0060fdd5  8bd5                 mov edx, ebp
// 0060fdd7  85ff                 test edi, edi
// 0060fdd9  7e32                 jle 0x60fe0d
// 0060fddb  eb03                 jmp 0x60fde0
// 0060fddd  8d4900               lea ecx, [ecx]
// 0060fde0  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0060fde6  803c0104             cmp byte ptr [ecx + eax], 4
// 0060fdea  751c                 jne 0x60fe08
// 0060fdec  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0060fdf2  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0060fdf6  8be8                 mov ebp, eax
// 0060fdf8  0fafc2               imul eax, edx
// 0060fdfb  0fafee               imul ebp, esi
// 0060fdfe  c1ed08               shr ebp, 8
// 0060fe01  c1e808               shr eax, 8
// 0060fe04  8bf5                 mov esi, ebp
// 0060fe06  8bd0                 mov edx, eax
// 0060fe08  41                   inc ecx
// 0060fe09  3bcf                 cmp ecx, edi
// 0060fe0b  7cd3                 jl 0x60fde0
// 0060fe0d  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0060fe13  0fb74908             movzx ecx, word ptr [ecx + 8]
// 0060fe17  8bc1                 mov eax, ecx
// 0060fe19  0fafc2               imul eax, edx
// 0060fe1c  c1e803               shr eax, 3
// 0060fe1f  3dc0ff3f00           cmp eax, 0x3fffc0
// 0060fe24  7607                 jbe 0x60fe2d
// 0060fe26  bdffffff7f           mov ebp, 0x7fffffff
// 0060fe2b  eb0d                 jmp 0x60fe3a
// 0060fe2d  0fafce               imul ecx, esi
// 0060fe30  c1e903               shr ecx, 3
// 0060fe33  c1e00a               shl eax, 0xa
// 0060fe36  03c8                 add ecx, eax
// 0060fe38  8be9                 mov ebp, ecx
// 0060fe3a  3b6c241c             cmp ebp, dword ptr [esp + 0x1c]
// 0060fe3e  730a                 jae 0x60fe4a
// 0060fe40  8b93fc000000         mov edx, dword ptr [ebx + 0xfc]
// 0060fe46  89542418             mov dword ptr [esp + 0x18], edx
// 0060fe4a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0060fe4e  50                   push eax
// 0060fe4f  53                   push ebx
// 0060fe50  e83bf4ffff           call 0x60f290
// 0060fe55  83c408               add esp, 8
// 0060fe58  80bbf901000000       cmp byte ptr [ebx + 0x1f9], 0
// 0060fe5f  7633                 jbe 0x60fe94
// 0060fe61  b801000000           mov eax, 1
// 0060fe66  39442448             cmp dword ptr [esp + 0x48], eax
// 0060fe6a  7e19                 jle 0x60fe85
// 0060fe6c  8d642400             lea esp, [esp]
// 0060fe70  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 0060fe76  8a5401ff             mov dl, byte ptr [ecx + eax - 1]
// 0060fe7a  03c8                 add ecx, eax
// 0060fe7c  40                   inc eax
// 0060fe7d  3b442448             cmp eax, dword ptr [esp + 0x48]
// 0060fe81  8811                 mov byte ptr [ecx], dl
// 0060fe83  7ceb                 jl 0x60fe70
// 0060fe85  8b542418             mov edx, dword ptr [esp + 0x18]
// 0060fe89  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 0060fe8f  8a12                 mov dl, byte ptr [edx]
// 0060fe91  881408               mov byte ptr [eax + ecx], dl
// 0060fe94  5f                   pop edi
// 0060fe95  5e                   pop esi
// 0060fe96  5d                   pop ebp
// 0060fe97  5b                   pop ebx
// 0060fe98  83c430               add esp, 0x30
// 0060fe9b  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_find_filter)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
