// from server: 100% by auto
// roc 2010-06 0056a320  unit: seg_00560000  size: 1035 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056a320
//
// 0056a320  83ec10               sub esp, 0x10
// 0056a323  53                   push ebx
// 0056a324  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0056a328  8a4308               mov al, byte ptr [ebx + 8]
// 0056a32b  56                   push esi
// 0056a32c  8b33                 mov esi, dword ptr [ebx]
// 0056a32e  57                   push edi
// 0056a32f  84c0                 test al, al
// 0056a331  0f8562020000         jne 0x56a599
// 0056a337  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0056a33b  85c9                 test ecx, ecx
// 0056a33d  7406                 je 0x56a345
// 0056a33f  0fb75108             movzx edx, word ptr [ecx + 8]
// 0056a343  eb0c                 jmp 0x56a351
// 0056a345  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0056a34d  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056a351  8a4309               mov al, byte ptr [ebx + 9]
// 0056a354  55                   push ebp
// 0056a355  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0056a359  3c08                 cmp al, 8
// 0056a35b  0f8360010000         jae 0x56a4c1
// 0056a361  0fb6c0               movzx eax, al
// 0056a364  83e801               sub eax, 1
// 0056a367  0f84ea000000         je 0x56a457
// 0056a36d  83e801               sub eax, 1
// 0056a370  7473                 je 0x56a3e5
// 0056a372  83e802               sub eax, 2
// 0056a375  0f8537010000         jne 0x56a4b2
// 0056a37b  8bc2                 mov eax, edx
// 0056a37d  83e00f               and eax, 0xf
// 0056a380  8bc8                 mov ecx, eax
// 0056a382  c1e104               shl ecx, 4
// 0056a385  03c8                 add ecx, eax
// 0056a387  0fb7d1               movzx edx, cx
// 0056a38a  8d46ff               lea eax, [esi - 1]
// 0056a38d  83e001               and eax, 1
// 0056a390  03c0                 add eax, eax
// 0056a392  89542418             mov dword ptr [esp + 0x18], edx
// 0056a396  8d7eff               lea edi, [esi - 1]
// 0056a399  d1ef                 shr edi, 1
// 0056a39b  03c0                 add eax, eax
// 0056a39d  ba04000000           mov edx, 4
// 0056a3a2  03fd                 add edi, ebp
// 0056a3a4  2bd0                 sub edx, eax
// 0056a3a6  8d5c2eff             lea ebx, [esi + ebp - 1]
// 0056a3aa  85f6                 test esi, esi
// 0056a3ac  0f86f8000000         jbe 0x56a4aa
// 0056a3b2  8974241c             mov dword ptr [esp + 0x1c], esi
// 0056a3b6  0fb607               movzx eax, byte ptr [edi]
// 0056a3b9  8aca                 mov cl, dl
// 0056a3bb  d3e8                 shr eax, cl
// 0056a3bd  83e00f               and eax, 0xf
// 0056a3c0  8ac8                 mov cl, al
// 0056a3c2  c0e104               shl cl, 4
// 0056a3c5  0ac8                 or cl, al
// 0056a3c7  880b                 mov byte ptr [ebx], cl
// 0056a3c9  83fa04               cmp edx, 4
// 0056a3cc  7505                 jne 0x56a3d3
// 0056a3ce  33d2                 xor edx, edx
// 0056a3d0  4f                   dec edi
// 0056a3d1  eb05                 jmp 0x56a3d8
// 0056a3d3  ba04000000           mov edx, 4
// 0056a3d8  4b                   dec ebx
// 0056a3d9  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0056a3de  75d6                 jne 0x56a3b6
// 0056a3e0  e9c5000000           jmp 0x56a4aa
// 0056a3e5  83e203               and edx, 3
// 0056a3e8  6bd255               imul edx, edx, 0x55
// 0056a3eb  0fb7d2               movzx edx, dx
// 0056a3ee  89542418             mov dword ptr [esp + 0x18], edx
// 0056a3f2  8d46ff               lea eax, [esi - 1]
// 0056a3f5  83e003               and eax, 3
// 0056a3f8  8d7eff               lea edi, [esi - 1]
// 0056a3fb  ba03000000           mov edx, 3
// 0056a400  c1ef02               shr edi, 2
// 0056a403  2bd0                 sub edx, eax
// 0056a405  03fd                 add edi, ebp
// 0056a407  03d2                 add edx, edx
// 0056a409  8d5c2eff             lea ebx, [esi + ebp - 1]
// 0056a40d  85f6                 test esi, esi
// 0056a40f  0f8695000000         jbe 0x56a4aa
// 0056a415  8974241c             mov dword ptr [esp + 0x1c], esi
// 0056a419  8da42400000000       lea esp, [esp]
// 0056a420  0fb607               movzx eax, byte ptr [edi]
// 0056a423  8aca                 mov cl, dl
// 0056a425  d3e8                 shr eax, cl
// 0056a427  83e003               and eax, 3
// 0056a42a  8ac8                 mov cl, al
// 0056a42c  02c9                 add cl, cl
// 0056a42e  02c9                 add cl, cl
// 0056a430  0ac8                 or cl, al
// 0056a432  02c9                 add cl, cl
// 0056a434  02c9                 add cl, cl
// 0056a436  0ac8                 or cl, al
// 0056a438  02c9                 add cl, cl
// 0056a43a  02c9                 add cl, cl
// 0056a43c  0ac8                 or cl, al
// 0056a43e  880b                 mov byte ptr [ebx], cl
// 0056a440  83fa06               cmp edx, 6
// 0056a443  7505                 jne 0x56a44a
// 0056a445  33d2                 xor edx, edx
// 0056a447  4f                   dec edi
// 0056a448  eb03                 jmp 0x56a44d
// 0056a44a  83c202               add edx, 2
// 0056a44d  4b                   dec ebx
// 0056a44e  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0056a453  75cb                 jne 0x56a420
// 0056a455  eb53                 jmp 0x56a4aa
// 0056a457  83e201               and edx, 1
// 0056a45a  69d2ff000000         imul edx, edx, 0xff
// 0056a460  0fb7d2               movzx edx, dx
// 0056a463  8d7eff               lea edi, [esi - 1]
// 0056a466  8d4eff               lea ecx, [esi - 1]
// 0056a469  c1ef03               shr edi, 3
// 0056a46c  83e107               and ecx, 7
// 0056a46f  b807000000           mov eax, 7
// 0056a474  03fd                 add edi, ebp
// 0056a476  2bc1                 sub eax, ecx
// 0056a478  89542418             mov dword ptr [esp + 0x18], edx
// 0056a47c  8d542eff             lea edx, [esi + ebp - 1]
// 0056a480  85f6                 test esi, esi
// 0056a482  762a                 jbe 0x56a4ae
// 0056a484  8974241c             mov dword ptr [esp + 0x1c], esi
// 0056a488  8a1f                 mov bl, byte ptr [edi]
// 0056a48a  8ac8                 mov cl, al
// 0056a48c  d2eb                 shr bl, cl
// 0056a48e  80e301               and bl, 1
// 0056a491  f6db                 neg bl
// 0056a493  1adb                 sbb bl, bl
// 0056a495  881a                 mov byte ptr [edx], bl
// 0056a497  83f807               cmp eax, 7
// 0056a49a  7505                 jne 0x56a4a1
// 0056a49c  33c0                 xor eax, eax
// 0056a49e  4f                   dec edi
// 0056a49f  eb01                 jmp 0x56a4a2
// 0056a4a1  40                   inc eax
// 0056a4a2  4a                   dec edx
// 0056a4a3  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0056a4a8  75de                 jne 0x56a488
// 0056a4aa  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0056a4ae  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056a4b2  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0056a4b6  c6430908             mov byte ptr [ebx + 9], 8
// 0056a4ba  c6430b08             mov byte ptr [ebx + 0xb], 8
// 0056a4be  897304               mov dword ptr [ebx + 4], esi
// 0056a4c1  85c9                 test ecx, ecx
// 0056a4c3  0f84c8000000         je 0x56a591
// 0056a4c9  8a4309               mov al, byte ptr [ebx + 9]
// 0056a4cc  3c08                 cmp al, 8
// 0056a4ce  7533                 jne 0x56a503
// 0056a4d0  81e2ff000000         and edx, 0xff
// 0056a4d6  8d4c2eff             lea ecx, [esi + ebp - 1]
// 0056a4da  8d4475ff             lea eax, [ebp + esi*2 - 1]
// 0056a4de  85f6                 test esi, esi
// 0056a4e0  767b                 jbe 0x56a55d
// 0056a4e2  8bfe                 mov edi, esi
// 0056a4e4  660fb619             movzx bx, byte ptr [ecx]
// 0056a4e8  663bda               cmp bx, dx
// 0056a4eb  7505                 jne 0x56a4f2
// 0056a4ed  c60000               mov byte ptr [eax], 0
// 0056a4f0  eb03                 jmp 0x56a4f5
// 0056a4f2  c600ff               mov byte ptr [eax], 0xff
// 0056a4f5  8a19                 mov bl, byte ptr [ecx]
// 0056a4f7  48                   dec eax
// 0056a4f8  8818                 mov byte ptr [eax], bl
// 0056a4fa  48                   dec eax
// 0056a4fb  49                   dec ecx
// 0056a4fc  83ef01               sub edi, 1
// 0056a4ff  75e3                 jne 0x56a4e4
// 0056a501  eb56                 jmp 0x56a559
// 0056a503  3c10                 cmp al, 0x10
// 0056a505  7556                 jne 0x56a55d
// 0056a507  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056a50b  8b4004               mov eax, dword ptr [eax + 4]
// 0056a50e  8bda                 mov ebx, edx
// 0056a510  c1eb08               shr ebx, 8
// 0056a513  8d4c28ff             lea ecx, [eax + ebp - 1]
// 0056a517  885c2413             mov byte ptr [esp + 0x13], bl
// 0056a51b  8d4445ff             lea eax, [ebp + eax*2 - 1]
// 0056a51f  85f6                 test esi, esi
// 0056a521  7636                 jbe 0x56a559
// 0056a523  8bfe                 mov edi, esi
// 0056a525  eb04                 jmp 0x56a52b
// 0056a527  8a5c2413             mov bl, byte ptr [esp + 0x13]
// 0056a52b  3859ff               cmp byte ptr [ecx - 1], bl
// 0056a52e  750d                 jne 0x56a53d
// 0056a530  3811                 cmp byte ptr [ecx], dl
// 0056a532  7509                 jne 0x56a53d
// 0056a534  c60000               mov byte ptr [eax], 0
// 0056a537  48                   dec eax
// 0056a538  c60000               mov byte ptr [eax], 0
// 0056a53b  eb07                 jmp 0x56a544
// 0056a53d  c600ff               mov byte ptr [eax], 0xff
// 0056a540  48                   dec eax
// 0056a541  c600ff               mov byte ptr [eax], 0xff
// 0056a544  0fb619               movzx ebx, byte ptr [ecx]
// 0056a547  48                   dec eax
// 0056a548  8818                 mov byte ptr [eax], bl
// 0056a54a  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0056a54e  49                   dec ecx
// 0056a54f  48                   dec eax
// 0056a550  8818                 mov byte ptr [eax], bl
// 0056a552  48                   dec eax
// 0056a553  49                   dec ecx
// 0056a554  83ef01               sub edi, 1
// 0056a557  75ce                 jne 0x56a527
// 0056a559  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0056a55d  8a4309               mov al, byte ptr [ebx + 9]
// 0056a560  02c0                 add al, al
// 0056a562  88430b               mov byte ptr [ebx + 0xb], al
// 0056a565  3c08                 cmp al, 8
// 0056a567  c6430804             mov byte ptr [ebx + 8], 4
// 0056a56b  c6430a02             mov byte ptr [ebx + 0xa], 2
// 0056a56f  0fb6c0               movzx eax, al
// 0056a572  7211                 jb 0x56a585
// 0056a574  c1e803               shr eax, 3
// 0056a577  0fafc6               imul eax, esi
// 0056a57a  5d                   pop ebp
// 0056a57b  5f                   pop edi
// 0056a57c  5e                   pop esi
// 0056a57d  894304               mov dword ptr [ebx + 4], eax
// 0056a580  5b                   pop ebx
// 0056a581  83c410               add esp, 0x10
// 0056a584  c3                   ret 
// 0056a585  0fafc6               imul eax, esi
// 0056a588  83c007               add eax, 7
// 0056a58b  c1e803               shr eax, 3
// 0056a58e  894304               mov dword ptr [ebx + 4], eax
// 0056a591  5d                   pop ebp
// 0056a592  5f                   pop edi
// 0056a593  5e                   pop esi
// 0056a594  5b                   pop ebx
// 0056a595  83c410               add esp, 0x10
// 0056a598  c3                   ret 
// 0056a599  3c02                 cmp al, 2
// 0056a59b  75f5                 jne 0x56a592
// 0056a59d  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056a5a1  85c0                 test eax, eax
// 0056a5a3  74ed                 je 0x56a592
// 0056a5a5  8a4b09               mov cl, byte ptr [ebx + 9]
// 0056a5a8  80f908               cmp cl, 8
// 0056a5ab  7577                 jne 0x56a624
// 0056a5ad  8a4802               mov cl, byte ptr [eax + 2]
// 0056a5b0  8a5004               mov dl, byte ptr [eax + 4]
// 0056a5b3  8a4006               mov al, byte ptr [eax + 6]
// 0056a5b6  884c2420             mov byte ptr [esp + 0x20], cl
// 0056a5ba  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0056a5be  8854240f             mov byte ptr [esp + 0xf], dl
// 0056a5c2  8b5304               mov edx, dword ptr [ebx + 4]
// 0056a5c5  8d540aff             lea edx, [edx + ecx - 1]
// 0056a5c9  88442410             mov byte ptr [esp + 0x10], al
// 0056a5cd  8d4cb1ff             lea ecx, [ecx + esi*4 - 1]
// 0056a5d1  85f6                 test esi, esi
// 0056a5d3  0f8616010000         jbe 0x56a6ef
// 0056a5d9  8bfe                 mov edi, esi
// 0056a5db  eb03                 jmp 0x56a5e0
// 0056a5dd  8d4900               lea ecx, [ecx]
// 0056a5e0  8a442420             mov al, byte ptr [esp + 0x20]
// 0056a5e4  3842fe               cmp byte ptr [edx - 2], al
// 0056a5e7  7516                 jne 0x56a5ff
// 0056a5e9  8a44240f             mov al, byte ptr [esp + 0xf]
// 0056a5ed  3842ff               cmp byte ptr [edx - 1], al
// 0056a5f0  750d                 jne 0x56a5ff
// 0056a5f2  8a442410             mov al, byte ptr [esp + 0x10]
// 0056a5f6  3802                 cmp byte ptr [edx], al
// 0056a5f8  7505                 jne 0x56a5ff
// 0056a5fa  c60100               mov byte ptr [ecx], 0
// 0056a5fd  eb03                 jmp 0x56a602
// 0056a5ff  c601ff               mov byte ptr [ecx], 0xff
// 0056a602  0fb602               movzx eax, byte ptr [edx]
// 0056a605  49                   dec ecx
// 0056a606  8801                 mov byte ptr [ecx], al
// 0056a608  0fb642ff             movzx eax, byte ptr [edx - 1]
// 0056a60c  4a                   dec edx
// 0056a60d  49                   dec ecx
// 0056a60e  8801                 mov byte ptr [ecx], al
// 0056a610  0fb642ff             movzx eax, byte ptr [edx - 1]
// 0056a614  4a                   dec edx
// 0056a615  49                   dec ecx
// 0056a616  8801                 mov byte ptr [ecx], al
// 0056a618  49                   dec ecx
// 0056a619  4a                   dec edx
// 0056a61a  83ef01               sub edi, 1
// 0056a61d  75c1                 jne 0x56a5e0
// 0056a61f  e9cb000000           jmp 0x56a6ef
// 0056a624  80f910               cmp cl, 0x10
// 0056a627  0f85c2000000         jne 0x56a6ef
// 0056a62d  0fb64803             movzx ecx, byte ptr [eax + 3]
// 0056a631  0fb65005             movzx edx, byte ptr [eax + 5]
// 0056a635  884c2420             mov byte ptr [esp + 0x20], cl
// 0056a639  0fb64807             movzx ecx, byte ptr [eax + 7]
// 0056a63d  8854240f             mov byte ptr [esp + 0xf], dl
// 0056a641  0fb65002             movzx edx, byte ptr [eax + 2]
// 0056a645  884c2412             mov byte ptr [esp + 0x12], cl
// 0056a649  0fb64804             movzx ecx, byte ptr [eax + 4]
// 0056a64d  88542410             mov byte ptr [esp + 0x10], dl
// 0056a651  0fb65006             movzx edx, byte ptr [eax + 6]
// 0056a655  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056a659  884c2411             mov byte ptr [esp + 0x11], cl
// 0056a65d  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0056a660  8d4c01ff             lea ecx, [ecx + eax - 1]
// 0056a664  88542413             mov byte ptr [esp + 0x13], dl
// 0056a668  8d44f0ff             lea eax, [eax + esi*8 - 1]
// 0056a66c  85f6                 test esi, esi
// 0056a66e  767f                 jbe 0x56a6ef
// 0056a670  8bfe                 mov edi, esi
// 0056a672  8a542420             mov dl, byte ptr [esp + 0x20]
// 0056a676  3851fb               cmp byte ptr [ecx - 5], dl
// 0056a679  7535                 jne 0x56a6b0
// 0056a67b  8a542410             mov dl, byte ptr [esp + 0x10]
// 0056a67f  3851fc               cmp byte ptr [ecx - 4], dl
// 0056a682  752c                 jne 0x56a6b0
// 0056a684  8a54240f             mov dl, byte ptr [esp + 0xf]
// 0056a688  3851fd               cmp byte ptr [ecx - 3], dl
// 0056a68b  7523                 jne 0x56a6b0
// 0056a68d  8a542411             mov dl, byte ptr [esp + 0x11]
// 0056a691  3851fe               cmp byte ptr [ecx - 2], dl
// 0056a694  751a                 jne 0x56a6b0
// 0056a696  8a542412             mov dl, byte ptr [esp + 0x12]
// 0056a69a  3851ff               cmp byte ptr [ecx - 1], dl
// 0056a69d  7511                 jne 0x56a6b0
// 0056a69f  8a542413             mov dl, byte ptr [esp + 0x13]
// 0056a6a3  3811                 cmp byte ptr [ecx], dl
// 0056a6a5  7509                 jne 0x56a6b0
// 0056a6a7  c60000               mov byte ptr [eax], 0
// 0056a6aa  48                   dec eax
// 0056a6ab  c60000               mov byte ptr [eax], 0
// 0056a6ae  eb07                 jmp 0x56a6b7
// 0056a6b0  c600ff               mov byte ptr [eax], 0xff
// 0056a6b3  48                   dec eax
// 0056a6b4  c600ff               mov byte ptr [eax], 0xff
// 0056a6b7  0fb611               movzx edx, byte ptr [ecx]
// 0056a6ba  8850ff               mov byte ptr [eax - 1], dl
// 0056a6bd  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0056a6c1  48                   dec eax
// 0056a6c2  49                   dec ecx
// 0056a6c3  8850ff               mov byte ptr [eax - 1], dl
// 0056a6c6  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0056a6ca  48                   dec eax
// 0056a6cb  49                   dec ecx
// 0056a6cc  8850ff               mov byte ptr [eax - 1], dl
// 0056a6cf  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0056a6d3  48                   dec eax
// 0056a6d4  49                   dec ecx
// 0056a6d5  48                   dec eax
// 0056a6d6  8810                 mov byte ptr [eax], dl
// 0056a6d8  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0056a6dc  49                   dec ecx
// 0056a6dd  48                   dec eax
// 0056a6de  8810                 mov byte ptr [eax], dl
// 0056a6e0  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0056a6e4  49                   dec ecx
// 0056a6e5  48                   dec eax
// 0056a6e6  8810                 mov byte ptr [eax], dl
// 0056a6e8  48                   dec eax
// 0056a6e9  49                   dec ecx
// 0056a6ea  83ef01               sub edi, 1
// 0056a6ed  7583                 jne 0x56a672
// 0056a6ef  8a4309               mov al, byte ptr [ebx + 9]
// 0056a6f2  02c0                 add al, al
// 0056a6f4  02c0                 add al, al
// 0056a6f6  88430b               mov byte ptr [ebx + 0xb], al
// 0056a6f9  3c08                 cmp al, 8
// 0056a6fb  c6430806             mov byte ptr [ebx + 8], 6
// 0056a6ff  c6430a04             mov byte ptr [ebx + 0xa], 4
// 0056a703  0fb6c0               movzx eax, al
// 0056a706  7210                 jb 0x56a718
// 0056a708  c1e803               shr eax, 3
// 0056a70b  0fafc6               imul eax, esi
// 0056a70e  5f                   pop edi
// 0056a70f  5e                   pop esi
// 0056a710  894304               mov dword ptr [ebx + 4], eax
// 0056a713  5b                   pop ebx
// 0056a714  83c410               add esp, 0x10
// 0056a717  c3                   ret 
// 0056a718  0fafc6               imul eax, esi
// 0056a71b  83c007               add eax, 7
// 0056a71e  5f                   pop edi
// 0056a71f  c1e803               shr eax, 3
// 0056a722  5e                   pop esi
// 0056a723  894304               mov dword ptr [ebx + 4], eax
// 0056a726  5b                   pop ebx
// 0056a727  83c410               add esp, 0x10
// 0056a72a  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_do_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
