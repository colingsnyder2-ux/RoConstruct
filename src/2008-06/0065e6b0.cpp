// from server: 100% by auto
// roc 2008-06 0065e6b0  unit: seg_00650000  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065e6b0
//
// 0065e6b0  51                   push ecx
// 0065e6b1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0065e6b5  53                   push ebx
// 0065e6b6  55                   push ebp
// 0065e6b7  56                   push esi
// 0065e6b8  57                   push edi
// 0065e6b9  33ff                 xor edi, edi
// 0065e6bb  bd01000000           mov ebp, 1
// 0065e6c0  897c2410             mov dword ptr [esp + 0x10], edi
// 0065e6c4  8bd5                 mov edx, ebp
// 0065e6c6  8b742418             mov esi, dword ptr [esp + 0x18]
// 0065e6ca  8b761c               mov esi, dword ptr [esi + 0x1c]
// 0065e6cd  33db                 xor ebx, ebx
// 0065e6cf  3bd6                 cmp edx, esi
// 0065e6d1  8bca                 mov ecx, edx
// 0065e6d3  7e08                 jle 0x65e6dd
// 0065e6d5  8bce                 mov ecx, esi
// 0065e6d7  3be9                 cmp ebp, ecx
// 0065e6d9  7f3c                 jg 0x65e717
// 0065e6db  eb04                 jmp 0x65e6e1
// 0065e6dd  3bea                 cmp ebp, edx
// 0065e6df  7f27                 jg 0x65e708
// 0065e6e1  8b742418             mov esi, dword ptr [esp + 0x18]
// 0065e6e5  8b760c               mov esi, dword ptr [esi + 0xc]
// 0065e6e8  8bc5                 mov eax, ebp
// 0065e6ea  2bcd                 sub ecx, ebp
// 0065e6ec  c1e004               shl eax, 4
// 0065e6ef  41                   inc ecx
// 0065e6f0  8d7430f8             lea esi, [eax + esi - 8]
// 0065e6f4  03e9                 add ebp, ecx
// 0065e6f6  833e00               cmp dword ptr [esi], 0
// 0065e6f9  7401                 je 0x65e6fc
// 0065e6fb  43                   inc ebx
// 0065e6fc  83c610               add esi, 0x10
// 0065e6ff  83e901               sub ecx, 1
// 0065e702  75f2                 jne 0x65e6f6
// 0065e704  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065e708  011cb8               add dword ptr [eax + edi*4], ebx
// 0065e70b  015c2410             add dword ptr [esp + 0x10], ebx
// 0065e70f  47                   inc edi
// 0065e710  03d2                 add edx, edx
// 0065e712  83ff1a               cmp edi, 0x1a
// 0065e715  7eaf                 jle 0x65e6c6
// 0065e717  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065e71b  5f                   pop edi
// 0065e71c  5e                   pop esi
// 0065e71d  5d                   pop ebp
// 0065e71e  5b                   pop ebx
// 0065e71f  59                   pop ecx
// 0065e720  c3                   ret 
// library lua-5.1/ltable.c (function _numusearray)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
