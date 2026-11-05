// from server: 100% by auto
// roc 2009-06 00594210  unit: seg_00590000  size: 1096 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00594210
//
// 00594210  83ec40               sub esp, 0x40
// 00594213  8b442444             mov eax, dword ptr [esp + 0x44]
// 00594217  8b88ec000000         mov ecx, dword ptr [eax + 0xec]
// 0059421d  83c101               add ecx, 1
// 00594220  0fb69024010000       movzx edx, byte ptr [eax + 0x124]
// 00594227  53                   push ebx
// 00594228  8b5870               mov ebx, dword ptr [eax + 0x70]
// 0059422b  56                   push esi
// 0059422c  8db000010000         lea esi, [eax + 0x100]
// 00594232  b808000000           mov eax, 8
// 00594237  57                   push edi
// 00594238  89442430             mov dword ptr [esp + 0x30], eax
// 0059423c  89442434             mov dword ptr [esp + 0x34], eax
// 00594240  b804000000           mov eax, 4
// 00594245  bf02000000           mov edi, 2
// 0059424a  89742410             mov dword ptr [esp + 0x10], esi
// 0059424e  89442438             mov dword ptr [esp + 0x38], eax
// 00594252  8944243c             mov dword ptr [esp + 0x3c], eax
// 00594256  897c2440             mov dword ptr [esp + 0x40], edi
// 0059425a  897c2444             mov dword ptr [esp + 0x44], edi
// 0059425e  c744244801000000     mov dword ptr [esp + 0x48], 1
// 00594266  0f84e5030000         je 0x594651
// 0059426c  85f6                 test esi, esi
// 0059426e  0f84dd030000         je 0x594651
// 00594274  8b549430             mov edx, dword ptr [esp + edx*4 + 0x30]
// 00594278  8b06                 mov eax, dword ptr [esi]
// 0059427a  0fb6760b             movzx esi, byte ptr [esi + 0xb]
// 0059427e  55                   push ebp
// 0059427f  8be8                 mov ebp, eax
// 00594281  0fafea               imul ebp, edx
// 00594284  89542418             mov dword ptr [esp + 0x18], edx
// 00594288  8bd6                 mov edx, esi
// 0059428a  83ea01               sub edx, 1
// 0059428d  896c2410             mov dword ptr [esp + 0x10], ebp
// 00594291  0f84a3020000         je 0x59453a
// 00594297  83ea01               sub edx, 1
// 0059429a  0f849e010000         je 0x59443e
// 005942a0  2bd7                 sub edx, edi
// 005942a2  8d7dff               lea edi, [ebp - 1]
// 005942a5  746b                 je 0x594312
// 005942a7  c1ee03               shr esi, 3
// 005942aa  8d58ff               lea ebx, [eax - 1]
// 005942ad  0faffe               imul edi, esi
// 005942b0  0fafde               imul ebx, esi
// 005942b3  03d9                 add ebx, ecx
// 005942b5  03f9                 add edi, ecx
// 005942b7  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005942bf  85c0                 test eax, eax
// 005942c1  0f8652010000         jbe 0x594419
// 005942c7  56                   push esi
// 005942c8  8d442430             lea eax, [esp + 0x30]
// 005942cc  53                   push ebx
// 005942cd  50                   push eax
// 005942ce  e8e35b1800           call 0x719eb6
// 005942d3  8b442424             mov eax, dword ptr [esp + 0x24]
// 005942d7  83c40c               add esp, 0xc
// 005942da  85c0                 test eax, eax
// 005942dc  7e1c                 jle 0x5942fa
// 005942de  8be8                 mov ebp, eax
// 005942e0  56                   push esi
// 005942e1  8d4c2430             lea ecx, [esp + 0x30]
// 005942e5  51                   push ecx
// 005942e6  57                   push edi
// 005942e7  e8ca5b1800           call 0x719eb6
// 005942ec  83c40c               add esp, 0xc
// 005942ef  2bfe                 sub edi, esi
// 005942f1  83ed01               sub ebp, 1
// 005942f4  75ea                 jne 0x5942e0
// 005942f6  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 005942fa  8b442454             mov eax, dword ptr [esp + 0x54]
// 005942fe  8b542414             mov edx, dword ptr [esp + 0x14]
// 00594302  40                   inc eax
// 00594303  2bde                 sub ebx, esi
// 00594305  89442454             mov dword ptr [esp + 0x54], eax
// 00594309  3b02                 cmp eax, dword ptr [edx]
// 0059430b  72ba                 jb 0x5942c7
// 0059430d  e907010000           jmp 0x594419
// 00594312  8d50ff               lea edx, [eax - 1]
// 00594315  d1ea                 shr edx, 1
// 00594317  d1ef                 shr edi, 1
// 00594319  03d1                 add edx, ecx
// 0059431b  03f9                 add edi, ecx
// 0059431d  89542420             mov dword ptr [esp + 0x20], edx
// 00594321  f7c300000100         test ebx, 0x10000
// 00594327  7432                 je 0x59435b
// 00594329  83caff               or edx, 0xffffffff
// 0059432c  8d0c8500000000       lea ecx, [eax*4]
// 00594333  2bd1                 sub edx, ecx
// 00594335  83ceff               or esi, 0xffffffff
// 00594338  8d0cad00000000       lea ecx, [ebp*4]
// 0059433f  2bf1                 sub esi, ecx
// 00594341  83e204               and edx, 4
// 00594344  83e604               and esi, 4
// 00594347  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 0059434f  33ed                 xor ebp, ebp
// 00594351  c7442424fcffffff     mov dword ptr [esp + 0x24], 0xfffffffc
// 00594359  eb33                 jmp 0x59438e
// 0059435b  8d50ff               lea edx, [eax - 1]
// 0059435e  83e201               and edx, 1
// 00594361  4d                   dec ebp
// 00594362  03d2                 add edx, edx
// 00594364  03d2                 add edx, edx
// 00594366  83e501               and ebp, 1
// 00594369  03ed                 add ebp, ebp
// 0059436b  8bca                 mov ecx, edx
// 0059436d  ba04000000           mov edx, 4
// 00594372  03ed                 add ebp, ebp
// 00594374  be04000000           mov esi, 4
// 00594379  2bd1                 sub edx, ecx
// 0059437b  2bf5                 sub esi, ebp
// 0059437d  bd04000000           mov ebp, 4
// 00594382  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0059438a  896c2424             mov dword ptr [esp + 0x24], ebp
// 0059438e  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00594396  85c0                 test eax, eax
// 00594398  767b                 jbe 0x594415
// 0059439a  8d9b00000000         lea ebx, [ebx]
// 005943a0  8b442420             mov eax, dword ptr [esp + 0x20]
// 005943a4  8a00                 mov al, byte ptr [eax]
// 005943a6  8aca                 mov cl, dl
// 005943a8  d2e8                 shr al, cl
// 005943aa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005943ae  240f                 and al, 0xf
// 005943b0  88442454             mov byte ptr [esp + 0x54], al
// 005943b4  85c9                 test ecx, ecx
// 005943b6  7e3a                 jle 0x5943f2
// 005943b8  894c2428             mov dword ptr [esp + 0x28], ecx
// 005943bc  eb06                 jmp 0x5943c4
// 005943be  8bff                 mov edi, edi
// 005943c0  8a442454             mov al, byte ptr [esp + 0x54]
// 005943c4  b904000000           mov ecx, 4
// 005943c9  2bce                 sub ecx, esi
// 005943cb  bb0f0f0000           mov ebx, 0xf0f
// 005943d0  d3fb                 sar ebx, cl
// 005943d2  8bce                 mov ecx, esi
// 005943d4  d2e0                 shl al, cl
// 005943d6  221f                 and bl, byte ptr [edi]
// 005943d8  0ad8                 or bl, al
// 005943da  881f                 mov byte ptr [edi], bl
// 005943dc  3bf5                 cmp esi, ebp
// 005943de  7507                 jne 0x5943e7
// 005943e0  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005943e4  4f                   dec edi
// 005943e5  eb04                 jmp 0x5943eb
// 005943e7  03742424             add esi, dword ptr [esp + 0x24]
// 005943eb  836c242801           sub dword ptr [esp + 0x28], 1
// 005943f0  75ce                 jne 0x5943c0
// 005943f2  3bd5                 cmp edx, ebp
// 005943f4  750a                 jne 0x594400
// 005943f6  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005943fa  ff4c2420             dec dword ptr [esp + 0x20]
// 005943fe  eb04                 jmp 0x594404
// 00594400  03542424             add edx, dword ptr [esp + 0x24]
// 00594404  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00594408  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0059440c  40                   inc eax
// 0059440d  8944242c             mov dword ptr [esp + 0x2c], eax
// 00594411  3b01                 cmp eax, dword ptr [ecx]
// 00594413  728b                 jb 0x5943a0
// 00594415  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00594419  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0059441d  8a410b               mov al, byte ptr [ecx + 0xb]
// 00594420  3c08                 cmp al, 8
// 00594422  8929                 mov dword ptr [ecx], ebp
// 00594424  0fb6c0               movzx eax, al
// 00594427  0f8217020000         jb 0x594644
// 0059442d  c1e803               shr eax, 3
// 00594430  0fafc5               imul eax, ebp
// 00594433  5d                   pop ebp
// 00594434  5f                   pop edi
// 00594435  5e                   pop esi
// 00594436  894104               mov dword ptr [ecx + 4], eax
// 00594439  5b                   pop ebx
// 0059443a  83c440               add esp, 0x40
// 0059443d  c3                   ret 
// 0059443e  8d50ff               lea edx, [eax - 1]
// 00594441  8d7dff               lea edi, [ebp - 1]
// 00594444  c1ea02               shr edx, 2
// 00594447  c1ef02               shr edi, 2
// 0059444a  03d1                 add edx, ecx
// 0059444c  03f9                 add edi, ecx
// 0059444e  89542420             mov dword ptr [esp + 0x20], edx
// 00594452  f7c300000100         test ebx, 0x10000
// 00594458  7422                 je 0x59447c
// 0059445a  8d742dff             lea esi, [ebp + ebp - 1]
// 0059445e  8d5400ff             lea edx, [eax + eax - 1]
// 00594462  83e206               and edx, 6
// 00594465  83e606               and esi, 6
// 00594468  c744242406000000     mov dword ptr [esp + 0x24], 6
// 00594470  33ed                 xor ebp, ebp
// 00594472  c744241cfeffffff     mov dword ptr [esp + 0x1c], 0xfffffffe
// 0059447a  eb31                 jmp 0x5944ad
// 0059447c  4d                   dec ebp
// 0059447d  8d48ff               lea ecx, [eax - 1]
// 00594480  83e103               and ecx, 3
// 00594483  83e503               and ebp, 3
// 00594486  ba03000000           mov edx, 3
// 0059448b  2bd1                 sub edx, ecx
// 0059448d  be03000000           mov esi, 3
// 00594492  2bf5                 sub esi, ebp
// 00594494  03d2                 add edx, edx
// 00594496  03f6                 add esi, esi
// 00594498  c744242400000000     mov dword ptr [esp + 0x24], 0
// 005944a0  bd06000000           mov ebp, 6
// 005944a5  c744241c02000000     mov dword ptr [esp + 0x1c], 2
// 005944ad  c744242800000000     mov dword ptr [esp + 0x28], 0
// 005944b5  85c0                 test eax, eax
// 005944b7  0f8658ffffff         jbe 0x594415
// 005944bd  8d4900               lea ecx, [ecx]
// 005944c0  8b442420             mov eax, dword ptr [esp + 0x20]
// 005944c4  8a00                 mov al, byte ptr [eax]
// 005944c6  8aca                 mov cl, dl
// 005944c8  d2e8                 shr al, cl
// 005944ca  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005944ce  2403                 and al, 3
// 005944d0  88442454             mov byte ptr [esp + 0x54], al
// 005944d4  85c9                 test ecx, ecx
// 005944d6  7e3a                 jle 0x594512
// 005944d8  894c242c             mov dword ptr [esp + 0x2c], ecx
// 005944dc  eb06                 jmp 0x5944e4
// 005944de  8bff                 mov edi, edi
// 005944e0  8a442454             mov al, byte ptr [esp + 0x54]
// 005944e4  b906000000           mov ecx, 6
// 005944e9  2bce                 sub ecx, esi
// 005944eb  bb3f3f0000           mov ebx, 0x3f3f
// 005944f0  d3fb                 sar ebx, cl
// 005944f2  8bce                 mov ecx, esi
// 005944f4  d2e0                 shl al, cl
// 005944f6  221f                 and bl, byte ptr [edi]
// 005944f8  0ad8                 or bl, al
// 005944fa  881f                 mov byte ptr [edi], bl
// 005944fc  3bf5                 cmp esi, ebp
// 005944fe  7507                 jne 0x594507
// 00594500  8b742424             mov esi, dword ptr [esp + 0x24]
// 00594504  4f                   dec edi
// 00594505  eb04                 jmp 0x59450b
// 00594507  0374241c             add esi, dword ptr [esp + 0x1c]
// 0059450b  836c242c01           sub dword ptr [esp + 0x2c], 1
// 00594510  75ce                 jne 0x5944e0
// 00594512  3bd5                 cmp edx, ebp
// 00594514  750a                 jne 0x594520
// 00594516  8b542424             mov edx, dword ptr [esp + 0x24]
// 0059451a  ff4c2420             dec dword ptr [esp + 0x20]
// 0059451e  eb04                 jmp 0x594524
// 00594520  0354241c             add edx, dword ptr [esp + 0x1c]
// 00594524  8b442428             mov eax, dword ptr [esp + 0x28]
// 00594528  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0059452c  40                   inc eax
// 0059452d  89442428             mov dword ptr [esp + 0x28], eax
// 00594531  3b01                 cmp eax, dword ptr [ecx]
// 00594533  728b                 jb 0x5944c0
// 00594535  e9dbfeffff           jmp 0x594415
// 0059453a  8d50ff               lea edx, [eax - 1]
// 0059453d  8d7dff               lea edi, [ebp - 1]
// 00594540  c1ea03               shr edx, 3
// 00594543  c1ef03               shr edi, 3
// 00594546  03d1                 add edx, ecx
// 00594548  03f9                 add edi, ecx
// 0059454a  8954241c             mov dword ptr [esp + 0x1c], edx
// 0059454e  f7c300000100         test ebx, 0x10000
// 00594554  7426                 je 0x59457c
// 00594556  8d50ff               lea edx, [eax - 1]
// 00594559  8d75ff               lea esi, [ebp - 1]
// 0059455c  83e207               and edx, 7
// 0059455f  83e607               and esi, 7
// 00594562  c744242007000000     mov dword ptr [esp + 0x20], 7
// 0059456a  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00594572  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0059457a  eb32                 jmp 0x5945ae
// 0059457c  8d48ff               lea ecx, [eax - 1]
// 0059457f  83e107               and ecx, 7
// 00594582  ba07000000           mov edx, 7
// 00594587  2bd1                 sub edx, ecx
// 00594589  8d4dff               lea ecx, [ebp - 1]
// 0059458c  83e107               and ecx, 7
// 0059458f  be07000000           mov esi, 7
// 00594594  2bf1                 sub esi, ecx
// 00594596  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0059459e  c744242407000000     mov dword ptr [esp + 0x24], 7
// 005945a6  c744241001000000     mov dword ptr [esp + 0x10], 1
// 005945ae  89542454             mov dword ptr [esp + 0x54], edx
// 005945b2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 005945ba  85c0                 test eax, eax
// 005945bc  0f8657feffff         jbe 0x594419
// 005945c2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005945c6  8a00                 mov al, byte ptr [eax]
// 005945c8  8aca                 mov cl, dl
// 005945ca  d2e8                 shr al, cl
// 005945cc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005945d0  2401                 and al, 1
// 005945d2  85c9                 test ecx, ecx
// 005945d4  7e40                 jle 0x594616
// 005945d6  894c242c             mov dword ptr [esp + 0x2c], ecx
// 005945da  8d9b00000000         lea ebx, [ebx]
// 005945e0  b907000000           mov ecx, 7
// 005945e5  2bce                 sub ecx, esi
// 005945e7  ba7f7f0000           mov edx, 0x7f7f
// 005945ec  d3fa                 sar edx, cl
// 005945ee  8ad8                 mov bl, al
// 005945f0  8bce                 mov ecx, esi
// 005945f2  d2e3                 shl bl, cl
// 005945f4  2217                 and dl, byte ptr [edi]
// 005945f6  0ad3                 or dl, bl
// 005945f8  8817                 mov byte ptr [edi], dl
// 005945fa  3b742424             cmp esi, dword ptr [esp + 0x24]
// 005945fe  7507                 jne 0x594607
// 00594600  8b742420             mov esi, dword ptr [esp + 0x20]
// 00594604  4f                   dec edi
// 00594605  eb04                 jmp 0x59460b
// 00594607  03742410             add esi, dword ptr [esp + 0x10]
// 0059460b  836c242c01           sub dword ptr [esp + 0x2c], 1
// 00594610  75ce                 jne 0x5945e0
// 00594612  8b542454             mov edx, dword ptr [esp + 0x54]
// 00594616  3b542424             cmp edx, dword ptr [esp + 0x24]
// 0059461a  750a                 jne 0x594626
// 0059461c  8b542420             mov edx, dword ptr [esp + 0x20]
// 00594620  ff4c241c             dec dword ptr [esp + 0x1c]
// 00594624  eb04                 jmp 0x59462a
// 00594626  03542410             add edx, dword ptr [esp + 0x10]
// 0059462a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0059462e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00594632  40                   inc eax
// 00594633  89542454             mov dword ptr [esp + 0x54], edx
// 00594637  89442428             mov dword ptr [esp + 0x28], eax
// 0059463b  3b01                 cmp eax, dword ptr [ecx]
// 0059463d  7283                 jb 0x5945c2
// 0059463f  e9d5fdffff           jmp 0x594419
// 00594644  0fafc5               imul eax, ebp
// 00594647  83c007               add eax, 7
// 0059464a  c1e803               shr eax, 3
// 0059464d  894104               mov dword ptr [ecx + 4], eax
// 00594650  5d                   pop ebp
// 00594651  5f                   pop edi
// 00594652  5e                   pop esi
// 00594653  5b                   pop ebx
// 00594654  83c440               add esp, 0x40
// 00594657  c3                   ret 
// library libpng-1.2.22/pngrutil.c (function _png_do_read_interlace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrutil.c
