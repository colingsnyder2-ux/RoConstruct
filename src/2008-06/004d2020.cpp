// from server: 100% by auto
// roc 2008-06 004d2020  unit: seg_004d0000  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d2020
//
// 004d2020  83ec08               sub esp, 8
// 004d2023  53                   push ebx
// 004d2024  55                   push ebp
// 004d2025  56                   push esi
// 004d2026  57                   push edi
// 004d2027  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004d202b  68c0f74c00           push 0x4cf7c0
// 004d2030  8d442417             lea eax, [esp + 0x17]
// 004d2034  8db1a4000000         lea esi, [ecx + 0xa4]
// 004d203a  50                   push eax
// 004d203b  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004d203f  83c71c               add edi, 0x1c
// 004d2042  57                   push edi
// 004d2043  8bce                 mov ecx, esi
// 004d2045  e826d1ffff           call 0x4cf170
// 004d204a  807c241300           cmp byte ptr [esp + 0x13], 0
// 004d204f  8be8                 mov ebp, eax
// 004d2051  7555                 jne 0x4d20a8
// 004d2053  6a18                 push 0x18
// 004d2055  e8c6e81c00           call 0x6a0920
// 004d205a  33db                 xor ebx, ebx
// 004d205c  83c404               add esp, 4
// 004d205f  3bc3                 cmp eax, ebx
// 004d2061  740b                 je 0x4d206e
// 004d2063  895810               mov dword ptr [eax + 0x10], ebx
// 004d2066  895808               mov dword ptr [eax + 8], ebx
// 004d2069  89580c               mov dword ptr [eax + 0xc], ebx
// 004d206c  8bd8                 mov ebx, eax
// 004d206e  68c0f74c00           push 0x4cf7c0
// 004d2073  8d4c2417             lea ecx, [esp + 0x17]
// 004d2077  51                   push ecx
// 004d2078  57                   push edi
// 004d2079  8bce                 mov ecx, esi
// 004d207b  e8f0d0ffff           call 0x4cf170
// 004d2080  807c241300           cmp byte ptr [esp + 0x13], 0
// 004d2085  8be8                 mov ebp, eax
// 004d2087  7405                 je 0x4d208e
// 004d2089  83cdff               or ebp, 0xffffffff
// 004d208c  eb1a                 jmp 0x4d20a8
// 004d208e  8bce                 mov ecx, esi
// 004d2090  3b6e04               cmp ebp, dword ptr [esi + 4]
// 004d2093  720c                 jb 0x4d20a1
// 004d2095  53                   push ebx
// 004d2096  e885a0feff           call 0x4bc120
// 004d209b  8b6e04               mov ebp, dword ptr [esi + 4]
// 004d209e  4d                   dec ebp
// 004d209f  eb07                 jmp 0x4d20a8
// 004d20a1  55                   push ebp
// 004d20a2  53                   push ebx
// 004d20a3  e8d8d2ffff           call 0x4cf380
// 004d20a8  8b16                 mov edx, dword ptr [esi]
// 004d20aa  8b3caa               mov edi, dword ptr [edx + ebp*4]
// 004d20ad  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004d20b1  68a0e94c00           push 0x4ce9a0
// 004d20b6  8d442417             lea eax, [esp + 0x17]
// 004d20ba  50                   push eax
// 004d20bb  8d4b20               lea ecx, [ebx + 0x20]
// 004d20be  83c708               add edi, 8
// 004d20c1  51                   push ecx
// 004d20c2  8bcf                 mov ecx, edi
// 004d20c4  e8a7d0ffff           call 0x4cf170
// 004d20c9  807c241300           cmp byte ptr [esp + 0x13], 0
// 004d20ce  7516                 jne 0x4d20e6
// 004d20d0  8bcf                 mov ecx, edi
// 004d20d2  3b4704               cmp eax, dword ptr [edi + 4]
// 004d20d5  7208                 jb 0x4d20df
// 004d20d7  53                   push ebx
// 004d20d8  e843a0feff           call 0x4bc120
// 004d20dd  eb07                 jmp 0x4d20e6
// 004d20df  50                   push eax
// 004d20e0  53                   push ebx
// 004d20e1  e89ad2ffff           call 0x4cf380
// 004d20e6  8b16                 mov edx, dword ptr [esi]
// 004d20e8  8b04aa               mov eax, dword ptr [edx + ebp*4]
// 004d20eb  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004d20ef  8b542424             mov edx, dword ptr [esp + 0x24]
// 004d20f3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004d20f7  8908                 mov dword ptr [eax], ecx
// 004d20f9  895004               mov dword ptr [eax + 4], edx
// 004d20fc  8b4f28               mov ecx, dword ptr [edi + 0x28]
// 004d20ff  85c9                 test ecx, ecx
// 004d2101  0f84e5000000         je 0x4d21ec
// 004d2107  8b06                 mov eax, dword ptr [esi]
// 004d2109  8b14a8               mov edx, dword ptr [eax + ebp*4]
// 004d210c  8b4208               mov eax, dword ptr [edx + 8]
// 004d210f  8b00                 mov eax, dword ptr [eax]
// 004d2111  83782000             cmp dword ptr [eax + 0x20], 0
// 004d2115  0f85d1000000         jne 0x4d21ec
// 004d211b  8b06                 mov eax, dword ptr [esi]
// 004d211d  8b04a8               mov eax, dword ptr [eax + ebp*4]
// 004d2120  8b5808               mov ebx, dword ptr [eax + 8]
// 004d2123  8b1b                 mov ebx, dword ptr [ebx]
// 004d2125  8b400c               mov eax, dword ptr [eax + 0xc]
// 004d2128  3b4324               cmp eax, dword ptr [ebx + 0x24]
// 004d212b  0f84bb000000         je 0x4d21ec
// 004d2131  8b420c               mov eax, dword ptr [edx + 0xc]
// 004d2134  33d2                 xor edx, edx
// 004d2136  f7f1                 div ecx
// 004d2138  85d2                 test edx, edx
// 004d213a  0f85ac000000         jne 0x4d21ec
// 004d2140  8d8fb0070000         lea ecx, [edi + 0x7b0]
// 004d2146  e8b5d7ffff           call 0x4cf900
// 004d214b  8b0e                 mov ecx, dword ptr [esi]
// 004d214d  8b14a9               mov edx, dword ptr [ecx + ebp*4]
// 004d2150  8bf8                 mov edi, eax
// 004d2152  8b4208               mov eax, dword ptr [edx + 8]
// 004d2155  8b08                 mov ecx, dword ptr [eax]
// 004d2157  8b5938               mov ebx, dword ptr [ecx + 0x38]
// 004d215a  83c307               add ebx, 7
// 004d215d  c1eb03               shr ebx, 3
// 004d2160  83c30d               add ebx, 0xd
// 004d2163  53                   push ebx
// 004d2164  897c2424             mov dword ptr [esp + 0x24], edi
// 004d2168  e8b3e71c00           call 0x6a0920
// 004d216d  89473c               mov dword ptr [edi + 0x3c], eax
// 004d2170  8d14dd00000000       lea edx, [ebx*8]
// 004d2177  895738               mov dword ptr [edi + 0x38], edx
// 004d217a  8b473c               mov eax, dword ptr [edi + 0x3c]
// 004d217d  c6001e               mov byte ptr [eax], 0x1e
// 004d2180  8b0e                 mov ecx, dword ptr [esi]
// 004d2182  8b14a9               mov edx, dword ptr [ecx + ebp*4]
// 004d2185  8b4a0c               mov ecx, dword ptr [edx + 0xc]
// 004d2188  8b473c               mov eax, dword ptr [edi + 0x3c]
// 004d218b  894801               mov dword ptr [eax + 1], ecx
// 004d218e  8b573c               mov edx, dword ptr [edi + 0x3c]
// 004d2191  8b442420             mov eax, dword ptr [esp + 0x20]
// 004d2195  8b4824               mov ecx, dword ptr [eax + 0x24]
// 004d2198  894a05               mov dword ptr [edx + 5], ecx
// 004d219b  8b16                 mov edx, dword ptr [esi]
// 004d219d  8b04aa               mov eax, dword ptr [edx + ebp*4]
// 004d21a0  8b4808               mov ecx, dword ptr [eax + 8]
// 004d21a3  8b11                 mov edx, dword ptr [ecx]
// 004d21a5  8b4238               mov eax, dword ptr [edx + 0x38]
// 004d21a8  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 004d21ab  83c007               add eax, 7
// 004d21ae  c1e803               shr eax, 3
// 004d21b1  894109               mov dword ptr [ecx + 9], eax
// 004d21b4  8b16                 mov edx, dword ptr [esi]
// 004d21b6  8b04aa               mov eax, dword ptr [edx + ebp*4]
// 004d21b9  8b4808               mov ecx, dword ptr [eax + 8]
// 004d21bc  8b01                 mov eax, dword ptr [ecx]
// 004d21be  8b5038               mov edx, dword ptr [eax + 0x38]
// 004d21c1  8b403c               mov eax, dword ptr [eax + 0x3c]
// 004d21c4  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 004d21c7  83c207               add edx, 7
// 004d21ca  c1ea03               shr edx, 3
// 004d21cd  52                   push edx
// 004d21ce  50                   push eax
// 004d21cf  83c10d               add ecx, 0xd
// 004d21d2  51                   push ecx
// 004d21d3  e808f61c00           call 0x6a17e0
// 004d21d8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004d21dc  83c410               add esp, 0x10
// 004d21df  8d542420             lea edx, [esp + 0x20]
// 004d21e3  52                   push edx
// 004d21e4  83c10c               add ecx, 0xc
// 004d21e7  e8f4cbffff           call 0x4cede0
// 004d21ec  5f                   pop edi
// 004d21ed  5e                   pop esi
// 004d21ee  5d                   pop ebp
// 004d21ef  5b                   pop ebx
// 004d21f0  83c408               add esp, 8
// 004d21f3  c20c00               ret 0xc
// library openrbx-raknet/ReliabilityLayer.cpp (function ?InsertIntoSplitPacketList@ReliabilityLayer@@AAEXPAUInternalPacket@@_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
