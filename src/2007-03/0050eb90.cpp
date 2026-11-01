// from server: 100% by auto
// roc 2007-03 0050eb90  unit: seg_00500000  size: 383 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050eb90
//
// 0050eb90  8b442404             mov eax, dword ptr [esp + 4]
// 0050eb94  8a4808               mov cl, byte ptr [eax + 8]
// 0050eb97  80f906               cmp cl, 6
// 0050eb9a  8b10                 mov edx, dword ptr [eax]
// 0050eb9c  53                   push ebx
// 0050eb9d  56                   push esi
// 0050eb9e  0f85df000000         jne 0x50ec83
// 0050eba4  80780908             cmp byte ptr [eax + 9], 8
// 0050eba8  8b4004               mov eax, dword ptr [eax + 4]
// 0050ebab  754b                 jne 0x50ebf8
// 0050ebad  03442410             add eax, dword ptr [esp + 0x10]
// 0050ebb1  85d2                 test edx, edx
// 0050ebb3  8bc8                 mov ecx, eax
// 0050ebb5  0f8651010000         jbe 0x50ed0c
// 0050ebbb  8bf2                 mov esi, edx
// 0050ebbd  8d4900               lea ecx, [ecx]
// 0050ebc0  8a50ff               mov dl, byte ptr [eax - 1]
// 0050ebc3  83e801               sub eax, 1
// 0050ebc6  0fb658ff             movzx ebx, byte ptr [eax - 1]
// 0050ebca  83e801               sub eax, 1
// 0050ebcd  8859ff               mov byte ptr [ecx - 1], bl
// 0050ebd0  0fb658ff             movzx ebx, byte ptr [eax - 1]
// 0050ebd4  83e901               sub ecx, 1
// 0050ebd7  83e801               sub eax, 1
// 0050ebda  83e901               sub ecx, 1
// 0050ebdd  8819                 mov byte ptr [ecx], bl
// 0050ebdf  0fb658ff             movzx ebx, byte ptr [eax - 1]
// 0050ebe3  83e801               sub eax, 1
// 0050ebe6  83e901               sub ecx, 1
// 0050ebe9  8819                 mov byte ptr [ecx], bl
// 0050ebeb  83e901               sub ecx, 1
// 0050ebee  83ee01               sub esi, 1
// 0050ebf1  8811                 mov byte ptr [ecx], dl
// 0050ebf3  75cb                 jne 0x50ebc0
// 0050ebf5  5e                   pop esi
// 0050ebf6  5b                   pop ebx
// 0050ebf7  c3                   ret 
// 0050ebf8  03442410             add eax, dword ptr [esp + 0x10]
// 0050ebfc  85d2                 test edx, edx
// 0050ebfe  8bc8                 mov ecx, eax
// 0050ec00  0f8606010000         jbe 0x50ed0c
// 0050ec06  8bf2                 mov esi, edx
// 0050ec08  eb06                 jmp 0x50ec10
// 0050ec0a  8d9b00000000         lea ebx, [ebx]
// 0050ec10  8a50ff               mov dl, byte ptr [eax - 1]
// 0050ec13  83e801               sub eax, 1
// 0050ec16  0fb658ff             movzx ebx, byte ptr [eax - 1]
// 0050ec1a  83e801               sub eax, 1
// 0050ec1d  83e801               sub eax, 1
// 0050ec20  885c240d             mov byte ptr [esp + 0xd], bl
// 0050ec24  0fb618               movzx ebx, byte ptr [eax]
// 0050ec27  8859ff               mov byte ptr [ecx - 1], bl
// 0050ec2a  0fb658ff             movzx ebx, byte ptr [eax - 1]
// 0050ec2e  83e901               sub ecx, 1
// 0050ec31  8859ff               mov byte ptr [ecx - 1], bl
// 0050ec34  83e801               sub eax, 1
// 0050ec37  0fb658ff             movzx ebx, byte ptr [eax - 1]
// 0050ec3b  83e901               sub ecx, 1
// 0050ec3e  8859ff               mov byte ptr [ecx - 1], bl
// 0050ec41  83e801               sub eax, 1
// 0050ec44  0fb658ff             movzx ebx, byte ptr [eax - 1]
// 0050ec48  83e901               sub ecx, 1
// 0050ec4b  83e801               sub eax, 1
// 0050ec4e  8859ff               mov byte ptr [ecx - 1], bl
// 0050ec51  0fb658ff             movzx ebx, byte ptr [eax - 1]
// 0050ec55  83e901               sub ecx, 1
// 0050ec58  83e801               sub eax, 1
// 0050ec5b  83e901               sub ecx, 1
// 0050ec5e  8819                 mov byte ptr [ecx], bl
// 0050ec60  0fb658ff             movzx ebx, byte ptr [eax - 1]
// 0050ec64  83e801               sub eax, 1
// 0050ec67  83e901               sub ecx, 1
// 0050ec6a  8819                 mov byte ptr [ecx], bl
// 0050ec6c  83e901               sub ecx, 1
// 0050ec6f  8811                 mov byte ptr [ecx], dl
// 0050ec71  0fb654240d           movzx edx, byte ptr [esp + 0xd]
// 0050ec76  83e901               sub ecx, 1
// 0050ec79  83ee01               sub esi, 1
// 0050ec7c  8811                 mov byte ptr [ecx], dl
// 0050ec7e  7590                 jne 0x50ec10
// 0050ec80  5e                   pop esi
// 0050ec81  5b                   pop ebx
// 0050ec82  c3                   ret 
// 0050ec83  80f904               cmp cl, 4
// 0050ec86  0f8580000000         jne 0x50ed0c
// 0050ec8c  80780908             cmp byte ptr [eax + 9], 8
// 0050ec90  8b4004               mov eax, dword ptr [eax + 4]
// 0050ec93  752a                 jne 0x50ecbf
// 0050ec95  03442410             add eax, dword ptr [esp + 0x10]
// 0050ec99  85d2                 test edx, edx
// 0050ec9b  8bc8                 mov ecx, eax
// 0050ec9d  766d                 jbe 0x50ed0c
// 0050ec9f  8bf2                 mov esi, edx
// 0050eca1  8a50ff               mov dl, byte ptr [eax - 1]
// 0050eca4  83e801               sub eax, 1
// 0050eca7  8a58ff               mov bl, byte ptr [eax - 1]
// 0050ecaa  83e801               sub eax, 1
// 0050ecad  83e901               sub ecx, 1
// 0050ecb0  8819                 mov byte ptr [ecx], bl
// 0050ecb2  83e901               sub ecx, 1
// 0050ecb5  83ee01               sub esi, 1
// 0050ecb8  8811                 mov byte ptr [ecx], dl
// 0050ecba  75e5                 jne 0x50eca1
// 0050ecbc  5e                   pop esi
// 0050ecbd  5b                   pop ebx
// 0050ecbe  c3                   ret 
// 0050ecbf  03442410             add eax, dword ptr [esp + 0x10]
// 0050ecc3  85d2                 test edx, edx
// 0050ecc5  8bc8                 mov ecx, eax
// 0050ecc7  7643                 jbe 0x50ed0c
// 0050ecc9  8bf2                 mov esi, edx
// 0050eccb  eb03                 jmp 0x50ecd0
// 0050eccd  8d4900               lea ecx, [ecx]
// 0050ecd0  8a50ff               mov dl, byte ptr [eax - 1]
// 0050ecd3  83e801               sub eax, 1
// 0050ecd6  0fb658ff             movzx ebx, byte ptr [eax - 1]
// 0050ecda  83e801               sub eax, 1
// 0050ecdd  83e801               sub eax, 1
// 0050ece0  885c240d             mov byte ptr [esp + 0xd], bl
// 0050ece4  0fb618               movzx ebx, byte ptr [eax]
// 0050ece7  83e901               sub ecx, 1
// 0050ecea  8819                 mov byte ptr [ecx], bl
// 0050ecec  0fb658ff             movzx ebx, byte ptr [eax - 1]
// 0050ecf0  83e801               sub eax, 1
// 0050ecf3  83e901               sub ecx, 1
// 0050ecf6  8819                 mov byte ptr [ecx], bl
// 0050ecf8  83e901               sub ecx, 1
// 0050ecfb  8811                 mov byte ptr [ecx], dl
// 0050ecfd  0fb654240d           movzx edx, byte ptr [esp + 0xd]
// 0050ed02  83e901               sub ecx, 1
// 0050ed05  83ee01               sub esi, 1
// 0050ed08  8811                 mov byte ptr [ecx], dl
// 0050ed0a  75c4                 jne 0x50ecd0
// 0050ed0c  5e                   pop esi
// 0050ed0d  5b                   pop ebx
// 0050ed0e  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_read_swap_alpha)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
