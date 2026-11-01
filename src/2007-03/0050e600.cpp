// from server: 100% by auto
// roc 2007-03 0050e600  unit: seg_00500000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e600
//
// 0050e600  8b442404             mov eax, dword ptr [esp + 4]
// 0050e604  81487000040000       or dword ptr [eax + 0x70], 0x400
// 0050e60b  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_set_strip_16)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
