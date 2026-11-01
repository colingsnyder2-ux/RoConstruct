// from server: 100% by auto
// roc 2007-03 0050ce60  unit: seg_00500000  size: 3684 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050ce60
//
// 0050ce60  51                   push ecx
// 0050ce61  53                   push ebx
// 0050ce62  55                   push ebp
// 0050ce63  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0050ce67  56                   push esi
// 0050ce68  57                   push edi
// 0050ce69  6a00                 push 0
// 0050ce6b  55                   push ebp
// 0050ce6c  e8ffeb0000           call 0x51ba70
// 0050ce71  83c408               add esp, 8
// 0050ce74  8dbd1c010000         lea edi, [ebp + 0x11c]
// 0050ce7a  8d9b00000000         lea ebx, [ebx]
// 0050ce80  6a04                 push 4
// 0050ce82  8d442414             lea eax, [esp + 0x14]
// 0050ce86  50                   push eax
// 0050ce87  55                   push ebp
// 0050ce88  e813610000           call 0x512fa0
// 0050ce8d  8d4c241c             lea ecx, [esp + 0x1c]
// 0050ce91  51                   push ecx
// 0050ce92  55                   push ebp
// 0050ce93  e8a8eb0000           call 0x51ba40
// 0050ce98  55                   push ebp
// 0050ce99  89442430             mov dword ptr [esp + 0x30], eax
// 0050ce9d  e82ed8ffff           call 0x50a6d0
// 0050cea2  6a04                 push 4
// 0050cea4  57                   push edi
// 0050cea5  55                   push ebp
// 0050cea6  e815db0000           call 0x51a9c0
// 0050ceab  83c424               add esp, 0x24
// 0050ceae  b804000000           mov eax, 4
// 0050ceb3  b99c0e7a00           mov ecx, 0x7a0e9c
// 0050ceb8  8bd7                 mov edx, edi
// 0050ceba  8d9b00000000         lea ebx, [ebx]
// 0050cec0  8b32                 mov esi, dword ptr [edx]
// 0050cec2  3b31                 cmp esi, dword ptr [ecx]
// 0050cec4  7512                 jne 0x50ced8
// 0050cec6  83e804               sub eax, 4
// 0050cec9  83c104               add ecx, 4
// 0050cecc  83c204               add edx, 4
// 0050cecf  83f804               cmp eax, 4
// 0050ced2  73ec                 jae 0x50cec0
// 0050ced4  85c0                 test eax, eax
// 0050ced6  745d                 je 0x50cf35
// 0050ced8  0fb619               movzx ebx, byte ptr [ecx]
// 0050cedb  0fb632               movzx esi, byte ptr [edx]
// 0050cede  2bf3                 sub esi, ebx
// 0050cee0  7545                 jne 0x50cf27
// 0050cee2  83e801               sub eax, 1
// 0050cee5  83c101               add ecx, 1
// 0050cee8  83c201               add edx, 1
// 0050ceeb  85c0                 test eax, eax
// 0050ceed  7446                 je 0x50cf35
// 0050ceef  0fb619               movzx ebx, byte ptr [ecx]
// 0050cef2  0fb632               movzx esi, byte ptr [edx]
// 0050cef5  2bf3                 sub esi, ebx
// 0050cef7  752e                 jne 0x50cf27
// 0050cef9  83e801               sub eax, 1
// 0050cefc  83c101               add ecx, 1
// 0050ceff  83c201               add edx, 1
// 0050cf02  85c0                 test eax, eax
// 0050cf04  742f                 je 0x50cf35
// 0050cf06  0fb619               movzx ebx, byte ptr [ecx]
// 0050cf09  0fb632               movzx esi, byte ptr [edx]
// 0050cf0c  2bf3                 sub esi, ebx
// 0050cf0e  7517                 jne 0x50cf27
// 0050cf10  83e801               sub eax, 1
// 0050cf13  83c101               add ecx, 1
// 0050cf16  83c201               add edx, 1
// 0050cf19  85c0                 test eax, eax
// 0050cf1b  7418                 je 0x50cf35
// 0050cf1d  0fb601               movzx eax, byte ptr [ecx]
// 0050cf20  0fb632               movzx esi, byte ptr [edx]
// 0050cf23  2bf0                 sub esi, eax
// 0050cf25  740e                 je 0x50cf35
// 0050cf27  85f6                 test esi, esi
// 0050cf29  b801000000           mov eax, 1
// 0050cf2e  7f07                 jg 0x50cf37
// 0050cf30  83c8ff               or eax, 0xffffffff
// 0050cf33  eb02                 jmp 0x50cf37
// 0050cf35  33c0                 xor eax, eax
// 0050cf37  85c0                 test eax, eax
// 0050cf39  7515                 jne 0x50cf50
// 0050cf3b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050cf3f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050cf43  51                   push ecx
// 0050cf44  52                   push edx
// 0050cf45  55                   push ebp
// 0050cf46  e8e5eb0000           call 0x51bb30
// 0050cf4b  e9610d0000           jmp 0x50dcb1
// 0050cf50  b804000000           mov eax, 4
// 0050cf55  b9ac0e7a00           mov ecx, 0x7a0eac
// 0050cf5a  8bd7                 mov edx, edi
// 0050cf5c  8d642400             lea esp, [esp]
// 0050cf60  8b32                 mov esi, dword ptr [edx]
// 0050cf62  3b31                 cmp esi, dword ptr [ecx]
// 0050cf64  7512                 jne 0x50cf78
// 0050cf66  83e804               sub eax, 4
// 0050cf69  83c104               add ecx, 4
// 0050cf6c  83c204               add edx, 4
// 0050cf6f  83f804               cmp eax, 4
// 0050cf72  73ec                 jae 0x50cf60
// 0050cf74  85c0                 test eax, eax
// 0050cf76  745d                 je 0x50cfd5
// 0050cf78  0fb632               movzx esi, byte ptr [edx]
// 0050cf7b  0fb619               movzx ebx, byte ptr [ecx]
// 0050cf7e  2bf3                 sub esi, ebx
// 0050cf80  7545                 jne 0x50cfc7
// 0050cf82  83e801               sub eax, 1
// 0050cf85  83c101               add ecx, 1
// 0050cf88  83c201               add edx, 1
// 0050cf8b  85c0                 test eax, eax
// 0050cf8d  7446                 je 0x50cfd5
// 0050cf8f  0fb632               movzx esi, byte ptr [edx]
// 0050cf92  0fb619               movzx ebx, byte ptr [ecx]
// 0050cf95  2bf3                 sub esi, ebx
// 0050cf97  752e                 jne 0x50cfc7
// 0050cf99  83e801               sub eax, 1
// 0050cf9c  83c101               add ecx, 1
// 0050cf9f  83c201               add edx, 1
// 0050cfa2  85c0                 test eax, eax
// 0050cfa4  742f                 je 0x50cfd5
// 0050cfa6  0fb632               movzx esi, byte ptr [edx]
// 0050cfa9  0fb619               movzx ebx, byte ptr [ecx]
// 0050cfac  2bf3                 sub esi, ebx
// 0050cfae  7517                 jne 0x50cfc7
// 0050cfb0  83e801               sub eax, 1
// 0050cfb3  83c101               add ecx, 1
// 0050cfb6  83c201               add edx, 1
// 0050cfb9  85c0                 test eax, eax
// 0050cfbb  7418                 je 0x50cfd5
// 0050cfbd  0fb632               movzx esi, byte ptr [edx]
// 0050cfc0  0fb601               movzx eax, byte ptr [ecx]
// 0050cfc3  2bf0                 sub esi, eax
// 0050cfc5  740e                 je 0x50cfd5
// 0050cfc7  85f6                 test esi, esi
// 0050cfc9  b801000000           mov eax, 1
// 0050cfce  7f07                 jg 0x50cfd7
// 0050cfd0  83c8ff               or eax, 0xffffffff
// 0050cfd3  eb02                 jmp 0x50cfd7
// 0050cfd5  33c0                 xor eax, eax
// 0050cfd7  85c0                 test eax, eax
// 0050cfd9  7515                 jne 0x50cff0
// 0050cfdb  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050cfdf  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050cfe3  51                   push ecx
// 0050cfe4  52                   push edx
// 0050cfe5  55                   push ebp
// 0050cfe6  e855ee0000           call 0x51be40
// 0050cfeb  e9c10c0000           jmp 0x50dcb1
// 0050cff0  57                   push edi
// 0050cff1  55                   push ebp
// 0050cff2  e899dbffff           call 0x50ab90
// 0050cff7  83c408               add esp, 8
// 0050cffa  85c0                 test eax, eax
// 0050cffc  b9a40e7a00           mov ecx, 0x7a0ea4
// 0050d001  8bd7                 mov edx, edi
// 0050d003  b804000000           mov eax, 4
// 0050d008  0f844a010000         je 0x50d158
// 0050d00e  8bff                 mov edi, edi
// 0050d010  8b32                 mov esi, dword ptr [edx]
// 0050d012  3b31                 cmp esi, dword ptr [ecx]
// 0050d014  7512                 jne 0x50d028
// 0050d016  83e804               sub eax, 4
// 0050d019  83c104               add ecx, 4
// 0050d01c  83c204               add edx, 4
// 0050d01f  83f804               cmp eax, 4
// 0050d022  73ec                 jae 0x50d010
// 0050d024  85c0                 test eax, eax
// 0050d026  745d                 je 0x50d085
// 0050d028  0fb619               movzx ebx, byte ptr [ecx]
// 0050d02b  0fb632               movzx esi, byte ptr [edx]
// 0050d02e  2bf3                 sub esi, ebx
// 0050d030  7545                 jne 0x50d077
// 0050d032  83e801               sub eax, 1
// 0050d035  83c101               add ecx, 1
// 0050d038  83c201               add edx, 1
// 0050d03b  85c0                 test eax, eax
// 0050d03d  7446                 je 0x50d085
// 0050d03f  0fb619               movzx ebx, byte ptr [ecx]
// 0050d042  0fb632               movzx esi, byte ptr [edx]
// 0050d045  2bf3                 sub esi, ebx
// 0050d047  752e                 jne 0x50d077
// 0050d049  83e801               sub eax, 1
// 0050d04c  83c101               add ecx, 1
// 0050d04f  83c201               add edx, 1
// 0050d052  85c0                 test eax, eax
// 0050d054  742f                 je 0x50d085
// 0050d056  0fb619               movzx ebx, byte ptr [ecx]
// 0050d059  0fb632               movzx esi, byte ptr [edx]
// 0050d05c  2bf3                 sub esi, ebx
// 0050d05e  7517                 jne 0x50d077
// 0050d060  83e801               sub eax, 1
// 0050d063  83c101               add ecx, 1
// 0050d066  83c201               add edx, 1
// 0050d069  85c0                 test eax, eax
// 0050d06b  7418                 je 0x50d085
// 0050d06d  0fb601               movzx eax, byte ptr [ecx]
// 0050d070  0fb632               movzx esi, byte ptr [edx]
// 0050d073  2bf0                 sub esi, eax
// 0050d075  740e                 je 0x50d085
// 0050d077  85f6                 test esi, esi
// 0050d079  b801000000           mov eax, 1
// 0050d07e  7f07                 jg 0x50d087
// 0050d080  83c8ff               or eax, 0xffffffff
// 0050d083  eb02                 jmp 0x50d087
// 0050d085  33c0                 xor eax, eax
// 0050d087  85c0                 test eax, eax
// 0050d089  751c                 jne 0x50d0a7
// 0050d08b  39442418             cmp dword ptr [esp + 0x18], eax
// 0050d08f  7706                 ja 0x50d097
// 0050d091  f6456808             test byte ptr [ebp + 0x68], 8
// 0050d095  7414                 je 0x50d0ab
// 0050d097  6850267a00           push 0x7a2650
// 0050d09c  55                   push ebp
// 0050d09d  e87eb20000           call 0x518320
// 0050d0a2  83c408               add esp, 8
// 0050d0a5  eb04                 jmp 0x50d0ab
// 0050d0a7  834d6808             or dword ptr [ebp + 0x68], 8
// 0050d0ab  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d0af  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d0b3  51                   push ecx
// 0050d0b4  52                   push edx
// 0050d0b5  55                   push ebp
// 0050d0b6  e8a50b0100           call 0x51dc60
// 0050d0bb  83c40c               add esp, 0xc
// 0050d0be  b804000000           mov eax, 4
// 0050d0c3  b9b40e7a00           mov ecx, 0x7a0eb4
// 0050d0c8  8bd7                 mov edx, edi
// 0050d0ca  8d9b00000000         lea ebx, [ebx]
// 0050d0d0  8b32                 mov esi, dword ptr [edx]
// 0050d0d2  3b31                 cmp esi, dword ptr [ecx]
// 0050d0d4  7512                 jne 0x50d0e8
// 0050d0d6  83e804               sub eax, 4
// 0050d0d9  83c104               add ecx, 4
// 0050d0dc  83c204               add edx, 4
// 0050d0df  83f804               cmp eax, 4
// 0050d0e2  73ec                 jae 0x50d0d0
// 0050d0e4  85c0                 test eax, eax
// 0050d0e6  745d                 je 0x50d145
// 0050d0e8  0fb632               movzx esi, byte ptr [edx]
// 0050d0eb  0fb619               movzx ebx, byte ptr [ecx]
// 0050d0ee  2bf3                 sub esi, ebx
// 0050d0f0  7545                 jne 0x50d137
// 0050d0f2  83e801               sub eax, 1
// 0050d0f5  83c101               add ecx, 1
// 0050d0f8  83c201               add edx, 1
// 0050d0fb  85c0                 test eax, eax
// 0050d0fd  7446                 je 0x50d145
// 0050d0ff  0fb632               movzx esi, byte ptr [edx]
// 0050d102  0fb619               movzx ebx, byte ptr [ecx]
// 0050d105  2bf3                 sub esi, ebx
// 0050d107  752e                 jne 0x50d137
// 0050d109  83e801               sub eax, 1
// 0050d10c  83c101               add ecx, 1
// 0050d10f  83c201               add edx, 1
// 0050d112  85c0                 test eax, eax
// 0050d114  742f                 je 0x50d145
// 0050d116  0fb632               movzx esi, byte ptr [edx]
// 0050d119  0fb619               movzx ebx, byte ptr [ecx]
// 0050d11c  2bf3                 sub esi, ebx
// 0050d11e  7517                 jne 0x50d137
// 0050d120  83e801               sub eax, 1
// 0050d123  83c101               add ecx, 1
// 0050d126  83c201               add edx, 1
// 0050d129  85c0                 test eax, eax
// 0050d12b  7418                 je 0x50d145
// 0050d12d  0fb632               movzx esi, byte ptr [edx]
// 0050d130  0fb601               movzx eax, byte ptr [ecx]
// 0050d133  2bf0                 sub esi, eax
// 0050d135  740e                 je 0x50d145
// 0050d137  85f6                 test esi, esi
// 0050d139  b801000000           mov eax, 1
// 0050d13e  7f07                 jg 0x50d147
// 0050d140  83c8ff               or eax, 0xffffffff
// 0050d143  eb02                 jmp 0x50d147
// 0050d145  33c0                 xor eax, eax
// 0050d147  85c0                 test eax, eax
// 0050d149  0f85650b0000         jne 0x50dcb4
// 0050d14f  834d6802             or dword ptr [ebp + 0x68], 2
// 0050d153  e95c0b0000           jmp 0x50dcb4
// 0050d158  8b32                 mov esi, dword ptr [edx]
// 0050d15a  3b31                 cmp esi, dword ptr [ecx]
// 0050d15c  7512                 jne 0x50d170
// 0050d15e  83e804               sub eax, 4
// 0050d161  83c104               add ecx, 4
// 0050d164  83c204               add edx, 4
// 0050d167  83f804               cmp eax, 4
// 0050d16a  73ec                 jae 0x50d158
// 0050d16c  85c0                 test eax, eax
// 0050d16e  745d                 je 0x50d1cd
// 0050d170  0fb619               movzx ebx, byte ptr [ecx]
// 0050d173  0fb632               movzx esi, byte ptr [edx]
// 0050d176  2bf3                 sub esi, ebx
// 0050d178  7545                 jne 0x50d1bf
// 0050d17a  83e801               sub eax, 1
// 0050d17d  83c101               add ecx, 1
// 0050d180  83c201               add edx, 1
// 0050d183  85c0                 test eax, eax
// 0050d185  7446                 je 0x50d1cd
// 0050d187  0fb619               movzx ebx, byte ptr [ecx]
// 0050d18a  0fb632               movzx esi, byte ptr [edx]
// 0050d18d  2bf3                 sub esi, ebx
// 0050d18f  752e                 jne 0x50d1bf
// 0050d191  83e801               sub eax, 1
// 0050d194  83c101               add ecx, 1
// 0050d197  83c201               add edx, 1
// 0050d19a  85c0                 test eax, eax
// 0050d19c  742f                 je 0x50d1cd
// 0050d19e  0fb619               movzx ebx, byte ptr [ecx]
// 0050d1a1  0fb632               movzx esi, byte ptr [edx]
// 0050d1a4  2bf3                 sub esi, ebx
// 0050d1a6  7517                 jne 0x50d1bf
// 0050d1a8  83e801               sub eax, 1
// 0050d1ab  83c101               add ecx, 1
// 0050d1ae  83c201               add edx, 1
// 0050d1b1  85c0                 test eax, eax
// 0050d1b3  7418                 je 0x50d1cd
// 0050d1b5  0fb609               movzx ecx, byte ptr [ecx]
// 0050d1b8  0fb632               movzx esi, byte ptr [edx]
// 0050d1bb  2bf1                 sub esi, ecx
// 0050d1bd  740e                 je 0x50d1cd
// 0050d1bf  85f6                 test esi, esi
// 0050d1c1  b801000000           mov eax, 1
// 0050d1c6  7f07                 jg 0x50d1cf
// 0050d1c8  83c8ff               or eax, 0xffffffff
// 0050d1cb  eb02                 jmp 0x50d1cf
// 0050d1cd  33c0                 xor eax, eax
// 0050d1cf  85c0                 test eax, eax
// 0050d1d1  752b                 jne 0x50d1fe
// 0050d1d3  8b742418             mov esi, dword ptr [esp + 0x18]
// 0050d1d7  85f6                 test esi, esi
// 0050d1d9  7706                 ja 0x50d1e1
// 0050d1db  f6456808             test byte ptr [ebp + 0x68], 8
// 0050d1df  740e                 je 0x50d1ef
// 0050d1e1  6850267a00           push 0x7a2650
// 0050d1e6  55                   push ebp
// 0050d1e7  e834b10000           call 0x518320
// 0050d1ec  83c408               add esp, 8
// 0050d1ef  56                   push esi
// 0050d1f0  55                   push ebp
// 0050d1f1  e87ae80000           call 0x51ba70
// 0050d1f6  83c408               add esp, 8
// 0050d1f9  e9b60a0000           jmp 0x50dcb4
// 0050d1fe  b804000000           mov eax, 4
// 0050d203  b9b40e7a00           mov ecx, 0x7a0eb4
// 0050d208  8bd7                 mov edx, edi
// 0050d20a  8d9b00000000         lea ebx, [ebx]
// 0050d210  8b32                 mov esi, dword ptr [edx]
// 0050d212  3b31                 cmp esi, dword ptr [ecx]
// 0050d214  7512                 jne 0x50d228
// 0050d216  83e804               sub eax, 4
// 0050d219  83c104               add ecx, 4
// 0050d21c  83c204               add edx, 4
// 0050d21f  83f804               cmp eax, 4
// 0050d222  73ec                 jae 0x50d210
// 0050d224  85c0                 test eax, eax
// 0050d226  745d                 je 0x50d285
// 0050d228  0fb632               movzx esi, byte ptr [edx]
// 0050d22b  0fb619               movzx ebx, byte ptr [ecx]
// 0050d22e  2bf3                 sub esi, ebx
// 0050d230  7545                 jne 0x50d277
// 0050d232  83e801               sub eax, 1
// 0050d235  83c101               add ecx, 1
// 0050d238  83c201               add edx, 1
// 0050d23b  85c0                 test eax, eax
// 0050d23d  7446                 je 0x50d285
// 0050d23f  0fb632               movzx esi, byte ptr [edx]
// 0050d242  0fb619               movzx ebx, byte ptr [ecx]
// 0050d245  2bf3                 sub esi, ebx
// 0050d247  752e                 jne 0x50d277
// 0050d249  83e801               sub eax, 1
// 0050d24c  83c101               add ecx, 1
// 0050d24f  83c201               add edx, 1
// 0050d252  85c0                 test eax, eax
// 0050d254  742f                 je 0x50d285
// 0050d256  0fb632               movzx esi, byte ptr [edx]
// 0050d259  0fb619               movzx ebx, byte ptr [ecx]
// 0050d25c  2bf3                 sub esi, ebx
// 0050d25e  7517                 jne 0x50d277
// 0050d260  83e801               sub eax, 1
// 0050d263  83c101               add ecx, 1
// 0050d266  83c201               add edx, 1
// 0050d269  85c0                 test eax, eax
// 0050d26b  7418                 je 0x50d285
// 0050d26d  0fb632               movzx esi, byte ptr [edx]
// 0050d270  0fb611               movzx edx, byte ptr [ecx]
// 0050d273  2bf2                 sub esi, edx
// 0050d275  740e                 je 0x50d285
// 0050d277  85f6                 test esi, esi
// 0050d279  b801000000           mov eax, 1
// 0050d27e  7f07                 jg 0x50d287
// 0050d280  83c8ff               or eax, 0xffffffff
// 0050d283  eb02                 jmp 0x50d287
// 0050d285  33c0                 xor eax, eax
// 0050d287  85c0                 test eax, eax
// 0050d289  7515                 jne 0x50d2a0
// 0050d28b  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050d28f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050d293  50                   push eax
// 0050d294  51                   push ecx
// 0050d295  55                   push ebp
// 0050d296  e815ea0000           call 0x51bcb0
// 0050d29b  e9110a0000           jmp 0x50dcb1
// 0050d2a0  b804000000           mov eax, 4
// 0050d2a5  b9bc0e7a00           mov ecx, 0x7a0ebc
// 0050d2aa  8bd7                 mov edx, edi
// 0050d2ac  8d642400             lea esp, [esp]
// 0050d2b0  8b32                 mov esi, dword ptr [edx]
// 0050d2b2  3b31                 cmp esi, dword ptr [ecx]
// 0050d2b4  7512                 jne 0x50d2c8
// 0050d2b6  83e804               sub eax, 4
// 0050d2b9  83c104               add ecx, 4
// 0050d2bc  83c204               add edx, 4
// 0050d2bf  83f804               cmp eax, 4
// 0050d2c2  73ec                 jae 0x50d2b0
// 0050d2c4  85c0                 test eax, eax
// 0050d2c6  745d                 je 0x50d325
// 0050d2c8  0fb619               movzx ebx, byte ptr [ecx]
// 0050d2cb  0fb632               movzx esi, byte ptr [edx]
// 0050d2ce  2bf3                 sub esi, ebx
// 0050d2d0  7545                 jne 0x50d317
// 0050d2d2  83e801               sub eax, 1
// 0050d2d5  83c101               add ecx, 1
// 0050d2d8  83c201               add edx, 1
// 0050d2db  85c0                 test eax, eax
// 0050d2dd  7446                 je 0x50d325
// 0050d2df  0fb619               movzx ebx, byte ptr [ecx]
// 0050d2e2  0fb632               movzx esi, byte ptr [edx]
// 0050d2e5  2bf3                 sub esi, ebx
// 0050d2e7  752e                 jne 0x50d317
// 0050d2e9  83e801               sub eax, 1
// 0050d2ec  83c101               add ecx, 1
// 0050d2ef  83c201               add edx, 1
// 0050d2f2  85c0                 test eax, eax
// 0050d2f4  742f                 je 0x50d325
// 0050d2f6  0fb619               movzx ebx, byte ptr [ecx]
// 0050d2f9  0fb632               movzx esi, byte ptr [edx]
// 0050d2fc  2bf3                 sub esi, ebx
// 0050d2fe  7517                 jne 0x50d317
// 0050d300  83e801               sub eax, 1
// 0050d303  83c101               add ecx, 1
// 0050d306  83c201               add edx, 1
// 0050d309  85c0                 test eax, eax
// 0050d30b  7418                 je 0x50d325
// 0050d30d  0fb601               movzx eax, byte ptr [ecx]
// 0050d310  0fb632               movzx esi, byte ptr [edx]
// 0050d313  2bf0                 sub esi, eax
// 0050d315  740e                 je 0x50d325
// 0050d317  85f6                 test esi, esi
// 0050d319  b801000000           mov eax, 1
// 0050d31e  7f07                 jg 0x50d327
// 0050d320  83c8ff               or eax, 0xffffffff
// 0050d323  eb02                 jmp 0x50d327
// 0050d325  33c0                 xor eax, eax
// 0050d327  85c0                 test eax, eax
// 0050d329  7515                 jne 0x50d340
// 0050d32b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d32f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d333  51                   push ecx
// 0050d334  52                   push edx
// 0050d335  55                   push ebp
// 0050d336  e835fb0000           call 0x51ce70
// 0050d33b  e971090000           jmp 0x50dcb1
// 0050d340  b804000000           mov eax, 4
// 0050d345  b9c40e7a00           mov ecx, 0x7a0ec4
// 0050d34a  8bd7                 mov edx, edi
// 0050d34c  8d642400             lea esp, [esp]
// 0050d350  8b32                 mov esi, dword ptr [edx]
// 0050d352  3b31                 cmp esi, dword ptr [ecx]
// 0050d354  7512                 jne 0x50d368
// 0050d356  83e804               sub eax, 4
// 0050d359  83c104               add ecx, 4
// 0050d35c  83c204               add edx, 4
// 0050d35f  83f804               cmp eax, 4
// 0050d362  73ec                 jae 0x50d350
// 0050d364  85c0                 test eax, eax
// 0050d366  745d                 je 0x50d3c5
// 0050d368  0fb632               movzx esi, byte ptr [edx]
// 0050d36b  0fb619               movzx ebx, byte ptr [ecx]
// 0050d36e  2bf3                 sub esi, ebx
// 0050d370  7545                 jne 0x50d3b7
// 0050d372  83e801               sub eax, 1
// 0050d375  83c101               add ecx, 1
// 0050d378  83c201               add edx, 1
// 0050d37b  85c0                 test eax, eax
// 0050d37d  7446                 je 0x50d3c5
// 0050d37f  0fb632               movzx esi, byte ptr [edx]
// 0050d382  0fb619               movzx ebx, byte ptr [ecx]
// 0050d385  2bf3                 sub esi, ebx
// 0050d387  752e                 jne 0x50d3b7
// 0050d389  83e801               sub eax, 1
// 0050d38c  83c101               add ecx, 1
// 0050d38f  83c201               add edx, 1
// 0050d392  85c0                 test eax, eax
// 0050d394  742f                 je 0x50d3c5
// 0050d396  0fb632               movzx esi, byte ptr [edx]
// 0050d399  0fb619               movzx ebx, byte ptr [ecx]
// 0050d39c  2bf3                 sub esi, ebx
// 0050d39e  7517                 jne 0x50d3b7
// 0050d3a0  83e801               sub eax, 1
// 0050d3a3  83c101               add ecx, 1
// 0050d3a6  83c201               add edx, 1
// 0050d3a9  85c0                 test eax, eax
// 0050d3ab  7418                 je 0x50d3c5
// 0050d3ad  0fb632               movzx esi, byte ptr [edx]
// 0050d3b0  0fb601               movzx eax, byte ptr [ecx]
// 0050d3b3  2bf0                 sub esi, eax
// 0050d3b5  740e                 je 0x50d3c5
// 0050d3b7  85f6                 test esi, esi
// 0050d3b9  b801000000           mov eax, 1
// 0050d3be  7f07                 jg 0x50d3c7
// 0050d3c0  83c8ff               or eax, 0xffffffff
// 0050d3c3  eb02                 jmp 0x50d3c7
// 0050d3c5  33c0                 xor eax, eax
// 0050d3c7  85c0                 test eax, eax
// 0050d3c9  7515                 jne 0x50d3e0
// 0050d3cb  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d3cf  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d3d3  51                   push ecx
// 0050d3d4  52                   push edx
// 0050d3d5  55                   push ebp
// 0050d3d6  e895ed0000           call 0x51c170
// 0050d3db  e9d1080000           jmp 0x50dcb1
// 0050d3e0  b804000000           mov eax, 4
// 0050d3e5  b9cc0e7a00           mov ecx, 0x7a0ecc
// 0050d3ea  8bd7                 mov edx, edi
// 0050d3ec  8d642400             lea esp, [esp]
// 0050d3f0  8b32                 mov esi, dword ptr [edx]
// 0050d3f2  3b31                 cmp esi, dword ptr [ecx]
// 0050d3f4  7512                 jne 0x50d408
// 0050d3f6  83e804               sub eax, 4
// 0050d3f9  83c104               add ecx, 4
// 0050d3fc  83c204               add edx, 4
// 0050d3ff  83f804               cmp eax, 4
// 0050d402  73ec                 jae 0x50d3f0
// 0050d404  85c0                 test eax, eax
// 0050d406  745d                 je 0x50d465
// 0050d408  0fb619               movzx ebx, byte ptr [ecx]
// 0050d40b  0fb632               movzx esi, byte ptr [edx]
// 0050d40e  2bf3                 sub esi, ebx
// 0050d410  7545                 jne 0x50d457
// 0050d412  83e801               sub eax, 1
// 0050d415  83c101               add ecx, 1
// 0050d418  83c201               add edx, 1
// 0050d41b  85c0                 test eax, eax
// 0050d41d  7446                 je 0x50d465
// 0050d41f  0fb619               movzx ebx, byte ptr [ecx]
// 0050d422  0fb632               movzx esi, byte ptr [edx]
// 0050d425  2bf3                 sub esi, ebx
// 0050d427  752e                 jne 0x50d457
// 0050d429  83e801               sub eax, 1
// 0050d42c  83c101               add ecx, 1
// 0050d42f  83c201               add edx, 1
// 0050d432  85c0                 test eax, eax
// 0050d434  742f                 je 0x50d465
// 0050d436  0fb619               movzx ebx, byte ptr [ecx]
// 0050d439  0fb632               movzx esi, byte ptr [edx]
// 0050d43c  2bf3                 sub esi, ebx
// 0050d43e  7517                 jne 0x50d457
// 0050d440  83e801               sub eax, 1
// 0050d443  83c101               add ecx, 1
// 0050d446  83c201               add edx, 1
// 0050d449  85c0                 test eax, eax
// 0050d44b  7418                 je 0x50d465
// 0050d44d  0fb601               movzx eax, byte ptr [ecx]
// 0050d450  0fb632               movzx esi, byte ptr [edx]
// 0050d453  2bf0                 sub esi, eax
// 0050d455  740e                 je 0x50d465
// 0050d457  85f6                 test esi, esi
// 0050d459  b801000000           mov eax, 1
// 0050d45e  7f07                 jg 0x50d467
// 0050d460  83c8ff               or eax, 0xffffffff
// 0050d463  eb02                 jmp 0x50d467
// 0050d465  33c0                 xor eax, eax
// 0050d467  85c0                 test eax, eax
// 0050d469  7515                 jne 0x50d480
// 0050d46b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d46f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d473  51                   push ecx
// 0050d474  52                   push edx
// 0050d475  55                   push ebp
// 0050d476  e815ea0000           call 0x51be90
// 0050d47b  e931080000           jmp 0x50dcb1
// 0050d480  b804000000           mov eax, 4
// 0050d485  b9d40e7a00           mov ecx, 0x7a0ed4
// 0050d48a  8bd7                 mov edx, edi
// 0050d48c  8d642400             lea esp, [esp]
// 0050d490  8b32                 mov esi, dword ptr [edx]
// 0050d492  3b31                 cmp esi, dword ptr [ecx]
// 0050d494  7512                 jne 0x50d4a8
// 0050d496  83e804               sub eax, 4
// 0050d499  83c104               add ecx, 4
// 0050d49c  83c204               add edx, 4
// 0050d49f  83f804               cmp eax, 4
// 0050d4a2  73ec                 jae 0x50d490
// 0050d4a4  85c0                 test eax, eax
// 0050d4a6  745d                 je 0x50d505
// 0050d4a8  0fb632               movzx esi, byte ptr [edx]
// 0050d4ab  0fb619               movzx ebx, byte ptr [ecx]
// 0050d4ae  2bf3                 sub esi, ebx
// 0050d4b0  7545                 jne 0x50d4f7
// 0050d4b2  83e801               sub eax, 1
// 0050d4b5  83c101               add ecx, 1
// 0050d4b8  83c201               add edx, 1
// 0050d4bb  85c0                 test eax, eax
// 0050d4bd  7446                 je 0x50d505
// 0050d4bf  0fb632               movzx esi, byte ptr [edx]
// 0050d4c2  0fb619               movzx ebx, byte ptr [ecx]
// 0050d4c5  2bf3                 sub esi, ebx
// 0050d4c7  752e                 jne 0x50d4f7
// 0050d4c9  83e801               sub eax, 1
// 0050d4cc  83c101               add ecx, 1
// 0050d4cf  83c201               add edx, 1
// 0050d4d2  85c0                 test eax, eax
// 0050d4d4  742f                 je 0x50d505
// 0050d4d6  0fb632               movzx esi, byte ptr [edx]
// 0050d4d9  0fb619               movzx ebx, byte ptr [ecx]
// 0050d4dc  2bf3                 sub esi, ebx
// 0050d4de  7517                 jne 0x50d4f7
// 0050d4e0  83e801               sub eax, 1
// 0050d4e3  83c101               add ecx, 1
// 0050d4e6  83c201               add edx, 1
// 0050d4e9  85c0                 test eax, eax
// 0050d4eb  7418                 je 0x50d505
// 0050d4ed  0fb632               movzx esi, byte ptr [edx]
// 0050d4f0  0fb601               movzx eax, byte ptr [ecx]
// 0050d4f3  2bf0                 sub esi, eax
// 0050d4f5  740e                 je 0x50d505
// 0050d4f7  85f6                 test esi, esi
// 0050d4f9  b801000000           mov eax, 1
// 0050d4fe  7f07                 jg 0x50d507
// 0050d500  83c8ff               or eax, 0xffffffff
// 0050d503  eb02                 jmp 0x50d507
// 0050d505  33c0                 xor eax, eax
// 0050d507  85c0                 test eax, eax
// 0050d509  7515                 jne 0x50d520
// 0050d50b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d50f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d513  51                   push ecx
// 0050d514  52                   push edx
// 0050d515  55                   push ebp
// 0050d516  e895fb0000           call 0x51d0b0
// 0050d51b  e991070000           jmp 0x50dcb1
// 0050d520  b804000000           mov eax, 4
// 0050d525  b9ec0e7a00           mov ecx, 0x7a0eec
// 0050d52a  8bd7                 mov edx, edi
// 0050d52c  8d642400             lea esp, [esp]
// 0050d530  8b32                 mov esi, dword ptr [edx]
// 0050d532  3b31                 cmp esi, dword ptr [ecx]
// 0050d534  7512                 jne 0x50d548
// 0050d536  83e804               sub eax, 4
// 0050d539  83c104               add ecx, 4
// 0050d53c  83c204               add edx, 4
// 0050d53f  83f804               cmp eax, 4
// 0050d542  73ec                 jae 0x50d530
// 0050d544  85c0                 test eax, eax
// 0050d546  745d                 je 0x50d5a5
// 0050d548  0fb619               movzx ebx, byte ptr [ecx]
// 0050d54b  0fb632               movzx esi, byte ptr [edx]
// 0050d54e  2bf3                 sub esi, ebx
// 0050d550  7545                 jne 0x50d597
// 0050d552  83e801               sub eax, 1
// 0050d555  83c101               add ecx, 1
// 0050d558  83c201               add edx, 1
// 0050d55b  85c0                 test eax, eax
// 0050d55d  7446                 je 0x50d5a5
// 0050d55f  0fb619               movzx ebx, byte ptr [ecx]
// 0050d562  0fb632               movzx esi, byte ptr [edx]
// 0050d565  2bf3                 sub esi, ebx
// 0050d567  752e                 jne 0x50d597
// 0050d569  83e801               sub eax, 1
// 0050d56c  83c101               add ecx, 1
// 0050d56f  83c201               add edx, 1
// 0050d572  85c0                 test eax, eax
// 0050d574  742f                 je 0x50d5a5
// 0050d576  0fb619               movzx ebx, byte ptr [ecx]
// 0050d579  0fb632               movzx esi, byte ptr [edx]
// 0050d57c  2bf3                 sub esi, ebx
// 0050d57e  7517                 jne 0x50d597
// 0050d580  83e801               sub eax, 1
// 0050d583  83c101               add ecx, 1
// 0050d586  83c201               add edx, 1
// 0050d589  85c0                 test eax, eax
// 0050d58b  7418                 je 0x50d5a5
// 0050d58d  0fb601               movzx eax, byte ptr [ecx]
// 0050d590  0fb632               movzx esi, byte ptr [edx]
// 0050d593  2bf0                 sub esi, eax
// 0050d595  740e                 je 0x50d5a5
// 0050d597  85f6                 test esi, esi
// 0050d599  b801000000           mov eax, 1
// 0050d59e  7f07                 jg 0x50d5a7
// 0050d5a0  83c8ff               or eax, 0xffffffff
// 0050d5a3  eb02                 jmp 0x50d5a7
// 0050d5a5  33c0                 xor eax, eax
// 0050d5a7  85c0                 test eax, eax
// 0050d5a9  7515                 jne 0x50d5c0
// 0050d5ab  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d5af  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d5b3  51                   push ecx
// 0050d5b4  52                   push edx
// 0050d5b5  55                   push ebp
// 0050d5b6  e8b5fd0000           call 0x51d370
// 0050d5bb  e9f1060000           jmp 0x50dcb1
// 0050d5c0  b804000000           mov eax, 4
// 0050d5c5  b9f40e7a00           mov ecx, 0x7a0ef4
// 0050d5ca  8bd7                 mov edx, edi
// 0050d5cc  8d642400             lea esp, [esp]
// 0050d5d0  8b32                 mov esi, dword ptr [edx]
// 0050d5d2  3b31                 cmp esi, dword ptr [ecx]
// 0050d5d4  7512                 jne 0x50d5e8
// 0050d5d6  83e804               sub eax, 4
// 0050d5d9  83c104               add ecx, 4
// 0050d5dc  83c204               add edx, 4
// 0050d5df  83f804               cmp eax, 4
// 0050d5e2  73ec                 jae 0x50d5d0
// 0050d5e4  85c0                 test eax, eax
// 0050d5e6  745d                 je 0x50d645
// 0050d5e8  0fb632               movzx esi, byte ptr [edx]
// 0050d5eb  0fb619               movzx ebx, byte ptr [ecx]
// 0050d5ee  2bf3                 sub esi, ebx
// 0050d5f0  7545                 jne 0x50d637
// 0050d5f2  83e801               sub eax, 1
// 0050d5f5  83c101               add ecx, 1
// 0050d5f8  83c201               add edx, 1
// 0050d5fb  85c0                 test eax, eax
// 0050d5fd  7446                 je 0x50d645
// 0050d5ff  0fb632               movzx esi, byte ptr [edx]
// 0050d602  0fb619               movzx ebx, byte ptr [ecx]
// 0050d605  2bf3                 sub esi, ebx
// 0050d607  752e                 jne 0x50d637
// 0050d609  83e801               sub eax, 1
// 0050d60c  83c101               add ecx, 1
// 0050d60f  83c201               add edx, 1
// 0050d612  85c0                 test eax, eax
// 0050d614  742f                 je 0x50d645
// 0050d616  0fb632               movzx esi, byte ptr [edx]
// 0050d619  0fb619               movzx ebx, byte ptr [ecx]
// 0050d61c  2bf3                 sub esi, ebx
// 0050d61e  7517                 jne 0x50d637
// 0050d620  83e801               sub eax, 1
// 0050d623  83c101               add ecx, 1
// 0050d626  83c201               add edx, 1
// 0050d629  85c0                 test eax, eax
// 0050d62b  7418                 je 0x50d645
// 0050d62d  0fb632               movzx esi, byte ptr [edx]
// 0050d630  0fb601               movzx eax, byte ptr [ecx]
// 0050d633  2bf0                 sub esi, eax
// 0050d635  740e                 je 0x50d645
// 0050d637  85f6                 test esi, esi
// 0050d639  b801000000           mov eax, 1
// 0050d63e  7f07                 jg 0x50d647
// 0050d640  83c8ff               or eax, 0xffffffff
// 0050d643  eb02                 jmp 0x50d647
// 0050d645  33c0                 xor eax, eax
// 0050d647  85c0                 test eax, eax
// 0050d649  7515                 jne 0x50d660
// 0050d64b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d64f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d653  51                   push ecx
// 0050d654  52                   push edx
// 0050d655  55                   push ebp
// 0050d656  e845fe0000           call 0x51d4a0
// 0050d65b  e951060000           jmp 0x50dcb1
// 0050d660  b804000000           mov eax, 4
// 0050d665  b9fc0e7a00           mov ecx, 0x7a0efc
// 0050d66a  8bd7                 mov edx, edi
// 0050d66c  8d642400             lea esp, [esp]
// 0050d670  8b32                 mov esi, dword ptr [edx]
// 0050d672  3b31                 cmp esi, dword ptr [ecx]
// 0050d674  7512                 jne 0x50d688
// 0050d676  83e804               sub eax, 4
// 0050d679  83c104               add ecx, 4
// 0050d67c  83c204               add edx, 4
// 0050d67f  83f804               cmp eax, 4
// 0050d682  73ec                 jae 0x50d670
// 0050d684  85c0                 test eax, eax
// 0050d686  745d                 je 0x50d6e5
// 0050d688  0fb619               movzx ebx, byte ptr [ecx]
// 0050d68b  0fb632               movzx esi, byte ptr [edx]
// 0050d68e  2bf3                 sub esi, ebx
// 0050d690  7545                 jne 0x50d6d7
// 0050d692  83e801               sub eax, 1
// 0050d695  83c101               add ecx, 1
// 0050d698  83c201               add edx, 1
// 0050d69b  85c0                 test eax, eax
// 0050d69d  7446                 je 0x50d6e5
// 0050d69f  0fb619               movzx ebx, byte ptr [ecx]
// 0050d6a2  0fb632               movzx esi, byte ptr [edx]
// 0050d6a5  2bf3                 sub esi, ebx
// 0050d6a7  752e                 jne 0x50d6d7
// 0050d6a9  83e801               sub eax, 1
// 0050d6ac  83c101               add ecx, 1
// 0050d6af  83c201               add edx, 1
// 0050d6b2  85c0                 test eax, eax
// 0050d6b4  742f                 je 0x50d6e5
// 0050d6b6  0fb619               movzx ebx, byte ptr [ecx]
// 0050d6b9  0fb632               movzx esi, byte ptr [edx]
// 0050d6bc  2bf3                 sub esi, ebx
// 0050d6be  7517                 jne 0x50d6d7
// 0050d6c0  83e801               sub eax, 1
// 0050d6c3  83c101               add ecx, 1
// 0050d6c6  83c201               add edx, 1
// 0050d6c9  85c0                 test eax, eax
// 0050d6cb  7418                 je 0x50d6e5
// 0050d6cd  0fb601               movzx eax, byte ptr [ecx]
// 0050d6d0  0fb632               movzx esi, byte ptr [edx]
// 0050d6d3  2bf0                 sub esi, eax
// 0050d6d5  740e                 je 0x50d6e5
// 0050d6d7  85f6                 test esi, esi
// 0050d6d9  b801000000           mov eax, 1
// 0050d6de  7f07                 jg 0x50d6e7
// 0050d6e0  83c8ff               or eax, 0xffffffff
// 0050d6e3  eb02                 jmp 0x50d6e7
// 0050d6e5  33c0                 xor eax, eax
// 0050d6e7  85c0                 test eax, eax
// 0050d6e9  7515                 jne 0x50d700
// 0050d6eb  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d6ef  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d6f3  51                   push ecx
// 0050d6f4  52                   push edx
// 0050d6f5  55                   push ebp
// 0050d6f6  e805000100           call 0x51d700
// 0050d6fb  e9b1050000           jmp 0x50dcb1
// 0050d700  b804000000           mov eax, 4
// 0050d705  b9040f7a00           mov ecx, 0x7a0f04
// 0050d70a  8bd7                 mov edx, edi
// 0050d70c  8d642400             lea esp, [esp]
// 0050d710  8b32                 mov esi, dword ptr [edx]
// 0050d712  3b31                 cmp esi, dword ptr [ecx]
// 0050d714  7512                 jne 0x50d728
// 0050d716  83e804               sub eax, 4
// 0050d719  83c104               add ecx, 4
// 0050d71c  83c204               add edx, 4
// 0050d71f  83f804               cmp eax, 4
// 0050d722  73ec                 jae 0x50d710
// 0050d724  85c0                 test eax, eax
// 0050d726  745d                 je 0x50d785
// 0050d728  0fb632               movzx esi, byte ptr [edx]
// 0050d72b  0fb619               movzx ebx, byte ptr [ecx]
// 0050d72e  2bf3                 sub esi, ebx
// 0050d730  7545                 jne 0x50d777
// 0050d732  83e801               sub eax, 1
// 0050d735  83c101               add ecx, 1
// 0050d738  83c201               add edx, 1
// 0050d73b  85c0                 test eax, eax
// 0050d73d  7446                 je 0x50d785
// 0050d73f  0fb632               movzx esi, byte ptr [edx]
// 0050d742  0fb619               movzx ebx, byte ptr [ecx]
// 0050d745  2bf3                 sub esi, ebx
// 0050d747  752e                 jne 0x50d777
// 0050d749  83e801               sub eax, 1
// 0050d74c  83c101               add ecx, 1
// 0050d74f  83c201               add edx, 1
// 0050d752  85c0                 test eax, eax
// 0050d754  742f                 je 0x50d785
// 0050d756  0fb632               movzx esi, byte ptr [edx]
// 0050d759  0fb619               movzx ebx, byte ptr [ecx]
// 0050d75c  2bf3                 sub esi, ebx
// 0050d75e  7517                 jne 0x50d777
// 0050d760  83e801               sub eax, 1
// 0050d763  83c101               add ecx, 1
// 0050d766  83c201               add edx, 1
// 0050d769  85c0                 test eax, eax
// 0050d76b  7418                 je 0x50d785
// 0050d76d  0fb632               movzx esi, byte ptr [edx]
// 0050d770  0fb601               movzx eax, byte ptr [ecx]
// 0050d773  2bf0                 sub esi, eax
// 0050d775  740e                 je 0x50d785
// 0050d777  85f6                 test esi, esi
// 0050d779  b801000000           mov eax, 1
// 0050d77e  7f07                 jg 0x50d787
// 0050d780  83c8ff               or eax, 0xffffffff
// 0050d783  eb02                 jmp 0x50d787
// 0050d785  33c0                 xor eax, eax
// 0050d787  85c0                 test eax, eax
// 0050d789  7515                 jne 0x50d7a0
// 0050d78b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d78f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d793  51                   push ecx
// 0050d794  52                   push edx
// 0050d795  55                   push ebp
// 0050d796  e8b5fa0000           call 0x51d250
// 0050d79b  e911050000           jmp 0x50dcb1
// 0050d7a0  b804000000           mov eax, 4
// 0050d7a5  b90c0f7a00           mov ecx, 0x7a0f0c
// 0050d7aa  8bd7                 mov edx, edi
// 0050d7ac  8d642400             lea esp, [esp]
// 0050d7b0  8b32                 mov esi, dword ptr [edx]
// 0050d7b2  3b31                 cmp esi, dword ptr [ecx]
// 0050d7b4  7512                 jne 0x50d7c8
// 0050d7b6  83e804               sub eax, 4
// 0050d7b9  83c104               add ecx, 4
// 0050d7bc  83c204               add edx, 4
// 0050d7bf  83f804               cmp eax, 4
// 0050d7c2  73ec                 jae 0x50d7b0
// 0050d7c4  85c0                 test eax, eax
// 0050d7c6  745d                 je 0x50d825
// 0050d7c8  0fb619               movzx ebx, byte ptr [ecx]
// 0050d7cb  0fb632               movzx esi, byte ptr [edx]
// 0050d7ce  2bf3                 sub esi, ebx
// 0050d7d0  7545                 jne 0x50d817
// 0050d7d2  83e801               sub eax, 1
// 0050d7d5  83c101               add ecx, 1
// 0050d7d8  83c201               add edx, 1
// 0050d7db  85c0                 test eax, eax
// 0050d7dd  7446                 je 0x50d825
// 0050d7df  0fb619               movzx ebx, byte ptr [ecx]
// 0050d7e2  0fb632               movzx esi, byte ptr [edx]
// 0050d7e5  2bf3                 sub esi, ebx
// 0050d7e7  752e                 jne 0x50d817
// 0050d7e9  83e801               sub eax, 1
// 0050d7ec  83c101               add ecx, 1
// 0050d7ef  83c201               add edx, 1
// 0050d7f2  85c0                 test eax, eax
// 0050d7f4  742f                 je 0x50d825
// 0050d7f6  0fb619               movzx ebx, byte ptr [ecx]
// 0050d7f9  0fb632               movzx esi, byte ptr [edx]
// 0050d7fc  2bf3                 sub esi, ebx
// 0050d7fe  7517                 jne 0x50d817
// 0050d800  83e801               sub eax, 1
// 0050d803  83c101               add ecx, 1
// 0050d806  83c201               add edx, 1
// 0050d809  85c0                 test eax, eax
// 0050d80b  7418                 je 0x50d825
// 0050d80d  0fb601               movzx eax, byte ptr [ecx]
// 0050d810  0fb632               movzx esi, byte ptr [edx]
// 0050d813  2bf0                 sub esi, eax
// 0050d815  740e                 je 0x50d825
// 0050d817  85f6                 test esi, esi
// 0050d819  b801000000           mov eax, 1
// 0050d81e  7f07                 jg 0x50d827
// 0050d820  83c8ff               or eax, 0xffffffff
// 0050d823  eb02                 jmp 0x50d827
// 0050d825  33c0                 xor eax, eax
// 0050d827  85c0                 test eax, eax
// 0050d829  7515                 jne 0x50d840
// 0050d82b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d82f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d833  51                   push ecx
// 0050d834  52                   push edx
// 0050d835  55                   push ebp
// 0050d836  e8c5e70000           call 0x51c000
// 0050d83b  e971040000           jmp 0x50dcb1
// 0050d840  b804000000           mov eax, 4
// 0050d845  b91c0f7a00           mov ecx, 0x7a0f1c
// 0050d84a  8bd7                 mov edx, edi
// 0050d84c  8d642400             lea esp, [esp]
// 0050d850  8b32                 mov esi, dword ptr [edx]
// 0050d852  3b31                 cmp esi, dword ptr [ecx]
// 0050d854  7512                 jne 0x50d868
// 0050d856  83e804               sub eax, 4
// 0050d859  83c104               add ecx, 4
// 0050d85c  83c204               add edx, 4
// 0050d85f  83f804               cmp eax, 4
// 0050d862  73ec                 jae 0x50d850
// 0050d864  85c0                 test eax, eax
// 0050d866  745d                 je 0x50d8c5
// 0050d868  0fb632               movzx esi, byte ptr [edx]
// 0050d86b  0fb619               movzx ebx, byte ptr [ecx]
// 0050d86e  2bf3                 sub esi, ebx
// 0050d870  7545                 jne 0x50d8b7
// 0050d872  83e801               sub eax, 1
// 0050d875  83c101               add ecx, 1
// 0050d878  83c201               add edx, 1
// 0050d87b  85c0                 test eax, eax
// 0050d87d  7446                 je 0x50d8c5
// 0050d87f  0fb632               movzx esi, byte ptr [edx]
// 0050d882  0fb619               movzx ebx, byte ptr [ecx]
// 0050d885  2bf3                 sub esi, ebx
// 0050d887  752e                 jne 0x50d8b7
// 0050d889  83e801               sub eax, 1
// 0050d88c  83c101               add ecx, 1
// 0050d88f  83c201               add edx, 1
// 0050d892  85c0                 test eax, eax
// 0050d894  742f                 je 0x50d8c5
// 0050d896  0fb632               movzx esi, byte ptr [edx]
// 0050d899  0fb619               movzx ebx, byte ptr [ecx]
// 0050d89c  2bf3                 sub esi, ebx
// 0050d89e  7517                 jne 0x50d8b7
// 0050d8a0  83e801               sub eax, 1
// 0050d8a3  83c101               add ecx, 1
// 0050d8a6  83c201               add edx, 1
// 0050d8a9  85c0                 test eax, eax
// 0050d8ab  7418                 je 0x50d8c5
// 0050d8ad  0fb632               movzx esi, byte ptr [edx]
// 0050d8b0  0fb601               movzx eax, byte ptr [ecx]
// 0050d8b3  2bf0                 sub esi, eax
// 0050d8b5  740e                 je 0x50d8c5
// 0050d8b7  85f6                 test esi, esi
// 0050d8b9  b801000000           mov eax, 1
// 0050d8be  7f07                 jg 0x50d8c7
// 0050d8c0  83c8ff               or eax, 0xffffffff
// 0050d8c3  eb02                 jmp 0x50d8c7
// 0050d8c5  33c0                 xor eax, eax
// 0050d8c7  85c0                 test eax, eax
// 0050d8c9  7515                 jne 0x50d8e0
// 0050d8cb  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d8cf  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d8d3  51                   push ecx
// 0050d8d4  52                   push edx
// 0050d8d5  55                   push ebp
// 0050d8d6  e885ed0000           call 0x51c660
// 0050d8db  e9d1030000           jmp 0x50dcb1
// 0050d8e0  b804000000           mov eax, 4
// 0050d8e5  b9dc0e7a00           mov ecx, 0x7a0edc
// 0050d8ea  8bd7                 mov edx, edi
// 0050d8ec  8d642400             lea esp, [esp]
// 0050d8f0  8b32                 mov esi, dword ptr [edx]
// 0050d8f2  3b31                 cmp esi, dword ptr [ecx]
// 0050d8f4  7512                 jne 0x50d908
// 0050d8f6  83e804               sub eax, 4
// 0050d8f9  83c104               add ecx, 4
// 0050d8fc  83c204               add edx, 4
// 0050d8ff  83f804               cmp eax, 4
// 0050d902  73ec                 jae 0x50d8f0
// 0050d904  85c0                 test eax, eax
// 0050d906  745d                 je 0x50d965
// 0050d908  0fb619               movzx ebx, byte ptr [ecx]
// 0050d90b  0fb632               movzx esi, byte ptr [edx]
// 0050d90e  2bf3                 sub esi, ebx
// 0050d910  7545                 jne 0x50d957
// 0050d912  83e801               sub eax, 1
// 0050d915  83c101               add ecx, 1
// 0050d918  83c201               add edx, 1
// 0050d91b  85c0                 test eax, eax
// 0050d91d  7446                 je 0x50d965
// 0050d91f  0fb619               movzx ebx, byte ptr [ecx]
// 0050d922  0fb632               movzx esi, byte ptr [edx]
// 0050d925  2bf3                 sub esi, ebx
// 0050d927  752e                 jne 0x50d957
// 0050d929  83e801               sub eax, 1
// 0050d92c  83c101               add ecx, 1
// 0050d92f  83c201               add edx, 1
// 0050d932  85c0                 test eax, eax
// 0050d934  742f                 je 0x50d965
// 0050d936  0fb619               movzx ebx, byte ptr [ecx]
// 0050d939  0fb632               movzx esi, byte ptr [edx]
// 0050d93c  2bf3                 sub esi, ebx
// 0050d93e  7517                 jne 0x50d957
// 0050d940  83e801               sub eax, 1
// 0050d943  83c101               add ecx, 1
// 0050d946  83c201               add edx, 1
// 0050d949  85c0                 test eax, eax
// 0050d94b  7418                 je 0x50d965
// 0050d94d  0fb601               movzx eax, byte ptr [ecx]
// 0050d950  0fb632               movzx esi, byte ptr [edx]
// 0050d953  2bf0                 sub esi, eax
// 0050d955  740e                 je 0x50d965
// 0050d957  85f6                 test esi, esi
// 0050d959  b801000000           mov eax, 1
// 0050d95e  7f07                 jg 0x50d967
// 0050d960  83c8ff               or eax, 0xffffffff
// 0050d963  eb02                 jmp 0x50d967
// 0050d965  33c0                 xor eax, eax
// 0050d967  85c0                 test eax, eax
// 0050d969  7515                 jne 0x50d980
// 0050d96b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050d96f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050d973  51                   push ecx
// 0050d974  52                   push edx
// 0050d975  55                   push ebp
// 0050d976  e8d5ee0000           call 0x51c850
// 0050d97b  e931030000           jmp 0x50dcb1
// 0050d980  b804000000           mov eax, 4
// 0050d985  b9140f7a00           mov ecx, 0x7a0f14
// 0050d98a  8bd7                 mov edx, edi
// 0050d98c  8d642400             lea esp, [esp]
// 0050d990  8b32                 mov esi, dword ptr [edx]
// 0050d992  3b31                 cmp esi, dword ptr [ecx]
// 0050d994  7512                 jne 0x50d9a8
// 0050d996  83e804               sub eax, 4
// 0050d999  83c104               add ecx, 4
// 0050d99c  83c204               add edx, 4
// 0050d99f  83f804               cmp eax, 4
// 0050d9a2  73ec                 jae 0x50d990
// 0050d9a4  85c0                 test eax, eax
// 0050d9a6  745d                 je 0x50da05
// 0050d9a8  0fb632               movzx esi, byte ptr [edx]
// 0050d9ab  0fb619               movzx ebx, byte ptr [ecx]
// 0050d9ae  2bf3                 sub esi, ebx
// 0050d9b0  7545                 jne 0x50d9f7
// 0050d9b2  83e801               sub eax, 1
// 0050d9b5  83c101               add ecx, 1
// 0050d9b8  83c201               add edx, 1
// 0050d9bb  85c0                 test eax, eax
// 0050d9bd  7446                 je 0x50da05
// 0050d9bf  0fb632               movzx esi, byte ptr [edx]
// 0050d9c2  0fb619               movzx ebx, byte ptr [ecx]
// 0050d9c5  2bf3                 sub esi, ebx
// 0050d9c7  752e                 jne 0x50d9f7
// 0050d9c9  83e801               sub eax, 1
// 0050d9cc  83c101               add ecx, 1
// 0050d9cf  83c201               add edx, 1
// 0050d9d2  85c0                 test eax, eax
// 0050d9d4  742f                 je 0x50da05
// 0050d9d6  0fb632               movzx esi, byte ptr [edx]
// 0050d9d9  0fb619               movzx ebx, byte ptr [ecx]
// 0050d9dc  2bf3                 sub esi, ebx
// 0050d9de  7517                 jne 0x50d9f7
// 0050d9e0  83e801               sub eax, 1
// 0050d9e3  83c101               add ecx, 1
// 0050d9e6  83c201               add edx, 1
// 0050d9e9  85c0                 test eax, eax
// 0050d9eb  7418                 je 0x50da05
// 0050d9ed  0fb632               movzx esi, byte ptr [edx]
// 0050d9f0  0fb601               movzx eax, byte ptr [ecx]
// 0050d9f3  2bf0                 sub esi, eax
// 0050d9f5  740e                 je 0x50da05
// 0050d9f7  85f6                 test esi, esi
// 0050d9f9  b801000000           mov eax, 1
// 0050d9fe  7f07                 jg 0x50da07
// 0050da00  83c8ff               or eax, 0xffffffff
// 0050da03  eb02                 jmp 0x50da07
// 0050da05  33c0                 xor eax, eax
// 0050da07  85c0                 test eax, eax
// 0050da09  7515                 jne 0x50da20
// 0050da0b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050da0f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050da13  51                   push ecx
// 0050da14  52                   push edx
// 0050da15  55                   push ebp
// 0050da16  e8e5ef0000           call 0x51ca00
// 0050da1b  e991020000           jmp 0x50dcb1
// 0050da20  b804000000           mov eax, 4
// 0050da25  b9240f7a00           mov ecx, 0x7a0f24
// 0050da2a  8bd7                 mov edx, edi
// 0050da2c  8d642400             lea esp, [esp]
// 0050da30  8b32                 mov esi, dword ptr [edx]
// 0050da32  3b31                 cmp esi, dword ptr [ecx]
// 0050da34  7512                 jne 0x50da48
// 0050da36  83e804               sub eax, 4
// 0050da39  83c104               add ecx, 4
// 0050da3c  83c204               add edx, 4
// 0050da3f  83f804               cmp eax, 4
// 0050da42  73ec                 jae 0x50da30
// 0050da44  85c0                 test eax, eax
// 0050da46  745d                 je 0x50daa5
// 0050da48  0fb619               movzx ebx, byte ptr [ecx]
// 0050da4b  0fb632               movzx esi, byte ptr [edx]
// 0050da4e  2bf3                 sub esi, ebx
// 0050da50  7545                 jne 0x50da97
// 0050da52  83e801               sub eax, 1
// 0050da55  83c101               add ecx, 1
// 0050da58  83c201               add edx, 1
// 0050da5b  85c0                 test eax, eax
// 0050da5d  7446                 je 0x50daa5
// 0050da5f  0fb619               movzx ebx, byte ptr [ecx]
// 0050da62  0fb632               movzx esi, byte ptr [edx]
// 0050da65  2bf3                 sub esi, ebx
// 0050da67  752e                 jne 0x50da97
// 0050da69  83e801               sub eax, 1
// 0050da6c  83c101               add ecx, 1
// 0050da6f  83c201               add edx, 1
// 0050da72  85c0                 test eax, eax
// 0050da74  742f                 je 0x50daa5
// 0050da76  0fb619               movzx ebx, byte ptr [ecx]
// 0050da79  0fb632               movzx esi, byte ptr [edx]
// 0050da7c  2bf3                 sub esi, ebx
// 0050da7e  7517                 jne 0x50da97
// 0050da80  83e801               sub eax, 1
// 0050da83  83c101               add ecx, 1
// 0050da86  83c201               add edx, 1
// 0050da89  85c0                 test eax, eax
// 0050da8b  7418                 je 0x50daa5
// 0050da8d  0fb601               movzx eax, byte ptr [ecx]
// 0050da90  0fb632               movzx esi, byte ptr [edx]
// 0050da93  2bf0                 sub esi, eax
// 0050da95  740e                 je 0x50daa5
// 0050da97  85f6                 test esi, esi
// 0050da99  b801000000           mov eax, 1
// 0050da9e  7f07                 jg 0x50daa7
// 0050daa0  83c8ff               or eax, 0xffffffff
// 0050daa3  eb02                 jmp 0x50daa7
// 0050daa5  33c0                 xor eax, eax
// 0050daa7  85c0                 test eax, eax
// 0050daa9  7515                 jne 0x50dac0
// 0050daab  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050daaf  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050dab3  51                   push ecx
// 0050dab4  52                   push edx
// 0050dab5  55                   push ebp
// 0050dab6  e825ff0000           call 0x51d9e0
// 0050dabb  e9f1010000           jmp 0x50dcb1
// 0050dac0  b804000000           mov eax, 4
// 0050dac5  b92c0f7a00           mov ecx, 0x7a0f2c
// 0050daca  8bd7                 mov edx, edi
// 0050dacc  8d642400             lea esp, [esp]
// 0050dad0  8b32                 mov esi, dword ptr [edx]
// 0050dad2  3b31                 cmp esi, dword ptr [ecx]
// 0050dad4  7512                 jne 0x50dae8
// 0050dad6  83e804               sub eax, 4
// 0050dad9  83c104               add ecx, 4
// 0050dadc  83c204               add edx, 4
// 0050dadf  83f804               cmp eax, 4
// 0050dae2  73ec                 jae 0x50dad0
// 0050dae4  85c0                 test eax, eax
// 0050dae6  745d                 je 0x50db45
// 0050dae8  0fb632               movzx esi, byte ptr [edx]
// 0050daeb  0fb619               movzx ebx, byte ptr [ecx]
// 0050daee  2bf3                 sub esi, ebx
// 0050daf0  7545                 jne 0x50db37
// 0050daf2  83e801               sub eax, 1
// 0050daf5  83c101               add ecx, 1
// 0050daf8  83c201               add edx, 1
// 0050dafb  85c0                 test eax, eax
// 0050dafd  7446                 je 0x50db45
// 0050daff  0fb632               movzx esi, byte ptr [edx]
// 0050db02  0fb619               movzx ebx, byte ptr [ecx]
// 0050db05  2bf3                 sub esi, ebx
// 0050db07  752e                 jne 0x50db37
// 0050db09  83e801               sub eax, 1
// 0050db0c  83c101               add ecx, 1
// 0050db0f  83c201               add edx, 1
// 0050db12  85c0                 test eax, eax
// 0050db14  742f                 je 0x50db45
// 0050db16  0fb632               movzx esi, byte ptr [edx]
// 0050db19  0fb619               movzx ebx, byte ptr [ecx]
// 0050db1c  2bf3                 sub esi, ebx
// 0050db1e  7517                 jne 0x50db37
// 0050db20  83e801               sub eax, 1
// 0050db23  83c101               add ecx, 1
// 0050db26  83c201               add edx, 1
// 0050db29  85c0                 test eax, eax
// 0050db2b  7418                 je 0x50db45
// 0050db2d  0fb632               movzx esi, byte ptr [edx]
// 0050db30  0fb601               movzx eax, byte ptr [ecx]
// 0050db33  2bf0                 sub esi, eax
// 0050db35  740e                 je 0x50db45
// 0050db37  85f6                 test esi, esi
// 0050db39  b801000000           mov eax, 1
// 0050db3e  7f07                 jg 0x50db47
// 0050db40  83c8ff               or eax, 0xffffffff
// 0050db43  eb02                 jmp 0x50db47
// 0050db45  33c0                 xor eax, eax
// 0050db47  85c0                 test eax, eax
// 0050db49  7515                 jne 0x50db60
// 0050db4b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050db4f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050db53  51                   push ecx
// 0050db54  52                   push edx
// 0050db55  55                   push ebp
// 0050db56  e865fd0000           call 0x51d8c0
// 0050db5b  e951010000           jmp 0x50dcb1
// 0050db60  b804000000           mov eax, 4
// 0050db65  b9340f7a00           mov ecx, 0x7a0f34
// 0050db6a  8bd7                 mov edx, edi
// 0050db6c  8d642400             lea esp, [esp]
// 0050db70  8b32                 mov esi, dword ptr [edx]
// 0050db72  3b31                 cmp esi, dword ptr [ecx]
// 0050db74  7512                 jne 0x50db88
// 0050db76  83e804               sub eax, 4
// 0050db79  83c104               add ecx, 4
// 0050db7c  83c204               add edx, 4
// 0050db7f  83f804               cmp eax, 4
// 0050db82  73ec                 jae 0x50db70
// 0050db84  85c0                 test eax, eax
// 0050db86  745d                 je 0x50dbe5
// 0050db88  0fb619               movzx ebx, byte ptr [ecx]
// 0050db8b  0fb632               movzx esi, byte ptr [edx]
// 0050db8e  2bf3                 sub esi, ebx
// 0050db90  7545                 jne 0x50dbd7
// 0050db92  83e801               sub eax, 1
// 0050db95  83c101               add ecx, 1
// 0050db98  83c201               add edx, 1
// 0050db9b  85c0                 test eax, eax
// 0050db9d  7446                 je 0x50dbe5
// 0050db9f  0fb619               movzx ebx, byte ptr [ecx]
// 0050dba2  0fb632               movzx esi, byte ptr [edx]
// 0050dba5  2bf3                 sub esi, ebx
// 0050dba7  752e                 jne 0x50dbd7
// 0050dba9  83e801               sub eax, 1
// 0050dbac  83c101               add ecx, 1
// 0050dbaf  83c201               add edx, 1
// 0050dbb2  85c0                 test eax, eax
// 0050dbb4  742f                 je 0x50dbe5
// 0050dbb6  0fb619               movzx ebx, byte ptr [ecx]
// 0050dbb9  0fb632               movzx esi, byte ptr [edx]
// 0050dbbc  2bf3                 sub esi, ebx
// 0050dbbe  7517                 jne 0x50dbd7
// 0050dbc0  83e801               sub eax, 1
// 0050dbc3  83c101               add ecx, 1
// 0050dbc6  83c201               add edx, 1
// 0050dbc9  85c0                 test eax, eax
// 0050dbcb  7418                 je 0x50dbe5
// 0050dbcd  0fb601               movzx eax, byte ptr [ecx]
// 0050dbd0  0fb632               movzx esi, byte ptr [edx]
// 0050dbd3  2bf0                 sub esi, eax
// 0050dbd5  740e                 je 0x50dbe5
// 0050dbd7  85f6                 test esi, esi
// 0050dbd9  b801000000           mov eax, 1
// 0050dbde  7f07                 jg 0x50dbe7
// 0050dbe0  83c8ff               or eax, 0xffffffff
// 0050dbe3  eb02                 jmp 0x50dbe7
// 0050dbe5  33c0                 xor eax, eax
// 0050dbe7  85c0                 test eax, eax
// 0050dbe9  7515                 jne 0x50dc00
// 0050dbeb  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050dbef  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050dbf3  51                   push ecx
// 0050dbf4  52                   push edx
// 0050dbf5  55                   push ebp
// 0050dbf6  e825f00000           call 0x51cc20
// 0050dbfb  e9b1000000           jmp 0x50dcb1
// 0050dc00  b804000000           mov eax, 4
// 0050dc05  b93c0f7a00           mov ecx, 0x7a0f3c
// 0050dc0a  8bd7                 mov edx, edi
// 0050dc0c  8d642400             lea esp, [esp]
// 0050dc10  8b32                 mov esi, dword ptr [edx]
// 0050dc12  3b31                 cmp esi, dword ptr [ecx]
// 0050dc14  7516                 jne 0x50dc2c
// 0050dc16  83e804               sub eax, 4
// 0050dc19  83c104               add ecx, 4
// 0050dc1c  83c204               add edx, 4
// 0050dc1f  83f804               cmp eax, 4
// 0050dc22  73ec                 jae 0x50dc10
// 0050dc24  85c0                 test eax, eax
// 0050dc26  0f845d000000         je 0x50dc89
// 0050dc2c  0fb632               movzx esi, byte ptr [edx]
// 0050dc2f  0fb619               movzx ebx, byte ptr [ecx]
// 0050dc32  2bf3                 sub esi, ebx
// 0050dc34  7545                 jne 0x50dc7b
// 0050dc36  83e801               sub eax, 1
// 0050dc39  83c101               add ecx, 1
// 0050dc3c  83c201               add edx, 1
// 0050dc3f  85c0                 test eax, eax
// 0050dc41  7446                 je 0x50dc89
// 0050dc43  0fb632               movzx esi, byte ptr [edx]
// 0050dc46  0fb619               movzx ebx, byte ptr [ecx]
// 0050dc49  2bf3                 sub esi, ebx
// 0050dc4b  752e                 jne 0x50dc7b
// 0050dc4d  83e801               sub eax, 1
// 0050dc50  83c101               add ecx, 1
// 0050dc53  83c201               add edx, 1
// 0050dc56  85c0                 test eax, eax
// 0050dc58  742f                 je 0x50dc89
// 0050dc5a  0fb632               movzx esi, byte ptr [edx]
// 0050dc5d  0fb619               movzx ebx, byte ptr [ecx]
// 0050dc60  2bf3                 sub esi, ebx
// 0050dc62  7517                 jne 0x50dc7b
// 0050dc64  83e801               sub eax, 1
// 0050dc67  83c101               add ecx, 1
// 0050dc6a  83c201               add edx, 1
// 0050dc6d  85c0                 test eax, eax
// 0050dc6f  7418                 je 0x50dc89
// 0050dc71  0fb632               movzx esi, byte ptr [edx]
// 0050dc74  0fb601               movzx eax, byte ptr [ecx]
// 0050dc77  2bf0                 sub esi, eax
// 0050dc79  740e                 je 0x50dc89
// 0050dc7b  85f6                 test esi, esi
// 0050dc7d  b801000000           mov eax, 1
// 0050dc82  7f07                 jg 0x50dc8b
// 0050dc84  83c8ff               or eax, 0xffffffff
// 0050dc87  eb02                 jmp 0x50dc8b
// 0050dc89  33c0                 xor eax, eax
// 0050dc8b  85c0                 test eax, eax
// 0050dc8d  7512                 jne 0x50dca1
// 0050dc8f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050dc93  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0050dc97  51                   push ecx
// 0050dc98  52                   push edx
// 0050dc99  55                   push ebp
// 0050dc9a  e861fe0000           call 0x51db00
// 0050dc9f  eb10                 jmp 0x50dcb1
// 0050dca1  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050dca5  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050dca9  50                   push eax
// 0050dcaa  51                   push ecx
// 0050dcab  55                   push ebp
// 0050dcac  e8afff0000           call 0x51dc60
// 0050dcb1  83c40c               add esp, 0xc
// 0050dcb4  f6456810             test byte ptr [ebp + 0x68], 0x10
// 0050dcb8  0f84c2f1ffff         je 0x50ce80
// 0050dcbe  5f                   pop edi
// 0050dcbf  5e                   pop esi
// 0050dcc0  5d                   pop ebp
// 0050dcc1  5b                   pop ebx
// 0050dcc2  59                   pop ecx
// 0050dcc3  c3                   ret 
// library libpng-1.2.7/pngread.c (function _png_read_end)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngread.c
