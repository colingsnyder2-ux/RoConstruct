// from server: 100% by auto
// roc 2011-06 0055c510  unit: seg_00550000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055c510
//
// 0055c510  8b442404             mov eax, dword ptr [esp + 4]
// 0055c514  81487000400000       or dword ptr [eax + 0x70], 0x4000
// 0055c51b  83606cbf             and dword ptr [eax + 0x6c], 0xffffffbf
// 0055c51f  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_set_gray_to_rgb)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
