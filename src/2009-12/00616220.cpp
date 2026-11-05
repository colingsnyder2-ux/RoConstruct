// from server: 100% by auto
// roc 2009-12 00616220  unit: seg_00610000  size: 1096 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00616220
//
// 00616220  83ec40               sub esp, 0x40
// 00616223  8b442444             mov eax, dword ptr [esp + 0x44]
// 00616227  8b88ec000000         mov ecx, dword ptr [eax + 0xec]
// 0061622d  83c101               add ecx, 1
// 00616230  0fb69024010000       movzx edx, byte ptr [eax + 0x124]
// 00616237  53                   push ebx
// 00616238  8b5870               mov ebx, dword ptr [eax + 0x70]
// 0061623b  56                   push esi
// 0061623c  8db000010000         lea esi, [eax + 0x100]
// 00616242  b808000000           mov eax, 8
// 00616247  57                   push edi
// 00616248  89442430             mov dword ptr [esp + 0x30], eax
// 0061624c  89442434             mov dword ptr [esp + 0x34], eax
// 00616250  b804000000           mov eax, 4
// 00616255  bf02000000           mov edi, 2
// 0061625a  89742410             mov dword ptr [esp + 0x10], esi
// 0061625e  89442438             mov dword ptr [esp + 0x38], eax
// 00616262  8944243c             mov dword ptr [esp + 0x3c], eax
// 00616266  897c2440             mov dword ptr [esp + 0x40], edi
// 0061626a  897c2444             mov dword ptr [esp + 0x44], edi
// 0061626e  c744244801000000     mov dword ptr [esp + 0x48], 1
// 00616276  0f84e5030000         je 0x616661
// 0061627c  85f6                 test esi, esi
// 0061627e  0f84dd030000         je 0x616661
// 00616284  8b549430             mov edx, dword ptr [esp + edx*4 + 0x30]
// 00616288  8b06                 mov eax, dword ptr [esi]
// 0061628a  0fb6760b             movzx esi, byte ptr [esi + 0xb]
// 0061628e  55                   push ebp
// 0061628f  8be8                 mov ebp, eax
// 00616291  0fafea               imul ebp, edx
// 00616294  89542418             mov dword ptr [esp + 0x18], edx
// 00616298  8bd6                 mov edx, esi
// 0061629a  83ea01               sub edx, 1
// 0061629d  896c2410             mov dword ptr [esp + 0x10], ebp
// 006162a1  0f84a3020000         je 0x61654a
// 006162a7  83ea01               sub edx, 1
// 006162aa  0f849e010000         je 0x61644e
// 006162b0  2bd7                 sub edx, edi
// 006162b2  8d7dff               lea edi, [ebp - 1]
// 006162b5  746b                 je 0x616322
// 006162b7  c1ee03               shr esi, 3
// 006162ba  8d58ff               lea ebx, [eax - 1]
// 006162bd  0faffe               imul edi, esi
// 006162c0  0fafde               imul ebx, esi
// 006162c3  03d9                 add ebx, ecx
// 006162c5  03f9                 add edi, ecx
// 006162c7  c744245400000000     mov dword ptr [esp + 0x54], 0
// 006162cf  85c0                 test eax, eax
// 006162d1  0f8652010000         jbe 0x616429
// 006162d7  56                   push esi
// 006162d8  8d442430             lea eax, [esp + 0x30]
// 006162dc  53                   push ebx
// 006162dd  50                   push eax
// 006162de  e803ea1d00           call 0x7f4ce6
// 006162e3  8b442424             mov eax, dword ptr [esp + 0x24]
// 006162e7  83c40c               add esp, 0xc
// 006162ea  85c0                 test eax, eax
// 006162ec  7e1c                 jle 0x61630a
// 006162ee  8be8                 mov ebp, eax
// 006162f0  56                   push esi
// 006162f1  8d4c2430             lea ecx, [esp + 0x30]
// 006162f5  51                   push ecx
// 006162f6  57                   push edi
// 006162f7  e8eae91d00           call 0x7f4ce6
// 006162fc  83c40c               add esp, 0xc
// 006162ff  2bfe                 sub edi, esi
// 00616301  83ed01               sub ebp, 1
// 00616304  75ea                 jne 0x6162f0
// 00616306  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0061630a  8b442454             mov eax, dword ptr [esp + 0x54]
// 0061630e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00616312  40                   inc eax
// 00616313  2bde                 sub ebx, esi
// 00616315  89442454             mov dword ptr [esp + 0x54], eax
// 00616319  3b02                 cmp eax, dword ptr [edx]
// 0061631b  72ba                 jb 0x6162d7
// 0061631d  e907010000           jmp 0x616429
// 00616322  8d50ff               lea edx, [eax - 1]
// 00616325  d1ea                 shr edx, 1
// 00616327  d1ef                 shr edi, 1
// 00616329  03d1                 add edx, ecx
// 0061632b  03f9                 add edi, ecx
// 0061632d  89542420             mov dword ptr [esp + 0x20], edx
// 00616331  f7c300000100         test ebx, 0x10000
// 00616337  7432                 je 0x61636b
// 00616339  83caff               or edx, 0xffffffff
// 0061633c  8d0c8500000000       lea ecx, [eax*4]
// 00616343  2bd1                 sub edx, ecx
// 00616345  83ceff               or esi, 0xffffffff
// 00616348  8d0cad00000000       lea ecx, [ebp*4]
// 0061634f  2bf1                 sub esi, ecx
// 00616351  83e204               and edx, 4
// 00616354  83e604               and esi, 4
// 00616357  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 0061635f  33ed                 xor ebp, ebp
// 00616361  c7442424fcffffff     mov dword ptr [esp + 0x24], 0xfffffffc
// 00616369  eb33                 jmp 0x61639e
// 0061636b  8d50ff               lea edx, [eax - 1]
// 0061636e  83e201               and edx, 1
// 00616371  4d                   dec ebp
// 00616372  03d2                 add edx, edx
// 00616374  03d2                 add edx, edx
// 00616376  83e501               and ebp, 1
// 00616379  03ed                 add ebp, ebp
// 0061637b  8bca                 mov ecx, edx
// 0061637d  ba04000000           mov edx, 4
// 00616382  03ed                 add ebp, ebp
// 00616384  be04000000           mov esi, 4
// 00616389  2bd1                 sub edx, ecx
// 0061638b  2bf5                 sub esi, ebp
// 0061638d  bd04000000           mov ebp, 4
// 00616392  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0061639a  896c2424             mov dword ptr [esp + 0x24], ebp
// 0061639e  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006163a6  85c0                 test eax, eax
// 006163a8  767b                 jbe 0x616425
// 006163aa  8d9b00000000         lea ebx, [ebx]
// 006163b0  8b442420             mov eax, dword ptr [esp + 0x20]
// 006163b4  8a00                 mov al, byte ptr [eax]
// 006163b6  8aca                 mov cl, dl
// 006163b8  d2e8                 shr al, cl
// 006163ba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006163be  240f                 and al, 0xf
// 006163c0  88442454             mov byte ptr [esp + 0x54], al
// 006163c4  85c9                 test ecx, ecx
// 006163c6  7e3a                 jle 0x616402
// 006163c8  894c2428             mov dword ptr [esp + 0x28], ecx
// 006163cc  eb06                 jmp 0x6163d4
// 006163ce  8bff                 mov edi, edi
// 006163d0  8a442454             mov al, byte ptr [esp + 0x54]
// 006163d4  b904000000           mov ecx, 4
// 006163d9  2bce                 sub ecx, esi
// 006163db  bb0f0f0000           mov ebx, 0xf0f
// 006163e0  d3fb                 sar ebx, cl
// 006163e2  8bce                 mov ecx, esi
// 006163e4  d2e0                 shl al, cl
// 006163e6  221f                 and bl, byte ptr [edi]
// 006163e8  0ad8                 or bl, al
// 006163ea  881f                 mov byte ptr [edi], bl
// 006163ec  3bf5                 cmp esi, ebp
// 006163ee  7507                 jne 0x6163f7
// 006163f0  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006163f4  4f                   dec edi
// 006163f5  eb04                 jmp 0x6163fb
// 006163f7  03742424             add esi, dword ptr [esp + 0x24]
// 006163fb  836c242801           sub dword ptr [esp + 0x28], 1
// 00616400  75ce                 jne 0x6163d0
// 00616402  3bd5                 cmp edx, ebp
// 00616404  750a                 jne 0x616410
// 00616406  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0061640a  ff4c2420             dec dword ptr [esp + 0x20]
// 0061640e  eb04                 jmp 0x616414
// 00616410  03542424             add edx, dword ptr [esp + 0x24]
// 00616414  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00616418  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0061641c  40                   inc eax
// 0061641d  8944242c             mov dword ptr [esp + 0x2c], eax
// 00616421  3b01                 cmp eax, dword ptr [ecx]
// 00616423  728b                 jb 0x6163b0
// 00616425  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00616429  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0061642d  8a410b               mov al, byte ptr [ecx + 0xb]
// 00616430  3c08                 cmp al, 8
// 00616432  8929                 mov dword ptr [ecx], ebp
// 00616434  0fb6c0               movzx eax, al
// 00616437  0f8217020000         jb 0x616654
// 0061643d  c1e803               shr eax, 3
// 00616440  0fafc5               imul eax, ebp
// 00616443  5d                   pop ebp
// 00616444  5f                   pop edi
// 00616445  5e                   pop esi
// 00616446  894104               mov dword ptr [ecx + 4], eax
// 00616449  5b                   pop ebx
// 0061644a  83c440               add esp, 0x40
// 0061644d  c3                   ret 
// 0061644e  8d50ff               lea edx, [eax - 1]
// 00616451  8d7dff               lea edi, [ebp - 1]
// 00616454  c1ea02               shr edx, 2
// 00616457  c1ef02               shr edi, 2
// 0061645a  03d1                 add edx, ecx
// 0061645c  03f9                 add edi, ecx
// 0061645e  89542420             mov dword ptr [esp + 0x20], edx
// 00616462  f7c300000100         test ebx, 0x10000
// 00616468  7422                 je 0x61648c
// 0061646a  8d742dff             lea esi, [ebp + ebp - 1]
// 0061646e  8d5400ff             lea edx, [eax + eax - 1]
// 00616472  83e206               and edx, 6
// 00616475  83e606               and esi, 6
// 00616478  c744242406000000     mov dword ptr [esp + 0x24], 6
// 00616480  33ed                 xor ebp, ebp
// 00616482  c744241cfeffffff     mov dword ptr [esp + 0x1c], 0xfffffffe
// 0061648a  eb31                 jmp 0x6164bd
// 0061648c  4d                   dec ebp
// 0061648d  8d48ff               lea ecx, [eax - 1]
// 00616490  83e103               and ecx, 3
// 00616493  83e503               and ebp, 3
// 00616496  ba03000000           mov edx, 3
// 0061649b  2bd1                 sub edx, ecx
// 0061649d  be03000000           mov esi, 3
// 006164a2  2bf5                 sub esi, ebp
// 006164a4  03d2                 add edx, edx
// 006164a6  03f6                 add esi, esi
// 006164a8  c744242400000000     mov dword ptr [esp + 0x24], 0
// 006164b0  bd06000000           mov ebp, 6
// 006164b5  c744241c02000000     mov dword ptr [esp + 0x1c], 2
// 006164bd  c744242800000000     mov dword ptr [esp + 0x28], 0
// 006164c5  85c0                 test eax, eax
// 006164c7  0f8658ffffff         jbe 0x616425
// 006164cd  8d4900               lea ecx, [ecx]
// 006164d0  8b442420             mov eax, dword ptr [esp + 0x20]
// 006164d4  8a00                 mov al, byte ptr [eax]
// 006164d6  8aca                 mov cl, dl
// 006164d8  d2e8                 shr al, cl
// 006164da  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006164de  2403                 and al, 3
// 006164e0  88442454             mov byte ptr [esp + 0x54], al
// 006164e4  85c9                 test ecx, ecx
// 006164e6  7e3a                 jle 0x616522
// 006164e8  894c242c             mov dword ptr [esp + 0x2c], ecx
// 006164ec  eb06                 jmp 0x6164f4
// 006164ee  8bff                 mov edi, edi
// 006164f0  8a442454             mov al, byte ptr [esp + 0x54]
// 006164f4  b906000000           mov ecx, 6
// 006164f9  2bce                 sub ecx, esi
// 006164fb  bb3f3f0000           mov ebx, 0x3f3f
// 00616500  d3fb                 sar ebx, cl
// 00616502  8bce                 mov ecx, esi
// 00616504  d2e0                 shl al, cl
// 00616506  221f                 and bl, byte ptr [edi]
// 00616508  0ad8                 or bl, al
// 0061650a  881f                 mov byte ptr [edi], bl
// 0061650c  3bf5                 cmp esi, ebp
// 0061650e  7507                 jne 0x616517
// 00616510  8b742424             mov esi, dword ptr [esp + 0x24]
// 00616514  4f                   dec edi
// 00616515  eb04                 jmp 0x61651b
// 00616517  0374241c             add esi, dword ptr [esp + 0x1c]
// 0061651b  836c242c01           sub dword ptr [esp + 0x2c], 1
// 00616520  75ce                 jne 0x6164f0
// 00616522  3bd5                 cmp edx, ebp
// 00616524  750a                 jne 0x616530
// 00616526  8b542424             mov edx, dword ptr [esp + 0x24]
// 0061652a  ff4c2420             dec dword ptr [esp + 0x20]
// 0061652e  eb04                 jmp 0x616534
// 00616530  0354241c             add edx, dword ptr [esp + 0x1c]
// 00616534  8b442428             mov eax, dword ptr [esp + 0x28]
// 00616538  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0061653c  40                   inc eax
// 0061653d  89442428             mov dword ptr [esp + 0x28], eax
// 00616541  3b01                 cmp eax, dword ptr [ecx]
// 00616543  728b                 jb 0x6164d0
// 00616545  e9dbfeffff           jmp 0x616425
// 0061654a  8d50ff               lea edx, [eax - 1]
// 0061654d  8d7dff               lea edi, [ebp - 1]
// 00616550  c1ea03               shr edx, 3
// 00616553  c1ef03               shr edi, 3
// 00616556  03d1                 add edx, ecx
// 00616558  03f9                 add edi, ecx
// 0061655a  8954241c             mov dword ptr [esp + 0x1c], edx
// 0061655e  f7c300000100         test ebx, 0x10000
// 00616564  7426                 je 0x61658c
// 00616566  8d50ff               lea edx, [eax - 1]
// 00616569  8d75ff               lea esi, [ebp - 1]
// 0061656c  83e207               and edx, 7
// 0061656f  83e607               and esi, 7
// 00616572  c744242007000000     mov dword ptr [esp + 0x20], 7
// 0061657a  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00616582  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0061658a  eb32                 jmp 0x6165be
// 0061658c  8d48ff               lea ecx, [eax - 1]
// 0061658f  83e107               and ecx, 7
// 00616592  ba07000000           mov edx, 7
// 00616597  2bd1                 sub edx, ecx
// 00616599  8d4dff               lea ecx, [ebp - 1]
// 0061659c  83e107               and ecx, 7
// 0061659f  be07000000           mov esi, 7
// 006165a4  2bf1                 sub esi, ecx
// 006165a6  c744242000000000     mov dword ptr [esp + 0x20], 0
// 006165ae  c744242407000000     mov dword ptr [esp + 0x24], 7
// 006165b6  c744241001000000     mov dword ptr [esp + 0x10], 1
// 006165be  89542454             mov dword ptr [esp + 0x54], edx
// 006165c2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 006165ca  85c0                 test eax, eax
// 006165cc  0f8657feffff         jbe 0x616429
// 006165d2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006165d6  8a00                 mov al, byte ptr [eax]
// 006165d8  8aca                 mov cl, dl
// 006165da  d2e8                 shr al, cl
// 006165dc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006165e0  2401                 and al, 1
// 006165e2  85c9                 test ecx, ecx
// 006165e4  7e40                 jle 0x616626
// 006165e6  894c242c             mov dword ptr [esp + 0x2c], ecx
// 006165ea  8d9b00000000         lea ebx, [ebx]
// 006165f0  b907000000           mov ecx, 7
// 006165f5  2bce                 sub ecx, esi
// 006165f7  ba7f7f0000           mov edx, 0x7f7f
// 006165fc  d3fa                 sar edx, cl
// 006165fe  8ad8                 mov bl, al
// 00616600  8bce                 mov ecx, esi
// 00616602  d2e3                 shl bl, cl
// 00616604  2217                 and dl, byte ptr [edi]
// 00616606  0ad3                 or dl, bl
// 00616608  8817                 mov byte ptr [edi], dl
// 0061660a  3b742424             cmp esi, dword ptr [esp + 0x24]
// 0061660e  7507                 jne 0x616617
// 00616610  8b742420             mov esi, dword ptr [esp + 0x20]
// 00616614  4f                   dec edi
// 00616615  eb04                 jmp 0x61661b
// 00616617  03742410             add esi, dword ptr [esp + 0x10]
// 0061661b  836c242c01           sub dword ptr [esp + 0x2c], 1
// 00616620  75ce                 jne 0x6165f0
// 00616622  8b542454             mov edx, dword ptr [esp + 0x54]
// 00616626  3b542424             cmp edx, dword ptr [esp + 0x24]
// 0061662a  750a                 jne 0x616636
// 0061662c  8b542420             mov edx, dword ptr [esp + 0x20]
// 00616630  ff4c241c             dec dword ptr [esp + 0x1c]
// 00616634  eb04                 jmp 0x61663a
// 00616636  03542410             add edx, dword ptr [esp + 0x10]
// 0061663a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0061663e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00616642  40                   inc eax
// 00616643  89542454             mov dword ptr [esp + 0x54], edx
// 00616647  89442428             mov dword ptr [esp + 0x28], eax
// 0061664b  3b01                 cmp eax, dword ptr [ecx]
// 0061664d  7283                 jb 0x6165d2
// 0061664f  e9d5fdffff           jmp 0x616429
// 00616654  0fafc5               imul eax, ebp
// 00616657  83c007               add eax, 7
// 0061665a  c1e803               shr eax, 3
// 0061665d  894104               mov dword ptr [ecx + 4], eax
// 00616660  5d                   pop ebp
// 00616661  5f                   pop edi
// 00616662  5e                   pop esi
// 00616663  5b                   pop ebx
// 00616664  83c440               add esp, 0x40
// 00616667  c3                   ret 
// library libpng-1.2.22/pngrutil.c (function _png_do_read_interlace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrutil.c
