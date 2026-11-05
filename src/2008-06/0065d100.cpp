// from server: 100% by auto
// roc 2008-06 0065d100  unit: RBX::BallBallContact  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065d100
//
// 0065d100  55                   push ebp
// 0065d101  8bec                 mov ebp, esp
// 0065d103  83e4c0               and esp, 0xffffffc0
// 0065d106  83ec3c               sub esp, 0x3c
// 0065d109  53                   push ebx
// 0065d10a  8bd8                 mov ebx, eax
// 0065d10c  8b4608               mov eax, dword ptr [esi + 8]
// 0065d10f  b903000000           mov ecx, 3
// 0065d114  3bc1                 cmp eax, ecx
// 0065d116  7506                 jne 0x65d11e
// 0065d118  89742418             mov dword ptr [esp + 0x18], esi
// 0065d11c  eb41                 jmp 0x65d15f
// 0065d11e  83f804               cmp eax, 4
// 0065d121  0f8519010000         jne 0x65d240
// 0065d127  8b0e                 mov ecx, dword ptr [esi]
// 0065d129  8d442418             lea eax, [esp + 0x18]
// 0065d12d  50                   push eax
// 0065d12e  83c110               add ecx, 0x10
// 0065d131  51                   push ecx
// 0065d132  e89955fcff           call 0x6226d0
// 0065d137  83c408               add esp, 8
// 0065d13a  85c0                 test eax, eax
// 0065d13c  0f84fe000000         je 0x65d240
// 0065d142  dd442418             fld qword ptr [esp + 0x18]
// 0065d146  8d542430             lea edx, [esp + 0x30]
// 0065d14a  dd5c2430             fstp qword ptr [esp + 0x30]
// 0065d14e  c744243803000000     mov dword ptr [esp + 0x38], 3
// 0065d156  89542418             mov dword ptr [esp + 0x18], edx
// 0065d15a  b903000000           mov ecx, 3
// 0065d15f  8b4308               mov eax, dword ptr [ebx + 8]
// 0065d162  3bc1                 cmp eax, ecx
// 0065d164  743d                 je 0x65d1a3
// 0065d166  83f804               cmp eax, 4
// 0065d169  0f85d1000000         jne 0x65d240
// 0065d16f  8b0b                 mov ecx, dword ptr [ebx]
// 0065d171  8d442420             lea eax, [esp + 0x20]
// 0065d175  50                   push eax
// 0065d176  83c110               add ecx, 0x10
// 0065d179  51                   push ecx
// 0065d17a  e85155fcff           call 0x6226d0
// 0065d17f  83c408               add esp, 8
// 0065d182  85c0                 test eax, eax
// 0065d184  0f84b6000000         je 0x65d240
// 0065d18a  dd442420             fld qword ptr [esp + 0x20]
// 0065d18e  c744242803000000     mov dword ptr [esp + 0x28], 3
// 0065d196  dd5c2420             fstp qword ptr [esp + 0x20]
// 0065d19a  8d5c2420             lea ebx, [esp + 0x20]
// 0065d19e  b903000000           mov ecx, 3
// 0065d1a3  8b542418             mov edx, dword ptr [esp + 0x18]
// 0065d1a7  dd02                 fld qword ptr [edx]
// 0065d1a9  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0065d1ac  dd542418             fst qword ptr [esp + 0x18]
// 0065d1b0  83c0fb               add eax, -5
// 0065d1b3  dd03                 fld qword ptr [ebx]
// 0065d1b5  dd542420             fst qword ptr [esp + 0x20]
// 0065d1b9  83f806               cmp eax, 6
// 0065d1bc  0f87d7000000         ja 0x65d299
// 0065d1c2  ff2485a4d26500       jmp dword ptr [eax*4 + 0x65d2a4]
// 0065d1c9  dec1                 faddp st(1)
// 0065d1cb  894f08               mov dword ptr [edi + 8], ecx
// 0065d1ce  dd1f                 fstp qword ptr [edi]
// 0065d1d0  5b                   pop ebx
// 0065d1d1  8be5                 mov esp, ebp
// 0065d1d3  5d                   pop ebp
// 0065d1d4  c3                   ret 
// 0065d1d5  dee9                 fsubp st(1)
// 0065d1d7  894f08               mov dword ptr [edi + 8], ecx
// 0065d1da  dd1f                 fstp qword ptr [edi]
// 0065d1dc  5b                   pop ebx
// 0065d1dd  8be5                 mov esp, ebp
// 0065d1df  5d                   pop ebp
// 0065d1e0  c3                   ret 
// 0065d1e1  dec9                 fmulp st(1)
// 0065d1e3  894f08               mov dword ptr [edi + 8], ecx
// 0065d1e6  dd1f                 fstp qword ptr [edi]
// 0065d1e8  5b                   pop ebx
// 0065d1e9  8be5                 mov esp, ebp
// 0065d1eb  5d                   pop ebp
// 0065d1ec  c3                   ret 
// 0065d1ed  def9                 fdivp st(1)
// 0065d1ef  894f08               mov dword ptr [edi + 8], ecx
// 0065d1f2  dd1f                 fstp qword ptr [edi]
// 0065d1f4  5b                   pop ebx
// 0065d1f5  8be5                 mov esp, ebp
// 0065d1f7  5d                   pop ebp
// 0065d1f8  c3                   ret 
// 0065d1f9  def9                 fdivp st(1)
// 0065d1fb  83ec08               sub esp, 8
// 0065d1fe  dd1c24               fstp qword ptr [esp]
// 0065d201  e8aa490400           call 0x6a1bb0
// 0065d206  dc4c2428             fmul qword ptr [esp + 0x28]
// 0065d20a  83c408               add esp, 8
// 0065d20d  c7470803000000       mov dword ptr [edi + 8], 3
// 0065d214  dc6c2418             fsubr qword ptr [esp + 0x18]
// 0065d218  dd1f                 fstp qword ptr [edi]
// 0065d21a  5b                   pop ebx
// 0065d21b  8be5                 mov esp, ebp
// 0065d21d  5d                   pop ebp
// 0065d21e  c3                   ret 
// 0065d21f  e8fc490400           call 0x6a1c20
// 0065d224  dd1f                 fstp qword ptr [edi]
// 0065d226  c7470803000000       mov dword ptr [edi + 8], 3
// 0065d22d  5b                   pop ebx
// 0065d22e  8be5                 mov esp, ebp
// 0065d230  5d                   pop ebp
// 0065d231  c3                   ret 
// 0065d232  ddd8                 fstp st(0)
// 0065d234  894f08               mov dword ptr [edi + 8], ecx
// 0065d237  d9e0                 fchs 
// 0065d239  dd1f                 fstp qword ptr [edi]
// 0065d23b  5b                   pop ebx
// 0065d23c  8be5                 mov esp, ebp
// 0065d23e  5d                   pop ebp
// 0065d23f  c3                   ret 
// 0065d240  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0065d243  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0065d246  50                   push eax
// 0065d247  56                   push esi
// 0065d248  51                   push ecx
// 0065d249  e8b2f3ffff           call 0x65c600
// 0065d24e  83c40c               add esp, 0xc
// 0065d251  83780800             cmp dword ptr [eax + 8], 0
// 0065d255  7511                 jne 0x65d268
// 0065d257  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0065d25a  8b4508               mov eax, dword ptr [ebp + 8]
// 0065d25d  52                   push edx
// 0065d25e  53                   push ebx
// 0065d25f  50                   push eax
// 0065d260  e89bf3ffff           call 0x65c600
// 0065d265  83c40c               add esp, 0xc
// 0065d268  83780806             cmp dword ptr [eax + 8], 6
// 0065d26c  7518                 jne 0x65d286
// 0065d26e  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0065d271  50                   push eax
// 0065d272  51                   push ecx
// 0065d273  8bcb                 mov ecx, ebx
// 0065d275  8bd6                 mov edx, esi
// 0065d277  8bc7                 mov eax, edi
// 0065d279  e832f5ffff           call 0x65c7b0
// 0065d27e  83c408               add esp, 8
// 0065d281  5b                   pop ebx
// 0065d282  8be5                 mov esp, ebp
// 0065d284  5d                   pop ebp
// 0065d285  c3                   ret 
// 0065d286  8b5508               mov edx, dword ptr [ebp + 8]
// 0065d289  53                   push ebx
// 0065d28a  56                   push esi
// 0065d28b  52                   push edx
// 0065d28c  e81f68fcff           call 0x623ab0
// 0065d291  83c40c               add esp, 0xc
// 0065d294  5b                   pop ebx
// 0065d295  8be5                 mov esp, ebp
// 0065d297  5d                   pop ebp
// 0065d298  c3                   ret 
// 0065d299  ddd8                 fstp st(0)
// 0065d29b  5b                   pop ebx
// 0065d29c  ddd8                 fstp st(0)
// 0065d29e  8be5                 mov esp, ebp
// 0065d2a0  5d                   pop ebp
// 0065d2a1  c3                   ret 
// 0065d2a2  8bff                 mov edi, edi
// 0065d2a4  c9                   leave 
// 0065d2a5  d16500               shl dword ptr [ebp], 1
// 0065d2a8  d5d1                 aad 0xd1
// 0065d2aa  6500e1               add cl, ah
// 0065d2ad  d16500               shl dword ptr [ebp], 1
// 0065d2b0  ed                   in eax, dx
// 0065d2b1  d16500               shl dword ptr [ebp], 1
// 0065d2b4  f9                   stc 
// 0065d2b5  d16500               shl dword ptr [ebp], 1
// 0065d2b8  1f                   pop ds
// 0065d2b9  d26500               shl byte ptr [ebp], cl
// 0065d2bc  32d2                 xor dl, dl
// library lua-5.1/lvm.c (function _Arith)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lvm.c
