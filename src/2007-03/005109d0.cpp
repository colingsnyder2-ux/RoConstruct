// from server: 100% by auto
// roc 2007-03 005109d0  unit: seg_00510000  size: 948 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005109d0
//
// 005109d0  83ec0c               sub esp, 0xc
// 005109d3  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005109d7  55                   push ebp
// 005109d8  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005109dc  8a4509               mov al, byte ptr [ebp + 9]
// 005109df  3c08                 cmp al, 8
// 005109e1  56                   push esi
// 005109e2  8b7500               mov esi, dword ptr [ebp]
// 005109e5  57                   push edi
// 005109e6  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005109ea  89742414             mov dword ptr [esp + 0x14], esi
// 005109ee  7704                 ja 0x5109f4
// 005109f0  85ff                 test edi, edi
// 005109f2  7510                 jne 0x510a04
// 005109f4  3c10                 cmp al, 0x10
// 005109f6  0f8564030000         jne 0x510d60
// 005109fc  85d2                 test edx, edx
// 005109fe  0f845c030000         je 0x510d60
// 00510a04  0fb64d08             movzx ecx, byte ptr [ebp + 8]
// 00510a08  83f906               cmp ecx, 6
// 00510a0b  0f874f030000         ja 0x510d60
// 00510a11  53                   push ebx
// 00510a12  ff248d680d5100       jmp dword ptr [ecx*4 + 0x510d68]
// 00510a19  3c08                 cmp al, 8
// 00510a1b  8b442424             mov eax, dword ptr [esp + 0x24]
// 00510a1f  7542                 jne 0x510a63
// 00510a21  85f6                 test esi, esi
// 00510a23  0f8636030000         jbe 0x510d5f
// 00510a29  8da42400000000       lea esp, [esp]
// 00510a30  0fb608               movzx ecx, byte ptr [eax]
// 00510a33  0fb61439             movzx edx, byte ptr [ecx + edi]
// 00510a37  8810                 mov byte ptr [eax], dl
// 00510a39  0fb64801             movzx ecx, byte ptr [eax + 1]
// 00510a3d  0fb61439             movzx edx, byte ptr [ecx + edi]
// 00510a41  83c001               add eax, 1
// 00510a44  8810                 mov byte ptr [eax], dl
// 00510a46  0fb64801             movzx ecx, byte ptr [eax + 1]
// 00510a4a  0fb61439             movzx edx, byte ptr [ecx + edi]
// 00510a4e  83c001               add eax, 1
// 00510a51  8810                 mov byte ptr [eax], dl
// 00510a53  83c001               add eax, 1
// 00510a56  83ee01               sub esi, 1
// 00510a59  75d5                 jne 0x510a30
// 00510a5b  5b                   pop ebx
// 00510a5c  5f                   pop edi
// 00510a5d  5e                   pop esi
// 00510a5e  5d                   pop ebp
// 00510a5f  83c40c               add esp, 0xc
// 00510a62  c3                   ret 
// 00510a63  85f6                 test esi, esi
// 00510a65  0f86f4020000         jbe 0x510d5f
// 00510a6b  0fb65c2430           movzx ebx, byte ptr [esp + 0x30]
// 00510a70  0fb67801             movzx edi, byte ptr [eax + 1]
// 00510a74  8acb                 mov cl, bl
// 00510a76  d3ef                 shr edi, cl
// 00510a78  0fb608               movzx ecx, byte ptr [eax]
// 00510a7b  8b3cba               mov edi, dword ptr [edx + edi*4]
// 00510a7e  0fb70c4f             movzx ecx, word ptr [edi + ecx*2]
// 00510a82  884801               mov byte ptr [eax + 1], cl
// 00510a85  8828                 mov byte ptr [eax], ch
// 00510a87  0fb67803             movzx edi, byte ptr [eax + 3]
// 00510a8b  83c002               add eax, 2
// 00510a8e  8acb                 mov cl, bl
// 00510a90  d3ef                 shr edi, cl
// 00510a92  0fb608               movzx ecx, byte ptr [eax]
// 00510a95  8b3cba               mov edi, dword ptr [edx + edi*4]
// 00510a98  0fb70c4f             movzx ecx, word ptr [edi + ecx*2]
// 00510a9c  884801               mov byte ptr [eax + 1], cl
// 00510a9f  8828                 mov byte ptr [eax], ch
// 00510aa1  0fb67803             movzx edi, byte ptr [eax + 3]
// 00510aa5  83c002               add eax, 2
// 00510aa8  8acb                 mov cl, bl
// 00510aaa  d3ef                 shr edi, cl
// 00510aac  0fb608               movzx ecx, byte ptr [eax]
// 00510aaf  8b3cba               mov edi, dword ptr [edx + edi*4]
// 00510ab2  0fb70c4f             movzx ecx, word ptr [edi + ecx*2]
// 00510ab6  8828                 mov byte ptr [eax], ch
// 00510ab8  884801               mov byte ptr [eax + 1], cl
// 00510abb  83c002               add eax, 2
// 00510abe  83ee01               sub esi, 1
// 00510ac1  75ad                 jne 0x510a70
// 00510ac3  5b                   pop ebx
// 00510ac4  5f                   pop edi
// 00510ac5  5e                   pop esi
// 00510ac6  5d                   pop ebp
// 00510ac7  83c40c               add esp, 0xc
// 00510aca  c3                   ret 
// 00510acb  3c08                 cmp al, 8
// 00510acd  8b442424             mov eax, dword ptr [esp + 0x24]
// 00510ad1  7540                 jne 0x510b13
// 00510ad3  85f6                 test esi, esi
// 00510ad5  0f8684020000         jbe 0x510d5f
// 00510adb  eb03                 jmp 0x510ae0
// 00510add  8d4900               lea ecx, [ecx]
// 00510ae0  0fb610               movzx edx, byte ptr [eax]
// 00510ae3  0fb60c3a             movzx ecx, byte ptr [edx + edi]
// 00510ae7  8808                 mov byte ptr [eax], cl
// 00510ae9  0fb65001             movzx edx, byte ptr [eax + 1]
// 00510aed  0fb60c3a             movzx ecx, byte ptr [edx + edi]
// 00510af1  83c001               add eax, 1
// 00510af4  8808                 mov byte ptr [eax], cl
// 00510af6  0fb65001             movzx edx, byte ptr [eax + 1]
// 00510afa  0fb60c3a             movzx ecx, byte ptr [edx + edi]
// 00510afe  83c001               add eax, 1
// 00510b01  8808                 mov byte ptr [eax], cl
// 00510b03  83c002               add eax, 2
// 00510b06  83ee01               sub esi, 1
// 00510b09  75d5                 jne 0x510ae0
// 00510b0b  5b                   pop ebx
// 00510b0c  5f                   pop edi
// 00510b0d  5e                   pop esi
// 00510b0e  5d                   pop ebp
// 00510b0f  83c40c               add esp, 0xc
// 00510b12  c3                   ret 
// 00510b13  85f6                 test esi, esi
// 00510b15  0f8644020000         jbe 0x510d5f
// 00510b1b  0fb65c2430           movzx ebx, byte ptr [esp + 0x30]
// 00510b20  0fb67801             movzx edi, byte ptr [eax + 1]
// 00510b24  8acb                 mov cl, bl
// 00510b26  d3ef                 shr edi, cl
// 00510b28  0fb608               movzx ecx, byte ptr [eax]
// 00510b2b  8b3cba               mov edi, dword ptr [edx + edi*4]
// 00510b2e  0fb70c4f             movzx ecx, word ptr [edi + ecx*2]
// 00510b32  884801               mov byte ptr [eax + 1], cl
// 00510b35  8828                 mov byte ptr [eax], ch
// 00510b37  0fb67803             movzx edi, byte ptr [eax + 3]
// 00510b3b  83c002               add eax, 2
// 00510b3e  8acb                 mov cl, bl
// 00510b40  d3ef                 shr edi, cl
// 00510b42  0fb608               movzx ecx, byte ptr [eax]
// 00510b45  8b3cba               mov edi, dword ptr [edx + edi*4]
// 00510b48  0fb70c4f             movzx ecx, word ptr [edi + ecx*2]
// 00510b4c  884801               mov byte ptr [eax + 1], cl
// 00510b4f  8828                 mov byte ptr [eax], ch
// 00510b51  0fb67803             movzx edi, byte ptr [eax + 3]
// 00510b55  83c002               add eax, 2
// 00510b58  8acb                 mov cl, bl
// 00510b5a  d3ef                 shr edi, cl
// 00510b5c  0fb608               movzx ecx, byte ptr [eax]
// 00510b5f  8b3cba               mov edi, dword ptr [edx + edi*4]
// 00510b62  0fb70c4f             movzx ecx, word ptr [edi + ecx*2]
// 00510b66  8828                 mov byte ptr [eax], ch
// 00510b68  884801               mov byte ptr [eax + 1], cl
// 00510b6b  83c004               add eax, 4
// 00510b6e  83ee01               sub esi, 1
// 00510b71  75ad                 jne 0x510b20
// 00510b73  5b                   pop ebx
// 00510b74  5f                   pop edi
// 00510b75  5e                   pop esi
// 00510b76  5d                   pop ebp
// 00510b77  83c40c               add esp, 0xc
// 00510b7a  c3                   ret 
// 00510b7b  3c08                 cmp al, 8
// 00510b7d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00510b81  7525                 jne 0x510ba8
// 00510b83  85f6                 test esi, esi
// 00510b85  0f86d4010000         jbe 0x510d5f
// 00510b8b  eb03                 jmp 0x510b90
// 00510b8d  8d4900               lea ecx, [ecx]
// 00510b90  0fb610               movzx edx, byte ptr [eax]
// 00510b93  8a0c3a               mov cl, byte ptr [edx + edi]
// 00510b96  8808                 mov byte ptr [eax], cl
// 00510b98  83c002               add eax, 2
// 00510b9b  83ee01               sub esi, 1
// 00510b9e  75f0                 jne 0x510b90
// 00510ba0  5b                   pop ebx
// 00510ba1  5f                   pop edi
// 00510ba2  5e                   pop esi
// 00510ba3  5d                   pop ebp
// 00510ba4  83c40c               add esp, 0xc
// 00510ba7  c3                   ret 
// 00510ba8  85f6                 test esi, esi
// 00510baa  0f86af010000         jbe 0x510d5f
// 00510bb0  0fb65c2430           movzx ebx, byte ptr [esp + 0x30]
// 00510bb5  0fb67801             movzx edi, byte ptr [eax + 1]
// 00510bb9  8acb                 mov cl, bl
// 00510bbb  d3ef                 shr edi, cl
// 00510bbd  0fb608               movzx ecx, byte ptr [eax]
// 00510bc0  8b3cba               mov edi, dword ptr [edx + edi*4]
// 00510bc3  0fb70c4f             movzx ecx, word ptr [edi + ecx*2]
// 00510bc7  8828                 mov byte ptr [eax], ch
// 00510bc9  884801               mov byte ptr [eax + 1], cl
// 00510bcc  83c004               add eax, 4
// 00510bcf  83ee01               sub esi, 1
// 00510bd2  75e1                 jne 0x510bb5
// 00510bd4  5b                   pop ebx
// 00510bd5  5f                   pop edi
// 00510bd6  5e                   pop esi
// 00510bd7  5d                   pop ebp
// 00510bd8  83c40c               add esp, 0xc
// 00510bdb  c3                   ret 
// 00510bdc  3c02                 cmp al, 2
// 00510bde  8b442424             mov eax, dword ptr [esp + 0x24]
// 00510be2  0f85cf000000         jne 0x510cb7
// 00510be8  85f6                 test esi, esi
// 00510bea  89442410             mov dword ptr [esp + 0x10], eax
// 00510bee  0f86c3000000         jbe 0x510cb7
// 00510bf4  8d4eff               lea ecx, [esi - 1]
// 00510bf7  c1e902               shr ecx, 2
// 00510bfa  83c101               add ecx, 1
// 00510bfd  894c2414             mov dword ptr [esp + 0x14], ecx
// 00510c01  0fb600               movzx eax, byte ptr [eax]
// 00510c04  8bd0                 mov edx, eax
// 00510c06  83e20c               and edx, 0xc
// 00510c09  8bc8                 mov ecx, eax
// 00510c0b  8bf0                 mov esi, eax
// 00510c0d  83e003               and eax, 3
// 00510c10  8d1c9500000000       lea ebx, [edx*4]
// 00510c17  0bda                 or ebx, edx
// 00510c19  03db                 add ebx, ebx
// 00510c1b  03db                 add ebx, ebx
// 00510c1d  8bea                 mov ebp, edx
// 00510c1f  c1fd02               sar ebp, 2
// 00510c22  0bdd                 or ebx, ebp
// 00510c24  0bda                 or ebx, edx
// 00510c26  8a143b               mov dl, byte ptr [ebx + edi]
// 00510c29  8d1c8500000000       lea ebx, [eax*4]
// 00510c30  0bd8                 or ebx, eax
// 00510c32  03db                 add ebx, ebx
// 00510c34  03db                 add ebx, ebx
// 00510c36  0bd8                 or ebx, eax
// 00510c38  03db                 add ebx, ebx
// 00510c3a  03db                 add ebx, ebx
// 00510c3c  0bd8                 or ebx, eax
// 00510c3e  0fb6043b             movzx eax, byte ptr [ebx + edi]
// 00510c42  c0e802               shr al, 2
// 00510c45  80e2cf               and dl, 0xcf
// 00510c48  0ad0                 or dl, al
// 00510c4a  83e630               and esi, 0x30
// 00510c4d  8bc6                 mov eax, esi
// 00510c4f  c1f802               sar eax, 2
// 00510c52  0bc6                 or eax, esi
// 00510c54  c1f802               sar eax, 2
// 00510c57  8d1cb500000000       lea ebx, [esi*4]
// 00510c5e  0bc3                 or eax, ebx
// 00510c60  0bc6                 or eax, esi
// 00510c62  0fb60438             movzx eax, byte ptr [eax + edi]
// 00510c66  24c3                 and al, 0xc3
// 00510c68  81e1c0000000         and ecx, 0xc0
// 00510c6e  c0ea02               shr dl, 2
// 00510c71  0ad0                 or dl, al
// 00510c73  8bc1                 mov eax, ecx
// 00510c75  c1f802               sar eax, 2
// 00510c78  0bc1                 or eax, ecx
// 00510c7a  c1f802               sar eax, 2
// 00510c7d  0bc1                 or eax, ecx
// 00510c7f  c1f802               sar eax, 2
// 00510c82  0bc1                 or eax, ecx
// 00510c84  8a0c38               mov cl, byte ptr [eax + edi]
// 00510c87  8b442410             mov eax, dword ptr [esp + 0x10]
// 00510c8b  c0ea02               shr dl, 2
// 00510c8e  80e1c0               and cl, 0xc0
// 00510c91  0ad1                 or dl, cl
// 00510c93  8810                 mov byte ptr [eax], dl
// 00510c95  83c001               add eax, 1
// 00510c98  836c241401           sub dword ptr [esp + 0x14], 1
// 00510c9d  89442410             mov dword ptr [esp + 0x10], eax
// 00510ca1  0f855affffff         jne 0x510c01
// 00510ca7  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00510cab  8b442424             mov eax, dword ptr [esp + 0x24]
// 00510caf  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00510cb3  8b742418             mov esi, dword ptr [esp + 0x18]
// 00510cb7  8a4d09               mov cl, byte ptr [ebp + 9]
// 00510cba  80f904               cmp cl, 4
// 00510cbd  754e                 jne 0x510d0d
// 00510cbf  85f6                 test esi, esi
// 00510cc1  8bd0                 mov edx, eax
// 00510cc3  0f8696000000         jbe 0x510d5f
// 00510cc9  83c6ff               add esi, -1
// 00510ccc  d1ee                 shr esi, 1
// 00510cce  83c601               add esi, 1
// 00510cd1  0fb602               movzx eax, byte ptr [edx]
// 00510cd4  8bc8                 mov ecx, eax
// 00510cd6  81e1f0000000         and ecx, 0xf0
// 00510cdc  8bd9                 mov ebx, ecx
// 00510cde  c1fb04               sar ebx, 4
// 00510ce1  0bd9                 or ebx, ecx
// 00510ce3  8a0c3b               mov cl, byte ptr [ebx + edi]
// 00510ce6  83e00f               and eax, 0xf
// 00510ce9  8bd8                 mov ebx, eax
// 00510ceb  c1e304               shl ebx, 4
// 00510cee  0bd8                 or ebx, eax
// 00510cf0  8a043b               mov al, byte ptr [ebx + edi]
// 00510cf3  80e1f0               and cl, 0xf0
// 00510cf6  c0e804               shr al, 4
// 00510cf9  0ac8                 or cl, al
// 00510cfb  880a                 mov byte ptr [edx], cl
// 00510cfd  83c201               add edx, 1
// 00510d00  83ee01               sub esi, 1
// 00510d03  75cc                 jne 0x510cd1
// 00510d05  5b                   pop ebx
// 00510d06  5f                   pop edi
// 00510d07  5e                   pop esi
// 00510d08  5d                   pop ebp
// 00510d09  83c40c               add esp, 0xc
// 00510d0c  c3                   ret 
// 00510d0d  80f908               cmp cl, 8
// 00510d10  751c                 jne 0x510d2e
// 00510d12  85f6                 test esi, esi
// 00510d14  7649                 jbe 0x510d5f
// 00510d16  0fb608               movzx ecx, byte ptr [eax]
// 00510d19  8a1439               mov dl, byte ptr [ecx + edi]
// 00510d1c  8810                 mov byte ptr [eax], dl
// 00510d1e  83c001               add eax, 1
// 00510d21  83ee01               sub esi, 1
// 00510d24  75f0                 jne 0x510d16
// 00510d26  5b                   pop ebx
// 00510d27  5f                   pop edi
// 00510d28  5e                   pop esi
// 00510d29  5d                   pop ebp
// 00510d2a  83c40c               add esp, 0xc
// 00510d2d  c3                   ret 
// 00510d2e  80f910               cmp cl, 0x10
// 00510d31  752c                 jne 0x510d5f
// 00510d33  85f6                 test esi, esi
// 00510d35  7628                 jbe 0x510d5f
// 00510d37  0fb65c2430           movzx ebx, byte ptr [esp + 0x30]
// 00510d3c  8d642400             lea esp, [esp]
// 00510d40  0fb67801             movzx edi, byte ptr [eax + 1]
// 00510d44  8acb                 mov cl, bl
// 00510d46  d3ef                 shr edi, cl
// 00510d48  0fb608               movzx ecx, byte ptr [eax]
// 00510d4b  8b3cba               mov edi, dword ptr [edx + edi*4]
// 00510d4e  0fb70c4f             movzx ecx, word ptr [edi + ecx*2]
// 00510d52  8828                 mov byte ptr [eax], ch
// 00510d54  884801               mov byte ptr [eax + 1], cl
// 00510d57  83c002               add eax, 2
// 00510d5a  83ee01               sub esi, 1
// 00510d5d  75e1                 jne 0x510d40
// 00510d5f  5b                   pop ebx
// 00510d60  5f                   pop edi
// 00510d61  5e                   pop esi
// 00510d62  5d                   pop ebp
// 00510d63  83c40c               add esp, 0xc
// 00510d66  c3                   ret 
// 00510d67  90                   nop 
// 00510d68  dc0b                 fmul qword ptr [ebx]
// 00510d6a  51                   push ecx
// 00510d6b  005f0d               add byte ptr [edi + 0xd], bl
// 00510d6e  51                   push ecx
// 00510d6f  0019                 add byte ptr [ecx], bl
// 00510d71  0a5100               or dl, byte ptr [ecx]
// 00510d74  5f                   pop edi
// 00510d75  0d51007b0b           or eax, 0xb7b0051
// 00510d7a  51                   push ecx
// 00510d7b  005f0d               add byte ptr [edi + 0xd], bl
// 00510d7e  51                   push ecx
// 00510d7f  00cb                 add bl, cl
// 00510d81  0a5100               or dl, byte ptr [ecx]
// library libpng-1.2.7/pngrtran.c (function _png_do_gamma)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
