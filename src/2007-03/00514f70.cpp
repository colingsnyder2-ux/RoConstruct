// from server: 100% by auto
// roc 2007-03 00514f70  unit: seg_00510000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00514f70
//
// 00514f70  8b442408             mov eax, dword ptr [esp + 8]
// 00514f74  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00514f78  8bd0                 mov edx, eax
// 00514f7a  c1fa18               sar edx, 0x18
// 00514f7d  8811                 mov byte ptr [ecx], dl
// 00514f7f  8bd0                 mov edx, eax
// 00514f81  c1fa10               sar edx, 0x10
// 00514f84  885101               mov byte ptr [ecx + 1], dl
// 00514f87  8bd0                 mov edx, eax
// 00514f89  c1fa08               sar edx, 8
// 00514f8c  885102               mov byte ptr [ecx + 2], dl
// 00514f8f  884103               mov byte ptr [ecx + 3], al
// 00514f92  c3                   ret 
// library libpng-1.2.7/pngwutil.c (function _png_save_int_32)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwutil.c
