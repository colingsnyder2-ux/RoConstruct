// from server: 100% by Yeetserama
// roc 2010-06 00622f80  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 724 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00622f80
//
// 00622f80  64a100000000         mov eax, dword ptr fs:[0]
// 00622f86  6aff                 push -1
// 00622f88  68e22f9a00           push 0x9a2fe2
// 00622f8d  50                   push eax
// 00622f8e  64892500000000       mov dword ptr fs:[0], esp
// 00622f95  8b442418             mov eax, dword ptr [esp + 0x18]
// 00622f99  83ec48               sub esp, 0x48
// 00622f9c  80783500             cmp byte ptr [eax + 0x35], 0
// 00622fa0  55                   push ebp
// 00622fa1  8be9                 mov ebp, ecx
// 00622fa3  7459                 je 0x622ffe
// 00622fa5  688c00a000           push 0xa0008c
// 00622faa  8d4c240c             lea ecx, [esp + 0xc]
// 00622fae  ff1510a49e00         call dword ptr [0x9ea410]
// 00622fb4  8d4c2424             lea ecx, [esp + 0x24]
// 00622fb8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00622fc0  ff1518a99e00         call dword ptr [0x9ea918]
// 00622fc6  8d442408             lea eax, [esp + 8]
// 00622fca  50                   push eax
// 00622fcb  8d4c2434             lea ecx, [esp + 0x34]
// 00622fcf  c644245801           mov byte ptr [esp + 0x58], 1
// 00622fd4  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 00622fdc  ff150ca49e00         call dword ptr [0x9ea40c]
// 00622fe2  68081bb000           push 0xb01b08
// 00622fe7  8d4c2428             lea ecx, [esp + 0x28]
// 00622feb  51                   push ecx
// 00622fec  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00622ff1  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 00622ff9  e8b4591800           call 0x7a89b2
// 00622ffe  53                   push ebx
// 00622fff  56                   push esi
// 00623000  8bd8                 mov ebx, eax
// 00623002  57                   push edi
// 00623003  8d4c246c             lea ecx, [esp + 0x6c]
// 00623007  895c2410             mov dword ptr [esp + 0x10], ebx
// 0062300b  e8f029ecff           call 0x4e5a00
// 00623010  8b0b                 mov ecx, dword ptr [ebx]
// 00623012  80793500             cmp byte ptr [ecx + 0x35], 0
// 00623016  7405                 je 0x62301d
// 00623018  8b7b08               mov edi, dword ptr [ebx + 8]
// 0062301b  eb1b                 jmp 0x623038
// 0062301d  8b5308               mov edx, dword ptr [ebx + 8]
// 00623020  807a3500             cmp byte ptr [edx + 0x35], 0
// 00623024  7404                 je 0x62302a
// 00623026  8bf9                 mov edi, ecx
// 00623028  eb0e                 jmp 0x623038
// 0062302a  8b442470             mov eax, dword ptr [esp + 0x70]
// 0062302e  8b7808               mov edi, dword ptr [eax + 8]
// 00623031  8d5008               lea edx, [eax + 8]
// 00623034  3bc3                 cmp eax, ebx
// 00623036  756b                 jne 0x6230a3
// 00623038  807f3500             cmp byte ptr [edi + 0x35], 0
// 0062303c  8b7304               mov esi, dword ptr [ebx + 4]
// 0062303f  7503                 jne 0x623044
// 00623041  897704               mov dword ptr [edi + 4], esi
// 00623044  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00623047  395804               cmp dword ptr [eax + 4], ebx
// 0062304a  7505                 jne 0x623051
// 0062304c  897804               mov dword ptr [eax + 4], edi
// 0062304f  eb0b                 jmp 0x62305c
// 00623051  391e                 cmp dword ptr [esi], ebx
// 00623053  7504                 jne 0x623059
// 00623055  893e                 mov dword ptr [esi], edi
// 00623057  eb03                 jmp 0x62305c
// 00623059  897e08               mov dword ptr [esi + 8], edi
// 0062305c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0062305f  8b03                 mov eax, dword ptr [ebx]
// 00623061  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00623065  7515                 jne 0x62307c
// 00623067  807f3500             cmp byte ptr [edi + 0x35], 0
// 0062306b  7404                 je 0x623071
// 0062306d  8bc6                 mov eax, esi
// 0062306f  eb09                 jmp 0x62307a
// 00623071  57                   push edi
// 00623072  e889e6ffff           call 0x621700
// 00623077  83c404               add esp, 4
// 0062307a  8903                 mov dword ptr [ebx], eax
// 0062307c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0062307f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00623083  394b08               cmp dword ptr [ebx + 8], ecx
// 00623086  7577                 jne 0x6230ff
// 00623088  807f3500             cmp byte ptr [edi + 0x35], 0
// 0062308c  7407                 je 0x623095
// 0062308e  8bc6                 mov eax, esi
// 00623090  894308               mov dword ptr [ebx + 8], eax
// 00623093  eb6a                 jmp 0x6230ff
// 00623095  57                   push edi
// 00623096  e84529ecff           call 0x4e59e0
// 0062309b  83c404               add esp, 4
// 0062309e  894308               mov dword ptr [ebx + 8], eax
// 006230a1  eb5c                 jmp 0x6230ff
// 006230a3  894104               mov dword ptr [ecx + 4], eax
// 006230a6  8b0b                 mov ecx, dword ptr [ebx]
// 006230a8  8908                 mov dword ptr [eax], ecx
// 006230aa  3b4308               cmp eax, dword ptr [ebx + 8]
// 006230ad  7504                 jne 0x6230b3
// 006230af  8bf0                 mov esi, eax
// 006230b1  eb19                 jmp 0x6230cc
// 006230b3  807f3500             cmp byte ptr [edi + 0x35], 0
// 006230b7  8b7004               mov esi, dword ptr [eax + 4]
// 006230ba  7503                 jne 0x6230bf
// 006230bc  897704               mov dword ptr [edi + 4], esi
// 006230bf  893e                 mov dword ptr [esi], edi
// 006230c1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006230c4  890a                 mov dword ptr [edx], ecx
// 006230c6  8b5308               mov edx, dword ptr [ebx + 8]
// 006230c9  894204               mov dword ptr [edx + 4], eax
// 006230cc  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006230cf  395904               cmp dword ptr [ecx + 4], ebx
// 006230d2  7505                 jne 0x6230d9
// 006230d4  894104               mov dword ptr [ecx + 4], eax
// 006230d7  eb0e                 jmp 0x6230e7
// 006230d9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006230dc  3919                 cmp dword ptr [ecx], ebx
// 006230de  7504                 jne 0x6230e4
// 006230e0  8901                 mov dword ptr [ecx], eax
// 006230e2  eb03                 jmp 0x6230e7
// 006230e4  894108               mov dword ptr [ecx + 8], eax
// 006230e7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006230ea  894804               mov dword ptr [eax + 4], ecx
// 006230ed  8d4b34               lea ecx, [ebx + 0x34]
// 006230f0  83c034               add eax, 0x34
// 006230f3  3bc1                 cmp eax, ecx
// 006230f5  7408                 je 0x6230ff
// 006230f7  8a19                 mov bl, byte ptr [ecx]
// 006230f9  8a10                 mov dl, byte ptr [eax]
// 006230fb  8818                 mov byte ptr [eax], bl
// 006230fd  8811                 mov byte ptr [ecx], dl
// 006230ff  8b542410             mov edx, dword ptr [esp + 0x10]
// 00623103  b301                 mov bl, 1
// 00623105  385a34               cmp byte ptr [edx + 0x34], bl
// 00623108  0f85fd000000         jne 0x62320b
// 0062310e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00623111  3b7804               cmp edi, dword ptr [eax + 4]
// 00623114  0f84ee000000         je 0x623208
// 0062311a  8d9b00000000         lea ebx, [ebx]
// 00623120  385f34               cmp byte ptr [edi + 0x34], bl
// 00623123  0f85df000000         jne 0x623208
// 00623129  8b06                 mov eax, dword ptr [esi]
// 0062312b  3bf8                 cmp edi, eax
// 0062312d  7565                 jne 0x623194
// 0062312f  8b4608               mov eax, dword ptr [esi + 8]
// 00623132  80783400             cmp byte ptr [eax + 0x34], 0
// 00623136  7512                 jne 0x62314a
// 00623138  885834               mov byte ptr [eax + 0x34], bl
// 0062313b  56                   push esi
// 0062313c  8bcd                 mov ecx, ebp
// 0062313e  c6463400             mov byte ptr [esi + 0x34], 0
// 00623142  e869cb0100           call 0x63fcb0
// 00623147  8b4608               mov eax, dword ptr [esi + 8]
// 0062314a  80783500             cmp byte ptr [eax + 0x35], 0
// 0062314e  7574                 jne 0x6231c4
// 00623150  8b08                 mov ecx, dword ptr [eax]
// 00623152  385934               cmp byte ptr [ecx + 0x34], bl
// 00623155  7508                 jne 0x62315f
// 00623157  8b5008               mov edx, dword ptr [eax + 8]
// 0062315a  385a34               cmp byte ptr [edx + 0x34], bl
// 0062315d  7461                 je 0x6231c0
// 0062315f  8b4808               mov ecx, dword ptr [eax + 8]
// 00623162  385934               cmp byte ptr [ecx + 0x34], bl
// 00623165  7514                 jne 0x62317b
// 00623167  8b10                 mov edx, dword ptr [eax]
// 00623169  885a34               mov byte ptr [edx + 0x34], bl
// 0062316c  50                   push eax
// 0062316d  8bcd                 mov ecx, ebp
// 0062316f  c6403400             mov byte ptr [eax + 0x34], 0
// 00623173  e888cb0100           call 0x63fd00
// 00623178  8b4608               mov eax, dword ptr [esi + 8]
// 0062317b  8a4e34               mov cl, byte ptr [esi + 0x34]
// 0062317e  884834               mov byte ptr [eax + 0x34], cl
// 00623181  885e34               mov byte ptr [esi + 0x34], bl
// 00623184  8b5008               mov edx, dword ptr [eax + 8]
// 00623187  56                   push esi
// 00623188  8bcd                 mov ecx, ebp
// 0062318a  885a34               mov byte ptr [edx + 0x34], bl
// 0062318d  e81ecb0100           call 0x63fcb0
// 00623192  eb74                 jmp 0x623208
// 00623194  80783400             cmp byte ptr [eax + 0x34], 0
// 00623198  7511                 jne 0x6231ab
// 0062319a  885834               mov byte ptr [eax + 0x34], bl
// 0062319d  56                   push esi
// 0062319e  8bcd                 mov ecx, ebp
// 006231a0  c6463400             mov byte ptr [esi + 0x34], 0
// 006231a4  e857cb0100           call 0x63fd00
// 006231a9  8b06                 mov eax, dword ptr [esi]
// 006231ab  80783500             cmp byte ptr [eax + 0x35], 0
// 006231af  7513                 jne 0x6231c4
// 006231b1  8b4808               mov ecx, dword ptr [eax + 8]
// 006231b4  385934               cmp byte ptr [ecx + 0x34], bl
// 006231b7  751e                 jne 0x6231d7
// 006231b9  8b10                 mov edx, dword ptr [eax]
// 006231bb  385a34               cmp byte ptr [edx + 0x34], bl
// 006231be  7517                 jne 0x6231d7
// 006231c0  c6403400             mov byte ptr [eax + 0x34], 0
// 006231c4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006231c7  8bfe                 mov edi, esi
// 006231c9  8b7604               mov esi, dword ptr [esi + 4]
// 006231cc  3b7804               cmp edi, dword ptr [eax + 4]
// 006231cf  0f854bffffff         jne 0x623120
// 006231d5  eb31                 jmp 0x623208
// 006231d7  8b08                 mov ecx, dword ptr [eax]
// 006231d9  385934               cmp byte ptr [ecx + 0x34], bl
// 006231dc  7514                 jne 0x6231f2
// 006231de  8b5008               mov edx, dword ptr [eax + 8]
// 006231e1  885a34               mov byte ptr [edx + 0x34], bl
// 006231e4  50                   push eax
// 006231e5  8bcd                 mov ecx, ebp
// 006231e7  c6403400             mov byte ptr [eax + 0x34], 0
// 006231eb  e8c0ca0100           call 0x63fcb0
// 006231f0  8b06                 mov eax, dword ptr [esi]
// 006231f2  8a4e34               mov cl, byte ptr [esi + 0x34]
// 006231f5  884834               mov byte ptr [eax + 0x34], cl
// 006231f8  885e34               mov byte ptr [esi + 0x34], bl
// 006231fb  8b10                 mov edx, dword ptr [eax]
// 006231fd  56                   push esi
// 006231fe  8bcd                 mov ecx, ebp
// 00623200  885a34               mov byte ptr [edx + 0x34], bl
// 00623203  e8f8ca0100           call 0x63fd00
// 00623208  885f34               mov byte ptr [edi + 0x34], bl
// 0062320b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062320f  83c10c               add ecx, 0xc
// 00623212  e879e9ffff           call 0x621b90
// 00623217  8b442410             mov eax, dword ptr [esp + 0x10]
// 0062321b  50                   push eax
// 0062321c  e879471800           call 0x7a799a
// 00623221  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00623224  83c404               add esp, 4
// 00623227  5f                   pop edi
// 00623228  5e                   pop esi
// 00623229  5b                   pop ebx
// 0062322a  85c0                 test eax, eax
// 0062322c  7604                 jbe 0x623232
// 0062322e  48                   dec eax
// 0062322f  89451c               mov dword ptr [ebp + 0x1c], eax
// 00623232  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00623236  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0062323a  8b5500               mov edx, dword ptr [ebp]
// 0062323d  894804               mov dword ptr [eax + 4], ecx
// 00623240  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00623244  8910                 mov dword ptr [eax], edx
// 00623246  5d                   pop ebp
// 00623247  64890d00000000       mov dword ptr fs:[0], ecx
// 0062324e  83c454               add esp, 0x54
// 00623251  c20c00               ret 0xc
// copied from an identical function in another client (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VTexturePtr@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VTexturePtr@Ogre@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreCompositionTechnique.cpp