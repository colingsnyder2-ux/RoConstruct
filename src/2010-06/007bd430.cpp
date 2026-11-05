// from server: 100% by auto
// roc 2010-06 007bd430  unit: CXTPCommandBar  size: 889 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bd430
//
// 007bd430  83c8ff               or eax, 0xffffffff
// 007bd433  83ec28               sub esp, 0x28
// 007bd436  39442430             cmp dword ptr [esp + 0x30], eax
// 007bd43a  740d                 je 0x7bd449
// 007bd43c  c7042401000000       mov dword ptr [esp], 1
// 007bd443  39442434             cmp dword ptr [esp + 0x34], eax
// 007bd447  7507                 jne 0x7bd450
// 007bd449  c7042400000000       mov dword ptr [esp], 0
// 007bd450  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007bd454  8d442410             lea eax, [esp + 0x10]
// 007bd458  50                   push eax
// 007bd459  6a18                 push 0x18
// 007bd45b  51                   push ecx
// 007bd45c  ff15bca09e00         call dword ptr [0x9ea0bc]
// 007bd462  85c0                 test eax, eax
// 007bd464  7508                 jne 0x7bd46e
// 007bd466  33c0                 xor eax, eax
// 007bd468  83c428               add esp, 0x28
// 007bd46b  c21000               ret 0x10
// 007bd46e  66837c242220         cmp word ptr [esp + 0x22], 0x20
// 007bd474  75f0                 jne 0x7bd466
// 007bd476  66837c242001         cmp word ptr [esp + 0x20], 1
// 007bd47c  75e8                 jne 0x7bd466
// 007bd47e  8b442424             mov eax, dword ptr [esp + 0x24]
// 007bd482  85c0                 test eax, eax
// 007bd484  74e0                 je 0x7bd466
// 007bd486  837c241800           cmp dword ptr [esp + 0x18], 0
// 007bd48b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007bd48f  8954240c             mov dword ptr [esp + 0xc], edx
// 007bd493  c744240800000000     mov dword ptr [esp + 8], 0
// 007bd49b  0f8efd020000         jle 0x7bd79e
// 007bd4a1  dd055802a200         fld qword ptr [0xa20258]
// 007bd4a7  53                   push ebx
// 007bd4a8  dd055002a200         fld qword ptr [0xa20250]
// 007bd4ae  55                   push ebp
// 007bd4af  dd057073a500         fld qword ptr [0xa57370]
// 007bd4b5  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 007bd4b9  dd058076a000         fld qword ptr [0xa07680]
// 007bd4bf  56                   push esi
// 007bd4c0  8d7002               lea esi, [eax + 2]
// 007bd4c3  8b442420             mov eax, dword ptr [esp + 0x20]
// 007bd4c7  57                   push edi
// 007bd4c8  89742414             mov dword ptr [esp + 0x14], esi
// 007bd4cc  33db                 xor ebx, ebx
// 007bd4ce  85c0                 test eax, eax
// 007bd4d0  0f8e9d020000         jle 0x7bd773
// 007bd4d6  837c241000           cmp dword ptr [esp + 0x10], 0
// 007bd4db  0f8419010000         je 0x7bd5fa
// 007bd4e1  0fb646ff             movzx eax, byte ptr [esi - 1]
// 007bd4e5  0fb64efe             movzx ecx, byte ptr [esi - 2]
// 007bd4e9  0fb616               movzx edx, byte ptr [esi]
// 007bd4ec  8944243c             mov dword ptr [esp + 0x3c], eax
// 007bd4f0  db44243c             fild dword ptr [esp + 0x3c]
// 007bd4f4  894c243c             mov dword ptr [esp + 0x3c], ecx
// 007bd4f8  d8cc                 fmul st(4)
// 007bd4fa  db44243c             fild dword ptr [esp + 0x3c]
// 007bd4fe  8954243c             mov dword ptr [esp + 0x3c], edx
// 007bd502  8b542444             mov edx, dword ptr [esp + 0x44]
// 007bd506  8bc2                 mov eax, edx
// 007bd508  d8cc                 fmul st(4)
// 007bd50a  c1e810               shr eax, 0x10
// 007bd50d  0fb6c8               movzx ecx, al
// 007bd510  dec1                 faddp st(1)
// 007bd512  db44243c             fild dword ptr [esp + 0x3c]
// 007bd516  894c243c             mov dword ptr [esp + 0x3c], ecx
// 007bd51a  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007bd51e  8bc1                 mov eax, ecx
// 007bd520  d8cb                 fmul st(3)
// 007bd522  c1e810               shr eax, 0x10
// 007bd525  0fb6c0               movzx eax, al
// 007bd528  dec1                 faddp st(1)
// 007bd52a  d8f1                 fdiv st(1)
// 007bd52c  d9e8                 fld1 
// 007bd52e  d8e1                 fsub st(1)
// 007bd530  db44243c             fild dword ptr [esp + 0x3c]
// 007bd534  8944243c             mov dword ptr [esp + 0x3c], eax
// 007bd538  d8c9                 fmul st(1)
// 007bd53a  db44243c             fild dword ptr [esp + 0x3c]
// 007bd53e  d97c243c             fnstcw word ptr [esp + 0x3c]
// 007bd542  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 007bd547  d8cb                 fmul st(3)
// 007bd549  0d000c0000           or eax, 0xc00
// 007bd54e  89442448             mov dword ptr [esp + 0x48], eax
// 007bd552  dec1                 faddp st(1)
// 007bd554  d96c2448             fldcw word ptr [esp + 0x48]
// 007bd558  db5c2448             fistp dword ptr [esp + 0x48]
// 007bd55c  0fb6442448           movzx eax, byte ptr [esp + 0x48]
// 007bd561  8846fe               mov byte ptr [esi - 2], al
// 007bd564  8bc2                 mov eax, edx
// 007bd566  d96c243c             fldcw word ptr [esp + 0x3c]
// 007bd56a  c1e808               shr eax, 8
// 007bd56d  0fb6c0               movzx eax, al
// 007bd570  8944243c             mov dword ptr [esp + 0x3c], eax
// 007bd574  8bc1                 mov eax, ecx
// 007bd576  c1e808               shr eax, 8
// 007bd579  db44243c             fild dword ptr [esp + 0x3c]
// 007bd57d  0fb6c0               movzx eax, al
// 007bd580  8944243c             mov dword ptr [esp + 0x3c], eax
// 007bd584  0fb6c9               movzx ecx, cl
// 007bd587  d8c9                 fmul st(1)
// 007bd589  db44243c             fild dword ptr [esp + 0x3c]
// 007bd58d  d97c243c             fnstcw word ptr [esp + 0x3c]
// 007bd591  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 007bd596  d8cb                 fmul st(3)
// 007bd598  0d000c0000           or eax, 0xc00
// 007bd59d  89442448             mov dword ptr [esp + 0x48], eax
// 007bd5a1  dec1                 faddp st(1)
// 007bd5a3  0fb6d2               movzx edx, dl
// 007bd5a6  d96c2448             fldcw word ptr [esp + 0x48]
// 007bd5aa  db5c2448             fistp dword ptr [esp + 0x48]
// 007bd5ae  0fb6442448           movzx eax, byte ptr [esp + 0x48]
// 007bd5b3  8846ff               mov byte ptr [esi - 1], al
// 007bd5b6  d96c243c             fldcw word ptr [esp + 0x3c]
// 007bd5ba  894c243c             mov dword ptr [esp + 0x3c], ecx
// 007bd5be  db44243c             fild dword ptr [esp + 0x3c]
// 007bd5c2  8954243c             mov dword ptr [esp + 0x3c], edx
// 007bd5c6  deca                 fmulp st(2)
// 007bd5c8  db44243c             fild dword ptr [esp + 0x3c]
// 007bd5cc  d97c243c             fnstcw word ptr [esp + 0x3c]
// 007bd5d0  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 007bd5d5  dec9                 fmulp st(1)
// 007bd5d7  0d000c0000           or eax, 0xc00
// 007bd5dc  89442448             mov dword ptr [esp + 0x48], eax
// 007bd5e0  dec1                 faddp st(1)
// 007bd5e2  d96c2448             fldcw word ptr [esp + 0x48]
// 007bd5e6  db5c2448             fistp dword ptr [esp + 0x48]
// 007bd5ea  0fb6442448           movzx eax, byte ptr [esp + 0x48]
// 007bd5ef  8806                 mov byte ptr [esi], al
// 007bd5f1  d96c243c             fldcw word ptr [esp + 0x3c]
// 007bd5f5  e969010000           jmp 0x7bd763
// 007bd5fa  83fdff               cmp ebp, -1
// 007bd5fd  0f849c000000         je 0x7bd69f
// 007bd603  0fb64eff             movzx ecx, byte ptr [esi - 1]
// 007bd607  0fb656fe             movzx edx, byte ptr [esi - 2]
// 007bd60b  69c94b020000         imul ecx, ecx, 0x24b
// 007bd611  0fb606               movzx eax, byte ptr [esi]
// 007bd614  6bd272               imul edx, edx, 0x72
// 007bd617  69c02b010000         imul eax, eax, 0x12b
// 007bd61d  03ca                 add ecx, edx
// 007bd61f  03c8                 add ecx, eax
// 007bd621  b8d34d6210           mov eax, 0x10624dd3
// 007bd626  f7e9                 imul ecx
// 007bd628  c1fa06               sar edx, 6
// 007bd62b  8bca                 mov ecx, edx
// 007bd62d  c1e91f               shr ecx, 0x1f
// 007bd630  03ca                 add ecx, edx
// 007bd632  bfff000000           mov edi, 0xff
// 007bd637  2bf9                 sub edi, ecx
// 007bd639  0faffd               imul edi, ebp
// 007bd63c  b881808080           mov eax, 0x80808081
// 007bd641  f7ef                 imul edi
// 007bd643  03d7                 add edx, edi
// 007bd645  c1fa07               sar edx, 7
// 007bd648  8bc2                 mov eax, edx
// 007bd64a  c1e81f               shr eax, 0x1f
// 007bd64d  03c2                 add eax, edx
// 007bd64f  03c8                 add ecx, eax
// 007bd651  81f9ff000000         cmp ecx, 0xff
// 007bd657  7c05                 jl 0x7bd65e
// 007bd659  b9ff000000           mov ecx, 0xff
// 007bd65e  884efe               mov byte ptr [esi - 2], cl
// 007bd661  884eff               mov byte ptr [esi - 1], cl
// 007bd664  880e                 mov byte ptr [esi], cl
// 007bd666  0fb64e01             movzx ecx, byte ptr [esi + 1]
// 007bd66a  894c243c             mov dword ptr [esp + 0x3c], ecx
// 007bd66e  db44243c             fild dword ptr [esp + 0x3c]
// 007bd672  d97c243c             fnstcw word ptr [esp + 0x3c]
// 007bd676  dc359063be00         fdiv qword ptr [0xbe6390]
// 007bd67c  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 007bd681  0d000c0000           or eax, 0xc00
// 007bd686  89442448             mov dword ptr [esp + 0x48], eax
// 007bd68a  d96c2448             fldcw word ptr [esp + 0x48]
// 007bd68e  db5c2448             fistp dword ptr [esp + 0x48]
// 007bd692  8a542448             mov dl, byte ptr [esp + 0x48]
// 007bd696  d96c243c             fldcw word ptr [esp + 0x3c]
// 007bd69a  e9c1000000           jmp 0x7bd760
// 007bd69f  0fb646ff             movzx eax, byte ptr [esi - 1]
// 007bd6a3  0fb64efe             movzx ecx, byte ptr [esi - 2]
// 007bd6a7  0fb616               movzx edx, byte ptr [esi]
// 007bd6aa  8944243c             mov dword ptr [esp + 0x3c], eax
// 007bd6ae  db44243c             fild dword ptr [esp + 0x3c]
// 007bd6b2  894c243c             mov dword ptr [esp + 0x3c], ecx
// 007bd6b6  decc                 fmulp st(4)
// 007bd6b8  db44243c             fild dword ptr [esp + 0x3c]
// 007bd6bc  8954243c             mov dword ptr [esp + 0x3c], edx
// 007bd6c0  decb                 fmulp st(3)
// 007bd6c2  d9cb                 fxch st(3)
// 007bd6c4  dec2                 faddp st(2)
// 007bd6c6  db44243c             fild dword ptr [esp + 0x3c]
// 007bd6ca  dec9                 fmulp st(1)
// 007bd6cc  dec1                 faddp st(1)
// 007bd6ce  def1                 fdivrp st(1)
// 007bd6d0  dd059863be00         fld qword ptr [0xbe6398]
// 007bd6d6  e885bbfeff           call 0x7a9260
// 007bd6db  dd058076a000         fld qword ptr [0xa07680]
// 007bd6e1  d97c243c             fnstcw word ptr [esp + 0x3c]
// 007bd6e5  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 007bd6ea  dcc9                 fmul st(1), st(0)
// 007bd6ec  0d000c0000           or eax, 0xc00
// 007bd6f1  d9c9                 fxch st(1)
// 007bd6f3  89442448             mov dword ptr [esp + 0x48], eax
// 007bd6f7  d96c2448             fldcw word ptr [esp + 0x48]
// 007bd6fb  db5c2448             fistp dword ptr [esp + 0x48]
// 007bd6ff  8a442448             mov al, byte ptr [esp + 0x48]
// 007bd703  0fb64e01             movzx ecx, byte ptr [esi + 1]
// 007bd707  8846fe               mov byte ptr [esi - 2], al
// 007bd70a  d96c243c             fldcw word ptr [esp + 0x3c]
// 007bd70e  8846ff               mov byte ptr [esi - 1], al
// 007bd711  0fb6c0               movzx eax, al
// 007bd714  894c243c             mov dword ptr [esp + 0x3c], ecx
// 007bd718  8806                 mov byte ptr [esi], al
// 007bd71a  db44243c             fild dword ptr [esp + 0x3c]
// 007bd71e  d97c243c             fnstcw word ptr [esp + 0x3c]
// 007bd722  dc359063be00         fdiv qword ptr [0xbe6390]
// 007bd728  0fb744243c           movzx eax, word ptr [esp + 0x3c]
// 007bd72d  0d000c0000           or eax, 0xc00
// 007bd732  89442448             mov dword ptr [esp + 0x48], eax
// 007bd736  d96c2448             fldcw word ptr [esp + 0x48]
// 007bd73a  db5c2448             fistp dword ptr [esp + 0x48]
// 007bd73e  8a542448             mov dl, byte ptr [esp + 0x48]
// 007bd742  d96c243c             fldcw word ptr [esp + 0x3c]
// 007bd746  dd057073a500         fld qword ptr [0xa57370]
// 007bd74c  dd055002a200         fld qword ptr [0xa20250]
// 007bd752  dd055802a200         fld qword ptr [0xa20258]
// 007bd758  d9cb                 fxch st(3)
// 007bd75a  d9c9                 fxch st(1)
// 007bd75c  d9ca                 fxch st(2)
// 007bd75e  d9c9                 fxch st(1)
// 007bd760  885601               mov byte ptr [esi + 1], dl
// 007bd763  8b442424             mov eax, dword ptr [esp + 0x24]
// 007bd767  43                   inc ebx
// 007bd768  83c604               add esi, 4
// 007bd76b  3bd8                 cmp ebx, eax
// 007bd76d  0f8c63fdffff         jl 0x7bd4d6
// 007bd773  8b742414             mov esi, dword ptr [esp + 0x14]
// 007bd777  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007bd77b  0374241c             add esi, dword ptr [esp + 0x1c]
// 007bd77f  41                   inc ecx
// 007bd780  3b4c2428             cmp ecx, dword ptr [esp + 0x28]
// 007bd784  89742414             mov dword ptr [esp + 0x14], esi
// 007bd788  894c2418             mov dword ptr [esp + 0x18], ecx
// 007bd78c  0f8c3afdffff         jl 0x7bd4cc
// 007bd792  ddd8                 fstp st(0)
// 007bd794  5f                   pop edi
// 007bd795  ddda                 fstp st(2)
// 007bd797  5e                   pop esi
// 007bd798  ddd8                 fstp st(0)
// 007bd79a  5d                   pop ebp
// 007bd79b  ddd8                 fstp st(0)
// 007bd79d  5b                   pop ebx
// 007bd79e  b801000000           mov eax, 1
// 007bd7a3  83c428               add esp, 0x28
// 007bd7a6  c21000               ret 0x10
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?DoDisableBitmap@CXTPImageManager@@AAEHPAUHBITMAP__@@KKH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
