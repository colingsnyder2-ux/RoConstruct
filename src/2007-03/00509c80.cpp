// from server: 100% by auto
// roc 2007-03 00509c80  unit: seg_00500000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509c80
//
// 00509c80  837c240400           cmp dword ptr [esp + 4], 0
// 00509c85  741b                 je 0x509ca2
// 00509c87  8b442408             mov eax, dword ptr [esp + 8]
// 00509c8b  85c0                 test eax, eax
// 00509c8d  7413                 je 0x509ca2
// 00509c8f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00509c93  8b11                 mov edx, dword ptr [ecx]
// 00509c95  895044               mov dword ptr [eax + 0x44], edx
// 00509c98  8a4904               mov cl, byte ptr [ecx + 4]
// 00509c9b  83480802             or dword ptr [eax + 8], 2
// 00509c9f  884848               mov byte ptr [eax + 0x48], cl
// 00509ca2  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_sBIT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
