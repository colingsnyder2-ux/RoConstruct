// from server: 100% by auto
// roc 2010-06 00564da0  unit: seg_00560000  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00564da0
//
// 00564da0  56                   push esi
// 00564da1  8b742408             mov esi, dword ptr [esp + 8]
// 00564da5  85f6                 test esi, esi
// 00564da7  745b                 je 0x564e04
// 00564da9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00564dad  894654               mov dword ptr [esi + 0x54], eax
// 00564db0  8b442410             mov eax, dword ptr [esp + 0x10]
// 00564db4  85c0                 test eax, eax
// 00564db6  7405                 je 0x564dbd
// 00564db8  89464c               mov dword ptr [esi + 0x4c], eax
// 00564dbb  eb07                 jmp 0x564dc4
// 00564dbd  c7464c204d5600       mov dword ptr [esi + 0x4c], 0x564d20
// 00564dc4  8b442414             mov eax, dword ptr [esp + 0x14]
// 00564dc8  85c0                 test eax, eax
// 00564dca  7408                 je 0x564dd4
// 00564dcc  89864c010000         mov dword ptr [esi + 0x14c], eax
// 00564dd2  eb0a                 jmp 0x564dde
// 00564dd4  c7864c010000804d5600 mov dword ptr [esi + 0x14c], 0x564d80
// 00564dde  837e5000             cmp dword ptr [esi + 0x50], 0
// 00564de2  7420                 je 0x564e04
// 00564de4  687815a200           push 0xa21578
// 00564de9  56                   push esi
// 00564dea  c7465000000000       mov dword ptr [esi + 0x50], 0
// 00564df1  e86acd0000           call 0x571b60
// 00564df6  684015a200           push 0xa21540
// 00564dfb  56                   push esi
// 00564dfc  e85fcd0000           call 0x571b60
// 00564e01  83c410               add esp, 0x10
// 00564e04  5e                   pop esi
// 00564e05  c3                   ret 
// library libpng-1.2.16/pngwio.c (function _png_set_write_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwio.c
