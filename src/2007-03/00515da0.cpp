// from server: 100% by auto
// roc 2007-03 00515da0  unit: seg_00510000  size: 575 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00515da0
//
// 00515da0  51                   push ecx
// 00515da1  8b442410             mov eax, dword ptr [esp + 0x10]
// 00515da5  83f806               cmp eax, 6
// 00515da8  0f8d2f020000         jge 0x515fdd
// 00515dae  53                   push ebx
// 00515daf  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00515db3  0fb64b0b             movzx ecx, byte ptr [ebx + 0xb]
// 00515db7  55                   push ebp
// 00515db8  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00515dbc  56                   push esi
// 00515dbd  8bd1                 mov edx, ecx
// 00515dbf  83ea01               sub edx, 1
// 00515dc2  57                   push edi
// 00515dc3  8d348500000000       lea esi, [eax*4]
// 00515dca  0f8456010000         je 0x515f26
// 00515dd0  83ea01               sub edx, 1
// 00515dd3  0f84cb000000         je 0x515ea4
// 00515dd9  83ea02               sub edx, 2
// 00515ddc  7453                 je 0x515e31
// 00515dde  8b13                 mov edx, dword ptr [ebx]
// 00515de0  8bbe440f7a00         mov edi, dword ptr [esi + 0x7a0f44]
// 00515de6  c1e903               shr ecx, 3
// 00515de9  3bfa                 cmp edi, edx
// 00515deb  89542410             mov dword ptr [esp + 0x10], edx
// 00515def  894c2420             mov dword ptr [esp + 0x20], ecx
// 00515df3  0f83a0010000         jae 0x515f99
// 00515df9  8da42400000000       lea esp, [esp]
// 00515e00  8bc7                 mov eax, edi
// 00515e02  0fafc1               imul eax, ecx
// 00515e05  0344241c             add eax, dword ptr [esp + 0x1c]
// 00515e09  3be8                 cmp ebp, eax
// 00515e0b  7413                 je 0x515e20
// 00515e0d  51                   push ecx
// 00515e0e  50                   push eax
// 00515e0f  55                   push ebp
// 00515e10  e8cd931000           call 0x61f1e2
// 00515e15  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00515e19  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00515e1d  83c40c               add esp, 0xc
// 00515e20  03be600f7a00         add edi, dword ptr [esi + 0x7a0f60]
// 00515e26  03e9                 add ebp, ecx
// 00515e28  3bfa                 cmp edi, edx
// 00515e2a  72d4                 jb 0x515e00
// 00515e2c  e968010000           jmp 0x515f99
// 00515e31  8b0b                 mov ecx, dword ptr [ebx]
// 00515e33  8b86440f7a00         mov eax, dword ptr [esi + 0x7a0f44]
// 00515e39  33d2                 xor edx, edx
// 00515e3b  3bc1                 cmp eax, ecx
// 00515e3d  894c2410             mov dword ptr [esp + 0x10], ecx
// 00515e41  896c2420             mov dword ptr [esp + 0x20], ebp
// 00515e45  bf04000000           mov edi, 4
// 00515e4a  0f8349010000         jae 0x515f99
// 00515e50  8ad8                 mov bl, al
// 00515e52  80e301               and bl, 1
// 00515e55  02db                 add bl, bl
// 00515e57  02db                 add bl, bl
// 00515e59  b904000000           mov ecx, 4
// 00515e5e  2acb                 sub cl, bl
// 00515e60  8bd8                 mov ebx, eax
// 00515e62  d1eb                 shr ebx, 1
// 00515e64  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 00515e68  d3eb                 shr ebx, cl
// 00515e6a  8bcf                 mov ecx, edi
// 00515e6c  83e30f               and ebx, 0xf
// 00515e6f  d3e3                 shl ebx, cl
// 00515e71  0bd3                 or edx, ebx
// 00515e73  85ff                 test edi, edi
// 00515e75  7516                 jne 0x515e8d
// 00515e77  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00515e7b  8811                 mov byte ptr [ecx], dl
// 00515e7d  83c101               add ecx, 1
// 00515e80  bf04000000           mov edi, 4
// 00515e85  894c2420             mov dword ptr [esp + 0x20], ecx
// 00515e89  33d2                 xor edx, edx
// 00515e8b  eb03                 jmp 0x515e90
// 00515e8d  83ef04               sub edi, 4
// 00515e90  0386600f7a00         add eax, dword ptr [esi + 0x7a0f60]
// 00515e96  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00515e9a  72b4                 jb 0x515e50
// 00515e9c  83ff04               cmp edi, 4
// 00515e9f  e9e9000000           jmp 0x515f8d
// 00515ea4  8b0b                 mov ecx, dword ptr [ebx]
// 00515ea6  8b86440f7a00         mov eax, dword ptr [esi + 0x7a0f44]
// 00515eac  33d2                 xor edx, edx
// 00515eae  3bc1                 cmp eax, ecx
// 00515eb0  894c2410             mov dword ptr [esp + 0x10], ecx
// 00515eb4  896c2420             mov dword ptr [esp + 0x20], ebp
// 00515eb8  bf06000000           mov edi, 6
// 00515ebd  0f83d6000000         jae 0x515f99
// 00515ec3  8ad8                 mov bl, al
// 00515ec5  80e303               and bl, 3
// 00515ec8  b903000000           mov ecx, 3
// 00515ecd  2acb                 sub cl, bl
// 00515ecf  8bd8                 mov ebx, eax
// 00515ed1  c1eb02               shr ebx, 2
// 00515ed4  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 00515ed8  02c9                 add cl, cl
// 00515eda  d3eb                 shr ebx, cl
// 00515edc  8bcf                 mov ecx, edi
// 00515ede  83e303               and ebx, 3
// 00515ee1  d3e3                 shl ebx, cl
// 00515ee3  0bd3                 or edx, ebx
// 00515ee5  85ff                 test edi, edi
// 00515ee7  7516                 jne 0x515eff
// 00515ee9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00515eed  8811                 mov byte ptr [ecx], dl
// 00515eef  83c101               add ecx, 1
// 00515ef2  bf06000000           mov edi, 6
// 00515ef7  894c2420             mov dword ptr [esp + 0x20], ecx
// 00515efb  33d2                 xor edx, edx
// 00515efd  eb03                 jmp 0x515f02
// 00515eff  83ef02               sub edi, 2
// 00515f02  0386600f7a00         add eax, dword ptr [esi + 0x7a0f60]
// 00515f08  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00515f0c  72b5                 jb 0x515ec3
// 00515f0e  83ff06               cmp edi, 6
// 00515f11  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00515f15  0f847e000000         je 0x515f99
// 00515f1b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00515f1f  8811                 mov byte ptr [ecx], dl
// 00515f21  e973000000           jmp 0x515f99
// 00515f26  8b0b                 mov ecx, dword ptr [ebx]
// 00515f28  8b86440f7a00         mov eax, dword ptr [esi + 0x7a0f44]
// 00515f2e  33d2                 xor edx, edx
// 00515f30  3bc1                 cmp eax, ecx
// 00515f32  894c2410             mov dword ptr [esp + 0x10], ecx
// 00515f36  896c2420             mov dword ptr [esp + 0x20], ebp
// 00515f3a  bf07000000           mov edi, 7
// 00515f3f  7358                 jae 0x515f99
// 00515f41  8ad8                 mov bl, al
// 00515f43  80e307               and bl, 7
// 00515f46  b907000000           mov ecx, 7
// 00515f4b  2acb                 sub cl, bl
// 00515f4d  8bd8                 mov ebx, eax
// 00515f4f  c1eb03               shr ebx, 3
// 00515f52  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 00515f56  d3eb                 shr ebx, cl
// 00515f58  8bcf                 mov ecx, edi
// 00515f5a  83e301               and ebx, 1
// 00515f5d  d3e3                 shl ebx, cl
// 00515f5f  0bd3                 or edx, ebx
// 00515f61  85ff                 test edi, edi
// 00515f63  7516                 jne 0x515f7b
// 00515f65  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00515f69  8811                 mov byte ptr [ecx], dl
// 00515f6b  83c101               add ecx, 1
// 00515f6e  bf07000000           mov edi, 7
// 00515f73  894c2420             mov dword ptr [esp + 0x20], ecx
// 00515f77  33d2                 xor edx, edx
// 00515f79  eb03                 jmp 0x515f7e
// 00515f7b  83ef01               sub edi, 1
// 00515f7e  0386600f7a00         add eax, dword ptr [esi + 0x7a0f60]
// 00515f84  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00515f88  72b7                 jb 0x515f41
// 00515f8a  83ff07               cmp edi, 7
// 00515f8d  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00515f91  7406                 je 0x515f99
// 00515f93  8b442420             mov eax, dword ptr [esp + 0x20]
// 00515f97  8810                 mov byte ptr [eax], dl
// 00515f99  8b8e600f7a00         mov ecx, dword ptr [esi + 0x7a0f60]
// 00515f9f  8b03                 mov eax, dword ptr [ebx]
// 00515fa1  8bd1                 mov edx, ecx
// 00515fa3  2b96440f7a00         sub edx, dword ptr [esi + 0x7a0f44]
// 00515fa9  8d4402ff             lea eax, [edx + eax - 1]
// 00515fad  33d2                 xor edx, edx
// 00515faf  f7f1                 div ecx
// 00515fb1  8a4b0b               mov cl, byte ptr [ebx + 0xb]
// 00515fb4  80f908               cmp cl, 8
// 00515fb7  0fb6c9               movzx ecx, cl
// 00515fba  8903                 mov dword ptr [ebx], eax
// 00515fbc  720f                 jb 0x515fcd
// 00515fbe  c1e903               shr ecx, 3
// 00515fc1  0fafc8               imul ecx, eax
// 00515fc4  5f                   pop edi
// 00515fc5  5e                   pop esi
// 00515fc6  5d                   pop ebp
// 00515fc7  894b04               mov dword ptr [ebx + 4], ecx
// 00515fca  5b                   pop ebx
// 00515fcb  59                   pop ecx
// 00515fcc  c3                   ret 
// 00515fcd  0fafc8               imul ecx, eax
// 00515fd0  5f                   pop edi
// 00515fd1  83c107               add ecx, 7
// 00515fd4  5e                   pop esi
// 00515fd5  c1e903               shr ecx, 3
// 00515fd8  5d                   pop ebp
// 00515fd9  894b04               mov dword ptr [ebx + 4], ecx
// 00515fdc  5b                   pop ebx
// 00515fdd  59                   pop ecx
// 00515fde  c3                   ret 
// library libpng-1.2.7/pngwutil.c (function _png_do_write_interlace)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwutil.c
