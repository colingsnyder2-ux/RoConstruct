// from server: 100% by auto
// roc 2011-06 0056ca90  unit: seg_00560000  size: 342 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056ca90
//
// 0056ca90  83ec10               sub esp, 0x10
// 0056ca93  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056ca97  c6042474             mov byte ptr [esp], 0x74
// 0056ca9b  c644240152           mov byte ptr [esp + 1], 0x52
// 0056caa0  c64424024e           mov byte ptr [esp + 2], 0x4e
// 0056caa5  c644240353           mov byte ptr [esp + 3], 0x53
// 0056caaa  c644240400           mov byte ptr [esp + 4], 0
// 0056caaf  83f803               cmp eax, 3
// 0056cab2  7541                 jne 0x56caf5
// 0056cab4  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056cab8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056cabc  85c0                 test eax, eax
// 0056cabe  7e23                 jle 0x56cae3
// 0056cac0  0fb79118010000       movzx edx, word ptr [ecx + 0x118]
// 0056cac7  3bc2                 cmp eax, edx
// 0056cac9  7f18                 jg 0x56cae3
// 0056cacb  50                   push eax
// 0056cacc  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056cad0  50                   push eax
// 0056cad1  8d542408             lea edx, [esp + 8]
// 0056cad5  52                   push edx
// 0056cad6  51                   push ecx
// 0056cad7  e834f0ffff           call 0x56bb10
// 0056cadc  83c410               add esp, 0x10
// 0056cadf  83c410               add esp, 0x10
// 0056cae2  c3                   ret 
// 0056cae3  68c860a800           push 0xa860c8
// 0056cae8  51                   push ecx
// 0056cae9  e8f248ffff           call 0x5613e0
// 0056caee  83c408               add esp, 8
// 0056caf1  83c410               add esp, 0x10
// 0056caf4  c3                   ret 
// 0056caf5  56                   push esi
// 0056caf6  85c0                 test eax, eax
// 0056caf8  7557                 jne 0x56cb51
// 0056cafa  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056cafe  8a8a27010000         mov cl, byte ptr [edx + 0x127]
// 0056cb04  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056cb08  0fb74008             movzx eax, word ptr [eax + 8]
// 0056cb0c  be01000000           mov esi, 1
// 0056cb11  d3e6                 shl esi, cl
// 0056cb13  3bc6                 cmp eax, esi
// 0056cb15  7c13                 jl 0x56cb2a
// 0056cb17  688860a800           push 0xa86088
// 0056cb1c  52                   push edx
// 0056cb1d  e8be48ffff           call 0x5613e0
// 0056cb22  83c408               add esp, 8
// 0056cb25  5e                   pop esi
// 0056cb26  83c410               add esp, 0x10
// 0056cb29  c3                   ret 
// 0056cb2a  8bc8                 mov ecx, eax
// 0056cb2c  c1e908               shr ecx, 8
// 0056cb2f  8844240d             mov byte ptr [esp + 0xd], al
// 0056cb33  6a02                 push 2
// 0056cb35  8d442410             lea eax, [esp + 0x10]
// 0056cb39  884c2410             mov byte ptr [esp + 0x10], cl
// 0056cb3d  50                   push eax
// 0056cb3e  8d4c240c             lea ecx, [esp + 0xc]
// 0056cb42  51                   push ecx
// 0056cb43  52                   push edx
// 0056cb44  e8c7efffff           call 0x56bb10
// 0056cb49  83c410               add esp, 0x10
// 0056cb4c  5e                   pop esi
// 0056cb4d  83c410               add esp, 0x10
// 0056cb50  c3                   ret 
// 0056cb51  83f802               cmp eax, 2
// 0056cb54  7579                 jne 0x56cbcf
// 0056cb56  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056cb5a  0fb74602             movzx eax, word ptr [esi + 2]
// 0056cb5e  8bc8                 mov ecx, eax
// 0056cb60  8844240d             mov byte ptr [esp + 0xd], al
// 0056cb64  0fb74604             movzx eax, word ptr [esi + 4]
// 0056cb68  53                   push ebx
// 0056cb69  0fb75e06             movzx ebx, word ptr [esi + 6]
// 0056cb6d  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0056cb71  8bd0                 mov edx, eax
// 0056cb73  88442413             mov byte ptr [esp + 0x13], al
// 0056cb77  8bc3                 mov eax, ebx
// 0056cb79  c1e908               shr ecx, 8
// 0056cb7c  c1ea08               shr edx, 8
// 0056cb7f  c1e808               shr eax, 8
// 0056cb82  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 0056cb89  885c2415             mov byte ptr [esp + 0x15], bl
// 0056cb8d  884c2410             mov byte ptr [esp + 0x10], cl
// 0056cb91  88542412             mov byte ptr [esp + 0x12], dl
// 0056cb95  88442414             mov byte ptr [esp + 0x14], al
// 0056cb99  5b                   pop ebx
// 0056cb9a  7519                 jne 0x56cbb5
// 0056cb9c  0ac2                 or al, dl
// 0056cb9e  0ac1                 or al, cl
// 0056cba0  7413                 je 0x56cbb5
// 0056cba2  684860a800           push 0xa86048
// 0056cba7  56                   push esi
// 0056cba8  e83348ffff           call 0x5613e0
// 0056cbad  83c408               add esp, 8
// 0056cbb0  5e                   pop esi
// 0056cbb1  83c410               add esp, 0x10
// 0056cbb4  c3                   ret 
// 0056cbb5  6a06                 push 6
// 0056cbb7  8d542410             lea edx, [esp + 0x10]
// 0056cbbb  52                   push edx
// 0056cbbc  8d44240c             lea eax, [esp + 0xc]
// 0056cbc0  50                   push eax
// 0056cbc1  56                   push esi
// 0056cbc2  e849efffff           call 0x56bb10
// 0056cbc7  83c410               add esp, 0x10
// 0056cbca  5e                   pop esi
// 0056cbcb  83c410               add esp, 0x10
// 0056cbce  c3                   ret 
// 0056cbcf  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056cbd3  682060a800           push 0xa86020
// 0056cbd8  51                   push ecx
// 0056cbd9  e80248ffff           call 0x5613e0
// 0056cbde  83c408               add esp, 8
// 0056cbe1  5e                   pop esi
// 0056cbe2  83c410               add esp, 0x10
// 0056cbe5  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
