// from server: 100% by auto
// roc 2008-06 004c3860  unit: ProfiledRakPeer  size: 1051 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c3860
//
// 004c3860  81eca0000000         sub esp, 0xa0
// 004c3866  56                   push esi
// 004c3867  57                   push edi
// 004c3868  33f6                 xor esi, esi
// 004c386a  8d9b00000000         lea ebx, [ebx]
// 004c3870  0fb78690618200       movzx eax, word ptr [esi + 0x826190]
// 004c3877  8bbc24ac000000       mov edi, dword ptr [esp + 0xac]
// 004c387e  8d4c2438             lea ecx, [esp + 0x38]
// 004c3882  51                   push ecx
// 004c3883  8bd1                 mov edx, ecx
// 004c3885  8944243c             mov dword ptr [esp + 0x3c], eax
// 004c3889  33c0                 xor eax, eax
// 004c388b  52                   push edx
// 004c388c  57                   push edi
// 004c388d  89442448             mov dword ptr [esp + 0x48], eax
// 004c3891  8944244c             mov dword ptr [esp + 0x4c], eax
// 004c3895  89442450             mov dword ptr [esp + 0x50], eax
// 004c3899  83c602               add esi, 2
// 004c389c  e8bfb7ffff           call 0x4bf060
// 004c38a1  83c40c               add esp, 0xc
// 004c38a4  33c0                 xor eax, eax
// 004c38a6  837c843800           cmp dword ptr [esp + eax*4 + 0x38], 0
// 004c38ab  7511                 jne 0x4c38be
// 004c38ad  40                   inc eax
// 004c38ae  83f804               cmp eax, 4
// 004c38b1  72f3                 jb 0x4c38a6
// 004c38b3  5f                   pop edi
// 004c38b4  32c0                 xor al, al
// 004c38b6  5e                   pop esi
// 004c38b7  81c4a0000000         add esp, 0xa0
// 004c38bd  c3                   ret 
// 004c38be  83c602               add esi, 2
// 004c38c1  81fe00020000         cmp esi, 0x200
// 004c38c7  72a7                 jb 0x4c3870
// 004c38c9  8b07                 mov eax, dword ptr [edi]
// 004c38cb  8b4f04               mov ecx, dword ptr [edi + 4]
// 004c38ce  8b5708               mov edx, dword ptr [edi + 8]
// 004c38d1  89442408             mov dword ptr [esp + 8], eax
// 004c38d5  8b470c               mov eax, dword ptr [edi + 0xc]
// 004c38d8  894c240c             mov dword ptr [esp + 0xc], ecx
// 004c38dc  89542410             mov dword ptr [esp + 0x10], edx
// 004c38e0  89442414             mov dword ptr [esp + 0x14], eax
// 004c38e4  33c9                 xor ecx, ecx
// 004c38e6  eb08                 jmp 0x4c38f0
// 004c38e8  8da42400000000       lea esp, [esp]
// 004c38ef  90                   nop 
// 004c38f0  8b448c08             mov eax, dword ptr [esp + ecx*4 + 8]
// 004c38f4  8d50ff               lea edx, [eax - 1]
// 004c38f7  89548c08             mov dword ptr [esp + ecx*4 + 8], edx
// 004c38fb  85c0                 test eax, eax
// 004c38fd  7506                 jne 0x4c3905
// 004c38ff  41                   inc ecx
// 004c3900  83f904               cmp ecx, 4
// 004c3903  72eb                 jb 0x4c38f0
// 004c3905  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c3909  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c390d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004c3911  53                   push ebx
// 004c3912  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 004c3916  55                   push ebp
// 004c3917  33ed                 xor ebp, ebp
// 004c3919  895c2430             mov dword ptr [esp + 0x30], ebx
// 004c391d  89742434             mov dword ptr [esp + 0x34], esi
// 004c3921  89542438             mov dword ptr [esp + 0x38], edx
// 004c3925  897c243c             mov dword ptr [esp + 0x3c], edi
// 004c3929  f6c301               test bl, 1
// 004c392c  7535                 jne 0x4c3963
// 004c392e  8bff                 mov edi, edi
// 004c3930  8bc7                 mov eax, edi
// 004c3932  c1e01f               shl eax, 0x1f
// 004c3935  8bca                 mov ecx, edx
// 004c3937  d1ea                 shr edx, 1
// 004c3939  0bd0                 or edx, eax
// 004c393b  8bc6                 mov eax, esi
// 004c393d  c1e01f               shl eax, 0x1f
// 004c3940  d1eb                 shr ebx, 1
// 004c3942  c1e11f               shl ecx, 0x1f
// 004c3945  d1ee                 shr esi, 1
// 004c3947  0bd8                 or ebx, eax
// 004c3949  d1ef                 shr edi, 1
// 004c394b  0bf1                 or esi, ecx
// 004c394d  45                   inc ebp
// 004c394e  f6c301               test bl, 1
// 004c3951  74dd                 je 0x4c3930
// 004c3953  895c2430             mov dword ptr [esp + 0x30], ebx
// 004c3957  89742434             mov dword ptr [esp + 0x34], esi
// 004c395b  89542438             mov dword ptr [esp + 0x38], edx
// 004c395f  897c243c             mov dword ptr [esp + 0x3c], edi
// 004c3963  8bbc24b4000000       mov edi, dword ptr [esp + 0xb4]
// 004c396a  8b4f04               mov ecx, dword ptr [edi + 4]
// 004c396d  8b5708               mov edx, dword ptr [edi + 8]
// 004c3970  33c0                 xor eax, eax
// 004c3972  89442454             mov dword ptr [esp + 0x54], eax
// 004c3976  89442458             mov dword ptr [esp + 0x58], eax
// 004c397a  8944245c             mov dword ptr [esp + 0x5c], eax
// 004c397e  8b07                 mov eax, dword ptr [edi]
// 004c3980  89442460             mov dword ptr [esp + 0x60], eax
// 004c3984  8b470c               mov eax, dword ptr [edi + 0xc]
// 004c3987  8944246c             mov dword ptr [esp + 0x6c], eax
// 004c398b  33c0                 xor eax, eax
// 004c398d  c744245001000000     mov dword ptr [esp + 0x50], 1
// 004c3995  894c2464             mov dword ptr [esp + 0x64], ecx
// 004c3999  89542468             mov dword ptr [esp + 0x68], edx
// 004c399d  89442470             mov dword ptr [esp + 0x70], eax
// 004c39a1  89442474             mov dword ptr [esp + 0x74], eax
// 004c39a5  89442478             mov dword ptr [esp + 0x78], eax
// 004c39a9  8944247c             mov dword ptr [esp + 0x7c], eax
// 004c39ad  398424b8000000       cmp dword ptr [esp + 0xb8], eax
// 004c39b4  0f84b4020000         je 0x4c3c6e
// 004c39ba  8d9b00000000         lea ebx, [ebx]
// 004c39c0  ff8c24b8000000       dec dword ptr [esp + 0xb8]
// 004c39c7  33f6                 xor esi, esi
// 004c39c9  8da42400000000       lea esp, [esp]
// 004c39d0  e84b070100           call 0x4d4120
// 004c39d5  8984b480000000       mov dword ptr [esp + esi*4 + 0x80], eax
// 004c39dc  46                   inc esi
// 004c39dd  83fe04               cmp esi, 4
// 004c39e0  7cee                 jl 0x4c39d0
// 004c39e2  8d8c2480000000       lea ecx, [esp + 0x80]
// 004c39e9  51                   push ecx
// 004c39ea  8d542414             lea edx, [esp + 0x14]
// 004c39ee  52                   push edx
// 004c39ef  8bc1                 mov eax, ecx
// 004c39f1  50                   push eax
// 004c39f2  e869b6ffff           call 0x4bf060
// 004c39f7  8d4c242c             lea ecx, [esp + 0x2c]
// 004c39fb  51                   push ecx
// 004c39fc  57                   push edi
// 004c39fd  8d542444             lea edx, [esp + 0x44]
// 004c3a01  52                   push edx
// 004c3a02  8d842498000000       lea eax, [esp + 0x98]
// 004c3a09  50                   push eax
// 004c3a0a  e8d1d7ffff           call 0x4c11e0
// 004c3a0f  83c41c               add esp, 0x1c
// 004c3a12  b810000000           mov eax, 0x10
// 004c3a17  8d4c2450             lea ecx, [esp + 0x50]
// 004c3a1b  8d542420             lea edx, [esp + 0x20]
// 004c3a1f  90                   nop 
// 004c3a20  8b32                 mov esi, dword ptr [edx]
// 004c3a22  3b31                 cmp esi, dword ptr [ecx]
// 004c3a24  7513                 jne 0x4c3a39
// 004c3a26  83e804               sub eax, 4
// 004c3a29  83c104               add ecx, 4
// 004c3a2c  83c204               add edx, 4
// 004c3a2f  83f804               cmp eax, 4
// 004c3a32  73ec                 jae 0x4c3a20
// 004c3a34  e927020000           jmp 0x4c3c60
// 004c3a39  0fb602               movzx eax, byte ptr [edx]
// 004c3a3c  0fb631               movzx esi, byte ptr [ecx]
// 004c3a3f  2bc6                 sub eax, esi
// 004c3a41  7522                 jne 0x4c3a65
// 004c3a43  0fb64201             movzx eax, byte ptr [edx + 1]
// 004c3a47  0fb67101             movzx esi, byte ptr [ecx + 1]
// 004c3a4b  2bc6                 sub eax, esi
// 004c3a4d  7516                 jne 0x4c3a65
// 004c3a4f  0fb64202             movzx eax, byte ptr [edx + 2]
// 004c3a53  0fb67102             movzx esi, byte ptr [ecx + 2]
// 004c3a57  2bc6                 sub eax, esi
// 004c3a59  750a                 jne 0x4c3a65
// 004c3a5b  0fb64203             movzx eax, byte ptr [edx + 3]
// 004c3a5f  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 004c3a63  2bc1                 sub eax, ecx
// 004c3a65  c1f81f               sar eax, 0x1f
// 004c3a68  83c801               or eax, 1
// 004c3a6b  0f84ef010000         je 0x4c3c60
// 004c3a71  b810000000           mov eax, 0x10
// 004c3a76  8d4c2410             lea ecx, [esp + 0x10]
// 004c3a7a  8d542420             lea edx, [esp + 0x20]
// 004c3a7e  8bff                 mov edi, edi
// 004c3a80  8b32                 mov esi, dword ptr [edx]
// 004c3a82  3b31                 cmp esi, dword ptr [ecx]
// 004c3a84  7513                 jne 0x4c3a99
// 004c3a86  83e804               sub eax, 4
// 004c3a89  83c104               add ecx, 4
// 004c3a8c  83c204               add edx, 4
// 004c3a8f  83f804               cmp eax, 4
// 004c3a92  73ec                 jae 0x4c3a80
// 004c3a94  e9c7010000           jmp 0x4c3c60
// 004c3a99  0fb602               movzx eax, byte ptr [edx]
// 004c3a9c  0fb631               movzx esi, byte ptr [ecx]
// 004c3a9f  2bc6                 sub eax, esi
// 004c3aa1  7522                 jne 0x4c3ac5
// 004c3aa3  0fb64201             movzx eax, byte ptr [edx + 1]
// 004c3aa7  0fb67101             movzx esi, byte ptr [ecx + 1]
// 004c3aab  2bc6                 sub eax, esi
// 004c3aad  7516                 jne 0x4c3ac5
// 004c3aaf  0fb64202             movzx eax, byte ptr [edx + 2]
// 004c3ab3  0fb67102             movzx esi, byte ptr [ecx + 2]
// 004c3ab7  2bc6                 sub eax, esi
// 004c3ab9  750a                 jne 0x4c3ac5
// 004c3abb  0fb64203             movzx eax, byte ptr [edx + 3]
// 004c3abf  0fb65103             movzx edx, byte ptr [ecx + 3]
// 004c3ac3  2bc2                 sub eax, edx
// 004c3ac5  c1f81f               sar eax, 0x1f
// 004c3ac8  83c801               or eax, 1
// 004c3acb  0f848f010000         je 0x4c3c60
// 004c3ad1  8bf5                 mov esi, ebp
// 004c3ad3  83fd01               cmp ebp, 1
// 004c3ad6  0f8629010000         jbe 0x4c3c05
// 004c3adc  8d642400             lea esp, [esp]
// 004c3ae0  4e                   dec esi
// 004c3ae1  b810000000           mov eax, 0x10
// 004c3ae6  8d4c2410             lea ecx, [esp + 0x10]
// 004c3aea  8d542420             lea edx, [esp + 0x20]
// 004c3aee  8bff                 mov edi, edi
// 004c3af0  8b1a                 mov ebx, dword ptr [edx]
// 004c3af2  3b19                 cmp ebx, dword ptr [ecx]
// 004c3af4  7513                 jne 0x4c3b09
// 004c3af6  83e804               sub eax, 4
// 004c3af9  83c104               add ecx, 4
// 004c3afc  83c204               add edx, 4
// 004c3aff  83f804               cmp eax, 4
// 004c3b02  73ec                 jae 0x4c3af0
// 004c3b04  e9fc000000           jmp 0x4c3c05
// 004c3b09  0fb619               movzx ebx, byte ptr [ecx]
// 004c3b0c  0fb602               movzx eax, byte ptr [edx]
// 004c3b0f  2bc3                 sub eax, ebx
// 004c3b11  7522                 jne 0x4c3b35
// 004c3b13  0fb64201             movzx eax, byte ptr [edx + 1]
// 004c3b17  0fb65901             movzx ebx, byte ptr [ecx + 1]
// 004c3b1b  2bc3                 sub eax, ebx
// 004c3b1d  7516                 jne 0x4c3b35
// 004c3b1f  0fb64202             movzx eax, byte ptr [edx + 2]
// 004c3b23  0fb65902             movzx ebx, byte ptr [ecx + 2]
// 004c3b27  2bc3                 sub eax, ebx
// 004c3b29  750a                 jne 0x4c3b35
// 004c3b2b  0fb64203             movzx eax, byte ptr [edx + 3]
// 004c3b2f  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 004c3b33  2bc1                 sub eax, ecx
// 004c3b35  c1f81f               sar eax, 0x1f
// 004c3b38  83c801               or eax, 1
// 004c3b3b  0f84c4000000         je 0x4c3c05
// 004c3b41  8d942490000000       lea edx, [esp + 0x90]
// 004c3b48  52                   push edx
// 004c3b49  8d442424             lea eax, [esp + 0x24]
// 004c3b4d  50                   push eax
// 004c3b4e  8bc8                 mov ecx, eax
// 004c3b50  51                   push ecx
// 004c3b51  e8baa0ffff           call 0x4bdc10
// 004c3b56  8d94249c000000       lea edx, [esp + 0x9c]
// 004c3b5d  52                   push edx
// 004c3b5e  8d442470             lea eax, [esp + 0x70]
// 004c3b62  50                   push eax
// 004c3b63  8bca                 mov ecx, edx
// 004c3b65  51                   push ecx
// 004c3b66  e835a6ffff           call 0x4be1a0
// 004c3b6b  8b9424a8000000       mov edx, dword ptr [esp + 0xa8]
// 004c3b72  8b8424ac000000       mov eax, dword ptr [esp + 0xac]
// 004c3b79  8b8c24b0000000       mov ecx, dword ptr [esp + 0xb0]
// 004c3b80  89542438             mov dword ptr [esp + 0x38], edx
// 004c3b84  8b9424b4000000       mov edx, dword ptr [esp + 0xb4]
// 004c3b8b  8944243c             mov dword ptr [esp + 0x3c], eax
// 004c3b8f  894c2440             mov dword ptr [esp + 0x40], ecx
// 004c3b93  89542444             mov dword ptr [esp + 0x44], edx
// 004c3b97  83c418               add esp, 0x18
// 004c3b9a  b810000000           mov eax, 0x10
// 004c3b9f  8d4c2450             lea ecx, [esp + 0x50]
// 004c3ba3  8d542420             lea edx, [esp + 0x20]
// 004c3ba7  8b1a                 mov ebx, dword ptr [edx]
// 004c3ba9  3b19                 cmp ebx, dword ptr [ecx]
// 004c3bab  751b                 jne 0x4c3bc8
// 004c3bad  83e804               sub eax, 4
// 004c3bb0  83c104               add ecx, 4
// 004c3bb3  83c204               add edx, 4
// 004c3bb6  83f804               cmp eax, 4
// 004c3bb9  73ec                 jae 0x4c3ba7
// 004c3bbb  5d                   pop ebp
// 004c3bbc  5b                   pop ebx
// 004c3bbd  5f                   pop edi
// 004c3bbe  32c0                 xor al, al
// 004c3bc0  5e                   pop esi
// 004c3bc1  81c4a0000000         add esp, 0xa0
// 004c3bc7  c3                   ret 
// 004c3bc8  0fb619               movzx ebx, byte ptr [ecx]
// 004c3bcb  0fb602               movzx eax, byte ptr [edx]
// 004c3bce  2bc3                 sub eax, ebx
// 004c3bd0  7522                 jne 0x4c3bf4
// 004c3bd2  0fb64201             movzx eax, byte ptr [edx + 1]
// 004c3bd6  0fb65901             movzx ebx, byte ptr [ecx + 1]
// 004c3bda  2bc3                 sub eax, ebx
// 004c3bdc  7516                 jne 0x4c3bf4
// 004c3bde  0fb64202             movzx eax, byte ptr [edx + 2]
// 004c3be2  0fb65902             movzx ebx, byte ptr [ecx + 2]
// 004c3be6  2bc3                 sub eax, ebx
// 004c3be8  750a                 jne 0x4c3bf4
// 004c3bea  0fb64203             movzx eax, byte ptr [edx + 3]
// 004c3bee  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 004c3bf2  2bc1                 sub eax, ecx
// 004c3bf4  c1f81f               sar eax, 0x1f
// 004c3bf7  83c801               or eax, 1
// 004c3bfa  74bf                 je 0x4c3bbb
// 004c3bfc  83fe01               cmp esi, 1
// 004c3bff  0f87dbfeffff         ja 0x4c3ae0
// 004c3c05  b810000000           mov eax, 0x10
// 004c3c0a  8d4c2410             lea ecx, [esp + 0x10]
// 004c3c0e  8d542420             lea edx, [esp + 0x20]
// 004c3c12  8b32                 mov esi, dword ptr [edx]
// 004c3c14  3b31                 cmp esi, dword ptr [ecx]
// 004c3c16  7510                 jne 0x4c3c28
// 004c3c18  83e804               sub eax, 4
// 004c3c1b  83c104               add ecx, 4
// 004c3c1e  83c204               add edx, 4
// 004c3c21  83f804               cmp eax, 4
// 004c3c24  73ec                 jae 0x4c3c12
// 004c3c26  eb38                 jmp 0x4c3c60
// 004c3c28  0fb602               movzx eax, byte ptr [edx]
// 004c3c2b  0fb631               movzx esi, byte ptr [ecx]
// 004c3c2e  2bc6                 sub eax, esi
// 004c3c30  7522                 jne 0x4c3c54
// 004c3c32  0fb64201             movzx eax, byte ptr [edx + 1]
// 004c3c36  0fb67101             movzx esi, byte ptr [ecx + 1]
// 004c3c3a  2bc6                 sub eax, esi
// 004c3c3c  7516                 jne 0x4c3c54
// 004c3c3e  0fb64202             movzx eax, byte ptr [edx + 2]
// 004c3c42  0fb67102             movzx esi, byte ptr [ecx + 2]
// 004c3c46  2bc6                 sub eax, esi
// 004c3c48  750a                 jne 0x4c3c54
// 004c3c4a  0fb64203             movzx eax, byte ptr [edx + 3]
// 004c3c4e  0fb65103             movzx edx, byte ptr [ecx + 3]
// 004c3c52  2bc2                 sub eax, edx
// 004c3c54  c1f81f               sar eax, 0x1f
// 004c3c57  83c801               or eax, 1
// 004c3c5a  0f855bffffff         jne 0x4c3bbb
// 004c3c60  83bc24b800000000     cmp dword ptr [esp + 0xb8], 0
// 004c3c68  0f8552fdffff         jne 0x4c39c0
// 004c3c6e  5d                   pop ebp
// 004c3c6f  5b                   pop ebx
// 004c3c70  5f                   pop edi
// 004c3c71  b001                 mov al, 1
// 004c3c73  5e                   pop esi
// 004c3c74  81c4a0000000         add esp, 0xa0
// 004c3c7a  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$RabinMillerPrimalityTest@$$BY03I@big@@YA_NAAY03II@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
