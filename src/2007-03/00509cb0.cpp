// from server: 100% by auto
// roc 2007-03 00509cb0  unit: seg_00500000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509cb0
//
// 00509cb0  837c240400           cmp dword ptr [esp + 4], 0
// 00509cb5  7416                 je 0x509ccd
// 00509cb7  8b442408             mov eax, dword ptr [esp + 8]
// 00509cbb  85c0                 test eax, eax
// 00509cbd  740e                 je 0x509ccd
// 00509cbf  8a4c240c             mov cl, byte ptr [esp + 0xc]
// 00509cc3  81480800080000       or dword ptr [eax + 8], 0x800
// 00509cca  88482c               mov byte ptr [eax + 0x2c], cl
// 00509ccd  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_sRGB)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
