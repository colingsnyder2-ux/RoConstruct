// from server: 100% by auto
// roc 2008-06 004bf060  unit: ProfiledRakPeer  size: 606 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bf060
//
// 004bf060  55                   push ebp
// 004bf061  8bec                 mov ebp, esp
// 004bf063  83ec14               sub esp, 0x14
// 004bf066  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004bf069  8b08                 mov ecx, dword ptr [eax]
// 004bf06b  53                   push ebx
// 004bf06c  8b580c               mov ebx, dword ptr [eax + 0xc]
// 004bf06f  56                   push esi
// 004bf070  8b7008               mov esi, dword ptr [eax + 8]
// 004bf073  57                   push edi
// 004bf074  8b7804               mov edi, dword ptr [eax + 4]
// 004bf077  8b4508               mov eax, dword ptr [ebp + 8]
// 004bf07a  8b10                 mov edx, dword ptr [eax]
// 004bf07c  894dec               mov dword ptr [ebp - 0x14], ecx
// 004bf07f  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 004bf082  8911                 mov dword ptr [ecx], edx
// 004bf084  8b5004               mov edx, dword ptr [eax + 4]
// 004bf087  895104               mov dword ptr [ecx + 4], edx
// 004bf08a  8b5008               mov edx, dword ptr [eax + 8]
// 004bf08d  895108               mov dword ptr [ecx + 8], edx
// 004bf090  8b400c               mov eax, dword ptr [eax + 0xc]
// 004bf093  c745fc01000000       mov dword ptr [ebp - 4], 1
// 004bf09a  897df0               mov dword ptr [ebp - 0x10], edi
// 004bf09d  8975f4               mov dword ptr [ebp - 0xc], esi
// 004bf0a0  895df8               mov dword ptr [ebp - 8], ebx
// 004bf0a3  89410c               mov dword ptr [ecx + 0xc], eax
// 004bf0a6  85db                 test ebx, ebx
// 004bf0a8  0f88e6010000         js 0x4bf294
// 004bf0ae  8d55ec               lea edx, [ebp - 0x14]
// 004bf0b1  52                   push edx
// 004bf0b2  51                   push ecx
// 004bf0b3  e878d5ffff           call 0x4bc630
// 004bf0b8  83c408               add esp, 8
// 004bf0bb  84c0                 test al, al
// 004bf0bd  0f84ce010000         je 0x4bf291
// 004bf0c3  b803000000           mov eax, 3
// 004bf0c8  eb06                 jmp 0x4bf0d0
// 004bf0ca  8d9b00000000         lea ebx, [ebx]
// 004bf0d0  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 004bf0d3  833c8100             cmp dword ptr [ecx + eax*4], 0
// 004bf0d7  7505                 jne 0x4bf0de
// 004bf0d9  83e801               sub eax, 1
// 004bf0dc  79f2                 jns 0x4bf0d0
// 004bf0de  8bc8                 mov ecx, eax
// 004bf0e0  85c0                 test eax, eax
// 004bf0e2  7c31                 jl 0x4bf115
// 004bf0e4  837c8dec00           cmp dword ptr [ebp + ecx*4 - 0x14], 0
// 004bf0e9  7505                 jne 0x4bf0f0
// 004bf0eb  83e901               sub ecx, 1
// 004bf0ee  79f4                 jns 0x4bf0e4
// 004bf0f0  3bc1                 cmp eax, ecx
// 004bf0f2  7421                 je 0x4bf115
// 004bf0f4  2bc1                 sub eax, ecx
// 004bf0f6  c1e005               shl eax, 5
// 004bf0f9  8bf0                 mov esi, eax
// 004bf0fb  8d55ec               lea edx, [ebp - 0x14]
// 004bf0fe  56                   push esi
// 004bf0ff  52                   push edx
// 004bf100  e8ebdaffff           call 0x4bcbf0
// 004bf105  8b5df8               mov ebx, dword ptr [ebp - 8]
// 004bf108  8b7df0               mov edi, dword ptr [ebp - 0x10]
// 004bf10b  83c408               add esp, 8
// 004bf10e  46                   inc esi
// 004bf10f  8975fc               mov dword ptr [ebp - 4], esi
// 004bf112  8b75f4               mov esi, dword ptr [ebp - 0xc]
// 004bf115  85db                 test ebx, ebx
// 004bf117  7857                 js 0x4bf170
// 004bf119  8da42400000000       lea esp, [esp]
// 004bf120  b803000000           mov eax, 3
// 004bf125  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 004bf128  8b0c81               mov ecx, dword ptr [ecx + eax*4]
// 004bf12b  8b5485ec             mov edx, dword ptr [ebp + eax*4 - 0x14]
// 004bf12f  3bca                 cmp ecx, edx
// 004bf131  7709                 ja 0x4bf13c
// 004bf133  723b                 jb 0x4bf170
// 004bf135  83e801               sub eax, 1
// 004bf138  79eb                 jns 0x4bf125
// 004bf13a  eb34                 jmp 0x4bf170
// 004bf13c  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004bf13f  ff45fc               inc dword ptr [ebp - 4]
// 004bf142  8bc1                 mov eax, ecx
// 004bf144  03c9                 add ecx, ecx
// 004bf146  894dec               mov dword ptr [ebp - 0x14], ecx
// 004bf149  c1e81f               shr eax, 0x1f
// 004bf14c  8bcf                 mov ecx, edi
// 004bf14e  03ff                 add edi, edi
// 004bf150  0bf8                 or edi, eax
// 004bf152  8bc6                 mov eax, esi
// 004bf154  c1e81f               shr eax, 0x1f
// 004bf157  03db                 add ebx, ebx
// 004bf159  c1e91f               shr ecx, 0x1f
// 004bf15c  03f6                 add esi, esi
// 004bf15e  0bd8                 or ebx, eax
// 004bf160  0bf1                 or esi, ecx
// 004bf162  897df0               mov dword ptr [ebp - 0x10], edi
// 004bf165  8975f4               mov dword ptr [ebp - 0xc], esi
// 004bf168  895df8               mov dword ptr [ebp - 8], ebx
// 004bf16b  85db                 test ebx, ebx
// 004bf16d  79b1                 jns 0x4bf120
// 004bf16f  90                   nop 
// 004bf170  b803000000           mov eax, 3
// 004bf175  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004bf178  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 004bf17b  8b5485ec             mov edx, dword ptr [ebp + eax*4 - 0x14]
// 004bf17f  3bd1                 cmp edx, ecx
// 004bf181  0f87d6000000         ja 0x4bf25d
// 004bf187  7205                 jb 0x4bf18e
// 004bf189  83e801               sub eax, 1
// 004bf18c  79e7                 jns 0x4bf175
// 004bf18e  837dfc00             cmp dword ptr [ebp - 4], 0
// 004bf192  0f84be000000         je 0x4bf256
// 004bf198  eb06                 jmp 0x4bf1a0
// 004bf19a  8d9b00000000         lea ebx, [ebx]
// 004bf1a0  ff4dfc               dec dword ptr [ebp - 4]
// 004bf1a3  b803000000           mov eax, 3
// 004bf1a8  eb06                 jmp 0x4bf1b0
// 004bf1aa  8d9b00000000         lea ebx, [ebx]
// 004bf1b0  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004bf1b3  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 004bf1b6  8b5485ec             mov edx, dword ptr [ebp + eax*4 - 0x14]
// 004bf1ba  3bd1                 cmp edx, ecx
// 004bf1bc  7762                 ja 0x4bf220
// 004bf1be  7205                 jb 0x4bf1c5
// 004bf1c0  83e801               sub eax, 1
// 004bf1c3  79eb                 jns 0x4bf1b0
// 004bf1c5  8d45ec               lea eax, [ebp - 0x14]
// 004bf1c8  894508               mov dword ptr [ebp + 8], eax
// 004bf1cb  c7450c00000000       mov dword ptr [ebp + 0xc], 0
// 004bf1d2  8b7508               mov esi, dword ptr [ebp + 8]
// 004bf1d5  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004bf1d8  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004bf1db  8b06                 mov eax, dword ptr [esi]
// 004bf1dd  33d2                 xor edx, edx
// 004bf1df  2907                 sub dword ptr [edi], eax
// 004bf1e1  8b4604               mov eax, dword ptr [esi + 4]
// 004bf1e4  194704               sbb dword ptr [edi + 4], eax
// 004bf1e7  8b4608               mov eax, dword ptr [esi + 8]
// 004bf1ea  194708               sbb dword ptr [edi + 8], eax
// 004bf1ed  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bf1f0  19470c               sbb dword ptr [edi + 0xc], eax
// 004bf1f3  e322                 jecxz 0x4bf217
// 004bf1f5  42                   inc edx
// 004bf1f6  42                   inc edx
// 004bf1f7  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004bf1fa  1904d7               sbb dword ptr [edi + edx*8], eax
// 004bf1fd  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004bf201  1944d704             sbb dword ptr [edi + edx*8 + 4], eax
// 004bf205  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004bf209  1944d708             sbb dword ptr [edi + edx*8 + 8], eax
// 004bf20d  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004bf211  1944d70c             sbb dword ptr [edi + edx*8 + 0xc], eax
// 004bf215  e2de                 loop 0x4bf1f5
// 004bf217  8b5df8               mov ebx, dword ptr [ebp - 8]
// 004bf21a  8b75f4               mov esi, dword ptr [ebp - 0xc]
// 004bf21d  8b7df0               mov edi, dword ptr [ebp - 0x10]
// 004bf220  8bc3                 mov eax, ebx
// 004bf222  c1e01f               shl eax, 0x1f
// 004bf225  8bce                 mov ecx, esi
// 004bf227  d1ee                 shr esi, 1
// 004bf229  0bf0                 or esi, eax
// 004bf22b  c1e11f               shl ecx, 0x1f
// 004bf22e  8bc7                 mov eax, edi
// 004bf230  d1ef                 shr edi, 1
// 004bf232  0bf9                 or edi, ecx
// 004bf234  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004bf237  c1e01f               shl eax, 0x1f
// 004bf23a  d1e9                 shr ecx, 1
// 004bf23c  d1eb                 shr ebx, 1
// 004bf23e  0bc8                 or ecx, eax
// 004bf240  837dfc00             cmp dword ptr [ebp - 4], 0
// 004bf244  895df8               mov dword ptr [ebp - 8], ebx
// 004bf247  8975f4               mov dword ptr [ebp - 0xc], esi
// 004bf24a  897df0               mov dword ptr [ebp - 0x10], edi
// 004bf24d  894dec               mov dword ptr [ebp - 0x14], ecx
// 004bf250  0f854affffff         jne 0x4bf1a0
// 004bf256  5f                   pop edi
// 004bf257  5e                   pop esi
// 004bf258  5b                   pop ebx
// 004bf259  8be5                 mov esp, ebp
// 004bf25b  5d                   pop ebp
// 004bf25c  c3                   ret 
// 004bf25d  8bc3                 mov eax, ebx
// 004bf25f  c1e01f               shl eax, 0x1f
// 004bf262  8bce                 mov ecx, esi
// 004bf264  d1ee                 shr esi, 1
// 004bf266  0bf0                 or esi, eax
// 004bf268  c1e11f               shl ecx, 0x1f
// 004bf26b  8bc7                 mov eax, edi
// 004bf26d  d1ef                 shr edi, 1
// 004bf26f  0bf9                 or edi, ecx
// 004bf271  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004bf274  c1e01f               shl eax, 0x1f
// 004bf277  d1e9                 shr ecx, 1
// 004bf279  d1eb                 shr ebx, 1
// 004bf27b  0bc8                 or ecx, eax
// 004bf27d  ff4dfc               dec dword ptr [ebp - 4]
// 004bf280  895df8               mov dword ptr [ebp - 8], ebx
// 004bf283  8975f4               mov dword ptr [ebp - 0xc], esi
// 004bf286  897df0               mov dword ptr [ebp - 0x10], edi
// 004bf289  894dec               mov dword ptr [ebp - 0x14], ecx
// 004bf28c  e9dffeffff           jmp 0x4bf170
// 004bf291  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 004bf294  b803000000           mov eax, 3
// 004bf299  eb08                 jmp 0x4bf2a3
// 004bf29b  eb03                 jmp 0x4bf2a0
// 004bf29d  8d4900               lea ecx, [ecx]
// 004bf2a0  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 004bf2a3  8b0c81               mov ecx, dword ptr [ecx + eax*4]
// 004bf2a6  8b5485ec             mov edx, dword ptr [ebp + eax*4 - 0x14]
// 004bf2aa  3bd1                 cmp edx, ecx
// 004bf2ac  77a8                 ja 0x4bf256
// 004bf2ae  0f82ecfeffff         jb 0x4bf1a0
// 004bf2b4  83e801               sub eax, 1
// 004bf2b7  79e7                 jns 0x4bf2a0
// 004bf2b9  e9e2feffff           jmp 0x4bf1a0
// library openrbx-raknet/RakPeer.cpp (function ??$umodulo@$$BY03I@big@@YAXAAY03I00@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
