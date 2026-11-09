// from server: 100% by EspClaude
// from server: 93% by colin
// roc 2008-06 006892d0  unit: Ogre::RbxSubEntity  size: 8940 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006892d0
//
// 006892d0  6aff                 push -1
// 006892d2  64a100000000         mov eax, dword ptr fs:[0]
// 006892d8  6884e07d00           push 0x7de084
// 006892dd  50                   push eax
// 006892de  b8c02e0000           mov eax, 0x2ec0
// 006892e3  64892500000000       mov dword ptr fs:[0], esp
// 006892ea  e831820100           call 0x6a1520
// 006892ef  55                   push ebp
// 006892f0  56                   push esi
// 006892f1  8bb424e02e0000       mov esi, dword ptr [esp + 0x2ee0]
// 006892f8  57                   push edi
// 006892f9  8bf9                 mov edi, ecx
// 006892fb  85f6                 test esi, esi
// 006892fd  751b                 jne 0x68931a
// 006892ff  8b8c24dc2e0000       mov ecx, dword ptr [esp + 0x2edc]
// 00689306  8b01                 mov eax, dword ptr [ecx]
// 00689308  8b9424e02e0000       mov edx, dword ptr [esp + 0x2ee0]
// 0068930f  8b80dc000000         mov eax, dword ptr [eax + 0xdc]
// 00689315  52                   push edx
// 00689316  ffd0                 call eax
// 00689318  8bf0                 mov esi, eax
// 0068931a  d9ee                 fldz 
// 0068931c  8b8c24ec2e0000       mov ecx, dword ptr [esp + 0x2eec]
// 00689323  d9542430             fst dword ptr [esp + 0x30]
// 00689327  33ed                 xor ebp, ebp
// 00689329  81f9f0000000         cmp ecx, 0xf0
// 0068932f  d9942488000000       fst dword ptr [esp + 0x88]
// 00689336  d9542420             fst dword ptr [esp + 0x20]
// 0068933a  d9542428             fst dword ptr [esp + 0x28]
// 0068933e  d9542444             fst dword ptr [esp + 0x44]
// 00689342  7c0c                 jl 0x689350
// 00689344  b9ef000000           mov ecx, 0xef
// 00689349  898c24ec2e0000       mov dword ptr [esp + 0x2eec], ecx
// 00689350  8b9424f02e0000       mov edx, dword ptr [esp + 0x2ef0]
// 00689357  81faf0000000         cmp edx, 0xf0
// 0068935d  7c0c                 jl 0x68936b
// 0068935f  baef000000           mov edx, 0xef
// 00689364  899424f02e0000       mov dword ptr [esp + 0x2ef0], edx
// 0068936b  83f902               cmp ecx, 2
// 0068936e  0f8c1a220000         jl 0x68b58e
// 00689374  83fa01               cmp edx, 1
// 00689377  0f8c11220000         jl 0x68b58e
// 0068937d  d98424e82e0000       fld dword ptr [esp + 0x2ee8]
// 00689384  d8d1                 fcom st(1)
// 00689386  dfe0                 fnstsw ax
// 00689388  f6c405               test ah, 5
// 0068938b  0f8bfb210000         jnp 0x68b58c
// 00689391  8b07                 mov eax, dword ptr [edi]
// 00689393  c644242f00           mov byte ptr [esp + 0x2f], 0
// 00689398  c644241b00           mov byte ptr [esp + 0x1b], 0
// 0068939d  85c0                 test eax, eax
// 0068939f  7505                 jne 0x6893a6
// 006893a1  c644241b01           mov byte ptr [esp + 0x1b], 1
// 006893a6  83f801               cmp eax, 1
// 006893a9  7515                 jne 0x6893c0
// 006893ab  8b470c               mov eax, dword ptr [edi + 0xc]
// 006893ae  85c0                 test eax, eax
// 006893b0  7405                 je 0x6893b7
// 006893b2  c644242f01           mov byte ptr [esp + 0x2f], 1
// 006893b7  83f801               cmp eax, 1
// 006893ba  7504                 jne 0x6893c0
// 006893bc  8844241b             mov byte ptr [esp + 0x1b], al
// 006893c0  d90534c48100         fld dword ptr [0x81c434]
// 006893c6  33c0                 xor eax, eax
// 006893c8  53                   push ebx
// 006893c9  89442414             mov dword ptr [esp + 0x14], eax
// 006893cd  85c9                 test ecx, ecx
// 006893cf  7e55                 jle 0x689426
// 006893d1  db8424f02e0000       fild dword ptr [esp + 0x2ef0]
// 006893d8  807c241f00           cmp byte ptr [esp + 0x1f], 0
// 006893dd  db442414             fild dword ptr [esp + 0x14]
// 006893e1  8b1de8468000         mov ebx, dword ptr [0x8046e8]
// 006893e7  d80b                 fmul dword ptr [ebx]
// 006893e9  d8ca                 fmul st(2)
// 006893eb  d8f1                 fdiv st(1)
// 006893ed  d9c0                 fld st(0)
// 006893ef  d9fe                 fsin 
// 006893f1  d99484d0010000       fst dword ptr [esp + eax*4 + 0x1d0]
// 006893f8  d9c9                 fxch st(1)
// 006893fa  d9ff                 fcos 
// 006893fc  d9948490050000       fst dword ptr [esp + eax*4 + 0x590]
// 00689403  7412                 je 0x689417
// 00689405  d9c9                 fxch st(1)
// 00689407  d99c84100d0000       fstp dword ptr [esp + eax*4 + 0xd10]
// 0068940e  d99c8450090000       fstp dword ptr [esp + eax*4 + 0x950]
// 00689415  eb04                 jmp 0x68941b
// 00689417  ddd8                 fstp st(0)
// 00689419  ddd8                 fstp st(0)
// 0068941b  40                   inc eax
// 0068941c  3bc1                 cmp eax, ecx
// 0068941e  89442414             mov dword ptr [esp + 0x14], eax
// 00689422  7cb4                 jl 0x6893d8
// 00689424  ddd8                 fstp st(0)
// 00689426  33c0                 xor eax, eax
// 00689428  89442410             mov dword ptr [esp + 0x10], eax
// 0068942c  85d2                 test edx, edx
// 0068942e  7c6b                 jl 0x68949b
// 00689430  db8424f42e0000       fild dword ptr [esp + 0x2ef4]
// 00689437  807c241f00           cmp byte ptr [esp + 0x1f], 0
// 0068943c  db442410             fild dword ptr [esp + 0x10]
// 00689440  8b1de8468000         mov ebx, dword ptr [0x8046e8]
// 00689446  d80b                 fmul dword ptr [ebx]
// 00689448  d8f1                 fdiv st(1)
// 0068944a  742c                 je 0x689478
// 0068944c  d9c0                 fld st(0)
// 0068944e  d9fe                 fsin 
// 00689450  396f08               cmp dword ptr [edi + 8], ebp
// 00689453  750d                 jne 0x689462
// 00689455  d99c8450180000       fstp dword ptr [esp + eax*4 + 0x1850]
// 0068945c  d9c0                 fld st(0)
// 0068945e  d9ff                 fcos 
// 00689460  eb0f                 jmp 0x689471
// 00689462  d9e0                 fchs 
// 00689464  d99c8450180000       fstp dword ptr [esp + eax*4 + 0x1850]
// 0068946b  d9c0                 fld st(0)
// 0068946d  d9ff                 fcos 
// 0068946f  d9e0                 fchs 
// 00689471  d99c8490140000       fstp dword ptr [esp + eax*4 + 0x1490]
// 00689478  d9c0                 fld st(0)
// 0068947a  40                   inc eax
// 0068947b  3bc2                 cmp eax, edx
// 0068947d  d9fe                 fsin 
// 0068947f  89442410             mov dword ptr [esp + 0x10], eax
// 00689483  d8cc                 fmul st(4)
// 00689485  d99c84cc100000       fstp dword ptr [esp + eax*4 + 0x10cc]
// 0068948c  d9ff                 fcos 
// 0068948e  d8cb                 fmul st(3)
// 00689490  d99c840c1c0000       fstp dword ptr [esp + eax*4 + 0x1c0c]
// 00689497  7e9e                 jle 0x689437
// 00689499  ddd8                 fstp st(0)
// 0068949b  807c243300           cmp byte ptr [esp + 0x33], 0
// 006894a0  ddd9                 fstp st(1)
// 006894a2  d9c9                 fxch st(1)
// 006894a4  8d8494d0100000       lea eax, [esp + edx*4 + 0x10d0]
// 006894ab  d99424d0100000       fst dword ptr [esp + 0x10d0]
// 006894b2  89442420             mov dword ptr [esp + 0x20], eax
// 006894b6  d918                 fstp dword ptr [eax]
// 006894b8  0f84a3000000         je 0x689561
// 006894be  dd0538e78100         fld qword ptr [0x81e738]
// 006894c4  8b1de8468000         mov ebx, dword ptr [0x8046e8]
// 006894ca  33c0                 xor eax, eax
// 006894cc  89442414             mov dword ptr [esp + 0x14], eax
// 006894d0  85c9                 test ecx, ecx
// 006894d2  7e34                 jle 0x689508
// 006894d4  d903                 fld dword ptr [ebx]
// 006894d6  deca                 fmulp st(2)
// 006894d8  db8424f02e0000       fild dword ptr [esp + 0x2ef0]
// 006894df  db442414             fild dword ptr [esp + 0x14]
// 006894e3  40                   inc eax
// 006894e4  3bc1                 cmp eax, ecx
// 006894e6  89442414             mov dword ptr [esp + 0x14], eax
// 006894ea  d8e2                 fsub st(2)
// 006894ec  d8cb                 fmul st(3)
// 006894ee  d8f1                 fdiv st(1)
// 006894f0  d9c0                 fld st(0)
// 006894f2  d9fe                 fsin 
// 006894f4  d99c84cc1f0000       fstp dword ptr [esp + eax*4 + 0x1fcc]
// 006894fb  d9ff                 fcos 
// 006894fd  d99c848c230000       fstp dword ptr [esp + eax*4 + 0x238c]
// 00689504  7cd9                 jl 0x6894df
// 00689506  ddda                 fstp st(2)
// 00689508  33c0                 xor eax, eax
// 0068950a  ddd9                 fstp st(1)
// 0068950c  89442410             mov dword ptr [esp + 0x10], eax
// 00689510  85d2                 test edx, edx
// 00689512  7c4d                 jl 0x689561
// 00689514  db8424f42e0000       fild dword ptr [esp + 0x2ef4]
// 0068951b  8b4f08               mov ecx, dword ptr [edi + 8]
// 0068951e  db442410             fild dword ptr [esp + 0x10]
// 00689522  d8e2                 fsub st(2)
// 00689524  d80b                 fmul dword ptr [ebx]
// 00689526  d8f1                 fdiv st(1)
// 00689528  d9c0                 fld st(0)
// 0068952a  d9fe                 fsin 
// 0068952c  85c9                 test ecx, ecx
// 0068952e  750b                 jne 0x68953b
// 00689530  d99c8450270000       fstp dword ptr [esp + eax*4 + 0x2750]
// 00689537  d9ff                 fcos 
// 00689539  eb0d                 jmp 0x689548
// 0068953b  d9e0                 fchs 
// 0068953d  d99c8450270000       fstp dword ptr [esp + eax*4 + 0x2750]
// 00689544  d9ff                 fcos 
// 00689546  d9e0                 fchs 
// 00689548  d99c84102b0000       fstp dword ptr [esp + eax*4 + 0x2b10]
// 0068954f  40                   inc eax
// 00689550  3bc2                 cmp eax, edx
// 00689552  89442410             mov dword ptr [esp + 0x10], eax
// 00689556  7ec6                 jle 0x68951e
// 00689558  8b8c24f02e0000       mov ecx, dword ptr [esp + 0x2ef0]
// 0068955f  ddd8                 fstp st(0)
// 00689561  807c241f00           cmp byte ptr [esp + 0x1f], 0
// 00689566  ddd8                 fstp st(0)
// 00689568  d98424d0010000       fld dword ptr [esp + 0x1d0]
// 0068956f  d99c8cd0010000       fstp dword ptr [esp + ecx*4 + 0x1d0]
// 00689576  d9842490050000       fld dword ptr [esp + 0x590]
// 0068957d  d99c8c90050000       fstp dword ptr [esp + ecx*4 + 0x590]
// 00689584  741c                 je 0x6895a2
// 00689586  d98424100d0000       fld dword ptr [esp + 0xd10]
// 0068958d  d99c8c100d0000       fstp dword ptr [esp + ecx*4 + 0xd10]
// 00689594  d9842450090000       fld dword ptr [esp + 0x950]
// 0068959b  d99c8c50090000       fstp dword ptr [esp + ecx*4 + 0x950]
// 006895a2  807c243300           cmp byte ptr [esp + 0x33], 0
// 006895a7  741c                 je 0x6895c5
// 006895a9  d98424d01f0000       fld dword ptr [esp + 0x1fd0]
// 006895b0  d99c8cd01f0000       fstp dword ptr [esp + ecx*4 + 0x1fd0]
// 006895b7  d9842490230000       fld dword ptr [esp + 0x2390]
// 006895be  d99c8c90230000       fstp dword ptr [esp + ecx*4 + 0x2390]
// 006895c5  8b470c               mov eax, dword ptr [edi + 0xc]
// 006895c8  83f803               cmp eax, 3
// 006895cb  0f87b61f0000         ja 0x68b587
// 006895d1  ff2485acb56800       jmp dword ptr [eax*4 + 0x68b5ac]
// 006895d8  807f0400             cmp byte ptr [edi + 4], 0
// 006895dc  0f8526060000         jne 0x689c08
// 006895e2  4a                   dec edx
// 006895e3  bb01000000           mov ebx, 1
// 006895e8  6816b78000           push 0x80b716
// 006895ed  8d8c249c010000       lea ecx, [esp + 0x19c]
// 006895f4  899c2498000000       mov dword ptr [esp + 0x98], ebx
// 006895fb  89942494000000       mov dword ptr [esp + 0x94], edx
// 00689602  ff1558248000         call dword ptr [0x802458]
// 00689608  8b16                 mov edx, dword ptr [esi]
// 0068960a  8b92e0000000         mov edx, dword ptr [edx + 0xe0]
// 00689610  6a06                 push 6
// 00689612  8d84249c010000       lea eax, [esp + 0x19c]
// 00689619  50                   push eax
// 0068961a  8bce                 mov ecx, esi
// 0068961c  c78424e02e000000000000 mov dword ptr [esp + 0x2ee0], 0
// 00689627  ffd2                 call edx
// 00689629  8d8c2498010000       lea ecx, [esp + 0x198]
// 00689630  c78424d82e0000ffffffff mov dword ptr [esp + 0x2ed8], 0xffffffff
// 0068963b  ff1568248000         call dword ptr [0x802468]
// 00689641  d9ee                 fldz 
// 00689643  d85f10               fcomp dword ptr [edi + 0x10]
// 00689646  8d4f10               lea ecx, [edi + 0x10]
// 00689649  dfe0                 fnstsw ax
// 0068964b  f6c441               test ah, 0x41
// 0068964e  7a0d                 jp 0x68965d
// 00689650  8b06                 mov eax, dword ptr [esi]
// 00689652  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00689658  51                   push ecx
// 00689659  8bce                 mov ecx, esi
// 0068965b  ffd2                 call edx
// 0068965d  d94728               fld dword ptr [edi + 0x28]
// 00689660  8b06                 mov eax, dword ptr [esi]
// 00689662  d88424ec2e0000       fadd dword ptr [esp + 0x2eec]
// 00689669  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 0068966f  83ec0c               sub esp, 0xc
// 00689672  8bce                 mov ecx, esi
// 00689674  d95c2408             fstp dword ptr [esp + 8]
// 00689678  d94724               fld dword ptr [edi + 0x24]
// 0068967b  d95c2404             fstp dword ptr [esp + 4]
// 0068967f  d94720               fld dword ptr [edi + 0x20]
// 00689682  d91c24               fstp dword ptr [esp]
// 00689685  ffd2                 call edx
// 00689687  8b06                 mov eax, dword ptr [esi]
// 00689689  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068968f  6a00                 push 0
// 00689691  8bce                 mov ecx, esi
// 00689693  ffd2                 call edx
// 00689695  8b07                 mov eax, dword ptr [edi]
// 00689697  83e800               sub eax, 0
// 0068969a  741d                 je 0x6896b9
// 0068969c  83e801               sub eax, 1
// 0068969f  7566                 jne 0x689707
// 006896a1  d9842454270000       fld dword ptr [esp + 0x2754]
// 006896a8  d95c2434             fstp dword ptr [esp + 0x34]
// 006896ac  d98424142b0000       fld dword ptr [esp + 0x2b14]
// 006896b3  d95c242c             fstp dword ptr [esp + 0x2c]
// 006896b7  eb4e                 jmp 0x689707
// 006896b9  d9842454180000       fld dword ptr [esp + 0x1854]
// 006896c0  8b06                 mov eax, dword ptr [esi]
// 006896c2  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 006896c8  d95c2434             fstp dword ptr [esp + 0x34]
// 006896cc  d9842494140000       fld dword ptr [esp + 0x1494]
// 006896d3  83ec0c               sub esp, 0xc
// 006896d6  d95c2438             fstp dword ptr [esp + 0x38]
// 006896da  8bce                 mov ecx, esi
// 006896dc  d984249c140000       fld dword ptr [esp + 0x149c]
// 006896e3  d95c2408             fstp dword ptr [esp + 8]
// 006896e7  d984245c180000       fld dword ptr [esp + 0x185c]
// 006896ee  d984245c090000       fld dword ptr [esp + 0x95c]
// 006896f5  d8c9                 fmul st(1)
// 006896f7  d95c2404             fstp dword ptr [esp + 4]
// 006896fb  d88c241c0d0000       fmul dword ptr [esp + 0xd1c]
// 00689702  d91c24               fstp dword ptr [esp]
// 00689705  ffd2                 call edx
// 00689707  837f0800             cmp dword ptr [edi + 8], 0
// 0068970b  d98424d4100000       fld dword ptr [esp + 0x10d4]
// 00689712  0f85e5010000         jne 0x6898fd
// 00689718  8bac24f02e0000       mov ebp, dword ptr [esp + 0x2ef0]
// 0068971f  85ed                 test ebp, ebp
// 00689721  0f8d10010000         jge 0x689837
// 00689727  ddd8                 fstp st(0)
// 00689729  8b06                 mov eax, dword ptr [esi]
// 0068972b  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 00689731  8bce                 mov ecx, esi
// 00689733  ffd2                 call edx
// 00689735  6816b78000           push 0x80b716
// 0068973a  8d8c2464010000       lea ecx, [esp + 0x164]
// 00689741  ff1558248000         call dword ptr [0x802458]
// 00689747  8b06                 mov eax, dword ptr [esi]
// 00689749  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 0068974f  6a06                 push 6
// 00689751  8d8c2464010000       lea ecx, [esp + 0x164]
// 00689758  51                   push ecx
// 00689759  bd01000000           mov ebp, 1
// 0068975e  8bce                 mov ecx, esi
// 00689760  89ac24e02e0000       mov dword ptr [esp + 0x2ee0], ebp
// 00689767  ffd2                 call edx
// 00689769  8d8c2460010000       lea ecx, [esp + 0x160]
// 00689770  c78424d82e0000ffffffff mov dword ptr [esp + 0x2ed8], 0xffffffff
// 0068977b  ff1568248000         call dword ptr [0x802468]
// 00689781  d9ee                 fldz 
// 00689783  d85f10               fcomp dword ptr [edi + 0x10]
// 00689786  8d4f10               lea ecx, [edi + 0x10]
// 00689789  dfe0                 fnstsw ax
// 0068978b  f6c441               test ah, 0x41
// 0068978e  7a0d                 jp 0x68979d
// 00689790  8b06                 mov eax, dword ptr [esi]
// 00689792  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00689798  51                   push ecx
// 00689799  8bce                 mov ecx, esi
// 0068979b  ffd2                 call edx
// 0068979d  d94728               fld dword ptr [edi + 0x28]
// 006897a0  8b06                 mov eax, dword ptr [esi]
// 006897a2  d8a424ec2e0000       fsub dword ptr [esp + 0x2eec]
// 006897a9  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 006897af  83ec0c               sub esp, 0xc
// 006897b2  8bce                 mov ecx, esi
// 006897b4  d95c2408             fstp dword ptr [esp + 8]
// 006897b8  d94724               fld dword ptr [edi + 0x24]
// 006897bb  d95c2404             fstp dword ptr [esp + 4]
// 006897bf  d94720               fld dword ptr [edi + 0x20]
// 006897c2  d91c24               fstp dword ptr [esp]
// 006897c5  ffd2                 call edx
// 006897c7  8b06                 mov eax, dword ptr [esi]
// 006897c9  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 006897cf  6a00                 push 0
// 006897d1  8bce                 mov ecx, esi
// 006897d3  ffd2                 call edx
// 006897d5  837f0800             cmp dword ptr [edi + 8], 0
// 006897d9  0f8540030000         jne 0x689b1f
// 006897df  8b442420             mov eax, dword ptr [esp + 0x20]
// 006897e3  d940fc               fld dword ptr [eax - 4]
// 006897e6  8b8424f42e0000       mov eax, dword ptr [esp + 0x2ef4]
// 006897ed  8b0f                 mov ecx, dword ptr [edi]
// 006897ef  d9542428             fst dword ptr [esp + 0x28]
// 006897f3  83e900               sub ecx, 0
// 006897f6  d984840c1c0000       fld dword ptr [esp + eax*4 + 0x1c0c]
// 006897fd  d95c243c             fstp dword ptr [esp + 0x3c]
// 00689801  0f84d2010000         je 0x6899d9
// 00689807  2bcd                 sub ecx, ebp
// 00689809  0f8520020000         jne 0x689a2f
// 0068980f  d9848450270000       fld dword ptr [esp + eax*4 + 0x2750]
// 00689816  d95c2434             fstp dword ptr [esp + 0x34]
// 0068981a  d98484102b0000       fld dword ptr [esp + eax*4 + 0x2b10]
// 00689821  d95c242c             fstp dword ptr [esp + 0x2c]
// 00689825  e905020000           jmp 0x689a2f
// 0068982a  8d9b00000000         lea ebx, [ebx]
// 00689830  d98424d4100000       fld dword ptr [esp + 0x10d4]
// 00689837  d94728               fld dword ptr [edi + 0x28]
// 0068983a  8b06                 mov eax, dword ptr [esi]
// 0068983c  d88424141c0000       fadd dword ptr [esp + 0x1c14]
// 00689843  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 00689849  83ec0c               sub esp, 0xc
// 0068984c  8bce                 mov ecx, esi
// 0068984e  d95c2408             fstp dword ptr [esp + 8]
// 00689852  d984ac9c050000       fld dword ptr [esp + ebp*4 + 0x59c]
// 00689859  d8c9                 fmul st(1)
// 0068985b  d84724               fadd dword ptr [edi + 0x24]
// 0068985e  d95c2404             fstp dword ptr [esp + 4]
// 00689862  d88cacdc010000       fmul dword ptr [esp + ebp*4 + 0x1dc]
// 00689869  d84720               fadd dword ptr [edi + 0x20]
// 0068986c  d91c24               fstp dword ptr [esp]
// 0068986f  ffd2                 call edx
// 00689871  8b06                 mov eax, dword ptr [esi]
// 00689873  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00689879  53                   push ebx
// 0068987a  8bce                 mov ecx, esi
// 0068987c  ffd2                 call edx
// 0068987e  8b07                 mov eax, dword ptr [edi]
// 00689880  43                   inc ebx
// 00689881  83e800               sub eax, 0
// 00689884  7435                 je 0x6898bb
// 00689886  83e801               sub eax, 1
// 00689889  7564                 jne 0x6898ef
// 0068988b  3bac24f02e0000       cmp ebp, dword ptr [esp + 0x2ef0]
// 00689892  745b                 je 0x6898ef
// 00689894  d944242c             fld dword ptr [esp + 0x2c]
// 00689898  83ec0c               sub esp, 0xc
// 0068989b  d95c2408             fstp dword ptr [esp + 8]
// 0068989f  d984aca0230000       fld dword ptr [esp + ebp*4 + 0x23a0]
// 006898a6  d9442440             fld dword ptr [esp + 0x40]
// 006898aa  dcc9                 fmul st(1), st(0)
// 006898ac  d9c9                 fxch st(1)
// 006898ae  d95c2404             fstp dword ptr [esp + 4]
// 006898b2  d88cace01f0000       fmul dword ptr [esp + ebp*4 + 0x1fe0]
// 006898b9  eb25                 jmp 0x6898e0
// 006898bb  d944242c             fld dword ptr [esp + 0x2c]
// 006898bf  83ec0c               sub esp, 0xc
// 006898c2  d95c2408             fstp dword ptr [esp + 8]
// 006898c6  d984ac5c090000       fld dword ptr [esp + ebp*4 + 0x95c]
// 006898cd  d9442440             fld dword ptr [esp + 0x40]
// 006898d1  dcc9                 fmul st(1), st(0)
// 006898d3  d9c9                 fxch st(1)
// 006898d5  d95c2404             fstp dword ptr [esp + 4]
// 006898d9  d88cac1c0d0000       fmul dword ptr [esp + ebp*4 + 0xd1c]
// 006898e0  8b06                 mov eax, dword ptr [esi]
// 006898e2  d91c24               fstp dword ptr [esp]
// 006898e5  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 006898eb  8bce                 mov ecx, esi
// 006898ed  ffd2                 call edx
// 006898ef  83ed01               sub ebp, 1
// 006898f2  0f8938ffffff         jns 0x689830
// 006898f8  e92cfeffff           jmp 0x689729
// 006898fd  33ed                 xor ebp, ebp
// 006898ff  39ac24f02e0000       cmp dword ptr [esp + 0x2ef0], ebp
// 00689906  0f8c1bfeffff         jl 0x689727
// 0068990c  eb09                 jmp 0x689917
// 0068990e  8bff                 mov edi, edi
// 00689910  d98424d4100000       fld dword ptr [esp + 0x10d4]
// 00689917  d94728               fld dword ptr [edi + 0x28]
// 0068991a  8b06                 mov eax, dword ptr [esi]
// 0068991c  d88424141c0000       fadd dword ptr [esp + 0x1c14]
// 00689923  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 00689929  83ec0c               sub esp, 0xc
// 0068992c  8bce                 mov ecx, esi
// 0068992e  d95c2408             fstp dword ptr [esp + 8]
// 00689932  d984ac9c050000       fld dword ptr [esp + ebp*4 + 0x59c]
// 00689939  d8c9                 fmul st(1)
// 0068993b  d84724               fadd dword ptr [edi + 0x24]
// 0068993e  d95c2404             fstp dword ptr [esp + 4]
// 00689942  d88cacdc010000       fmul dword ptr [esp + ebp*4 + 0x1dc]
// 00689949  d84720               fadd dword ptr [edi + 0x20]
// 0068994c  d91c24               fstp dword ptr [esp]
// 0068994f  ffd2                 call edx
// 00689951  8b06                 mov eax, dword ptr [esi]
// 00689953  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00689959  53                   push ebx
// 0068995a  8bce                 mov ecx, esi
// 0068995c  ffd2                 call edx
// 0068995e  8b07                 mov eax, dword ptr [edi]
// 00689960  43                   inc ebx
// 00689961  83e800               sub eax, 0
// 00689964  742c                 je 0x689992
// 00689966  83e801               sub eax, 1
// 00689969  755b                 jne 0x6899c6
// 0068996b  d944242c             fld dword ptr [esp + 0x2c]
// 0068996f  83ec0c               sub esp, 0xc
// 00689972  d95c2408             fstp dword ptr [esp + 8]
// 00689976  d984ac9c230000       fld dword ptr [esp + ebp*4 + 0x239c]
// 0068997d  d9442440             fld dword ptr [esp + 0x40]
// 00689981  dcc9                 fmul st(1), st(0)
// 00689983  d9c9                 fxch st(1)
// 00689985  d95c2404             fstp dword ptr [esp + 4]
// 00689989  d88cacdc1f0000       fmul dword ptr [esp + ebp*4 + 0x1fdc]
// 00689990  eb25                 jmp 0x6899b7
// 00689992  d944242c             fld dword ptr [esp + 0x2c]
// 00689996  83ec0c               sub esp, 0xc
// 00689999  d95c2408             fstp dword ptr [esp + 8]
// 0068999d  d984ac5c090000       fld dword ptr [esp + ebp*4 + 0x95c]
// 006899a4  d9442440             fld dword ptr [esp + 0x40]
// 006899a8  dcc9                 fmul st(1), st(0)
// 006899aa  d9c9                 fxch st(1)
// 006899ac  d95c2404             fstp dword ptr [esp + 4]
// 006899b0  d88cac1c0d0000       fmul dword ptr [esp + ebp*4 + 0xd1c]
// 006899b7  8b06                 mov eax, dword ptr [esi]
// 006899b9  d91c24               fstp dword ptr [esp]
// 006899bc  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 006899c2  8bce                 mov ecx, esi
// 006899c4  ffd2                 call edx
// 006899c6  45                   inc ebp
// 006899c7  3bac24f02e0000       cmp ebp, dword ptr [esp + 0x2ef0]
// 006899ce  0f8e3cffffff         jle 0x689910
// 006899d4  e950fdffff           jmp 0x689729
// 006899d9  8b16                 mov edx, dword ptr [esi]
// 006899db  ddd8                 fstp st(0)
// 006899dd  d984844c180000       fld dword ptr [esp + eax*4 + 0x184c]
// 006899e4  8d8c8450180000       lea ecx, [esp + eax*4 + 0x1850]
// 006899eb  d95c2434             fstp dword ptr [esp + 0x34]
// 006899ef  83ec0c               sub esp, 0xc
// 006899f2  d9848498140000       fld dword ptr [esp + eax*4 + 0x1498]
// 006899f9  d95c2438             fstp dword ptr [esp + 0x38]
// 006899fd  d984849c140000       fld dword ptr [esp + eax*4 + 0x149c]
// 00689a04  d95c2408             fstp dword ptr [esp + 8]
// 00689a08  d984845c090000       fld dword ptr [esp + eax*4 + 0x95c]
// 00689a0f  d809                 fmul dword ptr [ecx]
// 00689a11  d95c2404             fstp dword ptr [esp + 4]
// 00689a15  d984841c0d0000       fld dword ptr [esp + eax*4 + 0xd1c]
// 00689a1c  8b82f8000000         mov eax, dword ptr [edx + 0xf8]
// 00689a22  d809                 fmul dword ptr [ecx]
// 00689a24  8bce                 mov ecx, esi
// 00689a26  d91c24               fstp dword ptr [esp]
// 00689a29  ffd0                 call eax
// 00689a2b  d9442428             fld dword ptr [esp + 0x28]
// 00689a2f  33db                 xor ebx, ebx
// 00689a31  399c24f02e0000       cmp dword ptr [esp + 0x2ef0], ebx
// 00689a38  7d1a                 jge 0x689a54
// 00689a3a  ddd8                 fstp st(0)
// 00689a3c  8b16                 mov edx, dword ptr [esi]
// 00689a3e  8b8228010000         mov eax, dword ptr [edx + 0x128]
// 00689a44  8bce                 mov ecx, esi
// 00689a46  ffd0                 call eax
// 00689a48  e9c9010000           jmp 0x689c16
// 00689a4d  8d4900               lea ecx, [ecx]
// 00689a50  d9442428             fld dword ptr [esp + 0x28]
// 00689a54  d94728               fld dword ptr [edi + 0x28]
// 00689a57  8b16                 mov edx, dword ptr [esi]
// 00689a59  d844243c             fadd dword ptr [esp + 0x3c]
// 00689a5d  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00689a63  83ec0c               sub esp, 0xc
// 00689a66  8bce                 mov ecx, esi
// 00689a68  d95c2408             fstp dword ptr [esp + 8]
// 00689a6c  d9849c9c050000       fld dword ptr [esp + ebx*4 + 0x59c]
// 00689a73  d8c9                 fmul st(1)
// 00689a75  d84724               fadd dword ptr [edi + 0x24]
// 00689a78  d95c2404             fstp dword ptr [esp + 4]
// 00689a7c  d88c9cdc010000       fmul dword ptr [esp + ebx*4 + 0x1dc]
// 00689a83  d84720               fadd dword ptr [edi + 0x20]
// 00689a86  d91c24               fstp dword ptr [esp]
// 00689a89  ffd0                 call eax
// 00689a8b  8b16                 mov edx, dword ptr [esi]
// 00689a8d  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00689a93  55                   push ebp
// 00689a94  8bce                 mov ecx, esi
// 00689a96  ffd0                 call eax
// 00689a98  8b07                 mov eax, dword ptr [edi]
// 00689a9a  45                   inc ebp
// 00689a9b  83e800               sub eax, 0
// 00689a9e  742c                 je 0x689acc
// 00689aa0  83e801               sub eax, 1
// 00689aa3  755b                 jne 0x689b00
// 00689aa5  d944242c             fld dword ptr [esp + 0x2c]
// 00689aa9  83ec0c               sub esp, 0xc
// 00689aac  d95c2408             fstp dword ptr [esp + 8]
// 00689ab0  d9849c9c230000       fld dword ptr [esp + ebx*4 + 0x239c]
// 00689ab7  d9442440             fld dword ptr [esp + 0x40]
// 00689abb  dcc9                 fmul st(1), st(0)
// 00689abd  d9c9                 fxch st(1)
// 00689abf  d95c2404             fstp dword ptr [esp + 4]
// 00689ac3  d88c9cdc1f0000       fmul dword ptr [esp + ebx*4 + 0x1fdc]
// 00689aca  eb25                 jmp 0x689af1
// 00689acc  d944242c             fld dword ptr [esp + 0x2c]
// 00689ad0  83ec0c               sub esp, 0xc
// 00689ad3  d95c2408             fstp dword ptr [esp + 8]
// 00689ad7  d9849c5c090000       fld dword ptr [esp + ebx*4 + 0x95c]
// 00689ade  d9442440             fld dword ptr [esp + 0x40]
// 00689ae2  dcc9                 fmul st(1), st(0)
// 00689ae4  d9c9                 fxch st(1)
// 00689ae6  d95c2404             fstp dword ptr [esp + 4]
// 00689aea  d88c9c1c0d0000       fmul dword ptr [esp + ebx*4 + 0xd1c]
// 00689af1  8b16                 mov edx, dword ptr [esi]
// 00689af3  d91c24               fstp dword ptr [esp]
// 00689af6  8b82f8000000         mov eax, dword ptr [edx + 0xf8]
// 00689afc  8bce                 mov ecx, esi
// 00689afe  ffd0                 call eax
// 00689b00  43                   inc ebx
// 00689b01  3b9c24f02e0000       cmp ebx, dword ptr [esp + 0x2ef0]
// 00689b08  0f8e42ffffff         jle 0x689a50
// 00689b0e  8b16                 mov edx, dword ptr [esi]
// 00689b10  8b8228010000         mov eax, dword ptr [edx + 0x128]
// 00689b16  8bce                 mov ecx, esi
// 00689b18  ffd0                 call eax
// 00689b1a  e9f7000000           jmp 0x689c16
// 00689b1f  8b9c24f02e0000       mov ebx, dword ptr [esp + 0x2ef0]
// 00689b26  85db                 test ebx, ebx
// 00689b28  0f8c0effffff         jl 0x689a3c
// 00689b2e  8bff                 mov edi, edi
// 00689b30  d94728               fld dword ptr [edi + 0x28]
// 00689b33  8b16                 mov edx, dword ptr [esi]
// 00689b35  d88424141c0000       fadd dword ptr [esp + 0x1c14]
// 00689b3c  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00689b42  83ec0c               sub esp, 0xc
// 00689b45  8bce                 mov ecx, esi
// 00689b47  d95c2408             fstp dword ptr [esp + 8]
// 00689b4b  d9849c9c050000       fld dword ptr [esp + ebx*4 + 0x59c]
// 00689b52  d98424e0100000       fld dword ptr [esp + 0x10e0]
// 00689b59  dcc9                 fmul st(1), st(0)
// 00689b5b  d9c9                 fxch st(1)
// 00689b5d  d84724               fadd dword ptr [edi + 0x24]
// 00689b60  d95c2404             fstp dword ptr [esp + 4]
// 00689b64  d88c9cdc010000       fmul dword ptr [esp + ebx*4 + 0x1dc]
// 00689b6b  d84720               fadd dword ptr [edi + 0x20]
// 00689b6e  d91c24               fstp dword ptr [esp]
// 00689b71  ffd0                 call eax
// 00689b73  8b16                 mov edx, dword ptr [esi]
// 00689b75  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00689b7b  55                   push ebp
// 00689b7c  8bce                 mov ecx, esi
// 00689b7e  ffd0                 call eax
// 00689b80  8b07                 mov eax, dword ptr [edi]
// 00689b82  45                   inc ebp
// 00689b83  83e800               sub eax, 0
// 00689b86  7435                 je 0x689bbd
// 00689b88  83e801               sub eax, 1
// 00689b8b  7564                 jne 0x689bf1
// 00689b8d  3b9c24f02e0000       cmp ebx, dword ptr [esp + 0x2ef0]
// 00689b94  745b                 je 0x689bf1
// 00689b96  d944242c             fld dword ptr [esp + 0x2c]
// 00689b9a  83ec0c               sub esp, 0xc
// 00689b9d  d95c2408             fstp dword ptr [esp + 8]
// 00689ba1  d9849ca0230000       fld dword ptr [esp + ebx*4 + 0x23a0]
// 00689ba8  d9442440             fld dword ptr [esp + 0x40]
// 00689bac  dcc9                 fmul st(1), st(0)
// 00689bae  d9c9                 fxch st(1)
// 00689bb0  d95c2404             fstp dword ptr [esp + 4]
// 00689bb4  d88c9ce01f0000       fmul dword ptr [esp + ebx*4 + 0x1fe0]
// 00689bbb  eb25                 jmp 0x689be2
// 00689bbd  d944242c             fld dword ptr [esp + 0x2c]
// 00689bc1  83ec0c               sub esp, 0xc
// 00689bc4  d95c2408             fstp dword ptr [esp + 8]
// 00689bc8  d9849c5c090000       fld dword ptr [esp + ebx*4 + 0x95c]
// 00689bcf  d9442440             fld dword ptr [esp + 0x40]
// 00689bd3  dcc9                 fmul st(1), st(0)
// 00689bd5  d9c9                 fxch st(1)
// 00689bd7  d95c2404             fstp dword ptr [esp + 4]
// 00689bdb  d88c9c1c0d0000       fmul dword ptr [esp + ebx*4 + 0xd1c]
// 00689be2  8b16                 mov edx, dword ptr [esi]
// 00689be4  d91c24               fstp dword ptr [esp]
// 00689be7  8b82f8000000         mov eax, dword ptr [edx + 0xf8]
// 00689bed  8bce                 mov ecx, esi
// 00689bef  ffd0                 call eax
// 00689bf1  83eb01               sub ebx, 1
// 00689bf4  0f8936ffffff         jns 0x689b30
// 00689bfa  8b16                 mov edx, dword ptr [esi]
// 00689bfc  8b8228010000         mov eax, dword ptr [edx + 0x128]
// 00689c02  8bce                 mov ecx, esi
// 00689c04  ffd0                 call eax
// 00689c06  eb0e                 jmp 0x689c16
// 00689c08  89ac2494000000       mov dword ptr [esp + 0x94], ebp
// 00689c0f  89942490000000       mov dword ptr [esp + 0x90], edx
// 00689c16  8b9c2494000000       mov ebx, dword ptr [esp + 0x94]
// 00689c1d  3b9c2490000000       cmp ebx, dword ptr [esp + 0x90]
// 00689c24  895c2410             mov dword ptr [esp + 0x10], ebx
// 00689c28  0f8d59190000         jge 0x68b587
// 00689c2e  8bff                 mov edi, edi
// 00689c30  d9849c101c0000       fld dword ptr [esp + ebx*4 + 0x1c10]
// 00689c37  8b07                 mov eax, dword ptr [edi]
// 00689c39  83e800               sub eax, 0
// 00689c3c  d95c2424             fstp dword ptr [esp + 0x24]
// 00689c40  d9849c141c0000       fld dword ptr [esp + ebx*4 + 0x1c14]
// 00689c47  d95c243c             fstp dword ptr [esp + 0x3c]
// 00689c4b  d9849cd0100000       fld dword ptr [esp + ebx*4 + 0x10d0]
// 00689c52  d95c2440             fstp dword ptr [esp + 0x40]
// 00689c56  d9849cd4100000       fld dword ptr [esp + ebx*4 + 0x10d4]
// 00689c5d  d95c2428             fstp dword ptr [esp + 0x28]
// 00689c61  7420                 je 0x689c83
// 00689c63  83e801               sub eax, 1
// 00689c66  0f8579000000         jne 0x689ce5
// 00689c6c  d9849c54270000       fld dword ptr [esp + ebx*4 + 0x2754]
// 00689c73  d99c248c000000       fstp dword ptr [esp + 0x8c]
// 00689c7a  d9849c142b0000       fld dword ptr [esp + ebx*4 + 0x2b14]
// 00689c81  eb5e                 jmp 0x689ce1
// 00689c83  837f0800             cmp dword ptr [edi + 8], 0
// 00689c87  752d                 jne 0x689cb6
// 00689c89  d9849c54180000       fld dword ptr [esp + ebx*4 + 0x1854]
// 00689c90  d95c2434             fstp dword ptr [esp + 0x34]
// 00689c94  d9849c94140000       fld dword ptr [esp + ebx*4 + 0x1494]
// 00689c9b  d95c242c             fstp dword ptr [esp + 0x2c]
// 00689c9f  d9849c50180000       fld dword ptr [esp + ebx*4 + 0x1850]
// 00689ca6  d99c248c000000       fstp dword ptr [esp + 0x8c]
// 00689cad  d9849c90140000       fld dword ptr [esp + ebx*4 + 0x1490]
// 00689cb4  eb2b                 jmp 0x689ce1
// 00689cb6  d9849c50180000       fld dword ptr [esp + ebx*4 + 0x1850]
// 00689cbd  d95c2434             fstp dword ptr [esp + 0x34]
// 00689cc1  d9849c90140000       fld dword ptr [esp + ebx*4 + 0x1490]
// 00689cc8  d95c242c             fstp dword ptr [esp + 0x2c]
// 00689ccc  d9849c54180000       fld dword ptr [esp + ebx*4 + 0x1854]
// 00689cd3  d99c248c000000       fstp dword ptr [esp + 0x8c]
// 00689cda  d9849c94140000       fld dword ptr [esp + ebx*4 + 0x1494]
// 00689ce1  d95c2448             fstp dword ptr [esp + 0x48]
// 00689ce5  6a04                 push 4
// 00689ce7  e8346c0100           call 0x6a0920
// 00689cec  83c404               add esp, 4
// 00689cef  85c0                 test eax, eax
// 00689cf1  7408                 je 0x689cfb
// 00689cf3  8d4c2468             lea ecx, [esp + 0x68]
// 00689cf7  8908                 mov dword ptr [eax], ecx
// 00689cf9  eb02                 jmp 0x689cfd
// 00689cfb  33c0                 xor eax, eax
// 00689cfd  89442468             mov dword ptr [esp + 0x68], eax
// 00689d01  33c0                 xor eax, eax
// 00689d03  89442474             mov dword ptr [esp + 0x74], eax
// 00689d07  89442478             mov dword ptr [esp + 0x78], eax
// 00689d0b  8944247c             mov dword ptr [esp + 0x7c], eax
// 00689d0f  6a04                 push 4
// 00689d11  c78424dc2e000003000000 mov dword ptr [esp + 0x2edc], 3
// 00689d1c  e8ff6b0100           call 0x6a0920
// 00689d21  83c404               add esp, 4
// 00689d24  85c0                 test eax, eax
// 00689d26  7408                 je 0x689d30
// 00689d28  8d542450             lea edx, [esp + 0x50]
// 00689d2c  8910                 mov dword ptr [eax], edx
// 00689d2e  eb02                 jmp 0x689d32
// 00689d30  33c0                 xor eax, eax
// 00689d32  89442450             mov dword ptr [esp + 0x50], eax
// 00689d36  33c0                 xor eax, eax
// 00689d38  8944245c             mov dword ptr [esp + 0x5c], eax
// 00689d3c  89442460             mov dword ptr [esp + 0x60], eax
// 00689d40  89442464             mov dword ptr [esp + 0x64], eax
// 00689d44  c68424d82e000005     mov byte ptr [esp + 0x2ed8], 5
// 00689d4c  3b9c2494000000       cmp ebx, dword ptr [esp + 0x94]
// 00689d53  7547                 jne 0x689d9c
// 00689d55  6816b78000           push 0x80b716
// 00689d5a  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 00689d61  ff1558248000         call dword ptr [0x802458]
// 00689d67  8b06                 mov eax, dword ptr [esi]
// 00689d69  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00689d6f  6a04                 push 4
// 00689d71  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 00689d78  51                   push ecx
// 00689d79  8bce                 mov ecx, esi
// 00689d7b  c68424e02e000006     mov byte ptr [esp + 0x2ee0], 6
// 00689d83  ffd2                 call edx
// 00689d85  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 00689d8c  c68424d82e000005     mov byte ptr [esp + 0x2ed8], 5
// 00689d94  ff1568248000         call dword ptr [0x802468]
// 00689d9a  33ed                 xor ebp, ebp
// 00689d9c  d9ee                 fldz 
// 00689d9e  8d4f10               lea ecx, [edi + 0x10]
// 00689da1  d819                 fcomp dword ptr [ecx]
// 00689da3  dfe0                 fnstsw ax
// 00689da5  f6c441               test ah, 0x41
// 00689da8  7a0d                 jp 0x689db7
// 00689daa  8b06                 mov eax, dword ptr [esi]
// 00689dac  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00689db2  51                   push ecx
// 00689db3  8bce                 mov ecx, esi
// 00689db5  ffd2                 call edx
// 00689db7  33c0                 xor eax, eax
// 00689db9  398424f02e0000       cmp dword ptr [esp + 0x2ef0], eax
// 00689dc0  89442414             mov dword ptr [esp + 0x14], eax
// 00689dc4  0f8c7f110000         jl 0x68af49
// 00689dca  8d9b00000000         lea ebx, [ebx]
// 00689dd0  833f00               cmp dword ptr [edi], 0
// 00689dd3  752f                 jne 0x689e04
// 00689dd5  d98484100d0000       fld dword ptr [esp + eax*4 + 0xd10]
// 00689ddc  d9442434             fld dword ptr [esp + 0x34]
// 00689de0  dcc9                 fmul st(1), st(0)
// 00689de2  d88c8450090000       fmul dword ptr [esp + eax*4 + 0x950]
// 00689de9  d9c9                 fxch st(1)
// 00689deb  d99c2480000000       fstp dword ptr [esp + 0x80]
// 00689df2  d99c2484000000       fstp dword ptr [esp + 0x84]
// 00689df9  d944242c             fld dword ptr [esp + 0x2c]
// 00689dfd  d99c2488000000       fstp dword ptr [esp + 0x88]
// 00689e04  837f0800             cmp dword ptr [edi + 8], 0
// 00689e08  0f8542040000         jne 0x68a250
// 00689e0e  807f0400             cmp byte ptr [edi + 4], 0
// 00689e12  743d                 je 0x689e51
// 00689e14  8d4b01               lea ecx, [ebx + 1]
// 00689e17  894c2420             mov dword ptr [esp + 0x20], ecx
// 00689e1b  db442420             fild dword ptr [esp + 0x20]
// 00689e1f  83ec08               sub esp, 8
// 00689e22  8b06                 mov eax, dword ptr [esi]
// 00689e24  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 00689e2a  dab424fc2e0000       fidiv dword ptr [esp + 0x2efc]
// 00689e31  8bce                 mov ecx, esi
// 00689e33  d9e8                 fld1 
// 00689e35  d9c0                 fld st(0)
// 00689e37  dee2                 fsubrp st(2)
// 00689e39  d9c9                 fxch st(1)
// 00689e3b  d95c2404             fstp dword ptr [esp + 4]
// 00689e3f  db44241c             fild dword ptr [esp + 0x1c]
// 00689e43  dab424f82e0000       fidiv dword ptr [esp + 0x2ef8]
// 00689e4a  dee9                 fsubp st(1)
// 00689e4c  d91c24               fstp dword ptr [esp]
// 00689e4f  ffd2                 call edx
// 00689e51  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 00689e55  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 00689e59  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00689e5e  f7e9                 imul ecx
// 00689e60  d1fa                 sar edx, 1
// 00689e62  8bc2                 mov eax, edx
// 00689e64  c1e81f               shr eax, 0x1f
// 00689e67  03c2                 add eax, edx
// 00689e69  89442418             mov dword ptr [esp + 0x18], eax
// 00689e6d  83f802               cmp eax, 2
// 00689e70  0f827b030000         jb 0x68a1f1
// 00689e76  8bc8                 mov ecx, eax
// 00689e78  81e101000080         and ecx, 0x80000001
// 00689e7e  7905                 jns 0x689e85
// 00689e80  49                   dec ecx
// 00689e81  83c9fe               or ecx, 0xfffffffe
// 00689e84  41                   inc ecx
// 00689e85  0f84b4010000         je 0x68a03f
// 00689e8b  8d58ff               lea ebx, [eax - 1]
// 00689e8e  3bd8                 cmp ebx, eax
// 00689e90  7206                 jb 0x689e98
// 00689e92  ff1590288000         call dword ptr [0x802890]
// 00689e98  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 00689e9c  8b16                 mov edx, dword ptr [esi]
// 00689e9e  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 00689ea4  8d045b               lea eax, [ebx + ebx*2]
// 00689ea7  8d0481               lea eax, [ecx + eax*4]
// 00689eaa  50                   push eax
// 00689eab  8bce                 mov ecx, esi
// 00689ead  ffd2                 call edx
// 00689eaf  8b06                 mov eax, dword ptr [esi]
// 00689eb1  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00689eb7  55                   push ebp
// 00689eb8  8bce                 mov ecx, esi
// 00689eba  ffd2                 call edx
// 00689ebc  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00689ec0  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 00689ec4  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00689ec9  f7e9                 imul ecx
// 00689ecb  d1fa                 sar edx, 1
// 00689ecd  8bc2                 mov eax, edx
// 00689ecf  c1e81f               shr eax, 0x1f
// 00689ed2  03c2                 add eax, edx
// 00689ed4  45                   inc ebp
// 00689ed5  3bd8                 cmp ebx, eax
// 00689ed7  7206                 jb 0x689edf
// 00689ed9  ff1590288000         call dword ptr [0x802890]
// 00689edf  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00689ee3  8b16                 mov edx, dword ptr [esi]
// 00689ee5  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 00689eeb  8d045b               lea eax, [ebx + ebx*2]
// 00689eee  8d0481               lea eax, [ecx + eax*4]
// 00689ef1  50                   push eax
// 00689ef2  8bce                 mov ecx, esi
// 00689ef4  ffd2                 call edx
// 00689ef6  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 00689efa  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 00689efe  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00689f02  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00689f07  f7e9                 imul ecx
// 00689f09  d1fa                 sar edx, 1
// 00689f0b  8bc2                 mov eax, edx
// 00689f0d  c1e81f               shr eax, 0x1f
// 00689f10  83c3fe               add ebx, -2
// 00689f13  03c2                 add eax, edx
// 00689f15  3bd8                 cmp ebx, eax
// 00689f17  7206                 jb 0x689f1f
// 00689f19  ff1590288000         call dword ptr [0x802890]
// 00689f1f  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 00689f23  8b16                 mov edx, dword ptr [esi]
// 00689f25  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 00689f2b  8d045b               lea eax, [ebx + ebx*2]
// 00689f2e  8d0481               lea eax, [ecx + eax*4]
// 00689f31  50                   push eax
// 00689f32  8bce                 mov ecx, esi
// 00689f34  ffd2                 call edx
// 00689f36  8b06                 mov eax, dword ptr [esi]
// 00689f38  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00689f3e  55                   push ebp
// 00689f3f  8bce                 mov ecx, esi
// 00689f41  ffd2                 call edx
// 00689f43  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00689f47  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 00689f4b  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00689f50  f7e9                 imul ecx
// 00689f52  d1fa                 sar edx, 1
// 00689f54  8bc2                 mov eax, edx
// 00689f56  c1e81f               shr eax, 0x1f
// 00689f59  03c2                 add eax, edx
// 00689f5b  45                   inc ebp
// 00689f5c  3bd8                 cmp ebx, eax
// 00689f5e  7206                 jb 0x689f66
// 00689f60  ff1590288000         call dword ptr [0x802890]
// 00689f66  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00689f6a  8b16                 mov edx, dword ptr [esi]
// 00689f6c  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 00689f72  8d045b               lea eax, [ebx + ebx*2]
// 00689f75  8d0481               lea eax, [ecx + eax*4]
// 00689f78  50                   push eax
// 00689f79  8bce                 mov ecx, esi
// 00689f7b  ffd2                 call edx
// 00689f7d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00689f81  03c9                 add ecx, ecx
// 00689f83  03c9                 add ecx, ecx
// 00689f85  d9840c90050000       fld dword ptr [esp + ecx + 0x590]
// 00689f8c  8d840c90050000       lea eax, [esp + ecx + 0x590]
// 00689f93  d9442428             fld dword ptr [esp + 0x28]
// 00689f97  8944244c             mov dword ptr [esp + 0x4c], eax
// 00689f9b  dcc9                 fmul st(1), st(0)
// 00689f9d  8d840cd0010000       lea eax, [esp + ecx + 0x1d0]
// 00689fa4  d9c9                 fxch st(1)
// 00689fa6  83ec0c               sub esp, 0xc
// 00689fa9  89442450             mov dword ptr [esp + 0x50], eax
// 00689fad  d9542444             fst dword ptr [esp + 0x44]
// 00689fb1  894c2424             mov dword ptr [esp + 0x24], ecx
// 00689fb5  d900                 fld dword ptr [eax]
// 00689fb7  8b06                 mov eax, dword ptr [esi]
// 00689fb9  deca                 fmulp st(2)
// 00689fbb  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 00689fc1  d9c9                 fxch st(1)
// 00689fc3  8bce                 mov ecx, esi
// 00689fc5  d954242c             fst dword ptr [esp + 0x2c]
// 00689fc9  d94728               fld dword ptr [edi + 0x28]
// 00689fcc  d8442448             fadd dword ptr [esp + 0x48]
// 00689fd0  d95c2408             fstp dword ptr [esp + 8]
// 00689fd4  d9c9                 fxch st(1)
// 00689fd6  d84724               fadd dword ptr [edi + 0x24]
// 00689fd9  d95c2404             fstp dword ptr [esp + 4]
// 00689fdd  d84720               fadd dword ptr [edi + 0x20]
// 00689fe0  d91c24               fstp dword ptr [esp]
// 00689fe3  ffd2                 call edx
// 00689fe5  8b06                 mov eax, dword ptr [esi]
// 00689fe7  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00689fed  55                   push ebp
// 00689fee  8bce                 mov ecx, esi
// 00689ff0  ffd2                 call edx
// 00689ff2  8b06                 mov eax, dword ptr [esi]
// 00689ff4  8b90fc000000         mov edx, dword ptr [eax + 0xfc]
// 00689ffa  8d8c2480000000       lea ecx, [esp + 0x80]
// 0068a001  51                   push ecx
// 0068a002  8bce                 mov ecx, esi
// 0068a004  45                   inc ebp
// 0068a005  ffd2                 call edx
// 0068a007  d9442420             fld dword ptr [esp + 0x20]
// 0068a00b  d84720               fadd dword ptr [edi + 0x20]
// 0068a00e  8d8424c8000000       lea eax, [esp + 0xc8]
// 0068a015  d9442438             fld dword ptr [esp + 0x38]
// 0068a019  d84724               fadd dword ptr [edi + 0x24]
// 0068a01c  d94728               fld dword ptr [edi + 0x28]
// 0068a01f  d844243c             fadd dword ptr [esp + 0x3c]
// 0068a023  d9ca                 fxch st(2)
// 0068a025  d99c24c8000000       fstp dword ptr [esp + 0xc8]
// 0068a02c  d99c24cc000000       fstp dword ptr [esp + 0xcc]
// 0068a033  d99c24d0000000       fstp dword ptr [esp + 0xd0]
// 0068a03a  e9e8050000           jmp 0x68a627
// 0068a03f  8d58fe               lea ebx, [eax - 2]
// 0068a042  3bd8                 cmp ebx, eax
// 0068a044  7206                 jb 0x68a04c
// 0068a046  ff1590288000         call dword ptr [0x802890]
// 0068a04c  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068a050  8b16                 mov edx, dword ptr [esi]
// 0068a052  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068a058  8d045b               lea eax, [ebx + ebx*2]
// 0068a05b  8d0481               lea eax, [ecx + eax*4]
// 0068a05e  50                   push eax
// 0068a05f  8bce                 mov ecx, esi
// 0068a061  ffd2                 call edx
// 0068a063  8b06                 mov eax, dword ptr [esi]
// 0068a065  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a06b  55                   push ebp
// 0068a06c  8bce                 mov ecx, esi
// 0068a06e  ffd2                 call edx
// 0068a070  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068a074  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068a078  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a07d  f7e9                 imul ecx
// 0068a07f  d1fa                 sar edx, 1
// 0068a081  8bc2                 mov eax, edx
// 0068a083  c1e81f               shr eax, 0x1f
// 0068a086  03c2                 add eax, edx
// 0068a088  45                   inc ebp
// 0068a089  3bd8                 cmp ebx, eax
// 0068a08b  7206                 jb 0x68a093
// 0068a08d  ff1590288000         call dword ptr [0x802890]
// 0068a093  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068a097  8b16                 mov edx, dword ptr [esi]
// 0068a099  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068a09f  8d045b               lea eax, [ebx + ebx*2]
// 0068a0a2  8d0481               lea eax, [ecx + eax*4]
// 0068a0a5  50                   push eax
// 0068a0a6  8bce                 mov ecx, esi
// 0068a0a8  ffd2                 call edx
// 0068a0aa  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0068a0ae  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 0068a0b2  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0068a0b6  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a0bb  f7e9                 imul ecx
// 0068a0bd  d1fa                 sar edx, 1
// 0068a0bf  8bc2                 mov eax, edx
// 0068a0c1  c1e81f               shr eax, 0x1f
// 0068a0c4  4b                   dec ebx
// 0068a0c5  03c2                 add eax, edx
// 0068a0c7  3bd8                 cmp ebx, eax
// 0068a0c9  7206                 jb 0x68a0d1
// 0068a0cb  ff1590288000         call dword ptr [0x802890]
// 0068a0d1  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068a0d5  8b16                 mov edx, dword ptr [esi]
// 0068a0d7  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068a0dd  8d045b               lea eax, [ebx + ebx*2]
// 0068a0e0  8d0481               lea eax, [ecx + eax*4]
// 0068a0e3  50                   push eax
// 0068a0e4  8bce                 mov ecx, esi
// 0068a0e6  ffd2                 call edx
// 0068a0e8  8b06                 mov eax, dword ptr [esi]
// 0068a0ea  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a0f0  55                   push ebp
// 0068a0f1  8bce                 mov ecx, esi
// 0068a0f3  ffd2                 call edx
// 0068a0f5  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068a0f9  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068a0fd  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a102  f7e9                 imul ecx
// 0068a104  d1fa                 sar edx, 1
// 0068a106  8bc2                 mov eax, edx
// 0068a108  c1e81f               shr eax, 0x1f
// 0068a10b  03c2                 add eax, edx
// 0068a10d  45                   inc ebp
// 0068a10e  3bd8                 cmp ebx, eax
// 0068a110  7206                 jb 0x68a118
// 0068a112  ff1590288000         call dword ptr [0x802890]
// 0068a118  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068a11c  8b16                 mov edx, dword ptr [esi]
// 0068a11e  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068a124  8d045b               lea eax, [ebx + ebx*2]
// 0068a127  8d0481               lea eax, [ecx + eax*4]
// 0068a12a  50                   push eax
// 0068a12b  8bce                 mov ecx, esi
// 0068a12d  ffd2                 call edx
// 0068a12f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0068a133  03c9                 add ecx, ecx
// 0068a135  03c9                 add ecx, ecx
// 0068a137  d9840c90050000       fld dword ptr [esp + ecx + 0x590]
// 0068a13e  8d840c90050000       lea eax, [esp + ecx + 0x590]
// 0068a145  d9442428             fld dword ptr [esp + 0x28]
// 0068a149  8944244c             mov dword ptr [esp + 0x4c], eax
// 0068a14d  dcc9                 fmul st(1), st(0)
// 0068a14f  8d840cd0010000       lea eax, [esp + ecx + 0x1d0]
// 0068a156  d9c9                 fxch st(1)
// 0068a158  83ec0c               sub esp, 0xc
// 0068a15b  89442450             mov dword ptr [esp + 0x50], eax
// 0068a15f  d9542444             fst dword ptr [esp + 0x44]
// 0068a163  894c2424             mov dword ptr [esp + 0x24], ecx
// 0068a167  d900                 fld dword ptr [eax]
// 0068a169  8b06                 mov eax, dword ptr [esi]
// 0068a16b  deca                 fmulp st(2)
// 0068a16d  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 0068a173  d9c9                 fxch st(1)
// 0068a175  8bce                 mov ecx, esi
// 0068a177  d954242c             fst dword ptr [esp + 0x2c]
// 0068a17b  d94728               fld dword ptr [edi + 0x28]
// 0068a17e  d8442448             fadd dword ptr [esp + 0x48]
// 0068a182  d95c2408             fstp dword ptr [esp + 8]
// 0068a186  d9c9                 fxch st(1)
// 0068a188  d84724               fadd dword ptr [edi + 0x24]
// 0068a18b  d95c2404             fstp dword ptr [esp + 4]
// 0068a18f  d84720               fadd dword ptr [edi + 0x20]
// 0068a192  d91c24               fstp dword ptr [esp]
// 0068a195  ffd2                 call edx
// 0068a197  8b06                 mov eax, dword ptr [esi]
// 0068a199  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a19f  55                   push ebp
// 0068a1a0  8bce                 mov ecx, esi
// 0068a1a2  ffd2                 call edx
// 0068a1a4  8b06                 mov eax, dword ptr [esi]
// 0068a1a6  8b90fc000000         mov edx, dword ptr [eax + 0xfc]
// 0068a1ac  8d8c2480000000       lea ecx, [esp + 0x80]
// 0068a1b3  51                   push ecx
// 0068a1b4  8bce                 mov ecx, esi
// 0068a1b6  45                   inc ebp
// 0068a1b7  ffd2                 call edx
// 0068a1b9  d9442420             fld dword ptr [esp + 0x20]
// 0068a1bd  d84720               fadd dword ptr [edi + 0x20]
// 0068a1c0  8d842404010000       lea eax, [esp + 0x104]
// 0068a1c7  d9442438             fld dword ptr [esp + 0x38]
// 0068a1cb  d84724               fadd dword ptr [edi + 0x24]
// 0068a1ce  d94728               fld dword ptr [edi + 0x28]
// 0068a1d1  d844243c             fadd dword ptr [esp + 0x3c]
// 0068a1d5  d9ca                 fxch st(2)
// 0068a1d7  d99c2404010000       fstp dword ptr [esp + 0x104]
// 0068a1de  d99c2408010000       fstp dword ptr [esp + 0x108]
// 0068a1e5  d99c240c010000       fstp dword ptr [esp + 0x10c]
// 0068a1ec  e936040000           jmp 0x68a627
// 0068a1f1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0068a1f5  03c0                 add eax, eax
// 0068a1f7  03c0                 add eax, eax
// 0068a1f9  d98404d0010000       fld dword ptr [esp + eax + 0x1d0]
// 0068a200  8d8c04d0010000       lea ecx, [esp + eax + 0x1d0]
// 0068a207  d9442428             fld dword ptr [esp + 0x28]
// 0068a20b  89442418             mov dword ptr [esp + 0x18], eax
// 0068a20f  dcc9                 fmul st(1), st(0)
// 0068a211  8d840490050000       lea eax, [esp + eax + 0x590]
// 0068a218  d9c9                 fxch st(1)
// 0068a21a  8d94241c010000       lea edx, [esp + 0x11c]
// 0068a221  d84720               fadd dword ptr [edi + 0x20]
// 0068a224  d900                 fld dword ptr [eax]
// 0068a226  deca                 fmulp st(2)
// 0068a228  d9c9                 fxch st(1)
// 0068a22a  d84724               fadd dword ptr [edi + 0x24]
// 0068a22d  d94728               fld dword ptr [edi + 0x28]
// 0068a230  d844243c             fadd dword ptr [esp + 0x3c]
// 0068a234  d9ca                 fxch st(2)
// 0068a236  d99c241c010000       fstp dword ptr [esp + 0x11c]
// 0068a23d  d99c2420010000       fstp dword ptr [esp + 0x120]
// 0068a244  d99c2424010000       fstp dword ptr [esp + 0x124]
// 0068a24b  e952040000           jmp 0x68a6a2
// 0068a250  807f0400             cmp byte ptr [edi + 4], 0
// 0068a254  7436                 je 0x68a28c
// 0068a256  db442410             fild dword ptr [esp + 0x10]
// 0068a25a  83ec08               sub esp, 8
// 0068a25d  8b16                 mov edx, dword ptr [esi]
// 0068a25f  8b820c010000         mov eax, dword ptr [edx + 0x10c]
// 0068a265  dab424fc2e0000       fidiv dword ptr [esp + 0x2efc]
// 0068a26c  8bce                 mov ecx, esi
// 0068a26e  d9e8                 fld1 
// 0068a270  d9c0                 fld st(0)
// 0068a272  dee2                 fsubrp st(2)
// 0068a274  d9c9                 fxch st(1)
// 0068a276  d95c2404             fstp dword ptr [esp + 4]
// 0068a27a  db44241c             fild dword ptr [esp + 0x1c]
// 0068a27e  dab424f82e0000       fidiv dword ptr [esp + 0x2ef8]
// 0068a285  dee9                 fsubp st(1)
// 0068a287  d91c24               fstp dword ptr [esp]
// 0068a28a  ffd0                 call eax
// 0068a28c  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0068a290  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 0068a294  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a299  f7e9                 imul ecx
// 0068a29b  d1fa                 sar edx, 1
// 0068a29d  8bc2                 mov eax, edx
// 0068a29f  c1e81f               shr eax, 0x1f
// 0068a2a2  03c2                 add eax, edx
// 0068a2a4  89442418             mov dword ptr [esp + 0x18], eax
// 0068a2a8  83f802               cmp eax, 2
// 0068a2ab  0f8297030000         jb 0x68a648
// 0068a2b1  8bc8                 mov ecx, eax
// 0068a2b3  81e101000080         and ecx, 0x80000001
// 0068a2b9  7905                 jns 0x68a2c0
// 0068a2bb  49                   dec ecx
// 0068a2bc  83c9fe               or ecx, 0xfffffffe
// 0068a2bf  41                   inc ecx
// 0068a2c0  0f84b4010000         je 0x68a47a
// 0068a2c6  8d58ff               lea ebx, [eax - 1]
// 0068a2c9  3bd8                 cmp ebx, eax
// 0068a2cb  7206                 jb 0x68a2d3
// 0068a2cd  ff1590288000         call dword ptr [0x802890]
// 0068a2d3  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068a2d7  8b16                 mov edx, dword ptr [esi]
// 0068a2d9  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068a2df  8d045b               lea eax, [ebx + ebx*2]
// 0068a2e2  8d0481               lea eax, [ecx + eax*4]
// 0068a2e5  50                   push eax
// 0068a2e6  8bce                 mov ecx, esi
// 0068a2e8  ffd2                 call edx
// 0068a2ea  8b06                 mov eax, dword ptr [esi]
// 0068a2ec  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a2f2  55                   push ebp
// 0068a2f3  8bce                 mov ecx, esi
// 0068a2f5  ffd2                 call edx
// 0068a2f7  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068a2fb  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068a2ff  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a304  f7e9                 imul ecx
// 0068a306  d1fa                 sar edx, 1
// 0068a308  8bc2                 mov eax, edx
// 0068a30a  c1e81f               shr eax, 0x1f
// 0068a30d  03c2                 add eax, edx
// 0068a30f  45                   inc ebp
// 0068a310  3bd8                 cmp ebx, eax
// 0068a312  7206                 jb 0x68a31a
// 0068a314  ff1590288000         call dword ptr [0x802890]
// 0068a31a  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068a31e  8b16                 mov edx, dword ptr [esi]
// 0068a320  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068a326  8d045b               lea eax, [ebx + ebx*2]
// 0068a329  8d0481               lea eax, [ecx + eax*4]
// 0068a32c  50                   push eax
// 0068a32d  8bce                 mov ecx, esi
// 0068a32f  ffd2                 call edx
// 0068a331  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0068a335  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 0068a339  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0068a33d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a342  f7e9                 imul ecx
// 0068a344  d1fa                 sar edx, 1
// 0068a346  8bc2                 mov eax, edx
// 0068a348  c1e81f               shr eax, 0x1f
// 0068a34b  83c3fe               add ebx, -2
// 0068a34e  03c2                 add eax, edx
// 0068a350  3bd8                 cmp ebx, eax
// 0068a352  7206                 jb 0x68a35a
// 0068a354  ff1590288000         call dword ptr [0x802890]
// 0068a35a  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068a35e  8b16                 mov edx, dword ptr [esi]
// 0068a360  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068a366  8d045b               lea eax, [ebx + ebx*2]
// 0068a369  8d0481               lea eax, [ecx + eax*4]
// 0068a36c  50                   push eax
// 0068a36d  8bce                 mov ecx, esi
// 0068a36f  ffd2                 call edx
// 0068a371  8b06                 mov eax, dword ptr [esi]
// 0068a373  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a379  55                   push ebp
// 0068a37a  8bce                 mov ecx, esi
// 0068a37c  ffd2                 call edx
// 0068a37e  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068a382  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068a386  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a38b  f7e9                 imul ecx
// 0068a38d  d1fa                 sar edx, 1
// 0068a38f  8bc2                 mov eax, edx
// 0068a391  c1e81f               shr eax, 0x1f
// 0068a394  03c2                 add eax, edx
// 0068a396  45                   inc ebp
// 0068a397  3bd8                 cmp ebx, eax
// 0068a399  7206                 jb 0x68a3a1
// 0068a39b  ff1590288000         call dword ptr [0x802890]
// 0068a3a1  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068a3a5  8b16                 mov edx, dword ptr [esi]
// 0068a3a7  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068a3ad  8d045b               lea eax, [ebx + ebx*2]
// 0068a3b0  8d0481               lea eax, [ecx + eax*4]
// 0068a3b3  50                   push eax
// 0068a3b4  8bce                 mov ecx, esi
// 0068a3b6  ffd2                 call edx
// 0068a3b8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0068a3bc  03c9                 add ecx, ecx
// 0068a3be  03c9                 add ecx, ecx
// 0068a3c0  d9840c90050000       fld dword ptr [esp + ecx + 0x590]
// 0068a3c7  8d840c90050000       lea eax, [esp + ecx + 0x590]
// 0068a3ce  d9442440             fld dword ptr [esp + 0x40]
// 0068a3d2  8944244c             mov dword ptr [esp + 0x4c], eax
// 0068a3d6  dcc9                 fmul st(1), st(0)
// 0068a3d8  8d840cd0010000       lea eax, [esp + ecx + 0x1d0]
// 0068a3df  d9c9                 fxch st(1)
// 0068a3e1  83ec0c               sub esp, 0xc
// 0068a3e4  89442450             mov dword ptr [esp + 0x50], eax
// 0068a3e8  d954242c             fst dword ptr [esp + 0x2c]
// 0068a3ec  894c2424             mov dword ptr [esp + 0x24], ecx
// 0068a3f0  d900                 fld dword ptr [eax]
// 0068a3f2  8b06                 mov eax, dword ptr [esi]
// 0068a3f4  deca                 fmulp st(2)
// 0068a3f6  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 0068a3fc  d9c9                 fxch st(1)
// 0068a3fe  8bce                 mov ecx, esi
// 0068a400  d9542444             fst dword ptr [esp + 0x44]
// 0068a404  d94728               fld dword ptr [edi + 0x28]
// 0068a407  d8442430             fadd dword ptr [esp + 0x30]
// 0068a40b  d95c2408             fstp dword ptr [esp + 8]
// 0068a40f  d9c9                 fxch st(1)
// 0068a411  d84724               fadd dword ptr [edi + 0x24]
// 0068a414  d95c2404             fstp dword ptr [esp + 4]
// 0068a418  d84720               fadd dword ptr [edi + 0x20]
// 0068a41b  d91c24               fstp dword ptr [esp]
// 0068a41e  ffd2                 call edx
// 0068a420  8b06                 mov eax, dword ptr [esi]
// 0068a422  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a428  55                   push ebp
// 0068a429  8bce                 mov ecx, esi
// 0068a42b  ffd2                 call edx
// 0068a42d  8b06                 mov eax, dword ptr [esi]
// 0068a42f  8b90fc000000         mov edx, dword ptr [eax + 0xfc]
// 0068a435  8d8c2480000000       lea ecx, [esp + 0x80]
// 0068a43c  51                   push ecx
// 0068a43d  8bce                 mov ecx, esi
// 0068a43f  45                   inc ebp
// 0068a440  ffd2                 call edx
// 0068a442  d9442438             fld dword ptr [esp + 0x38]
// 0068a446  d84720               fadd dword ptr [edi + 0x20]
// 0068a449  8d8424b0000000       lea eax, [esp + 0xb0]
// 0068a450  d9442420             fld dword ptr [esp + 0x20]
// 0068a454  d84724               fadd dword ptr [edi + 0x24]
// 0068a457  d94728               fld dword ptr [edi + 0x28]
// 0068a45a  d8442424             fadd dword ptr [esp + 0x24]
// 0068a45e  d9ca                 fxch st(2)
// 0068a460  d99c24b0000000       fstp dword ptr [esp + 0xb0]
// 0068a467  d99c24b4000000       fstp dword ptr [esp + 0xb4]
// 0068a46e  d99c24b8000000       fstp dword ptr [esp + 0xb8]
// 0068a475  e9ad010000           jmp 0x68a627
// 0068a47a  8d58fe               lea ebx, [eax - 2]
// 0068a47d  3bd8                 cmp ebx, eax
// 0068a47f  7206                 jb 0x68a487
// 0068a481  ff1590288000         call dword ptr [0x802890]
// 0068a487  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068a48b  8b16                 mov edx, dword ptr [esi]
// 0068a48d  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068a493  8d045b               lea eax, [ebx + ebx*2]
// 0068a496  8d0481               lea eax, [ecx + eax*4]
// 0068a499  50                   push eax
// 0068a49a  8bce                 mov ecx, esi
// 0068a49c  ffd2                 call edx
// 0068a49e  8b06                 mov eax, dword ptr [esi]
// 0068a4a0  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a4a6  55                   push ebp
// 0068a4a7  8bce                 mov ecx, esi
// 0068a4a9  ffd2                 call edx
// 0068a4ab  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068a4af  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068a4b3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a4b8  f7e9                 imul ecx
// 0068a4ba  d1fa                 sar edx, 1
// 0068a4bc  8bc2                 mov eax, edx
// 0068a4be  c1e81f               shr eax, 0x1f
// 0068a4c1  03c2                 add eax, edx
// 0068a4c3  45                   inc ebp
// 0068a4c4  3bd8                 cmp ebx, eax
// 0068a4c6  7206                 jb 0x68a4ce
// 0068a4c8  ff1590288000         call dword ptr [0x802890]
// 0068a4ce  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068a4d2  8b16                 mov edx, dword ptr [esi]
// 0068a4d4  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068a4da  8d045b               lea eax, [ebx + ebx*2]
// 0068a4dd  8d0481               lea eax, [ecx + eax*4]
// 0068a4e0  50                   push eax
// 0068a4e1  8bce                 mov ecx, esi
// 0068a4e3  ffd2                 call edx
// 0068a4e5  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0068a4e9  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 0068a4ed  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0068a4f1  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a4f6  f7e9                 imul ecx
// 0068a4f8  d1fa                 sar edx, 1
// 0068a4fa  8bc2                 mov eax, edx
// 0068a4fc  c1e81f               shr eax, 0x1f
// 0068a4ff  4b                   dec ebx
// 0068a500  03c2                 add eax, edx
// 0068a502  3bd8                 cmp ebx, eax
// 0068a504  7206                 jb 0x68a50c
// 0068a506  ff1590288000         call dword ptr [0x802890]
// 0068a50c  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068a510  8b16                 mov edx, dword ptr [esi]
// 0068a512  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068a518  8d045b               lea eax, [ebx + ebx*2]
// 0068a51b  8d0481               lea eax, [ecx + eax*4]
// 0068a51e  50                   push eax
// 0068a51f  8bce                 mov ecx, esi
// 0068a521  ffd2                 call edx
// 0068a523  8b06                 mov eax, dword ptr [esi]
// 0068a525  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a52b  55                   push ebp
// 0068a52c  8bce                 mov ecx, esi
// 0068a52e  ffd2                 call edx
// 0068a530  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068a534  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068a538  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a53d  f7e9                 imul ecx
// 0068a53f  d1fa                 sar edx, 1
// 0068a541  8bc2                 mov eax, edx
// 0068a543  c1e81f               shr eax, 0x1f
// 0068a546  03c2                 add eax, edx
// 0068a548  45                   inc ebp
// 0068a549  3bd8                 cmp ebx, eax
// 0068a54b  7206                 jb 0x68a553
// 0068a54d  ff1590288000         call dword ptr [0x802890]
// 0068a553  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068a557  8b16                 mov edx, dword ptr [esi]
// 0068a559  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068a55f  8d045b               lea eax, [ebx + ebx*2]
// 0068a562  8d0481               lea eax, [ecx + eax*4]
// 0068a565  50                   push eax
// 0068a566  8bce                 mov ecx, esi
// 0068a568  ffd2                 call edx
// 0068a56a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0068a56e  03c9                 add ecx, ecx
// 0068a570  03c9                 add ecx, ecx
// 0068a572  d9840c90050000       fld dword ptr [esp + ecx + 0x590]
// 0068a579  8d840c90050000       lea eax, [esp + ecx + 0x590]
// 0068a580  d9442440             fld dword ptr [esp + 0x40]
// 0068a584  8944244c             mov dword ptr [esp + 0x4c], eax
// 0068a588  dcc9                 fmul st(1), st(0)
// 0068a58a  8d840cd0010000       lea eax, [esp + ecx + 0x1d0]
// 0068a591  d9c9                 fxch st(1)
// 0068a593  83ec0c               sub esp, 0xc
// 0068a596  89442450             mov dword ptr [esp + 0x50], eax
// 0068a59a  d954242c             fst dword ptr [esp + 0x2c]
// 0068a59e  894c2424             mov dword ptr [esp + 0x24], ecx
// 0068a5a2  d900                 fld dword ptr [eax]
// 0068a5a4  8b06                 mov eax, dword ptr [esi]
// 0068a5a6  deca                 fmulp st(2)
// 0068a5a8  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 0068a5ae  d9c9                 fxch st(1)
// 0068a5b0  8bce                 mov ecx, esi
// 0068a5b2  d9542444             fst dword ptr [esp + 0x44]
// 0068a5b6  d94728               fld dword ptr [edi + 0x28]
// 0068a5b9  d8442430             fadd dword ptr [esp + 0x30]
// 0068a5bd  d95c2408             fstp dword ptr [esp + 8]
// 0068a5c1  d9c9                 fxch st(1)
// 0068a5c3  d84724               fadd dword ptr [edi + 0x24]
// 0068a5c6  d95c2404             fstp dword ptr [esp + 4]
// 0068a5ca  d84720               fadd dword ptr [edi + 0x20]
// 0068a5cd  d91c24               fstp dword ptr [esp]
// 0068a5d0  ffd2                 call edx
// 0068a5d2  8b06                 mov eax, dword ptr [esi]
// 0068a5d4  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a5da  55                   push ebp
// 0068a5db  8bce                 mov ecx, esi
// 0068a5dd  ffd2                 call edx
// 0068a5df  8b06                 mov eax, dword ptr [esi]
// 0068a5e1  8b90fc000000         mov edx, dword ptr [eax + 0xfc]
// 0068a5e7  8d8c2480000000       lea ecx, [esp + 0x80]
// 0068a5ee  51                   push ecx
// 0068a5ef  8bce                 mov ecx, esi
// 0068a5f1  45                   inc ebp
// 0068a5f2  ffd2                 call edx
// 0068a5f4  d9442438             fld dword ptr [esp + 0x38]
// 0068a5f8  d84720               fadd dword ptr [edi + 0x20]
// 0068a5fb  8d842410010000       lea eax, [esp + 0x110]
// 0068a602  d9442420             fld dword ptr [esp + 0x20]
// 0068a606  d84724               fadd dword ptr [edi + 0x24]
// 0068a609  d94728               fld dword ptr [edi + 0x28]
// 0068a60c  d8442424             fadd dword ptr [esp + 0x24]
// 0068a610  d9ca                 fxch st(2)
// 0068a612  d99c2410010000       fstp dword ptr [esp + 0x110]
// 0068a619  d99c2414010000       fstp dword ptr [esp + 0x114]
// 0068a620  d99c2418010000       fstp dword ptr [esp + 0x118]
// 0068a627  50                   push eax
// 0068a628  8d4c246c             lea ecx, [esp + 0x6c]
// 0068a62c  e81f3ce5ff           call 0x4de250
// 0068a631  8d8c2480000000       lea ecx, [esp + 0x80]
// 0068a638  51                   push ecx
// 0068a639  8d4c2454             lea ecx, [esp + 0x54]
// 0068a63d  e80e3ce5ff           call 0x4de250
// 0068a642  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0068a646  eb7d                 jmp 0x68a6c5
// 0068a648  8b442414             mov eax, dword ptr [esp + 0x14]
// 0068a64c  03c0                 add eax, eax
// 0068a64e  03c0                 add eax, eax
// 0068a650  d98404d0010000       fld dword ptr [esp + eax + 0x1d0]
// 0068a657  8d8c04d0010000       lea ecx, [esp + eax + 0x1d0]
// 0068a65e  d9442440             fld dword ptr [esp + 0x40]
// 0068a662  89442418             mov dword ptr [esp + 0x18], eax
// 0068a666  dcc9                 fmul st(1), st(0)
// 0068a668  8d840490050000       lea eax, [esp + eax + 0x590]
// 0068a66f  d9c9                 fxch st(1)
// 0068a671  8d942498000000       lea edx, [esp + 0x98]
// 0068a678  d84720               fadd dword ptr [edi + 0x20]
// 0068a67b  d900                 fld dword ptr [eax]
// 0068a67d  deca                 fmulp st(2)
// 0068a67f  d9c9                 fxch st(1)
// 0068a681  d84724               fadd dword ptr [edi + 0x24]
// 0068a684  d94728               fld dword ptr [edi + 0x28]
// 0068a687  d8442424             fadd dword ptr [esp + 0x24]
// 0068a68b  d9ca                 fxch st(2)
// 0068a68d  d99c2498000000       fstp dword ptr [esp + 0x98]
// 0068a694  d99c249c000000       fstp dword ptr [esp + 0x9c]
// 0068a69b  d99c24a0000000       fstp dword ptr [esp + 0xa0]
// 0068a6a2  894c2444             mov dword ptr [esp + 0x44], ecx
// 0068a6a6  52                   push edx
// 0068a6a7  8d4c246c             lea ecx, [esp + 0x6c]
// 0068a6ab  89442450             mov dword ptr [esp + 0x50], eax
// 0068a6af  e89c3be5ff           call 0x4de250
// 0068a6b4  8d842480000000       lea eax, [esp + 0x80]
// 0068a6bb  50                   push eax
// 0068a6bc  8d4c2454             lea ecx, [esp + 0x54]
// 0068a6c0  e88b3be5ff           call 0x4de250
// 0068a6c5  8b07                 mov eax, dword ptr [edi]
// 0068a6c7  83e800               sub eax, 0
// 0068a6ca  7422                 je 0x68a6ee
// 0068a6cc  83e801               sub eax, 1
// 0068a6cf  7553                 jne 0x68a724
// 0068a6d1  8b442418             mov eax, dword ptr [esp + 0x18]
// 0068a6d5  d98404d01f0000       fld dword ptr [esp + eax + 0x1fd0]
// 0068a6dc  d984248c000000       fld dword ptr [esp + 0x8c]
// 0068a6e3  dcc9                 fmul st(1), st(0)
// 0068a6e5  d88c0490230000       fmul dword ptr [esp + eax + 0x2390]
// 0068a6ec  eb1b                 jmp 0x68a709
// 0068a6ee  8b442418             mov eax, dword ptr [esp + 0x18]
// 0068a6f2  d98404100d0000       fld dword ptr [esp + eax + 0xd10]
// 0068a6f9  d984248c000000       fld dword ptr [esp + 0x8c]
// 0068a700  dcc9                 fmul st(1), st(0)
// 0068a702  d88c0450090000       fmul dword ptr [esp + eax + 0x950]
// 0068a709  d9c9                 fxch st(1)
// 0068a70b  d99c2480000000       fstp dword ptr [esp + 0x80]
// 0068a712  d99c2484000000       fstp dword ptr [esp + 0x84]
// 0068a719  d9442448             fld dword ptr [esp + 0x48]
// 0068a71d  d99c2488000000       fstp dword ptr [esp + 0x88]
// 0068a724  837f0800             cmp dword ptr [edi + 8], 0
// 0068a728  0f85e6030000         jne 0x68ab14
// 0068a72e  807f0400             cmp byte ptr [edi + 4], 0
// 0068a732  7436                 je 0x68a76a
// 0068a734  db442410             fild dword ptr [esp + 0x10]
// 0068a738  83ec08               sub esp, 8
// 0068a73b  8b16                 mov edx, dword ptr [esi]
// 0068a73d  8b820c010000         mov eax, dword ptr [edx + 0x10c]
// 0068a743  dab424fc2e0000       fidiv dword ptr [esp + 0x2efc]
// 0068a74a  8bce                 mov ecx, esi
// 0068a74c  d9e8                 fld1 
// 0068a74e  d9c0                 fld st(0)
// 0068a750  dee2                 fsubrp st(2)
// 0068a752  d9c9                 fxch st(1)
// 0068a754  d95c2404             fstp dword ptr [esp + 4]
// 0068a758  db44241c             fild dword ptr [esp + 0x1c]
// 0068a75c  dab424f82e0000       fidiv dword ptr [esp + 0x2ef8]
// 0068a763  dee9                 fsubp st(1)
// 0068a765  d91c24               fstp dword ptr [esp]
// 0068a768  ffd0                 call eax
// 0068a76a  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0068a76e  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 0068a772  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a777  f7e9                 imul ecx
// 0068a779  d1fa                 sar edx, 1
// 0068a77b  8bc2                 mov eax, edx
// 0068a77d  c1e81f               shr eax, 0x1f
// 0068a780  03c2                 add eax, edx
// 0068a782  89442418             mov dword ptr [esp + 0x18], eax
// 0068a786  83f802               cmp eax, 2
// 0068a789  0f823d030000         jb 0x68aacc
// 0068a78f  8bc8                 mov ecx, eax
// 0068a791  81e101000080         and ecx, 0x80000001
// 0068a797  7905                 jns 0x68a79e
// 0068a799  49                   dec ecx
// 0068a79a  83c9fe               or ecx, 0xfffffffe
// 0068a79d  41                   inc ecx
// 0068a79e  0f8495010000         je 0x68a939
// 0068a7a4  8d58ff               lea ebx, [eax - 1]
// 0068a7a7  3bd8                 cmp ebx, eax
// 0068a7a9  7206                 jb 0x68a7b1
// 0068a7ab  ff1590288000         call dword ptr [0x802890]
// 0068a7b1  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068a7b5  8b16                 mov edx, dword ptr [esi]
// 0068a7b7  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068a7bd  8d045b               lea eax, [ebx + ebx*2]
// 0068a7c0  8d0481               lea eax, [ecx + eax*4]
// 0068a7c3  50                   push eax
// 0068a7c4  8bce                 mov ecx, esi
// 0068a7c6  ffd2                 call edx
// 0068a7c8  8b06                 mov eax, dword ptr [esi]
// 0068a7ca  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a7d0  55                   push ebp
// 0068a7d1  8bce                 mov ecx, esi
// 0068a7d3  ffd2                 call edx
// 0068a7d5  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068a7d9  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068a7dd  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a7e2  f7e9                 imul ecx
// 0068a7e4  d1fa                 sar edx, 1
// 0068a7e6  8bc2                 mov eax, edx
// 0068a7e8  c1e81f               shr eax, 0x1f
// 0068a7eb  03c2                 add eax, edx
// 0068a7ed  45                   inc ebp
// 0068a7ee  3bd8                 cmp ebx, eax
// 0068a7f0  7206                 jb 0x68a7f8
// 0068a7f2  ff1590288000         call dword ptr [0x802890]
// 0068a7f8  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068a7fc  8b16                 mov edx, dword ptr [esi]
// 0068a7fe  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068a804  8d045b               lea eax, [ebx + ebx*2]
// 0068a807  8d0481               lea eax, [ecx + eax*4]
// 0068a80a  50                   push eax
// 0068a80b  8bce                 mov ecx, esi
// 0068a80d  ffd2                 call edx
// 0068a80f  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0068a813  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 0068a817  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0068a81b  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a820  f7e9                 imul ecx
// 0068a822  d1fa                 sar edx, 1
// 0068a824  8bc2                 mov eax, edx
// 0068a826  c1e81f               shr eax, 0x1f
// 0068a829  83c3fe               add ebx, -2
// 0068a82c  03c2                 add eax, edx
// 0068a82e  3bd8                 cmp ebx, eax
// 0068a830  7206                 jb 0x68a838
// 0068a832  ff1590288000         call dword ptr [0x802890]
// 0068a838  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068a83c  8b16                 mov edx, dword ptr [esi]
// 0068a83e  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068a844  8d045b               lea eax, [ebx + ebx*2]
// 0068a847  8d0481               lea eax, [ecx + eax*4]
// 0068a84a  50                   push eax
// 0068a84b  8bce                 mov ecx, esi
// 0068a84d  ffd2                 call edx
// 0068a84f  8b06                 mov eax, dword ptr [esi]
// 0068a851  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a857  55                   push ebp
// 0068a858  8bce                 mov ecx, esi
// 0068a85a  ffd2                 call edx
// 0068a85c  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068a860  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068a864  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a869  f7e9                 imul ecx
// 0068a86b  d1fa                 sar edx, 1
// 0068a86d  8bc2                 mov eax, edx
// 0068a86f  c1e81f               shr eax, 0x1f
// 0068a872  03c2                 add eax, edx
// 0068a874  45                   inc ebp
// 0068a875  3bd8                 cmp ebx, eax
// 0068a877  7206                 jb 0x68a87f
// 0068a879  ff1590288000         call dword ptr [0x802890]
// 0068a87f  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068a883  8b16                 mov edx, dword ptr [esi]
// 0068a885  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068a88b  8d045b               lea eax, [ebx + ebx*2]
// 0068a88e  8d0481               lea eax, [ecx + eax*4]
// 0068a891  50                   push eax
// 0068a892  8bce                 mov ecx, esi
// 0068a894  ffd2                 call edx
// 0068a896  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0068a89a  d900                 fld dword ptr [eax]
// 0068a89c  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0068a8a0  d9442440             fld dword ptr [esp + 0x40]
// 0068a8a4  8b16                 mov edx, dword ptr [esi]
// 0068a8a6  dcc9                 fmul st(1), st(0)
// 0068a8a8  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0068a8ae  d9c9                 fxch st(1)
// 0068a8b0  83ec0c               sub esp, 0xc
// 0068a8b3  d954242c             fst dword ptr [esp + 0x2c]
// 0068a8b7  d901                 fld dword ptr [ecx]
// 0068a8b9  8bce                 mov ecx, esi
// 0068a8bb  deca                 fmulp st(2)
// 0068a8bd  d9c9                 fxch st(1)
// 0068a8bf  d9542444             fst dword ptr [esp + 0x44]
// 0068a8c3  d94728               fld dword ptr [edi + 0x28]
// 0068a8c6  d8442430             fadd dword ptr [esp + 0x30]
// 0068a8ca  d95c2408             fstp dword ptr [esp + 8]
// 0068a8ce  d9c9                 fxch st(1)
// 0068a8d0  d84724               fadd dword ptr [edi + 0x24]
// 0068a8d3  d95c2404             fstp dword ptr [esp + 4]
// 0068a8d7  d84720               fadd dword ptr [edi + 0x20]
// 0068a8da  d91c24               fstp dword ptr [esp]
// 0068a8dd  ffd0                 call eax
// 0068a8df  8b16                 mov edx, dword ptr [esi]
// 0068a8e1  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068a8e7  55                   push ebp
// 0068a8e8  8bce                 mov ecx, esi
// 0068a8ea  ffd0                 call eax
// 0068a8ec  8b16                 mov edx, dword ptr [esi]
// 0068a8ee  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068a8f4  8d842480000000       lea eax, [esp + 0x80]
// 0068a8fb  50                   push eax
// 0068a8fc  8bce                 mov ecx, esi
// 0068a8fe  45                   inc ebp
// 0068a8ff  ffd2                 call edx
// 0068a901  d9442438             fld dword ptr [esp + 0x38]
// 0068a905  d84720               fadd dword ptr [edi + 0x20]
// 0068a908  8d8424f8000000       lea eax, [esp + 0xf8]
// 0068a90f  d9442420             fld dword ptr [esp + 0x20]
// 0068a913  d84724               fadd dword ptr [edi + 0x24]
// 0068a916  d94728               fld dword ptr [edi + 0x28]
// 0068a919  d8442424             fadd dword ptr [esp + 0x24]
// 0068a91d  d9ca                 fxch st(2)
// 0068a91f  d99c24f8000000       fstp dword ptr [esp + 0xf8]
// 0068a926  d99c24fc000000       fstp dword ptr [esp + 0xfc]
// 0068a92d  d99c2400010000       fstp dword ptr [esp + 0x100]
// 0068a934  e97b050000           jmp 0x68aeb4
// 0068a939  8d58fe               lea ebx, [eax - 2]
// 0068a93c  3bd8                 cmp ebx, eax
// 0068a93e  7206                 jb 0x68a946
// 0068a940  ff1590288000         call dword ptr [0x802890]
// 0068a946  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068a94a  8b16                 mov edx, dword ptr [esi]
// 0068a94c  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068a952  8d045b               lea eax, [ebx + ebx*2]
// 0068a955  8d0481               lea eax, [ecx + eax*4]
// 0068a958  50                   push eax
// 0068a959  8bce                 mov ecx, esi
// 0068a95b  ffd2                 call edx
// 0068a95d  8b06                 mov eax, dword ptr [esi]
// 0068a95f  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a965  55                   push ebp
// 0068a966  8bce                 mov ecx, esi
// 0068a968  ffd2                 call edx
// 0068a96a  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068a96e  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068a972  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a977  f7e9                 imul ecx
// 0068a979  d1fa                 sar edx, 1
// 0068a97b  8bc2                 mov eax, edx
// 0068a97d  c1e81f               shr eax, 0x1f
// 0068a980  03c2                 add eax, edx
// 0068a982  45                   inc ebp
// 0068a983  3bd8                 cmp ebx, eax
// 0068a985  7206                 jb 0x68a98d
// 0068a987  ff1590288000         call dword ptr [0x802890]
// 0068a98d  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068a991  8b16                 mov edx, dword ptr [esi]
// 0068a993  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068a999  8d045b               lea eax, [ebx + ebx*2]
// 0068a99c  8d0481               lea eax, [ecx + eax*4]
// 0068a99f  50                   push eax
// 0068a9a0  8bce                 mov ecx, esi
// 0068a9a2  ffd2                 call edx
// 0068a9a4  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0068a9a8  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 0068a9ac  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0068a9b0  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a9b5  f7e9                 imul ecx
// 0068a9b7  d1fa                 sar edx, 1
// 0068a9b9  8bc2                 mov eax, edx
// 0068a9bb  c1e81f               shr eax, 0x1f
// 0068a9be  4b                   dec ebx
// 0068a9bf  03c2                 add eax, edx
// 0068a9c1  3bd8                 cmp ebx, eax
// 0068a9c3  7206                 jb 0x68a9cb
// 0068a9c5  ff1590288000         call dword ptr [0x802890]
// 0068a9cb  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068a9cf  8b16                 mov edx, dword ptr [esi]
// 0068a9d1  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068a9d7  8d045b               lea eax, [ebx + ebx*2]
// 0068a9da  8d0481               lea eax, [ecx + eax*4]
// 0068a9dd  50                   push eax
// 0068a9de  8bce                 mov ecx, esi
// 0068a9e0  ffd2                 call edx
// 0068a9e2  8b06                 mov eax, dword ptr [esi]
// 0068a9e4  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068a9ea  55                   push ebp
// 0068a9eb  8bce                 mov ecx, esi
// 0068a9ed  ffd2                 call edx
// 0068a9ef  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068a9f3  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068a9f7  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068a9fc  f7e9                 imul ecx
// 0068a9fe  d1fa                 sar edx, 1
// 0068aa00  8bc2                 mov eax, edx
// 0068aa02  c1e81f               shr eax, 0x1f
// 0068aa05  03c2                 add eax, edx
// 0068aa07  45                   inc ebp
// 0068aa08  3bd8                 cmp ebx, eax
// 0068aa0a  7206                 jb 0x68aa12
// 0068aa0c  ff1590288000         call dword ptr [0x802890]
// 0068aa12  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068aa16  8b16                 mov edx, dword ptr [esi]
// 0068aa18  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068aa1e  8d045b               lea eax, [ebx + ebx*2]
// 0068aa21  8d0481               lea eax, [ecx + eax*4]
// 0068aa24  50                   push eax
// 0068aa25  8bce                 mov ecx, esi
// 0068aa27  ffd2                 call edx
// 0068aa29  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0068aa2d  d900                 fld dword ptr [eax]
// 0068aa2f  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0068aa33  d9442440             fld dword ptr [esp + 0x40]
// 0068aa37  8b16                 mov edx, dword ptr [esi]
// 0068aa39  dcc9                 fmul st(1), st(0)
// 0068aa3b  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0068aa41  d9c9                 fxch st(1)
// 0068aa43  83ec0c               sub esp, 0xc
// 0068aa46  d954242c             fst dword ptr [esp + 0x2c]
// 0068aa4a  d901                 fld dword ptr [ecx]
// 0068aa4c  8bce                 mov ecx, esi
// 0068aa4e  deca                 fmulp st(2)
// 0068aa50  d9c9                 fxch st(1)
// 0068aa52  d9542444             fst dword ptr [esp + 0x44]
// 0068aa56  d94728               fld dword ptr [edi + 0x28]
// 0068aa59  d8442430             fadd dword ptr [esp + 0x30]
// 0068aa5d  d95c2408             fstp dword ptr [esp + 8]
// 0068aa61  d9c9                 fxch st(1)
// 0068aa63  d84724               fadd dword ptr [edi + 0x24]
// 0068aa66  d95c2404             fstp dword ptr [esp + 4]
// 0068aa6a  d84720               fadd dword ptr [edi + 0x20]
// 0068aa6d  d91c24               fstp dword ptr [esp]
// 0068aa70  ffd0                 call eax
// 0068aa72  8b16                 mov edx, dword ptr [esi]
// 0068aa74  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068aa7a  55                   push ebp
// 0068aa7b  8bce                 mov ecx, esi
// 0068aa7d  ffd0                 call eax
// 0068aa7f  8b16                 mov edx, dword ptr [esi]
// 0068aa81  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068aa87  8d842480000000       lea eax, [esp + 0x80]
// 0068aa8e  50                   push eax
// 0068aa8f  8bce                 mov ecx, esi
// 0068aa91  45                   inc ebp
// 0068aa92  ffd2                 call edx
// 0068aa94  d9442438             fld dword ptr [esp + 0x38]
// 0068aa98  d84720               fadd dword ptr [edi + 0x20]
// 0068aa9b  8d8424e0000000       lea eax, [esp + 0xe0]
// 0068aaa2  d9442420             fld dword ptr [esp + 0x20]
// 0068aaa6  d84724               fadd dword ptr [edi + 0x24]
// 0068aaa9  d94728               fld dword ptr [edi + 0x28]
// 0068aaac  d8442424             fadd dword ptr [esp + 0x24]
// 0068aab0  d9ca                 fxch st(2)
// 0068aab2  d99c24e0000000       fstp dword ptr [esp + 0xe0]
// 0068aab9  d99c24e4000000       fstp dword ptr [esp + 0xe4]
// 0068aac0  d99c24e8000000       fstp dword ptr [esp + 0xe8]
// 0068aac7  e9e8030000           jmp 0x68aeb4
// 0068aacc  8b542444             mov edx, dword ptr [esp + 0x44]
// 0068aad0  d902                 fld dword ptr [edx]
// 0068aad2  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0068aad6  d9442440             fld dword ptr [esp + 0x40]
// 0068aada  8d8c24a4000000       lea ecx, [esp + 0xa4]
// 0068aae1  dcc9                 fmul st(1), st(0)
// 0068aae3  d9c9                 fxch st(1)
// 0068aae5  d84720               fadd dword ptr [edi + 0x20]
// 0068aae8  d900                 fld dword ptr [eax]
// 0068aaea  deca                 fmulp st(2)
// 0068aaec  d9c9                 fxch st(1)
// 0068aaee  d84724               fadd dword ptr [edi + 0x24]
// 0068aaf1  d94728               fld dword ptr [edi + 0x28]
// 0068aaf4  d8442424             fadd dword ptr [esp + 0x24]
// 0068aaf8  d9ca                 fxch st(2)
// 0068aafa  d99c24a4000000       fstp dword ptr [esp + 0xa4]
// 0068ab01  d99c24a8000000       fstp dword ptr [esp + 0xa8]
// 0068ab08  d99c24ac000000       fstp dword ptr [esp + 0xac]
// 0068ab0f  e904040000           jmp 0x68af18
// 0068ab14  807f0400             cmp byte ptr [edi + 4], 0
// 0068ab18  743d                 je 0x68ab57
// 0068ab1a  8d4b01               lea ecx, [ebx + 1]
// 0068ab1d  894c2420             mov dword ptr [esp + 0x20], ecx
// 0068ab21  db442420             fild dword ptr [esp + 0x20]
// 0068ab25  83ec08               sub esp, 8
// 0068ab28  8b06                 mov eax, dword ptr [esi]
// 0068ab2a  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 0068ab30  dab424fc2e0000       fidiv dword ptr [esp + 0x2efc]
// 0068ab37  8bce                 mov ecx, esi
// 0068ab39  d9e8                 fld1 
// 0068ab3b  d9c0                 fld st(0)
// 0068ab3d  dee2                 fsubrp st(2)
// 0068ab3f  d9c9                 fxch st(1)
// 0068ab41  d95c2404             fstp dword ptr [esp + 4]
// 0068ab45  db44241c             fild dword ptr [esp + 0x1c]
// 0068ab49  dab424f82e0000       fidiv dword ptr [esp + 0x2ef8]
// 0068ab50  dee9                 fsubp st(1)
// 0068ab52  d91c24               fstp dword ptr [esp]
// 0068ab55  ffd2                 call edx
// 0068ab57  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0068ab5b  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 0068ab5f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068ab64  f7e9                 imul ecx
// 0068ab66  d1fa                 sar edx, 1
// 0068ab68  8bc2                 mov eax, edx
// 0068ab6a  c1e81f               shr eax, 0x1f
// 0068ab6d  03c2                 add eax, edx
// 0068ab6f  89442418             mov dword ptr [esp + 0x18], eax
// 0068ab73  83f802               cmp eax, 2
// 0068ab76  0f8259030000         jb 0x68aed5
// 0068ab7c  8bc8                 mov ecx, eax
// 0068ab7e  81e101000080         and ecx, 0x80000001
// 0068ab84  7905                 jns 0x68ab8b
// 0068ab86  49                   dec ecx
// 0068ab87  83c9fe               or ecx, 0xfffffffe
// 0068ab8a  41                   inc ecx
// 0068ab8b  0f8495010000         je 0x68ad26
// 0068ab91  8d58ff               lea ebx, [eax - 1]
// 0068ab94  3bd8                 cmp ebx, eax
// 0068ab96  7206                 jb 0x68ab9e
// 0068ab98  ff1590288000         call dword ptr [0x802890]
// 0068ab9e  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068aba2  8b16                 mov edx, dword ptr [esi]
// 0068aba4  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068abaa  8d045b               lea eax, [ebx + ebx*2]
// 0068abad  8d0481               lea eax, [ecx + eax*4]
// 0068abb0  50                   push eax
// 0068abb1  8bce                 mov ecx, esi
// 0068abb3  ffd2                 call edx
// 0068abb5  8b06                 mov eax, dword ptr [esi]
// 0068abb7  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068abbd  55                   push ebp
// 0068abbe  8bce                 mov ecx, esi
// 0068abc0  ffd2                 call edx
// 0068abc2  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068abc6  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068abca  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068abcf  f7e9                 imul ecx
// 0068abd1  d1fa                 sar edx, 1
// 0068abd3  8bc2                 mov eax, edx
// 0068abd5  c1e81f               shr eax, 0x1f
// 0068abd8  03c2                 add eax, edx
// 0068abda  45                   inc ebp
// 0068abdb  3bd8                 cmp ebx, eax
// 0068abdd  7206                 jb 0x68abe5
// 0068abdf  ff1590288000         call dword ptr [0x802890]
// 0068abe5  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068abe9  8b16                 mov edx, dword ptr [esi]
// 0068abeb  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068abf1  8d045b               lea eax, [ebx + ebx*2]
// 0068abf4  8d0481               lea eax, [ecx + eax*4]
// 0068abf7  50                   push eax
// 0068abf8  8bce                 mov ecx, esi
// 0068abfa  ffd2                 call edx
// 0068abfc  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0068ac00  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 0068ac04  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0068ac08  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068ac0d  f7e9                 imul ecx
// 0068ac0f  d1fa                 sar edx, 1
// 0068ac11  8bc2                 mov eax, edx
// 0068ac13  c1e81f               shr eax, 0x1f
// 0068ac16  83c3fe               add ebx, -2
// 0068ac19  03c2                 add eax, edx
// 0068ac1b  3bd8                 cmp ebx, eax
// 0068ac1d  7206                 jb 0x68ac25
// 0068ac1f  ff1590288000         call dword ptr [0x802890]
// 0068ac25  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068ac29  8b16                 mov edx, dword ptr [esi]
// 0068ac2b  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068ac31  8d045b               lea eax, [ebx + ebx*2]
// 0068ac34  8d0481               lea eax, [ecx + eax*4]
// 0068ac37  50                   push eax
// 0068ac38  8bce                 mov ecx, esi
// 0068ac3a  ffd2                 call edx
// 0068ac3c  8b06                 mov eax, dword ptr [esi]
// 0068ac3e  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068ac44  55                   push ebp
// 0068ac45  8bce                 mov ecx, esi
// 0068ac47  ffd2                 call edx
// 0068ac49  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068ac4d  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068ac51  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068ac56  f7e9                 imul ecx
// 0068ac58  d1fa                 sar edx, 1
// 0068ac5a  8bc2                 mov eax, edx
// 0068ac5c  c1e81f               shr eax, 0x1f
// 0068ac5f  03c2                 add eax, edx
// 0068ac61  45                   inc ebp
// 0068ac62  3bd8                 cmp ebx, eax
// 0068ac64  7206                 jb 0x68ac6c
// 0068ac66  ff1590288000         call dword ptr [0x802890]
// 0068ac6c  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068ac70  8b16                 mov edx, dword ptr [esi]
// 0068ac72  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068ac78  8d045b               lea eax, [ebx + ebx*2]
// 0068ac7b  8d0481               lea eax, [ecx + eax*4]
// 0068ac7e  50                   push eax
// 0068ac7f  8bce                 mov ecx, esi
// 0068ac81  ffd2                 call edx
// 0068ac83  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0068ac87  d900                 fld dword ptr [eax]
// 0068ac89  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0068ac8d  d9442428             fld dword ptr [esp + 0x28]
// 0068ac91  8b16                 mov edx, dword ptr [esi]
// 0068ac93  dcc9                 fmul st(1), st(0)
// 0068ac95  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0068ac9b  d9c9                 fxch st(1)
// 0068ac9d  83ec0c               sub esp, 0xc
// 0068aca0  d9542444             fst dword ptr [esp + 0x44]
// 0068aca4  d901                 fld dword ptr [ecx]
// 0068aca6  8bce                 mov ecx, esi
// 0068aca8  deca                 fmulp st(2)
// 0068acaa  d9c9                 fxch st(1)
// 0068acac  d954242c             fst dword ptr [esp + 0x2c]
// 0068acb0  d94728               fld dword ptr [edi + 0x28]
// 0068acb3  d8442448             fadd dword ptr [esp + 0x48]
// 0068acb7  d95c2408             fstp dword ptr [esp + 8]
// 0068acbb  d9c9                 fxch st(1)
// 0068acbd  d84724               fadd dword ptr [edi + 0x24]
// 0068acc0  d95c2404             fstp dword ptr [esp + 4]
// 0068acc4  d84720               fadd dword ptr [edi + 0x20]
// 0068acc7  d91c24               fstp dword ptr [esp]
// 0068acca  ffd0                 call eax
// 0068accc  8b16                 mov edx, dword ptr [esi]
// 0068acce  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068acd4  55                   push ebp
// 0068acd5  8bce                 mov ecx, esi
// 0068acd7  ffd0                 call eax
// 0068acd9  8b16                 mov edx, dword ptr [esi]
// 0068acdb  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068ace1  8d842480000000       lea eax, [esp + 0x80]
// 0068ace8  50                   push eax
// 0068ace9  8bce                 mov ecx, esi
// 0068aceb  45                   inc ebp
// 0068acec  ffd2                 call edx
// 0068acee  d9442420             fld dword ptr [esp + 0x20]
// 0068acf2  d84720               fadd dword ptr [edi + 0x20]
// 0068acf5  8d8424bc000000       lea eax, [esp + 0xbc]
// 0068acfc  d9442438             fld dword ptr [esp + 0x38]
// 0068ad00  d84724               fadd dword ptr [edi + 0x24]
// 0068ad03  d94728               fld dword ptr [edi + 0x28]
// 0068ad06  d844243c             fadd dword ptr [esp + 0x3c]
// 0068ad0a  d9ca                 fxch st(2)
// 0068ad0c  d99c24bc000000       fstp dword ptr [esp + 0xbc]
// 0068ad13  d99c24c0000000       fstp dword ptr [esp + 0xc0]
// 0068ad1a  d99c24c4000000       fstp dword ptr [esp + 0xc4]
// 0068ad21  e98e010000           jmp 0x68aeb4
// 0068ad26  8d58fe               lea ebx, [eax - 2]
// 0068ad29  3bd8                 cmp ebx, eax
// 0068ad2b  7206                 jb 0x68ad33
// 0068ad2d  ff1590288000         call dword ptr [0x802890]
// 0068ad33  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068ad37  8b16                 mov edx, dword ptr [esi]
// 0068ad39  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068ad3f  8d045b               lea eax, [ebx + ebx*2]
// 0068ad42  8d0481               lea eax, [ecx + eax*4]
// 0068ad45  50                   push eax
// 0068ad46  8bce                 mov ecx, esi
// 0068ad48  ffd2                 call edx
// 0068ad4a  8b06                 mov eax, dword ptr [esi]
// 0068ad4c  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068ad52  55                   push ebp
// 0068ad53  8bce                 mov ecx, esi
// 0068ad55  ffd2                 call edx
// 0068ad57  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068ad5b  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068ad5f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068ad64  f7e9                 imul ecx
// 0068ad66  d1fa                 sar edx, 1
// 0068ad68  8bc2                 mov eax, edx
// 0068ad6a  c1e81f               shr eax, 0x1f
// 0068ad6d  03c2                 add eax, edx
// 0068ad6f  45                   inc ebp
// 0068ad70  3bd8                 cmp ebx, eax
// 0068ad72  7206                 jb 0x68ad7a
// 0068ad74  ff1590288000         call dword ptr [0x802890]
// 0068ad7a  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068ad7e  8b16                 mov edx, dword ptr [esi]
// 0068ad80  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068ad86  8d045b               lea eax, [ebx + ebx*2]
// 0068ad89  8d0481               lea eax, [ecx + eax*4]
// 0068ad8c  50                   push eax
// 0068ad8d  8bce                 mov ecx, esi
// 0068ad8f  ffd2                 call edx
// 0068ad91  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0068ad95  2b4c2474             sub ecx, dword ptr [esp + 0x74]
// 0068ad99  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0068ad9d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068ada2  f7e9                 imul ecx
// 0068ada4  d1fa                 sar edx, 1
// 0068ada6  8bc2                 mov eax, edx
// 0068ada8  c1e81f               shr eax, 0x1f
// 0068adab  4b                   dec ebx
// 0068adac  03c2                 add eax, edx
// 0068adae  3bd8                 cmp ebx, eax
// 0068adb0  7206                 jb 0x68adb8
// 0068adb2  ff1590288000         call dword ptr [0x802890]
// 0068adb8  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0068adbc  8b16                 mov edx, dword ptr [esi]
// 0068adbe  8b92f4000000         mov edx, dword ptr [edx + 0xf4]
// 0068adc4  8d045b               lea eax, [ebx + ebx*2]
// 0068adc7  8d0481               lea eax, [ecx + eax*4]
// 0068adca  50                   push eax
// 0068adcb  8bce                 mov ecx, esi
// 0068adcd  ffd2                 call edx
// 0068adcf  8b06                 mov eax, dword ptr [esi]
// 0068add1  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068add7  55                   push ebp
// 0068add8  8bce                 mov ecx, esi
// 0068adda  ffd2                 call edx
// 0068addc  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0068ade0  2b4c245c             sub ecx, dword ptr [esp + 0x5c]
// 0068ade4  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068ade9  f7e9                 imul ecx
// 0068adeb  d1fa                 sar edx, 1
// 0068aded  8bc2                 mov eax, edx
// 0068adef  c1e81f               shr eax, 0x1f
// 0068adf2  03c2                 add eax, edx
// 0068adf4  45                   inc ebp
// 0068adf5  3bd8                 cmp ebx, eax
// 0068adf7  7206                 jb 0x68adff
// 0068adf9  ff1590288000         call dword ptr [0x802890]
// 0068adff  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0068ae03  8b16                 mov edx, dword ptr [esi]
// 0068ae05  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068ae0b  8d045b               lea eax, [ebx + ebx*2]
// 0068ae0e  8d0481               lea eax, [ecx + eax*4]
// 0068ae11  50                   push eax
// 0068ae12  8bce                 mov ecx, esi
// 0068ae14  ffd2                 call edx
// 0068ae16  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0068ae1a  d900                 fld dword ptr [eax]
// 0068ae1c  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0068ae20  d9442428             fld dword ptr [esp + 0x28]
// 0068ae24  8b16                 mov edx, dword ptr [esi]
// 0068ae26  dcc9                 fmul st(1), st(0)
// 0068ae28  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0068ae2e  d9c9                 fxch st(1)
// 0068ae30  83ec0c               sub esp, 0xc
// 0068ae33  d9542444             fst dword ptr [esp + 0x44]
// 0068ae37  d901                 fld dword ptr [ecx]
// 0068ae39  8bce                 mov ecx, esi
// 0068ae3b  deca                 fmulp st(2)
// 0068ae3d  d9c9                 fxch st(1)
// 0068ae3f  d954242c             fst dword ptr [esp + 0x2c]
// 0068ae43  d94728               fld dword ptr [edi + 0x28]
// 0068ae46  d8442448             fadd dword ptr [esp + 0x48]
// 0068ae4a  d95c2408             fstp dword ptr [esp + 8]
// 0068ae4e  d9c9                 fxch st(1)
// 0068ae50  d84724               fadd dword ptr [edi + 0x24]
// 0068ae53  d95c2404             fstp dword ptr [esp + 4]
// 0068ae57  d84720               fadd dword ptr [edi + 0x20]
// 0068ae5a  d91c24               fstp dword ptr [esp]
// 0068ae5d  ffd0                 call eax
// 0068ae5f  8b16                 mov edx, dword ptr [esi]
// 0068ae61  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068ae67  55                   push ebp
// 0068ae68  8bce                 mov ecx, esi
// 0068ae6a  ffd0                 call eax
// 0068ae6c  8b16                 mov edx, dword ptr [esi]
// 0068ae6e  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 0068ae74  8d842480000000       lea eax, [esp + 0x80]
// 0068ae7b  50                   push eax
// 0068ae7c  8bce                 mov ecx, esi
// 0068ae7e  45                   inc ebp
// 0068ae7f  ffd2                 call edx
// 0068ae81  d9442420             fld dword ptr [esp + 0x20]
// 0068ae85  d84720               fadd dword ptr [edi + 0x20]
// 0068ae88  8d8424d4000000       lea eax, [esp + 0xd4]
// 0068ae8f  d9442438             fld dword ptr [esp + 0x38]
// 0068ae93  d84724               fadd dword ptr [edi + 0x24]
// 0068ae96  d94728               fld dword ptr [edi + 0x28]
// 0068ae99  d844243c             fadd dword ptr [esp + 0x3c]
// 0068ae9d  d9ca                 fxch st(2)
// 0068ae9f  d99c24d4000000       fstp dword ptr [esp + 0xd4]
// 0068aea6  d99c24d8000000       fstp dword ptr [esp + 0xd8]
// 0068aead  d99c24dc000000       fstp dword ptr [esp + 0xdc]
// 0068aeb4  50                   push eax
// 0068aeb5  8d4c246c             lea ecx, [esp + 0x6c]
// 0068aeb9  e89233e5ff           call 0x4de250
// 0068aebe  8d8c2480000000       lea ecx, [esp + 0x80]
// 0068aec5  51                   push ecx
// 0068aec6  8d4c2454             lea ecx, [esp + 0x54]
// 0068aeca  e88133e5ff           call 0x4de250
// 0068aecf  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0068aed3  eb5e                 jmp 0x68af33
// 0068aed5  8b542444             mov edx, dword ptr [esp + 0x44]
// 0068aed9  d902                 fld dword ptr [edx]
// 0068aedb  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0068aedf  d9442428             fld dword ptr [esp + 0x28]
// 0068aee3  8d8c24ec000000       lea ecx, [esp + 0xec]
// 0068aeea  dcc9                 fmul st(1), st(0)
// 0068aeec  d9c9                 fxch st(1)
// 0068aeee  d84720               fadd dword ptr [edi + 0x20]
// 0068aef1  d900                 fld dword ptr [eax]
// 0068aef3  deca                 fmulp st(2)
// 0068aef5  d9c9                 fxch st(1)
// 0068aef7  d84724               fadd dword ptr [edi + 0x24]
// 0068aefa  d94728               fld dword ptr [edi + 0x28]
// 0068aefd  d844243c             fadd dword ptr [esp + 0x3c]
// 0068af01  d9ca                 fxch st(2)
// 0068af03  d99c24ec000000       fstp dword ptr [esp + 0xec]
// 0068af0a  d99c24f0000000       fstp dword ptr [esp + 0xf0]
// 0068af11  d99c24f4000000       fstp dword ptr [esp + 0xf4]
// 0068af18  51                   push ecx
// 0068af19  8d4c246c             lea ecx, [esp + 0x6c]
// 0068af1d  e82e33e5ff           call 0x4de250
// 0068af22  8d942480000000       lea edx, [esp + 0x80]
// 0068af29  52                   push edx
// 0068af2a  8d4c2454             lea ecx, [esp + 0x54]
// 0068af2e  e81d33e5ff           call 0x4de250
// 0068af33  8b442414             mov eax, dword ptr [esp + 0x14]
// 0068af37  40                   inc eax
// 0068af38  3b8424f02e0000       cmp eax, dword ptr [esp + 0x2ef0]
// 0068af3f  89442414             mov dword ptr [esp + 0x14], eax
// 0068af43  0f8e87eeffff         jle 0x689dd0
// 0068af49  8b842490000000       mov eax, dword ptr [esp + 0x90]
// 0068af50  48                   dec eax
// 0068af51  3bd8                 cmp ebx, eax
// 0068af53  750c                 jne 0x68af61
// 0068af55  8b06                 mov eax, dword ptr [esi]
// 0068af57  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 0068af5d  8bce                 mov ecx, esi
// 0068af5f  ffd2                 call edx
// 0068af61  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0068af65  85c0                 test eax, eax
// 0068af67  7409                 je 0x68af72
// 0068af69  50                   push eax
// 0068af6a  e80b570100           call 0x6a067a
// 0068af6f  83c404               add esp, 4
// 0068af72  33c0                 xor eax, eax
// 0068af74  8944245c             mov dword ptr [esp + 0x5c], eax
// 0068af78  89442460             mov dword ptr [esp + 0x60], eax
// 0068af7c  89442464             mov dword ptr [esp + 0x64], eax
// 0068af80  8b442450             mov eax, dword ptr [esp + 0x50]
// 0068af84  50                   push eax
// 0068af85  e8f0560100           call 0x6a067a
// 0068af8a  8b442478             mov eax, dword ptr [esp + 0x78]
// 0068af8e  83c404               add esp, 4
// 0068af91  c78424d82e0000ffffffff mov dword ptr [esp + 0x2ed8], 0xffffffff
// 0068af9c  85c0                 test eax, eax
// 0068af9e  7409                 je 0x68afa9
// 0068afa0  50                   push eax
// 0068afa1  e8d4560100           call 0x6a067a
// 0068afa6  83c404               add esp, 4
// 0068afa9  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 0068afad  33c0                 xor eax, eax
// 0068afaf  51                   push ecx
// 0068afb0  89442478             mov dword ptr [esp + 0x78], eax
// 0068afb4  8944247c             mov dword ptr [esp + 0x7c], eax
// 0068afb8  89842480000000       mov dword ptr [esp + 0x80], eax
// 0068afbf  e8b6560100           call 0x6a067a
// 0068afc4  43                   inc ebx
// 0068afc5  83c404               add esp, 4
// 0068afc8  3b9c2490000000       cmp ebx, dword ptr [esp + 0x90]
// 0068afcf  895c2410             mov dword ptr [esp + 0x10], ebx
// 0068afd3  0f8c57ecffff         jl 0x689c30
// 0068afd9  8bc6                 mov eax, esi
// 0068afdb  5b                   pop ebx
// 0068afdc  e9b1050000           jmp 0x68b592
// 0068afe1  6816b78000           push 0x80b716
// 0068afe6  8d8c242c010000       lea ecx, [esp + 0x12c]
// 0068afed  ff1558248000         call dword ptr [0x802458]
// 0068aff3  8b16                 mov edx, dword ptr [esi]
// 0068aff5  8b92e0000000         mov edx, dword ptr [edx + 0xe0]
// 0068affb  6a01                 push 1
// 0068affd  8d84242c010000       lea eax, [esp + 0x12c]
// 0068b004  50                   push eax
// 0068b005  8bce                 mov ecx, esi
// 0068b007  c78424e02e000007000000 mov dword ptr [esp + 0x2ee0], 7
// 0068b012  ffd2                 call edx
// 0068b014  8d8c2428010000       lea ecx, [esp + 0x128]
// 0068b01b  c78424d82e0000ffffffff mov dword ptr [esp + 0x2ed8], 0xffffffff
// 0068b026  ff1568248000         call dword ptr [0x802468]
// 0068b02c  d9ee                 fldz 
// 0068b02e  d85f10               fcomp dword ptr [edi + 0x10]
// 0068b031  8d4f10               lea ecx, [edi + 0x10]
// 0068b034  33db                 xor ebx, ebx
// 0068b036  dfe0                 fnstsw ax
// 0068b038  f6c441               test ah, 0x41
// 0068b03b  7a0d                 jp 0x68b04a
// 0068b03d  8b06                 mov eax, dword ptr [esi]
// 0068b03f  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 0068b045  51                   push ecx
// 0068b046  8bce                 mov ecx, esi
// 0068b048  ffd2                 call edx
// 0068b04a  83bc24f42e000000     cmp dword ptr [esp + 0x2ef4], 0
// 0068b052  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0068b05a  7c5c                 jl 0x68b0b8
// 0068b05c  8d642400             lea esp, [esp]
// 0068b060  833f01               cmp dword ptr [edi], 1
// 0068b063  8b442410             mov eax, dword ptr [esp + 0x10]
// 0068b067  d98484d0100000       fld dword ptr [esp + eax*4 + 0x10d0]
// 0068b06e  d9542440             fst dword ptr [esp + 0x40]
// 0068b072  d98484101c0000       fld dword ptr [esp + eax*4 + 0x1c10]
// 0068b079  d95c2448             fstp dword ptr [esp + 0x48]
// 0068b07d  7716                 ja 0x68b095
// 0068b07f  d9848450180000       fld dword ptr [esp + eax*4 + 0x1850]
// 0068b086  d95c2428             fstp dword ptr [esp + 0x28]
// 0068b08a  d9848490140000       fld dword ptr [esp + eax*4 + 0x1490]
// 0068b091  d95c2424             fstp dword ptr [esp + 0x24]
// 0068b095  33ed                 xor ebp, ebp
// 0068b097  39ac24f02e0000       cmp dword ptr [esp + 0x2ef0], ebp
// 0068b09e  896c2414             mov dword ptr [esp + 0x14], ebp
// 0068b0a2  7f30                 jg 0x68b0d4
// 0068b0a4  ddd8                 fstp st(0)
// 0068b0a6  8b442410             mov eax, dword ptr [esp + 0x10]
// 0068b0aa  40                   inc eax
// 0068b0ab  3b8424f42e0000       cmp eax, dword ptr [esp + 0x2ef4]
// 0068b0b2  89442410             mov dword ptr [esp + 0x10], eax
// 0068b0b6  7ea8                 jle 0x68b060
// 0068b0b8  8b06                 mov eax, dword ptr [esi]
// 0068b0ba  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 0068b0c0  8bce                 mov ecx, esi
// 0068b0c2  ffd2                 call edx
// 0068b0c4  8bc6                 mov eax, esi
// 0068b0c6  5b                   pop ebx
// 0068b0c7  e9c6040000           jmp 0x68b592
// 0068b0cc  8d642400             lea esp, [esp]
// 0068b0d0  d9442440             fld dword ptr [esp + 0x40]
// 0068b0d4  d9442448             fld dword ptr [esp + 0x48]
// 0068b0d8  8b06                 mov eax, dword ptr [esi]
// 0068b0da  d84728               fadd dword ptr [edi + 0x28]
// 0068b0dd  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 0068b0e3  83ec0c               sub esp, 0xc
// 0068b0e6  8bce                 mov ecx, esi
// 0068b0e8  d95c2408             fstp dword ptr [esp + 8]
// 0068b0ec  d984ac9c050000       fld dword ptr [esp + ebp*4 + 0x59c]
// 0068b0f3  d8c9                 fmul st(1)
// 0068b0f5  d84724               fadd dword ptr [edi + 0x24]
// 0068b0f8  d95c2404             fstp dword ptr [esp + 4]
// 0068b0fc  d88cacdc010000       fmul dword ptr [esp + ebp*4 + 0x1dc]
// 0068b103  d84720               fadd dword ptr [edi + 0x20]
// 0068b106  d91c24               fstp dword ptr [esp]
// 0068b109  ffd2                 call edx
// 0068b10b  8b06                 mov eax, dword ptr [esi]
// 0068b10d  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068b113  53                   push ebx
// 0068b114  8bce                 mov ecx, esi
// 0068b116  ffd2                 call edx
// 0068b118  43                   inc ebx
// 0068b119  833f01               cmp dword ptr [edi], 1
// 0068b11c  7734                 ja 0x68b152
// 0068b11e  d9442424             fld dword ptr [esp + 0x24]
// 0068b122  8b06                 mov eax, dword ptr [esi]
// 0068b124  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 0068b12a  83ec0c               sub esp, 0xc
// 0068b12d  d95c2408             fstp dword ptr [esp + 8]
// 0068b131  8bce                 mov ecx, esi
// 0068b133  d984ac5c090000       fld dword ptr [esp + ebp*4 + 0x95c]
// 0068b13a  d9442434             fld dword ptr [esp + 0x34]
// 0068b13e  dcc9                 fmul st(1), st(0)
// 0068b140  d9c9                 fxch st(1)
// 0068b142  d95c2404             fstp dword ptr [esp + 4]
// 0068b146  d88cac1c0d0000       fmul dword ptr [esp + ebp*4 + 0xd1c]
// 0068b14d  d91c24               fstp dword ptr [esp]
// 0068b150  ffd2                 call edx
// 0068b152  807f0400             cmp byte ptr [edi + 4], 0
// 0068b156  7436                 je 0x68b18e
// 0068b158  db442410             fild dword ptr [esp + 0x10]
// 0068b15c  83ec08               sub esp, 8
// 0068b15f  8b06                 mov eax, dword ptr [esi]
// 0068b161  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 0068b167  dab424fc2e0000       fidiv dword ptr [esp + 0x2efc]
// 0068b16e  8bce                 mov ecx, esi
// 0068b170  d9e8                 fld1 
// 0068b172  d9c0                 fld st(0)
// 0068b174  dee2                 fsubrp st(2)
// 0068b176  d9c9                 fxch st(1)
// 0068b178  d95c2404             fstp dword ptr [esp + 4]
// 0068b17c  db44241c             fild dword ptr [esp + 0x1c]
// 0068b180  dab424f82e0000       fidiv dword ptr [esp + 0x2ef8]
// 0068b187  dee9                 fsubp st(1)
// 0068b189  d91c24               fstp dword ptr [esp]
// 0068b18c  ffd2                 call edx
// 0068b18e  45                   inc ebp
// 0068b18f  3bac24f02e0000       cmp ebp, dword ptr [esp + 0x2ef0]
// 0068b196  896c2414             mov dword ptr [esp + 0x14], ebp
// 0068b19a  0f8c30ffffff         jl 0x68b0d0
// 0068b1a0  e901ffffff           jmp 0x68b0a6
// 0068b1a5  b801000000           mov eax, 1
// 0068b1aa  3bd0                 cmp edx, eax
// 0068b1ac  89442410             mov dword ptr [esp + 0x10], eax
// 0068b1b0  0f8ee3010000         jle 0x68b399
// 0068b1b6  eb08                 jmp 0x68b1c0
// 0068b1b8  8da42400000000       lea esp, [esp]
// 0068b1bf  90                   nop 
// 0068b1c0  833f01               cmp dword ptr [edi], 1
// 0068b1c3  d98484d0100000       fld dword ptr [esp + eax*4 + 0x10d0]
// 0068b1ca  d95c2440             fstp dword ptr [esp + 0x40]
// 0068b1ce  d98484101c0000       fld dword ptr [esp + eax*4 + 0x1c10]
// 0068b1d5  d95c2448             fstp dword ptr [esp + 0x48]
// 0068b1d9  7716                 ja 0x68b1f1
// 0068b1db  d9848450180000       fld dword ptr [esp + eax*4 + 0x1850]
// 0068b1e2  d95c2428             fstp dword ptr [esp + 0x28]
// 0068b1e6  d9848490140000       fld dword ptr [esp + eax*4 + 0x1490]
// 0068b1ed  d95c2424             fstp dword ptr [esp + 0x24]
// 0068b1f1  6816b78000           push 0x80b716
// 0068b1f6  8d8c2448010000       lea ecx, [esp + 0x148]
// 0068b1fd  ff1558248000         call dword ptr [0x802458]
// 0068b203  8b06                 mov eax, dword ptr [esi]
// 0068b205  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 0068b20b  6a03                 push 3
// 0068b20d  8d8c2448010000       lea ecx, [esp + 0x148]
// 0068b214  51                   push ecx
// 0068b215  8bce                 mov ecx, esi
// 0068b217  c78424e02e000008000000 mov dword ptr [esp + 0x2ee0], 8
// 0068b222  ffd2                 call edx
// 0068b224  8d8c2444010000       lea ecx, [esp + 0x144]
// 0068b22b  c78424d82e0000ffffffff mov dword ptr [esp + 0x2ed8], 0xffffffff
// 0068b236  ff1568248000         call dword ptr [0x802468]
// 0068b23c  d9ee                 fldz 
// 0068b23e  d85f10               fcomp dword ptr [edi + 0x10]
// 0068b241  8d4f10               lea ecx, [edi + 0x10]
// 0068b244  33db                 xor ebx, ebx
// 0068b246  dfe0                 fnstsw ax
// 0068b248  f6c441               test ah, 0x41
// 0068b24b  7a0d                 jp 0x68b25a
// 0068b24d  8b06                 mov eax, dword ptr [esi]
// 0068b24f  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 0068b255  51                   push ecx
// 0068b256  8bce                 mov ecx, esi
// 0068b258  ffd2                 call edx
// 0068b25a  33ed                 xor ebp, ebp
// 0068b25c  39ac24f02e0000       cmp dword ptr [esp + 0x2ef0], ebp
// 0068b263  896c2414             mov dword ptr [esp + 0x14], ebp
// 0068b267  0f8c03010000         jl 0x68b370
// 0068b26d  8d4900               lea ecx, [ecx]
// 0068b270  d9442448             fld dword ptr [esp + 0x48]
// 0068b274  8b06                 mov eax, dword ptr [esi]
// 0068b276  d84728               fadd dword ptr [edi + 0x28]
// 0068b279  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 0068b27f  83ec0c               sub esp, 0xc
// 0068b282  8bce                 mov ecx, esi
// 0068b284  d95c2408             fstp dword ptr [esp + 8]
// 0068b288  d984ac9c050000       fld dword ptr [esp + ebp*4 + 0x59c]
// 0068b28f  d944244c             fld dword ptr [esp + 0x4c]
// 0068b293  dcc9                 fmul st(1), st(0)
// 0068b295  d9c9                 fxch st(1)
// 0068b297  d84724               fadd dword ptr [edi + 0x24]
// 0068b29a  d95c2404             fstp dword ptr [esp + 4]
// 0068b29e  d88cacdc010000       fmul dword ptr [esp + ebp*4 + 0x1dc]
// 0068b2a5  d84720               fadd dword ptr [edi + 0x20]
// 0068b2a8  d91c24               fstp dword ptr [esp]
// 0068b2ab  ffd2                 call edx
// 0068b2ad  8b06                 mov eax, dword ptr [esi]
// 0068b2af  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068b2b5  53                   push ebx
// 0068b2b6  8bce                 mov ecx, esi
// 0068b2b8  ffd2                 call edx
// 0068b2ba  8b07                 mov eax, dword ptr [edi]
// 0068b2bc  43                   inc ebx
// 0068b2bd  83e800               sub eax, 0
// 0068b2c0  742c                 je 0x68b2ee
// 0068b2c2  83e801               sub eax, 1
// 0068b2c5  755b                 jne 0x68b322
// 0068b2c7  d9442424             fld dword ptr [esp + 0x24]
// 0068b2cb  83ec0c               sub esp, 0xc
// 0068b2ce  d95c2408             fstp dword ptr [esp + 8]
// 0068b2d2  d984ac9c230000       fld dword ptr [esp + ebp*4 + 0x239c]
// 0068b2d9  d9442434             fld dword ptr [esp + 0x34]
// 0068b2dd  dcc9                 fmul st(1), st(0)
// 0068b2df  d9c9                 fxch st(1)
// 0068b2e1  d95c2404             fstp dword ptr [esp + 4]
// 0068b2e5  d88cacdc1f0000       fmul dword ptr [esp + ebp*4 + 0x1fdc]
// 0068b2ec  eb25                 jmp 0x68b313
// 0068b2ee  d9442424             fld dword ptr [esp + 0x24]
// 0068b2f2  83ec0c               sub esp, 0xc
// 0068b2f5  d95c2408             fstp dword ptr [esp + 8]
// 0068b2f9  d984ac5c090000       fld dword ptr [esp + ebp*4 + 0x95c]
// 0068b300  d9442434             fld dword ptr [esp + 0x34]
// 0068b304  dcc9                 fmul st(1), st(0)
// 0068b306  d9c9                 fxch st(1)
// 0068b308  d95c2404             fstp dword ptr [esp + 4]
// 0068b30c  d88cac1c0d0000       fmul dword ptr [esp + ebp*4 + 0xd1c]
// 0068b313  8b06                 mov eax, dword ptr [esi]
// 0068b315  d91c24               fstp dword ptr [esp]
// 0068b318  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 0068b31e  8bce                 mov ecx, esi
// 0068b320  ffd2                 call edx
// 0068b322  807f0400             cmp byte ptr [edi + 4], 0
// 0068b326  7436                 je 0x68b35e
// 0068b328  db442410             fild dword ptr [esp + 0x10]
// 0068b32c  83ec08               sub esp, 8
// 0068b32f  8b06                 mov eax, dword ptr [esi]
// 0068b331  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 0068b337  dab424fc2e0000       fidiv dword ptr [esp + 0x2efc]
// 0068b33e  8bce                 mov ecx, esi
// 0068b340  d9e8                 fld1 
// 0068b342  d9c0                 fld st(0)
// 0068b344  dee2                 fsubrp st(2)
// 0068b346  d9c9                 fxch st(1)
// 0068b348  d95c2404             fstp dword ptr [esp + 4]
// 0068b34c  db44241c             fild dword ptr [esp + 0x1c]
// 0068b350  dab424f82e0000       fidiv dword ptr [esp + 0x2ef8]
// 0068b357  dee9                 fsubp st(1)
// 0068b359  d91c24               fstp dword ptr [esp]
// 0068b35c  ffd2                 call edx
// 0068b35e  45                   inc ebp
// 0068b35f  3bac24f02e0000       cmp ebp, dword ptr [esp + 0x2ef0]
// 0068b366  896c2414             mov dword ptr [esp + 0x14], ebp
// 0068b36a  0f8e00ffffff         jle 0x68b270
// 0068b370  8b06                 mov eax, dword ptr [esi]
// 0068b372  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 0068b378  8bce                 mov ecx, esi
// 0068b37a  ffd2                 call edx
// 0068b37c  8b442410             mov eax, dword ptr [esp + 0x10]
// 0068b380  40                   inc eax
// 0068b381  3b8424f42e0000       cmp eax, dword ptr [esp + 0x2ef4]
// 0068b388  89442410             mov dword ptr [esp + 0x10], eax
// 0068b38c  0f8c2efeffff         jl 0x68b1c0
// 0068b392  8b8c24f02e0000       mov ecx, dword ptr [esp + 0x2ef0]
// 0068b399  33c0                 xor eax, eax
// 0068b39b  89442414             mov dword ptr [esp + 0x14], eax
// 0068b39f  85c9                 test ecx, ecx
// 0068b3a1  0f8ee0010000         jle 0x68b587
// 0068b3a7  eb07                 jmp 0x68b3b0
// 0068b3a9  8da42400000000       lea esp, [esp]
// 0068b3b0  833f01               cmp dword ptr [edi], 1
// 0068b3b3  d98484d0010000       fld dword ptr [esp + eax*4 + 0x1d0]
// 0068b3ba  d95c2440             fstp dword ptr [esp + 0x40]
// 0068b3be  d9848490050000       fld dword ptr [esp + eax*4 + 0x590]
// 0068b3c5  d95c2448             fstp dword ptr [esp + 0x48]
// 0068b3c9  7716                 ja 0x68b3e1
// 0068b3cb  d98484100d0000       fld dword ptr [esp + eax*4 + 0xd10]
// 0068b3d2  d95c2428             fstp dword ptr [esp + 0x28]
// 0068b3d6  d9848450090000       fld dword ptr [esp + eax*4 + 0x950]
// 0068b3dd  d95c2424             fstp dword ptr [esp + 0x24]
// 0068b3e1  6816b78000           push 0x80b716
// 0068b3e6  8d8c2480010000       lea ecx, [esp + 0x180]
// 0068b3ed  ff1558248000         call dword ptr [0x802458]
// 0068b3f3  8b06                 mov eax, dword ptr [esi]
// 0068b3f5  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 0068b3fb  6a03                 push 3
// 0068b3fd  8d8c2480010000       lea ecx, [esp + 0x180]
// 0068b404  51                   push ecx
// 0068b405  8bce                 mov ecx, esi
// 0068b407  c78424e02e000009000000 mov dword ptr [esp + 0x2ee0], 9
// 0068b412  ffd2                 call edx
// 0068b414  8d8c247c010000       lea ecx, [esp + 0x17c]
// 0068b41b  c78424d82e0000ffffffff mov dword ptr [esp + 0x2ed8], 0xffffffff
// 0068b426  ff1568248000         call dword ptr [0x802468]
// 0068b42c  d9ee                 fldz 
// 0068b42e  d85f10               fcomp dword ptr [edi + 0x10]
// 0068b431  8d4f10               lea ecx, [edi + 0x10]
// 0068b434  33db                 xor ebx, ebx
// 0068b436  dfe0                 fnstsw ax
// 0068b438  f6c441               test ah, 0x41
// 0068b43b  7a0d                 jp 0x68b44a
// 0068b43d  8b06                 mov eax, dword ptr [esi]
// 0068b43f  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 0068b445  51                   push ecx
// 0068b446  8bce                 mov ecx, esi
// 0068b448  ffd2                 call edx
// 0068b44a  33ed                 xor ebp, ebp
// 0068b44c  39ac24f42e0000       cmp dword ptr [esp + 0x2ef4], ebp
// 0068b453  896c2410             mov dword ptr [esp + 0x10], ebp
// 0068b457  0f8c08010000         jl 0x68b565
// 0068b45d  8d4900               lea ecx, [ecx]
// 0068b460  d984ac101c0000       fld dword ptr [esp + ebp*4 + 0x1c10]
// 0068b467  8b06                 mov eax, dword ptr [esi]
// 0068b469  d84728               fadd dword ptr [edi + 0x28]
// 0068b46c  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 0068b472  83ec0c               sub esp, 0xc
// 0068b475  8bce                 mov ecx, esi
// 0068b477  d95c2408             fstp dword ptr [esp + 8]
// 0068b47b  d9442454             fld dword ptr [esp + 0x54]
// 0068b47f  d88cacdc100000       fmul dword ptr [esp + ebp*4 + 0x10dc]
// 0068b486  d84724               fadd dword ptr [edi + 0x24]
// 0068b489  d95c2404             fstp dword ptr [esp + 4]
// 0068b48d  d984acdc100000       fld dword ptr [esp + ebp*4 + 0x10dc]
// 0068b494  d84c244c             fmul dword ptr [esp + 0x4c]
// 0068b498  d84720               fadd dword ptr [edi + 0x20]
// 0068b49b  d91c24               fstp dword ptr [esp]
// 0068b49e  ffd2                 call edx
// 0068b4a0  8b06                 mov eax, dword ptr [esi]
// 0068b4a2  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068b4a8  53                   push ebx
// 0068b4a9  8bce                 mov ecx, esi
// 0068b4ab  ffd2                 call edx
// 0068b4ad  8b07                 mov eax, dword ptr [edi]
// 0068b4af  43                   inc ebx
// 0068b4b0  83e800               sub eax, 0
// 0068b4b3  742b                 je 0x68b4e0
// 0068b4b5  83e801               sub eax, 1
// 0068b4b8  755d                 jne 0x68b517
// 0068b4ba  d984ac102b0000       fld dword ptr [esp + ebp*4 + 0x2b10]
// 0068b4c1  83ec0c               sub esp, 0xc
// 0068b4c4  d95c2408             fstp dword ptr [esp + 8]
// 0068b4c8  d984ac5c270000       fld dword ptr [esp + ebp*4 + 0x275c]
// 0068b4cf  d84c2430             fmul dword ptr [esp + 0x30]
// 0068b4d3  d95c2404             fstp dword ptr [esp + 4]
// 0068b4d7  d984ac5c270000       fld dword ptr [esp + ebp*4 + 0x275c]
// 0068b4de  eb24                 jmp 0x68b504
// 0068b4e0  d984ac90140000       fld dword ptr [esp + ebp*4 + 0x1490]
// 0068b4e7  83ec0c               sub esp, 0xc
// 0068b4ea  d95c2408             fstp dword ptr [esp + 8]
// 0068b4ee  d984ac5c180000       fld dword ptr [esp + ebp*4 + 0x185c]
// 0068b4f5  d84c2430             fmul dword ptr [esp + 0x30]
// 0068b4f9  d95c2404             fstp dword ptr [esp + 4]
// 0068b4fd  d984ac5c180000       fld dword ptr [esp + ebp*4 + 0x185c]
// 0068b504  d84c2434             fmul dword ptr [esp + 0x34]
// 0068b508  8b06                 mov eax, dword ptr [esi]
// 0068b50a  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 0068b510  8bce                 mov ecx, esi
// 0068b512  d91c24               fstp dword ptr [esp]
// 0068b515  ffd2                 call edx
// 0068b517  807f0400             cmp byte ptr [edi + 4], 0
// 0068b51b  7436                 je 0x68b553
// 0068b51d  db442410             fild dword ptr [esp + 0x10]
// 0068b521  83ec08               sub esp, 8
// 0068b524  8b06                 mov eax, dword ptr [esi]
// 0068b526  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 0068b52c  dab424fc2e0000       fidiv dword ptr [esp + 0x2efc]
// 0068b533  8bce                 mov ecx, esi
// 0068b535  d9e8                 fld1 
// 0068b537  d9c0                 fld st(0)
// 0068b539  dee2                 fsubrp st(2)
// 0068b53b  d9c9                 fxch st(1)
// 0068b53d  d95c2404             fstp dword ptr [esp + 4]
// 0068b541  db44241c             fild dword ptr [esp + 0x1c]
// 0068b545  dab424f82e0000       fidiv dword ptr [esp + 0x2ef8]
// 0068b54c  dee9                 fsubp st(1)
// 0068b54e  d91c24               fstp dword ptr [esp]
// 0068b551  ffd2                 call edx
// 0068b553  45                   inc ebp
// 0068b554  3bac24f42e0000       cmp ebp, dword ptr [esp + 0x2ef4]
// 0068b55b  896c2410             mov dword ptr [esp + 0x10], ebp
// 0068b55f  0f8efbfeffff         jle 0x68b460
// 0068b565  8b06                 mov eax, dword ptr [esi]
// 0068b567  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 0068b56d  8bce                 mov ecx, esi
// 0068b56f  ffd2                 call edx
// 0068b571  8b442414             mov eax, dword ptr [esp + 0x14]
// 0068b575  40                   inc eax
// 0068b576  3b8424f02e0000       cmp eax, dword ptr [esp + 0x2ef0]
// 0068b57d  89442414             mov dword ptr [esp + 0x14], eax
// 0068b581  0f8c29feffff         jl 0x68b3b0
// 0068b587  8bc6                 mov eax, esi
// 0068b589  5b                   pop ebx
// 0068b58a  eb06                 jmp 0x68b592
// 0068b58c  ddd9                 fstp st(1)
// 0068b58e  ddd8                 fstp st(0)
// 0068b590  33c0                 xor eax, eax
// 0068b592  8b8c24cc2e0000       mov ecx, dword ptr [esp + 0x2ecc]
// 0068b599  5f                   pop edi
// 0068b59a  5e                   pop esi
// 0068b59b  5d                   pop ebp
// 0068b59c  64890d00000000       mov dword ptr fs:[0], ecx
// 0068b5a3  81c4cc2e0000         add esp, 0x2ecc
// 0068b5a9  c21800               ret 0x18
// 0068b5ac  e1af                 loope 0x68b55d
// 0068b5ae  6800a5b168           push 0x68b1a500
// 0068b5b3  00d8                 add al, bl
// 0068b5b5  95                   xchg ebp, eax
// 0068b5b6  6800a5b168           push 0x68b1a500

