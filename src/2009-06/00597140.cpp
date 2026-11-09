// from server: 100% by auto
// roc 2009-06 00597140  unit: seg_00590000  size: 843 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00597140
//
// 00597140  83ec7c               sub esp, 0x7c
// 00597143  b804000000           mov eax, 4
// 00597148  55                   push ebp
// 00597149  33ed                 xor ebp, ebp
// 0059714b  ba01000000           mov edx, 1
// 00597150  56                   push esi
// 00597151  8bb42488000000       mov esi, dword ptr [esp + 0x88]
// 00597158  0196e4000000         add dword ptr [esi + 0xe4], edx
// 0059715e  b902000000           mov ecx, 2
// 00597163  89442434             mov dword ptr [esp + 0x34], eax
// 00597167  8944241c             mov dword ptr [esp + 0x1c], eax
// 0059716b  89442420             mov dword ptr [esp + 0x20], eax
// 0059716f  89442470             mov dword ptr [esp + 0x70], eax
// 00597173  89442458             mov dword ptr [esp + 0x58], eax
// 00597177  8944245c             mov dword ptr [esp + 0x5c], eax
// 0059717b  8b86e4000000         mov eax, dword ptr [esi + 0xe4]
// 00597181  57                   push edi
// 00597182  bf08000000           mov edi, 8
// 00597187  896c2434             mov dword ptr [esp + 0x34], ebp
// 0059718b  896c243c             mov dword ptr [esp + 0x3c], ebp
// 0059718f  894c2440             mov dword ptr [esp + 0x40], ecx
// 00597193  896c2444             mov dword ptr [esp + 0x44], ebp
// 00597197  89542448             mov dword ptr [esp + 0x48], edx
// 0059719b  896c244c             mov dword ptr [esp + 0x4c], ebp
// 0059719f  897c2418             mov dword ptr [esp + 0x18], edi
// 005971a3  897c241c             mov dword ptr [esp + 0x1c], edi
// 005971a7  894c2428             mov dword ptr [esp + 0x28], ecx
// 005971ab  894c242c             mov dword ptr [esp + 0x2c], ecx
// 005971af  89542430             mov dword ptr [esp + 0x30], edx
// 005971b3  896c246c             mov dword ptr [esp + 0x6c], ebp
// 005971b7  896c2470             mov dword ptr [esp + 0x70], ebp
// 005971bb  896c2478             mov dword ptr [esp + 0x78], ebp
// 005971bf  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005971c3  89ac2480000000       mov dword ptr [esp + 0x80], ebp
// 005971ca  89942484000000       mov dword ptr [esp + 0x84], edx
// 005971d1  897c2450             mov dword ptr [esp + 0x50], edi
// 005971d5  897c2454             mov dword ptr [esp + 0x54], edi
// 005971d9  897c2458             mov dword ptr [esp + 0x58], edi
// 005971dd  894c2464             mov dword ptr [esp + 0x64], ecx
// 005971e1  894c2468             mov dword ptr [esp + 0x68], ecx
// 005971e5  3b86d0000000         cmp eax, dword ptr [esi + 0xd0]
// 005971eb  0f8277020000         jb 0x597468
// 005971f1  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 005971f8  53                   push ebx
// 005971f9  0f84c5000000         je 0x5972c4
// 005971ff  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00597205  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0059720b  03c2                 add eax, edx
// 0059720d  50                   push eax
// 0059720e  55                   push ebp
// 0059720f  51                   push ecx
// 00597210  56                   push esi
// 00597211  89aee4000000         mov dword ptr [esi + 0xe4], ebp
// 00597217  e8c479ffff           call 0x58ebe0
// 0059721c  83c410               add esp, 0x10
// 0059721f  eb05                 jmp 0x597226
// 00597221  bf08000000           mov edi, 8
// 00597226  fe8624010000         inc byte ptr [esi + 0x124]
// 0059722c  8a9e24010000         mov bl, byte ptr [esi + 0x124]
// 00597232  80fb07               cmp bl, 7
// 00597235  0f8384000000         jae 0x5972bf
// 0059723b  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 00597241  0fb6cb               movzx ecx, bl
// 00597244  03c9                 add ecx, ecx
// 00597246  03c9                 add ecx, ecx
// 00597248  2b540c38             sub edx, dword ptr [esp + ecx + 0x38]
// 0059724c  8b7c0c1c             mov edi, dword ptr [esp + ecx + 0x1c]
// 00597250  8d443aff             lea eax, [edx + edi - 1]
// 00597254  33d2                 xor edx, edx
// 00597256  f7f7                 div edi
// 00597258  8bf8                 mov edi, eax
// 0059725a  8a8629010000         mov al, byte ptr [esi + 0x129]
// 00597260  3c08                 cmp al, 8
// 00597262  89bee0000000         mov dword ptr [esi + 0xe0], edi
// 00597268  0fb6c0               movzx eax, al
// 0059726b  7208                 jb 0x597275
// 0059726d  c1e803               shr eax, 3
// 00597270  0fafc7               imul eax, edi
// 00597273  eb09                 jmp 0x59727e
// 00597275  0fafc7               imul eax, edi
// 00597278  83c007               add eax, 7
// 0059727b  c1e803               shr eax, 3
// 0059727e  40                   inc eax
// 0059727f  f6467002             test byte ptr [esi + 0x70], 2
// 00597283  8986dc000000         mov dword ptr [esi + 0xdc], eax
// 00597289  7526                 jne 0x5972b1
// 0059728b  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 00597291  2b440c70             sub eax, dword ptr [esp + ecx + 0x70]
// 00597295  8b6c0c54             mov ebp, dword ptr [esp + ecx + 0x54]
// 00597299  8d4428ff             lea eax, [eax + ebp - 1]
// 0059729d  33d2                 xor edx, edx
// 0059729f  f7f5                 div ebp
// 005972a1  33ed                 xor ebp, ebp
// 005972a3  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 005972a9  85ff                 test edi, edi
// 005972ab  0f8470ffffff         je 0x597221
// 005972b1  80fb07               cmp bl, 7
// 005972b4  0f82ad010000         jb 0x597467
// 005972ba  bf08000000           mov edi, 8
// 005972bf  ba01000000           mov edx, 1
// 005972c4  f6466c20             test byte ptr [esi + 0x6c], 0x20
// 005972c8  0f856f010000         jne 0x59743d
// 005972ce  8d4c2413             lea ecx, [esp + 0x13]
// 005972d2  c644241449           mov byte ptr [esp + 0x14], 0x49
// 005972d7  c644241544           mov byte ptr [esp + 0x15], 0x44
// 005972dc  c644241641           mov byte ptr [esp + 0x16], 0x41
// 005972e1  c644241754           mov byte ptr [esp + 0x17], 0x54
// 005972e6  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005972ea  898e80000000         mov dword ptr [esi + 0x80], ecx
// 005972f0  899684000000         mov dword ptr [esi + 0x84], edx
// 005972f6  396e78               cmp dword ptr [esi + 0x78], ebp
// 005972f9  0f85e7000000         jne 0x5973e6
// 005972ff  39ae0c010000         cmp dword ptr [esi + 0x10c], ebp
// 00597305  0f8598000000         jne 0x5973a3
// 0059730b  8dae1c010000         lea ebp, [esi + 0x11c]
// 00597311  6a00                 push 0
// 00597313  56                   push esi
// 00597314  e8c7d8ffff           call 0x594be0
// 00597319  6a04                 push 4
// 0059731b  8d542420             lea edx, [esp + 0x20]
// 0059731f  52                   push edx
// 00597320  56                   push esi
// 00597321  e8da19ffff           call 0x588d00
// 00597326  8b442428             mov eax, dword ptr [esp + 0x28]
// 0059732a  0fb64c242a           movzx ecx, byte ptr [esp + 0x2a]
// 0059732f  0fb654242b           movzx edx, byte ptr [esp + 0x2b]
// 00597334  0fb6f8               movzx edi, al
// 00597337  c1e708               shl edi, 8
// 0059733a  0fb6c4               movzx eax, ah
// 0059733d  03f8                 add edi, eax
// 0059733f  c1e708               shl edi, 8
// 00597342  03f9                 add edi, ecx
// 00597344  c1e708               shl edi, 8
// 00597347  03fa                 add edi, edx
// 00597349  83c414               add esp, 0x14
// 0059734c  81ffffffff7f         cmp edi, 0x7fffffff
// 00597352  760e                 jbe 0x597362
// 00597354  68481f8d00           push 0x8d1f48
// 00597359  56                   push esi
// 0059735a  e8016effff           call 0x58e160
// 0059735f  83c408               add esp, 8
// 00597362  56                   push esi
// 00597363  89be0c010000         mov dword ptr [esi + 0x10c], edi
// 00597369  e832a5feff           call 0x5818a0
// 0059736e  6a04                 push 4
// 00597370  55                   push ebp
// 00597371  56                   push esi
// 00597372  e88919ffff           call 0x588d00
// 00597377  6a04                 push 4
// 00597379  55                   push ebp
// 0059737a  56                   push esi
// 0059737b  e840a5feff           call 0x5818c0
// 00597380  83c41c               add esp, 0x1c
// 00597383  395d00               cmp dword ptr [ebp], ebx
// 00597386  740e                 je 0x597396
// 00597388  68d4df8c00           push 0x8cdfd4
// 0059738d  56                   push esi
// 0059738e  e8cd6dffff           call 0x58e160
// 00597393  83c408               add esp, 8
// 00597396  83be0c01000000       cmp dword ptr [esi + 0x10c], 0
// 0059739d  0f846effffff         je 0x597311
// 005973a3  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 005973a9  8b8e0c010000         mov ecx, dword ptr [esi + 0x10c]
// 005973af  8bbeac000000         mov edi, dword ptr [esi + 0xac]
// 005973b5  894678               mov dword ptr [esi + 0x78], eax
// 005973b8  897e74               mov dword ptr [esi + 0x74], edi
// 005973bb  3bc1                 cmp eax, ecx
// 005973bd  7603                 jbe 0x5973c2
// 005973bf  894e78               mov dword ptr [esi + 0x78], ecx
// 005973c2  8b6e78               mov ebp, dword ptr [esi + 0x78]
// 005973c5  55                   push ebp
// 005973c6  57                   push edi
// 005973c7  56                   push esi
// 005973c8  e83319ffff           call 0x588d00
// 005973cd  55                   push ebp
// 005973ce  57                   push edi
// 005973cf  56                   push esi
// 005973d0  e8eba4feff           call 0x5818c0
// 005973d5  8b4678               mov eax, dword ptr [esi + 0x78]
// 005973d8  29860c010000         sub dword ptr [esi + 0x10c], eax
// 005973de  83c418               add esp, 0x18
// 005973e1  33ed                 xor ebp, ebp
// 005973e3  8d7d08               lea edi, [ebp + 8]
// 005973e6  8d4674               lea eax, [esi + 0x74]
// 005973e9  6a01                 push 1
// 005973eb  50                   push eax
// 005973ec  e8ef97ffff           call 0x590be0
// 005973f1  83c408               add esp, 8
// 005973f4  83f801               cmp eax, 1
// 005973f7  7476                 je 0x59746f
// 005973f9  3bc5                 cmp eax, ebp
// 005973fb  7419                 je 0x597416
// 005973fd  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 00597403  3bc5                 cmp eax, ebp
// 00597405  7505                 jne 0x59740c
// 00597407  b81c2e8d00           mov eax, 0x8d2e1c
// 0059740c  50                   push eax
// 0059740d  56                   push esi
// 0059740e  e84d6dffff           call 0x58e160
// 00597413  83c408               add esp, 8
// 00597416  39ae84000000         cmp dword ptr [esi + 0x84], ebp
// 0059741c  0f85d4feffff         jne 0x5972f6
// 00597422  68042e8d00           push 0x8d2e04
// 00597427  56                   push esi
// 00597428  e8e36dffff           call 0x58e210
// 0059742d  83c408               add esp, 8
// 00597430  097e68               or dword ptr [esi + 0x68], edi
// 00597433  834e6c20             or dword ptr [esi + 0x6c], 0x20
// 00597437  89ae84000000         mov dword ptr [esi + 0x84], ebp
// 0059743d  39ae0c010000         cmp dword ptr [esi + 0x10c], ebp
// 00597443  7505                 jne 0x59744a
// 00597445  396e78               cmp dword ptr [esi + 0x78], ebp
// 00597448  740e                 je 0x597458
// 0059744a  68ec2d8d00           push 0x8d2dec
// 0059744f  56                   push esi
// 00597450  e8bb6dffff           call 0x58e210
// 00597455  83c408               add esp, 8
// 00597458  8d4e74               lea ecx, [esi + 0x74]
// 0059745b  51                   push ecx
// 0059745c  e83f95ffff           call 0x5909a0
// 00597461  83c404               add esp, 4
// 00597464  097e68               or dword ptr [esi + 0x68], edi
// 00597467  5b                   pop ebx
// 00597468  5f                   pop edi
// 00597469  5e                   pop esi
// 0059746a  5d                   pop ebp
// 0059746b  83c47c               add esp, 0x7c
// 0059746e  c3                   ret 
// 0059746f  39ae84000000         cmp dword ptr [esi + 0x84], ebp
// 00597475  740d                 je 0x597484
// 00597477  396e78               cmp dword ptr [esi + 0x78], ebp
// 0059747a  7508                 jne 0x597484
// 0059747c  39ae0c010000         cmp dword ptr [esi + 0x10c], ebp
// 00597482  74ac                 je 0x597430
// 00597484  68a8df8c00           push 0x8cdfa8
// 00597489  eb9c                 jmp 0x597427
// library libpng-1.2.22/pngrutil.c (function _png_read_finish_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrutil.c
