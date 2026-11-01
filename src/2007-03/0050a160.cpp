// from server: 100% by auto
// roc 2007-03 0050a160  unit: seg_00500000  size: 318 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050a160
//
// 0050a160  51                   push ecx
// 0050a161  53                   push ebx
// 0050a162  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0050a166  8b83d8000000         mov eax, dword ptr [ebx + 0xd8]
// 0050a16c  55                   push ebp
// 0050a16d  56                   push esi
// 0050a16e  8b742420             mov esi, dword ptr [esp + 0x20]
// 0050a172  03c6                 add eax, esi
// 0050a174  57                   push edi
// 0050a175  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0050a179  c1e004               shl eax, 4
// 0050a17c  50                   push eax
// 0050a17d  57                   push edi
// 0050a17e  e89dee0000           call 0x519020
// 0050a183  8be8                 mov ebp, eax
// 0050a185  83c408               add esp, 8
// 0050a188  85ed                 test ebp, ebp
// 0050a18a  896c2410             mov dword ptr [esp + 0x10], ebp
// 0050a18e  7514                 jne 0x50a1a4
// 0050a190  68700d7a00           push 0x7a0d70
// 0050a195  57                   push edi
// 0050a196  e835e20000           call 0x5183d0
// 0050a19b  83c408               add esp, 8
// 0050a19e  5f                   pop edi
// 0050a19f  5e                   pop esi
// 0050a1a0  5d                   pop ebp
// 0050a1a1  5b                   pop ebx
// 0050a1a2  59                   pop ecx
// 0050a1a3  c3                   ret 
// 0050a1a4  8b8bd8000000         mov ecx, dword ptr [ebx + 0xd8]
// 0050a1aa  8b93d4000000         mov edx, dword ptr [ebx + 0xd4]
// 0050a1b0  c1e104               shl ecx, 4
// 0050a1b3  51                   push ecx
// 0050a1b4  52                   push edx
// 0050a1b5  55                   push ebp
// 0050a1b6  e827501100           call 0x61f1e2
// 0050a1bb  8b83d4000000         mov eax, dword ptr [ebx + 0xd4]
// 0050a1c1  50                   push eax
// 0050a1c2  57                   push edi
// 0050a1c3  e828ee0000           call 0x518ff0
// 0050a1c8  33c0                 xor eax, eax
// 0050a1ca  83c414               add esp, 0x14
// 0050a1cd  3bf0                 cmp esi, eax
// 0050a1cf  8983d4000000         mov dword ptr [ebx + 0xd4], eax
// 0050a1d5  8944241c             mov dword ptr [esp + 0x1c], eax
// 0050a1d9  0f8e9f000000         jle 0x50a27e
// 0050a1df  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0050a1e3  8bb3d8000000         mov esi, dword ptr [ebx + 0xd8]
// 0050a1e9  0374241c             add esi, dword ptr [esp + 0x1c]
// 0050a1ed  8b07                 mov eax, dword ptr [edi]
// 0050a1ef  c1e604               shl esi, 4
// 0050a1f2  03f5                 add esi, ebp
// 0050a1f4  8d6801               lea ebp, [eax + 1]
// 0050a1f7  8a08                 mov cl, byte ptr [eax]
// 0050a1f9  83c001               add eax, 1
// 0050a1fc  84c9                 test cl, cl
// 0050a1fe  75f7                 jne 0x50a1f7
// 0050a200  2bc5                 sub eax, ebp
// 0050a202  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0050a206  83c001               add eax, 1
// 0050a209  50                   push eax
// 0050a20a  55                   push ebp
// 0050a20b  e890ed0000           call 0x518fa0
// 0050a210  8906                 mov dword ptr [esi], eax
// 0050a212  8b0f                 mov ecx, dword ptr [edi]
// 0050a214  83c408               add esp, 8
// 0050a217  8bd0                 mov edx, eax
// 0050a219  8da42400000000       lea esp, [esp]
// 0050a220  8a01                 mov al, byte ptr [ecx]
// 0050a222  8802                 mov byte ptr [edx], al
// 0050a224  83c101               add ecx, 1
// 0050a227  83c201               add edx, 1
// 0050a22a  84c0                 test al, al
// 0050a22c  75f2                 jne 0x50a220
// 0050a22e  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0050a231  c1e104               shl ecx, 4
// 0050a234  51                   push ecx
// 0050a235  55                   push ebp
// 0050a236  e865ed0000           call 0x518fa0
// 0050a23b  894608               mov dword ptr [esi + 8], eax
// 0050a23e  8b570c               mov edx, dword ptr [edi + 0xc]
// 0050a241  8b4f08               mov ecx, dword ptr [edi + 8]
// 0050a244  c1e204               shl edx, 4
// 0050a247  52                   push edx
// 0050a248  51                   push ecx
// 0050a249  50                   push eax
// 0050a24a  e8934f1100           call 0x61f1e2
// 0050a24f  8b570c               mov edx, dword ptr [edi + 0xc]
// 0050a252  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0050a256  89560c               mov dword ptr [esi + 0xc], edx
// 0050a259  8a4704               mov al, byte ptr [edi + 4]
// 0050a25c  884604               mov byte ptr [esi + 4], al
// 0050a25f  8b442430             mov eax, dword ptr [esp + 0x30]
// 0050a263  83c001               add eax, 1
// 0050a266  83c414               add esp, 0x14
// 0050a269  83c710               add edi, 0x10
// 0050a26c  3b442424             cmp eax, dword ptr [esp + 0x24]
// 0050a270  8944241c             mov dword ptr [esp + 0x1c], eax
// 0050a274  0f8c69ffffff         jl 0x50a1e3
// 0050a27a  8b742424             mov esi, dword ptr [esp + 0x24]
// 0050a27e  01b3d8000000         add dword ptr [ebx + 0xd8], esi
// 0050a284  814b0800200000       or dword ptr [ebx + 8], 0x2000
// 0050a28b  838bb800000020       or dword ptr [ebx + 0xb8], 0x20
// 0050a292  5f                   pop edi
// 0050a293  5e                   pop esi
// 0050a294  89abd4000000         mov dword ptr [ebx + 0xd4], ebp
// 0050a29a  5d                   pop ebp
// 0050a29b  5b                   pop ebx
// 0050a29c  59                   pop ecx
// 0050a29d  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_sPLT)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
