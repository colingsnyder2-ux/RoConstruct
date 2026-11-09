// from server: 100% by auto
// roc 2009-06 00584270  unit: seg_00580000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00584270
//
// 00584270  8b442404             mov eax, dword ptr [esp + 4]
// 00584274  85c0                 test eax, eax
// 00584276  7407                 je 0x58427f
// 00584278  81487000100002       or dword ptr [eax + 0x70], 0x2001000
// 0058427f  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
