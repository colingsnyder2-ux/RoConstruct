// from server: 100% by auto
// roc 2011-06 00550cc0  unit: seg_00550000  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00550cc0
//
// 00550cc0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00550cc4  85c9                 test ecx, ecx
// 00550cc6  7438                 je 0x550d00
// 00550cc8  8b542408             mov edx, dword ptr [esp + 8]
// 00550ccc  85d2                 test edx, edx
// 00550cce  7430                 je 0x550d00
// 00550cd0  83b92002000000       cmp dword ptr [ecx + 0x220], 0
// 00550cd7  7e27                 jle 0x550d00
// 00550cd9  8b8120020000         mov eax, dword ptr [ecx + 0x220]
// 00550cdf  8b8924020000         mov ecx, dword ptr [ecx + 0x224]
// 00550ce5  56                   push esi
// 00550ce6  8d3480               lea esi, [eax + eax*4]
// 00550ce9  8d4c0efb             lea ecx, [esi + ecx - 5]
// 00550ced  5e                   pop esi
// 00550cee  85c0                 test eax, eax
// 00550cf0  740e                 je 0x550d00
// 00550cf2  8b12                 mov edx, dword ptr [edx]
// 00550cf4  3b11                 cmp edx, dword ptr [ecx]
// 00550cf6  740b                 je 0x550d03
// 00550cf8  48                   dec eax
// 00550cf9  83e905               sub ecx, 5
// 00550cfc  85c0                 test eax, eax
// 00550cfe  75f4                 jne 0x550cf4
// 00550d00  33c0                 xor eax, eax
// 00550d02  c3                   ret 
// 00550d03  0fb64104             movzx eax, byte ptr [ecx + 4]
// 00550d07  c3                   ret 
// library libpng-1.2.22/png.c (function _png_handle_as_unknown)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 png.c
