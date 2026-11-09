// from server: 100% by auto
// roc 2009-06 0058b5e0  unit: seg_00580000  size: 387 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058b5e0
//
// 0058b5e0  56                   push esi
// 0058b5e1  8b742408             mov esi, dword ptr [esp + 8]
// 0058b5e5  0fb68e2b010000       movzx ecx, byte ptr [esi + 0x12b]
// 0058b5ec  0fb68628010000       movzx eax, byte ptr [esi + 0x128]
// 0058b5f3  0fafc8               imul ecx, eax
// 0058b5f6  83f908               cmp ecx, 8
// 0058b5f9  7c0e                 jl 0x58b609
// 0058b5fb  c1e903               shr ecx, 3
// 0058b5fe  0faf8ec8000000       imul ecx, dword ptr [esi + 0xc8]
// 0058b605  8bc1                 mov eax, ecx
// 0058b607  eb0f                 jmp 0x58b618
// 0058b609  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0058b60f  0fafc1               imul eax, ecx
// 0058b612  83c007               add eax, 7
// 0058b615  c1e803               shr eax, 3
// 0058b618  57                   push edi
// 0058b619  8d7801               lea edi, [eax + 1]
// 0058b61c  57                   push edi
// 0058b61d  56                   push esi
// 0058b61e  e82d360000           call 0x58ec50
// 0058b623  8986ec000000         mov dword ptr [esi + 0xec], eax
// 0058b629  83c408               add esp, 8
// 0058b62c  c60000               mov byte ptr [eax], 0
// 0058b62f  f6862501000010       test byte ptr [esi + 0x125], 0x10
// 0058b636  741a                 je 0x58b652
// 0058b638  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0058b63e  41                   inc ecx
// 0058b63f  51                   push ecx
// 0058b640  56                   push esi
// 0058b641  e80a360000           call 0x58ec50
// 0058b646  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 0058b64c  83c408               add esp, 8
// 0058b64f  c60001               mov byte ptr [eax], 1
// 0058b652  f68625010000e0       test byte ptr [esi + 0x125], 0xe0
// 0058b659  0f8482000000         je 0x58b6e1
// 0058b65f  57                   push edi
// 0058b660  56                   push esi
// 0058b661  e8ea350000           call 0x58ec50
// 0058b666  57                   push edi
// 0058b667  6a00                 push 0
// 0058b669  50                   push eax
// 0058b66a  8986e8000000         mov dword ptr [esi + 0xe8], eax
// 0058b670  e8ffe51800           call 0x719c74
// 0058b675  83c414               add esp, 0x14
// 0058b678  f6862501000020       test byte ptr [esi + 0x125], 0x20
// 0058b67f  741a                 je 0x58b69b
// 0058b681  8b96d8000000         mov edx, dword ptr [esi + 0xd8]
// 0058b687  42                   inc edx
// 0058b688  52                   push edx
// 0058b689  56                   push esi
// 0058b68a  e8c1350000           call 0x58ec50
// 0058b68f  8986f4000000         mov dword ptr [esi + 0xf4], eax
// 0058b695  83c408               add esp, 8
// 0058b698  c60002               mov byte ptr [eax], 2
// 0058b69b  f6862501000040       test byte ptr [esi + 0x125], 0x40
// 0058b6a2  741a                 je 0x58b6be
// 0058b6a4  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 0058b6aa  40                   inc eax
// 0058b6ab  50                   push eax
// 0058b6ac  56                   push esi
// 0058b6ad  e89e350000           call 0x58ec50
// 0058b6b2  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 0058b6b8  83c408               add esp, 8
// 0058b6bb  c60003               mov byte ptr [eax], 3
// 0058b6be  f6862501000080       test byte ptr [esi + 0x125], 0x80
// 0058b6c5  741a                 je 0x58b6e1
// 0058b6c7  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0058b6cd  41                   inc ecx
// 0058b6ce  51                   push ecx
// 0058b6cf  56                   push esi
// 0058b6d0  e87b350000           call 0x58ec50
// 0058b6d5  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0058b6db  83c408               add esp, 8
// 0058b6de  c60004               mov byte ptr [eax], 4
// 0058b6e1  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 0058b6e8  5f                   pop edi
// 0058b6e9  7446                 je 0x58b731
// 0058b6eb  f6467002             test byte ptr [esi + 0x70], 2
// 0058b6ef  7526                 jne 0x58b717
// 0058b6f1  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 0058b6f7  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0058b6fd  83c207               add edx, 7
// 0058b700  c1ea03               shr edx, 3
// 0058b703  83c007               add eax, 7
// 0058b706  c1e803               shr eax, 3
// 0058b709  8996d0000000         mov dword ptr [esi + 0xd0], edx
// 0058b70f  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 0058b715  eb32                 jmp 0x58b749
// 0058b717  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 0058b71d  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 0058b723  898ed0000000         mov dword ptr [esi + 0xd0], ecx
// 0058b729  8996d4000000         mov dword ptr [esi + 0xd4], edx
// 0058b72f  eb18                 jmp 0x58b749
// 0058b731  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 0058b737  8b8ec8000000         mov ecx, dword ptr [esi + 0xc8]
// 0058b73d  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0058b743  898ed4000000         mov dword ptr [esi + 0xd4], ecx
// 0058b749  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 0058b74f  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0058b755  899684000000         mov dword ptr [esi + 0x84], edx
// 0058b75b  898680000000         mov dword ptr [esi + 0x80], eax
// 0058b761  5e                   pop esi
// 0058b762  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_start_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
