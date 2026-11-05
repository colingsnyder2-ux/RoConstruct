// from server: 100% by auto
// roc 2009-06 0058b770  unit: seg_00580000  size: 676 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058b770
//
// 0058b770  83ec44               sub esp, 0x44
// 0058b773  b804000000           mov eax, 4
// 0058b778  55                   push ebp
// 0058b779  33d2                 xor edx, edx
// 0058b77b  89442430             mov dword ptr [esp + 0x30], eax
// 0058b77f  bd02000000           mov ebp, 2
// 0058b784  89442418             mov dword ptr [esp + 0x18], eax
// 0058b788  8944241c             mov dword ptr [esp + 0x1c], eax
// 0058b78c  8b442454             mov eax, dword ptr [esp + 0x54]
// 0058b790  83f806               cmp eax, 6
// 0058b793  56                   push esi
// 0058b794  be01000000           mov esi, 1
// 0058b799  b908000000           mov ecx, 8
// 0058b79e  89542430             mov dword ptr [esp + 0x30], edx
// 0058b7a2  89542438             mov dword ptr [esp + 0x38], edx
// 0058b7a6  896c243c             mov dword ptr [esp + 0x3c], ebp
// 0058b7aa  89542440             mov dword ptr [esp + 0x40], edx
// 0058b7ae  89742444             mov dword ptr [esp + 0x44], esi
// 0058b7b2  89542448             mov dword ptr [esp + 0x48], edx
// 0058b7b6  894c2414             mov dword ptr [esp + 0x14], ecx
// 0058b7ba  894c2418             mov dword ptr [esp + 0x18], ecx
// 0058b7be  896c2424             mov dword ptr [esp + 0x24], ebp
// 0058b7c2  896c2428             mov dword ptr [esp + 0x28], ebp
// 0058b7c6  8974242c             mov dword ptr [esp + 0x2c], esi
// 0058b7ca  0f8d3e020000         jge 0x58ba0e
// 0058b7d0  53                   push ebx
// 0058b7d1  57                   push edi
// 0058b7d2  8b7c2458             mov edi, dword ptr [esp + 0x58]
// 0058b7d6  0fb65f0b             movzx ebx, byte ptr [edi + 0xb]
// 0058b7da  8bcb                 mov ecx, ebx
// 0058b7dc  2bce                 sub ecx, esi
// 0058b7de  0f8472010000         je 0x58b956
// 0058b7e4  2bce                 sub ecx, esi
// 0058b7e6  0f84e3000000         je 0x58b8cf
// 0058b7ec  2bcd                 sub ecx, ebp
// 0058b7ee  8d2c8500000000       lea ebp, [eax*4]
// 0058b7f5  7467                 je 0x58b85e
// 0058b7f7  8b17                 mov edx, dword ptr [edi]
// 0058b7f9  8b7c2c38             mov edi, dword ptr [esp + ebp + 0x38]
// 0058b7fd  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0058b801  c1eb03               shr ebx, 3
// 0058b804  89542418             mov dword ptr [esp + 0x18], edx
// 0058b808  894c2410             mov dword ptr [esp + 0x10], ecx
// 0058b80c  897c2460             mov dword ptr [esp + 0x60], edi
// 0058b810  3bfa                 cmp edi, edx
// 0058b812  0f83b4010000         jae 0x58b9cc
// 0058b818  8b442c1c             mov eax, dword ptr [esp + ebp + 0x1c]
// 0058b81c  8bf7                 mov esi, edi
// 0058b81e  0fafc3               imul eax, ebx
// 0058b821  0faff3               imul esi, ebx
// 0058b824  89442414             mov dword ptr [esp + 0x14], eax
// 0058b828  03f1                 add esi, ecx
// 0058b82a  8d9b00000000         lea ebx, [ebx]
// 0058b830  3bce                 cmp ecx, esi
// 0058b832  7413                 je 0x58b847
// 0058b834  53                   push ebx
// 0058b835  56                   push esi
// 0058b836  51                   push ecx
// 0058b837  e87ae61800           call 0x719eb6
// 0058b83c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0058b840  8b442420             mov eax, dword ptr [esp + 0x20]
// 0058b844  83c40c               add esp, 0xc
// 0058b847  037c2c1c             add edi, dword ptr [esp + ebp + 0x1c]
// 0058b84b  03cb                 add ecx, ebx
// 0058b84d  03f0                 add esi, eax
// 0058b84f  894c2410             mov dword ptr [esp + 0x10], ecx
// 0058b853  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 0058b857  72d7                 jb 0x58b830
// 0058b859  e96e010000           jmp 0x58b9cc
// 0058b85e  8b0f                 mov ecx, dword ptr [edi]
// 0058b860  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0058b864  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0058b868  894c2418             mov dword ptr [esp + 0x18], ecx
// 0058b86c  897c2410             mov dword ptr [esp + 0x10], edi
// 0058b870  be04000000           mov esi, 4
// 0058b875  89442460             mov dword ptr [esp + 0x60], eax
// 0058b879  3bc1                 cmp eax, ecx
// 0058b87b  0f834b010000         jae 0x58b9cc
// 0058b881  8ad8                 mov bl, al
// 0058b883  80e301               and bl, 1
// 0058b886  02db                 add bl, bl
// 0058b888  02db                 add bl, bl
// 0058b88a  b904000000           mov ecx, 4
// 0058b88f  2acb                 sub cl, bl
// 0058b891  8bd8                 mov ebx, eax
// 0058b893  d1eb                 shr ebx, 1
// 0058b895  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0058b899  d3eb                 shr ebx, cl
// 0058b89b  8bce                 mov ecx, esi
// 0058b89d  83e30f               and ebx, 0xf
// 0058b8a0  d3e3                 shl ebx, cl
// 0058b8a2  0bd3                 or edx, ebx
// 0058b8a4  85f6                 test esi, esi
// 0058b8a6  7512                 jne 0x58b8ba
// 0058b8a8  8d7104               lea esi, [ecx + 4]
// 0058b8ab  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058b8af  8811                 mov byte ptr [ecx], dl
// 0058b8b1  41                   inc ecx
// 0058b8b2  894c2410             mov dword ptr [esp + 0x10], ecx
// 0058b8b6  33d2                 xor edx, edx
// 0058b8b8  eb03                 jmp 0x58b8bd
// 0058b8ba  83ee04               sub esi, 4
// 0058b8bd  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0058b8c1  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0058b8c5  72ba                 jb 0x58b881
// 0058b8c7  83fe04               cmp esi, 4
// 0058b8ca  e9f5000000           jmp 0x58b9c4
// 0058b8cf  8b0f                 mov ecx, dword ptr [edi]
// 0058b8d1  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0058b8d5  8d2c8500000000       lea ebp, [eax*4]
// 0058b8dc  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0058b8e0  894c2418             mov dword ptr [esp + 0x18], ecx
// 0058b8e4  897c2410             mov dword ptr [esp + 0x10], edi
// 0058b8e8  be06000000           mov esi, 6
// 0058b8ed  89442460             mov dword ptr [esp + 0x60], eax
// 0058b8f1  3bc1                 cmp eax, ecx
// 0058b8f3  0f83d3000000         jae 0x58b9cc
// 0058b8f9  8da42400000000       lea esp, [esp]
// 0058b900  8ad8                 mov bl, al
// 0058b902  80e303               and bl, 3
// 0058b905  b903000000           mov ecx, 3
// 0058b90a  2acb                 sub cl, bl
// 0058b90c  8bd8                 mov ebx, eax
// 0058b90e  c1eb02               shr ebx, 2
// 0058b911  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0058b915  02c9                 add cl, cl
// 0058b917  d3eb                 shr ebx, cl
// 0058b919  8bce                 mov ecx, esi
// 0058b91b  83e303               and ebx, 3
// 0058b91e  d3e3                 shl ebx, cl
// 0058b920  0bd3                 or edx, ebx
// 0058b922  85f6                 test esi, esi
// 0058b924  7512                 jne 0x58b938
// 0058b926  8d7106               lea esi, [ecx + 6]
// 0058b929  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058b92d  8811                 mov byte ptr [ecx], dl
// 0058b92f  41                   inc ecx
// 0058b930  894c2410             mov dword ptr [esp + 0x10], ecx
// 0058b934  33d2                 xor edx, edx
// 0058b936  eb03                 jmp 0x58b93b
// 0058b938  83ee02               sub esi, 2
// 0058b93b  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0058b93f  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0058b943  72bb                 jb 0x58b900
// 0058b945  83fe06               cmp esi, 6
// 0058b948  0f847e000000         je 0x58b9cc
// 0058b94e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058b952  8811                 mov byte ptr [ecx], dl
// 0058b954  eb76                 jmp 0x58b9cc
// 0058b956  8b0f                 mov ecx, dword ptr [edi]
// 0058b958  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0058b95c  8d2c8500000000       lea ebp, [eax*4]
// 0058b963  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0058b967  894c2418             mov dword ptr [esp + 0x18], ecx
// 0058b96b  897c2410             mov dword ptr [esp + 0x10], edi
// 0058b96f  be07000000           mov esi, 7
// 0058b974  89442460             mov dword ptr [esp + 0x60], eax
// 0058b978  3bc1                 cmp eax, ecx
// 0058b97a  7350                 jae 0x58b9cc
// 0058b97c  8d642400             lea esp, [esp]
// 0058b980  8ad8                 mov bl, al
// 0058b982  80e307               and bl, 7
// 0058b985  b907000000           mov ecx, 7
// 0058b98a  2acb                 sub cl, bl
// 0058b98c  8bd8                 mov ebx, eax
// 0058b98e  c1eb03               shr ebx, 3
// 0058b991  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0058b995  d3eb                 shr ebx, cl
// 0058b997  8bce                 mov ecx, esi
// 0058b999  83e301               and ebx, 1
// 0058b99c  d3e3                 shl ebx, cl
// 0058b99e  0bd3                 or edx, ebx
// 0058b9a0  85f6                 test esi, esi
// 0058b9a2  7512                 jne 0x58b9b6
// 0058b9a4  8d7107               lea esi, [ecx + 7]
// 0058b9a7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058b9ab  8811                 mov byte ptr [ecx], dl
// 0058b9ad  41                   inc ecx
// 0058b9ae  894c2410             mov dword ptr [esp + 0x10], ecx
// 0058b9b2  33d2                 xor edx, edx
// 0058b9b4  eb01                 jmp 0x58b9b7
// 0058b9b6  4e                   dec esi
// 0058b9b7  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0058b9bb  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0058b9bf  72bf                 jb 0x58b980
// 0058b9c1  83fe07               cmp esi, 7
// 0058b9c4  7406                 je 0x58b9cc
// 0058b9c6  8b442410             mov eax, dword ptr [esp + 0x10]
// 0058b9ca  8810                 mov byte ptr [eax], dl
// 0058b9cc  8b6c2c1c             mov ebp, dword ptr [esp + ebp + 0x1c]
// 0058b9d0  8b742458             mov esi, dword ptr [esp + 0x58]
// 0058b9d4  8b16                 mov edx, dword ptr [esi]
// 0058b9d6  8bcd                 mov ecx, ebp
// 0058b9d8  2b4c2460             sub ecx, dword ptr [esp + 0x60]
// 0058b9dc  5f                   pop edi
// 0058b9dd  8d4411ff             lea eax, [ecx + edx - 1]
// 0058b9e1  33d2                 xor edx, edx
// 0058b9e3  f7f5                 div ebp
// 0058b9e5  8a4e0b               mov cl, byte ptr [esi + 0xb]
// 0058b9e8  80f908               cmp cl, 8
// 0058b9eb  5b                   pop ebx
// 0058b9ec  0fb6c9               movzx ecx, cl
// 0058b9ef  8906                 mov dword ptr [esi], eax
// 0058b9f1  720f                 jb 0x58ba02
// 0058b9f3  c1e903               shr ecx, 3
// 0058b9f6  0fafc8               imul ecx, eax
// 0058b9f9  894e04               mov dword ptr [esi + 4], ecx
// 0058b9fc  5e                   pop esi
// 0058b9fd  5d                   pop ebp
// 0058b9fe  83c444               add esp, 0x44
// 0058ba01  c3                   ret 
// 0058ba02  0fafc8               imul ecx, eax
// 0058ba05  83c107               add ecx, 7
// 0058ba08  c1e903               shr ecx, 3
// 0058ba0b  894e04               mov dword ptr [esi + 4], ecx
// 0058ba0e  5e                   pop esi
// 0058ba0f  5d                   pop ebp
// 0058ba10  83c444               add esp, 0x44
// 0058ba13  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_do_write_interlace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
