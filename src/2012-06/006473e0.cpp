// from server: 100% by auto
// roc 2012-06 006473e0  unit: seg_00640000  size: 389 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006473e0
//
// 006473e0  51                   push ecx
// 006473e1  55                   push ebp
// 006473e2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 006473e6  85ed                 test ebp, ebp
// 006473e8  0f8474010000         je 0x647562
// 006473ee  56                   push esi
// 006473ef  8b742414             mov esi, dword ptr [esp + 0x14]
// 006473f3  85f6                 test esi, esi
// 006473f5  0f8466010000         je 0x647561
// 006473fb  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00647401  53                   push ebx
// 00647402  57                   push edi
// 00647403  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00647407  03c7                 add eax, edi
// 00647409  c1e004               shl eax, 4
// 0064740c  50                   push eax
// 0064740d  55                   push ebp
// 0064740e  e83d710000           call 0x64e550
// 00647413  8bd8                 mov ebx, eax
// 00647415  83c408               add esp, 8
// 00647418  895c2410             mov dword ptr [esp + 0x10], ebx
// 0064741c  85db                 test ebx, ebx
// 0064741e  7514                 jne 0x647434
// 00647420  68f063b800           push 0xb863f0
// 00647425  55                   push ebp
// 00647426  e8356e0000           call 0x64e260
// 0064742b  83c408               add esp, 8
// 0064742e  5f                   pop edi
// 0064742f  5b                   pop ebx
// 00647430  5e                   pop esi
// 00647431  5d                   pop ebp
// 00647432  59                   pop ecx
// 00647433  c3                   ret 
// 00647434  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0064743a  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 00647440  c1e104               shl ecx, 4
// 00647443  51                   push ecx
// 00647444  52                   push edx
// 00647445  53                   push ebx
// 00647446  e811c23300           call 0x98365c
// 0064744b  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 00647451  50                   push eax
// 00647452  55                   push ebp
// 00647453  e8c8700000           call 0x64e520
// 00647458  33c0                 xor eax, eax
// 0064745a  83c414               add esp, 0x14
// 0064745d  3bf8                 cmp edi, eax
// 0064745f  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 00647465  89442418             mov dword ptr [esp + 0x18], eax
// 00647469  0f8ed6000000         jle 0x647545
// 0064746f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00647473  83c70c               add edi, 0xc
// 00647476  eb08                 jmp 0x647480
// 00647478  8da42400000000       lea esp, [esp]
// 0064747f  90                   nop 
// 00647480  8bb6d8000000         mov esi, dword ptr [esi + 0xd8]
// 00647486  03742418             add esi, dword ptr [esp + 0x18]
// 0064748a  8b47f4               mov eax, dword ptr [edi - 0xc]
// 0064748d  c1e604               shl esi, 4
// 00647490  03f3                 add esi, ebx
// 00647492  8d5001               lea edx, [eax + 1]
// 00647495  8a08                 mov cl, byte ptr [eax]
// 00647497  40                   inc eax
// 00647498  84c9                 test cl, cl
// 0064749a  75f9                 jne 0x647495
// 0064749c  2bc2                 sub eax, edx
// 0064749e  8d5801               lea ebx, [eax + 1]
// 006474a1  53                   push ebx
// 006474a2  55                   push ebp
// 006474a3  e8a8700000           call 0x64e550
// 006474a8  83c408               add esp, 8
// 006474ab  8906                 mov dword ptr [esi], eax
// 006474ad  85c0                 test eax, eax
// 006474af  7510                 jne 0x6474c1
// 006474b1  68c463b800           push 0xb863c4
// 006474b6  55                   push ebp
// 006474b7  e8a46d0000           call 0x64e260
// 006474bc  83c408               add esp, 8
// 006474bf  eb62                 jmp 0x647523
// 006474c1  8b4ff4               mov ecx, dword ptr [edi - 0xc]
// 006474c4  53                   push ebx
// 006474c5  51                   push ecx
// 006474c6  50                   push eax
// 006474c7  e890c13300           call 0x98365c
// 006474cc  8b07                 mov eax, dword ptr [edi]
// 006474ce  8d1480               lea edx, [eax + eax*4]
// 006474d1  03d2                 add edx, edx
// 006474d3  52                   push edx
// 006474d4  55                   push ebp
// 006474d5  e876700000           call 0x64e550
// 006474da  83c414               add esp, 0x14
// 006474dd  894608               mov dword ptr [esi + 8], eax
// 006474e0  85c0                 test eax, eax
// 006474e2  751f                 jne 0x647503
// 006474e4  68c463b800           push 0xb863c4
// 006474e9  55                   push ebp
// 006474ea  e8716d0000           call 0x64e260
// 006474ef  8b06                 mov eax, dword ptr [esi]
// 006474f1  50                   push eax
// 006474f2  55                   push ebp
// 006474f3  e828700000           call 0x64e520
// 006474f8  83c410               add esp, 0x10
// 006474fb  c70600000000         mov dword ptr [esi], 0
// 00647501  eb20                 jmp 0x647523
// 00647503  8b0f                 mov ecx, dword ptr [edi]
// 00647505  8b57fc               mov edx, dword ptr [edi - 4]
// 00647508  8d0c89               lea ecx, [ecx + ecx*4]
// 0064750b  03c9                 add ecx, ecx
// 0064750d  51                   push ecx
// 0064750e  52                   push edx
// 0064750f  50                   push eax
// 00647510  e847c13300           call 0x98365c
// 00647515  8b07                 mov eax, dword ptr [edi]
// 00647517  89460c               mov dword ptr [esi + 0xc], eax
// 0064751a  8a4ff8               mov cl, byte ptr [edi - 8]
// 0064751d  83c40c               add esp, 0xc
// 00647520  884e04               mov byte ptr [esi + 4], cl
// 00647523  8b442418             mov eax, dword ptr [esp + 0x18]
// 00647527  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0064752b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0064752f  40                   inc eax
// 00647530  83c710               add edi, 0x10
// 00647533  3b442424             cmp eax, dword ptr [esp + 0x24]
// 00647537  89442418             mov dword ptr [esp + 0x18], eax
// 0064753b  0f8c3fffffff         jl 0x647480
// 00647541  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00647545  01bed8000000         add dword ptr [esi + 0xd8], edi
// 0064754b  814e0800200000       or dword ptr [esi + 8], 0x2000
// 00647552  838eb800000020       or dword ptr [esi + 0xb8], 0x20
// 00647559  5f                   pop edi
// 0064755a  899ed4000000         mov dword ptr [esi + 0xd4], ebx
// 00647560  5b                   pop ebx
// 00647561  5e                   pop esi
// 00647562  5d                   pop ebp
// 00647563  59                   pop ecx
// 00647564  c3                   ret 
// library libpng-1.2.29/pngset.c (function _png_set_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngset.c
