// from server: 100% by auto
// roc 2011-06 0056ee60  unit: seg_00560000  size: 1096 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056ee60
//
// 0056ee60  83ec40               sub esp, 0x40
// 0056ee63  8b442444             mov eax, dword ptr [esp + 0x44]
// 0056ee67  8b88ec000000         mov ecx, dword ptr [eax + 0xec]
// 0056ee6d  83c101               add ecx, 1
// 0056ee70  0fb69024010000       movzx edx, byte ptr [eax + 0x124]
// 0056ee77  53                   push ebx
// 0056ee78  8b5870               mov ebx, dword ptr [eax + 0x70]
// 0056ee7b  56                   push esi
// 0056ee7c  8db000010000         lea esi, [eax + 0x100]
// 0056ee82  b808000000           mov eax, 8
// 0056ee87  57                   push edi
// 0056ee88  89442430             mov dword ptr [esp + 0x30], eax
// 0056ee8c  89442434             mov dword ptr [esp + 0x34], eax
// 0056ee90  b804000000           mov eax, 4
// 0056ee95  bf02000000           mov edi, 2
// 0056ee9a  89742410             mov dword ptr [esp + 0x10], esi
// 0056ee9e  89442438             mov dword ptr [esp + 0x38], eax
// 0056eea2  8944243c             mov dword ptr [esp + 0x3c], eax
// 0056eea6  897c2440             mov dword ptr [esp + 0x40], edi
// 0056eeaa  897c2444             mov dword ptr [esp + 0x44], edi
// 0056eeae  c744244801000000     mov dword ptr [esp + 0x48], 1
// 0056eeb6  0f84e5030000         je 0x56f2a1
// 0056eebc  85f6                 test esi, esi
// 0056eebe  0f84dd030000         je 0x56f2a1
// 0056eec4  8b549430             mov edx, dword ptr [esp + edx*4 + 0x30]
// 0056eec8  8b06                 mov eax, dword ptr [esi]
// 0056eeca  0fb6760b             movzx esi, byte ptr [esi + 0xb]
// 0056eece  55                   push ebp
// 0056eecf  8be8                 mov ebp, eax
// 0056eed1  0fafea               imul ebp, edx
// 0056eed4  89542418             mov dword ptr [esp + 0x18], edx
// 0056eed8  8bd6                 mov edx, esi
// 0056eeda  83ea01               sub edx, 1
// 0056eedd  896c2410             mov dword ptr [esp + 0x10], ebp
// 0056eee1  0f84a3020000         je 0x56f18a
// 0056eee7  83ea01               sub edx, 1
// 0056eeea  0f849e010000         je 0x56f08e
// 0056eef0  2bd7                 sub edx, edi
// 0056eef2  8d7dff               lea edi, [ebp - 1]
// 0056eef5  746b                 je 0x56ef62
// 0056eef7  c1ee03               shr esi, 3
// 0056eefa  8d58ff               lea ebx, [eax - 1]
// 0056eefd  0faffe               imul edi, esi
// 0056ef00  0fafde               imul ebx, esi
// 0056ef03  03d9                 add ebx, ecx
// 0056ef05  03f9                 add edi, ecx
// 0056ef07  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0056ef0f  85c0                 test eax, eax
// 0056ef11  0f8652010000         jbe 0x56f069
// 0056ef17  56                   push esi
// 0056ef18  8d442430             lea eax, [esp + 0x30]
// 0056ef1c  53                   push ebx
// 0056ef1d  50                   push eax
// 0056ef1e  e8b9c62900           call 0x80b5dc
// 0056ef23  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056ef27  83c40c               add esp, 0xc
// 0056ef2a  85c0                 test eax, eax
// 0056ef2c  7e1c                 jle 0x56ef4a
// 0056ef2e  8be8                 mov ebp, eax
// 0056ef30  56                   push esi
// 0056ef31  8d4c2430             lea ecx, [esp + 0x30]
// 0056ef35  51                   push ecx
// 0056ef36  57                   push edi
// 0056ef37  e8a0c62900           call 0x80b5dc
// 0056ef3c  83c40c               add esp, 0xc
// 0056ef3f  2bfe                 sub edi, esi
// 0056ef41  83ed01               sub ebp, 1
// 0056ef44  75ea                 jne 0x56ef30
// 0056ef46  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0056ef4a  8b442454             mov eax, dword ptr [esp + 0x54]
// 0056ef4e  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056ef52  40                   inc eax
// 0056ef53  2bde                 sub ebx, esi
// 0056ef55  89442454             mov dword ptr [esp + 0x54], eax
// 0056ef59  3b02                 cmp eax, dword ptr [edx]
// 0056ef5b  72ba                 jb 0x56ef17
// 0056ef5d  e907010000           jmp 0x56f069
// 0056ef62  8d50ff               lea edx, [eax - 1]
// 0056ef65  d1ea                 shr edx, 1
// 0056ef67  d1ef                 shr edi, 1
// 0056ef69  03d1                 add edx, ecx
// 0056ef6b  03f9                 add edi, ecx
// 0056ef6d  89542420             mov dword ptr [esp + 0x20], edx
// 0056ef71  f7c300000100         test ebx, 0x10000
// 0056ef77  7432                 je 0x56efab
// 0056ef79  83caff               or edx, 0xffffffff
// 0056ef7c  8d0c8500000000       lea ecx, [eax*4]
// 0056ef83  2bd1                 sub edx, ecx
// 0056ef85  83ceff               or esi, 0xffffffff
// 0056ef88  8d0cad00000000       lea ecx, [ebp*4]
// 0056ef8f  2bf1                 sub esi, ecx
// 0056ef91  83e204               and edx, 4
// 0056ef94  83e604               and esi, 4
// 0056ef97  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 0056ef9f  33ed                 xor ebp, ebp
// 0056efa1  c7442424fcffffff     mov dword ptr [esp + 0x24], 0xfffffffc
// 0056efa9  eb33                 jmp 0x56efde
// 0056efab  8d50ff               lea edx, [eax - 1]
// 0056efae  83e201               and edx, 1
// 0056efb1  4d                   dec ebp
// 0056efb2  03d2                 add edx, edx
// 0056efb4  03d2                 add edx, edx
// 0056efb6  83e501               and ebp, 1
// 0056efb9  03ed                 add ebp, ebp
// 0056efbb  8bca                 mov ecx, edx
// 0056efbd  ba04000000           mov edx, 4
// 0056efc2  03ed                 add ebp, ebp
// 0056efc4  be04000000           mov esi, 4
// 0056efc9  2bd1                 sub edx, ecx
// 0056efcb  2bf5                 sub esi, ebp
// 0056efcd  bd04000000           mov ebp, 4
// 0056efd2  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0056efda  896c2424             mov dword ptr [esp + 0x24], ebp
// 0056efde  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0056efe6  85c0                 test eax, eax
// 0056efe8  767b                 jbe 0x56f065
// 0056efea  8d9b00000000         lea ebx, [ebx]
// 0056eff0  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056eff4  8a00                 mov al, byte ptr [eax]
// 0056eff6  8aca                 mov cl, dl
// 0056eff8  d2e8                 shr al, cl
// 0056effa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056effe  240f                 and al, 0xf
// 0056f000  88442454             mov byte ptr [esp + 0x54], al
// 0056f004  85c9                 test ecx, ecx
// 0056f006  7e3a                 jle 0x56f042
// 0056f008  894c2428             mov dword ptr [esp + 0x28], ecx
// 0056f00c  eb06                 jmp 0x56f014
// 0056f00e  8bff                 mov edi, edi
// 0056f010  8a442454             mov al, byte ptr [esp + 0x54]
// 0056f014  b904000000           mov ecx, 4
// 0056f019  2bce                 sub ecx, esi
// 0056f01b  bb0f0f0000           mov ebx, 0xf0f
// 0056f020  d3fb                 sar ebx, cl
// 0056f022  8bce                 mov ecx, esi
// 0056f024  d2e0                 shl al, cl
// 0056f026  221f                 and bl, byte ptr [edi]
// 0056f028  0ad8                 or bl, al
// 0056f02a  881f                 mov byte ptr [edi], bl
// 0056f02c  3bf5                 cmp esi, ebp
// 0056f02e  7507                 jne 0x56f037
// 0056f030  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0056f034  4f                   dec edi
// 0056f035  eb04                 jmp 0x56f03b
// 0056f037  03742424             add esi, dword ptr [esp + 0x24]
// 0056f03b  836c242801           sub dword ptr [esp + 0x28], 1
// 0056f040  75ce                 jne 0x56f010
// 0056f042  3bd5                 cmp edx, ebp
// 0056f044  750a                 jne 0x56f050
// 0056f046  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0056f04a  ff4c2420             dec dword ptr [esp + 0x20]
// 0056f04e  eb04                 jmp 0x56f054
// 0056f050  03542424             add edx, dword ptr [esp + 0x24]
// 0056f054  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0056f058  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056f05c  40                   inc eax
// 0056f05d  8944242c             mov dword ptr [esp + 0x2c], eax
// 0056f061  3b01                 cmp eax, dword ptr [ecx]
// 0056f063  728b                 jb 0x56eff0
// 0056f065  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0056f069  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056f06d  8a410b               mov al, byte ptr [ecx + 0xb]
// 0056f070  3c08                 cmp al, 8
// 0056f072  8929                 mov dword ptr [ecx], ebp
// 0056f074  0fb6c0               movzx eax, al
// 0056f077  0f8217020000         jb 0x56f294
// 0056f07d  c1e803               shr eax, 3
// 0056f080  0fafc5               imul eax, ebp
// 0056f083  5d                   pop ebp
// 0056f084  5f                   pop edi
// 0056f085  5e                   pop esi
// 0056f086  894104               mov dword ptr [ecx + 4], eax
// 0056f089  5b                   pop ebx
// 0056f08a  83c440               add esp, 0x40
// 0056f08d  c3                   ret 
// 0056f08e  8d50ff               lea edx, [eax - 1]
// 0056f091  8d7dff               lea edi, [ebp - 1]
// 0056f094  c1ea02               shr edx, 2
// 0056f097  c1ef02               shr edi, 2
// 0056f09a  03d1                 add edx, ecx
// 0056f09c  03f9                 add edi, ecx
// 0056f09e  89542420             mov dword ptr [esp + 0x20], edx
// 0056f0a2  f7c300000100         test ebx, 0x10000
// 0056f0a8  7422                 je 0x56f0cc
// 0056f0aa  8d742dff             lea esi, [ebp + ebp - 1]
// 0056f0ae  8d5400ff             lea edx, [eax + eax - 1]
// 0056f0b2  83e206               and edx, 6
// 0056f0b5  83e606               and esi, 6
// 0056f0b8  c744242406000000     mov dword ptr [esp + 0x24], 6
// 0056f0c0  33ed                 xor ebp, ebp
// 0056f0c2  c744241cfeffffff     mov dword ptr [esp + 0x1c], 0xfffffffe
// 0056f0ca  eb31                 jmp 0x56f0fd
// 0056f0cc  4d                   dec ebp
// 0056f0cd  8d48ff               lea ecx, [eax - 1]
// 0056f0d0  83e103               and ecx, 3
// 0056f0d3  83e503               and ebp, 3
// 0056f0d6  ba03000000           mov edx, 3
// 0056f0db  2bd1                 sub edx, ecx
// 0056f0dd  be03000000           mov esi, 3
// 0056f0e2  2bf5                 sub esi, ebp
// 0056f0e4  03d2                 add edx, edx
// 0056f0e6  03f6                 add esi, esi
// 0056f0e8  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0056f0f0  bd06000000           mov ebp, 6
// 0056f0f5  c744241c02000000     mov dword ptr [esp + 0x1c], 2
// 0056f0fd  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0056f105  85c0                 test eax, eax
// 0056f107  0f8658ffffff         jbe 0x56f065
// 0056f10d  8d4900               lea ecx, [ecx]
// 0056f110  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056f114  8a00                 mov al, byte ptr [eax]
// 0056f116  8aca                 mov cl, dl
// 0056f118  d2e8                 shr al, cl
// 0056f11a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056f11e  2403                 and al, 3
// 0056f120  88442454             mov byte ptr [esp + 0x54], al
// 0056f124  85c9                 test ecx, ecx
// 0056f126  7e3a                 jle 0x56f162
// 0056f128  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0056f12c  eb06                 jmp 0x56f134
// 0056f12e  8bff                 mov edi, edi
// 0056f130  8a442454             mov al, byte ptr [esp + 0x54]
// 0056f134  b906000000           mov ecx, 6
// 0056f139  2bce                 sub ecx, esi
// 0056f13b  bb3f3f0000           mov ebx, 0x3f3f
// 0056f140  d3fb                 sar ebx, cl
// 0056f142  8bce                 mov ecx, esi
// 0056f144  d2e0                 shl al, cl
// 0056f146  221f                 and bl, byte ptr [edi]
// 0056f148  0ad8                 or bl, al
// 0056f14a  881f                 mov byte ptr [edi], bl
// 0056f14c  3bf5                 cmp esi, ebp
// 0056f14e  7507                 jne 0x56f157
// 0056f150  8b742424             mov esi, dword ptr [esp + 0x24]
// 0056f154  4f                   dec edi
// 0056f155  eb04                 jmp 0x56f15b
// 0056f157  0374241c             add esi, dword ptr [esp + 0x1c]
// 0056f15b  836c242c01           sub dword ptr [esp + 0x2c], 1
// 0056f160  75ce                 jne 0x56f130
// 0056f162  3bd5                 cmp edx, ebp
// 0056f164  750a                 jne 0x56f170
// 0056f166  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f16a  ff4c2420             dec dword ptr [esp + 0x20]
// 0056f16e  eb04                 jmp 0x56f174
// 0056f170  0354241c             add edx, dword ptr [esp + 0x1c]
// 0056f174  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056f178  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056f17c  40                   inc eax
// 0056f17d  89442428             mov dword ptr [esp + 0x28], eax
// 0056f181  3b01                 cmp eax, dword ptr [ecx]
// 0056f183  728b                 jb 0x56f110
// 0056f185  e9dbfeffff           jmp 0x56f065
// 0056f18a  8d50ff               lea edx, [eax - 1]
// 0056f18d  8d7dff               lea edi, [ebp - 1]
// 0056f190  c1ea03               shr edx, 3
// 0056f193  c1ef03               shr edi, 3
// 0056f196  03d1                 add edx, ecx
// 0056f198  03f9                 add edi, ecx
// 0056f19a  8954241c             mov dword ptr [esp + 0x1c], edx
// 0056f19e  f7c300000100         test ebx, 0x10000
// 0056f1a4  7426                 je 0x56f1cc
// 0056f1a6  8d50ff               lea edx, [eax - 1]
// 0056f1a9  8d75ff               lea esi, [ebp - 1]
// 0056f1ac  83e207               and edx, 7
// 0056f1af  83e607               and esi, 7
// 0056f1b2  c744242007000000     mov dword ptr [esp + 0x20], 7
// 0056f1ba  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0056f1c2  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0056f1ca  eb32                 jmp 0x56f1fe
// 0056f1cc  8d48ff               lea ecx, [eax - 1]
// 0056f1cf  83e107               and ecx, 7
// 0056f1d2  ba07000000           mov edx, 7
// 0056f1d7  2bd1                 sub edx, ecx
// 0056f1d9  8d4dff               lea ecx, [ebp - 1]
// 0056f1dc  83e107               and ecx, 7
// 0056f1df  be07000000           mov esi, 7
// 0056f1e4  2bf1                 sub esi, ecx
// 0056f1e6  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0056f1ee  c744242407000000     mov dword ptr [esp + 0x24], 7
// 0056f1f6  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0056f1fe  89542454             mov dword ptr [esp + 0x54], edx
// 0056f202  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0056f20a  85c0                 test eax, eax
// 0056f20c  0f8657feffff         jbe 0x56f069
// 0056f212  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056f216  8a00                 mov al, byte ptr [eax]
// 0056f218  8aca                 mov cl, dl
// 0056f21a  d2e8                 shr al, cl
// 0056f21c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056f220  2401                 and al, 1
// 0056f222  85c9                 test ecx, ecx
// 0056f224  7e40                 jle 0x56f266
// 0056f226  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0056f22a  8d9b00000000         lea ebx, [ebx]
// 0056f230  b907000000           mov ecx, 7
// 0056f235  2bce                 sub ecx, esi
// 0056f237  ba7f7f0000           mov edx, 0x7f7f
// 0056f23c  d3fa                 sar edx, cl
// 0056f23e  8ad8                 mov bl, al
// 0056f240  8bce                 mov ecx, esi
// 0056f242  d2e3                 shl bl, cl
// 0056f244  2217                 and dl, byte ptr [edi]
// 0056f246  0ad3                 or dl, bl
// 0056f248  8817                 mov byte ptr [edi], dl
// 0056f24a  3b742424             cmp esi, dword ptr [esp + 0x24]
// 0056f24e  7507                 jne 0x56f257
// 0056f250  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056f254  4f                   dec edi
// 0056f255  eb04                 jmp 0x56f25b
// 0056f257  03742410             add esi, dword ptr [esp + 0x10]
// 0056f25b  836c242c01           sub dword ptr [esp + 0x2c], 1
// 0056f260  75ce                 jne 0x56f230
// 0056f262  8b542454             mov edx, dword ptr [esp + 0x54]
// 0056f266  3b542424             cmp edx, dword ptr [esp + 0x24]
// 0056f26a  750a                 jne 0x56f276
// 0056f26c  8b542420             mov edx, dword ptr [esp + 0x20]
// 0056f270  ff4c241c             dec dword ptr [esp + 0x1c]
// 0056f274  eb04                 jmp 0x56f27a
// 0056f276  03542410             add edx, dword ptr [esp + 0x10]
// 0056f27a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056f27e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056f282  40                   inc eax
// 0056f283  89542454             mov dword ptr [esp + 0x54], edx
// 0056f287  89442428             mov dword ptr [esp + 0x28], eax
// 0056f28b  3b01                 cmp eax, dword ptr [ecx]
// 0056f28d  7283                 jb 0x56f212
// 0056f28f  e9d5fdffff           jmp 0x56f069
// 0056f294  0fafc5               imul eax, ebp
// 0056f297  83c007               add eax, 7
// 0056f29a  c1e803               shr eax, 3
// 0056f29d  894104               mov dword ptr [ecx + 4], eax
// 0056f2a0  5d                   pop ebp
// 0056f2a1  5f                   pop edi
// 0056f2a2  5e                   pop esi
// 0056f2a3  5b                   pop ebx
// 0056f2a4  83c440               add esp, 0x40
// 0056f2a7  c3                   ret 
// library libpng-1.2.22/pngrutil.c (function _png_do_read_interlace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrutil.c
