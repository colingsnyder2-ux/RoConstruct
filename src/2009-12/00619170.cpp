// from server: 100% by auto
// roc 2009-12 00619170  unit: seg_00610000  size: 843 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00619170
//
// 00619170  83ec7c               sub esp, 0x7c
// 00619173  b804000000           mov eax, 4
// 00619178  55                   push ebp
// 00619179  33ed                 xor ebp, ebp
// 0061917b  ba01000000           mov edx, 1
// 00619180  56                   push esi
// 00619181  8bb42488000000       mov esi, dword ptr [esp + 0x88]
// 00619188  0196e4000000         add dword ptr [esi + 0xe4], edx
// 0061918e  b902000000           mov ecx, 2
// 00619193  89442434             mov dword ptr [esp + 0x34], eax
// 00619197  8944241c             mov dword ptr [esp + 0x1c], eax
// 0061919b  89442420             mov dword ptr [esp + 0x20], eax
// 0061919f  89442470             mov dword ptr [esp + 0x70], eax
// 006191a3  89442458             mov dword ptr [esp + 0x58], eax
// 006191a7  8944245c             mov dword ptr [esp + 0x5c], eax
// 006191ab  8b86e4000000         mov eax, dword ptr [esi + 0xe4]
// 006191b1  57                   push edi
// 006191b2  bf08000000           mov edi, 8
// 006191b7  896c2434             mov dword ptr [esp + 0x34], ebp
// 006191bb  896c243c             mov dword ptr [esp + 0x3c], ebp
// 006191bf  894c2440             mov dword ptr [esp + 0x40], ecx
// 006191c3  896c2444             mov dword ptr [esp + 0x44], ebp
// 006191c7  89542448             mov dword ptr [esp + 0x48], edx
// 006191cb  896c244c             mov dword ptr [esp + 0x4c], ebp
// 006191cf  897c2418             mov dword ptr [esp + 0x18], edi
// 006191d3  897c241c             mov dword ptr [esp + 0x1c], edi
// 006191d7  894c2428             mov dword ptr [esp + 0x28], ecx
// 006191db  894c242c             mov dword ptr [esp + 0x2c], ecx
// 006191df  89542430             mov dword ptr [esp + 0x30], edx
// 006191e3  896c246c             mov dword ptr [esp + 0x6c], ebp
// 006191e7  896c2470             mov dword ptr [esp + 0x70], ebp
// 006191eb  896c2478             mov dword ptr [esp + 0x78], ebp
// 006191ef  894c247c             mov dword ptr [esp + 0x7c], ecx
// 006191f3  89ac2480000000       mov dword ptr [esp + 0x80], ebp
// 006191fa  89942484000000       mov dword ptr [esp + 0x84], edx
// 00619201  897c2450             mov dword ptr [esp + 0x50], edi
// 00619205  897c2454             mov dword ptr [esp + 0x54], edi
// 00619209  897c2458             mov dword ptr [esp + 0x58], edi
// 0061920d  894c2464             mov dword ptr [esp + 0x64], ecx
// 00619211  894c2468             mov dword ptr [esp + 0x68], ecx
// 00619215  3b86d0000000         cmp eax, dword ptr [esi + 0xd0]
// 0061921b  0f8277020000         jb 0x619498
// 00619221  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 00619228  53                   push ebx
// 00619229  0f84c5000000         je 0x6192f4
// 0061922f  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00619235  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0061923b  03c2                 add eax, edx
// 0061923d  50                   push eax
// 0061923e  55                   push ebp
// 0061923f  51                   push ecx
// 00619240  56                   push esi
// 00619241  89aee4000000         mov dword ptr [esi + 0xe4], ebp
// 00619247  e8c479ffff           call 0x610c10
// 0061924c  83c410               add esp, 0x10
// 0061924f  eb05                 jmp 0x619256
// 00619251  bf08000000           mov edi, 8
// 00619256  fe8624010000         inc byte ptr [esi + 0x124]
// 0061925c  8a9e24010000         mov bl, byte ptr [esi + 0x124]
// 00619262  80fb07               cmp bl, 7
// 00619265  0f8384000000         jae 0x6192ef
// 0061926b  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 00619271  0fb6cb               movzx ecx, bl
// 00619274  03c9                 add ecx, ecx
// 00619276  03c9                 add ecx, ecx
// 00619278  2b540c38             sub edx, dword ptr [esp + ecx + 0x38]
// 0061927c  8b7c0c1c             mov edi, dword ptr [esp + ecx + 0x1c]
// 00619280  8d443aff             lea eax, [edx + edi - 1]
// 00619284  33d2                 xor edx, edx
// 00619286  f7f7                 div edi
// 00619288  8bf8                 mov edi, eax
// 0061928a  8a8629010000         mov al, byte ptr [esi + 0x129]
// 00619290  3c08                 cmp al, 8
// 00619292  89bee0000000         mov dword ptr [esi + 0xe0], edi
// 00619298  0fb6c0               movzx eax, al
// 0061929b  7208                 jb 0x6192a5
// 0061929d  c1e803               shr eax, 3
// 006192a0  0fafc7               imul eax, edi
// 006192a3  eb09                 jmp 0x6192ae
// 006192a5  0fafc7               imul eax, edi
// 006192a8  83c007               add eax, 7
// 006192ab  c1e803               shr eax, 3
// 006192ae  40                   inc eax
// 006192af  f6467002             test byte ptr [esi + 0x70], 2
// 006192b3  8986dc000000         mov dword ptr [esi + 0xdc], eax
// 006192b9  7526                 jne 0x6192e1
// 006192bb  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 006192c1  2b440c70             sub eax, dword ptr [esp + ecx + 0x70]
// 006192c5  8b6c0c54             mov ebp, dword ptr [esp + ecx + 0x54]
// 006192c9  8d4428ff             lea eax, [eax + ebp - 1]
// 006192cd  33d2                 xor edx, edx
// 006192cf  f7f5                 div ebp
// 006192d1  33ed                 xor ebp, ebp
// 006192d3  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 006192d9  85ff                 test edi, edi
// 006192db  0f8470ffffff         je 0x619251
// 006192e1  80fb07               cmp bl, 7
// 006192e4  0f82ad010000         jb 0x619497
// 006192ea  bf08000000           mov edi, 8
// 006192ef  ba01000000           mov edx, 1
// 006192f4  f6466c20             test byte ptr [esi + 0x6c], 0x20
// 006192f8  0f856f010000         jne 0x61946d
// 006192fe  8d4c2413             lea ecx, [esp + 0x13]
// 00619302  c644241449           mov byte ptr [esp + 0x14], 0x49
// 00619307  c644241544           mov byte ptr [esp + 0x15], 0x44
// 0061930c  c644241641           mov byte ptr [esp + 0x16], 0x41
// 00619311  c644241754           mov byte ptr [esp + 0x17], 0x54
// 00619316  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0061931a  898e80000000         mov dword ptr [esi + 0x80], ecx
// 00619320  899684000000         mov dword ptr [esi + 0x84], edx
// 00619326  396e78               cmp dword ptr [esi + 0x78], ebp
// 00619329  0f85e7000000         jne 0x619416
// 0061932f  39ae0c010000         cmp dword ptr [esi + 0x10c], ebp
// 00619335  0f8598000000         jne 0x6193d3
// 0061933b  8dae1c010000         lea ebp, [esi + 0x11c]
// 00619341  6a00                 push 0
// 00619343  56                   push esi
// 00619344  e8a7d8ffff           call 0x616bf0
// 00619349  6a04                 push 4
// 0061934b  8d542420             lea edx, [esp + 0x20]
// 0061934f  52                   push edx
// 00619350  56                   push esi
// 00619351  e83a17ffff           call 0x60aa90
// 00619356  8b442428             mov eax, dword ptr [esp + 0x28]
// 0061935a  0fb64c242a           movzx ecx, byte ptr [esp + 0x2a]
// 0061935f  0fb654242b           movzx edx, byte ptr [esp + 0x2b]
// 00619364  0fb6f8               movzx edi, al
// 00619367  c1e708               shl edi, 8
// 0061936a  0fb6c4               movzx eax, ah
// 0061936d  03f8                 add edi, eax
// 0061936f  c1e708               shl edi, 8
// 00619372  03f9                 add edi, ecx
// 00619374  c1e708               shl edi, 8
// 00619377  03fa                 add edi, edx
// 00619379  83c414               add esp, 0x14
// 0061937c  81ffffffff7f         cmp edi, 0x7fffffff
// 00619382  760e                 jbe 0x619392
// 00619384  68d88d9c00           push 0x9c8dd8
// 00619389  56                   push esi
// 0061938a  e8016effff           call 0x610190
// 0061938f  83c408               add esp, 8
// 00619392  56                   push esi
// 00619393  89be0c010000         mov dword ptr [esi + 0x10c], edi
// 00619399  e8b2a2feff           call 0x603650
// 0061939e  6a04                 push 4
// 006193a0  55                   push ebp
// 006193a1  56                   push esi
// 006193a2  e8e916ffff           call 0x60aa90
// 006193a7  6a04                 push 4
// 006193a9  55                   push ebp
// 006193aa  56                   push esi
// 006193ab  e8c0a2feff           call 0x603670
// 006193b0  83c41c               add esp, 0x1c
// 006193b3  395d00               cmp dword ptr [ebp], ebx
// 006193b6  740e                 je 0x6193c6
// 006193b8  68744e9c00           push 0x9c4e74
// 006193bd  56                   push esi
// 006193be  e8cd6dffff           call 0x610190
// 006193c3  83c408               add esp, 8
// 006193c6  83be0c01000000       cmp dword ptr [esi + 0x10c], 0
// 006193cd  0f846effffff         je 0x619341
// 006193d3  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 006193d9  8b8e0c010000         mov ecx, dword ptr [esi + 0x10c]
// 006193df  8bbeac000000         mov edi, dword ptr [esi + 0xac]
// 006193e5  894678               mov dword ptr [esi + 0x78], eax
// 006193e8  897e74               mov dword ptr [esi + 0x74], edi
// 006193eb  3bc1                 cmp eax, ecx
// 006193ed  7603                 jbe 0x6193f2
// 006193ef  894e78               mov dword ptr [esi + 0x78], ecx
// 006193f2  8b6e78               mov ebp, dword ptr [esi + 0x78]
// 006193f5  55                   push ebp
// 006193f6  57                   push edi
// 006193f7  56                   push esi
// 006193f8  e89316ffff           call 0x60aa90
// 006193fd  55                   push ebp
// 006193fe  57                   push edi
// 006193ff  56                   push esi
// 00619400  e86ba2feff           call 0x603670
// 00619405  8b4678               mov eax, dword ptr [esi + 0x78]
// 00619408  29860c010000         sub dword ptr [esi + 0x10c], eax
// 0061940e  83c418               add esp, 0x18
// 00619411  33ed                 xor ebp, ebp
// 00619413  8d7d08               lea edi, [ebp + 8]
// 00619416  8d4674               lea eax, [esi + 0x74]
// 00619419  6a01                 push 1
// 0061941b  50                   push eax
// 0061941c  e8cf97ffff           call 0x612bf0
// 00619421  83c408               add esp, 8
// 00619424  83f801               cmp eax, 1
// 00619427  7476                 je 0x61949f
// 00619429  3bc5                 cmp eax, ebp
// 0061942b  7419                 je 0x619446
// 0061942d  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 00619433  3bc5                 cmp eax, ebp
// 00619435  7505                 jne 0x61943c
// 00619437  b8ac9c9c00           mov eax, 0x9c9cac
// 0061943c  50                   push eax
// 0061943d  56                   push esi
// 0061943e  e84d6dffff           call 0x610190
// 00619443  83c408               add esp, 8
// 00619446  39ae84000000         cmp dword ptr [esi + 0x84], ebp
// 0061944c  0f85d4feffff         jne 0x619326
// 00619452  68949c9c00           push 0x9c9c94
// 00619457  56                   push esi
// 00619458  e8e36dffff           call 0x610240
// 0061945d  83c408               add esp, 8
// 00619460  097e68               or dword ptr [esi + 0x68], edi
// 00619463  834e6c20             or dword ptr [esi + 0x6c], 0x20
// 00619467  89ae84000000         mov dword ptr [esi + 0x84], ebp
// 0061946d  39ae0c010000         cmp dword ptr [esi + 0x10c], ebp
// 00619473  7505                 jne 0x61947a
// 00619475  396e78               cmp dword ptr [esi + 0x78], ebp
// 00619478  740e                 je 0x619488
// 0061947a  687c9c9c00           push 0x9c9c7c
// 0061947f  56                   push esi
// 00619480  e8bb6dffff           call 0x610240
// 00619485  83c408               add esp, 8
// 00619488  8d4e74               lea ecx, [esi + 0x74]
// 0061948b  51                   push ecx
// 0061948c  e82f95ffff           call 0x6129c0
// 00619491  83c404               add esp, 4
// 00619494  097e68               or dword ptr [esi + 0x68], edi
// 00619497  5b                   pop ebx
// 00619498  5f                   pop edi
// 00619499  5e                   pop esi
// 0061949a  5d                   pop ebp
// 0061949b  83c47c               add esp, 0x7c
// 0061949e  c3                   ret 
// 0061949f  39ae84000000         cmp dword ptr [esi + 0x84], ebp
// 006194a5  740d                 je 0x6194b4
// 006194a7  396e78               cmp dword ptr [esi + 0x78], ebp
// 006194aa  7508                 jne 0x6194b4
// 006194ac  39ae0c010000         cmp dword ptr [esi + 0x10c], ebp
// 006194b2  74ac                 je 0x619460
// 006194b4  68484e9c00           push 0x9c4e48
// 006194b9  eb9c                 jmp 0x619457
// library libpng-1.2.22/pngrutil.c (function _png_read_finish_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrutil.c
