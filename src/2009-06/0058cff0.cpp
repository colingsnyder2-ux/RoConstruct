// from server: 100% by auto
// roc 2009-06 0058cff0  unit: seg_00580000  size: 609 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058cff0
//
// 0058cff0  83ec70               sub esp, 0x70
// 0058cff3  53                   push ebx
// 0058cff4  55                   push ebp
// 0058cff5  bb01000000           mov ebx, 1
// 0058cffa  56                   push esi
// 0058cffb  8bb42480000000       mov esi, dword ptr [esp + 0x80]
// 0058d002  019ee4000000         add dword ptr [esi + 0xe4], ebx
// 0058d008  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 0058d00e  bd04000000           mov ebp, 4
// 0058d013  b802000000           mov eax, 2
// 0058d018  ba08000000           mov edx, 8
// 0058d01d  57                   push edi
// 0058d01e  33ff                 xor edi, edi
// 0058d020  897c242c             mov dword ptr [esp + 0x2c], edi
// 0058d024  896c2430             mov dword ptr [esp + 0x30], ebp
// 0058d028  897c2434             mov dword ptr [esp + 0x34], edi
// 0058d02c  89442438             mov dword ptr [esp + 0x38], eax
// 0058d030  897c243c             mov dword ptr [esp + 0x3c], edi
// 0058d034  895c2440             mov dword ptr [esp + 0x40], ebx
// 0058d038  897c2444             mov dword ptr [esp + 0x44], edi
// 0058d03c  89542410             mov dword ptr [esp + 0x10], edx
// 0058d040  89542414             mov dword ptr [esp + 0x14], edx
// 0058d044  896c2418             mov dword ptr [esp + 0x18], ebp
// 0058d048  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0058d04c  89442420             mov dword ptr [esp + 0x20], eax
// 0058d050  89442424             mov dword ptr [esp + 0x24], eax
// 0058d054  895c2428             mov dword ptr [esp + 0x28], ebx
// 0058d058  897c2464             mov dword ptr [esp + 0x64], edi
// 0058d05c  897c2468             mov dword ptr [esp + 0x68], edi
// 0058d060  896c246c             mov dword ptr [esp + 0x6c], ebp
// 0058d064  897c2470             mov dword ptr [esp + 0x70], edi
// 0058d068  89442474             mov dword ptr [esp + 0x74], eax
// 0058d06c  897c2478             mov dword ptr [esp + 0x78], edi
// 0058d070  895c247c             mov dword ptr [esp + 0x7c], ebx
// 0058d074  89542448             mov dword ptr [esp + 0x48], edx
// 0058d078  8954244c             mov dword ptr [esp + 0x4c], edx
// 0058d07c  89542450             mov dword ptr [esp + 0x50], edx
// 0058d080  896c2454             mov dword ptr [esp + 0x54], ebp
// 0058d084  896c2458             mov dword ptr [esp + 0x58], ebp
// 0058d088  8944245c             mov dword ptr [esp + 0x5c], eax
// 0058d08c  89442460             mov dword ptr [esp + 0x60], eax
// 0058d090  3b8ed0000000         cmp ecx, dword ptr [esi + 0xd0]
// 0058d096  0f82ad010000         jb 0x58d249
// 0058d09c  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 0058d0a3  0f84f7000000         je 0x58d1a0
// 0058d0a9  89bee4000000         mov dword ptr [esi + 0xe4], edi
// 0058d0af  844670               test byte ptr [esi + 0x70], al
// 0058d0b2  7413                 je 0x58d0c7
// 0058d0b4  fe8624010000         inc byte ptr [esi + 0x124]
// 0058d0ba  8a9e24010000         mov bl, byte ptr [esi + 0x124]
// 0058d0c0  eb6b                 jmp 0x58d12d
// 0058d0c2  33ff                 xor edi, edi
// 0058d0c4  8d6f04               lea ebp, [edi + 4]
// 0058d0c7  fe8624010000         inc byte ptr [esi + 0x124]
// 0058d0cd  8a9e24010000         mov bl, byte ptr [esi + 0x124]
// 0058d0d3  80fb07               cmp bl, 7
// 0058d0d6  0f83bc000000         jae 0x58d198
// 0058d0dc  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0058d0e2  0fb6cb               movzx ecx, bl
// 0058d0e5  03c9                 add ecx, ecx
// 0058d0e7  03c9                 add ecx, ecx
// 0058d0e9  2b440c2c             sub eax, dword ptr [esp + ecx + 0x2c]
// 0058d0ed  8b7c0c10             mov edi, dword ptr [esp + ecx + 0x10]
// 0058d0f1  33d2                 xor edx, edx
// 0058d0f3  8d4438ff             lea eax, [eax + edi - 1]
// 0058d0f7  f7f7                 div edi
// 0058d0f9  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 0058d0ff  2b540c64             sub edx, dword ptr [esp + ecx + 0x64]
// 0058d103  8b6c0c48             mov ebp, dword ptr [esp + ecx + 0x48]
// 0058d107  8bf8                 mov edi, eax
// 0058d109  8d442aff             lea eax, [edx + ebp - 1]
// 0058d10d  33d2                 xor edx, edx
// 0058d10f  f7f5                 div ebp
// 0058d111  89bed4000000         mov dword ptr [esi + 0xd4], edi
// 0058d117  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0058d11d  85ff                 test edi, edi
// 0058d11f  74a1                 je 0x58d0c2
// 0058d121  85c0                 test eax, eax
// 0058d123  749d                 je 0x58d0c2
// 0058d125  33ff                 xor edi, edi
// 0058d127  8d5708               lea edx, [edi + 8]
// 0058d12a  8d6f04               lea ebp, [edi + 4]
// 0058d12d  80fb07               cmp bl, 7
// 0058d130  7366                 jae 0x58d198
// 0058d132  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0058d138  3bcf                 cmp ecx, edi
// 0058d13a  0f8409010000         je 0x58d249
// 0058d140  0fb6862b010000       movzx eax, byte ptr [esi + 0x12b]
// 0058d147  0fb69e28010000       movzx ebx, byte ptr [esi + 0x128]
// 0058d14e  0fafc3               imul eax, ebx
// 0058d151  3bc2                 cmp eax, edx
// 0058d153  7c20                 jl 0x58d175
// 0058d155  c1e803               shr eax, 3
// 0058d158  0faf86c8000000       imul eax, dword ptr [esi + 0xc8]
// 0058d15f  8bf0                 mov esi, eax
// 0058d161  46                   inc esi
// 0058d162  56                   push esi
// 0058d163  57                   push edi
// 0058d164  51                   push ecx
// 0058d165  e80acb1800           call 0x719c74
// 0058d16a  83c40c               add esp, 0xc
// 0058d16d  5f                   pop edi
// 0058d16e  5e                   pop esi
// 0058d16f  5d                   pop ebp
// 0058d170  5b                   pop ebx
// 0058d171  83c470               add esp, 0x70
// 0058d174  c3                   ret 
// 0058d175  8bb6c8000000         mov esi, dword ptr [esi + 0xc8]
// 0058d17b  0faff0               imul esi, eax
// 0058d17e  83c607               add esi, 7
// 0058d181  c1ee03               shr esi, 3
// 0058d184  46                   inc esi
// 0058d185  56                   push esi
// 0058d186  57                   push edi
// 0058d187  51                   push ecx
// 0058d188  e8e7ca1800           call 0x719c74
// 0058d18d  83c40c               add esp, 0xc
// 0058d190  5f                   pop edi
// 0058d191  5e                   pop esi
// 0058d192  5d                   pop ebp
// 0058d193  5b                   pop ebx
// 0058d194  83c470               add esp, 0x70
// 0058d197  c3                   ret 
// 0058d198  bb01000000           mov ebx, 1
// 0058d19d  8d4900               lea ecx, [ecx]
// 0058d1a0  8d4674               lea eax, [esi + 0x74]
// 0058d1a3  55                   push ebp
// 0058d1a4  50                   push eax
// 0058d1a5  e8e61b0000           call 0x58ed90
// 0058d1aa  83c408               add esp, 8
// 0058d1ad  3bc7                 cmp eax, edi
// 0058d1af  7539                 jne 0x58d1ea
// 0058d1b1  39be84000000         cmp dword ptr [esi + 0x84], edi
// 0058d1b7  75e7                 jne 0x58d1a0
// 0058d1b9  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0058d1bf  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0058d1c5  50                   push eax
// 0058d1c6  51                   push ecx
// 0058d1c7  56                   push esi
// 0058d1c8  e823edffff           call 0x58bef0
// 0058d1cd  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 0058d1d3  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0058d1d9  83c40c               add esp, 0xc
// 0058d1dc  899680000000         mov dword ptr [esi + 0x80], edx
// 0058d1e2  898684000000         mov dword ptr [esi + 0x84], eax
// 0058d1e8  ebb6                 jmp 0x58d1a0
// 0058d1ea  3bc3                 cmp eax, ebx
// 0058d1ec  7426                 je 0x58d214
// 0058d1ee  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 0058d1f4  3bc7                 cmp eax, edi
// 0058d1f6  740c                 je 0x58d204
// 0058d1f8  50                   push eax
// 0058d1f9  56                   push esi
// 0058d1fa  e8610f0000           call 0x58e160
// 0058d1ff  83c408               add esp, 8
// 0058d202  eb9c                 jmp 0x58d1a0
// 0058d204  6814c38c00           push 0x8cc314
// 0058d209  56                   push esi
// 0058d20a  e8510f0000           call 0x58e160
// 0058d20f  83c408               add esp, 8
// 0058d212  eb8c                 jmp 0x58d1a0
// 0058d214  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 0058d21a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0058d220  3bc8                 cmp ecx, eax
// 0058d222  7313                 jae 0x58d237
// 0058d224  2bc1                 sub eax, ecx
// 0058d226  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0058d22c  50                   push eax
// 0058d22d  51                   push ecx
// 0058d22e  56                   push esi
// 0058d22f  e8bcecffff           call 0x58bef0
// 0058d234  83c40c               add esp, 0xc
// 0058d237  8d4674               lea eax, [esi + 0x74]
// 0058d23a  50                   push eax
// 0058d23b  e8b0310000           call 0x5903f0
// 0058d240  83c404               add esp, 4
// 0058d243  89bea0000000         mov dword ptr [esi + 0xa0], edi
// 0058d249  5f                   pop edi
// 0058d24a  5e                   pop esi
// 0058d24b  5d                   pop ebp
// 0058d24c  5b                   pop ebx
// 0058d24d  83c470               add esp, 0x70
// 0058d250  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_finish_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
