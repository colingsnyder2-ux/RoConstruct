// from server: 100% by auto
// roc 2009-06 0058e800  unit: seg_00580000  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058e800
//
// 0058e800  8b442404             mov eax, dword ptr [esp + 4]
// 0058e804  8a4808               mov cl, byte ptr [eax + 8]
// 0058e807  80f906               cmp cl, 6
// 0058e80a  7545                 jne 0x58e851
// 0058e80c  8b08                 mov ecx, dword ptr [eax]
// 0058e80e  80780908             cmp byte ptr [eax + 9], 8
// 0058e812  8b442408             mov eax, dword ptr [esp + 8]
// 0058e816  751a                 jne 0x58e832
// 0058e818  85c9                 test ecx, ecx
// 0058e81a  0f868a000000         jbe 0x58e8aa
// 0058e820  83c003               add eax, 3
// 0058e823  80caff               or dl, 0xff
// 0058e826  2a10                 sub dl, byte ptr [eax]
// 0058e828  40                   inc eax
// 0058e829  83e901               sub ecx, 1
// 0058e82c  8850ff               mov byte ptr [eax - 1], dl
// 0058e82f  75ef                 jne 0x58e820
// 0058e831  c3                   ret 
// 0058e832  85c9                 test ecx, ecx
// 0058e834  7674                 jbe 0x58e8aa
// 0058e836  83c006               add eax, 6
// 0058e839  80caff               or dl, 0xff
// 0058e83c  2a10                 sub dl, byte ptr [eax]
// 0058e83e  40                   inc eax
// 0058e83f  8850ff               mov byte ptr [eax - 1], dl
// 0058e842  80caff               or dl, 0xff
// 0058e845  2a10                 sub dl, byte ptr [eax]
// 0058e847  40                   inc eax
// 0058e848  83e901               sub ecx, 1
// 0058e84b  8850ff               mov byte ptr [eax - 1], dl
// 0058e84e  75e6                 jne 0x58e836
// 0058e850  c3                   ret 
// 0058e851  80f904               cmp cl, 4
// 0058e854  7554                 jne 0x58e8aa
// 0058e856  80780908             cmp byte ptr [eax + 9], 8
// 0058e85a  752a                 jne 0x58e886
// 0058e85c  8b10                 mov edx, dword ptr [eax]
// 0058e85e  8b442408             mov eax, dword ptr [esp + 8]
// 0058e862  8bc8                 mov ecx, eax
// 0058e864  85d2                 test edx, edx
// 0058e866  7642                 jbe 0x58e8aa
// 0058e868  56                   push esi
// 0058e869  8bf2                 mov esi, edx
// 0058e86b  eb03                 jmp 0x58e870
// 0058e86d  8d4900               lea ecx, [ecx]
// 0058e870  8a11                 mov dl, byte ptr [ecx]
// 0058e872  8810                 mov byte ptr [eax], dl
// 0058e874  41                   inc ecx
// 0058e875  80caff               or dl, 0xff
// 0058e878  2a11                 sub dl, byte ptr [ecx]
// 0058e87a  40                   inc eax
// 0058e87b  8810                 mov byte ptr [eax], dl
// 0058e87d  40                   inc eax
// 0058e87e  41                   inc ecx
// 0058e87f  83ee01               sub esi, 1
// 0058e882  75ec                 jne 0x58e870
// 0058e884  5e                   pop esi
// 0058e885  c3                   ret 
// 0058e886  8b08                 mov ecx, dword ptr [eax]
// 0058e888  8b442408             mov eax, dword ptr [esp + 8]
// 0058e88c  85c9                 test ecx, ecx
// 0058e88e  761a                 jbe 0x58e8aa
// 0058e890  83c002               add eax, 2
// 0058e893  80caff               or dl, 0xff
// 0058e896  2a10                 sub dl, byte ptr [eax]
// 0058e898  40                   inc eax
// 0058e899  8850ff               mov byte ptr [eax - 1], dl
// 0058e89c  80caff               or dl, 0xff
// 0058e89f  2a10                 sub dl, byte ptr [eax]
// 0058e8a1  40                   inc eax
// 0058e8a2  83e901               sub ecx, 1
// 0058e8a5  8850ff               mov byte ptr [eax - 1], dl
// 0058e8a8  75e6                 jne 0x58e890
// 0058e8aa  c3                   ret 
// library libpng-1.2.10/pngwtran.c (function _png_do_write_invert_alpha)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwtran.c
