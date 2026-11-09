// from server: 100% by auto
// roc 2009-06 00581680  unit: seg_00580000  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00581680
//
// 00581680  56                   push esi
// 00581681  8b742408             mov esi, dword ptr [esp + 8]
// 00581685  85f6                 test esi, esi
// 00581687  745b                 je 0x5816e4
// 00581689  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0058168d  894654               mov dword ptr [esi + 0x54], eax
// 00581690  8b442410             mov eax, dword ptr [esp + 0x10]
// 00581694  85c0                 test eax, eax
// 00581696  7405                 je 0x58169d
// 00581698  89464c               mov dword ptr [esi + 0x4c], eax
// 0058169b  eb07                 jmp 0x5816a4
// 0058169d  c7464c00165800       mov dword ptr [esi + 0x4c], 0x581600
// 005816a4  8b442414             mov eax, dword ptr [esp + 0x14]
// 005816a8  85c0                 test eax, eax
// 005816aa  7408                 je 0x5816b4
// 005816ac  89864c010000         mov dword ptr [esi + 0x14c], eax
// 005816b2  eb0a                 jmp 0x5816be
// 005816b4  c7864c01000060165800 mov dword ptr [esi + 0x14c], 0x581660
// 005816be  837e5000             cmp dword ptr [esi + 0x50], 0
// 005816c2  7420                 je 0x5816e4
// 005816c4  6878c98c00           push 0x8cc978
// 005816c9  56                   push esi
// 005816ca  c7465000000000       mov dword ptr [esi + 0x50], 0
// 005816d1  e83acb0000           call 0x58e210
// 005816d6  6840c98c00           push 0x8cc940
// 005816db  56                   push esi
// 005816dc  e82fcb0000           call 0x58e210
// 005816e1  83c410               add esp, 0x10
// 005816e4  5e                   pop esi
// 005816e5  c3                   ret 
// library libpng-1.2.16/pngwio.c (function _png_set_write_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwio.c
