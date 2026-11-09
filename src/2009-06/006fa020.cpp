// from server: 100% by auto
// roc 2009-06 006fa020  unit: RBX::GroupDragTool  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fa020
//
// 006fa020  83ec10               sub esp, 0x10
// 006fa023  833e05               cmp dword ptr [esi], 5
// 006fa026  756c                 jne 0x6fa094
// 006fa028  83c9ff               or ecx, 0xffffffff
// 006fa02b  394e10               cmp dword ptr [esi + 0x10], ecx
// 006fa02e  7564                 jne 0x6fa094
// 006fa030  394e14               cmp dword ptr [esi + 0x14], ecx
// 006fa033  755f                 jne 0x6fa094
// 006fa035  833805               cmp dword ptr [eax], 5
// 006fa038  755a                 jne 0x6fa094
// 006fa03a  394810               cmp dword ptr [eax + 0x10], ecx
// 006fa03d  7555                 jne 0x6fa094
// 006fa03f  394814               cmp dword ptr [eax + 0x14], ecx
// 006fa042  7550                 jne 0x6fa094
// 006fa044  dd4608               fld qword ptr [esi + 8]
// 006fa047  dd542408             fst qword ptr [esp + 8]
// 006fa04b  dd4008               fld qword ptr [eax + 8]
// 006fa04e  8b442414             mov eax, dword ptr [esp + 0x14]
// 006fa052  83c0f4               add eax, -0xc
// 006fa055  dd1424               fst qword ptr [esp]
// 006fa058  83f808               cmp eax, 8
// 006fa05b  7773                 ja 0x6fa0d0
// 006fa05d  ff2485e4a06f00       jmp dword ptr [eax*4 + 0x6fa0e4]
// 006fa064  dec1                 faddp st(1)
// 006fa066  d9c0                 fld st(0)
// 006fa068  dde9                 fucomp st(1)
// 006fa06a  dfe0                 fnstsw ax
// 006fa06c  f6c444               test ah, 0x44
// 006fa06f  7a21                 jp 0x6fa092
// 006fa071  dd5e08               fstp qword ptr [esi + 8]
// 006fa074  b801000000           mov eax, 1
// 006fa079  83c410               add esp, 0x10
// 006fa07c  c3                   ret 
// 006fa07d  dee9                 fsubp st(1)
// 006fa07f  ebe5                 jmp 0x6fa066
// 006fa081  dec9                 fmulp st(1)
// 006fa083  ebe1                 jmp 0x6fa066
// 006fa085  d9ee                 fldz 
// 006fa087  dde9                 fucomp st(1)
// 006fa089  dfe0                 fnstsw ax
// 006fa08b  f6c444               test ah, 0x44
// 006fa08e  7a0a                 jp 0x6fa09a
// 006fa090  ddd8                 fstp st(0)
// 006fa092  ddd8                 fstp st(0)
// 006fa094  33c0                 xor eax, eax
// 006fa096  83c410               add esp, 0x10
// 006fa099  c3                   ret 
// 006fa09a  def9                 fdivp st(1)
// 006fa09c  ebc8                 jmp 0x6fa066
// 006fa09e  d9ee                 fldz 
// 006fa0a0  dde9                 fucomp st(1)
// 006fa0a2  dfe0                 fnstsw ax
// 006fa0a4  f6c444               test ah, 0x44
// 006fa0a7  7be7                 jnp 0x6fa090
// 006fa0a9  def9                 fdivp st(1)
// 006fa0ab  83ec08               sub esp, 8
// 006fa0ae  dd1c24               fstp qword ptr [esp]
// 006fa0b1  e8ca010200           call 0x71a280
// 006fa0b6  dc4c2408             fmul qword ptr [esp + 8]
// 006fa0ba  83c408               add esp, 8
// 006fa0bd  dc6c2408             fsubr qword ptr [esp + 8]
// 006fa0c1  eba3                 jmp 0x6fa066
// 006fa0c3  e828020200           call 0x71a2f0
// 006fa0c8  eb9c                 jmp 0x6fa066
// 006fa0ca  ddd8                 fstp st(0)
// 006fa0cc  d9e0                 fchs 
// 006fa0ce  eb96                 jmp 0x6fa066
// 006fa0d0  ddd8                 fstp st(0)
// 006fa0d2  b801000000           mov eax, 1
// 006fa0d7  ddd8                 fstp st(0)
// 006fa0d9  d9ee                 fldz 
// 006fa0db  dd5e08               fstp qword ptr [esi + 8]
// 006fa0de  83c410               add esp, 0x10
// 006fa0e1  c3                   ret 
// 006fa0e2  8bff                 mov edi, edi
// 006fa0e4  64a06f007da0         mov al, byte ptr fs:[0xa07d006f]
// 006fa0ea  6f                   outsd dx, dword ptr [esi]
// 006fa0eb  0081a06f0085         add byte ptr [ecx - 0x7aff9060], al
// 006fa0f1  a06f009ea0           mov al, byte ptr [0xa09e006f]
// 006fa0f6  6f                   outsd dx, dword ptr [esi]
// 006fa0f7  00c3                 add bl, al
// 006fa0f9  a06f00caa0           mov al, byte ptr [0xa0ca006f]
// 006fa0fe  6f                   outsd dx, dword ptr [esi]
// 006fa0ff  00d0                 add al, dl
// 006fa101  a06f0090a0           mov al, byte ptr [0xa090006f]
// 006fa106  6f                   outsd dx, dword ptr [esi]
// library lua-5.1/lcode.c (function _constfolding)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
