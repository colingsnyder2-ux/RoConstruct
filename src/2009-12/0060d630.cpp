// from server: 100% by auto
// roc 2009-12 0060d630  unit: seg_00600000  size: 387 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060d630
//
// 0060d630  56                   push esi
// 0060d631  8b742408             mov esi, dword ptr [esp + 8]
// 0060d635  0fb68e2b010000       movzx ecx, byte ptr [esi + 0x12b]
// 0060d63c  0fb68628010000       movzx eax, byte ptr [esi + 0x128]
// 0060d643  0fafc8               imul ecx, eax
// 0060d646  83f908               cmp ecx, 8
// 0060d649  7c0e                 jl 0x60d659
// 0060d64b  c1e903               shr ecx, 3
// 0060d64e  0faf8ec8000000       imul ecx, dword ptr [esi + 0xc8]
// 0060d655  8bc1                 mov eax, ecx
// 0060d657  eb0f                 jmp 0x60d668
// 0060d659  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0060d65f  0fafc1               imul eax, ecx
// 0060d662  83c007               add eax, 7
// 0060d665  c1e803               shr eax, 3
// 0060d668  57                   push edi
// 0060d669  8d7801               lea edi, [eax + 1]
// 0060d66c  57                   push edi
// 0060d66d  56                   push esi
// 0060d66e  e80d360000           call 0x610c80
// 0060d673  8986ec000000         mov dword ptr [esi + 0xec], eax
// 0060d679  83c408               add esp, 8
// 0060d67c  c60000               mov byte ptr [eax], 0
// 0060d67f  f6862501000010       test byte ptr [esi + 0x125], 0x10
// 0060d686  741a                 je 0x60d6a2
// 0060d688  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0060d68e  41                   inc ecx
// 0060d68f  51                   push ecx
// 0060d690  56                   push esi
// 0060d691  e8ea350000           call 0x610c80
// 0060d696  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 0060d69c  83c408               add esp, 8
// 0060d69f  c60001               mov byte ptr [eax], 1
// 0060d6a2  f68625010000e0       test byte ptr [esi + 0x125], 0xe0
// 0060d6a9  0f8482000000         je 0x60d731
// 0060d6af  57                   push edi
// 0060d6b0  56                   push esi
// 0060d6b1  e8ca350000           call 0x610c80
// 0060d6b6  57                   push edi
// 0060d6b7  6a00                 push 0
// 0060d6b9  50                   push eax
// 0060d6ba  8986e8000000         mov dword ptr [esi + 0xe8], eax
// 0060d6c0  e8df731e00           call 0x7f4aa4
// 0060d6c5  83c414               add esp, 0x14
// 0060d6c8  f6862501000020       test byte ptr [esi + 0x125], 0x20
// 0060d6cf  741a                 je 0x60d6eb
// 0060d6d1  8b96d8000000         mov edx, dword ptr [esi + 0xd8]
// 0060d6d7  42                   inc edx
// 0060d6d8  52                   push edx
// 0060d6d9  56                   push esi
// 0060d6da  e8a1350000           call 0x610c80
// 0060d6df  8986f4000000         mov dword ptr [esi + 0xf4], eax
// 0060d6e5  83c408               add esp, 8
// 0060d6e8  c60002               mov byte ptr [eax], 2
// 0060d6eb  f6862501000040       test byte ptr [esi + 0x125], 0x40
// 0060d6f2  741a                 je 0x60d70e
// 0060d6f4  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 0060d6fa  40                   inc eax
// 0060d6fb  50                   push eax
// 0060d6fc  56                   push esi
// 0060d6fd  e87e350000           call 0x610c80
// 0060d702  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 0060d708  83c408               add esp, 8
// 0060d70b  c60003               mov byte ptr [eax], 3
// 0060d70e  f6862501000080       test byte ptr [esi + 0x125], 0x80
// 0060d715  741a                 je 0x60d731
// 0060d717  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0060d71d  41                   inc ecx
// 0060d71e  51                   push ecx
// 0060d71f  56                   push esi
// 0060d720  e85b350000           call 0x610c80
// 0060d725  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0060d72b  83c408               add esp, 8
// 0060d72e  c60004               mov byte ptr [eax], 4
// 0060d731  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 0060d738  5f                   pop edi
// 0060d739  7446                 je 0x60d781
// 0060d73b  f6467002             test byte ptr [esi + 0x70], 2
// 0060d73f  7526                 jne 0x60d767
// 0060d741  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 0060d747  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0060d74d  83c207               add edx, 7
// 0060d750  c1ea03               shr edx, 3
// 0060d753  83c007               add eax, 7
// 0060d756  c1e803               shr eax, 3
// 0060d759  8996d0000000         mov dword ptr [esi + 0xd0], edx
// 0060d75f  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 0060d765  eb32                 jmp 0x60d799
// 0060d767  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 0060d76d  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 0060d773  898ed0000000         mov dword ptr [esi + 0xd0], ecx
// 0060d779  8996d4000000         mov dword ptr [esi + 0xd4], edx
// 0060d77f  eb18                 jmp 0x60d799
// 0060d781  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 0060d787  8b8ec8000000         mov ecx, dword ptr [esi + 0xc8]
// 0060d78d  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0060d793  898ed4000000         mov dword ptr [esi + 0xd4], ecx
// 0060d799  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 0060d79f  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0060d7a5  899684000000         mov dword ptr [esi + 0x84], edx
// 0060d7ab  898680000000         mov dword ptr [esi + 0x80], eax
// 0060d7b1  5e                   pop esi
// 0060d7b2  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_start_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
