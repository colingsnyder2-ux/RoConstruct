// from server: 100% by auto
// roc 2010-06 00567920  unit: seg_00560000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00567920
//
// 00567920  8b442404             mov eax, dword ptr [esp + 4]
// 00567924  85c0                 test eax, eax
// 00567926  7407                 je 0x56792f
// 00567928  81487000040000       or dword ptr [eax + 0x70], 0x400
// 0056792f  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_strip_16)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
