// from server: 100% by auto
// roc 2007-03 00512e00  unit: seg_00510000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00512e00
//
// 00512e00  837c240400           cmp dword ptr [esp + 4], 0
// 00512e05  740c                 je 0x512e13
// 00512e07  8b442408             mov eax, dword ptr [esp + 8]
// 00512e0b  85c0                 test eax, eax
// 00512e0d  7404                 je 0x512e13
// 00512e0f  8a401d               mov al, byte ptr [eax + 0x1d]
// 00512e12  c3                   ret 
// 00512e13  32c0                 xor al, al
// 00512e15  c3                   ret 
// library libpng-1.2.7/pngget.c (function _png_get_channels)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngget.c
