// from server: 100% by auto
// roc 2009-12 00605fa0  unit: seg_00600000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00605fa0
//
// 00605fa0  8b442404             mov eax, dword ptr [esp + 4]
// 00605fa4  85c0                 test eax, eax
// 00605fa6  7407                 je 0x605faf
// 00605fa8  81487000040000       or dword ptr [eax + 0x70], 0x400
// 00605faf  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_strip_16)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
