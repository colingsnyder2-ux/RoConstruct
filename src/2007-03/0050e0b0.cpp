// from server: 100% by auto
// roc 2007-03 0050e0b0  unit: seg_00500000  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e0b0
//
// 0050e0b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0050e0b4  8a4108               mov al, byte ptr [ecx + 8]
// 0050e0b7  84c0                 test al, al
// 0050e0b9  751a                 jne 0x50e0d5
// 0050e0bb  8b4904               mov ecx, dword ptr [ecx + 4]
// 0050e0be  85c9                 test ecx, ecx
// 0050e0c0  8b442408             mov eax, dword ptr [esp + 8]
// 0050e0c4  7674                 jbe 0x50e13a
// 0050e0c6  8a10                 mov dl, byte ptr [eax]
// 0050e0c8  f6d2                 not dl
// 0050e0ca  8810                 mov byte ptr [eax], dl
// 0050e0cc  83c001               add eax, 1
// 0050e0cf  83e901               sub ecx, 1
// 0050e0d2  75f2                 jne 0x50e0c6
// 0050e0d4  c3                   ret 
// 0050e0d5  3c04                 cmp al, 4
// 0050e0d7  7561                 jne 0x50e13a
// 0050e0d9  80790908             cmp byte ptr [ecx + 9], 8
// 0050e0dd  7522                 jne 0x50e101
// 0050e0df  8b4904               mov ecx, dword ptr [ecx + 4]
// 0050e0e2  85c9                 test ecx, ecx
// 0050e0e4  8b442408             mov eax, dword ptr [esp + 8]
// 0050e0e8  7650                 jbe 0x50e13a
// 0050e0ea  83c1ff               add ecx, -1
// 0050e0ed  d1e9                 shr ecx, 1
// 0050e0ef  83c101               add ecx, 1
// 0050e0f2  8a10                 mov dl, byte ptr [eax]
// 0050e0f4  f6d2                 not dl
// 0050e0f6  8810                 mov byte ptr [eax], dl
// 0050e0f8  83c002               add eax, 2
// 0050e0fb  83e901               sub ecx, 1
// 0050e0fe  75f2                 jne 0x50e0f2
// 0050e100  c3                   ret 
// 0050e101  3c04                 cmp al, 4
// 0050e103  7535                 jne 0x50e13a
// 0050e105  80790910             cmp byte ptr [ecx + 9], 0x10
// 0050e109  752f                 jne 0x50e13a
// 0050e10b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0050e10e  85c9                 test ecx, ecx
// 0050e110  7628                 jbe 0x50e13a
// 0050e112  8b442408             mov eax, dword ptr [esp + 8]
// 0050e116  83c1ff               add ecx, -1
// 0050e119  c1e902               shr ecx, 2
// 0050e11c  83c001               add eax, 1
// 0050e11f  83c101               add ecx, 1
// 0050e122  0fb650ff             movzx edx, byte ptr [eax - 1]
// 0050e126  f6d2                 not dl
// 0050e128  8850ff               mov byte ptr [eax - 1], dl
// 0050e12b  0fb610               movzx edx, byte ptr [eax]
// 0050e12e  f6d2                 not dl
// 0050e130  8810                 mov byte ptr [eax], dl
// 0050e132  83c004               add eax, 4
// 0050e135  83e901               sub ecx, 1
// 0050e138  75e8                 jne 0x50e122
// 0050e13a  c3                   ret 
// library libpng-1.2.7/pngtrans.c (function _png_do_invert)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngtrans.c
