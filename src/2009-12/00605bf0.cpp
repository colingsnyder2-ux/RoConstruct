// from server: 100% by auto
// roc 2009-12 00605bf0  unit: seg_00600000  size: 583 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00605bf0
//
// 00605bf0  53                   push ebx
// 00605bf1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00605bf5  55                   push ebp
// 00605bf6  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00605bfa  8a5508               mov dl, byte ptr [ebp + 8]
// 00605bfd  56                   push esi
// 00605bfe  8b742414             mov esi, dword ptr [esp + 0x14]
// 00605c02  57                   push edi
// 00605c03  8b7d00               mov edi, dword ptr [ebp]
// 00605c06  8bc6                 mov eax, esi
// 00605c08  8bce                 mov ecx, esi
// 00605c0a  80fa02               cmp dl, 2
// 00605c0d  7415                 je 0x605c24
// 00605c0f  80fa06               cmp dl, 6
// 00605c12  0f853e010000         jne 0x605d56
// 00605c18  f7c300004000         test ebx, 0x400000
// 00605c1e  0f8432010000         je 0x605d56
// 00605c24  807d0a04             cmp byte ptr [ebp + 0xa], 4
// 00605c28  0f8528010000         jne 0x605d56
// 00605c2e  807d0908             cmp byte ptr [ebp + 9], 8
// 00605c32  757d                 jne 0x605cb1
// 00605c34  84db                 test bl, bl
// 00605c36  793f                 jns 0x605c77
// 00605c38  8d5603               lea edx, [esi + 3]
// 00605c3b  8d4604               lea eax, [esi + 4]
// 00605c3e  83ff01               cmp edi, 1
// 00605c41  765b                 jbe 0x605c9e
// 00605c43  8d77ff               lea esi, [edi - 1]
// 00605c46  0fb608               movzx ecx, byte ptr [eax]
// 00605c49  880a                 mov byte ptr [edx], cl
// 00605c4b  0fb64801             movzx ecx, byte ptr [eax + 1]
// 00605c4f  40                   inc eax
// 00605c50  42                   inc edx
// 00605c51  880a                 mov byte ptr [edx], cl
// 00605c53  0fb64801             movzx ecx, byte ptr [eax + 1]
// 00605c57  40                   inc eax
// 00605c58  42                   inc edx
// 00605c59  880a                 mov byte ptr [edx], cl
// 00605c5b  42                   inc edx
// 00605c5c  83c002               add eax, 2
// 00605c5f  83ee01               sub esi, 1
// 00605c62  75e2                 jne 0x605c46
// 00605c64  8d047f               lea eax, [edi + edi*2]
// 00605c67  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 00605c6b  894504               mov dword ptr [ebp + 4], eax
// 00605c6e  c6450a03             mov byte ptr [ebp + 0xa], 3
// 00605c72  e9af010000           jmp 0x605e26
// 00605c77  85ff                 test edi, edi
// 00605c79  7623                 jbe 0x605c9e
// 00605c7b  8bf7                 mov esi, edi
// 00605c7d  8d4900               lea ecx, [ecx]
// 00605c80  0fb65001             movzx edx, byte ptr [eax + 1]
// 00605c84  40                   inc eax
// 00605c85  8811                 mov byte ptr [ecx], dl
// 00605c87  0fb65001             movzx edx, byte ptr [eax + 1]
// 00605c8b  40                   inc eax
// 00605c8c  41                   inc ecx
// 00605c8d  8811                 mov byte ptr [ecx], dl
// 00605c8f  0fb65001             movzx edx, byte ptr [eax + 1]
// 00605c93  40                   inc eax
// 00605c94  41                   inc ecx
// 00605c95  8811                 mov byte ptr [ecx], dl
// 00605c97  41                   inc ecx
// 00605c98  40                   inc eax
// 00605c99  83ee01               sub esi, 1
// 00605c9c  75e2                 jne 0x605c80
// 00605c9e  8d047f               lea eax, [edi + edi*2]
// 00605ca1  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 00605ca5  894504               mov dword ptr [ebp + 4], eax
// 00605ca8  c6450a03             mov byte ptr [ebp + 0xa], 3
// 00605cac  e975010000           jmp 0x605e26
// 00605cb1  84db                 test bl, bl
// 00605cb3  794c                 jns 0x605d01
// 00605cb5  8d5608               lea edx, [esi + 8]
// 00605cb8  8d4606               lea eax, [esi + 6]
// 00605cbb  83ff01               cmp edi, 1
// 00605cbe  0f867d000000         jbe 0x605d41
// 00605cc4  8d77ff               lea esi, [edi - 1]
// 00605cc7  0fb60a               movzx ecx, byte ptr [edx]
// 00605cca  8808                 mov byte ptr [eax], cl
// 00605ccc  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00605cd0  42                   inc edx
// 00605cd1  884801               mov byte ptr [eax + 1], cl
// 00605cd4  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00605cd8  40                   inc eax
// 00605cd9  42                   inc edx
// 00605cda  884801               mov byte ptr [eax + 1], cl
// 00605cdd  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00605ce1  40                   inc eax
// 00605ce2  42                   inc edx
// 00605ce3  40                   inc eax
// 00605ce4  8808                 mov byte ptr [eax], cl
// 00605ce6  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00605cea  42                   inc edx
// 00605ceb  40                   inc eax
// 00605cec  8808                 mov byte ptr [eax], cl
// 00605cee  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00605cf2  42                   inc edx
// 00605cf3  40                   inc eax
// 00605cf4  8808                 mov byte ptr [eax], cl
// 00605cf6  40                   inc eax
// 00605cf7  83c203               add edx, 3
// 00605cfa  83ee01               sub esi, 1
// 00605cfd  75c8                 jne 0x605cc7
// 00605cff  eb40                 jmp 0x605d41
// 00605d01  85ff                 test edi, edi
// 00605d03  763c                 jbe 0x605d41
// 00605d05  8bf7                 mov esi, edi
// 00605d07  0fb65002             movzx edx, byte ptr [eax + 2]
// 00605d0b  8811                 mov byte ptr [ecx], dl
// 00605d0d  83c002               add eax, 2
// 00605d10  0fb65001             movzx edx, byte ptr [eax + 1]
// 00605d14  40                   inc eax
// 00605d15  885101               mov byte ptr [ecx + 1], dl
// 00605d18  0fb65001             movzx edx, byte ptr [eax + 1]
// 00605d1c  41                   inc ecx
// 00605d1d  40                   inc eax
// 00605d1e  885101               mov byte ptr [ecx + 1], dl
// 00605d21  0fb65001             movzx edx, byte ptr [eax + 1]
// 00605d25  41                   inc ecx
// 00605d26  40                   inc eax
// 00605d27  41                   inc ecx
// 00605d28  8811                 mov byte ptr [ecx], dl
// 00605d2a  0fb65001             movzx edx, byte ptr [eax + 1]
// 00605d2e  40                   inc eax
// 00605d2f  41                   inc ecx
// 00605d30  8811                 mov byte ptr [ecx], dl
// 00605d32  0fb65001             movzx edx, byte ptr [eax + 1]
// 00605d36  40                   inc eax
// 00605d37  41                   inc ecx
// 00605d38  8811                 mov byte ptr [ecx], dl
// 00605d3a  41                   inc ecx
// 00605d3b  40                   inc eax
// 00605d3c  83ee01               sub esi, 1
// 00605d3f  75c6                 jne 0x605d07
// 00605d41  8d047f               lea eax, [edi + edi*2]
// 00605d44  03c0                 add eax, eax
// 00605d46  c6450b30             mov byte ptr [ebp + 0xb], 0x30
// 00605d4a  894504               mov dword ptr [ebp + 4], eax
// 00605d4d  c6450a03             mov byte ptr [ebp + 0xa], 3
// 00605d51  e9d0000000           jmp 0x605e26
// 00605d56  84d2                 test dl, dl
// 00605d58  7415                 je 0x605d6f
// 00605d5a  80fa04               cmp dl, 4
// 00605d5d  0f85c3000000         jne 0x605e26
// 00605d63  f7c300004000         test ebx, 0x400000
// 00605d69  0f84c3000000         je 0x605e32
// 00605d6f  807d0a02             cmp byte ptr [ebp + 0xa], 2
// 00605d73  0f85ad000000         jne 0x605e26
// 00605d79  b208                 mov dl, 8
// 00605d7b  385509               cmp byte ptr [ebp + 9], dl
// 00605d7e  7549                 jne 0x605dc9
// 00605d80  84db                 test bl, bl
// 00605d82  7925                 jns 0x605da9
// 00605d84  85ff                 test edi, edi
// 00605d86  7639                 jbe 0x605dc1
// 00605d88  8bf7                 mov esi, edi
// 00605d8a  8d9b00000000         lea ebx, [ebx]
// 00605d90  8a18                 mov bl, byte ptr [eax]
// 00605d92  8819                 mov byte ptr [ecx], bl
// 00605d94  41                   inc ecx
// 00605d95  83c002               add eax, 2
// 00605d98  83ee01               sub esi, 1
// 00605d9b  75f3                 jne 0x605d90
// 00605d9d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00605da1  88550b               mov byte ptr [ebp + 0xb], dl
// 00605da4  897d04               mov dword ptr [ebp + 4], edi
// 00605da7  eb79                 jmp 0x605e22
// 00605da9  85ff                 test edi, edi
// 00605dab  7614                 jbe 0x605dc1
// 00605dad  8bf7                 mov esi, edi
// 00605daf  90                   nop 
// 00605db0  8a5801               mov bl, byte ptr [eax + 1]
// 00605db3  40                   inc eax
// 00605db4  8819                 mov byte ptr [ecx], bl
// 00605db6  41                   inc ecx
// 00605db7  40                   inc eax
// 00605db8  83ee01               sub esi, 1
// 00605dbb  75f3                 jne 0x605db0
// 00605dbd  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00605dc1  88550b               mov byte ptr [ebp + 0xb], dl
// 00605dc4  897d04               mov dword ptr [ebp + 4], edi
// 00605dc7  eb59                 jmp 0x605e22
// 00605dc9  84db                 test bl, bl
// 00605dcb  792b                 jns 0x605df8
// 00605dcd  8d5604               lea edx, [esi + 4]
// 00605dd0  8d4602               lea eax, [esi + 2]
// 00605dd3  83ff01               cmp edi, 1
// 00605dd6  7640                 jbe 0x605e18
// 00605dd8  8d77ff               lea esi, [edi - 1]
// 00605ddb  eb03                 jmp 0x605de0
// 00605ddd  8d4900               lea ecx, [ecx]
// 00605de0  0fb60a               movzx ecx, byte ptr [edx]
// 00605de3  8808                 mov byte ptr [eax], cl
// 00605de5  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00605de9  42                   inc edx
// 00605dea  40                   inc eax
// 00605deb  8808                 mov byte ptr [eax], cl
// 00605ded  40                   inc eax
// 00605dee  83c203               add edx, 3
// 00605df1  83ee01               sub esi, 1
// 00605df4  75ea                 jne 0x605de0
// 00605df6  eb20                 jmp 0x605e18
// 00605df8  85ff                 test edi, edi
// 00605dfa  761c                 jbe 0x605e18
// 00605dfc  8bf7                 mov esi, edi
// 00605dfe  8bff                 mov edi, edi
// 00605e00  0fb65002             movzx edx, byte ptr [eax + 2]
// 00605e04  83c002               add eax, 2
// 00605e07  8811                 mov byte ptr [ecx], dl
// 00605e09  0fb65001             movzx edx, byte ptr [eax + 1]
// 00605e0d  40                   inc eax
// 00605e0e  41                   inc ecx
// 00605e0f  8811                 mov byte ptr [ecx], dl
// 00605e11  41                   inc ecx
// 00605e12  40                   inc eax
// 00605e13  83ee01               sub esi, 1
// 00605e16  75e8                 jne 0x605e00
// 00605e18  8d043f               lea eax, [edi + edi]
// 00605e1b  c6450b10             mov byte ptr [ebp + 0xb], 0x10
// 00605e1f  894504               mov dword ptr [ebp + 4], eax
// 00605e22  c6450a01             mov byte ptr [ebp + 0xa], 1
// 00605e26  f7c300004000         test ebx, 0x400000
// 00605e2c  7404                 je 0x605e32
// 00605e2e  806508fb             and byte ptr [ebp + 8], 0xfb
// 00605e32  5f                   pop edi
// 00605e33  5e                   pop esi
// 00605e34  5d                   pop ebp
// 00605e35  5b                   pop ebx
// 00605e36  c3                   ret 
// library libpng-1.2.8/pngtrans.c (function _png_do_strip_filler)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.8 pngtrans.c
