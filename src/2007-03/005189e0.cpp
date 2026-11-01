// from server: 100% by auto
// roc 2007-03 005189e0  unit: seg_00510000  size: 345 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005189e0
//
// 005189e0  8b442404             mov eax, dword ptr [esp + 4]
// 005189e4  8a4808               mov cl, byte ptr [eax + 8]
// 005189e7  80f906               cmp cl, 6
// 005189ea  56                   push esi
// 005189eb  0f85ce000000         jne 0x518abf
// 005189f1  8b10                 mov edx, dword ptr [eax]
// 005189f3  80780908             cmp byte ptr [eax + 9], 8
// 005189f7  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005189fb  8bc8                 mov ecx, eax
// 005189fd  7549                 jne 0x518a48
// 005189ff  85d2                 test edx, edx
// 00518a01  0f8630010000         jbe 0x518b37
// 00518a07  8bf2                 mov esi, edx
// 00518a09  8da42400000000       lea esp, [esp]
// 00518a10  0fb611               movzx edx, byte ptr [ecx]
// 00518a13  8810                 mov byte ptr [eax], dl
// 00518a15  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00518a19  83c101               add ecx, 1
// 00518a1c  885001               mov byte ptr [eax + 1], dl
// 00518a1f  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00518a23  83c001               add eax, 1
// 00518a26  83c101               add ecx, 1
// 00518a29  83c001               add eax, 1
// 00518a2c  8810                 mov byte ptr [eax], dl
// 00518a2e  83c101               add ecx, 1
// 00518a31  80caff               or dl, 0xff
// 00518a34  2a11                 sub dl, byte ptr [ecx]
// 00518a36  83c001               add eax, 1
// 00518a39  8810                 mov byte ptr [eax], dl
// 00518a3b  83c001               add eax, 1
// 00518a3e  83c101               add ecx, 1
// 00518a41  83ee01               sub esi, 1
// 00518a44  75ca                 jne 0x518a10
// 00518a46  5e                   pop esi
// 00518a47  c3                   ret 
// 00518a48  85d2                 test edx, edx
// 00518a4a  0f86e7000000         jbe 0x518b37
// 00518a50  8bf2                 mov esi, edx
// 00518a52  0fb611               movzx edx, byte ptr [ecx]
// 00518a55  8810                 mov byte ptr [eax], dl
// 00518a57  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00518a5b  885001               mov byte ptr [eax + 1], dl
// 00518a5e  83c101               add ecx, 1
// 00518a61  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00518a65  83c001               add eax, 1
// 00518a68  885001               mov byte ptr [eax + 1], dl
// 00518a6b  83c101               add ecx, 1
// 00518a6e  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00518a72  83c001               add eax, 1
// 00518a75  885001               mov byte ptr [eax + 1], dl
// 00518a78  83c101               add ecx, 1
// 00518a7b  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00518a7f  83c001               add eax, 1
// 00518a82  83c101               add ecx, 1
// 00518a85  885001               mov byte ptr [eax + 1], dl
// 00518a88  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00518a8c  83c001               add eax, 1
// 00518a8f  83c101               add ecx, 1
// 00518a92  885001               mov byte ptr [eax + 1], dl
// 00518a95  83c001               add eax, 1
// 00518a98  83c101               add ecx, 1
// 00518a9b  80caff               or dl, 0xff
// 00518a9e  2a11                 sub dl, byte ptr [ecx]
// 00518aa0  83c001               add eax, 1
// 00518aa3  8810                 mov byte ptr [eax], dl
// 00518aa5  83c101               add ecx, 1
// 00518aa8  80caff               or dl, 0xff
// 00518aab  2a11                 sub dl, byte ptr [ecx]
// 00518aad  83c001               add eax, 1
// 00518ab0  8810                 mov byte ptr [eax], dl
// 00518ab2  83c001               add eax, 1
// 00518ab5  83c101               add ecx, 1
// 00518ab8  83ee01               sub esi, 1
// 00518abb  7595                 jne 0x518a52
// 00518abd  5e                   pop esi
// 00518abe  c3                   ret 
// 00518abf  80f904               cmp cl, 4
// 00518ac2  7573                 jne 0x518b37
// 00518ac4  8b10                 mov edx, dword ptr [eax]
// 00518ac6  80780908             cmp byte ptr [eax + 9], 8
// 00518aca  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00518ace  8bc8                 mov ecx, eax
// 00518ad0  7524                 jne 0x518af6
// 00518ad2  85d2                 test edx, edx
// 00518ad4  7661                 jbe 0x518b37
// 00518ad6  8bf2                 mov esi, edx
// 00518ad8  8a11                 mov dl, byte ptr [ecx]
// 00518ada  8810                 mov byte ptr [eax], dl
// 00518adc  83c101               add ecx, 1
// 00518adf  80caff               or dl, 0xff
// 00518ae2  2a11                 sub dl, byte ptr [ecx]
// 00518ae4  83c001               add eax, 1
// 00518ae7  8810                 mov byte ptr [eax], dl
// 00518ae9  83c001               add eax, 1
// 00518aec  83c101               add ecx, 1
// 00518aef  83ee01               sub esi, 1
// 00518af2  75e4                 jne 0x518ad8
// 00518af4  5e                   pop esi
// 00518af5  c3                   ret 
// 00518af6  85d2                 test edx, edx
// 00518af8  763d                 jbe 0x518b37
// 00518afa  8bf2                 mov esi, edx
// 00518afc  8d642400             lea esp, [esp]
// 00518b00  0fb611               movzx edx, byte ptr [ecx]
// 00518b03  8810                 mov byte ptr [eax], dl
// 00518b05  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00518b09  83c101               add ecx, 1
// 00518b0c  885001               mov byte ptr [eax + 1], dl
// 00518b0f  83c001               add eax, 1
// 00518b12  83c101               add ecx, 1
// 00518b15  80caff               or dl, 0xff
// 00518b18  2a11                 sub dl, byte ptr [ecx]
// 00518b1a  83c001               add eax, 1
// 00518b1d  8810                 mov byte ptr [eax], dl
// 00518b1f  83c101               add ecx, 1
// 00518b22  80caff               or dl, 0xff
// 00518b25  2a11                 sub dl, byte ptr [ecx]
// 00518b27  83c001               add eax, 1
// 00518b2a  8810                 mov byte ptr [eax], dl
// 00518b2c  83c001               add eax, 1
// 00518b2f  83c101               add ecx, 1
// 00518b32  83ee01               sub esi, 1
// 00518b35  75c9                 jne 0x518b00
// 00518b37  5e                   pop esi
// 00518b38  c3                   ret 
// library libpng-1.2.7/pngwtran.c (function _png_do_write_invert_alpha)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwtran.c