// from server: 93% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// Genuine Ogre 1.4.5 consumer interfaces, reduced to the virtual declarations
// used to establish primary vtable dispatch. Existing pointers only; no object
// of these interface views is constructed and no whole-owner size is claimed.
#include <string>
#include <vector>
#include <cmath>
#include <stddef.h>
namespace Ogre {
typedef float Real;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long ulong;
typedef std::string String;
class Light; class EdgeData; class AxisAlignedBox; class Vector2; class Vector4;
class SceneManager; class ManualObject; class Camera; class Node; class SceneNode;
class RenderQueue; class UserDefinedObject; class MovableObjectFactory; class Any;
class Matrix4; class Sphere; class ShadowRenderable; class HardwareIndexBufferSharedPtr;
class HardwareVertexBufferSharedPtr; class AnimableValue; class Entity;
class RenderQueueGroup; class Pass; class Renderable; class RenderablePass;
class Viewport; class RenderQueueInvocationSequence; class ShadowCaster;
template<class T> class SharedPtr;
template<class T> class VectorIterator;
typedef SharedPtr<AnimableValue> AnimableValuePtr;
typedef std::vector<String> StringVector;
typedef std::vector<Light*> LightList;
enum ShadowTechnique
    {
        SHADOWTYPE_NONE = 0x00,
		SHADOWDETAILTYPE_ADDITIVE = 0x01,
		SHADOWDETAILTYPE_MODULATIVE = 0x02,
		SHADOWDETAILTYPE_INTEGRATED = 0x04,
		SHADOWDETAILTYPE_STENCIL = 0x10,
		SHADOWDETAILTYPE_TEXTURE = 0x20,
        SHADOWTYPE_STENCIL_MODULATIVE = 0x12,
        SHADOWTYPE_STENCIL_ADDITIVE = 0x11,
        SHADOWTYPE_TEXTURE_MODULATIVE = 0x22,
        SHADOWTYPE_TEXTURE_ADDITIVE = 0x21,
		SHADOWTYPE_TEXTURE_ADDITIVE_INTEGRATED = 0x25,
		SHADOWTYPE_TEXTURE_MODULATIVE_INTEGRATED = 0x26
    };
class QueuedRenderableCollection {public:enum OrganisationMode
		{
			OM_PASS_GROUP = 1,
			OM_SORT_DESCENDING = 2,
			OM_SORT_ASCENDING = 6
		};};
class __declspec(dllimport) Math { public: static const Real PI; };
class __declspec(dllimport) Vector3 {
public: Real x,y,z;
inline Vector3() {}
inline Vector3(const Real fX,const Real fY,const Real fZ):x(fX),y(fY),z(fZ){}
inline Vector3(const Vector3& rkVector):x(rkVector.x),y(rkVector.y),z(rkVector.z){}
inline Vector3& operator=(const Vector3& rkVector){x=rkVector.x;y=rkVector.y;z=rkVector.z;return *this;}
};
class __declspec(dllimport) ColourValue {public:float r,g,b,a;};
class RenderOperation {public:enum OperationType {
            OT_POINT_LIST = 1,
            OT_LINE_LIST = 2,
            OT_LINE_STRIP = 3,
            OT_TRIANGLE_LIST = 4,
            OT_TRIANGLE_STRIP = 5,
            OT_TRIANGLE_FAN = 6
        };};
class __declspec(dllimport) ShadowCaster {public:
typedef std::vector<ShadowRenderable*> ShadowRenderableList;
typedef VectorIterator<ShadowRenderableList> ShadowRenderableListIterator;
virtual ~ShadowCaster();
virtual bool getCastShadows(void) const = 0;
virtual EdgeData* getEdgeList(void) = 0;
virtual bool hasEdgeList(void) = 0;
virtual const AxisAlignedBox& getWorldBoundingBox(bool derive = false) const = 0;
virtual const AxisAlignedBox& getLightCapBounds(void) const = 0;
virtual const AxisAlignedBox& getDarkCapBounds(const Light& light, Real dirLightExtrusionDist) const = 0;
virtual ShadowRenderableListIterator getShadowVolumeRenderableIterator(
            ShadowTechnique shadowTechnique, const Light* light, 
            HardwareIndexBufferSharedPtr* indexBuffer, 
            bool extrudeVertices, Real extrusionDistance, unsigned long flags = 0 ) = 0;
virtual Real getPointExtrusionDistance(const Light* l) const = 0;
virtual void updateEdgeListLightFacing(EdgeData* edgeData, 
            const Vector4& lightPos);
virtual void generateShadowVolume(EdgeData* edgeData, 
            const HardwareIndexBufferSharedPtr& indexBuffer, const Light* light,
            ShadowRenderableList& shadowRenderables, unsigned long flags);
virtual void extrudeBounds(AxisAlignedBox& box, const Vector4& lightPos, 
            Real extrudeDist) const;
};
class __declspec(dllimport) AnimableObject {public:
virtual const String& getAnimableDictionaryName(void) const;
virtual void initialiseAnimableDictionary(StringVector&) const;
virtual ~AnimableObject();
virtual AnimableValuePtr createAnimableValue(const String& valueName);
};
class __declspec(dllimport) MovableObject : public ShadowCaster,public AnimableObject {public:
class Listener;
virtual ~MovableObject();
virtual void _notifyCreator(MovableObjectFactory* fact);
virtual MovableObjectFactory*  _getCreator(void) const;
virtual void _notifyManager(SceneManager* man);
virtual SceneManager* _getManager(void) const;
virtual const String& getName(void) const;
virtual const String& getMovableType(void) const = 0;
virtual Node* getParentNode(void) const;
virtual SceneNode* getParentSceneNode(void) const;
virtual void _notifyAttached(Node* parent, bool isTagPoint = false);
virtual bool isAttached(void) const;
virtual bool isInScene(void) const;
virtual void _notifyMoved(void);
virtual void _notifyCurrentCamera(Camera* cam);
virtual const AxisAlignedBox& getBoundingBox(void) const = 0;
virtual Real getBoundingRadius(void) const = 0;
virtual const AxisAlignedBox& getWorldBoundingBox(bool derive = false) const;
virtual const Sphere& getWorldBoundingSphere(bool derive = false) const;
virtual void _updateRenderQueue(RenderQueue* queue) = 0;
virtual void setVisible(bool visible);
virtual bool getVisible(void) const;
virtual bool isVisible(void) const;
virtual void setRenderingDistance(Real dist);
virtual Real getRenderingDistance(void) const;
virtual void setUserObject(UserDefinedObject* obj);
virtual UserDefinedObject* getUserObject(void);
virtual void setUserAny(const Any& anything);
virtual const Any& getUserAny(void) const;
virtual void setRenderQueueGroup(uint8 queueID);
virtual uint8 getRenderQueueGroup(void) const;
virtual const Matrix4& _getParentNodeFullTransform(void) const;
virtual void setQueryFlags(uint32 flags);
virtual void addQueryFlags(uint32 flags);
virtual void removeQueryFlags(unsigned long flags);
virtual uint32 getQueryFlags(void) const;
virtual void setVisibilityFlags(uint32 flags);
virtual void addVisibilityFlags(uint32 flags);
virtual void removeVisibilityFlags(uint32 flags);
virtual uint32 getVisibilityFlags(void) const;
virtual void setListener(Listener* listener);
virtual Listener* getListener(void) const;
virtual const LightList& queryLights(void) const;
virtual uint32 getTypeFlags(void) const;
};
class __declspec(dllimport) SceneManager {public:
typedef std::vector<ShadowCaster*> ShadowCasterList;
enum PrefabType {PT_PLANE,PT_CUBE,PT_SPHERE};
virtual void initRenderQueue(void);
virtual void setViewport(Viewport *vp);
virtual void renderVisibleObjectsDefaultSequence(void);
virtual void renderVisibleObjectsCustomSequence(RenderQueueInvocationSequence* s);
virtual void prepareRenderQueue(void);
virtual void renderSingleObject(const Renderable* rend, const Pass* pass, 
			bool doLightIteration, const LightList* manualLightList = 0);
virtual void findLightsAffectingFrustum(const Camera* camera);
virtual void initShadowVolumeMaterials(void);
virtual void ensureShadowTexturesCreated();
virtual void destroyShadowTextures(void);
virtual void prepareShadowTextures(Camera* cam, Viewport* vp);
virtual void renderShadowVolumesToStencil(const Light* light, const Camera* cam);
virtual void setShadowVolumeStencilState(bool secondpass, bool zfail, bool twosided);
virtual const ShadowCasterList& findShadowCastersForLight(const Light* light, 
            const Camera* camera);
virtual void renderBasicQueueGroupObjects(RenderQueueGroup* pGroup, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderAdditiveStencilShadowedQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderModulativeStencilShadowedQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderTextureShadowCasterQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderTextureShadowReceiverQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderModulativeTextureShadowedQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderAdditiveTextureShadowedQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderObjects(const QueuedRenderableCollection& objs, 
			QueuedRenderableCollection::OrganisationMode om, 
            bool doLightIteration, const LightList* manualLightList = 0);
virtual void renderTransparentShadowCasterObjects(const QueuedRenderableCollection& objs, 
			QueuedRenderableCollection::OrganisationMode om, 
			bool doLightIteration, const LightList* manualLightList = 0);
virtual void updateRenderQueueSplitOptions(void);
virtual void updateRenderQueueGroupSplitOptions(RenderQueueGroup* group, 
			bool suppressShadows, bool suppressRenderState);
virtual ~SceneManager();
virtual const String& getTypeName(void) const = 0;
virtual Camera* createCamera(const String& name);
virtual Camera* getCamera(const String& name) const;
virtual bool hasCamera(const String& name) const;
virtual void destroyCamera(Camera *cam);
virtual void destroyCamera(const String& name);
virtual void destroyAllCameras(void);
virtual Light* createLight(const String& name);
virtual Light* getLight(const String& name) const;
virtual bool hasLight(const String& name) const;
virtual void destroyLight(const String& name);
virtual void destroyLight(Light* light);
virtual void destroyAllLights(void);
virtual void _notifyLightsDirty(void);
virtual const LightList& _getLightsAffectingFrustum(void) const;
virtual void _populateLightList(const Vector3& position, Real radius, LightList& destList);
virtual SceneNode* createSceneNode(void);
virtual SceneNode* createSceneNode(const String& name);
virtual void destroySceneNode(const String& name);
virtual SceneNode* getRootSceneNode(void) const;
virtual SceneNode* getSceneNode(const String& name) const;
virtual bool hasSceneNode(const String& name) const;
virtual Entity* createEntity(const String& entityName, const String& meshName);
virtual Entity* createEntity(const String& entityName, PrefabType ptype);
virtual Entity* getEntity(const String& name) const;
virtual bool hasEntity(const String& name) const;
virtual void destroyEntity(Entity* ent);
virtual void destroyEntity(const String& name);
virtual void destroyAllEntities(void);
virtual ManualObject* createManualObject(const String& name);
};
class __declspec(dllimport) ManualObject : public MovableObject {public:
class ManualObjectSection;
virtual ~ManualObject();
virtual void clear(void);
virtual void estimateVertexCount(size_t vcount);
virtual void estimateIndexCount(size_t icount);
virtual void begin(const String& materialName, 
			RenderOperation::OperationType opType = RenderOperation::OT_TRIANGLE_LIST);
virtual void setDynamic(bool dyn);
virtual bool getDynamic() const;
virtual void beginUpdate(size_t sectionIndex);
virtual void position(const Vector3& pos);
virtual void position(Real x, Real y, Real z);
virtual void normal(const Vector3& norm);
virtual void normal(Real x, Real y, Real z);
virtual void textureCoord(Real u);
virtual void textureCoord(Real u, Real v);
virtual void textureCoord(Real u, Real v, Real w);
virtual void textureCoord(const Vector2& uv);
virtual void textureCoord(const Vector3& uvw);
virtual void colour(const ColourValue& col);
virtual void colour(Real r, Real g, Real b, Real a = 1.0f);
virtual void index(uint16 idx);
virtual void triangle(uint16 i1, uint16 i2, uint16 i3);
virtual void quad(uint16 i1, uint16 i2, uint16 i3, uint16 i4);
virtual ManualObjectSection* end(void);
};
}
namespace Ogre {
// Existing receiver view: every field below is accessed by the native body.
class AdornQuadric {
public:
enum NormalStyle {Smooth=0,Flat=1,None=2};
enum Orientation {Outside=0,Inside=1};
enum DrawStyle {Point=0,Line=1,Fill=2,Silhouette=3};
NormalStyle normals;
bool textureCoords;
Orientation orientation;
DrawStyle drawStyle;
ColourValue colour;
Vector3 offset;
ManualObject* sphere(SceneManager*,const String&,ManualObject*,float,int,int);
};
ManualObject* AdornQuadric::sphere(SceneManager* manager,const String& name,ManualObject* object,float radius,int slices,int stacks){
const Ogre::Vector3& off=offset;
if(!object)object=manager->createManualObject(name);
unsigned int index=0;

    int i,j;
    float sinCache1a[240];
    float cosCache1a[240];
    float sinCache2a[240];
    float cosCache2a[240];
    float sinCache3a[240];
    float cosCache3a[240];
    float sinCache1b[240];
    float cosCache1b[240];
    float sinCache2b[240];
    float cosCache2b[240];
    float sinCache3b[240];
    float cosCache3b[240];
    float angle;
    float zLow, zHigh;
    float sintemp1, sintemp2, sintemp3 = 0.0, sintemp4 = 0.0;
    float costemp1, costemp2 = 0.0, costemp3 = 0.0, costemp4 = 0.0;
    bool needCache2, needCache3;
    int start, finish;

    if (slices >= 240) slices = 240-1;
    if (stacks >= 240) stacks = 240-1;
    if (slices < 2 || stacks < 1 || radius < 0.0) {
	
	return 0;
    }

    
    
    
    needCache2 = needCache3 = false;

    if (normals == Smooth) {
	needCache2 = true;
    }

    if (normals == Flat) {
	if (drawStyle != Point) {
	    needCache3 = true;
	}
	if (drawStyle == Line) {
	    needCache2 = true;
	}
    }

    for (i = 0; i < slices; i++) {
	angle = 2 * Ogre::Math::PI * i / slices;
	sinCache1a[i] = sin(angle);
	cosCache1a[i] = cos(angle);
	if (needCache2) {
	    sinCache2a[i] = sinCache1a[i];
	    cosCache2a[i] = cosCache1a[i];
	}
    }

    for (j = 0; j <= stacks; j++) {
	angle = Ogre::Math::PI * j / stacks;
	if (needCache2) {
	    if (orientation == Outside) {
		sinCache2b[j] = sin(angle);
		cosCache2b[j] = cos(angle);
	    } else {
		sinCache2b[j] = -sin(angle);
		cosCache2b[j] = -cos(angle);
	    }
	}
	sinCache1b[j] = radius * sin(angle);
	cosCache1b[j] = radius * cos(angle);
    }
    
    sinCache1b[0] = 0;
    sinCache1b[stacks] = 0;

    if (needCache3) {
	for (i = 0; i < slices; i++) {
	    angle = 2 * Ogre::Math::PI * (i-0.5) / slices;
	    sinCache3a[i] = sin(angle);
	    cosCache3a[i] = cos(angle);
	}
	for (j = 0; j <= stacks; j++) {
	    angle = Ogre::Math::PI * (j - 0.5) / stacks;
	    if (orientation == Outside) {
		sinCache3b[j] = sin(angle);
		cosCache3b[j] = cos(angle);
	    } else {
		sinCache3b[j] = -sin(angle);
		cosCache3b[j] = -cos(angle);
	    }
	}
    }

    sinCache1a[slices] = sinCache1a[0];
    cosCache1a[slices] = cosCache1a[0];
    if (needCache2) {
	sinCache2a[slices] = sinCache2a[0];
	cosCache2a[slices] = cosCache2a[0];
    }
    if (needCache3) {
	sinCache3a[slices] = sinCache3a[0];
	cosCache3a[slices] = cosCache3a[0];
    }

    switch(drawStyle){case Fill:if (!textureCoords) {start=1;finish=stacks-1;
object->begin("", Ogre::RenderOperation::OT_TRIANGLE_FAN);
if (colour.r >= 0.0f) object->colour(colour);
index=0;
object->position(0.0 + off.x, 0.0 + off.y, radius + off.z);
object->index(index++);
switch(normals) {
	      case Flat:
		sintemp3 = sinCache3b[1];
		costemp3 = cosCache3b[1];
		break;
	      case Smooth:
		sintemp3 = sinCache2b[1];
		costemp3 = cosCache2b[1];
		object->normal(sinCache2a[0] * sinCache2b[0],
			cosCache2a[0] * sinCache2b[0],
			cosCache2b[0]);
		break;
	      default:
		break;
	    }
sintemp2 = sinCache1b[1];
	    zHigh = cosCache1b[1];
	    
	    if (orientation == Outside) {
		for (i = slices; i >= 0; i--) {
		    object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
switch(normals) {
		      case Smooth:
			object->normal(sinCache2a[i] * sintemp3,
				cosCache2a[i] * sintemp3,
				costemp3);
			break;
		      case Flat:
			if (i != slices) {
			    object->normal(sinCache3a[i+1] * sintemp3,
				    cosCache3a[i+1] * sintemp3,
				    costemp3);
			}
			break;
		      case None:
		      default:
			break;
		    }
		    
		}
	    } else {
		for (i = 0; i <= slices; i++) {
		    object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
switch(normals) {
		      case Smooth:
			object->normal(sinCache2a[i] * sintemp3,
				cosCache2a[i] * sintemp3,
				costemp3);
			break;
		      case Flat:
			object->normal(sinCache3a[i] * sintemp3,
				cosCache3a[i] * sintemp3,
				costemp3);
			break;
		      case None:
		      default:
			break;
		    }
		    
		}
	    }
	    object->end();

	    
	    object->begin("", Ogre::RenderOperation::OT_TRIANGLE_FAN);
if (colour.r >= 0.0f) object->colour(colour);
index=0;
object->position(0.0 + off.x, 0.0 + off.y, -radius + off.z);
object->index(index++);


	    if (orientation == Outside) {sintemp2 = sinCache1b[stacks-1];
	    zHigh = cosCache1b[stacks-1];
	    switch(normals) {
	      case Flat:
		sintemp3 = sinCache3b[stacks];
		costemp3 = cosCache3b[stacks];
		break;
	      case Smooth:
		sintemp3 = sinCache2b[stacks-1];
		costemp3 = cosCache2b[stacks-1];
		object->normal(sinCache2a[stacks] * sinCache2b[stacks],
			cosCache2a[stacks] * sinCache2b[stacks],
			cosCache2b[stacks]);
		break;
	      default:
		break;
	    }
		for (i = 0; i <= slices; i++) {
		    object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
switch(normals) {
		      case Smooth:
			object->normal(sinCache2a[i] * sintemp3,
				cosCache2a[i] * sintemp3,
				costemp3);
			break;
		      case Flat:
			object->normal(sinCache3a[i] * sintemp3,
				cosCache3a[i] * sintemp3,
				costemp3);
			break;
		      case None:
		      default:
			break;
		    }
		    
		}
	    } else {
		for (i = slices; i >= 0; i--) {
		    object->position(sinCache1b[1] * sinCache1a[i] + off.x, sinCache1b[1] * cosCache1a[i] + off.y, cosCache1b[1] + off.z);
object->index(index++);
switch(normals) {
		      case Smooth:
			object->normal(sinCache2a[i] * sintemp3,
				cosCache2a[i] * sintemp3,
				costemp3);
			break;
		      case Flat:
			if (i != slices) {
			    object->normal(sinCache3a[i+1] * sintemp3,
				    cosCache3a[i+1] * sintemp3,
				    costemp3);
			}
			break;
		      case None:
		      default:
			break;
		    }
		    
		}
	    }
	    object->end();
	} else {start=0;finish=stacks;}
for (j = start; j < finish; j++) {
	    zLow = cosCache1b[j];
	    zHigh = cosCache1b[j+1];
	    sintemp1 = sinCache1b[j];
	    sintemp2 = sinCache1b[j+1];
	    switch(normals) {
	      case Flat:
		sintemp4 = sinCache3b[j+1];
		costemp4 = cosCache3b[j+1];
		break;
	      case Smooth:
		if (orientation == Outside) {
		    sintemp3 = sinCache2b[j+1];
		    costemp3 = cosCache2b[j+1];
		    sintemp4 = sinCache2b[j];
		    costemp4 = cosCache2b[j];
		} else {
		    sintemp3 = sinCache2b[j];
		    costemp3 = cosCache2b[j];
		    sintemp4 = sinCache2b[j+1];
		    costemp4 = cosCache2b[j+1];
		}
		break;
	      default:
		break;
	    }

	    std::vector<Ogre::Vector3> positions;
std::vector<Ogre::Vector3> normalsCache;
Ogre::Vector3 currentNormal;
if(j==start){object->begin("", Ogre::RenderOperation::OT_TRIANGLE_LIST);index=0;}
if(colour.r >= 0.0f)object->colour(colour);
	    for (i = 0; i <= slices; i++) {
		switch(normals) {
		  case Smooth:
		    currentNormal = Ogre::Vector3(sinCache2a[i] * sintemp3, cosCache2a[i] * sintemp3, costemp3);
		    break;
		  case Flat:
		  case None:
		  default:
		    break;
		}
		if (orientation == Outside) {
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				1 - (float) (j+1) / stacks);
		    }
		    {int count=positions.size();
if(positions.size()>=2){
if(count%2){object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));
normalsCache.push_back(currentNormal);}else{object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));
normalsCache.push_back(currentNormal);}
}else{positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));normalsCache.push_back(currentNormal);}};
		} else {
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				1 - (float) j / stacks);
		    }
		    {int count=positions.size();
if(positions.size()>=2){
if(count%2){object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));
normalsCache.push_back(currentNormal);}else{object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));
normalsCache.push_back(currentNormal);}
}else{positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));normalsCache.push_back(currentNormal);}};
		}
		switch(normals) {
		  case Smooth:
		    currentNormal = Ogre::Vector3(sinCache2a[i] * sintemp4, cosCache2a[i] * sintemp4, costemp4);
		    break;
		  case Flat:
		    currentNormal = Ogre::Vector3(sinCache3a[i] * sintemp4, cosCache3a[i] * sintemp4, costemp4);
		    break;
		  case None:
		  default:
		    break;
		}
		if (orientation == Outside) {
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				1 - (float) j / stacks);
		    }
		    {int count=positions.size();
if(positions.size()>=2){
if(count%2){object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));
normalsCache.push_back(currentNormal);}else{object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));
normalsCache.push_back(currentNormal);}
}else{positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));normalsCache.push_back(currentNormal);}};
		} else {
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				1 - (float) (j+1) / stacks);
		    }
		    {int count=positions.size();
if(positions.size()>=2){
if(count%2){object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));
normalsCache.push_back(currentNormal);}else{object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));
normalsCache.push_back(currentNormal);}
}else{positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));normalsCache.push_back(currentNormal);}};
		}
	    }
	    if(j==finish-1)object->end();
	}
	break;case Point:
	object->begin("", Ogre::RenderOperation::OT_POINT_LIST);
