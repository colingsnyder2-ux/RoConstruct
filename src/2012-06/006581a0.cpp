// from server: 100% by auto
// roc 2012-06 006581a0  unit: seg_00650000  size: 342 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006581a0
//
// 006581a0  83ec10               sub esp, 0x10
// 006581a3  8b442424             mov eax, dword ptr [esp + 0x24]
// 006581a7  c6042474             mov byte ptr [esp], 0x74
// 006581ab  c644240152           mov byte ptr [esp + 1], 0x52
// 006581b0  c64424024e           mov byte ptr [esp + 2], 0x4e
// 006581b5  c644240353           mov byte ptr [esp + 3], 0x53
// 006581ba  c644240400           mov byte ptr [esp + 4], 0
// 006581bf  83f803               cmp eax, 3
// 006581c2  7541                 jne 0x658205
// 006581c4  8b442420             mov eax, dword ptr [esp + 0x20]
// 006581c8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006581cc  85c0                 test eax, eax
// 006581ce  7e23                 jle 0x6581f3
// 006581d0  0fb79118010000       movzx edx, word ptr [ecx + 0x118]
// 006581d7  3bc2                 cmp eax, edx
// 006581d9  7f18                 jg 0x6581f3
// 006581db  50                   push eax
// 006581dc  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006581e0  50                   push eax
// 006581e1  8d542408             lea edx, [esp + 8]
// 006581e5  52                   push edx
// 006581e6  51                   push ecx
// 006581e7  e834f0ffff           call 0x657220
// 006581ec  83c410               add esp, 0x10
// 006581ef  83c410               add esp, 0x10
// 006581f2  c3                   ret 
// 006581f3  68189fb800           push 0xb89f18
// 006581f8  51                   push ecx
// 006581f9  e86260ffff           call 0x64e260
// 006581fe  83c408               add esp, 8
// 00658201  83c410               add esp, 0x10
// 00658204  c3                   ret 
// 00658205  56                   push esi
// 00658206  85c0                 test eax, eax
// 00658208  7557                 jne 0x658261
// 0065820a  8b542418             mov edx, dword ptr [esp + 0x18]
// 0065820e  8a8a27010000         mov cl, byte ptr [edx + 0x127]
// 00658214  8b442420             mov eax, dword ptr [esp + 0x20]
// 00658218  0fb74008             movzx eax, word ptr [eax + 8]
// 0065821c  be01000000           mov esi, 1
// 00658221  d3e6                 shl esi, cl
// 00658223  3bc6                 cmp eax, esi
// 00658225  7c13                 jl 0x65823a
// 00658227  68d89eb800           push 0xb89ed8
// 0065822c  52                   push edx
// 0065822d  e82e60ffff           call 0x64e260
// 00658232  83c408               add esp, 8
// 00658235  5e                   pop esi
// 00658236  83c410               add esp, 0x10
// 00658239  c3                   ret 
// 0065823a  8bc8                 mov ecx, eax
// 0065823c  c1e908               shr ecx, 8
// 0065823f  8844240d             mov byte ptr [esp + 0xd], al
// 00658243  6a02                 push 2
// 00658245  8d442410             lea eax, [esp + 0x10]
// 00658249  884c2410             mov byte ptr [esp + 0x10], cl
// 0065824d  50                   push eax
// 0065824e  8d4c240c             lea ecx, [esp + 0xc]
// 00658252  51                   push ecx
// 00658253  52                   push edx
// 00658254  e8c7efffff           call 0x657220
// 00658259  83c410               add esp, 0x10
// 0065825c  5e                   pop esi
// 0065825d  83c410               add esp, 0x10
// 00658260  c3                   ret 
// 00658261  83f802               cmp eax, 2
// 00658264  7579                 jne 0x6582df
// 00658266  8b742420             mov esi, dword ptr [esp + 0x20]
// 0065826a  0fb74602             movzx eax, word ptr [esi + 2]
// 0065826e  8bc8                 mov ecx, eax
// 00658270  8844240d             mov byte ptr [esp + 0xd], al
// 00658274  0fb74604             movzx eax, word ptr [esi + 4]
// 00658278  53                   push ebx
// 00658279  0fb75e06             movzx ebx, word ptr [esi + 6]
// 0065827d  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00658281  8bd0                 mov edx, eax
// 00658283  88442413             mov byte ptr [esp + 0x13], al
// 00658287  8bc3                 mov eax, ebx
// 00658289  c1e908               shr ecx, 8
// 0065828c  c1ea08               shr edx, 8
// 0065828f  c1e808               shr eax, 8
// 00658292  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 00658299  885c2415             mov byte ptr [esp + 0x15], bl
// 0065829d  884c2410             mov byte ptr [esp + 0x10], cl
// 006582a1  88542412             mov byte ptr [esp + 0x12], dl
// 006582a5  88442414             mov byte ptr [esp + 0x14], al
// 006582a9  5b                   pop ebx
// 006582aa  7519                 jne 0x6582c5
// 006582ac  0ac2                 or al, dl
// 006582ae  0ac1                 or al, cl
// 006582b0  7413                 je 0x6582c5
// 006582b2  68989eb800           push 0xb89e98
// 006582b7  56                   push esi
// 006582b8  e8a35fffff           call 0x64e260
// 006582bd  83c408               add esp, 8
// 006582c0  5e                   pop esi
// 006582c1  83c410               add esp, 0x10
// 006582c4  c3                   ret 
// 006582c5  6a06                 push 6
// 006582c7  8d542410             lea edx, [esp + 0x10]
// 006582cb  52                   push edx
// 006582cc  8d44240c             lea eax, [esp + 0xc]
// 006582d0  50                   push eax
// 006582d1  56                   push esi
// 006582d2  e849efffff           call 0x657220
// 006582d7  83c410               add esp, 0x10
// 006582da  5e                   pop esi
// 006582db  83c410               add esp, 0x10
// 006582de  c3                   ret 
// 006582df  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006582e3  68709eb800           push 0xb89e70
// 006582e8  51                   push ecx
// 006582e9  e8725fffff           call 0x64e260
// 006582ee  83c408               add esp, 8
// 006582f1  5e                   pop esi
// 006582f2  83c410               add esp, 0x10
// 006582f5  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
