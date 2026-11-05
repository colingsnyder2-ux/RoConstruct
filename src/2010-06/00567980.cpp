// from server: 100% by auto
// roc 2010-06 00567980  unit: seg_00560000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00567980
//
// 00567980  8b442404             mov eax, dword ptr [esp + 4]
// 00567984  85c0                 test eax, eax
// 00567986  740b                 je 0x567993
// 00567988  81487000100002       or dword ptr [eax + 0x70], 0x2001000
// 0056798f  83606cbf             and dword ptr [eax + 0x6c], 0xffffffbf
// 00567993  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_set_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
