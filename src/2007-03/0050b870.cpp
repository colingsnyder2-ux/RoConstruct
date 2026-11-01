// from server: 100% by auto
// roc 2007-03 0050b870  unit: seg_00500000  size: 3999 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050b870
//
// 0050b870  51                   push ecx
// 0050b871  53                   push ebx
// 0050b872  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0050b876  8a832c010000         mov al, byte ptr [ebx + 0x12c]
// 0050b87c  3c08                 cmp al, 8
// 0050b87e  55                   push ebp
// 0050b87f  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0050b883  56                   push esi
// 0050b884  57                   push edi
// 0050b885  7367                 jae 0x50b8ee
// 0050b887  0fb6f8               movzx edi, al
// 0050b88a  be08000000           mov esi, 8
// 0050b88f  2bf7                 sub esi, edi
// 0050b891  56                   push esi
// 0050b892  8d442f20             lea eax, [edi + ebp + 0x20]
// 0050b896  50                   push eax
// 0050b897  53                   push ebx
// 0050b898  e803770000           call 0x512fa0
// 0050b89d  56                   push esi
// 0050b89e  83c520               add ebp, 0x20
// 0050b8a1  57                   push edi
// 0050b8a2  55                   push ebp
// 0050b8a3  c6832c01000008       mov byte ptr [ebx + 0x12c], 8
// 0050b8aa  e871ecffff           call 0x50a520
// 0050b8af  83c418               add esp, 0x18
// 0050b8b2  85c0                 test eax, eax
// 0050b8b4  742c                 je 0x50b8e2
// 0050b8b6  83ff04               cmp edi, 4
// 0050b8b9  7319                 jae 0x50b8d4
// 0050b8bb  83c6fc               add esi, -4
// 0050b8be  56                   push esi
// 0050b8bf  57                   push edi
// 0050b8c0  55                   push ebp
// 0050b8c1  e85aecffff           call 0x50a520
// 0050b8c6  83c40c               add esp, 0xc
// 0050b8c9  85c0                 test eax, eax
// 0050b8cb  7407                 je 0x50b8d4
// 0050b8cd  6890257a00           push 0x7a2590
// 0050b8d2  eb05                 jmp 0x50b8d9
// 0050b8d4  6868257a00           push 0x7a2568
// 0050b8d9  53                   push ebx
// 0050b8da  e841ca0000           call 0x518320
// 0050b8df  83c408               add esp, 8
// 0050b8e2  83ff03               cmp edi, 3
// 0050b8e5  7307                 jae 0x50b8ee
// 0050b8e7  814b6800100000       or dword ptr [ebx + 0x68], 0x1000
// 0050b8ee  8dbb1c010000         lea edi, [ebx + 0x11c]
// 0050b8f4  6a04                 push 4
// 0050b8f6  8d4c2414             lea ecx, [esp + 0x14]
// 0050b8fa  51                   push ecx
// 0050b8fb  53                   push ebx
// 0050b8fc  e89f760000           call 0x512fa0
// 0050b901  8d54241c             lea edx, [esp + 0x1c]
// 0050b905  52                   push edx
// 0050b906  53                   push ebx
// 0050b907  e834010100           call 0x51ba40
// 0050b90c  53                   push ebx
// 0050b90d  8be8                 mov ebp, eax
// 0050b90f  e8bcedffff           call 0x50a6d0
// 0050b914  6a04                 push 4
// 0050b916  57                   push edi
// 0050b917  53                   push ebx
// 0050b918  e8a3f00000           call 0x51a9c0
// 0050b91d  83c424               add esp, 0x24
// 0050b920  b804000000           mov eax, 4
// 0050b925  b99c0e7a00           mov ecx, 0x7a0e9c
// 0050b92a  8bd7                 mov edx, edi
// 0050b92c  8d642400             lea esp, [esp]
// 0050b930  8b32                 mov esi, dword ptr [edx]
// 0050b932  3b31                 cmp esi, dword ptr [ecx]
// 0050b934  7512                 jne 0x50b948
// 0050b936  83e804               sub eax, 4
// 0050b939  83c104               add ecx, 4
// 0050b93c  83c204               add edx, 4
// 0050b93f  83f804               cmp eax, 4
// 0050b942  73ec                 jae 0x50b930
// 0050b944  85c0                 test eax, eax
// 0050b946  745d                 je 0x50b9a5
// 0050b948  0fb619               movzx ebx, byte ptr [ecx]
// 0050b94b  0fb632               movzx esi, byte ptr [edx]
// 0050b94e  2bf3                 sub esi, ebx
// 0050b950  7545                 jne 0x50b997
// 0050b952  83e801               sub eax, 1
// 0050b955  83c101               add ecx, 1
// 0050b958  83c201               add edx, 1
// 0050b95b  85c0                 test eax, eax
// 0050b95d  7446                 je 0x50b9a5
// 0050b95f  0fb619               movzx ebx, byte ptr [ecx]
// 0050b962  0fb632               movzx esi, byte ptr [edx]
// 0050b965  2bf3                 sub esi, ebx
// 0050b967  752e                 jne 0x50b997
// 0050b969  83e801               sub eax, 1
// 0050b96c  83c101               add ecx, 1
// 0050b96f  83c201               add edx, 1
// 0050b972  85c0                 test eax, eax
// 0050b974  742f                 je 0x50b9a5
// 0050b976  0fb619               movzx ebx, byte ptr [ecx]
// 0050b979  0fb632               movzx esi, byte ptr [edx]
// 0050b97c  2bf3                 sub esi, ebx
// 0050b97e  7517                 jne 0x50b997
// 0050b980  83e801               sub eax, 1
// 0050b983  83c101               add ecx, 1
// 0050b986  83c201               add edx, 1
// 0050b989  85c0                 test eax, eax
// 0050b98b  7418                 je 0x50b9a5
// 0050b98d  0fb601               movzx eax, byte ptr [ecx]
// 0050b990  0fb632               movzx esi, byte ptr [edx]
// 0050b993  2bf0                 sub esi, eax
// 0050b995  740e                 je 0x50b9a5
// 0050b997  85f6                 test esi, esi
// 0050b999  b801000000           mov eax, 1
// 0050b99e  7f07                 jg 0x50b9a7
// 0050b9a0  83c8ff               or eax, 0xffffffff
// 0050b9a3  eb02                 jmp 0x50b9a7
// 0050b9a5  33c0                 xor eax, eax
// 0050b9a7  85c0                 test eax, eax
// 0050b9a9  7518                 jne 0x50b9c3
// 0050b9ab  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050b9af  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050b9b3  55                   push ebp
// 0050b9b4  51                   push ecx
// 0050b9b5  53                   push ebx
// 0050b9b6  e875010100           call 0x51bb30
// 0050b9bb  83c40c               add esp, 0xc
// 0050b9be  e931ffffff           jmp 0x50b8f4
// 0050b9c3  b804000000           mov eax, 4
// 0050b9c8  b9ac0e7a00           mov ecx, 0x7a0eac
// 0050b9cd  8bd7                 mov edx, edi
// 0050b9cf  90                   nop 
// 0050b9d0  8b32                 mov esi, dword ptr [edx]
// 0050b9d2  3b31                 cmp esi, dword ptr [ecx]
// 0050b9d4  7512                 jne 0x50b9e8
// 0050b9d6  83e804               sub eax, 4
// 0050b9d9  83c104               add ecx, 4
// 0050b9dc  83c204               add edx, 4
// 0050b9df  83f804               cmp eax, 4
// 0050b9e2  73ec                 jae 0x50b9d0
// 0050b9e4  85c0                 test eax, eax
// 0050b9e6  745d                 je 0x50ba45
// 0050b9e8  0fb632               movzx esi, byte ptr [edx]
// 0050b9eb  0fb619               movzx ebx, byte ptr [ecx]
// 0050b9ee  2bf3                 sub esi, ebx
// 0050b9f0  7545                 jne 0x50ba37
// 0050b9f2  83e801               sub eax, 1
// 0050b9f5  83c101               add ecx, 1
// 0050b9f8  83c201               add edx, 1
// 0050b9fb  85c0                 test eax, eax
// 0050b9fd  7446                 je 0x50ba45
// 0050b9ff  0fb632               movzx esi, byte ptr [edx]
// 0050ba02  0fb619               movzx ebx, byte ptr [ecx]
// 0050ba05  2bf3                 sub esi, ebx
// 0050ba07  752e                 jne 0x50ba37
// 0050ba09  83e801               sub eax, 1
// 0050ba0c  83c101               add ecx, 1
// 0050ba0f  83c201               add edx, 1
// 0050ba12  85c0                 test eax, eax
// 0050ba14  742f                 je 0x50ba45
// 0050ba16  0fb632               movzx esi, byte ptr [edx]
// 0050ba19  0fb619               movzx ebx, byte ptr [ecx]
// 0050ba1c  2bf3                 sub esi, ebx
// 0050ba1e  7517                 jne 0x50ba37
// 0050ba20  83e801               sub eax, 1
// 0050ba23  83c101               add ecx, 1
// 0050ba26  83c201               add edx, 1
// 0050ba29  85c0                 test eax, eax
// 0050ba2b  7418                 je 0x50ba45
// 0050ba2d  0fb632               movzx esi, byte ptr [edx]
// 0050ba30  0fb611               movzx edx, byte ptr [ecx]
// 0050ba33  2bf2                 sub esi, edx
// 0050ba35  740e                 je 0x50ba45
// 0050ba37  85f6                 test esi, esi
// 0050ba39  b801000000           mov eax, 1
// 0050ba3e  7f07                 jg 0x50ba47
// 0050ba40  83c8ff               or eax, 0xffffffff
// 0050ba43  eb02                 jmp 0x50ba47
// 0050ba45  33c0                 xor eax, eax
// 0050ba47  85c0                 test eax, eax
// 0050ba49  7518                 jne 0x50ba63
// 0050ba4b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0050ba4f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050ba53  55                   push ebp
// 0050ba54  50                   push eax
// 0050ba55  53                   push ebx
// 0050ba56  e8e5030100           call 0x51be40
// 0050ba5b  83c40c               add esp, 0xc
// 0050ba5e  e991feffff           jmp 0x50b8f4
// 0050ba63  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050ba67  57                   push edi
// 0050ba68  51                   push ecx
// 0050ba69  e822f1ffff           call 0x50ab90
// 0050ba6e  83c408               add esp, 8
// 0050ba71  85c0                 test eax, eax
// 0050ba73  8bd7                 mov edx, edi
// 0050ba75  b804000000           mov eax, 4
// 0050ba7a  0f84d1010000         je 0x50bc51
// 0050ba80  b9a40e7a00           mov ecx, 0x7a0ea4
// 0050ba85  8b32                 mov esi, dword ptr [edx]
// 0050ba87  3b31                 cmp esi, dword ptr [ecx]
// 0050ba89  7512                 jne 0x50ba9d
// 0050ba8b  83e804               sub eax, 4
// 0050ba8e  83c104               add ecx, 4
// 0050ba91  83c204               add edx, 4
// 0050ba94  83f804               cmp eax, 4
// 0050ba97  73ec                 jae 0x50ba85
// 0050ba99  85c0                 test eax, eax
// 0050ba9b  745d                 je 0x50bafa
// 0050ba9d  0fb619               movzx ebx, byte ptr [ecx]
// 0050baa0  0fb632               movzx esi, byte ptr [edx]
// 0050baa3  2bf3                 sub esi, ebx
// 0050baa5  7545                 jne 0x50baec
// 0050baa7  83e801               sub eax, 1
// 0050baaa  83c101               add ecx, 1
// 0050baad  83c201               add edx, 1
// 0050bab0  85c0                 test eax, eax
// 0050bab2  7446                 je 0x50bafa
// 0050bab4  0fb619               movzx ebx, byte ptr [ecx]
// 0050bab7  0fb632               movzx esi, byte ptr [edx]
// 0050baba  2bf3                 sub esi, ebx
// 0050babc  752e                 jne 0x50baec
// 0050babe  83e801               sub eax, 1
// 0050bac1  83c101               add ecx, 1
// 0050bac4  83c201               add edx, 1
// 0050bac7  85c0                 test eax, eax
// 0050bac9  742f                 je 0x50bafa
// 0050bacb  0fb619               movzx ebx, byte ptr [ecx]
// 0050bace  0fb632               movzx esi, byte ptr [edx]
// 0050bad1  2bf3                 sub esi, ebx
// 0050bad3  7517                 jne 0x50baec
// 0050bad5  83e801               sub eax, 1
// 0050bad8  83c101               add ecx, 1
// 0050badb  83c201               add edx, 1
// 0050bade  85c0                 test eax, eax
// 0050bae0  7418                 je 0x50bafa
// 0050bae2  0fb601               movzx eax, byte ptr [ecx]
// 0050bae5  0fb632               movzx esi, byte ptr [edx]
// 0050bae8  2bf0                 sub esi, eax
// 0050baea  740e                 je 0x50bafa
// 0050baec  85f6                 test esi, esi
// 0050baee  b801000000           mov eax, 1
// 0050baf3  7f07                 jg 0x50bafc
// 0050baf5  83c8ff               or eax, 0xffffffff
// 0050baf8  eb02                 jmp 0x50bafc
// 0050bafa  33c0                 xor eax, eax
// 0050bafc  85c0                 test eax, eax
// 0050bafe  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050bb02  7504                 jne 0x50bb08
// 0050bb04  834b6804             or dword ptr [ebx + 0x68], 4
// 0050bb08  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050bb0c  55                   push ebp
// 0050bb0d  51                   push ecx
// 0050bb0e  53                   push ebx
// 0050bb0f  e84c210100           call 0x51dc60
// 0050bb14  83c40c               add esp, 0xc
// 0050bb17  b804000000           mov eax, 4
// 0050bb1c  b9b40e7a00           mov ecx, 0x7a0eb4
// 0050bb21  8bd7                 mov edx, edi
// 0050bb23  8b32                 mov esi, dword ptr [edx]
// 0050bb25  3b31                 cmp esi, dword ptr [ecx]
// 0050bb27  7512                 jne 0x50bb3b
// 0050bb29  83e804               sub eax, 4
// 0050bb2c  83c104               add ecx, 4
// 0050bb2f  83c204               add edx, 4
// 0050bb32  83f804               cmp eax, 4
// 0050bb35  73ec                 jae 0x50bb23
// 0050bb37  85c0                 test eax, eax
// 0050bb39  745d                 je 0x50bb98
// 0050bb3b  0fb632               movzx esi, byte ptr [edx]
// 0050bb3e  0fb629               movzx ebp, byte ptr [ecx]
// 0050bb41  2bf5                 sub esi, ebp
// 0050bb43  7545                 jne 0x50bb8a
// 0050bb45  83e801               sub eax, 1
// 0050bb48  83c101               add ecx, 1
// 0050bb4b  83c201               add edx, 1
// 0050bb4e  85c0                 test eax, eax
// 0050bb50  7446                 je 0x50bb98
// 0050bb52  0fb632               movzx esi, byte ptr [edx]
// 0050bb55  0fb629               movzx ebp, byte ptr [ecx]
// 0050bb58  2bf5                 sub esi, ebp
// 0050bb5a  752e                 jne 0x50bb8a
// 0050bb5c  83e801               sub eax, 1
// 0050bb5f  83c101               add ecx, 1
// 0050bb62  83c201               add edx, 1
// 0050bb65  85c0                 test eax, eax
// 0050bb67  742f                 je 0x50bb98
// 0050bb69  0fb632               movzx esi, byte ptr [edx]
// 0050bb6c  0fb629               movzx ebp, byte ptr [ecx]
// 0050bb6f  2bf5                 sub esi, ebp
// 0050bb71  7517                 jne 0x50bb8a
// 0050bb73  83e801               sub eax, 1
// 0050bb76  83c101               add ecx, 1
// 0050bb79  83c201               add edx, 1
// 0050bb7c  85c0                 test eax, eax
// 0050bb7e  7418                 je 0x50bb98
// 0050bb80  0fb632               movzx esi, byte ptr [edx]
// 0050bb83  0fb611               movzx edx, byte ptr [ecx]
// 0050bb86  2bf2                 sub esi, edx
// 0050bb88  740e                 je 0x50bb98
// 0050bb8a  85f6                 test esi, esi
// 0050bb8c  b801000000           mov eax, 1
// 0050bb91  7f07                 jg 0x50bb9a
// 0050bb93  83c8ff               or eax, 0xffffffff
// 0050bb96  eb02                 jmp 0x50bb9a
// 0050bb98  33c0                 xor eax, eax
// 0050bb9a  85c0                 test eax, eax
// 0050bb9c  7509                 jne 0x50bba7
// 0050bb9e  834b6802             or dword ptr [ebx + 0x68], 2
// 0050bba2  e94dfdffff           jmp 0x50b8f4
// 0050bba7  b804000000           mov eax, 4
// 0050bbac  b9a40e7a00           mov ecx, 0x7a0ea4
// 0050bbb1  8bd7                 mov edx, edi
// 0050bbb3  8b32                 mov esi, dword ptr [edx]
// 0050bbb5  3b31                 cmp esi, dword ptr [ecx]
// 0050bbb7  7512                 jne 0x50bbcb
// 0050bbb9  83e804               sub eax, 4
// 0050bbbc  83c104               add ecx, 4
// 0050bbbf  83c204               add edx, 4
// 0050bbc2  83f804               cmp eax, 4
// 0050bbc5  73ec                 jae 0x50bbb3
// 0050bbc7  85c0                 test eax, eax
// 0050bbc9  745d                 je 0x50bc28
// 0050bbcb  0fb629               movzx ebp, byte ptr [ecx]
// 0050bbce  0fb632               movzx esi, byte ptr [edx]
// 0050bbd1  2bf5                 sub esi, ebp
// 0050bbd3  7545                 jne 0x50bc1a
// 0050bbd5  83e801               sub eax, 1
// 0050bbd8  83c101               add ecx, 1
// 0050bbdb  83c201               add edx, 1
// 0050bbde  85c0                 test eax, eax
// 0050bbe0  7446                 je 0x50bc28
// 0050bbe2  0fb629               movzx ebp, byte ptr [ecx]
// 0050bbe5  0fb632               movzx esi, byte ptr [edx]
// 0050bbe8  2bf5                 sub esi, ebp
// 0050bbea  752e                 jne 0x50bc1a
// 0050bbec  83e801               sub eax, 1
// 0050bbef  83c101               add ecx, 1
// 0050bbf2  83c201               add edx, 1
// 0050bbf5  85c0                 test eax, eax
// 0050bbf7  742f                 je 0x50bc28
// 0050bbf9  0fb629               movzx ebp, byte ptr [ecx]
// 0050bbfc  0fb632               movzx esi, byte ptr [edx]
// 0050bbff  2bf5                 sub esi, ebp
// 0050bc01  7517                 jne 0x50bc1a
// 0050bc03  83e801               sub eax, 1
// 0050bc06  83c101               add ecx, 1
// 0050bc09  83c201               add edx, 1
// 0050bc0c  85c0                 test eax, eax
// 0050bc0e  7418                 je 0x50bc28
// 0050bc10  0fb601               movzx eax, byte ptr [ecx]
// 0050bc13  0fb632               movzx esi, byte ptr [edx]
// 0050bc16  2bf0                 sub esi, eax
// 0050bc18  740e                 je 0x50bc28
// 0050bc1a  85f6                 test esi, esi
// 0050bc1c  b801000000           mov eax, 1
// 0050bc21  7f07                 jg 0x50bc2a
// 0050bc23  83c8ff               or eax, 0xffffffff
// 0050bc26  eb02                 jmp 0x50bc2a
// 0050bc28  33c0                 xor eax, eax
// 0050bc2a  85c0                 test eax, eax
// 0050bc2c  0f85c2fcffff         jne 0x50b8f4
// 0050bc32  8b4368               mov eax, dword ptr [ebx + 0x68]
// 0050bc35  a801                 test al, 1
// 0050bc37  0f85700b0000         jne 0x50c7ad
// 0050bc3d  684c257a00           push 0x7a254c
// 0050bc42  53                   push ebx
// 0050bc43  e8d8c60000           call 0x518320
// 0050bc48  83c408               add esp, 8
// 0050bc4b  5f                   pop edi
// 0050bc4c  5e                   pop esi
// 0050bc4d  5d                   pop ebp
// 0050bc4e  5b                   pop ebx
// 0050bc4f  59                   pop ecx
// 0050bc50  c3                   ret 
// 0050bc51  b9b40e7a00           mov ecx, 0x7a0eb4
// 0050bc56  8b32                 mov esi, dword ptr [edx]
// 0050bc58  3b31                 cmp esi, dword ptr [ecx]
// 0050bc5a  7512                 jne 0x50bc6e
// 0050bc5c  83e804               sub eax, 4
// 0050bc5f  83c104               add ecx, 4
// 0050bc62  83c204               add edx, 4
// 0050bc65  83f804               cmp eax, 4
// 0050bc68  73ec                 jae 0x50bc56
// 0050bc6a  85c0                 test eax, eax
// 0050bc6c  745d                 je 0x50bccb
// 0050bc6e  0fb632               movzx esi, byte ptr [edx]
// 0050bc71  0fb619               movzx ebx, byte ptr [ecx]
// 0050bc74  2bf3                 sub esi, ebx
// 0050bc76  7545                 jne 0x50bcbd
// 0050bc78  83e801               sub eax, 1
// 0050bc7b  83c101               add ecx, 1
// 0050bc7e  83c201               add edx, 1
// 0050bc81  85c0                 test eax, eax
// 0050bc83  7446                 je 0x50bccb
// 0050bc85  0fb632               movzx esi, byte ptr [edx]
// 0050bc88  0fb619               movzx ebx, byte ptr [ecx]
// 0050bc8b  2bf3                 sub esi, ebx
// 0050bc8d  752e                 jne 0x50bcbd
// 0050bc8f  83e801               sub eax, 1
// 0050bc92  83c101               add ecx, 1
// 0050bc95  83c201               add edx, 1
// 0050bc98  85c0                 test eax, eax
// 0050bc9a  742f                 je 0x50bccb
// 0050bc9c  0fb632               movzx esi, byte ptr [edx]
// 0050bc9f  0fb619               movzx ebx, byte ptr [ecx]
// 0050bca2  2bf3                 sub esi, ebx
// 0050bca4  7517                 jne 0x50bcbd
// 0050bca6  83e801               sub eax, 1
// 0050bca9  83c101               add ecx, 1
// 0050bcac  83c201               add edx, 1
// 0050bcaf  85c0                 test eax, eax
// 0050bcb1  7418                 je 0x50bccb
// 0050bcb3  0fb632               movzx esi, byte ptr [edx]
// 0050bcb6  0fb609               movzx ecx, byte ptr [ecx]
// 0050bcb9  2bf1                 sub esi, ecx
// 0050bcbb  740e                 je 0x50bccb
// 0050bcbd  85f6                 test esi, esi
// 0050bcbf  b801000000           mov eax, 1
// 0050bcc4  7f07                 jg 0x50bccd
// 0050bcc6  83c8ff               or eax, 0xffffffff
// 0050bcc9  eb02                 jmp 0x50bccd
// 0050bccb  33c0                 xor eax, eax
// 0050bccd  85c0                 test eax, eax
// 0050bccf  7518                 jne 0x50bce9
// 0050bcd1  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050bcd5  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050bcd9  55                   push ebp
// 0050bcda  52                   push edx
// 0050bcdb  53                   push ebx
// 0050bcdc  e8cfff0000           call 0x51bcb0
// 0050bce1  83c40c               add esp, 0xc
// 0050bce4  e90bfcffff           jmp 0x50b8f4
// 0050bce9  b804000000           mov eax, 4
// 0050bcee  b9a40e7a00           mov ecx, 0x7a0ea4
// 0050bcf3  8bd7                 mov edx, edi
// 0050bcf5  8b32                 mov esi, dword ptr [edx]
// 0050bcf7  3b31                 cmp esi, dword ptr [ecx]
// 0050bcf9  7512                 jne 0x50bd0d
// 0050bcfb  83e804               sub eax, 4
// 0050bcfe  83c104               add ecx, 4
// 0050bd01  83c204               add edx, 4
// 0050bd04  83f804               cmp eax, 4
// 0050bd07  73ec                 jae 0x50bcf5
// 0050bd09  85c0                 test eax, eax
// 0050bd0b  745d                 je 0x50bd6a
// 0050bd0d  0fb619               movzx ebx, byte ptr [ecx]
// 0050bd10  0fb632               movzx esi, byte ptr [edx]
// 0050bd13  2bf3                 sub esi, ebx
// 0050bd15  7545                 jne 0x50bd5c
// 0050bd17  83e801               sub eax, 1
// 0050bd1a  83c101               add ecx, 1
// 0050bd1d  83c201               add edx, 1
// 0050bd20  85c0                 test eax, eax
// 0050bd22  7446                 je 0x50bd6a
// 0050bd24  0fb619               movzx ebx, byte ptr [ecx]
// 0050bd27  0fb632               movzx esi, byte ptr [edx]
// 0050bd2a  2bf3                 sub esi, ebx
// 0050bd2c  752e                 jne 0x50bd5c
// 0050bd2e  83e801               sub eax, 1
// 0050bd31  83c101               add ecx, 1
// 0050bd34  83c201               add edx, 1
// 0050bd37  85c0                 test eax, eax
// 0050bd39  742f                 je 0x50bd6a
// 0050bd3b  0fb619               movzx ebx, byte ptr [ecx]
// 0050bd3e  0fb632               movzx esi, byte ptr [edx]
// 0050bd41  2bf3                 sub esi, ebx
// 0050bd43  7517                 jne 0x50bd5c
// 0050bd45  83e801               sub eax, 1
// 0050bd48  83c101               add ecx, 1
// 0050bd4b  83c201               add edx, 1
// 0050bd4e  85c0                 test eax, eax
// 0050bd50  7418                 je 0x50bd6a
// 0050bd52  0fb601               movzx eax, byte ptr [ecx]
// 0050bd55  0fb632               movzx esi, byte ptr [edx]
// 0050bd58  2bf0                 sub esi, eax
// 0050bd5a  740e                 je 0x50bd6a
// 0050bd5c  85f6                 test esi, esi
// 0050bd5e  b801000000           mov eax, 1
// 0050bd63  7f07                 jg 0x50bd6c
// 0050bd65  83c8ff               or eax, 0xffffffff
// 0050bd68  eb02                 jmp 0x50bd6c
// 0050bd6a  33c0                 xor eax, eax
// 0050bd6c  85c0                 test eax, eax
// 0050bd6e  0f845e0a0000         je 0x50c7d2
// 0050bd74  b804000000           mov eax, 4
// 0050bd79  b9bc0e7a00           mov ecx, 0x7a0ebc
// 0050bd7e  8bd7                 mov edx, edi
// 0050bd80  8b32                 mov esi, dword ptr [edx]
// 0050bd82  3b31                 cmp esi, dword ptr [ecx]
// 0050bd84  7512                 jne 0x50bd98
// 0050bd86  83e804               sub eax, 4
// 0050bd89  83c104               add ecx, 4
// 0050bd8c  83c204               add edx, 4
// 0050bd8f  83f804               cmp eax, 4
// 0050bd92  73ec                 jae 0x50bd80
// 0050bd94  85c0                 test eax, eax
// 0050bd96  745d                 je 0x50bdf5
// 0050bd98  0fb632               movzx esi, byte ptr [edx]
// 0050bd9b  0fb619               movzx ebx, byte ptr [ecx]
// 0050bd9e  2bf3                 sub esi, ebx
// 0050bda0  7545                 jne 0x50bde7
// 0050bda2  83e801               sub eax, 1
// 0050bda5  83c101               add ecx, 1
// 0050bda8  83c201               add edx, 1
// 0050bdab  85c0                 test eax, eax
// 0050bdad  7446                 je 0x50bdf5
// 0050bdaf  0fb632               movzx esi, byte ptr [edx]
// 0050bdb2  0fb619               movzx ebx, byte ptr [ecx]
// 0050bdb5  2bf3                 sub esi, ebx
// 0050bdb7  752e                 jne 0x50bde7
// 0050bdb9  83e801               sub eax, 1
// 0050bdbc  83c101               add ecx, 1
// 0050bdbf  83c201               add edx, 1
// 0050bdc2  85c0                 test eax, eax
// 0050bdc4  742f                 je 0x50bdf5
// 0050bdc6  0fb632               movzx esi, byte ptr [edx]
// 0050bdc9  0fb619               movzx ebx, byte ptr [ecx]
// 0050bdcc  2bf3                 sub esi, ebx
// 0050bdce  7517                 jne 0x50bde7
// 0050bdd0  83e801               sub eax, 1
// 0050bdd3  83c101               add ecx, 1
// 0050bdd6  83c201               add edx, 1
// 0050bdd9  85c0                 test eax, eax
// 0050bddb  7418                 je 0x50bdf5
// 0050bddd  0fb632               movzx esi, byte ptr [edx]
// 0050bde0  0fb609               movzx ecx, byte ptr [ecx]
// 0050bde3  2bf1                 sub esi, ecx
// 0050bde5  740e                 je 0x50bdf5
// 0050bde7  85f6                 test esi, esi
// 0050bde9  b801000000           mov eax, 1
// 0050bdee  7f07                 jg 0x50bdf7
// 0050bdf0  83c8ff               or eax, 0xffffffff
// 0050bdf3  eb02                 jmp 0x50bdf7
// 0050bdf5  33c0                 xor eax, eax
// 0050bdf7  85c0                 test eax, eax
// 0050bdf9  7518                 jne 0x50be13
// 0050bdfb  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050bdff  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050be03  55                   push ebp
// 0050be04  52                   push edx
// 0050be05  53                   push ebx
// 0050be06  e865100100           call 0x51ce70
// 0050be0b  83c40c               add esp, 0xc
// 0050be0e  e9e1faffff           jmp 0x50b8f4
// 0050be13  b804000000           mov eax, 4
// 0050be18  b9c40e7a00           mov ecx, 0x7a0ec4
// 0050be1d  8bd7                 mov edx, edi
// 0050be1f  90                   nop 
// 0050be20  8b32                 mov esi, dword ptr [edx]
// 0050be22  3b31                 cmp esi, dword ptr [ecx]
// 0050be24  7512                 jne 0x50be38
// 0050be26  83e804               sub eax, 4
// 0050be29  83c104               add ecx, 4
// 0050be2c  83c204               add edx, 4
// 0050be2f  83f804               cmp eax, 4
// 0050be32  73ec                 jae 0x50be20
// 0050be34  85c0                 test eax, eax
// 0050be36  745d                 je 0x50be95
// 0050be38  0fb619               movzx ebx, byte ptr [ecx]
// 0050be3b  0fb632               movzx esi, byte ptr [edx]
// 0050be3e  2bf3                 sub esi, ebx
// 0050be40  7545                 jne 0x50be87
// 0050be42  83e801               sub eax, 1
// 0050be45  83c101               add ecx, 1
// 0050be48  83c201               add edx, 1
// 0050be4b  85c0                 test eax, eax
// 0050be4d  7446                 je 0x50be95
// 0050be4f  0fb619               movzx ebx, byte ptr [ecx]
// 0050be52  0fb632               movzx esi, byte ptr [edx]
// 0050be55  2bf3                 sub esi, ebx
// 0050be57  752e                 jne 0x50be87
// 0050be59  83e801               sub eax, 1
// 0050be5c  83c101               add ecx, 1
// 0050be5f  83c201               add edx, 1
// 0050be62  85c0                 test eax, eax
// 0050be64  742f                 je 0x50be95
// 0050be66  0fb619               movzx ebx, byte ptr [ecx]
// 0050be69  0fb632               movzx esi, byte ptr [edx]
// 0050be6c  2bf3                 sub esi, ebx
// 0050be6e  7517                 jne 0x50be87
// 0050be70  83e801               sub eax, 1
// 0050be73  83c101               add ecx, 1
// 0050be76  83c201               add edx, 1
// 0050be79  85c0                 test eax, eax
// 0050be7b  7418                 je 0x50be95
// 0050be7d  0fb601               movzx eax, byte ptr [ecx]
// 0050be80  0fb632               movzx esi, byte ptr [edx]
// 0050be83  2bf0                 sub esi, eax
// 0050be85  740e                 je 0x50be95
// 0050be87  85f6                 test esi, esi
// 0050be89  b801000000           mov eax, 1
// 0050be8e  7f07                 jg 0x50be97
// 0050be90  83c8ff               or eax, 0xffffffff
// 0050be93  eb02                 jmp 0x50be97
// 0050be95  33c0                 xor eax, eax
// 0050be97  85c0                 test eax, eax
// 0050be99  7518                 jne 0x50beb3
// 0050be9b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050be9f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050bea3  55                   push ebp
// 0050bea4  51                   push ecx
// 0050bea5  53                   push ebx
// 0050bea6  e8c5020100           call 0x51c170
// 0050beab  83c40c               add esp, 0xc
// 0050beae  e941faffff           jmp 0x50b8f4
// 0050beb3  b804000000           mov eax, 4
// 0050beb8  b9cc0e7a00           mov ecx, 0x7a0ecc
// 0050bebd  8bd7                 mov edx, edi
// 0050bebf  90                   nop 
// 0050bec0  8b32                 mov esi, dword ptr [edx]
// 0050bec2  3b31                 cmp esi, dword ptr [ecx]
// 0050bec4  7512                 jne 0x50bed8
// 0050bec6  83e804               sub eax, 4
// 0050bec9  83c104               add ecx, 4
// 0050becc  83c204               add edx, 4
// 0050becf  83f804               cmp eax, 4
// 0050bed2  73ec                 jae 0x50bec0
// 0050bed4  85c0                 test eax, eax
// 0050bed6  745d                 je 0x50bf35
// 0050bed8  0fb632               movzx esi, byte ptr [edx]
// 0050bedb  0fb619               movzx ebx, byte ptr [ecx]
// 0050bede  2bf3                 sub esi, ebx
// 0050bee0  7545                 jne 0x50bf27
// 0050bee2  83e801               sub eax, 1
// 0050bee5  83c101               add ecx, 1
// 0050bee8  83c201               add edx, 1
// 0050beeb  85c0                 test eax, eax
// 0050beed  7446                 je 0x50bf35
// 0050beef  0fb632               movzx esi, byte ptr [edx]
// 0050bef2  0fb619               movzx ebx, byte ptr [ecx]
// 0050bef5  2bf3                 sub esi, ebx
// 0050bef7  752e                 jne 0x50bf27
// 0050bef9  83e801               sub eax, 1
// 0050befc  83c101               add ecx, 1
// 0050beff  83c201               add edx, 1
// 0050bf02  85c0                 test eax, eax
// 0050bf04  742f                 je 0x50bf35
// 0050bf06  0fb632               movzx esi, byte ptr [edx]
// 0050bf09  0fb619               movzx ebx, byte ptr [ecx]
// 0050bf0c  2bf3                 sub esi, ebx
// 0050bf0e  7517                 jne 0x50bf27
// 0050bf10  83e801               sub eax, 1
// 0050bf13  83c101               add ecx, 1
// 0050bf16  83c201               add edx, 1
// 0050bf19  85c0                 test eax, eax
// 0050bf1b  7418                 je 0x50bf35
// 0050bf1d  0fb632               movzx esi, byte ptr [edx]
// 0050bf20  0fb611               movzx edx, byte ptr [ecx]
// 0050bf23  2bf2                 sub esi, edx
// 0050bf25  740e                 je 0x50bf35
// 0050bf27  85f6                 test esi, esi
// 0050bf29  b801000000           mov eax, 1
// 0050bf2e  7f07                 jg 0x50bf37
// 0050bf30  83c8ff               or eax, 0xffffffff
// 0050bf33  eb02                 jmp 0x50bf37
// 0050bf35  33c0                 xor eax, eax
// 0050bf37  85c0                 test eax, eax
// 0050bf39  7518                 jne 0x50bf53
// 0050bf3b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0050bf3f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050bf43  55                   push ebp
// 0050bf44  50                   push eax
// 0050bf45  53                   push ebx
// 0050bf46  e845ff0000           call 0x51be90
// 0050bf4b  83c40c               add esp, 0xc
// 0050bf4e  e9a1f9ffff           jmp 0x50b8f4
// 0050bf53  b804000000           mov eax, 4
// 0050bf58  b9d40e7a00           mov ecx, 0x7a0ed4
// 0050bf5d  8bd7                 mov edx, edi
// 0050bf5f  90                   nop 
// 0050bf60  8b32                 mov esi, dword ptr [edx]
// 0050bf62  3b31                 cmp esi, dword ptr [ecx]
// 0050bf64  7512                 jne 0x50bf78
// 0050bf66  83e804               sub eax, 4
// 0050bf69  83c104               add ecx, 4
// 0050bf6c  83c204               add edx, 4
// 0050bf6f  83f804               cmp eax, 4
// 0050bf72  73ec                 jae 0x50bf60
// 0050bf74  85c0                 test eax, eax
// 0050bf76  745d                 je 0x50bfd5
// 0050bf78  0fb619               movzx ebx, byte ptr [ecx]
// 0050bf7b  0fb632               movzx esi, byte ptr [edx]
// 0050bf7e  2bf3                 sub esi, ebx
// 0050bf80  7545                 jne 0x50bfc7
// 0050bf82  83e801               sub eax, 1
// 0050bf85  83c101               add ecx, 1
// 0050bf88  83c201               add edx, 1
// 0050bf8b  85c0                 test eax, eax
// 0050bf8d  7446                 je 0x50bfd5
// 0050bf8f  0fb619               movzx ebx, byte ptr [ecx]
// 0050bf92  0fb632               movzx esi, byte ptr [edx]
// 0050bf95  2bf3                 sub esi, ebx
// 0050bf97  752e                 jne 0x50bfc7
// 0050bf99  83e801               sub eax, 1
// 0050bf9c  83c101               add ecx, 1
// 0050bf9f  83c201               add edx, 1
// 0050bfa2  85c0                 test eax, eax
// 0050bfa4  742f                 je 0x50bfd5
// 0050bfa6  0fb619               movzx ebx, byte ptr [ecx]
// 0050bfa9  0fb632               movzx esi, byte ptr [edx]
// 0050bfac  2bf3                 sub esi, ebx
// 0050bfae  7517                 jne 0x50bfc7
// 0050bfb0  83e801               sub eax, 1
// 0050bfb3  83c101               add ecx, 1
// 0050bfb6  83c201               add edx, 1
// 0050bfb9  85c0                 test eax, eax
// 0050bfbb  7418                 je 0x50bfd5
// 0050bfbd  0fb609               movzx ecx, byte ptr [ecx]
// 0050bfc0  0fb632               movzx esi, byte ptr [edx]
// 0050bfc3  2bf1                 sub esi, ecx
// 0050bfc5  740e                 je 0x50bfd5
// 0050bfc7  85f6                 test esi, esi
// 0050bfc9  b801000000           mov eax, 1
// 0050bfce  7f07                 jg 0x50bfd7
// 0050bfd0  83c8ff               or eax, 0xffffffff
// 0050bfd3  eb02                 jmp 0x50bfd7
// 0050bfd5  33c0                 xor eax, eax
// 0050bfd7  85c0                 test eax, eax
// 0050bfd9  7518                 jne 0x50bff3
// 0050bfdb  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050bfdf  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050bfe3  55                   push ebp
// 0050bfe4  52                   push edx
// 0050bfe5  53                   push ebx
// 0050bfe6  e8c5100100           call 0x51d0b0
// 0050bfeb  83c40c               add esp, 0xc
// 0050bfee  e901f9ffff           jmp 0x50b8f4
// 0050bff3  b804000000           mov eax, 4
// 0050bff8  b9ec0e7a00           mov ecx, 0x7a0eec
// 0050bffd  8bd7                 mov edx, edi
// 0050bfff  90                   nop 
// 0050c000  8b32                 mov esi, dword ptr [edx]
// 0050c002  3b31                 cmp esi, dword ptr [ecx]
// 0050c004  7512                 jne 0x50c018
// 0050c006  83e804               sub eax, 4
// 0050c009  83c104               add ecx, 4
// 0050c00c  83c204               add edx, 4
// 0050c00f  83f804               cmp eax, 4
// 0050c012  73ec                 jae 0x50c000
// 0050c014  85c0                 test eax, eax
// 0050c016  745d                 je 0x50c075
// 0050c018  0fb632               movzx esi, byte ptr [edx]
// 0050c01b  0fb619               movzx ebx, byte ptr [ecx]
// 0050c01e  2bf3                 sub esi, ebx
// 0050c020  7545                 jne 0x50c067
// 0050c022  83e801               sub eax, 1
// 0050c025  83c101               add ecx, 1
// 0050c028  83c201               add edx, 1
// 0050c02b  85c0                 test eax, eax
// 0050c02d  7446                 je 0x50c075
// 0050c02f  0fb632               movzx esi, byte ptr [edx]
// 0050c032  0fb619               movzx ebx, byte ptr [ecx]
// 0050c035  2bf3                 sub esi, ebx
// 0050c037  752e                 jne 0x50c067
// 0050c039  83e801               sub eax, 1
// 0050c03c  83c101               add ecx, 1
// 0050c03f  83c201               add edx, 1
// 0050c042  85c0                 test eax, eax
// 0050c044  742f                 je 0x50c075
// 0050c046  0fb632               movzx esi, byte ptr [edx]
// 0050c049  0fb619               movzx ebx, byte ptr [ecx]
// 0050c04c  2bf3                 sub esi, ebx
// 0050c04e  7517                 jne 0x50c067
// 0050c050  83e801               sub eax, 1
// 0050c053  83c101               add ecx, 1
// 0050c056  83c201               add edx, 1
// 0050c059  85c0                 test eax, eax
// 0050c05b  7418                 je 0x50c075
// 0050c05d  0fb632               movzx esi, byte ptr [edx]
// 0050c060  0fb601               movzx eax, byte ptr [ecx]
// 0050c063  2bf0                 sub esi, eax
// 0050c065  740e                 je 0x50c075
// 0050c067  85f6                 test esi, esi
// 0050c069  b801000000           mov eax, 1
// 0050c06e  7f07                 jg 0x50c077
// 0050c070  83c8ff               or eax, 0xffffffff
// 0050c073  eb02                 jmp 0x50c077
// 0050c075  33c0                 xor eax, eax
// 0050c077  85c0                 test eax, eax
// 0050c079  7518                 jne 0x50c093
// 0050c07b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050c07f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c083  55                   push ebp
// 0050c084  51                   push ecx
// 0050c085  53                   push ebx
// 0050c086  e8e5120100           call 0x51d370
// 0050c08b  83c40c               add esp, 0xc
// 0050c08e  e961f8ffff           jmp 0x50b8f4
// 0050c093  b804000000           mov eax, 4
// 0050c098  b9f40e7a00           mov ecx, 0x7a0ef4
// 0050c09d  8bd7                 mov edx, edi
// 0050c09f  90                   nop 
// 0050c0a0  8b32                 mov esi, dword ptr [edx]
// 0050c0a2  3b31                 cmp esi, dword ptr [ecx]
// 0050c0a4  7512                 jne 0x50c0b8
// 0050c0a6  83e804               sub eax, 4
// 0050c0a9  83c104               add ecx, 4
// 0050c0ac  83c204               add edx, 4
// 0050c0af  83f804               cmp eax, 4
// 0050c0b2  73ec                 jae 0x50c0a0
// 0050c0b4  85c0                 test eax, eax
// 0050c0b6  745d                 je 0x50c115
// 0050c0b8  0fb619               movzx ebx, byte ptr [ecx]
// 0050c0bb  0fb632               movzx esi, byte ptr [edx]
// 0050c0be  2bf3                 sub esi, ebx
// 0050c0c0  7545                 jne 0x50c107
// 0050c0c2  83e801               sub eax, 1
// 0050c0c5  83c101               add ecx, 1
// 0050c0c8  83c201               add edx, 1
// 0050c0cb  85c0                 test eax, eax
// 0050c0cd  7446                 je 0x50c115
// 0050c0cf  0fb619               movzx ebx, byte ptr [ecx]
// 0050c0d2  0fb632               movzx esi, byte ptr [edx]
// 0050c0d5  2bf3                 sub esi, ebx
// 0050c0d7  752e                 jne 0x50c107
// 0050c0d9  83e801               sub eax, 1
// 0050c0dc  83c101               add ecx, 1
// 0050c0df  83c201               add edx, 1
// 0050c0e2  85c0                 test eax, eax
// 0050c0e4  742f                 je 0x50c115
// 0050c0e6  0fb619               movzx ebx, byte ptr [ecx]
// 0050c0e9  0fb632               movzx esi, byte ptr [edx]
// 0050c0ec  2bf3                 sub esi, ebx
// 0050c0ee  7517                 jne 0x50c107
// 0050c0f0  83e801               sub eax, 1
// 0050c0f3  83c101               add ecx, 1
// 0050c0f6  83c201               add edx, 1
// 0050c0f9  85c0                 test eax, eax
// 0050c0fb  7418                 je 0x50c115
// 0050c0fd  0fb601               movzx eax, byte ptr [ecx]
// 0050c100  0fb632               movzx esi, byte ptr [edx]
// 0050c103  2bf0                 sub esi, eax
// 0050c105  740e                 je 0x50c115
// 0050c107  85f6                 test esi, esi
// 0050c109  b801000000           mov eax, 1
// 0050c10e  7f07                 jg 0x50c117
// 0050c110  83c8ff               or eax, 0xffffffff
// 0050c113  eb02                 jmp 0x50c117
// 0050c115  33c0                 xor eax, eax
// 0050c117  85c0                 test eax, eax
// 0050c119  7518                 jne 0x50c133
// 0050c11b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050c11f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c123  55                   push ebp
// 0050c124  51                   push ecx
// 0050c125  53                   push ebx
// 0050c126  e875130100           call 0x51d4a0
// 0050c12b  83c40c               add esp, 0xc
// 0050c12e  e9c1f7ffff           jmp 0x50b8f4
// 0050c133  b804000000           mov eax, 4
// 0050c138  b9fc0e7a00           mov ecx, 0x7a0efc
// 0050c13d  8bd7                 mov edx, edi
// 0050c13f  90                   nop 
// 0050c140  8b32                 mov esi, dword ptr [edx]
// 0050c142  3b31                 cmp esi, dword ptr [ecx]
// 0050c144  7512                 jne 0x50c158
// 0050c146  83e804               sub eax, 4
// 0050c149  83c104               add ecx, 4
// 0050c14c  83c204               add edx, 4
// 0050c14f  83f804               cmp eax, 4
// 0050c152  73ec                 jae 0x50c140
// 0050c154  85c0                 test eax, eax
// 0050c156  745d                 je 0x50c1b5
// 0050c158  0fb632               movzx esi, byte ptr [edx]
// 0050c15b  0fb619               movzx ebx, byte ptr [ecx]
// 0050c15e  2bf3                 sub esi, ebx
// 0050c160  7545                 jne 0x50c1a7
// 0050c162  83e801               sub eax, 1
// 0050c165  83c101               add ecx, 1
// 0050c168  83c201               add edx, 1
// 0050c16b  85c0                 test eax, eax
// 0050c16d  7446                 je 0x50c1b5
// 0050c16f  0fb632               movzx esi, byte ptr [edx]
// 0050c172  0fb619               movzx ebx, byte ptr [ecx]
// 0050c175  2bf3                 sub esi, ebx
// 0050c177  752e                 jne 0x50c1a7
// 0050c179  83e801               sub eax, 1
// 0050c17c  83c101               add ecx, 1
// 0050c17f  83c201               add edx, 1
// 0050c182  85c0                 test eax, eax
// 0050c184  742f                 je 0x50c1b5
// 0050c186  0fb632               movzx esi, byte ptr [edx]
// 0050c189  0fb619               movzx ebx, byte ptr [ecx]
// 0050c18c  2bf3                 sub esi, ebx
// 0050c18e  7517                 jne 0x50c1a7
// 0050c190  83e801               sub eax, 1
// 0050c193  83c101               add ecx, 1
// 0050c196  83c201               add edx, 1
// 0050c199  85c0                 test eax, eax
// 0050c19b  7418                 je 0x50c1b5
// 0050c19d  0fb632               movzx esi, byte ptr [edx]
// 0050c1a0  0fb611               movzx edx, byte ptr [ecx]
// 0050c1a3  2bf2                 sub esi, edx
// 0050c1a5  740e                 je 0x50c1b5
// 0050c1a7  85f6                 test esi, esi
// 0050c1a9  b801000000           mov eax, 1
// 0050c1ae  7f07                 jg 0x50c1b7
// 0050c1b0  83c8ff               or eax, 0xffffffff
// 0050c1b3  eb02                 jmp 0x50c1b7
// 0050c1b5  33c0                 xor eax, eax
// 0050c1b7  85c0                 test eax, eax
// 0050c1b9  7518                 jne 0x50c1d3
// 0050c1bb  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0050c1bf  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c1c3  55                   push ebp
// 0050c1c4  50                   push eax
// 0050c1c5  53                   push ebx
// 0050c1c6  e835150100           call 0x51d700
// 0050c1cb  83c40c               add esp, 0xc
// 0050c1ce  e921f7ffff           jmp 0x50b8f4
// 0050c1d3  b804000000           mov eax, 4
// 0050c1d8  b9040f7a00           mov ecx, 0x7a0f04
// 0050c1dd  8bd7                 mov edx, edi
// 0050c1df  90                   nop 
// 0050c1e0  8b32                 mov esi, dword ptr [edx]
// 0050c1e2  3b31                 cmp esi, dword ptr [ecx]
// 0050c1e4  7512                 jne 0x50c1f8
// 0050c1e6  83e804               sub eax, 4
// 0050c1e9  83c104               add ecx, 4
// 0050c1ec  83c204               add edx, 4
// 0050c1ef  83f804               cmp eax, 4
// 0050c1f2  73ec                 jae 0x50c1e0
// 0050c1f4  85c0                 test eax, eax
// 0050c1f6  745d                 je 0x50c255
// 0050c1f8  0fb619               movzx ebx, byte ptr [ecx]
// 0050c1fb  0fb632               movzx esi, byte ptr [edx]
// 0050c1fe  2bf3                 sub esi, ebx
// 0050c200  7545                 jne 0x50c247
// 0050c202  83e801               sub eax, 1
// 0050c205  83c101               add ecx, 1
// 0050c208  83c201               add edx, 1
// 0050c20b  85c0                 test eax, eax
// 0050c20d  7446                 je 0x50c255
// 0050c20f  0fb619               movzx ebx, byte ptr [ecx]
// 0050c212  0fb632               movzx esi, byte ptr [edx]
// 0050c215  2bf3                 sub esi, ebx
// 0050c217  752e                 jne 0x50c247
// 0050c219  83e801               sub eax, 1
// 0050c21c  83c101               add ecx, 1
// 0050c21f  83c201               add edx, 1
// 0050c222  85c0                 test eax, eax
// 0050c224  742f                 je 0x50c255
// 0050c226  0fb619               movzx ebx, byte ptr [ecx]
// 0050c229  0fb632               movzx esi, byte ptr [edx]
// 0050c22c  2bf3                 sub esi, ebx
// 0050c22e  7517                 jne 0x50c247
// 0050c230  83e801               sub eax, 1
// 0050c233  83c101               add ecx, 1
// 0050c236  83c201               add edx, 1
// 0050c239  85c0                 test eax, eax
// 0050c23b  7418                 je 0x50c255
// 0050c23d  0fb609               movzx ecx, byte ptr [ecx]
// 0050c240  0fb632               movzx esi, byte ptr [edx]
// 0050c243  2bf1                 sub esi, ecx
// 0050c245  740e                 je 0x50c255
// 0050c247  85f6                 test esi, esi
// 0050c249  b801000000           mov eax, 1
// 0050c24e  7f07                 jg 0x50c257
// 0050c250  83c8ff               or eax, 0xffffffff
// 0050c253  eb02                 jmp 0x50c257
// 0050c255  33c0                 xor eax, eax
// 0050c257  85c0                 test eax, eax
// 0050c259  7518                 jne 0x50c273
// 0050c25b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050c25f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c263  55                   push ebp
// 0050c264  52                   push edx
// 0050c265  53                   push ebx
// 0050c266  e8e50f0100           call 0x51d250
// 0050c26b  83c40c               add esp, 0xc
// 0050c26e  e981f6ffff           jmp 0x50b8f4
// 0050c273  b804000000           mov eax, 4
// 0050c278  b90c0f7a00           mov ecx, 0x7a0f0c
// 0050c27d  8bd7                 mov edx, edi
// 0050c27f  90                   nop 
// 0050c280  8b32                 mov esi, dword ptr [edx]
// 0050c282  3b31                 cmp esi, dword ptr [ecx]
// 0050c284  7516                 jne 0x50c29c
// 0050c286  83e804               sub eax, 4
// 0050c289  83c104               add ecx, 4
// 0050c28c  83c204               add edx, 4
// 0050c28f  83f804               cmp eax, 4
// 0050c292  73ec                 jae 0x50c280
// 0050c294  85c0                 test eax, eax
// 0050c296  0f845d000000         je 0x50c2f9
// 0050c29c  0fb632               movzx esi, byte ptr [edx]
// 0050c29f  0fb619               movzx ebx, byte ptr [ecx]
// 0050c2a2  2bf3                 sub esi, ebx
// 0050c2a4  7545                 jne 0x50c2eb
// 0050c2a6  83e801               sub eax, 1
// 0050c2a9  83c101               add ecx, 1
// 0050c2ac  83c201               add edx, 1
// 0050c2af  85c0                 test eax, eax
// 0050c2b1  7446                 je 0x50c2f9
// 0050c2b3  0fb632               movzx esi, byte ptr [edx]
// 0050c2b6  0fb619               movzx ebx, byte ptr [ecx]
// 0050c2b9  2bf3                 sub esi, ebx
// 0050c2bb  752e                 jne 0x50c2eb
// 0050c2bd  83e801               sub eax, 1
// 0050c2c0  83c101               add ecx, 1
// 0050c2c3  83c201               add edx, 1
// 0050c2c6  85c0                 test eax, eax
// 0050c2c8  742f                 je 0x50c2f9
// 0050c2ca  0fb632               movzx esi, byte ptr [edx]
// 0050c2cd  0fb619               movzx ebx, byte ptr [ecx]
// 0050c2d0  2bf3                 sub esi, ebx
// 0050c2d2  7517                 jne 0x50c2eb
// 0050c2d4  83e801               sub eax, 1
// 0050c2d7  83c101               add ecx, 1
// 0050c2da  83c201               add edx, 1
// 0050c2dd  85c0                 test eax, eax
// 0050c2df  7418                 je 0x50c2f9
// 0050c2e1  0fb632               movzx esi, byte ptr [edx]
// 0050c2e4  0fb601               movzx eax, byte ptr [ecx]
// 0050c2e7  2bf0                 sub esi, eax
// 0050c2e9  740e                 je 0x50c2f9
// 0050c2eb  85f6                 test esi, esi
// 0050c2ed  b801000000           mov eax, 1
// 0050c2f2  7f07                 jg 0x50c2fb
// 0050c2f4  83c8ff               or eax, 0xffffffff
// 0050c2f7  eb02                 jmp 0x50c2fb
// 0050c2f9  33c0                 xor eax, eax
// 0050c2fb  85c0                 test eax, eax
// 0050c2fd  7518                 jne 0x50c317
// 0050c2ff  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050c303  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c307  55                   push ebp
// 0050c308  51                   push ecx
// 0050c309  53                   push ebx
// 0050c30a  e8f1fc0000           call 0x51c000
// 0050c30f  83c40c               add esp, 0xc
// 0050c312  e9ddf5ffff           jmp 0x50b8f4
// 0050c317  b804000000           mov eax, 4
// 0050c31c  b91c0f7a00           mov ecx, 0x7a0f1c
// 0050c321  8bd7                 mov edx, edi
// 0050c323  8b32                 mov esi, dword ptr [edx]
// 0050c325  3b31                 cmp esi, dword ptr [ecx]
// 0050c327  7516                 jne 0x50c33f
// 0050c329  83e804               sub eax, 4
// 0050c32c  83c104               add ecx, 4
// 0050c32f  83c204               add edx, 4
// 0050c332  83f804               cmp eax, 4
// 0050c335  73ec                 jae 0x50c323
// 0050c337  85c0                 test eax, eax
// 0050c339  0f845d000000         je 0x50c39c
// 0050c33f  0fb619               movzx ebx, byte ptr [ecx]
// 0050c342  0fb632               movzx esi, byte ptr [edx]
// 0050c345  2bf3                 sub esi, ebx
// 0050c347  7545                 jne 0x50c38e
// 0050c349  83e801               sub eax, 1
// 0050c34c  83c101               add ecx, 1
// 0050c34f  83c201               add edx, 1
// 0050c352  85c0                 test eax, eax
// 0050c354  7446                 je 0x50c39c
// 0050c356  0fb619               movzx ebx, byte ptr [ecx]
// 0050c359  0fb632               movzx esi, byte ptr [edx]
// 0050c35c  2bf3                 sub esi, ebx
// 0050c35e  752e                 jne 0x50c38e
// 0050c360  83e801               sub eax, 1
// 0050c363  83c101               add ecx, 1
// 0050c366  83c201               add edx, 1
// 0050c369  85c0                 test eax, eax
// 0050c36b  742f                 je 0x50c39c
// 0050c36d  0fb619               movzx ebx, byte ptr [ecx]
// 0050c370  0fb632               movzx esi, byte ptr [edx]
// 0050c373  2bf3                 sub esi, ebx
// 0050c375  7517                 jne 0x50c38e
// 0050c377  83e801               sub eax, 1
// 0050c37a  83c101               add ecx, 1
// 0050c37d  83c201               add edx, 1
// 0050c380  85c0                 test eax, eax
// 0050c382  7418                 je 0x50c39c
// 0050c384  0fb601               movzx eax, byte ptr [ecx]
// 0050c387  0fb632               movzx esi, byte ptr [edx]
// 0050c38a  2bf0                 sub esi, eax
// 0050c38c  740e                 je 0x50c39c
// 0050c38e  85f6                 test esi, esi
// 0050c390  b801000000           mov eax, 1
// 0050c395  7f07                 jg 0x50c39e
// 0050c397  83c8ff               or eax, 0xffffffff
// 0050c39a  eb02                 jmp 0x50c39e
// 0050c39c  33c0                 xor eax, eax
// 0050c39e  85c0                 test eax, eax
// 0050c3a0  7518                 jne 0x50c3ba
// 0050c3a2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050c3a6  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c3aa  55                   push ebp
// 0050c3ab  51                   push ecx
// 0050c3ac  53                   push ebx
// 0050c3ad  e8ae020100           call 0x51c660
// 0050c3b2  83c40c               add esp, 0xc
// 0050c3b5  e93af5ffff           jmp 0x50b8f4
// 0050c3ba  b804000000           mov eax, 4
// 0050c3bf  b9dc0e7a00           mov ecx, 0x7a0edc
// 0050c3c4  8bd7                 mov edx, edi
// 0050c3c6  8b32                 mov esi, dword ptr [edx]
// 0050c3c8  3b31                 cmp esi, dword ptr [ecx]
// 0050c3ca  7516                 jne 0x50c3e2
// 0050c3cc  83e804               sub eax, 4
// 0050c3cf  83c104               add ecx, 4
// 0050c3d2  83c204               add edx, 4
// 0050c3d5  83f804               cmp eax, 4
// 0050c3d8  73ec                 jae 0x50c3c6
// 0050c3da  85c0                 test eax, eax
// 0050c3dc  0f845d000000         je 0x50c43f
// 0050c3e2  0fb632               movzx esi, byte ptr [edx]
// 0050c3e5  0fb619               movzx ebx, byte ptr [ecx]
// 0050c3e8  2bf3                 sub esi, ebx
// 0050c3ea  7545                 jne 0x50c431
// 0050c3ec  83e801               sub eax, 1
// 0050c3ef  83c101               add ecx, 1
// 0050c3f2  83c201               add edx, 1
// 0050c3f5  85c0                 test eax, eax
// 0050c3f7  7446                 je 0x50c43f
// 0050c3f9  0fb632               movzx esi, byte ptr [edx]
// 0050c3fc  0fb619               movzx ebx, byte ptr [ecx]
// 0050c3ff  2bf3                 sub esi, ebx
// 0050c401  752e                 jne 0x50c431
// 0050c403  83e801               sub eax, 1
// 0050c406  83c101               add ecx, 1
// 0050c409  83c201               add edx, 1
// 0050c40c  85c0                 test eax, eax
// 0050c40e  742f                 je 0x50c43f
// 0050c410  0fb632               movzx esi, byte ptr [edx]
// 0050c413  0fb619               movzx ebx, byte ptr [ecx]
// 0050c416  2bf3                 sub esi, ebx
// 0050c418  7517                 jne 0x50c431
// 0050c41a  83e801               sub eax, 1
// 0050c41d  83c101               add ecx, 1
// 0050c420  83c201               add edx, 1
// 0050c423  85c0                 test eax, eax
// 0050c425  7418                 je 0x50c43f
// 0050c427  0fb632               movzx esi, byte ptr [edx]
// 0050c42a  0fb611               movzx edx, byte ptr [ecx]
// 0050c42d  2bf2                 sub esi, edx
// 0050c42f  740e                 je 0x50c43f
// 0050c431  85f6                 test esi, esi
// 0050c433  b801000000           mov eax, 1
// 0050c438  7f07                 jg 0x50c441
// 0050c43a  83c8ff               or eax, 0xffffffff
// 0050c43d  eb02                 jmp 0x50c441
// 0050c43f  33c0                 xor eax, eax
// 0050c441  85c0                 test eax, eax
// 0050c443  7518                 jne 0x50c45d
// 0050c445  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0050c449  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c44d  55                   push ebp
// 0050c44e  50                   push eax
// 0050c44f  53                   push ebx
// 0050c450  e8fb030100           call 0x51c850
// 0050c455  83c40c               add esp, 0xc
// 0050c458  e997f4ffff           jmp 0x50b8f4
// 0050c45d  b804000000           mov eax, 4
// 0050c462  b9140f7a00           mov ecx, 0x7a0f14
// 0050c467  8bd7                 mov edx, edi
// 0050c469  8da42400000000       lea esp, [esp]
// 0050c470  8b32                 mov esi, dword ptr [edx]
// 0050c472  3b31                 cmp esi, dword ptr [ecx]
// 0050c474  7516                 jne 0x50c48c
// 0050c476  83e804               sub eax, 4
// 0050c479  83c104               add ecx, 4
// 0050c47c  83c204               add edx, 4
// 0050c47f  83f804               cmp eax, 4
// 0050c482  73ec                 jae 0x50c470
// 0050c484  85c0                 test eax, eax
// 0050c486  0f845d000000         je 0x50c4e9
// 0050c48c  0fb619               movzx ebx, byte ptr [ecx]
// 0050c48f  0fb632               movzx esi, byte ptr [edx]
// 0050c492  2bf3                 sub esi, ebx
// 0050c494  7545                 jne 0x50c4db
// 0050c496  83e801               sub eax, 1
// 0050c499  83c101               add ecx, 1
// 0050c49c  83c201               add edx, 1
// 0050c49f  85c0                 test eax, eax
// 0050c4a1  7446                 je 0x50c4e9
// 0050c4a3  0fb619               movzx ebx, byte ptr [ecx]
// 0050c4a6  0fb632               movzx esi, byte ptr [edx]
// 0050c4a9  2bf3                 sub esi, ebx
// 0050c4ab  752e                 jne 0x50c4db
// 0050c4ad  83e801               sub eax, 1
// 0050c4b0  83c101               add ecx, 1
// 0050c4b3  83c201               add edx, 1
// 0050c4b6  85c0                 test eax, eax
// 0050c4b8  742f                 je 0x50c4e9
// 0050c4ba  0fb619               movzx ebx, byte ptr [ecx]
// 0050c4bd  0fb632               movzx esi, byte ptr [edx]
// 0050c4c0  2bf3                 sub esi, ebx
// 0050c4c2  7517                 jne 0x50c4db
// 0050c4c4  83e801               sub eax, 1
// 0050c4c7  83c101               add ecx, 1
// 0050c4ca  83c201               add edx, 1
// 0050c4cd  85c0                 test eax, eax
// 0050c4cf  7418                 je 0x50c4e9
// 0050c4d1  0fb609               movzx ecx, byte ptr [ecx]
// 0050c4d4  0fb632               movzx esi, byte ptr [edx]
// 0050c4d7  2bf1                 sub esi, ecx
// 0050c4d9  740e                 je 0x50c4e9
// 0050c4db  85f6                 test esi, esi
// 0050c4dd  b801000000           mov eax, 1
// 0050c4e2  7f07                 jg 0x50c4eb
// 0050c4e4  83c8ff               or eax, 0xffffffff
// 0050c4e7  eb02                 jmp 0x50c4eb
// 0050c4e9  33c0                 xor eax, eax
// 0050c4eb  85c0                 test eax, eax
// 0050c4ed  7518                 jne 0x50c507
// 0050c4ef  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050c4f3  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c4f7  55                   push ebp
// 0050c4f8  52                   push edx
// 0050c4f9  53                   push ebx
// 0050c4fa  e801050100           call 0x51ca00
// 0050c4ff  83c40c               add esp, 0xc
// 0050c502  e9edf3ffff           jmp 0x50b8f4
// 0050c507  b804000000           mov eax, 4
// 0050c50c  b9240f7a00           mov ecx, 0x7a0f24
// 0050c511  8bd7                 mov edx, edi
// 0050c513  8b32                 mov esi, dword ptr [edx]
// 0050c515  3b31                 cmp esi, dword ptr [ecx]
// 0050c517  7516                 jne 0x50c52f
// 0050c519  83e804               sub eax, 4
// 0050c51c  83c104               add ecx, 4
// 0050c51f  83c204               add edx, 4
// 0050c522  83f804               cmp eax, 4
// 0050c525  73ec                 jae 0x50c513
// 0050c527  85c0                 test eax, eax
// 0050c529  0f845d000000         je 0x50c58c
// 0050c52f  0fb632               movzx esi, byte ptr [edx]
// 0050c532  0fb619               movzx ebx, byte ptr [ecx]
// 0050c535  2bf3                 sub esi, ebx
// 0050c537  7545                 jne 0x50c57e
// 0050c539  83e801               sub eax, 1
// 0050c53c  83c101               add ecx, 1
// 0050c53f  83c201               add edx, 1
// 0050c542  85c0                 test eax, eax
// 0050c544  7446                 je 0x50c58c
// 0050c546  0fb632               movzx esi, byte ptr [edx]
// 0050c549  0fb619               movzx ebx, byte ptr [ecx]
// 0050c54c  2bf3                 sub esi, ebx
// 0050c54e  752e                 jne 0x50c57e
// 0050c550  83e801               sub eax, 1
// 0050c553  83c101               add ecx, 1
// 0050c556  83c201               add edx, 1
// 0050c559  85c0                 test eax, eax
// 0050c55b  742f                 je 0x50c58c
// 0050c55d  0fb632               movzx esi, byte ptr [edx]
// 0050c560  0fb619               movzx ebx, byte ptr [ecx]
// 0050c563  2bf3                 sub esi, ebx
// 0050c565  7517                 jne 0x50c57e
// 0050c567  83e801               sub eax, 1
// 0050c56a  83c101               add ecx, 1
// 0050c56d  83c201               add edx, 1
// 0050c570  85c0                 test eax, eax
// 0050c572  7418                 je 0x50c58c
// 0050c574  0fb632               movzx esi, byte ptr [edx]
// 0050c577  0fb601               movzx eax, byte ptr [ecx]
// 0050c57a  2bf0                 sub esi, eax
// 0050c57c  740e                 je 0x50c58c
// 0050c57e  85f6                 test esi, esi
// 0050c580  b801000000           mov eax, 1
// 0050c585  7f07                 jg 0x50c58e
// 0050c587  83c8ff               or eax, 0xffffffff
// 0050c58a  eb02                 jmp 0x50c58e
// 0050c58c  33c0                 xor eax, eax
// 0050c58e  85c0                 test eax, eax
// 0050c590  7518                 jne 0x50c5aa
// 0050c592  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050c596  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c59a  55                   push ebp
// 0050c59b  51                   push ecx
// 0050c59c  53                   push ebx
// 0050c59d  e83e140100           call 0x51d9e0
// 0050c5a2  83c40c               add esp, 0xc
// 0050c5a5  e94af3ffff           jmp 0x50b8f4
// 0050c5aa  b804000000           mov eax, 4
// 0050c5af  b92c0f7a00           mov ecx, 0x7a0f2c
// 0050c5b4  8bd7                 mov edx, edi
// 0050c5b6  8b32                 mov esi, dword ptr [edx]
// 0050c5b8  3b31                 cmp esi, dword ptr [ecx]
// 0050c5ba  7516                 jne 0x50c5d2
// 0050c5bc  83e804               sub eax, 4
// 0050c5bf  83c104               add ecx, 4
// 0050c5c2  83c204               add edx, 4
// 0050c5c5  83f804               cmp eax, 4
// 0050c5c8  73ec                 jae 0x50c5b6
// 0050c5ca  85c0                 test eax, eax
// 0050c5cc  0f845d000000         je 0x50c62f
// 0050c5d2  0fb619               movzx ebx, byte ptr [ecx]
// 0050c5d5  0fb632               movzx esi, byte ptr [edx]
// 0050c5d8  2bf3                 sub esi, ebx
// 0050c5da  7545                 jne 0x50c621
// 0050c5dc  83e801               sub eax, 1
// 0050c5df  83c101               add ecx, 1
// 0050c5e2  83c201               add edx, 1
// 0050c5e5  85c0                 test eax, eax
// 0050c5e7  7446                 je 0x50c62f
// 0050c5e9  0fb619               movzx ebx, byte ptr [ecx]
// 0050c5ec  0fb632               movzx esi, byte ptr [edx]
// 0050c5ef  2bf3                 sub esi, ebx
// 0050c5f1  752e                 jne 0x50c621
// 0050c5f3  83e801               sub eax, 1
// 0050c5f6  83c101               add ecx, 1
// 0050c5f9  83c201               add edx, 1
// 0050c5fc  85c0                 test eax, eax
// 0050c5fe  742f                 je 0x50c62f
// 0050c600  0fb619               movzx ebx, byte ptr [ecx]
// 0050c603  0fb632               movzx esi, byte ptr [edx]
// 0050c606  2bf3                 sub esi, ebx
// 0050c608  7517                 jne 0x50c621
// 0050c60a  83e801               sub eax, 1
// 0050c60d  83c101               add ecx, 1
// 0050c610  83c201               add edx, 1
// 0050c613  85c0                 test eax, eax
// 0050c615  7418                 je 0x50c62f
// 0050c617  0fb601               movzx eax, byte ptr [ecx]
// 0050c61a  0fb632               movzx esi, byte ptr [edx]
// 0050c61d  2bf0                 sub esi, eax
// 0050c61f  740e                 je 0x50c62f
// 0050c621  85f6                 test esi, esi
// 0050c623  b801000000           mov eax, 1
// 0050c628  7f07                 jg 0x50c631
// 0050c62a  83c8ff               or eax, 0xffffffff
// 0050c62d  eb02                 jmp 0x50c631
// 0050c62f  33c0                 xor eax, eax
// 0050c631  85c0                 test eax, eax
// 0050c633  7518                 jne 0x50c64d
// 0050c635  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050c639  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c63d  55                   push ebp
// 0050c63e  51                   push ecx
// 0050c63f  53                   push ebx
// 0050c640  e87b120100           call 0x51d8c0
// 0050c645  83c40c               add esp, 0xc
// 0050c648  e9a7f2ffff           jmp 0x50b8f4
// 0050c64d  b804000000           mov eax, 4
// 0050c652  b9340f7a00           mov ecx, 0x7a0f34
// 0050c657  8bd7                 mov edx, edi
// 0050c659  8da42400000000       lea esp, [esp]
// 0050c660  8b32                 mov esi, dword ptr [edx]
// 0050c662  3b31                 cmp esi, dword ptr [ecx]
// 0050c664  7516                 jne 0x50c67c
// 0050c666  83e804               sub eax, 4
// 0050c669  83c104               add ecx, 4
// 0050c66c  83c204               add edx, 4
// 0050c66f  83f804               cmp eax, 4
// 0050c672  73ec                 jae 0x50c660
// 0050c674  85c0                 test eax, eax
// 0050c676  0f845d000000         je 0x50c6d9
// 0050c67c  0fb632               movzx esi, byte ptr [edx]
// 0050c67f  0fb619               movzx ebx, byte ptr [ecx]
// 0050c682  2bf3                 sub esi, ebx
// 0050c684  7545                 jne 0x50c6cb
// 0050c686  83e801               sub eax, 1
// 0050c689  83c101               add ecx, 1
// 0050c68c  83c201               add edx, 1
// 0050c68f  85c0                 test eax, eax
// 0050c691  7446                 je 0x50c6d9
// 0050c693  0fb632               movzx esi, byte ptr [edx]
// 0050c696  0fb619               movzx ebx, byte ptr [ecx]
// 0050c699  2bf3                 sub esi, ebx
// 0050c69b  752e                 jne 0x50c6cb
// 0050c69d  83e801               sub eax, 1
// 0050c6a0  83c101               add ecx, 1
// 0050c6a3  83c201               add edx, 1
// 0050c6a6  85c0                 test eax, eax
// 0050c6a8  742f                 je 0x50c6d9
// 0050c6aa  0fb632               movzx esi, byte ptr [edx]
// 0050c6ad  0fb619               movzx ebx, byte ptr [ecx]
// 0050c6b0  2bf3                 sub esi, ebx
// 0050c6b2  7517                 jne 0x50c6cb
// 0050c6b4  83e801               sub eax, 1
// 0050c6b7  83c101               add ecx, 1
// 0050c6ba  83c201               add edx, 1
// 0050c6bd  85c0                 test eax, eax
// 0050c6bf  7418                 je 0x50c6d9
// 0050c6c1  0fb632               movzx esi, byte ptr [edx]
// 0050c6c4  0fb611               movzx edx, byte ptr [ecx]
// 0050c6c7  2bf2                 sub esi, edx
// 0050c6c9  740e                 je 0x50c6d9
// 0050c6cb  85f6                 test esi, esi
// 0050c6cd  b801000000           mov eax, 1
// 0050c6d2  7f07                 jg 0x50c6db
// 0050c6d4  83c8ff               or eax, 0xffffffff
// 0050c6d7  eb02                 jmp 0x50c6db
// 0050c6d9  33c0                 xor eax, eax
// 0050c6db  85c0                 test eax, eax
// 0050c6dd  7518                 jne 0x50c6f7
// 0050c6df  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0050c6e3  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c6e7  55                   push ebp
// 0050c6e8  50                   push eax
// 0050c6e9  53                   push ebx
// 0050c6ea  e831050100           call 0x51cc20
// 0050c6ef  83c40c               add esp, 0xc
// 0050c6f2  e9fdf1ffff           jmp 0x50b8f4
// 0050c6f7  b804000000           mov eax, 4
// 0050c6fc  b93c0f7a00           mov ecx, 0x7a0f3c
// 0050c701  8bd7                 mov edx, edi
// 0050c703  8b32                 mov esi, dword ptr [edx]
// 0050c705  3b31                 cmp esi, dword ptr [ecx]
// 0050c707  7516                 jne 0x50c71f
// 0050c709  83e804               sub eax, 4
// 0050c70c  83c104               add ecx, 4
// 0050c70f  83c204               add edx, 4
// 0050c712  83f804               cmp eax, 4
// 0050c715  73ec                 jae 0x50c703
// 0050c717  85c0                 test eax, eax
// 0050c719  0f845d000000         je 0x50c77c
// 0050c71f  0fb619               movzx ebx, byte ptr [ecx]
// 0050c722  0fb632               movzx esi, byte ptr [edx]
// 0050c725  2bf3                 sub esi, ebx
// 0050c727  7545                 jne 0x50c76e
// 0050c729  83e801               sub eax, 1
// 0050c72c  83c101               add ecx, 1
// 0050c72f  83c201               add edx, 1
// 0050c732  85c0                 test eax, eax
// 0050c734  7446                 je 0x50c77c
// 0050c736  0fb619               movzx ebx, byte ptr [ecx]
// 0050c739  0fb632               movzx esi, byte ptr [edx]
// 0050c73c  2bf3                 sub esi, ebx
// 0050c73e  752e                 jne 0x50c76e
// 0050c740  83e801               sub eax, 1
// 0050c743  83c101               add ecx, 1
// 0050c746  83c201               add edx, 1
// 0050c749  85c0                 test eax, eax
// 0050c74b  742f                 je 0x50c77c
// 0050c74d  0fb619               movzx ebx, byte ptr [ecx]
// 0050c750  0fb632               movzx esi, byte ptr [edx]
// 0050c753  2bf3                 sub esi, ebx
// 0050c755  7517                 jne 0x50c76e
// 0050c757  83e801               sub eax, 1
// 0050c75a  83c101               add ecx, 1
// 0050c75d  83c201               add edx, 1
// 0050c760  85c0                 test eax, eax
// 0050c762  7418                 je 0x50c77c
// 0050c764  0fb609               movzx ecx, byte ptr [ecx]
// 0050c767  0fb632               movzx esi, byte ptr [edx]
// 0050c76a  2bf1                 sub esi, ecx
// 0050c76c  740e                 je 0x50c77c
// 0050c76e  85f6                 test esi, esi
// 0050c770  b801000000           mov eax, 1
// 0050c775  7f07                 jg 0x50c77e
// 0050c777  83c8ff               or eax, 0xffffffff
// 0050c77a  eb02                 jmp 0x50c77e
// 0050c77c  33c0                 xor eax, eax
// 0050c77e  85c0                 test eax, eax
// 0050c780  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0050c784  55                   push ebp
// 0050c785  7513                 jne 0x50c79a
// 0050c787  8b542420             mov edx, dword ptr [esp + 0x20]
// 0050c78b  52                   push edx
// 0050c78c  53                   push ebx
// 0050c78d  e86e130100           call 0x51db00
// 0050c792  83c40c               add esp, 0xc
// 0050c795  e95af1ffff           jmp 0x50b8f4
// 0050c79a  8b442420             mov eax, dword ptr [esp + 0x20]
// 0050c79e  50                   push eax
// 0050c79f  53                   push ebx
// 0050c7a0  e8bb140100           call 0x51dc60
// 0050c7a5  83c40c               add esp, 0xc
// 0050c7a8  e947f1ffff           jmp 0x50b8f4
// 0050c7ad  80bb2601000003       cmp byte ptr [ebx + 0x126], 3
// 0050c7b4  0f854f000000         jne 0x50c809
// 0050c7ba  a802                 test al, 2
// 0050c7bc  754b                 jne 0x50c809
// 0050c7be  6830257a00           push 0x7a2530
// 0050c7c3  53                   push ebx
// 0050c7c4  e857bb0000           call 0x518320
// 0050c7c9  83c408               add esp, 8
// 0050c7cc  5f                   pop edi
// 0050c7cd  5e                   pop esi
// 0050c7ce  5d                   pop ebp
// 0050c7cf  5b                   pop ebx
// 0050c7d0  59                   pop ecx
// 0050c7d1  c3                   ret 
// 0050c7d2  8b742418             mov esi, dword ptr [esp + 0x18]
// 0050c7d6  8b4668               mov eax, dword ptr [esi + 0x68]
// 0050c7d9  a801                 test al, 1
// 0050c7db  7507                 jne 0x50c7e4
// 0050c7dd  684c257a00           push 0x7a254c
// 0050c7e2  eb12                 jmp 0x50c7f6
// 0050c7e4  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 0050c7eb  7512                 jne 0x50c7ff
// 0050c7ed  a802                 test al, 2
// 0050c7ef  750e                 jne 0x50c7ff
// 0050c7f1  6830257a00           push 0x7a2530
// 0050c7f6  56                   push esi
// 0050c7f7  e824bb0000           call 0x518320
// 0050c7fc  83c408               add esp, 8
// 0050c7ff  834e6804             or dword ptr [esi + 0x68], 4
// 0050c803  89ae0c010000         mov dword ptr [esi + 0x10c], ebp
// 0050c809  5f                   pop edi
// 0050c80a  5e                   pop esi
// 0050c80b  5d                   pop ebp
// 0050c80c  5b                   pop ebx
// 0050c80d  59                   pop ecx
// 0050c80e  c3                   ret 
// library libpng-1.2.7/pngread.c (function _png_read_info)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngread.c
