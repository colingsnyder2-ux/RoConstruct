// from server: 100% by auto
// roc 2009-06 005841f0  unit: seg_00580000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005841f0
//
// 005841f0  8b442404             mov eax, dword ptr [esp + 4]
// 005841f4  85c0                 test eax, eax
// 005841f6  7407                 je 0x5841ff
// 005841f8  81487000040000       or dword ptr [eax + 0x70], 0x400
// 005841ff  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_strip_16)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
