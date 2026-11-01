// from server: 100% by auto
// roc 2007-03 00509bc0  unit: seg_00500000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509bc0
//
// 00509bc0  837c240400           cmp dword ptr [esp + 4], 0
// 00509bc5  7424                 je 0x509beb
// 00509bc7  8b442408             mov eax, dword ptr [esp + 8]
// 00509bcb  85c0                 test eax, eax
// 00509bcd  741c                 je 0x509beb
// 00509bcf  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00509bd3  8b542410             mov edx, dword ptr [esp + 0x10]
// 00509bd7  81480880000000       or dword ptr [eax + 8], 0x80
// 00509bde  894870               mov dword ptr [eax + 0x70], ecx
// 00509be1  8a4c2414             mov cl, byte ptr [esp + 0x14]
// 00509be5  895074               mov dword ptr [eax + 0x74], edx
// 00509be8  884878               mov byte ptr [eax + 0x78], cl
// 00509beb  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_pHYs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
