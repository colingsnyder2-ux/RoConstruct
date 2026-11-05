// from server: 100% by auto
// roc 2010-06 00577b40  unit: seg_00570000  size: 1096 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00577b40
//
// 00577b40  83ec40               sub esp, 0x40
// 00577b43  8b442444             mov eax, dword ptr [esp + 0x44]
// 00577b47  8b88ec000000         mov ecx, dword ptr [eax + 0xec]
// 00577b4d  83c101               add ecx, 1
// 00577b50  0fb69024010000       movzx edx, byte ptr [eax + 0x124]
// 00577b57  53                   push ebx
// 00577b58  8b5870               mov ebx, dword ptr [eax + 0x70]
// 00577b5b  56                   push esi
// 00577b5c  8db000010000         lea esi, [eax + 0x100]
// 00577b62  b808000000           mov eax, 8
// 00577b67  57                   push edi
// 00577b68  89442430             mov dword ptr [esp + 0x30], eax
// 00577b6c  89442434             mov dword ptr [esp + 0x34], eax
// 00577b70  b804000000           mov eax, 4
// 00577b75  bf02000000           mov edi, 2
// 00577b7a  89742410             mov dword ptr [esp + 0x10], esi
// 00577b7e  89442438             mov dword ptr [esp + 0x38], eax
// 00577b82  8944243c             mov dword ptr [esp + 0x3c], eax
// 00577b86  897c2440             mov dword ptr [esp + 0x40], edi
// 00577b8a  897c2444             mov dword ptr [esp + 0x44], edi
// 00577b8e  c744244801000000     mov dword ptr [esp + 0x48], 1
// 00577b96  0f84e5030000         je 0x577f81
// 00577b9c  85f6                 test esi, esi
// 00577b9e  0f84dd030000         je 0x577f81
// 00577ba4  8b549430             mov edx, dword ptr [esp + edx*4 + 0x30]
// 00577ba8  8b06                 mov eax, dword ptr [esi]
// 00577baa  0fb6760b             movzx esi, byte ptr [esi + 0xb]
// 00577bae  55                   push ebp
// 00577baf  8be8                 mov ebp, eax
// 00577bb1  0fafea               imul ebp, edx
// 00577bb4  89542418             mov dword ptr [esp + 0x18], edx
// 00577bb8  8bd6                 mov edx, esi
// 00577bba  83ea01               sub edx, 1
// 00577bbd  896c2410             mov dword ptr [esp + 0x10], ebp
// 00577bc1  0f84a3020000         je 0x577e6a
// 00577bc7  83ea01               sub edx, 1
// 00577bca  0f849e010000         je 0x577d6e
// 00577bd0  2bd7                 sub edx, edi
// 00577bd2  8d7dff               lea edi, [ebp - 1]
// 00577bd5  746b                 je 0x577c42
// 00577bd7  c1ee03               shr esi, 3
// 00577bda  8d58ff               lea ebx, [eax - 1]
// 00577bdd  0faffe               imul edi, esi
// 00577be0  0fafde               imul ebx, esi
// 00577be3  03d9                 add ebx, ecx
// 00577be5  03f9                 add edi, ecx
// 00577be7  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00577bef  85c0                 test eax, eax
// 00577bf1  0f8652010000         jbe 0x577d49
// 00577bf7  56                   push esi
// 00577bf8  8d442430             lea eax, [esp + 0x30]
// 00577bfc  53                   push ebx
// 00577bfd  50                   push eax
// 00577bfe  e823122300           call 0x7a8e26
// 00577c03  8b442424             mov eax, dword ptr [esp + 0x24]
// 00577c07  83c40c               add esp, 0xc
// 00577c0a  85c0                 test eax, eax
// 00577c0c  7e1c                 jle 0x577c2a
// 00577c0e  8be8                 mov ebp, eax
// 00577c10  56                   push esi
// 00577c11  8d4c2430             lea ecx, [esp + 0x30]
// 00577c15  51                   push ecx
// 00577c16  57                   push edi
// 00577c17  e80a122300           call 0x7a8e26
// 00577c1c  83c40c               add esp, 0xc
// 00577c1f  2bfe                 sub edi, esi
// 00577c21  83ed01               sub ebp, 1
// 00577c24  75ea                 jne 0x577c10
// 00577c26  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00577c2a  8b442454             mov eax, dword ptr [esp + 0x54]
// 00577c2e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00577c32  40                   inc eax
// 00577c33  2bde                 sub ebx, esi
// 00577c35  89442454             mov dword ptr [esp + 0x54], eax
// 00577c39  3b02                 cmp eax, dword ptr [edx]
// 00577c3b  72ba                 jb 0x577bf7
// 00577c3d  e907010000           jmp 0x577d49
// 00577c42  8d50ff               lea edx, [eax - 1]
// 00577c45  d1ea                 shr edx, 1
// 00577c47  d1ef                 shr edi, 1
// 00577c49  03d1                 add edx, ecx
// 00577c4b  03f9                 add edi, ecx
// 00577c4d  89542420             mov dword ptr [esp + 0x20], edx
// 00577c51  f7c300000100         test ebx, 0x10000
// 00577c57  7432                 je 0x577c8b
// 00577c59  83caff               or edx, 0xffffffff
// 00577c5c  8d0c8500000000       lea ecx, [eax*4]
// 00577c63  2bd1                 sub edx, ecx
// 00577c65  83ceff               or esi, 0xffffffff
// 00577c68  8d0cad00000000       lea ecx, [ebp*4]
// 00577c6f  2bf1                 sub esi, ecx
// 00577c71  83e204               and edx, 4
// 00577c74  83e604               and esi, 4
// 00577c77  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 00577c7f  33ed                 xor ebp, ebp
// 00577c81  c7442424fcffffff     mov dword ptr [esp + 0x24], 0xfffffffc
// 00577c89  eb33                 jmp 0x577cbe
// 00577c8b  8d50ff               lea edx, [eax - 1]
// 00577c8e  83e201               and edx, 1
// 00577c91  4d                   dec ebp
// 00577c92  03d2                 add edx, edx
// 00577c94  03d2                 add edx, edx
// 00577c96  83e501               and ebp, 1
// 00577c99  03ed                 add ebp, ebp
// 00577c9b  8bca                 mov ecx, edx
// 00577c9d  ba04000000           mov edx, 4
// 00577ca2  03ed                 add ebp, ebp
// 00577ca4  be04000000           mov esi, 4
// 00577ca9  2bd1                 sub edx, ecx
// 00577cab  2bf5                 sub esi, ebp
// 00577cad  bd04000000           mov ebp, 4
// 00577cb2  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00577cba  896c2424             mov dword ptr [esp + 0x24], ebp
// 00577cbe  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00577cc6  85c0                 test eax, eax
// 00577cc8  767b                 jbe 0x577d45
// 00577cca  8d9b00000000         lea ebx, [ebx]
// 00577cd0  8b442420             mov eax, dword ptr [esp + 0x20]
// 00577cd4  8a00                 mov al, byte ptr [eax]
// 00577cd6  8aca                 mov cl, dl
// 00577cd8  d2e8                 shr al, cl
// 00577cda  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00577cde  240f                 and al, 0xf
// 00577ce0  88442454             mov byte ptr [esp + 0x54], al
// 00577ce4  85c9                 test ecx, ecx
// 00577ce6  7e3a                 jle 0x577d22
// 00577ce8  894c2428             mov dword ptr [esp + 0x28], ecx
// 00577cec  eb06                 jmp 0x577cf4
// 00577cee  8bff                 mov edi, edi
// 00577cf0  8a442454             mov al, byte ptr [esp + 0x54]
// 00577cf4  b904000000           mov ecx, 4
// 00577cf9  2bce                 sub ecx, esi
// 00577cfb  bb0f0f0000           mov ebx, 0xf0f
// 00577d00  d3fb                 sar ebx, cl
// 00577d02  8bce                 mov ecx, esi
// 00577d04  d2e0                 shl al, cl
// 00577d06  221f                 and bl, byte ptr [edi]
// 00577d08  0ad8                 or bl, al
// 00577d0a  881f                 mov byte ptr [edi], bl
// 00577d0c  3bf5                 cmp esi, ebp
// 00577d0e  7507                 jne 0x577d17
// 00577d10  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00577d14  4f                   dec edi
// 00577d15  eb04                 jmp 0x577d1b
// 00577d17  03742424             add esi, dword ptr [esp + 0x24]
// 00577d1b  836c242801           sub dword ptr [esp + 0x28], 1
// 00577d20  75ce                 jne 0x577cf0
// 00577d22  3bd5                 cmp edx, ebp
// 00577d24  750a                 jne 0x577d30
// 00577d26  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00577d2a  ff4c2420             dec dword ptr [esp + 0x20]
// 00577d2e  eb04                 jmp 0x577d34
// 00577d30  03542424             add edx, dword ptr [esp + 0x24]
// 00577d34  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00577d38  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00577d3c  40                   inc eax
// 00577d3d  8944242c             mov dword ptr [esp + 0x2c], eax
// 00577d41  3b01                 cmp eax, dword ptr [ecx]
// 00577d43  728b                 jb 0x577cd0
// 00577d45  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00577d49  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00577d4d  8a410b               mov al, byte ptr [ecx + 0xb]
// 00577d50  3c08                 cmp al, 8
// 00577d52  8929                 mov dword ptr [ecx], ebp
// 00577d54  0fb6c0               movzx eax, al
// 00577d57  0f8217020000         jb 0x577f74
// 00577d5d  c1e803               shr eax, 3
// 00577d60  0fafc5               imul eax, ebp
// 00577d63  5d                   pop ebp
// 00577d64  5f                   pop edi
// 00577d65  5e                   pop esi
// 00577d66  894104               mov dword ptr [ecx + 4], eax
// 00577d69  5b                   pop ebx
// 00577d6a  83c440               add esp, 0x40
// 00577d6d  c3                   ret 
// 00577d6e  8d50ff               lea edx, [eax - 1]
// 00577d71  8d7dff               lea edi, [ebp - 1]
// 00577d74  c1ea02               shr edx, 2
// 00577d77  c1ef02               shr edi, 2
// 00577d7a  03d1                 add edx, ecx
// 00577d7c  03f9                 add edi, ecx
// 00577d7e  89542420             mov dword ptr [esp + 0x20], edx
// 00577d82  f7c300000100         test ebx, 0x10000
// 00577d88  7422                 je 0x577dac
// 00577d8a  8d742dff             lea esi, [ebp + ebp - 1]
// 00577d8e  8d5400ff             lea edx, [eax + eax - 1]
// 00577d92  83e206               and edx, 6
// 00577d95  83e606               and esi, 6
// 00577d98  c744242406000000     mov dword ptr [esp + 0x24], 6
// 00577da0  33ed                 xor ebp, ebp
// 00577da2  c744241cfeffffff     mov dword ptr [esp + 0x1c], 0xfffffffe
// 00577daa  eb31                 jmp 0x577ddd
// 00577dac  4d                   dec ebp
// 00577dad  8d48ff               lea ecx, [eax - 1]
// 00577db0  83e103               and ecx, 3
// 00577db3  83e503               and ebp, 3
// 00577db6  ba03000000           mov edx, 3
// 00577dbb  2bd1                 sub edx, ecx
// 00577dbd  be03000000           mov esi, 3
// 00577dc2  2bf5                 sub esi, ebp
// 00577dc4  03d2                 add edx, edx
// 00577dc6  03f6                 add esi, esi
// 00577dc8  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00577dd0  bd06000000           mov ebp, 6
// 00577dd5  c744241c02000000     mov dword ptr [esp + 0x1c], 2
// 00577ddd  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00577de5  85c0                 test eax, eax
// 00577de7  0f8658ffffff         jbe 0x577d45
// 00577ded  8d4900               lea ecx, [ecx]
// 00577df0  8b442420             mov eax, dword ptr [esp + 0x20]
// 00577df4  8a00                 mov al, byte ptr [eax]
// 00577df6  8aca                 mov cl, dl
// 00577df8  d2e8                 shr al, cl
// 00577dfa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00577dfe  2403                 and al, 3
// 00577e00  88442454             mov byte ptr [esp + 0x54], al
// 00577e04  85c9                 test ecx, ecx
// 00577e06  7e3a                 jle 0x577e42
// 00577e08  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00577e0c  eb06                 jmp 0x577e14
// 00577e0e  8bff                 mov edi, edi
// 00577e10  8a442454             mov al, byte ptr [esp + 0x54]
// 00577e14  b906000000           mov ecx, 6
// 00577e19  2bce                 sub ecx, esi
// 00577e1b  bb3f3f0000           mov ebx, 0x3f3f
// 00577e20  d3fb                 sar ebx, cl
// 00577e22  8bce                 mov ecx, esi
// 00577e24  d2e0                 shl al, cl
// 00577e26  221f                 and bl, byte ptr [edi]
// 00577e28  0ad8                 or bl, al
// 00577e2a  881f                 mov byte ptr [edi], bl
// 00577e2c  3bf5                 cmp esi, ebp
// 00577e2e  7507                 jne 0x577e37
// 00577e30  8b742424             mov esi, dword ptr [esp + 0x24]
// 00577e34  4f                   dec edi
// 00577e35  eb04                 jmp 0x577e3b
// 00577e37  0374241c             add esi, dword ptr [esp + 0x1c]
// 00577e3b  836c242c01           sub dword ptr [esp + 0x2c], 1
// 00577e40  75ce                 jne 0x577e10
// 00577e42  3bd5                 cmp edx, ebp
// 00577e44  750a                 jne 0x577e50
// 00577e46  8b542424             mov edx, dword ptr [esp + 0x24]
// 00577e4a  ff4c2420             dec dword ptr [esp + 0x20]
// 00577e4e  eb04                 jmp 0x577e54
// 00577e50  0354241c             add edx, dword ptr [esp + 0x1c]
// 00577e54  8b442428             mov eax, dword ptr [esp + 0x28]
// 00577e58  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00577e5c  40                   inc eax
// 00577e5d  89442428             mov dword ptr [esp + 0x28], eax
// 00577e61  3b01                 cmp eax, dword ptr [ecx]
// 00577e63  728b                 jb 0x577df0
// 00577e65  e9dbfeffff           jmp 0x577d45
// 00577e6a  8d50ff               lea edx, [eax - 1]
// 00577e6d  8d7dff               lea edi, [ebp - 1]
// 00577e70  c1ea03               shr edx, 3
// 00577e73  c1ef03               shr edi, 3
// 00577e76  03d1                 add edx, ecx
// 00577e78  03f9                 add edi, ecx
// 00577e7a  8954241c             mov dword ptr [esp + 0x1c], edx
// 00577e7e  f7c300000100         test ebx, 0x10000
// 00577e84  7426                 je 0x577eac
// 00577e86  8d50ff               lea edx, [eax - 1]
// 00577e89  8d75ff               lea esi, [ebp - 1]
// 00577e8c  83e207               and edx, 7
// 00577e8f  83e607               and esi, 7
// 00577e92  c744242007000000     mov dword ptr [esp + 0x20], 7
// 00577e9a  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00577ea2  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00577eaa  eb32                 jmp 0x577ede
// 00577eac  8d48ff               lea ecx, [eax - 1]
// 00577eaf  83e107               and ecx, 7
// 00577eb2  ba07000000           mov edx, 7
// 00577eb7  2bd1                 sub edx, ecx
// 00577eb9  8d4dff               lea ecx, [ebp - 1]
// 00577ebc  83e107               and ecx, 7
// 00577ebf  be07000000           mov esi, 7
// 00577ec4  2bf1                 sub esi, ecx
// 00577ec6  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00577ece  c744242407000000     mov dword ptr [esp + 0x24], 7
// 00577ed6  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00577ede  89542454             mov dword ptr [esp + 0x54], edx
// 00577ee2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00577eea  85c0                 test eax, eax
// 00577eec  0f8657feffff         jbe 0x577d49
// 00577ef2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00577ef6  8a00                 mov al, byte ptr [eax]
// 00577ef8  8aca                 mov cl, dl
// 00577efa  d2e8                 shr al, cl
// 00577efc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00577f00  2401                 and al, 1
// 00577f02  85c9                 test ecx, ecx
// 00577f04  7e40                 jle 0x577f46
// 00577f06  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00577f0a  8d9b00000000         lea ebx, [ebx]
// 00577f10  b907000000           mov ecx, 7
// 00577f15  2bce                 sub ecx, esi
// 00577f17  ba7f7f0000           mov edx, 0x7f7f
// 00577f1c  d3fa                 sar edx, cl
// 00577f1e  8ad8                 mov bl, al
// 00577f20  8bce                 mov ecx, esi
// 00577f22  d2e3                 shl bl, cl
// 00577f24  2217                 and dl, byte ptr [edi]
// 00577f26  0ad3                 or dl, bl
// 00577f28  8817                 mov byte ptr [edi], dl
// 00577f2a  3b742424             cmp esi, dword ptr [esp + 0x24]
// 00577f2e  7507                 jne 0x577f37
// 00577f30  8b742420             mov esi, dword ptr [esp + 0x20]
// 00577f34  4f                   dec edi
// 00577f35  eb04                 jmp 0x577f3b
// 00577f37  03742410             add esi, dword ptr [esp + 0x10]
// 00577f3b  836c242c01           sub dword ptr [esp + 0x2c], 1
// 00577f40  75ce                 jne 0x577f10
// 00577f42  8b542454             mov edx, dword ptr [esp + 0x54]
// 00577f46  3b542424             cmp edx, dword ptr [esp + 0x24]
// 00577f4a  750a                 jne 0x577f56
// 00577f4c  8b542420             mov edx, dword ptr [esp + 0x20]
// 00577f50  ff4c241c             dec dword ptr [esp + 0x1c]
// 00577f54  eb04                 jmp 0x577f5a
// 00577f56  03542410             add edx, dword ptr [esp + 0x10]
// 00577f5a  8b442428             mov eax, dword ptr [esp + 0x28]
// 00577f5e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00577f62  40                   inc eax
// 00577f63  89542454             mov dword ptr [esp + 0x54], edx
// 00577f67  89442428             mov dword ptr [esp + 0x28], eax
// 00577f6b  3b01                 cmp eax, dword ptr [ecx]
// 00577f6d  7283                 jb 0x577ef2
// 00577f6f  e9d5fdffff           jmp 0x577d49
// 00577f74  0fafc5               imul eax, ebp
// 00577f77  83c007               add eax, 7
// 00577f7a  c1e803               shr eax, 3
// 00577f7d  894104               mov dword ptr [ecx + 4], eax
// 00577f80  5d                   pop ebp
// 00577f81  5f                   pop edi
// 00577f82  5e                   pop esi
// 00577f83  5b                   pop ebx
// 00577f84  83c440               add esp, 0x40
// 00577f87  c3                   ret 
// library libpng-1.2.22/pngrutil.c (function _png_do_read_interlace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrutil.c
