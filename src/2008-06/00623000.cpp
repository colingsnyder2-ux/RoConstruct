// from server: 100% by auto
// roc 2008-06 00623000  unit: lua_exception  size: 1108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00623000
//
// 00623000  83ec20               sub esp, 0x20
// 00623003  8b442424             mov eax, dword ptr [esp + 0x24]
// 00623007  8b482c               mov ecx, dword ptr [eax + 0x2c]
// 0062300a  53                   push ebx
// 0062300b  8a584b               mov bl, byte ptr [eax + 0x4b]
// 0062300e  8d51ff               lea edx, [ecx - 1]
// 00623011  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00623015  89542418             mov dword ptr [esp + 0x18], edx
// 00623019  885c2407             mov byte ptr [esp + 7], bl
// 0062301d  80fbfa               cmp bl, 0xfa
// 00623020  772b                 ja 0x62304d
// 00623022  0fb65048             movzx edx, byte ptr [eax + 0x48]
// 00623026  395024               cmp dword ptr [eax + 0x24], edx
// 00623029  89542420             mov dword ptr [esp + 0x20], edx
// 0062302d  7f1e                 jg 0x62304d
// 0062302f  8b5030               mov edx, dword ptr [eax + 0x30]
// 00623032  3bd1                 cmp edx, ecx
// 00623034  7404                 je 0x62303a
// 00623036  85d2                 test edx, edx
// 00623038  7513                 jne 0x62304d
// 0062303a  8b400c               mov eax, dword ptr [eax + 0xc]
// 0062303d  8b4c88fc             mov ecx, dword ptr [eax + ecx*4 - 4]
// 00623041  83e13f               and ecx, 0x3f
// 00623044  89442410             mov dword ptr [esp + 0x10], eax
// 00623048  80f91e               cmp cl, 0x1e
// 0062304b  7407                 je 0x623054
// 0062304d  33c0                 xor eax, eax
// 0062304f  5b                   pop ebx
// 00623050  83c420               add esp, 0x20
// 00623053  c3                   ret 
// 00623054  837c242c00           cmp dword ptr [esp + 0x2c], 0
// 00623059  55                   push ebp
// 0062305a  56                   push esi
// 0062305b  57                   push edi
// 0062305c  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00623064  7f1e                 jg 0x623084
// 00623066  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0062306a  8b0488               mov eax, dword ptr [eax + ecx*4]
// 0062306d  5f                   pop edi
// 0062306e  5e                   pop esi
// 0062306f  5d                   pop ebp
// 00623070  5b                   pop ebx
// 00623071  83c420               add esp, 0x20
// 00623074  c3                   ret 
// 00623075  eb09                 jmp 0x623080
// 00623077  8da42400000000       lea esp, [esp]
// 0062307e  8bff                 mov edi, edi
// 00623080  8a5c2413             mov bl, byte ptr [esp + 0x13]
// 00623084  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00623088  8b442420             mov eax, dword ptr [esp + 0x20]
// 0062308c  8b0482               mov eax, dword ptr [edx + eax*4]
// 0062308f  8bf8                 mov edi, eax
// 00623091  8be8                 mov ebp, eax
// 00623093  c1ef06               shr edi, 6
// 00623096  83e53f               and ebp, 0x3f
// 00623099  33f6                 xor esi, esi
// 0062309b  81e7ff000000         and edi, 0xff
// 006230a1  83fd26               cmp ebp, 0x26
// 006230a4  89742414             mov dword ptr [esp + 0x14], esi
// 006230a8  0f8d86000000         jge 0x623134
// 006230ae  0fb6cb               movzx ecx, bl
// 006230b1  3bf9                 cmp edi, ecx
// 006230b3  894c2418             mov dword ptr [esp + 0x18], ecx
// 006230b7  7d7b                 jge 0x623134
// 006230b9  8a9544c98400         mov dl, byte ptr [ebp + 0x84c944]
// 006230bf  0fb6da               movzx ebx, dl
// 006230c2  8bcb                 mov ecx, ebx
// 006230c4  83e103               and ecx, 3
// 006230c7  2bce                 sub ecx, esi
// 006230c9  7473                 je 0x62313e
// 006230cb  83e901               sub ecx, 1
// 006230ce  744e                 je 0x62311e
// 006230d0  83e901               sub ecx, 1
// 006230d3  0f85a6000000         jne 0x62317f
// 006230d9  c1e80e               shr eax, 0xe
// 006230dc  2dffff0100           sub eax, 0x1ffff
// 006230e1  80e230               and dl, 0x30
// 006230e4  8bf0                 mov esi, eax
// 006230e6  80fa20               cmp dl, 0x20
// 006230e9  0f8590000000         jne 0x62317f
// 006230ef  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006230f3  8d440e01             lea eax, [esi + ecx + 1]
// 006230f7  85c0                 test eax, eax
// 006230f9  7c39                 jl 0x623134
// 006230fb  3b442428             cmp eax, dword ptr [esp + 0x28]
// 006230ff  7d33                 jge 0x623134
// 00623101  85c0                 test eax, eax
// 00623103  7e7a                 jle 0x62317f
// 00623105  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00623109  8b4482fc             mov eax, dword ptr [edx + eax*4 - 4]
// 0062310d  8bc8                 mov ecx, eax
// 0062310f  83e13f               and ecx, 0x3f
// 00623112  80f922               cmp cl, 0x22
// 00623115  7568                 jne 0x62317f
// 00623117  a900c07f00           test eax, 0x7fc000
// 0062311c  eb5f                 jmp 0x62317d
// 0062311e  c1e80e               shr eax, 0xe
// 00623121  80e230               and dl, 0x30
// 00623124  8bf0                 mov esi, eax
// 00623126  80fa30               cmp dl, 0x30
// 00623129  7554                 jne 0x62317f
// 0062312b  8b542434             mov edx, dword ptr [esp + 0x34]
// 0062312f  3b7228               cmp esi, dword ptr [edx + 0x28]
// 00623132  7c4b                 jl 0x62317f
// 00623134  5f                   pop edi
// 00623135  5e                   pop esi
// 00623136  5d                   pop ebp
// 00623137  33c0                 xor eax, eax
// 00623139  5b                   pop ebx
// 0062313a  83c420               add esp, 0x20
// 0062313d  c3                   ret 
// 0062313e  8b542434             mov edx, dword ptr [esp + 0x34]
// 00623142  8bf0                 mov esi, eax
// 00623144  c1e80e               shr eax, 0xe
// 00623147  25ff010000           and eax, 0x1ff
// 0062314c  89442414             mov dword ptr [esp + 0x14], eax
// 00623150  8bc3                 mov eax, ebx
// 00623152  c1e804               shr eax, 4
// 00623155  c1ee17               shr esi, 0x17
// 00623158  83e003               and eax, 3
// 0062315b  8bce                 mov ecx, esi
// 0062315d  e84efeffff           call 0x622fb0
// 00623162  85c0                 test eax, eax
// 00623164  74ce                 je 0x623134
// 00623166  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0062316a  8b542434             mov edx, dword ptr [esp + 0x34]
// 0062316e  8bc3                 mov eax, ebx
// 00623170  c1e802               shr eax, 2
// 00623173  83e003               and eax, 3
// 00623176  e835feffff           call 0x622fb0
// 0062317b  85c0                 test eax, eax
// 0062317d  74b5                 je 0x623134
// 0062317f  8a8544c98400         mov al, byte ptr [ebp + 0x84c944]
// 00623185  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00623189  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0062318d  a840                 test al, 0x40
// 0062318f  7408                 je 0x623199
// 00623191  3bf9                 cmp edi, ecx
// 00623193  7504                 jne 0x623199
// 00623195  895c2424             mov dword ptr [esp + 0x24], ebx
// 00623199  8b542428             mov edx, dword ptr [esp + 0x28]
// 0062319d  84c0                 test al, al
// 0062319f  791a                 jns 0x6231bb
// 006231a1  8d4302               lea eax, [ebx + 2]
// 006231a4  3bc2                 cmp eax, edx
// 006231a6  7d8c                 jge 0x623134
// 006231a8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006231ac  8b449804             mov eax, dword ptr [eax + ebx*4 + 4]
// 006231b0  83e03f               and eax, 0x3f
// 006231b3  3c16                 cmp al, 0x16
// 006231b5  0f8579ffffff         jne 0x623134
// 006231bb  83c5fe               add ebp, -2
// 006231be  83fd23               cmp ebp, 0x23
// 006231c1  0f870b020000         ja 0x6233d2
// 006231c7  0fb68530346200       movzx eax, byte ptr [ebp + 0x623430]
// 006231ce  ff2485f4336200       jmp dword ptr [eax*4 + 0x6233f4]
// 006231d5  837c241400           cmp dword ptr [esp + 0x14], 0
// 006231da  0f84f2010000         je 0x6233d2
// 006231e0  8d4b02               lea ecx, [ebx + 2]
// 006231e3  3bca                 cmp ecx, edx
// 006231e5  e9e2010000           jmp 0x6233cc
// 006231ea  3bf9                 cmp edi, ecx
// 006231ec  0f8fe0010000         jg 0x6233d2
// 006231f2  3bce                 cmp ecx, esi
// 006231f4  0f8fd8010000         jg 0x6233d2
// 006231fa  895c2424             mov dword ptr [esp + 0x24], ebx
// 006231fe  e9cf010000           jmp 0x6233d2
// 00623203  3b74242c             cmp esi, dword ptr [esp + 0x2c]
// 00623207  e9c0010000           jmp 0x6233cc
// 0062320c  8b542434             mov edx, dword ptr [esp + 0x34]
// 00623210  8b4208               mov eax, dword ptr [edx + 8]
// 00623213  c1e604               shl esi, 4
// 00623216  837c060804           cmp dword ptr [esi + eax + 8], 4
// 0062321b  0f8513ffffff         jne 0x623134
// 00623221  e9ac010000           jmp 0x6233d2
// 00623226  47                   inc edi
// 00623227  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 0062322b  0f8d03ffffff         jge 0x623134
// 00623231  3bcf                 cmp ecx, edi
// 00623233  0f8599010000         jne 0x6233d2
// 00623239  895c2424             mov dword ptr [esp + 0x24], ebx
// 0062323d  e990010000           jmp 0x6233d2
// 00623242  3b742414             cmp esi, dword ptr [esp + 0x14]
// 00623246  e981010000           jmp 0x6233cc
// 0062324b  8b442414             mov eax, dword ptr [esp + 0x14]
// 0062324f  83f801               cmp eax, 1
// 00623252  0f8cdcfeffff         jl 0x623134
// 00623258  8d543802             lea edx, [eax + edi + 2]
// 0062325c  3b542418             cmp edx, dword ptr [esp + 0x18]
// 00623260  0f8dcefeffff         jge 0x623134
// 00623266  83c702               add edi, 2
// 00623269  3bcf                 cmp ecx, edi
// 0062326b  0f8c61010000         jl 0x6233d2
// 00623271  895c2424             mov dword ptr [esp + 0x24], ebx
// 00623275  e958010000           jmp 0x6233d2
// 0062327a  83c703               add edi, 3
// 0062327d  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 00623281  0f8dadfeffff         jge 0x623134
// 00623287  8d441e01             lea eax, [esi + ebx + 1]
// 0062328b  81f9ff000000         cmp ecx, 0xff
// 00623291  0f843b010000         je 0x6233d2
// 00623297  3bd8                 cmp ebx, eax
// 00623299  0f8d33010000         jge 0x6233d2
// 0062329f  3b442438             cmp eax, dword ptr [esp + 0x38]
// 006232a3  0f8f29010000         jg 0x6233d2
// 006232a9  03de                 add ebx, esi
// 006232ab  e922010000           jmp 0x6233d2
// 006232b0  85f6                 test esi, esi
// 006232b2  740e                 je 0x6232c2
// 006232b4  8d443eff             lea eax, [esi + edi - 1]
// 006232b8  3b442418             cmp eax, dword ptr [esp + 0x18]
// 006232bc  0f8d72feffff         jge 0x623134
// 006232c2  8b442414             mov eax, dword ptr [esp + 0x14]
// 006232c6  48                   dec eax
// 006232c7  83f8ff               cmp eax, -1
// 006232ca  751f                 jne 0x6232eb
// 006232cc  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006232d0  8b549904             mov edx, dword ptr [ecx + ebx*4 + 4]
// 006232d4  52                   push edx
// 006232d5  e8a6fcffff           call 0x622f80
// 006232da  83c404               add esp, 4
// 006232dd  85c0                 test eax, eax
// 006232df  0f844ffeffff         je 0x623134
// 006232e5  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 006232e9  eb12                 jmp 0x6232fd
// 006232eb  85c0                 test eax, eax
// 006232ed  740e                 je 0x6232fd
// 006232ef  8d4438ff             lea eax, [eax + edi - 1]
// 006232f3  3b442418             cmp eax, dword ptr [esp + 0x18]
// 006232f7  0f8d37feffff         jge 0x623134
// 006232fd  3bcf                 cmp ecx, edi
// 006232ff  0f8ccd000000         jl 0x6233d2
// 00623305  895c2424             mov dword ptr [esp + 0x24], ebx
// 00623309  e9c4000000           jmp 0x6233d2
// 0062330e  4e                   dec esi
// 0062330f  85f6                 test esi, esi
// 00623311  0f8ebb000000         jle 0x6233d2
// 00623317  8d4c3eff             lea ecx, [esi + edi - 1]
// 0062331b  3b4c2418             cmp ecx, dword ptr [esp + 0x18]
// 0062331f  e9a8000000           jmp 0x6233cc
// 00623324  85f6                 test esi, esi
// 00623326  7e0c                 jle 0x623334
// 00623328  03f7                 add esi, edi
// 0062332a  3b742418             cmp esi, dword ptr [esp + 0x18]
// 0062332e  0f8d00feffff         jge 0x623134
// 00623334  837c241400           cmp dword ptr [esp + 0x14], 0
// 00623339  0f8593000000         jne 0x6233d2
// 0062333f  43                   inc ebx
// 00623340  e98d000000           jmp 0x6233d2
// 00623345  8b442434             mov eax, dword ptr [esp + 0x34]
// 00623349  3b7034               cmp esi, dword ptr [eax + 0x34]
// 0062334c  0f8de2fdffff         jge 0x623134
// 00623352  8b4010               mov eax, dword ptr [eax + 0x10]
// 00623355  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 00623358  0fb64948             movzx ecx, byte ptr [ecx + 0x48]
// 0062335c  8d0419               lea eax, [ecx + ebx]
// 0062335f  3bc2                 cmp eax, edx
// 00623361  0f8dcdfdffff         jge 0x623134
// 00623367  85c9                 test ecx, ecx
// 00623369  7e67                 jle 0x6233d2
// 0062336b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0062336f  8d3482               lea esi, [edx + eax*4]
// 00623372  8b06                 mov eax, dword ptr [esi]
// 00623374  83e03f               and eax, 0x3f
// 00623377  83f804               cmp eax, 4
// 0062337a  7408                 je 0x623384
// 0062337c  85c0                 test eax, eax
// 0062337e  0f85b0fdffff         jne 0x623134
// 00623384  49                   dec ecx
// 00623385  83ee04               sub esi, 4
// 00623388  85c9                 test ecx, ecx
// 0062338a  7fe6                 jg 0x623372
// 0062338c  eb44                 jmp 0x6233d2
// 0062338e  8b442434             mov eax, dword ptr [esp + 0x34]
// 00623392  8a404a               mov al, byte ptr [eax + 0x4a]
// 00623395  a802                 test al, 2
// 00623397  0f8497fdffff         je 0x623134
// 0062339d  a804                 test al, 4
// 0062339f  0f858ffdffff         jne 0x623134
// 006233a5  4e                   dec esi
// 006233a6  83feff               cmp esi, -1
// 006233a9  7519                 jne 0x6233c4
// 006233ab  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006233af  8b549904             mov edx, dword ptr [ecx + ebx*4 + 4]
// 006233b3  52                   push edx
// 006233b4  e8c7fbffff           call 0x622f80
// 006233b9  83c404               add esp, 4
// 006233bc  85c0                 test eax, eax
// 006233be  0f8470fdffff         je 0x623134
// 006233c4  8d443eff             lea eax, [esi + edi - 1]
// 006233c8  3b442418             cmp eax, dword ptr [esp + 0x18]
// 006233cc  0f8d62fdffff         jge 0x623134
// 006233d2  43                   inc ebx
// 006233d3  3b5c2438             cmp ebx, dword ptr [esp + 0x38]
// 006233d7  895c2420             mov dword ptr [esp + 0x20], ebx
// 006233db  0f8c9ffcffff         jl 0x623080
// 006233e1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006233e5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006233e9  8b0488               mov eax, dword ptr [eax + ecx*4]
// 006233ec  5f                   pop edi
// 006233ed  5e                   pop esi
// 006233ee  5d                   pop ebp
// 006233ef  5b                   pop ebx
// 006233f0  83c420               add esp, 0x20
// 006233f3  c3                   ret 
// 006233f4  d531                 aad 0x31
// 006233f6  6200                 bound eax, qword ptr [eax]
// 006233f8  ea316200033262       ljmp 0x6232:0x3006231
// 006233ff  000c32               add byte ptr [edx + esi], cl
// 00623402  6200                 bound eax, qword ptr [eax]
// 00623404  26326200             xor ah, byte ptr es:[edx]
// 00623408  42                   inc edx
// 00623409  326200               xor ah, byte ptr [edx]
// 0062340c  8732                 xchg dword ptr [edx], esi
// 0062340e  6200                 bound eax, qword ptr [eax]
// 00623410  b032                 mov al, 0x32
// 00623412  6200                 bound eax, qword ptr [eax]
// 00623414  0e                   push cs
// 00623415  336200               xor esp, dword ptr [edx]
// 00623418  7a32                 jp 0x62344c
// 0062341a  6200                 bound eax, qword ptr [eax]
// 0062341c  4b                   dec ebx
// 0062341d  326200               xor ah, byte ptr [edx]
// 00623420  2433                 and al, 0x33
// 00623422  6200                 bound eax, qword ptr [eax]
// 00623424  45                   inc ebp
// 00623425  336200               xor esp, dword ptr [edx]
// library lua-5.1/ldebug.c (function _symbexec)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
