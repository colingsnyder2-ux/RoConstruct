// from server: 100% by auto
// roc 2011-06 0056b860  unit: seg_00560000  size: 676 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056b860
//
// 0056b860  83ec44               sub esp, 0x44
// 0056b863  b804000000           mov eax, 4
// 0056b868  55                   push ebp
// 0056b869  33d2                 xor edx, edx
// 0056b86b  89442430             mov dword ptr [esp + 0x30], eax
// 0056b86f  bd02000000           mov ebp, 2
// 0056b874  89442418             mov dword ptr [esp + 0x18], eax
// 0056b878  8944241c             mov dword ptr [esp + 0x1c], eax
// 0056b87c  8b442454             mov eax, dword ptr [esp + 0x54]
// 0056b880  83f806               cmp eax, 6
// 0056b883  56                   push esi
// 0056b884  be01000000           mov esi, 1
// 0056b889  b908000000           mov ecx, 8
// 0056b88e  89542430             mov dword ptr [esp + 0x30], edx
// 0056b892  89542438             mov dword ptr [esp + 0x38], edx
// 0056b896  896c243c             mov dword ptr [esp + 0x3c], ebp
// 0056b89a  89542440             mov dword ptr [esp + 0x40], edx
// 0056b89e  89742444             mov dword ptr [esp + 0x44], esi
// 0056b8a2  89542448             mov dword ptr [esp + 0x48], edx
// 0056b8a6  894c2414             mov dword ptr [esp + 0x14], ecx
// 0056b8aa  894c2418             mov dword ptr [esp + 0x18], ecx
// 0056b8ae  896c2424             mov dword ptr [esp + 0x24], ebp
// 0056b8b2  896c2428             mov dword ptr [esp + 0x28], ebp
// 0056b8b6  8974242c             mov dword ptr [esp + 0x2c], esi
// 0056b8ba  0f8d3e020000         jge 0x56bafe
// 0056b8c0  53                   push ebx
// 0056b8c1  57                   push edi
// 0056b8c2  8b7c2458             mov edi, dword ptr [esp + 0x58]
// 0056b8c6  0fb65f0b             movzx ebx, byte ptr [edi + 0xb]
// 0056b8ca  8bcb                 mov ecx, ebx
// 0056b8cc  2bce                 sub ecx, esi
// 0056b8ce  0f8472010000         je 0x56ba46
// 0056b8d4  2bce                 sub ecx, esi
// 0056b8d6  0f84e3000000         je 0x56b9bf
// 0056b8dc  2bcd                 sub ecx, ebp
// 0056b8de  8d2c8500000000       lea ebp, [eax*4]
// 0056b8e5  7467                 je 0x56b94e
// 0056b8e7  8b17                 mov edx, dword ptr [edi]
// 0056b8e9  8b7c2c38             mov edi, dword ptr [esp + ebp + 0x38]
// 0056b8ed  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0056b8f1  c1eb03               shr ebx, 3
// 0056b8f4  89542418             mov dword ptr [esp + 0x18], edx
// 0056b8f8  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056b8fc  897c2460             mov dword ptr [esp + 0x60], edi
// 0056b900  3bfa                 cmp edi, edx
// 0056b902  0f83b4010000         jae 0x56babc
// 0056b908  8b442c1c             mov eax, dword ptr [esp + ebp + 0x1c]
// 0056b90c  8bf7                 mov esi, edi
// 0056b90e  0fafc3               imul eax, ebx
// 0056b911  0faff3               imul esi, ebx
// 0056b914  89442414             mov dword ptr [esp + 0x14], eax
// 0056b918  03f1                 add esi, ecx
// 0056b91a  8d9b00000000         lea ebx, [ebx]
// 0056b920  3bce                 cmp ecx, esi
// 0056b922  7413                 je 0x56b937
// 0056b924  53                   push ebx
// 0056b925  56                   push esi
// 0056b926  51                   push ecx
// 0056b927  e8b0fc2900           call 0x80b5dc
// 0056b92c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056b930  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056b934  83c40c               add esp, 0xc
// 0056b937  037c2c1c             add edi, dword ptr [esp + ebp + 0x1c]
// 0056b93b  03cb                 add ecx, ebx
// 0056b93d  03f0                 add esi, eax
// 0056b93f  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056b943  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 0056b947  72d7                 jb 0x56b920
// 0056b949  e96e010000           jmp 0x56babc
// 0056b94e  8b0f                 mov ecx, dword ptr [edi]
// 0056b950  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0056b954  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0056b958  894c2418             mov dword ptr [esp + 0x18], ecx
// 0056b95c  897c2410             mov dword ptr [esp + 0x10], edi
// 0056b960  be04000000           mov esi, 4
// 0056b965  89442460             mov dword ptr [esp + 0x60], eax
// 0056b969  3bc1                 cmp eax, ecx
// 0056b96b  0f834b010000         jae 0x56babc
// 0056b971  8ad8                 mov bl, al
// 0056b973  80e301               and bl, 1
// 0056b976  02db                 add bl, bl
// 0056b978  02db                 add bl, bl
// 0056b97a  b904000000           mov ecx, 4
// 0056b97f  2acb                 sub cl, bl
// 0056b981  8bd8                 mov ebx, eax
// 0056b983  d1eb                 shr ebx, 1
// 0056b985  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0056b989  d3eb                 shr ebx, cl
// 0056b98b  8bce                 mov ecx, esi
// 0056b98d  83e30f               and ebx, 0xf
// 0056b990  d3e3                 shl ebx, cl
// 0056b992  0bd3                 or edx, ebx
// 0056b994  85f6                 test esi, esi
// 0056b996  7512                 jne 0x56b9aa
// 0056b998  8d7104               lea esi, [ecx + 4]
// 0056b99b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056b99f  8811                 mov byte ptr [ecx], dl
// 0056b9a1  41                   inc ecx
// 0056b9a2  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056b9a6  33d2                 xor edx, edx
// 0056b9a8  eb03                 jmp 0x56b9ad
// 0056b9aa  83ee04               sub esi, 4
// 0056b9ad  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0056b9b1  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0056b9b5  72ba                 jb 0x56b971
// 0056b9b7  83fe04               cmp esi, 4
// 0056b9ba  e9f5000000           jmp 0x56bab4
// 0056b9bf  8b0f                 mov ecx, dword ptr [edi]
// 0056b9c1  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0056b9c5  8d2c8500000000       lea ebp, [eax*4]
// 0056b9cc  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0056b9d0  894c2418             mov dword ptr [esp + 0x18], ecx
// 0056b9d4  897c2410             mov dword ptr [esp + 0x10], edi
// 0056b9d8  be06000000           mov esi, 6
// 0056b9dd  89442460             mov dword ptr [esp + 0x60], eax
// 0056b9e1  3bc1                 cmp eax, ecx
// 0056b9e3  0f83d3000000         jae 0x56babc
// 0056b9e9  8da42400000000       lea esp, [esp]
// 0056b9f0  8ad8                 mov bl, al
// 0056b9f2  80e303               and bl, 3
// 0056b9f5  b903000000           mov ecx, 3
// 0056b9fa  2acb                 sub cl, bl
// 0056b9fc  8bd8                 mov ebx, eax
// 0056b9fe  c1eb02               shr ebx, 2
// 0056ba01  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0056ba05  02c9                 add cl, cl
// 0056ba07  d3eb                 shr ebx, cl
// 0056ba09  8bce                 mov ecx, esi
// 0056ba0b  83e303               and ebx, 3
// 0056ba0e  d3e3                 shl ebx, cl
// 0056ba10  0bd3                 or edx, ebx
// 0056ba12  85f6                 test esi, esi
// 0056ba14  7512                 jne 0x56ba28
// 0056ba16  8d7106               lea esi, [ecx + 6]
// 0056ba19  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056ba1d  8811                 mov byte ptr [ecx], dl
// 0056ba1f  41                   inc ecx
// 0056ba20  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056ba24  33d2                 xor edx, edx
// 0056ba26  eb03                 jmp 0x56ba2b
// 0056ba28  83ee02               sub esi, 2
// 0056ba2b  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0056ba2f  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0056ba33  72bb                 jb 0x56b9f0
// 0056ba35  83fe06               cmp esi, 6
// 0056ba38  0f847e000000         je 0x56babc
// 0056ba3e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056ba42  8811                 mov byte ptr [ecx], dl
// 0056ba44  eb76                 jmp 0x56babc
// 0056ba46  8b0f                 mov ecx, dword ptr [edi]
// 0056ba48  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0056ba4c  8d2c8500000000       lea ebp, [eax*4]
// 0056ba53  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0056ba57  894c2418             mov dword ptr [esp + 0x18], ecx
// 0056ba5b  897c2410             mov dword ptr [esp + 0x10], edi
// 0056ba5f  be07000000           mov esi, 7
// 0056ba64  89442460             mov dword ptr [esp + 0x60], eax
// 0056ba68  3bc1                 cmp eax, ecx
// 0056ba6a  7350                 jae 0x56babc
// 0056ba6c  8d642400             lea esp, [esp]
// 0056ba70  8ad8                 mov bl, al
// 0056ba72  80e307               and bl, 7
// 0056ba75  b907000000           mov ecx, 7
// 0056ba7a  2acb                 sub cl, bl
// 0056ba7c  8bd8                 mov ebx, eax
// 0056ba7e  c1eb03               shr ebx, 3
// 0056ba81  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0056ba85  d3eb                 shr ebx, cl
// 0056ba87  8bce                 mov ecx, esi
// 0056ba89  83e301               and ebx, 1
// 0056ba8c  d3e3                 shl ebx, cl
// 0056ba8e  0bd3                 or edx, ebx
// 0056ba90  85f6                 test esi, esi
// 0056ba92  7512                 jne 0x56baa6
// 0056ba94  8d7107               lea esi, [ecx + 7]
// 0056ba97  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056ba9b  8811                 mov byte ptr [ecx], dl
// 0056ba9d  41                   inc ecx
// 0056ba9e  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056baa2  33d2                 xor edx, edx
// 0056baa4  eb01                 jmp 0x56baa7
// 0056baa6  4e                   dec esi
// 0056baa7  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0056baab  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0056baaf  72bf                 jb 0x56ba70
// 0056bab1  83fe07               cmp esi, 7
// 0056bab4  7406                 je 0x56babc
// 0056bab6  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056baba  8810                 mov byte ptr [eax], dl
// 0056babc  8b6c2c1c             mov ebp, dword ptr [esp + ebp + 0x1c]
// 0056bac0  8b742458             mov esi, dword ptr [esp + 0x58]
// 0056bac4  8b16                 mov edx, dword ptr [esi]
// 0056bac6  8bcd                 mov ecx, ebp
// 0056bac8  2b4c2460             sub ecx, dword ptr [esp + 0x60]
// 0056bacc  5f                   pop edi
// 0056bacd  8d4411ff             lea eax, [ecx + edx - 1]
// 0056bad1  33d2                 xor edx, edx
// 0056bad3  f7f5                 div ebp
// 0056bad5  8a4e0b               mov cl, byte ptr [esi + 0xb]
// 0056bad8  80f908               cmp cl, 8
// 0056badb  5b                   pop ebx
// 0056badc  0fb6c9               movzx ecx, cl
// 0056badf  8906                 mov dword ptr [esi], eax
// 0056bae1  720f                 jb 0x56baf2
// 0056bae3  c1e903               shr ecx, 3
// 0056bae6  0fafc8               imul ecx, eax
// 0056bae9  894e04               mov dword ptr [esi + 4], ecx
// 0056baec  5e                   pop esi
// 0056baed  5d                   pop ebp
// 0056baee  83c444               add esp, 0x44
// 0056baf1  c3                   ret 
// 0056baf2  0fafc8               imul ecx, eax
// 0056baf5  83c107               add ecx, 7
// 0056baf8  c1e903               shr ecx, 3
// 0056bafb  894e04               mov dword ptr [esi + 4], ecx
// 0056bafe  5e                   pop esi
// 0056baff  5d                   pop ebp
// 0056bb00  83c444               add esp, 0x44
// 0056bb03  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_do_write_interlace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
