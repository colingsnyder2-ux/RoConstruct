// from server: 100% by auto
// roc 2009-06 0058b100  unit: seg_00580000  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058b100
//
// 0058b100  83ec08               sub esp, 8
// 0058b103  b074                 mov al, 0x74
// 0058b105  880424               mov byte ptr [esp], al
// 0058b108  88442403             mov byte ptr [esp + 3], al
// 0058b10c  8b442410             mov eax, dword ptr [esp + 0x10]
// 0058b110  56                   push esi
// 0058b111  8b742410             mov esi, dword ptr [esp + 0x10]
// 0058b115  57                   push edi
// 0058b116  c644240945           mov byte ptr [esp + 9], 0x45
// 0058b11b  c644240a58           mov byte ptr [esp + 0xa], 0x58
// 0058b120  c644240c00           mov byte ptr [esp + 0xc], 0
// 0058b125  85c0                 test eax, eax
// 0058b127  0f849c000000         je 0x58b1c9
// 0058b12d  8d4c2418             lea ecx, [esp + 0x18]
// 0058b131  51                   push ecx
// 0058b132  50                   push eax
// 0058b133  56                   push esi
// 0058b134  e8e7fdffff           call 0x58af20
// 0058b139  8bf8                 mov edi, eax
// 0058b13b  83c40c               add esp, 0xc
// 0058b13e  85ff                 test edi, edi
// 0058b140  0f8483000000         je 0x58b1c9
// 0058b146  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058b14a  53                   push ebx
// 0058b14b  55                   push ebp
// 0058b14c  85c0                 test eax, eax
// 0058b14e  7415                 je 0x58b165
// 0058b150  803800               cmp byte ptr [eax], 0
// 0058b153  7410                 je 0x58b165
// 0058b155  8d5001               lea edx, [eax + 1]
// 0058b158  8a08                 mov cl, byte ptr [eax]
// 0058b15a  40                   inc eax
// 0058b15b  84c9                 test cl, cl
// 0058b15d  75f9                 jne 0x58b158
// 0058b15f  2bc2                 sub eax, edx
// 0058b161  8bd8                 mov ebx, eax
// 0058b163  eb02                 jmp 0x58b167
// 0058b165  33db                 xor ebx, ebx
// 0058b167  8d541f01             lea edx, [edi + ebx + 1]
// 0058b16b  52                   push edx
// 0058b16c  8d442414             lea eax, [esp + 0x14]
// 0058b170  50                   push eax
// 0058b171  56                   push esi
// 0058b172  e849f7ffff           call 0x58a8c0
// 0058b177  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0058b17b  83c40c               add esp, 0xc
// 0058b17e  47                   inc edi
// 0058b17f  85f6                 test esi, esi
// 0058b181  741b                 je 0x58b19e
// 0058b183  85ed                 test ebp, ebp
// 0058b185  7417                 je 0x58b19e
// 0058b187  85ff                 test edi, edi
// 0058b189  7613                 jbe 0x58b19e
// 0058b18b  57                   push edi
// 0058b18c  55                   push ebp
// 0058b18d  56                   push esi
// 0058b18e  e84d64ffff           call 0x5815e0
// 0058b193  57                   push edi
// 0058b194  55                   push ebp
// 0058b195  56                   push esi
// 0058b196  e82567ffff           call 0x5818c0
// 0058b19b  83c418               add esp, 0x18
// 0058b19e  85db                 test ebx, ebx
// 0058b1a0  740f                 je 0x58b1b1
// 0058b1a2  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0058b1a6  53                   push ebx
// 0058b1a7  51                   push ecx
// 0058b1a8  56                   push esi
// 0058b1a9  e882f7ffff           call 0x58a930
// 0058b1ae  83c40c               add esp, 0xc
// 0058b1b1  56                   push esi
// 0058b1b2  e8b9f7ffff           call 0x58a970
// 0058b1b7  55                   push ebp
// 0058b1b8  56                   push esi
// 0058b1b9  e8f23a0000           call 0x58ecb0
// 0058b1be  83c40c               add esp, 0xc
// 0058b1c1  5d                   pop ebp
// 0058b1c2  5b                   pop ebx
// 0058b1c3  5f                   pop edi
// 0058b1c4  5e                   pop esi
// 0058b1c5  83c408               add esp, 8
// 0058b1c8  c3                   ret 
// 0058b1c9  68d8ec8c00           push 0x8cecd8
// 0058b1ce  56                   push esi
// 0058b1cf  e83c300000           call 0x58e210
// 0058b1d4  83c408               add esp, 8
// 0058b1d7  5f                   pop edi
// 0058b1d8  5e                   pop esi
// 0058b1d9  83c408               add esp, 8
// 0058b1dc  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tEXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
