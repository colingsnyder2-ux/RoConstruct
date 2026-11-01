// from server: 100% by auto
// roc 2009-12 00809290  unit: CXTPCommandBar  size: 889 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809290
//
// 00809290  83c8ff               or eax, 0xffffffff
// 00809293  83ec28               sub esp, 0x28
// 00809296  39442430             cmp dword ptr [esp + 0x30], eax
// 0080929a  740d                 je 0x8092a9
// 0080929c  c7042401000000       mov dword ptr [esp], 1
// 008092a3  39442434             cmp dword ptr [esp + 0x34], eax
// 008092a7  7507                 jne 0x8092b0
// 008092a9  c7042400000000       mov dword ptr [esp], 0
// 008092b0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008092b4  8d442410             lea eax, [esp + 0x10]
// 008092b8  50                   push eax
// 008092b9  6a18                 push 0x18
// 008092bb  51                   push ecx
// 008092bc  ff155cb19800         call dword ptr [0x98b15c]
// 008092c2  85c0                 test eax, eax
// 008092c4  7508                 jne 0x8092ce
// 008092c6  33c0                 xor eax, eax
// 008092c8  83c428               add esp, 0x28
// 008092cb  c21000               ret 0x10
// 008092ce  66837c242220         cmp word ptr [esp + 0x22], 0x20
// 008092d4  75f0                 jne 0x8092c6
// 008092d6  66837c242001         cmp word ptr [esp + 0x20], 1
// 008092dc  75e8                 jne 0x8092c6
// 008092de  8b442424             mov eax, dword ptr [esp + 0x24]
// 008092e2  85c0                 test eax, eax
// 008092e4  74e0                 je 0x8092c6
// 008092e6  837c241800           cmp dword ptr [esp + 0x18], 0
// 008092eb  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008092ef  8954240c             mov dword ptr [esp + 0xc], edx
// 008092f3  c744240800000000     mov dword ptr [esp + 8], 0
// 008092fb  0f8efd020000         jle 0x8095fe
// 00809301  dd05b8239c00         fld qword ptr [0x9c23b8]
// 00809307  53                   push ebx
// 00809308  dd05b0239c00         fld qword ptr [0x9c23b0]
// 0080930e  55                   push ebp
// 0080930f  dd0588309f00         fld qword ptr [0x9f3088]
// 00809315  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 00809319  dd05e0689a00         fld qword ptr [0x9a68e0]
// 0080931f  56                   push esi
// 00809320  8d7002               lea esi, [eax + 2]
// 00809323  8b442420             mov eax, dword ptr [esp + 0x20]
// 00809327  57                   push edi
// 00809328  89742414             mov dword ptr [esp + 0x14], esi
// 0080932c  33db                 xor ebx, ebx
// 0080932e  85c0                 test eax, eax
// 00809330  0f8e9d020000         jle 0x8095d3
// 00809336  837c241000           cmp dword ptr [esp + 0x10], 0
// 0080933b  0f8419010000         je 0x80945a
// 00809341  0fb646ff             movzx eax, byte ptr [esi - 1]
// 00809345  0fb64efe             movzx ecx, byte ptr [esi - 2]
// 00809349  0fb616               movzx edx, byte ptr [esi]
// 0080934c  8944243c             mov dword ptr [esp + 0x3c], eax
// 00809350  db44243c             fild dword ptr [esp + 0x3c]
// 00809354  894c243c             mov dword ptr [esp + 0x3c], ecx
// 00809358  d8cc                 fmul st(4)
// 0080935a  db44243c             fild dword ptr [esp + 0x3c]
// 0080935e  8954243c             mov dword ptr [esp + 0x3c], edx
// 00809362  8b542444             mov edx, dword ptr [esp + 0x44]
// 00809366  8bc2                 mov eax, edx
// 00809368  d8cc                 fmul st(4)
// 0080936a  c1e810               shr eax, 0x10
// 0080936d  0fb6c8               movzx ecx, al
// 00809370  dec1                 faddp st(1)
// 00809372  db44243c             fild dword ptr [esp + 0x3c]
// 00809376  894c243c             mov dword ptr [esp + 0x3c], ecx
// 0080937a  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0080937e  8bc1                 mov eax, ecx
// 00809380  d8cb                 fmul st(3)
// 00809382  c1e810               shr eax, 0x10
// 00809385  0fb6c0               movzx eax, al
// 00809388  dec1                 faddp st(1)
// 0080938a  d8f1                 fdiv st(1)
// 0080938c  d9e8                 fld1 
// 0080938e  d8e1                 fsub st(1)
// 00809390  db44243c             fild dword ptr [esp + 0x3c]
// 00809394  8944243c             mov dword ptr [esp + 0x3c], eax
// 00809398  d8c9                 fmul st(1)
// 0080939a  db44243c             fild dword ptr [esp + 0x3c]
// 0080939e  d97c243c             fnstcw word ptr [esp + 0x3c]
// 008093a2  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 008093a7  d8cb                 fmul st(3)
// 008093a9  0d000c0000           or eax, 0xc00
// 008093ae  89442448             mov dword ptr [esp + 0x48], eax
// 008093b2  dec1                 faddp st(1)
// 008093b4  d96c2448             fldcw word ptr [esp + 0x48]
// 008093b8  db5c2448             fistp dword ptr [esp + 0x48]
// 008093bc  0fb6442448           movzx eax, byte ptr [esp + 0x48]
// 008093c1  8846fe               mov byte ptr [esi - 2], al
// 008093c4  8bc2                 mov eax, edx
// 008093c6  d96c243c             fldcw word ptr [esp + 0x3c]
// 008093ca  c1e808               shr eax, 8
// 008093cd  0fb6c0               movzx eax, al
// 008093d0  8944243c             mov dword ptr [esp + 0x3c], eax
// 008093d4  8bc1                 mov eax, ecx
// 008093d6  c1e808               shr eax, 8
// 008093d9  db44243c             fild dword ptr [esp + 0x3c]
// 008093dd  0fb6c0               movzx eax, al
// 008093e0  8944243c             mov dword ptr [esp + 0x3c], eax
// 008093e4  0fb6c9               movzx ecx, cl
// 008093e7  d8c9                 fmul st(1)
// 008093e9  db44243c             fild dword ptr [esp + 0x3c]
// 008093ed  d97c243c             fnstcw word ptr [esp + 0x3c]
// 008093f1  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 008093f6  d8cb                 fmul st(3)
// 008093f8  0d000c0000           or eax, 0xc00
// 008093fd  89442448             mov dword ptr [esp + 0x48], eax
// 00809401  dec1                 faddp st(1)
// 00809403  0fb6d2               movzx edx, dl
// 00809406  d96c2448             fldcw word ptr [esp + 0x48]
// 0080940a  db5c2448             fistp dword ptr [esp + 0x48]
// 0080940e  0fb6442448           movzx eax, byte ptr [esp + 0x48]
// 00809413  8846ff               mov byte ptr [esi - 1], al
// 00809416  d96c243c             fldcw word ptr [esp + 0x3c]
// 0080941a  894c243c             mov dword ptr [esp + 0x3c], ecx
// 0080941e  db44243c             fild dword ptr [esp + 0x3c]
// 00809422  8954243c             mov dword ptr [esp + 0x3c], edx
// 00809426  deca                 fmulp st(2)
// 00809428  db44243c             fild dword ptr [esp + 0x3c]
// 0080942c  d97c243c             fnstcw word ptr [esp + 0x3c]
// 00809430  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 00809435  dec9                 fmulp st(1)
// 00809437  0d000c0000           or eax, 0xc00
// 0080943c  89442448             mov dword ptr [esp + 0x48], eax
// 00809440  dec1                 faddp st(1)
// 00809442  d96c2448             fldcw word ptr [esp + 0x48]
// 00809446  db5c2448             fistp dword ptr [esp + 0x48]
// 0080944a  0fb6442448           movzx eax, byte ptr [esp + 0x48]
// 0080944f  8806                 mov byte ptr [esi], al
// 00809451  d96c243c             fldcw word ptr [esp + 0x3c]
// 00809455  e969010000           jmp 0x8095c3
// 0080945a  83fdff               cmp ebp, -1
// 0080945d  0f849c000000         je 0x8094ff
// 00809463  0fb64eff             movzx ecx, byte ptr [esi - 1]
// 00809467  0fb656fe             movzx edx, byte ptr [esi - 2]
// 0080946b  69c94b020000         imul ecx, ecx, 0x24b
// 00809471  0fb606               movzx eax, byte ptr [esi]
// 00809474  6bd272               imul edx, edx, 0x72
// 00809477  69c02b010000         imul eax, eax, 0x12b
// 0080947d  03ca                 add ecx, edx
// 0080947f  03c8                 add ecx, eax
// 00809481  b8d34d6210           mov eax, 0x10624dd3
// 00809486  f7e9                 imul ecx
// 00809488  c1fa06               sar edx, 6
// 0080948b  8bca                 mov ecx, edx
// 0080948d  c1e91f               shr ecx, 0x1f
// 00809490  03ca                 add ecx, edx
// 00809492  bfff000000           mov edi, 0xff
// 00809497  2bf9                 sub edi, ecx
// 00809499  0faffd               imul edi, ebp
// 0080949c  b881808080           mov eax, 0x80808081
// 008094a1  f7ef                 imul edi
// 008094a3  03d7                 add edx, edi
// 008094a5  c1fa07               sar edx, 7
// 008094a8  8bc2                 mov eax, edx
// 008094aa  c1e81f               shr eax, 0x1f
// 008094ad  03c2                 add eax, edx
// 008094af  03c8                 add ecx, eax
// 008094b1  81f9ff000000         cmp ecx, 0xff
// 008094b7  7c05                 jl 0x8094be
// 008094b9  b9ff000000           mov ecx, 0xff
// 008094be  884efe               mov byte ptr [esi - 2], cl
// 008094c1  884eff               mov byte ptr [esi - 1], cl
// 008094c4  880e                 mov byte ptr [esi], cl
// 008094c6  0fb64e01             movzx ecx, byte ptr [esi + 1]
// 008094ca  894c243c             mov dword ptr [esp + 0x3c], ecx
// 008094ce  db44243c             fild dword ptr [esp + 0x3c]
// 008094d2  d97c243c             fnstcw word ptr [esp + 0x3c]
// 008094d6  dc35e055b600         fdiv qword ptr [0xb655e0]
// 008094dc  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 008094e1  0d000c0000           or eax, 0xc00
// 008094e6  89442448             mov dword ptr [esp + 0x48], eax
// 008094ea  d96c2448             fldcw word ptr [esp + 0x48]
// 008094ee  db5c2448             fistp dword ptr [esp + 0x48]
// 008094f2  8a542448             mov dl, byte ptr [esp + 0x48]
// 008094f6  d96c243c             fldcw word ptr [esp + 0x3c]
// 008094fa  e9c1000000           jmp 0x8095c0
// 008094ff  0fb646ff             movzx eax, byte ptr [esi - 1]
// 00809503  0fb64efe             movzx ecx, byte ptr [esi - 2]
// 00809507  0fb616               movzx edx, byte ptr [esi]
// 0080950a  8944243c             mov dword ptr [esp + 0x3c], eax
// 0080950e  db44243c             fild dword ptr [esp + 0x3c]
// 00809512  894c243c             mov dword ptr [esp + 0x3c], ecx
// 00809516  decc                 fmulp st(4)
// 00809518  db44243c             fild dword ptr [esp + 0x3c]
// 0080951c  8954243c             mov dword ptr [esp + 0x3c], edx
// 00809520  decb                 fmulp st(3)
// 00809522  d9cb                 fxch st(3)
// 00809524  dec2                 faddp st(2)
// 00809526  db44243c             fild dword ptr [esp + 0x3c]
// 0080952a  dec9                 fmulp st(1)
// 0080952c  dec1                 faddp st(1)
// 0080952e  def1                 fdivrp st(1)
// 00809530  dd05e855b600         fld qword ptr [0xb655e8]
// 00809536  e875bbfeff           call 0x7f50b0
// 0080953b  dd05e0689a00         fld qword ptr [0x9a68e0]
// 00809541  d97c243c             fnstcw word ptr [esp + 0x3c]
// 00809545  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 0080954a  dcc9                 fmul st(1), st(0)
// 0080954c  0d000c0000           or eax, 0xc00
// 00809551  d9c9                 fxch st(1)
// 00809553  89442448             mov dword ptr [esp + 0x48], eax
// 00809557  d96c2448             fldcw word ptr [esp + 0x48]
// 0080955b  db5c2448             fistp dword ptr [esp + 0x48]
// 0080955f  8a442448             mov al, byte ptr [esp + 0x48]
// 00809563  0fb64e01             movzx ecx, byte ptr [esi + 1]
// 00809567  8846fe               mov byte ptr [esi - 2], al
// 0080956a  d96c243c             fldcw word ptr [esp + 0x3c]
// 0080956e  8846ff               mov byte ptr [esi - 1], al
// 00809571  0fb6c0               movzx eax, al
// 00809574  894c243c             mov dword ptr [esp + 0x3c], ecx
// 00809578  8806                 mov byte ptr [esi], al
// 0080957a  db44243c             fild dword ptr [esp + 0x3c]
// 0080957e  d97c243c             fnstcw word ptr [esp + 0x3c]
// 00809582  dc35e055b600         fdiv qword ptr [0xb655e0]
// 00809588  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 0080958d  0d000c0000           or eax, 0xc00
// 00809592  89442448             mov dword ptr [esp + 0x48], eax
// 00809596  d96c2448             fldcw word ptr [esp + 0x48]
// 0080959a  db5c2448             fistp dword ptr [esp + 0x48]
// 0080959e  8a542448             mov dl, byte ptr [esp + 0x48]
// 008095a2  d96c243c             fldcw word ptr [esp + 0x3c]
// 008095a6  dd0588309f00         fld qword ptr [0x9f3088]
// 008095ac  dd05b0239c00         fld qword ptr [0x9c23b0]
// 008095b2  dd05b8239c00         fld qword ptr [0x9c23b8]
// 008095b8  d9cb                 fxch st(3)
// 008095ba  d9c9                 fxch st(1)
// 008095bc  d9ca                 fxch st(2)
// 008095be  d9c9                 fxch st(1)
// 008095c0  885601               mov byte ptr [esi + 1], dl
// 008095c3  8b442424             mov eax, dword ptr [esp + 0x24]
// 008095c7  43                   inc ebx
// 008095c8  83c604               add esi, 4
// 008095cb  3bd8                 cmp ebx, eax
// 008095cd  0f8c63fdffff         jl 0x809336
// 008095d3  8b742414             mov esi, dword ptr [esp + 0x14]
// 008095d7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008095db  0374241c             add esi, dword ptr [esp + 0x1c]
// 008095df  41                   inc ecx
// 008095e0  3b4c2428             cmp ecx, dword ptr [esp + 0x28]
// 008095e4  89742414             mov dword ptr [esp + 0x14], esi
// 008095e8  894c2418             mov dword ptr [esp + 0x18], ecx
// 008095ec  0f8c3afdffff         jl 0x80932c
// 008095f2  ddd8                 fstp st(0)
// 008095f4  5f                   pop edi
// 008095f5  ddda                 fstp st(2)
// 008095f7  5e                   pop esi
// 008095f8  ddd8                 fstp st(0)
// 008095fa  5d                   pop ebp
// 008095fb  ddd8                 fstp st(0)
// 008095fd  5b                   pop ebx
// 008095fe  b801000000           mov eax, 1
// 00809603  83c428               add esp, 0x28
// 00809606  c21000               ret 0x10
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?DoDisableBitmap@CXTPImageManager@@AAEHPAUHBITMAP__@@KKH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
