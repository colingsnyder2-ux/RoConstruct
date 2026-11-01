// from server: 100% by auto
// roc 2007-03 005081b0  unit: seg_00500000  size: 724 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005081b0
//
// 005081b0  53                   push ebx
// 005081b1  55                   push ebp
// 005081b2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005081b6  56                   push esi
// 005081b7  8b742414             mov esi, dword ptr [esp + 0x14]
// 005081bb  57                   push edi
// 005081bc  56                   push esi
// 005081bd  55                   push ebp
// 005081be  e81dfeffff           call 0x507fe0
// 005081c3  83c408               add esp, 8
// 005081c6  f6460808             test byte ptr [esi + 8], 8
// 005081ca  7414                 je 0x5081e0
// 005081cc  0fb74614             movzx eax, word ptr [esi + 0x14]
// 005081d0  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005081d3  50                   push eax
// 005081d4  51                   push ecx
// 005081d5  55                   push ebp
// 005081d6  e865d20000           call 0x515440
// 005081db  83c40c               add esp, 0xc
// 005081de  eb14                 jmp 0x5081f4
// 005081e0  807e1903             cmp byte ptr [esi + 0x19], 3
// 005081e4  750e                 jne 0x5081f4
// 005081e6  68fc077a00           push 0x7a07fc
// 005081eb  55                   push ebp
// 005081ec  e82f010100           call 0x518320
// 005081f1  83c408               add esp, 8
// 005081f4  f6460810             test byte ptr [esi + 8], 0x10
// 005081f8  744a                 je 0x508244
// 005081fa  f7457000000800       test dword ptr [ebp + 0x70], 0x80000
// 00508201  7426                 je 0x508229
// 00508203  807e1903             cmp byte ptr [esi + 0x19], 3
// 00508207  7520                 jne 0x508229
// 00508209  33c0                 xor eax, eax
// 0050820b  66394616             cmp word ptr [esi + 0x16], ax
// 0050820f  7618                 jbe 0x508229
// 00508211  8b564c               mov edx, dword ptr [esi + 0x4c]
// 00508214  8d0c10               lea ecx, [eax + edx]
// 00508217  80caff               or dl, 0xff
// 0050821a  2a11                 sub dl, byte ptr [ecx]
// 0050821c  83c001               add eax, 1
// 0050821f  8811                 mov byte ptr [ecx], dl
// 00508221  0fb74e16             movzx ecx, word ptr [esi + 0x16]
// 00508225  3bc1                 cmp eax, ecx
// 00508227  7ce8                 jl 0x508211
// 00508229  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 0050822d  0fb74616             movzx eax, word ptr [esi + 0x16]
// 00508231  52                   push edx
// 00508232  8b564c               mov edx, dword ptr [esi + 0x4c]
// 00508235  50                   push eax
// 00508236  8d4e50               lea ecx, [esi + 0x50]
// 00508239  51                   push ecx
// 0050823a  52                   push edx
// 0050823b  55                   push ebp
// 0050823c  e87fea0000           call 0x516cc0
// 00508241  83c414               add esp, 0x14
// 00508244  f6460820             test byte ptr [esi + 8], 0x20
// 00508248  7412                 je 0x50825c
// 0050824a  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0050824e  50                   push eax
// 0050824f  8d4e5a               lea ecx, [esi + 0x5a]
// 00508252  51                   push ecx
// 00508253  55                   push ebp
// 00508254  e8b7eb0000           call 0x516e10
// 00508259  83c40c               add esp, 0xc
// 0050825c  f6460840             test byte ptr [esi + 8], 0x40
// 00508260  7412                 je 0x508274
// 00508262  0fb75614             movzx edx, word ptr [esi + 0x14]
// 00508266  8b467c               mov eax, dword ptr [esi + 0x7c]
// 00508269  52                   push edx
// 0050826a  50                   push eax
// 0050826b  55                   push ebp
// 0050826c  e88fd20000           call 0x515500
// 00508271  83c40c               add esp, 0xc
// 00508274  f7460800010000       test dword ptr [esi + 8], 0x100
// 0050827b  7416                 je 0x508293
// 0050827d  0fb64e6c             movzx ecx, byte ptr [esi + 0x6c]
// 00508281  8b5668               mov edx, dword ptr [esi + 0x68]
// 00508284  8b4664               mov eax, dword ptr [esi + 0x64]
// 00508287  51                   push ecx
// 00508288  52                   push edx
// 00508289  50                   push eax
// 0050828a  55                   push ebp
// 0050828b  e810ed0000           call 0x516fa0
// 00508290  83c410               add esp, 0x10
// 00508293  f7460800040000       test dword ptr [esi + 8], 0x400
// 0050829a  743c                 je 0x5082d8
// 0050829c  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 005082a2  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 005082a8  0fb686b5000000       movzx eax, byte ptr [esi + 0xb5]
// 005082af  51                   push ecx
// 005082b0  0fb68eb4000000       movzx ecx, byte ptr [esi + 0xb4]
// 005082b7  52                   push edx
// 005082b8  8b96a8000000         mov edx, dword ptr [esi + 0xa8]
// 005082be  50                   push eax
// 005082bf  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 005082c5  51                   push ecx
// 005082c6  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 005082cc  52                   push edx
// 005082cd  50                   push eax
// 005082ce  51                   push ecx
// 005082cf  55                   push ebp
// 005082d0  e86bd60000           call 0x515940
// 005082d5  83c420               add esp, 0x20
// 005082d8  f7460800400000       test dword ptr [esi + 8], 0x4000
// 005082df  7427                 je 0x508308
// 005082e1  dd86e8000000         fld qword ptr [esi + 0xe8]
// 005082e7  0fb696dc000000       movzx edx, byte ptr [esi + 0xdc]
// 005082ee  83ec10               sub esp, 0x10
// 005082f1  dd5c2408             fstp qword ptr [esp + 8]
// 005082f5  dd86e0000000         fld qword ptr [esi + 0xe0]
// 005082fb  dd1c24               fstp qword ptr [esp]
// 005082fe  52                   push edx
// 005082ff  55                   push ebp
// 00508300  e8ebd70000           call 0x515af0
// 00508305  83c418               add esp, 0x18
// 00508308  f6460880             test byte ptr [esi + 8], 0x80
// 0050830c  7416                 je 0x508324
// 0050830e  0fb64678             movzx eax, byte ptr [esi + 0x78]
// 00508312  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 00508315  8b5670               mov edx, dword ptr [esi + 0x70]
// 00508318  50                   push eax
// 00508319  51                   push ecx
// 0050831a  52                   push edx
// 0050831b  55                   push ebp
// 0050831c  e8ffec0000           call 0x517020
// 00508321  83c410               add esp, 0x10
// 00508324  bf00020000           mov edi, 0x200
// 00508329  857e08               test dword ptr [esi + 8], edi
// 0050832c  7410                 je 0x50833e
// 0050832e  8d463c               lea eax, [esi + 0x3c]
// 00508331  50                   push eax
// 00508332  55                   push ebp
// 00508333  e868ed0000           call 0x5170a0
// 00508338  83c408               add esp, 8
// 0050833b  097d68               or dword ptr [ebp + 0x68], edi
// 0050833e  f7460800200000       test dword ptr [esi + 8], 0x2000
// 00508345  742c                 je 0x508373
// 00508347  33ff                 xor edi, edi
// 00508349  39bed8000000         cmp dword ptr [esi + 0xd8], edi
// 0050834f  7e22                 jle 0x508373
// 00508351  33db                 xor ebx, ebx
// 00508353  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 00508359  03cb                 add ecx, ebx
// 0050835b  51                   push ecx
// 0050835c  55                   push ebp
// 0050835d  e8cee20000           call 0x516630
// 00508362  83c701               add edi, 1
// 00508365  83c408               add esp, 8
// 00508368  83c310               add ebx, 0x10
// 0050836b  3bbed8000000         cmp edi, dword ptr [esi + 0xd8]
// 00508371  7ce0                 jl 0x508353
// 00508373  33db                 xor ebx, ebx
// 00508375  395e30               cmp dword ptr [esi + 0x30], ebx
// 00508378  0f8e87000000         jle 0x508405
// 0050837e  33ff                 xor edi, edi
// 00508380  8b5638               mov edx, dword ptr [esi + 0x38]
// 00508383  8b0417               mov eax, dword ptr [edi + edx]
// 00508386  85c0                 test eax, eax
// 00508388  7e1a                 jle 0x5083a4
// 0050838a  68d8077a00           push 0x7a07d8
// 0050838f  55                   push ebp
// 00508390  e83b000100           call 0x5183d0
// 00508395  8b4638               mov eax, dword ptr [esi + 0x38]
// 00508398  83c408               add esp, 8
// 0050839b  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 005083a2  eb52                 jmp 0x5083f6
// 005083a4  7528                 jne 0x5083ce
// 005083a6  8bca                 mov ecx, edx
// 005083a8  8b140f               mov edx, dword ptr [edi + ecx]
// 005083ab  8d040f               lea eax, [edi + ecx]
// 005083ae  8b4808               mov ecx, dword ptr [eax + 8]
// 005083b1  52                   push edx
// 005083b2  8b5004               mov edx, dword ptr [eax + 4]
// 005083b5  6a00                 push 0
// 005083b7  51                   push ecx
// 005083b8  52                   push edx
// 005083b9  55                   push ebp
// 005083ba  e881d40000           call 0x515840
// 005083bf  8b4638               mov eax, dword ptr [esi + 0x38]
// 005083c2  83c414               add esp, 0x14
// 005083c5  c70407feffffff       mov dword ptr [edi + eax], 0xfffffffe
// 005083cc  eb28                 jmp 0x5083f6
// 005083ce  83f8ff               cmp eax, -1
// 005083d1  7523                 jne 0x5083f6
// 005083d3  8bca                 mov ecx, edx
// 005083d5  8b540f08             mov edx, dword ptr [edi + ecx + 8]
// 005083d9  8d040f               lea eax, [edi + ecx]
// 005083dc  8b4004               mov eax, dword ptr [eax + 4]
// 005083df  6a00                 push 0
// 005083e1  52                   push edx
// 005083e2  50                   push eax
// 005083e3  55                   push ebp
// 005083e4  e8a7d30000           call 0x515790
// 005083e9  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 005083ec  83c410               add esp, 0x10
// 005083ef  c7040ffdffffff       mov dword ptr [edi + ecx], 0xfffffffd
// 005083f6  83c301               add ebx, 1
// 005083f9  83c710               add edi, 0x10
// 005083fc  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 005083ff  0f8c7bffffff         jl 0x508380
// 00508405  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0050840b  85c0                 test eax, eax
// 0050840d  7470                 je 0x50847f
// 0050840f  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 00508415  8d1480               lea edx, [eax + eax*4]
// 00508418  8d0497               lea eax, [edi + edx*4]
// 0050841b  3bf8                 cmp edi, eax
// 0050841d  7360                 jae 0x50847f
// 0050841f  bb00000100           mov ebx, 0x10000
// 00508424  57                   push edi
// 00508425  55                   push ebp
// 00508426  e865270000           call 0x50ab90
// 0050842b  83c408               add esp, 8
// 0050842e  83f801               cmp eax, 1
// 00508431  7433                 je 0x508466
// 00508433  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00508436  84c9                 test cl, cl
// 00508438  742c                 je 0x508466
// 0050843a  f6c102               test cl, 2
// 0050843d  7427                 je 0x508466
// 0050843f  f6c104               test cl, 4
// 00508442  7522                 jne 0x508466
// 00508444  f6470320             test byte ptr [edi + 3], 0x20
// 00508448  750a                 jne 0x508454
// 0050844a  83f803               cmp eax, 3
// 0050844d  7405                 je 0x508454
// 0050844f  855d6c               test dword ptr [ebp + 0x6c], ebx
// 00508452  7412                 je 0x508466
// 00508454  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00508457  8b5708               mov edx, dword ptr [edi + 8]
// 0050845a  51                   push ecx
// 0050845b  52                   push edx
// 0050845c  57                   push edi
// 0050845d  55                   push ebp
// 0050845e  e87ddb0000           call 0x515fe0
// 00508463  83c410               add esp, 0x10
// 00508466  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0050846c  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 00508472  8d0480               lea eax, [eax + eax*4]
// 00508475  83c714               add edi, 0x14
// 00508478  8d1481               lea edx, [ecx + eax*4]
// 0050847b  3bfa                 cmp edi, edx
// 0050847d  72a5                 jb 0x508424
// 0050847f  5f                   pop edi
// 00508480  5e                   pop esi
// 00508481  5d                   pop ebp
// 00508482  5b                   pop ebx
// 00508483  c3                   ret 
// library libpng-1.2.7/pngwrite.c (function _png_write_info)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwrite.c
