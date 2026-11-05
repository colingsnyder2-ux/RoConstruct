// from server: 100% by auto
// roc 2009-06 0057fb50  unit: G3D::_internal::DialogTemplate  size: 822 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0057fb50
//
// 0057fb50  51                   push ecx
// 0057fb51  56                   push esi
// 0057fb52  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0057fb56  85f6                 test esi, esi
// 0057fb58  0f8425030000         je 0x57fe83
// 0057fb5e  8b442410             mov eax, dword ptr [esp + 0x10]
// 0057fb62  83f803               cmp eax, 3
// 0057fb65  7c11                 jl 0x57fb78
// 0057fb67  6830c38c00           push 0x8cc330
// 0057fb6c  56                   push esi
// 0057fb6d  e89ee60000           call 0x58e210
// 0057fb72  83c408               add esp, 8
// 0057fb75  5e                   pop esi
// 0057fb76  59                   pop ecx
// 0057fb77  c3                   ret 
// 0057fb78  85c0                 test eax, eax
// 0057fb7a  7505                 jne 0x57fb81
// 0057fb7c  b801000000           mov eax, 1
// 0057fb81  53                   push ebx
// 0057fb82  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0057fb86  55                   push ebp
// 0057fb87  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0057fb8b  57                   push edi
// 0057fb8c  85db                 test ebx, ebx
// 0057fb8e  7c09                 jl 0x57fb99
// 0057fb90  85ed                 test ebp, ebp
// 0057fb92  7405                 je 0x57fb99
// 0057fb94  83f801               cmp eax, 1
// 0057fb97  7502                 jne 0x57fb9b
// 0057fb99  33db                 xor ebx, ebx
// 0057fb9b  dd05f8018c00         fld qword ptr [0x8c01f8]
// 0057fba1  889ef9010000         mov byte ptr [esi + 0x1f9], bl
// 0057fba7  8886f8010000         mov byte ptr [esi + 0x1f8], al
// 0057fbad  85db                 test ebx, ebx
// 0057fbaf  0f8e4e010000         jle 0x57fd03
// 0057fbb5  83befc01000000       cmp dword ptr [esi + 0x1fc], 0
// 0057fbbc  7537                 jne 0x57fbf5
// 0057fbbe  53                   push ebx
// 0057fbbf  ddd8                 fstp st(0)
// 0057fbc1  56                   push esi
// 0057fbc2  e889f00000           call 0x58ec50
// 0057fbc7  8986fc010000         mov dword ptr [esi + 0x1fc], eax
// 0057fbcd  83c408               add esp, 8
// 0057fbd0  33c0                 xor eax, eax
// 0057fbd2  85db                 test ebx, ebx
// 0057fbd4  7e19                 jle 0x57fbef
// 0057fbd6  eb08                 jmp 0x57fbe0
// 0057fbd8  8da42400000000       lea esp, [esp]
// 0057fbdf  90                   nop 
// 0057fbe0  8b8efc010000         mov ecx, dword ptr [esi + 0x1fc]
// 0057fbe6  c60408ff             mov byte ptr [eax + ecx], 0xff
// 0057fbea  40                   inc eax
// 0057fbeb  3bc3                 cmp eax, ebx
// 0057fbed  7cf1                 jl 0x57fbe0
// 0057fbef  dd05f8018c00         fld qword ptr [0x8c01f8]
// 0057fbf5  83be0002000000       cmp dword ptr [esi + 0x200], 0
// 0057fbfc  7556                 jne 0x57fc54
// 0057fbfe  8d3c1b               lea edi, [ebx + ebx]
// 0057fc01  ddd8                 fstp st(0)
// 0057fc03  57                   push edi
// 0057fc04  56                   push esi
// 0057fc05  e846f00000           call 0x58ec50
// 0057fc0a  57                   push edi
// 0057fc0b  56                   push esi
// 0057fc0c  898600020000         mov dword ptr [esi + 0x200], eax
// 0057fc12  e839f00000           call 0x58ec50
// 0057fc17  898604020000         mov dword ptr [esi + 0x204], eax
// 0057fc1d  83c410               add esp, 0x10
// 0057fc20  33c0                 xor eax, eax
// 0057fc22  85db                 test ebx, ebx
// 0057fc24  7e28                 jle 0x57fc4e
// 0057fc26  eb08                 jmp 0x57fc30
// 0057fc28  8da42400000000       lea esp, [esp]
// 0057fc2f  90                   nop 
// 0057fc30  8b9600020000         mov edx, dword ptr [esi + 0x200]
// 0057fc36  b900010000           mov ecx, 0x100
// 0057fc3b  66890c42             mov word ptr [edx + eax*2], cx
// 0057fc3f  8b9604020000         mov edx, dword ptr [esi + 0x204]
// 0057fc45  66890c42             mov word ptr [edx + eax*2], cx
// 0057fc49  40                   inc eax
// 0057fc4a  3bc3                 cmp eax, ebx
// 0057fc4c  7ce2                 jl 0x57fc30
// 0057fc4e  dd05f8018c00         fld qword ptr [0x8c01f8]
// 0057fc54  33c9                 xor ecx, ecx
// 0057fc56  85db                 test ebx, ebx
// 0057fc58  0f8ea5000000         jle 0x57fd03
// 0057fc5e  dd0528c38c00         fld qword ptr [0x8cc328]
// 0057fc64  d9ee                 fldz 
// 0057fc66  dc54cd00             fcom qword ptr [ebp + ecx*8]
// 0057fc6a  dfe0                 fnstsw ax
// 0057fc6c  f6c441               test ah, 0x41
// 0057fc6f  751b                 jne 0x57fc8c
// 0057fc71  8b9600020000         mov edx, dword ptr [esi + 0x200]
// 0057fc77  b800010000           mov eax, 0x100
// 0057fc7c  6689044a             mov word ptr [edx + ecx*2], ax
// 0057fc80  8b9604020000         mov edx, dword ptr [esi + 0x204]
// 0057fc86  6689044a             mov word ptr [edx + ecx*2], ax
// 0057fc8a  eb6a                 jmp 0x57fcf6
// 0057fc8c  dd44cd00             fld qword ptr [ebp + ecx*8]
// 0057fc90  d97c2418             fnstcw word ptr [esp + 0x18]
// 0057fc94  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0057fc99  d8ca                 fmul st(2)
// 0057fc9b  0d000c0000           or eax, 0xc00
// 0057fca0  89442410             mov dword ptr [esp + 0x10], eax
// 0057fca4  8b8604020000         mov eax, dword ptr [esi + 0x204]
// 0057fcaa  d8c3                 fadd st(3)
// 0057fcac  d96c2410             fldcw word ptr [esp + 0x10]
// 0057fcb0  db5c2410             fistp dword ptr [esp + 0x10]
// 0057fcb4  0fb7542410           movzx edx, word ptr [esp + 0x10]
// 0057fcb9  66891448             mov word ptr [eax + ecx*2], dx
// 0057fcbd  d96c2418             fldcw word ptr [esp + 0x18]
// 0057fcc1  d9c1                 fld st(1)
// 0057fcc3  dc74cd00             fdiv qword ptr [ebp + ecx*8]
// 0057fcc7  d97c2418             fnstcw word ptr [esp + 0x18]
// 0057fccb  d8c3                 fadd st(3)
// 0057fccd  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0057fcd2  0d000c0000           or eax, 0xc00
// 0057fcd7  89442410             mov dword ptr [esp + 0x10], eax
// 0057fcdb  8b8600020000         mov eax, dword ptr [esi + 0x200]
// 0057fce1  d96c2410             fldcw word ptr [esp + 0x10]
// 0057fce5  db5c2410             fistp dword ptr [esp + 0x10]
// 0057fce9  0fb7542410           movzx edx, word ptr [esp + 0x10]
// 0057fcee  66891448             mov word ptr [eax + ecx*2], dx
// 0057fcf2  d96c2418             fldcw word ptr [esp + 0x18]
// 0057fcf6  41                   inc ecx
// 0057fcf7  3bcb                 cmp ecx, ebx
// 0057fcf9  0f8c67ffffff         jl 0x57fc66
// 0057fcff  ddd9                 fstp st(1)
// 0057fd01  ddd8                 fstp st(0)
// 0057fd03  83be0802000000       cmp dword ptr [esi + 0x208], 0
// 0057fd0a  0f85a0000000         jne 0x57fdb0
// 0057fd10  6a0a                 push 0xa
// 0057fd12  ddd8                 fstp st(0)
// 0057fd14  56                   push esi
// 0057fd15  e836ef0000           call 0x58ec50
// 0057fd1a  6a0a                 push 0xa
// 0057fd1c  56                   push esi
// 0057fd1d  898608020000         mov dword ptr [esi + 0x208], eax
// 0057fd23  e828ef0000           call 0x58ec50
// 0057fd28  dd05f8018c00         fld qword ptr [0x8c01f8]
// 0057fd2e  89860c020000         mov dword ptr [esi + 0x20c], eax
// 0057fd34  8b8e08020000         mov ecx, dword ptr [esi + 0x208]
// 0057fd3a  ba08000000           mov edx, 8
// 0057fd3f  668911               mov word ptr [ecx], dx
// 0057fd42  8b860c020000         mov eax, dword ptr [esi + 0x20c]
// 0057fd48  8bca                 mov ecx, edx
// 0057fd4a  668908               mov word ptr [eax], cx
// 0057fd4d  8b9608020000         mov edx, dword ptr [esi + 0x208]
// 0057fd53  8bc1                 mov eax, ecx
// 0057fd55  66894202             mov word ptr [edx + 2], ax
// 0057fd59  8b8e0c020000         mov ecx, dword ptr [esi + 0x20c]
// 0057fd5f  8bd0                 mov edx, eax
// 0057fd61  66895102             mov word ptr [ecx + 2], dx
// 0057fd65  8b8608020000         mov eax, dword ptr [esi + 0x208]
// 0057fd6b  8bca                 mov ecx, edx
// 0057fd6d  66894804             mov word ptr [eax + 4], cx
// 0057fd71  8b960c020000         mov edx, dword ptr [esi + 0x20c]
// 0057fd77  8bc1                 mov eax, ecx
// 0057fd79  66894204             mov word ptr [edx + 4], ax
// 0057fd7d  8b8e08020000         mov ecx, dword ptr [esi + 0x208]
// 0057fd83  8bd0                 mov edx, eax
// 0057fd85  66895106             mov word ptr [ecx + 6], dx
// 0057fd89  8b860c020000         mov eax, dword ptr [esi + 0x20c]
// 0057fd8f  8bca                 mov ecx, edx
// 0057fd91  66894806             mov word ptr [eax + 6], cx
// 0057fd95  8b9608020000         mov edx, dword ptr [esi + 0x208]
// 0057fd9b  8bc1                 mov eax, ecx
// 0057fd9d  66894208             mov word ptr [edx + 8], ax
// 0057fda1  8b8e0c020000         mov ecx, dword ptr [esi + 0x20c]
// 0057fda7  8bd0                 mov edx, eax
// 0057fda9  83c410               add esp, 0x10
// 0057fdac  66895108             mov word ptr [ecx + 8], dx
// 0057fdb0  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0057fdb4  d9e8                 fld1 
// 0057fdb6  dd0520c38c00         fld qword ptr [0x8cc320]
// 0057fdbc  33c9                 xor ecx, ecx
// 0057fdbe  d9ee                 fldz 
// 0057fdc0  8bd7                 mov edx, edi
// 0057fdc2  eb02                 jmp 0x57fdc6
// 0057fdc4  d9ca                 fxch st(2)
// 0057fdc6  85ff                 test edi, edi
// 0057fdc8  0f8480000000         je 0x57fe4e
// 0057fdce  dc12                 fcom qword ptr [edx]
// 0057fdd0  dfe0                 fnstsw ax
// 0057fdd2  f6c441               test ah, 0x41
// 0057fdd5  7477                 je 0x57fe4e
// 0057fdd7  d9ca                 fxch st(2)
// 0057fdd9  dc12                 fcom qword ptr [edx]
// 0057fddb  dfe0                 fnstsw ax
// 0057fddd  f6c441               test ah, 0x41
// 0057fde0  0f8a83000000         jp 0x57fe69
// 0057fde6  d9c1                 fld st(1)
// 0057fde8  8b9e0c020000         mov ebx, dword ptr [esi + 0x20c]
// 0057fdee  dc32                 fdiv qword ptr [edx]
// 0057fdf0  d97c2418             fnstcw word ptr [esp + 0x18]
// 0057fdf4  d8c4                 fadd st(4)
// 0057fdf6  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0057fdfb  0d000c0000           or eax, 0xc00
// 0057fe00  89442410             mov dword ptr [esp + 0x10], eax
// 0057fe04  d96c2410             fldcw word ptr [esp + 0x10]
// 0057fe08  db5c2410             fistp dword ptr [esp + 0x10]
// 0057fe0c  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 0057fe11  66890419             mov word ptr [ecx + ebx], ax
// 0057fe15  8b9e08020000         mov ebx, dword ptr [esi + 0x208]
// 0057fe1b  d96c2418             fldcw word ptr [esp + 0x18]
// 0057fe1f  dd02                 fld qword ptr [edx]
// 0057fe21  d97c2418             fnstcw word ptr [esp + 0x18]
// 0057fe25  d8ca                 fmul st(2)
// 0057fe27  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0057fe2c  0d000c0000           or eax, 0xc00
// 0057fe31  89442410             mov dword ptr [esp + 0x10], eax
// 0057fe35  d8c4                 fadd st(4)
// 0057fe37  d96c2410             fldcw word ptr [esp + 0x10]
// 0057fe3b  db5c2410             fistp dword ptr [esp + 0x10]
// 0057fe3f  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 0057fe44  66890419             mov word ptr [ecx + ebx], ax
// 0057fe48  d96c2418             fldcw word ptr [esp + 0x18]
// 0057fe4c  eb1b                 jmp 0x57fe69
// 0057fe4e  8b8608020000         mov eax, dword ptr [esi + 0x208]
// 0057fe54  d9ca                 fxch st(2)
// 0057fe56  bb08000000           mov ebx, 8
// 0057fe5b  66891c01             mov word ptr [ecx + eax], bx
// 0057fe5f  8b860c020000         mov eax, dword ptr [esi + 0x20c]
// 0057fe65  66891c01             mov word ptr [ecx + eax], bx
// 0057fe69  83c102               add ecx, 2
// 0057fe6c  83c208               add edx, 8
// 0057fe6f  83f90a               cmp ecx, 0xa
// 0057fe72  0f8c4cffffff         jl 0x57fdc4
// 0057fe78  dddb                 fstp st(3)
// 0057fe7a  5f                   pop edi
// 0057fe7b  ddd8                 fstp st(0)
// 0057fe7d  5d                   pop ebp
// 0057fe7e  ddd9                 fstp st(1)
// 0057fe80  5b                   pop ebx
// 0057fe81  ddd8                 fstp st(0)
// 0057fe83  5e                   pop esi
// 0057fe84  59                   pop ecx
// 0057fe85  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_set_filter_heuristics)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
