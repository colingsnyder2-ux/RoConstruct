// from server: 100% by auto
// roc 2012-06 0063e300  unit: seg_00630000  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063e300
//
// 0063e300  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0063e304  85c9                 test ecx, ecx
// 0063e306  7438                 je 0x63e340
// 0063e308  8b542408             mov edx, dword ptr [esp + 8]
// 0063e30c  85d2                 test edx, edx
// 0063e30e  7430                 je 0x63e340
// 0063e310  83b92002000000       cmp dword ptr [ecx + 0x220], 0
// 0063e317  7e27                 jle 0x63e340
// 0063e319  8b8120020000         mov eax, dword ptr [ecx + 0x220]
// 0063e31f  8b8924020000         mov ecx, dword ptr [ecx + 0x224]
// 0063e325  56                   push esi
// 0063e326  8d3480               lea esi, [eax + eax*4]
// 0063e329  8d4c0efb             lea ecx, [esi + ecx - 5]
// 0063e32d  5e                   pop esi
// 0063e32e  85c0                 test eax, eax
// 0063e330  740e                 je 0x63e340
// 0063e332  8b12                 mov edx, dword ptr [edx]
// 0063e334  3b11                 cmp edx, dword ptr [ecx]
// 0063e336  740b                 je 0x63e343
// 0063e338  48                   dec eax
// 0063e339  83e905               sub ecx, 5
// 0063e33c  85c0                 test eax, eax
// 0063e33e  75f4                 jne 0x63e334
// 0063e340  33c0                 xor eax, eax
// 0063e342  c3                   ret 
// 0063e343  0fb64104             movzx eax, byte ptr [ecx + 4]
// 0063e347  c3                   ret 
// library libpng-1.2.22/png.c (function _png_handle_as_unknown)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 png.c
