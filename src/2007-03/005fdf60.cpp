// from server: 100% by auto
// roc 2007-03 005fdf60  unit: seg_005f0000  size: 621 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fdf60
//
// 005fdf60  83ec30               sub esp, 0x30
// 005fdf63  53                   push ebx
// 005fdf64  55                   push ebp
// 005fdf65  56                   push esi
// 005fdf66  57                   push edi
// 005fdf67  33ff                 xor edi, edi
// 005fdf69  57                   push edi
// 005fdf6a  57                   push edi
// 005fdf6b  8bd9                 mov ebx, ecx
// 005fdf6d  8b6b30               mov ebp, dword ptr [ebx + 0x30]
// 005fdf70  57                   push edi
// 005fdf71  8bf0                 mov esi, eax
// 005fdf73  8b4304               mov eax, dword ptr [ebx + 4]
// 005fdf76  6a0a                 push 0xa
// 005fdf78  55                   push ebp
// 005fdf79  89442424             mov dword ptr [esp + 0x24], eax
// 005fdf7d  e82e6c0100           call 0x614bb0
// 005fdf82  8bc8                 mov ecx, eax
// 005fdf84  83c8ff               or eax, 0xffffffff
// 005fdf87  894c2428             mov dword ptr [esp + 0x28], ecx
// 005fdf8b  894610               mov dword ptr [esi + 0x10], eax
// 005fdf8e  894614               mov dword ptr [esi + 0x14], eax
// 005fdf91  c7060b000000         mov dword ptr [esi], 0xb
// 005fdf97  894e08               mov dword ptr [esi + 8], ecx
// 005fdf9a  8b4b30               mov ecx, dword ptr [ebx + 0x30]
// 005fdf9d  56                   push esi
// 005fdf9e  51                   push ecx
// 005fdf9f  897c2458             mov dword ptr [esp + 0x58], edi
// 005fdfa3  897c2450             mov dword ptr [esp + 0x50], edi
// 005fdfa7  897c2454             mov dword ptr [esp + 0x54], edi
// 005fdfab  8974244c             mov dword ptr [esp + 0x4c], esi
// 005fdfaf  89442444             mov dword ptr [esp + 0x44], eax
// 005fdfb3  89442448             mov dword ptr [esp + 0x48], eax
// 005fdfb7  897c2434             mov dword ptr [esp + 0x34], edi
// 005fdfbb  897c243c             mov dword ptr [esp + 0x3c], edi
// 005fdfbf  e8fc710100           call 0x6151c0
// 005fdfc4  83c41c               add esp, 0x1c
// 005fdfc7  837b107b             cmp dword ptr [ebx + 0x10], 0x7b
// 005fdfcb  7421                 je 0x5fdfee
// 005fdfcd  6a7b                 push 0x7b
// 005fdfcf  53                   push ebx
// 005fdfd0  e89b2e0000           call 0x600e70
// 005fdfd5  8b5334               mov edx, dword ptr [ebx + 0x34]
// 005fdfd8  50                   push eax
// 005fdfd9  6828047c00           push 0x7c0428
// 005fdfde  52                   push edx
// 005fdfdf  e85ca8ffff           call 0x5f8840
// 005fdfe4  50                   push eax
// 005fdfe5  53                   push ebx
// 005fdfe6  e8852f0000           call 0x600f70
// 005fdfeb  83c41c               add esp, 0x1c
// 005fdfee  53                   push ebx
// 005fdfef  e8ac430000           call 0x6023a0
// 005fdff4  83c404               add esp, 4
// 005fdff7  837b107d             cmp dword ptr [ebx + 0x10], 0x7d
// 005fdffb  0f845f010000         je 0x5fe160
// 005fe001  397c2418             cmp dword ptr [esp + 0x18], edi
// 005fe005  7435                 je 0x5fe03c
// 005fe007  8d442418             lea eax, [esp + 0x18]
// 005fe00b  50                   push eax
// 005fe00c  55                   push ebp
// 005fe00d  e8ae710100           call 0x6151c0
// 005fe012  83c408               add esp, 8
// 005fe015  837c243c32           cmp dword ptr [esp + 0x3c], 0x32
// 005fe01a  897c2418             mov dword ptr [esp + 0x18], edi
// 005fe01e  751c                 jne 0x5fe03c
// 005fe020  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 005fe024  8b542430             mov edx, dword ptr [esp + 0x30]
// 005fe028  8b4208               mov eax, dword ptr [edx + 8]
// 005fe02b  6a32                 push 0x32
// 005fe02d  51                   push ecx
// 005fe02e  50                   push eax
// 005fe02f  55                   push ebp
// 005fe030  e8db6b0100           call 0x614c10
// 005fe035  83c410               add esp, 0x10
// 005fe038  897c243c             mov dword ptr [esp + 0x3c], edi
// 005fe03c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 005fe03f  83f85b               cmp eax, 0x5b
// 005fe042  0f84f6000000         je 0x5fe13e
// 005fe048  3d1d010000           cmp eax, 0x11d
// 005fe04d  7474                 je 0x5fe0c3
// 005fe04f  57                   push edi
// 005fe050  8d4c241c             lea ecx, [esp + 0x1c]
// 005fe054  51                   push ecx
// 005fe055  53                   push ebx
// 005fe056  e8750c0000           call 0x5fecd0
// 005fe05b  83c40c               add esp, 0xc
// 005fe05e  817c2438ffff0300     cmp dword ptr [esp + 0x38], 0x3ffff
// 005fe066  7e49                 jle 0x5fe0b1
// 005fe068  8b7330               mov esi, dword ptr [ebx + 0x30]
// 005fe06b  8b16                 mov edx, dword ptr [esi]
// 005fe06d  8b423c               mov eax, dword ptr [edx + 0x3c]
// 005fe070  3bc7                 cmp eax, edi
// 005fe072  6824057c00           push 0x7c0524
// 005fe077  68ffff0300           push 0x3ffff
// 005fe07c  7513                 jne 0x5fe091
// 005fe07e  8b4610               mov eax, dword ptr [esi + 0x10]
// 005fe081  6860047c00           push 0x7c0460
// 005fe086  50                   push eax
// 005fe087  e8b4a7ffff           call 0x5f8840
// 005fe08c  83c410               add esp, 0x10
// 005fe08f  eb12                 jmp 0x5fe0a3
// 005fe091  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005fe094  50                   push eax
// 005fe095  6838047c00           push 0x7c0438
// 005fe09a  51                   push ecx
// 005fe09b  e8a0a7ffff           call 0x5f8840
// 005fe0a0  83c414               add esp, 0x14
// 005fe0a3  8b560c               mov edx, dword ptr [esi + 0xc]
// 005fe0a6  57                   push edi
// 005fe0a7  50                   push eax
// 005fe0a8  52                   push edx
// 005fe0a9  e8222e0000           call 0x600ed0
// 005fe0ae  83c40c               add esp, 0xc
// 005fe0b1  b801000000           mov eax, 1
// 005fe0b6  01442438             add dword ptr [esp + 0x38], eax
// 005fe0ba  0144243c             add dword ptr [esp + 0x3c], eax
// 005fe0be  e988000000           jmp 0x5fe14b
// 005fe0c3  53                   push ebx
// 005fe0c4  e827430000           call 0x6023f0
// 005fe0c9  83c404               add esp, 4
// 005fe0cc  837b203d             cmp dword ptr [ebx + 0x20], 0x3d
// 005fe0d0  7465                 je 0x5fe137
// 005fe0d2  57                   push edi
// 005fe0d3  8d44241c             lea eax, [esp + 0x1c]
// 005fe0d7  50                   push eax
// 005fe0d8  53                   push ebx
// 005fe0d9  e8f20b0000           call 0x5fecd0
// 005fe0de  83c40c               add esp, 0xc
// 005fe0e1  817c2438ffff0300     cmp dword ptr [esp + 0x38], 0x3ffff
// 005fe0e9  7ec6                 jle 0x5fe0b1
// 005fe0eb  8b7330               mov esi, dword ptr [ebx + 0x30]
// 005fe0ee  8b0e                 mov ecx, dword ptr [esi]
// 005fe0f0  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 005fe0f3  3bc7                 cmp eax, edi
// 005fe0f5  6824057c00           push 0x7c0524
// 005fe0fa  68ffff0300           push 0x3ffff
// 005fe0ff  7519                 jne 0x5fe11a
// 005fe101  8b5610               mov edx, dword ptr [esi + 0x10]
// 005fe104  6860047c00           push 0x7c0460
// 005fe109  52                   push edx
// 005fe10a  e831a7ffff           call 0x5f8840
// 005fe10f  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005fe112  83c410               add esp, 0x10
// 005fe115  57                   push edi
// 005fe116  50                   push eax
// 005fe117  51                   push ecx
// 005fe118  eb8f                 jmp 0x5fe0a9
// 005fe11a  50                   push eax
// 005fe11b  8b4610               mov eax, dword ptr [esi + 0x10]
// 005fe11e  6838047c00           push 0x7c0438
// 005fe123  50                   push eax
// 005fe124  e817a7ffff           call 0x5f8840
// 005fe129  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005fe12c  83c414               add esp, 0x14
// 005fe12f  57                   push edi
// 005fe130  50                   push eax
// 005fe131  51                   push ecx
// 005fe132  e972ffffff           jmp 0x5fe0a9
// 005fe137  8d542418             lea edx, [esp + 0x18]
// 005fe13b  52                   push edx
// 005fe13c  eb05                 jmp 0x5fe143
// 005fe13e  8d442418             lea eax, [esp + 0x18]
// 005fe142  50                   push eax
// 005fe143  e8e8fcffff           call 0x5fde30
// 005fe148  83c404               add esp, 4
// 005fe14b  8b4310               mov eax, dword ptr [ebx + 0x10]
// 005fe14e  83f82c               cmp eax, 0x2c
// 005fe151  0f8497feffff         je 0x5fdfee
// 005fe157  83f83b               cmp eax, 0x3b
// 005fe15a  0f848efeffff         je 0x5fdfee
// 005fe160  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fe164  6a7b                 push 0x7b
// 005fe166  bf7d000000           mov edi, 0x7d
// 005fe16b  8bf3                 mov esi, ebx
// 005fe16d  e85ef3ffff           call 0x5fd4d0
// 005fe172  8d74241c             lea esi, [esp + 0x1c]
// 005fe176  8bfd                 mov edi, ebp
// 005fe178  e883fdffff           call 0x5fdf00
// 005fe17d  8b4d00               mov ecx, dword ptr [ebp]
// 005fe180  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 005fe184  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005fe187  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005fe18b  50                   push eax
// 005fe18c  8d34ba               lea esi, [edx + edi*4]
// 005fe18f  e80ca2ffff           call 0x5f83a0
// 005fe194  8b0e                 mov ecx, dword ptr [esi]
// 005fe196  c1e017               shl eax, 0x17
// 005fe199  81e1ffff7f00         and ecx, 0x7fffff
// 005fe19f  0bc1                 or eax, ecx
// 005fe1a1  8906                 mov dword ptr [esi], eax
// 005fe1a3  8b5500               mov edx, dword ptr [ebp]
// 005fe1a6  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005fe1aa  8b420c               mov eax, dword ptr [edx + 0xc]
// 005fe1ad  51                   push ecx
// 005fe1ae  8d34b8               lea esi, [eax + edi*4]
// 005fe1b1  e8eaa1ffff           call 0x5f83a0
// 005fe1b6  c1e00e               shl eax, 0xe
// 005fe1b9  3306                 xor eax, dword ptr [esi]
// 005fe1bb  83c40c               add esp, 0xc
// 005fe1be  5f                   pop edi
// 005fe1bf  2500c07f00           and eax, 0x7fc000
// 005fe1c4  3106                 xor dword ptr [esi], eax
// 005fe1c6  5e                   pop esi
// 005fe1c7  5d                   pop ebp
// 005fe1c8  5b                   pop ebx
// 005fe1c9  83c430               add esp, 0x30
// 005fe1cc  c3                   ret 
// library lua-5.1.1/lparser.c (function _constructor)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
