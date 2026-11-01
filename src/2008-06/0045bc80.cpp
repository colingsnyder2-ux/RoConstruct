// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2008-06 0045bc80  unit: CRobloxWnd  size: 351 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045bc80
//
// 0045bc80  55                   push ebp
// 0045bc81  8bec                 mov ebp, esp
// 0045bc83  6aff                 push -1
// 0045bc85  68e82b7c00           push 0x7c2be8
// 0045bc8a  64a100000000         mov eax, dword ptr fs:[0]
// 0045bc90  50                   push eax
// 0045bc91  64892500000000       mov dword ptr fs:[0], esp
// 0045bc98  83ec20               sub esp, 0x20
// 0045bc9b  53                   push ebx
// 0045bc9c  56                   push esi
// 0045bc9d  8bf1                 mov esi, ecx
// 0045bc9f  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bca5  57                   push edi
// 0045bca6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0045bca9  8975ec               mov dword ptr [ebp - 0x14], esi
// 0045bcac  e82f100200           call 0x47cce0
// 0045bcb1  8b4670               mov eax, dword ptr [esi + 0x70]
// 0045bcb4  83ec08               sub esp, 8
// 0045bcb7  8bcc                 mov ecx, esp
// 0045bcb9  8901                 mov dword ptr [ecx], eax
// 0045bcbb  8b4674               mov eax, dword ptr [esi + 0x74]
// 0045bcbe  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0045bcc5  8965e8               mov dword ptr [ebp - 0x18], esp
// 0045bcc8  894104               mov dword ptr [ecx + 4], eax
// 0045bccb  85c0                 test eax, eax
// 0045bccd  740c                 je 0x45bcdb
// 0045bccf  83c004               add eax, 4
// 0045bcd2  b901000000           mov ecx, 1
// 0045bcd7  f00fc108             lock xadd dword ptr [eax], ecx
// 0045bcdb  8d4dd4               lea ecx, [ebp - 0x2c]
// 0045bcde  e85d5efbff           call 0x411b40
// 0045bce3  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0045bce9  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0045bcef  8b11                 mov edx, dword ptr [ecx]
// 0045bcf1  50                   push eax
// 0045bcf2  8b4204               mov eax, dword ptr [edx + 4]
// 0045bcf5  b301                 mov bl, 1
// 0045bcf7  885dfc               mov byte ptr [ebp - 4], bl
// 0045bcfa  ffd0                 call eax
// 0045bcfc  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0045bd02  8b11                 mov edx, dword ptr [ecx]
// 0045bd04  8b421c               mov eax, dword ptr [edx + 0x1c]
// 0045bd07  ffd0                 call eax
// 0045bd09  8bf8                 mov edi, eax
// 0045bd0b  8bc8                 mov ecx, eax
// 0045bd0d  897de8               mov dword ptr [ebp - 0x18], edi
// 0045bd10  e8db5f0b00           call 0x511cf0
// 0045bd15  8b86b4000000         mov eax, dword ptr [esi + 0xb4]
// 0045bd1b  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045bd1e  50                   push eax
// 0045bd1f  c645fc02             mov byte ptr [ebp - 4], 2
// 0045bd23  e898e91100           call 0x57a6c0
// 0045bd28  807d0800             cmp byte ptr [ebp + 8], 0
// 0045bd2c  7429                 je 0x45bd57
// 0045bd2e  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bd34  e867160200           call 0x47d3a0
// 0045bd39  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 0045bd3f  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045bd42  8d4658               lea eax, [esi + 0x58]
// 0045bd45  50                   push eax
// 0045bd46  52                   push edx
// 0045bd47  e864e41100           call 0x57a1b0
// 0045bd4c  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bd52  e809160200           call 0x47d360
// 0045bd57  8bcf                 mov ecx, edi
// 0045bd59  885dfc               mov byte ptr [ebp - 4], bl
// 0045bd5c  e88f600b00           call 0x511df0
// 0045bd61  8d4dd4               lea ecx, [ebp - 0x2c]
// 0045bd64  c645fc00             mov byte ptr [ebp - 4], 0
// 0045bd68  e853b61100           call 0x5773c0
// 0045bd6d  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0045bd74  eb3b                 jmp 0x45bdb1
// 0045bd76  8d4de4               lea ecx, [ebp - 0x1c]
// 0045bd79  51                   push ecx
// 0045bd7a  e8a1d81000           call 0x569620
// 0045bd7f  83c404               add esp, 4
// 0045bd82  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0045bd85  8b00                 mov eax, dword ptr [eax]
// 0045bd87  52                   push edx
// 0045bd88  6a03                 push 3
// 0045bd8a  8bc8                 mov ecx, eax
// 0045bd8c  c645fc04             mov byte ptr [ebp - 4], 4
// 0045bd90  e87bb0fbff           call 0x416e10
// 0045bd95  8d4de4               lea ecx, [ebp - 0x1c]
// 0045bd98  c645fc03             mov byte ptr [ebp - 4], 3
// 0045bd9c  e8bf481a00           call 0x600660
// 0045bda1  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0045bda8  b8aebd4500           mov eax, 0x45bdae
// 0045bdad  c3                   ret 
// 0045bdae  8b75ec               mov esi, dword ptr [ebp - 0x14]
// 0045bdb1  8b4e78               mov ecx, dword ptr [esi + 0x78]
// 0045bdb4  85c9                 test ecx, ecx
// 0045bdb6  7409                 je 0x45bdc1
// 0045bdb8  8d4654               lea eax, [esi + 0x54]
// 0045bdbb  50                   push eax
// 0045bdbc  e81f980f00           call 0x5555e0
// 0045bdc1  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bdc7  e894150200           call 0x47d360
// 0045bdcc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0045bdcf  5f                   pop edi
// 0045bdd0  5e                   pop esi
// 0045bdd1  64890d00000000       mov dword ptr fs:[0], ecx
// 0045bdd8  5b                   pop ebx
// 0045bdd9  8be5                 mov esp, ebp
// 0045bddb  5d                   pop ebp
// 0045bddc  c20400               ret 4

