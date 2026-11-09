// from server: 100% by auto
// roc 2010-06 0056c470  unit: seg_00560000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056c470
//
// 0056c470  56                   push esi
// 0056c471  8b742408             mov esi, dword ptr [esp + 8]
// 0056c475  85f6                 test esi, esi
// 0056c477  744b                 je 0x56c4c4
// 0056c479  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0056c47d  894654               mov dword ptr [esi + 0x54], eax
// 0056c480  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056c484  85c0                 test eax, eax
// 0056c486  7405                 je 0x56c48d
// 0056c488  894650               mov dword ptr [esi + 0x50], eax
// 0056c48b  eb07                 jmp 0x56c494
// 0056c48d  c7465030c45600       mov dword ptr [esi + 0x50], 0x56c430
// 0056c494  837e4c00             cmp dword ptr [esi + 0x4c], 0
// 0056c498  7420                 je 0x56c4ba
// 0056c49a  68f030a200           push 0xa230f0
// 0056c49f  56                   push esi
// 0056c4a0  c7464c00000000       mov dword ptr [esi + 0x4c], 0
// 0056c4a7  e8b4560000           call 0x571b60
// 0056c4ac  68bc30a200           push 0xa230bc
// 0056c4b1  56                   push esi
// 0056c4b2  e8a9560000           call 0x571b60
// 0056c4b7  83c410               add esp, 0x10
// 0056c4ba  c7864c01000000000000 mov dword ptr [esi + 0x14c], 0
// 0056c4c4  5e                   pop esi
// 0056c4c5  c3                   ret 
// library libpng-1.2.16/pngrio.c (function _png_set_read_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrio.c
