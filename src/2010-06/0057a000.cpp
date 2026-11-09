// from server: 100% by auto
// roc 2010-06 0057a000  unit: seg_00570000  size: 767 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0057a000
//
// 0057a000  83ec10               sub esp, 0x10
// 0057a003  56                   push esi
// 0057a004  8b742418             mov esi, dword ptr [esp + 0x18]
// 0057a008  8b4668               mov eax, dword ptr [esi + 0x68]
// 0057a00b  57                   push edi
// 0057a00c  a801                 test al, 1
// 0057a00e  7552                 jne 0x57a062
// 0057a010  68f876a200           push 0xa276f8
// 0057a015  56                   push esi
// 0057a016  e8957affff           call 0x571ab0
// 0057a01b  83c408               add esp, 8
// 0057a01e  33ff                 xor edi, edi
// 0057a020  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0057a026  53                   push ebx
// 0057a027  55                   push ebp
// 0057a028  52                   push edx
// 0057a029  56                   push esi
// 0057a02a  e8d185ffff           call 0x572600
// 0057a02f  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0057a033  8d4501               lea eax, [ebp + 1]
// 0057a036  50                   push eax
// 0057a037  56                   push esi
// 0057a038  e8f385ffff           call 0x572630
// 0057a03d  8bd8                 mov ebx, eax
// 0057a03f  83c410               add esp, 0x10
// 0057a042  899e88020000         mov dword ptr [esi + 0x288], ebx
// 0057a048  3bdf                 cmp ebx, edi
// 0057a04a  756b                 jne 0x57a0b7
// 0057a04c  68dc76a200           push 0xa276dc
// 0057a051  56                   push esi
// 0057a052  e8097bffff           call 0x571b60
// 0057a057  83c408               add esp, 8
// 0057a05a  5d                   pop ebp
// 0057a05b  5b                   pop ebx
// 0057a05c  5f                   pop edi
// 0057a05d  5e                   pop esi
// 0057a05e  83c410               add esp, 0x10
// 0057a061  c3                   ret 
// 0057a062  a804                 test al, 4
// 0057a064  741f                 je 0x57a085
// 0057a066  68c476a200           push 0xa276c4
// 0057a06b  56                   push esi
// 0057a06c  e8ef7affff           call 0x571b60
// 0057a071  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0057a075  50                   push eax
// 0057a076  56                   push esi
// 0057a077  e894e4ffff           call 0x578510
// 0057a07c  83c410               add esp, 0x10
// 0057a07f  5f                   pop edi
// 0057a080  5e                   pop esi
// 0057a081  83c410               add esp, 0x10
// 0057a084  c3                   ret 
// 0057a085  8b442420             mov eax, dword ptr [esp + 0x20]
// 0057a089  33ff                 xor edi, edi
// 0057a08b  3bc7                 cmp eax, edi
// 0057a08d  7491                 je 0x57a020
// 0057a08f  f7400800040000       test dword ptr [eax + 8], 0x400
// 0057a096  7488                 je 0x57a020
// 0057a098  68ac76a200           push 0xa276ac
// 0057a09d  56                   push esi
// 0057a09e  e8bd7affff           call 0x571b60
// 0057a0a3  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0057a0a7  51                   push ecx
// 0057a0a8  56                   push esi
// 0057a0a9  e862e4ffff           call 0x578510
// 0057a0ae  83c410               add esp, 0x10
// 0057a0b1  5f                   pop edi
// 0057a0b2  5e                   pop esi
// 0057a0b3  83c410               add esp, 0x10
// 0057a0b6  c3                   ret 
// 0057a0b7  55                   push ebp
// 0057a0b8  53                   push ebx
// 0057a0b9  56                   push esi
// 0057a0ba  e85123ffff           call 0x56c410
// 0057a0bf  55                   push ebp
// 0057a0c0  53                   push ebx
// 0057a0c1  56                   push esi
// 0057a0c2  e819affeff           call 0x564fe0
// 0057a0c7  57                   push edi
// 0057a0c8  56                   push esi
// 0057a0c9  e842e4ffff           call 0x578510
// 0057a0ce  83c420               add esp, 0x20
// 0057a0d1  85c0                 test eax, eax
// 0057a0d3  741e                 je 0x57a0f3
// 0057a0d5  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0057a0db  51                   push ecx
// 0057a0dc  56                   push esi
// 0057a0dd  e81e85ffff           call 0x572600
// 0057a0e2  83c408               add esp, 8
// 0057a0e5  5d                   pop ebp
// 0057a0e6  5b                   pop ebx
// 0057a0e7  89be88020000         mov dword ptr [esi + 0x288], edi
// 0057a0ed  5f                   pop edi
// 0057a0ee  5e                   pop esi
// 0057a0ef  83c410               add esp, 0x10
// 0057a0f2  c3                   ret 
// 0057a0f3  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0057a0f9  c6042a00             mov byte ptr [edx + ebp], 0
// 0057a0fd  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0057a103  8bc1                 mov eax, ecx
// 0057a105  803800               cmp byte ptr [eax], 0
// 0057a108  740c                 je 0x57a116
// 0057a10a  8d9b00000000         lea ebx, [ebx]
// 0057a110  40                   inc eax
// 0057a111  803800               cmp byte ptr [eax], 0
// 0057a114  75fa                 jne 0x57a110
// 0057a116  03cd                 add ecx, ebp
// 0057a118  8d500c               lea edx, [eax + 0xc]
// 0057a11b  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0057a11f  3bca                 cmp ecx, edx
// 0057a121  770a                 ja 0x57a12d
// 0057a123  689876a200           push 0xa27698
// 0057a128  e985000000           jmp 0x57a1b2
// 0057a12d  0fb66801             movzx ebp, byte ptr [eax + 1]
// 0057a131  0fb64802             movzx ecx, byte ptr [eax + 2]
// 0057a135  0fb65003             movzx edx, byte ptr [eax + 3]
// 0057a139  0fb65805             movzx ebx, byte ptr [eax + 5]
// 0057a13d  c1e508               shl ebp, 8
// 0057a140  03e9                 add ebp, ecx
// 0057a142  0fb64804             movzx ecx, byte ptr [eax + 4]
// 0057a146  c1e508               shl ebp, 8
// 0057a149  03ea                 add ebp, edx
// 0057a14b  0fb65006             movzx edx, byte ptr [eax + 6]
// 0057a14f  c1e308               shl ebx, 8
// 0057a152  03da                 add ebx, edx
// 0057a154  0fb65008             movzx edx, byte ptr [eax + 8]
// 0057a158  c1e508               shl ebp, 8
// 0057a15b  03e9                 add ebp, ecx
// 0057a15d  0fb64807             movzx ecx, byte ptr [eax + 7]
// 0057a161  c1e308               shl ebx, 8
// 0057a164  03d9                 add ebx, ecx
// 0057a166  8a4809               mov cl, byte ptr [eax + 9]
// 0057a169  c1e308               shl ebx, 8
// 0057a16c  03da                 add ebx, edx
// 0057a16e  8a500a               mov dl, byte ptr [eax + 0xa]
// 0057a171  83c00b               add eax, 0xb
// 0057a174  884c2413             mov byte ptr [esp + 0x13], cl
// 0057a178  88542424             mov byte ptr [esp + 0x24], dl
// 0057a17c  89442414             mov dword ptr [esp + 0x14], eax
// 0057a180  84c9                 test cl, cl
// 0057a182  7507                 jne 0x57a18b
// 0057a184  80fa02               cmp dl, 2
// 0057a187  7524                 jne 0x57a1ad
// 0057a189  eb66                 jmp 0x57a1f1
// 0057a18b  80f901               cmp cl, 1
// 0057a18e  7507                 jne 0x57a197
// 0057a190  80fa03               cmp dl, 3
// 0057a193  7518                 jne 0x57a1ad
// 0057a195  eb5a                 jmp 0x57a1f1
// 0057a197  80f902               cmp cl, 2
// 0057a19a  7507                 jne 0x57a1a3
// 0057a19c  80fa03               cmp dl, 3
// 0057a19f  750c                 jne 0x57a1ad
// 0057a1a1  eb4e                 jmp 0x57a1f1
// 0057a1a3  80f903               cmp cl, 3
// 0057a1a6  752e                 jne 0x57a1d6
// 0057a1a8  80fa04               cmp dl, 4
// 0057a1ab  7444                 je 0x57a1f1
// 0057a1ad  686c76a200           push 0xa2766c
// 0057a1b2  56                   push esi
// 0057a1b3  e8a879ffff           call 0x571b60
// 0057a1b8  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0057a1be  50                   push eax
// 0057a1bf  56                   push esi
// 0057a1c0  e83b84ffff           call 0x572600
// 0057a1c5  83c410               add esp, 0x10
// 0057a1c8  5d                   pop ebp
// 0057a1c9  5b                   pop ebx
// 0057a1ca  89be88020000         mov dword ptr [esi + 0x288], edi
// 0057a1d0  5f                   pop edi
// 0057a1d1  5e                   pop esi
// 0057a1d2  83c410               add esp, 0x10
// 0057a1d5  c3                   ret 
// 0057a1d6  80f904               cmp cl, 4
// 0057a1d9  7216                 jb 0x57a1f1
// 0057a1db  681c39a200           push 0xa2391c
// 0057a1e0  56                   push esi
// 0057a1e1  e87a79ffff           call 0x571b60
// 0057a1e6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0057a1ea  8a54242c             mov dl, byte ptr [esp + 0x2c]
// 0057a1ee  83c408               add esp, 8
// 0057a1f1  803800               cmp byte ptr [eax], 0
// 0057a1f4  8bf8                 mov edi, eax
// 0057a1f6  7406                 je 0x57a1fe
// 0057a1f8  47                   inc edi
// 0057a1f9  803f00               cmp byte ptr [edi], 0
// 0057a1fc  75fa                 jne 0x57a1f8
// 0057a1fe  0fb6c2               movzx eax, dl
// 0057a201  8d0c8500000000       lea ecx, [eax*4]
// 0057a208  51                   push ecx
// 0057a209  56                   push esi
// 0057a20a  8944242c             mov dword ptr [esp + 0x2c], eax
// 0057a20e  e81d84ffff           call 0x572630
// 0057a213  83c408               add esp, 8
// 0057a216  89442418             mov dword ptr [esp + 0x18], eax
// 0057a21a  85c0                 test eax, eax
// 0057a21c  752d                 jne 0x57a24b
// 0057a21e  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0057a224  52                   push edx
// 0057a225  56                   push esi
// 0057a226  e8d583ffff           call 0x572600
// 0057a22b  685076a200           push 0xa27650
// 0057a230  56                   push esi
// 0057a231  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0057a23b  e82079ffff           call 0x571b60
// 0057a240  83c410               add esp, 0x10
// 0057a243  5d                   pop ebp
// 0057a244  5b                   pop ebx
// 0057a245  5f                   pop edi
// 0057a246  5e                   pop esi
// 0057a247  83c410               add esp, 0x10
// 0057a24a  c3                   ret 
// 0057a24b  33d2                 xor edx, edx
// 0057a24d  39542424             cmp dword ptr [esp + 0x24], edx
// 0057a251  7e5a                 jle 0x57a2ad
// 0057a253  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0057a257  47                   inc edi
// 0057a258  893c90               mov dword ptr [eax + edx*4], edi
// 0057a25b  3bf9                 cmp edi, ecx
// 0057a25d  770b                 ja 0x57a26a
// 0057a25f  90                   nop 
// 0057a260  803f00               cmp byte ptr [edi], 0
// 0057a263  743d                 je 0x57a2a2
// 0057a265  47                   inc edi
// 0057a266  3bf9                 cmp edi, ecx
// 0057a268  76f6                 jbe 0x57a260
// 0057a26a  689876a200           push 0xa27698
// 0057a26f  56                   push esi
// 0057a270  e8eb78ffff           call 0x571b60
// 0057a275  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0057a27b  50                   push eax
// 0057a27c  56                   push esi
// 0057a27d  e87e83ffff           call 0x572600
// 0057a282  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0057a286  51                   push ecx
// 0057a287  56                   push esi
// 0057a288  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0057a292  e86983ffff           call 0x572600
// 0057a297  83c418               add esp, 0x18
// 0057a29a  5d                   pop ebp
// 0057a29b  5b                   pop ebx
// 0057a29c  5f                   pop edi
// 0057a29d  5e                   pop esi
// 0057a29e  83c410               add esp, 0x10
// 0057a2a1  c3                   ret 
// 0057a2a2  3bf9                 cmp edi, ecx
// 0057a2a4  77c4                 ja 0x57a26a
// 0057a2a6  42                   inc edx
// 0057a2a7  3b542424             cmp edx, dword ptr [esp + 0x24]
// 0057a2ab  7ca6                 jl 0x57a253
// 0057a2ad  8b542414             mov edx, dword ptr [esp + 0x14]
// 0057a2b1  0fb64c2413           movzx ecx, byte ptr [esp + 0x13]
// 0057a2b6  50                   push eax
// 0057a2b7  8b442428             mov eax, dword ptr [esp + 0x28]
// 0057a2bb  52                   push edx
// 0057a2bc  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0057a2c2  50                   push eax
// 0057a2c3  8b442434             mov eax, dword ptr [esp + 0x34]
// 0057a2c7  51                   push ecx
// 0057a2c8  53                   push ebx
// 0057a2c9  55                   push ebp
// 0057a2ca  52                   push edx
// 0057a2cb  50                   push eax
// 0057a2cc  56                   push esi
// 0057a2cd  e88e9ffeff           call 0x564260
// 0057a2d2  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0057a2d8  51                   push ecx
// 0057a2d9  56                   push esi
// 0057a2da  e82183ffff           call 0x572600
// 0057a2df  8b542444             mov edx, dword ptr [esp + 0x44]
// 0057a2e3  52                   push edx
// 0057a2e4  56                   push esi
// 0057a2e5  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0057a2ef  e80c83ffff           call 0x572600
// 0057a2f4  83c434               add esp, 0x34
// 0057a2f7  5d                   pop ebp
// 0057a2f8  5b                   pop ebx
// 0057a2f9  5f                   pop edi
// 0057a2fa  5e                   pop esi
// 0057a2fb  83c410               add esp, 0x10
// 0057a2fe  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
