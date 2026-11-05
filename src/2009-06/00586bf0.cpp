// from server: 100% by auto
// roc 2009-06 00586bf0  unit: seg_00580000  size: 1035 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00586bf0
//
// 00586bf0  83ec10               sub esp, 0x10
// 00586bf3  53                   push ebx
// 00586bf4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00586bf8  8a4308               mov al, byte ptr [ebx + 8]
// 00586bfb  56                   push esi
// 00586bfc  8b33                 mov esi, dword ptr [ebx]
// 00586bfe  57                   push edi
// 00586bff  84c0                 test al, al
// 00586c01  0f8562020000         jne 0x586e69
// 00586c07  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00586c0b  85c9                 test ecx, ecx
// 00586c0d  7406                 je 0x586c15
// 00586c0f  0fb75108             movzx edx, word ptr [ecx + 8]
// 00586c13  eb0c                 jmp 0x586c21
// 00586c15  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00586c1d  8b542414             mov edx, dword ptr [esp + 0x14]
// 00586c21  8a4309               mov al, byte ptr [ebx + 9]
// 00586c24  55                   push ebp
// 00586c25  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 00586c29  3c08                 cmp al, 8
// 00586c2b  0f8360010000         jae 0x586d91
// 00586c31  0fb6c0               movzx eax, al
// 00586c34  83e801               sub eax, 1
// 00586c37  0f84ea000000         je 0x586d27
// 00586c3d  83e801               sub eax, 1
// 00586c40  7473                 je 0x586cb5
// 00586c42  83e802               sub eax, 2
// 00586c45  0f8537010000         jne 0x586d82
// 00586c4b  8bc2                 mov eax, edx
// 00586c4d  83e00f               and eax, 0xf
// 00586c50  8bc8                 mov ecx, eax
// 00586c52  c1e104               shl ecx, 4
// 00586c55  03c8                 add ecx, eax
// 00586c57  0fb7d1               movzx edx, cx
// 00586c5a  8d46ff               lea eax, [esi - 1]
// 00586c5d  83e001               and eax, 1
// 00586c60  03c0                 add eax, eax
// 00586c62  89542418             mov dword ptr [esp + 0x18], edx
// 00586c66  8d7eff               lea edi, [esi - 1]
// 00586c69  d1ef                 shr edi, 1
// 00586c6b  03c0                 add eax, eax
// 00586c6d  ba04000000           mov edx, 4
// 00586c72  03fd                 add edi, ebp
// 00586c74  2bd0                 sub edx, eax
// 00586c76  8d5c2eff             lea ebx, [esi + ebp - 1]
// 00586c7a  85f6                 test esi, esi
// 00586c7c  0f86f8000000         jbe 0x586d7a
// 00586c82  8974241c             mov dword ptr [esp + 0x1c], esi
// 00586c86  0fb607               movzx eax, byte ptr [edi]
// 00586c89  8aca                 mov cl, dl
// 00586c8b  d3e8                 shr eax, cl
// 00586c8d  83e00f               and eax, 0xf
// 00586c90  8ac8                 mov cl, al
// 00586c92  c0e104               shl cl, 4
// 00586c95  0ac8                 or cl, al
// 00586c97  880b                 mov byte ptr [ebx], cl
// 00586c99  83fa04               cmp edx, 4
// 00586c9c  7505                 jne 0x586ca3
// 00586c9e  33d2                 xor edx, edx
// 00586ca0  4f                   dec edi
// 00586ca1  eb05                 jmp 0x586ca8
// 00586ca3  ba04000000           mov edx, 4
// 00586ca8  4b                   dec ebx
// 00586ca9  836c241c01           sub dword ptr [esp + 0x1c], 1
// 00586cae  75d6                 jne 0x586c86
// 00586cb0  e9c5000000           jmp 0x586d7a
// 00586cb5  83e203               and edx, 3
// 00586cb8  6bd255               imul edx, edx, 0x55
// 00586cbb  0fb7d2               movzx edx, dx
// 00586cbe  89542418             mov dword ptr [esp + 0x18], edx
// 00586cc2  8d46ff               lea eax, [esi - 1]
// 00586cc5  83e003               and eax, 3
// 00586cc8  8d7eff               lea edi, [esi - 1]
// 00586ccb  ba03000000           mov edx, 3
// 00586cd0  c1ef02               shr edi, 2
// 00586cd3  2bd0                 sub edx, eax
// 00586cd5  03fd                 add edi, ebp
// 00586cd7  03d2                 add edx, edx
// 00586cd9  8d5c2eff             lea ebx, [esi + ebp - 1]
// 00586cdd  85f6                 test esi, esi
// 00586cdf  0f8695000000         jbe 0x586d7a
// 00586ce5  8974241c             mov dword ptr [esp + 0x1c], esi
// 00586ce9  8da42400000000       lea esp, [esp]
// 00586cf0  0fb607               movzx eax, byte ptr [edi]
// 00586cf3  8aca                 mov cl, dl
// 00586cf5  d3e8                 shr eax, cl
// 00586cf7  83e003               and eax, 3
// 00586cfa  8ac8                 mov cl, al
// 00586cfc  02c9                 add cl, cl
// 00586cfe  02c9                 add cl, cl
// 00586d00  0ac8                 or cl, al
// 00586d02  02c9                 add cl, cl
// 00586d04  02c9                 add cl, cl
// 00586d06  0ac8                 or cl, al
// 00586d08  02c9                 add cl, cl
// 00586d0a  02c9                 add cl, cl
// 00586d0c  0ac8                 or cl, al
// 00586d0e  880b                 mov byte ptr [ebx], cl
// 00586d10  83fa06               cmp edx, 6
// 00586d13  7505                 jne 0x586d1a
// 00586d15  33d2                 xor edx, edx
// 00586d17  4f                   dec edi
// 00586d18  eb03                 jmp 0x586d1d
// 00586d1a  83c202               add edx, 2
// 00586d1d  4b                   dec ebx
// 00586d1e  836c241c01           sub dword ptr [esp + 0x1c], 1
// 00586d23  75cb                 jne 0x586cf0
// 00586d25  eb53                 jmp 0x586d7a
// 00586d27  83e201               and edx, 1
// 00586d2a  69d2ff000000         imul edx, edx, 0xff
// 00586d30  0fb7d2               movzx edx, dx
// 00586d33  8d7eff               lea edi, [esi - 1]
// 00586d36  8d4eff               lea ecx, [esi - 1]
// 00586d39  c1ef03               shr edi, 3
// 00586d3c  83e107               and ecx, 7
// 00586d3f  b807000000           mov eax, 7
// 00586d44  03fd                 add edi, ebp
// 00586d46  2bc1                 sub eax, ecx
// 00586d48  89542418             mov dword ptr [esp + 0x18], edx
// 00586d4c  8d542eff             lea edx, [esi + ebp - 1]
// 00586d50  85f6                 test esi, esi
// 00586d52  762a                 jbe 0x586d7e
// 00586d54  8974241c             mov dword ptr [esp + 0x1c], esi
// 00586d58  8a1f                 mov bl, byte ptr [edi]
// 00586d5a  8ac8                 mov cl, al
// 00586d5c  d2eb                 shr bl, cl
// 00586d5e  80e301               and bl, 1
// 00586d61  f6db                 neg bl
// 00586d63  1adb                 sbb bl, bl
// 00586d65  881a                 mov byte ptr [edx], bl
// 00586d67  83f807               cmp eax, 7
// 00586d6a  7505                 jne 0x586d71
// 00586d6c  33c0                 xor eax, eax
// 00586d6e  4f                   dec edi
// 00586d6f  eb01                 jmp 0x586d72
// 00586d71  40                   inc eax
// 00586d72  4a                   dec edx
// 00586d73  836c241c01           sub dword ptr [esp + 0x1c], 1
// 00586d78  75de                 jne 0x586d58
// 00586d7a  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00586d7e  8b542418             mov edx, dword ptr [esp + 0x18]
// 00586d82  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00586d86  c6430908             mov byte ptr [ebx + 9], 8
// 00586d8a  c6430b08             mov byte ptr [ebx + 0xb], 8
// 00586d8e  897304               mov dword ptr [ebx + 4], esi
// 00586d91  85c9                 test ecx, ecx
// 00586d93  0f84c8000000         je 0x586e61
// 00586d99  8a4309               mov al, byte ptr [ebx + 9]
// 00586d9c  3c08                 cmp al, 8
// 00586d9e  7533                 jne 0x586dd3
// 00586da0  81e2ff000000         and edx, 0xff
// 00586da6  8d4c2eff             lea ecx, [esi + ebp - 1]
// 00586daa  8d4475ff             lea eax, [ebp + esi*2 - 1]
// 00586dae  85f6                 test esi, esi
// 00586db0  767b                 jbe 0x586e2d
// 00586db2  8bfe                 mov edi, esi
// 00586db4  660fb619             movzx bx, byte ptr [ecx]
// 00586db8  663bda               cmp bx, dx
// 00586dbb  7505                 jne 0x586dc2
// 00586dbd  c60000               mov byte ptr [eax], 0
// 00586dc0  eb03                 jmp 0x586dc5
// 00586dc2  c600ff               mov byte ptr [eax], 0xff
// 00586dc5  8a19                 mov bl, byte ptr [ecx]
// 00586dc7  48                   dec eax
// 00586dc8  8818                 mov byte ptr [eax], bl
// 00586dca  48                   dec eax
// 00586dcb  49                   dec ecx
// 00586dcc  83ef01               sub edi, 1
// 00586dcf  75e3                 jne 0x586db4
// 00586dd1  eb56                 jmp 0x586e29
// 00586dd3  3c10                 cmp al, 0x10
// 00586dd5  7556                 jne 0x586e2d
// 00586dd7  8b442424             mov eax, dword ptr [esp + 0x24]
// 00586ddb  8b4004               mov eax, dword ptr [eax + 4]
// 00586dde  8bda                 mov ebx, edx
// 00586de0  c1eb08               shr ebx, 8
// 00586de3  8d4c28ff             lea ecx, [eax + ebp - 1]
// 00586de7  885c2413             mov byte ptr [esp + 0x13], bl
// 00586deb  8d4445ff             lea eax, [ebp + eax*2 - 1]
// 00586def  85f6                 test esi, esi
// 00586df1  7636                 jbe 0x586e29
// 00586df3  8bfe                 mov edi, esi
// 00586df5  eb04                 jmp 0x586dfb
// 00586df7  8a5c2413             mov bl, byte ptr [esp + 0x13]
// 00586dfb  3859ff               cmp byte ptr [ecx - 1], bl
// 00586dfe  750d                 jne 0x586e0d
// 00586e00  3811                 cmp byte ptr [ecx], dl
// 00586e02  7509                 jne 0x586e0d
// 00586e04  c60000               mov byte ptr [eax], 0
// 00586e07  48                   dec eax
// 00586e08  c60000               mov byte ptr [eax], 0
// 00586e0b  eb07                 jmp 0x586e14
// 00586e0d  c600ff               mov byte ptr [eax], 0xff
// 00586e10  48                   dec eax
// 00586e11  c600ff               mov byte ptr [eax], 0xff
// 00586e14  0fb619               movzx ebx, byte ptr [ecx]
// 00586e17  48                   dec eax
// 00586e18  8818                 mov byte ptr [eax], bl
// 00586e1a  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00586e1e  49                   dec ecx
// 00586e1f  48                   dec eax
// 00586e20  8818                 mov byte ptr [eax], bl
// 00586e22  48                   dec eax
// 00586e23  49                   dec ecx
// 00586e24  83ef01               sub edi, 1
// 00586e27  75ce                 jne 0x586df7
// 00586e29  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00586e2d  8a4309               mov al, byte ptr [ebx + 9]
// 00586e30  02c0                 add al, al
// 00586e32  88430b               mov byte ptr [ebx + 0xb], al
// 00586e35  3c08                 cmp al, 8
// 00586e37  c6430804             mov byte ptr [ebx + 8], 4
// 00586e3b  c6430a02             mov byte ptr [ebx + 0xa], 2
// 00586e3f  0fb6c0               movzx eax, al
// 00586e42  7211                 jb 0x586e55
// 00586e44  c1e803               shr eax, 3
// 00586e47  0fafc6               imul eax, esi
// 00586e4a  5d                   pop ebp
// 00586e4b  5f                   pop edi
// 00586e4c  5e                   pop esi
// 00586e4d  894304               mov dword ptr [ebx + 4], eax
// 00586e50  5b                   pop ebx
// 00586e51  83c410               add esp, 0x10
// 00586e54  c3                   ret 
// 00586e55  0fafc6               imul eax, esi
// 00586e58  83c007               add eax, 7
// 00586e5b  c1e803               shr eax, 3
// 00586e5e  894304               mov dword ptr [ebx + 4], eax
// 00586e61  5d                   pop ebp
// 00586e62  5f                   pop edi
// 00586e63  5e                   pop esi
// 00586e64  5b                   pop ebx
// 00586e65  83c410               add esp, 0x10
// 00586e68  c3                   ret 
// 00586e69  3c02                 cmp al, 2
// 00586e6b  75f5                 jne 0x586e62
// 00586e6d  8b442428             mov eax, dword ptr [esp + 0x28]
// 00586e71  85c0                 test eax, eax
// 00586e73  74ed                 je 0x586e62
// 00586e75  8a4b09               mov cl, byte ptr [ebx + 9]
// 00586e78  80f908               cmp cl, 8
// 00586e7b  7577                 jne 0x586ef4
// 00586e7d  8a4802               mov cl, byte ptr [eax + 2]
// 00586e80  8a5004               mov dl, byte ptr [eax + 4]
// 00586e83  8a4006               mov al, byte ptr [eax + 6]
// 00586e86  884c2420             mov byte ptr [esp + 0x20], cl
// 00586e8a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00586e8e  8854240f             mov byte ptr [esp + 0xf], dl
// 00586e92  8b5304               mov edx, dword ptr [ebx + 4]
// 00586e95  8d540aff             lea edx, [edx + ecx - 1]
// 00586e99  88442410             mov byte ptr [esp + 0x10], al
// 00586e9d  8d4cb1ff             lea ecx, [ecx + esi*4 - 1]
// 00586ea1  85f6                 test esi, esi
// 00586ea3  0f8616010000         jbe 0x586fbf
// 00586ea9  8bfe                 mov edi, esi
// 00586eab  eb03                 jmp 0x586eb0
// 00586ead  8d4900               lea ecx, [ecx]
// 00586eb0  8a442420             mov al, byte ptr [esp + 0x20]
// 00586eb4  3842fe               cmp byte ptr [edx - 2], al
// 00586eb7  7516                 jne 0x586ecf
// 00586eb9  8a44240f             mov al, byte ptr [esp + 0xf]
// 00586ebd  3842ff               cmp byte ptr [edx - 1], al
// 00586ec0  750d                 jne 0x586ecf
// 00586ec2  8a442410             mov al, byte ptr [esp + 0x10]
// 00586ec6  3802                 cmp byte ptr [edx], al
// 00586ec8  7505                 jne 0x586ecf
// 00586eca  c60100               mov byte ptr [ecx], 0
// 00586ecd  eb03                 jmp 0x586ed2
// 00586ecf  c601ff               mov byte ptr [ecx], 0xff
// 00586ed2  0fb602               movzx eax, byte ptr [edx]
// 00586ed5  49                   dec ecx
// 00586ed6  8801                 mov byte ptr [ecx], al
// 00586ed8  0fb642ff             movzx eax, byte ptr [edx - 1]
// 00586edc  4a                   dec edx
// 00586edd  49                   dec ecx
// 00586ede  8801                 mov byte ptr [ecx], al
// 00586ee0  0fb642ff             movzx eax, byte ptr [edx - 1]
// 00586ee4  4a                   dec edx
// 00586ee5  49                   dec ecx
// 00586ee6  8801                 mov byte ptr [ecx], al
// 00586ee8  49                   dec ecx
// 00586ee9  4a                   dec edx
// 00586eea  83ef01               sub edi, 1
// 00586eed  75c1                 jne 0x586eb0
// 00586eef  e9cb000000           jmp 0x586fbf
// 00586ef4  80f910               cmp cl, 0x10
// 00586ef7  0f85c2000000         jne 0x586fbf
// 00586efd  0fb64803             movzx ecx, byte ptr [eax + 3]
// 00586f01  0fb65005             movzx edx, byte ptr [eax + 5]
// 00586f05  884c2420             mov byte ptr [esp + 0x20], cl
// 00586f09  0fb64807             movzx ecx, byte ptr [eax + 7]
// 00586f0d  8854240f             mov byte ptr [esp + 0xf], dl
// 00586f11  0fb65002             movzx edx, byte ptr [eax + 2]
// 00586f15  884c2412             mov byte ptr [esp + 0x12], cl
// 00586f19  0fb64804             movzx ecx, byte ptr [eax + 4]
// 00586f1d  88542410             mov byte ptr [esp + 0x10], dl
// 00586f21  0fb65006             movzx edx, byte ptr [eax + 6]
// 00586f25  8b442424             mov eax, dword ptr [esp + 0x24]
// 00586f29  884c2411             mov byte ptr [esp + 0x11], cl
// 00586f2d  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00586f30  8d4c01ff             lea ecx, [ecx + eax - 1]
// 00586f34  88542413             mov byte ptr [esp + 0x13], dl
// 00586f38  8d44f0ff             lea eax, [eax + esi*8 - 1]
// 00586f3c  85f6                 test esi, esi
// 00586f3e  767f                 jbe 0x586fbf
// 00586f40  8bfe                 mov edi, esi
// 00586f42  8a542420             mov dl, byte ptr [esp + 0x20]
// 00586f46  3851fb               cmp byte ptr [ecx - 5], dl
// 00586f49  7535                 jne 0x586f80
// 00586f4b  8a542410             mov dl, byte ptr [esp + 0x10]
// 00586f4f  3851fc               cmp byte ptr [ecx - 4], dl
// 00586f52  752c                 jne 0x586f80
// 00586f54  8a54240f             mov dl, byte ptr [esp + 0xf]
// 00586f58  3851fd               cmp byte ptr [ecx - 3], dl
// 00586f5b  7523                 jne 0x586f80
// 00586f5d  8a542411             mov dl, byte ptr [esp + 0x11]
// 00586f61  3851fe               cmp byte ptr [ecx - 2], dl
// 00586f64  751a                 jne 0x586f80
// 00586f66  8a542412             mov dl, byte ptr [esp + 0x12]
// 00586f6a  3851ff               cmp byte ptr [ecx - 1], dl
// 00586f6d  7511                 jne 0x586f80
// 00586f6f  8a542413             mov dl, byte ptr [esp + 0x13]
// 00586f73  3811                 cmp byte ptr [ecx], dl
// 00586f75  7509                 jne 0x586f80
// 00586f77  c60000               mov byte ptr [eax], 0
// 00586f7a  48                   dec eax
// 00586f7b  c60000               mov byte ptr [eax], 0
// 00586f7e  eb07                 jmp 0x586f87
// 00586f80  c600ff               mov byte ptr [eax], 0xff
// 00586f83  48                   dec eax
// 00586f84  c600ff               mov byte ptr [eax], 0xff
// 00586f87  0fb611               movzx edx, byte ptr [ecx]
// 00586f8a  8850ff               mov byte ptr [eax - 1], dl
// 00586f8d  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00586f91  48                   dec eax
// 00586f92  49                   dec ecx
// 00586f93  8850ff               mov byte ptr [eax - 1], dl
// 00586f96  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00586f9a  48                   dec eax
// 00586f9b  49                   dec ecx
// 00586f9c  8850ff               mov byte ptr [eax - 1], dl
// 00586f9f  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00586fa3  48                   dec eax
// 00586fa4  49                   dec ecx
// 00586fa5  48                   dec eax
// 00586fa6  8810                 mov byte ptr [eax], dl
// 00586fa8  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00586fac  49                   dec ecx
// 00586fad  48                   dec eax
// 00586fae  8810                 mov byte ptr [eax], dl
// 00586fb0  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00586fb4  49                   dec ecx
// 00586fb5  48                   dec eax
// 00586fb6  8810                 mov byte ptr [eax], dl
// 00586fb8  48                   dec eax
// 00586fb9  49                   dec ecx
// 00586fba  83ef01               sub edi, 1
// 00586fbd  7583                 jne 0x586f42
// 00586fbf  8a4309               mov al, byte ptr [ebx + 9]
// 00586fc2  02c0                 add al, al
// 00586fc4  02c0                 add al, al
// 00586fc6  88430b               mov byte ptr [ebx + 0xb], al
// 00586fc9  3c08                 cmp al, 8
// 00586fcb  c6430806             mov byte ptr [ebx + 8], 6
// 00586fcf  c6430a04             mov byte ptr [ebx + 0xa], 4
// 00586fd3  0fb6c0               movzx eax, al
// 00586fd6  7210                 jb 0x586fe8
// 00586fd8  c1e803               shr eax, 3
// 00586fdb  0fafc6               imul eax, esi
// 00586fde  5f                   pop edi
// 00586fdf  5e                   pop esi
// 00586fe0  894304               mov dword ptr [ebx + 4], eax
// 00586fe3  5b                   pop ebx
// 00586fe4  83c410               add esp, 0x10
// 00586fe7  c3                   ret 
// 00586fe8  0fafc6               imul eax, esi
// 00586feb  83c007               add eax, 7
// 00586fee  5f                   pop edi
// 00586fef  c1e803               shr eax, 3
// 00586ff2  5e                   pop esi
// 00586ff3  894304               mov dword ptr [ebx + 4], eax
// 00586ff6  5b                   pop ebx
// 00586ff7  83c410               add esp, 0x10
// 00586ffa  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_do_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
