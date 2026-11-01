// from server: 100% by auto
// roc 2007-03 0050a0a0  unit: seg_00500000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050a0a0
//
// 0050a0a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0050a0a4  85c9                 test ecx, ecx
// 0050a0a6  7426                 je 0x50a0ce
// 0050a0a8  8b442408             mov eax, dword ptr [esp + 8]
// 0050a0ac  85c0                 test eax, eax
// 0050a0ae  741e                 je 0x50a0ce
// 0050a0b0  ba00020000           mov edx, 0x200
// 0050a0b5  855168               test dword ptr [ecx + 0x68], edx
// 0050a0b8  7514                 jne 0x50a0ce
// 0050a0ba  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0050a0be  56                   push esi
// 0050a0bf  8b31                 mov esi, dword ptr [ecx]
// 0050a0c1  89703c               mov dword ptr [eax + 0x3c], esi
// 0050a0c4  8b4904               mov ecx, dword ptr [ecx + 4]
// 0050a0c7  095008               or dword ptr [eax + 8], edx
// 0050a0ca  894840               mov dword ptr [eax + 0x40], ecx
// 0050a0cd  5e                   pop esi
// 0050a0ce  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_tIME)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
