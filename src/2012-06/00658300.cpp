// from server: 100% by auto
// roc 2012-06 00658300  unit: seg_00650000  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00658300
//
// 00658300  83ec10               sub esp, 0x10
// 00658303  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00658307  56                   push esi
// 00658308  c644240462           mov byte ptr [esp + 4], 0x62
// 0065830d  c64424054b           mov byte ptr [esp + 5], 0x4b
// 00658312  c644240647           mov byte ptr [esp + 6], 0x47
// 00658317  c644240744           mov byte ptr [esp + 7], 0x44
// 0065831c  c644240800           mov byte ptr [esp + 8], 0
// 00658321  83f803               cmp eax, 3
// 00658324  7559                 jne 0x65837f
// 00658326  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065832a  0fb78118010000       movzx eax, word ptr [ecx + 0x118]
// 00658331  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00658335  6685c0               test ax, ax
// 00658338  7509                 jne 0x658343
// 0065833a  f6813002000001       test byte ptr [ecx + 0x230], 1
// 00658341  751c                 jne 0x65835f
// 00658343  660fb632             movzx si, byte ptr [edx]
// 00658347  663bf0               cmp si, ax
// 0065834a  7213                 jb 0x65835f
// 0065834c  68c89fb800           push 0xb89fc8
// 00658351  51                   push ecx
// 00658352  e8095fffff           call 0x64e260
// 00658357  83c408               add esp, 8
// 0065835a  5e                   pop esi
// 0065835b  83c410               add esp, 0x10
// 0065835e  c3                   ret 
// 0065835f  8a02                 mov al, byte ptr [edx]
// 00658361  6a01                 push 1
// 00658363  8d542410             lea edx, [esp + 0x10]
// 00658367  88442410             mov byte ptr [esp + 0x10], al
// 0065836b  52                   push edx
// 0065836c  8d44240c             lea eax, [esp + 0xc]
// 00658370  50                   push eax
// 00658371  51                   push ecx
// 00658372  e8a9eeffff           call 0x657220
// 00658377  83c410               add esp, 0x10
// 0065837a  5e                   pop esi
// 0065837b  83c410               add esp, 0x10
// 0065837e  c3                   ret 
// 0065837f  a802                 test al, 2
// 00658381  7479                 je 0x6583fc
// 00658383  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00658387  0fb74602             movzx eax, word ptr [esi + 2]
// 0065838b  8bc8                 mov ecx, eax
// 0065838d  8844240d             mov byte ptr [esp + 0xd], al
// 00658391  0fb74604             movzx eax, word ptr [esi + 4]
// 00658395  53                   push ebx
// 00658396  0fb75e06             movzx ebx, word ptr [esi + 6]
// 0065839a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0065839e  8bd0                 mov edx, eax
// 006583a0  88442413             mov byte ptr [esp + 0x13], al
// 006583a4  8bc3                 mov eax, ebx
// 006583a6  c1e908               shr ecx, 8
// 006583a9  c1ea08               shr edx, 8
// 006583ac  c1e808               shr eax, 8
// 006583af  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 006583b6  885c2415             mov byte ptr [esp + 0x15], bl
// 006583ba  884c2410             mov byte ptr [esp + 0x10], cl
// 006583be  88542412             mov byte ptr [esp + 0x12], dl
// 006583c2  88442414             mov byte ptr [esp + 0x14], al
// 006583c6  5b                   pop ebx
// 006583c7  7519                 jne 0x6583e2
// 006583c9  0ac2                 or al, dl
// 006583cb  0ac1                 or al, cl
// 006583cd  7413                 je 0x6583e2
// 006583cf  68889fb800           push 0xb89f88
// 006583d4  56                   push esi
// 006583d5  e8865effff           call 0x64e260
// 006583da  83c408               add esp, 8
// 006583dd  5e                   pop esi
// 006583de  83c410               add esp, 0x10
// 006583e1  c3                   ret 
// 006583e2  6a06                 push 6
// 006583e4  8d4c2410             lea ecx, [esp + 0x10]
// 006583e8  51                   push ecx
// 006583e9  8d54240c             lea edx, [esp + 0xc]
// 006583ed  52                   push edx
// 006583ee  56                   push esi
// 006583ef  e82ceeffff           call 0x657220
// 006583f4  83c410               add esp, 0x10
// 006583f7  5e                   pop esi
// 006583f8  83c410               add esp, 0x10
// 006583fb  c3                   ret 
// 006583fc  8b542418             mov edx, dword ptr [esp + 0x18]
// 00658400  8a8a27010000         mov cl, byte ptr [edx + 0x127]
// 00658406  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065840a  0fb74008             movzx eax, word ptr [eax + 8]
// 0065840e  be01000000           mov esi, 1
// 00658413  d3e6                 shl esi, cl
// 00658415  3bc6                 cmp eax, esi
// 00658417  7c13                 jl 0x65842c
// 00658419  68489fb800           push 0xb89f48
// 0065841e  52                   push edx
// 0065841f  e83c5effff           call 0x64e260
// 00658424  83c408               add esp, 8
// 00658427  5e                   pop esi
// 00658428  83c410               add esp, 0x10
// 0065842b  c3                   ret 
// 0065842c  8bc8                 mov ecx, eax
// 0065842e  c1e908               shr ecx, 8
// 00658431  8844240d             mov byte ptr [esp + 0xd], al
// 00658435  6a02                 push 2
// 00658437  8d442410             lea eax, [esp + 0x10]
// 0065843b  884c2410             mov byte ptr [esp + 0x10], cl
// 0065843f  50                   push eax
// 00658440  8d4c240c             lea ecx, [esp + 0xc]
// 00658444  51                   push ecx
// 00658445  52                   push edx
// 00658446  e8d5edffff           call 0x657220
// 0065844b  83c410               add esp, 0x10
// 0065844e  5e                   pop esi
// 0065844f  83c410               add esp, 0x10
// 00658452  c3                   ret 
// library libpng-1.2.35/pngwutil.c (function _png_write_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngwutil.c
