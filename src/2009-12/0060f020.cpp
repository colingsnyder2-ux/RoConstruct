// from server: 100% by auto
// roc 2009-12 0060f020  unit: seg_00600000  size: 609 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060f020
//
// 0060f020  83ec70               sub esp, 0x70
// 0060f023  53                   push ebx
// 0060f024  55                   push ebp
// 0060f025  bb01000000           mov ebx, 1
// 0060f02a  56                   push esi
// 0060f02b  8bb42480000000       mov esi, dword ptr [esp + 0x80]
// 0060f032  019ee4000000         add dword ptr [esi + 0xe4], ebx
// 0060f038  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 0060f03e  bd04000000           mov ebp, 4
// 0060f043  b802000000           mov eax, 2
// 0060f048  ba08000000           mov edx, 8
// 0060f04d  57                   push edi
// 0060f04e  33ff                 xor edi, edi
// 0060f050  897c242c             mov dword ptr [esp + 0x2c], edi
// 0060f054  896c2430             mov dword ptr [esp + 0x30], ebp
// 0060f058  897c2434             mov dword ptr [esp + 0x34], edi
// 0060f05c  89442438             mov dword ptr [esp + 0x38], eax
// 0060f060  897c243c             mov dword ptr [esp + 0x3c], edi
// 0060f064  895c2440             mov dword ptr [esp + 0x40], ebx
// 0060f068  897c2444             mov dword ptr [esp + 0x44], edi
// 0060f06c  89542410             mov dword ptr [esp + 0x10], edx
// 0060f070  89542414             mov dword ptr [esp + 0x14], edx
// 0060f074  896c2418             mov dword ptr [esp + 0x18], ebp
// 0060f078  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0060f07c  89442420             mov dword ptr [esp + 0x20], eax
// 0060f080  89442424             mov dword ptr [esp + 0x24], eax
// 0060f084  895c2428             mov dword ptr [esp + 0x28], ebx
// 0060f088  897c2464             mov dword ptr [esp + 0x64], edi
// 0060f08c  897c2468             mov dword ptr [esp + 0x68], edi
// 0060f090  896c246c             mov dword ptr [esp + 0x6c], ebp
// 0060f094  897c2470             mov dword ptr [esp + 0x70], edi
// 0060f098  89442474             mov dword ptr [esp + 0x74], eax
// 0060f09c  897c2478             mov dword ptr [esp + 0x78], edi
// 0060f0a0  895c247c             mov dword ptr [esp + 0x7c], ebx
// 0060f0a4  89542448             mov dword ptr [esp + 0x48], edx
// 0060f0a8  8954244c             mov dword ptr [esp + 0x4c], edx
// 0060f0ac  89542450             mov dword ptr [esp + 0x50], edx
// 0060f0b0  896c2454             mov dword ptr [esp + 0x54], ebp
// 0060f0b4  896c2458             mov dword ptr [esp + 0x58], ebp
// 0060f0b8  8944245c             mov dword ptr [esp + 0x5c], eax
// 0060f0bc  89442460             mov dword ptr [esp + 0x60], eax
// 0060f0c0  3b8ed0000000         cmp ecx, dword ptr [esi + 0xd0]
// 0060f0c6  0f82ad010000         jb 0x60f279
// 0060f0cc  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 0060f0d3  0f84f7000000         je 0x60f1d0
// 0060f0d9  89bee4000000         mov dword ptr [esi + 0xe4], edi
// 0060f0df  844670               test byte ptr [esi + 0x70], al
// 0060f0e2  7413                 je 0x60f0f7
// 0060f0e4  fe8624010000         inc byte ptr [esi + 0x124]
// 0060f0ea  8a9e24010000         mov bl, byte ptr [esi + 0x124]
// 0060f0f0  eb6b                 jmp 0x60f15d
// 0060f0f2  33ff                 xor edi, edi
// 0060f0f4  8d6f04               lea ebp, [edi + 4]
// 0060f0f7  fe8624010000         inc byte ptr [esi + 0x124]
// 0060f0fd  8a9e24010000         mov bl, byte ptr [esi + 0x124]
// 0060f103  80fb07               cmp bl, 7
// 0060f106  0f83bc000000         jae 0x60f1c8
// 0060f10c  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0060f112  0fb6cb               movzx ecx, bl
// 0060f115  03c9                 add ecx, ecx
// 0060f117  03c9                 add ecx, ecx
// 0060f119  2b440c2c             sub eax, dword ptr [esp + ecx + 0x2c]
// 0060f11d  8b7c0c10             mov edi, dword ptr [esp + ecx + 0x10]
// 0060f121  33d2                 xor edx, edx
// 0060f123  8d4438ff             lea eax, [eax + edi - 1]
// 0060f127  f7f7                 div edi
// 0060f129  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 0060f12f  2b540c64             sub edx, dword ptr [esp + ecx + 0x64]
// 0060f133  8b6c0c48             mov ebp, dword ptr [esp + ecx + 0x48]
// 0060f137  8bf8                 mov edi, eax
// 0060f139  8d442aff             lea eax, [edx + ebp - 1]
// 0060f13d  33d2                 xor edx, edx
// 0060f13f  f7f5                 div ebp
// 0060f141  89bed4000000         mov dword ptr [esi + 0xd4], edi
// 0060f147  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0060f14d  85ff                 test edi, edi
// 0060f14f  74a1                 je 0x60f0f2
// 0060f151  85c0                 test eax, eax
// 0060f153  749d                 je 0x60f0f2
// 0060f155  33ff                 xor edi, edi
// 0060f157  8d5708               lea edx, [edi + 8]
// 0060f15a  8d6f04               lea ebp, [edi + 4]
// 0060f15d  80fb07               cmp bl, 7
// 0060f160  7366                 jae 0x60f1c8
// 0060f162  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0060f168  3bcf                 cmp ecx, edi
// 0060f16a  0f8409010000         je 0x60f279
// 0060f170  0fb6862b010000       movzx eax, byte ptr [esi + 0x12b]
// 0060f177  0fb69e28010000       movzx ebx, byte ptr [esi + 0x128]
// 0060f17e  0fafc3               imul eax, ebx
// 0060f181  3bc2                 cmp eax, edx
// 0060f183  7c20                 jl 0x60f1a5
// 0060f185  c1e803               shr eax, 3
// 0060f188  0faf86c8000000       imul eax, dword ptr [esi + 0xc8]
// 0060f18f  8bf0                 mov esi, eax
// 0060f191  46                   inc esi
// 0060f192  56                   push esi
// 0060f193  57                   push edi
// 0060f194  51                   push ecx
// 0060f195  e80a591e00           call 0x7f4aa4
// 0060f19a  83c40c               add esp, 0xc
// 0060f19d  5f                   pop edi
// 0060f19e  5e                   pop esi
// 0060f19f  5d                   pop ebp
// 0060f1a0  5b                   pop ebx
// 0060f1a1  83c470               add esp, 0x70
// 0060f1a4  c3                   ret 
// 0060f1a5  8bb6c8000000         mov esi, dword ptr [esi + 0xc8]
// 0060f1ab  0faff0               imul esi, eax
// 0060f1ae  83c607               add esi, 7
// 0060f1b1  c1ee03               shr esi, 3
// 0060f1b4  46                   inc esi
// 0060f1b5  56                   push esi
// 0060f1b6  57                   push edi
// 0060f1b7  51                   push ecx
// 0060f1b8  e8e7581e00           call 0x7f4aa4
// 0060f1bd  83c40c               add esp, 0xc
// 0060f1c0  5f                   pop edi
// 0060f1c1  5e                   pop esi
// 0060f1c2  5d                   pop ebp
// 0060f1c3  5b                   pop ebx
// 0060f1c4  83c470               add esp, 0x70
// 0060f1c7  c3                   ret 
// 0060f1c8  bb01000000           mov ebx, 1
// 0060f1cd  8d4900               lea ecx, [ecx]
// 0060f1d0  8d4674               lea eax, [esi + 0x74]
// 0060f1d3  55                   push ebp
// 0060f1d4  50                   push eax
// 0060f1d5  e8e61b0000           call 0x610dc0
// 0060f1da  83c408               add esp, 8
// 0060f1dd  3bc7                 cmp eax, edi
// 0060f1df  7539                 jne 0x60f21a
// 0060f1e1  39be84000000         cmp dword ptr [esi + 0x84], edi
// 0060f1e7  75e7                 jne 0x60f1d0
// 0060f1e9  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0060f1ef  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0060f1f5  50                   push eax
// 0060f1f6  51                   push ecx
// 0060f1f7  56                   push esi
// 0060f1f8  e843edffff           call 0x60df40
// 0060f1fd  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 0060f203  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0060f209  83c40c               add esp, 0xc
// 0060f20c  899680000000         mov dword ptr [esi + 0x80], edx
// 0060f212  898684000000         mov dword ptr [esi + 0x84], eax
// 0060f218  ebb6                 jmp 0x60f1d0
// 0060f21a  3bc3                 cmp eax, ebx
// 0060f21c  7426                 je 0x60f244
// 0060f21e  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 0060f224  3bc7                 cmp eax, edi
// 0060f226  740c                 je 0x60f234
// 0060f228  50                   push eax
// 0060f229  56                   push esi
// 0060f22a  e8610f0000           call 0x610190
// 0060f22f  83c408               add esp, 8
// 0060f232  eb9c                 jmp 0x60f1d0
// 0060f234  68bc319c00           push 0x9c31bc
// 0060f239  56                   push esi
// 0060f23a  e8510f0000           call 0x610190
// 0060f23f  83c408               add esp, 8
// 0060f242  eb8c                 jmp 0x60f1d0
// 0060f244  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 0060f24a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0060f250  3bc8                 cmp ecx, eax
// 0060f252  7313                 jae 0x60f267
// 0060f254  2bc1                 sub eax, ecx
// 0060f256  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0060f25c  50                   push eax
// 0060f25d  51                   push ecx
// 0060f25e  56                   push esi
// 0060f25f  e8dcecffff           call 0x60df40
// 0060f264  83c40c               add esp, 0xc
// 0060f267  8d4674               lea eax, [esi + 0x74]
// 0060f26a  50                   push eax
// 0060f26b  e8a0310000           call 0x612410
// 0060f270  83c404               add esp, 4
// 0060f273  89bea0000000         mov dword ptr [esi + 0xa0], edi
// 0060f279  5f                   pop edi
// 0060f27a  5e                   pop esi
// 0060f27b  5d                   pop ebp
// 0060f27c  5b                   pop ebx
// 0060f27d  83c470               add esp, 0x70
// 0060f280  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_finish_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
