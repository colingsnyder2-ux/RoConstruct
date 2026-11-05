// from server: 100% by auto
// roc 2011-06 0055ee70  unit: seg_00550000  size: 1035 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055ee70
//
// 0055ee70  83ec10               sub esp, 0x10
// 0055ee73  53                   push ebx
// 0055ee74  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0055ee78  8a4308               mov al, byte ptr [ebx + 8]
// 0055ee7b  56                   push esi
// 0055ee7c  8b33                 mov esi, dword ptr [ebx]
// 0055ee7e  57                   push edi
// 0055ee7f  84c0                 test al, al
// 0055ee81  0f8562020000         jne 0x55f0e9
// 0055ee87  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0055ee8b  85c9                 test ecx, ecx
// 0055ee8d  7406                 je 0x55ee95
// 0055ee8f  0fb75108             movzx edx, word ptr [ecx + 8]
// 0055ee93  eb0c                 jmp 0x55eea1
// 0055ee95  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0055ee9d  8b542414             mov edx, dword ptr [esp + 0x14]
// 0055eea1  8a4309               mov al, byte ptr [ebx + 9]
// 0055eea4  55                   push ebp
// 0055eea5  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0055eea9  3c08                 cmp al, 8
// 0055eeab  0f8360010000         jae 0x55f011
// 0055eeb1  0fb6c0               movzx eax, al
// 0055eeb4  83e801               sub eax, 1
// 0055eeb7  0f84ea000000         je 0x55efa7
// 0055eebd  83e801               sub eax, 1
// 0055eec0  7473                 je 0x55ef35
// 0055eec2  83e802               sub eax, 2
// 0055eec5  0f8537010000         jne 0x55f002
// 0055eecb  8bc2                 mov eax, edx
// 0055eecd  83e00f               and eax, 0xf
// 0055eed0  8bc8                 mov ecx, eax
// 0055eed2  c1e104               shl ecx, 4
// 0055eed5  03c8                 add ecx, eax
// 0055eed7  0fb7d1               movzx edx, cx
// 0055eeda  8d46ff               lea eax, [esi - 1]
// 0055eedd  83e001               and eax, 1
// 0055eee0  03c0                 add eax, eax
// 0055eee2  89542418             mov dword ptr [esp + 0x18], edx
// 0055eee6  8d7eff               lea edi, [esi - 1]
// 0055eee9  d1ef                 shr edi, 1
// 0055eeeb  03c0                 add eax, eax
// 0055eeed  ba04000000           mov edx, 4
// 0055eef2  03fd                 add edi, ebp
// 0055eef4  2bd0                 sub edx, eax
// 0055eef6  8d5c2eff             lea ebx, [esi + ebp - 1]
// 0055eefa  85f6                 test esi, esi
// 0055eefc  0f86f8000000         jbe 0x55effa
// 0055ef02  8974241c             mov dword ptr [esp + 0x1c], esi
// 0055ef06  0fb607               movzx eax, byte ptr [edi]
// 0055ef09  8aca                 mov cl, dl
// 0055ef0b  d3e8                 shr eax, cl
// 0055ef0d  83e00f               and eax, 0xf
// 0055ef10  8ac8                 mov cl, al
// 0055ef12  c0e104               shl cl, 4
// 0055ef15  0ac8                 or cl, al
// 0055ef17  880b                 mov byte ptr [ebx], cl
// 0055ef19  83fa04               cmp edx, 4
// 0055ef1c  7505                 jne 0x55ef23
// 0055ef1e  33d2                 xor edx, edx
// 0055ef20  4f                   dec edi
// 0055ef21  eb05                 jmp 0x55ef28
// 0055ef23  ba04000000           mov edx, 4
// 0055ef28  4b                   dec ebx
// 0055ef29  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0055ef2e  75d6                 jne 0x55ef06
// 0055ef30  e9c5000000           jmp 0x55effa
// 0055ef35  83e203               and edx, 3
// 0055ef38  6bd255               imul edx, edx, 0x55
// 0055ef3b  0fb7d2               movzx edx, dx
// 0055ef3e  89542418             mov dword ptr [esp + 0x18], edx
// 0055ef42  8d46ff               lea eax, [esi - 1]
// 0055ef45  83e003               and eax, 3
// 0055ef48  8d7eff               lea edi, [esi - 1]
// 0055ef4b  ba03000000           mov edx, 3
// 0055ef50  c1ef02               shr edi, 2
// 0055ef53  2bd0                 sub edx, eax
// 0055ef55  03fd                 add edi, ebp
// 0055ef57  03d2                 add edx, edx
// 0055ef59  8d5c2eff             lea ebx, [esi + ebp - 1]
// 0055ef5d  85f6                 test esi, esi
// 0055ef5f  0f8695000000         jbe 0x55effa
// 0055ef65  8974241c             mov dword ptr [esp + 0x1c], esi
// 0055ef69  8da42400000000       lea esp, [esp]
// 0055ef70  0fb607               movzx eax, byte ptr [edi]
// 0055ef73  8aca                 mov cl, dl
// 0055ef75  d3e8                 shr eax, cl
// 0055ef77  83e003               and eax, 3
// 0055ef7a  8ac8                 mov cl, al
// 0055ef7c  02c9                 add cl, cl
// 0055ef7e  02c9                 add cl, cl
// 0055ef80  0ac8                 or cl, al
// 0055ef82  02c9                 add cl, cl
// 0055ef84  02c9                 add cl, cl
// 0055ef86  0ac8                 or cl, al
// 0055ef88  02c9                 add cl, cl
// 0055ef8a  02c9                 add cl, cl
// 0055ef8c  0ac8                 or cl, al
// 0055ef8e  880b                 mov byte ptr [ebx], cl
// 0055ef90  83fa06               cmp edx, 6
// 0055ef93  7505                 jne 0x55ef9a
// 0055ef95  33d2                 xor edx, edx
// 0055ef97  4f                   dec edi
// 0055ef98  eb03                 jmp 0x55ef9d
// 0055ef9a  83c202               add edx, 2
// 0055ef9d  4b                   dec ebx
// 0055ef9e  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0055efa3  75cb                 jne 0x55ef70
// 0055efa5  eb53                 jmp 0x55effa
// 0055efa7  83e201               and edx, 1
// 0055efaa  69d2ff000000         imul edx, edx, 0xff
// 0055efb0  0fb7d2               movzx edx, dx
// 0055efb3  8d7eff               lea edi, [esi - 1]
// 0055efb6  8d4eff               lea ecx, [esi - 1]
// 0055efb9  c1ef03               shr edi, 3
// 0055efbc  83e107               and ecx, 7
// 0055efbf  b807000000           mov eax, 7
// 0055efc4  03fd                 add edi, ebp
// 0055efc6  2bc1                 sub eax, ecx
// 0055efc8  89542418             mov dword ptr [esp + 0x18], edx
// 0055efcc  8d542eff             lea edx, [esi + ebp - 1]
// 0055efd0  85f6                 test esi, esi
// 0055efd2  762a                 jbe 0x55effe
// 0055efd4  8974241c             mov dword ptr [esp + 0x1c], esi
// 0055efd8  8a1f                 mov bl, byte ptr [edi]
// 0055efda  8ac8                 mov cl, al
// 0055efdc  d2eb                 shr bl, cl
// 0055efde  80e301               and bl, 1
// 0055efe1  f6db                 neg bl
// 0055efe3  1adb                 sbb bl, bl
// 0055efe5  881a                 mov byte ptr [edx], bl
// 0055efe7  83f807               cmp eax, 7
// 0055efea  7505                 jne 0x55eff1
// 0055efec  33c0                 xor eax, eax
// 0055efee  4f                   dec edi
// 0055efef  eb01                 jmp 0x55eff2
// 0055eff1  40                   inc eax
// 0055eff2  4a                   dec edx
// 0055eff3  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0055eff8  75de                 jne 0x55efd8
// 0055effa  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0055effe  8b542418             mov edx, dword ptr [esp + 0x18]
// 0055f002  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0055f006  c6430908             mov byte ptr [ebx + 9], 8
// 0055f00a  c6430b08             mov byte ptr [ebx + 0xb], 8
// 0055f00e  897304               mov dword ptr [ebx + 4], esi
// 0055f011  85c9                 test ecx, ecx
// 0055f013  0f84c8000000         je 0x55f0e1
// 0055f019  8a4309               mov al, byte ptr [ebx + 9]
// 0055f01c  3c08                 cmp al, 8
// 0055f01e  7533                 jne 0x55f053
// 0055f020  81e2ff000000         and edx, 0xff
// 0055f026  8d4c2eff             lea ecx, [esi + ebp - 1]
// 0055f02a  8d4475ff             lea eax, [ebp + esi*2 - 1]
// 0055f02e  85f6                 test esi, esi
// 0055f030  767b                 jbe 0x55f0ad
// 0055f032  8bfe                 mov edi, esi
// 0055f034  660fb619             movzx bx, byte ptr [ecx]
// 0055f038  663bda               cmp bx, dx
// 0055f03b  7505                 jne 0x55f042
// 0055f03d  c60000               mov byte ptr [eax], 0
// 0055f040  eb03                 jmp 0x55f045
// 0055f042  c600ff               mov byte ptr [eax], 0xff
// 0055f045  8a19                 mov bl, byte ptr [ecx]
// 0055f047  48                   dec eax
// 0055f048  8818                 mov byte ptr [eax], bl
// 0055f04a  48                   dec eax
// 0055f04b  49                   dec ecx
// 0055f04c  83ef01               sub edi, 1
// 0055f04f  75e3                 jne 0x55f034
// 0055f051  eb56                 jmp 0x55f0a9
// 0055f053  3c10                 cmp al, 0x10
// 0055f055  7556                 jne 0x55f0ad
// 0055f057  8b442424             mov eax, dword ptr [esp + 0x24]
// 0055f05b  8b4004               mov eax, dword ptr [eax + 4]
// 0055f05e  8bda                 mov ebx, edx
// 0055f060  c1eb08               shr ebx, 8
// 0055f063  8d4c28ff             lea ecx, [eax + ebp - 1]
// 0055f067  885c2413             mov byte ptr [esp + 0x13], bl
// 0055f06b  8d4445ff             lea eax, [ebp + eax*2 - 1]
// 0055f06f  85f6                 test esi, esi
// 0055f071  7636                 jbe 0x55f0a9
// 0055f073  8bfe                 mov edi, esi
// 0055f075  eb04                 jmp 0x55f07b
// 0055f077  8a5c2413             mov bl, byte ptr [esp + 0x13]
// 0055f07b  3859ff               cmp byte ptr [ecx - 1], bl
// 0055f07e  750d                 jne 0x55f08d
// 0055f080  3811                 cmp byte ptr [ecx], dl
// 0055f082  7509                 jne 0x55f08d
// 0055f084  c60000               mov byte ptr [eax], 0
// 0055f087  48                   dec eax
// 0055f088  c60000               mov byte ptr [eax], 0
// 0055f08b  eb07                 jmp 0x55f094
// 0055f08d  c600ff               mov byte ptr [eax], 0xff
// 0055f090  48                   dec eax
// 0055f091  c600ff               mov byte ptr [eax], 0xff
// 0055f094  0fb619               movzx ebx, byte ptr [ecx]
// 0055f097  48                   dec eax
// 0055f098  8818                 mov byte ptr [eax], bl
// 0055f09a  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0055f09e  49                   dec ecx
// 0055f09f  48                   dec eax
// 0055f0a0  8818                 mov byte ptr [eax], bl
// 0055f0a2  48                   dec eax
// 0055f0a3  49                   dec ecx
// 0055f0a4  83ef01               sub edi, 1
// 0055f0a7  75ce                 jne 0x55f077
// 0055f0a9  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0055f0ad  8a4309               mov al, byte ptr [ebx + 9]
// 0055f0b0  02c0                 add al, al
// 0055f0b2  88430b               mov byte ptr [ebx + 0xb], al
// 0055f0b5  3c08                 cmp al, 8
// 0055f0b7  c6430804             mov byte ptr [ebx + 8], 4
// 0055f0bb  c6430a02             mov byte ptr [ebx + 0xa], 2
// 0055f0bf  0fb6c0               movzx eax, al
// 0055f0c2  7211                 jb 0x55f0d5
// 0055f0c4  c1e803               shr eax, 3
// 0055f0c7  0fafc6               imul eax, esi
// 0055f0ca  5d                   pop ebp
// 0055f0cb  5f                   pop edi
// 0055f0cc  5e                   pop esi
// 0055f0cd  894304               mov dword ptr [ebx + 4], eax
// 0055f0d0  5b                   pop ebx
// 0055f0d1  83c410               add esp, 0x10
// 0055f0d4  c3                   ret 
// 0055f0d5  0fafc6               imul eax, esi
// 0055f0d8  83c007               add eax, 7
// 0055f0db  c1e803               shr eax, 3
// 0055f0de  894304               mov dword ptr [ebx + 4], eax
// 0055f0e1  5d                   pop ebp
// 0055f0e2  5f                   pop edi
// 0055f0e3  5e                   pop esi
// 0055f0e4  5b                   pop ebx
// 0055f0e5  83c410               add esp, 0x10
// 0055f0e8  c3                   ret 
// 0055f0e9  3c02                 cmp al, 2
// 0055f0eb  75f5                 jne 0x55f0e2
// 0055f0ed  8b442428             mov eax, dword ptr [esp + 0x28]
// 0055f0f1  85c0                 test eax, eax
// 0055f0f3  74ed                 je 0x55f0e2
// 0055f0f5  8a4b09               mov cl, byte ptr [ebx + 9]
// 0055f0f8  80f908               cmp cl, 8
// 0055f0fb  7577                 jne 0x55f174
// 0055f0fd  8a4802               mov cl, byte ptr [eax + 2]
// 0055f100  8a5004               mov dl, byte ptr [eax + 4]
// 0055f103  8a4006               mov al, byte ptr [eax + 6]
// 0055f106  884c2420             mov byte ptr [esp + 0x20], cl
// 0055f10a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0055f10e  8854240f             mov byte ptr [esp + 0xf], dl
// 0055f112  8b5304               mov edx, dword ptr [ebx + 4]
// 0055f115  8d540aff             lea edx, [edx + ecx - 1]
// 0055f119  88442410             mov byte ptr [esp + 0x10], al
// 0055f11d  8d4cb1ff             lea ecx, [ecx + esi*4 - 1]
// 0055f121  85f6                 test esi, esi
// 0055f123  0f8616010000         jbe 0x55f23f
// 0055f129  8bfe                 mov edi, esi
// 0055f12b  eb03                 jmp 0x55f130
// 0055f12d  8d4900               lea ecx, [ecx]
// 0055f130  8a442420             mov al, byte ptr [esp + 0x20]
// 0055f134  3842fe               cmp byte ptr [edx - 2], al
// 0055f137  7516                 jne 0x55f14f
// 0055f139  8a44240f             mov al, byte ptr [esp + 0xf]
// 0055f13d  3842ff               cmp byte ptr [edx - 1], al
// 0055f140  750d                 jne 0x55f14f
// 0055f142  8a442410             mov al, byte ptr [esp + 0x10]
// 0055f146  3802                 cmp byte ptr [edx], al
// 0055f148  7505                 jne 0x55f14f
// 0055f14a  c60100               mov byte ptr [ecx], 0
// 0055f14d  eb03                 jmp 0x55f152
// 0055f14f  c601ff               mov byte ptr [ecx], 0xff
// 0055f152  0fb602               movzx eax, byte ptr [edx]
// 0055f155  49                   dec ecx
// 0055f156  8801                 mov byte ptr [ecx], al
// 0055f158  0fb642ff             movzx eax, byte ptr [edx - 1]
// 0055f15c  4a                   dec edx
// 0055f15d  49                   dec ecx
// 0055f15e  8801                 mov byte ptr [ecx], al
// 0055f160  0fb642ff             movzx eax, byte ptr [edx - 1]
// 0055f164  4a                   dec edx
// 0055f165  49                   dec ecx
// 0055f166  8801                 mov byte ptr [ecx], al
// 0055f168  49                   dec ecx
// 0055f169  4a                   dec edx
// 0055f16a  83ef01               sub edi, 1
// 0055f16d  75c1                 jne 0x55f130
// 0055f16f  e9cb000000           jmp 0x55f23f
// 0055f174  80f910               cmp cl, 0x10
// 0055f177  0f85c2000000         jne 0x55f23f
// 0055f17d  0fb64803             movzx ecx, byte ptr [eax + 3]
// 0055f181  0fb65005             movzx edx, byte ptr [eax + 5]
// 0055f185  884c2420             mov byte ptr [esp + 0x20], cl
// 0055f189  0fb64807             movzx ecx, byte ptr [eax + 7]
// 0055f18d  8854240f             mov byte ptr [esp + 0xf], dl
// 0055f191  0fb65002             movzx edx, byte ptr [eax + 2]
// 0055f195  884c2412             mov byte ptr [esp + 0x12], cl
// 0055f199  0fb64804             movzx ecx, byte ptr [eax + 4]
// 0055f19d  88542410             mov byte ptr [esp + 0x10], dl
// 0055f1a1  0fb65006             movzx edx, byte ptr [eax + 6]
// 0055f1a5  8b442424             mov eax, dword ptr [esp + 0x24]
// 0055f1a9  884c2411             mov byte ptr [esp + 0x11], cl
// 0055f1ad  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0055f1b0  8d4c01ff             lea ecx, [ecx + eax - 1]
// 0055f1b4  88542413             mov byte ptr [esp + 0x13], dl
// 0055f1b8  8d44f0ff             lea eax, [eax + esi*8 - 1]
// 0055f1bc  85f6                 test esi, esi
// 0055f1be  767f                 jbe 0x55f23f
// 0055f1c0  8bfe                 mov edi, esi
// 0055f1c2  8a542420             mov dl, byte ptr [esp + 0x20]
// 0055f1c6  3851fb               cmp byte ptr [ecx - 5], dl
// 0055f1c9  7535                 jne 0x55f200
// 0055f1cb  8a542410             mov dl, byte ptr [esp + 0x10]
// 0055f1cf  3851fc               cmp byte ptr [ecx - 4], dl
// 0055f1d2  752c                 jne 0x55f200
// 0055f1d4  8a54240f             mov dl, byte ptr [esp + 0xf]
// 0055f1d8  3851fd               cmp byte ptr [ecx - 3], dl
// 0055f1db  7523                 jne 0x55f200
// 0055f1dd  8a542411             mov dl, byte ptr [esp + 0x11]
// 0055f1e1  3851fe               cmp byte ptr [ecx - 2], dl
// 0055f1e4  751a                 jne 0x55f200
// 0055f1e6  8a542412             mov dl, byte ptr [esp + 0x12]
// 0055f1ea  3851ff               cmp byte ptr [ecx - 1], dl
// 0055f1ed  7511                 jne 0x55f200
// 0055f1ef  8a542413             mov dl, byte ptr [esp + 0x13]
// 0055f1f3  3811                 cmp byte ptr [ecx], dl
// 0055f1f5  7509                 jne 0x55f200
// 0055f1f7  c60000               mov byte ptr [eax], 0
// 0055f1fa  48                   dec eax
// 0055f1fb  c60000               mov byte ptr [eax], 0
// 0055f1fe  eb07                 jmp 0x55f207
// 0055f200  c600ff               mov byte ptr [eax], 0xff
// 0055f203  48                   dec eax
// 0055f204  c600ff               mov byte ptr [eax], 0xff
// 0055f207  0fb611               movzx edx, byte ptr [ecx]
// 0055f20a  8850ff               mov byte ptr [eax - 1], dl
// 0055f20d  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0055f211  48                   dec eax
// 0055f212  49                   dec ecx
// 0055f213  8850ff               mov byte ptr [eax - 1], dl
// 0055f216  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0055f21a  48                   dec eax
// 0055f21b  49                   dec ecx
// 0055f21c  8850ff               mov byte ptr [eax - 1], dl
// 0055f21f  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0055f223  48                   dec eax
// 0055f224  49                   dec ecx
// 0055f225  48                   dec eax
// 0055f226  8810                 mov byte ptr [eax], dl
// 0055f228  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0055f22c  49                   dec ecx
// 0055f22d  48                   dec eax
// 0055f22e  8810                 mov byte ptr [eax], dl
// 0055f230  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0055f234  49                   dec ecx
// 0055f235  48                   dec eax
// 0055f236  8810                 mov byte ptr [eax], dl
// 0055f238  48                   dec eax
// 0055f239  49                   dec ecx
// 0055f23a  83ef01               sub edi, 1
// 0055f23d  7583                 jne 0x55f1c2
// 0055f23f  8a4309               mov al, byte ptr [ebx + 9]
// 0055f242  02c0                 add al, al
// 0055f244  02c0                 add al, al
// 0055f246  88430b               mov byte ptr [ebx + 0xb], al
// 0055f249  3c08                 cmp al, 8
// 0055f24b  c6430806             mov byte ptr [ebx + 8], 6
// 0055f24f  c6430a04             mov byte ptr [ebx + 0xa], 4
// 0055f253  0fb6c0               movzx eax, al
// 0055f256  7210                 jb 0x55f268
// 0055f258  c1e803               shr eax, 3
// 0055f25b  0fafc6               imul eax, esi
// 0055f25e  5f                   pop edi
// 0055f25f  5e                   pop esi
// 0055f260  894304               mov dword ptr [ebx + 4], eax
// 0055f263  5b                   pop ebx
// 0055f264  83c410               add esp, 0x10
// 0055f267  c3                   ret 
// 0055f268  0fafc6               imul eax, esi
// 0055f26b  83c007               add eax, 7
// 0055f26e  5f                   pop edi
// 0055f26f  c1e803               shr eax, 3
// 0055f272  5e                   pop esi
// 0055f273  894304               mov dword ptr [ebx + 4], eax
// 0055f276  5b                   pop ebx
// 0055f277  83c410               add esp, 0x10
// 0055f27a  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_do_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
