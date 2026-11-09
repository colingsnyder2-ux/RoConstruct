// from server: 100% by auto
// roc 2009-12 0060d150  unit: seg_00600000  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060d150
//
// 0060d150  83ec08               sub esp, 8
// 0060d153  b074                 mov al, 0x74
// 0060d155  880424               mov byte ptr [esp], al
// 0060d158  88442403             mov byte ptr [esp + 3], al
// 0060d15c  8b442410             mov eax, dword ptr [esp + 0x10]
// 0060d160  56                   push esi
// 0060d161  8b742410             mov esi, dword ptr [esp + 0x10]
// 0060d165  57                   push edi
// 0060d166  c644240945           mov byte ptr [esp + 9], 0x45
// 0060d16b  c644240a58           mov byte ptr [esp + 0xa], 0x58
// 0060d170  c644240c00           mov byte ptr [esp + 0xc], 0
// 0060d175  85c0                 test eax, eax
// 0060d177  0f849c000000         je 0x60d219
// 0060d17d  8d4c2418             lea ecx, [esp + 0x18]
// 0060d181  51                   push ecx
// 0060d182  50                   push eax
// 0060d183  56                   push esi
// 0060d184  e8e7fdffff           call 0x60cf70
// 0060d189  8bf8                 mov edi, eax
// 0060d18b  83c40c               add esp, 0xc
// 0060d18e  85ff                 test edi, edi
// 0060d190  0f8483000000         je 0x60d219
// 0060d196  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060d19a  53                   push ebx
// 0060d19b  55                   push ebp
// 0060d19c  85c0                 test eax, eax
// 0060d19e  7415                 je 0x60d1b5
// 0060d1a0  803800               cmp byte ptr [eax], 0
// 0060d1a3  7410                 je 0x60d1b5
// 0060d1a5  8d5001               lea edx, [eax + 1]
// 0060d1a8  8a08                 mov cl, byte ptr [eax]
// 0060d1aa  40                   inc eax
// 0060d1ab  84c9                 test cl, cl
// 0060d1ad  75f9                 jne 0x60d1a8
// 0060d1af  2bc2                 sub eax, edx
// 0060d1b1  8bd8                 mov ebx, eax
// 0060d1b3  eb02                 jmp 0x60d1b7
// 0060d1b5  33db                 xor ebx, ebx
// 0060d1b7  8d541f01             lea edx, [edi + ebx + 1]
// 0060d1bb  52                   push edx
// 0060d1bc  8d442414             lea eax, [esp + 0x14]
// 0060d1c0  50                   push eax
// 0060d1c1  56                   push esi
// 0060d1c2  e849f7ffff           call 0x60c910
// 0060d1c7  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0060d1cb  83c40c               add esp, 0xc
// 0060d1ce  47                   inc edi
// 0060d1cf  85f6                 test esi, esi
// 0060d1d1  741b                 je 0x60d1ee
// 0060d1d3  85ed                 test ebp, ebp
// 0060d1d5  7417                 je 0x60d1ee
// 0060d1d7  85ff                 test edi, edi
// 0060d1d9  7613                 jbe 0x60d1ee
// 0060d1db  57                   push edi
// 0060d1dc  55                   push ebp
// 0060d1dd  56                   push esi
// 0060d1de  e8ad61ffff           call 0x603390
// 0060d1e3  57                   push edi
// 0060d1e4  55                   push ebp
// 0060d1e5  56                   push esi
// 0060d1e6  e88564ffff           call 0x603670
// 0060d1eb  83c418               add esp, 0x18
// 0060d1ee  85db                 test ebx, ebx
// 0060d1f0  740f                 je 0x60d201
// 0060d1f2  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0060d1f6  53                   push ebx
// 0060d1f7  51                   push ecx
// 0060d1f8  56                   push esi
// 0060d1f9  e882f7ffff           call 0x60c980
// 0060d1fe  83c40c               add esp, 0xc
// 0060d201  56                   push esi
// 0060d202  e8b9f7ffff           call 0x60c9c0
// 0060d207  55                   push ebp
// 0060d208  56                   push esi
// 0060d209  e8d23a0000           call 0x610ce0
// 0060d20e  83c40c               add esp, 0xc
// 0060d211  5d                   pop ebp
// 0060d212  5b                   pop ebx
// 0060d213  5f                   pop edi
// 0060d214  5e                   pop esi
// 0060d215  83c408               add esp, 8
// 0060d218  c3                   ret 
// 0060d219  68705b9c00           push 0x9c5b70
// 0060d21e  56                   push esi
// 0060d21f  e81c300000           call 0x610240
// 0060d224  83c408               add esp, 8
// 0060d227  5f                   pop edi
// 0060d228  5e                   pop esi
// 0060d229  83c408               add esp, 8
// 0060d22c  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tEXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
