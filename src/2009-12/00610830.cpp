// from server: 100% by auto
// roc 2009-12 00610830  unit: seg_00610000  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00610830
//
// 00610830  8b442404             mov eax, dword ptr [esp + 4]
// 00610834  8a4808               mov cl, byte ptr [eax + 8]
// 00610837  80f906               cmp cl, 6
// 0061083a  7545                 jne 0x610881
// 0061083c  8b08                 mov ecx, dword ptr [eax]
// 0061083e  80780908             cmp byte ptr [eax + 9], 8
// 00610842  8b442408             mov eax, dword ptr [esp + 8]
// 00610846  751a                 jne 0x610862
// 00610848  85c9                 test ecx, ecx
// 0061084a  0f868a000000         jbe 0x6108da
// 00610850  83c003               add eax, 3
// 00610853  80caff               or dl, 0xff
// 00610856  2a10                 sub dl, byte ptr [eax]
// 00610858  40                   inc eax
// 00610859  83e901               sub ecx, 1
// 0061085c  8850ff               mov byte ptr [eax - 1], dl
// 0061085f  75ef                 jne 0x610850
// 00610861  c3                   ret 
// 00610862  85c9                 test ecx, ecx
// 00610864  7674                 jbe 0x6108da
// 00610866  83c006               add eax, 6
// 00610869  80caff               or dl, 0xff
// 0061086c  2a10                 sub dl, byte ptr [eax]
// 0061086e  40                   inc eax
// 0061086f  8850ff               mov byte ptr [eax - 1], dl
// 00610872  80caff               or dl, 0xff
// 00610875  2a10                 sub dl, byte ptr [eax]
// 00610877  40                   inc eax
// 00610878  83e901               sub ecx, 1
// 0061087b  8850ff               mov byte ptr [eax - 1], dl
// 0061087e  75e6                 jne 0x610866
// 00610880  c3                   ret 
// 00610881  80f904               cmp cl, 4
// 00610884  7554                 jne 0x6108da
// 00610886  80780908             cmp byte ptr [eax + 9], 8
// 0061088a  752a                 jne 0x6108b6
// 0061088c  8b10                 mov edx, dword ptr [eax]
// 0061088e  8b442408             mov eax, dword ptr [esp + 8]
// 00610892  8bc8                 mov ecx, eax
// 00610894  85d2                 test edx, edx
// 00610896  7642                 jbe 0x6108da
// 00610898  56                   push esi
// 00610899  8bf2                 mov esi, edx
// 0061089b  eb03                 jmp 0x6108a0
// 0061089d  8d4900               lea ecx, [ecx]
// 006108a0  8a11                 mov dl, byte ptr [ecx]
// 006108a2  8810                 mov byte ptr [eax], dl
// 006108a4  41                   inc ecx
// 006108a5  80caff               or dl, 0xff
// 006108a8  2a11                 sub dl, byte ptr [ecx]
// 006108aa  40                   inc eax
// 006108ab  8810                 mov byte ptr [eax], dl
// 006108ad  40                   inc eax
// 006108ae  41                   inc ecx
// 006108af  83ee01               sub esi, 1
// 006108b2  75ec                 jne 0x6108a0
// 006108b4  5e                   pop esi
// 006108b5  c3                   ret 
// 006108b6  8b08                 mov ecx, dword ptr [eax]
// 006108b8  8b442408             mov eax, dword ptr [esp + 8]
// 006108bc  85c9                 test ecx, ecx
// 006108be  761a                 jbe 0x6108da
// 006108c0  83c002               add eax, 2
// 006108c3  80caff               or dl, 0xff
// 006108c6  2a10                 sub dl, byte ptr [eax]
// 006108c8  40                   inc eax
// 006108c9  8850ff               mov byte ptr [eax - 1], dl
// 006108cc  80caff               or dl, 0xff
// 006108cf  2a10                 sub dl, byte ptr [eax]
// 006108d1  40                   inc eax
// 006108d2  83e901               sub ecx, 1
// 006108d5  8850ff               mov byte ptr [eax - 1], dl
// 006108d8  75e6                 jne 0x6108c0
// 006108da  c3                   ret 
// library libpng-1.2.10/pngwtran.c (function _png_do_write_invert_alpha)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwtran.c
