// from server: 100% by auto
// roc 2009-06 00588d60  unit: seg_00580000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00588d60
//
// 00588d60  56                   push esi
// 00588d61  8b742408             mov esi, dword ptr [esp + 8]
// 00588d65  85f6                 test esi, esi
// 00588d67  744b                 je 0x588db4
// 00588d69  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00588d6d  894654               mov dword ptr [esi + 0x54], eax
// 00588d70  8b442410             mov eax, dword ptr [esp + 0x10]
// 00588d74  85c0                 test eax, eax
// 00588d76  7405                 je 0x588d7d
// 00588d78  894650               mov dword ptr [esi + 0x50], eax
// 00588d7b  eb07                 jmp 0x588d84
// 00588d7d  c74650208d5800       mov dword ptr [esi + 0x50], 0x588d20
// 00588d84  837e4c00             cmp dword ptr [esi + 0x4c], 0
// 00588d88  7420                 je 0x588daa
// 00588d8a  68f0e48c00           push 0x8ce4f0
// 00588d8f  56                   push esi
// 00588d90  c7464c00000000       mov dword ptr [esi + 0x4c], 0
// 00588d97  e874540000           call 0x58e210
// 00588d9c  68b8e48c00           push 0x8ce4b8
// 00588da1  56                   push esi
// 00588da2  e869540000           call 0x58e210
// 00588da7  83c410               add esp, 0x10
// 00588daa  c7864c01000000000000 mov dword ptr [esi + 0x14c], 0
// 00588db4  5e                   pop esi
// 00588db5  c3                   ret 
// library libpng-1.2.16/pngrio.c (function _png_set_read_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrio.c
