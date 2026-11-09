// from server: 100% by auto
// roc 2011-06 00561440  unit: seg_00560000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00561440
//
// 00561440  83ec54               sub esp, 0x54
// 00561443  56                   push esi
// 00561444  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 00561448  85f6                 test esi, esi
// 0056144a  7513                 jne 0x56145f
// 0056144c  8b442460             mov eax, dword ptr [esp + 0x60]
// 00561450  50                   push eax
// 00561451  56                   push esi
// 00561452  e8d9feffff           call 0x561330
// 00561457  83c408               add esp, 8
// 0056145a  5e                   pop esi
// 0056145b  83c454               add esp, 0x54
// 0056145e  c3                   ret 
// 0056145f  8b542460             mov edx, dword ptr [esp + 0x60]
// 00561463  8d442404             lea eax, [esp + 4]
// 00561467  8bce                 mov ecx, esi
// 00561469  e8c2fbffff           call 0x561030
// 0056146e  8d4c2404             lea ecx, [esp + 4]
// 00561472  51                   push ecx
// 00561473  56                   push esi
// 00561474  e8b7feffff           call 0x561330
// 00561479  83c408               add esp, 8
// 0056147c  5e                   pop esi
// 0056147d  83c454               add esp, 0x54
// 00561480  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_chunk_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
