// from server: 100% by auto
// roc 2011-06 00561330  unit: seg_00560000  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00561330
//
// 00561330  83ec10               sub esp, 0x10
// 00561333  55                   push ebp
// 00561334  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00561338  56                   push esi
// 00561339  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056133d  85ed                 test ebp, ebp
// 0056133f  0f8487000000         je 0x5613cc
// 00561345  8b556c               mov edx, dword ptr [ebp + 0x6c]
// 00561348  f7c200000c00         test edx, 0xc0000
// 0056134e  746e                 je 0x5613be
// 00561350  803e23               cmp byte ptr [esi], 0x23
// 00561353  7553                 jne 0x5613a8
// 00561355  b801000000           mov eax, 1
// 0056135a  b120                 mov cl, 0x20
// 0056135c  8d642400             lea esp, [esp]
// 00561360  380c30               cmp byte ptr [eax + esi], cl
// 00561363  7411                 je 0x561376
// 00561365  384c3001             cmp byte ptr [eax + esi + 1], cl
// 00561369  740a                 je 0x561375
// 0056136b  83c002               add eax, 2
// 0056136e  83f80f               cmp eax, 0xf
// 00561371  7ced                 jl 0x561360
// 00561373  eb01                 jmp 0x561376
// 00561375  40                   inc eax
// 00561376  f7c200000800         test edx, 0x80000
// 0056137c  7426                 je 0x5613a4
// 0056137e  57                   push edi
// 0056137f  8d78ff               lea edi, [eax - 1]
// 00561382  33c9                 xor ecx, ecx
// 00561384  85ff                 test edi, edi
// 00561386  7e14                 jle 0x56139c
// 00561388  8d4601               lea eax, [esi + 1]
// 0056138b  57                   push edi
// 0056138c  50                   push eax
// 0056138d  8d442414             lea eax, [esp + 0x14]
// 00561391  50                   push eax
// 00561392  e845a22a00           call 0x80b5dc
// 00561397  83c40c               add esp, 0xc
// 0056139a  8bcf                 mov ecx, edi
// 0056139c  c6440c0b00           mov byte ptr [esp + ecx + 0xb], 0
// 005613a1  5f                   pop edi
// 005613a2  eb16                 jmp 0x5613ba
// 005613a4  03f0                 add esi, eax
// 005613a6  eb16                 jmp 0x5613be
// 005613a8  f7c200000800         test edx, 0x80000
// 005613ae  740e                 je 0x5613be
// 005613b0  c644240830           mov byte ptr [esp + 8], 0x30
// 005613b5  c644240900           mov byte ptr [esp + 9], 0
// 005613ba  8d742408             lea esi, [esp + 8]
// 005613be  8b4540               mov eax, dword ptr [ebp + 0x40]
// 005613c1  85c0                 test eax, eax
// 005613c3  7407                 je 0x5613cc
// 005613c5  56                   push esi
// 005613c6  55                   push ebp
// 005613c7  ffd0                 call eax
// 005613c9  83c408               add esp, 8
// 005613cc  55                   push ebp
// 005613cd  8bc6                 mov eax, esi
// 005613cf  e8ecfcffff           call 0x5610c0
// 005613d4  83c404               add esp, 4
// 005613d7  5e                   pop esi
// 005613d8  5d                   pop ebp
// 005613d9  83c410               add esp, 0x10
// 005613dc  c3                   ret 
// library libpng-1.2.32/pngerror.c (function _png_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngerror.c
