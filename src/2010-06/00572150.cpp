// from server: 100% by auto
// roc 2010-06 00572150  unit: seg_00570000  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00572150
//
// 00572150  8b442404             mov eax, dword ptr [esp + 4]
// 00572154  8a4808               mov cl, byte ptr [eax + 8]
// 00572157  80f906               cmp cl, 6
// 0057215a  7545                 jne 0x5721a1
// 0057215c  8b08                 mov ecx, dword ptr [eax]
// 0057215e  80780908             cmp byte ptr [eax + 9], 8
// 00572162  8b442408             mov eax, dword ptr [esp + 8]
// 00572166  751a                 jne 0x572182
// 00572168  85c9                 test ecx, ecx
// 0057216a  0f868a000000         jbe 0x5721fa
// 00572170  83c003               add eax, 3
// 00572173  80caff               or dl, 0xff
// 00572176  2a10                 sub dl, byte ptr [eax]
// 00572178  40                   inc eax
// 00572179  83e901               sub ecx, 1
// 0057217c  8850ff               mov byte ptr [eax - 1], dl
// 0057217f  75ef                 jne 0x572170
// 00572181  c3                   ret 
// 00572182  85c9                 test ecx, ecx
// 00572184  7674                 jbe 0x5721fa
// 00572186  83c006               add eax, 6
// 00572189  80caff               or dl, 0xff
// 0057218c  2a10                 sub dl, byte ptr [eax]
// 0057218e  40                   inc eax
// 0057218f  8850ff               mov byte ptr [eax - 1], dl
// 00572192  80caff               or dl, 0xff
// 00572195  2a10                 sub dl, byte ptr [eax]
// 00572197  40                   inc eax
// 00572198  83e901               sub ecx, 1
// 0057219b  8850ff               mov byte ptr [eax - 1], dl
// 0057219e  75e6                 jne 0x572186
// 005721a0  c3                   ret 
// 005721a1  80f904               cmp cl, 4
// 005721a4  7554                 jne 0x5721fa
// 005721a6  80780908             cmp byte ptr [eax + 9], 8
// 005721aa  752a                 jne 0x5721d6
// 005721ac  8b10                 mov edx, dword ptr [eax]
// 005721ae  8b442408             mov eax, dword ptr [esp + 8]
// 005721b2  8bc8                 mov ecx, eax
// 005721b4  85d2                 test edx, edx
// 005721b6  7642                 jbe 0x5721fa
// 005721b8  56                   push esi
// 005721b9  8bf2                 mov esi, edx
// 005721bb  eb03                 jmp 0x5721c0
// 005721bd  8d4900               lea ecx, [ecx]
// 005721c0  8a11                 mov dl, byte ptr [ecx]
// 005721c2  8810                 mov byte ptr [eax], dl
// 005721c4  41                   inc ecx
// 005721c5  80caff               or dl, 0xff
// 005721c8  2a11                 sub dl, byte ptr [ecx]
// 005721ca  40                   inc eax
// 005721cb  8810                 mov byte ptr [eax], dl
// 005721cd  40                   inc eax
// 005721ce  41                   inc ecx
// 005721cf  83ee01               sub esi, 1
// 005721d2  75ec                 jne 0x5721c0
// 005721d4  5e                   pop esi
// 005721d5  c3                   ret 
// 005721d6  8b08                 mov ecx, dword ptr [eax]
// 005721d8  8b442408             mov eax, dword ptr [esp + 8]
// 005721dc  85c9                 test ecx, ecx
// 005721de  761a                 jbe 0x5721fa
// 005721e0  83c002               add eax, 2
// 005721e3  80caff               or dl, 0xff
// 005721e6  2a10                 sub dl, byte ptr [eax]
// 005721e8  40                   inc eax
// 005721e9  8850ff               mov byte ptr [eax - 1], dl
// 005721ec  80caff               or dl, 0xff
// 005721ef  2a10                 sub dl, byte ptr [eax]
// 005721f1  40                   inc eax
// 005721f2  83e901               sub ecx, 1
// 005721f5  8850ff               mov byte ptr [eax - 1], dl
// 005721f8  75e6                 jne 0x5721e0
// 005721fa  c3                   ret 
// library libpng-1.2.10/pngwtran.c (function _png_do_write_invert_alpha)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwtran.c