// from server: 97% by EspClaude
// roc 2008-06 0045bc80  unit: CRobloxWnd  size: 351 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045bc80
//
// 0045bc80  55                   push ebp
// 0045bc81  8bec                 mov ebp, esp
// 0045bc83  6aff                 push -1
// 0045bc85  68e82b7c00           push 0x7c2be8
// 0045bc8a  64a100000000         mov eax, dword ptr fs:[0]
// 0045bc90  50                   push eax
// 0045bc91  64892500000000       mov dword ptr fs:[0], esp
// 0045bc98  83ec20               sub esp, 0x20
// 0045bc9b  53                   push ebx
// 0045bc9c  56                   push esi
// 0045bc9d  8bf1                 mov esi, ecx
// 0045bc9f  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bca5  57                   push edi
// 0045bca6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0045bca9  8975ec               mov dword ptr [ebp - 0x14], esi
// 0045bcac  e82f100200           call 0x47cce0
// 0045bcb1  8b4670               mov eax, dword ptr [esi + 0x70]
// 0045bcb4  83ec08               sub esp, 8
// 0045bcb7  8bcc                 mov ecx, esp
// 0045bcb9  8901                 mov dword ptr [ecx], eax
// 0045bcbb  8b4674               mov eax, dword ptr [esi + 0x74]
// 0045bcbe  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0045bcc5  8965e8               mov dword ptr [ebp - 0x18], esp
// 0045bcc8  894104               mov dword ptr [ecx + 4], eax
// 0045bccb  85c0                 test eax, eax
// 0045bccd  740c                 je 0x45bcdb
// 0045bccf  83c004               add eax, 4
// 0045bcd2  b901000000           mov ecx, 1
// 0045bcd7  f00fc108             lock xadd dword ptr [eax], ecx
// 0045bcdb  8d4dd4               lea ecx, [ebp - 0x2c]
// 0045bcde  e85d5efbff           call 0x411b40
// 0045bce3  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0045bce9  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0045bcef  8b11                 mov edx, dword ptr [ecx]
// 0045bcf1  50                   push eax
// 0045bcf2  8b4204               mov eax, dword ptr [edx + 4]
// 0045bcf5  b301                 mov bl, 1
// 0045bcf7  885dfc               mov byte ptr [ebp - 4], bl
// 0045bcfa  ffd0                 call eax
// 0045bcfc  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0045bd02  8b11                 mov edx, dword ptr [ecx]
// 0045bd04  8b421c               mov eax, dword ptr [edx + 0x1c]
// 0045bd07  ffd0                 call eax
// 0045bd09  8bf8                 mov edi, eax
// 0045bd0b  8bc8                 mov ecx, eax
// 0045bd0d  897de8               mov dword ptr [ebp - 0x18], edi
// 0045bd10  e8db5f0b00           call 0x511cf0
// 0045bd15  8b86b4000000         mov eax, dword ptr [esi + 0xb4]
// 0045bd1b  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045bd1e  50                   push eax
// 0045bd1f  c645fc02             mov byte ptr [ebp - 4], 2
// 0045bd23  e898e91100           call 0x57a6c0
// 0045bd28  807d0800             cmp byte ptr [ebp + 8], 0
// 0045bd2c  7429                 je 0x45bd57
// 0045bd2e  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bd34  e867160200           call 0x47d3a0
// 0045bd39  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 0045bd3f  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045bd42  8d4658               lea eax, [esi + 0x58]
// 0045bd45  50                   push eax
// 0045bd46  52                   push edx
// 0045bd47  e864e41100           call 0x57a1b0
// 0045bd4c  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bd52  e809160200           call 0x47d360
// 0045bd57  8bcf                 mov ecx, edi
// 0045bd59  885dfc               mov byte ptr [ebp - 4], bl
// 0045bd5c  e88f600b00           call 0x511df0
// 0045bd61  8d4dd4               lea ecx, [ebp - 0x2c]
// 0045bd64  c645fc00             mov byte ptr [ebp - 4], 0
// 0045bd68  e853b61100           call 0x5773c0
// 0045bd6d  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0045bd74  eb3b                 jmp 0x45bdb1
// 0045bd76  8d4de4               lea ecx, [ebp - 0x1c]
// 0045bd79  51                   push ecx
// 0045bd7a  e8a1d81000           call 0x569620
// 0045bd7f  83c404               add esp, 4
// 0045bd82  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0045bd85  8b00                 mov eax, dword ptr [eax]
// 0045bd87  52                   push edx
// 0045bd88  6a03                 push 3
// 0045bd8a  8bc8                 mov ecx, eax
// 0045bd8c  c645fc04             mov byte ptr [ebp - 4], 4
// 0045bd90  e87bb0fbff           call 0x416e10
// 0045bd95  8d4de4               lea ecx, [ebp - 0x1c]
// 0045bd98  c645fc03             mov byte ptr [ebp - 4], 3
// 0045bd9c  e8bf481a00           call 0x600660
// 0045bda1  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0045bda8  b8aebd4500           mov eax, 0x45bdae
// 0045bdad  c3                   ret 
// 0045bdae  8b75ec               mov esi, dword ptr [ebp - 0x14]
// 0045bdb1  8b4e78               mov ecx, dword ptr [esi + 0x78]
// 0045bdb4  85c9                 test ecx, ecx
// 0045bdb6  7409                 je 0x45bdc1
// 0045bdb8  8d4654               lea eax, [esi + 0x54]
// 0045bdbb  50                   push eax
// 0045bdbc  e81f980f00           call 0x5555e0
// 0045bdc1  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bdc7  e894150200           call 0x47d360
// 0045bdcc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0045bdcf  5f                   pop edi
// 0045bdd0  5e                   pop esi
// 0045bdd1  64890d00000000       mov dword ptr fs:[0], ecx
// 0045bdd8  5b                   pop ebx
// 0045bdd9  8be5                 mov esp, ebp
// 0045bddb  5d                   pop ebp
// 0045bddc  c20400               ret 4

