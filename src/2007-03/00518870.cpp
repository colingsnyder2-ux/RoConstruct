// from server: 100% by auto
// roc 2007-03 00518870  unit: seg_00510000  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00518870
//
// 00518870  8b442404             mov eax, dword ptr [esp + 4]
// 00518874  8a4808               mov cl, byte ptr [eax + 8]
// 00518877  80f906               cmp cl, 6
// 0051887a  53                   push ebx
// 0051887b  56                   push esi
// 0051887c  0f85d5000000         jne 0x518957
// 00518882  80780908             cmp byte ptr [eax + 9], 8
// 00518886  754e                 jne 0x5188d6
// 00518888  8b10                 mov edx, dword ptr [eax]
// 0051888a  85d2                 test edx, edx
// 0051888c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00518890  8bc8                 mov ecx, eax
// 00518892  0f8643010000         jbe 0x5189db
// 00518898  8bf2                 mov esi, edx
// 0051889a  8d9b00000000         lea ebx, [ebx]
// 005188a0  8a10                 mov dl, byte ptr [eax]
// 005188a2  0fb65801             movzx ebx, byte ptr [eax + 1]
// 005188a6  83c001               add eax, 1
// 005188a9  8819                 mov byte ptr [ecx], bl
// 005188ab  0fb65801             movzx ebx, byte ptr [eax + 1]
// 005188af  83c001               add eax, 1
// 005188b2  83c101               add ecx, 1
// 005188b5  8819                 mov byte ptr [ecx], bl
// 005188b7  0fb65801             movzx ebx, byte ptr [eax + 1]
// 005188bb  83c001               add eax, 1
// 005188be  83c101               add ecx, 1
// 005188c1  8819                 mov byte ptr [ecx], bl
// 005188c3  83c101               add ecx, 1
// 005188c6  8811                 mov byte ptr [ecx], dl
// 005188c8  83c001               add eax, 1
// 005188cb  83c101               add ecx, 1
// 005188ce  83ee01               sub esi, 1
// 005188d1  75cd                 jne 0x5188a0
// 005188d3  5e                   pop esi
// 005188d4  5b                   pop ebx
// 005188d5  c3                   ret 
// 005188d6  8b30                 mov esi, dword ptr [eax]
// 005188d8  85f6                 test esi, esi
// 005188da  8b442410             mov eax, dword ptr [esp + 0x10]
// 005188de  8bc8                 mov ecx, eax
// 005188e0  0f86f5000000         jbe 0x5189db
// 005188e6  8a10                 mov dl, byte ptr [eax]
// 005188e8  0fb65801             movzx ebx, byte ptr [eax + 1]
// 005188ec  83c001               add eax, 1
// 005188ef  83c001               add eax, 1
// 005188f2  885c240d             mov byte ptr [esp + 0xd], bl
// 005188f6  0fb618               movzx ebx, byte ptr [eax]
// 005188f9  8819                 mov byte ptr [ecx], bl
// 005188fb  0fb65801             movzx ebx, byte ptr [eax + 1]
// 005188ff  885901               mov byte ptr [ecx + 1], bl
// 00518902  83c001               add eax, 1
// 00518905  0fb65801             movzx ebx, byte ptr [eax + 1]
// 00518909  83c101               add ecx, 1
// 0051890c  885901               mov byte ptr [ecx + 1], bl
// 0051890f  83c001               add eax, 1
// 00518912  0fb65801             movzx ebx, byte ptr [eax + 1]
// 00518916  83c101               add ecx, 1
// 00518919  83c001               add eax, 1
// 0051891c  885901               mov byte ptr [ecx + 1], bl
// 0051891f  0fb65801             movzx ebx, byte ptr [eax + 1]
// 00518923  83c101               add ecx, 1
// 00518926  83c001               add eax, 1
// 00518929  83c101               add ecx, 1
// 0051892c  8819                 mov byte ptr [ecx], bl
// 0051892e  0fb65801             movzx ebx, byte ptr [eax + 1]
// 00518932  83c001               add eax, 1
// 00518935  83c101               add ecx, 1
// 00518938  8819                 mov byte ptr [ecx], bl
// 0051893a  83c101               add ecx, 1
// 0051893d  8811                 mov byte ptr [ecx], dl
// 0051893f  0fb654240d           movzx edx, byte ptr [esp + 0xd]
// 00518944  83c101               add ecx, 1
// 00518947  8811                 mov byte ptr [ecx], dl
// 00518949  83c001               add eax, 1
// 0051894c  83c101               add ecx, 1
// 0051894f  83ee01               sub esi, 1
// 00518952  7592                 jne 0x5188e6
// 00518954  5e                   pop esi
// 00518955  5b                   pop ebx
// 00518956  c3                   ret 
// 00518957  80f904               cmp cl, 4
// 0051895a  757f                 jne 0x5189db
// 0051895c  80780908             cmp byte ptr [eax + 9], 8
// 00518960  752b                 jne 0x51898d
// 00518962  8b10                 mov edx, dword ptr [eax]
// 00518964  85d2                 test edx, edx
// 00518966  8b442410             mov eax, dword ptr [esp + 0x10]
// 0051896a  8bc8                 mov ecx, eax
// 0051896c  766d                 jbe 0x5189db
// 0051896e  8bf2                 mov esi, edx
// 00518970  8a10                 mov dl, byte ptr [eax]
// 00518972  8a5801               mov bl, byte ptr [eax + 1]
// 00518975  83c001               add eax, 1
// 00518978  8819                 mov byte ptr [ecx], bl
// 0051897a  83c101               add ecx, 1
// 0051897d  8811                 mov byte ptr [ecx], dl
// 0051897f  83c001               add eax, 1
// 00518982  83c101               add ecx, 1
// 00518985  83ee01               sub esi, 1
// 00518988  75e6                 jne 0x518970
// 0051898a  5e                   pop esi
// 0051898b  5b                   pop ebx
// 0051898c  c3                   ret 
// 0051898d  8b30                 mov esi, dword ptr [eax]
// 0051898f  85f6                 test esi, esi
// 00518991  8b442410             mov eax, dword ptr [esp + 0x10]
// 00518995  8bc8                 mov ecx, eax
// 00518997  7642                 jbe 0x5189db
// 00518999  8da42400000000       lea esp, [esp]
// 005189a0  8a10                 mov dl, byte ptr [eax]
// 005189a2  0fb65801             movzx ebx, byte ptr [eax + 1]
// 005189a6  83c001               add eax, 1
// 005189a9  83c001               add eax, 1
// 005189ac  885c240d             mov byte ptr [esp + 0xd], bl
// 005189b0  0fb618               movzx ebx, byte ptr [eax]
// 005189b3  8819                 mov byte ptr [ecx], bl
// 005189b5  0fb65801             movzx ebx, byte ptr [eax + 1]
// 005189b9  83c001               add eax, 1
// 005189bc  83c101               add ecx, 1
// 005189bf  8819                 mov byte ptr [ecx], bl
// 005189c1  83c101               add ecx, 1
// 005189c4  8811                 mov byte ptr [ecx], dl
// 005189c6  0fb654240d           movzx edx, byte ptr [esp + 0xd]
// 005189cb  83c101               add ecx, 1
// 005189ce  8811                 mov byte ptr [ecx], dl
// 005189d0  83c001               add eax, 1
// 005189d3  83c101               add ecx, 1
// 005189d6  83ee01               sub esi, 1
// 005189d9  75c5                 jne 0x5189a0
// 005189db  5e                   pop esi
// 005189dc  5b                   pop ebx
// 005189dd  c3                   ret 
// library libpng-1.2.7/pngwtran.c (function _png_do_write_swap_alpha)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwtran.c
