// from server: 100% by auto
// roc 2008-06 004bdd20  unit: ProfiledRakPeer  size: 599 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bdd20
//
// 004bdd20  55                   push ebp
// 004bdd21  8bec                 mov ebp, esp
// 004bdd23  83ec44               sub esp, 0x44
// 004bdd26  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004bdd29  53                   push ebx
// 004bdd2a  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 004bdd2d  56                   push esi
// 004bdd2e  8b750c               mov esi, dword ptr [ebp + 0xc]
// 004bdd31  57                   push edi
// 004bdd32  6a40                 push 0x40
// 004bdd34  b910000000           mov ecx, 0x10
// 004bdd39  8d7dbc               lea edi, [ebp - 0x44]
// 004bdd3c  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bdd3e  8b7508               mov esi, dword ptr [ebp + 8]
// 004bdd41  6a00                 push 0
// 004bdd43  b910000000           mov ecx, 0x10
// 004bdd48  8bfb                 mov edi, ebx
// 004bdd4a  50                   push eax
// 004bdd4b  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bdd4d  e8b2391e00           call 0x6a1704
// 004bdd52  bf00000080           mov edi, 0x80000000
// 004bdd57  83c40c               add esp, 0xc
// 004bdd5a  be01000000           mov esi, 1
// 004bdd5f  89750c               mov dword ptr [ebp + 0xc], esi
// 004bdd62  857df8               test dword ptr [ebp - 8], edi
// 004bdd65  0f8511010000         jne 0x4bde7c
// 004bdd6b  8d4dbc               lea ecx, [ebp - 0x44]
// 004bdd6e  51                   push ecx
// 004bdd6f  53                   push ebx
// 004bdd70  e8ebebffff           call 0x4bc960
// 004bdd75  83c408               add esp, 8
// 004bdd78  84c0                 test al, al
// 004bdd7a  0f84fc000000         je 0x4bde7c
// 004bdd80  8d460e               lea eax, [esi + 0xe]
// 004bdd83  8d4b34               lea ecx, [ebx + 0x34]
// 004bdd86  83790800             cmp dword ptr [ecx + 8], 0
// 004bdd8a  7529                 jne 0x4bddb5
// 004bdd8c  83790400             cmp dword ptr [ecx + 4], 0
// 004bdd90  7517                 jne 0x4bdda9
// 004bdd92  833900               cmp dword ptr [ecx], 0
// 004bdd95  7516                 jne 0x4bddad
// 004bdd97  8379fc00             cmp dword ptr [ecx - 4], 0
// 004bdd9b  7515                 jne 0x4bddb2
// 004bdd9d  83e804               sub eax, 4
// 004bdda0  83e910               sub ecx, 0x10
// 004bdda3  85c0                 test eax, eax
// 004bdda5  7ddf                 jge 0x4bdd86
// 004bdda7  eb0c                 jmp 0x4bddb5
// 004bdda9  2bc6                 sub eax, esi
// 004bddab  eb08                 jmp 0x4bddb5
// 004bddad  83e802               sub eax, 2
// 004bddb0  eb03                 jmp 0x4bddb5
// 004bddb2  83e803               sub eax, 3
// 004bddb5  8bc8                 mov ecx, eax
// 004bddb7  85c0                 test eax, eax
// 004bddb9  7c2c                 jl 0x4bdde7
// 004bddbb  eb03                 jmp 0x4bddc0
// 004bddbd  8d4900               lea ecx, [ecx]
// 004bddc0  837c8dbc00           cmp dword ptr [ebp + ecx*4 - 0x44], 0
// 004bddc5  7504                 jne 0x4bddcb
// 004bddc7  2bce                 sub ecx, esi
// 004bddc9  79f5                 jns 0x4bddc0
// 004bddcb  3bc1                 cmp eax, ecx
// 004bddcd  7418                 je 0x4bdde7
// 004bddcf  2bc1                 sub eax, ecx
// 004bddd1  c1e005               shl eax, 5
// 004bddd4  8bf0                 mov esi, eax
// 004bddd6  8d55bc               lea edx, [ebp - 0x44]
// 004bddd9  56                   push esi
// 004bddda  52                   push edx
// 004bdddb  e8c0ebffff           call 0x4bc9a0
// 004bdde0  83c408               add esp, 8
// 004bdde3  46                   inc esi
// 004bdde4  89750c               mov dword ptr [ebp + 0xc], esi
// 004bdde7  857df8               test dword ptr [ebp - 8], edi
// 004bddea  7544                 jne 0x4bde30
// 004bddec  8d642400             lea esp, [esp]
// 004bddf0  b80f000000           mov eax, 0xf
// 004bddf5  8b0c83               mov ecx, dword ptr [ebx + eax*4]
// 004bddf8  8b5485bc             mov edx, dword ptr [ebp + eax*4 - 0x44]
// 004bddfc  3bca                 cmp ecx, edx
// 004bddfe  7709                 ja 0x4bde09
// 004bde00  722e                 jb 0x4bde30
// 004bde02  83e801               sub eax, 1
// 004bde05  79ee                 jns 0x4bddf5
// 004bde07  eb27                 jmp 0x4bde30
// 004bde09  33d2                 xor edx, edx
// 004bde0b  33c9                 xor ecx, ecx
// 004bde0d  8d4900               lea ecx, [ecx]
// 004bde10  8b448dbc             mov eax, dword ptr [ebp + ecx*4 - 0x44]
// 004bde14  8d3400               lea esi, [eax + eax]
// 004bde17  0bf2                 or esi, edx
// 004bde19  89748dbc             mov dword ptr [ebp + ecx*4 - 0x44], esi
// 004bde1d  c1e81f               shr eax, 0x1f
// 004bde20  41                   inc ecx
// 004bde21  8bd0                 mov edx, eax
// 004bde23  83f910               cmp ecx, 0x10
// 004bde26  72e8                 jb 0x4bde10
// 004bde28  ff450c               inc dword ptr [ebp + 0xc]
// 004bde2b  857df8               test dword ptr [ebp - 8], edi
// 004bde2e  74c0                 je 0x4bddf0
// 004bde30  be01000000           mov esi, 1
// 004bde35  eb09                 jmp 0x4bde40
// 004bde37  8da42400000000       lea esp, [esp]
// 004bde3e  8bff                 mov edi, edi
// 004bde40  b80f000000           mov eax, 0xf
// 004bde45  8b0c83               mov ecx, dword ptr [ebx + eax*4]
// 004bde48  8b5485bc             mov edx, dword ptr [ebp + eax*4 - 0x44]
// 004bde4c  3bd1                 cmp edx, ecx
// 004bde4e  7708                 ja 0x4bde58
// 004bde50  7255                 jb 0x4bdea7
// 004bde52  2bc6                 sub eax, esi
// 004bde54  79ef                 jns 0x4bde45
// 004bde56  eb4f                 jmp 0x4bdea7
// 004bde58  33c9                 xor ecx, ecx
// 004bde5a  ba0f000000           mov edx, 0xf
// 004bde5f  90                   nop 
// 004bde60  8b4495bc             mov eax, dword ptr [ebp + edx*4 - 0x44]
// 004bde64  8bf8                 mov edi, eax
// 004bde66  d1ef                 shr edi, 1
// 004bde68  0bf9                 or edi, ecx
// 004bde6a  c1e01f               shl eax, 0x1f
// 004bde6d  897c95bc             mov dword ptr [ebp + edx*4 - 0x44], edi
// 004bde71  2bd6                 sub edx, esi
// 004bde73  8bc8                 mov ecx, eax
// 004bde75  79e9                 jns 0x4bde60
// 004bde77  29750c               sub dword ptr [ebp + 0xc], esi
// 004bde7a  ebc4                 jmp 0x4bde40
// 004bde7c  b80f000000           mov eax, 0xf
// 004bde81  8b0c83               mov ecx, dword ptr [ebx + eax*4]
// 004bde84  8b5485bc             mov edx, dword ptr [ebp + eax*4 - 0x44]
// 004bde88  3bd1                 cmp edx, ecx
// 004bde8a  7708                 ja 0x4bde94
// 004bde8c  7219                 jb 0x4bdea7
// 004bde8e  2bc6                 sub eax, esi
// 004bde90  79ef                 jns 0x4bde81
// 004bde92  eb13                 jmp 0x4bdea7
// 004bde94  8d45bc               lea eax, [ebp - 0x44]
// 004bde97  50                   push eax
// 004bde98  e893ebffff           call 0x4bca30
// 004bde9d  83c404               add esp, 4
// 004bdea0  c7450c00000000       mov dword ptr [ebp + 0xc], 0
// 004bdea7  33db                 xor ebx, ebx
// 004bdea9  395d0c               cmp dword ptr [ebp + 0xc], ebx
// 004bdeac  0f84b1000000         je 0x4bdf63
// 004bdeb2  29750c               sub dword ptr [ebp + 0xc], esi
// 004bdeb5  03de                 add ebx, esi
// 004bdeb7  b80f000000           mov eax, 0xf
// 004bdebc  8d642400             lea esp, [esp]
// 004bdec0  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004bdec3  8b0c81               mov ecx, dword ptr [ecx + eax*4]
// 004bdec6  8b5485bc             mov edx, dword ptr [ebp + eax*4 - 0x44]
// 004bdeca  3bd1                 cmp edx, ecx
// 004bdecc  776a                 ja 0x4bdf38
// 004bdece  7204                 jb 0x4bded4
// 004bded0  2bc6                 sub eax, esi
// 004bded2  79ec                 jns 0x4bdec0
// 004bded4  8d55bc               lea edx, [ebp - 0x44]
// 004bded7  8955fc               mov dword ptr [ebp - 4], edx
// 004bdeda  c7450803000000       mov dword ptr [ebp + 8], 3
// 004bdee1  8b75fc               mov esi, dword ptr [ebp - 4]
// 004bdee4  8b7d14               mov edi, dword ptr [ebp + 0x14]
// 004bdee7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004bdeea  8b06                 mov eax, dword ptr [esi]
// 004bdeec  33d2                 xor edx, edx
// 004bdeee  2907                 sub dword ptr [edi], eax
// 004bdef0  8b4604               mov eax, dword ptr [esi + 4]
// 004bdef3  194704               sbb dword ptr [edi + 4], eax
// 004bdef6  8b4608               mov eax, dword ptr [esi + 8]
// 004bdef9  194708               sbb dword ptr [edi + 8], eax
// 004bdefc  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bdeff  19470c               sbb dword ptr [edi + 0xc], eax
// 004bdf02  e322                 jecxz 0x4bdf26
// 004bdf04  42                   inc edx
// 004bdf05  42                   inc edx
// 004bdf06  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004bdf09  1904d7               sbb dword ptr [edi + edx*8], eax
// 004bdf0c  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004bdf10  1944d704             sbb dword ptr [edi + edx*8 + 4], eax
// 004bdf14  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004bdf18  1944d708             sbb dword ptr [edi + edx*8 + 8], eax
// 004bdf1c  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004bdf20  1944d70c             sbb dword ptr [edi + edx*8 + 0xc], eax
// 004bdf24  e2de                 loop 0x4bdf04
// 004bdf26  8b7510               mov esi, dword ptr [ebp + 0x10]
// 004bdf29  53                   push ebx
// 004bdf2a  56                   push esi
// 004bdf2b  e870eaffff           call 0x4bc9a0
// 004bdf30  83c408               add esp, 8
// 004bdf33  33db                 xor ebx, ebx
// 004bdf35  830e01               or dword ptr [esi], 1
// 004bdf38  33c9                 xor ecx, ecx
// 004bdf3a  ba0f000000           mov edx, 0xf
// 004bdf3f  8d7101               lea esi, [ecx + 1]
// 004bdf42  8b4495bc             mov eax, dword ptr [ebp + edx*4 - 0x44]
// 004bdf46  8bf8                 mov edi, eax
// 004bdf48  d1ef                 shr edi, 1
// 004bdf4a  0bf9                 or edi, ecx
// 004bdf4c  c1e01f               shl eax, 0x1f
// 004bdf4f  897c95bc             mov dword ptr [ebp + edx*4 - 0x44], edi
// 004bdf53  2bd6                 sub edx, esi
// 004bdf55  8bc8                 mov ecx, eax
// 004bdf57  79e9                 jns 0x4bdf42
// 004bdf59  837d0c00             cmp dword ptr [ebp + 0xc], 0
// 004bdf5d  0f854fffffff         jne 0x4bdeb2
// 004bdf63  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004bdf66  53                   push ebx
// 004bdf67  50                   push eax
// 004bdf68  e833eaffff           call 0x4bc9a0
// 004bdf6d  83c408               add esp, 8
// 004bdf70  5f                   pop edi
// 004bdf71  5e                   pop esi
// 004bdf72  5b                   pop ebx
// 004bdf73  8be5                 mov esp, ebp
// 004bdf75  5d                   pop ebp
// 004bdf76  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$udivide@$$BY0BA@I@big@@YAXAAY0BA@I000@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