index=0;
if(colour.r >= 0.0f)object->colour(colour);
	for (j = 0; j <= stacks; j++) {
	    sintemp1 = sinCache1b[j];
	    costemp1 = cosCache1b[j];
	    switch(normals) {
	      case Flat:
	      case Smooth:
		sintemp2 = sinCache2b[j];
		costemp2 = cosCache2b[j];
		break;
	      default:
		break;
	    }
	    for (i = 0; i < slices; i++) {
		object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, costemp1 + off.z);
object->index(index++);
switch(normals) {
		  case Flat:
		  case Smooth:
		    object->normal(sinCache2a[i] * sintemp2,
			    cosCache2a[i] * sintemp2,
			    costemp2);
		    break;
		  case None:
		  default:
		    break;
		}

		zLow = j * radius / stacks;

		if (textureCoords) {
		    object->textureCoord(1 - (float) i / slices,
			    1 - (float) j / stacks);
		}
		
	    }
	}
	object->end();
	break;
      case Line:
      case Silhouette:
	for (j = 1; j < stacks; j++) {
	    sintemp1 = sinCache1b[j];
	    costemp1 = cosCache1b[j];
	    switch(normals) {
	      case Flat:
	      case Smooth:
		sintemp2 = sinCache2b[j];
		costemp2 = cosCache2b[j];
		break;
	      default:
		break;
	    }

	    object->begin("", Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r >= 0.0f)object->colour(colour);
	    for (i = 0; i <= slices; i++) {
		object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, costemp1 + off.z);
object->index(index++);
switch(normals) {
		  case Flat:
		    object->normal(sinCache3a[i] * sintemp2,
			    cosCache3a[i] * sintemp2,
			    costemp2);
		    break;
		  case Smooth:
		    object->normal(sinCache2a[i] * sintemp2,
			    cosCache2a[i] * sintemp2,
			    costemp2);
		    break;
		  case None:
		  default:
		    break;
		}
		if (textureCoords) {
		    object->textureCoord(1 - (float) i / slices,
			    1 - (float) j / stacks);
		}
		
	    }
	    object->end();
	}
	for (i = 0; i < slices; i++) {
	    sintemp1 = sinCache1a[i];
	    costemp1 = cosCache1a[i];
	    switch(normals) {
	      case Flat:
	      case Smooth:
		sintemp2 = sinCache2a[i];
		costemp2 = cosCache2a[i];
		break;
	      default:
		break;
	    }

	    object->begin("", Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r >= 0.0f)object->colour(colour);
	    for (j = 0; j <= stacks; j++) {
		object->position(sintemp1 * sinCache1b[j] + off.x, costemp1 * sinCache1b[j] + off.y, cosCache1b[j] + off.z);
object->index(index++);
switch(normals) {
		  case Flat:
		    object->normal(sintemp2 * sinCache3b[j],
			    costemp2 * sinCache3b[j],
			    cosCache3b[j]);
		    break;
		  case Smooth:
		    object->normal(sintemp2 * sinCache2b[j],
			    costemp2 * sinCache2b[j],
			    cosCache2b[j]);
		    break;
		  case None:
		  default:
		    break;
		}

		if (textureCoords) {
		    object->textureCoord(1 - (float) i / slices,
			    1 - (float) j / stacks);
		}
		
	    }
	    object->end();
	}
	break;
      default:
	break;
    }

