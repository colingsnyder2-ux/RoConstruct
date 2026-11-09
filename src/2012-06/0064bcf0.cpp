// from server: 100% by auto
// roc 2012-06 0064bcf0  unit: seg_00640000  size: 1035 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064bcf0
//
// 0064bcf0  83ec10               sub esp, 0x10
// 0064bcf3  53                   push ebx
// 0064bcf4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0064bcf8  8a4308               mov al, byte ptr [ebx + 8]
// 0064bcfb  56                   push esi
// 0064bcfc  8b33                 mov esi, dword ptr [ebx]
// 0064bcfe  57                   push edi
// 0064bcff  84c0                 test al, al
// 0064bd01  0f8562020000         jne 0x64bf69
// 0064bd07  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0064bd0b  85c9                 test ecx, ecx
// 0064bd0d  7406                 je 0x64bd15
// 0064bd0f  0fb75108             movzx edx, word ptr [ecx + 8]
// 0064bd13  eb0c                 jmp 0x64bd21
// 0064bd15  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0064bd1d  8b542414             mov edx, dword ptr [esp + 0x14]
// 0064bd21  8a4309               mov al, byte ptr [ebx + 9]
// 0064bd24  55                   push ebp
// 0064bd25  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0064bd29  3c08                 cmp al, 8
// 0064bd2b  0f8360010000         jae 0x64be91
// 0064bd31  0fb6c0               movzx eax, al
// 0064bd34  83e801               sub eax, 1
// 0064bd37  0f84ea000000         je 0x64be27
// 0064bd3d  83e801               sub eax, 1
// 0064bd40  7473                 je 0x64bdb5
// 0064bd42  83e802               sub eax, 2
// 0064bd45  0f8537010000         jne 0x64be82
// 0064bd4b  8bc2                 mov eax, edx
// 0064bd4d  83e00f               and eax, 0xf
// 0064bd50  8bc8                 mov ecx, eax
// 0064bd52  c1e104               shl ecx, 4
// 0064bd55  03c8                 add ecx, eax
// 0064bd57  0fb7d1               movzx edx, cx
// 0064bd5a  8d46ff               lea eax, [esi - 1]
// 0064bd5d  83e001               and eax, 1
// 0064bd60  03c0                 add eax, eax
// 0064bd62  89542418             mov dword ptr [esp + 0x18], edx
// 0064bd66  8d7eff               lea edi, [esi - 1]
// 0064bd69  d1ef                 shr edi, 1
// 0064bd6b  03c0                 add eax, eax
// 0064bd6d  ba04000000           mov edx, 4
// 0064bd72  03fd                 add edi, ebp
// 0064bd74  2bd0                 sub edx, eax
// 0064bd76  8d5c2eff             lea ebx, [esi + ebp - 1]
// 0064bd7a  85f6                 test esi, esi
// 0064bd7c  0f86f8000000         jbe 0x64be7a
// 0064bd82  8974241c             mov dword ptr [esp + 0x1c], esi
// 0064bd86  0fb607               movzx eax, byte ptr [edi]
// 0064bd89  8aca                 mov cl, dl
// 0064bd8b  d3e8                 shr eax, cl
// 0064bd8d  83e00f               and eax, 0xf
// 0064bd90  8ac8                 mov cl, al
// 0064bd92  c0e104               shl cl, 4
// 0064bd95  0ac8                 or cl, al
// 0064bd97  880b                 mov byte ptr [ebx], cl
// 0064bd99  83fa04               cmp edx, 4
// 0064bd9c  7505                 jne 0x64bda3
// 0064bd9e  33d2                 xor edx, edx
// 0064bda0  4f                   dec edi
// 0064bda1  eb05                 jmp 0x64bda8
// 0064bda3  ba04000000           mov edx, 4
// 0064bda8  4b                   dec ebx
// 0064bda9  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0064bdae  75d6                 jne 0x64bd86
// 0064bdb0  e9c5000000           jmp 0x64be7a
// 0064bdb5  83e203               and edx, 3
// 0064bdb8  6bd255               imul edx, edx, 0x55
// 0064bdbb  0fb7d2               movzx edx, dx
// 0064bdbe  89542418             mov dword ptr [esp + 0x18], edx
// 0064bdc2  8d46ff               lea eax, [esi - 1]
// 0064bdc5  83e003               and eax, 3
// 0064bdc8  8d7eff               lea edi, [esi - 1]
// 0064bdcb  ba03000000           mov edx, 3
// 0064bdd0  c1ef02               shr edi, 2
// 0064bdd3  2bd0                 sub edx, eax
// 0064bdd5  03fd                 add edi, ebp
// 0064bdd7  03d2                 add edx, edx
// 0064bdd9  8d5c2eff             lea ebx, [esi + ebp - 1]
// 0064bddd  85f6                 test esi, esi
// 0064bddf  0f8695000000         jbe 0x64be7a
// 0064bde5  8974241c             mov dword ptr [esp + 0x1c], esi
// 0064bde9  8da42400000000       lea esp, [esp]
// 0064bdf0  0fb607               movzx eax, byte ptr [edi]
// 0064bdf3  8aca                 mov cl, dl
// 0064bdf5  d3e8                 shr eax, cl
// 0064bdf7  83e003               and eax, 3
// 0064bdfa  8ac8                 mov cl, al
// 0064bdfc  02c9                 add cl, cl
// 0064bdfe  02c9                 add cl, cl
// 0064be00  0ac8                 or cl, al
// 0064be02  02c9                 add cl, cl
// 0064be04  02c9                 add cl, cl
// 0064be06  0ac8                 or cl, al
// 0064be08  02c9                 add cl, cl
// 0064be0a  02c9                 add cl, cl
// 0064be0c  0ac8                 or cl, al
// 0064be0e  880b                 mov byte ptr [ebx], cl
// 0064be10  83fa06               cmp edx, 6
// 0064be13  7505                 jne 0x64be1a
// 0064be15  33d2                 xor edx, edx
// 0064be17  4f                   dec edi
// 0064be18  eb03                 jmp 0x64be1d
// 0064be1a  83c202               add edx, 2
// 0064be1d  4b                   dec ebx
// 0064be1e  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0064be23  75cb                 jne 0x64bdf0
// 0064be25  eb53                 jmp 0x64be7a
// 0064be27  83e201               and edx, 1
// 0064be2a  69d2ff000000         imul edx, edx, 0xff
// 0064be30  0fb7d2               movzx edx, dx
// 0064be33  8d7eff               lea edi, [esi - 1]
// 0064be36  8d4eff               lea ecx, [esi - 1]
// 0064be39  c1ef03               shr edi, 3
// 0064be3c  83e107               and ecx, 7
// 0064be3f  b807000000           mov eax, 7
// 0064be44  03fd                 add edi, ebp
// 0064be46  2bc1                 sub eax, ecx
// 0064be48  89542418             mov dword ptr [esp + 0x18], edx
// 0064be4c  8d542eff             lea edx, [esi + ebp - 1]
// 0064be50  85f6                 test esi, esi
// 0064be52  762a                 jbe 0x64be7e
// 0064be54  8974241c             mov dword ptr [esp + 0x1c], esi
// 0064be58  8a1f                 mov bl, byte ptr [edi]
// 0064be5a  8ac8                 mov cl, al
// 0064be5c  d2eb                 shr bl, cl
// 0064be5e  80e301               and bl, 1
// 0064be61  f6db                 neg bl
// 0064be63  1adb                 sbb bl, bl
// 0064be65  881a                 mov byte ptr [edx], bl
// 0064be67  83f807               cmp eax, 7
// 0064be6a  7505                 jne 0x64be71
// 0064be6c  33c0                 xor eax, eax
// 0064be6e  4f                   dec edi
// 0064be6f  eb01                 jmp 0x64be72
// 0064be71  40                   inc eax
// 0064be72  4a                   dec edx
// 0064be73  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0064be78  75de                 jne 0x64be58
// 0064be7a  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0064be7e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0064be82  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0064be86  c6430908             mov byte ptr [ebx + 9], 8
// 0064be8a  c6430b08             mov byte ptr [ebx + 0xb], 8
// 0064be8e  897304               mov dword ptr [ebx + 4], esi
// 0064be91  85c9                 test ecx, ecx
// 0064be93  0f84c8000000         je 0x64bf61
// 0064be99  8a4309               mov al, byte ptr [ebx + 9]
// 0064be9c  3c08                 cmp al, 8
// 0064be9e  7533                 jne 0x64bed3
// 0064bea0  81e2ff000000         and edx, 0xff
// 0064bea6  8d4c2eff             lea ecx, [esi + ebp - 1]
// 0064beaa  8d4475ff             lea eax, [ebp + esi*2 - 1]
// 0064beae  85f6                 test esi, esi
// 0064beb0  767b                 jbe 0x64bf2d
// 0064beb2  8bfe                 mov edi, esi
// 0064beb4  660fb619             movzx bx, byte ptr [ecx]
// 0064beb8  663bda               cmp bx, dx
// 0064bebb  7505                 jne 0x64bec2
// 0064bebd  c60000               mov byte ptr [eax], 0
// 0064bec0  eb03                 jmp 0x64bec5
// 0064bec2  c600ff               mov byte ptr [eax], 0xff
// 0064bec5  8a19                 mov bl, byte ptr [ecx]
// 0064bec7  48                   dec eax
// 0064bec8  8818                 mov byte ptr [eax], bl
// 0064beca  48                   dec eax
// 0064becb  49                   dec ecx
// 0064becc  83ef01               sub edi, 1
// 0064becf  75e3                 jne 0x64beb4
// 0064bed1  eb56                 jmp 0x64bf29
// 0064bed3  3c10                 cmp al, 0x10
// 0064bed5  7556                 jne 0x64bf2d
// 0064bed7  8b442424             mov eax, dword ptr [esp + 0x24]
// 0064bedb  8b4004               mov eax, dword ptr [eax + 4]
// 0064bede  8bda                 mov ebx, edx
// 0064bee0  c1eb08               shr ebx, 8
// 0064bee3  8d4c28ff             lea ecx, [eax + ebp - 1]
// 0064bee7  885c2413             mov byte ptr [esp + 0x13], bl
// 0064beeb  8d4445ff             lea eax, [ebp + eax*2 - 1]
// 0064beef  85f6                 test esi, esi
// 0064bef1  7636                 jbe 0x64bf29
// 0064bef3  8bfe                 mov edi, esi
// 0064bef5  eb04                 jmp 0x64befb
// 0064bef7  8a5c2413             mov bl, byte ptr [esp + 0x13]
// 0064befb  3859ff               cmp byte ptr [ecx - 1], bl
// 0064befe  750d                 jne 0x64bf0d
// 0064bf00  3811                 cmp byte ptr [ecx], dl
// 0064bf02  7509                 jne 0x64bf0d
// 0064bf04  c60000               mov byte ptr [eax], 0
// 0064bf07  48                   dec eax
// 0064bf08  c60000               mov byte ptr [eax], 0
// 0064bf0b  eb07                 jmp 0x64bf14
// 0064bf0d  c600ff               mov byte ptr [eax], 0xff
// 0064bf10  48                   dec eax
// 0064bf11  c600ff               mov byte ptr [eax], 0xff
// 0064bf14  0fb619               movzx ebx, byte ptr [ecx]
// 0064bf17  48                   dec eax
// 0064bf18  8818                 mov byte ptr [eax], bl
// 0064bf1a  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0064bf1e  49                   dec ecx
// 0064bf1f  48                   dec eax
// 0064bf20  8818                 mov byte ptr [eax], bl
// 0064bf22  48                   dec eax
// 0064bf23  49                   dec ecx
// 0064bf24  83ef01               sub edi, 1
// 0064bf27  75ce                 jne 0x64bef7
// 0064bf29  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0064bf2d  8a4309               mov al, byte ptr [ebx + 9]
// 0064bf30  02c0                 add al, al
// 0064bf32  88430b               mov byte ptr [ebx + 0xb], al
// 0064bf35  3c08                 cmp al, 8
// 0064bf37  c6430804             mov byte ptr [ebx + 8], 4
// 0064bf3b  c6430a02             mov byte ptr [ebx + 0xa], 2
// 0064bf3f  0fb6c0               movzx eax, al
// 0064bf42  7211                 jb 0x64bf55
// 0064bf44  c1e803               shr eax, 3
// 0064bf47  0fafc6               imul eax, esi
// 0064bf4a  5d                   pop ebp
// 0064bf4b  5f                   pop edi
// 0064bf4c  5e                   pop esi
// 0064bf4d  894304               mov dword ptr [ebx + 4], eax
// 0064bf50  5b                   pop ebx
// 0064bf51  83c410               add esp, 0x10
// 0064bf54  c3                   ret 
// 0064bf55  0fafc6               imul eax, esi
// 0064bf58  83c007               add eax, 7
// 0064bf5b  c1e803               shr eax, 3
// 0064bf5e  894304               mov dword ptr [ebx + 4], eax
// 0064bf61  5d                   pop ebp
// 0064bf62  5f                   pop edi
// 0064bf63  5e                   pop esi
// 0064bf64  5b                   pop ebx
// 0064bf65  83c410               add esp, 0x10
// 0064bf68  c3                   ret 
// 0064bf69  3c02                 cmp al, 2
// 0064bf6b  75f5                 jne 0x64bf62
// 0064bf6d  8b442428             mov eax, dword ptr [esp + 0x28]
// 0064bf71  85c0                 test eax, eax
// 0064bf73  74ed                 je 0x64bf62
// 0064bf75  8a4b09               mov cl, byte ptr [ebx + 9]
// 0064bf78  80f908               cmp cl, 8
// 0064bf7b  7577                 jne 0x64bff4
// 0064bf7d  8a4802               mov cl, byte ptr [eax + 2]
// 0064bf80  8a5004               mov dl, byte ptr [eax + 4]
// 0064bf83  8a4006               mov al, byte ptr [eax + 6]
// 0064bf86  884c2420             mov byte ptr [esp + 0x20], cl
// 0064bf8a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0064bf8e  8854240f             mov byte ptr [esp + 0xf], dl
// 0064bf92  8b5304               mov edx, dword ptr [ebx + 4]
// 0064bf95  8d540aff             lea edx, [edx + ecx - 1]
// 0064bf99  88442410             mov byte ptr [esp + 0x10], al
// 0064bf9d  8d4cb1ff             lea ecx, [ecx + esi*4 - 1]
// 0064bfa1  85f6                 test esi, esi
// 0064bfa3  0f8616010000         jbe 0x64c0bf
// 0064bfa9  8bfe                 mov edi, esi
// 0064bfab  eb03                 jmp 0x64bfb0
// 0064bfad  8d4900               lea ecx, [ecx]
// 0064bfb0  8a442420             mov al, byte ptr [esp + 0x20]
// 0064bfb4  3842fe               cmp byte ptr [edx - 2], al
// 0064bfb7  7516                 jne 0x64bfcf
// 0064bfb9  8a44240f             mov al, byte ptr [esp + 0xf]
// 0064bfbd  3842ff               cmp byte ptr [edx - 1], al
// 0064bfc0  750d                 jne 0x64bfcf
// 0064bfc2  8a442410             mov al, byte ptr [esp + 0x10]
// 0064bfc6  3802                 cmp byte ptr [edx], al
// 0064bfc8  7505                 jne 0x64bfcf
// 0064bfca  c60100               mov byte ptr [ecx], 0
// 0064bfcd  eb03                 jmp 0x64bfd2
// 0064bfcf  c601ff               mov byte ptr [ecx], 0xff
// 0064bfd2  0fb602               movzx eax, byte ptr [edx]
// 0064bfd5  49                   dec ecx
// 0064bfd6  8801                 mov byte ptr [ecx], al
// 0064bfd8  0fb642ff             movzx eax, byte ptr [edx - 1]
// 0064bfdc  4a                   dec edx
// 0064bfdd  49                   dec ecx
// 0064bfde  8801                 mov byte ptr [ecx], al
// 0064bfe0  0fb642ff             movzx eax, byte ptr [edx - 1]
// 0064bfe4  4a                   dec edx
// 0064bfe5  49                   dec ecx
// 0064bfe6  8801                 mov byte ptr [ecx], al
// 0064bfe8  49                   dec ecx
// 0064bfe9  4a                   dec edx
// 0064bfea  83ef01               sub edi, 1
// 0064bfed  75c1                 jne 0x64bfb0
// 0064bfef  e9cb000000           jmp 0x64c0bf
// 0064bff4  80f910               cmp cl, 0x10
// 0064bff7  0f85c2000000         jne 0x64c0bf
// 0064bffd  0fb64803             movzx ecx, byte ptr [eax + 3]
// 0064c001  0fb65005             movzx edx, byte ptr [eax + 5]
// 0064c005  884c2420             mov byte ptr [esp + 0x20], cl
// 0064c009  0fb64807             movzx ecx, byte ptr [eax + 7]
// 0064c00d  8854240f             mov byte ptr [esp + 0xf], dl
// 0064c011  0fb65002             movzx edx, byte ptr [eax + 2]
// 0064c015  884c2412             mov byte ptr [esp + 0x12], cl
// 0064c019  0fb64804             movzx ecx, byte ptr [eax + 4]
// 0064c01d  88542410             mov byte ptr [esp + 0x10], dl
// 0064c021  0fb65006             movzx edx, byte ptr [eax + 6]
// 0064c025  8b442424             mov eax, dword ptr [esp + 0x24]
// 0064c029  884c2411             mov byte ptr [esp + 0x11], cl
// 0064c02d  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0064c030  8d4c01ff             lea ecx, [ecx + eax - 1]
// 0064c034  88542413             mov byte ptr [esp + 0x13], dl
// 0064c038  8d44f0ff             lea eax, [eax + esi*8 - 1]
// 0064c03c  85f6                 test esi, esi
// 0064c03e  767f                 jbe 0x64c0bf
// 0064c040  8bfe                 mov edi, esi
// 0064c042  8a542420             mov dl, byte ptr [esp + 0x20]
// 0064c046  3851fb               cmp byte ptr [ecx - 5], dl
// 0064c049  7535                 jne 0x64c080
// 0064c04b  8a542410             mov dl, byte ptr [esp + 0x10]
// 0064c04f  3851fc               cmp byte ptr [ecx - 4], dl
// 0064c052  752c                 jne 0x64c080
// 0064c054  8a54240f             mov dl, byte ptr [esp + 0xf]
// 0064c058  3851fd               cmp byte ptr [ecx - 3], dl
// 0064c05b  7523                 jne 0x64c080
// 0064c05d  8a542411             mov dl, byte ptr [esp + 0x11]
// 0064c061  3851fe               cmp byte ptr [ecx - 2], dl
// 0064c064  751a                 jne 0x64c080
// 0064c066  8a542412             mov dl, byte ptr [esp + 0x12]
// 0064c06a  3851ff               cmp byte ptr [ecx - 1], dl
// 0064c06d  7511                 jne 0x64c080
// 0064c06f  8a542413             mov dl, byte ptr [esp + 0x13]
// 0064c073  3811                 cmp byte ptr [ecx], dl
// 0064c075  7509                 jne 0x64c080
// 0064c077  c60000               mov byte ptr [eax], 0
// 0064c07a  48                   dec eax
// 0064c07b  c60000               mov byte ptr [eax], 0
// 0064c07e  eb07                 jmp 0x64c087
// 0064c080  c600ff               mov byte ptr [eax], 0xff
// 0064c083  48                   dec eax
// 0064c084  c600ff               mov byte ptr [eax], 0xff
// 0064c087  0fb611               movzx edx, byte ptr [ecx]
// 0064c08a  8850ff               mov byte ptr [eax - 1], dl
// 0064c08d  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0064c091  48                   dec eax
// 0064c092  49                   dec ecx
// 0064c093  8850ff               mov byte ptr [eax - 1], dl
// 0064c096  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0064c09a  48                   dec eax
// 0064c09b  49                   dec ecx
// 0064c09c  8850ff               mov byte ptr [eax - 1], dl
// 0064c09f  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0064c0a3  48                   dec eax
// 0064c0a4  49                   dec ecx
// 0064c0a5  48                   dec eax
// 0064c0a6  8810                 mov byte ptr [eax], dl
// 0064c0a8  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0064c0ac  49                   dec ecx
// 0064c0ad  48                   dec eax
// 0064c0ae  8810                 mov byte ptr [eax], dl
// 0064c0b0  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 0064c0b4  49                   dec ecx
// 0064c0b5  48                   dec eax
// 0064c0b6  8810                 mov byte ptr [eax], dl
// 0064c0b8  48                   dec eax
// 0064c0b9  49                   dec ecx
// 0064c0ba  83ef01               sub edi, 1
// 0064c0bd  7583                 jne 0x64c042
// 0064c0bf  8a4309               mov al, byte ptr [ebx + 9]
// 0064c0c2  02c0                 add al, al
// 0064c0c4  02c0                 add al, al
// 0064c0c6  88430b               mov byte ptr [ebx + 0xb], al
// 0064c0c9  3c08                 cmp al, 8
// 0064c0cb  c6430806             mov byte ptr [ebx + 8], 6
// 0064c0cf  c6430a04             mov byte ptr [ebx + 0xa], 4
// 0064c0d3  0fb6c0               movzx eax, al
// 0064c0d6  7210                 jb 0x64c0e8
// 0064c0d8  c1e803               shr eax, 3
// 0064c0db  0fafc6               imul eax, esi
// 0064c0de  5f                   pop edi
// 0064c0df  5e                   pop esi
// 0064c0e0  894304               mov dword ptr [ebx + 4], eax
// 0064c0e3  5b                   pop ebx
// 0064c0e4  83c410               add esp, 0x10
// 0064c0e7  c3                   ret 
// 0064c0e8  0fafc6               imul eax, esi
// 0064c0eb  83c007               add eax, 7
// 0064c0ee  5f                   pop edi
// 0064c0ef  c1e803               shr eax, 3
// 0064c0f2  5e                   pop esi
// 0064c0f3  894304               mov dword ptr [ebx + 4], eax
// 0064c0f6  5b                   pop ebx
// 0064c0f7  83c410               add esp, 0x10
// 0064c0fa  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_do_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
