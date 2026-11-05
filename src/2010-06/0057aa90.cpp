// from server: 100% by auto
// roc 2010-06 0057aa90  unit: seg_00570000  size: 843 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0057aa90
//
// 0057aa90  83ec7c               sub esp, 0x7c
// 0057aa93  b804000000           mov eax, 4
// 0057aa98  55                   push ebp
// 0057aa99  33ed                 xor ebp, ebp
// 0057aa9b  ba01000000           mov edx, 1
// 0057aaa0  56                   push esi
// 0057aaa1  8bb42488000000       mov esi, dword ptr [esp + 0x88]
// 0057aaa8  0196e4000000         add dword ptr [esi + 0xe4], edx
// 0057aaae  b902000000           mov ecx, 2
// 0057aab3  89442434             mov dword ptr [esp + 0x34], eax
// 0057aab7  8944241c             mov dword ptr [esp + 0x1c], eax
// 0057aabb  89442420             mov dword ptr [esp + 0x20], eax
// 0057aabf  89442470             mov dword ptr [esp + 0x70], eax
// 0057aac3  89442458             mov dword ptr [esp + 0x58], eax
// 0057aac7  8944245c             mov dword ptr [esp + 0x5c], eax
// 0057aacb  8b86e4000000         mov eax, dword ptr [esi + 0xe4]
// 0057aad1  57                   push edi
// 0057aad2  bf08000000           mov edi, 8
// 0057aad7  896c2434             mov dword ptr [esp + 0x34], ebp
// 0057aadb  896c243c             mov dword ptr [esp + 0x3c], ebp
// 0057aadf  894c2440             mov dword ptr [esp + 0x40], ecx
// 0057aae3  896c2444             mov dword ptr [esp + 0x44], ebp
// 0057aae7  89542448             mov dword ptr [esp + 0x48], edx
// 0057aaeb  896c244c             mov dword ptr [esp + 0x4c], ebp
// 0057aaef  897c2418             mov dword ptr [esp + 0x18], edi
// 0057aaf3  897c241c             mov dword ptr [esp + 0x1c], edi
// 0057aaf7  894c2428             mov dword ptr [esp + 0x28], ecx
// 0057aafb  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0057aaff  89542430             mov dword ptr [esp + 0x30], edx
// 0057ab03  896c246c             mov dword ptr [esp + 0x6c], ebp
// 0057ab07  896c2470             mov dword ptr [esp + 0x70], ebp
// 0057ab0b  896c2478             mov dword ptr [esp + 0x78], ebp
// 0057ab0f  894c247c             mov dword ptr [esp + 0x7c], ecx
// 0057ab13  89ac2480000000       mov dword ptr [esp + 0x80], ebp
// 0057ab1a  89942484000000       mov dword ptr [esp + 0x84], edx
// 0057ab21  897c2450             mov dword ptr [esp + 0x50], edi
// 0057ab25  897c2454             mov dword ptr [esp + 0x54], edi
// 0057ab29  897c2458             mov dword ptr [esp + 0x58], edi
// 0057ab2d  894c2464             mov dword ptr [esp + 0x64], ecx
// 0057ab31  894c2468             mov dword ptr [esp + 0x68], ecx
// 0057ab35  3b86d0000000         cmp eax, dword ptr [esi + 0xd0]
// 0057ab3b  0f8277020000         jb 0x57adb8
// 0057ab41  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 0057ab48  53                   push ebx
// 0057ab49  0f84c5000000         je 0x57ac14
// 0057ab4f  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 0057ab55  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0057ab5b  03c2                 add eax, edx
// 0057ab5d  50                   push eax
// 0057ab5e  55                   push ebp
// 0057ab5f  51                   push ecx
// 0057ab60  56                   push esi
// 0057ab61  89aee4000000         mov dword ptr [esi + 0xe4], ebp
// 0057ab67  e8c479ffff           call 0x572530
// 0057ab6c  83c410               add esp, 0x10
// 0057ab6f  eb05                 jmp 0x57ab76
// 0057ab71  bf08000000           mov edi, 8
// 0057ab76  fe8624010000         inc byte ptr [esi + 0x124]
// 0057ab7c  8a9e24010000         mov bl, byte ptr [esi + 0x124]
// 0057ab82  80fb07               cmp bl, 7
// 0057ab85  0f8384000000         jae 0x57ac0f
// 0057ab8b  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 0057ab91  0fb6cb               movzx ecx, bl
// 0057ab94  03c9                 add ecx, ecx
// 0057ab96  03c9                 add ecx, ecx
// 0057ab98  2b540c38             sub edx, dword ptr [esp + ecx + 0x38]
// 0057ab9c  8b7c0c1c             mov edi, dword ptr [esp + ecx + 0x1c]
// 0057aba0  8d443aff             lea eax, [edx + edi - 1]
// 0057aba4  33d2                 xor edx, edx
// 0057aba6  f7f7                 div edi
// 0057aba8  8bf8                 mov edi, eax
// 0057abaa  8a8629010000         mov al, byte ptr [esi + 0x129]
// 0057abb0  3c08                 cmp al, 8
// 0057abb2  89bee0000000         mov dword ptr [esi + 0xe0], edi
// 0057abb8  0fb6c0               movzx eax, al
// 0057abbb  7208                 jb 0x57abc5
// 0057abbd  c1e803               shr eax, 3
// 0057abc0  0fafc7               imul eax, edi
// 0057abc3  eb09                 jmp 0x57abce
// 0057abc5  0fafc7               imul eax, edi
// 0057abc8  83c007               add eax, 7
// 0057abcb  c1e803               shr eax, 3
// 0057abce  40                   inc eax
// 0057abcf  f6467002             test byte ptr [esi + 0x70], 2
// 0057abd3  8986dc000000         mov dword ptr [esi + 0xdc], eax
// 0057abd9  7526                 jne 0x57ac01
// 0057abdb  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 0057abe1  2b440c70             sub eax, dword ptr [esp + ecx + 0x70]
// 0057abe5  8b6c0c54             mov ebp, dword ptr [esp + ecx + 0x54]
// 0057abe9  8d4428ff             lea eax, [eax + ebp - 1]
// 0057abed  33d2                 xor edx, edx
// 0057abef  f7f5                 div ebp
// 0057abf1  33ed                 xor ebp, ebp
// 0057abf3  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0057abf9  85ff                 test edi, edi
// 0057abfb  0f8470ffffff         je 0x57ab71
// 0057ac01  80fb07               cmp bl, 7
// 0057ac04  0f82ad010000         jb 0x57adb7
// 0057ac0a  bf08000000           mov edi, 8
// 0057ac0f  ba01000000           mov edx, 1
// 0057ac14  f6466c20             test byte ptr [esi + 0x6c], 0x20
// 0057ac18  0f856f010000         jne 0x57ad8d
// 0057ac1e  8d4c2413             lea ecx, [esp + 0x13]
// 0057ac22  c644241449           mov byte ptr [esp + 0x14], 0x49
// 0057ac27  c644241544           mov byte ptr [esp + 0x15], 0x44
// 0057ac2c  c644241641           mov byte ptr [esp + 0x16], 0x41
// 0057ac31  c644241754           mov byte ptr [esp + 0x17], 0x54
// 0057ac36  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0057ac3a  898e80000000         mov dword ptr [esi + 0x80], ecx
// 0057ac40  899684000000         mov dword ptr [esi + 0x84], edx
// 0057ac46  396e78               cmp dword ptr [esi + 0x78], ebp
// 0057ac49  0f85e7000000         jne 0x57ad36
// 0057ac4f  39ae0c010000         cmp dword ptr [esi + 0x10c], ebp
// 0057ac55  0f8598000000         jne 0x57acf3
// 0057ac5b  8dae1c010000         lea ebp, [esi + 0x11c]
// 0057ac61  6a00                 push 0
// 0057ac63  56                   push esi
// 0057ac64  e8a7d8ffff           call 0x578510
// 0057ac69  6a04                 push 4
// 0057ac6b  8d542420             lea edx, [esp + 0x20]
// 0057ac6f  52                   push edx
// 0057ac70  56                   push esi
// 0057ac71  e89a17ffff           call 0x56c410
// 0057ac76  8b442428             mov eax, dword ptr [esp + 0x28]
// 0057ac7a  0fb64c242a           movzx ecx, byte ptr [esp + 0x2a]
// 0057ac7f  0fb654242b           movzx edx, byte ptr [esp + 0x2b]
// 0057ac84  0fb6f8               movzx edi, al
// 0057ac87  c1e708               shl edi, 8
// 0057ac8a  0fb6c4               movzx eax, ah
// 0057ac8d  03f8                 add edi, eax
// 0057ac8f  c1e708               shl edi, 8
// 0057ac92  03f9                 add edi, ecx
// 0057ac94  c1e708               shl edi, 8
// 0057ac97  03fa                 add edi, edx
// 0057ac99  83c414               add esp, 0x14
// 0057ac9c  81ffffffff7f         cmp edi, 0x7fffffff
// 0057aca2  760e                 jbe 0x57acb2
// 0057aca4  68506ba200           push 0xa26b50
// 0057aca9  56                   push esi
// 0057acaa  e8016effff           call 0x571ab0
// 0057acaf  83c408               add esp, 8
// 0057acb2  56                   push esi
// 0057acb3  89be0c010000         mov dword ptr [esi + 0x10c], edi
// 0057acb9  e802a3feff           call 0x564fc0
// 0057acbe  6a04                 push 4
// 0057acc0  55                   push ebp
// 0057acc1  56                   push esi
// 0057acc2  e84917ffff           call 0x56c410
// 0057acc7  6a04                 push 4
// 0057acc9  55                   push ebp
// 0057acca  56                   push esi
// 0057accb  e810a3feff           call 0x564fe0
// 0057acd0  83c41c               add esp, 0x1c
// 0057acd3  395d00               cmp dword ptr [ebp], ebx
// 0057acd6  740e                 je 0x57ace6
// 0057acd8  68d42ba200           push 0xa22bd4
// 0057acdd  56                   push esi
// 0057acde  e8cd6dffff           call 0x571ab0
// 0057ace3  83c408               add esp, 8
// 0057ace6  83be0c01000000       cmp dword ptr [esi + 0x10c], 0
// 0057aced  0f846effffff         je 0x57ac61
// 0057acf3  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0057acf9  8b8e0c010000         mov ecx, dword ptr [esi + 0x10c]
// 0057acff  8bbeac000000         mov edi, dword ptr [esi + 0xac]
// 0057ad05  894678               mov dword ptr [esi + 0x78], eax
// 0057ad08  897e74               mov dword ptr [esi + 0x74], edi
// 0057ad0b  3bc1                 cmp eax, ecx
// 0057ad0d  7603                 jbe 0x57ad12
// 0057ad0f  894e78               mov dword ptr [esi + 0x78], ecx
// 0057ad12  8b6e78               mov ebp, dword ptr [esi + 0x78]
// 0057ad15  55                   push ebp
// 0057ad16  57                   push edi
// 0057ad17  56                   push esi
// 0057ad18  e8f316ffff           call 0x56c410
// 0057ad1d  55                   push ebp
// 0057ad1e  57                   push edi
// 0057ad1f  56                   push esi
// 0057ad20  e8bba2feff           call 0x564fe0
// 0057ad25  8b4678               mov eax, dword ptr [esi + 0x78]
// 0057ad28  29860c010000         sub dword ptr [esi + 0x10c], eax
// 0057ad2e  83c418               add esp, 0x18
// 0057ad31  33ed                 xor ebp, ebp
// 0057ad33  8d7d08               lea edi, [ebp + 8]
// 0057ad36  8d4674               lea eax, [esi + 0x74]
// 0057ad39  6a01                 push 1
// 0057ad3b  50                   push eax
// 0057ad3c  e8cf97ffff           call 0x574510
// 0057ad41  83c408               add esp, 8
// 0057ad44  83f801               cmp eax, 1
// 0057ad47  7476                 je 0x57adbf
// 0057ad49  3bc5                 cmp eax, ebp
// 0057ad4b  7419                 je 0x57ad66
// 0057ad4d  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 0057ad53  3bc5                 cmp eax, ebp
// 0057ad55  7505                 jne 0x57ad5c
// 0057ad57  b8247aa200           mov eax, 0xa27a24
// 0057ad5c  50                   push eax
// 0057ad5d  56                   push esi
// 0057ad5e  e84d6dffff           call 0x571ab0
// 0057ad63  83c408               add esp, 8
// 0057ad66  39ae84000000         cmp dword ptr [esi + 0x84], ebp
// 0057ad6c  0f85d4feffff         jne 0x57ac46
// 0057ad72  680c7aa200           push 0xa27a0c
// 0057ad77  56                   push esi
// 0057ad78  e8e36dffff           call 0x571b60
// 0057ad7d  83c408               add esp, 8
// 0057ad80  097e68               or dword ptr [esi + 0x68], edi
// 0057ad83  834e6c20             or dword ptr [esi + 0x6c], 0x20
// 0057ad87  89ae84000000         mov dword ptr [esi + 0x84], ebp
// 0057ad8d  39ae0c010000         cmp dword ptr [esi + 0x10c], ebp
// 0057ad93  7505                 jne 0x57ad9a
// 0057ad95  396e78               cmp dword ptr [esi + 0x78], ebp
// 0057ad98  740e                 je 0x57ada8
// 0057ad9a  68f479a200           push 0xa279f4
// 0057ad9f  56                   push esi
// 0057ada0  e8bb6dffff           call 0x571b60
// 0057ada5  83c408               add esp, 8
// 0057ada8  8d4e74               lea ecx, [esi + 0x74]
// 0057adab  51                   push ecx
// 0057adac  e82f95ffff           call 0x5742e0
// 0057adb1  83c404               add esp, 4
// 0057adb4  097e68               or dword ptr [esi + 0x68], edi
// 0057adb7  5b                   pop ebx
// 0057adb8  5f                   pop edi
// 0057adb9  5e                   pop esi
// 0057adba  5d                   pop ebp
// 0057adbb  83c47c               add esp, 0x7c
// 0057adbe  c3                   ret 
// 0057adbf  39ae84000000         cmp dword ptr [esi + 0x84], ebp
// 0057adc5  740d                 je 0x57add4
// 0057adc7  396e78               cmp dword ptr [esi + 0x78], ebp
// 0057adca  7508                 jne 0x57add4
// 0057adcc  39ae0c010000         cmp dword ptr [esi + 0x10c], ebp
// 0057add2  74ac                 je 0x57ad80
// 0057add4  68a82ba200           push 0xa22ba8
// 0057add9  eb9c                 jmp 0x57ad77
// library libpng-1.2.22/pngrutil.c (function _png_read_finish_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrutil.c
