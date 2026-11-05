// from server: 100% by auto
// roc 2011-06 0056e3e0  unit: seg_00560000  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056e3e0
//
// 0056e3e0  8b442404             mov eax, dword ptr [esp + 4]
// 0056e3e4  8a4808               mov cl, byte ptr [eax + 8]
// 0056e3e7  80f906               cmp cl, 6
// 0056e3ea  7545                 jne 0x56e431
// 0056e3ec  8b08                 mov ecx, dword ptr [eax]
// 0056e3ee  80780908             cmp byte ptr [eax + 9], 8
// 0056e3f2  8b442408             mov eax, dword ptr [esp + 8]
// 0056e3f6  751a                 jne 0x56e412
// 0056e3f8  85c9                 test ecx, ecx
// 0056e3fa  0f868a000000         jbe 0x56e48a
// 0056e400  83c003               add eax, 3
// 0056e403  80caff               or dl, 0xff
// 0056e406  2a10                 sub dl, byte ptr [eax]
// 0056e408  40                   inc eax
// 0056e409  83e901               sub ecx, 1
// 0056e40c  8850ff               mov byte ptr [eax - 1], dl
// 0056e40f  75ef                 jne 0x56e400
// 0056e411  c3                   ret 
// 0056e412  85c9                 test ecx, ecx
// 0056e414  7674                 jbe 0x56e48a
// 0056e416  83c006               add eax, 6
// 0056e419  80caff               or dl, 0xff
// 0056e41c  2a10                 sub dl, byte ptr [eax]
// 0056e41e  40                   inc eax
// 0056e41f  8850ff               mov byte ptr [eax - 1], dl
// 0056e422  80caff               or dl, 0xff
// 0056e425  2a10                 sub dl, byte ptr [eax]
// 0056e427  40                   inc eax
// 0056e428  83e901               sub ecx, 1
// 0056e42b  8850ff               mov byte ptr [eax - 1], dl
// 0056e42e  75e6                 jne 0x56e416
// 0056e430  c3                   ret 
// 0056e431  80f904               cmp cl, 4
// 0056e434  7554                 jne 0x56e48a
// 0056e436  80780908             cmp byte ptr [eax + 9], 8
// 0056e43a  752a                 jne 0x56e466
// 0056e43c  8b10                 mov edx, dword ptr [eax]
// 0056e43e  8b442408             mov eax, dword ptr [esp + 8]
// 0056e442  8bc8                 mov ecx, eax
// 0056e444  85d2                 test edx, edx
// 0056e446  7642                 jbe 0x56e48a
// 0056e448  56                   push esi
// 0056e449  8bf2                 mov esi, edx
// 0056e44b  eb03                 jmp 0x56e450
// 0056e44d  8d4900               lea ecx, [ecx]
// 0056e450  8a11                 mov dl, byte ptr [ecx]
// 0056e452  8810                 mov byte ptr [eax], dl
// 0056e454  41                   inc ecx
// 0056e455  80caff               or dl, 0xff
// 0056e458  2a11                 sub dl, byte ptr [ecx]
// 0056e45a  40                   inc eax
// 0056e45b  8810                 mov byte ptr [eax], dl
// 0056e45d  40                   inc eax
// 0056e45e  41                   inc ecx
// 0056e45f  83ee01               sub esi, 1
// 0056e462  75ec                 jne 0x56e450
// 0056e464  5e                   pop esi
// 0056e465  c3                   ret 
// 0056e466  8b08                 mov ecx, dword ptr [eax]
// 0056e468  8b442408             mov eax, dword ptr [esp + 8]
// 0056e46c  85c9                 test ecx, ecx
// 0056e46e  761a                 jbe 0x56e48a
// 0056e470  83c002               add eax, 2
// 0056e473  80caff               or dl, 0xff
// 0056e476  2a10                 sub dl, byte ptr [eax]
// 0056e478  40                   inc eax
// 0056e479  8850ff               mov byte ptr [eax - 1], dl
// 0056e47c  80caff               or dl, 0xff
// 0056e47f  2a10                 sub dl, byte ptr [eax]
// 0056e481  40                   inc eax
// 0056e482  83e901               sub ecx, 1
// 0056e485  8850ff               mov byte ptr [eax - 1], dl
// 0056e488  75e6                 jne 0x56e470
// 0056e48a  c3                   ret 
// library libpng-1.2.10/pngwtran.c (function _png_do_write_invert_alpha)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwtran.c
