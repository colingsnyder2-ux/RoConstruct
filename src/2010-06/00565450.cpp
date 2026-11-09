// from server: 100% by auto
// roc 2010-06 00565450  unit: seg_00560000  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00565450
//
// 00565450  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00565454  85c9                 test ecx, ecx
// 00565456  7438                 je 0x565490
// 00565458  8b542408             mov edx, dword ptr [esp + 8]
// 0056545c  85d2                 test edx, edx
// 0056545e  7430                 je 0x565490
// 00565460  83b92002000000       cmp dword ptr [ecx + 0x220], 0
// 00565467  7e27                 jle 0x565490
// 00565469  8b8120020000         mov eax, dword ptr [ecx + 0x220]
// 0056546f  8b8924020000         mov ecx, dword ptr [ecx + 0x224]
// 00565475  56                   push esi
// 00565476  8d3480               lea esi, [eax + eax*4]
// 00565479  8d4c0efb             lea ecx, [esi + ecx - 5]
// 0056547d  5e                   pop esi
// 0056547e  85c0                 test eax, eax
// 00565480  740e                 je 0x565490
// 00565482  8b12                 mov edx, dword ptr [edx]
// 00565484  3b11                 cmp edx, dword ptr [ecx]
// 00565486  740b                 je 0x565493
// 00565488  48                   dec eax
// 00565489  83e905               sub ecx, 5
// 0056548c  85c0                 test eax, eax
// 0056548e  75f4                 jne 0x565484
// 00565490  33c0                 xor eax, eax
// 00565492  c3                   ret 
// 00565493  0fb64104             movzx eax, byte ptr [ecx + 4]
// 00565497  c3                   ret 
// library libpng-1.2.22/png.c (function _png_handle_as_unknown)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 png.c