// from server: 96% by colin
// roc 2008-06 0045bc80  unit: CRobloxWnd  size: 246 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045bc80
//
// 0045bc80  55                   push ebp
// 0045bc81  8bec                 mov ebp, esp
// 0045bc83  6aff                 push -1
// 0045bc85  68e82b7c00           push 0x7c2be8
// 0045bc8a  64a100000000         mov eax, dword ptr fs:[0]
// 0045bc90  50                   push eax
// 0045bc91  64892500000000       mov dword ptr fs:[0], esp
// 0045bc98  83ec20               sub esp, 0x20
// 0045bc9b  53                   push ebx
// 0045bc9c  56                   push esi
// 0045bc9d  8bf1                 mov esi, ecx
// 0045bc9f  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bca5  57                   push edi
// 0045bca6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0045bca9  8975ec               mov dword ptr [ebp - 0x14], esi
// 0045bcac  e82f100200           call 0x47cce0
// 0045bcb1  8b4670               mov eax, dword ptr [esi + 0x70]
// 0045bcb4  83ec08               sub esp, 8
// 0045bcb7  8bcc                 mov ecx, esp
// 0045bcb9  8901                 mov dword ptr [ecx], eax
// 0045bcbb  8b4674               mov eax, dword ptr [esi + 0x74]
// 0045bcbe  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0045bcc5  8965e8               mov dword ptr [ebp - 0x18], esp
// 0045bcc8  894104               mov dword ptr [ecx + 4], eax
// 0045bccb  85c0                 test eax, eax
// 0045bccd  740c                 je 0x45bcdb
// 0045bccf  83c004               add eax, 4
// 0045bcd2  b901000000           mov ecx, 1
// 0045bcd7  f00fc108             lock xadd dword ptr [eax], ecx
// 0045bcdb  8d4dd4               lea ecx, [ebp - 0x2c]
// 0045bcde  e85d5efbff           call 0x411b40
// 0045bce3  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0045bce9  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0045bcef  8b11                 mov edx, dword ptr [ecx]
// 0045bcf1  50                   push eax
// 0045bcf2  8b4204               mov eax, dword ptr [edx + 4]
// 0045bcf5  b301                 mov bl, 1
// 0045bcf7  885dfc               mov byte ptr [ebp - 4], bl
// 0045bcfa  ffd0                 call eax
// 0045bcfc  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0045bd02  8b11                 mov edx, dword ptr [ecx]
// 0045bd04  8b421c               mov eax, dword ptr [edx + 0x1c]
// 0045bd07  ffd0                 call eax
// 0045bd09  8bf8                 mov edi, eax
// 0045bd0b  8bc8                 mov ecx, eax
// 0045bd0d  897de8               mov dword ptr [ebp - 0x18], edi
// 0045bd10  e8db5f0b00           call 0x511cf0
// 0045bd15  8b86b4000000         mov eax, dword ptr [esi + 0xb4]
// 0045bd1b  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045bd1e  50                   push eax
// 0045bd1f  c645fc02             mov byte ptr [ebp - 4], 2
// 0045bd23  e898e91100           call 0x57a6c0
// 0045bd28  807d0800             cmp byte ptr [ebp + 8], 0
// 0045bd2c  7429                 je 0x45bd57
// 0045bd2e  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bd34  e867160200           call 0x47d3a0
// 0045bd39  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 0045bd3f  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045bd42  8d4658               lea eax, [esi + 0x58]
// 0045bd45  50                   push eax
// 0045bd46  52                   push edx
// 0045bd47  e864e41100           call 0x57a1b0
// 0045bd4c  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bd52  e809160200           call 0x47d360
// 0045bd57  8bcf                 mov ecx, edi
// 0045bd59  885dfc               mov byte ptr [ebp - 4], bl
// 0045bd5c  e88f600b00           call 0x511df0
// 0045bd61  8d4dd4               lea ecx, [ebp - 0x2c]
// 0045bd64  c645fc00             mov byte ptr [ebp - 4], 0
// 0045bd68  e853b61100           call 0x5773c0
// 0045bd6d  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0045bd74  eb3b                 jmp 0x45bdb1

