// from server: 100% by auto
// roc 2012-06 00656f70  unit: seg_00650000  size: 676 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00656f70
//
// 00656f70  83ec44               sub esp, 0x44
// 00656f73  b804000000           mov eax, 4
// 00656f78  55                   push ebp
// 00656f79  33d2                 xor edx, edx
// 00656f7b  89442430             mov dword ptr [esp + 0x30], eax
// 00656f7f  bd02000000           mov ebp, 2
// 00656f84  89442418             mov dword ptr [esp + 0x18], eax
// 00656f88  8944241c             mov dword ptr [esp + 0x1c], eax
// 00656f8c  8b442454             mov eax, dword ptr [esp + 0x54]
// 00656f90  83f806               cmp eax, 6
// 00656f93  56                   push esi
// 00656f94  be01000000           mov esi, 1
// 00656f99  b908000000           mov ecx, 8
// 00656f9e  89542430             mov dword ptr [esp + 0x30], edx
// 00656fa2  89542438             mov dword ptr [esp + 0x38], edx
// 00656fa6  896c243c             mov dword ptr [esp + 0x3c], ebp
// 00656faa  89542440             mov dword ptr [esp + 0x40], edx
// 00656fae  89742444             mov dword ptr [esp + 0x44], esi
// 00656fb2  89542448             mov dword ptr [esp + 0x48], edx
// 00656fb6  894c2414             mov dword ptr [esp + 0x14], ecx
// 00656fba  894c2418             mov dword ptr [esp + 0x18], ecx
// 00656fbe  896c2424             mov dword ptr [esp + 0x24], ebp
// 00656fc2  896c2428             mov dword ptr [esp + 0x28], ebp
// 00656fc6  8974242c             mov dword ptr [esp + 0x2c], esi
// 00656fca  0f8d3e020000         jge 0x65720e
// 00656fd0  53                   push ebx
// 00656fd1  57                   push edi
// 00656fd2  8b7c2458             mov edi, dword ptr [esp + 0x58]
// 00656fd6  0fb65f0b             movzx ebx, byte ptr [edi + 0xb]
// 00656fda  8bcb                 mov ecx, ebx
// 00656fdc  2bce                 sub ecx, esi
// 00656fde  0f8472010000         je 0x657156
// 00656fe4  2bce                 sub ecx, esi
// 00656fe6  0f84e3000000         je 0x6570cf
// 00656fec  2bcd                 sub ecx, ebp
// 00656fee  8d2c8500000000       lea ebp, [eax*4]
// 00656ff5  7467                 je 0x65705e
// 00656ff7  8b17                 mov edx, dword ptr [edi]
// 00656ff9  8b7c2c38             mov edi, dword ptr [esp + ebp + 0x38]
// 00656ffd  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00657001  c1eb03               shr ebx, 3
// 00657004  89542418             mov dword ptr [esp + 0x18], edx
// 00657008  894c2410             mov dword ptr [esp + 0x10], ecx
// 0065700c  897c2460             mov dword ptr [esp + 0x60], edi
// 00657010  3bfa                 cmp edi, edx
// 00657012  0f83b4010000         jae 0x6571cc
// 00657018  8b442c1c             mov eax, dword ptr [esp + ebp + 0x1c]
// 0065701c  8bf7                 mov esi, edi
// 0065701e  0fafc3               imul eax, ebx
// 00657021  0faff3               imul esi, ebx
// 00657024  89442414             mov dword ptr [esp + 0x14], eax
// 00657028  03f1                 add esi, ecx
// 0065702a  8d9b00000000         lea ebx, [ebx]
// 00657030  3bce                 cmp ecx, esi
// 00657032  7413                 je 0x657047
// 00657034  53                   push ebx
// 00657035  56                   push esi
// 00657036  51                   push ecx
// 00657037  e820c63200           call 0x98365c
// 0065703c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00657040  8b442420             mov eax, dword ptr [esp + 0x20]
// 00657044  83c40c               add esp, 0xc
// 00657047  037c2c1c             add edi, dword ptr [esp + ebp + 0x1c]
// 0065704b  03cb                 add ecx, ebx
// 0065704d  03f0                 add esi, eax
// 0065704f  894c2410             mov dword ptr [esp + 0x10], ecx
// 00657053  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 00657057  72d7                 jb 0x657030
// 00657059  e96e010000           jmp 0x6571cc
// 0065705e  8b0f                 mov ecx, dword ptr [edi]
// 00657060  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 00657064  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 00657068  894c2418             mov dword ptr [esp + 0x18], ecx
// 0065706c  897c2410             mov dword ptr [esp + 0x10], edi
// 00657070  be04000000           mov esi, 4
// 00657075  89442460             mov dword ptr [esp + 0x60], eax
// 00657079  3bc1                 cmp eax, ecx
// 0065707b  0f834b010000         jae 0x6571cc
// 00657081  8ad8                 mov bl, al
// 00657083  80e301               and bl, 1
// 00657086  02db                 add bl, bl
// 00657088  02db                 add bl, bl
// 0065708a  b904000000           mov ecx, 4
// 0065708f  2acb                 sub cl, bl
// 00657091  8bd8                 mov ebx, eax
// 00657093  d1eb                 shr ebx, 1
// 00657095  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 00657099  d3eb                 shr ebx, cl
// 0065709b  8bce                 mov ecx, esi
// 0065709d  83e30f               and ebx, 0xf
// 006570a0  d3e3                 shl ebx, cl
// 006570a2  0bd3                 or edx, ebx
// 006570a4  85f6                 test esi, esi
// 006570a6  7512                 jne 0x6570ba
// 006570a8  8d7104               lea esi, [ecx + 4]
// 006570ab  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006570af  8811                 mov byte ptr [ecx], dl
// 006570b1  41                   inc ecx
// 006570b2  894c2410             mov dword ptr [esp + 0x10], ecx
// 006570b6  33d2                 xor edx, edx
// 006570b8  eb03                 jmp 0x6570bd
// 006570ba  83ee04               sub esi, 4
// 006570bd  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 006570c1  3b442418             cmp eax, dword ptr [esp + 0x18]
// 006570c5  72ba                 jb 0x657081
// 006570c7  83fe04               cmp esi, 4
// 006570ca  e9f5000000           jmp 0x6571c4
// 006570cf  8b0f                 mov ecx, dword ptr [edi]
// 006570d1  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 006570d5  8d2c8500000000       lea ebp, [eax*4]
// 006570dc  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 006570e0  894c2418             mov dword ptr [esp + 0x18], ecx
// 006570e4  897c2410             mov dword ptr [esp + 0x10], edi
// 006570e8  be06000000           mov esi, 6
// 006570ed  89442460             mov dword ptr [esp + 0x60], eax
// 006570f1  3bc1                 cmp eax, ecx
// 006570f3  0f83d3000000         jae 0x6571cc
// 006570f9  8da42400000000       lea esp, [esp]
// 00657100  8ad8                 mov bl, al
// 00657102  80e303               and bl, 3
// 00657105  b903000000           mov ecx, 3
// 0065710a  2acb                 sub cl, bl
// 0065710c  8bd8                 mov ebx, eax
// 0065710e  c1eb02               shr ebx, 2
// 00657111  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 00657115  02c9                 add cl, cl
// 00657117  d3eb                 shr ebx, cl
// 00657119  8bce                 mov ecx, esi
// 0065711b  83e303               and ebx, 3
// 0065711e  d3e3                 shl ebx, cl
// 00657120  0bd3                 or edx, ebx
// 00657122  85f6                 test esi, esi
// 00657124  7512                 jne 0x657138
// 00657126  8d7106               lea esi, [ecx + 6]
// 00657129  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065712d  8811                 mov byte ptr [ecx], dl
// 0065712f  41                   inc ecx
// 00657130  894c2410             mov dword ptr [esp + 0x10], ecx
// 00657134  33d2                 xor edx, edx
// 00657136  eb03                 jmp 0x65713b
// 00657138  83ee02               sub esi, 2
// 0065713b  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0065713f  3b442418             cmp eax, dword ptr [esp + 0x18]
// 00657143  72bb                 jb 0x657100
// 00657145  83fe06               cmp esi, 6
// 00657148  0f847e000000         je 0x6571cc
// 0065714e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00657152  8811                 mov byte ptr [ecx], dl
// 00657154  eb76                 jmp 0x6571cc
// 00657156  8b0f                 mov ecx, dword ptr [edi]
// 00657158  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0065715c  8d2c8500000000       lea ebp, [eax*4]
// 00657163  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 00657167  894c2418             mov dword ptr [esp + 0x18], ecx
// 0065716b  897c2410             mov dword ptr [esp + 0x10], edi
// 0065716f  be07000000           mov esi, 7
// 00657174  89442460             mov dword ptr [esp + 0x60], eax
// 00657178  3bc1                 cmp eax, ecx
// 0065717a  7350                 jae 0x6571cc
// 0065717c  8d642400             lea esp, [esp]
// 00657180  8ad8                 mov bl, al
// 00657182  80e307               and bl, 7
// 00657185  b907000000           mov ecx, 7
// 0065718a  2acb                 sub cl, bl
// 0065718c  8bd8                 mov ebx, eax
// 0065718e  c1eb03               shr ebx, 3
// 00657191  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 00657195  d3eb                 shr ebx, cl
// 00657197  8bce                 mov ecx, esi
// 00657199  83e301               and ebx, 1
// 0065719c  d3e3                 shl ebx, cl
// 0065719e  0bd3                 or edx, ebx
// 006571a0  85f6                 test esi, esi
// 006571a2  7512                 jne 0x6571b6
// 006571a4  8d7107               lea esi, [ecx + 7]
// 006571a7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006571ab  8811                 mov byte ptr [ecx], dl
// 006571ad  41                   inc ecx
// 006571ae  894c2410             mov dword ptr [esp + 0x10], ecx
// 006571b2  33d2                 xor edx, edx
// 006571b4  eb01                 jmp 0x6571b7
// 006571b6  4e                   dec esi
// 006571b7  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 006571bb  3b442418             cmp eax, dword ptr [esp + 0x18]
// 006571bf  72bf                 jb 0x657180
// 006571c1  83fe07               cmp esi, 7
// 006571c4  7406                 je 0x6571cc
// 006571c6  8b442410             mov eax, dword ptr [esp + 0x10]
// 006571ca  8810                 mov byte ptr [eax], dl
// 006571cc  8b6c2c1c             mov ebp, dword ptr [esp + ebp + 0x1c]
// 006571d0  8b742458             mov esi, dword ptr [esp + 0x58]
// 006571d4  8b16                 mov edx, dword ptr [esi]
// 006571d6  8bcd                 mov ecx, ebp
// 006571d8  2b4c2460             sub ecx, dword ptr [esp + 0x60]
// 006571dc  5f                   pop edi
// 006571dd  8d4411ff             lea eax, [ecx + edx - 1]
// 006571e1  33d2                 xor edx, edx
// 006571e3  f7f5                 div ebp
// 006571e5  8a4e0b               mov cl, byte ptr [esi + 0xb]
// 006571e8  80f908               cmp cl, 8
// 006571eb  5b                   pop ebx
// 006571ec  0fb6c9               movzx ecx, cl
// 006571ef  8906                 mov dword ptr [esi], eax
// 006571f1  720f                 jb 0x657202
// 006571f3  c1e903               shr ecx, 3
// 006571f6  0fafc8               imul ecx, eax
// 006571f9  894e04               mov dword ptr [esi + 4], ecx
// 006571fc  5e                   pop esi
// 006571fd  5d                   pop ebp
// 006571fe  83c444               add esp, 0x44
// 00657201  c3                   ret 
// 00657202  0fafc8               imul ecx, eax
// 00657205  83c107               add ecx, 7
// 00657208  c1e903               shr ecx, 3
// 0065720b  894e04               mov dword ptr [esi + 4], ecx
// 0065720e  5e                   pop esi
// 0065720f  5d                   pop ebp
// 00657210  83c444               add esp, 0x44
// 00657213  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_do_write_interlace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
