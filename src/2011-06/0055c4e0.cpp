// from server: 100% by auto
// roc 2011-06 0055c4e0  unit: seg_00550000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055c4e0
//
// 0055c4e0  8b442404             mov eax, dword ptr [esp + 4]
// 0055c4e4  85c0                 test eax, eax
// 0055c4e6  740b                 je 0x55c4f3
// 0055c4e8  81487000100002       or dword ptr [eax + 0x70], 0x2001000
// 0055c4ef  83606cbf             and dword ptr [eax + 0x6c], 0xffffffbf
// 0055c4f3  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_set_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
