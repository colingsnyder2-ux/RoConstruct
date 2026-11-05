// from server: 100% by auto
// roc 2010-06 005679a0  unit: seg_00560000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005679a0
//
// 005679a0  8b442404             mov eax, dword ptr [esp + 4]
// 005679a4  85c0                 test eax, eax
// 005679a6  7407                 je 0x5679af
// 005679a8  81487000100002       or dword ptr [eax + 0x70], 0x2001000
// 005679af  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
