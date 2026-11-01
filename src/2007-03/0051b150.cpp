// from server: 100% by auto
// roc 2007-03 0051b150  unit: seg_00510000  size: 1067 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0051b150
//
// 0051b150  83ec30               sub esp, 0x30
// 0051b153  a1b4f58a00           mov eax, dword ptr [0x8af5b4]
// 0051b158  33c4                 xor eax, esp
// 0051b15a  8944242c             mov dword ptr [esp + 0x2c], eax
// 0051b15e  8b442434             mov eax, dword ptr [esp + 0x34]
// 0051b162  8b88ec000000         mov ecx, dword ptr [eax + 0xec]
// 0051b168  83c101               add ecx, 1
// 0051b16b  0fb69024010000       movzx edx, byte ptr [eax + 0x124]
// 0051b172  53                   push ebx
// 0051b173  8b5870               mov ebx, dword ptr [eax + 0x70]
// 0051b176  56                   push esi
// 0051b177  8db000010000         lea esi, [eax + 0x100]
// 0051b17d  89742424             mov dword ptr [esp + 0x24], esi
// 0051b181  0f84e3030000         je 0x51b56a
// 0051b187  85f6                 test esi, esi
// 0051b189  0f84db030000         je 0x51b56a
// 0051b18f  8b1495600f7a00       mov edx, dword ptr [edx*4 + 0x7a0f60]
// 0051b196  8b06                 mov eax, dword ptr [esi]
// 0051b198  0fb6760b             movzx esi, byte ptr [esi + 0xb]
// 0051b19c  55                   push ebp
// 0051b19d  8be8                 mov ebp, eax
// 0051b19f  0fafea               imul ebp, edx
// 0051b1a2  8954242c             mov dword ptr [esp + 0x2c], edx
// 0051b1a6  8bd6                 mov edx, esi
// 0051b1a8  83ea01               sub edx, 1
// 0051b1ab  57                   push edi
// 0051b1ac  896c2424             mov dword ptr [esp + 0x24], ebp
// 0051b1b0  8d7dff               lea edi, [ebp - 1]
// 0051b1b3  0f848e020000         je 0x51b447
// 0051b1b9  83ea01               sub edx, 1
// 0051b1bc  0f847d010000         je 0x51b33f
// 0051b1c2  83ea02               sub edx, 2
// 0051b1c5  746d                 je 0x51b234
// 0051b1c7  c1ee03               shr esi, 3
// 0051b1ca  8d58ff               lea ebx, [eax - 1]
// 0051b1cd  0faffe               imul edi, esi
// 0051b1d0  0fafde               imul ebx, esi
// 0051b1d3  03d9                 add ebx, ecx
// 0051b1d5  03f9                 add edi, ecx
// 0051b1d7  85c0                 test eax, eax
// 0051b1d9  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0051b1e1  0f865d030000         jbe 0x51b544
// 0051b1e7  56                   push esi
// 0051b1e8  8d442438             lea eax, [esp + 0x38]
// 0051b1ec  53                   push ebx
// 0051b1ed  50                   push eax
// 0051b1ee  e8ef3f1000           call 0x61f1e2
// 0051b1f3  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0051b1f7  83c40c               add esp, 0xc
// 0051b1fa  85c0                 test eax, eax
// 0051b1fc  7e1c                 jle 0x51b21a
// 0051b1fe  8be8                 mov ebp, eax
// 0051b200  56                   push esi
// 0051b201  8d4c2438             lea ecx, [esp + 0x38]
// 0051b205  51                   push ecx
// 0051b206  57                   push edi
// 0051b207  e8d63f1000           call 0x61f1e2
// 0051b20c  83c40c               add esp, 0xc
// 0051b20f  2bfe                 sub edi, esi
// 0051b211  83ed01               sub ebp, 1
// 0051b214  75ea                 jne 0x51b200
// 0051b216  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0051b21a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0051b21e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0051b222  83c001               add eax, 1
// 0051b225  2bde                 sub ebx, esi
// 0051b227  3b02                 cmp eax, dword ptr [edx]
// 0051b229  89442418             mov dword ptr [esp + 0x18], eax
// 0051b22d  72b8                 jb 0x51b1e7
// 0051b22f  e910030000           jmp 0x51b544
// 0051b234  8d50ff               lea edx, [eax - 1]
// 0051b237  d1ea                 shr edx, 1
// 0051b239  d1ef                 shr edi, 1
// 0051b23b  03d1                 add edx, ecx
// 0051b23d  03f9                 add edi, ecx
// 0051b23f  f7c300000100         test ebx, 0x10000
// 0051b245  8954241c             mov dword ptr [esp + 0x1c], edx
// 0051b249  7432                 je 0x51b27d
// 0051b24b  83caff               or edx, 0xffffffff
// 0051b24e  8d0c8500000000       lea ecx, [eax*4]
// 0051b255  2bd1                 sub edx, ecx
// 0051b257  83ceff               or esi, 0xffffffff
// 0051b25a  8d0cad00000000       lea ecx, [ebp*4]
// 0051b261  2bf1                 sub esi, ecx
// 0051b263  83e204               and edx, 4
// 0051b266  83e604               and esi, 4
// 0051b269  c744241404000000     mov dword ptr [esp + 0x14], 4
// 0051b271  33ed                 xor ebp, ebp
// 0051b273  c7442420fcffffff     mov dword ptr [esp + 0x20], 0xfffffffc
// 0051b27b  eb35                 jmp 0x51b2b2
// 0051b27d  8d50ff               lea edx, [eax - 1]
// 0051b280  83e201               and edx, 1
// 0051b283  83c5ff               add ebp, -1
// 0051b286  03d2                 add edx, edx
// 0051b288  03d2                 add edx, edx
// 0051b28a  83e501               and ebp, 1
// 0051b28d  03ed                 add ebp, ebp
// 0051b28f  8bca                 mov ecx, edx
// 0051b291  ba04000000           mov edx, 4
// 0051b296  03ed                 add ebp, ebp
// 0051b298  be04000000           mov esi, 4
// 0051b29d  2bd1                 sub edx, ecx
// 0051b29f  2bf5                 sub esi, ebp
// 0051b2a1  bd04000000           mov ebp, 4
// 0051b2a6  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0051b2ae  896c2420             mov dword ptr [esp + 0x20], ebp
// 0051b2b2  85c0                 test eax, eax
// 0051b2b4  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0051b2bc  0f867e020000         jbe 0x51b540
// 0051b2c2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051b2c6  8a00                 mov al, byte ptr [eax]
// 0051b2c8  8aca                 mov cl, dl
// 0051b2ca  d2e8                 shr al, cl
// 0051b2cc  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0051b2d0  240f                 and al, 0xf
// 0051b2d2  85c9                 test ecx, ecx
// 0051b2d4  88442413             mov byte ptr [esp + 0x13], al
// 0051b2d8  7e3a                 jle 0x51b314
// 0051b2da  894c2418             mov dword ptr [esp + 0x18], ecx
// 0051b2de  eb04                 jmp 0x51b2e4
// 0051b2e0  8a442413             mov al, byte ptr [esp + 0x13]
// 0051b2e4  b904000000           mov ecx, 4
// 0051b2e9  2bce                 sub ecx, esi
// 0051b2eb  bb0f0f0000           mov ebx, 0xf0f
// 0051b2f0  d3fb                 sar ebx, cl
// 0051b2f2  8bce                 mov ecx, esi
// 0051b2f4  d2e0                 shl al, cl
// 0051b2f6  221f                 and bl, byte ptr [edi]
// 0051b2f8  0ad8                 or bl, al
// 0051b2fa  3bf5                 cmp esi, ebp
// 0051b2fc  881f                 mov byte ptr [edi], bl
// 0051b2fe  7509                 jne 0x51b309
// 0051b300  8b742414             mov esi, dword ptr [esp + 0x14]
// 0051b304  83ef01               sub edi, 1
// 0051b307  eb04                 jmp 0x51b30d
// 0051b309  03742420             add esi, dword ptr [esp + 0x20]
// 0051b30d  836c241801           sub dword ptr [esp + 0x18], 1
// 0051b312  75cc                 jne 0x51b2e0
// 0051b314  3bd5                 cmp edx, ebp
// 0051b316  750b                 jne 0x51b323
// 0051b318  8b542414             mov edx, dword ptr [esp + 0x14]
// 0051b31c  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0051b321  eb04                 jmp 0x51b327
// 0051b323  03542420             add edx, dword ptr [esp + 0x20]
// 0051b327  8b442428             mov eax, dword ptr [esp + 0x28]
// 0051b32b  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0051b32f  83c001               add eax, 1
// 0051b332  3b01                 cmp eax, dword ptr [ecx]
// 0051b334  89442428             mov dword ptr [esp + 0x28], eax
// 0051b338  7288                 jb 0x51b2c2
// 0051b33a  e901020000           jmp 0x51b540
// 0051b33f  8d50ff               lea edx, [eax - 1]
// 0051b342  c1ea02               shr edx, 2
// 0051b345  c1ef02               shr edi, 2
// 0051b348  03d1                 add edx, ecx
// 0051b34a  03f9                 add edi, ecx
// 0051b34c  f7c300000100         test ebx, 0x10000
// 0051b352  89542414             mov dword ptr [esp + 0x14], edx
// 0051b356  7428                 je 0x51b380
// 0051b358  8d5400ff             lea edx, [eax + eax - 1]
// 0051b35c  8d742dff             lea esi, [ebp + ebp - 1]
// 0051b360  83e206               and edx, 6
// 0051b363  83e606               and esi, 6
// 0051b366  c744241c06000000     mov dword ptr [esp + 0x1c], 6
// 0051b36e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0051b376  c7442424feffffff     mov dword ptr [esp + 0x24], 0xfffffffe
// 0051b37e  eb36                 jmp 0x51b3b6
// 0051b380  8d48ff               lea ecx, [eax - 1]
// 0051b383  83e103               and ecx, 3
// 0051b386  ba03000000           mov edx, 3
// 0051b38b  2bd1                 sub edx, ecx
// 0051b38d  8d4dff               lea ecx, [ebp - 1]
// 0051b390  83e103               and ecx, 3
// 0051b393  be03000000           mov esi, 3
// 0051b398  2bf1                 sub esi, ecx
// 0051b39a  03d2                 add edx, edx
// 0051b39c  03f6                 add esi, esi
// 0051b39e  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0051b3a6  c744242006000000     mov dword ptr [esp + 0x20], 6
// 0051b3ae  c744242402000000     mov dword ptr [esp + 0x24], 2
// 0051b3b6  85c0                 test eax, eax
// 0051b3b8  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0051b3c0  0f867e010000         jbe 0x51b544
// 0051b3c6  8b442414             mov eax, dword ptr [esp + 0x14]
// 0051b3ca  8a00                 mov al, byte ptr [eax]
// 0051b3cc  8aca                 mov cl, dl
// 0051b3ce  d2e8                 shr al, cl
// 0051b3d0  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0051b3d4  2403                 and al, 3
// 0051b3d6  85c9                 test ecx, ecx
// 0051b3d8  88442413             mov byte ptr [esp + 0x13], al
// 0051b3dc  7e3c                 jle 0x51b41a
// 0051b3de  894c2428             mov dword ptr [esp + 0x28], ecx
// 0051b3e2  eb04                 jmp 0x51b3e8
// 0051b3e4  8a442413             mov al, byte ptr [esp + 0x13]
// 0051b3e8  b906000000           mov ecx, 6
// 0051b3ed  2bce                 sub ecx, esi
// 0051b3ef  bb3f3f0000           mov ebx, 0x3f3f
// 0051b3f4  d3fb                 sar ebx, cl
// 0051b3f6  8bce                 mov ecx, esi
// 0051b3f8  d2e0                 shl al, cl
// 0051b3fa  221f                 and bl, byte ptr [edi]
// 0051b3fc  0ad8                 or bl, al
// 0051b3fe  3b742420             cmp esi, dword ptr [esp + 0x20]
// 0051b402  881f                 mov byte ptr [edi], bl
// 0051b404  7509                 jne 0x51b40f
// 0051b406  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0051b40a  83ef01               sub edi, 1
// 0051b40d  eb04                 jmp 0x51b413
// 0051b40f  03742424             add esi, dword ptr [esp + 0x24]
// 0051b413  836c242801           sub dword ptr [esp + 0x28], 1
// 0051b418  75ca                 jne 0x51b3e4
// 0051b41a  3b542420             cmp edx, dword ptr [esp + 0x20]
// 0051b41e  750b                 jne 0x51b42b
// 0051b420  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0051b424  836c241401           sub dword ptr [esp + 0x14], 1
// 0051b429  eb04                 jmp 0x51b42f
// 0051b42b  03542424             add edx, dword ptr [esp + 0x24]
// 0051b42f  8b442418             mov eax, dword ptr [esp + 0x18]
// 0051b433  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0051b437  83c001               add eax, 1
// 0051b43a  3b01                 cmp eax, dword ptr [ecx]
// 0051b43c  89442418             mov dword ptr [esp + 0x18], eax
// 0051b440  7284                 jb 0x51b3c6
// 0051b442  e9fd000000           jmp 0x51b544
// 0051b447  8d50ff               lea edx, [eax - 1]
// 0051b44a  c1ea03               shr edx, 3
// 0051b44d  c1ef03               shr edi, 3
// 0051b450  03d1                 add edx, ecx
// 0051b452  03f9                 add edi, ecx
// 0051b454  f7c300000100         test ebx, 0x10000
// 0051b45a  8954241c             mov dword ptr [esp + 0x1c], edx
// 0051b45e  7420                 je 0x51b480
// 0051b460  8d75ff               lea esi, [ebp - 1]
// 0051b463  8d50ff               lea edx, [eax - 1]
// 0051b466  83e207               and edx, 7
// 0051b469  83e607               and esi, 7
// 0051b46c  c744242007000000     mov dword ptr [esp + 0x20], 7
// 0051b474  33ed                 xor ebp, ebp
// 0051b476  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0051b47e  eb2f                 jmp 0x51b4af
// 0051b480  83c5ff               add ebp, -1
// 0051b483  8d48ff               lea ecx, [eax - 1]
// 0051b486  83e107               and ecx, 7
// 0051b489  ba07000000           mov edx, 7
// 0051b48e  83e507               and ebp, 7
// 0051b491  be07000000           mov esi, 7
// 0051b496  2bd1                 sub edx, ecx
// 0051b498  2bf5                 sub esi, ebp
// 0051b49a  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0051b4a2  bd07000000           mov ebp, 7
// 0051b4a7  c744241801000000     mov dword ptr [esp + 0x18], 1
// 0051b4af  85c0                 test eax, eax
// 0051b4b1  89542414             mov dword ptr [esp + 0x14], edx
// 0051b4b5  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0051b4bd  0f867d000000         jbe 0x51b540
// 0051b4c3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051b4c7  8a00                 mov al, byte ptr [eax]
// 0051b4c9  8aca                 mov cl, dl
// 0051b4cb  d2e8                 shr al, cl
// 0051b4cd  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0051b4d1  2401                 and al, 1
// 0051b4d3  85c9                 test ecx, ecx
// 0051b4d5  7e3f                 jle 0x51b516
// 0051b4d7  894c2428             mov dword ptr [esp + 0x28], ecx
// 0051b4db  eb03                 jmp 0x51b4e0
// 0051b4dd  8d4900               lea ecx, [ecx]
// 0051b4e0  b907000000           mov ecx, 7
// 0051b4e5  2bce                 sub ecx, esi
// 0051b4e7  ba7f7f0000           mov edx, 0x7f7f
// 0051b4ec  d3fa                 sar edx, cl
// 0051b4ee  8ad8                 mov bl, al
// 0051b4f0  8bce                 mov ecx, esi
// 0051b4f2  d2e3                 shl bl, cl
// 0051b4f4  2217                 and dl, byte ptr [edi]
// 0051b4f6  0ad3                 or dl, bl
// 0051b4f8  3bf5                 cmp esi, ebp
// 0051b4fa  8817                 mov byte ptr [edi], dl
// 0051b4fc  7509                 jne 0x51b507
// 0051b4fe  8b742420             mov esi, dword ptr [esp + 0x20]
// 0051b502  83ef01               sub edi, 1
// 0051b505  eb04                 jmp 0x51b50b
// 0051b507  03742418             add esi, dword ptr [esp + 0x18]
// 0051b50b  836c242801           sub dword ptr [esp + 0x28], 1
// 0051b510  75ce                 jne 0x51b4e0
// 0051b512  8b542414             mov edx, dword ptr [esp + 0x14]
// 0051b516  3bd5                 cmp edx, ebp
// 0051b518  750b                 jne 0x51b525
// 0051b51a  8b542420             mov edx, dword ptr [esp + 0x20]
// 0051b51e  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0051b523  eb04                 jmp 0x51b529
// 0051b525  03542418             add edx, dword ptr [esp + 0x18]
// 0051b529  8b442434             mov eax, dword ptr [esp + 0x34]
// 0051b52d  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0051b531  83c001               add eax, 1
// 0051b534  3b01                 cmp eax, dword ptr [ecx]
// 0051b536  89542414             mov dword ptr [esp + 0x14], edx
// 0051b53a  89442434             mov dword ptr [esp + 0x34], eax
// 0051b53e  7283                 jb 0x51b4c3
// 0051b540  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0051b544  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0051b548  8a410b               mov al, byte ptr [ecx + 0xb]
// 0051b54b  3c08                 cmp al, 8
// 0051b54d  8929                 mov dword ptr [ecx], ebp
// 0051b54f  0fb6c0               movzx eax, al
// 0051b552  7208                 jb 0x51b55c
// 0051b554  c1e803               shr eax, 3
// 0051b557  0fafc5               imul eax, ebp
// 0051b55a  eb09                 jmp 0x51b565
// 0051b55c  0fafc5               imul eax, ebp
// 0051b55f  83c007               add eax, 7
// 0051b562  c1e803               shr eax, 3
// 0051b565  5f                   pop edi
// 0051b566  894104               mov dword ptr [ecx + 4], eax
// 0051b569  5d                   pop ebp
// 0051b56a  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0051b56e  5e                   pop esi
// 0051b56f  5b                   pop ebx
// 0051b570  33cc                 xor ecx, esp
// 0051b572  e82f391000           call 0x61eea6
// 0051b577  83c430               add esp, 0x30
// 0051b57a  c3                   ret 
// library libpng-1.2.7/pngrutil.c (function _png_do_read_interlace)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS /MD
// roc-lib: libpng-1.2.7 pngrutil.c
