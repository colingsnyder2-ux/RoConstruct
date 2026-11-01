// from server: 100% by auto
// roc 2007-03 00514f40  unit: seg_00510000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00514f40
//
// 00514f40  8b442408             mov eax, dword ptr [esp + 8]
// 00514f44  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00514f48  8bd0                 mov edx, eax
// 00514f4a  c1ea18               shr edx, 0x18
// 00514f4d  8811                 mov byte ptr [ecx], dl
// 00514f4f  8bd0                 mov edx, eax
// 00514f51  c1ea10               shr edx, 0x10
// 00514f54  885101               mov byte ptr [ecx + 1], dl
// 00514f57  8bd0                 mov edx, eax
// 00514f59  c1ea08               shr edx, 8
// 00514f5c  885102               mov byte ptr [ecx + 2], dl
// 00514f5f  884103               mov byte ptr [ecx + 3], al
// 00514f62  c3                   ret 
// library libpng-1.2.7/pngwutil.c (function _png_save_uint_32)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwutil.c
