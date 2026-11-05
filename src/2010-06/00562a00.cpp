// from server: 100% by auto
// roc 2010-06 00562a00  unit: G3D::_internal::DialogTemplate  size: 736 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00562a00
//
// 00562a00  55                   push ebp
// 00562a01  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00562a05  85ed                 test ebp, ebp
// 00562a07  0f84d1020000         je 0x562cde
// 00562a0d  56                   push esi
// 00562a0e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00562a12  85f6                 test esi, esi
// 00562a14  0f84c3020000         je 0x562cdd
// 00562a1a  56                   push esi
// 00562a1b  55                   push ebp
// 00562a1c  e8effdffff           call 0x562810
// 00562a21  83c408               add esp, 8
// 00562a24  f6460808             test byte ptr [esi + 8], 8
// 00562a28  7414                 je 0x562a3e
// 00562a2a  0fb74614             movzx eax, word ptr [esi + 0x14]
// 00562a2e  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00562a31  50                   push eax
// 00562a32  51                   push ecx
// 00562a33  55                   push ebp
// 00562a34  e867bc0000           call 0x56e6a0
// 00562a39  83c40c               add esp, 0xc
// 00562a3c  eb14                 jmp 0x562a52
// 00562a3e  807e1903             cmp byte ptr [esi + 0x19], 3
// 00562a42  750e                 jne 0x562a52
// 00562a44  68940ea200           push 0xa20e94
// 00562a49  55                   push ebp
// 00562a4a  e861f00000           call 0x571ab0
// 00562a4f  83c408               add esp, 8
// 00562a52  f6460810             test byte ptr [esi + 8], 0x10
// 00562a56  7449                 je 0x562aa1
// 00562a58  f7457000000800       test dword ptr [ebp + 0x70], 0x80000
// 00562a5f  7425                 je 0x562a86
// 00562a61  807e1903             cmp byte ptr [esi + 0x19], 3
// 00562a65  751f                 jne 0x562a86
// 00562a67  33d2                 xor edx, edx
// 00562a69  33c0                 xor eax, eax
// 00562a6b  663b5616             cmp dx, word ptr [esi + 0x16]
// 00562a6f  7315                 jae 0x562a86
// 00562a71  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 00562a74  03c8                 add ecx, eax
// 00562a76  80caff               or dl, 0xff
// 00562a79  2a11                 sub dl, byte ptr [ecx]
// 00562a7b  40                   inc eax
// 00562a7c  8811                 mov byte ptr [ecx], dl
// 00562a7e  0fb74e16             movzx ecx, word ptr [esi + 0x16]
// 00562a82  3bc1                 cmp eax, ecx
// 00562a84  7ceb                 jl 0x562a71
// 00562a86  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 00562a8a  0fb74616             movzx eax, word ptr [esi + 0x16]
// 00562a8e  52                   push edx
// 00562a8f  8b564c               mov edx, dword ptr [esi + 0x4c]
// 00562a92  50                   push eax
// 00562a93  8d4e50               lea ecx, [esi + 0x50]
// 00562a96  51                   push ecx
// 00562a97  52                   push edx
// 00562a98  55                   push ebp
// 00562a99  e8a2d80000           call 0x570340
// 00562a9e  83c414               add esp, 0x14
// 00562aa1  f6460820             test byte ptr [esi + 8], 0x20
// 00562aa5  7412                 je 0x562ab9
// 00562aa7  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 00562aab  50                   push eax
// 00562aac  8d4e5a               lea ecx, [esi + 0x5a]
// 00562aaf  51                   push ecx
// 00562ab0  55                   push ebp
// 00562ab1  e8ead90000           call 0x5704a0
// 00562ab6  83c40c               add esp, 0xc
// 00562ab9  f6460840             test byte ptr [esi + 8], 0x40
// 00562abd  7412                 je 0x562ad1
// 00562abf  0fb75614             movzx edx, word ptr [esi + 0x14]
// 00562ac3  8b467c               mov eax, dword ptr [esi + 0x7c]
// 00562ac6  52                   push edx
// 00562ac7  50                   push eax
// 00562ac8  55                   push ebp
// 00562ac9  e8e2bc0000           call 0x56e7b0
// 00562ace  83c40c               add esp, 0xc
// 00562ad1  f7460800010000       test dword ptr [esi + 8], 0x100
// 00562ad8  7416                 je 0x562af0
// 00562ada  0fb64e6c             movzx ecx, byte ptr [esi + 0x6c]
// 00562ade  8b5668               mov edx, dword ptr [esi + 0x68]
// 00562ae1  8b4664               mov eax, dword ptr [esi + 0x64]
// 00562ae4  51                   push ecx
// 00562ae5  52                   push edx
// 00562ae6  50                   push eax
// 00562ae7  55                   push ebp
// 00562ae8  e813db0000           call 0x570600
// 00562aed  83c410               add esp, 0x10
// 00562af0  f7460800040000       test dword ptr [esi + 8], 0x400
// 00562af7  743c                 je 0x562b35
// 00562af9  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 00562aff  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 00562b05  0fb686b5000000       movzx eax, byte ptr [esi + 0xb5]
// 00562b0c  51                   push ecx
// 00562b0d  0fb68eb4000000       movzx ecx, byte ptr [esi + 0xb4]
// 00562b14  52                   push edx
// 00562b15  8b96a8000000         mov edx, dword ptr [esi + 0xa8]
// 00562b1b  50                   push eax
// 00562b1c  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 00562b22  51                   push ecx
// 00562b23  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 00562b29  52                   push edx
// 00562b2a  50                   push eax
// 00562b2b  51                   push ecx
// 00562b2c  55                   push ebp
// 00562b2d  e86ec10000           call 0x56eca0
// 00562b32  83c420               add esp, 0x20
// 00562b35  f7460800400000       test dword ptr [esi + 8], 0x4000
// 00562b3c  7427                 je 0x562b65
// 00562b3e  dd86e8000000         fld qword ptr [esi + 0xe8]
// 00562b44  0fb696dc000000       movzx edx, byte ptr [esi + 0xdc]
// 00562b4b  83ec10               sub esp, 0x10
// 00562b4e  dd5c2408             fstp qword ptr [esp + 8]
// 00562b52  dd86e0000000         fld qword ptr [esi + 0xe0]
// 00562b58  dd1c24               fstp qword ptr [esp]
// 00562b5b  52                   push edx
// 00562b5c  55                   push ebp
// 00562b5d  e88edb0000           call 0x5706f0
// 00562b62  83c418               add esp, 0x18
// 00562b65  f6460880             test byte ptr [esi + 8], 0x80
// 00562b69  7416                 je 0x562b81
// 00562b6b  0fb64678             movzx eax, byte ptr [esi + 0x78]
// 00562b6f  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 00562b72  8b5670               mov edx, dword ptr [esi + 0x70]
// 00562b75  50                   push eax
// 00562b76  51                   push ecx
// 00562b77  52                   push edx
// 00562b78  55                   push ebp
// 00562b79  e822dc0000           call 0x5707a0
// 00562b7e  83c410               add esp, 0x10
// 00562b81  57                   push edi
// 00562b82  bf00020000           mov edi, 0x200
// 00562b87  857e08               test dword ptr [esi + 8], edi
// 00562b8a  7410                 je 0x562b9c
// 00562b8c  8d463c               lea eax, [esi + 0x3c]
// 00562b8f  50                   push eax
// 00562b90  55                   push ebp
// 00562b91  e8fadc0000           call 0x570890
// 00562b96  83c408               add esp, 8
// 00562b99  097d68               or dword ptr [ebp + 0x68], edi
// 00562b9c  f7460800200000       test dword ptr [esi + 8], 0x2000
// 00562ba3  53                   push ebx
// 00562ba4  742a                 je 0x562bd0
// 00562ba6  33ff                 xor edi, edi
// 00562ba8  39bed8000000         cmp dword ptr [esi + 0xd8], edi
// 00562bae  7e20                 jle 0x562bd0
// 00562bb0  33db                 xor ebx, ebx
// 00562bb2  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 00562bb8  03cb                 add ecx, ebx
// 00562bba  51                   push ecx
// 00562bbb  55                   push ebp
// 00562bbc  e81fd10000           call 0x56fce0
// 00562bc1  47                   inc edi
// 00562bc2  83c408               add esp, 8
// 00562bc5  83c310               add ebx, 0x10
// 00562bc8  3bbed8000000         cmp edi, dword ptr [esi + 0xd8]
// 00562bce  7ce2                 jl 0x562bb2
// 00562bd0  33db                 xor ebx, ebx
// 00562bd2  395e30               cmp dword ptr [esi + 0x30], ebx
// 00562bd5  0f8e84000000         jle 0x562c5f
// 00562bdb  33ff                 xor edi, edi
// 00562bdd  8d4900               lea ecx, [ecx]
// 00562be0  8b5638               mov edx, dword ptr [esi + 0x38]
// 00562be3  8b0417               mov eax, dword ptr [edi + edx]
// 00562be6  85c0                 test eax, eax
// 00562be8  7e1a                 jle 0x562c04
// 00562bea  68700ea200           push 0xa20e70
// 00562bef  55                   push ebp
// 00562bf0  e86bef0000           call 0x571b60
// 00562bf5  8b4638               mov eax, dword ptr [esi + 0x38]
// 00562bf8  83c408               add esp, 8
// 00562bfb  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 00562c02  eb52                 jmp 0x562c56
// 00562c04  7528                 jne 0x562c2e
// 00562c06  8bca                 mov ecx, edx
// 00562c08  8b140f               mov edx, dword ptr [edi + ecx]
// 00562c0b  8d040f               lea eax, [edi + ecx]
// 00562c0e  8b4808               mov ecx, dword ptr [eax + 8]
// 00562c11  52                   push edx
// 00562c12  8b5004               mov edx, dword ptr [eax + 4]
// 00562c15  6a00                 push 0
// 00562c17  51                   push ecx
// 00562c18  52                   push edx
// 00562c19  55                   push ebp
// 00562c1a  e831bf0000           call 0x56eb50
// 00562c1f  8b4638               mov eax, dword ptr [esi + 0x38]
// 00562c22  83c414               add esp, 0x14
// 00562c25  c70407feffffff       mov dword ptr [edi + eax], 0xfffffffe
// 00562c2c  eb28                 jmp 0x562c56
// 00562c2e  83f8ff               cmp eax, -1
// 00562c31  7523                 jne 0x562c56
// 00562c33  8bca                 mov ecx, edx
// 00562c35  8b540f08             mov edx, dword ptr [edi + ecx + 8]
// 00562c39  8d040f               lea eax, [edi + ecx]
// 00562c3c  8b4004               mov eax, dword ptr [eax + 4]
// 00562c3f  6a00                 push 0
// 00562c41  52                   push edx
// 00562c42  50                   push eax
// 00562c43  55                   push ebp
// 00562c44  e827be0000           call 0x56ea70
// 00562c49  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00562c4c  83c410               add esp, 0x10
// 00562c4f  c7040ffdffffff       mov dword ptr [edi + ecx], 0xfffffffd
// 00562c56  43                   inc ebx
// 00562c57  83c710               add edi, 0x10
// 00562c5a  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 00562c5d  7c81                 jl 0x562be0
// 00562c5f  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00562c65  85c0                 test eax, eax
// 00562c67  7472                 je 0x562cdb
// 00562c69  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 00562c6f  8d1480               lea edx, [eax + eax*4]
// 00562c72  8d0497               lea eax, [edi + edx*4]
// 00562c75  3bf8                 cmp edi, eax
// 00562c77  7362                 jae 0x562cdb
// 00562c79  bb00000100           mov ebx, 0x10000
// 00562c7e  8bff                 mov edi, edi
// 00562c80  57                   push edi
// 00562c81  55                   push ebp
// 00562c82  e8c9270000           call 0x565450
// 00562c87  83c408               add esp, 8
// 00562c8a  83f801               cmp eax, 1
// 00562c8d  7433                 je 0x562cc2
// 00562c8f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00562c92  84c9                 test cl, cl
// 00562c94  742c                 je 0x562cc2
// 00562c96  f6c102               test cl, 2
// 00562c99  7427                 je 0x562cc2
// 00562c9b  f6c104               test cl, 4
// 00562c9e  7522                 jne 0x562cc2
// 00562ca0  f6470320             test byte ptr [edi + 3], 0x20
// 00562ca4  750a                 jne 0x562cb0
// 00562ca6  83f803               cmp eax, 3
// 00562ca9  7405                 je 0x562cb0
// 00562cab  855d6c               test dword ptr [ebp + 0x6c], ebx
// 00562cae  7412                 je 0x562cc2
// 00562cb0  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00562cb3  8b5708               mov edx, dword ptr [edi + 8]
// 00562cb6  51                   push ecx
// 00562cb7  52                   push edx
// 00562cb8  57                   push edi
// 00562cb9  55                   push ebp
// 00562cba  e8d1c60000           call 0x56f390
// 00562cbf  83c410               add esp, 0x10
// 00562cc2  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00562cc8  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 00562cce  8d0480               lea eax, [eax + eax*4]
// 00562cd1  83c714               add edi, 0x14
// 00562cd4  8d1481               lea edx, [ecx + eax*4]
// 00562cd7  3bfa                 cmp edi, edx
// 00562cd9  72a5                 jb 0x562c80
// 00562cdb  5b                   pop ebx
// 00562cdc  5f                   pop edi
// 00562cdd  5e                   pop esi
// 00562cde  5d                   pop ebp
// 00562cdf  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
