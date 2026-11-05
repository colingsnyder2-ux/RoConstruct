// from server: 100% by auto
// roc 2009-06 00584250  unit: seg_00580000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00584250
//
// 00584250  8b442404             mov eax, dword ptr [esp + 4]
// 00584254  85c0                 test eax, eax
// 00584256  740b                 je 0x584263
// 00584258  81487000100002       or dword ptr [eax + 0x70], 0x2001000
// 0058425f  83606cbf             and dword ptr [eax + 0x6c], 0xffffffbf
// 00584263  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_set_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
