// from server: 100% by auto
// roc 2009-06 00584280  unit: seg_00580000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00584280
//
// 00584280  8b442404             mov eax, dword ptr [esp + 4]
// 00584284  81487000100002       or dword ptr [eax + 0x70], 0x2001000
// 0058428b  83606cbf             and dword ptr [eax + 0x6c], 0xffffffbf
// 0058428f  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_set_tRNS_to_alpha)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
