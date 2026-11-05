// from server: 100% by auto
// roc 2012-06 00649360  unit: seg_00640000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00649360
//
// 00649360  8b442404             mov eax, dword ptr [esp + 4]
// 00649364  85c0                 test eax, eax
// 00649366  740b                 je 0x649373
// 00649368  81487000100002       or dword ptr [eax + 0x70], 0x2001000
// 0064936f  83606cbf             and dword ptr [eax + 0x6c], 0xffffffbf
// 00649373  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_set_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
