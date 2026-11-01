// from server: 100% by auto
// roc 2007-03 00512e50  unit: seg_00510000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00512e50
//
// 00512e50  837c240400           cmp dword ptr [esp + 4], 0
// 00512e55  7421                 je 0x512e78
// 00512e57  8b442408             mov eax, dword ptr [esp + 8]
// 00512e5b  85c0                 test eax, eax
// 00512e5d  7419                 je 0x512e78
// 00512e5f  f6400801             test byte ptr [eax + 8], 1
// 00512e63  7413                 je 0x512e78
// 00512e65  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00512e69  85c9                 test ecx, ecx
// 00512e6b  740b                 je 0x512e78
// 00512e6d  d94028               fld dword ptr [eax + 0x28]
// 00512e70  b801000000           mov eax, 1
// 00512e75  dd19                 fstp qword ptr [ecx]
// 00512e77  c3                   ret 
// 00512e78  33c0                 xor eax, eax
// 00512e7a  c3                   ret 
// library libpng-1.2.7/pngget.c (function _png_get_gAMA)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngget.c
