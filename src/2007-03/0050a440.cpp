// from server: 100% by auto
// roc 2007-03 0050a440  unit: seg_00500000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050a440
//
// 0050a440  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0050a444  8b814c010000         mov eax, dword ptr [ecx + 0x14c]
// 0050a44a  85c0                 test eax, eax
// 0050a44c  7406                 je 0x50a454
// 0050a44e  894c2404             mov dword ptr [esp + 4], ecx
// 0050a452  ffe0                 jmp eax
// 0050a454  c3                   ret 
// library libpng-1.2.7/pngwio.c (function _png_flush)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwio.c
