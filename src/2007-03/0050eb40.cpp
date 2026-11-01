// from server: 100% by auto
// roc 2007-03 0050eb40  unit: seg_00500000  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050eb40
//
// 0050eb40  56                   push esi
// 0050eb41  8b742408             mov esi, dword ptr [esp + 8]
// 0050eb45  807e0910             cmp byte ptr [esi + 9], 0x10
// 0050eb49  7540                 jne 0x50eb8b
// 0050eb4b  0fb6560a             movzx edx, byte ptr [esi + 0xa]
// 0050eb4f  0faf16               imul edx, dword ptr [esi]
// 0050eb52  85d2                 test edx, edx
// 0050eb54  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0050eb58  8bc8                 mov ecx, eax
// 0050eb5a  7614                 jbe 0x50eb70
// 0050eb5c  57                   push edi
// 0050eb5d  8bfa                 mov edi, edx
// 0050eb5f  90                   nop 
// 0050eb60  8a10                 mov dl, byte ptr [eax]
// 0050eb62  8811                 mov byte ptr [ecx], dl
// 0050eb64  83c002               add eax, 2
// 0050eb67  83c101               add ecx, 1
// 0050eb6a  83ef01               sub edi, 1
// 0050eb6d  75f1                 jne 0x50eb60
// 0050eb6f  5f                   pop edi
// 0050eb70  8a460a               mov al, byte ptr [esi + 0xa]
// 0050eb73  8ac8                 mov cl, al
// 0050eb75  02c9                 add cl, cl
// 0050eb77  02c9                 add cl, cl
// 0050eb79  0fb6d0               movzx edx, al
// 0050eb7c  02c9                 add cl, cl
// 0050eb7e  0faf16               imul edx, dword ptr [esi]
// 0050eb81  c6460908             mov byte ptr [esi + 9], 8
// 0050eb85  884e0b               mov byte ptr [esi + 0xb], cl
// 0050eb88  895604               mov dword ptr [esi + 4], edx
// 0050eb8b  5e                   pop esi
// 0050eb8c  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_chop)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
