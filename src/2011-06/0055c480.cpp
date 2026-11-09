// from server: 100% by auto
// roc 2011-06 0055c480  unit: seg_00550000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055c480
//
// 0055c480  8b442404             mov eax, dword ptr [esp + 4]
// 0055c484  85c0                 test eax, eax
// 0055c486  7407                 je 0x55c48f
// 0055c488  81487000040000       or dword ptr [eax + 0x70], 0x400
// 0055c48f  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_strip_16)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
