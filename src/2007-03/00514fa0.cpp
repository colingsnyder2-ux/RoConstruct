// from server: 100% by auto
// roc 2007-03 00514fa0  unit: seg_00510000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00514fa0
//
// 00514fa0  8b442408             mov eax, dword ptr [esp + 8]
// 00514fa4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00514fa8  8bd0                 mov edx, eax
// 00514faa  c1ea08               shr edx, 8
// 00514fad  8811                 mov byte ptr [ecx], dl
// 00514faf  884101               mov byte ptr [ecx + 1], al
// 00514fb2  c3                   ret 
// library libpng-1.2.7/pngwutil.c (function _png_save_uint_16)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwutil.c
