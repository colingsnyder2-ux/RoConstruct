// from server: 100% by auto
// roc 2007-03 0050ed10  unit: seg_00500000  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050ed10
//
// 0050ed10  8b442404             mov eax, dword ptr [esp + 4]
// 0050ed14  8a4808               mov cl, byte ptr [eax + 8]
// 0050ed17  80f906               cmp cl, 6
// 0050ed1a  8b10                 mov edx, dword ptr [eax]
// 0050ed1c  56                   push esi
// 0050ed1d  7559                 jne 0x50ed78
// 0050ed1f  80780908             cmp byte ptr [eax + 9], 8
// 0050ed23  8b4004               mov eax, dword ptr [eax + 4]
// 0050ed26  7521                 jne 0x50ed49
// 0050ed28  0344240c             add eax, dword ptr [esp + 0xc]
// 0050ed2c  85d2                 test edx, edx
// 0050ed2e  0f86ab000000         jbe 0x50eddf
// 0050ed34  83e801               sub eax, 1
// 0050ed37  80c9ff               or cl, 0xff
// 0050ed3a  2a08                 sub cl, byte ptr [eax]
// 0050ed3c  83e803               sub eax, 3
// 0050ed3f  83ea01               sub edx, 1
// 0050ed42  884803               mov byte ptr [eax + 3], cl
// 0050ed45  75ed                 jne 0x50ed34
// 0050ed47  5e                   pop esi
// 0050ed48  c3                   ret 
// 0050ed49  0344240c             add eax, dword ptr [esp + 0xc]
// 0050ed4d  85d2                 test edx, edx
// 0050ed4f  0f868a000000         jbe 0x50eddf
// 0050ed55  8bf2                 mov esi, edx
// 0050ed57  83e801               sub eax, 1
// 0050ed5a  80caff               or dl, 0xff
// 0050ed5d  2a10                 sub dl, byte ptr [eax]
// 0050ed5f  8bc8                 mov ecx, eax
// 0050ed61  8811                 mov byte ptr [ecx], dl
// 0050ed63  83e801               sub eax, 1
// 0050ed66  80caff               or dl, 0xff
// 0050ed69  2a10                 sub dl, byte ptr [eax]
// 0050ed6b  83e806               sub eax, 6
// 0050ed6e  83ee01               sub esi, 1
// 0050ed71  8851ff               mov byte ptr [ecx - 1], dl
// 0050ed74  75e1                 jne 0x50ed57
// 0050ed76  5e                   pop esi
// 0050ed77  c3                   ret 
// 0050ed78  80f904               cmp cl, 4
// 0050ed7b  7562                 jne 0x50eddf
// 0050ed7d  80780908             cmp byte ptr [eax + 9], 8
// 0050ed81  8b4004               mov eax, dword ptr [eax + 4]
// 0050ed84  752b                 jne 0x50edb1
// 0050ed86  0344240c             add eax, dword ptr [esp + 0xc]
// 0050ed8a  85d2                 test edx, edx
// 0050ed8c  8bc8                 mov ecx, eax
// 0050ed8e  764f                 jbe 0x50eddf
// 0050ed90  8bf2                 mov esi, edx
// 0050ed92  83e801               sub eax, 1
// 0050ed95  80caff               or dl, 0xff
// 0050ed98  2a10                 sub dl, byte ptr [eax]
// 0050ed9a  83e901               sub ecx, 1
// 0050ed9d  8811                 mov byte ptr [ecx], dl
// 0050ed9f  8a50ff               mov dl, byte ptr [eax - 1]
// 0050eda2  83e801               sub eax, 1
// 0050eda5  83e901               sub ecx, 1
// 0050eda8  83ee01               sub esi, 1
// 0050edab  8811                 mov byte ptr [ecx], dl
// 0050edad  75e3                 jne 0x50ed92
// 0050edaf  5e                   pop esi
// 0050edb0  c3                   ret 
// 0050edb1  0344240c             add eax, dword ptr [esp + 0xc]
// 0050edb5  85d2                 test edx, edx
// 0050edb7  7626                 jbe 0x50eddf
// 0050edb9  8bf2                 mov esi, edx
// 0050edbb  eb03                 jmp 0x50edc0
// 0050edbd  8d4900               lea ecx, [ecx]
// 0050edc0  83e801               sub eax, 1
// 0050edc3  80caff               or dl, 0xff
// 0050edc6  2a10                 sub dl, byte ptr [eax]
// 0050edc8  8bc8                 mov ecx, eax
// 0050edca  8811                 mov byte ptr [ecx], dl
// 0050edcc  83e801               sub eax, 1
// 0050edcf  80caff               or dl, 0xff
// 0050edd2  2a10                 sub dl, byte ptr [eax]
// 0050edd4  83e802               sub eax, 2
// 0050edd7  83ee01               sub esi, 1
// 0050edda  8851ff               mov byte ptr [ecx - 1], dl
// 0050eddd  75e1                 jne 0x50edc0
// 0050eddf  5e                   pop esi
// 0050ede0  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_read_invert_alpha)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
