// from server: 100% by auto
// roc 2012-06 00649300  unit: seg_00640000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00649300
//
// 00649300  8b442404             mov eax, dword ptr [esp + 4]
// 00649304  85c0                 test eax, eax
// 00649306  7407                 je 0x64930f
// 00649308  81487000040000       or dword ptr [eax + 0x70], 0x400
// 0064930f  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_strip_16)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
