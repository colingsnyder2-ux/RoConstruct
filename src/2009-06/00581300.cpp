// from server: 100% by auto
// roc 2009-06 00581300  unit: seg_00580000  size: 389 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00581300
//
// 00581300  51                   push ecx
// 00581301  55                   push ebp
// 00581302  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00581306  85ed                 test ebp, ebp
// 00581308  0f8474010000         je 0x581482
// 0058130e  56                   push esi
// 0058130f  8b742414             mov esi, dword ptr [esp + 0x14]
// 00581313  85f6                 test esi, esi
// 00581315  0f8466010000         je 0x581481
// 0058131b  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00581321  53                   push ebx
// 00581322  57                   push edi
// 00581323  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00581327  03c7                 add eax, edi
// 00581329  c1e004               shl eax, 4
// 0058132c  50                   push eax
// 0058132d  55                   push ebp
// 0058132e  e8add90000           call 0x58ece0
// 00581333  8bd8                 mov ebx, eax
// 00581335  83c408               add esp, 8
// 00581338  895c2410             mov dword ptr [esp + 0x10], ebx
// 0058133c  85db                 test ebx, ebx
// 0058133e  7514                 jne 0x581354
// 00581340  68c8c88c00           push 0x8cc8c8
// 00581345  55                   push ebp
// 00581346  e8c5ce0000           call 0x58e210
// 0058134b  83c408               add esp, 8
// 0058134e  5f                   pop edi
// 0058134f  5b                   pop ebx
// 00581350  5e                   pop esi
// 00581351  5d                   pop ebp
// 00581352  59                   pop ecx
// 00581353  c3                   ret 
// 00581354  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0058135a  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 00581360  c1e104               shl ecx, 4
// 00581363  51                   push ecx
// 00581364  52                   push edx
// 00581365  53                   push ebx
// 00581366  e84b8b1900           call 0x719eb6
// 0058136b  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 00581371  50                   push eax
// 00581372  55                   push ebp
// 00581373  e838d90000           call 0x58ecb0
// 00581378  33c0                 xor eax, eax
// 0058137a  83c414               add esp, 0x14
// 0058137d  3bf8                 cmp edi, eax
// 0058137f  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 00581385  89442418             mov dword ptr [esp + 0x18], eax
// 00581389  0f8ed6000000         jle 0x581465
// 0058138f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00581393  83c70c               add edi, 0xc
// 00581396  eb08                 jmp 0x5813a0
// 00581398  8da42400000000       lea esp, [esp]
// 0058139f  90                   nop 
// 005813a0  8bb6d8000000         mov esi, dword ptr [esi + 0xd8]
// 005813a6  03742418             add esi, dword ptr [esp + 0x18]
// 005813aa  8b47f4               mov eax, dword ptr [edi - 0xc]
// 005813ad  c1e604               shl esi, 4
// 005813b0  03f3                 add esi, ebx
// 005813b2  8d5001               lea edx, [eax + 1]
// 005813b5  8a08                 mov cl, byte ptr [eax]
// 005813b7  40                   inc eax
// 005813b8  84c9                 test cl, cl
// 005813ba  75f9                 jne 0x5813b5
// 005813bc  2bc2                 sub eax, edx
// 005813be  8d5801               lea ebx, [eax + 1]
// 005813c1  53                   push ebx
// 005813c2  55                   push ebp
// 005813c3  e818d90000           call 0x58ece0
// 005813c8  83c408               add esp, 8
// 005813cb  8906                 mov dword ptr [esi], eax
// 005813cd  85c0                 test eax, eax
// 005813cf  7510                 jne 0x5813e1
// 005813d1  689cc88c00           push 0x8cc89c
// 005813d6  55                   push ebp
// 005813d7  e834ce0000           call 0x58e210
// 005813dc  83c408               add esp, 8
// 005813df  eb62                 jmp 0x581443
// 005813e1  8b4ff4               mov ecx, dword ptr [edi - 0xc]
// 005813e4  53                   push ebx
// 005813e5  51                   push ecx
// 005813e6  50                   push eax
// 005813e7  e8ca8a1900           call 0x719eb6
// 005813ec  8b07                 mov eax, dword ptr [edi]
// 005813ee  8d1480               lea edx, [eax + eax*4]
// 005813f1  03d2                 add edx, edx
// 005813f3  52                   push edx
// 005813f4  55                   push ebp
// 005813f5  e8e6d80000           call 0x58ece0
// 005813fa  83c414               add esp, 0x14
// 005813fd  894608               mov dword ptr [esi + 8], eax
// 00581400  85c0                 test eax, eax
// 00581402  751f                 jne 0x581423
// 00581404  689cc88c00           push 0x8cc89c
// 00581409  55                   push ebp
// 0058140a  e801ce0000           call 0x58e210
// 0058140f  8b06                 mov eax, dword ptr [esi]
// 00581411  50                   push eax
// 00581412  55                   push ebp
// 00581413  e898d80000           call 0x58ecb0
// 00581418  83c410               add esp, 0x10
// 0058141b  c70600000000         mov dword ptr [esi], 0
// 00581421  eb20                 jmp 0x581443
// 00581423  8b0f                 mov ecx, dword ptr [edi]
// 00581425  8b57fc               mov edx, dword ptr [edi - 4]
// 00581428  8d0c89               lea ecx, [ecx + ecx*4]
// 0058142b  03c9                 add ecx, ecx
// 0058142d  51                   push ecx
// 0058142e  52                   push edx
// 0058142f  50                   push eax
// 00581430  e8818a1900           call 0x719eb6
// 00581435  8b07                 mov eax, dword ptr [edi]
// 00581437  89460c               mov dword ptr [esi + 0xc], eax
// 0058143a  8a4ff8               mov cl, byte ptr [edi - 8]
// 0058143d  83c40c               add esp, 0xc
// 00581440  884e04               mov byte ptr [esi + 4], cl
// 00581443  8b442418             mov eax, dword ptr [esp + 0x18]
// 00581447  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0058144b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0058144f  40                   inc eax
// 00581450  83c710               add edi, 0x10
// 00581453  3b442424             cmp eax, dword ptr [esp + 0x24]
// 00581457  89442418             mov dword ptr [esp + 0x18], eax
// 0058145b  0f8c3fffffff         jl 0x5813a0
// 00581461  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00581465  01bed8000000         add dword ptr [esi + 0xd8], edi
// 0058146b  814e0800200000       or dword ptr [esi + 8], 0x2000
// 00581472  838eb800000020       or dword ptr [esi + 0xb8], 0x20
// 00581479  5f                   pop edi
// 0058147a  899ed4000000         mov dword ptr [esi + 0xd4], ebx
// 00581480  5b                   pop ebx
// 00581481  5e                   pop esi
// 00581482  5d                   pop ebp
// 00581483  59                   pop ecx
// 00581484  c3                   ret 
// library libpng-1.2.29/pngset.c (function _png_set_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngset.c
