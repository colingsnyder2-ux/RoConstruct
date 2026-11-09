// from server: 100% by auto
// roc 2009-06 00581d30  unit: seg_00580000  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00581d30
//
// 00581d30  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00581d34  85c9                 test ecx, ecx
// 00581d36  7438                 je 0x581d70
// 00581d38  8b542408             mov edx, dword ptr [esp + 8]
// 00581d3c  85d2                 test edx, edx
// 00581d3e  7430                 je 0x581d70
// 00581d40  83b92002000000       cmp dword ptr [ecx + 0x220], 0
// 00581d47  7e27                 jle 0x581d70
// 00581d49  8b8120020000         mov eax, dword ptr [ecx + 0x220]
// 00581d4f  8b8924020000         mov ecx, dword ptr [ecx + 0x224]
// 00581d55  56                   push esi
// 00581d56  8d3480               lea esi, [eax + eax*4]
// 00581d59  8d4c0efb             lea ecx, [esi + ecx - 5]
// 00581d5d  5e                   pop esi
// 00581d5e  85c0                 test eax, eax
// 00581d60  740e                 je 0x581d70
// 00581d62  8b12                 mov edx, dword ptr [edx]
// 00581d64  3b11                 cmp edx, dword ptr [ecx]
// 00581d66  740b                 je 0x581d73
// 00581d68  48                   dec eax
// 00581d69  83e905               sub ecx, 5
// 00581d6c  85c0                 test eax, eax
// 00581d6e  75f4                 jne 0x581d64
// 00581d70  33c0                 xor eax, eax
// 00581d72  c3                   ret 
// 00581d73  0fb64104             movzx eax, byte ptr [ecx + 4]
// 00581d77  c3                   ret 
// library libpng-1.2.22/png.c (function _png_handle_as_unknown)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 png.c
