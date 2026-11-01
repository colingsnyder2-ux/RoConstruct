// from server: 100% by auto
// roc 2007-08 0051a1c0  unit: seg_00510000  size: 4092 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0051a1c0
//
// 0051a1c0  83ec10               sub esp, 0x10
// 0051a1c3  837c242000           cmp dword ptr [esp + 0x20], 0
// 0051a1c8  8b442414             mov eax, dword ptr [esp + 0x14]
// 0051a1cc  8b08                 mov ecx, dword ptr [eax]
// 0051a1ce  890c24               mov dword ptr [esp], ecx
// 0051a1d1  0f849b0f0000         je 0x51b172
// 0051a1d7  8a4008               mov al, byte ptr [eax + 8]
// 0051a1da  a804                 test al, 4
// 0051a1dc  55                   push ebp
// 0051a1dd  7416                 je 0x51a1f5
// 0051a1df  3c03                 cmp al, 3
// 0051a1e1  0f848a0f0000         je 0x51b171
// 0051a1e7  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0051a1eb  85ed                 test ebp, ebp
// 0051a1ed  0f847e0f0000         je 0x51b171
// 0051a1f3  eb04                 jmp 0x51a1f9
// 0051a1f5  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0051a1f9  0fb6c0               movzx eax, al
// 0051a1fc  83f806               cmp eax, 6
// 0051a1ff  0f87280f0000         ja 0x51b12d
// 0051a205  53                   push ebx
// 0051a206  56                   push esi
// 0051a207  57                   push edi
// 0051a208  ff248578b15100       jmp dword ptr [eax*4 + 0x51b178]
// 0051a20f  8b542424             mov edx, dword ptr [esp + 0x24]
// 0051a213  0fb64209             movzx eax, byte ptr [edx + 9]
// 0051a217  83c0ff               add eax, -1
// 0051a21a  83f80f               cmp eax, 0xf
// 0051a21d  0f87070f0000         ja 0x51b12a
// 0051a223  0fb680acb15100       movzx eax, byte ptr [eax + 0x51b1ac]
// 0051a22a  ff248594b15100       jmp dword ptr [eax*4 + 0x51b194]
// 0051a231  85c9                 test ecx, ecx
// 0051a233  8b742428             mov esi, dword ptr [esp + 0x28]
// 0051a237  ba07000000           mov edx, 7
// 0051a23c  0f86e80e0000         jbe 0x51b12a
// 0051a242  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0051a246  8be9                 mov ebp, ecx
// 0051a248  8a1e                 mov bl, byte ptr [esi]
// 0051a24a  8ac3                 mov al, bl
// 0051a24c  8aca                 mov cl, dl
// 0051a24e  d2e8                 shr al, cl
// 0051a250  2401                 and al, 1
// 0051a252  660fb6c8             movzx cx, al
// 0051a256  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0051a25a  663b4808             cmp cx, word ptr [eax + 8]
// 0051a25e  751d                 jne 0x51a27d
// 0051a260  b907000000           mov ecx, 7
// 0051a265  2bca                 sub ecx, edx
// 0051a267  b87f7f0000           mov eax, 0x7f7f
// 0051a26c  d3f8                 sar eax, cl
// 0051a26e  8bca                 mov ecx, edx
// 0051a270  22c3                 and al, bl
// 0051a272  8806                 mov byte ptr [esi], al
// 0051a274  8a5f08               mov bl, byte ptr [edi + 8]
// 0051a277  d2e3                 shl bl, cl
// 0051a279  0ad8                 or bl, al
// 0051a27b  881e                 mov byte ptr [esi], bl
// 0051a27d  85d2                 test edx, edx
// 0051a27f  750a                 jne 0x51a28b
// 0051a281  ba07000000           mov edx, 7
// 0051a286  83c601               add esi, 1
// 0051a289  eb03                 jmp 0x51a28e
// 0051a28b  83ea01               sub edx, 1
// 0051a28e  83ed01               sub ebp, 1
// 0051a291  75b5                 jne 0x51a248
// 0051a293  e9920e0000           jmp 0x51b12a
// 0051a298  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0051a29c  85ff                 test edi, edi
// 0051a29e  8b742428             mov esi, dword ptr [esp + 0x28]
// 0051a2a2  ba06000000           mov edx, 6
// 0051a2a7  0f84a1000000         je 0x51a34e
// 0051a2ad  85c9                 test ecx, ecx
// 0051a2af  0f86750e0000         jbe 0x51b12a
// 0051a2b5  894c2414             mov dword ptr [esp + 0x14], ecx
// 0051a2b9  8da42400000000       lea esp, [esp]
// 0051a2c0  8a1e                 mov bl, byte ptr [esi]
// 0051a2c2  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0051a2c6  8aca                 mov cl, dl
// 0051a2c8  8ac3                 mov al, bl
// 0051a2ca  d2e8                 shr al, cl
// 0051a2cc  2403                 and al, 3
// 0051a2ce  660fb6c8             movzx cx, al
// 0051a2d2  663b4d08             cmp cx, word ptr [ebp + 8]
// 0051a2d6  751f                 jne 0x51a2f7
// 0051a2d8  b906000000           mov ecx, 6
// 0051a2dd  2bca                 sub ecx, edx
// 0051a2df  b83f3f0000           mov eax, 0x3f3f
// 0051a2e4  d3f8                 sar eax, cl
// 0051a2e6  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0051a2ea  22c3                 and al, bl
// 0051a2ec  8806                 mov byte ptr [esi], al
// 0051a2ee  8a5908               mov bl, byte ptr [ecx + 8]
// 0051a2f1  8bca                 mov ecx, edx
// 0051a2f3  d2e3                 shl bl, cl
// 0051a2f5  eb32                 jmp 0x51a329
// 0051a2f7  0fb6c0               movzx eax, al
// 0051a2fa  8d0c8500000000       lea ecx, [eax*4]
// 0051a301  0bc8                 or ecx, eax
// 0051a303  03c9                 add ecx, ecx
// 0051a305  03c9                 add ecx, ecx
// 0051a307  0bc8                 or ecx, eax
// 0051a309  03c9                 add ecx, ecx
// 0051a30b  03c9                 add ecx, ecx
// 0051a30d  0bc8                 or ecx, eax
// 0051a30f  8a0439               mov al, byte ptr [ecx + edi]
// 0051a312  b906000000           mov ecx, 6
// 0051a317  2bca                 sub ecx, edx
// 0051a319  bb3f3f0000           mov ebx, 0x3f3f
// 0051a31e  d3fb                 sar ebx, cl
// 0051a320  c0e806               shr al, 6
// 0051a323  8bca                 mov ecx, edx
// 0051a325  221e                 and bl, byte ptr [esi]
// 0051a327  d2e0                 shl al, cl
// 0051a329  0ad8                 or bl, al
// 0051a32b  85d2                 test edx, edx
// 0051a32d  881e                 mov byte ptr [esi], bl
// 0051a32f  750a                 jne 0x51a33b
// 0051a331  ba06000000           mov edx, 6
// 0051a336  83c601               add esi, 1
// 0051a339  eb03                 jmp 0x51a33e
// 0051a33b  83ea02               sub edx, 2
// 0051a33e  836c241401           sub dword ptr [esp + 0x14], 1
// 0051a343  0f8577ffffff         jne 0x51a2c0
// 0051a349  e9dc0d0000           jmp 0x51b12a
// 0051a34e  85c9                 test ecx, ecx
// 0051a350  0f86d40d0000         jbe 0x51b12a
// 0051a356  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0051a35a  8be9                 mov ebp, ecx
// 0051a35c  8d642400             lea esp, [esp]
// 0051a360  8a1e                 mov bl, byte ptr [esi]
// 0051a362  8ac3                 mov al, bl
// 0051a364  8aca                 mov cl, dl
// 0051a366  d2e8                 shr al, cl
// 0051a368  2403                 and al, 3
// 0051a36a  660fb6c8             movzx cx, al
// 0051a36e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0051a372  663b4808             cmp cx, word ptr [eax + 8]
// 0051a376  751d                 jne 0x51a395
// 0051a378  b906000000           mov ecx, 6
// 0051a37d  2bca                 sub ecx, edx
// 0051a37f  b83f3f0000           mov eax, 0x3f3f
// 0051a384  d3f8                 sar eax, cl
// 0051a386  8bca                 mov ecx, edx
// 0051a388  22c3                 and al, bl
// 0051a38a  8806                 mov byte ptr [esi], al
// 0051a38c  8a5f08               mov bl, byte ptr [edi + 8]
// 0051a38f  d2e3                 shl bl, cl
// 0051a391  0ad8                 or bl, al
// 0051a393  881e                 mov byte ptr [esi], bl
// 0051a395  85d2                 test edx, edx
// 0051a397  750a                 jne 0x51a3a3
// 0051a399  ba06000000           mov edx, 6
// 0051a39e  83c601               add esi, 1
// 0051a3a1  eb03                 jmp 0x51a3a6
// 0051a3a3  83ea02               sub edx, 2
// 0051a3a6  83ed01               sub ebp, 1
// 0051a3a9  75b5                 jne 0x51a360
// 0051a3ab  e97a0d0000           jmp 0x51b12a
// 0051a3b0  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0051a3b4  85ff                 test edi, edi
// 0051a3b6  8b742428             mov esi, dword ptr [esp + 0x28]
// 0051a3ba  ba04000000           mov edx, 4
// 0051a3bf  0f8488000000         je 0x51a44d
// 0051a3c5  85c9                 test ecx, ecx
// 0051a3c7  0f865d0d0000         jbe 0x51b12a
// 0051a3cd  894c2414             mov dword ptr [esp + 0x14], ecx
// 0051a3d1  8a1e                 mov bl, byte ptr [esi]
// 0051a3d3  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0051a3d7  8aca                 mov cl, dl
// 0051a3d9  8ac3                 mov al, bl
// 0051a3db  d2e8                 shr al, cl
// 0051a3dd  240f                 and al, 0xf
// 0051a3df  660fb6c8             movzx cx, al
// 0051a3e3  663b4d08             cmp cx, word ptr [ebp + 8]
// 0051a3e7  751f                 jne 0x51a408
// 0051a3e9  b904000000           mov ecx, 4
// 0051a3ee  2bca                 sub ecx, edx
// 0051a3f0  b80f0f0000           mov eax, 0xf0f
// 0051a3f5  d3f8                 sar eax, cl
// 0051a3f7  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0051a3fb  22c3                 and al, bl
// 0051a3fd  8806                 mov byte ptr [esi], al
// 0051a3ff  8a5908               mov bl, byte ptr [ecx + 8]
// 0051a402  8bca                 mov ecx, edx
// 0051a404  d2e3                 shl bl, cl
// 0051a406  eb24                 jmp 0x51a42c
// 0051a408  0fb6c0               movzx eax, al
// 0051a40b  8bc8                 mov ecx, eax
// 0051a40d  c1e104               shl ecx, 4
// 0051a410  0bc8                 or ecx, eax
// 0051a412  8a0439               mov al, byte ptr [ecx + edi]
// 0051a415  b904000000           mov ecx, 4
// 0051a41a  2bca                 sub ecx, edx
// 0051a41c  bb0f0f0000           mov ebx, 0xf0f
// 0051a421  d3fb                 sar ebx, cl
// 0051a423  c0e804               shr al, 4
// 0051a426  8bca                 mov ecx, edx
// 0051a428  221e                 and bl, byte ptr [esi]
// 0051a42a  d2e0                 shl al, cl
// 0051a42c  0ad8                 or bl, al
// 0051a42e  85d2                 test edx, edx
// 0051a430  881e                 mov byte ptr [esi], bl
// 0051a432  750a                 jne 0x51a43e
// 0051a434  ba04000000           mov edx, 4
// 0051a439  83c601               add esi, 1
// 0051a43c  eb03                 jmp 0x51a441
// 0051a43e  83ea04               sub edx, 4
// 0051a441  836c241401           sub dword ptr [esp + 0x14], 1
// 0051a446  7589                 jne 0x51a3d1
// 0051a448  e9dd0c0000           jmp 0x51b12a
// 0051a44d  85c9                 test ecx, ecx
// 0051a44f  0f86d50c0000         jbe 0x51b12a
// 0051a455  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0051a459  8be9                 mov ebp, ecx
// 0051a45b  eb03                 jmp 0x51a460
// 0051a45d  8d4900               lea ecx, [ecx]
// 0051a460  8a1e                 mov bl, byte ptr [esi]
// 0051a462  8ac3                 mov al, bl
// 0051a464  8aca                 mov cl, dl
// 0051a466  d2e8                 shr al, cl
// 0051a468  240f                 and al, 0xf
// 0051a46a  660fb6c8             movzx cx, al
// 0051a46e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0051a472  663b4808             cmp cx, word ptr [eax + 8]
// 0051a476  751d                 jne 0x51a495
// 0051a478  b904000000           mov ecx, 4
// 0051a47d  2bca                 sub ecx, edx
// 0051a47f  b80f0f0000           mov eax, 0xf0f
// 0051a484  d3f8                 sar eax, cl
// 0051a486  8bca                 mov ecx, edx
// 0051a488  22c3                 and al, bl
// 0051a48a  8806                 mov byte ptr [esi], al
// 0051a48c  8a5f08               mov bl, byte ptr [edi + 8]
// 0051a48f  d2e3                 shl bl, cl
// 0051a491  0ad8                 or bl, al
// 0051a493  881e                 mov byte ptr [esi], bl
// 0051a495  85d2                 test edx, edx
// 0051a497  750a                 jne 0x51a4a3
// 0051a499  ba04000000           mov edx, 4
// 0051a49e  83c601               add esi, 1
// 0051a4a1  eb03                 jmp 0x51a4a6
// 0051a4a3  83ea04               sub edx, 4
// 0051a4a6  83ed01               sub ebp, 1
// 0051a4a9  75b5                 jne 0x51a460
// 0051a4ab  e97a0c0000           jmp 0x51b12a
// 0051a4b0  8b742438             mov esi, dword ptr [esp + 0x38]
// 0051a4b4  85f6                 test esi, esi
// 0051a4b6  8b442428             mov eax, dword ptr [esp + 0x28]
// 0051a4ba  743a                 je 0x51a4f6
// 0051a4bc  85c9                 test ecx, ecx
// 0051a4be  0f86660c0000         jbe 0x51b12a
// 0051a4c4  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0051a4c8  8bd1                 mov edx, ecx
// 0051a4ca  8d9b00000000         lea ebx, [ebx]
// 0051a4d0  8a08                 mov cl, byte ptr [eax]
// 0051a4d2  660fb6d9             movzx bx, cl
// 0051a4d6  663b5d08             cmp bx, word ptr [ebp + 8]
// 0051a4da  7505                 jne 0x51a4e1
// 0051a4dc  8a4f08               mov cl, byte ptr [edi + 8]
// 0051a4df  eb06                 jmp 0x51a4e7
// 0051a4e1  0fb6c9               movzx ecx, cl
// 0051a4e4  8a0c31               mov cl, byte ptr [ecx + esi]
// 0051a4e7  8808                 mov byte ptr [eax], cl
// 0051a4e9  83c001               add eax, 1
// 0051a4ec  83ea01               sub edx, 1
// 0051a4ef  75df                 jne 0x51a4d0
// 0051a4f1  e9340c0000           jmp 0x51b12a
// 0051a4f6  85c9                 test ecx, ecx
// 0051a4f8  0f862c0c0000         jbe 0x51b12a
// 0051a4fe  8b742430             mov esi, dword ptr [esp + 0x30]
// 0051a502  660fb610             movzx dx, byte ptr [eax]
// 0051a506  663b5508             cmp dx, word ptr [ebp + 8]
// 0051a50a  7505                 jne 0x51a511
// 0051a50c  8a5608               mov dl, byte ptr [esi + 8]
// 0051a50f  8810                 mov byte ptr [eax], dl
// 0051a511  83c001               add eax, 1
// 0051a514  83e901               sub ecx, 1
// 0051a517  75e9                 jne 0x51a502
// 0051a519  e90c0c0000           jmp 0x51b12a
// 0051a51e  8b742444             mov esi, dword ptr [esp + 0x44]
// 0051a522  85f6                 test esi, esi
// 0051a524  8b442428             mov eax, dword ptr [esp + 0x28]
// 0051a528  7467                 je 0x51a591
// 0051a52a  85c9                 test ecx, ecx
// 0051a52c  0f86f80b0000         jbe 0x51b12a
// 0051a532  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 0051a536  894c2414             mov dword ptr [esp + 0x14], ecx
// 0051a53a  8d9b00000000         lea ebx, [ebx]
// 0051a540  8a10                 mov dl, byte ptr [eax]
// 0051a542  8a4801               mov cl, byte ptr [eax + 1]
// 0051a545  660fb6fa             movzx di, dl
// 0051a549  660fb6e9             movzx bp, cl
// 0051a54d  66c1e708             shl di, 8
// 0051a551  6603fd               add di, bp
// 0051a554  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0051a558  663b7d08             cmp di, word ptr [ebp + 8]
// 0051a55c  750e                 jne 0x51a56c
// 0051a55e  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0051a562  8a5709               mov dl, byte ptr [edi + 9]
// 0051a565  8810                 mov byte ptr [eax], dl
// 0051a567  8a4f08               mov cl, byte ptr [edi + 8]
// 0051a56a  eb13                 jmp 0x51a57f
// 0051a56c  0fb6f9               movzx edi, cl
// 0051a56f  8acb                 mov cl, bl
// 0051a571  d3ef                 shr edi, cl
// 0051a573  0fb6d2               movzx edx, dl
// 0051a576  8b0cbe               mov ecx, dword ptr [esi + edi*4]
// 0051a579  0fb70c51             movzx ecx, word ptr [ecx + edx*2]
// 0051a57d  8828                 mov byte ptr [eax], ch
// 0051a57f  884801               mov byte ptr [eax + 1], cl
// 0051a582  83c002               add eax, 2
// 0051a585  836c241401           sub dword ptr [esp + 0x14], 1
// 0051a58a  75b4                 jne 0x51a540
// 0051a58c  e9990b0000           jmp 0x51b12a
// 0051a591  85c9                 test ecx, ecx
// 0051a593  0f86910b0000         jbe 0x51b12a
// 0051a599  8b742430             mov esi, dword ptr [esp + 0x30]
// 0051a59d  8d4900               lea ecx, [ecx]
// 0051a5a0  660fb610             movzx dx, byte ptr [eax]
// 0051a5a4  660fb67801           movzx di, byte ptr [eax + 1]
// 0051a5a9  66c1e208             shl dx, 8
// 0051a5ad  6603d7               add dx, di
// 0051a5b0  663b5508             cmp dx, word ptr [ebp + 8]
// 0051a5b4  750d                 jne 0x51a5c3
// 0051a5b6  0fb65609             movzx edx, byte ptr [esi + 9]
// 0051a5ba  8810                 mov byte ptr [eax], dl
// 0051a5bc  0fb65608             movzx edx, byte ptr [esi + 8]
// 0051a5c0  885001               mov byte ptr [eax + 1], dl
// 0051a5c3  83c002               add eax, 2
// 0051a5c6  83e901               sub ecx, 1
// 0051a5c9  75d5                 jne 0x51a5a0
// 0051a5cb  e95a0b0000           jmp 0x51b12a
// 0051a5d0  8b442424             mov eax, dword ptr [esp + 0x24]
// 0051a5d4  80780908             cmp byte ptr [eax + 9], 8
// 0051a5d8  0f85d7000000         jne 0x51a6b5
// 0051a5de  8b542438             mov edx, dword ptr [esp + 0x38]
// 0051a5e2  85d2                 test edx, edx
// 0051a5e4  747b                 je 0x51a661
// 0051a5e6  85c9                 test ecx, ecx
// 0051a5e8  0f863c0b0000         jbe 0x51b12a
// 0051a5ee  8b442428             mov eax, dword ptr [esp + 0x28]
// 0051a5f2  8b742430             mov esi, dword ptr [esp + 0x30]
// 0051a5f6  83c002               add eax, 2
// 0051a5f9  8bf9                 mov edi, ecx
// 0051a5fb  eb03                 jmp 0x51a600
// 0051a5fd  8d4900               lea ecx, [ecx]
// 0051a600  8a48fe               mov cl, byte ptr [eax - 2]
// 0051a603  660fb6d9             movzx bx, cl
// 0051a607  663b5d02             cmp bx, word ptr [ebp + 2]
// 0051a60b  7529                 jne 0x51a636
// 0051a60d  660fb658ff           movzx bx, byte ptr [eax - 1]
// 0051a612  663b5d04             cmp bx, word ptr [ebp + 4]
// 0051a616  751e                 jne 0x51a636
// 0051a618  660fb618             movzx bx, byte ptr [eax]
// 0051a61c  663b5d06             cmp bx, word ptr [ebp + 6]
// 0051a620  7514                 jne 0x51a636
// 0051a622  0fb64e02             movzx ecx, byte ptr [esi + 2]
// 0051a626  8848fe               mov byte ptr [eax - 2], cl
// 0051a629  0fb64e04             movzx ecx, byte ptr [esi + 4]
// 0051a62d  8848ff               mov byte ptr [eax - 1], cl
// 0051a630  0fb64e06             movzx ecx, byte ptr [esi + 6]
// 0051a634  eb1c                 jmp 0x51a652
// 0051a636  0fb6c9               movzx ecx, cl
// 0051a639  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 0051a63d  8848fe               mov byte ptr [eax - 2], cl
// 0051a640  0fb648ff             movzx ecx, byte ptr [eax - 1]
// 0051a644  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 0051a648  8848ff               mov byte ptr [eax - 1], cl
// 0051a64b  0fb608               movzx ecx, byte ptr [eax]
// 0051a64e  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 0051a652  8808                 mov byte ptr [eax], cl
// 0051a654  83c003               add eax, 3
// 0051a657  83ef01               sub edi, 1
// 0051a65a  75a4                 jne 0x51a600
// 0051a65c  e9c90a0000           jmp 0x51b12a
// 0051a661  85c9                 test ecx, ecx
// 0051a663  0f86c10a0000         jbe 0x51b12a
// 0051a669  8b442428             mov eax, dword ptr [esp + 0x28]
// 0051a66d  8b742430             mov esi, dword ptr [esp + 0x30]
// 0051a671  83c002               add eax, 2
// 0051a674  660fb650fe           movzx dx, byte ptr [eax - 2]
// 0051a679  663b5502             cmp dx, word ptr [ebp + 2]
// 0051a67d  7529                 jne 0x51a6a8
// 0051a67f  660fb650ff           movzx dx, byte ptr [eax - 1]
// 0051a684  663b5504             cmp dx, word ptr [ebp + 4]
// 0051a688  751e                 jne 0x51a6a8
// 0051a68a  660fb610             movzx dx, byte ptr [eax]
// 0051a68e  663b5506             cmp dx, word ptr [ebp + 6]
// 0051a692  7514                 jne 0x51a6a8
// 0051a694  0fb65602             movzx edx, byte ptr [esi + 2]
// 0051a698  8850fe               mov byte ptr [eax - 2], dl
// 0051a69b  0fb65604             movzx edx, byte ptr [esi + 4]
// 0051a69f  8850ff               mov byte ptr [eax - 1], dl
// 0051a6a2  0fb65606             movzx edx, byte ptr [esi + 6]
// 0051a6a6  8810                 mov byte ptr [eax], dl
// 0051a6a8  83c003               add eax, 3
// 0051a6ab  83e901               sub ecx, 1
// 0051a6ae  75c4                 jne 0x51a674
// 0051a6b0  e9750a0000           jmp 0x51b12a
// 0051a6b5  8b742444             mov esi, dword ptr [esp + 0x44]
// 0051a6b9  85f6                 test esi, esi
// 0051a6bb  0f84fd000000         je 0x51a7be
// 0051a6c1  85c9                 test ecx, ecx
// 0051a6c3  0f86610a0000         jbe 0x51b12a
// 0051a6c9  8b442428             mov eax, dword ptr [esp + 0x28]
// 0051a6cd  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0051a6d1  83c002               add eax, 2
// 0051a6d4  894c2414             mov dword ptr [esp + 0x14], ecx
// 0051a6d8  eb06                 jmp 0x51a6e0
// 0051a6da  8d9b00000000         lea ebx, [ebx]
// 0051a6e0  8a58fe               mov bl, byte ptr [eax - 2]
// 0051a6e3  8a48ff               mov cl, byte ptr [eax - 1]
// 0051a6e6  660fb6d3             movzx dx, bl
// 0051a6ea  660fb6e9             movzx bp, cl
// 0051a6ee  66c1e208             shl dx, 8
// 0051a6f2  6603d5               add dx, bp
// 0051a6f5  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0051a6f9  663b5502             cmp dx, word ptr [ebp + 2]
// 0051a6fd  7560                 jne 0x51a75f
// 0051a6ff  660fb610             movzx dx, byte ptr [eax]
// 0051a703  660fb66801           movzx bp, byte ptr [eax + 1]
// 0051a708  66c1e208             shl dx, 8
// 0051a70c  6603d5               add dx, bp
// 0051a70f  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0051a713  663b5504             cmp dx, word ptr [ebp + 4]
// 0051a717  7546                 jne 0x51a75f
// 0051a719  660fb65002           movzx dx, byte ptr [eax + 2]
// 0051a71e  660fb66803           movzx bp, byte ptr [eax + 3]
// 0051a723  66c1e208             shl dx, 8
// 0051a727  6603d5               add dx, bp
// 0051a72a  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0051a72e  663b5506             cmp dx, word ptr [ebp + 6]
// 0051a732  752b                 jne 0x51a75f
// 0051a734  0fb64f03             movzx ecx, byte ptr [edi + 3]
// 0051a738  8848fe               mov byte ptr [eax - 2], cl
// 0051a73b  0fb65702             movzx edx, byte ptr [edi + 2]
// 0051a73f  8850ff               mov byte ptr [eax - 1], dl
// 0051a742  0fb64f05             movzx ecx, byte ptr [edi + 5]
// 0051a746  8808                 mov byte ptr [eax], cl
// 0051a748  0fb65704             movzx edx, byte ptr [edi + 4]
// 0051a74c  885001               mov byte ptr [eax + 1], dl
// 0051a74f  0fb64f07             movzx ecx, byte ptr [edi + 7]
// 0051a753  884802               mov byte ptr [eax + 2], cl
// 0051a756  0fb65706             movzx edx, byte ptr [edi + 6]
// 0051a75a  885003               mov byte ptr [eax + 3], dl
// 0051a75d  eb4c                 jmp 0x51a7ab
// 0051a75f  0fb6542450           movzx edx, byte ptr [esp + 0x50]
// 0051a764  0fb6e9               movzx ebp, cl
// 0051a767  8aca                 mov cl, dl
// 0051a769  d3ed                 shr ebp, cl
// 0051a76b  0fb6cb               movzx ecx, bl
// 0051a76e  8b1cae               mov ebx, dword ptr [esi + ebp*4]
// 0051a771  0fb70c4b             movzx ecx, word ptr [ebx + ecx*2]
// 0051a775  0fb65801             movzx ebx, byte ptr [eax + 1]
// 0051a779  8848ff               mov byte ptr [eax - 1], cl
// 0051a77c  8aca                 mov cl, dl
// 0051a77e  d3eb                 shr ebx, cl
// 0051a780  8868fe               mov byte ptr [eax - 2], ch
// 0051a783  0fb608               movzx ecx, byte ptr [eax]
// 0051a786  8b1c9e               mov ebx, dword ptr [esi + ebx*4]
// 0051a789  0fb70c4b             movzx ecx, word ptr [ebx + ecx*2]
// 0051a78d  0fb65803             movzx ebx, byte ptr [eax + 3]
// 0051a791  884801               mov byte ptr [eax + 1], cl
// 0051a794  8aca                 mov cl, dl
// 0051a796  0fb65002             movzx edx, byte ptr [eax + 2]
// 0051a79a  d3eb                 shr ebx, cl
// 0051a79c  8828                 mov byte ptr [eax], ch
// 0051a79e  8b0c9e               mov ecx, dword ptr [esi + ebx*4]
// 0051a7a1  0fb70c51             movzx ecx, word ptr [ecx + edx*2]
// 0051a7a5  886802               mov byte ptr [eax + 2], ch
// 0051a7a8  884803               mov byte ptr [eax + 3], cl
// 0051a7ab  83c006               add eax, 6
// 0051a7ae  836c241401           sub dword ptr [esp + 0x14], 1
// 0051a7b3  0f8527ffffff         jne 0x51a6e0
// 0051a7b9  e96c090000           jmp 0x51b12a
// 0051a7be  85c9                 test ecx, ecx
// 0051a7c0  0f8664090000         jbe 0x51b12a
// 0051a7c6  8b442428             mov eax, dword ptr [esp + 0x28]
// 0051a7ca  8b742430             mov esi, dword ptr [esp + 0x30]
// 0051a7ce  83c002               add eax, 2
// 0051a7d1  660fb650fe           movzx dx, byte ptr [eax - 2]
// 0051a7d6  660fb678ff           movzx di, byte ptr [eax - 1]
// 0051a7db  66c1e208             shl dx, 8
// 0051a7df  6603d7               add dx, di
// 0051a7e2  663b5502             cmp dx, word ptr [ebp + 2]
// 0051a7e6  7556                 jne 0x51a83e
// 0051a7e8  660fb610             movzx dx, byte ptr [eax]
// 0051a7ec  660fb67801           movzx di, byte ptr [eax + 1]
// 0051a7f1  66c1e208             shl dx, 8
// 0051a7f5  6603d7               add dx, di
// 0051a7f8  663b5504             cmp dx, word ptr [ebp + 4]
// 0051a7fc  7540                 jne 0x51a83e
// 0051a7fe  660fb65002           movzx dx, byte ptr [eax + 2]
// 0051a803  660fb67803           movzx di, byte ptr [eax + 3]
// 0051a808  66c1e208             shl dx, 8
// 0051a80c  6603d7               add dx, di
// 0051a80f  663b5506             cmp dx, word ptr [ebp + 6]
// 0051a813  7529                 jne 0x51a83e
// 0051a815  0fb65603             movzx edx, byte ptr [esi + 3]
// 0051a819  8850fe               mov byte ptr [eax - 2], dl
// 0051a81c  0fb65602             movzx edx, byte ptr [esi + 2]
// 0051a820  8850ff               mov byte ptr [eax - 1], dl
// 0051a823  0fb65605             movzx edx, byte ptr [esi + 5]
// 0051a827  8810                 mov byte ptr [eax], dl
// 0051a829  0fb65604             movzx edx, byte ptr [esi + 4]
// 0051a82d  885001               mov byte ptr [eax + 1], dl
// 0051a830  0fb65607             movzx edx, byte ptr [esi + 7]
// 0051a834  885002               mov byte ptr [eax + 2], dl
// 0051a837  0fb65606             movzx edx, byte ptr [esi + 6]
// 0051a83b  885003               mov byte ptr [eax + 3], dl
// 0051a83e  83c006               add eax, 6
// 0051a841  83e901               sub ecx, 1
// 0051a844  758b                 jne 0x51a7d1
// 0051a846  e9df080000           jmp 0x51b12a
// 0051a84b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0051a84f  80780908             cmp byte ptr [eax + 9], 8
// 0051a853  0f8534010000         jne 0x51a98d
// 0051a859  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0051a85d  85ff                 test edi, edi
// 0051a85f  0f84b5000000         je 0x51a91a
// 0051a865  837c243c00           cmp dword ptr [esp + 0x3c], 0
// 0051a86a  0f84aa000000         je 0x51a91a
// 0051a870  837c243800           cmp dword ptr [esp + 0x38], 0
// 0051a875  0f849f000000         je 0x51a91a
// 0051a87b  837c241000           cmp dword ptr [esp + 0x10], 0
// 0051a880  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0051a884  8bf1                 mov esi, ecx
// 0051a886  0f869e080000         jbe 0x51b12a
// 0051a88c  8b542410             mov edx, dword ptr [esp + 0x10]
// 0051a890  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0051a894  89542414             mov dword ptr [esp + 0x14], edx
// 0051a898  eb06                 jmp 0x51a8a0
// 0051a89a  8d9b00000000         lea ebx, [ebx]
// 0051a8a0  660fb64101           movzx ax, byte ptr [ecx + 1]
// 0051a8a5  0fb7c0               movzx eax, ax
// 0051a8a8  663dff00             cmp ax, 0xff
// 0051a8ac  750e                 jne 0x51a8bc
// 0051a8ae  0fb611               movzx edx, byte ptr [ecx]
// 0051a8b1  8b442438             mov eax, dword ptr [esp + 0x38]
// 0051a8b5  8a1402               mov dl, byte ptr [edx + eax]
// 0051a8b8  8816                 mov byte ptr [esi], dl
// 0051a8ba  eb4c                 jmp 0x51a908
// 0051a8bc  6685c0               test ax, ax
// 0051a8bf  750b                 jne 0x51a8cc
// 0051a8c1  8b442430             mov eax, dword ptr [esp + 0x30]
// 0051a8c5  8a5008               mov dl, byte ptr [eax + 8]
// 0051a8c8  8816                 mov byte ptr [esi], dl
// 0051a8ca  eb3c                 jmp 0x51a908
// 0051a8cc  0fb619               movzx ebx, byte ptr [ecx]
// 0051a8cf  660fb61c3b           movzx bx, byte ptr [ebx + edi]
// 0051a8d4  660fafd8             imul bx, ax
// 0051a8d8  baff000000           mov edx, 0xff
// 0051a8dd  2bd0                 sub edx, eax
// 0051a8df  660faf5508           imul dx, word ptr [ebp + 8]
// 0051a8e4  6603d3               add dx, bx
// 0051a8e7  6681c28000           add dx, 0x80
// 0051a8ec  0fb7c2               movzx eax, dx
// 0051a8ef  0fb7c0               movzx eax, ax
// 0051a8f2  8bd0                 mov edx, eax
// 0051a8f4  c1ea08               shr edx, 8
// 0051a8f7  03d0                 add edx, eax
// 0051a8f9  c1fa08               sar edx, 8
// 0051a8fc  0fb6c2               movzx eax, dl
// 0051a8ff  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0051a903  8a0410               mov al, byte ptr [eax + edx]
// 0051a906  8806                 mov byte ptr [esi], al
// 0051a908  83c102               add ecx, 2
// 0051a90b  83c601               add esi, 1
// 0051a90e  836c241401           sub dword ptr [esp + 0x14], 1
// 0051a913  758b                 jne 0x51a8a0
// 0051a915  e910080000           jmp 0x51b12a
// 0051a91a  837c241000           cmp dword ptr [esp + 0x10], 0
// 0051a91f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0051a923  8bf1                 mov esi, ecx
// 0051a925  0f86ff070000         jbe 0x51b12a
// 0051a92b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0051a92f  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0051a933  8a4101               mov al, byte ptr [ecx + 1]
// 0051a936  3cff                 cmp al, 0xff
// 0051a938  7504                 jne 0x51a93e
// 0051a93a  8a11                 mov dl, byte ptr [ecx]
// 0051a93c  eb3d                 jmp 0x51a97b
// 0051a93e  84c0                 test al, al
// 0051a940  7509                 jne 0x51a94b
// 0051a942  8b442430             mov eax, dword ptr [esp + 0x30]
// 0051a946  8a5008               mov dl, byte ptr [eax + 8]
// 0051a949  eb30                 jmp 0x51a97b
// 0051a94b  660fb619             movzx bx, byte ptr [ecx]
// 0051a94f  660fb6c0             movzx ax, al
// 0051a953  baff000000           mov edx, 0xff
// 0051a958  660fafd8             imul bx, ax
// 0051a95c  2bd0                 sub edx, eax
// 0051a95e  660faf5508           imul dx, word ptr [ebp + 8]
// 0051a963  6603d3               add dx, bx
// 0051a966  6681c28000           add dx, 0x80
// 0051a96b  0fb7c2               movzx eax, dx
// 0051a96e  0fb7c0               movzx eax, ax
// 0051a971  8bd0                 mov edx, eax
// 0051a973  c1ea08               shr edx, 8
// 0051a976  03d0                 add edx, eax
// 0051a978  c1fa08               sar edx, 8
// 0051a97b  8816                 mov byte ptr [esi], dl
// 0051a97d  83c102               add ecx, 2
// 0051a980  83c601               add esi, 1
// 0051a983  83ef01               sub edi, 1
// 0051a986  75ab                 jne 0x51a933
// 0051a988  e99d070000           jmp 0x51b12a
// 0051a98d  837c244400           cmp dword ptr [esp + 0x44], 0
// 0051a992  0f84f1000000         je 0x51aa89
// 0051a998  837c244800           cmp dword ptr [esp + 0x48], 0
// 0051a99d  0f84e6000000         je 0x51aa89
// 0051a9a3  837c244c00           cmp dword ptr [esp + 0x4c], 0
// 0051a9a8  0f84db000000         je 0x51aa89
// 0051a9ae  85c9                 test ecx, ecx
// 0051a9b0  8b542428             mov edx, dword ptr [esp + 0x28]
// 0051a9b4  8bf2                 mov esi, edx
// 0051a9b6  0f866e070000         jbe 0x51b12a
// 0051a9bc  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 0051a9c0  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0051a9c4  8bc1                 mov eax, ecx
// 0051a9c6  83c201               add edx, 1
// 0051a9c9  89442414             mov dword ptr [esp + 0x14], eax
// 0051a9cd  8d4900               lea ecx, [ecx]
// 0051a9d0  660fb64a01           movzx cx, byte ptr [edx + 1]
// 0051a9d5  660fb64202           movzx ax, byte ptr [edx + 2]
// 0051a9da  66c1e108             shl cx, 8
// 0051a9de  6603c8               add cx, ax
// 0051a9e1  0fb7c1               movzx eax, cx
// 0051a9e4  663dffff             cmp ax, 0xffff
// 0051a9e8  7519                 jne 0x51aa03
// 0051a9ea  0fb602               movzx eax, byte ptr [edx]
// 0051a9ed  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 0051a9f1  8acb                 mov cl, bl
// 0051a9f3  d3e8                 shr eax, cl
// 0051a9f5  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 0051a9f9  8b448500             mov eax, dword ptr [ebp + eax*4]
// 0051a9fd  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0051aa01  eb6b                 jmp 0x51aa6e
// 0051aa03  6685c0               test ax, ax
// 0051aa06  750a                 jne 0x51aa12
// 0051aa08  8a4f09               mov cl, byte ptr [edi + 9]
// 0051aa0b  880e                 mov byte ptr [esi], cl
// 0051aa0d  8a4708               mov al, byte ptr [edi + 8]
// 0051aa10  eb5e                 jmp 0x51aa70
// 0051aa12  0fb63a               movzx edi, byte ptr [edx]
// 0051aa15  8b6c244c             mov ebp, dword ptr [esp + 0x4c]
// 0051aa19  8acb                 mov cl, bl
// 0051aa1b  d3ef                 shr edi, cl
// 0051aa1d  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 0051aa21  8b7cbd00             mov edi, dword ptr [ebp + edi*4]
// 0051aa25  0fb70c4f             movzx ecx, word ptr [edi + ecx*2]
// 0051aa29  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0051aa2d  0fb77f08             movzx edi, word ptr [edi + 8]
// 0051aa31  0fb7c0               movzx eax, ax
// 0051aa34  0fafc8               imul ecx, eax
// 0051aa37  bdffff0000           mov ebp, 0xffff
// 0051aa3c  2be8                 sub ebp, eax
// 0051aa3e  0faffd               imul edi, ebp
// 0051aa41  8d8c3900800000       lea ecx, [ecx + edi + 0x8000]
// 0051aa48  8bc1                 mov eax, ecx
// 0051aa4a  c1e810               shr eax, 0x10
// 0051aa4d  03c1                 add eax, ecx
// 0051aa4f  c1e810               shr eax, 0x10
// 0051aa52  0fb7c0               movzx eax, ax
// 0051aa55  0fb6f8               movzx edi, al
// 0051aa58  8acb                 mov cl, bl
// 0051aa5a  d3ef                 shr edi, cl
// 0051aa5c  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0051aa60  c1e808               shr eax, 8
// 0051aa63  8b0cb9               mov ecx, dword ptr [ecx + edi*4]
// 0051aa66  0fb70441             movzx eax, word ptr [ecx + eax*2]
// 0051aa6a  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0051aa6e  8826                 mov byte ptr [esi], ah
// 0051aa70  884601               mov byte ptr [esi + 1], al
// 0051aa73  83c204               add edx, 4
// 0051aa76  83c602               add esi, 2
// 0051aa79  836c241401           sub dword ptr [esp + 0x14], 1
// 0051aa7e  0f854cffffff         jne 0x51a9d0
// 0051aa84  e9a1060000           jmp 0x51b12a
// 0051aa89  837c241000           cmp dword ptr [esp + 0x10], 0
// 0051aa8e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0051aa92  8bd1                 mov edx, ecx
// 0051aa94  0f8690060000         jbe 0x51b12a
// 0051aa9a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0051aa9e  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0051aaa2  8b742430             mov esi, dword ptr [esp + 0x30]
// 0051aaa6  83c103               add ecx, 3
// 0051aaa9  89442414             mov dword ptr [esp + 0x14], eax
// 0051aaad  8d4900               lea ecx, [ecx]
// 0051aab0  660fb641ff           movzx ax, byte ptr [ecx - 1]
// 0051aab5  660fb639             movzx di, byte ptr [ecx]
// 0051aab9  66c1e008             shl ax, 8
// 0051aabd  6603c7               add ax, di
// 0051aac0  0fb7c0               movzx eax, ax
// 0051aac3  663dffff             cmp ax, 0xffff
// 0051aac7  7509                 jne 0x51aad2
// 0051aac9  668b41fd             mov ax, word ptr [ecx - 3]
// 0051aacd  668902               mov word ptr [edx], ax
// 0051aad0  eb53                 jmp 0x51ab25
// 0051aad2  6685c0               test ax, ax
// 0051aad5  750c                 jne 0x51aae3
// 0051aad7  0fb64609             movzx eax, byte ptr [esi + 9]
// 0051aadb  8802                 mov byte ptr [edx], al
// 0051aadd  0fb64608             movzx eax, byte ptr [esi + 8]
// 0051aae1  eb3f                 jmp 0x51ab22
// 0051aae3  660fb671fd           movzx si, byte ptr [ecx - 3]
// 0051aae8  660fb679fe           movzx di, byte ptr [ecx - 2]
// 0051aaed  66c1e608             shl si, 8
// 0051aaf1  6603f7               add si, di
// 0051aaf4  0fb77d08             movzx edi, word ptr [ebp + 8]
// 0051aaf8  0fb7c0               movzx eax, ax
// 0051aafb  0fb7f6               movzx esi, si
// 0051aafe  0faff0               imul esi, eax
// 0051ab01  bbffff0000           mov ebx, 0xffff
// 0051ab06  2bd8                 sub ebx, eax
// 0051ab08  0faffb               imul edi, ebx
// 0051ab0b  8db43e00800000       lea esi, [esi + edi + 0x8000]
// 0051ab12  8bc6                 mov eax, esi
// 0051ab14  c1e810               shr eax, 0x10
// 0051ab17  03c6                 add eax, esi
// 0051ab19  8b742430             mov esi, dword ptr [esp + 0x30]
// 0051ab1d  c1e810               shr eax, 0x10
// 0051ab20  8822                 mov byte ptr [edx], ah
// 0051ab22  884201               mov byte ptr [edx + 1], al
// 0051ab25  83c104               add ecx, 4
// 0051ab28  83c202               add edx, 2
// 0051ab2b  836c241401           sub dword ptr [esp + 0x14], 1
// 0051ab30  0f857affffff         jne 0x51aab0
// 0051ab36  e9ef050000           jmp 0x51b12a
// 0051ab3b  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0051ab3f  80790908             cmp byte ptr [ecx + 9], 8
// 0051ab43  0f8562020000         jne 0x51adab
// 0051ab49  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0051ab4d  85ed                 test ebp, ebp
// 0051ab4f  0f845c010000         je 0x51acb1
// 0051ab55  837c243c00           cmp dword ptr [esp + 0x3c], 0
// 0051ab5a  0f8451010000         je 0x51acb1
// 0051ab60  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0051ab64  85c9                 test ecx, ecx
// 0051ab66  0f8445010000         je 0x51acb1
// 0051ab6c  837c241000           cmp dword ptr [esp + 0x10], 0
// 0051ab71  0f86b3050000         jbe 0x51b12a
// 0051ab77  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0051ab7b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0051ab7f  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0051ab83  8d7702               lea esi, [edi + 2]
// 0051ab86  89542414             mov dword ptr [esp + 0x14], edx
// 0051ab8a  8b542434             mov edx, dword ptr [esp + 0x34]
// 0051ab8e  83c701               add edi, 1
// 0051ab91  8a4702               mov al, byte ptr [edi + 2]
// 0051ab94  3cff                 cmp al, 0xff
// 0051ab96  7522                 jne 0x51abba
// 0051ab98  0fb647ff             movzx eax, byte ptr [edi - 1]
// 0051ab9c  0fb60408             movzx eax, byte ptr [eax + ecx]
// 0051aba0  8846fe               mov byte ptr [esi - 2], al
// 0051aba3  0fb607               movzx eax, byte ptr [edi]
// 0051aba6  0fb60408             movzx eax, byte ptr [eax + ecx]
// 0051abaa  8846ff               mov byte ptr [esi - 1], al
// 0051abad  0fb64701             movzx eax, byte ptr [edi + 1]
// 0051abb1  0fb60408             movzx eax, byte ptr [eax + ecx]
// 0051abb5  e9df000000           jmp 0x51ac99
// 0051abba  84c0                 test al, al
// 0051abbc  7517                 jne 0x51abd5
// 0051abbe  0fb64302             movzx eax, byte ptr [ebx + 2]
// 0051abc2  8846fe               mov byte ptr [esi - 2], al
// 0051abc5  0fb64304             movzx eax, byte ptr [ebx + 4]
// 0051abc9  8846ff               mov byte ptr [esi - 1], al
// 0051abcc  0fb64306             movzx eax, byte ptr [ebx + 6]
// 0051abd0  e9c4000000           jmp 0x51ac99
// 0051abd5  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 0051abd9  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0051abdd  668b6a02             mov bp, word ptr [edx + 2]
// 0051abe1  660fb6c0             movzx ax, al
// 0051abe5  660fafd8             imul bx, ax
// 0051abe9  b9ff000000           mov ecx, 0xff
// 0051abee  2bc8                 sub ecx, eax
// 0051abf0  660fafe9             imul bp, cx
// 0051abf4  6603dd               add bx, bp
// 0051abf7  6681c38000           add bx, 0x80
// 0051abfc  0fb7db               movzx ebx, bx
// 0051abff  0fb7eb               movzx ebp, bx
// 0051ac02  8bdd                 mov ebx, ebp
// 0051ac04  c1eb08               shr ebx, 8
// 0051ac07  03dd                 add ebx, ebp
// 0051ac09  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 0051ac0d  c1fb08               sar ebx, 8
// 0051ac10  0fb6db               movzx ebx, bl
// 0051ac13  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0051ac17  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0051ac1b  885efe               mov byte ptr [esi - 2], bl
// 0051ac1e  0fb61f               movzx ebx, byte ptr [edi]
// 0051ac21  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0051ac25  668b6a04             mov bp, word ptr [edx + 4]
// 0051ac29  660fafd8             imul bx, ax
// 0051ac2d  660fafe9             imul bp, cx
// 0051ac31  6603dd               add bx, bp
// 0051ac34  6681c38000           add bx, 0x80
// 0051ac39  0fb7db               movzx ebx, bx
// 0051ac3c  0fb7eb               movzx ebp, bx
// 0051ac3f  8bdd                 mov ebx, ebp
// 0051ac41  c1eb08               shr ebx, 8
// 0051ac44  03dd                 add ebx, ebp
// 0051ac46  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 0051ac4a  c1fb08               sar ebx, 8
// 0051ac4d  0fb6db               movzx ebx, bl
// 0051ac50  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0051ac54  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0051ac58  885eff               mov byte ptr [esi - 1], bl
// 0051ac5b  0fb65f01             movzx ebx, byte ptr [edi + 1]
// 0051ac5f  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0051ac63  660fafd8             imul bx, ax
// 0051ac67  668b4206             mov ax, word ptr [edx + 6]
// 0051ac6b  660fafc1             imul ax, cx
// 0051ac6f  6603d8               add bx, ax
// 0051ac72  6681c38000           add bx, 0x80
// 0051ac77  0fb7c3               movzx eax, bx
// 0051ac7a  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0051ac7e  0fb7c0               movzx eax, ax
// 0051ac81  8bc8                 mov ecx, eax
// 0051ac83  c1e908               shr ecx, 8
// 0051ac86  03c8                 add ecx, eax
// 0051ac88  c1f908               sar ecx, 8
// 0051ac8b  0fb6c1               movzx eax, cl
// 0051ac8e  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0051ac92  8a0408               mov al, byte ptr [eax + ecx]
// 0051ac95  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0051ac99  8806                 mov byte ptr [esi], al
// 0051ac9b  83c704               add edi, 4
// 0051ac9e  83c603               add esi, 3
// 0051aca1  836c241401           sub dword ptr [esp + 0x14], 1
// 0051aca6  0f85e5feffff         jne 0x51ab91
// 0051acac  e979040000           jmp 0x51b12a
// 0051acb1  837c241000           cmp dword ptr [esp + 0x10], 0
// 0051acb6  0f866e040000         jbe 0x51b12a
// 0051acbc  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0051acc0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0051acc4  8b542430             mov edx, dword ptr [esp + 0x30]
// 0051acc8  8d7702               lea esi, [edi + 2]
// 0051accb  83c701               add edi, 1
// 0051acce  894c2414             mov dword ptr [esp + 0x14], ecx
// 0051acd2  8a4702               mov al, byte ptr [edi + 2]
// 0051acd5  3cff                 cmp al, 0xff
// 0051acd7  7517                 jne 0x51acf0
// 0051acd9  0fb647ff             movzx eax, byte ptr [edi - 1]
// 0051acdd  8846fe               mov byte ptr [esi - 2], al
// 0051ace0  8a0f                 mov cl, byte ptr [edi]
// 0051ace2  884eff               mov byte ptr [esi - 1], cl
// 0051ace5  0fb64701             movzx eax, byte ptr [edi + 1]
// 0051ace9  8806                 mov byte ptr [esi], al
// 0051aceb  e9a5000000           jmp 0x51ad95
// 0051acf0  84c0                 test al, al
// 0051acf2  7516                 jne 0x51ad0a
// 0051acf4  0fb64a02             movzx ecx, byte ptr [edx + 2]
// 0051acf8  884efe               mov byte ptr [esi - 2], cl
// 0051acfb  8a4204               mov al, byte ptr [edx + 4]
// 0051acfe  8846ff               mov byte ptr [esi - 1], al
// 0051ad01  0fb64a06             movzx ecx, byte ptr [edx + 6]
// 0051ad05  e989000000           jmp 0x51ad93
// 0051ad0a  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 0051ad0e  668b6a02             mov bp, word ptr [edx + 2]
// 0051ad12  660fb6c0             movzx ax, al
// 0051ad16  660fafd8             imul bx, ax
// 0051ad1a  b9ff000000           mov ecx, 0xff
// 0051ad1f  2bc8                 sub ecx, eax
// 0051ad21  660fafe9             imul bp, cx
// 0051ad25  6603dd               add bx, bp
// 0051ad28  6681c38000           add bx, 0x80
// 0051ad2d  0fb7db               movzx ebx, bx
// 0051ad30  0fb7eb               movzx ebp, bx
// 0051ad33  8bdd                 mov ebx, ebp
// 0051ad35  c1eb08               shr ebx, 8
// 0051ad38  03dd                 add ebx, ebp
// 0051ad3a  c1fb08               sar ebx, 8
// 0051ad3d  885efe               mov byte ptr [esi - 2], bl
// 0051ad40  0fb75a04             movzx ebx, word ptr [edx + 4]
// 0051ad44  660fb62f             movzx bp, byte ptr [edi]
// 0051ad48  660fafd9             imul bx, cx
// 0051ad4c  660fafe8             imul bp, ax
// 0051ad50  6603dd               add bx, bp
// 0051ad53  6681c38000           add bx, 0x80
// 0051ad58  0fb7db               movzx ebx, bx
// 0051ad5b  0fb7eb               movzx ebp, bx
// 0051ad5e  8bdd                 mov ebx, ebp
// 0051ad60  c1eb08               shr ebx, 8
// 0051ad63  03dd                 add ebx, ebp
// 0051ad65  c1fb08               sar ebx, 8
// 0051ad68  885eff               mov byte ptr [esi - 1], bl
// 0051ad6b  0fb65f01             movzx ebx, byte ptr [edi + 1]
// 0051ad6f  660fafd8             imul bx, ax
// 0051ad73  668b4206             mov ax, word ptr [edx + 6]
// 0051ad77  660fafc1             imul ax, cx
// 0051ad7b  6603d8               add bx, ax
// 0051ad7e  6681c38000           add bx, 0x80
// 0051ad83  0fb7c3               movzx eax, bx
// 0051ad86  0fb7c0               movzx eax, ax
// 0051ad89  8bc8                 mov ecx, eax
// 0051ad8b  c1e908               shr ecx, 8
// 0051ad8e  03c8                 add ecx, eax
// 0051ad90  c1f908               sar ecx, 8
// 0051ad93  880e                 mov byte ptr [esi], cl
// 0051ad95  83c704               add edi, 4
// 0051ad98  83c603               add esi, 3
// 0051ad9b  836c241401           sub dword ptr [esp + 0x14], 1
// 0051ada0  0f852cffffff         jne 0x51acd2
// 0051ada6  e97f030000           jmp 0x51b12a
// 0051adab  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 0051adaf  85ed                 test ebp, ebp
// 0051adb1  0f842a020000         je 0x51afe1
// 0051adb7  837c244800           cmp dword ptr [esp + 0x48], 0
// 0051adbc  0f841f020000         je 0x51afe1
// 0051adc2  837c244c00           cmp dword ptr [esp + 0x4c], 0
// 0051adc7  0f8414020000         je 0x51afe1
// 0051adcd  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0051add1  85c9                 test ecx, ecx
// 0051add3  0f8651030000         jbe 0x51b12a
// 0051add9  8b542428             mov edx, dword ptr [esp + 0x28]
// 0051addd  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 0051ade1  8d4202               lea eax, [edx + 2]
// 0051ade4  83c201               add edx, 1
// 0051ade7  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0051adeb  eb03                 jmp 0x51adf0
// 0051aded  8d4900               lea ecx, [ecx]
// 0051adf0  660fb64a05           movzx cx, byte ptr [edx + 5]
// 0051adf5  660fb67206           movzx si, byte ptr [edx + 6]
// 0051adfa  66c1e108             shl cx, 8
// 0051adfe  6603ce               add cx, si
// 0051ae01  0fb7f1               movzx esi, cx
// 0051ae04  6681feffff           cmp si, 0xffff
// 0051ae09  7556                 jne 0x51ae61
// 0051ae0b  0fb632               movzx esi, byte ptr [edx]
// 0051ae0e  0fb6cb               movzx ecx, bl
// 0051ae11  d3ee                 shr esi, cl
// 0051ae13  894c2414             mov dword ptr [esp + 0x14], ecx
// 0051ae17  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 0051ae1b  8b74b500             mov esi, dword ptr [ebp + esi*4]
// 0051ae1f  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 0051ae23  8868fe               mov byte ptr [eax - 2], ch
// 0051ae26  8848ff               mov byte ptr [eax - 1], cl
// 0051ae29  0fb67202             movzx esi, byte ptr [edx + 2]
// 0051ae2d  0fb64c2414           movzx ecx, byte ptr [esp + 0x14]
// 0051ae32  d3ee                 shr esi, cl
// 0051ae34  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0051ae38  8b74b500             mov esi, dword ptr [ebp + esi*4]
// 0051ae3c  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 0051ae40  8828                 mov byte ptr [eax], ch
// 0051ae42  884801               mov byte ptr [eax + 1], cl
// 0051ae45  0fb64c2414           movzx ecx, byte ptr [esp + 0x14]
// 0051ae4a  0fb67204             movzx esi, byte ptr [edx + 4]
// 0051ae4e  d3ee                 shr esi, cl
// 0051ae50  0fb64a03             movzx ecx, byte ptr [edx + 3]
// 0051ae54  8b74b500             mov esi, dword ptr [ebp + esi*4]
// 0051ae58  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 0051ae5c  e964010000           jmp 0x51afc5
// 0051ae61  6685f6               test si, si
// 0051ae64  7543                 jne 0x51aea9
// 0051ae66  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0051ae6a  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 0051ae6e  8848fe               mov byte ptr [eax - 2], cl
// 0051ae71  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0051ae75  0fb64902             movzx ecx, byte ptr [ecx + 2]
// 0051ae79  8848ff               mov byte ptr [eax - 1], cl
// 0051ae7c  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0051ae80  0fb64905             movzx ecx, byte ptr [ecx + 5]
// 0051ae84  8808                 mov byte ptr [eax], cl
// 0051ae86  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0051ae8a  0fb64904             movzx ecx, byte ptr [ecx + 4]
// 0051ae8e  884801               mov byte ptr [eax + 1], cl
// 0051ae91  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0051ae95  0fb64907             movzx ecx, byte ptr [ecx + 7]
// 0051ae99  884802               mov byte ptr [eax + 2], cl
// 0051ae9c  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0051aea0  0fb64906             movzx ecx, byte ptr [ecx + 6]
// 0051aea4  e91f010000           jmp 0x51afc8
// 0051aea9  0fb7fe               movzx edi, si
// 0051aeac  0fb632               movzx esi, byte ptr [edx]
// 0051aeaf  0fb6cb               movzx ecx, bl
// 0051aeb2  d3ee                 shr esi, cl
// 0051aeb4  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 0051aeb8  894c2414             mov dword ptr [esp + 0x14], ecx
// 0051aebc  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 0051aec0  8b34b3               mov esi, dword ptr [ebx + esi*4]
// 0051aec3  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 0051aec7  8b742434             mov esi, dword ptr [esp + 0x34]
// 0051aecb  0fafcf               imul ecx, edi
// 0051aece  0fb77602             movzx esi, word ptr [esi + 2]
// 0051aed2  bdffff0000           mov ebp, 0xffff
// 0051aed7  2bef                 sub ebp, edi
// 0051aed9  0faff5               imul esi, ebp
// 0051aedc  8d8c3100800000       lea ecx, [ecx + esi + 0x8000]
// 0051aee3  8bf1                 mov esi, ecx
// 0051aee5  c1ee10               shr esi, 0x10
// 0051aee8  03f1                 add esi, ecx
// 0051aeea  0fb74c2450           movzx ecx, word ptr [esp + 0x50]
// 0051aeef  c1ee10               shr esi, 0x10
// 0051aef2  0fb7de               movzx ebx, si
// 0051aef5  894c2418             mov dword ptr [esp + 0x18], ecx
// 0051aef9  0fb6f3               movzx esi, bl
// 0051aefc  d3ee                 shr esi, cl
// 0051aefe  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0051af02  c1eb08               shr ebx, 8
// 0051af05  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 0051af08  0fb70c59             movzx ecx, word ptr [ecx + ebx*2]
// 0051af0c  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 0051af10  8868fe               mov byte ptr [eax - 2], ch
// 0051af13  8848ff               mov byte ptr [eax - 1], cl
// 0051af16  0fb67202             movzx esi, byte ptr [edx + 2]
// 0051af1a  0fb64c2414           movzx ecx, byte ptr [esp + 0x14]
// 0051af1f  d3ee                 shr esi, cl
// 0051af21  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0051af25  8b34b3               mov esi, dword ptr [ebx + esi*4]
// 0051af28  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 0051af2c  8b742434             mov esi, dword ptr [esp + 0x34]
// 0051af30  0fafcf               imul ecx, edi
// 0051af33  0fb77604             movzx esi, word ptr [esi + 4]
// 0051af37  0faff5               imul esi, ebp
// 0051af3a  8d8c3100800000       lea ecx, [ecx + esi + 0x8000]
// 0051af41  8bf1                 mov esi, ecx
// 0051af43  c1ee10               shr esi, 0x10
// 0051af46  03f1                 add esi, ecx
// 0051af48  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0051af4c  c1ee10               shr esi, 0x10
// 0051af4f  0fb7de               movzx ebx, si
// 0051af52  0fb6f3               movzx esi, bl
// 0051af55  d3ee                 shr esi, cl
// 0051af57  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0051af5b  c1eb08               shr ebx, 8
// 0051af5e  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 0051af61  0fb70c59             movzx ecx, word ptr [ecx + ebx*2]
// 0051af65  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 0051af69  8828                 mov byte ptr [eax], ch
// 0051af6b  884801               mov byte ptr [eax + 1], cl
// 0051af6e  0fb64c2414           movzx ecx, byte ptr [esp + 0x14]
// 0051af73  0fb67204             movzx esi, byte ptr [edx + 4]
// 0051af77  d3ee                 shr esi, cl
// 0051af79  0fb64a03             movzx ecx, byte ptr [edx + 3]
// 0051af7d  8b34b3               mov esi, dword ptr [ebx + esi*4]
// 0051af80  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 0051af84  8b742434             mov esi, dword ptr [esp + 0x34]
// 0051af88  0fafcf               imul ecx, edi
// 0051af8b  0fb77606             movzx esi, word ptr [esi + 6]
// 0051af8f  0faff5               imul esi, ebp
// 0051af92  8d8c3100800000       lea ecx, [ecx + esi + 0x8000]
// 0051af99  8bf1                 mov esi, ecx
// 0051af9b  c1ee10               shr esi, 0x10
// 0051af9e  03f1                 add esi, ecx
// 0051afa0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0051afa4  c1ee10               shr esi, 0x10
// 0051afa7  0fb7de               movzx ebx, si
// 0051afaa  0fb6f3               movzx esi, bl
// 0051afad  d3ee                 shr esi, cl
// 0051afaf  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0051afb3  c1eb08               shr ebx, 8
// 0051afb6  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 0051afb9  0fb70c59             movzx ecx, word ptr [ecx + ebx*2]
// 0051afbd  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 0051afc1  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 0051afc5  886802               mov byte ptr [eax + 2], ch
// 0051afc8  884803               mov byte ptr [eax + 3], cl
// 0051afcb  83c208               add edx, 8
// 0051afce  83c006               add eax, 6
// 0051afd1  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0051afd6  0f8514feffff         jne 0x51adf0
// 0051afdc  e949010000           jmp 0x51b12a
// 0051afe1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0051afe5  85d2                 test edx, edx
// 0051afe7  0f863d010000         jbe 0x51b12a
// 0051afed  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0051aff1  8b742430             mov esi, dword ptr [esp + 0x30]
// 0051aff5  8d4102               lea eax, [ecx + 2]
// 0051aff8  83c107               add ecx, 7
// 0051affb  8954241c             mov dword ptr [esp + 0x1c], edx
// 0051afff  90                   nop 
// 0051b000  660fb651ff           movzx dx, byte ptr [ecx - 1]
// 0051b005  660fb639             movzx di, byte ptr [ecx]
// 0051b009  66c1e208             shl dx, 8
// 0051b00d  6603d7               add dx, di
// 0051b010  0fb7d2               movzx edx, dx
// 0051b013  6681faffff           cmp dx, 0xffff
// 0051b018  7513                 jne 0x51b02d
// 0051b01a  8b51f9               mov edx, dword ptr [ecx - 7]
// 0051b01d  8950fe               mov dword ptr [eax - 2], edx
// 0051b020  668b51fd             mov dx, word ptr [ecx - 3]
// 0051b024  66895002             mov word ptr [eax + 2], dx
// 0051b028  e9ec000000           jmp 0x51b119
// 0051b02d  6685d2               test dx, dx
// 0051b030  752b                 jne 0x51b05d
// 0051b032  0fb65603             movzx edx, byte ptr [esi + 3]
// 0051b036  8850fe               mov byte ptr [eax - 2], dl
// 0051b039  0fb65602             movzx edx, byte ptr [esi + 2]
// 0051b03d  8850ff               mov byte ptr [eax - 1], dl
// 0051b040  0fb65605             movzx edx, byte ptr [esi + 5]
// 0051b044  8810                 mov byte ptr [eax], dl
// 0051b046  0fb65604             movzx edx, byte ptr [esi + 4]
// 0051b04a  885001               mov byte ptr [eax + 1], dl
// 0051b04d  0fb65607             movzx edx, byte ptr [esi + 7]
// 0051b051  885002               mov byte ptr [eax + 2], dl
// 0051b054  0fb65606             movzx edx, byte ptr [esi + 6]
// 0051b058  e9b9000000           jmp 0x51b116
// 0051b05d  0fb671fb             movzx esi, byte ptr [ecx - 5]
// 0051b061  0fb679fc             movzx edi, byte ptr [ecx - 4]
// 0051b065  660fb659fa           movzx bx, byte ptr [ecx - 6]
// 0051b06a  66c1e608             shl si, 8
// 0051b06e  6603f7               add si, di
// 0051b071  0fb679fe             movzx edi, byte ptr [ecx - 2]
// 0051b075  0fb7f6               movzx esi, si
// 0051b078  89742418             mov dword ptr [esp + 0x18], esi
// 0051b07c  0fb671fd             movzx esi, byte ptr [ecx - 3]
// 0051b080  66c1e608             shl si, 8
// 0051b084  6603f7               add si, di
// 0051b087  0fb7f6               movzx esi, si
// 0051b08a  89742414             mov dword ptr [esp + 0x14], esi
// 0051b08e  0fb7f2               movzx esi, dx
// 0051b091  660fb651f9           movzx dx, byte ptr [ecx - 7]
// 0051b096  66c1e208             shl dx, 8
// 0051b09a  6603d3               add dx, bx
// 0051b09d  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0051b0a1  0fb76b02             movzx ebp, word ptr [ebx + 2]
// 0051b0a5  0fb7d2               movzx edx, dx
// 0051b0a8  0fafd6               imul edx, esi
// 0051b0ab  bfffff0000           mov edi, 0xffff
// 0051b0b0  2bfe                 sub edi, esi
// 0051b0b2  0fafef               imul ebp, edi
// 0051b0b5  8dac2a00800000       lea ebp, [edx + ebp + 0x8000]
// 0051b0bc  8bd5                 mov edx, ebp
// 0051b0be  c1ea10               shr edx, 0x10
// 0051b0c1  03d5                 add edx, ebp
// 0051b0c3  0fb76c2418           movzx ebp, word ptr [esp + 0x18]
// 0051b0c8  c1ea10               shr edx, 0x10
// 0051b0cb  0fafee               imul ebp, esi
// 0051b0ce  8870fe               mov byte ptr [eax - 2], dh
// 0051b0d1  8850ff               mov byte ptr [eax - 1], dl
// 0051b0d4  0fb75304             movzx edx, word ptr [ebx + 4]
// 0051b0d8  0fafd7               imul edx, edi
// 0051b0db  8dac2a00800000       lea ebp, [edx + ebp + 0x8000]
// 0051b0e2  8bd5                 mov edx, ebp
// 0051b0e4  c1ea10               shr edx, 0x10
// 0051b0e7  03d5                 add edx, ebp
// 0051b0e9  c1ea10               shr edx, 0x10
// 0051b0ec  8830                 mov byte ptr [eax], dh
// 0051b0ee  885001               mov byte ptr [eax + 1], dl
// 0051b0f1  0fb75306             movzx edx, word ptr [ebx + 6]
// 0051b0f5  0fafd7               imul edx, edi
// 0051b0f8  0fb77c2414           movzx edi, word ptr [esp + 0x14]
// 0051b0fd  0faffe               imul edi, esi
// 0051b100  8db43a00800000       lea esi, [edx + edi + 0x8000]
// 0051b107  8bd6                 mov edx, esi
// 0051b109  c1ea10               shr edx, 0x10
// 0051b10c  03d6                 add edx, esi
// 0051b10e  c1ea10               shr edx, 0x10
// 0051b111  887002               mov byte ptr [eax + 2], dh
// 0051b114  8bf3                 mov esi, ebx
// 0051b116  885003               mov byte ptr [eax + 3], dl
// 0051b119  83c108               add ecx, 8
// 0051b11c  83c006               add eax, 6
// 0051b11f  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0051b124  0f85d6feffff         jne 0x51b000
// 0051b12a  5f                   pop edi
// 0051b12b  5e                   pop esi
// 0051b12c  5b                   pop ebx
// 0051b12d  8b542418             mov edx, dword ptr [esp + 0x18]
// 0051b131  8a4208               mov al, byte ptr [edx + 8]
// 0051b134  a804                 test al, 4
// 0051b136  7439                 je 0x51b171
// 0051b138  80420aff             add byte ptr [edx + 0xa], 0xff
// 0051b13c  8a4a0a               mov cl, byte ptr [edx + 0xa]
// 0051b13f  24fb                 and al, 0xfb
// 0051b141  884208               mov byte ptr [edx + 8], al
// 0051b144  8a4209               mov al, byte ptr [edx + 9]
// 0051b147  f6e9                 imul cl
// 0051b149  88420b               mov byte ptr [edx + 0xb], al
// 0051b14c  3c08                 cmp al, 8
// 0051b14e  0fb6c0               movzx eax, al
// 0051b151  7210                 jb 0x51b163
// 0051b153  c1e803               shr eax, 3
// 0051b156  0faf442404           imul eax, dword ptr [esp + 4]
// 0051b15b  894204               mov dword ptr [edx + 4], eax
// 0051b15e  5d                   pop ebp
// 0051b15f  83c410               add esp, 0x10
// 0051b162  c3                   ret 
// 0051b163  0faf442404           imul eax, dword ptr [esp + 4]
// 0051b168  83c007               add eax, 7
// 0051b16b  c1e803               shr eax, 3
// 0051b16e  894204               mov dword ptr [edx + 4], eax
// 0051b171  5d                   pop ebp
// 0051b172  83c410               add esp, 0x10
// 0051b175  c3                   ret 
// 0051b176  8bff                 mov edi, edi
// 0051b178  0fa2                 cpuid 
// 0051b17a  51                   push ecx
// 0051b17b  002a                 add byte ptr [edx], ch
// 0051b17d  b151                 mov cl, 0x51
// 0051b17f  00d0                 add al, dl
// 0051b181  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 0051b182  51                   push ecx
// 0051b183  002a                 add byte ptr [edx], ch
// 0051b185  b151                 mov cl, 0x51
// 0051b187  004ba8               add byte ptr [ebx - 0x58], cl
// 0051b18a  51                   push ecx
// 0051b18b  002a                 add byte ptr [edx], ch
// 0051b18d  b151                 mov cl, 0x51
// 0051b18f  003b                 add byte ptr [ebx], bh
// 0051b191  ab                   stosd dword ptr es:[edi], eax
// 0051b192  51                   push ecx
// 0051b193  0031                 add byte ptr [ecx], dh
// 0051b195  a2510098a2           mov byte ptr [0xa2980051], al
// 0051b19a  51                   push ecx
// 0051b19b  00b0a35100b0         add byte ptr [eax - 0x4fffae5d], dh
// 0051b1a1  a4                   movsb byte ptr es:[edi], byte ptr [esi]
// 0051b1a2  51                   push ecx
// 0051b1a3  001e                 add byte ptr [esi], bl
// 0051b1a5  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 0051b1a6  51                   push ecx
// 0051b1a7  002a                 add byte ptr [edx], ch
// 0051b1a9  b151                 mov cl, 0x51
// 0051b1ab  0000                 add byte ptr [eax], al
// 0051b1ad  010502050505         add dword ptr [0x5050502], eax
// 0051b1b3  030505050505         add eax, dword ptr [0x5050505]
// library libpng-1.2.6/pngrtran.c (function _png_do_background)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngrtran.c
