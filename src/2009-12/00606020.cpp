// from server: 100% by auto
// roc 2009-12 00606020  unit: seg_00600000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00606020
//
// 00606020  8b442404             mov eax, dword ptr [esp + 4]
// 00606024  85c0                 test eax, eax
// 00606026  7407                 je 0x60602f
// 00606028  81487000100002       or dword ptr [eax + 0x70], 0x2001000
// 0060602f  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
