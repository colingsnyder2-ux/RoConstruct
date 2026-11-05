// from server: 100% by auto
// roc 2009-06 0058c220  unit: seg_00580000  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058c220
//
// 0058c220  83ec1c               sub esp, 0x1c
// 0058c223  53                   push ebx
// 0058c224  b043                 mov al, 0x43
// 0058c226  56                   push esi
// 0058c227  8b742428             mov esi, dword ptr [esp + 0x28]
// 0058c22b  57                   push edi
// 0058c22c  33ff                 xor edi, edi
// 0058c22e  8844240d             mov byte ptr [esp + 0xd], al
// 0058c232  8844240e             mov byte ptr [esp + 0xe], al
// 0058c236  8b442430             mov eax, dword ptr [esp + 0x30]
// 0058c23a  c644240c69           mov byte ptr [esp + 0xc], 0x69
// 0058c23f  c644240f50           mov byte ptr [esp + 0xf], 0x50
// 0058c244  c644241000           mov byte ptr [esp + 0x10], 0
// 0058c249  897c241c             mov dword ptr [esp + 0x1c], edi
// 0058c24d  897c2420             mov dword ptr [esp + 0x20], edi
// 0058c251  897c2424             mov dword ptr [esp + 0x24], edi
// 0058c255  897c2414             mov dword ptr [esp + 0x14], edi
// 0058c259  897c2418             mov dword ptr [esp + 0x18], edi
// 0058c25d  3bc7                 cmp eax, edi
// 0058c25f  0f84f6000000         je 0x58c35b
// 0058c265  8d4c2430             lea ecx, [esp + 0x30]
// 0058c269  51                   push ecx
// 0058c26a  50                   push eax
// 0058c26b  56                   push esi
// 0058c26c  e8afecffff           call 0x58af20
// 0058c271  8bd8                 mov ebx, eax
// 0058c273  83c40c               add esp, 0xc
// 0058c276  3bdf                 cmp ebx, edi
// 0058c278  0f84dd000000         je 0x58c35b
// 0058c27e  397c2434             cmp dword ptr [esp + 0x34], edi
// 0058c282  740e                 je 0x58c292
// 0058c284  6830f08c00           push 0x8cf030
// 0058c289  56                   push esi
// 0058c28a  e8811f0000           call 0x58e210
// 0058c28f  83c408               add esp, 8
// 0058c292  8b442438             mov eax, dword ptr [esp + 0x38]
// 0058c296  55                   push ebp
// 0058c297  3bc7                 cmp eax, edi
// 0058c299  7504                 jne 0x58c29f
// 0058c29b  33ed                 xor ebp, ebp
// 0058c29d  eb70                 jmp 0x58c30f
// 0058c29f  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0058c2a3  83fd03               cmp ebp, 3
// 0058c2a6  7e1e                 jle 0x58c2c6
// 0058c2a8  0fb638               movzx edi, byte ptr [eax]
// 0058c2ab  0fb65001             movzx edx, byte ptr [eax + 1]
// 0058c2af  0fb64802             movzx ecx, byte ptr [eax + 2]
// 0058c2b3  c1e708               shl edi, 8
// 0058c2b6  0bfa                 or edi, edx
// 0058c2b8  0fb65003             movzx edx, byte ptr [eax + 3]
// 0058c2bc  c1e708               shl edi, 8
// 0058c2bf  0bf9                 or edi, ecx
// 0058c2c1  c1e708               shl edi, 8
// 0058c2c4  0bfa                 or edi, edx
// 0058c2c6  3bef                 cmp ebp, edi
// 0058c2c8  7d16                 jge 0x58c2e0
// 0058c2ca  6800f08c00           push 0x8cf000
// 0058c2cf  56                   push esi
// 0058c2d0  e83b1f0000           call 0x58e210
// 0058c2d5  83c408               add esp, 8
// 0058c2d8  5d                   pop ebp
// 0058c2d9  5f                   pop edi
// 0058c2da  5e                   pop esi
// 0058c2db  5b                   pop ebx
// 0058c2dc  83c41c               add esp, 0x1c
// 0058c2df  c3                   ret 
// 0058c2e0  7e14                 jle 0x58c2f6
// 0058c2e2  68ccef8c00           push 0x8cefcc
// 0058c2e7  56                   push esi
// 0058c2e8  e8231f0000           call 0x58e210
// 0058c2ed  8b442444             mov eax, dword ptr [esp + 0x44]
// 0058c2f1  83c408               add esp, 8
// 0058c2f4  8bef                 mov ebp, edi
// 0058c2f6  85ed                 test ebp, ebp
// 0058c2f8  7415                 je 0x58c30f
// 0058c2fa  50                   push eax
// 0058c2fb  8d7c241c             lea edi, [esp + 0x1c]
// 0058c2ff  33c0                 xor eax, eax
// 0058c301  8bcd                 mov ecx, ebp
// 0058c303  8bd6                 mov edx, esi
// 0058c305  e8a6e6ffff           call 0x58a9b0
// 0058c30a  83c404               add esp, 4
// 0058c30d  8be8                 mov ebp, eax
// 0058c30f  8d442b02             lea eax, [ebx + ebp + 2]
// 0058c313  50                   push eax
// 0058c314  8d4c2414             lea ecx, [esp + 0x14]
// 0058c318  51                   push ecx
// 0058c319  56                   push esi
// 0058c31a  e8a1e5ffff           call 0x58a8c0
// 0058c31f  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0058c323  c6441f0100           mov byte ptr [edi + ebx + 1], 0
// 0058c328  83c302               add ebx, 2
// 0058c32b  53                   push ebx
// 0058c32c  57                   push edi
// 0058c32d  56                   push esi
// 0058c32e  e8fde5ffff           call 0x58a930
// 0058c333  83c418               add esp, 0x18
// 0058c336  85ed                 test ebp, ebp
// 0058c338  7409                 je 0x58c343
// 0058c33a  8d442418             lea eax, [esp + 0x18]
// 0058c33e  e8ede8ffff           call 0x58ac30
// 0058c343  56                   push esi
// 0058c344  e827e6ffff           call 0x58a970
// 0058c349  57                   push edi
// 0058c34a  56                   push esi
// 0058c34b  e860290000           call 0x58ecb0
// 0058c350  83c40c               add esp, 0xc
// 0058c353  5d                   pop ebp
// 0058c354  5f                   pop edi
// 0058c355  5e                   pop esi
// 0058c356  5b                   pop ebx
// 0058c357  83c41c               add esp, 0x1c
// 0058c35a  c3                   ret 
// 0058c35b  68b0ef8c00           push 0x8cefb0
// 0058c360  56                   push esi
// 0058c361  e8aa1e0000           call 0x58e210
// 0058c366  83c408               add esp, 8
// 0058c369  5f                   pop edi
// 0058c36a  5e                   pop esi
// 0058c36b  5b                   pop ebx
// 0058c36c  83c41c               add esp, 0x1c
// 0058c36f  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
