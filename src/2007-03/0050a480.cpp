// from server: 100% by auto
// roc 2007-03 0050a480  unit: seg_00500000  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050a480
//
// 0050a480  8b442408             mov eax, dword ptr [esp + 8]
// 0050a484  56                   push esi
// 0050a485  8b742408             mov esi, dword ptr [esp + 8]
// 0050a489  894654               mov dword ptr [esi + 0x54], eax
// 0050a48c  8b442410             mov eax, dword ptr [esp + 0x10]
// 0050a490  85c0                 test eax, eax
// 0050a492  7405                 je 0x50a499
// 0050a494  89464c               mov dword ptr [esi + 0x4c], eax
// 0050a497  eb07                 jmp 0x50a4a0
// 0050a499  c7464c00a45000       mov dword ptr [esi + 0x4c], 0x50a400
// 0050a4a0  8b442414             mov eax, dword ptr [esp + 0x14]
// 0050a4a4  85c0                 test eax, eax
// 0050a4a6  7408                 je 0x50a4b0
// 0050a4a8  89864c010000         mov dword ptr [esi + 0x14c], eax
// 0050a4ae  eb0a                 jmp 0x50a4ba
// 0050a4b0  c7864c01000060a45000 mov dword ptr [esi + 0x14c], 0x50a460
// 0050a4ba  837e5000             cmp dword ptr [esi + 0x50], 0
// 0050a4be  7420                 je 0x50a4e0
// 0050a4c0  68480e7a00           push 0x7a0e48
// 0050a4c5  56                   push esi
// 0050a4c6  c7465000000000       mov dword ptr [esi + 0x50], 0
// 0050a4cd  e8fede0000           call 0x5183d0
// 0050a4d2  68100e7a00           push 0x7a0e10
// 0050a4d7  56                   push esi
// 0050a4d8  e8f3de0000           call 0x5183d0
// 0050a4dd  83c410               add esp, 0x10
// 0050a4e0  5e                   pop esi
// 0050a4e1  c3                   ret 
// library libpng-1.2.7/pngwio.c (function _png_set_write_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwio.c
