// from server: 100% by auto
// roc 2010-06 0056ef50  unit: G3D::LineSegment  size: 387 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056ef50
//
// 0056ef50  56                   push esi
// 0056ef51  8b742408             mov esi, dword ptr [esp + 8]
// 0056ef55  0fb68e2b010000       movzx ecx, byte ptr [esi + 0x12b]
// 0056ef5c  0fb68628010000       movzx eax, byte ptr [esi + 0x128]
// 0056ef63  0fafc8               imul ecx, eax
// 0056ef66  83f908               cmp ecx, 8
// 0056ef69  7c0e                 jl 0x56ef79
// 0056ef6b  c1e903               shr ecx, 3
// 0056ef6e  0faf8ec8000000       imul ecx, dword ptr [esi + 0xc8]
// 0056ef75  8bc1                 mov eax, ecx
// 0056ef77  eb0f                 jmp 0x56ef88
// 0056ef79  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0056ef7f  0fafc1               imul eax, ecx
// 0056ef82  83c007               add eax, 7
// 0056ef85  c1e803               shr eax, 3
// 0056ef88  57                   push edi
// 0056ef89  8d7801               lea edi, [eax + 1]
// 0056ef8c  57                   push edi
// 0056ef8d  56                   push esi
// 0056ef8e  e80d360000           call 0x5725a0
// 0056ef93  8986ec000000         mov dword ptr [esi + 0xec], eax
// 0056ef99  83c408               add esp, 8
// 0056ef9c  c60000               mov byte ptr [eax], 0
// 0056ef9f  f6862501000010       test byte ptr [esi + 0x125], 0x10
// 0056efa6  741a                 je 0x56efc2
// 0056efa8  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0056efae  41                   inc ecx
// 0056efaf  51                   push ecx
// 0056efb0  56                   push esi
// 0056efb1  e8ea350000           call 0x5725a0
// 0056efb6  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 0056efbc  83c408               add esp, 8
// 0056efbf  c60001               mov byte ptr [eax], 1
// 0056efc2  f68625010000e0       test byte ptr [esi + 0x125], 0xe0
// 0056efc9  0f8482000000         je 0x56f051
// 0056efcf  57                   push edi
// 0056efd0  56                   push esi
// 0056efd1  e8ca350000           call 0x5725a0
// 0056efd6  57                   push edi
// 0056efd7  6a00                 push 0
// 0056efd9  50                   push eax
// 0056efda  8986e8000000         mov dword ptr [esi + 0xe8], eax
// 0056efe0  e8ff9b2300           call 0x7a8be4
// 0056efe5  83c414               add esp, 0x14
// 0056efe8  f6862501000020       test byte ptr [esi + 0x125], 0x20
// 0056efef  741a                 je 0x56f00b
// 0056eff1  8b96d8000000         mov edx, dword ptr [esi + 0xd8]
// 0056eff7  42                   inc edx
// 0056eff8  52                   push edx
// 0056eff9  56                   push esi
// 0056effa  e8a1350000           call 0x5725a0
// 0056efff  8986f4000000         mov dword ptr [esi + 0xf4], eax
// 0056f005  83c408               add esp, 8
// 0056f008  c60002               mov byte ptr [eax], 2
// 0056f00b  f6862501000040       test byte ptr [esi + 0x125], 0x40
// 0056f012  741a                 je 0x56f02e
// 0056f014  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 0056f01a  40                   inc eax
// 0056f01b  50                   push eax
// 0056f01c  56                   push esi
// 0056f01d  e87e350000           call 0x5725a0
// 0056f022  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 0056f028  83c408               add esp, 8
// 0056f02b  c60003               mov byte ptr [eax], 3
// 0056f02e  f6862501000080       test byte ptr [esi + 0x125], 0x80
// 0056f035  741a                 je 0x56f051
// 0056f037  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0056f03d  41                   inc ecx
// 0056f03e  51                   push ecx
// 0056f03f  56                   push esi
// 0056f040  e85b350000           call 0x5725a0
// 0056f045  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0056f04b  83c408               add esp, 8
// 0056f04e  c60004               mov byte ptr [eax], 4
// 0056f051  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 0056f058  5f                   pop edi
// 0056f059  7446                 je 0x56f0a1
// 0056f05b  f6467002             test byte ptr [esi + 0x70], 2
// 0056f05f  7526                 jne 0x56f087
// 0056f061  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 0056f067  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0056f06d  83c207               add edx, 7
// 0056f070  c1ea03               shr edx, 3
// 0056f073  83c007               add eax, 7
// 0056f076  c1e803               shr eax, 3
// 0056f079  8996d0000000         mov dword ptr [esi + 0xd0], edx
// 0056f07f  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 0056f085  eb32                 jmp 0x56f0b9
// 0056f087  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 0056f08d  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 0056f093  898ed0000000         mov dword ptr [esi + 0xd0], ecx
// 0056f099  8996d4000000         mov dword ptr [esi + 0xd4], edx
// 0056f09f  eb18                 jmp 0x56f0b9
// 0056f0a1  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 0056f0a7  8b8ec8000000         mov ecx, dword ptr [esi + 0xc8]
// 0056f0ad  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0056f0b3  898ed4000000         mov dword ptr [esi + 0xd4], ecx
// 0056f0b9  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 0056f0bf  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0056f0c5  899684000000         mov dword ptr [esi + 0x84], edx
// 0056f0cb  898680000000         mov dword ptr [esi + 0x80], eax
// 0056f0d1  5e                   pop esi
// 0056f0d2  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_start_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
