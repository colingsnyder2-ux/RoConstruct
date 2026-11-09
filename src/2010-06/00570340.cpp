// from server: 100% by auto
// roc 2010-06 00570340  unit: G3D::LineSegment  size: 342 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00570340
//
// 00570340  83ec10               sub esp, 0x10
// 00570343  8b442424             mov eax, dword ptr [esp + 0x24]
// 00570347  c6042474             mov byte ptr [esp], 0x74
// 0057034b  c644240152           mov byte ptr [esp + 1], 0x52
// 00570350  c64424024e           mov byte ptr [esp + 2], 0x4e
// 00570355  c644240353           mov byte ptr [esp + 3], 0x53
// 0057035a  c644240400           mov byte ptr [esp + 4], 0
// 0057035f  83f803               cmp eax, 3
// 00570362  7541                 jne 0x5703a5
// 00570364  8b442420             mov eax, dword ptr [esp + 0x20]
// 00570368  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0057036c  85c0                 test eax, eax
// 0057036e  7e23                 jle 0x570393
// 00570370  0fb79118010000       movzx edx, word ptr [ecx + 0x118]
// 00570377  3bc2                 cmp eax, edx
// 00570379  7f18                 jg 0x570393
// 0057037b  50                   push eax
// 0057037c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00570380  50                   push eax
// 00570381  8d542408             lea edx, [esp + 8]
// 00570385  52                   push edx
// 00570386  51                   push ecx
// 00570387  e804f0ffff           call 0x56f390
// 0057038c  83c410               add esp, 0x10
// 0057038f  83c410               add esp, 0x10
// 00570392  c3                   ret 
// 00570393  68f83da200           push 0xa23df8
// 00570398  51                   push ecx
// 00570399  e8c2170000           call 0x571b60
// 0057039e  83c408               add esp, 8
// 005703a1  83c410               add esp, 0x10
// 005703a4  c3                   ret 
// 005703a5  56                   push esi
// 005703a6  85c0                 test eax, eax
// 005703a8  7557                 jne 0x570401
// 005703aa  8b542418             mov edx, dword ptr [esp + 0x18]
// 005703ae  8a8a27010000         mov cl, byte ptr [edx + 0x127]
// 005703b4  8b442420             mov eax, dword ptr [esp + 0x20]
// 005703b8  0fb74008             movzx eax, word ptr [eax + 8]
// 005703bc  be01000000           mov esi, 1
// 005703c1  d3e6                 shl esi, cl
// 005703c3  3bc6                 cmp eax, esi
// 005703c5  7c13                 jl 0x5703da
// 005703c7  68b83da200           push 0xa23db8
// 005703cc  52                   push edx
// 005703cd  e88e170000           call 0x571b60
// 005703d2  83c408               add esp, 8
// 005703d5  5e                   pop esi
// 005703d6  83c410               add esp, 0x10
// 005703d9  c3                   ret 
// 005703da  8bc8                 mov ecx, eax
// 005703dc  c1e908               shr ecx, 8
// 005703df  8844240d             mov byte ptr [esp + 0xd], al
// 005703e3  6a02                 push 2
// 005703e5  8d442410             lea eax, [esp + 0x10]
// 005703e9  884c2410             mov byte ptr [esp + 0x10], cl
// 005703ed  50                   push eax
// 005703ee  8d4c240c             lea ecx, [esp + 0xc]
// 005703f2  51                   push ecx
// 005703f3  52                   push edx
// 005703f4  e897efffff           call 0x56f390
// 005703f9  83c410               add esp, 0x10
// 005703fc  5e                   pop esi
// 005703fd  83c410               add esp, 0x10
// 00570400  c3                   ret 
// 00570401  83f802               cmp eax, 2
// 00570404  7579                 jne 0x57047f
// 00570406  8b742420             mov esi, dword ptr [esp + 0x20]
// 0057040a  0fb74602             movzx eax, word ptr [esi + 2]
// 0057040e  8bc8                 mov ecx, eax
// 00570410  8844240d             mov byte ptr [esp + 0xd], al
// 00570414  0fb74604             movzx eax, word ptr [esi + 4]
// 00570418  53                   push ebx
// 00570419  0fb75e06             movzx ebx, word ptr [esi + 6]
// 0057041d  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00570421  8bd0                 mov edx, eax
// 00570423  88442413             mov byte ptr [esp + 0x13], al
// 00570427  8bc3                 mov eax, ebx
// 00570429  c1e908               shr ecx, 8
// 0057042c  c1ea08               shr edx, 8
// 0057042f  c1e808               shr eax, 8
// 00570432  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 00570439  885c2415             mov byte ptr [esp + 0x15], bl
// 0057043d  884c2410             mov byte ptr [esp + 0x10], cl
// 00570441  88542412             mov byte ptr [esp + 0x12], dl
// 00570445  88442414             mov byte ptr [esp + 0x14], al
// 00570449  5b                   pop ebx
// 0057044a  7519                 jne 0x570465
// 0057044c  0ac2                 or al, dl
// 0057044e  0ac1                 or al, cl
// 00570450  7413                 je 0x570465
// 00570452  68783da200           push 0xa23d78
// 00570457  56                   push esi
// 00570458  e803170000           call 0x571b60
// 0057045d  83c408               add esp, 8
// 00570460  5e                   pop esi
// 00570461  83c410               add esp, 0x10
// 00570464  c3                   ret 
// 00570465  6a06                 push 6
// 00570467  8d542410             lea edx, [esp + 0x10]
// 0057046b  52                   push edx
// 0057046c  8d44240c             lea eax, [esp + 0xc]
// 00570470  50                   push eax
// 00570471  56                   push esi
// 00570472  e819efffff           call 0x56f390
// 00570477  83c410               add esp, 0x10
// 0057047a  5e                   pop esi
// 0057047b  83c410               add esp, 0x10
// 0057047e  c3                   ret 
// 0057047f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00570483  68503da200           push 0xa23d50
// 00570488  51                   push ecx
// 00570489  e8d2160000           call 0x571b60
// 0057048e  83c408               add esp, 8
// 00570491  5e                   pop esi
// 00570492  83c410               add esp, 0x10
// 00570495  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
