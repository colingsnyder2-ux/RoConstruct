// from server: 100% by auto
// roc 2010-06 00565030  unit: seg_00560000  size: 941 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00565030
//
// 00565030  53                   push ebx
// 00565031  57                   push edi
// 00565032  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00565036  33db                 xor ebx, ebx
// 00565038  3bfb                 cmp edi, ebx
// 0056503a  0f849a030000         je 0x5653da
// 00565040  56                   push esi
// 00565041  8b742414             mov esi, dword ptr [esp + 0x14]
// 00565045  3bf3                 cmp esi, ebx
// 00565047  0f848c030000         je 0x5653d9
// 0056504d  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 00565053  55                   push ebp
// 00565054  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00565058  23c5                 and eax, ebp
// 0056505a  a900400000           test eax, 0x4000
// 0056505f  7461                 je 0x5650c2
// 00565061  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00565065  83f9ff               cmp ecx, -1
// 00565068  7424                 je 0x56508e
// 0056506a  8b4638               mov eax, dword ptr [esi + 0x38]
// 0056506d  3bc3                 cmp eax, ebx
// 0056506f  7451                 je 0x5650c2
// 00565071  8be9                 mov ebp, ecx
// 00565073  c1e504               shl ebp, 4
// 00565076  8b442804             mov eax, dword ptr [eax + ebp + 4]
// 0056507a  3bc3                 cmp eax, ebx
// 0056507c  7440                 je 0x5650be
// 0056507e  50                   push eax
// 0056507f  57                   push edi
// 00565080  e87bd50000           call 0x572600
// 00565085  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00565088  895c2904             mov dword ptr [ecx + ebp + 4], ebx
// 0056508c  eb2d                 jmp 0x5650bb
// 0056508e  33ed                 xor ebp, ebp
// 00565090  395e30               cmp dword ptr [esi + 0x30], ebx
// 00565093  7e16                 jle 0x5650ab
// 00565095  55                   push ebp
// 00565096  6800400000           push 0x4000
// 0056509b  56                   push esi
// 0056509c  57                   push edi
// 0056509d  e88effffff           call 0x565030
// 005650a2  45                   inc ebp
// 005650a3  83c410               add esp, 0x10
// 005650a6  3b6e30               cmp ebp, dword ptr [esi + 0x30]
// 005650a9  7cea                 jl 0x565095
// 005650ab  8b5638               mov edx, dword ptr [esi + 0x38]
// 005650ae  52                   push edx
// 005650af  57                   push edi
// 005650b0  e84bd50000           call 0x572600
// 005650b5  895e38               mov dword ptr [esi + 0x38], ebx
// 005650b8  895e30               mov dword ptr [esi + 0x30], ebx
// 005650bb  83c408               add esp, 8
// 005650be  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 005650c2  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 005650c8  23c5                 and eax, ebp
// 005650ca  a900200000           test eax, 0x2000
// 005650cf  7414                 je 0x5650e5
// 005650d1  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 005650d4  51                   push ecx
// 005650d5  57                   push edi
// 005650d6  e825d50000           call 0x572600
// 005650db  83c408               add esp, 8
// 005650de  836608ef             and dword ptr [esi + 8], 0xffffffef
// 005650e2  895e4c               mov dword ptr [esi + 0x4c], ebx
// 005650e5  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 005650eb  23c5                 and eax, ebp
// 005650ed  a900010000           test eax, 0x100
// 005650f2  7407                 je 0x5650fb
// 005650f4  816608ffbfffff       and dword ptr [esi + 8], 0xffffbfff
// 005650fb  84c0                 test al, al
// 005650fd  0f8986000000         jns 0x565189
// 00565103  8b96a0000000         mov edx, dword ptr [esi + 0xa0]
// 00565109  52                   push edx
// 0056510a  57                   push edi
// 0056510b  e8f0d40000           call 0x572600
// 00565110  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 00565116  50                   push eax
// 00565117  57                   push edi
// 00565118  e8e3d40000           call 0x572600
// 0056511d  83c410               add esp, 0x10
// 00565120  899ea0000000         mov dword ptr [esi + 0xa0], ebx
// 00565126  899eac000000         mov dword ptr [esi + 0xac], ebx
// 0056512c  399eb0000000         cmp dword ptr [esi + 0xb0], ebx
// 00565132  744e                 je 0x565182
// 00565134  33ed                 xor ebp, ebp
// 00565136  389eb5000000         cmp byte ptr [esi + 0xb5], bl
// 0056513c  762a                 jbe 0x565168
// 0056513e  8bff                 mov edi, edi
// 00565140  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 00565146  8b14a9               mov edx, dword ptr [ecx + ebp*4]
// 00565149  52                   push edx
// 0056514a  57                   push edi
// 0056514b  e8b0d40000           call 0x572600
// 00565150  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00565156  891ca8               mov dword ptr [eax + ebp*4], ebx
// 00565159  0fb68eb5000000       movzx ecx, byte ptr [esi + 0xb5]
// 00565160  45                   inc ebp
// 00565161  83c408               add esp, 8
// 00565164  3be9                 cmp ebp, ecx
// 00565166  7cd8                 jl 0x565140
// 00565168  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 0056516e  52                   push edx
// 0056516f  57                   push edi
// 00565170  e88bd40000           call 0x572600
// 00565175  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00565179  83c408               add esp, 8
// 0056517c  899eb0000000         mov dword ptr [esi + 0xb0], ebx
// 00565182  816608fffbffff       and dword ptr [esi + 8], 0xfffffbff
// 00565189  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0056518f  23c5                 and eax, ebp
// 00565191  a810                 test al, 0x10
// 00565193  7430                 je 0x5651c5
// 00565195  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 0056519b  51                   push ecx
// 0056519c  57                   push edi
// 0056519d  e85ed40000           call 0x572600
// 005651a2  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 005651a8  52                   push edx
// 005651a9  57                   push edi
// 005651aa  e851d40000           call 0x572600
// 005651af  83c410               add esp, 0x10
// 005651b2  816608ffefffff       and dword ptr [esi + 8], 0xffffefff
// 005651b9  899ec4000000         mov dword ptr [esi + 0xc4], ebx
// 005651bf  899ec8000000         mov dword ptr [esi + 0xc8], ebx
// 005651c5  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 005651cb  23c5                 and eax, ebp
// 005651cd  a820                 test al, 0x20
// 005651cf  0f84a0000000         je 0x565275
// 005651d5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005651d9  83f9ff               cmp ecx, -1
// 005651dc  744a                 je 0x565228
// 005651de  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 005651e4  3bc3                 cmp eax, ebx
// 005651e6  0f8489000000         je 0x565275
// 005651ec  8be9                 mov ebp, ecx
// 005651ee  c1e504               shl ebp, 4
// 005651f1  8b0c28               mov ecx, dword ptr [eax + ebp]
// 005651f4  51                   push ecx
// 005651f5  57                   push edi
// 005651f6  e805d40000           call 0x572600
// 005651fb  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 00565201  8b442a08             mov eax, dword ptr [edx + ebp + 8]
// 00565205  50                   push eax
// 00565206  57                   push edi
// 00565207  e8f4d30000           call 0x572600
// 0056520c  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 00565212  891c29               mov dword ptr [ecx + ebp], ebx
// 00565215  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 0056521b  895c2a08             mov dword ptr [edx + ebp + 8], ebx
// 0056521f  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00565223  83c410               add esp, 0x10
// 00565226  eb4d                 jmp 0x565275
// 00565228  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 0056522e  3bc3                 cmp eax, ebx
// 00565230  743c                 je 0x56526e
// 00565232  33ed                 xor ebp, ebp
// 00565234  3bc3                 cmp eax, ebx
// 00565236  7e16                 jle 0x56524e
// 00565238  55                   push ebp
// 00565239  6a20                 push 0x20
// 0056523b  56                   push esi
// 0056523c  57                   push edi
// 0056523d  e8eefdffff           call 0x565030
// 00565242  45                   inc ebp
// 00565243  83c410               add esp, 0x10
// 00565246  3baed8000000         cmp ebp, dword ptr [esi + 0xd8]
// 0056524c  7cea                 jl 0x565238
// 0056524e  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 00565254  50                   push eax
// 00565255  57                   push edi
// 00565256  e8a5d30000           call 0x572600
// 0056525b  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0056525f  83c408               add esp, 8
// 00565262  899ed4000000         mov dword ptr [esi + 0xd4], ebx
// 00565268  899ed8000000         mov dword ptr [esi + 0xd8], ebx
// 0056526e  816608ffdfffff       and dword ptr [esi + 8], 0xffffdfff
// 00565275  8b8774020000         mov eax, dword ptr [edi + 0x274]
// 0056527b  3bc3                 cmp eax, ebx
// 0056527d  7410                 je 0x56528f
// 0056527f  50                   push eax
// 00565280  57                   push edi
// 00565281  e87ad30000           call 0x572600
// 00565286  83c408               add esp, 8
// 00565289  899f74020000         mov dword ptr [edi + 0x274], ebx
// 0056528f  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 00565295  23cd                 and ecx, ebp
// 00565297  f7c100020000         test ecx, 0x200
// 0056529d  747a                 je 0x565319
// 0056529f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005652a3  83f9ff               cmp ecx, -1
// 005652a6  7428                 je 0x5652d0
// 005652a8  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 005652ae  3bc3                 cmp eax, ebx
// 005652b0  7467                 je 0x565319
// 005652b2  8d2c89               lea ebp, [ecx + ecx*4]
// 005652b5  03ed                 add ebp, ebp
// 005652b7  03ed                 add ebp, ebp
// 005652b9  8b542808             mov edx, dword ptr [eax + ebp + 8]
// 005652bd  52                   push edx
// 005652be  57                   push edi
// 005652bf  e83cd30000           call 0x572600
// 005652c4  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 005652ca  895c2808             mov dword ptr [eax + ebp + 8], ebx
// 005652ce  eb42                 jmp 0x565312
// 005652d0  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 005652d6  3bc3                 cmp eax, ebx
// 005652d8  743f                 je 0x565319
// 005652da  33ed                 xor ebp, ebp
// 005652dc  3bc3                 cmp eax, ebx
// 005652de  7e19                 jle 0x5652f9
// 005652e0  55                   push ebp
// 005652e1  6800020000           push 0x200
// 005652e6  56                   push esi
// 005652e7  57                   push edi
// 005652e8  e843fdffff           call 0x565030
// 005652ed  45                   inc ebp
// 005652ee  83c410               add esp, 0x10
// 005652f1  3baec0000000         cmp ebp, dword ptr [esi + 0xc0]
// 005652f7  7ce7                 jl 0x5652e0
// 005652f9  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 005652ff  51                   push ecx
// 00565300  57                   push edi
// 00565301  e8fad20000           call 0x572600
// 00565306  899ebc000000         mov dword ptr [esi + 0xbc], ebx
// 0056530c  899ec0000000         mov dword ptr [esi + 0xc0], ebx
// 00565312  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00565316  83c408               add esp, 8
// 00565319  8b96b8000000         mov edx, dword ptr [esi + 0xb8]
// 0056531f  23d5                 and edx, ebp
// 00565321  f6c208               test dl, 8
// 00565324  7414                 je 0x56533a
// 00565326  8b467c               mov eax, dword ptr [esi + 0x7c]
// 00565329  50                   push eax
// 0056532a  57                   push edi
// 0056532b  e8d0d20000           call 0x572600
// 00565330  83c408               add esp, 8
// 00565333  836608bf             and dword ptr [esi + 8], 0xffffffbf
// 00565337  895e7c               mov dword ptr [esi + 0x7c], ebx
// 0056533a  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 00565340  23cd                 and ecx, ebp
// 00565342  f7c100100000         test ecx, 0x1000
// 00565348  741a                 je 0x565364
// 0056534a  8b5610               mov edx, dword ptr [esi + 0x10]
// 0056534d  52                   push edx
// 0056534e  57                   push edi
// 0056534f  e8acd20000           call 0x572600
// 00565354  836608f7             and dword ptr [esi + 8], 0xfffffff7
// 00565358  83c408               add esp, 8
// 0056535b  33c0                 xor eax, eax
// 0056535d  895e10               mov dword ptr [esi + 0x10], ebx
// 00565360  66894614             mov word ptr [esi + 0x14], ax
// 00565364  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 0056536a  23cd                 and ecx, ebp
// 0056536c  f6c140               test cl, 0x40
// 0056536f  7452                 je 0x5653c3
// 00565371  399ef8000000         cmp dword ptr [esi + 0xf8], ebx
// 00565377  7443                 je 0x5653bc
// 00565379  33ed                 xor ebp, ebp
// 0056537b  395e04               cmp dword ptr [esi + 4], ebx
// 0056537e  7e22                 jle 0x5653a2
// 00565380  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 00565386  8b04aa               mov eax, dword ptr [edx + ebp*4]
// 00565389  50                   push eax
// 0056538a  57                   push edi
// 0056538b  e870d20000           call 0x572600
// 00565390  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 00565396  891ca9               mov dword ptr [ecx + ebp*4], ebx
// 00565399  45                   inc ebp
// 0056539a  83c408               add esp, 8
// 0056539d  3b6e04               cmp ebp, dword ptr [esi + 4]
// 005653a0  7cde                 jl 0x565380
// 005653a2  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 005653a8  52                   push edx
// 005653a9  57                   push edi
// 005653aa  e851d20000           call 0x572600
// 005653af  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 005653b3  83c408               add esp, 8
// 005653b6  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 005653bc  816608ff7fffff       and dword ptr [esi + 8], 0xffff7fff
// 005653c3  837c2420ff           cmp dword ptr [esp + 0x20], -1
// 005653c8  7406                 je 0x5653d0
// 005653ca  81e5dfbdffff         and ebp, 0xffffbddf
// 005653d0  f7d5                 not ebp
// 005653d2  21aeb8000000         and dword ptr [esi + 0xb8], ebp
// 005653d8  5d                   pop ebp
// 005653d9  5e                   pop esi
// 005653da  5f                   pop edi
// 005653db  5b                   pop ebx
// 005653dc  c3                   ret 
// library libpng-1.2.22/png.c (function _png_free_data)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 png.c
