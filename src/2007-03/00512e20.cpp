// from server: 100% by auto
// roc 2007-03 00512e20  unit: seg_00510000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00512e20
//
// 00512e20  837c240400           cmp dword ptr [esp + 4], 0
// 00512e25  7421                 je 0x512e48
// 00512e27  8b442408             mov eax, dword ptr [esp + 8]
// 00512e2b  85c0                 test eax, eax
// 00512e2d  7419                 je 0x512e48
// 00512e2f  f6400820             test byte ptr [eax + 8], 0x20
// 00512e33  7413                 je 0x512e48
// 00512e35  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00512e39  85c9                 test ecx, ecx
// 00512e3b  740b                 je 0x512e48
// 00512e3d  83c05a               add eax, 0x5a
// 00512e40  8901                 mov dword ptr [ecx], eax
// 00512e42  b820000000           mov eax, 0x20
// 00512e47  c3                   ret 
// 00512e48  33c0                 xor eax, eax
// 00512e4a  c3                   ret 
// library libpng-1.2.7/pngget.c (function _png_get_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngget.c
