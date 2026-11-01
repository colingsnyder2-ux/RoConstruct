// from server: 100% by auto
// roc 2007-03 00517410  unit: seg_00510000  size: 3006 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00517410
//
// 00517410  83ec30               sub esp, 0x30
// 00517413  8b442438             mov eax, dword ptr [esp + 0x38]
// 00517417  53                   push ebx
// 00517418  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 0051741c  8a8b25010000         mov cl, byte ptr [ebx + 0x125]
// 00517422  0fb693f9010000       movzx edx, byte ptr [ebx + 0x1f9]
// 00517429  55                   push ebp
// 0051742a  8b6804               mov ebp, dword ptr [eax + 4]
// 0051742d  56                   push esi
// 0051742e  57                   push edi
// 0051742f  0fb6780b             movzx edi, byte ptr [eax + 0xb]
// 00517433  8b83e8000000         mov eax, dword ptr [ebx + 0xe8]
// 00517439  83c707               add edi, 7
// 0051743c  c1ff03               sar edi, 3
// 0051743f  f6c108               test cl, 8
// 00517442  8944242c             mov dword ptr [esp + 0x2c], eax
// 00517446  8b83ec000000         mov eax, dword ptr [ebx + 0xec]
// 0051744c  884c2413             mov byte ptr [esp + 0x13], cl
// 00517450  896c2414             mov dword ptr [esp + 0x14], ebp
// 00517454  89542448             mov dword ptr [esp + 0x48], edx
// 00517458  897c2428             mov dword ptr [esp + 0x28], edi
// 0051745c  89442420             mov dword ptr [esp + 0x20], eax
// 00517460  8944241c             mov dword ptr [esp + 0x1c], eax
// 00517464  c7442418ffffff7f     mov dword ptr [esp + 0x18], 0x7fffffff
// 0051746c  0f84c1000000         je 0x517533
// 00517472  80f908               cmp cl, 8
// 00517475  0f84b8000000         je 0x517533
// 0051747b  33c0                 xor eax, eax
// 0051747d  33d2                 xor edx, edx
// 0051747f  85ed                 test ebp, ebp
// 00517481  7632                 jbe 0x5174b5
// 00517483  eb0b                 jmp 0x517490
// 00517485  8da42400000000       lea esp, [esp]
// 0051748c  8d642400             lea esp, [esp]
// 00517490  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00517494  0fb6741101           movzx esi, byte ptr [ecx + edx + 1]
// 00517499  81fe80000000         cmp esi, 0x80
// 0051749f  7d04                 jge 0x5174a5
// 005174a1  8bce                 mov ecx, esi
// 005174a3  eb07                 jmp 0x5174ac
// 005174a5  b900010000           mov ecx, 0x100
// 005174aa  2bce                 sub ecx, esi
// 005174ac  83c201               add edx, 1
// 005174af  03c1                 add eax, ecx
// 005174b1  3bd5                 cmp edx, ebp
// 005174b3  72db                 jb 0x517490
// 005174b5  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 005174bc  7571                 jne 0x51752f
// 005174be  0fb7f0               movzx esi, ax
// 005174c1  c1e80a               shr eax, 0xa
// 005174c4  25c0ff3f00           and eax, 0x3fffc0
// 005174c9  33c9                 xor ecx, ecx
// 005174cb  394c2448             cmp dword ptr [esp + 0x48], ecx
// 005174cf  8bd0                 mov edx, eax
// 005174d1  7e31                 jle 0x517504
// 005174d3  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 005174d9  803c0800             cmp byte ptr [eax + ecx], 0
// 005174dd  751c                 jne 0x5174fb
// 005174df  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 005174e5  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 005174e9  8be8                 mov ebp, eax
// 005174eb  0fafc2               imul eax, edx
// 005174ee  0fafee               imul ebp, esi
// 005174f1  c1ed08               shr ebp, 8
// 005174f4  c1e808               shr eax, 8
// 005174f7  8bf5                 mov esi, ebp
// 005174f9  8bd0                 mov edx, eax
// 005174fb  83c101               add ecx, 1
// 005174fe  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 00517502  7ccf                 jl 0x5174d3
// 00517504  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 0051750a  0fb701               movzx eax, word ptr [ecx]
// 0051750d  8bc8                 mov ecx, eax
// 0051750f  0fafca               imul ecx, edx
// 00517512  c1e903               shr ecx, 3
// 00517515  81f9c0ff3f00         cmp ecx, 0x3fffc0
// 0051751b  7607                 jbe 0x517524
// 0051751d  b8ffffff7f           mov eax, 0x7fffffff
// 00517522  eb0b                 jmp 0x51752f
// 00517524  0fafc6               imul eax, esi
// 00517527  c1e803               shr eax, 3
// 0051752a  c1e10a               shl ecx, 0xa
// 0051752d  03c1                 add eax, ecx
// 0051752f  89442418             mov dword ptr [esp + 0x18], eax
// 00517533  8a442413             mov al, byte ptr [esp + 0x13]
// 00517537  3c10                 cmp al, 0x10
// 00517539  0f85fa000000         jne 0x517639
// 0051753f  8b742420             mov esi, dword ptr [esp + 0x20]
// 00517543  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 00517549  83c601               add esi, 1
// 0051754c  33ed                 xor ebp, ebp
// 0051754e  83c001               add eax, 1
// 00517551  85ff                 test edi, edi
// 00517553  8bce                 mov ecx, esi
// 00517555  7618                 jbe 0x51756f
// 00517557  8bef                 mov ebp, edi
// 00517559  8da42400000000       lea esp, [esp]
// 00517560  8a11                 mov dl, byte ptr [ecx]
// 00517562  8810                 mov byte ptr [eax], dl
// 00517564  83c101               add ecx, 1
// 00517567  83c001               add eax, 1
// 0051756a  83ef01               sub edi, 1
// 0051756d  75f1                 jne 0x517560
// 0051756f  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 00517573  731f                 jae 0x517594
// 00517575  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00517579  2bfd                 sub edi, ebp
// 0051757b  eb03                 jmp 0x517580
// 0051757d  8d4900               lea ecx, [ecx]
// 00517580  8a11                 mov dl, byte ptr [ecx]
// 00517582  2a16                 sub dl, byte ptr [esi]
// 00517584  83c101               add ecx, 1
// 00517587  8810                 mov byte ptr [eax], dl
// 00517589  83c601               add esi, 1
// 0051758c  83c001               add eax, 1
// 0051758f  83ef01               sub edi, 1
// 00517592  75ec                 jne 0x517580
// 00517594  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 0051759a  8944241c             mov dword ptr [esp + 0x1c], eax
// 0051759e  f644241320           test byte ptr [esp + 0x13], 0x20
// 005175a3  0f8446040000         je 0x5179ef
// 005175a9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005175ad  33ff                 xor edi, edi
// 005175af  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 005175b6  894c2434             mov dword ptr [esp + 0x34], ecx
// 005175ba  0f8538030000         jne 0x5178f8
// 005175c0  0fb7f1               movzx esi, cx
// 005175c3  c1e90a               shr ecx, 0xa
// 005175c6  33d2                 xor edx, edx
// 005175c8  81e1c0ff3f00         and ecx, 0x3fffc0
// 005175ce  39542448             cmp dword ptr [esp + 0x48], edx
// 005175d2  89742438             mov dword ptr [esp + 0x38], esi
// 005175d6  7e37                 jle 0x51760f
// 005175d8  8babfc010000         mov ebp, dword ptr [ebx + 0x1fc]
// 005175de  8bff                 mov edi, edi
// 005175e0  803c2a02             cmp byte ptr [edx + ebp], 2
// 005175e4  7520                 jne 0x517606
// 005175e6  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 005175ec  0fb70450             movzx eax, word ptr [eax + edx*2]
// 005175f0  8bf0                 mov esi, eax
// 005175f2  0fafc1               imul eax, ecx
// 005175f5  0faf742438           imul esi, dword ptr [esp + 0x38]
// 005175fa  c1ee08               shr esi, 8
// 005175fd  c1e808               shr eax, 8
// 00517600  89742438             mov dword ptr [esp + 0x38], esi
// 00517604  8bc8                 mov ecx, eax
// 00517606  83c201               add edx, 1
// 00517609  3b542448             cmp edx, dword ptr [esp + 0x48]
// 0051760d  7cd1                 jl 0x5175e0
// 0051760f  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 00517615  0fb75204             movzx edx, word ptr [edx + 4]
// 00517619  8bc2                 mov eax, edx
// 0051761b  0fafc1               imul eax, ecx
// 0051761e  c1e803               shr eax, 3
// 00517621  3dc0ff3f00           cmp eax, 0x3fffc0
// 00517626  0f86bd020000         jbe 0x5178e9
// 0051762c  c7442434ffffff7f     mov dword ptr [esp + 0x34], 0x7fffffff
// 00517634  e9bf020000           jmp 0x5178f8
// 00517639  a810                 test al, 0x10
// 0051763b  0f84c3010000         je 0x517804
// 00517641  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00517645  33ff                 xor edi, edi
// 00517647  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0051764e  894c2434             mov dword ptr [esp + 0x34], ecx
// 00517652  757f                 jne 0x5176d3
// 00517654  0fb7f1               movzx esi, cx
// 00517657  c1e90a               shr ecx, 0xa
// 0051765a  81e1c0ff3f00         and ecx, 0x3fffc0
// 00517660  33d2                 xor edx, edx
// 00517662  397c2448             cmp dword ptr [esp + 0x48], edi
// 00517666  7e39                 jle 0x5176a1
// 00517668  eb06                 jmp 0x517670
// 0051766a  8d9b00000000         lea ebx, [ebx]
// 00517670  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00517676  803c1001             cmp byte ptr [eax + edx], 1
// 0051767a  751c                 jne 0x517698
// 0051767c  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 00517682  0fb70450             movzx eax, word ptr [eax + edx*2]
// 00517686  8be8                 mov ebp, eax
// 00517688  0fafc1               imul eax, ecx
// 0051768b  0fafee               imul ebp, esi
// 0051768e  c1ed08               shr ebp, 8
// 00517691  c1e808               shr eax, 8
// 00517694  8bf5                 mov esi, ebp
// 00517696  8bc8                 mov ecx, eax
// 00517698  83c201               add edx, 1
// 0051769b  3b542448             cmp edx, dword ptr [esp + 0x48]
// 0051769f  7ccf                 jl 0x517670
// 005176a1  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 005176a7  0fb75202             movzx edx, word ptr [edx + 2]
// 005176ab  8bc2                 mov eax, edx
// 005176ad  0fafc1               imul eax, ecx
// 005176b0  c1e803               shr eax, 3
// 005176b3  3dc0ff3f00           cmp eax, 0x3fffc0
// 005176b8  760a                 jbe 0x5176c4
// 005176ba  c7442434ffffff7f     mov dword ptr [esp + 0x34], 0x7fffffff
// 005176c2  eb0f                 jmp 0x5176d3
// 005176c4  0fafd6               imul edx, esi
// 005176c7  c1ea03               shr edx, 3
// 005176ca  c1e00a               shl eax, 0xa
// 005176cd  03d0                 add edx, eax
// 005176cf  89542434             mov dword ptr [esp + 0x34], edx
// 005176d3  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005176d7  8b8bf0000000         mov ecx, dword ptr [ebx + 0xf0]
// 005176dd  8b442428             mov eax, dword ptr [esp + 0x28]
// 005176e1  83c501               add ebp, 1
// 005176e4  83c101               add ecx, 1
// 005176e7  85c0                 test eax, eax
// 005176e9  897c2424             mov dword ptr [esp + 0x24], edi
// 005176ed  896c2430             mov dword ptr [esp + 0x30], ebp
// 005176f1  8bd5                 mov edx, ebp
// 005176f3  7636                 jbe 0x51772b
// 005176f5  8be8                 mov ebp, eax
// 005176f7  89442424             mov dword ptr [esp + 0x24], eax
// 005176fb  eb03                 jmp 0x517700
// 005176fd  8d4900               lea ecx, [ecx]
// 00517700  8a02                 mov al, byte ptr [edx]
// 00517702  0fb6f0               movzx esi, al
// 00517705  81fe80000000         cmp esi, 0x80
// 0051770b  8801                 mov byte ptr [ecx], al
// 0051770d  7d04                 jge 0x517713
// 0051770f  8bc6                 mov eax, esi
// 00517711  eb07                 jmp 0x51771a
// 00517713  b800010000           mov eax, 0x100
// 00517718  2bc6                 sub eax, esi
// 0051771a  03f8                 add edi, eax
// 0051771c  83c201               add edx, 1
// 0051771f  83c101               add ecx, 1
// 00517722  83ed01               sub ebp, 1
// 00517725  75d9                 jne 0x517700
// 00517727  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 0051772b  8b442414             mov eax, dword ptr [esp + 0x14]
// 0051772f  39442424             cmp dword ptr [esp + 0x24], eax
// 00517733  733e                 jae 0x517773
// 00517735  8a02                 mov al, byte ptr [edx]
// 00517737  2a4500               sub al, byte ptr [ebp]
// 0051773a  8801                 mov byte ptr [ecx], al
// 0051773c  0fb6c0               movzx eax, al
// 0051773f  3d80000000           cmp eax, 0x80
// 00517744  7d04                 jge 0x51774a
// 00517746  8bf0                 mov esi, eax
// 00517748  eb07                 jmp 0x517751
// 0051774a  be00010000           mov esi, 0x100
// 0051774f  2bf0                 sub esi, eax
// 00517751  03fe                 add edi, esi
// 00517753  3b7c2434             cmp edi, dword ptr [esp + 0x34]
// 00517757  771a                 ja 0x517773
// 00517759  8b442424             mov eax, dword ptr [esp + 0x24]
// 0051775d  83c001               add eax, 1
// 00517760  83c201               add edx, 1
// 00517763  83c501               add ebp, 1
// 00517766  83c101               add ecx, 1
// 00517769  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0051776d  89442424             mov dword ptr [esp + 0x24], eax
// 00517771  72c2                 jb 0x517735
// 00517773  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 0051777a  7574                 jne 0x5177f0
// 0051777c  0fb7f7               movzx esi, di
// 0051777f  c1ef0a               shr edi, 0xa
// 00517782  81e7c0ff3f00         and edi, 0x3fffc0
// 00517788  33c9                 xor ecx, ecx
// 0051778a  394c2448             cmp dword ptr [esp + 0x48], ecx
// 0051778e  8bd7                 mov edx, edi
// 00517790  7e31                 jle 0x5177c3
// 00517792  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 00517798  803c0f01             cmp byte ptr [edi + ecx], 1
// 0051779c  751c                 jne 0x5177ba
// 0051779e  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 005177a4  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 005177a8  8be8                 mov ebp, eax
// 005177aa  0fafc2               imul eax, edx
// 005177ad  0fafee               imul ebp, esi
// 005177b0  c1ed08               shr ebp, 8
// 005177b3  c1e808               shr eax, 8
// 005177b6  8bf5                 mov esi, ebp
// 005177b8  8bd0                 mov edx, eax
// 005177ba  83c101               add ecx, 1
// 005177bd  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 005177c1  7cd5                 jl 0x517798
// 005177c3  8b8b0c020000         mov ecx, dword ptr [ebx + 0x20c]
// 005177c9  0fb74902             movzx ecx, word ptr [ecx + 2]
// 005177cd  8bc1                 mov eax, ecx
// 005177cf  0fafc2               imul eax, edx
// 005177d2  c1e803               shr eax, 3
// 005177d5  3dc0ff3f00           cmp eax, 0x3fffc0
// 005177da  7607                 jbe 0x5177e3
// 005177dc  bfffffff7f           mov edi, 0x7fffffff
// 005177e1  eb0d                 jmp 0x5177f0
// 005177e3  0fafce               imul ecx, esi
// 005177e6  c1e903               shr ecx, 3
// 005177e9  c1e00a               shl eax, 0xa
// 005177ec  03c8                 add ecx, eax
// 005177ee  8bf9                 mov edi, ecx
// 005177f0  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 005177f4  730e                 jae 0x517804
// 005177f6  8b93f0000000         mov edx, dword ptr [ebx + 0xf0]
// 005177fc  897c2418             mov dword ptr [esp + 0x18], edi
// 00517800  8954241c             mov dword ptr [esp + 0x1c], edx
// 00517804  807c241320           cmp byte ptr [esp + 0x13], 0x20
// 00517809  0f858ffdffff         jne 0x51759e
// 0051780f  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 00517815  8b542420             mov edx, dword ptr [esp + 0x20]
// 00517819  33c9                 xor ecx, ecx
// 0051781b  83c001               add eax, 1
// 0051781e  394c2414             cmp dword ptr [esp + 0x14], ecx
// 00517822  8d7a01               lea edi, [edx + 1]
// 00517825  761f                 jbe 0x517846
// 00517827  8bf7                 mov esi, edi
// 00517829  2bf2                 sub esi, edx
// 0051782b  0374242c             add esi, dword ptr [esp + 0x2c]
// 0051782f  90                   nop 
// 00517830  8a1439               mov dl, byte ptr [ecx + edi]
// 00517833  2a16                 sub dl, byte ptr [esi]
// 00517835  83c101               add ecx, 1
// 00517838  8810                 mov byte ptr [eax], dl
// 0051783a  83c601               add esi, 1
// 0051783d  83c001               add eax, 1
// 00517840  3b4c2414             cmp ecx, dword ptr [esp + 0x14]
// 00517844  72ea                 jb 0x517830
// 00517846  8b83f4000000         mov eax, dword ptr [ebx + 0xf4]
// 0051784c  8944241c             mov dword ptr [esp + 0x1c], eax
// 00517850  f644241340           test byte ptr [esp + 0x13], 0x40
// 00517855  0f843a040000         je 0x517c95
// 0051785b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0051785f  33d2                 xor edx, edx
// 00517861  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00517868  89542424             mov dword ptr [esp + 0x24], edx
// 0051786c  894c2434             mov dword ptr [esp + 0x34], ecx
// 00517870  0f85b4020000         jne 0x517b2a
// 00517876  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 0051787a  0fb7f1               movzx esi, cx
// 0051787d  c1e90a               shr ecx, 0xa
// 00517880  81e1c0ff3f00         and ecx, 0x3fffc0
// 00517886  3bfa                 cmp edi, edx
// 00517888  7e35                 jle 0x5178bf
// 0051788a  8d9b00000000         lea ebx, [ebx]
// 00517890  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00517896  803c0203             cmp byte ptr [edx + eax], 3
// 0051789a  751c                 jne 0x5178b8
// 0051789c  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 005178a2  0fb70450             movzx eax, word ptr [eax + edx*2]
// 005178a6  8be8                 mov ebp, eax
// 005178a8  0fafc1               imul eax, ecx
// 005178ab  0fafee               imul ebp, esi
// 005178ae  c1ed08               shr ebp, 8
// 005178b1  c1e808               shr eax, 8
// 005178b4  8bf5                 mov esi, ebp
// 005178b6  8bc8                 mov ecx, eax
// 005178b8  83c201               add edx, 1
// 005178bb  3bd7                 cmp edx, edi
// 005178bd  7cd1                 jl 0x517890
// 005178bf  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 005178c5  0fb75206             movzx edx, word ptr [edx + 6]
// 005178c9  8bc2                 mov eax, edx
// 005178cb  0fafc1               imul eax, ecx
// 005178ce  c1e803               shr eax, 3
// 005178d1  3dc0ff3f00           cmp eax, 0x3fffc0
// 005178d6  0f863f020000         jbe 0x517b1b
// 005178dc  c7442434ffffff7f     mov dword ptr [esp + 0x34], 0x7fffffff
// 005178e4  e941020000           jmp 0x517b2a
// 005178e9  0fafd6               imul edx, esi
// 005178ec  c1ea03               shr edx, 3
// 005178ef  c1e00a               shl eax, 0xa
// 005178f2  03d0                 add edx, eax
// 005178f4  89542434             mov dword ptr [esp + 0x34], edx
// 005178f8  8b542420             mov edx, dword ptr [esp + 0x20]
// 005178fc  8b8bf4000000         mov ecx, dword ptr [ebx + 0xf4]
// 00517902  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00517906  83c201               add edx, 1
// 00517909  83c101               add ecx, 1
// 0051790c  83c001               add eax, 1
// 0051790f  837c241400           cmp dword ptr [esp + 0x14], 0
// 00517914  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0051791c  7640                 jbe 0x51795e
// 0051791e  8be8                 mov ebp, eax
// 00517920  2bea                 sub ebp, edx
// 00517922  8a02                 mov al, byte ptr [edx]
// 00517924  2a042a               sub al, byte ptr [edx + ebp]
// 00517927  83c101               add ecx, 1
// 0051792a  8841ff               mov byte ptr [ecx - 1], al
// 0051792d  0fb6c0               movzx eax, al
// 00517930  83c201               add edx, 1
// 00517933  3d80000000           cmp eax, 0x80
// 00517938  7d04                 jge 0x51793e
// 0051793a  8bf0                 mov esi, eax
// 0051793c  eb07                 jmp 0x517945
// 0051793e  be00010000           mov esi, 0x100
// 00517943  2bf0                 sub esi, eax
// 00517945  03fe                 add edi, esi
// 00517947  3b7c2434             cmp edi, dword ptr [esp + 0x34]
// 0051794b  7711                 ja 0x51795e
// 0051794d  8b442438             mov eax, dword ptr [esp + 0x38]
// 00517951  83c001               add eax, 1
// 00517954  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00517958  89442438             mov dword ptr [esp + 0x38], eax
// 0051795c  72c4                 jb 0x517922
// 0051795e  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00517965  7574                 jne 0x5179db
// 00517967  0fb7f7               movzx esi, di
// 0051796a  c1ef0a               shr edi, 0xa
// 0051796d  81e7c0ff3f00         and edi, 0x3fffc0
// 00517973  33c9                 xor ecx, ecx
// 00517975  394c2448             cmp dword ptr [esp + 0x48], ecx
// 00517979  8bd7                 mov edx, edi
// 0051797b  7e31                 jle 0x5179ae
// 0051797d  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 00517983  803c0f02             cmp byte ptr [edi + ecx], 2
// 00517987  751c                 jne 0x5179a5
// 00517989  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 0051798f  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00517993  8be8                 mov ebp, eax
// 00517995  0fafc2               imul eax, edx
// 00517998  0fafee               imul ebp, esi
// 0051799b  c1ed08               shr ebp, 8
// 0051799e  c1e808               shr eax, 8
// 005179a1  8bf5                 mov esi, ebp
// 005179a3  8bd0                 mov edx, eax
// 005179a5  83c101               add ecx, 1
// 005179a8  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 005179ac  7cd5                 jl 0x517983
// 005179ae  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 005179b4  0fb74904             movzx ecx, word ptr [ecx + 4]
// 005179b8  8bc1                 mov eax, ecx
// 005179ba  0fafc2               imul eax, edx
// 005179bd  c1e803               shr eax, 3
// 005179c0  3dc0ff3f00           cmp eax, 0x3fffc0
// 005179c5  7607                 jbe 0x5179ce
// 005179c7  bfffffff7f           mov edi, 0x7fffffff
// 005179cc  eb0d                 jmp 0x5179db
// 005179ce  0fafce               imul ecx, esi
// 005179d1  c1e903               shr ecx, 3
// 005179d4  c1e00a               shl eax, 0xa
// 005179d7  03c8                 add ecx, eax
// 005179d9  8bf9                 mov edi, ecx
// 005179db  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 005179df  730e                 jae 0x5179ef
// 005179e1  8b93f4000000         mov edx, dword ptr [ebx + 0xf4]
// 005179e7  897c2418             mov dword ptr [esp + 0x18], edi
// 005179eb  8954241c             mov dword ptr [esp + 0x1c], edx
// 005179ef  807c241340           cmp byte ptr [esp + 0x13], 0x40
// 005179f4  0f8556feffff         jne 0x517850
// 005179fa  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005179fe  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 00517a04  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00517a08  8b542428             mov edx, dword ptr [esp + 0x28]
// 00517a0c  83c501               add ebp, 1
// 00517a0f  33c0                 xor eax, eax
// 00517a11  83c101               add ecx, 1
// 00517a14  83c601               add esi, 1
// 00517a17  85d2                 test edx, edx
// 00517a19  8bfd                 mov edi, ebp
// 00517a1b  7626                 jbe 0x517a43
// 00517a1d  89542444             mov dword ptr [esp + 0x44], edx
// 00517a21  89542438             mov dword ptr [esp + 0x38], edx
// 00517a25  8a06                 mov al, byte ptr [esi]
// 00517a27  8a17                 mov dl, byte ptr [edi]
// 00517a29  d0e8                 shr al, 1
// 00517a2b  2ad0                 sub dl, al
// 00517a2d  8811                 mov byte ptr [ecx], dl
// 00517a2f  83c101               add ecx, 1
// 00517a32  83c601               add esi, 1
// 00517a35  83c701               add edi, 1
// 00517a38  836c244401           sub dword ptr [esp + 0x44], 1
// 00517a3d  75e6                 jne 0x517a25
// 00517a3f  8b442438             mov eax, dword ptr [esp + 0x38]
// 00517a43  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00517a47  7331                 jae 0x517a7a
// 00517a49  8b542414             mov edx, dword ptr [esp + 0x14]
// 00517a4d  2bd0                 sub edx, eax
// 00517a4f  89542444             mov dword ptr [esp + 0x44], edx
// 00517a53  0fb65500             movzx edx, byte ptr [ebp]
// 00517a57  0fb606               movzx eax, byte ptr [esi]
// 00517a5a  03c2                 add eax, edx
// 00517a5c  99                   cdq 
// 00517a5d  2bc2                 sub eax, edx
// 00517a5f  8a17                 mov dl, byte ptr [edi]
// 00517a61  d1f8                 sar eax, 1
// 00517a63  2ad0                 sub dl, al
// 00517a65  8811                 mov byte ptr [ecx], dl
// 00517a67  83c101               add ecx, 1
// 00517a6a  83c501               add ebp, 1
// 00517a6d  83c601               add esi, 1
// 00517a70  83c701               add edi, 1
// 00517a73  836c244401           sub dword ptr [esp + 0x44], 1
// 00517a78  75d9                 jne 0x517a53
// 00517a7a  8b83f8000000         mov eax, dword ptr [ebx + 0xf8]
// 00517a80  8944241c             mov dword ptr [esp + 0x1c], eax
// 00517a84  f644241380           test byte ptr [esp + 0x13], 0x80
// 00517a89  0f84ed040000         je 0x517f7c
// 00517a8f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00517a93  33ed                 xor ebp, ebp
// 00517a95  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00517a9c  896c2424             mov dword ptr [esp + 0x24], ebp
// 00517aa0  894c2438             mov dword ptr [esp + 0x38], ecx
// 00517aa4  0f85f5020000         jne 0x517d9f
// 00517aaa  0fb7f1               movzx esi, cx
// 00517aad  c1e90a               shr ecx, 0xa
// 00517ab0  33d2                 xor edx, edx
// 00517ab2  81e1c0ff3f00         and ecx, 0x3fffc0
// 00517ab8  39542448             cmp dword ptr [esp + 0x48], edx
// 00517abc  7e33                 jle 0x517af1
// 00517abe  8bff                 mov edi, edi
// 00517ac0  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00517ac6  803c0204             cmp byte ptr [edx + eax], 4
// 00517aca  751c                 jne 0x517ae8
// 00517acc  8b8304020000         mov eax, dword ptr [ebx + 0x204]
// 00517ad2  0fb70450             movzx eax, word ptr [eax + edx*2]
// 00517ad6  8bf8                 mov edi, eax
// 00517ad8  0fafc1               imul eax, ecx
// 00517adb  0faffe               imul edi, esi
// 00517ade  c1ef08               shr edi, 8
// 00517ae1  c1e808               shr eax, 8
// 00517ae4  8bf7                 mov esi, edi
// 00517ae6  8bc8                 mov ecx, eax
// 00517ae8  83c201               add edx, 1
// 00517aeb  3b542448             cmp edx, dword ptr [esp + 0x48]
// 00517aef  7ccf                 jl 0x517ac0
// 00517af1  8b930c020000         mov edx, dword ptr [ebx + 0x20c]
// 00517af7  0fb75208             movzx edx, word ptr [edx + 8]
// 00517afb  8bc2                 mov eax, edx
// 00517afd  0fafc1               imul eax, ecx
// 00517b00  c1e803               shr eax, 3
// 00517b03  3dc0ff3f00           cmp eax, 0x3fffc0
// 00517b08  0f8682020000         jbe 0x517d90
// 00517b0e  c7442438ffffff7f     mov dword ptr [esp + 0x38], 0x7fffffff
// 00517b16  e984020000           jmp 0x517d9f
// 00517b1b  0fafd6               imul edx, esi
// 00517b1e  c1ea03               shr edx, 3
// 00517b21  c1e00a               shl eax, 0xa
// 00517b24  03d0                 add edx, eax
// 00517b26  89542434             mov dword ptr [esp + 0x34], edx
// 00517b2a  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00517b2e  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 00517b34  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00517b38  8b442428             mov eax, dword ptr [esp + 0x28]
// 00517b3c  83c501               add ebp, 1
// 00517b3f  83c101               add ecx, 1
// 00517b42  83c601               add esi, 1
// 00517b45  85c0                 test eax, eax
// 00517b47  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00517b4f  8bfd                 mov edi, ebp
// 00517b51  7640                 jbe 0x517b93
// 00517b53  89442438             mov dword ptr [esp + 0x38], eax
// 00517b57  89442430             mov dword ptr [esp + 0x30], eax
// 00517b5b  eb03                 jmp 0x517b60
// 00517b5d  8d4900               lea ecx, [ecx]
// 00517b60  8a16                 mov dl, byte ptr [esi]
// 00517b62  8a07                 mov al, byte ptr [edi]
// 00517b64  d0ea                 shr dl, 1
// 00517b66  2ac2                 sub al, dl
// 00517b68  8801                 mov byte ptr [ecx], al
// 00517b6a  0fb6c0               movzx eax, al
// 00517b6d  83c101               add ecx, 1
// 00517b70  83c601               add esi, 1
// 00517b73  83c701               add edi, 1
// 00517b76  3d80000000           cmp eax, 0x80
// 00517b7b  7d04                 jge 0x517b81
// 00517b7d  8bd0                 mov edx, eax
// 00517b7f  eb07                 jmp 0x517b88
// 00517b81  ba00010000           mov edx, 0x100
// 00517b86  2bd0                 sub edx, eax
// 00517b88  01542424             add dword ptr [esp + 0x24], edx
// 00517b8c  836c243801           sub dword ptr [esp + 0x38], 1
// 00517b91  75cd                 jne 0x517b60
// 00517b93  8b442414             mov eax, dword ptr [esp + 0x14]
// 00517b97  39442430             cmp dword ptr [esp + 0x30], eax
// 00517b9b  735b                 jae 0x517bf8
// 00517b9d  8d4900               lea ecx, [ecx]
// 00517ba0  0fb616               movzx edx, byte ptr [esi]
// 00517ba3  0fb64500             movzx eax, byte ptr [ebp]
// 00517ba7  03c2                 add eax, edx
// 00517ba9  99                   cdq 
// 00517baa  2bc2                 sub eax, edx
// 00517bac  8bd0                 mov edx, eax
// 00517bae  8a07                 mov al, byte ptr [edi]
// 00517bb0  d1fa                 sar edx, 1
// 00517bb2  2ac2                 sub al, dl
// 00517bb4  8801                 mov byte ptr [ecx], al
// 00517bb6  0fb6c0               movzx eax, al
// 00517bb9  83c101               add ecx, 1
// 00517bbc  83c501               add ebp, 1
// 00517bbf  83c601               add esi, 1
// 00517bc2  83c701               add edi, 1
// 00517bc5  3d80000000           cmp eax, 0x80
// 00517bca  7d04                 jge 0x517bd0
// 00517bcc  8bd0                 mov edx, eax
// 00517bce  eb07                 jmp 0x517bd7
// 00517bd0  ba00010000           mov edx, 0x100
// 00517bd5  2bd0                 sub edx, eax
// 00517bd7  8b442424             mov eax, dword ptr [esp + 0x24]
// 00517bdb  03c2                 add eax, edx
// 00517bdd  3b442434             cmp eax, dword ptr [esp + 0x34]
// 00517be1  89442424             mov dword ptr [esp + 0x24], eax
// 00517be5  7711                 ja 0x517bf8
// 00517be7  8b442430             mov eax, dword ptr [esp + 0x30]
// 00517beb  83c001               add eax, 1
// 00517bee  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00517bf2  89442430             mov dword ptr [esp + 0x30], eax
// 00517bf6  72a8                 jb 0x517ba0
// 00517bf8  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00517bff  757c                 jne 0x517c7d
// 00517c01  8b542424             mov edx, dword ptr [esp + 0x24]
// 00517c05  0fb7f2               movzx esi, dx
// 00517c08  c1ea0a               shr edx, 0xa
// 00517c0b  33c9                 xor ecx, ecx
// 00517c0d  81e2c0ff3f00         and edx, 0x3fffc0
// 00517c13  394c2448             cmp dword ptr [esp + 0x48], ecx
// 00517c17  7e32                 jle 0x517c4b
// 00517c19  8bbbfc010000         mov edi, dword ptr [ebx + 0x1fc]
// 00517c1f  90                   nop 
// 00517c20  803c3900             cmp byte ptr [ecx + edi], 0
// 00517c24  751c                 jne 0x517c42
// 00517c26  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 00517c2c  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00517c30  8be8                 mov ebp, eax
// 00517c32  0fafc2               imul eax, edx
// 00517c35  0fafee               imul ebp, esi
// 00517c38  c1ed08               shr ebp, 8
// 00517c3b  c1e808               shr eax, 8
// 00517c3e  8bf5                 mov esi, ebp
// 00517c40  8bd0                 mov edx, eax
// 00517c42  83c101               add ecx, 1
// 00517c45  3b4c2448             cmp ecx, dword ptr [esp + 0x48]
// 00517c49  7cd5                 jl 0x517c20
// 00517c4b  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 00517c51  0fb74906             movzx ecx, word ptr [ecx + 6]
// 00517c55  8bc1                 mov eax, ecx
// 00517c57  0fafc2               imul eax, edx
// 00517c5a  c1e803               shr eax, 3
// 00517c5d  3dc0ff3f00           cmp eax, 0x3fffc0
// 00517c62  760a                 jbe 0x517c6e
// 00517c64  c7442424ffffff7f     mov dword ptr [esp + 0x24], 0x7fffffff
// 00517c6c  eb0f                 jmp 0x517c7d
// 00517c6e  0fafce               imul ecx, esi
// 00517c71  c1e903               shr ecx, 3
// 00517c74  c1e00a               shl eax, 0xa
// 00517c77  03c8                 add ecx, eax
// 00517c79  894c2424             mov dword ptr [esp + 0x24], ecx
// 00517c7d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00517c81  3b442418             cmp eax, dword ptr [esp + 0x18]
// 00517c85  730e                 jae 0x517c95
// 00517c87  8b93f8000000         mov edx, dword ptr [ebx + 0xf8]
// 00517c8d  89442418             mov dword ptr [esp + 0x18], eax
// 00517c91  8954241c             mov dword ptr [esp + 0x1c], edx
// 00517c95  807c241380           cmp byte ptr [esp + 0x13], 0x80
// 00517c9a  0f85e4fdffff         jne 0x517a84
// 00517ca0  8b442420             mov eax, dword ptr [esp + 0x20]
// 00517ca4  8bbbfc000000         mov edi, dword ptr [ebx + 0xfc]
// 00517caa  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00517cae  83c001               add eax, 1
// 00517cb1  83c201               add edx, 1
// 00517cb4  83c701               add edi, 1
// 00517cb7  837c242800           cmp dword ptr [esp + 0x28], 0
// 00517cbc  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00517cc4  8bc8                 mov ecx, eax
// 00517cc6  89442430             mov dword ptr [esp + 0x30], eax
// 00517cca  8bf2                 mov esi, edx
// 00517ccc  7621                 jbe 0x517cef
// 00517cce  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 00517cd2  896c2434             mov dword ptr [esp + 0x34], ebp
// 00517cd6  8a19                 mov bl, byte ptr [ecx]
// 00517cd8  2a1e                 sub bl, byte ptr [esi]
// 00517cda  83c701               add edi, 1
// 00517cdd  885fff               mov byte ptr [edi - 1], bl
// 00517ce0  83c601               add esi, 1
// 00517ce3  83c101               add ecx, 1
// 00517ce6  83ed01               sub ebp, 1
// 00517ce9  75eb                 jne 0x517cd6
// 00517ceb  894c2430             mov dword ptr [esp + 0x30], ecx
// 00517cef  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00517cf3  395c2434             cmp dword ptr [esp + 0x34], ebx
// 00517cf7  8be8                 mov ebp, eax
// 00517cf9  0f8388000000         jae 0x517d87
// 00517cff  8bca                 mov ecx, edx
// 00517d01  2bc8                 sub ecx, eax
// 00517d03  2b5c2434             sub ebx, dword ptr [esp + 0x34]
// 00517d07  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00517d0b  895c2434             mov dword ptr [esp + 0x34], ebx
// 00517d0f  eb04                 jmp 0x517d15
// 00517d11  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00517d15  0fb61429             movzx edx, byte ptr [ecx + ebp]
// 00517d19  0fb606               movzx eax, byte ptr [esi]
// 00517d1c  0fb64d00             movzx ecx, byte ptr [ebp]
// 00517d20  89442424             mov dword ptr [esp + 0x24], eax
// 00517d24  894c2428             mov dword ptr [esp + 0x28], ecx
// 00517d28  2bc2                 sub eax, edx
// 00517d2a  83c601               add esi, 1
// 00517d2d  83c501               add ebp, 1
// 00517d30  2bca                 sub ecx, edx
// 00517d32  85c0                 test eax, eax
// 00517d34  7d0a                 jge 0x517d40
// 00517d36  8bd8                 mov ebx, eax
// 00517d38  f7db                 neg ebx
// 00517d3a  895c2438             mov dword ptr [esp + 0x38], ebx
// 00517d3e  eb04                 jmp 0x517d44
// 00517d40  89442438             mov dword ptr [esp + 0x38], eax
// 00517d44  85c9                 test ecx, ecx
// 00517d46  8bd9                 mov ebx, ecx
// 00517d48  7d02                 jge 0x517d4c
// 00517d4a  f7db                 neg ebx
// 00517d4c  03c1                 add eax, ecx
// 00517d4e  7902                 jns 0x517d52
// 00517d50  f7d8                 neg eax
// 00517d52  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00517d56  3bcb                 cmp ecx, ebx
// 00517d58  7f0a                 jg 0x517d64
// 00517d5a  3bc8                 cmp ecx, eax
// 00517d5c  7f06                 jg 0x517d64
// 00517d5e  8b542428             mov edx, dword ptr [esp + 0x28]
// 00517d62  eb08                 jmp 0x517d6c
// 00517d64  3bd8                 cmp ebx, eax
// 00517d66  7f04                 jg 0x517d6c
// 00517d68  8b542424             mov edx, dword ptr [esp + 0x24]
// 00517d6c  8b442430             mov eax, dword ptr [esp + 0x30]
// 00517d70  8a08                 mov cl, byte ptr [eax]
// 00517d72  2aca                 sub cl, dl
// 00517d74  880f                 mov byte ptr [edi], cl
// 00517d76  83c001               add eax, 1
// 00517d79  83c701               add edi, 1
// 00517d7c  836c243401           sub dword ptr [esp + 0x34], 1
// 00517d81  89442430             mov dword ptr [esp + 0x30], eax
// 00517d85  758a                 jne 0x517d11
// 00517d87  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 00517d8b  e9e2010000           jmp 0x517f72
// 00517d90  0fafd6               imul edx, esi
// 00517d93  c1ea03               shr edx, 3
// 00517d96  c1e00a               shl eax, 0xa
// 00517d99  03d0                 add edx, eax
// 00517d9b  89542438             mov dword ptr [esp + 0x38], edx
// 00517d9f  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00517da3  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00517da7  8bb3fc000000         mov esi, dword ptr [ebx + 0xfc]
// 00517dad  8b442428             mov eax, dword ptr [esp + 0x28]
// 00517db1  83c701               add edi, 1
// 00517db4  83c201               add edx, 1
// 00517db7  83c601               add esi, 1
// 00517dba  85c0                 test eax, eax
// 00517dbc  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00517dc4  897c2430             mov dword ptr [esp + 0x30], edi
// 00517dc8  897c2434             mov dword ptr [esp + 0x34], edi
// 00517dcc  8954242c             mov dword ptr [esp + 0x2c], edx
// 00517dd0  7644                 jbe 0x517e16
// 00517dd2  89442434             mov dword ptr [esp + 0x34], eax
// 00517dd6  89442444             mov dword ptr [esp + 0x44], eax
// 00517dda  8d9b00000000         lea ebx, [ebx]
// 00517de0  8a07                 mov al, byte ptr [edi]
// 00517de2  2a02                 sub al, byte ptr [edx]
// 00517de4  83c601               add esi, 1
// 00517de7  8846ff               mov byte ptr [esi - 1], al
// 00517dea  0fb6c0               movzx eax, al
// 00517ded  83c201               add edx, 1
// 00517df0  83c701               add edi, 1
// 00517df3  3d80000000           cmp eax, 0x80
// 00517df8  7d04                 jge 0x517dfe
// 00517dfa  8bc8                 mov ecx, eax
// 00517dfc  eb07                 jmp 0x517e05
// 00517dfe  b900010000           mov ecx, 0x100
// 00517e03  2bc8                 sub ecx, eax
// 00517e05  03e9                 add ebp, ecx
// 00517e07  836c243401           sub dword ptr [esp + 0x34], 1
// 00517e0c  75d2                 jne 0x517de0
// 00517e0e  896c2424             mov dword ptr [esp + 0x24], ebp
// 00517e12  897c2434             mov dword ptr [esp + 0x34], edi
// 00517e16  8b442444             mov eax, dword ptr [esp + 0x44]
// 00517e1a  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00517e1e  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00517e22  0f83c0000000         jae 0x517ee8
// 00517e28  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00517e2c  2bf9                 sub edi, ecx
// 00517e2e  897c242c             mov dword ptr [esp + 0x2c], edi
// 00517e32  eb0c                 jmp 0x517e40
// 00517e34  8b542428             mov edx, dword ptr [esp + 0x28]
// 00517e38  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00517e3c  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00517e40  0fb602               movzx eax, byte ptr [edx]
// 00517e43  83c201               add edx, 1
// 00517e46  89542428             mov dword ptr [esp + 0x28], edx
// 00517e4a  0fb6140f             movzx edx, byte ptr [edi + ecx]
// 00517e4e  0fb639               movzx edi, byte ptr [ecx]
// 00517e51  83c101               add ecx, 1
// 00517e54  894c2420             mov dword ptr [esp + 0x20], ecx
// 00517e58  8944243c             mov dword ptr [esp + 0x3c], eax
// 00517e5c  8bcf                 mov ecx, edi
// 00517e5e  2bc2                 sub eax, edx
// 00517e60  2bca                 sub ecx, edx
// 00517e62  85c0                 test eax, eax
// 00517e64  7d0a                 jge 0x517e70
// 00517e66  8be8                 mov ebp, eax
// 00517e68  f7dd                 neg ebp
// 00517e6a  896c2430             mov dword ptr [esp + 0x30], ebp
// 00517e6e  eb04                 jmp 0x517e74
// 00517e70  89442430             mov dword ptr [esp + 0x30], eax
// 00517e74  85c9                 test ecx, ecx
// 00517e76  8be9                 mov ebp, ecx
// 00517e78  7d02                 jge 0x517e7c
// 00517e7a  f7dd                 neg ebp
// 00517e7c  03c1                 add eax, ecx
// 00517e7e  7902                 jns 0x517e82
// 00517e80  f7d8                 neg eax
// 00517e82  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00517e86  3bcd                 cmp ecx, ebp
// 00517e88  7f08                 jg 0x517e92
// 00517e8a  3bc8                 cmp ecx, eax
// 00517e8c  7f04                 jg 0x517e92
// 00517e8e  8bd7                 mov edx, edi
// 00517e90  eb08                 jmp 0x517e9a
// 00517e92  3be8                 cmp ebp, eax
// 00517e94  7f04                 jg 0x517e9a
// 00517e96  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00517e9a  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00517e9e  8a01                 mov al, byte ptr [ecx]
// 00517ea0  2ac2                 sub al, dl
// 00517ea2  8806                 mov byte ptr [esi], al
// 00517ea4  0fb6c0               movzx eax, al
// 00517ea7  83c101               add ecx, 1
// 00517eaa  83c601               add esi, 1
// 00517ead  3d80000000           cmp eax, 0x80
// 00517eb2  894c2434             mov dword ptr [esp + 0x34], ecx
// 00517eb6  7d04                 jge 0x517ebc
// 00517eb8  8bc8                 mov ecx, eax
// 00517eba  eb07                 jmp 0x517ec3
// 00517ebc  b900010000           mov ecx, 0x100
// 00517ec1  2bc8                 sub ecx, eax
// 00517ec3  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00517ec7  03e9                 add ebp, ecx
// 00517ec9  3b6c2438             cmp ebp, dword ptr [esp + 0x38]
// 00517ecd  896c2424             mov dword ptr [esp + 0x24], ebp
// 00517ed1  7715                 ja 0x517ee8
// 00517ed3  8b442444             mov eax, dword ptr [esp + 0x44]
// 00517ed7  83c001               add eax, 1
// 00517eda  3b442414             cmp eax, dword ptr [esp + 0x14]
// 00517ede  89442444             mov dword ptr [esp + 0x44], eax
// 00517ee2  0f824cffffff         jb 0x517e34
// 00517ee8  80bbf801000002       cmp byte ptr [ebx + 0x1f8], 2
// 00517eef  757b                 jne 0x517f6c
// 00517ef1  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 00517ef5  0fb7f5               movzx esi, bp
// 00517ef8  c1ed0a               shr ebp, 0xa
// 00517efb  81e5c0ff3f00         and ebp, 0x3fffc0
// 00517f01  33c9                 xor ecx, ecx
// 00517f03  85ff                 test edi, edi
// 00517f05  8bd5                 mov edx, ebp
// 00517f07  7e36                 jle 0x517f3f
// 00517f09  8da42400000000       lea esp, [esp]
// 00517f10  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00517f16  803c0104             cmp byte ptr [ecx + eax], 4
// 00517f1a  751c                 jne 0x517f38
// 00517f1c  8b8300020000         mov eax, dword ptr [ebx + 0x200]
// 00517f22  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 00517f26  8be8                 mov ebp, eax
// 00517f28  0fafc2               imul eax, edx
// 00517f2b  0fafee               imul ebp, esi
// 00517f2e  c1ed08               shr ebp, 8
// 00517f31  c1e808               shr eax, 8
// 00517f34  8bf5                 mov esi, ebp
// 00517f36  8bd0                 mov edx, eax
// 00517f38  83c101               add ecx, 1
// 00517f3b  3bcf                 cmp ecx, edi
// 00517f3d  7cd1                 jl 0x517f10
// 00517f3f  8b8b08020000         mov ecx, dword ptr [ebx + 0x208]
// 00517f45  0fb74908             movzx ecx, word ptr [ecx + 8]
// 00517f49  8bc1                 mov eax, ecx
// 00517f4b  0fafc2               imul eax, edx
// 00517f4e  c1e803               shr eax, 3
// 00517f51  3dc0ff3f00           cmp eax, 0x3fffc0
// 00517f56  7607                 jbe 0x517f5f
// 00517f58  bdffffff7f           mov ebp, 0x7fffffff
// 00517f5d  eb0d                 jmp 0x517f6c
// 00517f5f  0fafce               imul ecx, esi
// 00517f62  c1e903               shr ecx, 3
// 00517f65  c1e00a               shl eax, 0xa
// 00517f68  03c8                 add ecx, eax
// 00517f6a  8be9                 mov ebp, ecx
// 00517f6c  3b6c2418             cmp ebp, dword ptr [esp + 0x18]
// 00517f70  730a                 jae 0x517f7c
// 00517f72  8b93fc000000         mov edx, dword ptr [ebx + 0xfc]
// 00517f78  8954241c             mov dword ptr [esp + 0x1c], edx
// 00517f7c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00517f80  50                   push eax
// 00517f81  53                   push ebx
// 00517f82  e8a9f3ffff           call 0x517330
// 00517f87  83c408               add esp, 8
// 00517f8a  80bbf901000000       cmp byte ptr [ebx + 0x1f9], 0
// 00517f91  7633                 jbe 0x517fc6
// 00517f93  b801000000           mov eax, 1
// 00517f98  39442448             cmp dword ptr [esp + 0x48], eax
// 00517f9c  7e19                 jle 0x517fb7
// 00517f9e  8bff                 mov edi, edi
// 00517fa0  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 00517fa6  8a5401ff             mov dl, byte ptr [ecx + eax - 1]
// 00517faa  03c8                 add ecx, eax
// 00517fac  83c001               add eax, 1
// 00517faf  3b442448             cmp eax, dword ptr [esp + 0x48]
// 00517fb3  8811                 mov byte ptr [ecx], dl
// 00517fb5  7ce9                 jl 0x517fa0
// 00517fb7  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00517fbb  8b8bfc010000         mov ecx, dword ptr [ebx + 0x1fc]
// 00517fc1  8a12                 mov dl, byte ptr [edx]
// 00517fc3  881408               mov byte ptr [eax + ecx], dl
// 00517fc6  5f                   pop edi
// 00517fc7  5e                   pop esi
// 00517fc8  5d                   pop ebp
// 00517fc9  5b                   pop ebx
// 00517fca  83c430               add esp, 0x30
// 00517fcd  c3                   ret 
// library libpng-1.2.7/pngwutil.c (function _png_write_find_filter)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwutil.c
