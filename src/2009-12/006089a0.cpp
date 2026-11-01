// from server: 100% by auto
// roc 2009-12 006089a0  unit: seg_00600000  size: 1035 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006089a0
//
// 006089a0  83ec10               sub esp, 0x10
// 006089a3  53                   push ebx
// 006089a4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006089a8  8a4308               mov al, byte ptr [ebx + 8]
// 006089ab  56                   push esi
// 006089ac  8b33                 mov esi, dword ptr [ebx]
// 006089ae  57                   push edi
// 006089af  84c0                 test al, al
// 006089b1  0f8562020000         jne 0x608c19
// 006089b7  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006089bb  85c9                 test ecx, ecx
// 006089bd  7406                 je 0x6089c5
// 006089bf  0fb75108             movzx edx, word ptr [ecx + 8]
// 006089c3  eb0c                 jmp 0x6089d1
// 006089c5  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006089cd  8b542414             mov edx, dword ptr [esp + 0x14]
// 006089d1  8a4309               mov al, byte ptr [ebx + 9]
// 006089d4  55                   push ebp
// 006089d5  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 006089d9  3c08                 cmp al, 8
// 006089db  0f8360010000         jae 0x608b41
// 006089e1  0fb6c0               movzx eax, al
// 006089e4  83e801               sub eax, 1
// 006089e7  0f84ea000000         je 0x608ad7
// 006089ed  83e801               sub eax, 1
// 006089f0  7473                 je 0x608a65
// 006089f2  83e802               sub eax, 2
// 006089f5  0f8537010000         jne 0x608b32
// 006089fb  8bc2                 mov eax, edx
// 006089fd  83e00f               and eax, 0xf
// 00608a00  8bc8                 mov ecx, eax
// 00608a02  c1e104               shl ecx, 4
// 00608a05  03c8                 add ecx, eax
// 00608a07  0fb7d1               movzx edx, cx
// 00608a0a  8d46ff               lea eax, [esi - 1]
// 00608a0d  83e001               and eax, 1
// 00608a10  03c0                 add eax, eax
// 00608a12  89542418             mov dword ptr [esp + 0x18], edx
// 00608a16  8d7eff               lea edi, [esi - 1]
// 00608a19  d1ef                 shr edi, 1
// 00608a1b  03c0                 add eax, eax
// 00608a1d  ba04000000           mov edx, 4
// 00608a22  03fd                 add edi, ebp
// 00608a24  2bd0                 sub edx, eax
// 00608a26  8d5c2eff             lea ebx, [esi + ebp - 1]
// 00608a2a  85f6                 test esi, esi
// 00608a2c  0f86f8000000         jbe 0x608b2a
// 00608a32  8974241c             mov dword ptr [esp + 0x1c], esi
// 00608a36  0fb607               movzx eax, byte ptr [edi]
// 00608a39  8aca                 mov cl, dl
// 00608a3b  d3e8                 shr eax, cl
// 00608a3d  83e00f               and eax, 0xf
// 00608a40  8ac8                 mov cl, al
// 00608a42  c0e104               shl cl, 4
// 00608a45  0ac8                 or cl, al
// 00608a47  880b                 mov byte ptr [ebx], cl
// 00608a49  83fa04               cmp edx, 4
// 00608a4c  7505                 jne 0x608a53
// 00608a4e  33d2                 xor edx, edx
// 00608a50  4f                   dec edi
// 00608a51  eb05                 jmp 0x608a58
// 00608a53  ba04000000           mov edx, 4
// 00608a58  4b                   dec ebx
// 00608a59  836c241c01           sub dword ptr [esp + 0x1c], 1
// 00608a5e  75d6                 jne 0x608a36
// 00608a60  e9c5000000           jmp 0x608b2a
// 00608a65  83e203               and edx, 3
// 00608a68  6bd255               imul edx, edx, 0x55
// 00608a6b  0fb7d2               movzx edx, dx
// 00608a6e  89542418             mov dword ptr [esp + 0x18], edx
// 00608a72  8d46ff               lea eax, [esi - 1]
// 00608a75  83e003               and eax, 3
// 00608a78  8d7eff               lea edi, [esi - 1]
// 00608a7b  ba03000000           mov edx, 3
// 00608a80  c1ef02               shr edi, 2
// 00608a83  2bd0                 sub edx, eax
// 00608a85  03fd                 add edi, ebp
// 00608a87  03d2                 add edx, edx
// 00608a89  8d5c2eff             lea ebx, [esi + ebp - 1]
// 00608a8d  85f6                 test esi, esi
// 00608a8f  0f8695000000         jbe 0x608b2a
// 00608a95  8974241c             mov dword ptr [esp + 0x1c], esi
// 00608a99  8da42400000000       lea esp, [esp]
// 00608aa0  0fb607               movzx eax, byte ptr [edi]
// 00608aa3  8aca                 mov cl, dl
// 00608aa5  d3e8                 shr eax, cl
// 00608aa7  83e003               and eax, 3
// 00608aaa  8ac8                 mov cl, al
// 00608aac  02c9                 add cl, cl
// 00608aae  02c9                 add cl, cl
// 00608ab0  0ac8                 or cl, al
// 00608ab2  02c9                 add cl, cl
// 00608ab4  02c9                 add cl, cl
// 00608ab6  0ac8                 or cl, al
// 00608ab8  02c9                 add cl, cl
// 00608aba  02c9                 add cl, cl
// 00608abc  0ac8                 or cl, al
// 00608abe  880b                 mov byte ptr [ebx], cl
// 00608ac0  83fa06               cmp edx, 6
// 00608ac3  7505                 jne 0x608aca
// 00608ac5  33d2                 xor edx, edx
// 00608ac7  4f                   dec edi
// 00608ac8  eb03                 jmp 0x608acd
// 00608aca  83c202               add edx, 2
// 00608acd  4b                   dec ebx
// 00608ace  836c241c01           sub dword ptr [esp + 0x1c], 1
// 00608ad3  75cb                 jne 0x608aa0
// 00608ad5  eb53                 jmp 0x608b2a
// 00608ad7  83e201               and edx, 1
// 00608ada  69d2ff000000         imul edx, edx, 0xff
// 00608ae0  0fb7d2               movzx edx, dx
// 00608ae3  8d7eff               lea edi, [esi - 1]
// 00608ae6  8d4eff               lea ecx, [esi - 1]
// 00608ae9  c1ef03               shr edi, 3
// 00608aec  83e107               and ecx, 7
// 00608aef  b807000000           mov eax, 7
// 00608af4  03fd                 add edi, ebp
// 00608af6  2bc1                 sub eax, ecx
// 00608af8  89542418             mov dword ptr [esp + 0x18], edx
// 00608afc  8d542eff             lea edx, [esi + ebp - 1]
// 00608b00  85f6                 test esi, esi
// 00608b02  762a                 jbe 0x608b2e
// 00608b04  8974241c             mov dword ptr [esp + 0x1c], esi
// 00608b08  8a1f                 mov bl, byte ptr [edi]
// 00608b0a  8ac8                 mov cl, al
// 00608b0c  d2eb                 shr bl, cl
// 00608b0e  80e301               and bl, 1
// 00608b11  f6db                 neg bl
// 00608b13  1adb                 sbb bl, bl
// 00608b15  881a                 mov byte ptr [edx], bl
// 00608b17  83f807               cmp eax, 7
// 00608b1a  7505                 jne 0x608b21
// 00608b1c  33c0                 xor eax, eax
// 00608b1e  4f                   dec edi
// 00608b1f  eb01                 jmp 0x608b22
// 00608b21  40                   inc eax
// 00608b22  4a                   dec edx
// 00608b23  836c241c01           sub dword ptr [esp + 0x1c], 1
// 00608b28  75de                 jne 0x608b08
// 00608b2a  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00608b2e  8b542418             mov edx, dword ptr [esp + 0x18]
// 00608b32  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00608b36  c6430908             mov byte ptr [ebx + 9], 8
// 00608b3a  c6430b08             mov byte ptr [ebx + 0xb], 8
// 00608b3e  897304               mov dword ptr [ebx + 4], esi
// 00608b41  85c9                 test ecx, ecx
// 00608b43  0f84c8000000         je 0x608c11
// 00608b49  8a4309               mov al, byte ptr [ebx + 9]
// 00608b4c  3c08                 cmp al, 8
// 00608b4e  7533                 jne 0x608b83
// 00608b50  81e2ff000000         and edx, 0xff
// 00608b56  8d4c2eff             lea ecx, [esi + ebp - 1]
// 00608b5a  8d4475ff             lea eax, [ebp + esi*2 - 1]
// 00608b5e  85f6                 test esi, esi
// 00608b60  767b                 jbe 0x608bdd
// 00608b62  8bfe                 mov edi, esi
// 00608b64  660fb619             movzx bx, byte ptr [ecx]
// 00608b68  663bda               cmp bx, dx
// 00608b6b  7505                 jne 0x608b72
// 00608b6d  c60000               mov byte ptr [eax], 0
// 00608b70  eb03                 jmp 0x608b75
// 00608b72  c600ff               mov byte ptr [eax], 0xff
// 00608b75  8a19                 mov bl, byte ptr [ecx]
// 00608b77  48                   dec eax
// 00608b78  8818                 mov byte ptr [eax], bl
// 00608b7a  48                   dec eax
// 00608b7b  49                   dec ecx
// 00608b7c  83ef01               sub edi, 1
// 00608b7f  75e3                 jne 0x608b64
// 00608b81  eb56                 jmp 0x608bd9
// 00608b83  3c10                 cmp al, 0x10
// 00608b85  7556                 jne 0x608bdd
// 00608b87  8b442424             mov eax, dword ptr [esp + 0x24]
// 00608b8b  8b4004               mov eax, dword ptr [eax + 4]
// 00608b8e  8bda                 mov ebx, edx
// 00608b90  c1eb08               shr ebx, 8
// 00608b93  8d4c28ff             lea ecx, [eax + ebp - 1]
// 00608b97  885c2413             mov byte ptr [esp + 0x13], bl
// 00608b9b  8d4445ff             lea eax, [ebp + eax*2 - 1]
// 00608b9f  85f6                 test esi, esi
// 00608ba1  7636                 jbe 0x608bd9
// 00608ba3  8bfe                 mov edi, esi
// 00608ba5  eb04                 jmp 0x608bab
// 00608ba7  8a5c2413             mov bl, byte ptr [esp + 0x13]
// 00608bab  3859ff               cmp byte ptr [ecx - 1], bl
// 00608bae  750d                 jne 0x608bbd
// 00608bb0  3811                 cmp byte ptr [ecx], dl
// 00608bb2  7509                 jne 0x608bbd
// 00608bb4  c60000               mov byte ptr [eax], 0
// 00608bb7  48                   dec eax
// 00608bb8  c60000               mov byte ptr [eax], 0
// 00608bbb  eb07                 jmp 0x608bc4
// 00608bbd  c600ff               mov byte ptr [eax], 0xff
// 00608bc0  48                   dec eax
// 00608bc1  c600ff               mov byte ptr [eax], 0xff
// 00608bc4  0fb619               movzx ebx, byte ptr [ecx]
// 00608bc7  48                   dec eax
// 00608bc8  8818                 mov byte ptr [eax], bl
// 00608bca  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00608bce  49                   dec ecx
// 00608bcf  48                   dec eax
// 00608bd0  8818                 mov byte ptr [eax], bl
// 00608bd2  48                   dec eax
// 00608bd3  49                   dec ecx
// 00608bd4  83ef01               sub edi, 1
// 00608bd7  75ce                 jne 0x608ba7
// 00608bd9  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00608bdd  8a4309               mov al, byte ptr [ebx + 9]
// 00608be0  02c0                 add al, al
// 00608be2  88430b               mov byte ptr [ebx + 0xb], al
// 00608be5  3c08                 cmp al, 8
// 00608be7  c6430804             mov byte ptr [ebx + 8], 4
// 00608beb  c6430a02             mov byte ptr [ebx + 0xa], 2
// 00608bef  0fb6c0               movzx eax, al
// 00608bf2  7211                 jb 0x608c05
// 00608bf4  c1e803               shr eax, 3
// 00608bf7  0fafc6               imul eax, esi
// 00608bfa  5d                   pop ebp
// 00608bfb  5f                   pop edi
// 00608bfc  5e                   pop esi
// 00608bfd  894304               mov dword ptr [ebx + 4], eax
// 00608c00  5b                   pop ebx
// 00608c01  83c410               add esp, 0x10
// 00608c04  c3                   ret 
// 00608c05  0fafc6               imul eax, esi
// 00608c08  83c007               add eax, 7
// 00608c0b  c1e803               shr eax, 3
// 00608c0e  894304               mov dword ptr [ebx + 4], eax
// 00608c11  5d                   pop ebp
// 00608c12  5f                   pop edi
// 00608c13  5e                   pop esi
// 00608c14  5b                   pop ebx
// 00608c15  83c410               add esp, 0x10
// 00608c18  c3                   ret 
// 00608c19  3c02                 cmp al, 2
// 00608c1b  75f5                 jne 0x608c12
// 00608c1d  8b442428             mov eax, dword ptr [esp + 0x28]
// 00608c21  85c0                 test eax, eax
// 00608c23  74ed                 je 0x608c12
// 00608c25  8a4b09               mov cl, byte ptr [ebx + 9]
// 00608c28  80f908               cmp cl, 8
// 00608c2b  7577                 jne 0x608ca4
// 00608c2d  8a4802               mov cl, byte ptr [eax + 2]
// 00608c30  8a5004               mov dl, byte ptr [eax + 4]
// 00608c33  8a4006               mov al, byte ptr [eax + 6]
// 00608c36  884c2420             mov byte ptr [esp + 0x20], cl
// 00608c3a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00608c3e  8854240f             mov byte ptr [esp + 0xf], dl
// 00608c42  8b5304               mov edx, dword ptr [ebx + 4]
// 00608c45  8d540aff             lea edx, [edx + ecx - 1]
// 00608c49  88442410             mov byte ptr [esp + 0x10], al
// 00608c4d  8d4cb1ff             lea ecx, [ecx + esi*4 - 1]
// 00608c51  85f6                 test esi, esi
// 00608c53  0f8616010000         jbe 0x608d6f
// 00608c59  8bfe                 mov edi, esi
// 00608c5b  eb03                 jmp 0x608c60
// 00608c5d  8d4900               lea ecx, [ecx]
// 00608c60  8a442420             mov al, byte ptr [esp + 0x20]
// 00608c64  3842fe               cmp byte ptr [edx - 2], al
// 00608c67  7516                 jne 0x608c7f
// 00608c69  8a44240f             mov al, byte ptr [esp + 0xf]
// 00608c6d  3842ff               cmp byte ptr [edx - 1], al
// 00608c70  750d                 jne 0x608c7f
// 00608c72  8a442410             mov al, byte ptr [esp + 0x10]
// 00608c76  3802                 cmp byte ptr [edx], al
// 00608c78  7505                 jne 0x608c7f
// 00608c7a  c60100               mov byte ptr [ecx], 0
// 00608c7d  eb03                 jmp 0x608c82
// 00608c7f  c601ff               mov byte ptr [ecx], 0xff
// 00608c82  0fb602               movzx eax, byte ptr [edx]
// 00608c85  49                   dec ecx
// 00608c86  8801                 mov byte ptr [ecx], al
// 00608c88  0fb642ff             movzx eax, byte ptr [edx - 1]
// 00608c8c  4a                   dec edx
// 00608c8d  49                   dec ecx
// 00608c8e  8801                 mov byte ptr [ecx], al
// 00608c90  0fb642ff             movzx eax, byte ptr [edx - 1]
// 00608c94  4a                   dec edx
// 00608c95  49                   dec ecx
// 00608c96  8801                 mov byte ptr [ecx], al
// 00608c98  49                   dec ecx
// 00608c99  4a                   dec edx
// 00608c9a  83ef01               sub edi, 1
// 00608c9d  75c1                 jne 0x608c60
// 00608c9f  e9cb000000           jmp 0x608d6f
// 00608ca4  80f910               cmp cl, 0x10
// 00608ca7  0f85c2000000         jne 0x608d6f
// 00608cad  0fb64803             movzx ecx, byte ptr [eax + 3]
// 00608cb1  0fb65005             movzx edx, byte ptr [eax + 5]
// 00608cb5  884c2420             mov byte ptr [esp + 0x20], cl
// 00608cb9  0fb64807             movzx ecx, byte ptr [eax + 7]
// 00608cbd  8854240f             mov byte ptr [esp + 0xf], dl
// 00608cc1  0fb65002             movzx edx, byte ptr [eax + 2]
// 00608cc5  884c2412             mov byte ptr [esp + 0x12], cl
// 00608cc9  0fb64804             movzx ecx, byte ptr [eax + 4]
// 00608ccd  88542410             mov byte ptr [esp + 0x10], dl
// 00608cd1  0fb65006             movzx edx, byte ptr [eax + 6]
// 00608cd5  8b442424             mov eax, dword ptr [esp + 0x24]
// 00608cd9  884c2411             mov byte ptr [esp + 0x11], cl
// 00608cdd  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00608ce0  8d4c01ff             lea ecx, [ecx + eax - 1]
// 00608ce4  88542413             mov byte ptr [esp + 0x13], dl
// 00608ce8  8d44f0ff             lea eax, [eax + esi*8 - 1]
// 00608cec  85f6                 test esi, esi
// 00608cee  767f                 jbe 0x608d6f
// 00608cf0  8bfe                 mov edi, esi
// 00608cf2  8a542420             mov dl, byte ptr [esp + 0x20]
// 00608cf6  3851fb               cmp byte ptr [ecx - 5], dl
// 00608cf9  7535                 jne 0x608d30
// 00608cfb  8a542410             mov dl, byte ptr [esp + 0x10]
// 00608cff  3851fc               cmp byte ptr [ecx - 4], dl
// 00608d02  752c                 jne 0x608d30
// 00608d04  8a54240f             mov dl, byte ptr [esp + 0xf]
// 00608d08  3851fd               cmp byte ptr [ecx - 3], dl
// 00608d0b  7523                 jne 0x608d30
// 00608d0d  8a542411             mov dl, byte ptr [esp + 0x11]
// 00608d11  3851fe               cmp byte ptr [ecx - 2], dl
// 00608d14  751a                 jne 0x608d30
// 00608d16  8a542412             mov dl, byte ptr [esp + 0x12]
// 00608d1a  3851ff               cmp byte ptr [ecx - 1], dl
// 00608d1d  7511                 jne 0x608d30
// 00608d1f  8a542413             mov dl, byte ptr [esp + 0x13]
// 00608d23  3811                 cmp byte ptr [ecx], dl
// 00608d25  7509                 jne 0x608d30
// 00608d27  c60000               mov byte ptr [eax], 0
// 00608d2a  48                   dec eax
// 00608d2b  c60000               mov byte ptr [eax], 0
// 00608d2e  eb07                 jmp 0x608d37
// 00608d30  c600ff               mov byte ptr [eax], 0xff
// 00608d33  48                   dec eax
// 00608d34  c600ff               mov byte ptr [eax], 0xff
// 00608d37  0fb611               movzx edx, byte ptr [ecx]
// 00608d3a  8850ff               mov byte ptr [eax - 1], dl
// 00608d3d  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00608d41  48                   dec eax
// 00608d42  49                   dec ecx
// 00608d43  8850ff               mov byte ptr [eax - 1], dl
// 00608d46  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00608d4a  48                   dec eax
// 00608d4b  49                   dec ecx
// 00608d4c  8850ff               mov byte ptr [eax - 1], dl
// 00608d4f  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00608d53  48                   dec eax
// 00608d54  49                   dec ecx
// 00608d55  48                   dec eax
// 00608d56  8810                 mov byte ptr [eax], dl
// 00608d58  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00608d5c  49                   dec ecx
// 00608d5d  48                   dec eax
// 00608d5e  8810                 mov byte ptr [eax], dl
// 00608d60  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00608d64  49                   dec ecx
// 00608d65  48                   dec eax
// 00608d66  8810                 mov byte ptr [eax], dl
// 00608d68  48                   dec eax
// 00608d69  49                   dec ecx
// 00608d6a  83ef01               sub edi, 1
// 00608d6d  7583                 jne 0x608cf2
// 00608d6f  8a4309               mov al, byte ptr [ebx + 9]
// 00608d72  02c0                 add al, al
// 00608d74  02c0                 add al, al
// 00608d76  88430b               mov byte ptr [ebx + 0xb], al
// 00608d79  3c08                 cmp al, 8
// 00608d7b  c6430806             mov byte ptr [ebx + 8], 6
// 00608d7f  c6430a04             mov byte ptr [ebx + 0xa], 4
// 00608d83  0fb6c0               movzx eax, al
// 00608d86  7210                 jb 0x608d98
// 00608d88  c1e803               shr eax, 3
// 00608d8b  0fafc6               imul eax, esi
// 00608d8e  5f                   pop edi
// 00608d8f  5e                   pop esi
// 00608d90  894304               mov dword ptr [ebx + 4], eax
// 00608d93  5b                   pop ebx
// 00608d94  83c410               add esp, 0x10
// 00608d97  c3                   ret 
// 00608d98  0fafc6               imul eax, esi
// 00608d9b  83c007               add eax, 7
// 00608d9e  5f                   pop edi
// 00608d9f  c1e803               shr eax, 3
// 00608da2  5e                   pop esi
// 00608da3  894304               mov dword ptr [ebx + 4], eax
// 00608da6  5b                   pop ebx
// 00608da7  83c410               add esp, 0x10
// 00608daa  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_do_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
