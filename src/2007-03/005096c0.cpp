// from server: 100% by auto
// roc 2007-03 005096c0  unit: seg_00500000  size: 177 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005096c0
//
// 005096c0  57                   push edi
// 005096c1  8b7c2408             mov edi, dword ptr [esp + 8]
// 005096c5  85ff                 test edi, edi
// 005096c7  0f84a2000000         je 0x50976f
// 005096cd  56                   push esi
// 005096ce  8b742410             mov esi, dword ptr [esp + 0x10]
// 005096d2  85f6                 test esi, esi
// 005096d4  0f8494000000         je 0x50976e
// 005096da  66837e1400           cmp word ptr [esi + 0x14], 0
// 005096df  7511                 jne 0x5096f2
// 005096e1  68600a7a00           push 0x7a0a60
// 005096e6  57                   push edi
// 005096e7  e8e4ec0000           call 0x5183d0
// 005096ec  83c408               add esp, 8
// 005096ef  5e                   pop esi
// 005096f0  5f                   pop edi
// 005096f1  c3                   ret 
// 005096f2  6a00                 push 0
// 005096f4  6a08                 push 8
// 005096f6  56                   push esi
// 005096f7  57                   push edi
// 005096f8  e883100000           call 0x50a780
// 005096fd  6800020000           push 0x200
// 00509702  57                   push edi
// 00509703  e818f90000           call 0x519020
// 00509708  83c418               add esp, 0x18
// 0050970b  85c0                 test eax, eax
// 0050970d  8987f4010000         mov dword ptr [edi + 0x1f4], eax
// 00509713  7511                 jne 0x509726
// 00509715  68340a7a00           push 0x7a0a34
// 0050971a  57                   push edi
// 0050971b  e8b0ec0000           call 0x5183d0
// 00509720  83c408               add esp, 8
// 00509723  5e                   pop esi
// 00509724  5f                   pop edi
// 00509725  c3                   ret 
// 00509726  33c0                 xor eax, eax
// 00509728  66394614             cmp word ptr [esi + 0x14], ax
// 0050972c  762c                 jbe 0x50975a
// 0050972e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00509732  53                   push ebx
// 00509733  eb0b                 jmp 0x509740
// 00509735  8da42400000000       lea esp, [esp]
// 0050973c  8d642400             lea esp, [esp]
// 00509740  8b97f4010000         mov edx, dword ptr [edi + 0x1f4]
// 00509746  668b1c41             mov bx, word ptr [ecx + eax*2]
// 0050974a  66891c42             mov word ptr [edx + eax*2], bx
// 0050974e  0fb75614             movzx edx, word ptr [esi + 0x14]
// 00509752  83c001               add eax, 1
// 00509755  3bc2                 cmp eax, edx
// 00509757  7ce7                 jl 0x509740
// 00509759  5b                   pop ebx
// 0050975a  8b87f4010000         mov eax, dword ptr [edi + 0x1f4]
// 00509760  834e0840             or dword ptr [esi + 8], 0x40
// 00509764  838eb800000008       or dword ptr [esi + 0xb8], 8
// 0050976b  89467c               mov dword ptr [esi + 0x7c], eax
// 0050976e  5e                   pop esi
// 0050976f  5f                   pop edi
// 00509770  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_hIST)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
