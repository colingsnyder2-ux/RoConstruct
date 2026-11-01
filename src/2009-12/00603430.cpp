// from server: 100% by auto
// roc 2009-12 00603430  unit: seg_00600000  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00603430
//
// 00603430  56                   push esi
// 00603431  8b742408             mov esi, dword ptr [esp + 8]
// 00603435  85f6                 test esi, esi
// 00603437  745b                 je 0x603494
// 00603439  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0060343d  894654               mov dword ptr [esi + 0x54], eax
// 00603440  8b442410             mov eax, dword ptr [esp + 0x10]
// 00603444  85c0                 test eax, eax
// 00603446  7405                 je 0x60344d
// 00603448  89464c               mov dword ptr [esi + 0x4c], eax
// 0060344b  eb07                 jmp 0x603454
// 0060344d  c7464cb0336000       mov dword ptr [esi + 0x4c], 0x6033b0
// 00603454  8b442414             mov eax, dword ptr [esp + 0x14]
// 00603458  85c0                 test eax, eax
// 0060345a  7408                 je 0x603464
// 0060345c  89864c010000         mov dword ptr [esi + 0x14c], eax
// 00603462  eb0a                 jmp 0x60346e
// 00603464  c7864c01000010346000 mov dword ptr [esi + 0x14c], 0x603410
// 0060346e  837e5000             cmp dword ptr [esi + 0x50], 0
// 00603472  7420                 je 0x603494
// 00603474  6818389c00           push 0x9c3818
// 00603479  56                   push esi
// 0060347a  c7465000000000       mov dword ptr [esi + 0x50], 0
// 00603481  e8bacd0000           call 0x610240
// 00603486  68e0379c00           push 0x9c37e0
// 0060348b  56                   push esi
// 0060348c  e8afcd0000           call 0x610240
// 00603491  83c410               add esp, 0x10
// 00603494  5e                   pop esi
// 00603495  c3                   ret 
// library libpng-1.2.16/pngwio.c (function _png_set_write_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwio.c
