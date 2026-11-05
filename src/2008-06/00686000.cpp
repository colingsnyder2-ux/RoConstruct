// roc 2008-06 00686000  unit: Ogre::RbxSubEntity  size: 6236 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00686000
//
// 00686000  eb11                 jmp 0x686013
// 00686002  d9e0                 fchs 
// 00686004  d99c841c090000       fstp dword ptr [esp + eax*4 + 0x91c]
// 0068600b  d9c0                 fld st(0)
// 0068600d  d9ff                 fcos 
// 0068600f  d8cc                 fmul st(4)
// 00686011  d9e0                 fchs 
// 00686013  d99c84dc0c0000       fstp dword ptr [esp + eax*4 + 0xcdc]
// 0068601a  d9c0                 fld st(0)
// 0068601c  40                   inc eax
// 0068601d  3bc5                 cmp eax, ebp
// 0068601f  d9fe                 fsin 
// 00686021  89442418             mov dword ptr [esp + 0x18], eax
// 00686025  d99c8498010000       fstp dword ptr [esp + eax*4 + 0x198]
// 0068602c  d9ff                 fcos 
// 0068602e  d99c8458050000       fstp dword ptr [esp + eax*4 + 0x558]
// 00686035  7ca2                 jl 0x685fd9
// 00686037  ddd8                 fstp st(0)
// 00686039  85db                 test ebx, ebx
// 0068603b  0f84d3000000         je 0x686114
// 00686041  33c0                 xor eax, eax
// 00686043  89442418             mov dword ptr [esp + 0x18], eax
// 00686047  85ed                 test ebp, ebp
// 00686049  0f8ec5000000         jle 0x686114
// 0068604f  d809                 fmul dword ptr [ecx]
// 00686051  8b4f08               mov ecx, dword ptr [edi + 8]
// 00686054  db842444180000       fild dword ptr [esp + 0x1844]
// 0068605b  db442418             fild dword ptr [esp + 0x18]
// 0068605f  dc2538e78100         fsub qword ptr [0x81e738]
// 00686065  d8ca                 fmul st(2)
// 00686067  d8f1                 fdiv st(1)
// 00686069  d9c0                 fld st(0)
// 0068606b  d9fe                 fsin 
// 0068606d  d8cc                 fmul st(4)
// 0068606f  85c9                 test ecx, ecx
// 00686071  750d                 jne 0x686080
// 00686073  d99c845c140000       fstp dword ptr [esp + eax*4 + 0x145c]
// 0068607a  d9ff                 fcos 
// 0068607c  d8cb                 fmul st(3)
// 0068607e  eb0f                 jmp 0x68608f
// 00686080  d9e0                 fchs 
// 00686082  d99c845c140000       fstp dword ptr [esp + eax*4 + 0x145c]
// 00686089  d9ff                 fcos 
// 0068608b  d8cb                 fmul st(3)
// 0068608d  d9e0                 fchs 
// 0068608f  d99c849c100000       fstp dword ptr [esp + eax*4 + 0x109c]
// 00686096  40                   inc eax
// 00686097  3bc5                 cmp eax, ebp
// 00686099  89442418             mov dword ptr [esp + 0x18], eax
// 0068609d  7cbc                 jl 0x68605b
// 0068609f  ddda                 fstp st(2)
// 006860a1  ddd8                 fstp st(0)
// 006860a3  ddd8                 fstp st(0)
// 006860a5  d984249c010000       fld dword ptr [esp + 0x19c]
// 006860ac  d99cac9c010000       fstp dword ptr [esp + ebp*4 + 0x19c]
// 006860b3  d984245c050000       fld dword ptr [esp + 0x55c]
// 006860ba  d99cac5c050000       fstp dword ptr [esp + ebp*4 + 0x55c]
// 006860c1  85d2                 test edx, edx
// 006860c3  741c                 je 0x6860e1
// 006860c5  d984241c090000       fld dword ptr [esp + 0x91c]
// 006860cc  d99cac1c090000       fstp dword ptr [esp + ebp*4 + 0x91c]
// 006860d3  d98424dc0c0000       fld dword ptr [esp + 0xcdc]
// 006860da  d99cacdc0c0000       fstp dword ptr [esp + ebp*4 + 0xcdc]
// 006860e1  85db                 test ebx, ebx
// 006860e3  741c                 je 0x686101
// 006860e5  d984245c140000       fld dword ptr [esp + 0x145c]
// 006860ec  d99cac5c140000       fstp dword ptr [esp + ebp*4 + 0x145c]
// 006860f3  d984249c100000       fld dword ptr [esp + 0x109c]
// 006860fa  d99cac9c100000       fstp dword ptr [esp + ebp*4 + 0x109c]
// 00686101  8b470c               mov eax, dword ptr [edi + 0xc]
// 00686104  83f803               cmp eax, 3
// 00686107  0f870e170000         ja 0x68781b
// 0068610d  ff24854c786800       jmp dword ptr [eax*4 + 0x68784c]
// 00686114  ddd9                 fstp st(1)
// 00686116  eb8b                 jmp 0x6860a3
// 00686118  33c0                 xor eax, eax
// 0068611a  39842448180000       cmp dword ptr [esp + 0x1848], eax
// 00686121  89442414             mov dword ptr [esp + 0x14], eax
// 00686125  0f8ef0160000         jle 0x68781b
// 0068612b  db842448180000       fild dword ptr [esp + 0x1848]
// 00686132  d954242c             fst dword ptr [esp + 0x2c]
// 00686136  eb28                 jmp 0x686160
// 00686138  eb06                 jmp 0x686140
// 0068613a  8d9b00000000         lea ebx, [ebx]
// 00686140  d944242c             fld dword ptr [esp + 0x2c]
// 00686144  d944245c             fld dword ptr [esp + 0x5c]
// 00686148  d9842438180000       fld dword ptr [esp + 0x1838]
// 0068614f  d9842440180000       fld dword ptr [esp + 0x1840]
// 00686156  d9ca                 fxch st(2)
// 00686158  d9cb                 fxch st(3)
// 0068615a  d9c9                 fxch st(1)
// 0068615c  d9ca                 fxch st(2)
// 0068615e  d9c9                 fxch st(1)
// 00686160  db442414             fild dword ptr [esp + 0x14]
// 00686164  40                   inc eax
// 00686165  89442478             mov dword ptr [esp + 0x78], eax
// 00686169  8d4c2444             lea ecx, [esp + 0x44]
// 0068616d  d9c0                 fld st(0)
// 0068616f  d8cb                 fmul st(3)
// 00686171  d8f2                 fdiv st(2)
// 00686173  d95c241c             fstp dword ptr [esp + 0x1c]
// 00686177  db442478             fild dword ptr [esp + 0x78]
// 0068617b  d9c0                 fld st(0)
// 0068617d  decc                 fmulp st(4)
// 0068617f  d9cb                 fxch st(3)
// 00686181  d8f2                 fdiv st(2)
// 00686183  d95c2428             fstp dword ptr [esp + 0x28]
// 00686187  d8f1                 fdiv st(1)
// 00686189  d9542430             fst dword ptr [esp + 0x30]
// 0068618d  d8cc                 fmul st(4)
// 0068618f  d8eb                 fsubr st(3)
// 00686191  d95c2420             fstp dword ptr [esp + 0x20]
// 00686195  def9                 fdivp st(1)
// 00686197  d954247c             fst dword ptr [esp + 0x7c]
// 0068619b  deca                 fmulp st(2)
// 0068619d  dee1                 fsubrp st(1)
// 0068619f  d95c2424             fstp dword ptr [esp + 0x24]
// 006861a3  e82832daff           call 0x4293d0
// 006861a8  33ed                 xor ebp, ebp
// 006861aa  8d4c2460             lea ecx, [esp + 0x60]
// 006861ae  89ac2424180000       mov dword ptr [esp + 0x1824], ebp
// 006861b5  e81632daff           call 0x4293d0
// 006861ba  6816b78000           push 0x80b716
// 006861bf  8d8c2414010000       lea ecx, [esp + 0x114]
// 006861c6  c684242818000001     mov byte ptr [esp + 0x1828], 1
// 006861ce  ff1558248000         call dword ptr [0x802458]
// 006861d4  8b16                 mov edx, dword ptr [esi]
// 006861d6  8b92e0000000         mov edx, dword ptr [edx + 0xe0]
// 006861dc  6a04                 push 4
// 006861de  8d842414010000       lea eax, [esp + 0x114]
// 006861e5  50                   push eax
// 006861e6  8bce                 mov ecx, esi
// 006861e8  c684242c18000002     mov byte ptr [esp + 0x182c], 2
// 006861f0  ffd2                 call edx
// 006861f2  8d8c2410010000       lea ecx, [esp + 0x110]
// 006861f9  c684242418000001     mov byte ptr [esp + 0x1824], 1
// 00686201  ff1568248000         call dword ptr [0x802468]
// 00686207  d9ee                 fldz 
// 00686209  d85f10               fcomp dword ptr [edi + 0x10]
// 0068620c  8d4f10               lea ecx, [edi + 0x10]
// 0068620f  dfe0                 fnstsw ax
// 00686211  f6c441               test ah, 0x41
// 00686214  7a0d                 jp 0x686223
// 00686216  8b06                 mov eax, dword ptr [esi]
// 00686218  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 0068621e  51                   push ecx
// 0068621f  8bce                 mov ecx, esi
// 00686221  ffd2                 call edx
// 00686223  33db                 xor ebx, ebx
// 00686225  399c2444180000       cmp dword ptr [esp + 0x1844], ebx
// 0068622c  895c2418             mov dword ptr [esp + 0x18], ebx
// 00686230  0f8c4e0e0000         jl 0x687084
// 00686236  8b07                 mov eax, dword ptr [edi]
// 00686238  83e800               sub eax, 0
// 0068623b  7415                 je 0x686252
// 0068623d  83e801               sub eax, 1
// 00686240  752e                 jne 0x686270
// 00686242  d9849c9c100000       fld dword ptr [esp + ebx*4 + 0x109c]
// 00686249  d9849c5c140000       fld dword ptr [esp + ebx*4 + 0x145c]
// 00686250  eb0e                 jmp 0x686260
// 00686252  d9849cdc0c0000       fld dword ptr [esp + ebx*4 + 0xcdc]
// 00686259  d9849c1c090000       fld dword ptr [esp + ebx*4 + 0x91c]
// 00686260  d95c2434             fstp dword ptr [esp + 0x34]
// 00686264  d95c2438             fstp dword ptr [esp + 0x38]
// 00686268  d9442440             fld dword ptr [esp + 0x40]
// 0068626c  d95c243c             fstp dword ptr [esp + 0x3c]
// 00686270  837f0800             cmp dword ptr [edi + 8], 0
// 00686274  0f85f4060000         jne 0x68696e
// 0068627a  807f0400             cmp byte ptr [edi + 4], 0
// 0068627e  7429                 je 0x6862a9
// 00686280  d9442430             fld dword ptr [esp + 0x30]
// 00686284  8b06                 mov eax, dword ptr [esi]
// 00686286  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 0068628c  83ec08               sub esp, 8
// 0068628f  d95c2404             fstp dword ptr [esp + 4]
// 00686293  8bce                 mov ecx, esi
// 00686295  db442420             fild dword ptr [esp + 0x20]
// 00686299  dab4244c180000       fidiv dword ptr [esp + 0x184c]
// 006862a0  d9e8                 fld1 
// 006862a2  dee1                 fsubrp st(1)
// 006862a4  d91c24               fstp dword ptr [esp]
// 006862a7  ffd2                 call edx
// 006862a9  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 006862ad  2b4c2450             sub ecx, dword ptr [esp + 0x50]
// 006862b1  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006862b6  f7e9                 imul ecx
// 006862b8  d1fa                 sar edx, 1
// 006862ba  8bc2                 mov eax, edx
// 006862bc  c1e81f               shr eax, 0x1f
// 006862bf  03c2                 add eax, edx
// 006862c1  89442414             mov dword ptr [esp + 0x14], eax
// 006862c5  83f802               cmp eax, 2
// 006862c8  0f82d3020000         jb 0x6865a1
// 006862ce  2501000080           and eax, 0x80000001
// 006862d3  7905                 jns 0x6862da
// 006862d5  48                   dec eax
// 006862d6  83c8fe               or eax, 0xfffffffe
// 006862d9  40                   inc eax
// 006862da  8b06                 mov eax, dword ptr [esi]
// 006862dc  8d4c2444             lea ecx, [esp + 0x44]
// 006862e0  0f845e010000         je 0x686444
// 006862e6  05f4000000           add eax, 0xf4
// 006862eb  89442410             mov dword ptr [esp + 0x10], eax
// 006862ef  8b442414             mov eax, dword ptr [esp + 0x14]
// 006862f3  48                   dec eax
// 006862f4  50                   push eax
// 006862f5  e8866c0000           call 0x68cf80
// 006862fa  50                   push eax
// 006862fb  8b442414             mov eax, dword ptr [esp + 0x14]
// 006862ff  8b10                 mov edx, dword ptr [eax]
// 00686301  8bce                 mov ecx, esi
// 00686303  ffd2                 call edx
// 00686305  8b06                 mov eax, dword ptr [esi]
// 00686307  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068630d  55                   push ebp
// 0068630e  8bce                 mov ecx, esi
// 00686310  ffd2                 call edx
// 00686312  8b06                 mov eax, dword ptr [esi]
// 00686314  05fc000000           add eax, 0xfc
// 00686319  89442410             mov dword ptr [esp + 0x10], eax
// 0068631d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686321  48                   dec eax
// 00686322  50                   push eax
// 00686323  8d4c2464             lea ecx, [esp + 0x64]
// 00686327  45                   inc ebp
// 00686328  e8536c0000           call 0x68cf80
// 0068632d  50                   push eax
// 0068632e  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686332  8b10                 mov edx, dword ptr [eax]
// 00686334  8bce                 mov ecx, esi
// 00686336  ffd2                 call edx
// 00686338  8b06                 mov eax, dword ptr [esi]
// 0068633a  05f4000000           add eax, 0xf4
// 0068633f  89442410             mov dword ptr [esp + 0x10], eax
// 00686343  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686347  83c0fe               add eax, -2
// 0068634a  50                   push eax
// 0068634b  8d4c2448             lea ecx, [esp + 0x48]
// 0068634f  89442418             mov dword ptr [esp + 0x18], eax
// 00686353  e8286c0000           call 0x68cf80
// 00686358  50                   push eax
// 00686359  8b442414             mov eax, dword ptr [esp + 0x14]
// 0068635d  8b10                 mov edx, dword ptr [eax]
// 0068635f  8bce                 mov ecx, esi
// 00686361  ffd2                 call edx
// 00686363  8b06                 mov eax, dword ptr [esi]
// 00686365  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068636b  55                   push ebp
// 0068636c  8bce                 mov ecx, esi
// 0068636e  ffd2                 call edx
// 00686370  8b06                 mov eax, dword ptr [esi]
// 00686372  05fc000000           add eax, 0xfc
// 00686377  89442410             mov dword ptr [esp + 0x10], eax
// 0068637b  8b442414             mov eax, dword ptr [esp + 0x14]
// 0068637f  50                   push eax
// 00686380  8d4c2464             lea ecx, [esp + 0x64]
// 00686384  45                   inc ebp
// 00686385  e8f66b0000           call 0x68cf80
// 0068638a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0068638e  50                   push eax
// 0068638f  8b02                 mov eax, dword ptr [edx]
// 00686391  8bce                 mov ecx, esi
// 00686393  ffd0                 call eax
// 00686395  d9442420             fld dword ptr [esp + 0x20]
// 00686399  d9c0                 fld st(0)
// 0068639b  8b16                 mov edx, dword ptr [esi]
// 0068639d  d88c9c5c050000       fmul dword ptr [esp + ebx*4 + 0x55c]
// 006863a4  83ec0c               sub esp, 0xc
// 006863a7  8bce                 mov ecx, esi
// 006863a9  d9542420             fst dword ptr [esp + 0x20]
// 006863ad  d9849ca8010000       fld dword ptr [esp + ebx*4 + 0x1a8]
// 006863b4  deca                 fmulp st(2)
// 006863b6  d9c9                 fxch st(1)
// 006863b8  d954241c             fst dword ptr [esp + 0x1c]
// 006863bc  d94728               fld dword ptr [edi + 0x28]
// 006863bf  d8442428             fadd dword ptr [esp + 0x28]
// 006863c3  d95c2408             fstp dword ptr [esp + 8]
// 006863c7  d9c9                 fxch st(1)
// 006863c9  d84724               fadd dword ptr [edi + 0x24]
// 006863cc  d95c2404             fstp dword ptr [esp + 4]
// 006863d0  d84720               fadd dword ptr [edi + 0x20]
// 006863d3  d91c24               fstp dword ptr [esp]
// 006863d6  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 006863dc  ffd0                 call eax
// 006863de  8b16                 mov edx, dword ptr [esi]
// 006863e0  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 006863e6  55                   push ebp
// 006863e7  8bce                 mov ecx, esi
// 006863e9  ffd0                 call eax
// 006863eb  8b16                 mov edx, dword ptr [esi]
// 006863ed  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 006863f3  8d442434             lea eax, [esp + 0x34]
// 006863f7  50                   push eax
// 006863f8  8bce                 mov ecx, esi
// 006863fa  45                   inc ebp
// 006863fb  ffd2                 call edx
// 006863fd  d94720               fld dword ptr [edi + 0x20]
// 00686400  d8442410             fadd dword ptr [esp + 0x10]
// 00686404  8d8424b0000000       lea eax, [esp + 0xb0]
// 0068640b  d9442414             fld dword ptr [esp + 0x14]
// 0068640f  50                   push eax
// 00686410  d84724               fadd dword ptr [edi + 0x24]
// 00686413  8d4c2448             lea ecx, [esp + 0x48]
// 00686417  d94728               fld dword ptr [edi + 0x28]
// 0068641a  d8442420             fadd dword ptr [esp + 0x20]
// 0068641e  d9ca                 fxch st(2)
// 00686420  d99c24b4000000       fstp dword ptr [esp + 0xb4]
// 00686427  d99c24b8000000       fstp dword ptr [esp + 0xb8]
// 0068642e  d99c24bc000000       fstp dword ptr [esp + 0xbc]
// 00686435  e8167ee5ff           call 0x4de250
// 0068643a  8d4c2434             lea ecx, [esp + 0x34]
// 0068643e  51                   push ecx
// 0068643f  e9af010000           jmp 0x6865f3
// 00686444  05f4000000           add eax, 0xf4
// 00686449  89442410             mov dword ptr [esp + 0x10], eax
// 0068644d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686451  83c0fe               add eax, -2
// 00686454  50                   push eax
// 00686455  e8266b0000           call 0x68cf80
// 0068645a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0068645e  50                   push eax
// 0068645f  8b02                 mov eax, dword ptr [edx]
// 00686461  8bce                 mov ecx, esi
// 00686463  ffd0                 call eax
// 00686465  8b16                 mov edx, dword ptr [esi]
// 00686467  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068646d  55                   push ebp
// 0068646e  8bce                 mov ecx, esi
// 00686470  ffd0                 call eax
// 00686472  8b06                 mov eax, dword ptr [esi]
// 00686474  05fc000000           add eax, 0xfc
// 00686479  89442410             mov dword ptr [esp + 0x10], eax
// 0068647d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686481  83c0fe               add eax, -2
// 00686484  50                   push eax
// 00686485  8d4c2464             lea ecx, [esp + 0x64]
// 00686489  45                   inc ebp
// 0068648a  e8f16a0000           call 0x68cf80
// 0068648f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686493  50                   push eax
// 00686494  8b02                 mov eax, dword ptr [edx]
// 00686496  8bce                 mov ecx, esi
// 00686498  ffd0                 call eax
// 0068649a  8b06                 mov eax, dword ptr [esi]
// 0068649c  05f4000000           add eax, 0xf4
// 006864a1  89442410             mov dword ptr [esp + 0x10], eax
// 006864a5  8b442414             mov eax, dword ptr [esp + 0x14]
// 006864a9  48                   dec eax
// 006864aa  50                   push eax
// 006864ab  8d4c2448             lea ecx, [esp + 0x48]
// 006864af  89442418             mov dword ptr [esp + 0x18], eax
// 006864b3  e8c86a0000           call 0x68cf80
// 006864b8  8b542410             mov edx, dword ptr [esp + 0x10]
// 006864bc  50                   push eax
// 006864bd  8b02                 mov eax, dword ptr [edx]
// 006864bf  8bce                 mov ecx, esi
// 006864c1  ffd0                 call eax
// 006864c3  8b16                 mov edx, dword ptr [esi]
// 006864c5  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 006864cb  55                   push ebp
// 006864cc  8bce                 mov ecx, esi
// 006864ce  ffd0                 call eax
// 006864d0  8b06                 mov eax, dword ptr [esi]
// 006864d2  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006864d6  05fc000000           add eax, 0xfc
// 006864db  51                   push ecx
// 006864dc  8d4c2464             lea ecx, [esp + 0x64]
// 006864e0  45                   inc ebp
// 006864e1  89442414             mov dword ptr [esp + 0x14], eax
// 006864e5  e8966a0000           call 0x68cf80
// 006864ea  8b542410             mov edx, dword ptr [esp + 0x10]
// 006864ee  50                   push eax
// 006864ef  8b02                 mov eax, dword ptr [edx]
// 006864f1  8bce                 mov ecx, esi
// 006864f3  ffd0                 call eax
// 006864f5  d9442420             fld dword ptr [esp + 0x20]
// 006864f9  d9c0                 fld st(0)
// 006864fb  8b16                 mov edx, dword ptr [esi]
// 006864fd  d88c9c5c050000       fmul dword ptr [esp + ebx*4 + 0x55c]
// 00686504  83ec0c               sub esp, 0xc
// 00686507  8bce                 mov ecx, esi
// 00686509  d9542420             fst dword ptr [esp + 0x20]
// 0068650d  d9849ca8010000       fld dword ptr [esp + ebx*4 + 0x1a8]
// 00686514  deca                 fmulp st(2)
// 00686516  d9c9                 fxch st(1)
// 00686518  d954241c             fst dword ptr [esp + 0x1c]
// 0068651c  d94728               fld dword ptr [edi + 0x28]
// 0068651f  d8442428             fadd dword ptr [esp + 0x28]
// 00686523  d95c2408             fstp dword ptr [esp + 8]
// 00686527  d9c9                 fxch st(1)
// 00686529  d84724               fadd dword ptr [edi + 0x24]
// 0068652c  d95c2404             fstp dword ptr [esp + 4]
// 00686530  d84720               fadd dword ptr [edi + 0x20]
// 00686533  d91c24               fstp dword ptr [esp]
// 00686536  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0068653c  ffd0                 call eax
// 0068653e  8b16                 mov edx, dword ptr [esi]
// 00686540  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686546  55                   push ebp
// 00686547  8bce                 mov ecx, esi
// 00686549  ffd0                 call eax
// 0068654b  8b16                 mov edx, dword ptr [esi]
// 0068654d  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 00686553  8d442434             lea eax, [esp + 0x34]
// 00686557  50                   push eax
// 00686558  8bce                 mov ecx, esi
// 0068655a  45                   inc ebp
// 0068655b  ffd2                 call edx
// 0068655d  d94720               fld dword ptr [edi + 0x20]
// 00686560  d8442410             fadd dword ptr [esp + 0x10]
// 00686564  8d8424ec000000       lea eax, [esp + 0xec]
// 0068656b  d9442414             fld dword ptr [esp + 0x14]
// 0068656f  50                   push eax
// 00686570  d84724               fadd dword ptr [edi + 0x24]
// 00686573  8d4c2448             lea ecx, [esp + 0x48]
// 00686577  d94728               fld dword ptr [edi + 0x28]
// 0068657a  d8442420             fadd dword ptr [esp + 0x20]
// 0068657e  d9ca                 fxch st(2)
// 00686580  d99c24f0000000       fstp dword ptr [esp + 0xf0]
// 00686587  d99c24f4000000       fstp dword ptr [esp + 0xf4]
// 0068658e  d99c24f8000000       fstp dword ptr [esp + 0xf8]
// 00686595  e8b67ce5ff           call 0x4de250
// 0068659a  8d4c2434             lea ecx, [esp + 0x34]
// 0068659e  51                   push ecx
// 0068659f  eb52                 jmp 0x6865f3
// 006865a1  d9849c9c010000       fld dword ptr [esp + ebx*4 + 0x19c]
// 006865a8  8d94248c000000       lea edx, [esp + 0x8c]
// 006865af  d9442420             fld dword ptr [esp + 0x20]
// 006865b3  52                   push edx
// 006865b4  dcc9                 fmul st(1), st(0)
// 006865b6  8d4c2448             lea ecx, [esp + 0x48]
// 006865ba  d9c9                 fxch st(1)
// 006865bc  d84720               fadd dword ptr [edi + 0x20]
// 006865bf  d9c9                 fxch st(1)
// 006865c1  d88c9c60050000       fmul dword ptr [esp + ebx*4 + 0x560]
// 006865c8  d84724               fadd dword ptr [edi + 0x24]
// 006865cb  d94728               fld dword ptr [edi + 0x28]
// 006865ce  d8442420             fadd dword ptr [esp + 0x20]
// 006865d2  d9ca                 fxch st(2)
// 006865d4  d99c2490000000       fstp dword ptr [esp + 0x90]
// 006865db  d99c2494000000       fstp dword ptr [esp + 0x94]
// 006865e2  d99c2498000000       fstp dword ptr [esp + 0x98]
// 006865e9  e8627ce5ff           call 0x4de250
// 006865ee  8d442434             lea eax, [esp + 0x34]
// 006865f2  50                   push eax
// 006865f3  8d4c2464             lea ecx, [esp + 0x64]
// 006865f7  e8547ce5ff           call 0x4de250
// 006865fc  807f0400             cmp byte ptr [edi + 4], 0
// 00686600  7429                 je 0x68662b
// 00686602  d944247c             fld dword ptr [esp + 0x7c]
// 00686606  8b16                 mov edx, dword ptr [esi]
// 00686608  8b820c010000         mov eax, dword ptr [edx + 0x10c]
// 0068660e  83ec08               sub esp, 8
// 00686611  d95c2404             fstp dword ptr [esp + 4]
// 00686615  8bce                 mov ecx, esi
// 00686617  db442420             fild dword ptr [esp + 0x20]
// 0068661b  dab4244c180000       fidiv dword ptr [esp + 0x184c]
// 00686622  d9e8                 fld1 
// 00686624  dee1                 fsubrp st(1)
// 00686626  d91c24               fstp dword ptr [esp]
// 00686629  ffd0                 call eax
// 0068662b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0068662f  2b4c2450             sub ecx, dword ptr [esp + 0x50]
// 00686633  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00686638  f7e9                 imul ecx
// 0068663a  d1fa                 sar edx, 1
// 0068663c  8bc2                 mov eax, edx
// 0068663e  c1e81f               shr eax, 0x1f
// 00686641  03c2                 add eax, edx
// 00686643  89442414             mov dword ptr [esp + 0x14], eax
// 00686647  83f802               cmp eax, 2
// 0068664a  0f82d6020000         jb 0x686926
// 00686650  2501000080           and eax, 0x80000001
// 00686655  7905                 jns 0x68665c
// 00686657  48                   dec eax
// 00686658  83c8fe               or eax, 0xfffffffe
// 0068665b  40                   inc eax
// 0068665c  8b06                 mov eax, dword ptr [esi]
// 0068665e  8d4c2444             lea ecx, [esp + 0x44]
// 00686662  0f845e010000         je 0x6867c6
// 00686668  05f4000000           add eax, 0xf4
// 0068666d  89442410             mov dword ptr [esp + 0x10], eax
// 00686671  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686675  48                   dec eax
// 00686676  50                   push eax
// 00686677  e804690000           call 0x68cf80
// 0068667c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686680  50                   push eax
// 00686681  8b02                 mov eax, dword ptr [edx]
// 00686683  8bce                 mov ecx, esi
// 00686685  ffd0                 call eax
// 00686687  8b16                 mov edx, dword ptr [esi]
// 00686689  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068668f  55                   push ebp
// 00686690  8bce                 mov ecx, esi
// 00686692  ffd0                 call eax
// 00686694  8b06                 mov eax, dword ptr [esi]
// 00686696  05fc000000           add eax, 0xfc
// 0068669b  89442410             mov dword ptr [esp + 0x10], eax
// 0068669f  8b442414             mov eax, dword ptr [esp + 0x14]
// 006866a3  48                   dec eax
// 006866a4  50                   push eax
// 006866a5  8d4c2464             lea ecx, [esp + 0x64]
// 006866a9  45                   inc ebp
// 006866aa  e8d1680000           call 0x68cf80
// 006866af  8b542410             mov edx, dword ptr [esp + 0x10]
// 006866b3  50                   push eax
// 006866b4  8b02                 mov eax, dword ptr [edx]
// 006866b6  8bce                 mov ecx, esi
// 006866b8  ffd0                 call eax
// 006866ba  8b06                 mov eax, dword ptr [esi]
// 006866bc  05f4000000           add eax, 0xf4
// 006866c1  89442410             mov dword ptr [esp + 0x10], eax
// 006866c5  8b442414             mov eax, dword ptr [esp + 0x14]
// 006866c9  83c0fe               add eax, -2
// 006866cc  50                   push eax
// 006866cd  8d4c2448             lea ecx, [esp + 0x48]
// 006866d1  8944241c             mov dword ptr [esp + 0x1c], eax
// 006866d5  e8a6680000           call 0x68cf80
// 006866da  8b542410             mov edx, dword ptr [esp + 0x10]
// 006866de  50                   push eax
// 006866df  8b02                 mov eax, dword ptr [edx]
// 006866e1  8bce                 mov ecx, esi
// 006866e3  ffd0                 call eax
// 006866e5  8b16                 mov edx, dword ptr [esi]
// 006866e7  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 006866ed  55                   push ebp
// 006866ee  8bce                 mov ecx, esi
// 006866f0  ffd0                 call eax
// 006866f2  8b06                 mov eax, dword ptr [esi]
// 006866f4  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006866f8  05fc000000           add eax, 0xfc
// 006866fd  51                   push ecx
// 006866fe  8d4c2464             lea ecx, [esp + 0x64]
// 00686702  45                   inc ebp
// 00686703  89442414             mov dword ptr [esp + 0x14], eax
// 00686707  e874680000           call 0x68cf80
// 0068670c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686710  50                   push eax
// 00686711  8b02                 mov eax, dword ptr [edx]
// 00686713  8bce                 mov ecx, esi
// 00686715  ffd0                 call eax
// 00686717  d9442424             fld dword ptr [esp + 0x24]
// 0068671b  d9c0                 fld st(0)
// 0068671d  8b16                 mov edx, dword ptr [esi]
// 0068671f  d88c9c5c050000       fmul dword ptr [esp + ebx*4 + 0x55c]
// 00686726  83ec0c               sub esp, 0xc
// 00686729  8bce                 mov ecx, esi
// 0068672b  d954241c             fst dword ptr [esp + 0x1c]
// 0068672f  d9849ca8010000       fld dword ptr [esp + ebx*4 + 0x1a8]
// 00686736  deca                 fmulp st(2)
// 00686738  d9c9                 fxch st(1)
// 0068673a  d9542420             fst dword ptr [esp + 0x20]
// 0068673e  d94728               fld dword ptr [edi + 0x28]
// 00686741  d8442434             fadd dword ptr [esp + 0x34]
// 00686745  d95c2408             fstp dword ptr [esp + 8]
// 00686749  d9c9                 fxch st(1)
// 0068674b  d84724               fadd dword ptr [edi + 0x24]
// 0068674e  d95c2404             fstp dword ptr [esp + 4]
// 00686752  d84720               fadd dword ptr [edi + 0x20]
// 00686755  d91c24               fstp dword ptr [esp]
// 00686758  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0068675e  ffd0                 call eax
// 00686760  8b16                 mov edx, dword ptr [esi]
// 00686762  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686768  55                   push ebp
// 00686769  8bce                 mov ecx, esi
// 0068676b  ffd0                 call eax
// 0068676d  8b16                 mov edx, dword ptr [esi]
// 0068676f  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 00686775  8d442434             lea eax, [esp + 0x34]
// 00686779  50                   push eax
// 0068677a  8bce                 mov ecx, esi
// 0068677c  45                   inc ebp
// 0068677d  ffd2                 call edx
// 0068677f  d94720               fld dword ptr [edi + 0x20]
// 00686782  d8442414             fadd dword ptr [esp + 0x14]
// 00686786  8d842404010000       lea eax, [esp + 0x104]
// 0068678d  d9442410             fld dword ptr [esp + 0x10]
// 00686791  50                   push eax
// 00686792  d84724               fadd dword ptr [edi + 0x24]
// 00686795  8d4c2448             lea ecx, [esp + 0x48]
// 00686799  d94728               fld dword ptr [edi + 0x28]
// 0068679c  d844242c             fadd dword ptr [esp + 0x2c]
// 006867a0  d9ca                 fxch st(2)
// 006867a2  d99c2408010000       fstp dword ptr [esp + 0x108]
// 006867a9  d99c240c010000       fstp dword ptr [esp + 0x10c]
// 006867b0  d99c2410010000       fstp dword ptr [esp + 0x110]
// 006867b7  e8947ae5ff           call 0x4de250
// 006867bc  8d4c2434             lea ecx, [esp + 0x34]
// 006867c0  51                   push ecx
// 006867c1  e9a3080000           jmp 0x687069
// 006867c6  05f4000000           add eax, 0xf4
// 006867cb  89442410             mov dword ptr [esp + 0x10], eax
// 006867cf  8b442414             mov eax, dword ptr [esp + 0x14]
// 006867d3  83c0fe               add eax, -2
// 006867d6  50                   push eax
// 006867d7  e8a4670000           call 0x68cf80
// 006867dc  8b542410             mov edx, dword ptr [esp + 0x10]
// 006867e0  50                   push eax
// 006867e1  8b02                 mov eax, dword ptr [edx]
// 006867e3  8bce                 mov ecx, esi
// 006867e5  ffd0                 call eax
// 006867e7  8b16                 mov edx, dword ptr [esi]
// 006867e9  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 006867ef  55                   push ebp
// 006867f0  8bce                 mov ecx, esi
// 006867f2  ffd0                 call eax
// 006867f4  8b06                 mov eax, dword ptr [esi]
// 006867f6  05fc000000           add eax, 0xfc
// 006867fb  89442410             mov dword ptr [esp + 0x10], eax
// 006867ff  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686803  83c0fe               add eax, -2
// 00686806  50                   push eax
// 00686807  8d4c2464             lea ecx, [esp + 0x64]
// 0068680b  45                   inc ebp
// 0068680c  e86f670000           call 0x68cf80
// 00686811  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686815  50                   push eax
// 00686816  8b02                 mov eax, dword ptr [edx]
// 00686818  8bce                 mov ecx, esi
// 0068681a  ffd0                 call eax
// 0068681c  8b06                 mov eax, dword ptr [esi]
// 0068681e  05f4000000           add eax, 0xf4
// 00686823  89442410             mov dword ptr [esp + 0x10], eax
// 00686827  8b442414             mov eax, dword ptr [esp + 0x14]
// 0068682b  48                   dec eax
// 0068682c  50                   push eax
// 0068682d  8d4c2448             lea ecx, [esp + 0x48]
// 00686831  8944241c             mov dword ptr [esp + 0x1c], eax
// 00686835  e846670000           call 0x68cf80
// 0068683a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0068683e  50                   push eax
// 0068683f  8b02                 mov eax, dword ptr [edx]
// 00686841  8bce                 mov ecx, esi
// 00686843  ffd0                 call eax
// 00686845  8b16                 mov edx, dword ptr [esi]
// 00686847  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068684d  55                   push ebp
// 0068684e  8bce                 mov ecx, esi
// 00686850  ffd0                 call eax
// 00686852  8b06                 mov eax, dword ptr [esi]
// 00686854  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00686858  05fc000000           add eax, 0xfc
// 0068685d  51                   push ecx
// 0068685e  8d4c2464             lea ecx, [esp + 0x64]
// 00686862  45                   inc ebp
// 00686863  89442414             mov dword ptr [esp + 0x14], eax
// 00686867  e814670000           call 0x68cf80
// 0068686c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686870  50                   push eax
// 00686871  8b02                 mov eax, dword ptr [edx]
// 00686873  8bce                 mov ecx, esi
// 00686875  ffd0                 call eax
// 00686877  d9442424             fld dword ptr [esp + 0x24]
// 0068687b  d9c0                 fld st(0)
// 0068687d  8b16                 mov edx, dword ptr [esi]
// 0068687f  d88c9c5c050000       fmul dword ptr [esp + ebx*4 + 0x55c]
// 00686886  83ec0c               sub esp, 0xc
// 00686889  8bce                 mov ecx, esi
// 0068688b  d954241c             fst dword ptr [esp + 0x1c]
// 0068688f  d9849ca8010000       fld dword ptr [esp + ebx*4 + 0x1a8]
// 00686896  deca                 fmulp st(2)
// 00686898  d9c9                 fxch st(1)
// 0068689a  d9542420             fst dword ptr [esp + 0x20]
// 0068689e  d94728               fld dword ptr [edi + 0x28]
// 006868a1  d8442434             fadd dword ptr [esp + 0x34]
// 006868a5  d95c2408             fstp dword ptr [esp + 8]
// 006868a9  d9c9                 fxch st(1)
// 006868ab  d84724               fadd dword ptr [edi + 0x24]
// 006868ae  d95c2404             fstp dword ptr [esp + 4]
// 006868b2  d84720               fadd dword ptr [edi + 0x20]
// 006868b5  d91c24               fstp dword ptr [esp]
// 006868b8  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 006868be  ffd0                 call eax
// 006868c0  8b16                 mov edx, dword ptr [esi]
// 006868c2  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 006868c8  55                   push ebp
// 006868c9  8bce                 mov ecx, esi
// 006868cb  ffd0                 call eax
// 006868cd  8b16                 mov edx, dword ptr [esi]
// 006868cf  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 006868d5  8d442434             lea eax, [esp + 0x34]
// 006868d9  50                   push eax
// 006868da  8bce                 mov ecx, esi
// 006868dc  45                   inc ebp
// 006868dd  ffd2                 call edx
// 006868df  d94720               fld dword ptr [edi + 0x20]
// 006868e2  d8442414             fadd dword ptr [esp + 0x14]
// 006868e6  8d8424f8000000       lea eax, [esp + 0xf8]
// 006868ed  d9442410             fld dword ptr [esp + 0x10]
// 006868f1  50                   push eax
// 006868f2  d84724               fadd dword ptr [edi + 0x24]
// 006868f5  8d4c2448             lea ecx, [esp + 0x48]
// 006868f9  d94728               fld dword ptr [edi + 0x28]
// 006868fc  d844242c             fadd dword ptr [esp + 0x2c]
// 00686900  d9ca                 fxch st(2)
// 00686902  d99c24fc000000       fstp dword ptr [esp + 0xfc]
// 00686909  d99c2400010000       fstp dword ptr [esp + 0x100]
// 00686910  d99c2404010000       fstp dword ptr [esp + 0x104]
// 00686917  e83479e5ff           call 0x4de250
// 0068691c  8d4c2434             lea ecx, [esp + 0x34]
// 00686920  51                   push ecx
// 00686921  e943070000           jmp 0x687069
// 00686926  d9849c9c010000       fld dword ptr [esp + ebx*4 + 0x19c]
// 0068692d  8d942480000000       lea edx, [esp + 0x80]
// 00686934  d9442424             fld dword ptr [esp + 0x24]
// 00686938  dcc9                 fmul st(1), st(0)
// 0068693a  d9c9                 fxch st(1)
// 0068693c  d84720               fadd dword ptr [edi + 0x20]
// 0068693f  d9c9                 fxch st(1)
// 00686941  d88c9c5c050000       fmul dword ptr [esp + ebx*4 + 0x55c]
// 00686948  d84724               fadd dword ptr [edi + 0x24]
// 0068694b  d94728               fld dword ptr [edi + 0x28]
// 0068694e  d8442428             fadd dword ptr [esp + 0x28]
// 00686952  d9ca                 fxch st(2)
// 00686954  d99c2480000000       fstp dword ptr [esp + 0x80]
// 0068695b  d99c2484000000       fstp dword ptr [esp + 0x84]
// 00686962  d99c2488000000       fstp dword ptr [esp + 0x88]
// 00686969  e9ec060000           jmp 0x68705a
// 0068696e  807f0400             cmp byte ptr [edi + 4], 0
// 00686972  7429                 je 0x68699d
// 00686974  d944247c             fld dword ptr [esp + 0x7c]
// 00686978  8b16                 mov edx, dword ptr [esi]
// 0068697a  8b820c010000         mov eax, dword ptr [edx + 0x10c]
// 00686980  83ec08               sub esp, 8
// 00686983  d95c2404             fstp dword ptr [esp + 4]
// 00686987  8bce                 mov ecx, esi
// 00686989  db442420             fild dword ptr [esp + 0x20]
// 0068698d  dab4244c180000       fidiv dword ptr [esp + 0x184c]
// 00686994  d9e8                 fld1 
// 00686996  dee1                 fsubrp st(1)
// 00686998  d91c24               fstp dword ptr [esp]
// 0068699b  ffd0                 call eax
// 0068699d  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 006869a1  2b4c2450             sub ecx, dword ptr [esp + 0x50]
// 006869a5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006869aa  f7e9                 imul ecx
// 006869ac  d1fa                 sar edx, 1
// 006869ae  8bc2                 mov eax, edx
// 006869b0  c1e81f               shr eax, 0x1f
// 006869b3  03c2                 add eax, edx
// 006869b5  89442414             mov dword ptr [esp + 0x14], eax
// 006869b9  83f802               cmp eax, 2
// 006869bc  0f82d3020000         jb 0x686c95
// 006869c2  2501000080           and eax, 0x80000001
// 006869c7  7905                 jns 0x6869ce
// 006869c9  48                   dec eax
// 006869ca  83c8fe               or eax, 0xfffffffe
// 006869cd  40                   inc eax
// 006869ce  8b06                 mov eax, dword ptr [esi]
// 006869d0  8d4c2444             lea ecx, [esp + 0x44]
// 006869d4  0f845e010000         je 0x686b38
// 006869da  05f4000000           add eax, 0xf4
// 006869df  89442410             mov dword ptr [esp + 0x10], eax
// 006869e3  8b442414             mov eax, dword ptr [esp + 0x14]
// 006869e7  48                   dec eax
// 006869e8  50                   push eax
// 006869e9  e892650000           call 0x68cf80
// 006869ee  8b542410             mov edx, dword ptr [esp + 0x10]
// 006869f2  50                   push eax
// 006869f3  8b02                 mov eax, dword ptr [edx]
// 006869f5  8bce                 mov ecx, esi
// 006869f7  ffd0                 call eax
// 006869f9  8b16                 mov edx, dword ptr [esi]
// 006869fb  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686a01  55                   push ebp
// 00686a02  8bce                 mov ecx, esi
// 00686a04  ffd0                 call eax
// 00686a06  8b06                 mov eax, dword ptr [esi]
// 00686a08  05fc000000           add eax, 0xfc
// 00686a0d  89442410             mov dword ptr [esp + 0x10], eax
// 00686a11  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686a15  48                   dec eax
// 00686a16  50                   push eax
// 00686a17  8d4c2464             lea ecx, [esp + 0x64]
// 00686a1b  45                   inc ebp
// 00686a1c  e85f650000           call 0x68cf80
// 00686a21  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686a25  50                   push eax
// 00686a26  8b02                 mov eax, dword ptr [edx]
// 00686a28  8bce                 mov ecx, esi
// 00686a2a  ffd0                 call eax
// 00686a2c  8b06                 mov eax, dword ptr [esi]
// 00686a2e  05f4000000           add eax, 0xf4
// 00686a33  89442410             mov dword ptr [esp + 0x10], eax
// 00686a37  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686a3b  83c0fe               add eax, -2
// 00686a3e  50                   push eax
// 00686a3f  8d4c2448             lea ecx, [esp + 0x48]
// 00686a43  89442418             mov dword ptr [esp + 0x18], eax
// 00686a47  e834650000           call 0x68cf80
// 00686a4c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686a50  50                   push eax
// 00686a51  8b02                 mov eax, dword ptr [edx]
// 00686a53  8bce                 mov ecx, esi
// 00686a55  ffd0                 call eax
// 00686a57  8b16                 mov edx, dword ptr [esi]
// 00686a59  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686a5f  55                   push ebp
// 00686a60  8bce                 mov ecx, esi
// 00686a62  ffd0                 call eax
// 00686a64  8b06                 mov eax, dword ptr [esi]
// 00686a66  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00686a6a  05fc000000           add eax, 0xfc
// 00686a6f  51                   push ecx
// 00686a70  8d4c2464             lea ecx, [esp + 0x64]
// 00686a74  45                   inc ebp
// 00686a75  89442414             mov dword ptr [esp + 0x14], eax
// 00686a79  e802650000           call 0x68cf80
// 00686a7e  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686a82  50                   push eax
// 00686a83  8b02                 mov eax, dword ptr [edx]
// 00686a85  8bce                 mov ecx, esi
// 00686a87  ffd0                 call eax
// 00686a89  d9442424             fld dword ptr [esp + 0x24]
// 00686a8d  d9c0                 fld st(0)
// 00686a8f  8b16                 mov edx, dword ptr [esi]
// 00686a91  d88c9c5c050000       fmul dword ptr [esp + ebx*4 + 0x55c]
// 00686a98  83ec0c               sub esp, 0xc
// 00686a9b  8bce                 mov ecx, esi
// 00686a9d  d954241c             fst dword ptr [esp + 0x1c]
// 00686aa1  d9849ca8010000       fld dword ptr [esp + ebx*4 + 0x1a8]
// 00686aa8  deca                 fmulp st(2)
// 00686aaa  d9c9                 fxch st(1)
// 00686aac  d9542420             fst dword ptr [esp + 0x20]
// 00686ab0  d94728               fld dword ptr [edi + 0x28]
// 00686ab3  d8442434             fadd dword ptr [esp + 0x34]
// 00686ab7  d95c2408             fstp dword ptr [esp + 8]
// 00686abb  d9c9                 fxch st(1)
// 00686abd  d84724               fadd dword ptr [edi + 0x24]
// 00686ac0  d95c2404             fstp dword ptr [esp + 4]
// 00686ac4  d84720               fadd dword ptr [edi + 0x20]
// 00686ac7  d91c24               fstp dword ptr [esp]
// 00686aca  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00686ad0  ffd0                 call eax
// 00686ad2  8b16                 mov edx, dword ptr [esi]
// 00686ad4  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686ada  55                   push ebp
// 00686adb  8bce                 mov ecx, esi
// 00686add  ffd0                 call eax
// 00686adf  8b16                 mov edx, dword ptr [esi]
// 00686ae1  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 00686ae7  8d442434             lea eax, [esp + 0x34]
// 00686aeb  50                   push eax
// 00686aec  8bce                 mov ecx, esi
// 00686aee  45                   inc ebp
// 00686aef  ffd2                 call edx
// 00686af1  d94720               fld dword ptr [edi + 0x20]
// 00686af4  d8442414             fadd dword ptr [esp + 0x14]
// 00686af8  8d8424e0000000       lea eax, [esp + 0xe0]
// 00686aff  d9442410             fld dword ptr [esp + 0x10]
// 00686b03  50                   push eax
// 00686b04  d84724               fadd dword ptr [edi + 0x24]
// 00686b07  8d4c2448             lea ecx, [esp + 0x48]
// 00686b0b  d94728               fld dword ptr [edi + 0x28]
// 00686b0e  d844242c             fadd dword ptr [esp + 0x2c]
// 00686b12  d9ca                 fxch st(2)
// 00686b14  d99c24e4000000       fstp dword ptr [esp + 0xe4]
// 00686b1b  d99c24e8000000       fstp dword ptr [esp + 0xe8]
// 00686b22  d99c24ec000000       fstp dword ptr [esp + 0xec]
// 00686b29  e82277e5ff           call 0x4de250
// 00686b2e  8d4c2434             lea ecx, [esp + 0x34]
// 00686b32  51                   push ecx
// 00686b33  e9af010000           jmp 0x686ce7
// 00686b38  05f4000000           add eax, 0xf4
// 00686b3d  89442410             mov dword ptr [esp + 0x10], eax
// 00686b41  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686b45  83c0fe               add eax, -2
// 00686b48  50                   push eax
// 00686b49  e832640000           call 0x68cf80
// 00686b4e  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686b52  50                   push eax
// 00686b53  8b02                 mov eax, dword ptr [edx]
// 00686b55  8bce                 mov ecx, esi
// 00686b57  ffd0                 call eax
// 00686b59  8b16                 mov edx, dword ptr [esi]
// 00686b5b  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686b61  55                   push ebp
// 00686b62  8bce                 mov ecx, esi
// 00686b64  ffd0                 call eax
// 00686b66  8b06                 mov eax, dword ptr [esi]
// 00686b68  05fc000000           add eax, 0xfc
// 00686b6d  89442410             mov dword ptr [esp + 0x10], eax
// 00686b71  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686b75  83c0fe               add eax, -2
// 00686b78  50                   push eax
// 00686b79  8d4c2464             lea ecx, [esp + 0x64]
// 00686b7d  45                   inc ebp
// 00686b7e  e8fd630000           call 0x68cf80
// 00686b83  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686b87  50                   push eax
// 00686b88  8b02                 mov eax, dword ptr [edx]
// 00686b8a  8bce                 mov ecx, esi
// 00686b8c  ffd0                 call eax
// 00686b8e  8b06                 mov eax, dword ptr [esi]
// 00686b90  05f4000000           add eax, 0xf4
// 00686b95  89442410             mov dword ptr [esp + 0x10], eax
// 00686b99  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686b9d  48                   dec eax
// 00686b9e  50                   push eax
// 00686b9f  8d4c2448             lea ecx, [esp + 0x48]
// 00686ba3  89442418             mov dword ptr [esp + 0x18], eax
// 00686ba7  e8d4630000           call 0x68cf80
// 00686bac  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686bb0  50                   push eax
// 00686bb1  8b02                 mov eax, dword ptr [edx]
// 00686bb3  8bce                 mov ecx, esi
// 00686bb5  ffd0                 call eax
// 00686bb7  8b16                 mov edx, dword ptr [esi]
// 00686bb9  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686bbf  55                   push ebp
// 00686bc0  8bce                 mov ecx, esi
// 00686bc2  ffd0                 call eax
// 00686bc4  8b06                 mov eax, dword ptr [esi]
// 00686bc6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00686bca  05fc000000           add eax, 0xfc
// 00686bcf  51                   push ecx
// 00686bd0  8d4c2464             lea ecx, [esp + 0x64]
// 00686bd4  45                   inc ebp
// 00686bd5  89442414             mov dword ptr [esp + 0x14], eax
// 00686bd9  e8a2630000           call 0x68cf80
// 00686bde  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686be2  50                   push eax
// 00686be3  8b02                 mov eax, dword ptr [edx]
// 00686be5  8bce                 mov ecx, esi
// 00686be7  ffd0                 call eax
// 00686be9  d9442424             fld dword ptr [esp + 0x24]
// 00686bed  d9c0                 fld st(0)
// 00686bef  8b16                 mov edx, dword ptr [esi]
// 00686bf1  d88c9c5c050000       fmul dword ptr [esp + ebx*4 + 0x55c]
// 00686bf8  83ec0c               sub esp, 0xc
// 00686bfb  8bce                 mov ecx, esi
// 00686bfd  d954241c             fst dword ptr [esp + 0x1c]
// 00686c01  d9849ca8010000       fld dword ptr [esp + ebx*4 + 0x1a8]
// 00686c08  deca                 fmulp st(2)
// 00686c0a  d9c9                 fxch st(1)
// 00686c0c  d9542420             fst dword ptr [esp + 0x20]
// 00686c10  d94728               fld dword ptr [edi + 0x28]
// 00686c13  d8442434             fadd dword ptr [esp + 0x34]
// 00686c17  d95c2408             fstp dword ptr [esp + 8]
// 00686c1b  d9c9                 fxch st(1)
// 00686c1d  d84724               fadd dword ptr [edi + 0x24]
// 00686c20  d95c2404             fstp dword ptr [esp + 4]
// 00686c24  d84720               fadd dword ptr [edi + 0x20]
// 00686c27  d91c24               fstp dword ptr [esp]
// 00686c2a  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00686c30  ffd0                 call eax
// 00686c32  8b16                 mov edx, dword ptr [esi]
// 00686c34  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686c3a  55                   push ebp
// 00686c3b  8bce                 mov ecx, esi
// 00686c3d  ffd0                 call eax
// 00686c3f  8b16                 mov edx, dword ptr [esi]
// 00686c41  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 00686c47  8d442434             lea eax, [esp + 0x34]
// 00686c4b  50                   push eax
// 00686c4c  8bce                 mov ecx, esi
// 00686c4e  45                   inc ebp
// 00686c4f  ffd2                 call edx
// 00686c51  d94720               fld dword ptr [edi + 0x20]
// 00686c54  d8442414             fadd dword ptr [esp + 0x14]
// 00686c58  8d8424c8000000       lea eax, [esp + 0xc8]
// 00686c5f  d9442410             fld dword ptr [esp + 0x10]
// 00686c63  50                   push eax
// 00686c64  d84724               fadd dword ptr [edi + 0x24]
// 00686c67  8d4c2448             lea ecx, [esp + 0x48]
// 00686c6b  d94728               fld dword ptr [edi + 0x28]
// 00686c6e  d844242c             fadd dword ptr [esp + 0x2c]
// 00686c72  d9ca                 fxch st(2)
// 00686c74  d99c24cc000000       fstp dword ptr [esp + 0xcc]
// 00686c7b  d99c24d0000000       fstp dword ptr [esp + 0xd0]
// 00686c82  d99c24d4000000       fstp dword ptr [esp + 0xd4]
// 00686c89  e8c275e5ff           call 0x4de250
// 00686c8e  8d4c2434             lea ecx, [esp + 0x34]
// 00686c92  51                   push ecx
// 00686c93  eb52                 jmp 0x686ce7
// 00686c95  d9849c9c010000       fld dword ptr [esp + ebx*4 + 0x19c]
// 00686c9c  8d942498000000       lea edx, [esp + 0x98]
// 00686ca3  d9442424             fld dword ptr [esp + 0x24]
// 00686ca7  52                   push edx
// 00686ca8  dcc9                 fmul st(1), st(0)
// 00686caa  8d4c2448             lea ecx, [esp + 0x48]
// 00686cae  d9c9                 fxch st(1)
// 00686cb0  d84720               fadd dword ptr [edi + 0x20]
// 00686cb3  d9c9                 fxch st(1)
// 00686cb5  d88c9c60050000       fmul dword ptr [esp + ebx*4 + 0x560]
// 00686cbc  d84724               fadd dword ptr [edi + 0x24]
// 00686cbf  d94728               fld dword ptr [edi + 0x28]
// 00686cc2  d844242c             fadd dword ptr [esp + 0x2c]
// 00686cc6  d9ca                 fxch st(2)
// 00686cc8  d99c249c000000       fstp dword ptr [esp + 0x9c]
// 00686ccf  d99c24a0000000       fstp dword ptr [esp + 0xa0]
// 00686cd6  d99c24a4000000       fstp dword ptr [esp + 0xa4]
// 00686cdd  e86e75e5ff           call 0x4de250
// 00686ce2  8d442434             lea eax, [esp + 0x34]
// 00686ce6  50                   push eax
// 00686ce7  8d4c2464             lea ecx, [esp + 0x64]
// 00686ceb  e86075e5ff           call 0x4de250
// 00686cf0  807f0400             cmp byte ptr [edi + 4], 0
// 00686cf4  7429                 je 0x686d1f
// 00686cf6  d9442430             fld dword ptr [esp + 0x30]
// 00686cfa  8b16                 mov edx, dword ptr [esi]
// 00686cfc  8b820c010000         mov eax, dword ptr [edx + 0x10c]
// 00686d02  83ec08               sub esp, 8
// 00686d05  d95c2404             fstp dword ptr [esp + 4]
// 00686d09  8bce                 mov ecx, esi
// 00686d0b  db442420             fild dword ptr [esp + 0x20]
// 00686d0f  dab4244c180000       fidiv dword ptr [esp + 0x184c]
// 00686d16  d9e8                 fld1 
// 00686d18  dee1                 fsubrp st(1)
// 00686d1a  d91c24               fstp dword ptr [esp]
// 00686d1d  ffd0                 call eax
// 00686d1f  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00686d23  2b4c2450             sub ecx, dword ptr [esp + 0x50]
// 00686d27  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00686d2c  f7e9                 imul ecx
// 00686d2e  d1fa                 sar edx, 1
// 00686d30  8bc2                 mov eax, edx
// 00686d32  c1e81f               shr eax, 0x1f
// 00686d35  03c2                 add eax, edx
// 00686d37  89442414             mov dword ptr [esp + 0x14], eax
// 00686d3b  83f802               cmp eax, 2
// 00686d3e  0f82d3020000         jb 0x687017
// 00686d44  2501000080           and eax, 0x80000001
// 00686d49  7905                 jns 0x686d50
// 00686d4b  48                   dec eax
// 00686d4c  83c8fe               or eax, 0xfffffffe
// 00686d4f  40                   inc eax
// 00686d50  8b06                 mov eax, dword ptr [esi]
// 00686d52  8d4c2444             lea ecx, [esp + 0x44]
// 00686d56  0f845e010000         je 0x686eba
// 00686d5c  05f4000000           add eax, 0xf4
// 00686d61  89442410             mov dword ptr [esp + 0x10], eax
// 00686d65  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686d69  48                   dec eax
// 00686d6a  50                   push eax
// 00686d6b  e810620000           call 0x68cf80
// 00686d70  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686d74  50                   push eax
// 00686d75  8b02                 mov eax, dword ptr [edx]
// 00686d77  8bce                 mov ecx, esi
// 00686d79  ffd0                 call eax
// 00686d7b  8b16                 mov edx, dword ptr [esi]
// 00686d7d  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686d83  55                   push ebp
// 00686d84  8bce                 mov ecx, esi
// 00686d86  ffd0                 call eax
// 00686d88  8b06                 mov eax, dword ptr [esi]
// 00686d8a  05fc000000           add eax, 0xfc
// 00686d8f  89442410             mov dword ptr [esp + 0x10], eax
// 00686d93  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686d97  48                   dec eax
// 00686d98  50                   push eax
// 00686d99  8d4c2464             lea ecx, [esp + 0x64]
// 00686d9d  45                   inc ebp
// 00686d9e  e8dd610000           call 0x68cf80
// 00686da3  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686da7  50                   push eax
// 00686da8  8b02                 mov eax, dword ptr [edx]
// 00686daa  8bce                 mov ecx, esi
// 00686dac  ffd0                 call eax
// 00686dae  8b06                 mov eax, dword ptr [esi]
// 00686db0  05f4000000           add eax, 0xf4
// 00686db5  89442410             mov dword ptr [esp + 0x10], eax
// 00686db9  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686dbd  83c0fe               add eax, -2
// 00686dc0  50                   push eax
// 00686dc1  8d4c2448             lea ecx, [esp + 0x48]
// 00686dc5  8944241c             mov dword ptr [esp + 0x1c], eax
// 00686dc9  e8b2610000           call 0x68cf80
// 00686dce  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686dd2  50                   push eax
// 00686dd3  8b02                 mov eax, dword ptr [edx]
// 00686dd5  8bce                 mov ecx, esi
// 00686dd7  ffd0                 call eax
// 00686dd9  8b16                 mov edx, dword ptr [esi]
// 00686ddb  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686de1  55                   push ebp
// 00686de2  8bce                 mov ecx, esi
// 00686de4  ffd0                 call eax
// 00686de6  8b06                 mov eax, dword ptr [esi]
// 00686de8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00686dec  05fc000000           add eax, 0xfc
// 00686df1  51                   push ecx
// 00686df2  8d4c2464             lea ecx, [esp + 0x64]
// 00686df6  45                   inc ebp
// 00686df7  89442414             mov dword ptr [esp + 0x14], eax
// 00686dfb  e880610000           call 0x68cf80
// 00686e00  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686e04  50                   push eax
// 00686e05  8b02                 mov eax, dword ptr [edx]
// 00686e07  8bce                 mov ecx, esi
// 00686e09  ffd0                 call eax
// 00686e0b  d9442420             fld dword ptr [esp + 0x20]
// 00686e0f  d9c0                 fld st(0)
// 00686e11  8b16                 mov edx, dword ptr [esi]
// 00686e13  d88c9c5c050000       fmul dword ptr [esp + ebx*4 + 0x55c]
// 00686e1a  83ec0c               sub esp, 0xc
// 00686e1d  8bce                 mov ecx, esi
// 00686e1f  d9542420             fst dword ptr [esp + 0x20]
// 00686e23  d9849ca8010000       fld dword ptr [esp + ebx*4 + 0x1a8]
// 00686e2a  deca                 fmulp st(2)
// 00686e2c  d9c9                 fxch st(1)
// 00686e2e  d954241c             fst dword ptr [esp + 0x1c]
// 00686e32  d94728               fld dword ptr [edi + 0x28]
// 00686e35  d8442428             fadd dword ptr [esp + 0x28]
// 00686e39  d95c2408             fstp dword ptr [esp + 8]
// 00686e3d  d9c9                 fxch st(1)
// 00686e3f  d84724               fadd dword ptr [edi + 0x24]
// 00686e42  d95c2404             fstp dword ptr [esp + 4]
// 00686e46  d84720               fadd dword ptr [edi + 0x20]
// 00686e49  d91c24               fstp dword ptr [esp]
// 00686e4c  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00686e52  ffd0                 call eax
// 00686e54  8b16                 mov edx, dword ptr [esi]
// 00686e56  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686e5c  55                   push ebp
// 00686e5d  8bce                 mov ecx, esi
// 00686e5f  ffd0                 call eax
// 00686e61  8b16                 mov edx, dword ptr [esi]
// 00686e63  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 00686e69  8d442434             lea eax, [esp + 0x34]
// 00686e6d  50                   push eax
// 00686e6e  8bce                 mov ecx, esi
// 00686e70  45                   inc ebp
// 00686e71  ffd2                 call edx
// 00686e73  d94720               fld dword ptr [edi + 0x20]
// 00686e76  d8442410             fadd dword ptr [esp + 0x10]
// 00686e7a  8d8424a4000000       lea eax, [esp + 0xa4]
// 00686e81  d9442414             fld dword ptr [esp + 0x14]
// 00686e85  50                   push eax
// 00686e86  d84724               fadd dword ptr [edi + 0x24]
// 00686e89  8d4c2448             lea ecx, [esp + 0x48]
// 00686e8d  d94728               fld dword ptr [edi + 0x28]
// 00686e90  d8442420             fadd dword ptr [esp + 0x20]
// 00686e94  d9ca                 fxch st(2)
// 00686e96  d99c24a8000000       fstp dword ptr [esp + 0xa8]
// 00686e9d  d99c24ac000000       fstp dword ptr [esp + 0xac]
// 00686ea4  d99c24b0000000       fstp dword ptr [esp + 0xb0]
// 00686eab  e8a073e5ff           call 0x4de250
// 00686eb0  8d4c2434             lea ecx, [esp + 0x34]
// 00686eb4  51                   push ecx
// 00686eb5  e9af010000           jmp 0x687069
// 00686eba  05f4000000           add eax, 0xf4
// 00686ebf  89442410             mov dword ptr [esp + 0x10], eax
// 00686ec3  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686ec7  83c0fe               add eax, -2
// 00686eca  50                   push eax
// 00686ecb  e8b0600000           call 0x68cf80
// 00686ed0  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686ed4  50                   push eax
// 00686ed5  8b02                 mov eax, dword ptr [edx]
// 00686ed7  8bce                 mov ecx, esi
// 00686ed9  ffd0                 call eax
// 00686edb  8b16                 mov edx, dword ptr [esi]
// 00686edd  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686ee3  55                   push ebp
// 00686ee4  8bce                 mov ecx, esi
// 00686ee6  ffd0                 call eax
// 00686ee8  8b06                 mov eax, dword ptr [esi]
// 00686eea  05fc000000           add eax, 0xfc
// 00686eef  89442410             mov dword ptr [esp + 0x10], eax
// 00686ef3  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686ef7  83c0fe               add eax, -2
// 00686efa  50                   push eax
// 00686efb  8d4c2464             lea ecx, [esp + 0x64]
// 00686eff  45                   inc ebp
// 00686f00  e87b600000           call 0x68cf80
// 00686f05  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686f09  50                   push eax
// 00686f0a  8b02                 mov eax, dword ptr [edx]
// 00686f0c  8bce                 mov ecx, esi
// 00686f0e  ffd0                 call eax
// 00686f10  8b06                 mov eax, dword ptr [esi]
// 00686f12  05f4000000           add eax, 0xf4
// 00686f17  89442410             mov dword ptr [esp + 0x10], eax
// 00686f1b  8b442414             mov eax, dword ptr [esp + 0x14]
// 00686f1f  48                   dec eax
// 00686f20  50                   push eax
// 00686f21  8d4c2448             lea ecx, [esp + 0x48]
// 00686f25  8944241c             mov dword ptr [esp + 0x1c], eax
// 00686f29  e852600000           call 0x68cf80
// 00686f2e  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686f32  50                   push eax
// 00686f33  8b02                 mov eax, dword ptr [edx]
// 00686f35  8bce                 mov ecx, esi
// 00686f37  ffd0                 call eax
// 00686f39  8b16                 mov edx, dword ptr [esi]
// 00686f3b  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686f41  55                   push ebp
// 00686f42  8bce                 mov ecx, esi
// 00686f44  ffd0                 call eax
// 00686f46  8b06                 mov eax, dword ptr [esi]
// 00686f48  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00686f4c  05fc000000           add eax, 0xfc
// 00686f51  51                   push ecx
// 00686f52  8d4c2464             lea ecx, [esp + 0x64]
// 00686f56  45                   inc ebp
// 00686f57  89442414             mov dword ptr [esp + 0x14], eax
// 00686f5b  e820600000           call 0x68cf80
// 00686f60  8b542410             mov edx, dword ptr [esp + 0x10]
// 00686f64  50                   push eax
// 00686f65  8b02                 mov eax, dword ptr [edx]
// 00686f67  8bce                 mov ecx, esi
// 00686f69  ffd0                 call eax
// 00686f6b  d9442420             fld dword ptr [esp + 0x20]
// 00686f6f  d9c0                 fld st(0)
// 00686f71  8b16                 mov edx, dword ptr [esi]
// 00686f73  d88c9c5c050000       fmul dword ptr [esp + ebx*4 + 0x55c]
// 00686f7a  83ec0c               sub esp, 0xc
// 00686f7d  8bce                 mov ecx, esi
// 00686f7f  d9542420             fst dword ptr [esp + 0x20]
// 00686f83  d9849ca8010000       fld dword ptr [esp + ebx*4 + 0x1a8]
// 00686f8a  deca                 fmulp st(2)
// 00686f8c  d9c9                 fxch st(1)
// 00686f8e  d954241c             fst dword ptr [esp + 0x1c]
// 00686f92  d94728               fld dword ptr [edi + 0x28]
// 00686f95  d8442428             fadd dword ptr [esp + 0x28]
// 00686f99  d95c2408             fstp dword ptr [esp + 8]
// 00686f9d  d9c9                 fxch st(1)
// 00686f9f  d84724               fadd dword ptr [edi + 0x24]
// 00686fa2  d95c2404             fstp dword ptr [esp + 4]
// 00686fa6  d84720               fadd dword ptr [edi + 0x20]
// 00686fa9  d91c24               fstp dword ptr [esp]
// 00686fac  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00686fb2  ffd0                 call eax
// 00686fb4  8b16                 mov edx, dword ptr [esi]
// 00686fb6  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00686fbc  55                   push ebp
// 00686fbd  8bce                 mov ecx, esi
// 00686fbf  ffd0                 call eax
// 00686fc1  8b16                 mov edx, dword ptr [esi]
// 00686fc3  8b92fc000000         mov edx, dword ptr [edx + 0xfc]
// 00686fc9  8d442434             lea eax, [esp + 0x34]
// 00686fcd  50                   push eax
// 00686fce  8bce                 mov ecx, esi
// 00686fd0  45                   inc ebp
// 00686fd1  ffd2                 call edx
// 00686fd3  d94720               fld dword ptr [edi + 0x20]
// 00686fd6  d8442410             fadd dword ptr [esp + 0x10]
// 00686fda  8d8424bc000000       lea eax, [esp + 0xbc]
// 00686fe1  d9442414             fld dword ptr [esp + 0x14]
// 00686fe5  50                   push eax
// 00686fe6  d84724               fadd dword ptr [edi + 0x24]
// 00686fe9  8d4c2448             lea ecx, [esp + 0x48]
// 00686fed  d94728               fld dword ptr [edi + 0x28]
// 00686ff0  d8442420             fadd dword ptr [esp + 0x20]
// 00686ff4  d9ca                 fxch st(2)
// 00686ff6  d99c24c0000000       fstp dword ptr [esp + 0xc0]
// 00686ffd  d99c24c4000000       fstp dword ptr [esp + 0xc4]
// 00687004  d99c24c8000000       fstp dword ptr [esp + 0xc8]
// 0068700b  e84072e5ff           call 0x4de250
// 00687010  8d4c2434             lea ecx, [esp + 0x34]
// 00687014  51                   push ecx
// 00687015  eb52                 jmp 0x687069
// 00687017  d9849c9c010000       fld dword ptr [esp + ebx*4 + 0x19c]
// 0068701e  8d9424d4000000       lea edx, [esp + 0xd4]
// 00687025  d9442420             fld dword ptr [esp + 0x20]
// 00687029  dcc9                 fmul st(1), st(0)
// 0068702b  d9c9                 fxch st(1)
// 0068702d  d84720               fadd dword ptr [edi + 0x20]
// 00687030  d9c9                 fxch st(1)
// 00687032  d88c9c5c050000       fmul dword ptr [esp + ebx*4 + 0x55c]
// 00687039  d84724               fadd dword ptr [edi + 0x24]
// 0068703c  d94728               fld dword ptr [edi + 0x28]
// 0068703f  d844241c             fadd dword ptr [esp + 0x1c]
// 00687043  d9ca                 fxch st(2)
// 00687045  d99c24d4000000       fstp dword ptr [esp + 0xd4]
// 0068704c  d99c24d8000000       fstp dword ptr [esp + 0xd8]
// 00687053  d99c24dc000000       fstp dword ptr [esp + 0xdc]
// 0068705a  52                   push edx
// 0068705b  8d4c2448             lea ecx, [esp + 0x48]
// 0068705f  e8ec71e5ff           call 0x4de250
// 00687064  8d442434             lea eax, [esp + 0x34]
// 00687068  50                   push eax
// 00687069  8d4c2464             lea ecx, [esp + 0x64]
// 0068706d  e8de71e5ff           call 0x4de250
// 00687072  43                   inc ebx
// 00687073  3b9c2444180000       cmp ebx, dword ptr [esp + 0x1844]
// 0068707a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0068707e  0f8eb2f1ffff         jle 0x686236
// 00687084  8b16                 mov edx, dword ptr [esi]
// 00687086  8b8228010000         mov eax, dword ptr [edx + 0x128]
// 0068708c  8bce                 mov ecx, esi
// 0068708e  ffd0                 call eax
// 00687090  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 00687094  33db                 xor ebx, ebx
// 00687096  3bc3                 cmp eax, ebx
// 00687098  7409                 je 0x6870a3
// 0068709a  50                   push eax
// 0068709b  e8da950100           call 0x6a067a
// 006870a0  83c404               add esp, 4
// 006870a3  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 006870a7  51                   push ecx
// 006870a8  895c2470             mov dword ptr [esp + 0x70], ebx
// 006870ac  895c2474             mov dword ptr [esp + 0x74], ebx
// 006870b0  895c2478             mov dword ptr [esp + 0x78], ebx
// 006870b4  e8c1950100           call 0x6a067a
// 006870b9  8b442454             mov eax, dword ptr [esp + 0x54]
// 006870bd  83c404               add esp, 4
// 006870c0  c7842424180000ffffffff mov dword ptr [esp + 0x1824], 0xffffffff
// 006870cb  3bc3                 cmp eax, ebx
// 006870cd  7409                 je 0x6870d8
// 006870cf  50                   push eax
// 006870d0  e8a5950100           call 0x6a067a
// 006870d5  83c404               add esp, 4
// 006870d8  8b542444             mov edx, dword ptr [esp + 0x44]
// 006870dc  52                   push edx
// 006870dd  895c2454             mov dword ptr [esp + 0x54], ebx
// 006870e1  895c2458             mov dword ptr [esp + 0x58], ebx
// 006870e5  895c245c             mov dword ptr [esp + 0x5c], ebx
// 006870e9  e88c950100           call 0x6a067a
// 006870ee  8b44247c             mov eax, dword ptr [esp + 0x7c]
// 006870f2  83c404               add esp, 4
// 006870f5  3b842448180000       cmp eax, dword ptr [esp + 0x1848]
// 006870fc  89442414             mov dword ptr [esp + 0x14], eax
// 00687100  0f8c3af0ffff         jl 0x686140
// 00687106  8bc6                 mov eax, esi
// 00687108  5b                   pop ebx
// 00687109  e922070000           jmp 0x687830
// 0068710e  ddda                 fstp st(2)
// 00687110  6816b78000           push 0x80b716
// 00687115  ddd9                 fstp st(1)
// 00687117  8d8c2468010000       lea ecx, [esp + 0x168]
// 0068711e  ddd8                 fstp st(0)
// 00687120  ff1558248000         call dword ptr [0x802458]
// 00687126  8b06                 mov eax, dword ptr [esi]
// 00687128  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 0068712e  6a01                 push 1
// 00687130  8d8c2468010000       lea ecx, [esp + 0x168]
// 00687137  51                   push ecx
// 00687138  8bce                 mov ecx, esi
// 0068713a  c784242c18000003000000 mov dword ptr [esp + 0x182c], 3
// 00687145  ffd2                 call edx
// 00687147  8d8c2464010000       lea ecx, [esp + 0x164]
// 0068714e  c7842424180000ffffffff mov dword ptr [esp + 0x1824], 0xffffffff
// 00687159  ff1568248000         call dword ptr [0x802468]
// 0068715f  d9ee                 fldz 
// 00687161  d85f10               fcomp dword ptr [edi + 0x10]
// 00687164  8d4f10               lea ecx, [edi + 0x10]
// 00687167  dfe0                 fnstsw ax
// 00687169  f6c441               test ah, 0x41
// 0068716c  7a0d                 jp 0x68717b
// 0068716e  8b06                 mov eax, dword ptr [esi]
// 00687170  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00687176  51                   push ecx
// 00687177  8bce                 mov ecx, esi
// 00687179  ffd2                 call edx
// 0068717b  33db                 xor ebx, ebx
// 0068717d  895c2418             mov dword ptr [esp + 0x18], ebx
// 00687181  85ed                 test ebp, ebp
// 00687183  0f8e16010000         jle 0x68729f
// 00687189  8da42400000000       lea esp, [esp]
// 00687190  d9849c9c010000       fld dword ptr [esp + ebx*4 + 0x19c]
// 00687197  33ed                 xor ebp, ebp
// 00687199  39ac2448180000       cmp dword ptr [esp + 0x1848], ebp
// 006871a0  d95c2410             fstp dword ptr [esp + 0x10]
// 006871a4  d9849c5c050000       fld dword ptr [esp + ebx*4 + 0x55c]
// 006871ab  896c2414             mov dword ptr [esp + 0x14], ebp
// 006871af  d95c2424             fstp dword ptr [esp + 0x24]
// 006871b3  0f8cd4000000         jl 0x68728d
// 006871b9  db842448180000       fild dword ptr [esp + 0x1848]
// 006871c0  d954242c             fst dword ptr [esp + 0x2c]
// 006871c4  eb04                 jmp 0x6871ca
// 006871c6  d944242c             fld dword ptr [esp + 0x2c]
// 006871ca  db442414             fild dword ptr [esp + 0x14]
// 006871ce  8b06                 mov eax, dword ptr [esi]
// 006871d0  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 006871d6  83ec0c               sub esp, 0xc
// 006871d9  d9c0                 fld st(0)
// 006871db  8bce                 mov ecx, esi
// 006871dd  d8f2                 fdiv st(2)
// 006871df  d954243c             fst dword ptr [esp + 0x3c]
// 006871e3  d84c2468             fmul dword ptr [esp + 0x68]
// 006871e7  d8ac2444180000       fsubr dword ptr [esp + 0x1844]
// 006871ee  d9c9                 fxch st(1)
// 006871f0  d88c244c180000       fmul dword ptr [esp + 0x184c]
// 006871f7  def2                 fdivrp st(2)
// 006871f9  d9c9                 fxch st(1)
// 006871fb  d84728               fadd dword ptr [edi + 0x28]
// 006871fe  d95c2408             fstp dword ptr [esp + 8]
// 00687202  d9442430             fld dword ptr [esp + 0x30]
// 00687206  d8c9                 fmul st(1)
// 00687208  d84724               fadd dword ptr [edi + 0x24]
// 0068720b  d95c2404             fstp dword ptr [esp + 4]
// 0068720f  d84c241c             fmul dword ptr [esp + 0x1c]
// 00687213  d84720               fadd dword ptr [edi + 0x20]
// 00687216  d91c24               fstp dword ptr [esp]
// 00687219  ffd2                 call edx
// 0068721b  833f01               cmp dword ptr [edi], 1
// 0068721e  772c                 ja 0x68724c
// 00687220  d9442440             fld dword ptr [esp + 0x40]
// 00687224  8b06                 mov eax, dword ptr [esi]
// 00687226  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 0068722c  83ec0c               sub esp, 0xc
// 0068722f  d95c2408             fstp dword ptr [esp + 8]
// 00687233  8bce                 mov ecx, esi
// 00687235  d9849ce80c0000       fld dword ptr [esp + ebx*4 + 0xce8]
// 0068723c  d95c2404             fstp dword ptr [esp + 4]
// 00687240  d9849c28090000       fld dword ptr [esp + ebx*4 + 0x928]
// 00687247  d91c24               fstp dword ptr [esp]
// 0068724a  ffd2                 call edx
// 0068724c  807f0400             cmp byte ptr [edi + 4], 0
// 00687250  7429                 je 0x68727b
// 00687252  d9442430             fld dword ptr [esp + 0x30]
// 00687256  8b06                 mov eax, dword ptr [esi]
// 00687258  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 0068725e  83ec08               sub esp, 8
// 00687261  d95c2404             fstp dword ptr [esp + 4]
// 00687265  8bce                 mov ecx, esi
// 00687267  db442420             fild dword ptr [esp + 0x20]
// 0068726b  dab4244c180000       fidiv dword ptr [esp + 0x184c]
// 00687272  d9e8                 fld1 
// 00687274  dee1                 fsubrp st(1)
// 00687276  d91c24               fstp dword ptr [esp]
// 00687279  ffd2                 call edx
// 0068727b  45                   inc ebp
// 0068727c  3bac2448180000       cmp ebp, dword ptr [esp + 0x1848]
// 00687283  896c2414             mov dword ptr [esp + 0x14], ebp
// 00687287  0f8e39ffffff         jle 0x6871c6
// 0068728d  43                   inc ebx
// 0068728e  3b9c2444180000       cmp ebx, dword ptr [esp + 0x1844]
// 00687295  895c2418             mov dword ptr [esp + 0x18], ebx
// 00687299  0f8cf1feffff         jl 0x687190
// 0068729f  8b06                 mov eax, dword ptr [esi]
// 006872a1  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 006872a7  8bce                 mov ecx, esi
// 006872a9  ffd2                 call edx
// 006872ab  8bc6                 mov eax, esi
// 006872ad  5b                   pop ebx
// 006872ae  e97d050000           jmp 0x687830
// 006872b3  b801000000           mov eax, 1
// 006872b8  39842448180000       cmp dword ptr [esp + 0x1848], eax
// 006872bf  89442414             mov dword ptr [esp + 0x14], eax
// 006872c3  0f8ece010000         jle 0x687497
// 006872c9  db842448180000       fild dword ptr [esp + 0x1848]
// 006872d0  8bac2444180000       mov ebp, dword ptr [esp + 0x1844]
// 006872d7  d954242c             fst dword ptr [esp + 0x2c]
// 006872db  eb23                 jmp 0x687300
// 006872dd  8d4900               lea ecx, [ecx]
// 006872e0  d944242c             fld dword ptr [esp + 0x2c]
// 006872e4  d944245c             fld dword ptr [esp + 0x5c]
// 006872e8  d9842438180000       fld dword ptr [esp + 0x1838]
// 006872ef  d9842440180000       fld dword ptr [esp + 0x1840]
// 006872f6  d9ca                 fxch st(2)
// 006872f8  d9cb                 fxch st(3)
// 006872fa  d9c9                 fxch st(1)
// 006872fc  d9ca                 fxch st(2)
// 006872fe  d9c9                 fxch st(1)
// 00687300  db442414             fild dword ptr [esp + 0x14]
// 00687304  6816b78000           push 0x80b716
// 00687309  8d8c2430010000       lea ecx, [esp + 0x130]
// 00687310  d9c0                 fld st(0)
// 00687312  decb                 fmulp st(3)
// 00687314  d9ca                 fxch st(2)
// 00687316  d8f1                 fdiv st(1)
// 00687318  d95c2420             fstp dword ptr [esp + 0x20]
// 0068731c  def9                 fdivp st(1)
// 0068731e  d9542434             fst dword ptr [esp + 0x34]
// 00687322  deca                 fmulp st(2)
// 00687324  dee1                 fsubrp st(1)
// 00687326  d95c2424             fstp dword ptr [esp + 0x24]
// 0068732a  ff1558248000         call dword ptr [0x802458]
// 00687330  8b06                 mov eax, dword ptr [esi]
// 00687332  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00687338  6a03                 push 3
// 0068733a  8d8c2430010000       lea ecx, [esp + 0x130]
// 00687341  51                   push ecx
// 00687342  8bce                 mov ecx, esi
// 00687344  c784242c18000004000000 mov dword ptr [esp + 0x182c], 4
// 0068734f  ffd2                 call edx
// 00687351  8d8c242c010000       lea ecx, [esp + 0x12c]
// 00687358  c7842424180000ffffffff mov dword ptr [esp + 0x1824], 0xffffffff
// 00687363  ff1568248000         call dword ptr [0x802468]
// 00687369  d9ee                 fldz 
// 0068736b  d85f10               fcomp dword ptr [edi + 0x10]
// 0068736e  8d4f10               lea ecx, [edi + 0x10]
// 00687371  dfe0                 fnstsw ax
// 00687373  f6c441               test ah, 0x41
// 00687376  7a0d                 jp 0x687385
// 00687378  8b06                 mov eax, dword ptr [esi]
// 0068737a  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00687380  51                   push ecx
// 00687381  8bce                 mov ecx, esi
// 00687383  ffd2                 call edx
// 00687385  33db                 xor ebx, ebx
// 00687387  895c2418             mov dword ptr [esp + 0x18], ebx
// 0068738b  85ed                 test ebp, ebp
// 0068738d  0f8cd0000000         jl 0x687463
// 00687393  d94728               fld dword ptr [edi + 0x28]
// 00687396  8b06                 mov eax, dword ptr [esi]
// 00687398  d844241c             fadd dword ptr [esp + 0x1c]
// 0068739c  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 006873a2  83ec0c               sub esp, 0xc
// 006873a5  8bce                 mov ecx, esi
// 006873a7  d95c2408             fstp dword ptr [esp + 8]
// 006873ab  d9849c68050000       fld dword ptr [esp + ebx*4 + 0x568]
// 006873b2  d944242c             fld dword ptr [esp + 0x2c]
// 006873b6  dcc9                 fmul st(1), st(0)
// 006873b8  d9c9                 fxch st(1)
// 006873ba  d84724               fadd dword ptr [edi + 0x24]
// 006873bd  d95c2404             fstp dword ptr [esp + 4]
// 006873c1  d88c9ca8010000       fmul dword ptr [esp + ebx*4 + 0x1a8]
// 006873c8  d84720               fadd dword ptr [edi + 0x20]
// 006873cb  d91c24               fstp dword ptr [esp]
// 006873ce  ffd2                 call edx
// 006873d0  8b07                 mov eax, dword ptr [edi]
// 006873d2  83e800               sub eax, 0
// 006873d5  7424                 je 0x6873fb
// 006873d7  83e801               sub eax, 1
// 006873da  754b                 jne 0x687427
// 006873dc  d9442440             fld dword ptr [esp + 0x40]
// 006873e0  83ec0c               sub esp, 0xc
// 006873e3  d95c2408             fstp dword ptr [esp + 8]
// 006873e7  d9849ca8100000       fld dword ptr [esp + ebx*4 + 0x10a8]
// 006873ee  d95c2404             fstp dword ptr [esp + 4]
// 006873f2  d9849c68140000       fld dword ptr [esp + ebx*4 + 0x1468]
// 006873f9  eb1d                 jmp 0x687418
// 006873fb  d9442440             fld dword ptr [esp + 0x40]
// 006873ff  83ec0c               sub esp, 0xc
// 00687402  d95c2408             fstp dword ptr [esp + 8]
// 00687406  d9849ce80c0000       fld dword ptr [esp + ebx*4 + 0xce8]
// 0068740d  d95c2404             fstp dword ptr [esp + 4]
// 00687411  d9849c28090000       fld dword ptr [esp + ebx*4 + 0x928]
// 00687418  8b06                 mov eax, dword ptr [esi]
// 0068741a  d91c24               fstp dword ptr [esp]
// 0068741d  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 00687423  8bce                 mov ecx, esi
// 00687425  ffd2                 call edx
// 00687427  807f0400             cmp byte ptr [edi + 4], 0
// 0068742b  7429                 je 0x687456
// 0068742d  d9442430             fld dword ptr [esp + 0x30]
// 00687431  8b06                 mov eax, dword ptr [esi]
// 00687433  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 00687439  83ec08               sub esp, 8
// 0068743c  d95c2404             fstp dword ptr [esp + 4]
// 00687440  8bce                 mov ecx, esi
// 00687442  db442420             fild dword ptr [esp + 0x20]
// 00687446  dab4244c180000       fidiv dword ptr [esp + 0x184c]
// 0068744d  d9e8                 fld1 
// 0068744f  dee1                 fsubrp st(1)
// 00687451  d91c24               fstp dword ptr [esp]
// 00687454  ffd2                 call edx
// 00687456  43                   inc ebx
// 00687457  3bdd                 cmp ebx, ebp
// 00687459  895c2418             mov dword ptr [esp + 0x18], ebx
// 0068745d  0f8e30ffffff         jle 0x687393
// 00687463  8b06                 mov eax, dword ptr [esi]
// 00687465  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 0068746b  8bce                 mov ecx, esi
// 0068746d  ffd2                 call edx
// 0068746f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00687473  40                   inc eax
// 00687474  3b842448180000       cmp eax, dword ptr [esp + 0x1848]
// 0068747b  89442414             mov dword ptr [esp + 0x14], eax
// 0068747f  0f8c5bfeffff         jl 0x6872e0
// 00687485  d944245c             fld dword ptr [esp + 0x5c]
// 00687489  d9842438180000       fld dword ptr [esp + 0x1838]
// 00687490  d9842440180000       fld dword ptr [esp + 0x1840]
// 00687497  83bc244818000000     cmp dword ptr [esp + 0x1848], 0
// 0068749f  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006874a7  0f8cbe010000         jl 0x68766b
// 006874ad  db842448180000       fild dword ptr [esp + 0x1848]
// 006874b4  8bac2444180000       mov ebp, dword ptr [esp + 0x1844]
// 006874bb  d954242c             fst dword ptr [esp + 0x2c]
// 006874bf  eb20                 jmp 0x6874e1
// 006874c1  d944242c             fld dword ptr [esp + 0x2c]
// 006874c5  d944245c             fld dword ptr [esp + 0x5c]
// 006874c9  d9842438180000       fld dword ptr [esp + 0x1838]
// 006874d0  d9842440180000       fld dword ptr [esp + 0x1840]
// 006874d7  d9ca                 fxch st(2)
// 006874d9  d9cb                 fxch st(3)
// 006874db  d9c9                 fxch st(1)
// 006874dd  d9ca                 fxch st(2)
// 006874df  d9c9                 fxch st(1)
// 006874e1  db442414             fild dword ptr [esp + 0x14]
// 006874e5  6816b78000           push 0x80b716
// 006874ea  8d8c244c010000       lea ecx, [esp + 0x14c]
// 006874f1  d9c0                 fld st(0)
// 006874f3  decb                 fmulp st(3)
// 006874f5  d9ca                 fxch st(2)
// 006874f7  d8f1                 fdiv st(1)
// 006874f9  d95c2420             fstp dword ptr [esp + 0x20]
// 006874fd  def9                 fdivp st(1)
// 006874ff  d9542434             fst dword ptr [esp + 0x34]
// 00687503  deca                 fmulp st(2)
// 00687505  dee1                 fsubrp st(1)
// 00687507  d95c2424             fstp dword ptr [esp + 0x24]
// 0068750b  ff1558248000         call dword ptr [0x802458]
// 00687511  8b06                 mov eax, dword ptr [esi]
// 00687513  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00687519  6a03                 push 3
// 0068751b  8d8c244c010000       lea ecx, [esp + 0x14c]
// 00687522  51                   push ecx
// 00687523  8bce                 mov ecx, esi
// 00687525  c784242c18000005000000 mov dword ptr [esp + 0x182c], 5
// 00687530  ffd2                 call edx
// 00687532  8d8c2448010000       lea ecx, [esp + 0x148]
// 00687539  c7842424180000ffffffff mov dword ptr [esp + 0x1824], 0xffffffff
// 00687544  ff1568248000         call dword ptr [0x802468]
// 0068754a  d9ee                 fldz 
// 0068754c  d85f10               fcomp dword ptr [edi + 0x10]
// 0068754f  8d4f10               lea ecx, [edi + 0x10]
// 00687552  dfe0                 fnstsw ax
// 00687554  f6c441               test ah, 0x41
// 00687557  7a0d                 jp 0x687566
// 00687559  8b06                 mov eax, dword ptr [esi]
// 0068755b  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00687561  51                   push ecx
// 00687562  8bce                 mov ecx, esi
// 00687564  ffd2                 call edx
// 00687566  33db                 xor ebx, ebx
// 00687568  895c2418             mov dword ptr [esp + 0x18], ebx
// 0068756c  85ed                 test ebp, ebp
// 0068756e  0f8cd0000000         jl 0x687644
// 00687574  d94728               fld dword ptr [edi + 0x28]
// 00687577  8b06                 mov eax, dword ptr [esi]
// 00687579  d844241c             fadd dword ptr [esp + 0x1c]
// 0068757d  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 00687583  83ec0c               sub esp, 0xc
// 00687586  8bce                 mov ecx, esi
// 00687588  d95c2408             fstp dword ptr [esp + 8]
// 0068758c  d9849c68050000       fld dword ptr [esp + ebx*4 + 0x568]
// 00687593  d944242c             fld dword ptr [esp + 0x2c]
// 00687597  dcc9                 fmul st(1), st(0)
// 00687599  d9c9                 fxch st(1)
// 0068759b  d84724               fadd dword ptr [edi + 0x24]
// 0068759e  d95c2404             fstp dword ptr [esp + 4]
// 006875a2  d88c9ca8010000       fmul dword ptr [esp + ebx*4 + 0x1a8]
// 006875a9  d84720               fadd dword ptr [edi + 0x20]
// 006875ac  d91c24               fstp dword ptr [esp]
// 006875af  ffd2                 call edx
// 006875b1  8b07                 mov eax, dword ptr [edi]
// 006875b3  83e800               sub eax, 0
// 006875b6  7424                 je 0x6875dc
// 006875b8  83e801               sub eax, 1
// 006875bb  754b                 jne 0x687608
// 006875bd  d9442440             fld dword ptr [esp + 0x40]
// 006875c1  83ec0c               sub esp, 0xc
// 006875c4  d95c2408             fstp dword ptr [esp + 8]
// 006875c8  d9849ca8100000       fld dword ptr [esp + ebx*4 + 0x10a8]
// 006875cf  d95c2404             fstp dword ptr [esp + 4]
// 006875d3  d9849c68140000       fld dword ptr [esp + ebx*4 + 0x1468]
// 006875da  eb1d                 jmp 0x6875f9
// 006875dc  d9442440             fld dword ptr [esp + 0x40]
// 006875e0  83ec0c               sub esp, 0xc
// 006875e3  d95c2408             fstp dword ptr [esp + 8]
// 006875e7  d9849ce80c0000       fld dword ptr [esp + ebx*4 + 0xce8]
// 006875ee  d95c2404             fstp dword ptr [esp + 4]
// 006875f2  d9849c28090000       fld dword ptr [esp + ebx*4 + 0x928]
// 006875f9  8b06                 mov eax, dword ptr [esi]
// 006875fb  d91c24               fstp dword ptr [esp]
// 006875fe  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 00687604  8bce                 mov ecx, esi
// 00687606  ffd2                 call edx
// 00687608  807f0400             cmp byte ptr [edi + 4], 0
// 0068760c  7429                 je 0x687637
// 0068760e  d9442430             fld dword ptr [esp + 0x30]
// 00687612  8b06                 mov eax, dword ptr [esi]
// 00687614  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 0068761a  83ec08               sub esp, 8
// 0068761d  d95c2404             fstp dword ptr [esp + 4]
// 00687621  8bce                 mov ecx, esi
// 00687623  db442420             fild dword ptr [esp + 0x20]
// 00687627  dab4244c180000       fidiv dword ptr [esp + 0x184c]
// 0068762e  d9e8                 fld1 
// 00687630  dee1                 fsubrp st(1)
// 00687632  d91c24               fstp dword ptr [esp]
// 00687635  ffd2                 call edx
// 00687637  43                   inc ebx
// 00687638  3bdd                 cmp ebx, ebp
// 0068763a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0068763e  0f8e30ffffff         jle 0x687574
// 00687644  8b06                 mov eax, dword ptr [esi]
// 00687646  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 0068764c  8bce                 mov ecx, esi
// 0068764e  ffd2                 call edx
// 00687650  8b442414             mov eax, dword ptr [esp + 0x14]
// 00687654  8b8c2448180000       mov ecx, dword ptr [esp + 0x1848]
// 0068765b  03c1                 add eax, ecx
// 0068765d  3bc1                 cmp eax, ecx
// 0068765f  89442414             mov dword ptr [esp + 0x14], eax
// 00687663  0f8e58feffff         jle 0x6874c1
// 00687669  eb06                 jmp 0x687671
// 0068766b  ddda                 fstp st(2)
// 0068766d  ddd9                 fstp st(1)
// 0068766f  ddd8                 fstp st(0)
// 00687671  33db                 xor ebx, ebx
// 00687673  399c2444180000       cmp dword ptr [esp + 0x1844], ebx
// 0068767a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0068767e  0f8e9d010000         jle 0x687821
// 00687684  833f01               cmp dword ptr [edi], 1
// 00687687  772a                 ja 0x6876b3
// 00687689  d9ee                 fldz 
// 0068768b  8b06                 mov eax, dword ptr [esi]
// 0068768d  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 00687693  83ec0c               sub esp, 0xc
// 00687696  d95c2408             fstp dword ptr [esp + 8]
// 0068769a  8bce                 mov ecx, esi
// 0068769c  d9849ce80c0000       fld dword ptr [esp + ebx*4 + 0xce8]
// 006876a3  d95c2404             fstp dword ptr [esp + 4]
// 006876a7  d9849c28090000       fld dword ptr [esp + ebx*4 + 0x928]
// 006876ae  d91c24               fstp dword ptr [esp]
// 006876b1  ffd2                 call edx
// 006876b3  d9849c9c010000       fld dword ptr [esp + ebx*4 + 0x19c]
// 006876ba  6816b78000           push 0x80b716
// 006876bf  d95c2414             fstp dword ptr [esp + 0x14]
// 006876c3  8d8c2484010000       lea ecx, [esp + 0x184]
// 006876ca  d9849c60050000       fld dword ptr [esp + ebx*4 + 0x560]
// 006876d1  d95c2428             fstp dword ptr [esp + 0x28]
// 006876d5  ff1558248000         call dword ptr [0x802458]
// 006876db  8b06                 mov eax, dword ptr [esi]
// 006876dd  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 006876e3  6a03                 push 3
// 006876e5  8d8c2484010000       lea ecx, [esp + 0x184]
// 006876ec  51                   push ecx
// 006876ed  8bce                 mov ecx, esi
// 006876ef  c784242c18000006000000 mov dword ptr [esp + 0x182c], 6
// 006876fa  ffd2                 call edx
// 006876fc  8d8c2480010000       lea ecx, [esp + 0x180]
// 00687703  c7842424180000ffffffff mov dword ptr [esp + 0x1824], 0xffffffff
// 0068770e  ff1568248000         call dword ptr [0x802468]
// 00687714  d9ee                 fldz 
// 00687716  d85f10               fcomp dword ptr [edi + 0x10]
// 00687719  8d4f10               lea ecx, [edi + 0x10]
// 0068771c  dfe0                 fnstsw ax
// 0068771e  f6c441               test ah, 0x41
// 00687721  7a0d                 jp 0x687730
// 00687723  8b06                 mov eax, dword ptr [esi]
// 00687725  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 0068772b  51                   push ecx
// 0068772c  8bce                 mov ecx, esi
// 0068772e  ffd2                 call edx
// 00687730  33ed                 xor ebp, ebp
// 00687732  39ac2448180000       cmp dword ptr [esp + 0x1848], ebp
// 00687739  896c2414             mov dword ptr [esp + 0x14], ebp
// 0068773d  0f8cb5000000         jl 0x6877f8
// 00687743  db842448180000       fild dword ptr [esp + 0x1848]
// 0068774a  d95c242c             fstp dword ptr [esp + 0x2c]
// 0068774e  d9442420             fld dword ptr [esp + 0x20]
// 00687752  d94728               fld dword ptr [edi + 0x28]
// 00687755  8b06                 mov eax, dword ptr [esi]
// 00687757  d844241c             fadd dword ptr [esp + 0x1c]
// 0068775b  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 00687761  83ec0c               sub esp, 0xc
// 00687764  8bce                 mov ecx, esi
// 00687766  d95c2408             fstp dword ptr [esp + 8]
// 0068776a  d9442430             fld dword ptr [esp + 0x30]
// 0068776e  d8c9                 fmul st(1)
// 00687770  d84724               fadd dword ptr [edi + 0x24]
// 00687773  d95c2404             fstp dword ptr [esp + 4]
// 00687777  d84c241c             fmul dword ptr [esp + 0x1c]
// 0068777b  d84720               fadd dword ptr [edi + 0x20]
// 0068777e  d91c24               fstp dword ptr [esp]
// 00687781  ffd2                 call edx
// 00687783  807f0400             cmp byte ptr [edi + 4], 0
// 00687787  db442414             fild dword ptr [esp + 0x14]
// 0068778b  d9842440180000       fld dword ptr [esp + 0x1840]
// 00687792  d8c9                 fmul st(1)
// 00687794  d944242c             fld dword ptr [esp + 0x2c]
// 00687798  dcf9                 fdiv st(1), st(0)
// 0068779a  d9c9                 fxch st(1)
// 0068779c  d95c241c             fstp dword ptr [esp + 0x1c]
// 006877a0  def9                 fdivp st(1)
// 006877a2  d944245c             fld dword ptr [esp + 0x5c]
// 006877a6  d8c9                 fmul st(1)
// 006877a8  d8ac2438180000       fsubr dword ptr [esp + 0x1838]
// 006877af  d9542420             fst dword ptr [esp + 0x20]
// 006877b3  742d                 je 0x6877e2
// 006877b5  8b06                 mov eax, dword ptr [esi]
// 006877b7  ddd8                 fstp st(0)
// 006877b9  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 006877bf  83ec08               sub esp, 8
// 006877c2  d95c2404             fstp dword ptr [esp + 4]
// 006877c6  8bce                 mov ecx, esi
// 006877c8  db442420             fild dword ptr [esp + 0x20]
// 006877cc  dab4244c180000       fidiv dword ptr [esp + 0x184c]
// 006877d3  d9e8                 fld1 
// 006877d5  dee1                 fsubrp st(1)
// 006877d7  d91c24               fstp dword ptr [esp]
// 006877da  ffd2                 call edx
// 006877dc  d9442420             fld dword ptr [esp + 0x20]
// 006877e0  eb02                 jmp 0x6877e4
// 006877e2  ddd9                 fstp st(1)
// 006877e4  45                   inc ebp
// 006877e5  3bac2448180000       cmp ebp, dword ptr [esp + 0x1848]
// 006877ec  896c2414             mov dword ptr [esp + 0x14], ebp
// 006877f0  0f8e5cffffff         jle 0x687752
// 006877f6  ddd8                 fstp st(0)
// 006877f8  8b06                 mov eax, dword ptr [esi]
// 006877fa  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 00687800  8bce                 mov ecx, esi
// 00687802  ffd2                 call edx
// 00687804  43                   inc ebx
// 00687805  3b9c2444180000       cmp ebx, dword ptr [esp + 0x1844]
// 0068780c  895c2418             mov dword ptr [esp + 0x18], ebx
// 00687810  0f8c6efeffff         jl 0x687684
// 00687816  8bc6                 mov eax, esi
// 00687818  5b                   pop ebx
// 00687819  eb15                 jmp 0x687830
// 0068781b  ddda                 fstp st(2)
// 0068781d  ddd9                 fstp st(1)
// 0068781f  ddd8                 fstp st(0)
// 00687821  8bc6                 mov eax, esi
// 00687823  5b                   pop ebx
// 00687824  eb0a                 jmp 0x687830
// 00687826  ddd9                 fstp st(1)
// 00687828  ddd8                 fstp st(0)
// 0068782a  ddd9                 fstp st(1)
// 0068782c  ddd8                 fstp st(0)
// 0068782e  33c0                 xor eax, eax
// 00687830  8b8c2418180000       mov ecx, dword ptr [esp + 0x1818]
// 00687837  5f                   pop edi
// 00687838  5e                   pop esi
// 00687839  5d                   pop ebp
// 0068783a  64890d00000000       mov dword ptr fs:[0], ecx
// 00687841  81c418180000         add esp, 0x1818
// 00687847  c22000               ret 0x20
// 0068784a  8bff                 mov edi, edi
// 0068784c  0e                   push cs
// 0068784d  7168                 jno 0x6878b7
// 0068784f  00b372680018         add byte ptr [ebx + 0x18006872], dh
// 00687855  61                   popal 
// 00687856  6800977468           push 0x68749700

void func_00686000()
{
}
