// from server: 100% by auto
// roc 2012-06 0065a570  unit: seg_00650000  size: 1096 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065a570
//
// 0065a570  83ec40               sub esp, 0x40
// 0065a573  8b442444             mov eax, dword ptr [esp + 0x44]
// 0065a577  8b88ec000000         mov ecx, dword ptr [eax + 0xec]
// 0065a57d  83c101               add ecx, 1
// 0065a580  0fb69024010000       movzx edx, byte ptr [eax + 0x124]
// 0065a587  53                   push ebx
// 0065a588  8b5870               mov ebx, dword ptr [eax + 0x70]
// 0065a58b  56                   push esi
// 0065a58c  8db000010000         lea esi, [eax + 0x100]
// 0065a592  b808000000           mov eax, 8
// 0065a597  57                   push edi
// 0065a598  89442430             mov dword ptr [esp + 0x30], eax
// 0065a59c  89442434             mov dword ptr [esp + 0x34], eax
// 0065a5a0  b804000000           mov eax, 4
// 0065a5a5  bf02000000           mov edi, 2
// 0065a5aa  89742410             mov dword ptr [esp + 0x10], esi
// 0065a5ae  89442438             mov dword ptr [esp + 0x38], eax
// 0065a5b2  8944243c             mov dword ptr [esp + 0x3c], eax
// 0065a5b6  897c2440             mov dword ptr [esp + 0x40], edi
// 0065a5ba  897c2444             mov dword ptr [esp + 0x44], edi
// 0065a5be  c744244801000000     mov dword ptr [esp + 0x48], 1
// 0065a5c6  0f84e5030000         je 0x65a9b1
// 0065a5cc  85f6                 test esi, esi
// 0065a5ce  0f84dd030000         je 0x65a9b1
// 0065a5d4  8b549430             mov edx, dword ptr [esp + edx*4 + 0x30]
// 0065a5d8  8b06                 mov eax, dword ptr [esi]
// 0065a5da  0fb6760b             movzx esi, byte ptr [esi + 0xb]
// 0065a5de  55                   push ebp
// 0065a5df  8be8                 mov ebp, eax
// 0065a5e1  0fafea               imul ebp, edx
// 0065a5e4  89542418             mov dword ptr [esp + 0x18], edx
// 0065a5e8  8bd6                 mov edx, esi
// 0065a5ea  83ea01               sub edx, 1
// 0065a5ed  896c2410             mov dword ptr [esp + 0x10], ebp
// 0065a5f1  0f84a3020000         je 0x65a89a
// 0065a5f7  83ea01               sub edx, 1
// 0065a5fa  0f849e010000         je 0x65a79e
// 0065a600  2bd7                 sub edx, edi
// 0065a602  8d7dff               lea edi, [ebp - 1]
// 0065a605  746b                 je 0x65a672
// 0065a607  c1ee03               shr esi, 3
// 0065a60a  8d58ff               lea ebx, [eax - 1]
// 0065a60d  0faffe               imul edi, esi
// 0065a610  0fafde               imul ebx, esi
// 0065a613  03d9                 add ebx, ecx
// 0065a615  03f9                 add edi, ecx
// 0065a617  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0065a61f  85c0                 test eax, eax
// 0065a621  0f8652010000         jbe 0x65a779
// 0065a627  56                   push esi
// 0065a628  8d442430             lea eax, [esp + 0x30]
// 0065a62c  53                   push ebx
// 0065a62d  50                   push eax
// 0065a62e  e829903200           call 0x98365c
// 0065a633  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065a637  83c40c               add esp, 0xc
// 0065a63a  85c0                 test eax, eax
// 0065a63c  7e1c                 jle 0x65a65a
// 0065a63e  8be8                 mov ebp, eax
// 0065a640  56                   push esi
// 0065a641  8d4c2430             lea ecx, [esp + 0x30]
// 0065a645  51                   push ecx
// 0065a646  57                   push edi
// 0065a647  e810903200           call 0x98365c
// 0065a64c  83c40c               add esp, 0xc
// 0065a64f  2bfe                 sub edi, esi
// 0065a651  83ed01               sub ebp, 1
// 0065a654  75ea                 jne 0x65a640
// 0065a656  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0065a65a  8b442454             mov eax, dword ptr [esp + 0x54]
// 0065a65e  8b542414             mov edx, dword ptr [esp + 0x14]
// 0065a662  40                   inc eax
// 0065a663  2bde                 sub ebx, esi
// 0065a665  89442454             mov dword ptr [esp + 0x54], eax
// 0065a669  3b02                 cmp eax, dword ptr [edx]
// 0065a66b  72ba                 jb 0x65a627
// 0065a66d  e907010000           jmp 0x65a779
// 0065a672  8d50ff               lea edx, [eax - 1]
// 0065a675  d1ea                 shr edx, 1
// 0065a677  d1ef                 shr edi, 1
// 0065a679  03d1                 add edx, ecx
// 0065a67b  03f9                 add edi, ecx
// 0065a67d  89542420             mov dword ptr [esp + 0x20], edx
// 0065a681  f7c300000100         test ebx, 0x10000
// 0065a687  7432                 je 0x65a6bb
// 0065a689  83caff               or edx, 0xffffffff
// 0065a68c  8d0c8500000000       lea ecx, [eax*4]
// 0065a693  2bd1                 sub edx, ecx
// 0065a695  83ceff               or esi, 0xffffffff
// 0065a698  8d0cad00000000       lea ecx, [ebp*4]
// 0065a69f  2bf1                 sub esi, ecx
// 0065a6a1  83e204               and edx, 4
// 0065a6a4  83e604               and esi, 4
// 0065a6a7  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 0065a6af  33ed                 xor ebp, ebp
// 0065a6b1  c7442424fcffffff     mov dword ptr [esp + 0x24], 0xfffffffc
// 0065a6b9  eb33                 jmp 0x65a6ee
// 0065a6bb  8d50ff               lea edx, [eax - 1]
// 0065a6be  83e201               and edx, 1
// 0065a6c1  4d                   dec ebp
// 0065a6c2  03d2                 add edx, edx
// 0065a6c4  03d2                 add edx, edx
// 0065a6c6  83e501               and ebp, 1
// 0065a6c9  03ed                 add ebp, ebp
// 0065a6cb  8bca                 mov ecx, edx
// 0065a6cd  ba04000000           mov edx, 4
// 0065a6d2  03ed                 add ebp, ebp
// 0065a6d4  be04000000           mov esi, 4
// 0065a6d9  2bd1                 sub edx, ecx
// 0065a6db  2bf5                 sub esi, ebp
// 0065a6dd  bd04000000           mov ebp, 4
// 0065a6e2  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0065a6ea  896c2424             mov dword ptr [esp + 0x24], ebp
// 0065a6ee  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0065a6f6  85c0                 test eax, eax
// 0065a6f8  767b                 jbe 0x65a775
// 0065a6fa  8d9b00000000         lea ebx, [ebx]
// 0065a700  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065a704  8a00                 mov al, byte ptr [eax]
// 0065a706  8aca                 mov cl, dl
// 0065a708  d2e8                 shr al, cl
// 0065a70a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065a70e  240f                 and al, 0xf
// 0065a710  88442454             mov byte ptr [esp + 0x54], al
// 0065a714  85c9                 test ecx, ecx
// 0065a716  7e3a                 jle 0x65a752
// 0065a718  894c2428             mov dword ptr [esp + 0x28], ecx
// 0065a71c  eb06                 jmp 0x65a724
// 0065a71e  8bff                 mov edi, edi
// 0065a720  8a442454             mov al, byte ptr [esp + 0x54]
// 0065a724  b904000000           mov ecx, 4
// 0065a729  2bce                 sub ecx, esi
// 0065a72b  bb0f0f0000           mov ebx, 0xf0f
// 0065a730  d3fb                 sar ebx, cl
// 0065a732  8bce                 mov ecx, esi
// 0065a734  d2e0                 shl al, cl
// 0065a736  221f                 and bl, byte ptr [edi]
// 0065a738  0ad8                 or bl, al
// 0065a73a  881f                 mov byte ptr [edi], bl
// 0065a73c  3bf5                 cmp esi, ebp
// 0065a73e  7507                 jne 0x65a747
// 0065a740  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0065a744  4f                   dec edi
// 0065a745  eb04                 jmp 0x65a74b
// 0065a747  03742424             add esi, dword ptr [esp + 0x24]
// 0065a74b  836c242801           sub dword ptr [esp + 0x28], 1
// 0065a750  75ce                 jne 0x65a720
// 0065a752  3bd5                 cmp edx, ebp
// 0065a754  750a                 jne 0x65a760
// 0065a756  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0065a75a  ff4c2420             dec dword ptr [esp + 0x20]
// 0065a75e  eb04                 jmp 0x65a764
// 0065a760  03542424             add edx, dword ptr [esp + 0x24]
// 0065a764  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0065a768  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0065a76c  40                   inc eax
// 0065a76d  8944242c             mov dword ptr [esp + 0x2c], eax
// 0065a771  3b01                 cmp eax, dword ptr [ecx]
// 0065a773  728b                 jb 0x65a700
// 0065a775  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0065a779  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0065a77d  8a410b               mov al, byte ptr [ecx + 0xb]
// 0065a780  3c08                 cmp al, 8
// 0065a782  8929                 mov dword ptr [ecx], ebp
// 0065a784  0fb6c0               movzx eax, al
// 0065a787  0f8217020000         jb 0x65a9a4
// 0065a78d  c1e803               shr eax, 3
// 0065a790  0fafc5               imul eax, ebp
// 0065a793  5d                   pop ebp
// 0065a794  5f                   pop edi
// 0065a795  5e                   pop esi
// 0065a796  894104               mov dword ptr [ecx + 4], eax
// 0065a799  5b                   pop ebx
// 0065a79a  83c440               add esp, 0x40
// 0065a79d  c3                   ret 
// 0065a79e  8d50ff               lea edx, [eax - 1]
// 0065a7a1  8d7dff               lea edi, [ebp - 1]
// 0065a7a4  c1ea02               shr edx, 2
// 0065a7a7  c1ef02               shr edi, 2
// 0065a7aa  03d1                 add edx, ecx
// 0065a7ac  03f9                 add edi, ecx
// 0065a7ae  89542420             mov dword ptr [esp + 0x20], edx
// 0065a7b2  f7c300000100         test ebx, 0x10000
// 0065a7b8  7422                 je 0x65a7dc
// 0065a7ba  8d742dff             lea esi, [ebp + ebp - 1]
// 0065a7be  8d5400ff             lea edx, [eax + eax - 1]
// 0065a7c2  83e206               and edx, 6
// 0065a7c5  83e606               and esi, 6
// 0065a7c8  c744242406000000     mov dword ptr [esp + 0x24], 6
// 0065a7d0  33ed                 xor ebp, ebp
// 0065a7d2  c744241cfeffffff     mov dword ptr [esp + 0x1c], 0xfffffffe
// 0065a7da  eb31                 jmp 0x65a80d
// 0065a7dc  4d                   dec ebp
// 0065a7dd  8d48ff               lea ecx, [eax - 1]
// 0065a7e0  83e103               and ecx, 3
// 0065a7e3  83e503               and ebp, 3
// 0065a7e6  ba03000000           mov edx, 3
// 0065a7eb  2bd1                 sub edx, ecx
// 0065a7ed  be03000000           mov esi, 3
// 0065a7f2  2bf5                 sub esi, ebp
// 0065a7f4  03d2                 add edx, edx
// 0065a7f6  03f6                 add esi, esi
// 0065a7f8  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0065a800  bd06000000           mov ebp, 6
// 0065a805  c744241c02000000     mov dword ptr [esp + 0x1c], 2
// 0065a80d  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0065a815  85c0                 test eax, eax
// 0065a817  0f8658ffffff         jbe 0x65a775
// 0065a81d  8d4900               lea ecx, [ecx]
// 0065a820  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065a824  8a00                 mov al, byte ptr [eax]
// 0065a826  8aca                 mov cl, dl
// 0065a828  d2e8                 shr al, cl
// 0065a82a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065a82e  2403                 and al, 3
// 0065a830  88442454             mov byte ptr [esp + 0x54], al
// 0065a834  85c9                 test ecx, ecx
// 0065a836  7e3a                 jle 0x65a872
// 0065a838  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0065a83c  eb06                 jmp 0x65a844
// 0065a83e  8bff                 mov edi, edi
// 0065a840  8a442454             mov al, byte ptr [esp + 0x54]
// 0065a844  b906000000           mov ecx, 6
// 0065a849  2bce                 sub ecx, esi
// 0065a84b  bb3f3f0000           mov ebx, 0x3f3f
// 0065a850  d3fb                 sar ebx, cl
// 0065a852  8bce                 mov ecx, esi
// 0065a854  d2e0                 shl al, cl
// 0065a856  221f                 and bl, byte ptr [edi]
// 0065a858  0ad8                 or bl, al
// 0065a85a  881f                 mov byte ptr [edi], bl
// 0065a85c  3bf5                 cmp esi, ebp
// 0065a85e  7507                 jne 0x65a867
// 0065a860  8b742424             mov esi, dword ptr [esp + 0x24]
// 0065a864  4f                   dec edi
// 0065a865  eb04                 jmp 0x65a86b
// 0065a867  0374241c             add esi, dword ptr [esp + 0x1c]
// 0065a86b  836c242c01           sub dword ptr [esp + 0x2c], 1
// 0065a870  75ce                 jne 0x65a840
// 0065a872  3bd5                 cmp edx, ebp
// 0065a874  750a                 jne 0x65a880
// 0065a876  8b542424             mov edx, dword ptr [esp + 0x24]
// 0065a87a  ff4c2420             dec dword ptr [esp + 0x20]
// 0065a87e  eb04                 jmp 0x65a884
// 0065a880  0354241c             add edx, dword ptr [esp + 0x1c]
// 0065a884  8b442428             mov eax, dword ptr [esp + 0x28]
// 0065a888  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0065a88c  40                   inc eax
// 0065a88d  89442428             mov dword ptr [esp + 0x28], eax
// 0065a891  3b01                 cmp eax, dword ptr [ecx]
// 0065a893  728b                 jb 0x65a820
// 0065a895  e9dbfeffff           jmp 0x65a775
// 0065a89a  8d50ff               lea edx, [eax - 1]
// 0065a89d  8d7dff               lea edi, [ebp - 1]
// 0065a8a0  c1ea03               shr edx, 3
// 0065a8a3  c1ef03               shr edi, 3
// 0065a8a6  03d1                 add edx, ecx
// 0065a8a8  03f9                 add edi, ecx
// 0065a8aa  8954241c             mov dword ptr [esp + 0x1c], edx
// 0065a8ae  f7c300000100         test ebx, 0x10000
// 0065a8b4  7426                 je 0x65a8dc
// 0065a8b6  8d50ff               lea edx, [eax - 1]
// 0065a8b9  8d75ff               lea esi, [ebp - 1]
// 0065a8bc  83e207               and edx, 7
// 0065a8bf  83e607               and esi, 7
// 0065a8c2  c744242007000000     mov dword ptr [esp + 0x20], 7
// 0065a8ca  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0065a8d2  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0065a8da  eb32                 jmp 0x65a90e
// 0065a8dc  8d48ff               lea ecx, [eax - 1]
// 0065a8df  83e107               and ecx, 7
// 0065a8e2  ba07000000           mov edx, 7
// 0065a8e7  2bd1                 sub edx, ecx
// 0065a8e9  8d4dff               lea ecx, [ebp - 1]
// 0065a8ec  83e107               and ecx, 7
// 0065a8ef  be07000000           mov esi, 7
// 0065a8f4  2bf1                 sub esi, ecx
// 0065a8f6  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0065a8fe  c744242407000000     mov dword ptr [esp + 0x24], 7
// 0065a906  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0065a90e  89542454             mov dword ptr [esp + 0x54], edx
// 0065a912  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0065a91a  85c0                 test eax, eax
// 0065a91c  0f8657feffff         jbe 0x65a779
// 0065a922  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065a926  8a00                 mov al, byte ptr [eax]
// 0065a928  8aca                 mov cl, dl
// 0065a92a  d2e8                 shr al, cl
// 0065a92c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065a930  2401                 and al, 1
// 0065a932  85c9                 test ecx, ecx
// 0065a934  7e40                 jle 0x65a976
// 0065a936  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0065a93a  8d9b00000000         lea ebx, [ebx]
// 0065a940  b907000000           mov ecx, 7
// 0065a945  2bce                 sub ecx, esi
// 0065a947  ba7f7f0000           mov edx, 0x7f7f
// 0065a94c  d3fa                 sar edx, cl
// 0065a94e  8ad8                 mov bl, al
// 0065a950  8bce                 mov ecx, esi
// 0065a952  d2e3                 shl bl, cl
// 0065a954  2217                 and dl, byte ptr [edi]
// 0065a956  0ad3                 or dl, bl
// 0065a958  8817                 mov byte ptr [edi], dl
// 0065a95a  3b742424             cmp esi, dword ptr [esp + 0x24]
// 0065a95e  7507                 jne 0x65a967
// 0065a960  8b742420             mov esi, dword ptr [esp + 0x20]
// 0065a964  4f                   dec edi
// 0065a965  eb04                 jmp 0x65a96b
// 0065a967  03742410             add esi, dword ptr [esp + 0x10]
// 0065a96b  836c242c01           sub dword ptr [esp + 0x2c], 1
// 0065a970  75ce                 jne 0x65a940
// 0065a972  8b542454             mov edx, dword ptr [esp + 0x54]
// 0065a976  3b542424             cmp edx, dword ptr [esp + 0x24]
// 0065a97a  750a                 jne 0x65a986
// 0065a97c  8b542420             mov edx, dword ptr [esp + 0x20]
// 0065a980  ff4c241c             dec dword ptr [esp + 0x1c]
// 0065a984  eb04                 jmp 0x65a98a
// 0065a986  03542410             add edx, dword ptr [esp + 0x10]
// 0065a98a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0065a98e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0065a992  40                   inc eax
// 0065a993  89542454             mov dword ptr [esp + 0x54], edx
// 0065a997  89442428             mov dword ptr [esp + 0x28], eax
// 0065a99b  3b01                 cmp eax, dword ptr [ecx]
// 0065a99d  7283                 jb 0x65a922
// 0065a99f  e9d5fdffff           jmp 0x65a779
// 0065a9a4  0fafc5               imul eax, ebp
// 0065a9a7  83c007               add eax, 7
// 0065a9aa  c1e803               shr eax, 3
// 0065a9ad  894104               mov dword ptr [ecx + 4], eax
// 0065a9b0  5d                   pop ebp
// 0065a9b1  5f                   pop edi
// 0065a9b2  5e                   pop esi
// 0065a9b3  5b                   pop ebx
// 0065a9b4  83c440               add esp, 0x40
// 0065a9b7  c3                   ret 
// library libpng-1.2.22/pngrutil.c (function _png_do_read_interlace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrutil.c
