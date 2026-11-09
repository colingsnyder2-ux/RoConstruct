// from server: 100% by auto
// roc 2012-06 00659af0  unit: seg_00650000  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00659af0
//
// 00659af0  8b442404             mov eax, dword ptr [esp + 4]
// 00659af4  8a4808               mov cl, byte ptr [eax + 8]
// 00659af7  80f906               cmp cl, 6
// 00659afa  7545                 jne 0x659b41
// 00659afc  8b08                 mov ecx, dword ptr [eax]
// 00659afe  80780908             cmp byte ptr [eax + 9], 8
// 00659b02  8b442408             mov eax, dword ptr [esp + 8]
// 00659b06  751a                 jne 0x659b22
// 00659b08  85c9                 test ecx, ecx
// 00659b0a  0f868a000000         jbe 0x659b9a
// 00659b10  83c003               add eax, 3
// 00659b13  80caff               or dl, 0xff
// 00659b16  2a10                 sub dl, byte ptr [eax]
// 00659b18  40                   inc eax
// 00659b19  83e901               sub ecx, 1
// 00659b1c  8850ff               mov byte ptr [eax - 1], dl
// 00659b1f  75ef                 jne 0x659b10
// 00659b21  c3                   ret 
// 00659b22  85c9                 test ecx, ecx
// 00659b24  7674                 jbe 0x659b9a
// 00659b26  83c006               add eax, 6
// 00659b29  80caff               or dl, 0xff
// 00659b2c  2a10                 sub dl, byte ptr [eax]
// 00659b2e  40                   inc eax
// 00659b2f  8850ff               mov byte ptr [eax - 1], dl
// 00659b32  80caff               or dl, 0xff
// 00659b35  2a10                 sub dl, byte ptr [eax]
// 00659b37  40                   inc eax
// 00659b38  83e901               sub ecx, 1
// 00659b3b  8850ff               mov byte ptr [eax - 1], dl
// 00659b3e  75e6                 jne 0x659b26
// 00659b40  c3                   ret 
// 00659b41  80f904               cmp cl, 4
// 00659b44  7554                 jne 0x659b9a
// 00659b46  80780908             cmp byte ptr [eax + 9], 8
// 00659b4a  752a                 jne 0x659b76
// 00659b4c  8b10                 mov edx, dword ptr [eax]
// 00659b4e  8b442408             mov eax, dword ptr [esp + 8]
// 00659b52  8bc8                 mov ecx, eax
// 00659b54  85d2                 test edx, edx
// 00659b56  7642                 jbe 0x659b9a
// 00659b58  56                   push esi
// 00659b59  8bf2                 mov esi, edx
// 00659b5b  eb03                 jmp 0x659b60
// 00659b5d  8d4900               lea ecx, [ecx]
// 00659b60  8a11                 mov dl, byte ptr [ecx]
// 00659b62  8810                 mov byte ptr [eax], dl
// 00659b64  41                   inc ecx
// 00659b65  80caff               or dl, 0xff
// 00659b68  2a11                 sub dl, byte ptr [ecx]
// 00659b6a  40                   inc eax
// 00659b6b  8810                 mov byte ptr [eax], dl
// 00659b6d  40                   inc eax
// 00659b6e  41                   inc ecx
// 00659b6f  83ee01               sub esi, 1
// 00659b72  75ec                 jne 0x659b60
// 00659b74  5e                   pop esi
// 00659b75  c3                   ret 
// 00659b76  8b08                 mov ecx, dword ptr [eax]
// 00659b78  8b442408             mov eax, dword ptr [esp + 8]
// 00659b7c  85c9                 test ecx, ecx
// 00659b7e  761a                 jbe 0x659b9a
// 00659b80  83c002               add eax, 2
// 00659b83  80caff               or dl, 0xff
// 00659b86  2a10                 sub dl, byte ptr [eax]
// 00659b88  40                   inc eax
// 00659b89  8850ff               mov byte ptr [eax - 1], dl
// 00659b8c  80caff               or dl, 0xff
// 00659b8f  2a10                 sub dl, byte ptr [eax]
// 00659b91  40                   inc eax
// 00659b92  83e901               sub ecx, 1
// 00659b95  8850ff               mov byte ptr [eax - 1], dl
// 00659b98  75e6                 jne 0x659b80
// 00659b9a  c3                   ret 
// library libpng-1.2.10/pngwtran.c (function _png_do_write_invert_alpha)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwtran.c
