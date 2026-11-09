// from server: 100% by auto
// roc 2011-06 0056b6d0  unit: seg_00560000  size: 387 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056b6d0
//
// 0056b6d0  56                   push esi
// 0056b6d1  8b742408             mov esi, dword ptr [esp + 8]
// 0056b6d5  0fb68e2b010000       movzx ecx, byte ptr [esi + 0x12b]
// 0056b6dc  0fb68628010000       movzx eax, byte ptr [esi + 0x128]
// 0056b6e3  0fafc8               imul ecx, eax
// 0056b6e6  83f908               cmp ecx, 8
// 0056b6e9  7c0e                 jl 0x56b6f9
// 0056b6eb  c1e903               shr ecx, 3
// 0056b6ee  0faf8ec8000000       imul ecx, dword ptr [esi + 0xc8]
// 0056b6f5  8bc1                 mov eax, ecx
// 0056b6f7  eb0f                 jmp 0x56b708
// 0056b6f9  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0056b6ff  0fafc1               imul eax, ecx
// 0056b702  83c007               add eax, 7
// 0056b705  c1e803               shr eax, 3
// 0056b708  57                   push edi
// 0056b709  8d7801               lea edi, [eax + 1]
// 0056b70c  57                   push edi
// 0056b70d  56                   push esi
// 0056b70e  e82d5fffff           call 0x561640
// 0056b713  8986ec000000         mov dword ptr [esi + 0xec], eax
// 0056b719  83c408               add esp, 8
// 0056b71c  c60000               mov byte ptr [eax], 0
// 0056b71f  f6862501000010       test byte ptr [esi + 0x125], 0x10
// 0056b726  741a                 je 0x56b742
// 0056b728  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0056b72e  41                   inc ecx
// 0056b72f  51                   push ecx
// 0056b730  56                   push esi
// 0056b731  e80a5fffff           call 0x561640
// 0056b736  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 0056b73c  83c408               add esp, 8
// 0056b73f  c60001               mov byte ptr [eax], 1
// 0056b742  f68625010000e0       test byte ptr [esi + 0x125], 0xe0
// 0056b749  0f8482000000         je 0x56b7d1
// 0056b74f  57                   push edi
// 0056b750  56                   push esi
// 0056b751  e8ea5effff           call 0x561640
// 0056b756  57                   push edi
// 0056b757  6a00                 push 0
// 0056b759  50                   push eax
// 0056b75a  8986e8000000         mov dword ptr [esi + 0xe8], eax
// 0056b760  e87ffb2900           call 0x80b2e4
// 0056b765  83c414               add esp, 0x14
// 0056b768  f6862501000020       test byte ptr [esi + 0x125], 0x20
// 0056b76f  741a                 je 0x56b78b
// 0056b771  8b96d8000000         mov edx, dword ptr [esi + 0xd8]
// 0056b777  42                   inc edx
// 0056b778  52                   push edx
// 0056b779  56                   push esi
// 0056b77a  e8c15effff           call 0x561640
// 0056b77f  8986f4000000         mov dword ptr [esi + 0xf4], eax
// 0056b785  83c408               add esp, 8
// 0056b788  c60002               mov byte ptr [eax], 2
// 0056b78b  f6862501000040       test byte ptr [esi + 0x125], 0x40
// 0056b792  741a                 je 0x56b7ae
// 0056b794  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 0056b79a  40                   inc eax
// 0056b79b  50                   push eax
// 0056b79c  56                   push esi
// 0056b79d  e89e5effff           call 0x561640
// 0056b7a2  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 0056b7a8  83c408               add esp, 8
// 0056b7ab  c60003               mov byte ptr [eax], 3
// 0056b7ae  f6862501000080       test byte ptr [esi + 0x125], 0x80
// 0056b7b5  741a                 je 0x56b7d1
// 0056b7b7  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0056b7bd  41                   inc ecx
// 0056b7be  51                   push ecx
// 0056b7bf  56                   push esi
// 0056b7c0  e87b5effff           call 0x561640
// 0056b7c5  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0056b7cb  83c408               add esp, 8
// 0056b7ce  c60004               mov byte ptr [eax], 4
// 0056b7d1  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 0056b7d8  5f                   pop edi
// 0056b7d9  7446                 je 0x56b821
// 0056b7db  f6467002             test byte ptr [esi + 0x70], 2
// 0056b7df  7526                 jne 0x56b807
// 0056b7e1  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 0056b7e7  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0056b7ed  83c207               add edx, 7
// 0056b7f0  c1ea03               shr edx, 3
// 0056b7f3  83c007               add eax, 7
// 0056b7f6  c1e803               shr eax, 3
// 0056b7f9  8996d0000000         mov dword ptr [esi + 0xd0], edx
// 0056b7ff  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 0056b805  eb32                 jmp 0x56b839
// 0056b807  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 0056b80d  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 0056b813  898ed0000000         mov dword ptr [esi + 0xd0], ecx
// 0056b819  8996d4000000         mov dword ptr [esi + 0xd4], edx
// 0056b81f  eb18                 jmp 0x56b839
// 0056b821  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 0056b827  8b8ec8000000         mov ecx, dword ptr [esi + 0xc8]
// 0056b82d  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0056b833  898ed4000000         mov dword ptr [esi + 0xd4], ecx
// 0056b839  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 0056b83f  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0056b845  899684000000         mov dword ptr [esi + 0x84], edx
// 0056b84b  898680000000         mov dword ptr [esi + 0x80], eax
// 0056b851  5e                   pop esi
// 0056b852  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_start_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
