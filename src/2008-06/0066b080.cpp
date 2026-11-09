// from server: 100% by auto
// roc 2008-06 0066b080  unit: RBX::GroupDragTool  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066b080
//
// 0066b080  83ec10               sub esp, 0x10
// 0066b083  833e05               cmp dword ptr [esi], 5
// 0066b086  756c                 jne 0x66b0f4
// 0066b088  83c9ff               or ecx, 0xffffffff
// 0066b08b  394e10               cmp dword ptr [esi + 0x10], ecx
// 0066b08e  7564                 jne 0x66b0f4
// 0066b090  394e14               cmp dword ptr [esi + 0x14], ecx
// 0066b093  755f                 jne 0x66b0f4
// 0066b095  833805               cmp dword ptr [eax], 5
// 0066b098  755a                 jne 0x66b0f4
// 0066b09a  394810               cmp dword ptr [eax + 0x10], ecx
// 0066b09d  7555                 jne 0x66b0f4
// 0066b09f  394814               cmp dword ptr [eax + 0x14], ecx
// 0066b0a2  7550                 jne 0x66b0f4
// 0066b0a4  dd4608               fld qword ptr [esi + 8]
// 0066b0a7  dd542408             fst qword ptr [esp + 8]
// 0066b0ab  dd4008               fld qword ptr [eax + 8]
// 0066b0ae  8b442414             mov eax, dword ptr [esp + 0x14]
// 0066b0b2  83c0f4               add eax, -0xc
// 0066b0b5  dd1424               fst qword ptr [esp]
// 0066b0b8  83f808               cmp eax, 8
// 0066b0bb  7773                 ja 0x66b130
// 0066b0bd  ff248544b16600       jmp dword ptr [eax*4 + 0x66b144]
// 0066b0c4  dec1                 faddp st(1)
// 0066b0c6  d9c0                 fld st(0)
// 0066b0c8  dde9                 fucomp st(1)
// 0066b0ca  dfe0                 fnstsw ax
// 0066b0cc  f6c444               test ah, 0x44
// 0066b0cf  7a21                 jp 0x66b0f2
// 0066b0d1  dd5e08               fstp qword ptr [esi + 8]
// 0066b0d4  b801000000           mov eax, 1
// 0066b0d9  83c410               add esp, 0x10
// 0066b0dc  c3                   ret 
// 0066b0dd  dee9                 fsubp st(1)
// 0066b0df  ebe5                 jmp 0x66b0c6
// 0066b0e1  dec9                 fmulp st(1)
// 0066b0e3  ebe1                 jmp 0x66b0c6
// 0066b0e5  d9ee                 fldz 
// 0066b0e7  dde9                 fucomp st(1)
// 0066b0e9  dfe0                 fnstsw ax
// 0066b0eb  f6c444               test ah, 0x44
// 0066b0ee  7a0a                 jp 0x66b0fa
// 0066b0f0  ddd8                 fstp st(0)
// 0066b0f2  ddd8                 fstp st(0)
// 0066b0f4  33c0                 xor eax, eax
// 0066b0f6  83c410               add esp, 0x10
// 0066b0f9  c3                   ret 
// 0066b0fa  def9                 fdivp st(1)
// 0066b0fc  ebc8                 jmp 0x66b0c6
// 0066b0fe  d9ee                 fldz 
// 0066b100  dde9                 fucomp st(1)
// 0066b102  dfe0                 fnstsw ax
// 0066b104  f6c444               test ah, 0x44
// 0066b107  7be7                 jnp 0x66b0f0
// 0066b109  def9                 fdivp st(1)
// 0066b10b  83ec08               sub esp, 8
// 0066b10e  dd1c24               fstp qword ptr [esp]
// 0066b111  e89a6a0300           call 0x6a1bb0
// 0066b116  dc4c2408             fmul qword ptr [esp + 8]
// 0066b11a  83c408               add esp, 8
// 0066b11d  dc6c2408             fsubr qword ptr [esp + 8]
// 0066b121  eba3                 jmp 0x66b0c6
// 0066b123  e8f86a0300           call 0x6a1c20
// 0066b128  eb9c                 jmp 0x66b0c6
// 0066b12a  ddd8                 fstp st(0)
// 0066b12c  d9e0                 fchs 
// 0066b12e  eb96                 jmp 0x66b0c6
// 0066b130  ddd8                 fstp st(0)
// 0066b132  b801000000           mov eax, 1
// 0066b137  ddd8                 fstp st(0)
// 0066b139  d9ee                 fldz 
// 0066b13b  dd5e08               fstp qword ptr [esi + 8]
// 0066b13e  83c410               add esp, 0x10
// 0066b141  c3                   ret 
// 0066b142  8bff                 mov edi, edi
// 0066b144  c4b06600ddb0         les esi, ptr [eax - 0x4f22ff9a]
// 0066b14a  6600e1               add cl, ah
// 0066b14d  b066                 mov al, 0x66
// 0066b14f  00e5                 add ch, ah
// 0066b151  b066                 mov al, 0x66
// 0066b153  00fe                 add dh, bh
// 0066b155  b066                 mov al, 0x66
// 0066b157  0023                 add byte ptr [ebx], ah
// 0066b159  b166                 mov cl, 0x66
// 0066b15b  002a                 add byte ptr [edx], ch
// 0066b15d  b166                 mov cl, 0x66
// 0066b15f  0030                 add byte ptr [eax], dh
// 0066b161  b166                 mov cl, 0x66
// 0066b163  00f0                 add al, dh
// 0066b165  b066                 mov al, 0x66
// library lua-5.1/lcode.c (function _constfolding)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
