// from server: 100% by auto
// roc 2012-06 0064e1b0  unit: seg_00640000  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064e1b0
//
// 0064e1b0  83ec10               sub esp, 0x10
// 0064e1b3  55                   push ebp
// 0064e1b4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0064e1b8  56                   push esi
// 0064e1b9  8b742420             mov esi, dword ptr [esp + 0x20]
// 0064e1bd  85ed                 test ebp, ebp
// 0064e1bf  0f8487000000         je 0x64e24c
// 0064e1c5  8b556c               mov edx, dword ptr [ebp + 0x6c]
// 0064e1c8  f7c200000c00         test edx, 0xc0000
// 0064e1ce  746e                 je 0x64e23e
// 0064e1d0  803e23               cmp byte ptr [esi], 0x23
// 0064e1d3  7553                 jne 0x64e228
// 0064e1d5  b801000000           mov eax, 1
// 0064e1da  b120                 mov cl, 0x20
// 0064e1dc  8d642400             lea esp, [esp]
// 0064e1e0  380c30               cmp byte ptr [eax + esi], cl
// 0064e1e3  7411                 je 0x64e1f6
// 0064e1e5  384c3001             cmp byte ptr [eax + esi + 1], cl
// 0064e1e9  740a                 je 0x64e1f5
// 0064e1eb  83c002               add eax, 2
// 0064e1ee  83f80f               cmp eax, 0xf
// 0064e1f1  7ced                 jl 0x64e1e0
// 0064e1f3  eb01                 jmp 0x64e1f6
// 0064e1f5  40                   inc eax
// 0064e1f6  f7c200000800         test edx, 0x80000
// 0064e1fc  7426                 je 0x64e224
// 0064e1fe  57                   push edi
// 0064e1ff  8d78ff               lea edi, [eax - 1]
// 0064e202  33c9                 xor ecx, ecx
// 0064e204  85ff                 test edi, edi
// 0064e206  7e14                 jle 0x64e21c
// 0064e208  8d4601               lea eax, [esi + 1]
// 0064e20b  57                   push edi
// 0064e20c  50                   push eax
// 0064e20d  8d442414             lea eax, [esp + 0x14]
// 0064e211  50                   push eax
// 0064e212  e845543300           call 0x98365c
// 0064e217  83c40c               add esp, 0xc
// 0064e21a  8bcf                 mov ecx, edi
// 0064e21c  c6440c0b00           mov byte ptr [esp + ecx + 0xb], 0
// 0064e221  5f                   pop edi
// 0064e222  eb16                 jmp 0x64e23a
// 0064e224  03f0                 add esi, eax
// 0064e226  eb16                 jmp 0x64e23e
// 0064e228  f7c200000800         test edx, 0x80000
// 0064e22e  740e                 je 0x64e23e
// 0064e230  c644240830           mov byte ptr [esp + 8], 0x30
// 0064e235  c644240900           mov byte ptr [esp + 9], 0
// 0064e23a  8d742408             lea esi, [esp + 8]
// 0064e23e  8b4540               mov eax, dword ptr [ebp + 0x40]
// 0064e241  85c0                 test eax, eax
// 0064e243  7407                 je 0x64e24c
// 0064e245  56                   push esi
// 0064e246  55                   push ebp
// 0064e247  ffd0                 call eax
// 0064e249  83c408               add esp, 8
// 0064e24c  55                   push ebp
// 0064e24d  8bc6                 mov eax, esi
// 0064e24f  e8ecfcffff           call 0x64df40
// 0064e254  83c404               add esp, 4
// 0064e257  5e                   pop esi
// 0064e258  5d                   pop ebp
// 0064e259  83c410               add esp, 0x10
// 0064e25c  c3                   ret 
// library libpng-1.2.32/pngerror.c (function _png_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngerror.c