// from server: 97% by EspClaude
// from server: 89% by king_originala
// roc 2008-06 0045bc80  unit: CRobloxWnd  size: 246 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045bc80
//
// 0045bc80  55                   push ebp
// 0045bc81  8bec                 mov ebp, esp
// 0045bc83  6aff                 push -1
// 0045bc85  68e82b7c00           push 0x7c2be8
// 0045bc8a  64a100000000         mov eax, dword ptr fs:[0]
// 0045bc90  50                   push eax
// 0045bc91  64892500000000       mov dword ptr fs:[0], esp
// 0045bc98  83ec20               sub esp, 0x20
// 0045bc9b  53                   push ebx
// 0045bc9c  56                   push esi
// 0045bc9d  8bf1                 mov esi, ecx
// 0045bc9f  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bca5  57                   push edi
// 0045bca6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0045bca9  8975ec               mov dword ptr [ebp - 0x14], esi
// 0045bcac  e82f100200           call 0x47cce0
// 0045bcb1  8b4670               mov eax, dword ptr [esi + 0x70]
// 0045bcb4  83ec08               sub esp, 8
// 0045bcb7  8bcc                 mov ecx, esp
// 0045bcb9  8901                 mov dword ptr [ecx], eax
// 0045bcbb  8b4674               mov eax, dword ptr [esi + 0x74]
// 0045bcbe  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0045bcc5  8965e8               mov dword ptr [ebp - 0x18], esp
// 0045bcc8  894104               mov dword ptr [ecx + 4], eax
// 0045bccb  85c0                 test eax, eax
// 0045bccd  740c                 je 0x45bcdb
// 0045bccf  83c004               add eax, 4
// 0045bcd2  b901000000           mov ecx, 1
// 0045bcd7  f00fc108             lock xadd dword ptr [eax], ecx
// 0045bcdb  8d4dd4               lea ecx, [ebp - 0x2c]
// 0045bcde  e85d5efbff           call 0x411b40
// 0045bce3  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0045bce9  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0045bcef  8b11                 mov edx, dword ptr [ecx]
// 0045bcf1  50                   push eax
// 0045bcf2  8b4204               mov eax, dword ptr [edx + 4]
// 0045bcf5  b301                 mov bl, 1
// 0045bcf7  885dfc               mov byte ptr [ebp - 4], bl
// 0045bcfa  ffd0                 call eax
// 0045bcfc  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0045bd02  8b11                 mov edx, dword ptr [ecx]
// 0045bd04  8b421c               mov eax, dword ptr [edx + 0x1c]
// 0045bd07  ffd0                 call eax
// 0045bd09  8bf8                 mov edi, eax
// 0045bd0b  8bc8                 mov ecx, eax
// 0045bd0d  897de8               mov dword ptr [ebp - 0x18], edi
// 0045bd10  e8db5f0b00           call 0x511cf0
// 0045bd15  8b86b4000000         mov eax, dword ptr [esi + 0xb4]
// 0045bd1b  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045bd1e  50                   push eax
// 0045bd1f  c645fc02             mov byte ptr [ebp - 4], 2
// 0045bd23  e898e91100           call 0x57a6c0
// 0045bd28  807d0800             cmp byte ptr [ebp + 8], 0
// 0045bd2c  7429                 je 0x45bd57
// 0045bd2e  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bd34  e867160200           call 0x47d3a0
// 0045bd39  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 0045bd3f  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045bd42  8d4658               lea eax, [esi + 0x58]
// 0045bd45  50                   push eax
// 0045bd46  52                   push edx
// 0045bd47  e864e41100           call 0x57a1b0
// 0045bd4c  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0045bd52  e809160200           call 0x47d360
// 0045bd57  8bcf                 mov ecx, edi
// 0045bd59  885dfc               mov byte ptr [ebp - 4], bl
// 0045bd5c  e88f600b00           call 0x511df0
// 0045bd61  8d4dd4               lea ecx, [ebp - 0x2c]
// 0045bd64  c645fc00             mov byte ptr [ebp - 4], 0
// 0045bd68  e853b61100           call 0x5773c0
// 0045bd6d  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0045bd74  eb3b                 jmp 0x45bdb1