return object;
}
}

// Native used values and receiver member addresses; interface owner sizes are
// deliberately unspecified because this function only uses existing pointers.
typedef char sphere_vector_size[sizeof(Ogre::Vector3)==12?1:-1];
typedef char sphere_vector_x[offsetof(Ogre::Vector3,x)==0?1:-1];
typedef char sphere_vector_y[offsetof(Ogre::Vector3,y)==4?1:-1];
typedef char sphere_vector_z[offsetof(Ogre::Vector3,z)==8?1:-1];
typedef char sphere_colour_size[sizeof(Ogre::ColourValue)==16?1:-1];
typedef char sphere_colour_r[offsetof(Ogre::ColourValue,r)==0?1:-1];
typedef char sphere_colour_g[offsetof(Ogre::ColourValue,g)==4?1:-1];
typedef char sphere_colour_b[offsetof(Ogre::ColourValue,b)==8?1:-1];
typedef char sphere_colour_a[offsetof(Ogre::ColourValue,a)==12?1:-1];
typedef char sphere_receiver_normals[offsetof(Ogre::AdornQuadric,normals)==0?1:-1];
typedef char sphere_receiver_texture[offsetof(Ogre::AdornQuadric,textureCoords)==4?1:-1];
typedef char sphere_receiver_orientation[offsetof(Ogre::AdornQuadric,orientation)==8?1:-1];
typedef char sphere_receiver_draw[offsetof(Ogre::AdornQuadric,drawStyle)==12?1:-1];
typedef char sphere_receiver_colour[offsetof(Ogre::AdornQuadric,colour)==16?1:-1];
typedef char sphere_receiver_offset[offsetof(Ogre::AdornQuadric,offset)==32?1:-1];
typedef char sphere_cache_size[sizeof(std::vector<Ogre::Vector3>)==24?1:-1];
