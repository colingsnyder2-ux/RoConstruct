// from server: 100% by auto
// roc 2009-12 0060d7c0  unit: seg_00600000  size: 676 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060d7c0
//
// 0060d7c0  83ec44               sub esp, 0x44
// 0060d7c3  b804000000           mov eax, 4
// 0060d7c8  55                   push ebp
// 0060d7c9  33d2                 xor edx, edx
// 0060d7cb  89442430             mov dword ptr [esp + 0x30], eax
// 0060d7cf  bd02000000           mov ebp, 2
// 0060d7d4  89442418             mov dword ptr [esp + 0x18], eax
// 0060d7d8  8944241c             mov dword ptr [esp + 0x1c], eax
// 0060d7dc  8b442454             mov eax, dword ptr [esp + 0x54]
// 0060d7e0  83f806               cmp eax, 6
// 0060d7e3  56                   push esi
// 0060d7e4  be01000000           mov esi, 1
// 0060d7e9  b908000000           mov ecx, 8
// 0060d7ee  89542430             mov dword ptr [esp + 0x30], edx
// 0060d7f2  89542438             mov dword ptr [esp + 0x38], edx
// 0060d7f6  896c243c             mov dword ptr [esp + 0x3c], ebp
// 0060d7fa  89542440             mov dword ptr [esp + 0x40], edx
// 0060d7fe  89742444             mov dword ptr [esp + 0x44], esi
// 0060d802  89542448             mov dword ptr [esp + 0x48], edx
// 0060d806  894c2414             mov dword ptr [esp + 0x14], ecx
// 0060d80a  894c2418             mov dword ptr [esp + 0x18], ecx
// 0060d80e  896c2424             mov dword ptr [esp + 0x24], ebp
// 0060d812  896c2428             mov dword ptr [esp + 0x28], ebp
// 0060d816  8974242c             mov dword ptr [esp + 0x2c], esi
// 0060d81a  0f8d3e020000         jge 0x60da5e
// 0060d820  53                   push ebx
// 0060d821  57                   push edi
// 0060d822  8b7c2458             mov edi, dword ptr [esp + 0x58]
// 0060d826  0fb65f0b             movzx ebx, byte ptr [edi + 0xb]
// 0060d82a  8bcb                 mov ecx, ebx
// 0060d82c  2bce                 sub ecx, esi
// 0060d82e  0f8472010000         je 0x60d9a6
// 0060d834  2bce                 sub ecx, esi
// 0060d836  0f84e3000000         je 0x60d91f
// 0060d83c  2bcd                 sub ecx, ebp
// 0060d83e  8d2c8500000000       lea ebp, [eax*4]
// 0060d845  7467                 je 0x60d8ae
// 0060d847  8b17                 mov edx, dword ptr [edi]
// 0060d849  8b7c2c38             mov edi, dword ptr [esp + ebp + 0x38]
// 0060d84d  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0060d851  c1eb03               shr ebx, 3
// 0060d854  89542418             mov dword ptr [esp + 0x18], edx
// 0060d858  894c2410             mov dword ptr [esp + 0x10], ecx
// 0060d85c  897c2460             mov dword ptr [esp + 0x60], edi
// 0060d860  3bfa                 cmp edi, edx
// 0060d862  0f83b4010000         jae 0x60da1c
// 0060d868  8b442c1c             mov eax, dword ptr [esp + ebp + 0x1c]
// 0060d86c  8bf7                 mov esi, edi
// 0060d86e  0fafc3               imul eax, ebx
// 0060d871  0faff3               imul esi, ebx
// 0060d874  89442414             mov dword ptr [esp + 0x14], eax
// 0060d878  03f1                 add esi, ecx
// 0060d87a  8d9b00000000         lea ebx, [ebx]
// 0060d880  3bce                 cmp ecx, esi
// 0060d882  7413                 je 0x60d897
// 0060d884  53                   push ebx
// 0060d885  56                   push esi
// 0060d886  51                   push ecx
// 0060d887  e85a741e00           call 0x7f4ce6
// 0060d88c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060d890  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060d894  83c40c               add esp, 0xc
// 0060d897  037c2c1c             add edi, dword ptr [esp + ebp + 0x1c]
// 0060d89b  03cb                 add ecx, ebx
// 0060d89d  03f0                 add esi, eax
// 0060d89f  894c2410             mov dword ptr [esp + 0x10], ecx
// 0060d8a3  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 0060d8a7  72d7                 jb 0x60d880
// 0060d8a9  e96e010000           jmp 0x60da1c
// 0060d8ae  8b0f                 mov ecx, dword ptr [edi]
// 0060d8b0  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0060d8b4  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0060d8b8  894c2418             mov dword ptr [esp + 0x18], ecx
// 0060d8bc  897c2410             mov dword ptr [esp + 0x10], edi
// 0060d8c0  be04000000           mov esi, 4
// 0060d8c5  89442460             mov dword ptr [esp + 0x60], eax
// 0060d8c9  3bc1                 cmp eax, ecx
// 0060d8cb  0f834b010000         jae 0x60da1c
// 0060d8d1  8ad8                 mov bl, al
// 0060d8d3  80e301               and bl, 1
// 0060d8d6  02db                 add bl, bl
// 0060d8d8  02db                 add bl, bl
// 0060d8da  b904000000           mov ecx, 4
// 0060d8df  2acb                 sub cl, bl
// 0060d8e1  8bd8                 mov ebx, eax
// 0060d8e3  d1eb                 shr ebx, 1
// 0060d8e5  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0060d8e9  d3eb                 shr ebx, cl
// 0060d8eb  8bce                 mov ecx, esi
// 0060d8ed  83e30f               and ebx, 0xf
// 0060d8f0  d3e3                 shl ebx, cl
// 0060d8f2  0bd3                 or edx, ebx
// 0060d8f4  85f6                 test esi, esi
// 0060d8f6  7512                 jne 0x60d90a
// 0060d8f8  8d7104               lea esi, [ecx + 4]
// 0060d8fb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0060d8ff  8811                 mov byte ptr [ecx], dl
// 0060d901  41                   inc ecx
// 0060d902  894c2410             mov dword ptr [esp + 0x10], ecx
// 0060d906  33d2                 xor edx, edx
// 0060d908  eb03                 jmp 0x60d90d
// 0060d90a  83ee04               sub esi, 4
// 0060d90d  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0060d911  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0060d915  72ba                 jb 0x60d8d1
// 0060d917  83fe04               cmp esi, 4
// 0060d91a  e9f5000000           jmp 0x60da14
// 0060d91f  8b0f                 mov ecx, dword ptr [edi]
// 0060d921  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0060d925  8d2c8500000000       lea ebp, [eax*4]
// 0060d92c  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0060d930  894c2418             mov dword ptr [esp + 0x18], ecx
// 0060d934  897c2410             mov dword ptr [esp + 0x10], edi
// 0060d938  be06000000           mov esi, 6
// 0060d93d  89442460             mov dword ptr [esp + 0x60], eax
// 0060d941  3bc1                 cmp eax, ecx
// 0060d943  0f83d3000000         jae 0x60da1c
// 0060d949  8da42400000000       lea esp, [esp]
// 0060d950  8ad8                 mov bl, al
// 0060d952  80e303               and bl, 3
// 0060d955  b903000000           mov ecx, 3
// 0060d95a  2acb                 sub cl, bl
// 0060d95c  8bd8                 mov ebx, eax
// 0060d95e  c1eb02               shr ebx, 2
// 0060d961  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0060d965  02c9                 add cl, cl
// 0060d967  d3eb                 shr ebx, cl
// 0060d969  8bce                 mov ecx, esi
// 0060d96b  83e303               and ebx, 3
// 0060d96e  d3e3                 shl ebx, cl
// 0060d970  0bd3                 or edx, ebx
// 0060d972  85f6                 test esi, esi
// 0060d974  7512                 jne 0x60d988
// 0060d976  8d7106               lea esi, [ecx + 6]
// 0060d979  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0060d97d  8811                 mov byte ptr [ecx], dl
// 0060d97f  41                   inc ecx
// 0060d980  894c2410             mov dword ptr [esp + 0x10], ecx
// 0060d984  33d2                 xor edx, edx
// 0060d986  eb03                 jmp 0x60d98b
// 0060d988  83ee02               sub esi, 2
// 0060d98b  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0060d98f  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0060d993  72bb                 jb 0x60d950
// 0060d995  83fe06               cmp esi, 6
// 0060d998  0f847e000000         je 0x60da1c
// 0060d99e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0060d9a2  8811                 mov byte ptr [ecx], dl
// 0060d9a4  eb76                 jmp 0x60da1c
// 0060d9a6  8b0f                 mov ecx, dword ptr [edi]
// 0060d9a8  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0060d9ac  8d2c8500000000       lea ebp, [eax*4]
// 0060d9b3  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0060d9b7  894c2418             mov dword ptr [esp + 0x18], ecx
// 0060d9bb  897c2410             mov dword ptr [esp + 0x10], edi
// 0060d9bf  be07000000           mov esi, 7
// 0060d9c4  89442460             mov dword ptr [esp + 0x60], eax
// 0060d9c8  3bc1                 cmp eax, ecx
// 0060d9ca  7350                 jae 0x60da1c
// 0060d9cc  8d642400             lea esp, [esp]
// 0060d9d0  8ad8                 mov bl, al
// 0060d9d2  80e307               and bl, 7
// 0060d9d5  b907000000           mov ecx, 7
// 0060d9da  2acb                 sub cl, bl
// 0060d9dc  8bd8                 mov ebx, eax
// 0060d9de  c1eb03               shr ebx, 3
// 0060d9e1  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0060d9e5  d3eb                 shr ebx, cl
// 0060d9e7  8bce                 mov ecx, esi
// 0060d9e9  83e301               and ebx, 1
// 0060d9ec  d3e3                 shl ebx, cl
// 0060d9ee  0bd3                 or edx, ebx
// 0060d9f0  85f6                 test esi, esi
// 0060d9f2  7512                 jne 0x60da06
// 0060d9f4  8d7107               lea esi, [ecx + 7]
// 0060d9f7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0060d9fb  8811                 mov byte ptr [ecx], dl
// 0060d9fd  41                   inc ecx
// 0060d9fe  894c2410             mov dword ptr [esp + 0x10], ecx
// 0060da02  33d2                 xor edx, edx
// 0060da04  eb01                 jmp 0x60da07
// 0060da06  4e                   dec esi
// 0060da07  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0060da0b  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0060da0f  72bf                 jb 0x60d9d0
// 0060da11  83fe07               cmp esi, 7
// 0060da14  7406                 je 0x60da1c
// 0060da16  8b442410             mov eax, dword ptr [esp + 0x10]
// 0060da1a  8810                 mov byte ptr [eax], dl
// 0060da1c  8b6c2c1c             mov ebp, dword ptr [esp + ebp + 0x1c]
// 0060da20  8b742458             mov esi, dword ptr [esp + 0x58]
// 0060da24  8b16                 mov edx, dword ptr [esi]
// 0060da26  8bcd                 mov ecx, ebp
// 0060da28  2b4c2460             sub ecx, dword ptr [esp + 0x60]
// 0060da2c  5f                   pop edi
// 0060da2d  8d4411ff             lea eax, [ecx + edx - 1]
// 0060da31  33d2                 xor edx, edx
// 0060da33  f7f5                 div ebp
// 0060da35  8a4e0b               mov cl, byte ptr [esi + 0xb]
// 0060da38  80f908               cmp cl, 8
// 0060da3b  5b                   pop ebx
// 0060da3c  0fb6c9               movzx ecx, cl
// 0060da3f  8906                 mov dword ptr [esi], eax
// 0060da41  720f                 jb 0x60da52
// 0060da43  c1e903               shr ecx, 3
// 0060da46  0fafc8               imul ecx, eax
// 0060da49  894e04               mov dword ptr [esi + 4], ecx
// 0060da4c  5e                   pop esi
// 0060da4d  5d                   pop ebp
// 0060da4e  83c444               add esp, 0x44
// 0060da51  c3                   ret 
// 0060da52  0fafc8               imul ecx, eax
// 0060da55  83c107               add ecx, 7
// 0060da58  c1e903               shr ecx, 3
// 0060da5b  894e04               mov dword ptr [esi + 4], ecx
// 0060da5e  5e                   pop esi
// 0060da5f  5d                   pop ebp
// 0060da60  83c444               add esp, 0x44
// 0060da63  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_do_write_interlace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