#include <exception>

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ReferenceCount {
    long reserved;
    volatile long count;
};

struct Payload;

struct Object {
    void apply(Payload*);
    void update(Payload*, void*);
};

struct SharedObject {
    Object* object;
    ReferenceCount* reference;
    SharedObject(const SharedObject&);
    Object* operator->() const { return object; }
    ~SharedObject();
};

__forceinline SharedObject::SharedObject(const SharedObject& other)
    : object(other.object), reference(other.reference) {
    if (reference) {
        volatile long* count = &reference->count;
        _InterlockedExchangeAdd(count, 1);
    }
}

struct Context {
    void begin();
    void prepare();
    void finish();
};

struct Mutex {
    void lock();
    void unlock();
};

struct Interface {
    virtual void slot0() = 0;
    virtual void setContext(Context*) = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual Mutex* getMutex() = 0;
};

struct LocalScope {
    char storage[12];
    LocalScope(SharedObject);
    ~LocalScope();
};

struct MutexScope {
    Mutex* mutex;
    explicit MutexScope(Mutex*);
    ~MutexScope();
};

__forceinline MutexScope::MutexScope(Mutex* value) : mutex(value) {
    value->lock();
}

__forceinline MutexScope::~MutexScope() {
    mutex->unlock();
}

struct StandardOut {
    void print(int, const std::exception&);
};

struct OutPtr {
    StandardOut* px;
    void* pn;
    ~OutPtr();
    StandardOut* operator->() const { return px; }
};

OutPtr __cdecl singleton();

struct Thing {
    void method(void*);
};

struct CRobloxWnd {
    char reserved0[0x54];
    char field54[4];
    char state[0x18];
    SharedObject object;
    Thing* field78;
    char reserved1[0x30];
    Context* context;
    Interface* interfaceObject;
    Payload* payload;
    void run(bool);
};

void CRobloxWnd::run(bool updateState) {
    context->begin();
    try {
        LocalScope scope(object);
        Interface* i = interfaceObject; Context* c = context;
        i->setContext(c);
        MutexScope lock(interfaceObject->getMutex());
        Payload* p = payload; object->apply(p);
        if (updateState) {
            context->prepare();
            void* st = state; Payload* q = payload; object->update(q, st);
            context->finish();
        }
    } catch (std::exception& e) {
        singleton()->print(3, e);
    }
    if (field78)
        field78->method(field54);
    context->finish();
}
