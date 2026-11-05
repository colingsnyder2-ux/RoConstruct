// roc 2008-06 007ab820  unit: RBX::RenderNew::RenderScene  size: 5279 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007ab820
//
// 007ab820  0100                 add dword ptr [eax], eax
// 007ab822  00897c2424d9         add byte ptr [ecx - 0x26dbdb84], cl
// 007ab828  40                   inc eax
// 007ab829  28d8                 sub al, bl
// 007ab82b  a4                   movsb byte ptr es:[edi], byte ptr [esi]
// 007ab82c  24d0                 and al, 0xd0
// 007ab82e  0100                 add dword ptr [eax], eax
// 007ab830  00d9                 add cl, bl
// 007ab832  40                   inc eax
// 007ab833  2cd8                 sub al, 0xd8
// 007ab835  a4                   movsb byte ptr es:[edi], byte ptr [esi]
// 007ab836  24d4                 and al, 0xd4
// 007ab838  0100                 add dword ptr [eax], eax
// 007ab83a  00d8                 add al, bl
// 007ab83c  8c24c8               mov word ptr [eax + ecx*8], fs
// 007ab83f  0100                 add dword ptr [eax], eax
// 007ab841  00d9                 add cl, bl
// 007ab843  8424bc               test byte ptr [esp + edi*4], ah
// 007ab846  0100                 add dword ptr [eax], eax
// 007ab848  00de                 add dh, bl
// 007ab84a  cadec1               retf 0xc1de
// 007ab84d  d98424b0010000       fld dword ptr [esp + 0x1b0]
// 007ab854  deca                 fmulp st(2)
// 007ab856  dec1                 faddp st(1)
// 007ab858  d9e0                 fchs 
// 007ab85a  d81d48788300         fcomp dword ptr [0x837848]
// 007ab860  dfe0                 fnstsw ax
// 007ab862  f6c405               test ah, 5
// 007ab865  7b08                 jnp 0x7ab86f
// 007ab867  c744242401000000     mov dword ptr [esp + 0x24], 1
// 007ab86f  db442424             fild dword ptr [esp + 0x24]
// 007ab873  51                   push ecx
// 007ab874  8d4c2418             lea ecx, [esp + 0x18]
// 007ab878  d91c24               fstp dword ptr [esp]
// 007ab87b  51                   push ecx
// 007ab87c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007ab880  e8fbd6d9ff           call 0x548f80
// 007ab885  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007ab889  83b98400000004       cmp dword ptr [ecx + 0x84], 4
// 007ab890  c68424280300000c     mov byte ptr [esp + 0x328], 0xc
// 007ab898  c644241200           mov byte ptr [esp + 0x12], 0
// 007ab89d  0f85e6000000         jne 0x7ab989
// 007ab8a3  8b942430030000       mov edx, dword ptr [esp + 0x330]
// 007ab8aa  80ba0608000000       cmp byte ptr [edx + 0x806], 0
// 007ab8b1  0f85d2000000         jne 0x7ab989
// 007ab8b7  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ab8bb  80781c00             cmp byte ptr [eax + 0x1c], 0
// 007ab8bf  0f84c6000000         je 0x7ab98b
// 007ab8c5  d9ee                 fldz 
// 007ab8c7  51                   push ecx
// 007ab8c8  8d542424             lea edx, [esp + 0x24]
// 007ab8cc  d91c24               fstp dword ptr [esp]
// 007ab8cf  52                   push edx
// 007ab8d0  e8abd6d9ff           call 0x548f80
// 007ab8d5  8b442420             mov eax, dword ptr [esp + 0x20]
// 007ab8d9  83781805             cmp dword ptr [eax + 0x18], 5
// 007ab8dd  c68424280300000d     mov byte ptr [esp + 0x328], 0xd
// 007ab8e5  7567                 jne 0x7ab94e
// 007ab8e7  83781004             cmp dword ptr [eax + 0x10], 4
// 007ab8eb  7561                 jne 0x7ab94e
// 007ab8ed  8b400c               mov eax, dword ptr [eax + 0xc]
// 007ab8f0  8b00                 mov eax, dword ptr [eax]
// 007ab8f2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007ab8f6  50                   push eax
// 007ab8f7  e8e4e3ffff           call 0x7a9ce0
// 007ab8fc  8bf8                 mov edi, eax
// 007ab8fe  33f6                 xor esi, esi
// 007ab900  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007ab904  8b410c               mov eax, dword ptr [ecx + 0xc]
// 007ab907  8b1430               mov edx, dword ptr [eax + esi]
// 007ab90a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007ab90e  03c6                 add eax, esi
// 007ab910  52                   push edx
// 007ab911  e87ae3ffff           call 0x7a9c90
// 007ab916  d907                 fld dword ptr [edi]
// 007ab918  d9056c4a8700         fld dword ptr [0x874a6c]
// 007ab91e  83c604               add esi, 4
// 007ab921  83fe10               cmp esi, 0x10
// 007ab924  dcc9                 fmul st(1), st(0)
// 007ab926  d94704               fld dword ptr [edi + 4]
// 007ab929  d8c9                 fmul st(1)
// 007ab92b  d94708               fld dword ptr [edi + 8]
// 007ab92e  deca                 fmulp st(2)
// 007ab930  d900                 fld dword ptr [eax]
// 007ab932  dec3                 faddp st(3)
// 007ab934  d9ca                 fxch st(2)
// 007ab936  d918                 fstp dword ptr [eax]
// 007ab938  d94004               fld dword ptr [eax + 4]
// 007ab93b  dec2                 faddp st(2)
// 007ab93d  d9c9                 fxch st(1)
// 007ab93f  d95804               fstp dword ptr [eax + 4]
// 007ab942  d84008               fadd dword ptr [eax + 8]
// 007ab945  d95808               fstp dword ptr [eax + 8]
// 007ab948  7cb6                 jl 0x7ab900
// 007ab94a  8b442420             mov eax, dword ptr [esp + 0x20]
// 007ab94e  c68424280300000c     mov byte ptr [esp + 0x328], 0xc
// 007ab956  85c0                 test eax, eax
// 007ab958  742f                 je 0x7ab989
// 007ab95a  83c004               add eax, 4
// 007ab95d  50                   push eax
// 007ab95e  ff15ac218000         call dword ptr [0x8021ac]
// 007ab964  85c0                 test eax, eax
// 007ab966  7519                 jne 0x7ab981
// 007ab968  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007ab96c  e81ff4caff           call 0x45ad90
// 007ab971  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007ab975  85c9                 test ecx, ecx
// 007ab977  7408                 je 0x7ab981
// 007ab979  8b01                 mov eax, dword ptr [ecx]
// 007ab97b  8b10                 mov edx, dword ptr [eax]
// 007ab97d  6a01                 push 1
// 007ab97f  ffd2                 call edx
// 007ab981  c744242000000000     mov dword ptr [esp + 0x20], 0
// 007ab989  33ff                 xor edi, edi
// 007ab98b  807c241300           cmp byte ptr [esp + 0x13], 0
// 007ab990  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ab994  0f85a0000000         jne 0x7aba3a
// 007ab99a  80781c00             cmp byte ptr [eax + 0x1c], 0
// 007ab99e  0f8462010000         je 0x7abb06
// 007ab9a4  8d4c2478             lea ecx, [esp + 0x78]
// 007ab9a8  ff1538438000         call dword ptr [0x804338]
// 007ab9ae  8b942430030000       mov edx, dword ptr [esp + 0x330]
// 007ab9b5  8d4c2478             lea ecx, [esp + 0x78]
// 007ab9b9  51                   push ecx
// 007ab9ba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007ab9be  52                   push edx
// 007ab9bf  c68424300300000e     mov byte ptr [esp + 0x330], 0xe
// 007ab9c7  e884e0d9ff           call 0x549a50
// 007ab9cc  8d8424c8020000       lea eax, [esp + 0x2c8]
// 007ab9d3  50                   push eax
// 007ab9d4  8d4c247c             lea ecx, [esp + 0x7c]
// 007ab9d8  ff1544438000         call dword ptr [0x804344]
// 007ab9de  8bc8                 mov ecx, eax
// 007ab9e0  ff1540438000         call dword ptr [0x804340]
// 007ab9e6  d95c242c             fstp dword ptr [esp + 0x2c]
// 007ab9ea  8d8c24d4020000       lea ecx, [esp + 0x2d4]
// 007ab9f1  51                   push ecx
// 007ab9f2  8d4c247c             lea ecx, [esp + 0x7c]
// 007ab9f6  ff155c428000         call dword ptr [0x80425c]
// 007ab9fc  d944242c             fld dword ptr [esp + 0x2c]
// 007aba00  50                   push eax
// 007aba01  d99c24fc010000       fstp dword ptr [esp + 0x1fc]
// 007aba08  8d8c2400020000       lea ecx, [esp + 0x200]
// 007aba0f  ff1598448000         call dword ptr [0x804498]
// 007aba15  8b8d68020000         mov ecx, dword ptr [ebp + 0x268]
// 007aba1b  8b11                 mov edx, dword ptr [ecx]
// 007aba1d  8b92c4010000         mov edx, dword ptr [edx + 0x1c4]
// 007aba23  8d8424f8010000       lea eax, [esp + 0x1f8]
// 007aba2a  50                   push eax
// 007aba2b  8b442418             mov eax, dword ptr [esp + 0x18]
// 007aba2f  8b4024               mov eax, dword ptr [eax + 0x24]
// 007aba32  50                   push eax
// 007aba33  ffd2                 call edx
// 007aba35  e9b5000000           jmp 0x7abaef
// 007aba3a  80781c00             cmp byte ptr [eax + 0x1c], 0
// 007aba3e  0f84c2000000         je 0x7abb06
// 007aba44  8d4c2478             lea ecx, [esp + 0x78]
// 007aba48  ff1538438000         call dword ptr [0x804338]
// 007aba4e  8b942430030000       mov edx, dword ptr [esp + 0x330]
// 007aba55  8d4c2478             lea ecx, [esp + 0x78]
// 007aba59  51                   push ecx
// 007aba5a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007aba5e  52                   push edx
// 007aba5f  c68424300300000f     mov byte ptr [esp + 0x330], 0xf
// 007aba67  e8a4dbd9ff           call 0x549610
// 007aba6c  8d8424bc020000       lea eax, [esp + 0x2bc]
// 007aba73  50                   push eax
// 007aba74  8d4c247c             lea ecx, [esp + 0x7c]
// 007aba78  ff1544438000         call dword ptr [0x804344]
// 007aba7e  8bc8                 mov ecx, eax
// 007aba80  ff1540438000         call dword ptr [0x804340]
// 007aba86  d95c242c             fstp dword ptr [esp + 0x2c]
// 007aba8a  8d4c245c             lea ecx, [esp + 0x5c]
// 007aba8e  51                   push ecx
// 007aba8f  8d4c247c             lea ecx, [esp + 0x7c]
// 007aba93  ff155c428000         call dword ptr [0x80425c]
// 007aba99  d944242c             fld dword ptr [esp + 0x2c]
// 007aba9d  50                   push eax
// 007aba9e  d99c24dc000000       fstp dword ptr [esp + 0xdc]
// 007abaa5  8d8c24e0000000       lea ecx, [esp + 0xe0]
// 007abaac  ff1598448000         call dword ptr [0x804498]
// 007abab2  8b442414             mov eax, dword ptr [esp + 0x14]
// 007abab6  80781c00             cmp byte ptr [eax + 0x1c], 0
// 007ababa  7518                 jne 0x7abad4
// 007ababc  397820               cmp dword ptr [eax + 0x20], edi
// 007ababf  7c13                 jl 0x7abad4
// 007abac1  0fb75020             movzx edx, word ptr [eax + 0x20]
// 007abac5  8b0dbc389700         mov ecx, dword ptr [0x9738bc]
// 007abacb  52                   push edx
// 007abacc  ff15bc4c8000         call dword ptr [0x804cbc]
// 007abad2  eb02                 jmp 0x7abad6
// 007abad4  33c0                 xor eax, eax
// 007abad6  8b8d68020000         mov ecx, dword ptr [ebp + 0x268]
// 007abadc  8b11                 mov edx, dword ptr [ecx]
// 007abade  8db424d8000000       lea esi, [esp + 0xd8]
// 007abae5  56                   push esi
// 007abae6  50                   push eax
// 007abae7  8b82c4010000         mov eax, dword ptr [edx + 0x1c4]
// 007abaed  ffd0                 call eax
// 007abaef  8d4c2478             lea ecx, [esp + 0x78]
// 007abaf3  c644241201           mov byte ptr [esp + 0x12], 1
// 007abaf8  c68424280300000c     mov byte ptr [esp + 0x328], 0xc
// 007abb00  ff15ec438000         call dword ptr [0x8043ec]
// 007abb06  8b13                 mov edx, dword ptr [ebx]
// 007abb08  8b5214               mov edx, dword ptr [edx + 0x14]
// 007abb0b  8d442434             lea eax, [esp + 0x34]
// 007abb0f  50                   push eax
// 007abb10  8bcb                 mov ecx, ebx
// 007abb12  c644241500           mov byte ptr [esp + 0x15], 0
// 007abb17  ffd2                 call edx
// 007abb19  8b08                 mov ecx, dword ptr [eax]
// 007abb1b  8b01                 mov eax, dword ptr [ecx]
// 007abb1d  8b5014               mov edx, dword ptr [eax + 0x14]
// 007abb20  6a00                 push 0
// 007abb22  682cbe9600           push 0x96be2c
// 007abb27  68fcbd9600           push 0x96bdfc
// 007abb2c  6a00                 push 0
// 007abb2e  6a00                 push 0
// 007abb30  c684243c03000010     mov byte ptr [esp + 0x33c], 0x10
// 007abb38  ffd2                 call edx
// 007abb3a  50                   push eax
// 007abb3b  e8865cefff           call 0x6a17c6
// 007abb40  8be8                 mov ebp, eax
// 007abb42  8b442448             mov eax, dword ptr [esp + 0x48]
// 007abb46  83c414               add esp, 0x14
// 007abb49  896c242c             mov dword ptr [esp + 0x2c], ebp
// 007abb4d  c68424280300000c     mov byte ptr [esp + 0x328], 0xc
// 007abb55  85c0                 test eax, eax
// 007abb57  744c                 je 0x7abba5
// 007abb59  83c004               add eax, 4
// 007abb5c  50                   push eax
// 007abb5d  ff15ac218000         call dword ptr [0x8021ac]
// 007abb63  85c0                 test eax, eax
// 007abb65  7536                 jne 0x7abb9d
// 007abb67  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 007abb6b  8b7108               mov esi, dword ptr [ecx + 8]
// 007abb6e  85f6                 test esi, esi
// 007abb70  741f                 je 0x7abb91
// 007abb72  8b0e                 mov ecx, dword ptr [esi]
// 007abb74  8b01                 mov eax, dword ptr [ecx]
// 007abb76  8b5004               mov edx, dword ptr [eax + 4]
// 007abb79  ffd2                 call edx
// 007abb7b  8bc6                 mov eax, esi
// 007abb7d  8b7604               mov esi, dword ptr [esi + 4]
// 007abb80  50                   push eax
// 007abb81  e8f44aefff           call 0x6a067a
// 007abb86  83c404               add esp, 4
// 007abb89  85f6                 test esi, esi
// 007abb8b  75e5                 jne 0x7abb72
// 007abb8d  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 007abb91  85c9                 test ecx, ecx
// 007abb93  7408                 je 0x7abb9d
// 007abb95  8b01                 mov eax, dword ptr [ecx]
// 007abb97  8b10                 mov edx, dword ptr [eax]
// 007abb99  6a01                 push 1
// 007abb9b  ffd2                 call edx
// 007abb9d  c744243400000000     mov dword ptr [esp + 0x34], 0
// 007abba5  85ed                 test ebp, ebp
// 007abba7  0f8486090000         je 0x7ac533
// 007abbad  837d3000             cmp dword ptr [ebp + 0x30], 0
// 007abbb1  0f857c090000         jne 0x7ac533
// 007abbb7  a16cf39700           mov eax, dword ptr [0x97f36c]
// 007abbbc  8bc8                 mov ecx, eax
// 007abbbe  51                   push ecx
// 007abbbf  40                   inc eax
// 007abbc0  68684a8700           push 0x874a68
// 007abbc5  a36cf39700           mov dword ptr [0x97f36c], eax
// 007abbca  8d442474             lea eax, [esp + 0x74]
// 007abbce  6a08                 push 8
// 007abbd0  50                   push eax
// 007abbd1  ff15b4278000         call dword ptr [0x8027b4]
// 007abbd7  83c410               add esp, 0x10
// 007abbda  68c4638100           push 0x8163c4
// 007abbdf  8d8c2418020000       lea ecx, [esp + 0x218]
// 007abbe6  ff1558248000         call dword ptr [0x802458]
// 007abbec  8d4c246c             lea ecx, [esp + 0x6c]
// 007abbf0  51                   push ecx
// 007abbf1  8d8c2470010000       lea ecx, [esp + 0x170]
// 007abbf8  c684242c03000011     mov byte ptr [esp + 0x32c], 0x11
// 007abc00  ff1558248000         call dword ptr [0x802458]
// 007abc06  c684242803000012     mov byte ptr [esp + 0x328], 0x12
// 007abc0e  ff15604e8000         call dword ptr [0x804e60]
// 007abc14  8b10                 mov edx, dword ptr [eax]
// 007abc16  8b5210               mov edx, dword ptr [edx + 0x10]
// 007abc19  6a00                 push 0
// 007abc1b  6a00                 push 0
// 007abc1d  6a00                 push 0
// 007abc1f  8d8c2420020000       lea ecx, [esp + 0x220]
// 007abc26  51                   push ecx
// 007abc27  8d8c247c010000       lea ecx, [esp + 0x17c]
// 007abc2e  51                   push ecx
// 007abc2f  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 007abc36  51                   push ecx
// 007abc37  8bc8                 mov ecx, eax
// 007abc39  ffd2                 call edx
// 007abc3b  50                   push eax
// 007abc3c  8d4d2c               lea ecx, [ebp + 0x2c]
// 007abc3f  c684242c03000013     mov byte ptr [esp + 0x32c], 0x13
// 007abc47  ff1568428000         call dword ptr [0x804268]
// 007abc4d  8b8424c4000000       mov eax, dword ptr [esp + 0xc4]
// 007abc54  c684242803000012     mov byte ptr [esp + 0x328], 0x12
// 007abc5c  c78424bc000000c46b8200 mov dword ptr [esp + 0xbc], 0x826bc4
// 007abc67  85c0                 test eax, eax
// 007abc69  7421                 je 0x7abc8c
// 007abc6b  ff08                 dec dword ptr [eax]
// 007abc6d  8b8424c4000000       mov eax, dword ptr [esp + 0xc4]
// 007abc74  833800               cmp dword ptr [eax], 0
// 007abc77  7513                 jne 0x7abc8c
// 007abc79  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 007abc80  8b4204               mov eax, dword ptr [edx + 4]
// 007abc83  8d8c24bc000000       lea ecx, [esp + 0xbc]
// 007abc8a  ffd0                 call eax
// 007abc8c  8d8c246c010000       lea ecx, [esp + 0x16c]
// 007abc93  c684242803000011     mov byte ptr [esp + 0x328], 0x11
// 007abc9b  ff1568248000         call dword ptr [0x802468]
// 007abca1  8d8c2414020000       lea ecx, [esp + 0x214]
// 007abca8  c68424280300000c     mov byte ptr [esp + 0x328], 0xc
// 007abcb0  ff1568248000         call dword ptr [0x802468]
// 007abcb6  33ff                 xor edi, edi
// 007abcb8  897c2438             mov dword ptr [esp + 0x38], edi
// 007abcbc  8d642400             lea esp, [esp]
// 007abcc0  8b13                 mov edx, dword ptr [ebx]
// 007abcc2  8b5214               mov edx, dword ptr [edx + 0x14]
// 007abcc5  8d442450             lea eax, [esp + 0x50]
// 007abcc9  50                   push eax
// 007abcca  8bcb                 mov ecx, ebx
// 007abccc  ffd2                 call edx
// 007abcce  8b08                 mov ecx, dword ptr [eax]
// 007abcd0  8b01                 mov eax, dword ptr [ecx]
// 007abcd2  8b5010               mov edx, dword ptr [eax + 0x10]
// 007abcd5  c684242803000014     mov byte ptr [esp + 0x328], 0x14
// 007abcdd  ffd2                 call edx
// 007abcdf  3bf8                 cmp edi, eax
// 007abce1  8b442450             mov eax, dword ptr [esp + 0x50]
// 007abce5  0f9c442411           setl byte ptr [esp + 0x11]
// 007abcea  c68424280300000c     mov byte ptr [esp + 0x328], 0xc
// 007abcf2  85c0                 test eax, eax
// 007abcf4  744d                 je 0x7abd43
// 007abcf6  83c004               add eax, 4
// 007abcf9  50                   push eax
// 007abcfa  ff15ac218000         call dword ptr [0x8021ac]
// 007abd00  85c0                 test eax, eax
// 007abd02  7537                 jne 0x7abd3b
// 007abd04  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 007abd08  8b7108               mov esi, dword ptr [ecx + 8]
// 007abd0b  85f6                 test esi, esi
// 007abd0d  7420                 je 0x7abd2f
// 007abd0f  90                   nop 
// 007abd10  8b0e                 mov ecx, dword ptr [esi]
// 007abd12  8b01                 mov eax, dword ptr [ecx]
// 007abd14  8b5004               mov edx, dword ptr [eax + 4]
// 007abd17  ffd2                 call edx
// 007abd19  8bc6                 mov eax, esi
// 007abd1b  8b7604               mov esi, dword ptr [esi + 4]
// 007abd1e  50                   push eax
// 007abd1f  e85649efff           call 0x6a067a
// 007abd24  83c404               add esp, 4
// 007abd27  85f6                 test esi, esi
// 007abd29  75e5                 jne 0x7abd10
// 007abd2b  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 007abd2f  85c9                 test ecx, ecx
// 007abd31  7408                 je 0x7abd3b
// 007abd33  8b01                 mov eax, dword ptr [ecx]
// 007abd35  8b10                 mov edx, dword ptr [eax]
// 007abd37  6a01                 push 1
// 007abd39  ffd2                 call edx
// 007abd3b  c744245000000000     mov dword ptr [esp + 0x50], 0
// 007abd43  807c241100           cmp byte ptr [esp + 0x11], 0
// 007abd48  0f8480040000         je 0x7ac1ce
// 007abd4e  8b03                 mov eax, dword ptr [ebx]
// 007abd50  8b5014               mov edx, dword ptr [eax + 0x14]
// 007abd53  8d4c2440             lea ecx, [esp + 0x40]
// 007abd57  51                   push ecx
// 007abd58  8bcb                 mov ecx, ebx
// 007abd5a  ffd2                 call edx
// 007abd5c  8b08                 mov ecx, dword ptr [eax]
// 007abd5e  8b01                 mov eax, dword ptr [ecx]
// 007abd60  8b5014               mov edx, dword ptr [eax + 0x14]
// 007abd63  6a00                 push 0
// 007abd65  682cbe9600           push 0x96be2c
// 007abd6a  68fcbd9600           push 0x96bdfc
// 007abd6f  6a00                 push 0
// 007abd71  57                   push edi
// 007abd72  c684243c03000015     mov byte ptr [esp + 0x33c], 0x15
// 007abd7a  ffd2                 call edx
// 007abd7c  50                   push eax
// 007abd7d  e8445aefff           call 0x6a17c6
// 007abd82  8bf0                 mov esi, eax
// 007abd84  8b442454             mov eax, dword ptr [esp + 0x54]
// 007abd88  83c414               add esp, 0x14
// 007abd8b  c68424280300000c     mov byte ptr [esp + 0x328], 0xc
// 007abd93  85c0                 test eax, eax
// 007abd95  744c                 je 0x7abde3
// 007abd97  83c004               add eax, 4
// 007abd9a  50                   push eax
// 007abd9b  ff15ac218000         call dword ptr [0x8021ac]
// 007abda1  85c0                 test eax, eax
// 007abda3  7536                 jne 0x7abddb
// 007abda5  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007abda9  8b7908               mov edi, dword ptr [ecx + 8]
// 007abdac  85ff                 test edi, edi
// 007abdae  741f                 je 0x7abdcf
// 007abdb0  8b0f                 mov ecx, dword ptr [edi]
// 007abdb2  8b01                 mov eax, dword ptr [ecx]
// 007abdb4  8b5004               mov edx, dword ptr [eax + 4]
// 007abdb7  ffd2                 call edx
// 007abdb9  8bc7                 mov eax, edi
// 007abdbb  8b7f04               mov edi, dword ptr [edi + 4]
// 007abdbe  50                   push eax
// 007abdbf  e8b648efff           call 0x6a067a
// 007abdc4  83c404               add esp, 4
// 007abdc7  85ff                 test edi, edi
// 007abdc9  75e5                 jne 0x7abdb0
// 007abdcb  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007abdcf  85c9                 test ecx, ecx
// 007abdd1  7408                 je 0x7abddb
// 007abdd3  8b01                 mov eax, dword ptr [ecx]
// 007abdd5  8b10                 mov edx, dword ptr [eax]
// 007abdd7  6a01                 push 1
// 007abdd9  ffd2                 call edx
// 007abddb  c744244000000000     mov dword ptr [esp + 0x40], 0
// 007abde3  85f6                 test esi, esi
// 007abde5  0f84d2030000         je 0x7ac1bd
// 007abdeb  8b8c2430030000       mov ecx, dword ptr [esp + 0x330]
// 007abdf2  8b06                 mov eax, dword ptr [esi]
// 007abdf4  8b4008               mov eax, dword ptr [eax + 8]
// 007abdf7  51                   push ecx
// 007abdf8  8d542458             lea edx, [esp + 0x58]
// 007abdfc  52                   push edx
// 007abdfd  8bce                 mov ecx, esi
// 007abdff  ffd0                 call eax
// 007abe01  8b442454             mov eax, dword ptr [esp + 0x54]
// 007abe05  85c0                 test eax, eax
// 007abe07  742f                 je 0x7abe38
// 007abe09  83c004               add eax, 4
// 007abe0c  50                   push eax
// 007abe0d  ff15ac218000         call dword ptr [0x8021ac]
// 007abe13  85c0                 test eax, eax
// 007abe15  7519                 jne 0x7abe30
// 007abe17  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 007abe1b  e870efcaff           call 0x45ad90
// 007abe20  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 007abe24  85c9                 test ecx, ecx
// 007abe26  7408                 je 0x7abe30
// 007abe28  8b11                 mov edx, dword ptr [ecx]
// 007abe2a  8b02                 mov eax, dword ptr [edx]
// 007abe2c  6a01                 push 1
// 007abe2e  ffd0                 call eax
// 007abe30  c744245400000000     mov dword ptr [esp + 0x54], 0
// 007abe38  837c243800           cmp dword ptr [esp + 0x38], 0
// 007abe3d  6a00                 push 0
// 007abe3f  7519                 jne 0x7abe5a
// 007abe41  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007abe45  8b4930               mov ecx, dword ptr [ecx + 0x30]
// 007abe48  6a00                 push 0
// 007abe4a  ff156c428000         call dword ptr [0x80426c]
// 007abe50  8bc8                 mov ecx, eax
// 007abe52  ff1570428000         call dword ptr [0x804270]
// 007abe58  eb15                 jmp 0x7abe6f
// 007abe5a  8b542430             mov edx, dword ptr [esp + 0x30]
// 007abe5e  8b4a30               mov ecx, dword ptr [edx + 0x30]
// 007abe61  ff156c428000         call dword ptr [0x80426c]
// 007abe67  8bc8                 mov ecx, eax
// 007abe69  ff15b0438000         call dword ptr [0x8043b0]
// 007abe6f  8be8                 mov ebp, eax
// 007abe71  8b06                 mov eax, dword ptr [esi]
// 007abe73  8b5018               mov edx, dword ptr [eax + 0x18]
// 007abe76  8bce                 mov ecx, esi
// 007abe78  ffd2                 call edx
// 007abe7a  8bf8                 mov edi, eax
// 007abe7c  8b06                 mov eax, dword ptr [esi]
// 007abe7e  8b5028               mov edx, dword ptr [eax + 0x28]
// 007abe81  8bce                 mov ecx, esi
// 007abe83  ffd2                 call edx
// 007abe85  d9e8                 fld1 
// 007abe87  dee1                 fsubrp st(1)
// 007abe89  83ec10               sub esp, 0x10
// 007abe8c  8bcd                 mov ecx, ebp
// 007abe8e  d95c240c             fstp dword ptr [esp + 0xc]
// 007abe92  d94708               fld dword ptr [edi + 8]
// 007abe95  d95c2408             fstp dword ptr [esp + 8]
// 007abe99  d94704               fld dword ptr [edi + 4]
// 007abe9c  d95c2404             fstp dword ptr [esp + 4]
// 007abea0  d907                 fld dword ptr [edi]
// 007abea2  d91c24               fstp dword ptr [esp]
// 007abea5  ff15104c8000         call dword ptr [0x804c10]
// 007abeab  d94708               fld dword ptr [edi + 8]
// 007abeae  83ec0c               sub esp, 0xc
// 007abeb1  d95c2408             fstp dword ptr [esp + 8]
// 007abeb5  8bcd                 mov ecx, ebp
// 007abeb7  d94704               fld dword ptr [edi + 4]
// 007abeba  d95c2404             fstp dword ptr [esp + 4]
// 007abebe  d907                 fld dword ptr [edi]
// 007abec0  d91c24               fstp dword ptr [esp]
// 007abec3  ff1574428000         call dword ptr [0x804274]
// 007abec9  8b442418             mov eax, dword ptr [esp + 0x18]
// 007abecd  8b8084000000         mov eax, dword ptr [eax + 0x84]
// 007abed3  83f801               cmp eax, 1
// 007abed6  7434                 je 0x7abf0c
// 007abed8  83f802               cmp eax, 2
// 007abedb  742f                 je 0x7abf0c
// 007abedd  83f803               cmp eax, 3
// 007abee0  742a                 je 0x7abf0c
// 007abee2  d9e8                 fld1 
// 007abee4  83ec10               sub esp, 0x10
// 007abee7  d95c240c             fstp dword ptr [esp + 0xc]
// 007abeeb  8bcd                 mov ecx, ebp
// 007abeed  d90540f88200         fld dword ptr [0x82f840]
// 007abef3  d9542408             fst dword ptr [esp + 8]
// 007abef7  d9542404             fst dword ptr [esp + 4]
// 007abefb  d91c24               fstp dword ptr [esp]
// 007abefe  ff15144c8000         call dword ptr [0x804c14]
// 007abf04  d90590748200         fld dword ptr [0x827490]
// 007abf0a  eb50                 jmp 0x7abf5c
// 007abf0c  8b16                 mov edx, dword ptr [esi]
// 007abf0e  d9e8                 fld1 
// 007abf10  8b421c               mov eax, dword ptr [edx + 0x1c]
// 007abf13  51                   push ecx
// 007abf14  8bce                 mov ecx, esi
// 007abf16  d91c24               fstp dword ptr [esp]
// 007abf19  ffd0                 call eax
// 007abf1b  8b16                 mov edx, dword ptr [esi]
// 007abf1d  8b421c               mov eax, dword ptr [edx + 0x1c]
// 007abf20  51                   push ecx
// 007abf21  8bce                 mov ecx, esi
// 007abf23  d91c24               fstp dword ptr [esp]
// 007abf26  ffd0                 call eax
// 007abf28  8b16                 mov edx, dword ptr [esi]
// 007abf2a  8b421c               mov eax, dword ptr [edx + 0x1c]
// 007abf2d  51                   push ecx
// 007abf2e  8bce                 mov ecx, esi
// 007abf30  d91c24               fstp dword ptr [esp]
// 007abf33  ffd0                 call eax
// 007abf35  51                   push ecx
// 007abf36  8bcd                 mov ecx, ebp
// 007abf38  d91c24               fstp dword ptr [esp]
// 007abf3b  ff15144c8000         call dword ptr [0x804c14]
// 007abf41  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007abf45  83b98400000002       cmp dword ptr [ecx + 0x84], 2
// 007abf4c  7508                 jne 0x7abf56
// 007abf4e  d905e0c18400         fld dword ptr [0x84c1e0]
// 007abf54  eb06                 jmp 0x7abf5c
// 007abf56  d905e4c18400         fld dword ptr [0x84c1e4]
// 007abf5c  51                   push ecx
// 007abf5d  8bcd                 mov ecx, ebp
// 007abf5f  d91c24               fstp dword ptr [esp]
// 007abf62  ff15184c8000         call dword ptr [0x804c18]
// 007abf68  d9ee                 fldz 
// 007abf6a  83ec08               sub esp, 8
// 007abf6d  d95c2404             fstp dword ptr [esp + 4]
// 007abf71  d94318               fld dword ptr [ebx + 0x18]
// 007abf74  8bcd                 mov ecx, ebp
// 007abf76  d80d644a8700         fmul dword ptr [0x874a64]
// 007abf7c  d91c24               fstp dword ptr [esp]
// 007abf7f  ff15ac438000         call dword ptr [0x8043ac]
// 007abf85  8b16                 mov edx, dword ptr [esi]
// 007abf87  8b4228               mov eax, dword ptr [edx + 0x28]
// 007abf8a  8bce                 mov ecx, esi
// 007abf8c  ffd0                 call eax
// 007abf8e  d81dc4358100         fcomp dword ptr [0x8135c4]
// 007abf94  dfe0                 fnstsw ax
// 007abf96  f6c441               test ah, 0x41
// 007abf99  740d                 je 0x7abfa8
// 007abf9b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007abf9f  83b98400000004       cmp dword ptr [ecx + 0x84], 4
// 007abfa6  7516                 jne 0x7abfbe
// 007abfa8  6a09                 push 9
// 007abfaa  6a07                 push 7
// 007abfac  8bcd                 mov ecx, ebp
// 007abfae  ff1558498000         call dword ptr [0x804958]
// 007abfb4  6a00                 push 0
// 007abfb6  8bcd                 mov ecx, ebp
// 007abfb8  ff15e04e8000         call dword ptr [0x804ee0]
// 007abfbe  8b16                 mov edx, dword ptr [esi]
// 007abfc0  8b520c               mov edx, dword ptr [edx + 0xc]
// 007abfc3  8d442448             lea eax, [esp + 0x48]
// 007abfc7  50                   push eax
// 007abfc8  8bce                 mov ecx, esi
// 007abfca  ffd2                 call edx
// 007abfcc  33ff                 xor edi, edi
// 007abfce  3938                 cmp dword ptr [eax], edi
// 007abfd0  8b442448             mov eax, dword ptr [esp + 0x48]
// 007abfd4  0f95442411           setne byte ptr [esp + 0x11]
// 007abfd9  3bc7                 cmp eax, edi
// 007abfdb  742b                 je 0x7ac008
// 007abfdd  83c004               add eax, 4
// 007abfe0  50                   push eax
// 007abfe1  ff15ac218000         call dword ptr [0x8021ac]
// 007abfe7  85c0                 test eax, eax
// 007abfe9  7519                 jne 0x7ac004
// 007abfeb  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 007abfef  e89cedcaff           call 0x45ad90
// 007abff4  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 007abff8  3bcf                 cmp ecx, edi
// 007abffa  7408                 je 0x7ac004
// 007abffc  8b01                 mov eax, dword ptr [ecx]
// 007abffe  8b10                 mov edx, dword ptr [eax]
// 007ac000  6a01                 push 1
// 007ac002  ffd2                 call edx
// 007ac004  897c2448             mov dword ptr [esp + 0x48], edi
// 007ac008  807c241100           cmp byte ptr [esp + 0x11], 0
// 007ac00d  0f84aa010000         je 0x7ac1bd
// 007ac013  8b06                 mov eax, dword ptr [esi]
// 007ac015  8b500c               mov edx, dword ptr [eax + 0xc]
// 007ac018  8d4c2458             lea ecx, [esp + 0x58]
// 007ac01c  51                   push ecx
// 007ac01d  8bce                 mov ecx, esi
// 007ac01f  ffd2                 call edx
// 007ac021  8b00                 mov eax, dword ptr [eax]
// 007ac023  57                   push edi
// 007ac024  68142f9400           push 0x942f14
// 007ac029  68f02e9400           push 0x942ef0
// 007ac02e  57                   push edi
// 007ac02f  50                   push eax
// 007ac030  c684243c03000016     mov byte ptr [esp + 0x33c], 0x16
// 007ac038  e88957efff           call 0x6a17c6
// 007ac03d  83c414               add esp, 0x14
// 007ac040  83c054               add eax, 0x54
// 007ac043  50                   push eax
// 007ac044  8d8c24f8000000       lea ecx, [esp + 0xf8]
// 007ac04b  ff15a8438000         call dword ptr [0x8043a8]
// 007ac051  8b442458             mov eax, dword ptr [esp + 0x58]
// 007ac055  c684242803000018     mov byte ptr [esp + 0x328], 0x18
// 007ac05d  3bc7                 cmp eax, edi
// 007ac05f  742b                 je 0x7ac08c
// 007ac061  83c004               add eax, 4
// 007ac064  50                   push eax
// 007ac065  ff15ac218000         call dword ptr [0x8021ac]
// 007ac06b  85c0                 test eax, eax
// 007ac06d  7519                 jne 0x7ac088
// 007ac06f  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 007ac073  e818edcaff           call 0x45ad90
// 007ac078  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 007ac07c  3bcf                 cmp ecx, edi
// 007ac07e  7408                 je 0x7ac088
// 007ac080  8b01                 mov eax, dword ptr [ecx]
// 007ac082  8b10                 mov edx, dword ptr [eax]
// 007ac084  6a01                 push 1
// 007ac086  ffd2                 call edx
// 007ac088  897c2458             mov dword ptr [esp + 0x58], edi
// 007ac08c  39bc24f8000000       cmp dword ptr [esp + 0xf8], edi
// 007ac093  0f84c5000000         je 0x7ac15e
// 007ac099  8bcd                 mov ecx, ebp
// 007ac09b  ff1510468000         call dword ptr [0x804610]
// 007ac0a1  8bf8                 mov edi, eax
// 007ac0a3  6a02                 push 2
// 007ac0a5  8bcf                 mov ecx, edi
// 007ac0a7  ff15704d8000         call dword ptr [0x804d70]
// 007ac0ad  6a02                 push 2
// 007ac0af  6a02                 push 2
// 007ac0b1  6a02                 push 2
// 007ac0b3  8bcf                 mov ecx, edi
// 007ac0b5  ff15a4438000         call dword ptr [0x8043a4]
// 007ac0bb  6a00                 push 0
// 007ac0bd  6a00                 push 0
// 007ac0bf  6a00                 push 0
// 007ac0c1  8bcf                 mov ecx, edi
// 007ac0c3  ff15a0438000         call dword ptr [0x8043a0]
// 007ac0c9  8b06                 mov eax, dword ptr [esi]
// 007ac0cb  8b5018               mov edx, dword ptr [eax + 0x18]
// 007ac0ce  8bce                 mov ecx, esi
// 007ac0d0  ffd2                 call edx
// 007ac0d2  8bd8                 mov ebx, eax
// 007ac0d4  8b06                 mov eax, dword ptr [esi]
// 007ac0d6  8b5018               mov edx, dword ptr [eax + 0x18]
// 007ac0d9  8bce                 mov ecx, esi
// 007ac0db  ffd2                 call edx
// 007ac0dd  898424c8000000       mov dword ptr [esp + 0xc8], eax
// 007ac0e4  8b06                 mov eax, dword ptr [esi]
// 007ac0e6  8b5018               mov edx, dword ptr [eax + 0x18]
// 007ac0e9  8bce                 mov ecx, esi
// 007ac0eb  ffd2                 call edx
// 007ac0ed  d900                 fld dword ptr [eax]
// 007ac0ef  8b8424c8000000       mov eax, dword ptr [esp + 0xc8]
// 007ac0f6  d94004               fld dword ptr [eax + 4]
// 007ac0f9  8d8c245c010000       lea ecx, [esp + 0x15c]
// 007ac100  d94308               fld dword ptr [ebx + 8]
// 007ac103  51                   push ecx
// 007ac104  d9ca                 fxch st(2)
// 007ac106  8bcf                 mov ecx, edi
// 007ac108  d99c2460010000       fstp dword ptr [esp + 0x160]
// 007ac10f  d99c2464010000       fstp dword ptr [esp + 0x164]
// 007ac116  d99c2468010000       fstp dword ptr [esp + 0x168]
// 007ac11d  d9e8                 fld1 
// 007ac11f  d99c246c010000       fstp dword ptr [esp + 0x16c]
// 007ac126  ff15644d8000         call dword ptr [0x804d64]
// 007ac12c  8b9424f8000000       mov edx, dword ptr [esp + 0xf8]
// 007ac133  6a02                 push 2
// 007ac135  83c224               add edx, 0x24
// 007ac138  52                   push edx
// 007ac139  8bcf                 mov ecx, edi
// 007ac13b  ff150c438000         call dword ptr [0x80430c]
// 007ac141  8b8c24f8000000       mov ecx, dword ptr [esp + 0xf8]
// 007ac148  85c9                 test ecx, ecx
// 007ac14a  7412                 je 0x7ac15e
// 007ac14c  8b01                 mov eax, dword ptr [ecx]
// 007ac14e  8b90b4000000         mov edx, dword ptr [eax + 0xb4]
// 007ac154  ffd2                 call edx
// 007ac156  84c0                 test al, al
// 007ac158  7404                 je 0x7ac15e
// 007ac15a  b301                 mov bl, 1
// 007ac15c  eb02                 jmp 0x7ac160
// 007ac15e  32db                 xor bl, bl
// 007ac160  8b06                 mov eax, dword ptr [esi]
// 007ac162  8b5028               mov edx, dword ptr [eax + 0x28]
// 007ac165  8bce                 mov ecx, esi
// 007ac167  ffd2                 call edx
// 007ac169  d81dc4358100         fcomp dword ptr [0x8135c4]
// 007ac16f  dfe0                 fnstsw ax
// 007ac171  f6c441               test ah, 0x41
// 007ac174  7a2e                 jp 0x7ac1a4
// 007ac176  84db                 test bl, bl
// 007ac178  742a                 je 0x7ac1a4
// 007ac17a  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ac17e  83781802             cmp dword ptr [eax + 0x18], 2
// 007ac182  7520                 jne 0x7ac1a4
// 007ac184  6a04                 push 4
// 007ac186  8bcd                 mov ecx, ebp
// 007ac188  ff151c498000         call dword ptr [0x80491c]
// 007ac18e  6a01                 push 1
// 007ac190  8bcd                 mov ecx, ebp
// 007ac192  ff15e04e8000         call dword ptr [0x804ee0]
// 007ac198  6a01                 push 1
// 007ac19a  6a06                 push 6
// 007ac19c  8bcd                 mov ecx, ebp
// 007ac19e  ff155c498000         call dword ptr [0x80495c]
// 007ac1a4  8d8c24f4000000       lea ecx, [esp + 0xf4]
// 007ac1ab  c68424280300000c     mov byte ptr [esp + 0x328], 0xc
// 007ac1b3  ff158c4c8000         call dword ptr [0x804c8c]
// 007ac1b9  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 007ac1bd  ff442438             inc dword ptr [esp + 0x38]
// 007ac1c1  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 007ac1c5  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 007ac1c9  e9f2faffff           jmp 0x7abcc0
// 007ac1ce  8b5500               mov edx, dword ptr [ebp]
// 007ac1d1  8b4224               mov eax, dword ptr [edx + 0x24]
// 007ac1d4  8bcd                 mov ecx, ebp
// 007ac1d6  ffd0                 call eax
// 007ac1d8  d81dc4358100         fcomp dword ptr [0x8135c4]
// 007ac1de  dfe0                 fnstsw ax
// 007ac1e0  f6c441               test ah, 0x41
// 007ac1e3  0f8545030000         jne 0x7ac52e
// 007ac1e9  68584a8700           push 0x874a58
// 007ac1ee  8d8c2418020000       lea ecx, [esp + 0x218]
// 007ac1f5  ff1558248000         call dword ptr [0x802458]
// 007ac1fb  8b35444c8000         mov esi, dword ptr [0x804c44]
// 007ac201  c684242803000019     mov byte ptr [esp + 0x328], 0x19
// 007ac209  ffd6                 call esi
// 007ac20b  8b10                 mov edx, dword ptr [eax]
// 007ac20d  8b524c               mov edx, dword ptr [edx + 0x4c]
// 007ac210  8d8c2414020000       lea ecx, [esp + 0x214]
// 007ac217  51                   push ecx
// 007ac218  8d8c24b4000000       lea ecx, [esp + 0xb4]
// 007ac21f  51                   push ecx
// 007ac220  8bc8                 mov ecx, eax
// 007ac222  ffd2                 call edx
// 007ac224  50                   push eax
// 007ac225  8d8c249c000000       lea ecx, [esp + 0x9c]
// 007ac22c  c684242c0300001a     mov byte ptr [esp + 0x32c], 0x1a
// 007ac234  ff15584c8000         call dword ptr [0x804c58]
// 007ac23a  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 007ac241  bfc46b8200           mov edi, 0x826bc4
// 007ac246  c68424280300001c     mov byte ptr [esp + 0x328], 0x1c
// 007ac24e  89bc24b0000000       mov dword ptr [esp + 0xb0], edi
// 007ac255  85c0                 test eax, eax
// 007ac257  7421                 je 0x7ac27a
// 007ac259  ff08                 dec dword ptr [eax]
// 007ac25b  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 007ac262  833800               cmp dword ptr [eax], 0
// 007ac265  7513                 jne 0x7ac27a
// 007ac267  8b9424b0000000       mov edx, dword ptr [esp + 0xb0]
// 007ac26e  8b4204               mov eax, dword ptr [edx + 4]
// 007ac271  8d8c24b0000000       lea ecx, [esp + 0xb0]
// 007ac278  ffd0                 call eax
// 007ac27a  8d8c2414020000       lea ecx, [esp + 0x214]
// 007ac281  c68424280300001d     mov byte ptr [esp + 0x328], 0x1d
// 007ac289  ff1568248000         call dword ptr [0x802468]
// 007ac28f  83bc249c00000000     cmp dword ptr [esp + 0x9c], 0
// 007ac297  0f85e6010000         jne 0x7ac483
// 007ac29d  68c4638100           push 0x8163c4
// 007ac2a2  8d8c248c010000       lea ecx, [esp + 0x18c]
// 007ac2a9  ff1558248000         call dword ptr [0x802458]
// 007ac2af  68584a8700           push 0x874a58
// 007ac2b4  8d8c2470010000       lea ecx, [esp + 0x170]
// 007ac2bb  c684242c0300001e     mov byte ptr [esp + 0x32c], 0x1e
// 007ac2c3  ff1558248000         call dword ptr [0x802458]
// 007ac2c9  c68424280300001f     mov byte ptr [esp + 0x328], 0x1f
// 007ac2d1  ffd6                 call esi
// 007ac2d3  8b10                 mov edx, dword ptr [eax]
// 007ac2d5  8b5210               mov edx, dword ptr [edx + 0x10]
// 007ac2d8  6a00                 push 0
// 007ac2da  6a00                 push 0
// 007ac2dc  6a00                 push 0
// 007ac2de  8d8c2494010000       lea ecx, [esp + 0x194]
// 007ac2e5  51                   push ecx
// 007ac2e6  8d8c247c010000       lea ecx, [esp + 0x17c]
// 007ac2ed  51                   push ecx
// 007ac2ee  8d8c24e0000000       lea ecx, [esp + 0xe0]
// 007ac2f5  51                   push ecx
// 007ac2f6  8bc8                 mov ecx, eax
// 007ac2f8  ffd2                 call edx
// 007ac2fa  50                   push eax
// 007ac2fb  8d8c249c000000       lea ecx, [esp + 0x9c]
// 007ac302  c684242c03000020     mov byte ptr [esp + 0x32c], 0x20
// 007ac30a  ff15f4468000         call dword ptr [0x8046f4]
// 007ac310  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 007ac317  c68424280300001f     mov byte ptr [esp + 0x328], 0x1f
// 007ac31f  89bc24cc000000       mov dword ptr [esp + 0xcc], edi
// 007ac326  85c0                 test eax, eax
// 007ac328  7421                 je 0x7ac34b
// 007ac32a  ff08                 dec dword ptr [eax]
// 007ac32c  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 007ac333  833800               cmp dword ptr [eax], 0
// 007ac336  7513                 jne 0x7ac34b
// 007ac338  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 007ac33f  8b4204               mov eax, dword ptr [edx + 4]
// 007ac342  8d8c24cc000000       lea ecx, [esp + 0xcc]
// 007ac349  ffd0                 call eax
// 007ac34b  8d8c246c010000       lea ecx, [esp + 0x16c]
// 007ac352  c68424280300001e     mov byte ptr [esp + 0x328], 0x1e
// 007ac35a  ff1568248000         call dword ptr [0x802468]
// 007ac360  8d8c2488010000       lea ecx, [esp + 0x188]
// 007ac367  c68424280300001d     mov byte ptr [esp + 0x328], 0x1d
// 007ac36f  ff1568248000         call dword ptr [0x802468]
// 007ac375  8d8c2490020000       lea ecx, [esp + 0x290]
// 007ac37c  ff15484c8000         call dword ptr [0x804c48]
// 007ac382  8d4c2478             lea ecx, [esp + 0x78]
// 007ac386  51                   push ecx
// 007ac387  c684242c03000021     mov byte ptr [esp + 0x32c], 0x21
// 007ac38f  e82c01dbff           call 0x55c4c0
// 007ac394  8b35e4238000         mov esi, dword ptr [0x8023e4]
// 007ac39a  68b86c8200           push 0x826cb8
// 007ac39f  50                   push eax
// 007ac3a0  8d942478010000       lea edx, [esp + 0x178]
// 007ac3a7  52                   push edx
// 007ac3a8  c684243803000022     mov byte ptr [esp + 0x338], 0x22
// 007ac3b0  ffd6                 call esi
// 007ac3b2  68444a8700           push 0x874a44
// 007ac3b7  50                   push eax
// 007ac3b8  8d8424f0010000       lea eax, [esp + 0x1f0]
// 007ac3bf  50                   push eax
// 007ac3c0  c684244403000023     mov byte ptr [esp + 0x344], 0x23
// 007ac3c8  ffd6                 call esi
// 007ac3ca  83c41c               add esp, 0x1c
// 007ac3cd  8d8c246c010000       lea ecx, [esp + 0x16c]
// 007ac3d4  c684242803000025     mov byte ptr [esp + 0x328], 0x25
// 007ac3dc  ff1568248000         call dword ptr [0x802468]
// 007ac3e2  8d4c2478             lea ecx, [esp + 0x78]
// 007ac3e6  c684242803000026     mov byte ptr [esp + 0x328], 0x26
// 007ac3ee  ff1568248000         call dword ptr [0x802468]
// 007ac3f4  68c4638100           push 0x8163c4
// 007ac3f9  8d8c248c010000       lea ecx, [esp + 0x18c]
// 007ac400  ff1558248000         call dword ptr [0x802458]
// 007ac406  8d8c2488010000       lea ecx, [esp + 0x188]
// 007ac40d  51                   push ecx
// 007ac40e  8d9424dc010000       lea edx, [esp + 0x1dc]
// 007ac415  52                   push edx
// 007ac416  8d8c2498020000       lea ecx, [esp + 0x298]
// 007ac41d  c684243003000027     mov byte ptr [esp + 0x330], 0x27
// 007ac425  ff154c4c8000         call dword ptr [0x804c4c]
// 007ac42b  8d8c2488010000       lea ecx, [esp + 0x188]
// 007ac432  c684242803000026     mov byte ptr [esp + 0x328], 0x26
// 007ac43a  ff1568248000         call dword ptr [0x802468]
// 007ac440  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 007ac447  8b01                 mov eax, dword ptr [ecx]
// 007ac449  8b8098000000         mov eax, dword ptr [eax + 0x98]
// 007ac44f  8d942490020000       lea edx, [esp + 0x290]
// 007ac456  52                   push edx
// 007ac457  ffd0                 call eax
// 007ac459  8d8c24d8010000       lea ecx, [esp + 0x1d8]
// 007ac460  c684242803000021     mov byte ptr [esp + 0x328], 0x21
// 007ac468  ff1568248000         call dword ptr [0x802468]
// 007ac46e  8d8c2490020000       lea ecx, [esp + 0x290]
// 007ac475  c68424280300001d     mov byte ptr [esp + 0x328], 0x1d
// 007ac47d  ff155c4c8000         call dword ptr [0x804c5c]
// 007ac483  8b4d30               mov ecx, dword ptr [ebp + 0x30]
// 007ac486  6a00                 push 0
// 007ac488  ff156c428000         call dword ptr [0x80426c]
// 007ac48e  8bc8                 mov ecx, eax
// 007ac490  ff15b0438000         call dword ptr [0x8043b0]
// 007ac496  8b5500               mov edx, dword ptr [ebp]
// 007ac499  8bf0                 mov esi, eax
// 007ac49b  8b4224               mov eax, dword ptr [edx + 0x24]
// 007ac49e  8bcd                 mov ecx, ebp
// 007ac4a0  ffd0                 call eax
// 007ac4a2  d954241c             fst dword ptr [esp + 0x1c]
// 007ac4a6  d905489b8100         fld dword ptr [0x819b48]
// 007ac4ac  83ec10               sub esp, 0x10
// 007ac4af  d8c9                 fmul st(1)
// 007ac4b1  8bce                 mov ecx, esi
// 007ac4b3  d95c240c             fstp dword ptr [esp + 0xc]
// 007ac4b7  d9542408             fst dword ptr [esp + 8]
// 007ac4bb  d9542404             fst dword ptr [esp + 4]
// 007ac4bf  d91c24               fstp dword ptr [esp]
// 007ac4c2  ff15104c8000         call dword ptr [0x804c10]
// 007ac4c8  d944241c             fld dword ptr [esp + 0x1c]
// 007ac4cc  83ec0c               sub esp, 0xc
// 007ac4cf  d9542408             fst dword ptr [esp + 8]
// 007ac4d3  8bce                 mov ecx, esi
// 007ac4d5  d9542404             fst dword ptr [esp + 4]
// 007ac4d9  d91c24               fstp dword ptr [esp]
// 007ac4dc  ff1574428000         call dword ptr [0x804274]
// 007ac4e2  6a09                 push 9
// 007ac4e4  6a00                 push 0
// 007ac4e6  8bce                 mov ecx, esi
// 007ac4e8  ff1558498000         call dword ptr [0x804958]
// 007ac4ee  8bce                 mov ecx, esi
// 007ac4f0  ff1510468000         call dword ptr [0x804610]
// 007ac4f6  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 007ac4fd  83c124               add ecx, 0x24
// 007ac500  6a02                 push 2
// 007ac502  8bf0                 mov esi, eax
// 007ac504  51                   push ecx
// 007ac505  8bce                 mov ecx, esi
// 007ac507  ff150c438000         call dword ptr [0x80430c]
// 007ac50d  6a01                 push 1
// 007ac50f  6a01                 push 1
// 007ac511  8bce                 mov ecx, esi
// 007ac513  ff159c438000         call dword ptr [0x80439c]
// 007ac519  8d8c2498000000       lea ecx, [esp + 0x98]
// 007ac520  c68424280300000c     mov byte ptr [esp + 0x328], 0xc
// 007ac528  ff158c4c8000         call dword ptr [0x804c8c]
// 007ac52e  c644241101           mov byte ptr [esp + 0x11], 1
// 007ac533  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 007ac536  85c9                 test ecx, ecx
// 007ac538  0f85ab030000         jne 0x7ac8e9
// 007ac53e  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ac542  384c2413             cmp byte ptr [esp + 0x13], cl
// 007ac546  7472                 je 0x7ac5ba
// 007ac548  38481c               cmp byte ptr [eax + 0x1c], cl
// 007ac54b  0f8542060000         jne 0x7acb93
// 007ac551  394820               cmp dword ptr [eax + 0x20], ecx
// 007ac554  0f8c39060000         jl 0x7acb93
// 007ac55a  0fb75020             movzx edx, word ptr [eax + 0x20]
// 007ac55e  8b0dbc389700         mov ecx, dword ptr [0x9738bc]
// 007ac564  52                   push edx
// 007ac565  ff15bc4c8000         call dword ptr [0x804cbc]
// 007ac56b  85c0                 test eax, eax
// 007ac56d  0f8420060000         je 0x7acb93
// 007ac573  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ac577  80781c00             cmp byte ptr [eax + 0x1c], 0
// 007ac57b  751b                 jne 0x7ac598
// 007ac57d  83782000             cmp dword ptr [eax + 0x20], 0
// 007ac581  7c15                 jl 0x7ac598
// 007ac583  0fb74020             movzx eax, word ptr [eax + 0x20]
// 007ac587  8b0dbc389700         mov ecx, dword ptr [0x9738bc]
// 007ac58d  50                   push eax
// 007ac58e  ff15bc4c8000         call dword ptr [0x804cbc]
// 007ac594  8be8                 mov ebp, eax
// 007ac596  eb02                 jmp 0x7ac59a
// 007ac598  33ed                 xor ebp, ebp
// 007ac59a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007ac59e  8b542430             mov edx, dword ptr [esp + 0x30]
// 007ac5a2  51                   push ecx
// 007ac5a3  8b8a6c020000         mov ecx, dword ptr [edx + 0x26c]
// 007ac5a9  55                   push ebp
// 007ac5aa  e80114edff           call 0x67d9b0
// 007ac5af  8bf0                 mov esi, eax
// 007ac5b1  c6863c01000000       mov byte ptr [esi + 0x13c], 0
// 007ac5b8  eb24                 jmp 0x7ac5de
// 007ac5ba  8b4024               mov eax, dword ptr [eax + 0x24]
// 007ac5bd  85c0                 test eax, eax
// 007ac5bf  0f84ce050000         je 0x7acb93
// 007ac5c5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007ac5c9  8b542430             mov edx, dword ptr [esp + 0x30]
// 007ac5cd  51                   push ecx
// 007ac5ce  8b8a6c020000         mov ecx, dword ptr [edx + 0x26c]
// 007ac5d4  8be8                 mov ebp, eax
// 007ac5d6  55                   push ebp
// 007ac5d7  e8d413edff           call 0x67d9b0
// 007ac5dc  8bf0                 mov esi, eax
// 007ac5de  8b03                 mov eax, dword ptr [ebx]
// 007ac5e0  8b3e                 mov edi, dword ptr [esi]
// 007ac5e2  8b5024               mov edx, dword ptr [eax + 0x24]
// 007ac5e5  8bcb                 mov ecx, ebx
// 007ac5e7  83c748               add edi, 0x48
// 007ac5ea  ffd2                 call edx
// 007ac5ec  8b07                 mov eax, dword ptr [edi]
// 007ac5ee  51                   push ecx
// 007ac5ef  8bce                 mov ecx, esi
// 007ac5f1  d91c24               fstp dword ptr [esp]
// 007ac5f4  ffd0                 call eax
// 007ac5f6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007ac5fa  8b8180000000         mov eax, dword ptr [ecx + 0x80]
// 007ac600  898640010000         mov dword ptr [esi + 0x140], eax
// 007ac606  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ac60a  83b88000000000       cmp dword ptr [eax + 0x80], 0
// 007ac611  7514                 jne 0x7ac627
// 007ac613  83b88400000001       cmp dword ptr [eax + 0x84], 1
// 007ac61a  750b                 jne 0x7ac627
// 007ac61c  c6863c01000000       mov byte ptr [esi + 0x13c], 0
// 007ac623  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ac627  83b88400000004       cmp dword ptr [eax + 0x84], 4
// 007ac62e  7507                 jne 0x7ac637
// 007ac630  c6863c01000000       mov byte ptr [esi + 0x13c], 0
// 007ac637  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007ac63b  8b03                 mov eax, dword ptr [ebx]
// 007ac63d  897310               mov dword ptr [ebx + 0x10], esi
// 007ac640  8b976c020000         mov edx, dword ptr [edi + 0x26c]
// 007ac646  89530c               mov dword ptr [ebx + 0xc], edx
// 007ac649  8b501c               mov edx, dword ptr [eax + 0x1c]
// 007ac64c  8bcb                 mov ecx, ebx
// 007ac64e  ffd2                 call edx
// 007ac650  8bf0                 mov esi, eax
// 007ac652  8b876c020000         mov eax, dword ptr [edi + 0x26c]
// 007ac658  057c020000           add eax, 0x27c
// 007ac65d  50                   push eax
// 007ac65e  8d8c24dc010000       lea ecx, [esp + 0x1dc]
// 007ac665  83c624               add esi, 0x24
// 007ac668  ff15c4488000         call dword ptr [0x8048c4]
// 007ac66e  d906                 fld dword ptr [esi]
// 007ac670  d9e1                 fabs 
// 007ac672  c684242803000028     mov byte ptr [esp + 0x328], 0x28
// 007ac67a  d9056c748200         fld dword ptr [0x82746c]
// 007ac680  d8d1                 fcom st(1)
// 007ac682  dfe0                 fnstsw ax
// 007ac684  ddd9                 fstp st(1)
// 007ac686  f6c441               test ah, 0x41
// 007ac689  0f8539020000         jne 0x7ac8c8
// 007ac68f  d94604               fld dword ptr [esi + 4]
// 007ac692  d9e1                 fabs 
// 007ac694  d8d9                 fcomp st(1)
// 007ac696  dfe0                 fnstsw ax
// 007ac698  f6c405               test ah, 5
// 007ac69b  0f8a27020000         jp 0x7ac8c8
// 007ac6a1  d94608               fld dword ptr [esi + 8]
// 007ac6a4  d9e1                 fabs 
// 007ac6a6  ded9                 fcompp 
// 007ac6a8  dfe0                 fnstsw ax
// 007ac6aa  f6c405               test ah, 5
// 007ac6ad  0f8a17020000         jp 0x7ac8ca
// 007ac6b3  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ac6b7  3b6824               cmp ebp, dword ptr [eax + 0x24]
// 007ac6ba  0f8436010000         je 0x7ac7f6
// 007ac6c0  8bc7                 mov eax, edi
// 007ac6c2  8b8868020000         mov ecx, dword ptr [eax + 0x268]
// 007ac6c8  8b11                 mov edx, dword ptr [ecx]
// 007ac6ca  8b82c8010000         mov eax, dword ptr [edx + 0x1c8]
// 007ac6d0  55                   push ebp
// 007ac6d1  ffd0                 call eax
// 007ac6d3  8b13                 mov edx, dword ptr [ebx]
// 007ac6d5  8bf8                 mov edi, eax
// 007ac6d7  d907                 fld dword ptr [edi]
// 007ac6d9  8b421c               mov eax, dword ptr [edx + 0x1c]
// 007ac6dc  8bcb                 mov ecx, ebx
// 007ac6de  d95c241c             fstp dword ptr [esp + 0x1c]
// 007ac6e2  ffd0                 call eax
// 007ac6e4  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 007ac6e8  8bf0                 mov esi, eax
// 007ac6ea  8b856c020000         mov eax, dword ptr [ebp + 0x26c]
// 007ac6f0  057c020000           add eax, 0x27c
// 007ac6f5  50                   push eax
// 007ac6f6  8d4c247c             lea ecx, [esp + 0x7c]
// 007ac6fa  83c624               add esi, 0x24
// 007ac6fd  ff15c4488000         call dword ptr [0x8048c4]
// 007ac703  d94704               fld dword ptr [edi + 4]
// 007ac706  d806                 fadd dword ptr [esi]
// 007ac708  8d8c2444010000       lea ecx, [esp + 0x144]
// 007ac70f  d94708               fld dword ptr [edi + 8]
// 007ac712  51                   push ecx
// 007ac713  d84604               fadd dword ptr [esi + 4]
// 007ac716  8d942454010000       lea edx, [esp + 0x154]
// 007ac71d  d9470c               fld dword ptr [edi + 0xc]
// 007ac720  52                   push edx
// 007ac721  d84608               fadd dword ptr [esi + 8]
// 007ac724  8d8c2490010000       lea ecx, [esp + 0x190]
// 007ac72b  d9442424             fld dword ptr [esp + 0x24]
// 007ac72f  c684243003000029     mov byte ptr [esp + 0x330], 0x29
// 007ac737  dceb                 fsub st(3), st(0)
// 007ac739  dcea                 fsub st(2), st(0)
// 007ac73b  dce9                 fsub st(1), st(0)
// 007ac73d  d9cb                 fxch st(3)
// 007ac73f  d99c2458010000       fstp dword ptr [esp + 0x158]
// 007ac746  d9c9                 fxch st(1)
// 007ac748  d99c245c010000       fstp dword ptr [esp + 0x15c]
// 007ac74f  d99c2460010000       fstp dword ptr [esp + 0x160]
// 007ac756  d906                 fld dword ptr [esi]
// 007ac758  d84704               fadd dword ptr [edi + 4]
// 007ac75b  d94708               fld dword ptr [edi + 8]
// 007ac75e  d84604               fadd dword ptr [esi + 4]
// 007ac761  d9470c               fld dword ptr [edi + 0xc]
// 007ac764  d84608               fadd dword ptr [esi + 8]
// 007ac767  d9c3                 fld st(3)
// 007ac769  dec3                 faddp st(3)
// 007ac76b  d9c3                 fld st(3)
// 007ac76d  dec2                 faddp st(2)
// 007ac76f  dec3                 faddp st(3)
// 007ac771  d9c9                 fxch st(1)
// 007ac773  d99c244c010000       fstp dword ptr [esp + 0x14c]
// 007ac77a  d99c2450010000       fstp dword ptr [esp + 0x150]
// 007ac781  d99c2454010000       fstp dword ptr [esp + 0x154]
// 007ac788  ff1598438000         call dword ptr [0x804398]
// 007ac78e  8d842488010000       lea eax, [esp + 0x188]
// 007ac795  50                   push eax
// 007ac796  8d4c247c             lea ecx, [esp + 0x7c]
// 007ac79a  c684242c0300002a     mov byte ptr [esp + 0x32c], 0x2a
// 007ac7a2  ff15c0468000         call dword ptr [0x8046c0]
// 007ac7a8  83ec20               sub esp, 0x20
// 007ac7ab  8d942498000000       lea edx, [esp + 0x98]
// 007ac7b2  8bcc                 mov ecx, esp
// 007ac7b4  8964243c             mov dword ptr [esp + 0x3c], esp
// 007ac7b8  52                   push edx
// 007ac7b9  ff15c4488000         call dword ptr [0x8048c4]
// 007ac7bf  8b8d6c020000         mov ecx, dword ptr [ebp + 0x26c]
// 007ac7c5  e876d4ffff           call 0x7a9c40
// 007ac7ca  8d8c2488010000       lea ecx, [esp + 0x188]
// 007ac7d1  c684242803000029     mov byte ptr [esp + 0x328], 0x29
// 007ac7d9  ff15ec438000         call dword ptr [0x8043ec]
// 007ac7df  8d4c2478             lea ecx, [esp + 0x78]
// 007ac7e3  c684242803000028     mov byte ptr [esp + 0x328], 0x28
// 007ac7eb  ff15ec438000         call dword ptr [0x8043ec]
// 007ac7f1  e9d4000000           jmp 0x7ac8ca
// 007ac7f6  8b4024               mov eax, dword ptr [eax + 0x24]
// 007ac7f9  d980d8000000         fld dword ptr [eax + 0xd8]
// 007ac7ff  8d8c2420010000       lea ecx, [esp + 0x120]
// 007ac806  d806                 fadd dword ptr [esi]
// 007ac808  d980dc000000         fld dword ptr [eax + 0xdc]
// 007ac80e  d84604               fadd dword ptr [esi + 4]
// 007ac811  d980e0000000         fld dword ptr [eax + 0xe0]
// 007ac817  d84608               fadd dword ptr [esi + 8]
// 007ac81a  d9ca                 fxch st(2)
// 007ac81c  d99c242c010000       fstp dword ptr [esp + 0x12c]
// 007ac823  d99c2430010000       fstp dword ptr [esp + 0x130]
// 007ac82a  d99c2434010000       fstp dword ptr [esp + 0x134]
// 007ac831  d980cc000000         fld dword ptr [eax + 0xcc]
// 007ac837  d806                 fadd dword ptr [esi]
// 007ac839  d980d0000000         fld dword ptr [eax + 0xd0]
// 007ac83f  d84604               fadd dword ptr [esi + 4]
// 007ac842  d980d4000000         fld dword ptr [eax + 0xd4]
// 007ac848  8d84242c010000       lea eax, [esp + 0x12c]
// 007ac84f  d84608               fadd dword ptr [esi + 8]
// 007ac852  50                   push eax
// 007ac853  d9ca                 fxch st(2)
// 007ac855  51                   push ecx
// 007ac856  d99c2428010000       fstp dword ptr [esp + 0x128]
// 007ac85d  8d8c2480000000       lea ecx, [esp + 0x80]
// 007ac864  d99c242c010000       fstp dword ptr [esp + 0x12c]
// 007ac86b  d99c2430010000       fstp dword ptr [esp + 0x130]
// 007ac872  ff1598438000         call dword ptr [0x804398]
// 007ac878  8d542478             lea edx, [esp + 0x78]
// 007ac87c  52                   push edx
// 007ac87d  8d8c24dc010000       lea ecx, [esp + 0x1dc]
// 007ac884  c684242c0300002b     mov byte ptr [esp + 0x32c], 0x2b
// 007ac88c  ff15c0468000         call dword ptr [0x8046c0]
// 007ac892  83ec20               sub esp, 0x20
// 007ac895  8d8424f8010000       lea eax, [esp + 0x1f8]
// 007ac89c  8bcc                 mov ecx, esp
// 007ac89e  8964243c             mov dword ptr [esp + 0x3c], esp
// 007ac8a2  50                   push eax
// 007ac8a3  ff15c4488000         call dword ptr [0x8048c4]
// 007ac8a9  8b8f6c020000         mov ecx, dword ptr [edi + 0x26c]
// 007ac8af  e88cd3ffff           call 0x7a9c40
// 007ac8b4  8d4c2478             lea ecx, [esp + 0x78]
// 007ac8b8  c684242803000028     mov byte ptr [esp + 0x328], 0x28
// 007ac8c0  ff15ec438000         call dword ptr [0x8043ec]
// 007ac8c6  eb02                 jmp 0x7ac8ca
// 007ac8c8  ddd8                 fstp st(0)
// 007ac8ca  8d8c24d8010000       lea ecx, [esp + 0x1d8]
// 007ac8d1  c68424280300000c     mov byte ptr [esp + 0x328], 0xc
// 007ac8d9  ff15ec438000         call dword ptr [0x8043ec]
// 007ac8df  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 007ac8e3  8b742424             mov esi, dword ptr [esp + 0x24]
// 007ac8e7  eb77                 jmp 0x7ac960
// 007ac8e9  807c241200           cmp byte ptr [esp + 0x12], 0
// 007ac8ee  8b742424             mov esi, dword ptr [esp + 0x24]
// 007ac8f2  750a                 jne 0x7ac8fe
// 007ac8f4  56                   push esi
// 007ac8f5  e8d687edff           call 0x6850d0
// 007ac8fa  85c0                 test eax, eax
// 007ac8fc  7562                 jne 0x7ac960
// 007ac8fe  807c241300           cmp byte ptr [esp + 0x13], 0
// 007ac903  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ac907  7446                 je 0x7ac94f
// 007ac909  80781c00             cmp byte ptr [eax + 0x1c], 0
// 007ac90d  7551                 jne 0x7ac960
// 007ac90f  83782000             cmp dword ptr [eax + 0x20], 0
// 007ac913  7c4b                 jl 0x7ac960
// 007ac915  0fb74820             movzx ecx, word ptr [eax + 0x20]
// 007ac919  8b3dbc4c8000         mov edi, dword ptr [0x804cbc]
// 007ac91f  51                   push ecx
// 007ac920  8b0dbc389700         mov ecx, dword ptr [0x9738bc]
// 007ac926  ffd7                 call edi
// 007ac928  85c0                 test eax, eax
// 007ac92a  7434                 je 0x7ac960
// 007ac92c  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ac930  80781c00             cmp byte ptr [eax + 0x1c], 0
// 007ac934  7515                 jne 0x7ac94b
// 007ac936  83782000             cmp dword ptr [eax + 0x20], 0
// 007ac93a  7c0f                 jl 0x7ac94b
// 007ac93c  0fb75020             movzx edx, word ptr [eax + 0x20]
// 007ac940  8b0dbc389700         mov ecx, dword ptr [0x9738bc]
// 007ac946  52                   push edx
// 007ac947  ffd7                 call edi
// 007ac949  eb0b                 jmp 0x7ac956
// 007ac94b  33c0                 xor eax, eax
// 007ac94d  eb07                 jmp 0x7ac956
// 007ac94f  8b4024               mov eax, dword ptr [eax + 0x24]
// 007ac952  85c0                 test eax, eax
// 007ac954  740a                 je 0x7ac960
// 007ac956  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 007ac959  50                   push eax
// 007ac95a  56                   push esi
// 007ac95b  e85087edff           call 0x6850b0
// 007ac960  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 007ac963  56                   push esi
// 007ac964  e88787edff           call 0x6850f0
// 007ac969  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 007ac96c  8b31                 mov esi, dword ptr [ecx]
// 007ac96e  8b13                 mov edx, dword ptr [ebx]
// 007ac970  8b4224               mov eax, dword ptr [edx + 0x24]
// 007ac973  8bcb                 mov ecx, ebx
// 007ac975  83c648               add esi, 0x48
// 007ac978  ffd0                 call eax
// 007ac97a  8b16                 mov edx, dword ptr [esi]
// 007ac97c  51                   push ecx
// 007ac97d  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 007ac980  d91c24               fstp dword ptr [esp]
// 007ac983  ffd2                 call edx
// 007ac985  8b7310               mov esi, dword ptr [ebx + 0x10]
// 007ac988  85ed                 test ebp, ebp
// 007ac98a  7432                 je 0x7ac9be
// 007ac98c  807c241100           cmp byte ptr [esp + 0x11], 0
// 007ac991  7518                 jne 0x7ac9ab
// 007ac993  8b06                 mov eax, dword ptr [esi]
// 007ac995  8b5004               mov edx, dword ptr [eax + 4]
// 007ac998  8bce                 mov ecx, esi
// 007ac99a  ffd2                 call edx
// 007ac99c  8b4004               mov eax, dword ptr [eax + 4]
// 007ac99f  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007ac9a3  3b8174020000         cmp eax, dword ptr [ecx + 0x274]
// 007ac9a9  7513                 jne 0x7ac9be
// 007ac9ab  8b4530               mov eax, dword ptr [ebp + 0x30]
// 007ac9ae  85c0                 test eax, eax
// 007ac9b0  740c                 je 0x7ac9be
// 007ac9b2  83c024               add eax, 0x24
// 007ac9b5  50                   push eax
// 007ac9b6  8bce                 mov ecx, esi
// 007ac9b8  ff1584458000         call dword ptr [0x804584]
// 007ac9be  8b13                 mov edx, dword ptr [ebx]
// 007ac9c0  8b421c               mov eax, dword ptr [edx + 0x1c]
// 007ac9c3  8bcb                 mov ecx, ebx
// 007ac9c5  ffd0                 call eax
// 007ac9c7  d9e8                 fld1 
// 007ac9c9  d99c2410010000       fstp dword ptr [esp + 0x110]
// 007ac9d0  50                   push eax
// 007ac9d1  d9ee                 fldz 
// 007ac9d3  8d8c2414010000       lea ecx, [esp + 0x114]
// 007ac9da  d9942418010000       fst dword ptr [esp + 0x118]
// 007ac9e1  d994241c010000       fst dword ptr [esp + 0x11c]
// 007ac9e8  d99c2420010000       fstp dword ptr [esp + 0x120]
// 007ac9ef  ff15784c8000         call dword ptr [0x804c78]
// 007ac9f5  8b13                 mov edx, dword ptr [ebx]
// 007ac9f7  8b421c               mov eax, dword ptr [edx + 0x1c]
// 007ac9fa  8bcb                 mov ecx, ebx
// 007ac9fc  ffd0                 call eax
// 007ac9fe  d9e8                 fld1 
// 007aca00  d9942438010000       fst dword ptr [esp + 0x138]
// 007aca07  83c024               add eax, 0x24
// 007aca0a  d994243c010000       fst dword ptr [esp + 0x13c]
// 007aca11  8d8c2410010000       lea ecx, [esp + 0x110]
// 007aca18  d99c2440010000       fstp dword ptr [esp + 0x140]
// 007aca1f  51                   push ecx
// 007aca20  d900                 fld dword ptr [eax]
// 007aca22  8d94243c010000       lea edx, [esp + 0x13c]
// 007aca29  d94004               fld dword ptr [eax + 4]
// 007aca2c  52                   push edx
// 007aca2d  d94008               fld dword ptr [eax + 8]
// 007aca30  8d8c24e8020000       lea ecx, [esp + 0x2e8]
// 007aca37  d9ca                 fxch st(2)
// 007aca39  8d8424ac000000       lea eax, [esp + 0xac]
// 007aca40  d99c24ac000000       fstp dword ptr [esp + 0xac]
// 007aca47  50                   push eax
// 007aca48  d99c24b4000000       fstp dword ptr [esp + 0xb4]
// 007aca4f  d99c24b8000000       fstp dword ptr [esp + 0xb8]
// 007aca56  ff15744c8000         call dword ptr [0x804c74]
// 007aca5c  8b5b10               mov ebx, dword ptr [ebx + 0x10]
// 007aca5f  8dbbf0000000         lea edi, [ebx + 0xf0]
// 007aca65  b910000000           mov ecx, 0x10
// 007aca6a  8db424e0020000       lea esi, [esp + 0x2e0]
// 007aca71  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007aca73  8b442414             mov eax, dword ptr [esp + 0x14]
// 007aca77  c68424280300000b     mov byte ptr [esp + 0x328], 0xb
// 007aca7f  85c0                 test eax, eax
// 007aca81  7450                 je 0x7acad3
// 007aca83  83c004               add eax, 4
// 007aca86  50                   push eax
// 007aca87  ff15ac218000         call dword ptr [0x8021ac]
// 007aca8d  85c0                 test eax, eax
// 007aca8f  753a                 jne 0x7acacb
// 007aca91  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007aca95  8b7108               mov esi, dword ptr [ecx + 8]
// 007aca98  85f6                 test esi, esi
// 007aca9a  7423                 je 0x7acabf
// 007aca9c  8d642400             lea esp, [esp]
// 007acaa0  8b0e                 mov ecx, dword ptr [esi]
// 007acaa2  8b11                 mov edx, dword ptr [ecx]
// 007acaa4  8b4204               mov eax, dword ptr [edx + 4]
// 007acaa7  ffd0                 call eax
// 007acaa9  8bc6                 mov eax, esi
// 007acaab  8b7604               mov esi, dword ptr [esi + 4]
// 007acaae  50                   push eax
// 007acaaf  e8c63befff           call 0x6a067a
// 007acab4  83c404               add esp, 4
// 007acab7  85f6                 test esi, esi
// 007acab9  75e5                 jne 0x7acaa0
// 007acabb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007acabf  85c9                 test ecx, ecx
// 007acac1  7408                 je 0x7acacb
// 007acac3  8b11                 mov edx, dword ptr [ecx]
// 007acac5  8b02                 mov eax, dword ptr [edx]
// 007acac7  6a01                 push 1
// 007acac9  ffd0                 call eax
// 007acacb  c744241400000000     mov dword ptr [esp + 0x14], 0
// 007acad3  8b442418             mov eax, dword ptr [esp + 0x18]
// 007acad7  c684242803000000     mov byte ptr [esp + 0x328], 0
// 007acadf  85c0                 test eax, eax
// 007acae1  7450                 je 0x7acb33
// 007acae3  83c004               add eax, 4
// 007acae6  50                   push eax
// 007acae7  ff15ac218000         call dword ptr [0x8021ac]
// 007acaed  85c0                 test eax, eax
// 007acaef  753a                 jne 0x7acb2b
// 007acaf1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007acaf5  8b7108               mov esi, dword ptr [ecx + 8]
// 007acaf8  85f6                 test esi, esi
// 007acafa  7423                 je 0x7acb1f
// 007acafc  8d642400             lea esp, [esp]
// 007acb00  8b0e                 mov ecx, dword ptr [esi]
// 007acb02  8b11                 mov edx, dword ptr [ecx]
// 007acb04  8b4204               mov eax, dword ptr [edx + 4]
// 007acb07  ffd0                 call eax
// 007acb09  8bc6                 mov eax, esi
// 007acb0b  8b7604               mov esi, dword ptr [esi + 4]
// 007acb0e  50                   push eax
// 007acb0f  e8663befff           call 0x6a067a
// 007acb14  83c404               add esp, 4
// 007acb17  85f6                 test esi, esi
// 007acb19  75e5                 jne 0x7acb00
// 007acb1b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007acb1f  85c9                 test ecx, ecx
// 007acb21  7408                 je 0x7acb2b
// 007acb23  8b11                 mov edx, dword ptr [ecx]
// 007acb25  8b02                 mov eax, dword ptr [edx]
// 007acb27  6a01                 push 1
// 007acb29  ffd0                 call eax
// 007acb2b  c744241800000000     mov dword ptr [esp + 0x18], 0
// 007acb33  8b442428             mov eax, dword ptr [esp + 0x28]
// 007acb37  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 007acb3b  40                   inc eax
// 007acb3c  3b450c               cmp eax, dword ptr [ebp + 0xc]
// 007acb3f  89442428             mov dword ptr [esp + 0x28], eax
// 007acb43  0f8cfceaffff         jl 0x7ab645
// 007acb49  807c241300           cmp byte ptr [esp + 0x13], 0
// 007acb4e  746f                 je 0x7acbbf
// 007acb50  803dbc2e940000       cmp byte ptr [0x942ebc], 0
// 007acb57  7466                 je 0x7acbbf
// 007acb59  8bbc2430030000       mov edi, dword ptr [esp + 0x330]
// 007acb60  57                   push edi
// 007acb61  e87ac8d9ff           call 0x5493e0
// 007acb66  83c404               add esp, 4
// 007acb69  83bd6c02000000       cmp dword ptr [ebp + 0x26c], 0
// 007acb70  7454                 je 0x7acbc6
// 007acb72  83ec0c               sub esp, 0xc
// 007acb75  8bcc                 mov ecx, esp
// 007acb77  89642428             mov dword ptr [esp + 0x28], esp
// 007acb7b  68b8389700           push 0x9738b8
// 007acb80  ff15684c8000         call dword ptr [0x804c68]
// 007acb86  8b8d6c020000         mov ecx, dword ptr [ebp + 0x26c]
// 007acb8c  e88ff9ecff           call 0x67c520
// 007acb91  eb33                 jmp 0x7acbc6
// 007acb93  8d4c241c             lea ecx, [esp + 0x1c]
// 007acb97  51                   push ecx
// 007acb98  8d8c24a8000000       lea ecx, [esp + 0xa8]
// 007acb9f  c7442420f8498700     mov dword ptr [esp + 0x20], 0x8749f8
// 007acba7  ff15a4288000         call dword ptr [0x8028a4]
// 007acbad  687c998d00           push 0x8d997c
// 007acbb2  8d9424a8000000       lea edx, [esp + 0xa8]
// 007acbb9  52                   push edx
// 007acbba  e8cd49efff           call 0x6a158c
// 007acbbf  8bbc2430030000       mov edi, dword ptr [esp + 0x330]
// 007acbc6  8b35604d8000         mov esi, dword ptr [0x804d60]
// 007acbcc  8d8c2430020000       lea ecx, [esp + 0x230]
// 007acbd3  ffd6                 call esi
// 007acbd5  8d8c2430020000       lea ecx, [esp + 0x230]
// 007acbdc  ff15804e8000         call dword ptr [0x804e80]
// 007acbe2  8b8d6c020000         mov ecx, dword ptr [ebp + 0x26c]
// 007acbe8  85c9                 test ecx, ecx
// 007acbea  7471                 je 0x7acc5d
// 007acbec  8d4718               lea eax, [edi + 0x18]
// 007acbef  50                   push eax
// 007acbf0  e81bf9ecff           call 0x67c510
// 007acbf5  8b856c020000         mov eax, dword ptr [ebp + 0x26c]
// 007acbfb  c6807902000000       mov byte ptr [eax + 0x279], 0
// 007acc02  8b8d6c020000         mov ecx, dword ptr [ebp + 0x26c]
// 007acc08  8b11                 mov edx, dword ptr [ecx]
// 007acc0a  8b82d8000000         mov eax, dword ptr [edx + 0xd8]
// 007acc10  6a01                 push 1
// 007acc12  ffd0                 call eax
// 007acc14  80bdf402000000       cmp byte ptr [ebp + 0x2f4], 0
// 007acc1b  8b856c020000         mov eax, dword ptr [ebp + 0x26c]
// 007acc21  741e                 je 0x7acc41
// 007acc23  d90520b08400         fld dword ptr [0x84b020]
// 007acc29  d9989c020000         fstp dword ptr [eax + 0x29c]
// 007acc2f  8b856c020000         mov eax, dword ptr [ebp + 0x26c]
// 007acc35  c780a002000058020000 mov dword ptr [eax + 0x2a0], 0x258
// 007acc3f  eb1c                 jmp 0x7acc5d
// 007acc41  d905f0228200         fld dword ptr [0x8222f0]
// 007acc47  d9989c020000         fstp dword ptr [eax + 0x29c]
// 007acc4d  8b856c020000         mov eax, dword ptr [ebp + 0x26c]
// 007acc53  c780a00200008a020000 mov dword ptr [eax + 0x2a0], 0x28a
// 007acc5d  8b0d48db9700         mov ecx, dword ptr [0x97db48]
// 007acc63  ff1594438000         call dword ptr [0x804394]
// 007acc69  84c0                 test al, al
// 007acc6b  741f                 je 0x7acc8c
// 007acc6d  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 007acc70  8b11                 mov edx, dword ptr [ecx]
// 007acc72  8b4218               mov eax, dword ptr [edx + 0x18]
// 007acc75  ffd0                 call eax
// 007acc77  8b0d48db9700         mov ecx, dword ptr [0x97db48]
// 007acc7d  ff1590438000         call dword ptr [0x804390]
// 007acc83  8d8c2430020000       lea ecx, [esp + 0x230]
// 007acc8a  ffd6                 call esi
// 007acc8c  8d8c2430020000       lea ecx, [esp + 0x230]
// 007acc93  c7842428030000ffffffff mov dword ptr [esp + 0x328], 0xffffffff
// 007acc9e  ff15884e8000         call dword ptr [0x804e88]
// 007acca4  8b8c2420030000       mov ecx, dword ptr [esp + 0x320]
// 007accab  5f                   pop edi
// 007accac  5e                   pop esi
// 007accad  5d                   pop ebp
// 007accae  64890d00000000       mov dword ptr fs:[0], ecx
// 007accb5  5b                   pop ebx
// 007accb6  81c41c030000         add esp, 0x31c
// 007accbc  c20800               ret 8

void func_007ab820()
{
}
