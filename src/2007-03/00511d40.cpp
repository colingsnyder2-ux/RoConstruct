// from server: 100% by auto
// roc 2007-03 00511d40  unit: seg_00510000  size: 3028 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00511d40
//
// 00511d40  83ec3c               sub esp, 0x3c
// 00511d43  53                   push ebx
// 00511d44  56                   push esi
// 00511d45  8b742448             mov esi, dword ptr [esp + 0x48]
// 00511d49  0fb69e26010000       movzx ebx, byte ptr [esi + 0x126]
// 00511d50  57                   push edi
// 00511d51  8b7e70               mov edi, dword ptr [esi + 0x70]
// 00511d54  f7c700010000         test edi, 0x100
// 00511d5a  895c2418             mov dword ptr [esp + 0x18], ebx
// 00511d5e  897c244c             mov dword ptr [esp + 0x4c], edi
// 00511d62  0f84c8000000         je 0x511e30
// 00511d68  f7c700100000         test edi, 0x1000
// 00511d6e  0f84bc000000         je 0x511e30
// 00511d74  f6c302               test bl, 2
// 00511d77  7575                 jne 0x511dee
// 00511d79  0fb68627010000       movzx eax, byte ptr [esi + 0x127]
// 00511d80  83c0ff               add eax, -1
// 00511d83  83f80f               cmp eax, 0xf
// 00511d86  0f87a4000000         ja 0x511e30
// 00511d8c  0fb68004295100       movzx eax, byte ptr [eax + 0x512904]
// 00511d93  ff2485f0285100       jmp dword ptr [eax*4 + 0x5128f0]
// 00511d9a  668b8640010000       mov ax, word ptr [esi + 0x140]
// 00511da1  6669c0ff00           imul ax, ax, 0xff
// 00511da6  66898640010000       mov word ptr [esi + 0x140], ax
// 00511dad  6689863c010000       mov word ptr [esi + 0x13c], ax
// 00511db4  6689863a010000       mov word ptr [esi + 0x13a], ax
// 00511dbb  eb65                 jmp 0x511e22
// 00511dbd  668b8640010000       mov ax, word ptr [esi + 0x140]
// 00511dc4  666bc055             imul ax, ax, 0x55
// 00511dc8  ebdc                 jmp 0x511da6
// 00511dca  668b8640010000       mov ax, word ptr [esi + 0x140]
// 00511dd1  666bc011             imul ax, ax, 0x11
// 00511dd5  ebcf                 jmp 0x511da6
// 00511dd7  0fb78640010000       movzx eax, word ptr [esi + 0x140]
// 00511dde  6689863c010000       mov word ptr [esi + 0x13c], ax
// 00511de5  6689863a010000       mov word ptr [esi + 0x13a], ax
// 00511dec  eb34                 jmp 0x511e22
// 00511dee  83fb03               cmp ebx, 3
// 00511df1  753d                 jne 0x511e30
// 00511df3  0fb68638010000       movzx eax, byte ptr [esi + 0x138]
// 00511dfa  8b9614010000         mov edx, dword ptr [esi + 0x114]
// 00511e00  8d0c40               lea ecx, [eax + eax*2]
// 00511e03  8d0411               lea eax, [ecx + edx]
// 00511e06  660fb608             movzx cx, byte ptr [eax]
// 00511e0a  66898e3a010000       mov word ptr [esi + 0x13a], cx
// 00511e11  660fb65001           movzx dx, byte ptr [eax + 1]
// 00511e16  6689963c010000       mov word ptr [esi + 0x13c], dx
// 00511e1d  660fb64002           movzx ax, byte ptr [eax + 2]
// 00511e22  6689863e010000       mov word ptr [esi + 0x13e], ax
// 00511e29  8da42400000000       lea esp, [esp]
// 00511e30  83fb03               cmp ebx, 3
// 00511e33  8b8e38010000         mov ecx, dword ptr [esi + 0x138]
// 00511e39  8b963c010000         mov edx, dword ptr [esi + 0x13c]
// 00511e3f  668b8640010000       mov ax, word ptr [esi + 0x140]
// 00511e46  898e42010000         mov dword ptr [esi + 0x142], ecx
// 00511e4c  899646010000         mov dword ptr [esi + 0x146], edx
// 00511e52  55                   push ebp
// 00511e53  6689864a010000       mov word ptr [esi + 0x14a], ax
// 00511e5a  756c                 jne 0x511ec8
// 00511e5c  0fb7961a010000       movzx edx, word ptr [esi + 0x11a]
// 00511e63  6685d2               test dx, dx
// 00511e66  7460                 je 0x511ec8
// 00511e68  d98660010000         fld dword ptr [esi + 0x160]
// 00511e6e  d88e5c010000         fmul dword ptr [esi + 0x15c]
// 00511e74  dc25a81f7900         fsub qword ptr [0x791fa8]
// 00511e7a  d9e1                 fabs 
// 00511e7c  dc1d18fe7900         fcomp qword ptr [0x79fe18]
// 00511e82  dfe0                 fnstsw ax
// 00511e84  f6c405               test ah, 5
// 00511e87  7a3f                 jp 0x511ec8
// 00511e89  33ed                 xor ebp, ebp
// 00511e8b  33c9                 xor ecx, ecx
// 00511e8d  6685d2               test dx, dx
// 00511e90  762d                 jbe 0x511ebf
// 00511e92  0fb7be1a010000       movzx edi, word ptr [esi + 0x11a]
// 00511e99  8b9688010000         mov edx, dword ptr [esi + 0x188]
// 00511e9f  90                   nop 
// 00511ea0  8a040a               mov al, byte ptr [edx + ecx]
// 00511ea3  84c0                 test al, al
// 00511ea5  7409                 je 0x511eb0
// 00511ea7  3cff                 cmp al, 0xff
// 00511ea9  7405                 je 0x511eb0
// 00511eab  bd01000000           mov ebp, 1
// 00511eb0  83c101               add ecx, 1
// 00511eb3  3bcf                 cmp ecx, edi
// 00511eb5  7ce9                 jl 0x511ea0
// 00511eb7  85ed                 test ebp, ebp
// 00511eb9  750d                 jne 0x511ec8
// 00511ebb  8b7c2450             mov edi, dword ptr [esp + 0x50]
// 00511ebf  81e7ffdfffff         and edi, 0xffffdfff
// 00511ec5  897e70               mov dword ptr [esi + 0x70], edi
// 00511ec8  8b4670               mov eax, dword ptr [esi + 0x70]
// 00511ecb  a900206000           test eax, 0x602000
// 00511ed0  0f8418080000         je 0x5126ee
// 00511ed6  56                   push esi
// 00511ed7  e874f6ffff           call 0x511550
// 00511edc  83c404               add esp, 4
// 00511edf  f6467080             test byte ptr [esi + 0x70], 0x80
// 00511ee3  0f849a070000         je 0x512683
// 00511ee9  83fb03               cmp ebx, 3
// 00511eec  0f8557040000         jne 0x512349
// 00511ef2  0fb7ae18010000       movzx ebp, word ptr [esi + 0x118]
// 00511ef9  8a8630010000         mov al, byte ptr [esi + 0x130]
// 00511eff  3c02                 cmp al, 2
// 00511f01  896c2428             mov dword ptr [esp + 0x28], ebp
// 00511f05  754f                 jne 0x511f56
// 00511f07  0fb78e3a010000       movzx ecx, word ptr [esi + 0x13a]
// 00511f0e  8b8664010000         mov eax, dword ptr [esi + 0x164]
// 00511f14  0fb61408             movzx edx, byte ptr [eax + ecx]
// 00511f18  0fb7be3c010000       movzx edi, word ptr [esi + 0x13c]
// 00511f1f  88542410             mov byte ptr [esp + 0x10], dl
// 00511f23  0fb61407             movzx edx, byte ptr [edi + eax]
// 00511f27  88542411             mov byte ptr [esp + 0x11], dl
// 00511f2b  0fb7963e010000       movzx edx, word ptr [esi + 0x13e]
// 00511f32  8a0402               mov al, byte ptr [edx + eax]
// 00511f35  88442412             mov byte ptr [esp + 0x12], al
// 00511f39  8b866c010000         mov eax, dword ptr [esi + 0x16c]
// 00511f3f  0fb61410             movzx edx, byte ptr [eax + edx]
// 00511f43  8a1c08               mov bl, byte ptr [eax + ecx]
// 00511f46  8a0c38               mov cl, byte ptr [eax + edi]
// 00511f49  884c2415             mov byte ptr [esp + 0x15], cl
// 00511f4d  88542416             mov byte ptr [esp + 0x16], dl
// 00511f51  e966020000           jmp 0x5121bc
// 00511f56  0fb6c0               movzx eax, al
// 00511f59  83e801               sub eax, 1
// 00511f5c  743a                 je 0x511f98
// 00511f5e  83e801               sub eax, 1
// 00511f61  742d                 je 0x511f90
// 00511f63  83e801               sub eax, 1
// 00511f66  7408                 je 0x511f70
// 00511f68  d9e8                 fld1 
// 00511f6a  dd542420             fst qword ptr [esp + 0x20]
// 00511f6e  eb34                 jmp 0x511fa4
// 00511f70  d98634010000         fld dword ptr [esi + 0x134]
// 00511f76  d9e8                 fld1 
// 00511f78  d9c0                 fld st(0)
// 00511f7a  d8f2                 fdiv st(2)
// 00511f7c  dd5c2420             fstp qword ptr [esp + 0x20]
// 00511f80  d98660010000         fld dword ptr [esi + 0x160]
// 00511f86  deca                 fmulp st(2)
// 00511f88  d9c0                 fld st(0)
// 00511f8a  def2                 fdivrp st(2)
// 00511f8c  d9c9                 fxch st(1)
// 00511f8e  eb16                 jmp 0x511fa6
// 00511f90  d9865c010000         fld dword ptr [esi + 0x15c]
// 00511f96  ebde                 jmp 0x511f76
// 00511f98  d98660010000         fld dword ptr [esi + 0x160]
// 00511f9e  dd5c2420             fstp qword ptr [esp + 0x20]
// 00511fa2  d9e8                 fld1 
// 00511fa4  d9c0                 fld st(0)
// 00511fa6  dd54242c             fst qword ptr [esp + 0x2c]
// 00511faa  d9c0                 fld st(0)
// 00511fac  dee2                 fsubrp st(2)
// 00511fae  d9c9                 fxch st(1)
// 00511fb0  d9e1                 fabs 
// 00511fb2  dc1d18fe7900         fcomp qword ptr [0x79fe18]
// 00511fb8  dfe0                 fnstsw ax
// 00511fba  dd0510c47800         fld qword ptr [0x78c410]
// 00511fc0  f6c405               test ah, 5
// 00511fc3  7a21                 jp 0x511fe6
// 00511fc5  8a863a010000         mov al, byte ptr [esi + 0x13a]
// 00511fcb  ddd9                 fstp st(1)
// 00511fcd  8a8e3c010000         mov cl, byte ptr [esi + 0x13c]
// 00511fd3  8a963e010000         mov dl, byte ptr [esi + 0x13e]
// 00511fd9  88442410             mov byte ptr [esp + 0x10], al
// 00511fdd  884c2411             mov byte ptr [esp + 0x11], cl
// 00511fe1  e9ea000000           jmp 0x5120d0
// 00511fe6  0fb7863a010000       movzx eax, word ptr [esi + 0x13a]
// 00511fed  89442450             mov dword ptr [esp + 0x50], eax
// 00511ff1  db442450             fild dword ptr [esp + 0x50]
// 00511ff5  def1                 fdivrp st(1)
// 00511ff7  d9c9                 fxch st(1)
// 00511ff9  e840d61000           call 0x61f63e
// 00511ffe  dd0510c47800         fld qword ptr [0x78c410]
// 00512004  0fb7963c010000       movzx edx, word ptr [esi + 0x13c]
// 0051200b  dcc9                 fmul st(1), st(0)
// 0051200d  d97c2450             fnstcw word ptr [esp + 0x50]
// 00512011  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00512016  d9c9                 fxch st(1)
// 00512018  dc05584f7900         fadd qword ptr [0x794f58]
// 0051201e  0d000c0000           or eax, 0xc00
// 00512023  89442414             mov dword ptr [esp + 0x14], eax
// 00512027  d96c2414             fldcw word ptr [esp + 0x14]
// 0051202b  db5c2414             fistp dword ptr [esp + 0x14]
// 0051202f  8a4c2414             mov cl, byte ptr [esp + 0x14]
// 00512033  884c2410             mov byte ptr [esp + 0x10], cl
// 00512037  d96c2450             fldcw word ptr [esp + 0x50]
// 0051203b  89542450             mov dword ptr [esp + 0x50], edx
// 0051203f  db442450             fild dword ptr [esp + 0x50]
// 00512043  def1                 fdivrp st(1)
// 00512045  dd44242c             fld qword ptr [esp + 0x2c]
// 00512049  e8f0d51000           call 0x61f63e
// 0051204e  dd0510c47800         fld qword ptr [0x78c410]
// 00512054  0fb78e3e010000       movzx ecx, word ptr [esi + 0x13e]
// 0051205b  dcc9                 fmul st(1), st(0)
// 0051205d  d97c2450             fnstcw word ptr [esp + 0x50]
// 00512061  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00512066  d9c9                 fxch st(1)
// 00512068  dc05584f7900         fadd qword ptr [0x794f58]
// 0051206e  0d000c0000           or eax, 0xc00
// 00512073  89442414             mov dword ptr [esp + 0x14], eax
// 00512077  d96c2414             fldcw word ptr [esp + 0x14]
// 0051207b  db5c2414             fistp dword ptr [esp + 0x14]
// 0051207f  8a442414             mov al, byte ptr [esp + 0x14]
// 00512083  88442411             mov byte ptr [esp + 0x11], al
// 00512087  d96c2450             fldcw word ptr [esp + 0x50]
// 0051208b  894c2450             mov dword ptr [esp + 0x50], ecx
// 0051208f  db442450             fild dword ptr [esp + 0x50]
// 00512093  def1                 fdivrp st(1)
// 00512095  dd44242c             fld qword ptr [esp + 0x2c]
// 00512099  e8a0d51000           call 0x61f63e
// 0051209e  dd0510c47800         fld qword ptr [0x78c410]
// 005120a4  d97c2450             fnstcw word ptr [esp + 0x50]
// 005120a8  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 005120ad  dcc9                 fmul st(1), st(0)
// 005120af  0d000c0000           or eax, 0xc00
// 005120b4  d9c9                 fxch st(1)
// 005120b6  89442414             mov dword ptr [esp + 0x14], eax
// 005120ba  dc05584f7900         fadd qword ptr [0x794f58]
// 005120c0  d96c2414             fldcw word ptr [esp + 0x14]
// 005120c4  db5c2414             fistp dword ptr [esp + 0x14]
// 005120c8  8a542414             mov dl, byte ptr [esp + 0x14]
// 005120cc  d96c2450             fldcw word ptr [esp + 0x50]
// 005120d0  0fb7863a010000       movzx eax, word ptr [esi + 0x13a]
// 005120d7  89442450             mov dword ptr [esp + 0x50], eax
// 005120db  88542412             mov byte ptr [esp + 0x12], dl
// 005120df  db442450             fild dword ptr [esp + 0x50]
// 005120e3  def1                 fdivrp st(1)
// 005120e5  dd442420             fld qword ptr [esp + 0x20]
// 005120e9  e850d51000           call 0x61f63e
// 005120ee  dd0510c47800         fld qword ptr [0x78c410]
// 005120f4  0fb78e3c010000       movzx ecx, word ptr [esi + 0x13c]
// 005120fb  dcc9                 fmul st(1), st(0)
// 005120fd  d97c2450             fnstcw word ptr [esp + 0x50]
// 00512101  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00512106  d9c9                 fxch st(1)
// 00512108  dc05584f7900         fadd qword ptr [0x794f58]
// 0051210e  0d000c0000           or eax, 0xc00
// 00512113  89442414             mov dword ptr [esp + 0x14], eax
// 00512117  d96c2414             fldcw word ptr [esp + 0x14]
// 0051211b  db5c2414             fistp dword ptr [esp + 0x14]
// 0051211f  8a5c2414             mov bl, byte ptr [esp + 0x14]
// 00512123  d96c2450             fldcw word ptr [esp + 0x50]
// 00512127  894c2450             mov dword ptr [esp + 0x50], ecx
// 0051212b  db442450             fild dword ptr [esp + 0x50]
// 0051212f  def1                 fdivrp st(1)
// 00512131  dd442420             fld qword ptr [esp + 0x20]
// 00512135  e804d51000           call 0x61f63e
// 0051213a  dd0510c47800         fld qword ptr [0x78c410]
// 00512140  dcc9                 fmul st(1), st(0)
// 00512142  d97c2450             fnstcw word ptr [esp + 0x50]
// 00512146  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 0051214b  d9c9                 fxch st(1)
// 0051214d  0d000c0000           or eax, 0xc00
// 00512152  dc05584f7900         fadd qword ptr [0x794f58]
// 00512158  89442414             mov dword ptr [esp + 0x14], eax
// 0051215c  0fb7863e010000       movzx eax, word ptr [esi + 0x13e]
// 00512163  d96c2414             fldcw word ptr [esp + 0x14]
// 00512167  db5c2414             fistp dword ptr [esp + 0x14]
// 0051216b  8a542414             mov dl, byte ptr [esp + 0x14]
// 0051216f  88542415             mov byte ptr [esp + 0x15], dl
// 00512173  d96c2450             fldcw word ptr [esp + 0x50]
// 00512177  89442450             mov dword ptr [esp + 0x50], eax
// 0051217b  db442450             fild dword ptr [esp + 0x50]
// 0051217f  def1                 fdivrp st(1)
// 00512181  dd442420             fld qword ptr [esp + 0x20]
// 00512185  e8b4d41000           call 0x61f63e
// 0051218a  dc0d10c47800         fmul qword ptr [0x78c410]
// 00512190  d97c2450             fnstcw word ptr [esp + 0x50]
// 00512194  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00512199  dc05584f7900         fadd qword ptr [0x794f58]
// 0051219f  0d000c0000           or eax, 0xc00
// 005121a4  89442420             mov dword ptr [esp + 0x20], eax
// 005121a8  d96c2420             fldcw word ptr [esp + 0x20]
// 005121ac  db5c2420             fistp dword ptr [esp + 0x20]
// 005121b0  8a4c2420             mov cl, byte ptr [esp + 0x20]
// 005121b4  884c2416             mov byte ptr [esp + 0x16], cl
// 005121b8  d96c2450             fldcw word ptr [esp + 0x50]
// 005121bc  33ff                 xor edi, edi
// 005121be  85ed                 test ebp, ebp
// 005121c0  0f8e69060000         jle 0x51282f
// 005121c6  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 005121cc  83c002               add eax, 2
// 005121cf  90                   nop 
// 005121d0  0fb7961a010000       movzx edx, word ptr [esi + 0x11a]
// 005121d7  3bfa                 cmp edi, edx
// 005121d9  0f8d27010000         jge 0x512306
// 005121df  8b8e88010000         mov ecx, dword ptr [esi + 0x188]
// 005121e5  8a1439               mov dl, byte ptr [ecx + edi]
// 005121e8  03cf                 add ecx, edi
// 005121ea  80faff               cmp dl, 0xff
// 005121ed  0f8413010000         je 0x512306
// 005121f3  84d2                 test dl, dl
// 005121f5  7514                 jne 0x51220b
// 005121f7  668b542410           mov dx, word ptr [esp + 0x10]
// 005121fc  8a4c2412             mov cl, byte ptr [esp + 0x12]
// 00512200  668950fe             mov word ptr [eax - 2], dx
// 00512204  8808                 mov byte ptr [eax], cl
// 00512206  e92b010000           jmp 0x512336
// 0051220b  660fb609             movzx cx, byte ptr [ecx]
// 0051220f  8bae6c010000         mov ebp, dword ptr [esi + 0x16c]
// 00512215  0fb650fe             movzx edx, byte ptr [eax - 2]
// 00512219  0fb6142a             movzx edx, byte ptr [edx + ebp]
// 0051221d  660fafd1             imul dx, cx
// 00512221  bdff000000           mov ebp, 0xff
// 00512226  2be9                 sub ebp, ecx
// 00512228  660fb6cb             movzx cx, bl
// 0051222c  660fafe9             imul bp, cx
// 00512230  6603d5               add dx, bp
// 00512233  6681c28000           add dx, 0x80
// 00512238  0fb7ca               movzx ecx, dx
// 0051223b  0fb7c9               movzx ecx, cx
// 0051223e  8bd1                 mov edx, ecx
// 00512240  c1ea08               shr edx, 8
// 00512243  03d1                 add edx, ecx
// 00512245  c1fa08               sar edx, 8
// 00512248  0fb6ca               movzx ecx, dl
// 0051224b  8b9668010000         mov edx, dword ptr [esi + 0x168]
// 00512251  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 00512255  8848fe               mov byte ptr [eax - 2], cl
// 00512258  8b9688010000         mov edx, dword ptr [esi + 0x188]
// 0051225e  660fb60c3a           movzx cx, byte ptr [edx + edi]
// 00512263  0fb650ff             movzx edx, byte ptr [eax - 1]
// 00512267  8bae6c010000         mov ebp, dword ptr [esi + 0x16c]
// 0051226d  0fb6142a             movzx edx, byte ptr [edx + ebp]
// 00512271  660fafd1             imul dx, cx
// 00512275  bdff000000           mov ebp, 0xff
// 0051227a  2be9                 sub ebp, ecx
// 0051227c  0fb64c2415           movzx ecx, byte ptr [esp + 0x15]
// 00512281  660fafe9             imul bp, cx
// 00512285  6603d5               add dx, bp
// 00512288  6681c28000           add dx, 0x80
// 0051228d  0fb7ca               movzx ecx, dx
// 00512290  0fb7c9               movzx ecx, cx
// 00512293  8bd1                 mov edx, ecx
// 00512295  c1ea08               shr edx, 8
// 00512298  03d1                 add edx, ecx
// 0051229a  c1fa08               sar edx, 8
// 0051229d  0fb6ca               movzx ecx, dl
// 005122a0  8b9668010000         mov edx, dword ptr [esi + 0x168]
// 005122a6  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 005122aa  8848ff               mov byte ptr [eax - 1], cl
// 005122ad  8b9688010000         mov edx, dword ptr [esi + 0x188]
// 005122b3  660fb60c3a           movzx cx, byte ptr [edx + edi]
// 005122b8  0fb610               movzx edx, byte ptr [eax]
// 005122bb  8bae6c010000         mov ebp, dword ptr [esi + 0x16c]
// 005122c1  0fb6142a             movzx edx, byte ptr [edx + ebp]
// 005122c5  660fafd1             imul dx, cx
// 005122c9  bdff000000           mov ebp, 0xff
// 005122ce  2be9                 sub ebp, ecx
// 005122d0  0fb64c2416           movzx ecx, byte ptr [esp + 0x16]
// 005122d5  660fafe9             imul bp, cx
// 005122d9  6603d5               add dx, bp
// 005122dc  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005122e0  6681c28000           add dx, 0x80
// 005122e5  0fb7ca               movzx ecx, dx
// 005122e8  0fb7c9               movzx ecx, cx
// 005122eb  8bd1                 mov edx, ecx
// 005122ed  c1ea08               shr edx, 8
// 005122f0  03d1                 add edx, ecx
// 005122f2  c1fa08               sar edx, 8
// 005122f5  0fb6ca               movzx ecx, dl
// 005122f8  8b9668010000         mov edx, dword ptr [esi + 0x168]
// 005122fe  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 00512302  8808                 mov byte ptr [eax], cl
// 00512304  eb30                 jmp 0x512336
// 00512306  8b8e64010000         mov ecx, dword ptr [esi + 0x164]
// 0051230c  0fb650fe             movzx edx, byte ptr [eax - 2]
// 00512310  0fb6140a             movzx edx, byte ptr [edx + ecx]
// 00512314  0fb648ff             movzx ecx, byte ptr [eax - 1]
// 00512318  8850fe               mov byte ptr [eax - 2], dl
// 0051231b  8b9664010000         mov edx, dword ptr [esi + 0x164]
// 00512321  8a0c11               mov cl, byte ptr [ecx + edx]
// 00512324  0fb610               movzx edx, byte ptr [eax]
// 00512327  8848ff               mov byte ptr [eax - 1], cl
// 0051232a  8b8e64010000         mov ecx, dword ptr [esi + 0x164]
// 00512330  0fb6140a             movzx edx, byte ptr [edx + ecx]
// 00512334  8810                 mov byte ptr [eax], dl
// 00512336  83c701               add edi, 1
// 00512339  83c003               add eax, 3
// 0051233c  3bfd                 cmp edi, ebp
// 0051233e  0f8c8cfeffff         jl 0x5121d0
// 00512344  e9e6040000           jmp 0x51282f
// 00512349  8a8e27010000         mov cl, byte ptr [esi + 0x127]
// 0051234f  b801000000           mov eax, 1
// 00512354  d3e0                 shl eax, cl
// 00512356  83e801               sub eax, 1
// 00512359  85c0                 test eax, eax
// 0051235b  89442450             mov dword ptr [esp + 0x50], eax
// 0051235f  db442450             fild dword ptr [esp + 0x50]
// 00512363  7d06                 jge 0x51236b
// 00512365  dc05a89b7800         fadd qword ptr [0x789ba8]
// 0051236b  0fb68630010000       movzx eax, byte ptr [esi + 0x130]
// 00512372  dd542420             fst qword ptr [esp + 0x20]
// 00512376  83e801               sub eax, 1
// 00512379  d9e8                 fld1 
// 0051237b  d9c0                 fld st(0)
// 0051237d  dd54242c             fst qword ptr [esp + 0x2c]
// 00512381  d9c9                 fxch st(1)
// 00512383  dd542414             fst qword ptr [esp + 0x14]
// 00512387  7436                 je 0x5123bf
// 00512389  83e801               sub eax, 1
// 0051238c  740f                 je 0x51239d
// 0051238e  83e801               sub eax, 1
// 00512391  7540                 jne 0x5123d3
// 00512393  ddd9                 fstp st(1)
// 00512395  d98634010000         fld dword ptr [esi + 0x134]
// 0051239b  eb08                 jmp 0x5123a5
// 0051239d  ddd9                 fstp st(1)
// 0051239f  d9865c010000         fld dword ptr [esi + 0x15c]
// 005123a5  d9c1                 fld st(1)
// 005123a7  d8f1                 fdiv st(1)
// 005123a9  dd54242c             fst qword ptr [esp + 0x2c]
// 005123ad  d98660010000         fld dword ptr [esi + 0x160]
// 005123b3  deca                 fmulp st(2)
// 005123b5  d9ca                 fxch st(2)
// 005123b7  def1                 fdivrp st(1)
// 005123b9  dd5c2414             fstp qword ptr [esp + 0x14]
// 005123bd  eb16                 jmp 0x5123d5
// 005123bf  ddd9                 fstp st(1)
// 005123c1  d98660010000         fld dword ptr [esi + 0x160]
// 005123c7  dd54242c             fst qword ptr [esp + 0x2c]
// 005123cb  d9c9                 fxch st(1)
// 005123cd  dd5c2414             fstp qword ptr [esp + 0x14]
// 005123d1  eb02                 jmp 0x5123d5
// 005123d3  ddd8                 fstp st(0)
// 005123d5  0fb78e40010000       movzx ecx, word ptr [esi + 0x140]
// 005123dc  894c2450             mov dword ptr [esp + 0x50], ecx
// 005123e0  db442450             fild dword ptr [esp + 0x50]
// 005123e4  def2                 fdivrp st(2)
// 005123e6  d9c9                 fxch st(1)
// 005123e8  dd542434             fst qword ptr [esp + 0x34]
// 005123ec  d9c9                 fxch st(1)
// 005123ee  e84bd21000           call 0x61f63e
// 005123f3  dc4c2420             fmul qword ptr [esp + 0x20]
// 005123f7  d97c2450             fnstcw word ptr [esp + 0x50]
// 005123fb  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00512400  dc05584f7900         fadd qword ptr [0x794f58]
// 00512406  0d000c0000           or eax, 0xc00
// 0051240b  89442428             mov dword ptr [esp + 0x28], eax
// 0051240f  d96c2428             fldcw word ptr [esp + 0x28]
// 00512413  db5c2428             fistp dword ptr [esp + 0x28]
// 00512417  668b542428           mov dx, word ptr [esp + 0x28]
// 0051241c  6689964a010000       mov word ptr [esi + 0x14a], dx
// 00512423  d96c2450             fldcw word ptr [esp + 0x50]
// 00512427  dd442434             fld qword ptr [esp + 0x34]
// 0051242b  dd442414             fld qword ptr [esp + 0x14]
// 0051242f  e80ad21000           call 0x61f63e
// 00512434  dd442420             fld qword ptr [esp + 0x20]
// 00512438  0fb7be3c010000       movzx edi, word ptr [esi + 0x13c]
// 0051243f  d97c2450             fnstcw word ptr [esp + 0x50]
// 00512443  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00512448  dcc9                 fmul st(1), st(0)
// 0051244a  d9c9                 fxch st(1)
// 0051244c  0fb78e3a010000       movzx ecx, word ptr [esi + 0x13a]
// 00512453  dc05584f7900         fadd qword ptr [0x794f58]
// 00512459  0d000c0000           or eax, 0xc00
// 0051245e  663bcf               cmp cx, di
// 00512461  89442428             mov dword ptr [esp + 0x28], eax
// 00512465  d96c2428             fldcw word ptr [esp + 0x28]
// 00512469  db5c2428             fistp dword ptr [esp + 0x28]
// 0051246d  668b442428           mov ax, word ptr [esp + 0x28]
// 00512472  66898640010000       mov word ptr [esi + 0x140], ax
// 00512479  d96c2450             fldcw word ptr [esp + 0x50]
// 0051247d  7546                 jne 0x5124c5
// 0051247f  663b8e3e010000       cmp cx, word ptr [esi + 0x13e]
// 00512486  753d                 jne 0x5124c5
// 00512488  663bc8               cmp cx, ax
// 0051248b  7538                 jne 0x5124c5
// 0051248d  0fb78e4a010000       movzx ecx, word ptr [esi + 0x14a]
// 00512494  ddd8                 fstp st(0)
// 00512496  66898e48010000       mov word ptr [esi + 0x148], cx
// 0051249d  66898e46010000       mov word ptr [esi + 0x146], cx
// 005124a4  66898e44010000       mov word ptr [esi + 0x144], cx
// 005124ab  6689863e010000       mov word ptr [esi + 0x13e], ax
// 005124b2  6689863c010000       mov word ptr [esi + 0x13c], ax
// 005124b9  6689863a010000       mov word ptr [esi + 0x13a], ax
// 005124c0  e96a030000           jmp 0x51282f
// 005124c5  0fb7c1               movzx eax, cx
// 005124c8  89442450             mov dword ptr [esp + 0x50], eax
// 005124cc  db442450             fild dword ptr [esp + 0x50]
// 005124d0  def1                 fdivrp st(1)
// 005124d2  dd542434             fst qword ptr [esp + 0x34]
// 005124d6  dd44242c             fld qword ptr [esp + 0x2c]
// 005124da  e85fd11000           call 0x61f63e
// 005124df  dd442420             fld qword ptr [esp + 0x20]
// 005124e3  dcc9                 fmul st(1), st(0)
// 005124e5  0fb7d7               movzx edx, di
// 005124e8  d97c2450             fnstcw word ptr [esp + 0x50]
// 005124ec  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 005124f1  d9c9                 fxch st(1)
// 005124f3  dc05584f7900         fadd qword ptr [0x794f58]
// 005124f9  0d000c0000           or eax, 0xc00
// 005124fe  89442428             mov dword ptr [esp + 0x28], eax
// 00512502  d96c2428             fldcw word ptr [esp + 0x28]
// 00512506  db5c2428             fistp dword ptr [esp + 0x28]
// 0051250a  0fb74c2428           movzx ecx, word ptr [esp + 0x28]
// 0051250f  66898e44010000       mov word ptr [esi + 0x144], cx
// 00512516  d96c2450             fldcw word ptr [esp + 0x50]
// 0051251a  89542450             mov dword ptr [esp + 0x50], edx
// 0051251e  db442450             fild dword ptr [esp + 0x50]
// 00512522  def1                 fdivrp st(1)
// 00512524  dd54243c             fst qword ptr [esp + 0x3c]
// 00512528  dd44242c             fld qword ptr [esp + 0x2c]
// 0051252c  e80dd11000           call 0x61f63e
// 00512531  dd442420             fld qword ptr [esp + 0x20]
// 00512535  0fb78e3e010000       movzx ecx, word ptr [esi + 0x13e]
// 0051253c  dcc9                 fmul st(1), st(0)
// 0051253e  d97c2450             fnstcw word ptr [esp + 0x50]
// 00512542  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00512547  d9c9                 fxch st(1)
// 00512549  dc05584f7900         fadd qword ptr [0x794f58]
// 0051254f  0d000c0000           or eax, 0xc00
// 00512554  89442428             mov dword ptr [esp + 0x28], eax
// 00512558  d96c2428             fldcw word ptr [esp + 0x28]
// 0051255c  db5c2428             fistp dword ptr [esp + 0x28]
// 00512560  0fb7442428           movzx eax, word ptr [esp + 0x28]
// 00512565  66898646010000       mov word ptr [esi + 0x146], ax
// 0051256c  d96c2450             fldcw word ptr [esp + 0x50]
// 00512570  894c2450             mov dword ptr [esp + 0x50], ecx
// 00512574  db442450             fild dword ptr [esp + 0x50]
// 00512578  def1                 fdivrp st(1)
// 0051257a  dd542444             fst qword ptr [esp + 0x44]
// 0051257e  dd44242c             fld qword ptr [esp + 0x2c]
// 00512582  e8b7d01000           call 0x61f63e
// 00512587  dc4c2420             fmul qword ptr [esp + 0x20]
// 0051258b  d97c2450             fnstcw word ptr [esp + 0x50]
// 0051258f  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00512594  dc05584f7900         fadd qword ptr [0x794f58]
// 0051259a  0d000c0000           or eax, 0xc00
// 0051259f  89442428             mov dword ptr [esp + 0x28], eax
// 005125a3  d96c2428             fldcw word ptr [esp + 0x28]
// 005125a7  db5c2428             fistp dword ptr [esp + 0x28]
// 005125ab  0fb7542428           movzx edx, word ptr [esp + 0x28]
// 005125b0  66899648010000       mov word ptr [esi + 0x148], dx
// 005125b7  d96c2450             fldcw word ptr [esp + 0x50]
// 005125bb  dd442434             fld qword ptr [esp + 0x34]
// 005125bf  dd442414             fld qword ptr [esp + 0x14]
// 005125c3  e876d01000           call 0x61f63e
// 005125c8  dc4c2420             fmul qword ptr [esp + 0x20]
// 005125cc  d97c2450             fnstcw word ptr [esp + 0x50]
// 005125d0  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 005125d5  dc05584f7900         fadd qword ptr [0x794f58]
// 005125db  0d000c0000           or eax, 0xc00
// 005125e0  89442428             mov dword ptr [esp + 0x28], eax
// 005125e4  d96c2428             fldcw word ptr [esp + 0x28]
// 005125e8  db5c2428             fistp dword ptr [esp + 0x28]
// 005125ec  0fb7442428           movzx eax, word ptr [esp + 0x28]
// 005125f1  6689863a010000       mov word ptr [esi + 0x13a], ax
// 005125f8  d96c2450             fldcw word ptr [esp + 0x50]
// 005125fc  dd44243c             fld qword ptr [esp + 0x3c]
// 00512600  dd442414             fld qword ptr [esp + 0x14]
// 00512604  e835d01000           call 0x61f63e
// 00512609  dc4c2420             fmul qword ptr [esp + 0x20]
// 0051260d  d97c2450             fnstcw word ptr [esp + 0x50]
// 00512611  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00512616  dc05584f7900         fadd qword ptr [0x794f58]
// 0051261c  0d000c0000           or eax, 0xc00
// 00512621  89442428             mov dword ptr [esp + 0x28], eax
// 00512625  d96c2428             fldcw word ptr [esp + 0x28]
// 00512629  db5c2428             fistp dword ptr [esp + 0x28]
// 0051262d  0fb74c2428           movzx ecx, word ptr [esp + 0x28]
// 00512632  66898e3c010000       mov word ptr [esi + 0x13c], cx
// 00512639  d96c2450             fldcw word ptr [esp + 0x50]
// 0051263d  dd442444             fld qword ptr [esp + 0x44]
// 00512641  dd442414             fld qword ptr [esp + 0x14]
// 00512645  e8f4cf1000           call 0x61f63e
// 0051264a  dc4c2420             fmul qword ptr [esp + 0x20]
// 0051264e  d97c2450             fnstcw word ptr [esp + 0x50]
// 00512652  0fb7442450           movzx eax, word ptr [esp + 0x50]
// 00512657  dc05584f7900         fadd qword ptr [0x794f58]
// 0051265d  0d000c0000           or eax, 0xc00
// 00512662  89442428             mov dword ptr [esp + 0x28], eax
// 00512666  d96c2428             fldcw word ptr [esp + 0x28]
// 0051266a  db5c2428             fistp dword ptr [esp + 0x28]
// 0051266e  0fb7542428           movzx edx, word ptr [esp + 0x28]
// 00512673  6689963e010000       mov word ptr [esi + 0x13e], dx
// 0051267a  d96c2450             fldcw word ptr [esp + 0x50]
// 0051267e  e9ac010000           jmp 0x51282f
// 00512683  83fb03               cmp ebx, 3
// 00512686  0f85a3010000         jne 0x51282f
// 0051268c  0fb78e18010000       movzx ecx, word ptr [esi + 0x118]
// 00512693  85c9                 test ecx, ecx
// 00512695  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 0051269b  0f8e8e010000         jle 0x51282f
// 005126a1  83c002               add eax, 2
// 005126a4  eb0a                 jmp 0x5126b0
// 005126a6  8da42400000000       lea esp, [esp]
// 005126ad  8d4900               lea ecx, [ecx]
// 005126b0  0fb650fe             movzx edx, byte ptr [eax - 2]
// 005126b4  8bbe64010000         mov edi, dword ptr [esi + 0x164]
// 005126ba  0fb6143a             movzx edx, byte ptr [edx + edi]
// 005126be  8850fe               mov byte ptr [eax - 2], dl
// 005126c1  0fb650ff             movzx edx, byte ptr [eax - 1]
// 005126c5  8bbe64010000         mov edi, dword ptr [esi + 0x164]
// 005126cb  0fb6143a             movzx edx, byte ptr [edx + edi]
// 005126cf  8850ff               mov byte ptr [eax - 1], dl
// 005126d2  0fb610               movzx edx, byte ptr [eax]
// 005126d5  8bbe64010000         mov edi, dword ptr [esi + 0x164]
// 005126db  0fb6143a             movzx edx, byte ptr [edx + edi]
// 005126df  8810                 mov byte ptr [eax], dl
// 005126e1  83c003               add eax, 3
// 005126e4  83e901               sub ecx, 1
// 005126e7  75c7                 jne 0x5126b0
// 005126e9  e941010000           jmp 0x51282f
// 005126ee  84c0                 test al, al
// 005126f0  0f8939010000         jns 0x51282f
// 005126f6  837c241c03           cmp dword ptr [esp + 0x1c], 3
// 005126fb  0f852e010000         jne 0x51282f
// 00512701  0fb7ae1a010000       movzx ebp, word ptr [esi + 0x11a]
// 00512708  0fb6963c010000       movzx edx, byte ptr [esi + 0x13c]
// 0051270f  8a8e3a010000         mov cl, byte ptr [esi + 0x13a]
// 00512715  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 0051271b  33ff                 xor edi, edi
// 0051271d  85ed                 test ebp, ebp
// 0051271f  88542451             mov byte ptr [esp + 0x51], dl
// 00512723  8a963e010000         mov dl, byte ptr [esi + 0x13e]
// 00512729  896c2428             mov dword ptr [esp + 0x28], ebp
// 0051272d  884c2450             mov byte ptr [esp + 0x50], cl
// 00512731  0f8ef8000000         jle 0x51282f
// 00512737  83c002               add eax, 2
// 0051273a  8d9b00000000         lea ebx, [ebx]
// 00512740  8b8e88010000         mov ecx, dword ptr [esi + 0x188]
// 00512746  8a1c39               mov bl, byte ptr [ecx + edi]
// 00512749  03cf                 add ecx, edi
// 0051274b  84db                 test bl, bl
// 0051274d  7510                 jne 0x51275f
// 0051274f  668b4c2450           mov cx, word ptr [esp + 0x50]
// 00512754  668948fe             mov word ptr [eax - 2], cx
// 00512758  8810                 mov byte ptr [eax], dl
// 0051275a  e9c2000000           jmp 0x512821
// 0051275f  80fbff               cmp bl, 0xff
// 00512762  0f84b9000000         je 0x512821
// 00512768  660fb609             movzx cx, byte ptr [ecx]
// 0051276c  660fb66c2450         movzx bp, byte ptr [esp + 0x50]
// 00512772  bbff000000           mov ebx, 0xff
// 00512777  2bd9                 sub ebx, ecx
// 00512779  660fafdd             imul bx, bp
// 0051277d  660fb668fe           movzx bp, byte ptr [eax - 2]
// 00512782  660fafe9             imul bp, cx
// 00512786  6603dd               add bx, bp
// 00512789  6681c38000           add bx, 0x80
// 0051278e  0fb7cb               movzx ecx, bx
// 00512791  660fb66c2451         movzx bp, byte ptr [esp + 0x51]
// 00512797  0fb7c9               movzx ecx, cx
// 0051279a  8bd9                 mov ebx, ecx
// 0051279c  c1eb08               shr ebx, 8
// 0051279f  03d9                 add ebx, ecx
// 005127a1  c1fb08               sar ebx, 8
// 005127a4  8858fe               mov byte ptr [eax - 2], bl
// 005127a7  8b8e88010000         mov ecx, dword ptr [esi + 0x188]
// 005127ad  660fb60c39           movzx cx, byte ptr [ecx + edi]
// 005127b2  bbff000000           mov ebx, 0xff
// 005127b7  2bd9                 sub ebx, ecx
// 005127b9  660fafdd             imul bx, bp
// 005127bd  660fb668ff           movzx bp, byte ptr [eax - 1]
// 005127c2  660fafe9             imul bp, cx
// 005127c6  6603dd               add bx, bp
// 005127c9  6681c38000           add bx, 0x80
// 005127ce  0fb7cb               movzx ecx, bx
// 005127d1  0fb7c9               movzx ecx, cx
// 005127d4  8bd9                 mov ebx, ecx
// 005127d6  c1eb08               shr ebx, 8
// 005127d9  03d9                 add ebx, ecx
// 005127db  c1fb08               sar ebx, 8
// 005127de  8858ff               mov byte ptr [eax - 1], bl
// 005127e1  8b8e88010000         mov ecx, dword ptr [esi + 0x188]
// 005127e7  660fb60c39           movzx cx, byte ptr [ecx + edi]
// 005127ec  660fb6ea             movzx bp, dl
// 005127f0  bbff000000           mov ebx, 0xff
// 005127f5  2bd9                 sub ebx, ecx
// 005127f7  660fafdd             imul bx, bp
// 005127fb  660fb628             movzx bp, byte ptr [eax]
// 005127ff  660fafe9             imul bp, cx
// 00512803  6603dd               add bx, bp
// 00512806  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0051280a  6681c38000           add bx, 0x80
// 0051280f  0fb7cb               movzx ecx, bx
// 00512812  0fb7c9               movzx ecx, cx
// 00512815  8bd9                 mov ebx, ecx
// 00512817  c1eb08               shr ebx, 8
// 0051281a  03d9                 add ebx, ecx
// 0051281c  c1fb08               sar ebx, 8
// 0051281f  8818                 mov byte ptr [eax], bl
// 00512821  83c701               add edi, 1
// 00512824  83c003               add eax, 3
// 00512827  3bfd                 cmp edi, ebp
// 00512829  0f8c11ffffff         jl 0x512740
// 0051282f  f6467008             test byte ptr [esi + 0x70], 8
// 00512833  5d                   pop ebp
// 00512834  0f84ae000000         je 0x5128e8
// 0051283a  837c241803           cmp dword ptr [esp + 0x18], 3
// 0051283f  0f85a3000000         jne 0x5128e8
// 00512845  0fb6867c010000       movzx eax, byte ptr [esi + 0x17c]
// 0051284c  0fb68e7d010000       movzx ecx, byte ptr [esi + 0x17d]
// 00512853  0fb6be7e010000       movzx edi, byte ptr [esi + 0x17e]
// 0051285a  0fb79618010000       movzx edx, word ptr [esi + 0x118]
// 00512861  bb08000000           mov ebx, 8
// 00512866  2bd8                 sub ebx, eax
// 00512868  b808000000           mov eax, 8
// 0051286d  2bc1                 sub eax, ecx
// 0051286f  b908000000           mov ecx, 8
// 00512874  2bcf                 sub ecx, edi
// 00512876  33ff                 xor edi, edi
// 00512878  3bdf                 cmp ebx, edi
// 0051287a  8944244c             mov dword ptr [esp + 0x4c], eax
// 0051287e  894c2418             mov dword ptr [esp + 0x18], ecx
// 00512882  7c05                 jl 0x512889
// 00512884  83fb08               cmp ebx, 8
// 00512887  7e02                 jle 0x51288b
// 00512889  33db                 xor ebx, ebx
// 0051288b  3bc7                 cmp eax, edi
// 0051288d  7c05                 jl 0x512894
// 0051288f  83f808               cmp eax, 8
// 00512892  7e04                 jle 0x512898
// 00512894  897c244c             mov dword ptr [esp + 0x4c], edi
// 00512898  3bcf                 cmp ecx, edi
// 0051289a  7c05                 jl 0x5128a1
// 0051289c  83f908               cmp ecx, 8
// 0051289f  7e04                 jle 0x5128a5
// 005128a1  897c2418             mov dword ptr [esp + 0x18], edi
// 005128a5  663bd7               cmp dx, di
// 005128a8  763e                 jbe 0x5128e8
// 005128aa  33c0                 xor eax, eax
// 005128ac  0fb7fa               movzx edi, dx
// 005128af  90                   nop 
// 005128b0  8b9614010000         mov edx, dword ptr [esi + 0x114]
// 005128b6  03d0                 add edx, eax
// 005128b8  8acb                 mov cl, bl
// 005128ba  d22a                 shr byte ptr [edx], cl
// 005128bc  8b8e14010000         mov ecx, dword ptr [esi + 0x114]
// 005128c2  8d540101             lea edx, [ecx + eax + 1]
// 005128c6  0fb64c244c           movzx ecx, byte ptr [esp + 0x4c]
// 005128cb  d22a                 shr byte ptr [edx], cl
// 005128cd  8b9614010000         mov edx, dword ptr [esi + 0x114]
// 005128d3  0fb64c2418           movzx ecx, byte ptr [esp + 0x18]
// 005128d8  d26c0202             shr byte ptr [edx + eax + 2], cl
// 005128dc  8d540202             lea edx, [edx + eax + 2]
// 005128e0  83c003               add eax, 3
// 005128e3  83ef01               sub edi, 1
// 005128e6  75c8                 jne 0x5128b0
// 005128e8  5f                   pop edi
// 005128e9  5e                   pop esi
// 005128ea  5b                   pop ebx
// 005128eb  83c43c               add esp, 0x3c
// 005128ee  c3                   ret 
// 005128ef  90                   nop 
// 005128f0  9a1d5100bd1d51       lcall 0x511d, 0xbd00511d
// 005128f7  00ca                 add dl, cl
// 005128f9  1d5100d71d           sbb eax, 0x1dd70051
// 005128fe  51                   push ecx
// 005128ff  0030                 add byte ptr [eax], dh
// 00512901  1e                   push ds
// 00512902  51                   push ecx
// 00512903  0000                 add byte ptr [eax], al
// 00512905  010402               add dword ptr [edx + eax], eax
// 00512908  0404                 add al, 4
// 0051290a  0403                 add al, 3
// 0051290c  0404                 add al, 4
// 0051290e  0404                 add al, 4
// 00512910  0404                 add al, 4
// 00512912  0403                 add al, 3
// library libpng-1.2.7/pngrtran.c (function _png_init_read_transformations)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
