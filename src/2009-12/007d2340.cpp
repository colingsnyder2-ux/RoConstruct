// from server: 100% by auto
// roc 2009-12 007d2340  unit: seg_007d0000  size: 621 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d2340
//
// 007d2340  83ec30               sub esp, 0x30
// 007d2343  53                   push ebx
// 007d2344  55                   push ebp
// 007d2345  56                   push esi
// 007d2346  57                   push edi
// 007d2347  33ff                 xor edi, edi
// 007d2349  57                   push edi
// 007d234a  57                   push edi
// 007d234b  8bd9                 mov ebx, ecx
// 007d234d  8b6b30               mov ebp, dword ptr [ebx + 0x30]
// 007d2350  57                   push edi
// 007d2351  8bf0                 mov esi, eax
// 007d2353  8b4304               mov eax, dword ptr [ebx + 4]
// 007d2356  6a0a                 push 0xa
// 007d2358  55                   push ebp
// 007d2359  89442424             mov dword ptr [esp + 0x24], eax
// 007d235d  e89ea20000           call 0x7dc600
// 007d2362  8bc8                 mov ecx, eax
// 007d2364  83c8ff               or eax, 0xffffffff
// 007d2367  894c2428             mov dword ptr [esp + 0x28], ecx
// 007d236b  894610               mov dword ptr [esi + 0x10], eax
// 007d236e  894614               mov dword ptr [esi + 0x14], eax
// 007d2371  c7060b000000         mov dword ptr [esi], 0xb
// 007d2377  894e08               mov dword ptr [esi + 8], ecx
// 007d237a  8b4b30               mov ecx, dword ptr [ebx + 0x30]
// 007d237d  56                   push esi
// 007d237e  51                   push ecx
// 007d237f  897c2458             mov dword ptr [esp + 0x58], edi
// 007d2383  897c2450             mov dword ptr [esp + 0x50], edi
// 007d2387  897c2454             mov dword ptr [esp + 0x54], edi
// 007d238b  8974244c             mov dword ptr [esp + 0x4c], esi
// 007d238f  89442444             mov dword ptr [esp + 0x44], eax
// 007d2393  89442448             mov dword ptr [esp + 0x48], eax
// 007d2397  897c2434             mov dword ptr [esp + 0x34], edi
// 007d239b  897c243c             mov dword ptr [esp + 0x3c], edi
// 007d239f  e86ca80000           call 0x7dcc10
// 007d23a4  83c41c               add esp, 0x1c
// 007d23a7  837b107b             cmp dword ptr [ebx + 0x10], 0x7b
// 007d23ab  7421                 je 0x7d23ce
// 007d23ad  6a7b                 push 0x7b
// 007d23af  53                   push ebx
// 007d23b0  e88b2e0000           call 0x7d5240
// 007d23b5  8b5334               mov edx, dword ptr [ebx + 0x34]
// 007d23b8  50                   push eax
// 007d23b9  68d0ed9e00           push 0x9eedd0
// 007d23be  52                   push edx
// 007d23bf  e8bc81fcff           call 0x79a580
// 007d23c4  50                   push eax
// 007d23c5  53                   push ebx
// 007d23c6  e8752f0000           call 0x7d5340
// 007d23cb  83c41c               add esp, 0x1c
// 007d23ce  53                   push ebx
// 007d23cf  e85c430000           call 0x7d6730
// 007d23d4  83c404               add esp, 4
// 007d23d7  837b107d             cmp dword ptr [ebx + 0x10], 0x7d
// 007d23db  0f845f010000         je 0x7d2540
// 007d23e1  397c2418             cmp dword ptr [esp + 0x18], edi
// 007d23e5  7435                 je 0x7d241c
// 007d23e7  8d442418             lea eax, [esp + 0x18]
// 007d23eb  50                   push eax
// 007d23ec  55                   push ebp
// 007d23ed  e81ea80000           call 0x7dcc10
// 007d23f2  83c408               add esp, 8
// 007d23f5  837c243c32           cmp dword ptr [esp + 0x3c], 0x32
// 007d23fa  897c2418             mov dword ptr [esp + 0x18], edi
// 007d23fe  751c                 jne 0x7d241c
// 007d2400  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007d2404  8b542430             mov edx, dword ptr [esp + 0x30]
// 007d2408  8b4208               mov eax, dword ptr [edx + 8]
// 007d240b  6a32                 push 0x32
// 007d240d  51                   push ecx
// 007d240e  50                   push eax
// 007d240f  55                   push ebp
// 007d2410  e84ba20000           call 0x7dc660
// 007d2415  83c410               add esp, 0x10
// 007d2418  897c243c             mov dword ptr [esp + 0x3c], edi
// 007d241c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 007d241f  83f85b               cmp eax, 0x5b
// 007d2422  0f84f6000000         je 0x7d251e
// 007d2428  3d1d010000           cmp eax, 0x11d
// 007d242d  7474                 je 0x7d24a3
// 007d242f  57                   push edi
// 007d2430  8d4c241c             lea ecx, [esp + 0x1c]
// 007d2434  51                   push ecx
// 007d2435  53                   push ebx
// 007d2436  e8750c0000           call 0x7d30b0
// 007d243b  83c40c               add esp, 0xc
// 007d243e  817c2438fdffff7f     cmp dword ptr [esp + 0x38], 0x7ffffffd
// 007d2446  7e49                 jle 0x7d2491
// 007d2448  8b7330               mov esi, dword ptr [ebx + 0x30]
// 007d244b  8b16                 mov edx, dword ptr [esi]
// 007d244d  8b423c               mov eax, dword ptr [edx + 0x3c]
// 007d2450  68ccee9e00           push 0x9eeecc
// 007d2455  68fdffff7f           push 0x7ffffffd
// 007d245a  3bc7                 cmp eax, edi
// 007d245c  7513                 jne 0x7d2471
// 007d245e  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d2461  6808ee9e00           push 0x9eee08
// 007d2466  50                   push eax
// 007d2467  e81481fcff           call 0x79a580
// 007d246c  83c410               add esp, 0x10
// 007d246f  eb12                 jmp 0x7d2483
// 007d2471  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007d2474  50                   push eax
// 007d2475  68e0ed9e00           push 0x9eede0
// 007d247a  51                   push ecx
// 007d247b  e80081fcff           call 0x79a580
// 007d2480  83c414               add esp, 0x14
// 007d2483  8b560c               mov edx, dword ptr [esi + 0xc]
// 007d2486  57                   push edi
// 007d2487  50                   push eax
// 007d2488  52                   push edx
// 007d2489  e8122e0000           call 0x7d52a0
// 007d248e  83c40c               add esp, 0xc
// 007d2491  b801000000           mov eax, 1
// 007d2496  01442438             add dword ptr [esp + 0x38], eax
// 007d249a  0144243c             add dword ptr [esp + 0x3c], eax
// 007d249e  e988000000           jmp 0x7d252b
// 007d24a3  53                   push ebx
// 007d24a4  e8d7420000           call 0x7d6780
// 007d24a9  83c404               add esp, 4
// 007d24ac  837b203d             cmp dword ptr [ebx + 0x20], 0x3d
// 007d24b0  7465                 je 0x7d2517
// 007d24b2  57                   push edi
// 007d24b3  8d44241c             lea eax, [esp + 0x1c]
// 007d24b7  50                   push eax
// 007d24b8  53                   push ebx
// 007d24b9  e8f20b0000           call 0x7d30b0
// 007d24be  83c40c               add esp, 0xc
// 007d24c1  817c2438fdffff7f     cmp dword ptr [esp + 0x38], 0x7ffffffd
// 007d24c9  7ec6                 jle 0x7d2491
// 007d24cb  8b7330               mov esi, dword ptr [ebx + 0x30]
// 007d24ce  8b0e                 mov ecx, dword ptr [esi]
// 007d24d0  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 007d24d3  68ccee9e00           push 0x9eeecc
// 007d24d8  68fdffff7f           push 0x7ffffffd
// 007d24dd  3bc7                 cmp eax, edi
// 007d24df  7519                 jne 0x7d24fa
// 007d24e1  8b5610               mov edx, dword ptr [esi + 0x10]
// 007d24e4  6808ee9e00           push 0x9eee08
// 007d24e9  52                   push edx
// 007d24ea  e89180fcff           call 0x79a580
// 007d24ef  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007d24f2  83c410               add esp, 0x10
// 007d24f5  57                   push edi
// 007d24f6  50                   push eax
// 007d24f7  51                   push ecx
// 007d24f8  eb8f                 jmp 0x7d2489
// 007d24fa  50                   push eax
// 007d24fb  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d24fe  68e0ed9e00           push 0x9eede0
// 007d2503  50                   push eax
// 007d2504  e87780fcff           call 0x79a580
// 007d2509  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007d250c  83c414               add esp, 0x14
// 007d250f  57                   push edi
// 007d2510  50                   push eax
// 007d2511  51                   push ecx
// 007d2512  e972ffffff           jmp 0x7d2489
// 007d2517  8d542418             lea edx, [esp + 0x18]
// 007d251b  52                   push edx
// 007d251c  eb05                 jmp 0x7d2523
// 007d251e  8d442418             lea eax, [esp + 0x18]
// 007d2522  50                   push eax
// 007d2523  e8e8fcffff           call 0x7d2210
// 007d2528  83c404               add esp, 4
// 007d252b  8b4310               mov eax, dword ptr [ebx + 0x10]
// 007d252e  83f82c               cmp eax, 0x2c
// 007d2531  0f8497feffff         je 0x7d23ce
// 007d2537  83f83b               cmp eax, 0x3b
// 007d253a  0f848efeffff         je 0x7d23ce
// 007d2540  8b442410             mov eax, dword ptr [esp + 0x10]
// 007d2544  6a7b                 push 0x7b
// 007d2546  bf7d000000           mov edi, 0x7d
// 007d254b  8bf3                 mov esi, ebx
// 007d254d  e88ef3ffff           call 0x7d18e0
// 007d2552  8d74241c             lea esi, [esp + 0x1c]
// 007d2556  8bfd                 mov edi, ebp
// 007d2558  e883fdffff           call 0x7d22e0
// 007d255d  8b4d00               mov ecx, dword ptr [ebp]
// 007d2560  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 007d2564  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007d2567  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007d256b  50                   push eax
// 007d256c  8d34ba               lea esi, [edx + edi*4]
// 007d256f  e83c7bfcff           call 0x79a0b0
// 007d2574  8b0e                 mov ecx, dword ptr [esi]
// 007d2576  c1e017               shl eax, 0x17
// 007d2579  81e1ffff7f00         and ecx, 0x7fffff
// 007d257f  0bc1                 or eax, ecx
// 007d2581  8906                 mov dword ptr [esi], eax
// 007d2583  8b5500               mov edx, dword ptr [ebp]
// 007d2586  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 007d258a  8b420c               mov eax, dword ptr [edx + 0xc]
// 007d258d  51                   push ecx
// 007d258e  8d34b8               lea esi, [eax + edi*4]
// 007d2591  e81a7bfcff           call 0x79a0b0
// 007d2596  c1e00e               shl eax, 0xe
// 007d2599  3306                 xor eax, dword ptr [esi]
// 007d259b  83c40c               add esp, 0xc
// 007d259e  5f                   pop edi
// 007d259f  2500c07f00           and eax, 0x7fc000
// 007d25a4  3106                 xor dword ptr [esi], eax
// 007d25a6  5e                   pop esi
// 007d25a7  5d                   pop ebp
// 007d25a8  5b                   pop ebx
// 007d25a9  83c430               add esp, 0x30
// 007d25ac  c3                   ret 
// library lua-5.1.2/lparser.c (function _constructor)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lparser.c
