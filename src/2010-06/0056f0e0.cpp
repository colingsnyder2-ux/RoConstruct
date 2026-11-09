// from server: 100% by auto
// roc 2010-06 0056f0e0  unit: G3D::LineSegment  size: 676 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056f0e0
//
// 0056f0e0  83ec44               sub esp, 0x44
// 0056f0e3  b804000000           mov eax, 4
// 0056f0e8  55                   push ebp
// 0056f0e9  33d2                 xor edx, edx
// 0056f0eb  89442430             mov dword ptr [esp + 0x30], eax
// 0056f0ef  bd02000000           mov ebp, 2
// 0056f0f4  89442418             mov dword ptr [esp + 0x18], eax
// 0056f0f8  8944241c             mov dword ptr [esp + 0x1c], eax
// 0056f0fc  8b442454             mov eax, dword ptr [esp + 0x54]
// 0056f100  83f806               cmp eax, 6
// 0056f103  56                   push esi
// 0056f104  be01000000           mov esi, 1
// 0056f109  b908000000           mov ecx, 8
// 0056f10e  89542430             mov dword ptr [esp + 0x30], edx
// 0056f112  89542438             mov dword ptr [esp + 0x38], edx
// 0056f116  896c243c             mov dword ptr [esp + 0x3c], ebp
// 0056f11a  89542440             mov dword ptr [esp + 0x40], edx
// 0056f11e  89742444             mov dword ptr [esp + 0x44], esi
// 0056f122  89542448             mov dword ptr [esp + 0x48], edx
// 0056f126  894c2414             mov dword ptr [esp + 0x14], ecx
// 0056f12a  894c2418             mov dword ptr [esp + 0x18], ecx
// 0056f12e  896c2424             mov dword ptr [esp + 0x24], ebp
// 0056f132  896c2428             mov dword ptr [esp + 0x28], ebp
// 0056f136  8974242c             mov dword ptr [esp + 0x2c], esi
// 0056f13a  0f8d3e020000         jge 0x56f37e
// 0056f140  53                   push ebx
// 0056f141  57                   push edi
// 0056f142  8b7c2458             mov edi, dword ptr [esp + 0x58]
// 0056f146  0fb65f0b             movzx ebx, byte ptr [edi + 0xb]
// 0056f14a  8bcb                 mov ecx, ebx
// 0056f14c  2bce                 sub ecx, esi
// 0056f14e  0f8472010000         je 0x56f2c6
// 0056f154  2bce                 sub ecx, esi
// 0056f156  0f84e3000000         je 0x56f23f
// 0056f15c  2bcd                 sub ecx, ebp
// 0056f15e  8d2c8500000000       lea ebp, [eax*4]
// 0056f165  7467                 je 0x56f1ce
// 0056f167  8b17                 mov edx, dword ptr [edi]
// 0056f169  8b7c2c38             mov edi, dword ptr [esp + ebp + 0x38]
// 0056f16d  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0056f171  c1eb03               shr ebx, 3
// 0056f174  89542418             mov dword ptr [esp + 0x18], edx
// 0056f178  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056f17c  897c2460             mov dword ptr [esp + 0x60], edi
// 0056f180  3bfa                 cmp edi, edx
// 0056f182  0f83b4010000         jae 0x56f33c
// 0056f188  8b442c1c             mov eax, dword ptr [esp + ebp + 0x1c]
// 0056f18c  8bf7                 mov esi, edi
// 0056f18e  0fafc3               imul eax, ebx
// 0056f191  0faff3               imul esi, ebx
// 0056f194  89442414             mov dword ptr [esp + 0x14], eax
// 0056f198  03f1                 add esi, ecx
// 0056f19a  8d9b00000000         lea ebx, [ebx]
// 0056f1a0  3bce                 cmp ecx, esi
// 0056f1a2  7413                 je 0x56f1b7
// 0056f1a4  53                   push ebx
// 0056f1a5  56                   push esi
// 0056f1a6  51                   push ecx
// 0056f1a7  e87a9c2300           call 0x7a8e26
// 0056f1ac  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056f1b0  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056f1b4  83c40c               add esp, 0xc
// 0056f1b7  037c2c1c             add edi, dword ptr [esp + ebp + 0x1c]
// 0056f1bb  03cb                 add ecx, ebx
// 0056f1bd  03f0                 add esi, eax
// 0056f1bf  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056f1c3  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 0056f1c7  72d7                 jb 0x56f1a0
// 0056f1c9  e96e010000           jmp 0x56f33c
// 0056f1ce  8b0f                 mov ecx, dword ptr [edi]
// 0056f1d0  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0056f1d4  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0056f1d8  894c2418             mov dword ptr [esp + 0x18], ecx
// 0056f1dc  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f1e0  be04000000           mov esi, 4
// 0056f1e5  89442460             mov dword ptr [esp + 0x60], eax
// 0056f1e9  3bc1                 cmp eax, ecx
// 0056f1eb  0f834b010000         jae 0x56f33c
// 0056f1f1  8ad8                 mov bl, al
// 0056f1f3  80e301               and bl, 1
// 0056f1f6  02db                 add bl, bl
// 0056f1f8  02db                 add bl, bl
// 0056f1fa  b904000000           mov ecx, 4
// 0056f1ff  2acb                 sub cl, bl
// 0056f201  8bd8                 mov ebx, eax
// 0056f203  d1eb                 shr ebx, 1
// 0056f205  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0056f209  d3eb                 shr ebx, cl
// 0056f20b  8bce                 mov ecx, esi
// 0056f20d  83e30f               and ebx, 0xf
// 0056f210  d3e3                 shl ebx, cl
// 0056f212  0bd3                 or edx, ebx
// 0056f214  85f6                 test esi, esi
// 0056f216  7512                 jne 0x56f22a
// 0056f218  8d7104               lea esi, [ecx + 4]
// 0056f21b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056f21f  8811                 mov byte ptr [ecx], dl
// 0056f221  41                   inc ecx
// 0056f222  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056f226  33d2                 xor edx, edx
// 0056f228  eb03                 jmp 0x56f22d
// 0056f22a  83ee04               sub esi, 4
// 0056f22d  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0056f231  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0056f235  72ba                 jb 0x56f1f1
// 0056f237  83fe04               cmp esi, 4
// 0056f23a  e9f5000000           jmp 0x56f334
// 0056f23f  8b0f                 mov ecx, dword ptr [edi]
// 0056f241  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0056f245  8d2c8500000000       lea ebp, [eax*4]
// 0056f24c  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0056f250  894c2418             mov dword ptr [esp + 0x18], ecx
// 0056f254  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f258  be06000000           mov esi, 6
// 0056f25d  89442460             mov dword ptr [esp + 0x60], eax
// 0056f261  3bc1                 cmp eax, ecx
// 0056f263  0f83d3000000         jae 0x56f33c
// 0056f269  8da42400000000       lea esp, [esp]
// 0056f270  8ad8                 mov bl, al
// 0056f272  80e303               and bl, 3
// 0056f275  b903000000           mov ecx, 3
// 0056f27a  2acb                 sub cl, bl
// 0056f27c  8bd8                 mov ebx, eax
// 0056f27e  c1eb02               shr ebx, 2
// 0056f281  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0056f285  02c9                 add cl, cl
// 0056f287  d3eb                 shr ebx, cl
// 0056f289  8bce                 mov ecx, esi
// 0056f28b  83e303               and ebx, 3
// 0056f28e  d3e3                 shl ebx, cl
// 0056f290  0bd3                 or edx, ebx
// 0056f292  85f6                 test esi, esi
// 0056f294  7512                 jne 0x56f2a8
// 0056f296  8d7106               lea esi, [ecx + 6]
// 0056f299  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056f29d  8811                 mov byte ptr [ecx], dl
// 0056f29f  41                   inc ecx
// 0056f2a0  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056f2a4  33d2                 xor edx, edx
// 0056f2a6  eb03                 jmp 0x56f2ab
// 0056f2a8  83ee02               sub esi, 2
// 0056f2ab  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0056f2af  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0056f2b3  72bb                 jb 0x56f270
// 0056f2b5  83fe06               cmp esi, 6
// 0056f2b8  0f847e000000         je 0x56f33c
// 0056f2be  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056f2c2  8811                 mov byte ptr [ecx], dl
// 0056f2c4  eb76                 jmp 0x56f33c
// 0056f2c6  8b0f                 mov ecx, dword ptr [edi]
// 0056f2c8  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0056f2cc  8d2c8500000000       lea ebp, [eax*4]
// 0056f2d3  8b442c38             mov eax, dword ptr [esp + ebp + 0x38]
// 0056f2d7  894c2418             mov dword ptr [esp + 0x18], ecx
// 0056f2db  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f2df  be07000000           mov esi, 7
// 0056f2e4  89442460             mov dword ptr [esp + 0x60], eax
// 0056f2e8  3bc1                 cmp eax, ecx
// 0056f2ea  7350                 jae 0x56f33c
// 0056f2ec  8d642400             lea esp, [esp]
// 0056f2f0  8ad8                 mov bl, al
// 0056f2f2  80e307               and bl, 7
// 0056f2f5  b907000000           mov ecx, 7
// 0056f2fa  2acb                 sub cl, bl
// 0056f2fc  8bd8                 mov ebx, eax
// 0056f2fe  c1eb03               shr ebx, 3
// 0056f301  0fb61c3b             movzx ebx, byte ptr [ebx + edi]
// 0056f305  d3eb                 shr ebx, cl
// 0056f307  8bce                 mov ecx, esi
// 0056f309  83e301               and ebx, 1
// 0056f30c  d3e3                 shl ebx, cl
// 0056f30e  0bd3                 or edx, ebx
// 0056f310  85f6                 test esi, esi
// 0056f312  7512                 jne 0x56f326
// 0056f314  8d7107               lea esi, [ecx + 7]
// 0056f317  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056f31b  8811                 mov byte ptr [ecx], dl
// 0056f31d  41                   inc ecx
// 0056f31e  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056f322  33d2                 xor edx, edx
// 0056f324  eb01                 jmp 0x56f327
// 0056f326  4e                   dec esi
// 0056f327  03442c1c             add eax, dword ptr [esp + ebp + 0x1c]
// 0056f32b  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0056f32f  72bf                 jb 0x56f2f0
// 0056f331  83fe07               cmp esi, 7
// 0056f334  7406                 je 0x56f33c
// 0056f336  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056f33a  8810                 mov byte ptr [eax], dl
// 0056f33c  8b6c2c1c             mov ebp, dword ptr [esp + ebp + 0x1c]
// 0056f340  8b742458             mov esi, dword ptr [esp + 0x58]
// 0056f344  8b16                 mov edx, dword ptr [esi]
// 0056f346  8bcd                 mov ecx, ebp
// 0056f348  2b4c2460             sub ecx, dword ptr [esp + 0x60]
// 0056f34c  5f                   pop edi
// 0056f34d  8d4411ff             lea eax, [ecx + edx - 1]
// 0056f351  33d2                 xor edx, edx
// 0056f353  f7f5                 div ebp
// 0056f355  8a4e0b               mov cl, byte ptr [esi + 0xb]
// 0056f358  80f908               cmp cl, 8
// 0056f35b  5b                   pop ebx
// 0056f35c  0fb6c9               movzx ecx, cl
// 0056f35f  8906                 mov dword ptr [esi], eax
// 0056f361  720f                 jb 0x56f372
// 0056f363  c1e903               shr ecx, 3
// 0056f366  0fafc8               imul ecx, eax
// 0056f369  894e04               mov dword ptr [esi + 4], ecx
// 0056f36c  5e                   pop esi
// 0056f36d  5d                   pop ebp
// 0056f36e  83c444               add esp, 0x44
// 0056f371  c3                   ret 
// 0056f372  0fafc8               imul ecx, eax
// 0056f375  83c107               add ecx, 7
// 0056f378  c1e903               shr ecx, 3
// 0056f37b  894e04               mov dword ptr [esi + 4], ecx
// 0056f37e  5e                   pop esi
// 0056f37f  5d                   pop ebp
// 0056f380  83c444               add esp, 0x44
// 0056f383  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_do_write_interlace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
