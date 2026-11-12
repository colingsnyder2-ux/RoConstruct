// from server: 100% by auto
// roc 2008-06 004bdf80  unit: ProfiledRakPeer  size: 535 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bdf80
//
// 004bdf80  55                   push ebp
// 004bdf81  8bec                 mov ebp, esp
// 004bdf83  83ec44               sub esp, 0x44
// 004bdf86  53                   push ebx
// 004bdf87  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 004bdf8a  56                   push esi
// 004bdf8b  8b750c               mov esi, dword ptr [ebp + 0xc]
// 004bdf8e  57                   push edi
// 004bdf8f  b910000000           mov ecx, 0x10
// 004bdf94  8d7dbc               lea edi, [ebp - 0x44]
// 004bdf97  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bdf99  8b7508               mov esi, dword ptr [ebp + 8]
// 004bdf9c  b910000000           mov ecx, 0x10
// 004bdfa1  8bfb                 mov edi, ebx
// 004bdfa3  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bdfa5  bf00000080           mov edi, 0x80000000
// 004bdfaa  c745fc01000000       mov dword ptr [ebp - 4], 1
// 004bdfb1  857df8               test dword ptr [ebp - 8], edi
// 004bdfb4  0f8511010000         jne 0x4be0cb
// 004bdfba  8d45bc               lea eax, [ebp - 0x44]
// 004bdfbd  50                   push eax
// 004bdfbe  53                   push ebx
// 004bdfbf  e89ce9ffff           call 0x4bc960
// 004bdfc4  83c408               add esp, 8
// 004bdfc7  84c0                 test al, al
// 004bdfc9  0f84fc000000         je 0x4be0cb
// 004bdfcf  b80f000000           mov eax, 0xf
// 004bdfd4  8d4b34               lea ecx, [ebx + 0x34]
// 004bdfd7  83790800             cmp dword ptr [ecx + 8], 0
// 004bdfdb  7528                 jne 0x4be005
// 004bdfdd  83790400             cmp dword ptr [ecx + 4], 0
// 004bdfe1  7517                 jne 0x4bdffa
// 004bdfe3  833900               cmp dword ptr [ecx], 0
// 004bdfe6  7515                 jne 0x4bdffd
// 004bdfe8  8379fc00             cmp dword ptr [ecx - 4], 0
// 004bdfec  7514                 jne 0x4be002
// 004bdfee  83e804               sub eax, 4
// 004bdff1  83e910               sub ecx, 0x10
// 004bdff4  85c0                 test eax, eax
// 004bdff6  7ddf                 jge 0x4bdfd7
// 004bdff8  eb0b                 jmp 0x4be005
// 004bdffa  48                   dec eax
// 004bdffb  eb08                 jmp 0x4be005
// 004bdffd  83e802               sub eax, 2
// 004be000  eb03                 jmp 0x4be005
// 004be002  83e803               sub eax, 3
// 004be005  8bc8                 mov ecx, eax
// 004be007  85c0                 test eax, eax
// 004be009  7c2c                 jl 0x4be037
// 004be00b  eb03                 jmp 0x4be010
// 004be00d  8d4900               lea ecx, [ecx]
// 004be010  837c8dbc00           cmp dword ptr [ebp + ecx*4 - 0x44], 0
// 004be015  7505                 jne 0x4be01c
// 004be017  83e901               sub ecx, 1
// 004be01a  79f4                 jns 0x4be010
// 004be01c  3bc1                 cmp eax, ecx
// 004be01e  7417                 je 0x4be037
// 004be020  2bc1                 sub eax, ecx
// 004be022  c1e005               shl eax, 5
// 004be025  8bf0                 mov esi, eax
// 004be027  8d4dbc               lea ecx, [ebp - 0x44]
// 004be02a  56                   push esi
// 004be02b  51                   push ecx
// 004be02c  e86fe9ffff           call 0x4bc9a0
// 004be031  83c408               add esp, 8
// 004be034  46                   inc esi
// 004be035  eb03                 jmp 0x4be03a
// 004be037  8b75fc               mov esi, dword ptr [ebp - 4]
// 004be03a  857df8               test dword ptr [ebp - 8], edi
// 004be03d  7543                 jne 0x4be082
// 004be03f  90                   nop 
// 004be040  b80f000000           mov eax, 0xf
// 004be045  8b0c83               mov ecx, dword ptr [ebx + eax*4]
// 004be048  8b5485bc             mov edx, dword ptr [ebp + eax*4 - 0x44]
// 004be04c  3bca                 cmp ecx, edx
// 004be04e  7709                 ja 0x4be059
// 004be050  7230                 jb 0x4be082
// 004be052  83e801               sub eax, 1
// 004be055  79ee                 jns 0x4be045
// 004be057  eb29                 jmp 0x4be082
// 004be059  33d2                 xor edx, edx
// 004be05b  33c9                 xor ecx, ecx
// 004be05d  8d4900               lea ecx, [ecx]
// 004be060  8b448dbc             mov eax, dword ptr [ebp + ecx*4 - 0x44]
// 004be064  8d3c00               lea edi, [eax + eax]
// 004be067  0bfa                 or edi, edx
// 004be069  897c8dbc             mov dword ptr [ebp + ecx*4 - 0x44], edi
// 004be06d  c1e81f               shr eax, 0x1f
// 004be070  41                   inc ecx
// 004be071  8bd0                 mov edx, eax
// 004be073  83f910               cmp ecx, 0x10
// 004be076  72e8                 jb 0x4be060
// 004be078  46                   inc esi
// 004be079  f745f800000080       test dword ptr [ebp - 8], 0x80000000
// 004be080  74be                 je 0x4be040
// 004be082  b80f000000           mov eax, 0xf
// 004be087  8b0c83               mov ecx, dword ptr [ebx + eax*4]
// 004be08a  8b5485bc             mov edx, dword ptr [ebp + eax*4 - 0x44]
// 004be08e  3bd1                 cmp edx, ecx
// 004be090  7711                 ja 0x4be0a3
// 004be092  7205                 jb 0x4be099
// 004be094  83e801               sub eax, 1
// 004be097  79ee                 jns 0x4be087
// 004be099  85f6                 test esi, esi
// 004be09b  0f84ef000000         je 0x4be190
// 004be0a1  eb4d                 jmp 0x4be0f0
// 004be0a3  33c9                 xor ecx, ecx
// 004be0a5  ba0f000000           mov edx, 0xf
// 004be0aa  8d9b00000000         lea ebx, [ebx]
// 004be0b0  8b4495bc             mov eax, dword ptr [ebp + edx*4 - 0x44]
// 004be0b4  8bf8                 mov edi, eax
// 004be0b6  d1ef                 shr edi, 1
// 004be0b8  0bf9                 or edi, ecx
// 004be0ba  c1e01f               shl eax, 0x1f
// 004be0bd  83ea01               sub edx, 1
// 004be0c0  897c95c0             mov dword ptr [ebp + edx*4 - 0x40], edi
// 004be0c4  8bc8                 mov ecx, eax
// 004be0c6  79e8                 jns 0x4be0b0
// 004be0c8  4e                   dec esi
// 004be0c9  ebb7                 jmp 0x4be082
// 004be0cb  b80f000000           mov eax, 0xf
// 004be0d0  8b0c83               mov ecx, dword ptr [ebx + eax*4]
// 004be0d3  8b5485bc             mov edx, dword ptr [ebp + eax*4 - 0x44]
// 004be0d7  3bd1                 cmp edx, ecx
// 004be0d9  0f87b1000000         ja 0x4be190
// 004be0df  7205                 jb 0x4be0e6
// 004be0e1  83e801               sub eax, 1
// 004be0e4  79ea                 jns 0x4be0d0
// 004be0e6  8b75fc               mov esi, dword ptr [ebp - 4]
// 004be0e9  8da42400000000       lea esp, [esp]
// 004be0f0  4e                   dec esi
// 004be0f1  8975fc               mov dword ptr [ebp - 4], esi
// 004be0f4  b80f000000           mov eax, 0xf
// 004be0f9  8da42400000000       lea esp, [esp]
// 004be100  8b0c83               mov ecx, dword ptr [ebx + eax*4]
// 004be103  8b5485bc             mov edx, dword ptr [ebp + eax*4 - 0x44]
// 004be107  3bd1                 cmp edx, ecx
// 004be109  775c                 ja 0x4be167
// 004be10b  7205                 jb 0x4be112
// 004be10d  83e801               sub eax, 1
// 004be110  79ee                 jns 0x4be100
// 004be112  8d55bc               lea edx, [ebp - 0x44]
// 004be115  895508               mov dword ptr [ebp + 8], edx
// 004be118  c7450c03000000       mov dword ptr [ebp + 0xc], 3
// 004be11f  8b7508               mov esi, dword ptr [ebp + 8]
// 004be122  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004be125  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004be128  8b06                 mov eax, dword ptr [esi]
// 004be12a  33d2                 xor edx, edx
// 004be12c  2907                 sub dword ptr [edi], eax
// 004be12e  8b4604               mov eax, dword ptr [esi + 4]
// 004be131  194704               sbb dword ptr [edi + 4], eax
// 004be134  8b4608               mov eax, dword ptr [esi + 8]
// 004be137  194708               sbb dword ptr [edi + 8], eax
// 004be13a  8b460c               mov eax, dword ptr [esi + 0xc]
// 004be13d  19470c               sbb dword ptr [edi + 0xc], eax
// 004be140  e322                 jecxz 0x4be164
// 004be142  42                   inc edx
// 004be143  42                   inc edx
// 004be144  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004be147  1904d7               sbb dword ptr [edi + edx*8], eax
// 004be14a  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004be14e  1944d704             sbb dword ptr [edi + edx*8 + 4], eax
// 004be152  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004be156  1944d708             sbb dword ptr [edi + edx*8 + 8], eax
// 004be15a  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004be15e  1944d70c             sbb dword ptr [edi + edx*8 + 0xc], eax
// 004be162  e2de                 loop 0x4be142
// 004be164  8b75fc               mov esi, dword ptr [ebp - 4]
// 004be167  33c9                 xor ecx, ecx
// 004be169  ba0f000000           mov edx, 0xf
// 004be16e  8bff                 mov edi, edi
// 004be170  8b4495bc             mov eax, dword ptr [ebp + edx*4 - 0x44]
// 004be174  8bf8                 mov edi, eax
// 004be176  d1ef                 shr edi, 1
// 004be178  0bf9                 or edi, ecx
// 004be17a  c1e01f               shl eax, 0x1f
// 004be17d  83ea01               sub edx, 1
// 004be180  897c95c0             mov dword ptr [ebp + edx*4 - 0x40], edi
// 004be184  8bc8                 mov ecx, eax
// 004be186  79e8                 jns 0x4be170
// 004be188  85f6                 test esi, esi
// 004be18a  0f8560ffffff         jne 0x4be0f0
// 004be190  5f                   pop edi
// 004be191  5e                   pop esi
// 004be192  5b                   pop ebx
// 004be193  8be5                 mov esp, ebp
// 004be195  5d                   pop ebp
// 004be196  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$umodulo@$$BY0BA@I@big@@YAXAAY0BA@I00@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
