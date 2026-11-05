// from server: 100% by auto
// roc 2010-06 00567570  unit: seg_00560000  size: 583 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00567570
//
// 00567570  53                   push ebx
// 00567571  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00567575  55                   push ebp
// 00567576  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0056757a  8a5508               mov dl, byte ptr [ebp + 8]
// 0056757d  56                   push esi
// 0056757e  8b742414             mov esi, dword ptr [esp + 0x14]
// 00567582  57                   push edi
// 00567583  8b7d00               mov edi, dword ptr [ebp]
// 00567586  8bc6                 mov eax, esi
// 00567588  8bce                 mov ecx, esi
// 0056758a  80fa02               cmp dl, 2
// 0056758d  7415                 je 0x5675a4
// 0056758f  80fa06               cmp dl, 6
// 00567592  0f853e010000         jne 0x5676d6
// 00567598  f7c300004000         test ebx, 0x400000
// 0056759e  0f8432010000         je 0x5676d6
// 005675a4  807d0a04             cmp byte ptr [ebp + 0xa], 4
// 005675a8  0f8528010000         jne 0x5676d6
// 005675ae  807d0908             cmp byte ptr [ebp + 9], 8
// 005675b2  757d                 jne 0x567631
// 005675b4  84db                 test bl, bl
// 005675b6  793f                 jns 0x5675f7
// 005675b8  8d5603               lea edx, [esi + 3]
// 005675bb  8d4604               lea eax, [esi + 4]
// 005675be  83ff01               cmp edi, 1
// 005675c1  765b                 jbe 0x56761e
// 005675c3  8d77ff               lea esi, [edi - 1]
// 005675c6  0fb608               movzx ecx, byte ptr [eax]
// 005675c9  880a                 mov byte ptr [edx], cl
// 005675cb  0fb64801             movzx ecx, byte ptr [eax + 1]
// 005675cf  40                   inc eax
// 005675d0  42                   inc edx
// 005675d1  880a                 mov byte ptr [edx], cl
// 005675d3  0fb64801             movzx ecx, byte ptr [eax + 1]
// 005675d7  40                   inc eax
// 005675d8  42                   inc edx
// 005675d9  880a                 mov byte ptr [edx], cl
// 005675db  42                   inc edx
// 005675dc  83c002               add eax, 2
// 005675df  83ee01               sub esi, 1
// 005675e2  75e2                 jne 0x5675c6
// 005675e4  8d047f               lea eax, [edi + edi*2]
// 005675e7  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 005675eb  894504               mov dword ptr [ebp + 4], eax
// 005675ee  c6450a03             mov byte ptr [ebp + 0xa], 3
// 005675f2  e9af010000           jmp 0x5677a6
// 005675f7  85ff                 test edi, edi
// 005675f9  7623                 jbe 0x56761e
// 005675fb  8bf7                 mov esi, edi
// 005675fd  8d4900               lea ecx, [ecx]
// 00567600  0fb65001             movzx edx, byte ptr [eax + 1]
// 00567604  40                   inc eax
// 00567605  8811                 mov byte ptr [ecx], dl
// 00567607  0fb65001             movzx edx, byte ptr [eax + 1]
// 0056760b  40                   inc eax
// 0056760c  41                   inc ecx
// 0056760d  8811                 mov byte ptr [ecx], dl
// 0056760f  0fb65001             movzx edx, byte ptr [eax + 1]
// 00567613  40                   inc eax
// 00567614  41                   inc ecx
// 00567615  8811                 mov byte ptr [ecx], dl
// 00567617  41                   inc ecx
// 00567618  40                   inc eax
// 00567619  83ee01               sub esi, 1
// 0056761c  75e2                 jne 0x567600
// 0056761e  8d047f               lea eax, [edi + edi*2]
// 00567621  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 00567625  894504               mov dword ptr [ebp + 4], eax
// 00567628  c6450a03             mov byte ptr [ebp + 0xa], 3
// 0056762c  e975010000           jmp 0x5677a6
// 00567631  84db                 test bl, bl
// 00567633  794c                 jns 0x567681
// 00567635  8d5608               lea edx, [esi + 8]
// 00567638  8d4606               lea eax, [esi + 6]
// 0056763b  83ff01               cmp edi, 1
// 0056763e  0f867d000000         jbe 0x5676c1
// 00567644  8d77ff               lea esi, [edi - 1]
// 00567647  0fb60a               movzx ecx, byte ptr [edx]
// 0056764a  8808                 mov byte ptr [eax], cl
// 0056764c  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00567650  42                   inc edx
// 00567651  884801               mov byte ptr [eax + 1], cl
// 00567654  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00567658  40                   inc eax
// 00567659  42                   inc edx
// 0056765a  884801               mov byte ptr [eax + 1], cl
// 0056765d  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00567661  40                   inc eax
// 00567662  42                   inc edx
// 00567663  40                   inc eax
// 00567664  8808                 mov byte ptr [eax], cl
// 00567666  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0056766a  42                   inc edx
// 0056766b  40                   inc eax
// 0056766c  8808                 mov byte ptr [eax], cl
// 0056766e  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00567672  42                   inc edx
// 00567673  40                   inc eax
// 00567674  8808                 mov byte ptr [eax], cl
// 00567676  40                   inc eax
// 00567677  83c203               add edx, 3
// 0056767a  83ee01               sub esi, 1
// 0056767d  75c8                 jne 0x567647
// 0056767f  eb40                 jmp 0x5676c1
// 00567681  85ff                 test edi, edi
// 00567683  763c                 jbe 0x5676c1
// 00567685  8bf7                 mov esi, edi
// 00567687  0fb65002             movzx edx, byte ptr [eax + 2]
// 0056768b  8811                 mov byte ptr [ecx], dl
// 0056768d  83c002               add eax, 2
// 00567690  0fb65001             movzx edx, byte ptr [eax + 1]
// 00567694  40                   inc eax
// 00567695  885101               mov byte ptr [ecx + 1], dl
// 00567698  0fb65001             movzx edx, byte ptr [eax + 1]
// 0056769c  41                   inc ecx
// 0056769d  40                   inc eax
// 0056769e  885101               mov byte ptr [ecx + 1], dl
// 005676a1  0fb65001             movzx edx, byte ptr [eax + 1]
// 005676a5  41                   inc ecx
// 005676a6  40                   inc eax
// 005676a7  41                   inc ecx
// 005676a8  8811                 mov byte ptr [ecx], dl
// 005676aa  0fb65001             movzx edx, byte ptr [eax + 1]
// 005676ae  40                   inc eax
// 005676af  41                   inc ecx
// 005676b0  8811                 mov byte ptr [ecx], dl
// 005676b2  0fb65001             movzx edx, byte ptr [eax + 1]
// 005676b6  40                   inc eax
// 005676b7  41                   inc ecx
// 005676b8  8811                 mov byte ptr [ecx], dl
// 005676ba  41                   inc ecx
// 005676bb  40                   inc eax
// 005676bc  83ee01               sub esi, 1
// 005676bf  75c6                 jne 0x567687
// 005676c1  8d047f               lea eax, [edi + edi*2]
// 005676c4  03c0                 add eax, eax
// 005676c6  c6450b30             mov byte ptr [ebp + 0xb], 0x30
// 005676ca  894504               mov dword ptr [ebp + 4], eax
// 005676cd  c6450a03             mov byte ptr [ebp + 0xa], 3
// 005676d1  e9d0000000           jmp 0x5677a6
// 005676d6  84d2                 test dl, dl
// 005676d8  7415                 je 0x5676ef
// 005676da  80fa04               cmp dl, 4
// 005676dd  0f85c3000000         jne 0x5677a6
// 005676e3  f7c300004000         test ebx, 0x400000
// 005676e9  0f84c3000000         je 0x5677b2
// 005676ef  807d0a02             cmp byte ptr [ebp + 0xa], 2
// 005676f3  0f85ad000000         jne 0x5677a6
// 005676f9  b208                 mov dl, 8
// 005676fb  385509               cmp byte ptr [ebp + 9], dl
// 005676fe  7549                 jne 0x567749
// 00567700  84db                 test bl, bl
// 00567702  7925                 jns 0x567729
// 00567704  85ff                 test edi, edi
// 00567706  7639                 jbe 0x567741
// 00567708  8bf7                 mov esi, edi
// 0056770a  8d9b00000000         lea ebx, [ebx]
// 00567710  8a18                 mov bl, byte ptr [eax]
// 00567712  8819                 mov byte ptr [ecx], bl
// 00567714  41                   inc ecx
// 00567715  83c002               add eax, 2
// 00567718  83ee01               sub esi, 1
// 0056771b  75f3                 jne 0x567710
// 0056771d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00567721  88550b               mov byte ptr [ebp + 0xb], dl
// 00567724  897d04               mov dword ptr [ebp + 4], edi
// 00567727  eb79                 jmp 0x5677a2
// 00567729  85ff                 test edi, edi
// 0056772b  7614                 jbe 0x567741
// 0056772d  8bf7                 mov esi, edi
// 0056772f  90                   nop 
// 00567730  8a5801               mov bl, byte ptr [eax + 1]
// 00567733  40                   inc eax
// 00567734  8819                 mov byte ptr [ecx], bl
// 00567736  41                   inc ecx
// 00567737  40                   inc eax
// 00567738  83ee01               sub esi, 1
// 0056773b  75f3                 jne 0x567730
// 0056773d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00567741  88550b               mov byte ptr [ebp + 0xb], dl
// 00567744  897d04               mov dword ptr [ebp + 4], edi
// 00567747  eb59                 jmp 0x5677a2
// 00567749  84db                 test bl, bl
// 0056774b  792b                 jns 0x567778
// 0056774d  8d5604               lea edx, [esi + 4]
// 00567750  8d4602               lea eax, [esi + 2]
// 00567753  83ff01               cmp edi, 1
// 00567756  7640                 jbe 0x567798
// 00567758  8d77ff               lea esi, [edi - 1]
// 0056775b  eb03                 jmp 0x567760
// 0056775d  8d4900               lea ecx, [ecx]
// 00567760  0fb60a               movzx ecx, byte ptr [edx]
// 00567763  8808                 mov byte ptr [eax], cl
// 00567765  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00567769  42                   inc edx
// 0056776a  40                   inc eax
// 0056776b  8808                 mov byte ptr [eax], cl
// 0056776d  40                   inc eax
// 0056776e  83c203               add edx, 3
// 00567771  83ee01               sub esi, 1
// 00567774  75ea                 jne 0x567760
// 00567776  eb20                 jmp 0x567798
// 00567778  85ff                 test edi, edi
// 0056777a  761c                 jbe 0x567798
// 0056777c  8bf7                 mov esi, edi
// 0056777e  8bff                 mov edi, edi
// 00567780  0fb65002             movzx edx, byte ptr [eax + 2]
// 00567784  83c002               add eax, 2
// 00567787  8811                 mov byte ptr [ecx], dl
// 00567789  0fb65001             movzx edx, byte ptr [eax + 1]
// 0056778d  40                   inc eax
// 0056778e  41                   inc ecx
// 0056778f  8811                 mov byte ptr [ecx], dl
// 00567791  41                   inc ecx
// 00567792  40                   inc eax
// 00567793  83ee01               sub esi, 1
// 00567796  75e8                 jne 0x567780
// 00567798  8d043f               lea eax, [edi + edi]
// 0056779b  c6450b10             mov byte ptr [ebp + 0xb], 0x10
// 0056779f  894504               mov dword ptr [ebp + 4], eax
// 005677a2  c6450a01             mov byte ptr [ebp + 0xa], 1
// 005677a6  f7c300004000         test ebx, 0x400000
// 005677ac  7404                 je 0x5677b2
// 005677ae  806508fb             and byte ptr [ebp + 8], 0xfb
// 005677b2  5f                   pop edi
// 005677b3  5e                   pop esi
// 005677b4  5d                   pop ebp
// 005677b5  5b                   pop ebx
// 005677b6  c3                   ret 
// library libpng-1.2.8/pngtrans.c (function _png_do_strip_filler)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.8 pngtrans.c
