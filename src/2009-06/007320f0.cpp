// from server: 100% by auto
// roc 2009-06 007320f0  unit: CXTPCommandBar  size: 889 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007320f0
//
// 007320f0  83c8ff               or eax, 0xffffffff
// 007320f3  83ec28               sub esp, 0x28
// 007320f6  39442430             cmp dword ptr [esp + 0x30], eax
// 007320fa  740d                 je 0x732109
// 007320fc  c7042401000000       mov dword ptr [esp], 1
// 00732103  39442434             cmp dword ptr [esp + 0x34], eax
// 00732107  7507                 jne 0x732110
// 00732109  c7042400000000       mov dword ptr [esp], 0
// 00732110  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00732114  8d442410             lea eax, [esp + 0x10]
// 00732118  50                   push eax
// 00732119  6a18                 push 0x18
// 0073211b  51                   push ecx
// 0073211c  ff1564e18900         call dword ptr [0x89e164]
// 00732122  85c0                 test eax, eax
// 00732124  7508                 jne 0x73212e
// 00732126  33c0                 xor eax, eax
// 00732128  83c428               add esp, 0x28
// 0073212b  c21000               ret 0x10
// 0073212e  66837c242220         cmp word ptr [esp + 0x22], 0x20
// 00732134  75f0                 jne 0x732126
// 00732136  66837c242001         cmp word ptr [esp + 0x20], 1
// 0073213c  75e8                 jne 0x732126
// 0073213e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00732142  85c0                 test eax, eax
// 00732144  74e0                 je 0x732126
// 00732146  837c241800           cmp dword ptr [esp + 0x18], 0
// 0073214b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0073214f  8954240c             mov dword ptr [esp + 0xc], edx
// 00732153  c744240800000000     mov dword ptr [esp + 8], 0
// 0073215b  0f8efd020000         jle 0x73245e
// 00732161  dd0530b58c00         fld qword ptr [0x8cb530]
// 00732167  53                   push ebx
// 00732168  dd0528b58c00         fld qword ptr [0x8cb528]
// 0073216e  55                   push ebp
// 0073216f  dd05a0308f00         fld qword ptr [0x8f30a0]
// 00732175  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 00732179  dd05703b8b00         fld qword ptr [0x8b3b70]
// 0073217f  56                   push esi
// 00732180  8d7002               lea esi, [eax + 2]
// 00732183  8b442420             mov eax, dword ptr [esp + 0x20]
// 00732187  57                   push edi
// 00732188  89742414             mov dword ptr [esp + 0x14], esi
// 0073218c  33db                 xor ebx, ebx
// 0073218e  85c0                 test eax, eax
// 00732190  0f8e9d020000         jle 0x732433
// 00732196  837c241000           cmp dword ptr [esp + 0x10], 0
// 0073219b  0f8419010000         je 0x7322ba
// 007321a1  0fb646ff             movzx eax, byte ptr [esi - 1]
// 007321a5  0fb64efe             movzx ecx, byte ptr [esi - 2]
// 007321a9  0fb616               movzx edx, byte ptr [esi]
// 007321ac  8944243c             mov dword ptr [esp + 0x3c], eax
// 007321b0  db44243c             fild dword ptr [esp + 0x3c]
// 007321b4  894c243c             mov dword ptr [esp + 0x3c], ecx
// 007321b8  d8cc                 fmul st(4)
// 007321ba  db44243c             fild dword ptr [esp + 0x3c]
// 007321be  8954243c             mov dword ptr [esp + 0x3c], edx
// 007321c2  8b542444             mov edx, dword ptr [esp + 0x44]
// 007321c6  8bc2                 mov eax, edx
// 007321c8  d8cc                 fmul st(4)
// 007321ca  c1e810               shr eax, 0x10
// 007321cd  0fb6c8               movzx ecx, al
// 007321d0  dec1                 faddp st(1)
// 007321d2  db44243c             fild dword ptr [esp + 0x3c]
// 007321d6  894c243c             mov dword ptr [esp + 0x3c], ecx
// 007321da  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007321de  8bc1                 mov eax, ecx
// 007321e0  d8cb                 fmul st(3)
// 007321e2  c1e810               shr eax, 0x10
// 007321e5  0fb6c0               movzx eax, al
// 007321e8  dec1                 faddp st(1)
// 007321ea  d8f1                 fdiv st(1)
// 007321ec  d9e8                 fld1 
// 007321ee  d8e1                 fsub st(1)
// 007321f0  db44243c             fild dword ptr [esp + 0x3c]
// 007321f4  8944243c             mov dword ptr [esp + 0x3c], eax
// 007321f8  d8c9                 fmul st(1)
// 007321fa  db44243c             fild dword ptr [esp + 0x3c]
// 007321fe  d97c243c             fnstcw word ptr [esp + 0x3c]
// 00732202  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 00732207  d8cb                 fmul st(3)
// 00732209  0d000c0000           or eax, 0xc00
// 0073220e  89442448             mov dword ptr [esp + 0x48], eax
// 00732212  dec1                 faddp st(1)
// 00732214  d96c2448             fldcw word ptr [esp + 0x48]
// 00732218  db5c2448             fistp dword ptr [esp + 0x48]
// 0073221c  0fb6442448           movzx eax, byte ptr [esp + 0x48]
// 00732221  8846fe               mov byte ptr [esi - 2], al
// 00732224  8bc2                 mov eax, edx
// 00732226  d96c243c             fldcw word ptr [esp + 0x3c]
// 0073222a  c1e808               shr eax, 8
// 0073222d  0fb6c0               movzx eax, al
// 00732230  8944243c             mov dword ptr [esp + 0x3c], eax
// 00732234  8bc1                 mov eax, ecx
// 00732236  c1e808               shr eax, 8
// 00732239  db44243c             fild dword ptr [esp + 0x3c]
// 0073223d  0fb6c0               movzx eax, al
// 00732240  8944243c             mov dword ptr [esp + 0x3c], eax
// 00732244  0fb6c9               movzx ecx, cl
// 00732247  d8c9                 fmul st(1)
// 00732249  db44243c             fild dword ptr [esp + 0x3c]
// 0073224d  d97c243c             fnstcw word ptr [esp + 0x3c]
// 00732251  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 00732256  d8cb                 fmul st(3)
// 00732258  0d000c0000           or eax, 0xc00
// 0073225d  89442448             mov dword ptr [esp + 0x48], eax
// 00732261  dec1                 faddp st(1)
// 00732263  0fb6d2               movzx edx, dl
// 00732266  d96c2448             fldcw word ptr [esp + 0x48]
// 0073226a  db5c2448             fistp dword ptr [esp + 0x48]
// 0073226e  0fb6442448           movzx eax, byte ptr [esp + 0x48]
// 00732273  8846ff               mov byte ptr [esi - 1], al
// 00732276  d96c243c             fldcw word ptr [esp + 0x3c]
// 0073227a  894c243c             mov dword ptr [esp + 0x3c], ecx
// 0073227e  db44243c             fild dword ptr [esp + 0x3c]
// 00732282  8954243c             mov dword ptr [esp + 0x3c], edx
// 00732286  deca                 fmulp st(2)
// 00732288  db44243c             fild dword ptr [esp + 0x3c]
// 0073228c  d97c243c             fnstcw word ptr [esp + 0x3c]
// 00732290  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 00732295  dec9                 fmulp st(1)
// 00732297  0d000c0000           or eax, 0xc00
// 0073229c  89442448             mov dword ptr [esp + 0x48], eax
// 007322a0  dec1                 faddp st(1)
// 007322a2  d96c2448             fldcw word ptr [esp + 0x48]
// 007322a6  db5c2448             fistp dword ptr [esp + 0x48]
// 007322aa  0fb6442448           movzx eax, byte ptr [esp + 0x48]
// 007322af  8806                 mov byte ptr [esi], al
// 007322b1  d96c243c             fldcw word ptr [esp + 0x3c]
// 007322b5  e969010000           jmp 0x732423
// 007322ba  83fdff               cmp ebp, -1
// 007322bd  0f849c000000         je 0x73235f
// 007322c3  0fb64eff             movzx ecx, byte ptr [esi - 1]
// 007322c7  0fb656fe             movzx edx, byte ptr [esi - 2]
// 007322cb  69c94b020000         imul ecx, ecx, 0x24b
// 007322d1  0fb606               movzx eax, byte ptr [esi]
// 007322d4  6bd272               imul edx, edx, 0x72
// 007322d7  69c02b010000         imul eax, eax, 0x12b
// 007322dd  03ca                 add ecx, edx
// 007322df  03c8                 add ecx, eax
// 007322e1  b8d34d6210           mov eax, 0x10624dd3
// 007322e6  f7e9                 imul ecx
// 007322e8  c1fa06               sar edx, 6
// 007322eb  8bca                 mov ecx, edx
// 007322ed  c1e91f               shr ecx, 0x1f
// 007322f0  03ca                 add ecx, edx
// 007322f2  bfff000000           mov edi, 0xff
// 007322f7  2bf9                 sub edi, ecx
// 007322f9  0faffd               imul edi, ebp
// 007322fc  b881808080           mov eax, 0x80808081
// 00732301  f7ef                 imul edi
// 00732303  03d7                 add edx, edi
// 00732305  c1fa07               sar edx, 7
// 00732308  8bc2                 mov eax, edx
// 0073230a  c1e81f               shr eax, 0x1f
// 0073230d  03c2                 add eax, edx
// 0073230f  03c8                 add ecx, eax
// 00732311  81f9ff000000         cmp ecx, 0xff
// 00732317  7c05                 jl 0x73231e
// 00732319  b9ff000000           mov ecx, 0xff
// 0073231e  884efe               mov byte ptr [esi - 2], cl
// 00732321  884eff               mov byte ptr [esi - 1], cl
// 00732324  880e                 mov byte ptr [esi], cl
// 00732326  0fb64e01             movzx ecx, byte ptr [esi + 1]
// 0073232a  894c243c             mov dword ptr [esp + 0x3c], ecx
// 0073232e  db44243c             fild dword ptr [esp + 0x3c]
// 00732332  d97c243c             fnstcw word ptr [esp + 0x3c]
// 00732336  dc353854a200         fdiv qword ptr [0xa25438]
// 0073233c  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 00732341  0d000c0000           or eax, 0xc00
// 00732346  89442448             mov dword ptr [esp + 0x48], eax
// 0073234a  d96c2448             fldcw word ptr [esp + 0x48]
// 0073234e  db5c2448             fistp dword ptr [esp + 0x48]
// 00732352  8a542448             mov dl, byte ptr [esp + 0x48]
// 00732356  d96c243c             fldcw word ptr [esp + 0x3c]
// 0073235a  e9c1000000           jmp 0x732420
// 0073235f  0fb646ff             movzx eax, byte ptr [esi - 1]
// 00732363  0fb64efe             movzx ecx, byte ptr [esi - 2]
// 00732367  0fb616               movzx edx, byte ptr [esi]
// 0073236a  8944243c             mov dword ptr [esp + 0x3c], eax
// 0073236e  db44243c             fild dword ptr [esp + 0x3c]
// 00732372  894c243c             mov dword ptr [esp + 0x3c], ecx
// 00732376  decc                 fmulp st(4)
// 00732378  db44243c             fild dword ptr [esp + 0x3c]
// 0073237c  8954243c             mov dword ptr [esp + 0x3c], edx
// 00732380  decb                 fmulp st(3)
// 00732382  d9cb                 fxch st(3)
// 00732384  dec2                 faddp st(2)
// 00732386  db44243c             fild dword ptr [esp + 0x3c]
// 0073238a  dec9                 fmulp st(1)
// 0073238c  dec1                 faddp st(1)
// 0073238e  def1                 fdivrp st(1)
// 00732390  dd054054a200         fld qword ptr [0xa25440]
// 00732396  e8557ffeff           call 0x71a2f0
// 0073239b  dd05703b8b00         fld qword ptr [0x8b3b70]
// 007323a1  d97c243c             fnstcw word ptr [esp + 0x3c]
// 007323a5  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 007323aa  dcc9                 fmul st(1), st(0)
// 007323ac  0d000c0000           or eax, 0xc00
// 007323b1  d9c9                 fxch st(1)
// 007323b3  89442448             mov dword ptr [esp + 0x48], eax
// 007323b7  d96c2448             fldcw word ptr [esp + 0x48]
// 007323bb  db5c2448             fistp dword ptr [esp + 0x48]
// 007323bf  8a442448             mov al, byte ptr [esp + 0x48]
// 007323c3  0fb64e01             movzx ecx, byte ptr [esi + 1]
// 007323c7  8846fe               mov byte ptr [esi - 2], al
// 007323ca  d96c243c             fldcw word ptr [esp + 0x3c]
// 007323ce  8846ff               mov byte ptr [esi - 1], al
// 007323d1  0fb6c0               movzx eax, al
// 007323d4  894c243c             mov dword ptr [esp + 0x3c], ecx
// 007323d8  8806                 mov byte ptr [esi], al
// 007323da  db44243c             fild dword ptr [esp + 0x3c]
// 007323de  d97c243c             fnstcw word ptr [esp + 0x3c]
// 007323e2  dc353854a200         fdiv qword ptr [0xa25438]
// 007323e8  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 007323ed  0d000c0000           or eax, 0xc00
// 007323f2  89442448             mov dword ptr [esp + 0x48], eax
// 007323f6  d96c2448             fldcw word ptr [esp + 0x48]
// 007323fa  db5c2448             fistp dword ptr [esp + 0x48]
// 007323fe  8a542448             mov dl, byte ptr [esp + 0x48]
// 00732402  d96c243c             fldcw word ptr [esp + 0x3c]
// 00732406  dd05a0308f00         fld qword ptr [0x8f30a0]
// 0073240c  dd0528b58c00         fld qword ptr [0x8cb528]
// 00732412  dd0530b58c00         fld qword ptr [0x8cb530]
// 00732418  d9cb                 fxch st(3)
// 0073241a  d9c9                 fxch st(1)
// 0073241c  d9ca                 fxch st(2)
// 0073241e  d9c9                 fxch st(1)
// 00732420  885601               mov byte ptr [esi + 1], dl
// 00732423  8b442424             mov eax, dword ptr [esp + 0x24]
// 00732427  43                   inc ebx
// 00732428  83c604               add esi, 4
// 0073242b  3bd8                 cmp ebx, eax
// 0073242d  0f8c63fdffff         jl 0x732196
// 00732433  8b742414             mov esi, dword ptr [esp + 0x14]
// 00732437  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0073243b  0374241c             add esi, dword ptr [esp + 0x1c]
// 0073243f  41                   inc ecx
// 00732440  3b4c2428             cmp ecx, dword ptr [esp + 0x28]
// 00732444  89742414             mov dword ptr [esp + 0x14], esi
// 00732448  894c2418             mov dword ptr [esp + 0x18], ecx
// 0073244c  0f8c3afdffff         jl 0x73218c
// 00732452  ddd8                 fstp st(0)
// 00732454  5f                   pop edi
// 00732455  ddda                 fstp st(2)
// 00732457  5e                   pop esi
// 00732458  ddd8                 fstp st(0)
// 0073245a  5d                   pop ebp
// 0073245b  ddd8                 fstp st(0)
// 0073245d  5b                   pop ebx
// 0073245e  b801000000           mov eax, 1
// 00732463  83c428               add esp, 0x28
// 00732466  c21000               ret 0x10
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?DoDisableBitmap@CXTPImageManager@@AAEHPAUHBITMAP__@@KKH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
