// from server: 100% by auto
// roc 2011-06 00560fd0  unit: seg_00560000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00560fd0
//
// 00560fd0  56                   push esi
// 00560fd1  8b742408             mov esi, dword ptr [esp + 8]
// 00560fd5  85f6                 test esi, esi
// 00560fd7  744b                 je 0x561024
// 00560fd9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00560fdd  894654               mov dword ptr [esi + 0x54], eax
// 00560fe0  8b442410             mov eax, dword ptr [esp + 0x10]
// 00560fe4  85c0                 test eax, eax
// 00560fe6  7405                 je 0x560fed
// 00560fe8  894650               mov dword ptr [esi + 0x50], eax
// 00560feb  eb07                 jmp 0x560ff4
// 00560fed  c74650900f5600       mov dword ptr [esi + 0x50], 0x560f90
// 00560ff4  837e4c00             cmp dword ptr [esi + 0x4c], 0
// 00560ff8  7420                 je 0x56101a
// 00560ffa  68882ca800           push 0xa82c88
// 00560fff  56                   push esi
// 00561000  c7464c00000000       mov dword ptr [esi + 0x4c], 0
// 00561007  e8d4030000           call 0x5613e0
// 0056100c  68502ca800           push 0xa82c50
// 00561011  56                   push esi
// 00561012  e8c9030000           call 0x5613e0
// 00561017  83c410               add esp, 0x10
// 0056101a  c7864c01000000000000 mov dword ptr [esi + 0x14c], 0
// 00561024  5e                   pop esi
// 00561025  c3                   ret 
// library libpng-1.2.16/pngrio.c (function _png_set_read_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrio.c
