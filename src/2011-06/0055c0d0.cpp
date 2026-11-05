// from server: 100% by auto
// roc 2011-06 0055c0d0  unit: seg_00550000  size: 583 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055c0d0
//
// 0055c0d0  53                   push ebx
// 0055c0d1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0055c0d5  55                   push ebp
// 0055c0d6  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0055c0da  8a5508               mov dl, byte ptr [ebp + 8]
// 0055c0dd  56                   push esi
// 0055c0de  8b742414             mov esi, dword ptr [esp + 0x14]
// 0055c0e2  57                   push edi
// 0055c0e3  8b7d00               mov edi, dword ptr [ebp]
// 0055c0e6  8bc6                 mov eax, esi
// 0055c0e8  8bce                 mov ecx, esi
// 0055c0ea  80fa02               cmp dl, 2
// 0055c0ed  7415                 je 0x55c104
// 0055c0ef  80fa06               cmp dl, 6
// 0055c0f2  0f853e010000         jne 0x55c236
// 0055c0f8  f7c300004000         test ebx, 0x400000
// 0055c0fe  0f8432010000         je 0x55c236
// 0055c104  807d0a04             cmp byte ptr [ebp + 0xa], 4
// 0055c108  0f8528010000         jne 0x55c236
// 0055c10e  807d0908             cmp byte ptr [ebp + 9], 8
// 0055c112  757d                 jne 0x55c191
// 0055c114  84db                 test bl, bl
// 0055c116  793f                 jns 0x55c157
// 0055c118  8d5603               lea edx, [esi + 3]
// 0055c11b  8d4604               lea eax, [esi + 4]
// 0055c11e  83ff01               cmp edi, 1
// 0055c121  765b                 jbe 0x55c17e
// 0055c123  8d77ff               lea esi, [edi - 1]
// 0055c126  0fb608               movzx ecx, byte ptr [eax]
// 0055c129  880a                 mov byte ptr [edx], cl
// 0055c12b  0fb64801             movzx ecx, byte ptr [eax + 1]
// 0055c12f  40                   inc eax
// 0055c130  42                   inc edx
// 0055c131  880a                 mov byte ptr [edx], cl
// 0055c133  0fb64801             movzx ecx, byte ptr [eax + 1]
// 0055c137  40                   inc eax
// 0055c138  42                   inc edx
// 0055c139  880a                 mov byte ptr [edx], cl
// 0055c13b  42                   inc edx
// 0055c13c  83c002               add eax, 2
// 0055c13f  83ee01               sub esi, 1
// 0055c142  75e2                 jne 0x55c126
// 0055c144  8d047f               lea eax, [edi + edi*2]
// 0055c147  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 0055c14b  894504               mov dword ptr [ebp + 4], eax
// 0055c14e  c6450a03             mov byte ptr [ebp + 0xa], 3
// 0055c152  e9af010000           jmp 0x55c306
// 0055c157  85ff                 test edi, edi
// 0055c159  7623                 jbe 0x55c17e
// 0055c15b  8bf7                 mov esi, edi
// 0055c15d  8d4900               lea ecx, [ecx]
// 0055c160  0fb65001             movzx edx, byte ptr [eax + 1]
// 0055c164  40                   inc eax
// 0055c165  8811                 mov byte ptr [ecx], dl
// 0055c167  0fb65001             movzx edx, byte ptr [eax + 1]
// 0055c16b  40                   inc eax
// 0055c16c  41                   inc ecx
// 0055c16d  8811                 mov byte ptr [ecx], dl
// 0055c16f  0fb65001             movzx edx, byte ptr [eax + 1]
// 0055c173  40                   inc eax
// 0055c174  41                   inc ecx
// 0055c175  8811                 mov byte ptr [ecx], dl
// 0055c177  41                   inc ecx
// 0055c178  40                   inc eax
// 0055c179  83ee01               sub esi, 1
// 0055c17c  75e2                 jne 0x55c160
// 0055c17e  8d047f               lea eax, [edi + edi*2]
// 0055c181  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 0055c185  894504               mov dword ptr [ebp + 4], eax
// 0055c188  c6450a03             mov byte ptr [ebp + 0xa], 3
// 0055c18c  e975010000           jmp 0x55c306
// 0055c191  84db                 test bl, bl
// 0055c193  794c                 jns 0x55c1e1
// 0055c195  8d5608               lea edx, [esi + 8]
// 0055c198  8d4606               lea eax, [esi + 6]
// 0055c19b  83ff01               cmp edi, 1
// 0055c19e  0f867d000000         jbe 0x55c221
// 0055c1a4  8d77ff               lea esi, [edi - 1]
// 0055c1a7  0fb60a               movzx ecx, byte ptr [edx]
// 0055c1aa  8808                 mov byte ptr [eax], cl
// 0055c1ac  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0055c1b0  42                   inc edx
// 0055c1b1  884801               mov byte ptr [eax + 1], cl
// 0055c1b4  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0055c1b8  40                   inc eax
// 0055c1b9  42                   inc edx
// 0055c1ba  884801               mov byte ptr [eax + 1], cl
// 0055c1bd  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0055c1c1  40                   inc eax
// 0055c1c2  42                   inc edx
// 0055c1c3  40                   inc eax
// 0055c1c4  8808                 mov byte ptr [eax], cl
// 0055c1c6  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0055c1ca  42                   inc edx
// 0055c1cb  40                   inc eax
// 0055c1cc  8808                 mov byte ptr [eax], cl
// 0055c1ce  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0055c1d2  42                   inc edx
// 0055c1d3  40                   inc eax
// 0055c1d4  8808                 mov byte ptr [eax], cl
// 0055c1d6  40                   inc eax
// 0055c1d7  83c203               add edx, 3
// 0055c1da  83ee01               sub esi, 1
// 0055c1dd  75c8                 jne 0x55c1a7
// 0055c1df  eb40                 jmp 0x55c221
// 0055c1e1  85ff                 test edi, edi
// 0055c1e3  763c                 jbe 0x55c221
// 0055c1e5  8bf7                 mov esi, edi
// 0055c1e7  0fb65002             movzx edx, byte ptr [eax + 2]
// 0055c1eb  8811                 mov byte ptr [ecx], dl
// 0055c1ed  83c002               add eax, 2
// 0055c1f0  0fb65001             movzx edx, byte ptr [eax + 1]
// 0055c1f4  40                   inc eax
// 0055c1f5  885101               mov byte ptr [ecx + 1], dl
// 0055c1f8  0fb65001             movzx edx, byte ptr [eax + 1]
// 0055c1fc  41                   inc ecx
// 0055c1fd  40                   inc eax
// 0055c1fe  885101               mov byte ptr [ecx + 1], dl
// 0055c201  0fb65001             movzx edx, byte ptr [eax + 1]
// 0055c205  41                   inc ecx
// 0055c206  40                   inc eax
// 0055c207  41                   inc ecx
// 0055c208  8811                 mov byte ptr [ecx], dl
// 0055c20a  0fb65001             movzx edx, byte ptr [eax + 1]
// 0055c20e  40                   inc eax
// 0055c20f  41                   inc ecx
// 0055c210  8811                 mov byte ptr [ecx], dl
// 0055c212  0fb65001             movzx edx, byte ptr [eax + 1]
// 0055c216  40                   inc eax
// 0055c217  41                   inc ecx
// 0055c218  8811                 mov byte ptr [ecx], dl
// 0055c21a  41                   inc ecx
// 0055c21b  40                   inc eax
// 0055c21c  83ee01               sub esi, 1
// 0055c21f  75c6                 jne 0x55c1e7
// 0055c221  8d047f               lea eax, [edi + edi*2]
// 0055c224  03c0                 add eax, eax
// 0055c226  c6450b30             mov byte ptr [ebp + 0xb], 0x30
// 0055c22a  894504               mov dword ptr [ebp + 4], eax
// 0055c22d  c6450a03             mov byte ptr [ebp + 0xa], 3
// 0055c231  e9d0000000           jmp 0x55c306
// 0055c236  84d2                 test dl, dl
// 0055c238  7415                 je 0x55c24f
// 0055c23a  80fa04               cmp dl, 4
// 0055c23d  0f85c3000000         jne 0x55c306
// 0055c243  f7c300004000         test ebx, 0x400000
// 0055c249  0f84c3000000         je 0x55c312
// 0055c24f  807d0a02             cmp byte ptr [ebp + 0xa], 2
// 0055c253  0f85ad000000         jne 0x55c306
// 0055c259  b208                 mov dl, 8
// 0055c25b  385509               cmp byte ptr [ebp + 9], dl
// 0055c25e  7549                 jne 0x55c2a9
// 0055c260  84db                 test bl, bl
// 0055c262  7925                 jns 0x55c289
// 0055c264  85ff                 test edi, edi
// 0055c266  7639                 jbe 0x55c2a1
// 0055c268  8bf7                 mov esi, edi
// 0055c26a  8d9b00000000         lea ebx, [ebx]
// 0055c270  8a18                 mov bl, byte ptr [eax]
// 0055c272  8819                 mov byte ptr [ecx], bl
// 0055c274  41                   inc ecx
// 0055c275  83c002               add eax, 2
// 0055c278  83ee01               sub esi, 1
// 0055c27b  75f3                 jne 0x55c270
// 0055c27d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0055c281  88550b               mov byte ptr [ebp + 0xb], dl
// 0055c284  897d04               mov dword ptr [ebp + 4], edi
// 0055c287  eb79                 jmp 0x55c302
// 0055c289  85ff                 test edi, edi
// 0055c28b  7614                 jbe 0x55c2a1
// 0055c28d  8bf7                 mov esi, edi
// 0055c28f  90                   nop 
// 0055c290  8a5801               mov bl, byte ptr [eax + 1]
// 0055c293  40                   inc eax
// 0055c294  8819                 mov byte ptr [ecx], bl
// 0055c296  41                   inc ecx
// 0055c297  40                   inc eax
// 0055c298  83ee01               sub esi, 1
// 0055c29b  75f3                 jne 0x55c290
// 0055c29d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0055c2a1  88550b               mov byte ptr [ebp + 0xb], dl
// 0055c2a4  897d04               mov dword ptr [ebp + 4], edi
// 0055c2a7  eb59                 jmp 0x55c302
// 0055c2a9  84db                 test bl, bl
// 0055c2ab  792b                 jns 0x55c2d8
// 0055c2ad  8d5604               lea edx, [esi + 4]
// 0055c2b0  8d4602               lea eax, [esi + 2]
// 0055c2b3  83ff01               cmp edi, 1
// 0055c2b6  7640                 jbe 0x55c2f8
// 0055c2b8  8d77ff               lea esi, [edi - 1]
// 0055c2bb  eb03                 jmp 0x55c2c0
// 0055c2bd  8d4900               lea ecx, [ecx]
// 0055c2c0  0fb60a               movzx ecx, byte ptr [edx]
// 0055c2c3  8808                 mov byte ptr [eax], cl
// 0055c2c5  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0055c2c9  42                   inc edx
// 0055c2ca  40                   inc eax
// 0055c2cb  8808                 mov byte ptr [eax], cl
// 0055c2cd  40                   inc eax
// 0055c2ce  83c203               add edx, 3
// 0055c2d1  83ee01               sub esi, 1
// 0055c2d4  75ea                 jne 0x55c2c0
// 0055c2d6  eb20                 jmp 0x55c2f8
// 0055c2d8  85ff                 test edi, edi
// 0055c2da  761c                 jbe 0x55c2f8
// 0055c2dc  8bf7                 mov esi, edi
// 0055c2de  8bff                 mov edi, edi
// 0055c2e0  0fb65002             movzx edx, byte ptr [eax + 2]
// 0055c2e4  83c002               add eax, 2
// 0055c2e7  8811                 mov byte ptr [ecx], dl
// 0055c2e9  0fb65001             movzx edx, byte ptr [eax + 1]
// 0055c2ed  40                   inc eax
// 0055c2ee  41                   inc ecx
// 0055c2ef  8811                 mov byte ptr [ecx], dl
// 0055c2f1  41                   inc ecx
// 0055c2f2  40                   inc eax
// 0055c2f3  83ee01               sub esi, 1
// 0055c2f6  75e8                 jne 0x55c2e0
// 0055c2f8  8d043f               lea eax, [edi + edi]
// 0055c2fb  c6450b10             mov byte ptr [ebp + 0xb], 0x10
// 0055c2ff  894504               mov dword ptr [ebp + 4], eax
// 0055c302  c6450a01             mov byte ptr [ebp + 0xa], 1
// 0055c306  f7c300004000         test ebx, 0x400000
// 0055c30c  7404                 je 0x55c312
// 0055c30e  806508fb             and byte ptr [ebp + 8], 0xfb
// 0055c312  5f                   pop edi
// 0055c313  5e                   pop esi
// 0055c314  5d                   pop ebp
// 0055c315  5b                   pop ebx
// 0055c316  c3                   ret 
// library libpng-1.2.8/pngtrans.c (function _png_do_strip_filler)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.8 pngtrans.c
