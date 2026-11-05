// from server: 100% by auto
// roc 2009-12 0060e270  unit: seg_00600000  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060e270
//
// 0060e270  83ec1c               sub esp, 0x1c
// 0060e273  53                   push ebx
// 0060e274  b043                 mov al, 0x43
// 0060e276  56                   push esi
// 0060e277  8b742428             mov esi, dword ptr [esp + 0x28]
// 0060e27b  57                   push edi
// 0060e27c  33ff                 xor edi, edi
// 0060e27e  8844240d             mov byte ptr [esp + 0xd], al
// 0060e282  8844240e             mov byte ptr [esp + 0xe], al
// 0060e286  8b442430             mov eax, dword ptr [esp + 0x30]
// 0060e28a  c644240c69           mov byte ptr [esp + 0xc], 0x69
// 0060e28f  c644240f50           mov byte ptr [esp + 0xf], 0x50
// 0060e294  c644241000           mov byte ptr [esp + 0x10], 0
// 0060e299  897c241c             mov dword ptr [esp + 0x1c], edi
// 0060e29d  897c2420             mov dword ptr [esp + 0x20], edi
// 0060e2a1  897c2424             mov dword ptr [esp + 0x24], edi
// 0060e2a5  897c2414             mov dword ptr [esp + 0x14], edi
// 0060e2a9  897c2418             mov dword ptr [esp + 0x18], edi
// 0060e2ad  3bc7                 cmp eax, edi
// 0060e2af  0f84f6000000         je 0x60e3ab
// 0060e2b5  8d4c2430             lea ecx, [esp + 0x30]
// 0060e2b9  51                   push ecx
// 0060e2ba  50                   push eax
// 0060e2bb  56                   push esi
// 0060e2bc  e8afecffff           call 0x60cf70
// 0060e2c1  8bd8                 mov ebx, eax
// 0060e2c3  83c40c               add esp, 0xc
// 0060e2c6  3bdf                 cmp ebx, edi
// 0060e2c8  0f84dd000000         je 0x60e3ab
// 0060e2ce  397c2434             cmp dword ptr [esp + 0x34], edi
// 0060e2d2  740e                 je 0x60e2e2
// 0060e2d4  68c85e9c00           push 0x9c5ec8
// 0060e2d9  56                   push esi
// 0060e2da  e8611f0000           call 0x610240
// 0060e2df  83c408               add esp, 8
// 0060e2e2  8b442438             mov eax, dword ptr [esp + 0x38]
// 0060e2e6  55                   push ebp
// 0060e2e7  3bc7                 cmp eax, edi
// 0060e2e9  7504                 jne 0x60e2ef
// 0060e2eb  33ed                 xor ebp, ebp
// 0060e2ed  eb70                 jmp 0x60e35f
// 0060e2ef  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0060e2f3  83fd03               cmp ebp, 3
// 0060e2f6  7e1e                 jle 0x60e316
// 0060e2f8  0fb638               movzx edi, byte ptr [eax]
// 0060e2fb  0fb65001             movzx edx, byte ptr [eax + 1]
// 0060e2ff  0fb64802             movzx ecx, byte ptr [eax + 2]
// 0060e303  c1e708               shl edi, 8
// 0060e306  0bfa                 or edi, edx
// 0060e308  0fb65003             movzx edx, byte ptr [eax + 3]
// 0060e30c  c1e708               shl edi, 8
// 0060e30f  0bf9                 or edi, ecx
// 0060e311  c1e708               shl edi, 8
// 0060e314  0bfa                 or edi, edx
// 0060e316  3bef                 cmp ebp, edi
// 0060e318  7d16                 jge 0x60e330
// 0060e31a  68985e9c00           push 0x9c5e98
// 0060e31f  56                   push esi
// 0060e320  e81b1f0000           call 0x610240
// 0060e325  83c408               add esp, 8
// 0060e328  5d                   pop ebp
// 0060e329  5f                   pop edi
// 0060e32a  5e                   pop esi
// 0060e32b  5b                   pop ebx
// 0060e32c  83c41c               add esp, 0x1c
// 0060e32f  c3                   ret 
// 0060e330  7e14                 jle 0x60e346
// 0060e332  68645e9c00           push 0x9c5e64
// 0060e337  56                   push esi
// 0060e338  e8031f0000           call 0x610240
// 0060e33d  8b442444             mov eax, dword ptr [esp + 0x44]
// 0060e341  83c408               add esp, 8
// 0060e344  8bef                 mov ebp, edi
// 0060e346  85ed                 test ebp, ebp
// 0060e348  7415                 je 0x60e35f
// 0060e34a  50                   push eax
// 0060e34b  8d7c241c             lea edi, [esp + 0x1c]
// 0060e34f  33c0                 xor eax, eax
// 0060e351  8bcd                 mov ecx, ebp
// 0060e353  8bd6                 mov edx, esi
// 0060e355  e8a6e6ffff           call 0x60ca00
// 0060e35a  83c404               add esp, 4
// 0060e35d  8be8                 mov ebp, eax
// 0060e35f  8d442b02             lea eax, [ebx + ebp + 2]
// 0060e363  50                   push eax
// 0060e364  8d4c2414             lea ecx, [esp + 0x14]
// 0060e368  51                   push ecx
// 0060e369  56                   push esi
// 0060e36a  e8a1e5ffff           call 0x60c910
// 0060e36f  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0060e373  c6441f0100           mov byte ptr [edi + ebx + 1], 0
// 0060e378  83c302               add ebx, 2
// 0060e37b  53                   push ebx
// 0060e37c  57                   push edi
// 0060e37d  56                   push esi
// 0060e37e  e8fde5ffff           call 0x60c980
// 0060e383  83c418               add esp, 0x18
// 0060e386  85ed                 test ebp, ebp
// 0060e388  7409                 je 0x60e393
// 0060e38a  8d442418             lea eax, [esp + 0x18]
// 0060e38e  e8ede8ffff           call 0x60cc80
// 0060e393  56                   push esi
// 0060e394  e827e6ffff           call 0x60c9c0
// 0060e399  57                   push edi
// 0060e39a  56                   push esi
// 0060e39b  e840290000           call 0x610ce0
// 0060e3a0  83c40c               add esp, 0xc
// 0060e3a3  5d                   pop ebp
// 0060e3a4  5f                   pop edi
// 0060e3a5  5e                   pop esi
// 0060e3a6  5b                   pop ebx
// 0060e3a7  83c41c               add esp, 0x1c
// 0060e3aa  c3                   ret 
// 0060e3ab  68485e9c00           push 0x9c5e48
// 0060e3b0  56                   push esi
// 0060e3b1  e88a1e0000           call 0x610240
// 0060e3b6  83c408               add esp, 8
// 0060e3b9  5f                   pop edi
// 0060e3ba  5e                   pop esi
// 0060e3bb  5b                   pop ebx
// 0060e3bc  83c41c               add esp, 0x1c
// 0060e3bf  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
