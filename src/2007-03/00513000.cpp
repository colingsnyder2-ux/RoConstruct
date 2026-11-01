// from server: 100% by auto
// roc 2007-03 00513000  unit: seg_00510000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00513000
//
// 00513000  8b442408             mov eax, dword ptr [esp + 8]
// 00513004  56                   push esi
// 00513005  8b742408             mov esi, dword ptr [esp + 8]
// 00513009  894654               mov dword ptr [esi + 0x54], eax
// 0051300c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00513010  85c0                 test eax, eax
// 00513012  7405                 je 0x513019
// 00513014  894650               mov dword ptr [esi + 0x50], eax
// 00513017  eb07                 jmp 0x513020
// 00513019  c74650c02f5100       mov dword ptr [esi + 0x50], 0x512fc0
// 00513020  837e4c00             cmp dword ptr [esi + 0x4c], 0
// 00513024  7420                 je 0x513046
// 00513026  6800287a00           push 0x7a2800
// 0051302b  56                   push esi
// 0051302c  c7464c00000000       mov dword ptr [esi + 0x4c], 0
// 00513033  e898530000           call 0x5183d0
// 00513038  68cc277a00           push 0x7a27cc
// 0051303d  56                   push esi
// 0051303e  e88d530000           call 0x5183d0
// 00513043  83c410               add esp, 0x10
// 00513046  c7864c01000000000000 mov dword ptr [esi + 0x14c], 0
// 00513050  5e                   pop esi
// 00513051  c3                   ret 
// library libpng-1.2.7/pngrio.c (function _png_set_read_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrio.c
