// from server: 100% by auto
// roc 2009-06 0057f2b0  unit: G3D::_internal::DialogTemplate  size: 736 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0057f2b0
//
// 0057f2b0  55                   push ebp
// 0057f2b1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0057f2b5  85ed                 test ebp, ebp
// 0057f2b7  0f84d1020000         je 0x57f58e
// 0057f2bd  56                   push esi
// 0057f2be  8b742410             mov esi, dword ptr [esp + 0x10]
// 0057f2c2  85f6                 test esi, esi
// 0057f2c4  0f84c3020000         je 0x57f58d
// 0057f2ca  56                   push esi
// 0057f2cb  55                   push ebp
// 0057f2cc  e8effdffff           call 0x57f0c0
// 0057f2d1  83c408               add esp, 8
// 0057f2d4  f6460808             test byte ptr [esi + 8], 8
// 0057f2d8  7414                 je 0x57f2ee
// 0057f2da  0fb74614             movzx eax, word ptr [esi + 0x14]
// 0057f2de  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0057f2e1  50                   push eax
// 0057f2e2  51                   push ecx
// 0057f2e3  55                   push ebp
// 0057f2e4  e847ba0000           call 0x58ad30
// 0057f2e9  83c40c               add esp, 0xc
// 0057f2ec  eb14                 jmp 0x57f302
// 0057f2ee  807e1903             cmp byte ptr [esi + 0x19], 3
// 0057f2f2  750e                 jne 0x57f302
// 0057f2f4  6894c28c00           push 0x8cc294
// 0057f2f9  55                   push ebp
// 0057f2fa  e861ee0000           call 0x58e160
// 0057f2ff  83c408               add esp, 8
// 0057f302  f6460810             test byte ptr [esi + 8], 0x10
// 0057f306  7449                 je 0x57f351
// 0057f308  f7457000000800       test dword ptr [ebp + 0x70], 0x80000
// 0057f30f  7425                 je 0x57f336
// 0057f311  807e1903             cmp byte ptr [esi + 0x19], 3
// 0057f315  751f                 jne 0x57f336
// 0057f317  33d2                 xor edx, edx
// 0057f319  33c0                 xor eax, eax
// 0057f31b  663b5616             cmp dx, word ptr [esi + 0x16]
// 0057f31f  7315                 jae 0x57f336
// 0057f321  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0057f324  03c8                 add ecx, eax
// 0057f326  80caff               or dl, 0xff
// 0057f329  2a11                 sub dl, byte ptr [ecx]
// 0057f32b  40                   inc eax
// 0057f32c  8811                 mov byte ptr [ecx], dl
// 0057f32e  0fb74e16             movzx ecx, word ptr [esi + 0x16]
// 0057f332  3bc1                 cmp eax, ecx
// 0057f334  7ceb                 jl 0x57f321
// 0057f336  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 0057f33a  0fb74616             movzx eax, word ptr [esi + 0x16]
// 0057f33e  52                   push edx
// 0057f33f  8b564c               mov edx, dword ptr [esi + 0x4c]
// 0057f342  50                   push eax
// 0057f343  8d4e50               lea ecx, [esi + 0x50]
// 0057f346  51                   push ecx
// 0057f347  52                   push edx
// 0057f348  55                   push ebp
// 0057f349  e8a2d60000           call 0x58c9f0
// 0057f34e  83c414               add esp, 0x14
// 0057f351  f6460820             test byte ptr [esi + 8], 0x20
// 0057f355  7412                 je 0x57f369
// 0057f357  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0057f35b  50                   push eax
// 0057f35c  8d4e5a               lea ecx, [esi + 0x5a]
// 0057f35f  51                   push ecx
// 0057f360  55                   push ebp
// 0057f361  e8ead70000           call 0x58cb50
// 0057f366  83c40c               add esp, 0xc
// 0057f369  f6460840             test byte ptr [esi + 8], 0x40
// 0057f36d  7412                 je 0x57f381
// 0057f36f  0fb75614             movzx edx, word ptr [esi + 0x14]
// 0057f373  8b467c               mov eax, dword ptr [esi + 0x7c]
// 0057f376  52                   push edx
// 0057f377  50                   push eax
// 0057f378  55                   push ebp
// 0057f379  e8c2ba0000           call 0x58ae40
// 0057f37e  83c40c               add esp, 0xc
// 0057f381  f7460800010000       test dword ptr [esi + 8], 0x100
// 0057f388  7416                 je 0x57f3a0
// 0057f38a  0fb64e6c             movzx ecx, byte ptr [esi + 0x6c]
// 0057f38e  8b5668               mov edx, dword ptr [esi + 0x68]
// 0057f391  8b4664               mov eax, dword ptr [esi + 0x64]
// 0057f394  51                   push ecx
// 0057f395  52                   push edx
// 0057f396  50                   push eax
// 0057f397  55                   push ebp
// 0057f398  e813d90000           call 0x58ccb0
// 0057f39d  83c410               add esp, 0x10
// 0057f3a0  f7460800040000       test dword ptr [esi + 8], 0x400
// 0057f3a7  743c                 je 0x57f3e5
// 0057f3a9  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0057f3af  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 0057f3b5  0fb686b5000000       movzx eax, byte ptr [esi + 0xb5]
// 0057f3bc  51                   push ecx
// 0057f3bd  0fb68eb4000000       movzx ecx, byte ptr [esi + 0xb4]
// 0057f3c4  52                   push edx
// 0057f3c5  8b96a8000000         mov edx, dword ptr [esi + 0xa8]
// 0057f3cb  50                   push eax
// 0057f3cc  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 0057f3d2  51                   push ecx
// 0057f3d3  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 0057f3d9  52                   push edx
// 0057f3da  50                   push eax
// 0057f3db  51                   push ecx
// 0057f3dc  55                   push ebp
// 0057f3dd  e84ebf0000           call 0x58b330
// 0057f3e2  83c420               add esp, 0x20
// 0057f3e5  f7460800400000       test dword ptr [esi + 8], 0x4000
// 0057f3ec  7427                 je 0x57f415
// 0057f3ee  dd86e8000000         fld qword ptr [esi + 0xe8]
// 0057f3f4  0fb696dc000000       movzx edx, byte ptr [esi + 0xdc]
// 0057f3fb  83ec10               sub esp, 0x10
// 0057f3fe  dd5c2408             fstp qword ptr [esp + 8]
// 0057f402  dd86e0000000         fld qword ptr [esi + 0xe0]
// 0057f408  dd1c24               fstp qword ptr [esp]
// 0057f40b  52                   push edx
// 0057f40c  55                   push ebp
// 0057f40d  e88ed90000           call 0x58cda0
// 0057f412  83c418               add esp, 0x18
// 0057f415  f6460880             test byte ptr [esi + 8], 0x80
// 0057f419  7416                 je 0x57f431
// 0057f41b  0fb64678             movzx eax, byte ptr [esi + 0x78]
// 0057f41f  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 0057f422  8b5670               mov edx, dword ptr [esi + 0x70]
// 0057f425  50                   push eax
// 0057f426  51                   push ecx
// 0057f427  52                   push edx
// 0057f428  55                   push ebp
// 0057f429  e822da0000           call 0x58ce50
// 0057f42e  83c410               add esp, 0x10
// 0057f431  57                   push edi
// 0057f432  bf00020000           mov edi, 0x200
// 0057f437  857e08               test dword ptr [esi + 8], edi
// 0057f43a  7410                 je 0x57f44c
// 0057f43c  8d463c               lea eax, [esi + 0x3c]
// 0057f43f  50                   push eax
// 0057f440  55                   push ebp
// 0057f441  e8fada0000           call 0x58cf40
// 0057f446  83c408               add esp, 8
// 0057f449  097d68               or dword ptr [ebp + 0x68], edi
// 0057f44c  f7460800200000       test dword ptr [esi + 8], 0x2000
// 0057f453  53                   push ebx
// 0057f454  742a                 je 0x57f480
// 0057f456  33ff                 xor edi, edi
// 0057f458  39bed8000000         cmp dword ptr [esi + 0xd8], edi
// 0057f45e  7e20                 jle 0x57f480
// 0057f460  33db                 xor ebx, ebx
// 0057f462  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 0057f468  03cb                 add ecx, ebx
// 0057f46a  51                   push ecx
// 0057f46b  55                   push ebp
// 0057f46c  e8ffce0000           call 0x58c370
// 0057f471  47                   inc edi
// 0057f472  83c408               add esp, 8
// 0057f475  83c310               add ebx, 0x10
// 0057f478  3bbed8000000         cmp edi, dword ptr [esi + 0xd8]
// 0057f47e  7ce2                 jl 0x57f462
// 0057f480  33db                 xor ebx, ebx
// 0057f482  395e30               cmp dword ptr [esi + 0x30], ebx
// 0057f485  0f8e84000000         jle 0x57f50f
// 0057f48b  33ff                 xor edi, edi
// 0057f48d  8d4900               lea ecx, [ecx]
// 0057f490  8b5638               mov edx, dword ptr [esi + 0x38]
// 0057f493  8b0417               mov eax, dword ptr [edi + edx]
// 0057f496  85c0                 test eax, eax
// 0057f498  7e1a                 jle 0x57f4b4
// 0057f49a  6870c28c00           push 0x8cc270
// 0057f49f  55                   push ebp
// 0057f4a0  e86bed0000           call 0x58e210
// 0057f4a5  8b4638               mov eax, dword ptr [esi + 0x38]
// 0057f4a8  83c408               add esp, 8
// 0057f4ab  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 0057f4b2  eb52                 jmp 0x57f506
// 0057f4b4  7528                 jne 0x57f4de
// 0057f4b6  8bca                 mov ecx, edx
// 0057f4b8  8b140f               mov edx, dword ptr [edi + ecx]
// 0057f4bb  8d040f               lea eax, [edi + ecx]
// 0057f4be  8b4808               mov ecx, dword ptr [eax + 8]
// 0057f4c1  52                   push edx
// 0057f4c2  8b5004               mov edx, dword ptr [eax + 4]
// 0057f4c5  6a00                 push 0
// 0057f4c7  51                   push ecx
// 0057f4c8  52                   push edx
// 0057f4c9  55                   push ebp
// 0057f4ca  e811bd0000           call 0x58b1e0
// 0057f4cf  8b4638               mov eax, dword ptr [esi + 0x38]
// 0057f4d2  83c414               add esp, 0x14
// 0057f4d5  c70407feffffff       mov dword ptr [edi + eax], 0xfffffffe
// 0057f4dc  eb28                 jmp 0x57f506
// 0057f4de  83f8ff               cmp eax, -1
// 0057f4e1  7523                 jne 0x57f506
// 0057f4e3  8bca                 mov ecx, edx
// 0057f4e5  8b540f08             mov edx, dword ptr [edi + ecx + 8]
// 0057f4e9  8d040f               lea eax, [edi + ecx]
// 0057f4ec  8b4004               mov eax, dword ptr [eax + 4]
// 0057f4ef  6a00                 push 0
// 0057f4f1  52                   push edx
// 0057f4f2  50                   push eax
// 0057f4f3  55                   push ebp
// 0057f4f4  e807bc0000           call 0x58b100
// 0057f4f9  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0057f4fc  83c410               add esp, 0x10
// 0057f4ff  c7040ffdffffff       mov dword ptr [edi + ecx], 0xfffffffd
// 0057f506  43                   inc ebx
// 0057f507  83c710               add edi, 0x10
// 0057f50a  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 0057f50d  7c81                 jl 0x57f490
// 0057f50f  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0057f515  85c0                 test eax, eax
// 0057f517  7472                 je 0x57f58b
// 0057f519  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 0057f51f  8d1480               lea edx, [eax + eax*4]
// 0057f522  8d0497               lea eax, [edi + edx*4]
// 0057f525  3bf8                 cmp edi, eax
// 0057f527  7362                 jae 0x57f58b
// 0057f529  bb00000100           mov ebx, 0x10000
// 0057f52e  8bff                 mov edi, edi
// 0057f530  57                   push edi
// 0057f531  55                   push ebp
// 0057f532  e8f9270000           call 0x581d30
// 0057f537  83c408               add esp, 8
// 0057f53a  83f801               cmp eax, 1
// 0057f53d  7433                 je 0x57f572
// 0057f53f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 0057f542  84c9                 test cl, cl
// 0057f544  742c                 je 0x57f572
// 0057f546  f6c102               test cl, 2
// 0057f549  7427                 je 0x57f572
// 0057f54b  f6c104               test cl, 4
// 0057f54e  7522                 jne 0x57f572
// 0057f550  f6470320             test byte ptr [edi + 3], 0x20
// 0057f554  750a                 jne 0x57f560
// 0057f556  83f803               cmp eax, 3
// 0057f559  7405                 je 0x57f560
// 0057f55b  855d6c               test dword ptr [ebp + 0x6c], ebx
// 0057f55e  7412                 je 0x57f572
// 0057f560  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0057f563  8b5708               mov edx, dword ptr [edi + 8]
// 0057f566  51                   push ecx
// 0057f567  52                   push edx
// 0057f568  57                   push edi
// 0057f569  55                   push ebp
// 0057f56a  e8b1c40000           call 0x58ba20
// 0057f56f  83c410               add esp, 0x10
// 0057f572  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0057f578  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0057f57e  8d0480               lea eax, [eax + eax*4]
// 0057f581  83c714               add edi, 0x14
// 0057f584  8d1481               lea edx, [ecx + eax*4]
// 0057f587  3bfa                 cmp edi, edx
// 0057f589  72a5                 jb 0x57f530
// 0057f58b  5b                   pop ebx
// 0057f58c  5f                   pop edi
// 0057f58d  5e                   pop esi
// 0057f58e  5d                   pop ebp
// 0057f58f  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
