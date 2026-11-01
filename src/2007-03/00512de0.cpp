// from server: 100% by auto
// roc 2007-03 00512de0  unit: seg_00510000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00512de0
//
// 00512de0  837c240400           cmp dword ptr [esp + 4], 0
// 00512de5  740c                 je 0x512df3
// 00512de7  8b442408             mov eax, dword ptr [esp + 8]
// 00512deb  85c0                 test eax, eax
// 00512ded  7404                 je 0x512df3
// 00512def  8b400c               mov eax, dword ptr [eax + 0xc]
// 00512df2  c3                   ret 
// 00512df3  33c0                 xor eax, eax
// 00512df5  c3                   ret 
// library libpng-1.2.7/pngget.c (function _png_get_rowbytes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngget.c
