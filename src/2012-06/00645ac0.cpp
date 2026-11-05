// roc 2012-06 00645ac0  unit: seg_00640000  size: 588 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00645ac0
//
// 00645ac0  56                   push esi
// 00645ac1  8b742408             mov esi, dword ptr [esp + 8]
// 00645ac5  85f6                 test esi, esi
// 00645ac7  0f841f020000         je 0x645cec
// 00645acd  83bee400000000       cmp dword ptr [esi + 0xe4], 0
// 00645ad4  7529                 jne 0x645aff
// 00645ad6  80be2401000000       cmp byte ptr [esi + 0x124], 0
// 00645add  7520                 jne 0x645aff
// 00645adf  f7466800040000       test dword ptr [esi + 0x68], 0x400
// 00645ae6  750e                 jne 0x645af6
// 00645ae8  68b05eb800           push 0xb85eb0
// 00645aed  56                   push esi
// 00645aee  e8bd860000           call 0x64e1b0
// 00645af3  83c408               add esp, 8
// 00645af6  56                   push esi
// 00645af7  e8e4120100           call 0x656de0
// 00645afc  83c404               add esp, 4
// 00645aff  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 00645b06  0f84d4000000         je 0x645be0
// 00645b0c  f6467002             test byte ptr [esi + 0x70], 2
// 00645b10  0f84ca000000         je 0x645be0
// 00645b16  0fb68624010000       movzx eax, byte ptr [esi + 0x124]
// 00645b1d  83f806               cmp eax, 6
// 00645b20  0f87ba000000         ja 0x645be0
// 00645b26  ff2485f05c6400       jmp dword ptr [eax*4 + 0x645cf0]
// 00645b2d  f686e400000007       test byte ptr [esi + 0xe4], 7
// 00645b34  0f84a6000000         je 0x645be0
// 00645b3a  56                   push esi
// 00645b3b  e8602c0100           call 0x6587a0
// 00645b40  83c404               add esp, 4
// 00645b43  5e                   pop esi
// 00645b44  c3                   ret 
// 00645b45  f686e400000007       test byte ptr [esi + 0xe4], 7
// 00645b4c  750d                 jne 0x645b5b
// 00645b4e  83bec800000005       cmp dword ptr [esi + 0xc8], 5
// 00645b55  0f8385000000         jae 0x645be0
// 00645b5b  56                   push esi
// 00645b5c  e83f2c0100           call 0x6587a0
// 00645b61  83c404               add esp, 4
// 00645b64  5e                   pop esi
// 00645b65  c3                   ret 
// 00645b66  8b86e4000000         mov eax, dword ptr [esi + 0xe4]
// 00645b6c  2407                 and al, 7
// 00645b6e  3c04                 cmp al, 4
// 00645b70  746e                 je 0x645be0
// 00645b72  56                   push esi
// 00645b73  e8282c0100           call 0x6587a0
// 00645b78  83c404               add esp, 4
// 00645b7b  5e                   pop esi
// 00645b7c  c3                   ret 
// 00645b7d  b803000000           mov eax, 3
// 00645b82  8486e4000000         test byte ptr [esi + 0xe4], al
// 00645b88  7508                 jne 0x645b92
// 00645b8a  3986c8000000         cmp dword ptr [esi + 0xc8], eax
// 00645b90  734e                 jae 0x645be0
// 00645b92  56                   push esi
// 00645b93  e8082c0100           call 0x6587a0
// 00645b98  83c404               add esp, 4
// 00645b9b  5e                   pop esi
// 00645b9c  c3                   ret 
// 00645b9d  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 00645ba3  80e103               and cl, 3
// 00645ba6  80f902               cmp cl, 2
// 00645ba9  7435                 je 0x645be0
// 00645bab  56                   push esi
// 00645bac  e8ef2b0100           call 0x6587a0
// 00645bb1  83c404               add esp, 4
// 00645bb4  5e                   pop esi
// 00645bb5  c3                   ret 
// 00645bb6  f686e400000001       test byte ptr [esi + 0xe4], 1
// 00645bbd  7509                 jne 0x645bc8
// 00645bbf  83bec800000002       cmp dword ptr [esi + 0xc8], 2
// 00645bc6  7318                 jae 0x645be0
// 00645bc8  56                   push esi
// 00645bc9  e8d22b0100           call 0x6587a0
// 00645bce  83c404               add esp, 4
// 00645bd1  5e                   pop esi
// 00645bd2  c3                   ret 
// 00645bd3  f686e400000001       test byte ptr [esi + 0xe4], 1
// 00645bda  0f845affffff         je 0x645b3a
// 00645be0  0fb69626010000       movzx edx, byte ptr [esi + 0x126]
// 00645be7  8a8628010000         mov al, byte ptr [esi + 0x128]
// 00645bed  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 00645bf3  889608010000         mov byte ptr [esi + 0x108], dl
// 00645bf9  8a962b010000         mov dl, byte ptr [esi + 0x12b]
// 00645bff  888609010000         mov byte ptr [esi + 0x109], al
// 00645c05  f6ea                 imul dl
// 00645c07  57                   push edi
// 00645c08  8dbe00010000         lea edi, [esi + 0x100]
// 00645c0e  88860b010000         mov byte ptr [esi + 0x10b], al
// 00645c14  3c08                 cmp al, 8
// 00645c16  890f                 mov dword ptr [edi], ecx
// 00645c18  88960a010000         mov byte ptr [esi + 0x10a], dl
// 00645c1e  0fb6c0               movzx eax, al
// 00645c21  7208                 jb 0x645c2b
// 00645c23  c1e803               shr eax, 3
// 00645c26  0fafc1               imul eax, ecx
// 00645c29  eb09                 jmp 0x645c34
// 00645c2b  0fafc1               imul eax, ecx
// 00645c2e  83c007               add eax, 7
// 00645c31  c1e803               shr eax, 3
// 00645c34  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00645c3a  50                   push eax
// 00645c3b  898604010000         mov dword ptr [esi + 0x104], eax
// 00645c41  8b442414             mov eax, dword ptr [esp + 0x14]
// 00645c45  50                   push eax
// 00645c46  41                   inc ecx
// 00645c47  51                   push ecx
// 00645c48  56                   push esi
// 00645c49  e8e2870000           call 0x64e430
// 00645c4e  83c410               add esp, 0x10
// 00645c51  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 00645c58  7436                 je 0x645c90
// 00645c5a  8a8624010000         mov al, byte ptr [esi + 0x124]
// 00645c60  3c06                 cmp al, 6
// 00645c62  732c                 jae 0x645c90
// 00645c64  f6467002             test byte ptr [esi + 0x70], 2
// 00645c68  7426                 je 0x645c90
// 00645c6a  0fb6d0               movzx edx, al
// 00645c6d  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00645c73  52                   push edx
// 00645c74  40                   inc eax
// 00645c75  50                   push eax
// 00645c76  57                   push edi
// 00645c77  e8f4120100           call 0x656f70
// 00645c7c  83c40c               add esp, 0xc
// 00645c7f  833f00               cmp dword ptr [edi], 0
// 00645c82  750c                 jne 0x645c90
// 00645c84  56                   push esi
// 00645c85  e8162b0100           call 0x6587a0
// 00645c8a  83c404               add esp, 4
// 00645c8d  5f                   pop edi
// 00645c8e  5e                   pop esi
// 00645c8f  c3                   ret 
// 00645c90  837e7000             cmp dword ptr [esi + 0x70], 0
// 00645c94  7409                 je 0x645c9f
// 00645c96  56                   push esi
// 00645c97  e8e43f0100           call 0x659c80
// 00645c9c  83c404               add esp, 4
// 00645c9f  f6863002000004       test byte ptr [esi + 0x230], 4
// 00645ca6  741a                 je 0x645cc2
// 00645ca8  80be3802000040       cmp byte ptr [esi + 0x238], 0x40
// 00645caf  7511                 jne 0x645cc2
// 00645cb1  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00645cb7  41                   inc ecx
// 00645cb8  51                   push ecx
// 00645cb9  57                   push edi
// 00645cba  e8e13e0100           call 0x659ba0
// 00645cbf  83c408               add esp, 8
// 00645cc2  57                   push edi
// 00645cc3  56                   push esi
// 00645cc4  e8072e0100           call 0x658ad0
// 00645cc9  8b869c010000         mov eax, dword ptr [esi + 0x19c]
// 00645ccf  83c408               add esp, 8
// 00645cd2  85c0                 test eax, eax
// 00645cd4  7415                 je 0x645ceb
// 00645cd6  0fb69624010000       movzx edx, byte ptr [esi + 0x124]
// 00645cdd  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 00645ce3  52                   push edx
// 00645ce4  51                   push ecx
// 00645ce5  56                   push esi
// 00645ce6  ffd0                 call eax
// 00645ce8  83c40c               add esp, 0xc
// 00645ceb  5f                   pop edi
// 00645cec  5e                   pop esi
// 00645ced  c3                   ret 
// 00645cee  8bff                 mov edi, edi
// 00645cf0  2d5b640045           sub eax, 0x4500645b
// 00645cf5  5b                   pop ebx
// 00645cf6  6400665b             add byte ptr fs:[esi + 0x5b], ah
// 00645cfa  64007d5b             add byte ptr fs:[ebp + 0x5b], bh
// 00645cfe  64009d5b6400b6       add byte ptr fs:[ebp - 0x49ff9ba5], bl
// 00645d05  5b                   pop ebx
// 00645d06  6400d3               add bl, dl
// 00645d09  5b                   pop ebx
// library libpng-1.2.10/pngwrite.c (function _png_write_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
